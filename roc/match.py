"""Compile C++ with the client's original cl.exe and diff it against the exe.

Score 100 = byte-identical once relocated fields are masked on both sides.
"""
import difflib
import functools
import hashlib
import json
import os
import re
import struct
import subprocess
import tempfile
import threading
from pathlib import Path

import pefile
from capstone import CS_ARCH_X86, CS_MODE_32, Cs

from roc import clients, setup

ROOT = Path(__file__).resolve().parent.parent
# Starting point only: `roc flags <client>` tunes this into clients.json.
DEFAULT_FLAGS = "/O2 /GS- /EHsc /MD"
COMPILE_ERRORS = ROOT / "work" / "compile-errors.json"
_COMPILE_ERRORS = None


class CompileError(RuntimeError):
    pass


def _compile_error_cache():
    global _COMPILE_ERRORS
    if _COMPILE_ERRORS is None:
        try:
            _COMPILE_ERRORS = json.loads(COMPILE_ERRORS.read_text())
        except (OSError, ValueError):
            _COMPILE_ERRORS = {}
    return _COMPILE_ERRORS


def _remember_compile_error(key, message):
    cache = _compile_error_cache()
    cache[key] = message[-1200:]
    try:
        COMPILE_ERRORS.parent.mkdir(parents=True, exist_ok=True)
        COMPILE_ERRORS.write_text(json.dumps(cache, separators=(",", ":")))
    except OSError:
        pass


@functools.lru_cache(maxsize=512)
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


def exact_match(target, target_relocs, cand, cand_relocs):
    """Byte-identical once relocated fields are masked on both sides.

    This is the only verification signal. Everything else is a fuzzy hint.
    """
    mask = set(target_relocs) | set(cand_relocs)
    return masked(target, mask) == masked(cand, mask)


def similarity_ratio(target, target_relocs, cand, cand_relocs):
    """Fuzzy 0.0-1.0 byte similarity. Guides search only; never verifies.

    Known limits: rewards common prologues/zero bytes, ignores instruction
    boundaries, and the union mask can hide position-shifted relocs. Do not
    treat a high value as near-correct code.
    """
    mask = set(target_relocs) | set(cand_relocs)
    a, b = masked(target, mask), masked(cand, mask)
    if a == b:
        return 1.0
    return difflib.SequenceMatcher(None, a, b, autojunk=False).ratio()


def score(target, target_relocs, cand, cand_relocs):
    if exact_match(target, target_relocs, cand, cand_relocs):
        return 100
    return min(99, int(100 * similarity_ratio(target, target_relocs, cand, cand_relocs)))


def _insn_parts(code):
    """[(mnemonic, operands)] via capstone; never raises on bad bytes."""
    try:
        return [(m, o) for _, _, m, o in Cs(CS_ARCH_X86, CS_MODE_32).disasm_lite(code, 0)]
    except (ValueError, TypeError):
        return []


def _call_pushes(code, relocs):
    ins = list(Cs(CS_ARCH_X86, CS_MODE_32).disasm_lite(code, 0))
    lines = asm_lines(code, relocs)
    calls, pending = [], []
    for i, (_, _, mnemonic, operands) in enumerate(ins):
        if mnemonic == "push":
            pending.append(operands)
        elif mnemonic == "call":
            calls.append((lines[i].partition(" ")[2], pending))
            pending = []
        else:
            pending = []
    return calls


_REGS = ("eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp",
         "ax", "bx", "cx", "dx", "si", "di", "bp", "sp",
         "al", "bl", "cl", "dl", "ah", "bh", "ch", "dh")


