"""Compile C++ with the client's original cl.exe and diff it against the exe.

Score 100 = byte-identical once relocated fields are masked on both sides.
"""
import difflib
import errno
import contextlib
import functools
from bisect import bisect_left
import hashlib
import json
import os
import re
import shutil
import struct
import subprocess
import tempfile
import threading
import time
import uuid
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


_COMPILE_ERRORS_LOCK = threading.Lock()
_OBJECT_LOCKS = [threading.Lock() for _ in range(32)]


def _compile_error_cache():
    global _COMPILE_ERRORS
    if _COMPILE_ERRORS is None:
        try:
            _COMPILE_ERRORS = json.loads(COMPILE_ERRORS.read_text())
        except (OSError, ValueError):
            _COMPILE_ERRORS = {}
    return _COMPILE_ERRORS


def _remember_compile_error(key, message):
    # Parallel library/STL/submit compiles can fail at the same time; without a
    # lock two threads rewriting the JSON file can truncate or lose entries.
    with _COMPILE_ERRORS_LOCK:
        cache = _compile_error_cache()
        cache[key] = message[-1200:]
        try:
            COMPILE_ERRORS.parent.mkdir(parents=True, exist_ok=True)
            COMPILE_ERRORS.write_text(json.dumps(cache, separators=(",", ":")))
        except OSError:
            pass


@functools.lru_cache(maxsize=32)
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
    starts, ends, labels = {}, {}, {}
    for sec, value, name in syms:
        starts.setdefault(sec, set()).add(value)
        labels.setdefault((sec, value), []).append(name)
    for sec, values in starts.items():
        ordered = sorted(values)
        for value, following in zip(ordered, ordered[1:] + [secs[sec][3]]):
            ends[sec, value] = min(following, secs[sec][3])
    out = []
    for sec, value, name in syms:
        _, _, _, rawsize, rawptr, relptr, _, nrel, _, _ = secs[sec]
        nxt = ends[sec, value]
        # MSVC places embedded catches and the owner's normal continuation in
        # the same section. Their function labels are not owner boundaries.
        while nxt < rawsize and all(label.startswith("__catch$" + name + "$")
                                    for label in labels[sec, nxt]):
            nxt = ends[sec, nxt]
        relocs = [struct.unpack_from("<I", obj, relptr + 10 * k)[0] - value for k in range(nrel)]
        relocs = [r for r in relocs if 0 <= r < nxt - value]
        body = obj[rawptr + value:rawptr + nxt]
        # analyze.py strips trailing int3 from exe functions (padding is
        # indistinguishable); strip the same bytes here so both sides agree.
        body = body[:max([len(body.rstrip(b"\xcc"))] + [r + 4 for r in relocs])]
        out.append((name, body, relocs))
    return out


@functools.lru_cache(maxsize=4)
def _coff_data_index(obj):
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

    functions = {}
    for name, value, section, _ in syms.values():
        if section > 0:
            functions.setdefault(name, (value, section - 1))
    return secs, syms, functions


def coff_data_refs(obj, func_name):
    """Data a function's source defines and points to with absolute (DIR32) relocations:
    [(offset in function, data bytes, reloc offsets inside the data)]. Only data with
    contents in this .obj (string literals, constants, initialised globals) is listed;
    `extern` declarations have none and are not compared."""
    secs, syms, functions = _coff_data_index(obj)

    def relocs_of(sec):
        _, _, _, _, _, relptr, _, nrel, _, _ = secs[sec]
        return [struct.unpack_from("<IIH", obj, relptr + 10 * k) for k in range(nrel)]

    func = functions.get(func_name)
    if func is None:
        return []
    fvalue, fsec = func
    fptr = secs[fsec][4]
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
        # The exe operand is symbol + addend (e.g. [table+4]); start the data there too.
        start = value + struct.unpack_from("<i", obj, fptr + off)[0]
        if not value <= start < nxt:
            continue
        inner = [r - start for r, _, _ in relocs_of(secnum - 1) if start <= r < nxt]
        out.append((off - fvalue, obj[rawptr + start:rawptr + nxt], inner))
    return out


