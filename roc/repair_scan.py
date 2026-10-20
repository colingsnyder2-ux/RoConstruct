"""Single-immediate scanner: near-misses whose only real residue is one constant.

When a near-miss has one numeric operand difference, report the observed target
value. Trace its meaning before changing source: stack/EH bookkeeping requires
lifetime/ABI evidence, and an indirect-call offset may be a virtual slot.
"""
import json
import re
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

from roc import match, worker

ROOT = Path(__file__).resolve().parent.parent
IMM_RE = re.compile(r"(?<!\w)-?(?:0x[0-9a-f]+|\d+)(?!\w)", re.I)


def _residue_pairs(diff):
    """(target_line, ours_line) instruction pairs that differ beyond masking."""
    pairs = []
    target, ours = [], []
    for line in diff.splitlines() + [" "]:
        if line.startswith(("---", "+++")):
            continue
        if line.startswith("-"):
            target.append(line[1:])
        elif line.startswith("+"):
            ours.append(line[1:])
        else:
            pairs.extend((target[i] if i < len(target) else "",
                          ours[i] if i < len(ours) else "")
                         for i in range(max(len(target), len(ours))))
            target, ours = [], []
    # A masked relocation (`push sym` vs `push 0`) is not residue.
    real = [p for p in pairs if not (p[1].strip() in ("push 0", "mov eax, sym") and "sym" in p[0])]
    real = [(t, o) for t, o in real if not (re.sub(r"sym|0x[0-9a-f]+|\b\d+\b", "", t).strip() ==
                                            re.sub(r"sym|0x[0-9a-f]+|\b\d+\b", "", o).strip()
                                            and t.replace("sym", "0") == o)]
    return real


def _single_immediate(pair):
    """The differing constant when a pair differs in exactly one immediate."""
    t, o = pair
    if not t or not o:
        return None
    if t.split()[0] != o.split()[0]:  # different mnemonic: not an immediate fix
        return None
    t_consts, o_consts = list(IMM_RE.finditer(t)), list(IMM_RE.finditer(o))
    if len(t_consts) != len(o_consts):
        return None
    changed = [(a, b) for a, b in zip(t_consts, o_consts) if a.group().lower() != b.group().lower()]
    if len(changed) != 1:
        return None
    a, b = changed[0]
    # Same instruction modulo that one constant.
    if t[:a.start()] + "<c>" + t[a.end():] != o[:b.start()] + "<c>" + o[b.end():]:
        return None
    return {"target": t, "ours": o, "target_value": a.group(), "ours_value": b.group()}


def scan_one(client, addr, source_text):
    try:
        score, symbol, diff, _ = match.check_text(client, addr, source_text)
    except match.CompileError:
        return None
    except Exception:
        return None  # server/unit-fetch outages must not kill the whole scan
    if score >= 100:
        return None
    real = _residue_pairs(diff)
    fixes = [f for f in map(_single_immediate, real) if f]
    if len(real) == 1 and len(fixes) == 1:
        return {"addr": addr, "score": score, "fix": fixes[0], "residue_count": len(real)}
    return None


def scan(client, min_score=95, max_score=99, jobs=None, server=None, token=None):
    """Every near-miss whose only residue is one wrong constant, target value included."""
    import os
    scores = ({r["addr"]: r["score"] for r in worker.Api(server, token).call(
        "/v1/sources?scores=1&client=" + client, timeout=120)} if server else
        json.loads((ROOT / "work" / client / "scores.json").read_text()))
    src_dir = ROOT / "src" / client
    tasks = []
    with (ROOT / "work" / client / "functions.jsonl").open(encoding="utf-8") as stream:
        for line in stream:
            row = json.loads(line)
            addr = row["addr"]
            if row.get("kind", "code") != "code" or not min_score <= scores.get(addr, 0) <= min(max_score, 99):
                continue
            src = src_dir / ("%s.cpp" % addr)
            if server or src.exists():
                tasks.append((addr, None if server else src.read_text(encoding="utf-8", errors="replace"), row.get("unit", "")))
    def check(addr, text):
        if server:
            row = worker.Api(server, token).call("/v1/source?client=" + client + "&addr=" + addr, timeout=120)
            if not min_score <= row["score"] <= min(max_score, 99):
                return None  # Another worker may have finished it after the initial snapshot.
            text = row["source"]
        return scan_one(client, addr, text)
    out = []
    jobs = jobs or int(os.environ.get("ROC_JOBS") or 0) or min(8, os.cpu_count() or 4)
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        futures = {pool.submit(check, addr, text): unit for addr, text, unit in tasks}
        for future in as_completed(futures):
            hit = future.result()
            if hit:
                hit["unit"] = futures[future]
                out.append(hit)
    out.sort(key=lambda r: -r["score"])
    return out