def diagnose(target_code, target_relocs, cand, cand_relocs):
    """Instruction-aware mismatch diagnostics (no exe needed).

    Returns opcode/operand-class deltas plus focused register, stack-offset,
    and branch-difference notes for prompts and the mismatch classifier.
    """
    t_lines = asm_lines(target_code, target_relocs)
    c_lines = asm_lines(cand, cand_relocs)
    t_ins = _insn_parts(target_code)
    c_ins = _insn_parts(cand)

    def hist(ins, idx):
        out = {}
        for part in ins:
            out[part[idx]] = out.get(part[idx], 0) + 1
        return out

    t_op, c_op = hist(t_ins, 0), hist(c_ins, 0)
    ops = sorted(set(t_op) | set(c_op))
    opcode_delta = {o: c_op.get(o, 0) - t_op.get(o, 0) for o in ops if c_op.get(o, 0) != t_op.get(o, 0)}

    def reg_use(ins):
        out = {}
        for _, o in ins:
            low = " " + o.lower() + " "
            for r in _REGS:
                if re.search(r"\b%s\b" % r, low):
                    out[r] = out.get(r, 0) + 1
        return out

    t_reg, c_reg = reg_use(t_ins), reg_use(c_ins)
    regs = sorted(set(t_reg) | set(c_reg))
    register_delta = {r: c_reg.get(r, 0) - t_reg.get(r, 0) for r in regs if c_reg.get(r, 0) != t_reg.get(r, 0)}

    def stack_offsets(ins):
        return sorted(set(re.findall(r"\[esp \+ ([^\]]+)\]|\[ebp ([+-]) ([^\]]+)\]", " ".join(o for _, o in ins))))
    t_stk = re.findall(r"esp|ebp", " ".join(o for _, o in t_ins).lower())
    c_stk = re.findall(r"esp|ebp", " ".join(o for _, o in c_ins).lower())

    def branches(ins):
        return sum(1 for m, _ in ins if m.startswith("j") and m != "jmp"), \
               sum(1 for m, _ in ins if m == "jmp"), \
               sum(1 for m, _ in ins if m in ("call",))
    t_br, c_br = branches(t_ins), branches(c_ins)
    diff_lines = [l for l in difflib.unified_diff(t_lines, c_lines, "target", "yours", lineterm="", n=3)]
    t_calls = _call_pushes(target_code, target_relocs)
    c_calls = _call_pushes(cand, cand_relocs)
    call_argument_diffs = []
    for i, (target_call, cand_call) in enumerate(zip(t_calls, c_calls)):
        target_args, cand_args = target_call[1][::-1], cand_call[1][::-1]
        immediate_args = all(re.fullmatch(r"(?:0x[0-9a-f]+|-?\d+)", arg, re.I)
                             for arg in target_args + cand_args)
        if (target_call[0] == cand_call[0] and len(target_args) >= 2 and
                len(target_args) == len(cand_args) and target_args != cand_args and immediate_args):
                call_argument_diffs.append({"call": i + 1, "target": target_args, "candidate": cand_args})
    immediate_diffs = []
    stack_offset_diffs = []
    position_aligned = len(t_ins) == len(c_ins) and all(tm == cm for (tm, _), (cm, _) in zip(t_ins, c_ins))
    if position_aligned:
        for i, ((tm, to), (cm, co)) in enumerate(zip(t_ins, c_ins)):
            if tm != cm or tm.startswith("j") or tm == "call":
                continue
            t_nums = re.findall(r"0x[0-9a-f]+|\d+", to, re.I)
            c_nums = re.findall(r"0x[0-9a-f]+|\d+", co, re.I)
            if len(t_nums) != 1 or len(c_nums) != 1 or t_nums[0].lower() == c_nums[0].lower():
                continue
            if re.sub(re.escape(t_nums[0]), "<imm>", to, flags=re.I).lower() == \
                    re.sub(re.escape(c_nums[0]), "<imm>", co, flags=re.I).lower():
                immediate_diffs.append({"instruction": i, "mnemonic": tm,
                                         "target": t_nums[0], "candidate": c_nums[0]})
            if "[esp" in to.lower() or "[ebp" in to.lower():
                stack_offset_diffs.append({"instruction": i, "mnemonic": tm,
                                           "target": t_nums[0], "candidate": c_nums[0]})
    def frame_size(ins):
        for mnemonic, operands in ins:
            if mnemonic == "sub" and operands.startswith("esp, "):
                token = operands.split(", ", 1)[1].strip().rstrip("h")
                try:
                    return int(token, 16) if token.lower().startswith("0x") else int(token)
                except ValueError:
                    return None
        return None
    t_frame, c_frame = frame_size(t_ins), frame_size(c_ins)
    inverted = {"je": "jne", "jne": "je", "jz": "jnz", "jnz": "jz", "jl": "jge", "jge": "jl",
                "jle": "jg", "jg": "jle", "jb": "jae", "jae": "jb", "jbe": "ja", "ja": "jbe",
                "js": "jns", "jns": "js", "jo": "jno", "jno": "jo", "jp": "jnp", "jnp": "jp"}
    branch_condition_diff = (len(t_ins) == len(c_ins) and any(
        inverted.get(tm) == cm for (tm, _), (cm, _) in zip(t_ins, c_ins)) and all(
        tm == cm or inverted.get(tm) == cm for (tm, _), (cm, _) in zip(t_ins, c_ins)))
    t_ret = next((o for m, o in reversed(t_ins) if m == "ret"), None)
    c_ret = next((o for m, o in reversed(c_ins) if m == "ret"), None)
    missing_return_value = None
    for index, (mnemonic, operands) in enumerate(t_ins[:-1]):
        if mnemonic != "mov" or not re.fullmatch(r"eax, (e?[abcd]x|e[sd]i|ebp)", operands):
            continue
        if index < len(t_ins) - 5 or any(m == "mov" and o == operands for m, o in c_ins):
            continue
        if any(m == "pop" for m, _ in t_ins[index + 1:]) and t_ret is not None:
            missing_return_value = {"register": operands.split(",", 1)[1].strip(),
                                    "instruction": index}
            break
    if exact_match(target_code, target_relocs, cand, cand_relocs):
        mismatch = "exact"
    elif call_argument_diffs:
        mismatch = "argument-order mismatch"
    elif immediate_diffs and not stack_offset_diffs:
        mismatch = "immediate/constant mismatch"
    elif branch_condition_diff:
        mismatch = "branch-condition mismatch"
    elif t_ret is not None and c_ret is not None and t_ret != c_ret:
        mismatch = "calling-convention mismatch"
    elif stack_offset_diffs:
        mismatch = "stack-frame/layout mismatch"
    elif missing_return_value:
        mismatch = "missing return value"
    elif (t_br[2] != c_br[2] and (t_op.get("xadd", 0) or c_op.get("xadd", 0))):
        mismatch = "intrinsic/call mismatch"
    elif len(t_ins) != len(c_ins):
        mismatch = "missing/extra instruction"
    elif len(target_code) != len(cand):
        mismatch = "code-size mismatch"
    elif t_stk != c_stk:
        mismatch = "stack-frame/layout mismatch"
    elif t_op == c_op and t_reg != c_reg:
        mismatch = "register allocation difference"
    elif t_op != c_op:
        mismatch = "instruction-selection mismatch"
    else:
        mismatch = "unknown"
    byte_diffs = []
    if len(target_code) == len(cand):
        masked_offsets = {r + i for r in target_relocs + cand_relocs for i in range(4)}
        for offset, (target_byte, candidate_byte) in enumerate(zip(target_code, cand)):
            if offset not in masked_offsets and target_byte != candidate_byte:
                byte_diffs.append({"offset": offset, "target": target_byte, "candidate": candidate_byte})
    return {"exact": exact_match(target_code, target_relocs, cand, cand_relocs),
            "similarity": round(similarity_ratio(target_code, target_relocs, cand, cand_relocs), 4),
            "target_insns": len(t_ins), "cand_insns": len(c_ins),
            "opcode_delta": opcode_delta,
            "register_delta": register_delta,
            "stack_refs": {"target": len(t_stk), "cand": len(c_stk)},
            "branches": {"target_jcc": t_br[0], "cand_jcc": c_br[0],
                         "target_jmp": t_br[1], "cand_jmp": c_br[1],
                         "target_call": t_br[2], "cand_call": c_br[2]},
            "call_argument_diffs": call_argument_diffs,
            "immediate_diffs": immediate_diffs,
            "stack_offset_diffs": stack_offset_diffs,
            "branch_condition_diff": branch_condition_diff,
            "return_cleanup": {"target": t_ret, "candidate": c_ret},
            "frame_size": {"target": t_frame, "candidate": c_frame},
            "missing_return_value": missing_return_value,
            "mismatch_class": mismatch,
            "mismatch_is_hypothesis": mismatch not in ("exact", "argument-order mismatch"),
            "byte_diffs": byte_diffs,
            "diff_preview": diff_lines[:40]}


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