@functools.lru_cache(maxsize=4)
def _relocation_index(relocs):
    return tuple(sorted(relocs))


def data_check(client, addr, code, refs):
    """Compare referenced data against the exe. Returns (matched [(va, len)], mismatch notes)."""
    base, image = _image(client)
    exe_relocs = _relocation_index(frozenset(_base_relocs(client)))
    ok, bad = [], []
    for off, data, inner in refs:
        if off + 4 > len(code):
            continue
        va = int.from_bytes(code[off:off + 4], "little")
        rva = va - base
        if not 0 <= rva < len(image) or not data:
            continue
        exe = bytes(image[rva:rva + len(data)])
        lo, hi = bisect_left(exe_relocs, va), bisect_left(exe_relocs, va + len(data))
        mask = set(inner) | {r - va for r in exe_relocs[lo:hi]}
        if masked(exe, mask) == masked(data, mask):
            ok.append((va, len(data)))
        else:
            bad.append("data at %08x differs: exe %r, yours %r" % (va, exe[:40], data[:40]))
    return ok, bad







@functools.lru_cache(maxsize=None)
def _base_relocs(client):
    from roc.analyze import reloc_sites
    entry = clients.load()[client]
    return frozenset(reloc_sites(pefile.PE(str(clients.exe_path(client, entry)))))




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


def precise_score(client, addr, text, obj=None):
    """Untruncated similarity (e.g. 97.412) of the closest function in text: a search
    tie-breaker that sees sub-percent gains. Acceptance still uses score()/exact bytes."""
    code, relocs, _ = target(client, addr)
    obj = compile_text(client, text) if obj is None else obj
    return max((100.0 if exact_match(code, relocs, f[1], f[2]) else
                100 * similarity_ratio(code, relocs, f[1], f[2]) for f in coff_functions(obj)), default=0.0)


def rank_candidate(target, target_relocs, cand, cand_relocs):
    """Rank near-misses by bytes, then instruction structure.

    Exact bytes remain only acceptance signal; alignment only breaks fuzzy ties.
    """
    value = score(target, target_relocs, cand, cand_relocs)
    if value == 100:
        return (100, 0, 0)
    aligned = align_insns(target, target_relocs, cand, cand_relocs)
    return (value, -aligned["cost"], -abs(len(target) - len(cand)))


# Instruction-alignment penalties (adapted from cpp_permuter's scorer.cpp and
# decomp-permuter's Scorer tiers): register renaming is cheap, argument
# differences cost more, insert/delete cost most, and a matched delete/insert
# pair is a cheap reorder rather than a missing+extra instruction.
ALIGN_PENALTY_REGALLOC = 1
ALIGN_PENALTY_ARGS = 5
ALIGN_PENALTY_DELETE = 100
ALIGN_PENALTY_INSERT = 100
ALIGN_PENALTY_REORDER = 60


def _squash_regs(operands):
    """Registers collapse to r so renaming alone scores as regalloc delta."""
    out = []
    for token in re.split(r"(\W)", operands.lower()):
        out.append("r" if token in _REGS else token)
    return "".join(out)


