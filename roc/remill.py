"""Thin integration around Remill's example 32-bit x86 lifter.

Remill is used only as an evidence source: it gives a verified LLVM IR model of
the original bytes. The IR is summarised into a compact packet for RoConstruct's
existing C++ reconstruction and checked with the original MSVC toolchain.
"""
import hashlib
import json
import re
import subprocess
import time
from pathlib import Path

from roc import draft, match

REMILL_EXE = Path(r"C:\Users\colin\remill\build-remill-1440\bin\lift\remill-lift-17.exe")
LLVM_BIN = Path(r"C:\Users\colin\remill\dependencies\install\bin")
OPT_EXE = LLVM_BIN / "opt.exe"

def remill_available():
    return REMILL_EXE.is_file() and OPT_EXE.is_file()

def _paths(client, addr, out_dir=None):
    out_dir = Path(out_dir) if out_dir else (Path(match.ROOT) / "work" / client / "lifted" / addr)
    out_dir.mkdir(parents=True, exist_ok=True)
    return out_dir, {
        "ll": out_dir / ("%s.ll" % addr),
        "bc": out_dir / ("%s.bc" % addr),
        "pre": out_dir / ("%s.pre.ll" % addr),
        "summary": out_dir / ("%s.summary.json" % addr),
        "text": out_dir / ("%s.summary.txt" % addr),
    }

def _cfg(client, addr):
    code, relocs, row = match.target(client, addr)
    va = int(addr, 16)
    lines = match.disasm(code, va)
    facts = draft.cfg_facts(lines)
    indirect = 0
    calls = 0
    for line in lines:
        text = line.split(None, 2)[-1] if isinstance(line, str) else ""
        low = text.lower()
        if "call" in low:
            calls += 1
            if "dword ptr" in low or not re.search(r"\bcall\s+(?:0x)?[0-9a-f]{6,}\b", low):
                indirect += 1
    original_branches = sum(1 for b in facts.get("blocks", [])
                            for e in b.get("edges", []) if e.get("kind") == "branch")
    original_returns = len(facts.get("returns", []))
    original_cfg_blocks = len(facts.get("blocks", [])) or 1
    return (code, relocs, row, va, lines, facts, calls, indirect,
            original_cfg_blocks, original_branches, original_returns)

def summarize_ir(text, addr, original_cfg_blocks, indirect_calls,
                 original_branches=0, original_returns=0):
    labels = re.findall(r"(?m)^\s*(?:\d+|[A-Za-z_][\w.]*)\s*:\s*(?:;.*)?$", text)
    blocks = len(labels)
    br = len(re.findall(r"\bbr\b", text))
    ret = len(re.findall(r"\bret\b", text))
    loads = len(re.findall(r"\bload\b", text))
    stores = len(re.findall(r"\bstore\b", text))
    calls = len(re.findall(r"\bcall\b", text))
    helpers = sorted(set(re.findall(r"@__remill_[A-Za-z0-9_]*", text)))
    arith_ops = ["add", "sub", "mul", "and", "or", "xor", "shl", "lshr", "ashr"]
    arith = sum(len(re.findall(r"\b" + op + r"\b", text)) for op in arith_ops)
    constants = []
    for match_imm in re.finditer(r"\bi32\s+(-?\d+)\b", text):
        value = match_imm.group(1)
        if value not in constants:
            constants.append(value)
        if len(constants) >= 20:
            break
    verified_structure = (ret >= max(1, original_returns))
    unresolved = []
    if indirect_calls:
        unresolved.append("original has %d opaque/indirect call site(s); Remill exposes them as state/memory operations, not named calls" % indirect_calls)
    if original_branches and br < original_branches:
        unresolved.append("branch coverage may be incomplete: original CFG has %d branches, IR has %d br terminators (IR is instruction-granular, so this is only a sanity check)" % (original_branches, br))
    if not verified_structure:
        unresolved.append("return count differs from original CFG (%d vs %d)" % (ret, original_returns))
    if not unresolved:
        unresolved.append("no unresolved items recorded by the static coverage checks")
    summary = {
        "address": "0x" + addr.lower().replace("0x", "").zfill(8),
        "original_cfg_blocks": original_cfg_blocks,
        "original_branches": original_branches,
        "original_returns": original_returns,
        "indirect_calls": indirect_calls,
        "ir_basic_blocks": blocks,
        "ir_branch_terms": br,
        "ir_returns": ret,
        "ir_loads": loads,
        "ir_stores": stores,
        "ir_calls": calls,
        "ir_arithmetic": arith,
        "ir_helpers": helpers[:25],
        "constants_sample": constants,
        "structure_verified": verified_structure,
        "unresolved": unresolved,
    }
    text_lines = [
        "Remill lifted summary",
        "=====================",
        "function: 0x%s" % addr.lower().replace("0x", "").zfill(8),
        "original CFG: %d basic blocks, %d branches, %d returns" % (original_cfg_blocks, original_branches, original_returns),
        "indirect/opaque calls in original: %d" % indirect_calls,
        "IR (instruction-granular): %d basic blocks, %d br, %d ret" % (blocks, br, ret),
        "IR memory: %d load, %d store" % (loads, stores),
        "IR calls/helpers: %d (%d unique helper families)" % (calls, len(helpers)),
        "IR arithmetic: %d" % arith,
        "constants (sample): %s" % (", ".join(constants[:12]) if constants else "none"),
        "helpers (sample): %s" % (", ".join(helpers[:8]) if helpers else "none"),
        "structure verified: %s" % ("yes" if verified_structure else "no"),
        "unresolved: " + "; ".join(unresolved),
        "",
        "Compact semantic packet for C++ reconstruction:",
        "- %d source lines lowered to LLVM IR and verified with LLVM 17 opt." % len(text.splitlines()),
        "- Use original disassembly for names/ABI; use CFG, branches, loads/stores and constants above for structure.",
    ]
    return summary, "\n".join(text_lines)

