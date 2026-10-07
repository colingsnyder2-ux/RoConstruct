"""Split a client exe into functions: work/<client>/functions.jsonl + meta.json.

Each row: addr, size, relocs (offsets of 4-byte fields the loader patches,
masked when diffing), calls (direct call count; 0 = leaf), unit (RTTI class
or seg_<64 KB block>).
"""
import json
import re
from bisect import bisect_left
from pathlib import Path

import pefile
from capstone import CS_ARCH_X86, CS_MODE_32, Cs

ROOT = Path(__file__).resolve().parent.parent
STOP = {"ret", "retf", "int3", "hlt", "ud2"}


def reloc_sites(pe):
    """Virtual addresses of every HIGHLOW base relocation."""
    base = pe.OPTIONAL_HEADER.ImageBase
    return sorted(base + e.rva for block in getattr(pe, "DIRECTORY_ENTRY_BASERELOC", [])
                  for e in block.entries if e.type == 3)


def find_functions(code, text_va, seeds, relocs):
    """Recursive descent from seeds over .text (code at text_va).
    New starts: direct call targets and `push/mov offset fn` immediates.
    Switch jump tables are followed so their case blocks count as reached.
    MSVC aligns functions to 16 after int3 padding, so aligned non-cc bytes
    after cc also seed (unless a jump table sits there)."""
    end = text_va + len(code)
    reloc_set = set(relocs)
    rd = lambda va: int.from_bytes(code[va - text_va:va - text_va + 4], "little")
    seeds = set(seeds) | {text_va + i for i in range(16, len(code), 16)
                          if code[i - 1] == 0xCC and code[i] != 0xCC
                          and text_va + i not in reloc_set}
    starts = {s for s in seeds if text_va <= s < end}
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    seen, calls, work = set(), set(), list(starts)
    while work:
        a = work.pop()
        while text_va <= a < end and a not in seen:
            insn = next(md.disasm_lite(code[a - text_va:a - text_va + 15], a, 1), None)
            if insn is None:
                starts.discard(a)
                break
            seen.add(a)
            _, size, mnem, op = insn
            for r in range(a, a + size - 3):
                if r not in reloc_set or not text_va <= rd(r) < end:
                    continue
                t = rd(r)
                if mnem == "jmp" and "[" in op:  # jmp [idx*4 + table]
                    while t in reloc_set and text_va <= rd(t) < end:
                        work.append(rd(t))
                        t += 4
                elif "[" not in op.split(",")[-1]:  # immediate code pointer: callback
                    starts.add(t)
                    work.append(t)
            if mnem == "call" and op.startswith("0x"):
                t = int(op, 16)
                if text_va <= t < end:
                    starts.add(t)
                    work.append(t)
                    calls.add(a)
            elif mnem.startswith(("j", "loop")):
                if op.startswith("0x"):
                    work.append(int(op, 16))
                if mnem == "jmp":
                    break
            elif mnem in STOP:
                break
            a += size
    order = sorted(s for s in starts if s in seen) + [end]
    call_sites = sorted(calls)
    out = []
    for start, nxt in zip(order, order[1:]):
        body = code[start - text_va:nxt - text_va].rstrip(b"\xcc")  # MSVC int3 padding
        if not body:
            continue
        stop = start + len(body)
        lo, hi = bisect_left(relocs, start), bisect_left(relocs, stop)
        rel = [r - start for r in relocs[lo:hi]]
        out.append({
            "addr": "%08x" % start,
            "size": len(body),
            "relocs": rel,
            "calls": bisect_left(call_sites, stop) - bisect_left(call_sites, start),
            "kind": kind_of(body, rel),
        })
    return out


GENERATED = [re.compile(p) for p in (
    # __ehhandler$: security cookie check, then jump to __CxxFrameHandler3
    r"^mov edx, dword ptr \[esp \+ 8\] ; lea eax, \[edx [+-] \w+\] ; .*xor ecx, eax ; call N ; mov eax, N ; jmp N$",
    # scalar deleting destructor (??_G): ~T(); if (flags & 1) delete this;
    r"^push esi ; mov esi, ecx ; (mov dword ptr \[esi\], N ; )?call (dword ptr \[N\]|N) ; test byte ptr \[esp \+ 8\], 1 ; "
    r"je N ; push esi ; call (dword ptr \[N\]|N) ; add esp, 4 ; mov eax, esi ; pop esi ; ret 4$",
    r"^test byte ptr \[esp \+ 4\], 1 ; push esi ; mov esi, ecx ; mov dword ptr \[esi\], N ; je N ; push esi ; "
    r"call (dword ptr \[N\]|N) ; add esp, 4 ; mov eax, esi ; pop esi ; ret 4$",
    # static-local guard reset in unwind code: $S &= ~bit
    r"^mov eax, dword ptr \[N\] ; and eax, N ; mov dword ptr \[N\], eax ; ret$",
    # EH-guarded dynamic initializer of a global object
    r"^mov eax, dword ptr fs:\[0\] ; push -1 ; push N ; push eax ; mov dword ptr fs:\[0\], esp ; mov ecx, N ; .* ; mov dword ptr fs:\[0\], ecx ; add esp, \w+ ; ret$",
)]