def align_insns(target, target_relocs, cand, cand_relocs):
    """Needleman-Wunsch alignment of target vs candidate instructions.

    Returns {cost, steps} where steps is the opcode path (same/regalloc/args/
    del/ins/reorder). Never verifies; it only ranks mismatch causes so repair
    hypotheses can be prioritized. A per-byte score stays the verification
    signal via exact_match.
    """
    t_lines = asm_lines(target, target_relocs)
    c_lines = asm_lines(cand, cand_relocs)
    n, m = len(t_lines), len(c_lines)
    if not n and not m:
        return {"cost": 0, "steps": []}
    dp = [0] * ((n + 1) * (m + 1))
    for i in range(n + 1):
        dp[i * (m + 1)] = i * ALIGN_PENALTY_DELETE
    for j in range(m + 1):
        dp[j] = j * ALIGN_PENALTY_INSERT

    def at(i, j):
        return dp[i * (m + 1) + j]

    for i in range(1, n + 1):
        t_mnem, _, t_key = t_lines[i - 1].partition(" ")
        for j in range(1, m + 1):
            c_mnem, _, c_key = c_lines[j - 1].partition(" ")
            best = min(at(i - 1, j) + ALIGN_PENALTY_DELETE,
                       at(i, j - 1) + ALIGN_PENALTY_INSERT)
            if t_mnem == c_mnem:
                if t_key == c_key:
                    sub = 0
                elif _squash_regs(t_key) == _squash_regs(c_key):
                    sub = ALIGN_PENALTY_REGALLOC
                else:
                    sub = ALIGN_PENALTY_ARGS
                best = min(best, at(i - 1, j - 1) + sub)
            dp[i * (m + 1) + j] = best

    steps = []
    i, j = n, m
    while i > 0 or j > 0:
        current = at(i, j)
        if i > 0 and j > 0:
            t_mnem, _, t_key = t_lines[i - 1].partition(" ")
            c_mnem, _, c_key = c_lines[j - 1].partition(" ")
            if t_mnem == c_mnem:
                prev = at(i - 1, j - 1)
                if t_key == c_key and current == prev:
                    steps.append({"op": "same", "i": i - 1, "j": j - 1})
                    i, j = i - 1, j - 1
                    continue
                if _squash_regs(t_key) == _squash_regs(c_key) and \
                        current == prev + ALIGN_PENALTY_REGALLOC:
                    steps.append({"op": "regalloc", "i": i - 1, "j": j - 1})
                    i, j = i - 1, j - 1
                    continue
                if current == prev + ALIGN_PENALTY_ARGS:
                    steps.append({"op": "args", "i": i - 1, "j": j - 1})
                    i, j = i - 1, j - 1
                    continue
        if i > 0 and current == at(i - 1, j) + ALIGN_PENALTY_DELETE:
            steps.append({"op": "del", "i": i - 1})
            i -= 1
        else:
            steps.append({"op": "ins", "j": j - 1})
            j -= 1
    steps.reverse()
    # A delete and an insertion of the identical instruction is a reorder:
    # cheaper than a missing+extra pair.
    cost = at(n, m)
    dels = [s for s in steps if s["op"] == "del"]
    inss = [s for s in steps if s["op"] == "ins"]
    used = set()
    for d in dels:
        for k, ins in enumerate(inss):
            if k in used:
                continue
            if t_lines[d["i"]] == c_lines[ins["j"]]:
                used.add(k)
                d["op"] = ins["op"] = "reorder"
                cost -= ALIGN_PENALTY_DELETE + ALIGN_PENALTY_INSERT - ALIGN_PENALTY_REORDER
                break
    return {"cost": cost, "steps": steps}


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
    from roc import repair
    t_asm, c_asm = "\n".join(t_lines), "\n".join(c_lines)
    flow = {"target": {"blocks": len(repair.blocks(t_asm)),
                        "branch_targets": repair.branch_targets(t_asm),
                        "pressure": repair.block_pressure(t_asm)},
            "candidate": {"blocks": len(repair.blocks(c_asm)),
                          "branch_targets": repair.branch_targets(c_asm),
                          "pressure": repair.block_pressure(c_asm)}}

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
            if "sym" in t_lines[i] or "sym" in c_lines[i]:
                continue  # relocated field: masked when scoring, so never a constant mismatch
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
    receiver_call_diffs = []
    for index in range(min(len(t_ins), len(c_ins)) - 1):
        tm, to = t_ins[index]
        cm, co = c_ins[index]
        if (tm, cm) == ("mov", "push") and to.lower().startswith("ecx,") and \
                index + 1 < len(t_ins) and index + 1 < len(c_ins) and \
                t_ins[index + 1][0] == c_ins[index + 1][0] == "call":
            receiver_call_diffs.append({"instruction": index, "target": to,
                                        "candidate": co, "call": t_ins[index + 1][1]})
        elif tm == "mov" and cm == "call" and to.lower().startswith("ecx,") and \
                index + 1 < len(t_ins) and t_ins[index + 1][0] == "call":
            receiver_call_diffs.append({"instruction": index, "target": to,
                                        "candidate": co, "call": t_ins[index + 1][1],
                                        "direct": True})
    return_carrier_call_diffs = []
    for index in range(len(t_ins) - 2):
        if (t_ins[index][0], t_ins[index][1].lower()) == ("push", "eax") and \
                t_ins[index + 1][0] == "mov" and t_ins[index + 1][1].lower().startswith("ecx,") and \
                t_ins[index + 2][0] == "call":
            if any(c_m == "push" and c_o.lower() in ("0", "0x0") for c_m, c_o in c_ins) and \
                    any(c_m == "mov" and c_o.lower().startswith("al,") for c_m, c_o in c_ins):
                return_carrier_call_diffs.append({"instruction": index,
                                                   "receiver": t_ins[index + 1][1],
                                                   "call": t_ins[index + 2][1],
                                                   "carried": "eax"})
    indirect_call_diffs = []
    for index, ((tm, to), (cm, co)) in enumerate(zip(t_ins, c_ins)):
        if tm == cm == "call" and (to.lower().startswith("dword ptr [") !=
                                    co.lower().startswith("dword ptr [")):
            indirect_call_diffs.append({"instruction": index, "target": to, "candidate": co})
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
    alignment = align_insns(target_code, target_relocs, cand, cand_relocs)
    step_counts = {name: sum(step["op"] == name for step in alignment["steps"])
                   for name in ("same", "regalloc", "args", "del", "ins", "reorder")}
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
    elif step_counts["reorder"] and not step_counts["ins"] and not step_counts["del"] and not step_counts["regalloc"]:
        mismatch = "scheduling-only"
    elif t_op != c_op:
        mismatch = "instruction-selection mismatch"
    else:
        mismatch = "unknown"
    evidence = []
    def add_class(category, confidence, facts):
        evidence.append({"category": category, "confidence": round(confidence, 2),
                         "evidence": facts})
    if mismatch == "exact":
        add_class("exact", 1.0, ["relocation-masked bytes identical"])
    if call_argument_diffs:
        add_class("argument-order mismatch", 0.98, ["decoded immediate push order differs"])
    if t_ret != c_ret:
        add_class("calling-convention mismatch", 0.98, ["ret cleanup differs"])
    if stack_offset_diffs or t_frame != c_frame or t_stk != c_stk:
        add_class("stack-frame/layout mismatch", 0.9, ["stack references or frame size differ"])
    if branch_condition_diff:
        add_class("branch-condition mismatch", 0.95, ["paired conditional branch is inverted"])
    if immediate_diffs:
        add_class("immediate/constant mismatch", 0.94, ["same opcode/shape, numeric operand differs"])
    if step_counts["regalloc"] and not step_counts["args"] and not step_counts["del"] and not step_counts["ins"]:
        add_class("register allocation difference", 0.82,
                  ["alignment pairs same opcodes with register-only operand changes",
                   "register deltas=%s" % sorted(register_delta),
                   "fix to try first: hoist the chained member load into a named local "
                   "(const T* t = obj->field;) before the if/call using it â€” forces MSVC eax chaining; "
                   "fixed 92-93% near-misses in one try (00445e50/00445f10/0059b730/0059b650/0059f310/005ef240)"])
    if step_counts["reorder"] and not step_counts["ins"] and not step_counts["del"] and not step_counts["regalloc"]:
        add_class("scheduling-only", 0.85,
                  ["alignment pairs same opcodes with only instruction order differing",
                   "MSVC scheduler store/save timing; source-level fixes are usually ineffective",
                   "steps: reorder=%d, args=%d" % (step_counts["reorder"], step_counts["args"])])
    if len(t_ins) != len(c_ins):
        add_class("missing/extra instruction", 0.9, ["instruction counts differ"])
    if t_op != c_op:
        add_class("instruction-selection mismatch", 0.78, ["opcode histograms differ"])
    if not evidence and mismatch != "exact":
        add_class("unknown", 0.0, ["no conservative rule matched"])
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
            "receiver_call_diffs": receiver_call_diffs,
            "return_carrier_call_diffs": return_carrier_call_diffs,
            "indirect_call_diffs": indirect_call_diffs,
            "frame_size": {"target": t_frame, "candidate": c_frame},
            "missing_return_value": missing_return_value,
            "mismatch_class": mismatch,
            "classifications": evidence,
            "alignment": {"cost": alignment["cost"], "steps": step_counts},
            "flow": flow,
            "mismatch_is_hypothesis": mismatch not in ("exact", "argument-order mismatch"),
            "byte_diffs": byte_diffs,
            "diff_preview": diff_lines[:40]}


