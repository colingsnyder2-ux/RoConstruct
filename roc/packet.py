"""Compact, token-bounded candidate packet.

A packet is cheap: it reads the target's binary facts, any stored source, the
local/served diff, similar matched siblings, research lessons and recent failed
hypotheses.  It never forces Rev.ng or Remill.  Every field states its evidence
level so a hypothesis is not mistaken for a confirmed offset, declaration or
ABI.
"""
import difflib
import hashlib
import json
import re
from pathlib import Path

from roc import claims as claim_state
from roc import draft, match, research

PROVEN = "proven binary"
OBSERVED = "observed compiler diff"
HYPOTHESIS = "hypothesis"
UNKNOWN = "unknown"


def _norm(addr):
    return str(addr).lower().replace("0x", "").zfill(8)


def _strip_comments(source):
    return re.sub(r"//[^\n]*|/\*.*?\*/", "", source or "", flags=re.S)


def _source(client, addr, api=None, root=None):
    """Best stored source with provenance; never invents one."""
    root = Path(root or match.ROOT)
    path = root / "src" / client / (addr + ".cpp")
    if path.is_file():
        return path.read_text(encoding="utf-8", errors="replace"), "local src/%s/%s.cpp" % (client, addr), 0
    if api is not None:
        try:
            row = api.call("/v1/source?client=%s&addr=%s" % (client, addr), timeout=20) or {}
        except RuntimeError:
            row = {}
        if row.get("source"):
            return row["source"], "server best source", int(row.get("score") or 0)
    return "", "none", 0


def _similar(client, addr, row, root=None, limit=5, band=0.25):
    root = Path(root or match.ROOT)
    path = root / "work" / client / "functions.jsonl"
    scores_path = root / "work" / client / "scores.json"
    if not path.exists():
        return []
    scores = json.loads(scores_path.read_text()) if scores_path.exists() else {}
    want = row.get("shape", "").split(" ; ")
    out = []
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        try:
            other = json.loads(line)
        except ValueError:
            continue
        if other.get("addr") in (None, addr) or other.get("kind", "code") != "code":
            continue
        if scores.get(other["addr"]) != 100:
            continue
        if row.get("size") and abs(other.get("size", 0) - row["size"]) > row["size"] * band:
            continue
        ratio = difflib.SequenceMatcher(None, want, other.get("shape", "").split(" ; "),
                                        autojunk=False).ratio()
        src = root / "src" / client / (other["addr"] + ".cpp")
        out.append({"addr": other["addr"], "size": other.get("size"), "shape_ratio": round(ratio, 3),
                    "source_available": src.exists(),
                    "source_path": str(src.relative_to(root)) if src.exists() else None,
                    "confidence": PROVEN})
    out.sort(key=lambda item: (-item["shape_ratio"], item["addr"]))
    return out[:limit]


def _lessons(unit=None, addr=None, limit=3, root=None):
    root = Path(root or match.ROOT)
    path = root / "research" / "lessons.json"
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return []
    rows = data if isinstance(data, list) else list(data.values()) if isinstance(data, dict) else []
    terms = [term.lower() for term in re.findall(r"[A-Za-z_][A-Za-z0-9_:]{3,}", unit or "")][:6]
    scored = []
    for row in rows:
        text = json.dumps(row, ensure_ascii=True).lower()
        score = sum(1 for term in terms if term in text)
        if addr and addr.lower() in text:
            score += 5
        if score:
            scored.append((score, row))
    scored.sort(key=lambda pair: -pair[0])
    out = []
    for _score, row in scored[:limit]:
        if not isinstance(row, dict):
            out.append({"title": str(row)[:80], "lesson": str(row)[:600], "confidence": HYPOTHESIS})
            continue
        out.append({"title": row.get("title") or row.get("id") or row.get("name"),
                    "lesson": (row.get("lesson") or row.get("text") or row.get("hypothesis")
                               or row.get("change") or "")[:600],
                    "confidence": PROVEN if row.get("receipt") else HYPOTHESIS})
    return out