def lift_function(client, addr, out_dir=None, timeout=180):
    addr = addr.lower().replace("0x", "").zfill(8)
    if not remill_available():
        raise RuntimeError("Remill or LLVM opt is not available at the configured paths")
    addr = addr.lower().replace("0x", "").zfill(8)
    code, relocs, row, va, lines, facts, calls, indirect, cfg_blocks, branches, returns = _cfg(client, addr)
    original_cfg_blocks = cfg_blocks
    code_sha = hashlib.sha256(code).hexdigest()
    lifter_mtime = REMILL_EXE.stat().st_mtime if REMILL_EXE.is_file() else 0
    addr_norm = addr.lower().replace("0x", "").zfill(8)
    out_dir, paths = _paths(client, addr_norm, out_dir)
    summary_path = paths["summary"]
    if summary_path.is_file() and paths["ll"].is_file() and paths["bc"].is_file():
        cached = json.loads(summary_path.read_text(encoding="utf-8"))
        if (cached.get("code_sha256") == code_sha
                and cached.get("lifter_path") == str(REMILL_EXE)
                and cached.get("lifter_mtime") == lifter_mtime
                and cached.get("verified") is True):
            compact = paths["text"].read_text(encoding="utf-8") if paths["text"].is_file() else ""
            return cached, compact, paths
    cmd = [
        str(REMILL_EXE),
        "--arch=x86",
        "--os=windows",
        "--address=%d" % va,
        "--entry_address=%d" % va,
        "--bytes=%s" % code.hex(),
        "--ir_out=%s" % paths["ll"],
        "--bc_out=%s" % paths["bc"],
        "--ir_pre_out=%s" % paths["pre"],
    ]
    started = time.time()
    proc = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout)
    verified = False
    verify_error = ""
    if paths["bc"].is_file():
        try:
            v = subprocess.run([str(OPT_EXE), "-passes=verify", "-disable-output", str(paths["bc"])],
                               capture_output=True, text=True, timeout=120)
            verified = (v.returncode == 0)
            verify_error = (v.stderr or v.stdout or "").strip()
        except (OSError, subprocess.TimeoutExpired) as error:
            verify_error = str(error)
    text = paths["ll"].read_text(errors="replace") if paths["ll"].is_file() else ""
    summary, compact = summarize_ir(text, addr, original_cfg_blocks, indirect,
                                    original_branches=branches, original_returns=returns)
    summary.update({
        "client": client,
        "code_sha256": code_sha,
        "lifter_path": str(REMILL_EXE),
        "lifter_mtime": lifter_mtime,
        "size": row["size"],
        "function": row.get("unit"),
        "returncode": proc.returncode,
        "elapsed_seconds": round(time.time() - started, 2),
        "verified": verified,
        "verify_error": verify_error[:500],
        "stdout_tail": (proc.stdout or "")[-500:],
        "stderr_tail": (proc.stderr or "")[-800:],
        "ir_path": str(paths["ll"]),
        "bc_path": str(paths["bc"]),
        "pre_path": str(paths["pre"]),
    })
    paths["summary"].write_text(json.dumps(summary, indent=2), encoding="utf-8")
    paths["text"].write_text(compact + "\n", encoding="utf-8")
    return summary, compact, paths

def latest_summary(client, addr):
    addr = addr.lower().replace("0x", "").zfill(8)
    path = Path(match.ROOT) / "work" / client / "lifted" / addr / ("%s.summary.json" % addr)
    if not path.is_file():
        return None
    return json.loads(path.read_text(encoding="utf-8"))