def asm_lines(code, relocs):
    """Disassembly with relocated operands shown as `sym`, for diffs people and LLMs read.
    Direct call/jmp targets outside the function also become `sym`."""
    out = []
    for a, s, m, o in Cs(CS_ARCH_X86, CS_MODE_32).disasm_lite(code, 0):
        if any(a <= r < a + s for r in relocs):
            if m in ("call", "jmp") and re.fullmatch(r"(?:0x[0-9a-f]+|\d+)", o):
                o = "sym"
            else:
                # A COFF field holds only the addend, so capstone prints `push 0` or `[4]`.
                o = re.sub(r"0x[0-9a-f]+|(?<=\[)\d+(?=\])|(?<=, )0$|^\d+$", "sym", o)
        elif m.startswith(("j", "call")) and o.startswith("0x") and not 0 <= int(o, 16) < len(code):
            o = "sym"
        out.append("%s %s" % (m, o))
    return out


# Unchanged lines shown around each hunk; `roc check --context 3` keeps big diffs inside CLI output caps.
DIFF_CONTEXT = 99


def diff(target_code, target_relocs, cand, cand_relocs):
    return "\n".join(difflib.unified_diff(asm_lines(target_code, target_relocs), asm_lines(cand, cand_relocs),
                                          "target", "yours", lineterm="", n=DIFF_CONTEXT))


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
def function_starts(client):
    """Addresses that start a function now, or None when the client is not analyzed.
    Boundary fixes (bounds.json) retire addresses; stored sources for them are orphans."""
    try:
        return set(_functions(client))
    except FileNotFoundError:
        return None