def _single_load(fn):
    lock = threading.Lock()
    @functools.wraps(fn)
    def cached(*args):
        with lock:
            return fn(*args)
    cached.cache_clear = fn.cache_clear
    return cached


@_single_load
@functools.lru_cache(maxsize=None)
def _functions(client):
    rows = {}
    for line in (ROOT / "work" / client / "functions.jsonl").open():
        row = json.loads(line)
        rows[row["addr"]] = row
    return rows


@_single_load
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
    return dict(re.findall(r"(?m)^//\s*roc-(lang|flags|cl|lib|archive):\s*(.+?)\s*$", text))


@functools.lru_cache(maxsize=512)
def compile_text(client, text, flags=None, build=None):
    """Compile source text to COFF bytes with the client's compiler (or `build`)."""
    reject_asm(text)
    entry = clients.load()[client]
    d = directives(text)
    build = build or (int(d["cl"]) if d.get("cl", "").isdigit() else entry["compiler_build"])
    error_key = hashlib.sha1((client + "\0" + str(build) + "\0" + (flags or "") + "\0" + text).encode()).hexdigest()
    known_error = _compile_error_cache().get(error_key)
    if known_error:
        raise CompileError(known_error)
    if "archive" in d:  # exact CRT/STL COFF member from matching installed compiler
        from roc import libs
        recipe, _, path = d["archive"].partition(" ")
        return libs.archive_unit(recipe, path.strip(), build)
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
        try:
            run = subprocess.run([str(cl), "/nologo", "/c", "/Gy", *flags, "/Fo" + str(obj), str(src)],
                                 capture_output=True, text=True, env=env, cwd=tmp, timeout=120)
        except subprocess.TimeoutExpired:
            message = "compiler timeout after 120 seconds"
            _remember_compile_error(error_key, message)
            raise CompileError(message)
        if run.returncode:
            out = (run.stdout + run.stderr).replace(str(src), "source").strip()
            message = "\n".join(l for l in out.splitlines() if l.strip() not in ("f.cpp", "f.c"))
            _remember_compile_error(error_key, message)
            raise CompileError(message)
        return obj.read_bytes()


def check_text(client, addr, text, flags=None, include_diagnosis=False):
    """(score, symbol, asm diff, data spans) for the best function in text vs the target.
    A byte-identical function whose own strings/constants differ from the exe scores 99."""
    code, relocs, _ = target(client, addr)
    obj = compile_text(client, text, flags)
    funcs = coff_functions(obj)
    if not funcs:
        result = (0, None, "no functions compiled (is the function body empty or inline?)", [])
        return result + ({},) if include_diagnosis else result
    best = max(funcs, key=lambda f: score(code, relocs, f[1], f[2]))
    value, d, spans = score(code, relocs, best[1], best[2]), diff(code, relocs, best[1], best[2]), []
    if value == 100:
        spans, bad = data_check(client, addr, code, coff_data_refs(obj, best[0]))
        if bad:
            value, d = 99, "Code matches, but data your source defines does not:\n" + "\n".join(bad)
    result = (value, best[0], d, spans)
    diagnosis = diagnose(code, relocs, best[1], best[2]) if include_diagnosis and value < 100 else {}
    return result + (diagnosis,) if include_diagnosis else result


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