def _failed(client, addr, limit=5, root=None):
    path = Path(root or match.ROOT) / "work" / "agent-memory" / "attempts.jsonl"
    try:
        lines = path.read_text(encoding="utf-8", errors="replace").splitlines()[-20000:]
    except OSError:
        return []
    out = []
    for line in reversed(lines):
        try:
            row = json.loads(line)
        except ValueError:
            continue
        addrs = row.get("addresses") or ([row.get("addr")] if row.get("addr") else [])
        if row.get("client") not in (None, client) or addr not in {_norm(a) for a in addrs}:
            continue
        if row.get("after") == 100:
            continue
        hypothesis = (row.get("hypothesis") or row.get("change") or row.get("summary") or "")[:300]
        if any(seen["hypothesis"] == hypothesis for seen in out):
            continue  # the same idea retried is one failed hypothesis
        out.append({"kind": row.get("kind"), "hypothesis": hypothesis,
                    "score": row.get("after"), "result": row.get("outcome") or row.get("result"),
                    "source_hash": row.get("source_hash"), "model": row.get("model"),
                    "confidence": OBSERVED})
        if len(out) >= limit:
            break
    return out


def _first_hunk(diff, max_lines=24):
    """The leading hunks (each `@@` block) up to max_lines in total: one hunk is often
    a lone prologue difference while the real residue sits further down."""
    lines = (diff or "").splitlines()
    start = next((i for i, line in enumerate(lines) if line.startswith("@@")), None)
    if start is None:
        return "\n".join(lines[:max_lines])
    out = []
    for line in lines[start:]:
        if len(out) >= max_lines:
            break
        out.append(line)
    return "\n".join(out)


def _residue(diff, context=2, max_lines=40):
    """Changed lines with `context` unchanged lines around each, from a wide-context diff."""
    lines = [line for line in (diff or "").splitlines() if not line.startswith(("---", "+++", "@@"))]
    changed = [i for i, line in enumerate(lines) if line[:1] in "+-"]
    keep = sorted({j for i in changed for j in range(i - context, i + context + 1) if 0 <= j < len(lines)})
    out, last = [], None
    for j in keep:
        if last is not None and j != last + 1:
            out.append("@@")
        out.append(lines[j])
        last = j
    if len(out) > max_lines:
        out = out[:max_lines] + ["... %d more residue lines" % (len(out) - max_lines)]
    return "\n".join(["@@"] + out) if out else ""


def _facts(row, asm):
    try:
        facts = draft.facts_from_asm(asm)
    except Exception:
        facts = {}
    keys = ("calls", "branch_count", "calling_convention", "ret_args", "this_offsets",
            "imports", "direct_calls", "returns", "needs_destructor_care", "alloc_calls")
    return {key: facts.get(key) for key in keys if key in facts}


def build(client, addr, api=None, root=None, max_tokens=2000, include_diff=True,
          similar_limit=5, check=True, flags=None):
    """Build the packet.  Compilation is optional (``include_diff``) and cached
    by the existing object cache; no lifter is invoked."""
    addr = _norm(addr)
    root = Path(root or match.ROOT)
    max_chars = max(400, int(max_tokens) * 4)
    code, relocs, row = match.target(client, addr)
    asm = match.disasm(code, int(addr, 16))
    facts = _facts(row, asm)
    try:
        data_facts = draft.target_data_facts(client, code, relocs)
    except Exception:
        data_facts = {}
    target = {
        "address": addr, "size": row.get("size"), "unit": row.get("unit"),
        "shape": row.get("shape"), "family": row.get("family"),
        "code_sha256": hashlib.sha256(code).hexdigest(),
        "asm": list(asm)[:120], "facts": facts, "data_facts": data_facts,
        "confidence": PROVEN,
    }
    source, origin, source_score = _source(client, addr, api, root)
    score = int(row.get("score") or source_score or 0)
    diff = None
    if source and include_diff and check:
        try:
            checked = match.check_text(client, addr, source, flags, include_diagnosis=True)
            measured = checked[0]
            diagnosis = checked[4] if len(checked) > 4 and isinstance(checked[4], dict) else {}
            diff = {"score": measured, "symbol": checked[1],
                    "first_hunk": _residue(checked[2]), "mismatch_class": diagnosis.get("mismatch_class"),
                    "confidence": OBSERVED}
            score = measured
        except match.CompileError as error:
            diff = {"score": 0, "compile_error": str(error)[:800], "confidence": OBSERVED}
        except Exception as error:
            diff = {"score": 0, "error": str(error)[:300], "confidence": UNKNOWN}
    packet = {
        "format": "roconstruct-packet-v1",
        "client": client,
        "address": addr,
        "confidence_scale": {
            PROVEN: "read directly from the verified binary or an exact stored source",
            OBSERVED: "measured by compiling this checkout; reproducible, not original source",
            HYPOTHESIS: "research note or model guess; must be proven against bytes",
            UNKNOWN: "no measurement; do not present as confirmed",
        },
        "target": target,
        "source": {
            "origin": origin, "text": source, "score": score,
            "confidence": OBSERVED if source else UNKNOWN,
            "likely_original": False,
        },
        "diff": diff,
        "similar": _similar(client, addr, row, root, similar_limit),
        "lessons": _lessons(row.get("unit"), addr, root=root),
        "failed_hypotheses": _failed(client, addr, root=root),
        "local_claim": claim_state.load_claim(client, addr, root=root, include_expired=True),
        "assumptions": [
            "a matching source is a codegen analog, not the original declaration",
            "offsets/types/member layouts are unproven unless stated by a target fact",
            "lifted IR (if a cached summary exists elsewhere) models instructions, not source",
        ],
        "truncated": False,
        "omitted": [],
    }
    return _fit(packet, max_chars)