def _functions(client):
    # Cached per file version: every target() call re-parsed 41k lines while holding the file open,
    # so on Windows analyze's atomic replace failed with "Access is denied" whenever checks ran.
    path = ROOT / "work" / client / "functions.jsonl"
    stat = path.stat()
    return _functions_at(path, stat.st_mtime_ns, stat.st_size)


@_single_load
@functools.lru_cache(maxsize=8)
def _functions_at(path, mtime_ns, size):
    rows = {}
    for line in path.read_text().splitlines():
        row = json.loads(line)
        rows[row["addr"]] = row
    return rows


@_single_load
@functools.lru_cache(maxsize=None)
@functools.lru_cache(maxsize=4)  # the mapped exe is immutable; remapping it per target() call dominated scans
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
    if row.get("kind") == "data":
        raise CompileError("%s %s is reviewed data, not a function" % (client, addr))
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
        raise CompileError('#import, #using, #include "file" and #pragma comment are not allowed. '
                           'Use // roc-lib: RECIPE relative/file.cpp for authentic vendor sources; '
                           'generate the candidate with libs.source_for. Register edited vendor units with libs.add_unit.')


def directives(text):
    """`// roc-<key>: value` lines: lang (c|cpp), flags, cl (compiler build), lib (recipe + file).
    Library code matched with its own build settings carries them, so anyone re-checks it the same way."""
    return dict(re.findall(r"(?m)^//[ \t]*roc-(lang|flags|cl|lib|archive):[ \t]*(\S.*?)[ \t]*$", text))


