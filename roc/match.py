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


def coff_data_refs(obj, func_name):
    """Data a function's source defines and points to with absolute (DIR32) relocations:
    [(offset in function, data bytes, reloc offsets inside the data)]. Only data with
    contents in this .obj (string literals, constants, initialised globals) is listed;
    `extern` declarations have none and are not compared."""
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from("<HHIIIHH", obj, 0)
    strtab = symptr + nsym * 18
    secs = [struct.unpack_from("<8sIIIIIIHHI", obj, 20 + optsz + 40 * i) for i in range(nsec)]
    syms, i = {}, 0
    while i < nsym:
        raw, value, secnum, typ, _, naux = struct.unpack_from("<8sIhHBB", obj, symptr + 18 * i)
        if raw[:4] == b"\0\0\0\0":
            off = strtab + struct.unpack_from("<I", raw, 4)[0]
            raw = obj[off:obj.index(b"\0", off)]
        syms[i] = (raw.rstrip(b"\0").decode("latin-1"), value, secnum, typ)
        i += 1 + naux

    def relocs_of(sec):
        _, _, _, _, _, relptr, _, nrel, _, _ = secs[sec]
        return [struct.unpack_from("<IIH", obj, relptr + 10 * k) for k in range(nrel)]

    func = next(((v, s - 1) for n, v, s, t in syms.values() if n == func_name and s > 0), None)
    if func is None:
        return []
    fvalue, fsec = func
    out = []
    for off, symidx, typ in relocs_of(fsec):
        if typ != 6 or symidx not in syms:  # 6 = IMAGE_REL_I386_DIR32 (absolute address)
            continue
        name, value, secnum, _ = syms[symidx]
        if secnum <= 0:
            continue  # extern: no contents here
        _, _, _, rawsize, rawptr, _, _, _, _, chars = secs[secnum - 1]
        if chars & 0x20 or not chars & 0x40 or not rawptr:  # code, or no initialised data
            continue
        nxt = min([v for n, v, s, t in syms.values() if s == secnum and v > value] + [rawsize])
        inner = [r - value for r, _, _ in relocs_of(secnum - 1) if value <= r < nxt]
        out.append((off - fvalue, obj[rawptr + value:rawptr + nxt], inner))
    return out


@functools.lru_cache(maxsize=None)
def _base_relocs(client):
    from roc.analyze import reloc_sites
    entry = clients.load()[client]
    return frozenset(reloc_sites(pefile.PE(str(clients.exe_path(client, entry)))))


def data_check(client, addr, code, refs):
    """Compare referenced data against the exe. Returns (matched [(va, len)], mismatch notes)."""
    base, image = _image(client)
    exe_relocs = _base_relocs(client)
    ok, bad = [], []
    for off, data, inner in refs:
        if off + 4 > len(code):
            continue
        va = int.from_bytes(code[off:off + 4], "little")
        rva = va - base
        if not 0 <= rva < len(image) or not data:
            continue
        exe = bytes(image[rva:rva + len(data)])
        mask = set(inner) | {r - va for r in exe_relocs if va <= r < va + len(data)}
        if masked(exe, mask) == masked(data, mask):
            ok.append((va, len(data)))
        else:
            bad.append("data at %08x differs: exe %r, yours %r" % (va, exe[:40], data[:40]))
    return ok, bad


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
            o = re.sub(r"0x[0-9a-f]+|(?<=\[)0(?=\])|(?<=, )0$", "sym", o)
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
    """Inline asm would 'match' without decompiling anything. Sources also arrive
    from servers and AI, so anything that reads other files on this PC is refused
    (only `#include <system header>` is allowed)."""
    if re.search(r"__asm|\b_asm\b|\b_emit\b|#pragma\s+code_seg", text):
        raise CompileError("inline asm / _emit is not allowed: write C++")
    if re.search(r'#\s*(import|using)\b|#\s*include\s*"|#\s*pragma\s+(comment|include_alias)', text):
        raise CompileError('#import, #using, #include "file" and #pragma comment are not allowed')


def directives(text):
    """`// roc-<key>: value` lines: lang (c|cpp), flags, cl (compiler build), lib (recipe + file).
    Library code matched with its own build settings carries them, so anyone re-checks it the same way."""
    return dict(re.findall(r"(?m)^//\s*roc-(lang|flags|cl|lib):\s*(.+?)\s*$", text))


def compile_text(client, text, flags=None, build=None):
    """Compile source text to COFF bytes with the client's compiler (or `build`)."""
    reject_asm(text)
    entry = clients.load()[client]
    d = directives(text)
    build = build or (int(d["cl"]) if d.get("cl", "").isdigit() else entry["compiler_build"])
    if "lib" in d:  # library file: rebuilt from the pinned, hash-checked source in tools/libs
        from roc import libs
        recipe, _, path = d["lib"].partition(" ")
        text = "%s\n%s" % (text, libs.unit(recipe, path.strip(), build))
    cl = setup.compilers().get(build)
    if not cl:
        raise SystemExit("Missing compiler build %s for %s. Run: roc install" % (build, client))
    env = setup.cl_env(cl)
    flags = (flags or d.get("flags") or entry.get("flags") or DEFAULT_FLAGS).split()
    with tempfile.TemporaryDirectory() as tmp:
        src, obj = Path(tmp) / ("f.c" if d.get("lang") == "c" else "f.cpp"), Path(tmp) / "f.obj"
        src.write_text(text)
        run = subprocess.run([str(cl), "/nologo", "/c", "/Gy", *flags, "/Fo" + str(obj), str(src)],
                             capture_output=True, text=True, env=env, cwd=tmp)
        if run.returncode:
            out = (run.stdout + run.stderr).replace(str(src), "source").strip()
            raise CompileError("\n".join(l for l in out.splitlines() if l.strip() not in ("f.cpp", "f.c")))
        return obj.read_bytes()


def check_text(client, addr, text, flags=None):
    """(score, symbol, asm diff, data spans) for the best function in text vs the target.
    A byte-identical function whose own strings/constants differ from the exe scores 99."""
    code, relocs, _ = target(client, addr)
    obj = compile_text(client, text, flags)
    funcs = coff_functions(obj)
    if not funcs:
        return 0, None, "no functions compiled (is the function body empty or inline?)", []
    best = max(funcs, key=lambda f: score(code, relocs, f[1], f[2]))
    value, d, spans = score(code, relocs, best[1], best[2]), diff(code, relocs, best[1], best[2]), []
    if value == 100:
        spans, bad = data_check(client, addr, code, coff_data_refs(obj, best[0]))
        if bad:
            value, d = 99, "Code matches, but data your source defines does not:\n" + "\n".join(bad)
    return value, best[0], d, spans


def save_data(client, addr, spans):
    """Record verified data (va, length) per function in work/<client>/data.json."""
    if not spans:
        return
    path = ROOT / "work" / client / "data.json"
    data = json.loads(path.read_text()) if path.exists() else {}
    data[addr] = spans
    path.write_text(json.dumps(data, separators=(",", ":")))


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
