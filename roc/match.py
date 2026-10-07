"""Compile C++ with the client's original cl.exe and diff it against the exe.

Score 100 = byte-identical once relocated fields are masked on both sides.
"""
import difflib
import functools
import json
import os
import re
import struct
import subprocess
import tempfile
from pathlib import Path

import pefile
from capstone import CS_ARCH_X86, CS_MODE_32, Cs

from roc import clients, setup

ROOT = Path(__file__).resolve().parent.parent
# Starting point only: `roc flags <client>` tunes this into clients.json.
DEFAULT_FLAGS = "/O2 /GS- /EHsc /MD"


class CompileError(RuntimeError):
    pass


def coff_functions(obj):
    """[(name, bytes, reloc offsets)] for every function symbol in a COFF .obj."""
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from("<HHIIIHH", obj, 0)
    strtab = symptr + nsym * 18
    secs = [struct.unpack_from("<8sIIIIIIHHI", obj, 20 + optsz + 40 * i) for i in range(nsec)]
    syms, i = [], 0
    while i < nsym:
        raw, value, secnum, typ, _, naux = struct.unpack_from("<8sIhHBB", obj, symptr + 18 * i)
        if raw[:4] == b"\0\0\0\0":
            off = strtab + struct.unpack_from("<I", raw, 4)[0]
            raw = obj[off:obj.index(b"\0", off)]
        if secnum > 0 and typ == 0x20:
            syms.append((secnum - 1, value, raw.rstrip(b"\0").decode("latin-1")))
        i += 1 + naux
    out = []
    for sec, value, name in syms:
        _, _, _, rawsize, rawptr, relptr, _, nrel, _, _ = secs[sec]
        nxt = min([v for s, v, _ in syms if s == sec and v > value] + [rawsize])
        relocs = [struct.unpack_from("<I", obj, relptr + 10 * k)[0] - value for k in range(nrel)]
        out.append((name, obj[rawptr + value:rawptr + nxt],
                    [r for r in relocs if 0 <= r < nxt - value]))
    return out


def masked(code, relocs):
    b = bytearray(code)
    for r in relocs:
        b[r:r + 4] = b"\0" * len(b[r:r + 4])
    return bytes(b)


def score(target, target_relocs, cand, cand_relocs):
    mask = set(target_relocs) | set(cand_relocs)
    a, b = masked(target, mask), masked(cand, mask)
    if a == b:
        return 100
    return min(99, int(100 * difflib.SequenceMatcher(None, a, b, autojunk=False).ratio()))


def asm_lines(code, relocs):
    """Disassembly with relocated operands shown as `sym`, for diffs people and LLMs read.
    Direct call/jmp targets outside the function also become `sym`."""
    out = []
    for a, s, m, o in Cs(CS_ARCH_X86, CS_MODE_32).disasm_lite(code, 0):
        if any(a <= r < a + s for r in relocs):
            o = re.sub(r"0x[0-9a-f]+|(?<=\[)0(?=\])", "sym", o)
        elif m.startswith(("j", "call")) and o.startswith("0x") and not 0 <= int(o, 16) < len(code):
            o = "sym"
        out.append("%s %s" % (m, o))
    return out


def diff(target_code, target_relocs, cand, cand_relocs):
    return "\n".join(difflib.unified_diff(asm_lines(target_code, target_relocs), asm_lines(cand, cand_relocs),
                                          "target", "yours", lineterm="", n=99))


def disasm(code, addr):
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    return ["%08x  %-20s %s %s" % (a, code[a - addr:a - addr + s].hex(), m, o)
            for a, s, m, o in md.disasm_lite(code, addr)]


@functools.lru_cache(maxsize=None)
def _functions(client):
    rows = {}
    for line in (ROOT / "work" / client / "functions.jsonl").open():
        row = json.loads(line)
        rows[row["addr"]] = row
    return rows