def compile_text(client, text, flags=None, build=None):
    """Compile source text to COFF bytes with the client's compiler (or `build`).
    Results and remembered errors are keyed on the text after library expansion, so an
    edited vendor header (tracked by libs.unit) never replays a stale object or error."""
    reject_asm(text)
    entry = clients.load()[client]
    d = directives(text)
    library_prelude_includes = "lib" in d and bool(re.search(r"(?m)^\s*#\s*include\b", text))
    build = build or (int(d["cl"]) if d.get("cl", "").isdigit() else entry["compiler_build"])
    if "archive" in d:  # exact CRT/STL COFF member from matching installed compiler
        from roc import libs
        recipe, _, path = d["archive"].partition(" ")
        return libs.archive_unit(recipe, path.strip(), build)
    if "lib" in d:  # library file: rebuilt from the pinned, hash-checked source in tools/libs
        from roc import libs
        recipe, _, path = d["lib"].partition(" ")
        try:
            body = libs.unit(recipe, path.strip(), build)
            # Metadata-only wrappers expand to the same preprocessed C++ regardless
            # of address/author comments. Settings are already captured in d.
            metadata_only = all(not line.strip() or (line.strip().startswith("//") and
                                not line.rstrip().endswith("\\")) for line in text.splitlines())
            text = body if metadata_only else "%s\n%s" % (text, body)
        except SystemExit as error:  # local-only tree (e.g. rbxgs) not on this PC
            raise CompileError(str(error))
    flags = flags or d.get("flags") or entry.get("flags") or DEFAULT_FLAGS
    compile_fn = _compile if _cacheable(text) else _compile_uncached
    try:
        return compile_fn(text, flags, build, d.get("lang") == "c")
    except CompileError as error:
        if library_prelude_includes and "C1083" in str(error):
            raise CompileError(str(error) + "\nThe roc-lib candidate contains raw includes outside its preprocessed unit. "
                "Those lines do not receive recipe include paths. For vendor header/body changes, "
                "register the complete unit with libs.add_unit and reference it with libs.source_for.") from error
        raise


@contextlib.contextmanager
def compile_directory():
    if os.name != "nt":
        with tempfile.TemporaryDirectory() as directory:
            yield directory
        return
    # Python's mode-0700 temp directories discard inherited Windows sandbox ACLs.
    directory = Path(tempfile.gettempdir()) / ("roc-compile-" + uuid.uuid4().hex)
    directory.mkdir(mode=0o777)
    try:
        yield str(directory)
    finally:
        shutil.rmtree(directory)


# Expanded native TUs can be megabytes; persistent objects handle older reuse.
@functools.lru_cache(maxsize=32)
def _compile(text, flags, build, c_lang):
    key = hashlib.sha256(json.dumps([1, text, flags, build, c_lang]).encode()).hexdigest()
    if not _cacheable(text):
        return _compile_uncached(text, flags, build, c_lang)  # Unexpanded headers have untracked dependencies.
    cache = ROOT / "work" / "object-cache" / (key + ".obj")
    with _OBJECT_LOCKS[int(key[:8], 16) % len(_OBJECT_LOCKS)], _object_lock(cache):
        if cache.exists():
            return cache.read_bytes()
        started = time.monotonic()
        obj = _compile_uncached(text, flags, build, c_lang)
        cache.parent.mkdir(parents=True, exist_ok=True)
        tmp = cache.with_suffix(".%s.tmp" % uuid.uuid4().hex)
        tmp.write_bytes(obj)
        os.replace(tmp, cache)
        from roc import telemetry
        telemetry.record("compiler", event="timing", phase="compile", build=build,
                         source_hash=key, seconds=time.monotonic() - started)
        return obj


