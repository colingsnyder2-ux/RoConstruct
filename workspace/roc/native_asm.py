"""Target vs candidate disassembly for native recovery, in one call.

Replaces ad-hoc capstone snippets: lists target functions at their real
addresses with call/IAT targets named, and diffs a candidate .obj symbol
against the target with relocated operands masked.
"""
import difflib
import functools
import json
import re
from pathlib import Path

from capstone import CS_ARCH_X86, CS_MODE_32, Cs

from roc import match

ROOT = Path(__file__).resolve().parent.parent


@functools.lru_cache(maxsize=4)
def names(client):
    """addr -> label from rebuilt tudiff symbols (unique pairs only) and the IAT."""
    out = {}
    for path in (ROOT / "rebuild" / client / "out").glob("**/*.tudiff.json"):
        try:
            files = json.loads(path.read_text()).get("files", {})
        except (OSError, ValueError):
            continue
        for info in files.values():
            for row in info.get("symbols", []):
                if len(row.get("addrs", [])) == 1:
                    out.setdefault(int(row["addrs"][0], 16), row["symbol"])
    import pefile
    from roc import clients
    pe = pefile.PE(str(clients.exe_path(client, clients.load()[client])),
                   fast_load=True)
    pe.parse_data_directories([pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_IMPORT"]])
    for dll in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []):
        for imp in dll.imports:
            label = imp.name.decode() if imp.name else "#%d" % imp.ordinal
            out[imp.address] = "%s!%s" % (dll.dll.decode(), label)
    return out


@functools.lru_cache(maxsize=4)
def mfc_ordinals():
    """ordinal -> MFC90 export name, read from the installed MFC .def when present."""
    out = {}
    for path in (ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel").glob("mfc90.def"):
        for line in path.read_text(errors="replace").splitlines():
            m = re.match(r"\s*(\S+)\s+@\s*(\d+)", line)
            if m:
                out[int(m.group(2))] = m.group(1)
    return out


def thunk_label(client, value):
    """Name an MFC/CRT import thunk (jmp [iat]) by its export."""
    try:
        base, image = match._image(client)
        raw = bytes(image[value - base:value - base + 6])
    except Exception:
        return None
    if raw[:2] != bytes([0xff, 0x25]):
        return None
    target = int.from_bytes(raw[2:], "little")
    name = names(client).get(target)
    m = re.match(r"mfc90[.]dll!#([0-9]+)$", name or "")
    if m:
        return "MFC " + mfc_ordinals().get(int(m.group(1)), name)
    return name


def label(client, value):
    name = names(client).get(value)
    if name:
        return name
    name = thunk_label(client, value)
    if name:
        return name
    try:
        row = match._functions(client).get("%08x" % value)
    except FileNotFoundError:
        row = None
    if row:
        return "fn_%08x%s" % (value, " [unit? %s]" % row["unit"] if row.get("unit") else "")
    return None


def lines(code, base, relocs=(), client=None):
    """[(addr, text, normalized)]: normalized masks relocated and branch-target operands."""
    # Zero each relocated dword so both sides compare only non-link bytes;
    # instruction lengths are unchanged, so the two streams zip 1:1.
    zeroed = bytearray(code)
    for r in relocs:
        zeroed[r:r + 4] = b"\0" * len(zeroed[r:r + 4])
    cs = Cs(CS_ARCH_X86, CS_MODE_32)
    out = []
    for ins, z in zip(cs.disasm(code, base), cs.disasm(bytes(zeroed), base)):
        text = "%s %s" % (ins.mnemonic, ins.op_str)
        norm = "%s %s" % (z.mnemonic, z.op_str)
        # Local branches compare exactly (candidate is placed at the target address);
        # direct calls/branches leaving the function differ only by link placement.
        start = ins.address - base
        relocated = any(start <= r < start + ins.size for r in relocs)
        if (ins.mnemonic == "call" or ins.mnemonic.startswith("j")) and re.fullmatch(r"0x[0-9a-f]+", ins.op_str) \
                and (relocated or not base <= int(ins.op_str, 16) < base + len(code)):
            norm = ins.mnemonic + " <out>"
        if client:
            for m in re.findall(r"0x[0-9a-f]{6,8}", ins.op_str):
                name = label(client, int(m, 16))
                if name:
                    text += "  ; " + name
                    break
        out.append((ins.address, text, norm))
    return out


def window(rows, lo=None, hi=None, only=None, head=None, tail=None):
    rows = [r for r in rows if (lo is None or r[0] >= lo) and (hi is None or r[0] < hi)]
    if only:
        rows = [r for r in rows if r[1].split()[0] in only]
    if head:
        rows = rows[:head]
    if tail:
        rows = rows[-tail:]
    return rows


def candidate(obj_path, sym=None, client=None, addr=None):
    """(symbol, bytes, relocs) from a COFF .obj; sym is a decorated-name prefix."""
    if not Path(obj_path).is_file():
        raise SystemExit("no such object: %s" % obj_path)
    funcs = match.coff_functions(Path(obj_path).read_bytes())
    if not sym and client and addr:
        sym = names(client).get(int(addr, 16))
    if not sym:
        raise SystemExit("--sym PREFIX needed: no rebuilt name known for %s" % addr)
    hits = [f for f in funcs if f[0].startswith(sym)]
    if not hits:
        near = [f[0] for f in funcs if sym[:12] in f[0]][:8]
        raise SystemExit("no symbol starting %s in %s; similar: %s" % (sym, obj_path, near))
    return hits[0]


def diff(target_rows, cand_rows, context=3):
    """Unified diff of normalized instruction streams; '' when identical."""
    a = ["%s" % r[2] for r in target_rows]
    b = ["%s" % r[2] for r in cand_rows]
    return "\n".join(difflib.unified_diff(a, b, "target", "candidate", n=context, lineterm=""))


def first_divergence(target_rows, cand_rows):
    for i, (t, c) in enumerate(zip(target_rows, cand_rows)):
        if t[2] != c[2]:
            return i
    return None if len(target_rows) == len(cand_rows) else min(len(target_rows), len(cand_rows))


def demo():
    # mov eax,[ecx+4]; call rel32; ret -- call operand differs, normalization hides it
    a = lines(bytes.fromhex("8b4104e810000000c3"), 0x1000)
    b = lines(bytes.fromhex("8b4104e820000000c3"), 0x1000)
    assert first_divergence(a, b) is None and diff(a, b) == ""
    c = lines(bytes.fromhex("8b4108e810000000c3"), 0x1000)
    assert first_divergence(a, c) == 0 and "+mov eax, dword ptr [ecx + 8]" in diff(a, c)
    # local branch: jne +1 vs jne +2 at the same base must differ
    j1, j2 = lines(bytes.fromhex("7501c3c3c3"), 0x1000), lines(bytes.fromhex("7502c3c3c3"), 0x1000)
    assert first_divergence(j1, j2) == 0
    assert [r[1] for r in window(lines(bytes.fromhex("e8000000c0c3"), 0x1000), only={"call"})][0].startswith("call")
    print("native_asm demo ok")


if __name__ == "__main__":
    demo()