def _fit(packet, max_chars):
    """Trim low-priority sections first; code is marked when shortened."""
    def size(value):
        return len(json.dumps(value, ensure_ascii=True))

    while size(packet) > max_chars:
        changed = False
        if packet["target"]["asm"] and len(packet["target"]["asm"]) > 8:
            packet["target"]["asm"] = packet["target"]["asm"][:max(8, len(packet["target"]["asm"]) // 2)]
            packet["omitted"].append("target.asm tail")
            changed = True
        elif packet["similar"]:
            packet["similar"].pop()
            packet["omitted"].append("similar tail")
            changed = True
        elif packet["lessons"]:
            packet["lessons"].pop()
            packet["omitted"].append("lessons tail")
            changed = True
        elif packet["source"]["text"] and len(packet["source"]["text"]) > 1200:
            packet["source"]["text"] = packet["source"]["text"][:1200]
            packet["source"]["truncated"] = True
            packet["omitted"].append("source.text (truncated; re-request with a larger --max-tokens)")
            changed = True
        elif packet["diff"] and packet["diff"].get("first_hunk"):
            trimmed = _first_hunk(packet["diff"]["first_hunk"], max_lines=10)
            if trimmed != packet["diff"]["first_hunk"]:
                packet["diff"]["first_hunk"] = trimmed
                packet["omitted"].append("diff hunk tail")
                changed = True
            else:
                break
        else:
            break
        packet["truncated"] = True
    packet["chars"] = size(packet)
    packet["estimated_tokens"] = max(1, packet["chars"] // 4)
    return packet


def render(packet):
    lines = ["%s %s  %d B  %s" % (packet["client"], packet["address"],
                                  packet.get("target", {}).get("size") or 0,
                                  packet.get("target", {}).get("unit") or "")]
    src = packet.get("source") or {}
    lines.append("source: %s  score %s  [%s]" % (src.get("origin"), src.get("score"), src.get("confidence")))
    diff = packet.get("diff")
    if diff:
        lines.append("diff: %s%%  %s  [%s]" % (diff.get("score"), diff.get("mismatch_class") or
                                               diff.get("symbol") or "compile failure", diff.get("confidence")))
        if diff.get("first_hunk"):
            lines.append(diff["first_hunk"])
    if packet.get("similar"):
        lines.append("exact siblings: " + ", ".join(
            "%s (%.2f)" % (row["addr"], row["shape_ratio"]) for row in packet["similar"][:5]))
    if packet.get("lessons"):
        lines.append("lessons:")
        lines += ["  - %s: %s" % (row.get("title"), row.get("lesson")) for row in packet["lessons"]]
    if packet.get("failed_hypotheses"):
        lines.append("recent failed hypotheses:")
        lines += ["  - %s %s -> %s" % (row.get("kind"), (row.get("hypothesis") or "")[:120],
                                       row.get("result") or row.get("score"))
                  for row in packet["failed_hypotheses"]]
    lines.append("assumptions: " + "; ".join(packet.get("assumptions", [])))
    if packet.get("truncated"):
        lines.append("packet truncated to %d tokens; omitted: %s" %
                     (packet.get("estimated_tokens"), ", ".join(packet.get("omitted", []))))
    return "\n".join(lines)