@contextlib.contextmanager
def _object_lock(cache):
    """One compiler per key across CLI processes; OS releases locks after a crash."""
    cache.parent.mkdir(parents=True, exist_ok=True)
    with cache.with_suffix(".lock").open("a+b") as stream:
        if os.name == "nt":
            import msvcrt
            started = time.monotonic()
            while True:
                stream.seek(0)
                try:
                    msvcrt.locking(stream.fileno(), msvcrt.LK_NBLCK, 1)
                    break
                except OSError as error:
                    if error.errno not in (errno.EACCES, errno.EAGAIN, errno.EDEADLK) or time.monotonic() - started > 130:
                        raise
                    time.sleep(.1)
        else:
            import fcntl
            fcntl.flock(stream, fcntl.LOCK_EX)
        try:
            yield
        finally:
            if os.name == "nt":
                stream.seek(0)
                msvcrt.locking(stream.fileno(), msvcrt.LK_UNLCK, 1)
            else:
                fcntl.flock(stream, fcntl.LOCK_UN)


def _compile_uncached(text, flags, build, c_lang):
    error_key = hashlib.sha256(json.dumps([build, flags, c_lang, text]).encode()).hexdigest()
    known_error = _compile_error_cache().get(error_key) if _cacheable(text) else None
    if known_error:
        raise CompileError(known_error)
    cl = setup.compilers().get(build)
    if not cl:
        raise SystemExit("Missing compiler build %s. Run: roc install" % build)
    env = setup.cl_env(cl)
    if re.search(r"(?m)^\s*#\s*include\s*<Ogre[A-Za-z0-9_]*\.h>", text):
        ogre = setup.TOOLS / "libs" / "ogre-1.4.5" / "ogrenew" / "OgreMain" / "include"
        if not (ogre / "Ogre.h").is_file():
            raise CompileError("Missing Ogre 1.4.5 headers: %s" % ogre)
        from roc import libs
        sdk = libs.winsdk_include()
        if not sdk:
            raise CompileError("Missing WinSDK/Include in tools/; run roc install")
        paths = [env.get("INCLUDE", ""), setup.cl_path(ogre), setup.cl_path(sdk)]
        env["INCLUDE"] = ";".join(p for p in paths if p)
    with compile_directory() as tmp:
        src, obj = Path(tmp) / ("f.c" if c_lang else "f.cpp"), Path(tmp) / "f.obj"
        src.write_text(text)
        try:
            run = subprocess.run([*setup.cl_command(cl), "/nologo", "/c", "/Gy", *flags.split(),
                                  "/Fo" + setup.cl_path(obj), setup.cl_path(src)],
                                 capture_output=True, text=True, env=env, cwd=tmp, timeout=120)
        except subprocess.TimeoutExpired:
            message = "compiler timeout after 120 seconds"
            if _cacheable(text):
                _remember_compile_error(error_key, message)
            raise CompileError(message)
        from roc import telemetry
        telemetry.command(list(run.args), tmp, run)
        if run.returncode:
            out = run.stdout + run.stderr
            for shown in {str(src), setup.cl_path(src)}:  # Wine echoes the Z:\ form
                out = out.replace(shown, "source")
            out = out.strip()
            message = "\n".join(l for l in out.splitlines() if l.strip() not in ("f.cpp", "f.c"))
            if _cacheable(text):
                _remember_compile_error(error_key, message)
            raise CompileError(message)
        return obj.read_bytes()


def _cacheable(text):
    return not re.search(r"(?m)^\s*#\s*include\b|\b__(?:DATE|TIME|TIMESTAMP)__\b", text)


compile_text.cache_clear = _compile.cache_clear


def alignment_evidence(client, addr, src, flags=None):
    """Instruction-alignment evidence for one source vs its target (or None).

    Used to rank permutation hypotheses; never verifies matches.
    """
    try:
        code, relocs, _ = target(client, addr)
        obj = compile_text(client, src, flags)
        funcs = coff_functions(obj)
        if not funcs:
            return None
        best = max(funcs, key=lambda f: rank_candidate(code, relocs, f[1], f[2]))
        return align_insns(code, relocs, best[1], best[2])
    except (CompileError, ValueError):
        return None


def select_exact_data(client, addr, code, obj, candidates):
    """Choose a code-exact symbol whose referenced data also matches."""
    first = None
    for candidate in candidates:
        spans, bad = data_check(client, addr, code, coff_data_refs(obj, candidate[0]))
        if first is None:
            first = candidate, spans, bad
        if not bad:
            return candidate, spans, bad
    return first