@functools.lru_cache(maxsize=None)
def _image(client):
    entry = clients.load()[client]
    pe = pefile.PE(str(clients.exe_path(client, entry)), fast_load=True)
    return pe.OPTIONAL_HEADER.ImageBase, pe.get_memory_mapped_image()


def target(client, addr):
    """(bytes, relocs, row) of a function from the client exe."""
    addr = addr.lower().replace("0x", "").zfill(8)
    try:
        row = _functions(client)[addr]
    except FileNotFoundError:
        raise SystemExit("%s is not analyzed yet: run  roc analyze %s" % (client, client))
    except KeyError:
        raise SystemExit("%s: no function starts at %s (pick one on the site or from `roc next %s`)"
                         % (client, addr, client))
    base, image = _image(client)
    va = int(addr, 16) - base
    return bytes(image[va:va + row["size"]]), row["relocs"], row


def reject_asm(text):
    """Inline asm would 'match' without decompiling anything."""
    if re.search(r"__asm|\b_asm\b|\b_emit\b|#pragma\s+code_seg", text):
        raise CompileError("inline asm / _emit is not allowed: write C++")


def compile_text(client, text, flags=None):
    """Compile C++ source text to COFF bytes with the client's compiler."""
    reject_asm(text)
    entry = clients.load()[client]
    cl = setup.compilers().get(entry["compiler_build"])
    if not cl:
        raise SystemExit("Missing compiler %s for %s. Run: roc install" % (entry["compiler"], client))
    env = setup.cl_env(cl)
    flags = (flags or entry.get("flags") or DEFAULT_FLAGS).split()
    with tempfile.TemporaryDirectory() as tmp:
        src, obj = Path(tmp) / "f.cpp", Path(tmp) / "f.obj"
        src.write_text(text)
        run = subprocess.run([str(cl), "/nologo", "/c", "/Gy", *flags, "/Fo" + str(obj), str(src)],
                             capture_output=True, text=True, env=env, cwd=tmp)
        if run.returncode:
            out = (run.stdout + run.stderr).replace(str(src), "source").strip()
            raise CompileError("\n".join(l for l in out.splitlines() if l.strip() != "f.cpp"))
        return obj.read_bytes()


def check_text(client, addr, text, flags=None):
    """(score, symbol, asm diff) for the best function in text vs the target."""
    code, relocs, _ = target(client, addr)
    funcs = coff_functions(compile_text(client, text, flags))
    if not funcs:
        return 0, None, "no functions compiled (is the function body empty or inline?)"
    best = max(funcs, key=lambda f: score(code, relocs, f[1], f[2]))
    return score(code, relocs, best[1], best[2]), best[0], diff(code, relocs, best[1], best[2])


def check(client, addr, src, flags=None):
    return check_text(client, addr, Path(src).read_text(errors="replace"), flags)


def save_score(client, addr, value):
    """Keep the best score per function in work/<client>/scores.json."""
    path = ROOT / "work" / client / "scores.json"
    scores = json.loads(path.read_text()) if path.exists() else {}
    if value > scores.get(addr, 0):
        scores[addr] = value
        path.write_text(json.dumps(scores, indent=0, sort_keys=True))
    return scores.get(addr, 0)


def template(client, addr):
    """Starter source: header + target disassembly as comments + empty stub."""
    code, _, row = target(client, addr)
    lines = ["// roc %s %s  unit: %s  size: %d bytes" % (client, addr, row["unit"], row["size"]),
             "// Make this compile to the exact bytes below, then: roc check %s %s" % (client, addr),
             "//"] + ["// " + l for l in disasm(code, int(addr, 16))]
    return "\n".join(lines) + "\n\nvoid func_%s()\n{\n}\n" % addr


def claim(client, addr):
    """Write src/<client>/<addr>.cpp (kept if it already exists)."""
    addr = addr.lower().replace("0x", "").zfill(8)
    path = ROOT / "src" / client / ("%s.cpp" % addr)
    if not path.exists():
        text = template(client, addr)
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)
    return path