def kind_of(code, relocs):
    """'thunk' (import jump), 'adjustor' (this-pointer fixup + jmp), 'gen' (EH handler, deleting dtor, guard reset), 'eh'
    (unwind funclet / exception handler stub) or 'code'. Only 'code' counts
    toward progress: the rest is generated by the compiler or linker.
    ponytail: pattern list, misses rarer generated shapes."""
    insns = list(Cs(CS_ARCH_X86, CS_MODE_32).disasm_lite(code, 0))
    if sum(i[1] for i in insns) != len(code):
        return "bad"  # split mid-instruction or data: not a real function
    if not insns:
        return "code"
    if len(insns) == 1 and code[0] == 0xEB:
        return "bad"  # lone short jump: the tail of another function
    if len(code) <= 4 and not insns[-1][2].startswith(("ret", "jmp")):
        return "bad"  # tiny and never returns: data bytes, not code
    shape = " ; ".join(re.sub(r"0x[0-9a-f]+", "N", "%s %s" % (m, o)).strip() for _, _, m, o in insns)
    if any(p.search(shape) for p in GENERATED):
        return "gen"
    first, last = insns[0], insns[-1]
    if len(insns) == 1 and first[2] == "jmp" and first[3].startswith("dword ptr [0x"):
        return "thunk"
    if last[2] == "jmp" and len(insns) == 2 and first[2] in ("sub", "add") and first[3].startswith("ecx,"):
        return "adjustor"
    if "[ebp" in first[3] and not any(m == "push" and o == "ebp" for _, _, m, o in insns):
        return "eh"
    if len(insns) == 2 and first[2] == "mov" and first[3].startswith("eax, 0x") and last[2] == "jmp" and relocs == [1]:
        return "eh"
    return "code"


def demangle_class(raw):
    """'.?AVInstance@RBX@@' -> 'RBX::Instance'. Templates stay rough."""
    name = raw[4:].split("@@")[0]
    return "::".join(reversed([p for p in name.split("@") if p]))


def rtti_classes(read, relocs, in_text):
    """{function va: class} from MSVC vtables. read(va, n) -> bytes.
    vtable[-1] -> CompleteObjectLocator{sig 0, off, cdOff, TypeDescriptor*}.
    A function shared by several vtables goes to the smallest one (the base)."""
    reloc_set = set(relocs)
    rd = lambda va: int.from_bytes(read(va, 4), "little")
    best = {}
    for site in relocs:
        if in_text(site):
            continue
        col = rd(site)
        if col + 12 not in reloc_set or rd(col) != 0:
            continue
        raw = read(rd(col + 12) + 8, 256).split(b"\0")[0]
        if not raw.startswith((b".?AV", b".?AU")):
            continue
        cls = demangle_class(raw.decode("latin-1"))
        vt, fns = site + 4, []
        while vt in reloc_set and in_text(rd(vt)):
            fns.append(rd(vt))
            vt += 4
        for fn in fns:
            if fn not in best or len(fns) < best[fn][0]:
                best[fn] = (len(fns), cls)
    return {fn: cls for fn, (_, cls) in best.items()}


def assign_units(funcs, classes, reach=0x4000):
    """Link order keeps one .obj contiguous, so a function inherits the class of
    the nearest labelled function before it (within `reach` bytes).
    ponytail: guesses .obj boundaries; real ones need map files or symbols."""
    cur, cur_end = None, 0
    for f in funcs:
        va = int(f["addr"], 16)
        if va in classes:
            cur, cur_end = classes[va], va + f["size"]
        elif cur and va - cur_end > reach:
            cur = None
        f["unit"] = cur or "seg_%08x" % (va - va % 0x10000)


def analyze(client, exe):
    pe = pefile.PE(str(exe))
    base = pe.OPTIONAL_HEADER.ImageBase
    text = next(s for s in pe.sections if s.Name.rstrip(b"\0") == b".text")
    text_va = base + text.VirtualAddress
    code = text.get_data()[:text.Misc_VirtualSize]
    in_text = lambda va: text_va <= va < text_va + len(code)
    image = pe.get_memory_mapped_image()
    read = lambda va, n: image[va - base:va - base + n] if 0 <= va - base < len(image) else b""
    relocs = reloc_sites(pe)
    seeds = {base + pe.OPTIONAL_HEADER.AddressOfEntryPoint}
    # Pointers stored outside .text (vtables, callback tables) into .text.
    seeds.update(v for v in (int.from_bytes(read(s, 4), "little") for s in relocs if not in_text(s))
                 if in_text(v))
    funcs = find_functions(code, text_va, seeds, relocs)
    classes = rtti_classes(read, relocs, in_text)
    assign_units(funcs, classes)
    # Functions found in the compiler's own prebuilt libraries (`roc mass`) are not Roblox code.
    libmatch = ROOT / "work" / client / "libmatch.json"
    if libmatch.exists():
        runtime = set(json.loads(libmatch.read_text()))
        for f in funcs:
            if f["addr"] in runtime:
                f["kind"] = "gen"
    # Anything already byte-matched by real source is code, whatever a pattern guessed.
    scores_file = ROOT / "work" / client / "scores.json"
    if scores_file.exists():
        matched = {a for a, s in json.loads(scores_file.read_text()).items() if s == 100}
        for f in funcs:
            if f["kind"] == "gen" and f["addr"] in matched:
                f["kind"] = "code"
    data = sum(s.Misc_VirtualSize for s in pe.sections
               if s.Name.rstrip(b"\0") in (b".rdata", b".data", b".tls"))
    out = ROOT / "work" / client
    out.mkdir(parents=True, exist_ok=True)
    (out / "functions.jsonl").write_text("".join(json.dumps(f, separators=(",", ":")) + "\n" for f in funcs))
    (out / "meta.json").write_text(json.dumps({"code_bytes": len(code), "data_bytes": data,
                                               "classes": len(set(classes.values()))}))
    return out / "functions.jsonl", funcs