def check_text(client, addr, text, flags=None, include_diagnosis=False, obj=None, minimum=None):
    """(score, symbol, asm diff, data spans) for the best function in text vs the target.
    A byte-identical function whose own strings/constants differ from the exe scores 99.
    With minimum set, return a None score when no candidate can improve it; exact
    and referenced-data verification remain unchanged. This avoids fuzzy work on
    candidates whose length or byte-count upper bound cannot beat the stored best."""
    code, relocs, _ = target(client, addr)
    obj = compile_text(client, text, flags) if obj is None else obj
    funcs = coff_functions(obj)
    if not funcs:
        result = (0, None, "no functions compiled (is the function body empty or inline?)", [])
        return result + ({},) if include_diagnosis else result
    scored = []
    for function in funcs:
        if minimum is not None and not exact_match(code, relocs, function[1], function[2]):
            if minimum >= 99:
                continue
            length = len(code) + len(function[1])
            if length and int(200 * min(len(code), len(function[1])) / length) <= minimum:
                continue
            mask = set(relocs) | set(function[2])
            upper = difflib.SequenceMatcher(None, masked(code, mask), masked(function[1], mask), autojunk=False).quick_ratio()
            if int(100 * upper) <= minimum:
                continue
        value = score(code, relocs, function[1], function[2])
        if minimum is None or value > minimum:
            scored.append((value, function))
    if not scored:
        result = (None, None, "no compiled candidate exceeds score %s" % minimum, [])
        return result + ({},) if include_diagnosis else result
    highest = max(value for value, _ in scored)
    # Alignment only breaks byte-score ties; don't align losing candidates.
    best = max((f for value, f in scored if value == highest),
               key=lambda f: rank_candidate(code, relocs, f[1], f[2]))
    value, d, spans = score(code, relocs, best[1], best[2]), diff(code, relocs, best[1], best[2]), []
    bad = []
    if value == 100:
        exacts = [best] + [f for score_value, f in scored if score_value == 100 and f is not best]
        best, spans, bad = select_exact_data(client, addr, code, obj, exacts)
        d = diff(code, relocs, best[1], best[2])
        if bad:
            value, d = 99, "Code matches, but data your source defines does not:\n" + "\n".join(bad)
    from roc import telemetry
    telemetry.candidate(text, value)
    result = (value, best[0], d, spans)
    diagnosis = diagnose(code, relocs, best[1], best[2]) if include_diagnosis and value < 100 else {}
    if include_diagnosis and bad:
        diagnosis.update(exact=False, code_exact=True, mismatch_class="referenced-data mismatch",
                         data_mismatches=bad, classifications=[{
                             "category": "referenced-data mismatch", "confidence": 1.0, "evidence": bad}])
    return result + (diagnosis,) if include_diagnosis else result


def save_data(client, addr, spans):
    """Record verified data (va, length) per function in work/<client>/data.json."""
    if not spans:
        return
    path = ROOT / "work" / client / "data.json"
    with _object_lock(path):
        data = json.loads(path.read_text()) if path.exists() else {}
        data[addr] = spans
        tmp = path.with_suffix(".%s.tmp" % uuid.uuid4().hex)
        tmp.write_text(json.dumps(data, separators=(",", ":")))
        os.replace(tmp, path)


def check(client, addr, src, flags=None):
    return check_text(client, addr, Path(src).read_text(errors="replace"), flags)


_SCORES_LOCK = threading.Lock()


def save_score(client, addr, value):
    """Keep the best score per function in work/<client>/scores.json."""
    path = ROOT / "work" / client / "scores.json"
    with _SCORES_LOCK:
        scores = json.loads(path.read_text()) if path.exists() else {}
        if value > scores.get(addr, 0):
            scores[addr] = value
            path.parent.mkdir(parents=True, exist_ok=True)
            tmp = path.with_name("scores.%d.tmp" % os.getpid())  # replace atomically: readers never see a half file
            tmp.write_text(json.dumps(scores, indent=0, sort_keys=True))
            os.replace(tmp, path)
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
