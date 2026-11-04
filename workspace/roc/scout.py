"""Read-only opportunity scouting.

``roc scout`` asks the server for ranked *open* targets without claiming or
reserving anything.  When the server predates ``/v1/work-candidates`` (or is
offline) it falls back to the local ``functions.jsonl``/``scores.json`` cache,
which is explicitly marked stale: a local percentage is not confirmed server
progress.
"""
import json
import time
from pathlib import Path

from roc import claims as claim_state
from roc import match, ranking


def _int(value, default=0):
    try:
        return int(value)
    except (TypeError, ValueError):
        return default


def _api_call(api, path, timeout=60):
    return api.call(path, timeout=timeout)


def from_server(api, client, limit=20, profile="quick", max_size=None, min_score=0,
                max_score=99, include_claimed=True, timeout=60):
    """Return (rows, live, note).  Never retries: one compact round-trip."""
    query = ("/v1/work-candidates?client=%s&limit=%d&profile=%s&min_score=%d&max_score=%d"
             "&include_claimed=%d" % (client, max(1, min(int(limit), 200)), profile,
                                      _int(min_score), _int(max_score), 1 if include_claimed else 0))
    if max_size:
        query += "&max_size=%d" % _int(max_size)
    try:
        rows = _api_call(api, query, timeout=timeout)
        if isinstance(rows, list):
            for row in rows:
                row.setdefault("server_ranked", True)
            return rows, True, ""
    except RuntimeError as error:
        return [], False, str(error)[:200]
    return [], False, "server returned no candidate list"


def _attempt_counts(client, root=None):
    """Cheap local attempt tally; server attempts still win when live."""
    out = {}
    path = Path(root or match.ROOT) / "work" / "agent-memory" / "attempts.jsonl"
    try:
        lines = path.read_text(encoding="utf-8", errors="replace").splitlines()[-20000:]
    except OSError:
        return out
    for line in lines:
        try:
            row = json.loads(line)
        except ValueError:
            continue
        if row.get("client") not in (None, client):
            continue
        for addr in row.get("addresses") or ([row.get("addr")] if row.get("addr") else []):
            addr = str(addr).lower().replace("0x", "").zfill(8)
            out[addr] = out.get(addr, 0) + 1
    return out


def from_local(client, limit=20, profile="quick", max_size=None, root=None, min_score=0,
               max_score=99, include_claimed=True, skip_cooling=True):
    """Offline fallback over local analysis.  Scores are stale, not confirmed."""
    root = Path(root or match.ROOT)
    funcs_path = root / "work" / client / "functions.jsonl"
    scores_path = root / "work" / client / "scores.json"
    if not funcs_path.exists():
        raise ValueError("%s is not analyzed yet: run roc analyze %s" % (client, client))
    scores = json.loads(scores_path.read_text()) if scores_path.exists() else {}
    attempts = _attempt_counts(client, root)
    rows = []
    for line in funcs_path.read_text(encoding="utf-8", errors="replace").splitlines():
        if not line.strip():
            continue
        try:
            row = json.loads(line)
        except ValueError:
            continue
        if row.get("kind", "code") != "code":
            continue
        score = _int(scores.get(row["addr"], 0))
        if score < min_score or score > max_score:
            continue
        src = root / "src" / client / (row["addr"] + ".cpp")
        rows.append({
            "addr": row["addr"], "size": _int(row.get("size")), "unit": row.get("unit"),
            "score": score, "shape": row.get("shape"), "family": row.get("family"),
            "attempts": attempts.get(row["addr"], 0), "source_confidence": 0,
            "difficulty": row.get("difficulty"), "has_source": src.exists(),
            "claimed": False, "owner": None, "mismatch_category": None,
            "cooldown_until": None,
        })
    matched_rows = [row for row in rows if row["score"] == 100]
    matched = {"shape": {}, "family": {}}
    for row in matched_rows:
        if row.get("shape"):
            matched["shape"].setdefault(row["shape"], row["addr"])
        if row.get("family"):
            matched["family"].setdefault(row["family"], row["addr"])
    ranked = ranking.rank_candidates([row for row in rows if row["score"] < 100], matched,
                                     profile_name=profile, max_size=max_size,
                                     limit=max(1, min(int(limit), 200)),
                                     exclude_claimed=not include_claimed)
    if skip_cooling:
        ranked = [row for row in ranked
                  if not claim_state.cooling(client, row["addr"], root=root)]
    for row in ranked:
        row["server_ranked"] = False
    return ranked


def candidates(api, client, limit=20, profile="quick", max_size=None, min_score=0,
               max_score=99, include_claimed=True, root=None, skip_cooling=True):
    rows, live, note = from_server(api, client, limit=limit, profile=profile,
                                   max_size=max_size, min_score=min_score,
                                   max_score=max_score, include_claimed=include_claimed)
    if live and rows:
        if skip_cooling:
            rows = [row for row in rows
                    if not claim_state.cooling(client, row["addr"], root=root)]
        return rows, True, note or "server-ranked; no claim made"
    local = from_local(client, limit=limit, profile=profile, max_size=max_size, root=root,
                       min_score=min_score, max_score=max_score,
                       include_claimed=include_claimed, skip_cooling=skip_cooling)
    return local, False, (note + "; using stale local scores, not server progress").strip("; ")


def format_table(rows, live=True, note=""):
    header = "%-8s %5s %5s %5s  %-10s %-9s %-4s %-15s %s" % (
        "address", "score", "size", "twin", "recommend", "confidence", "att", "owner", "reason")
    lines = []
    if note:
        lines.append(("Server-ranked candidates (read-only)." if live else
                      "Local fallback: scores below are stale local measurements, NOT server progress.") +
                     "  " + note)
    lines.append(header)
    for row in rows:
        age = ""
        if row.get("claim_expires"):
            try:
                age = "%dm" % max(0, int((float(row["claim_expires"]) - time.time()) / 60))
            except (TypeError, ValueError):
                age = "?"
        twin = row.get("twin") or "-"
        confidence = "%d%%" % _int(row.get("source_confidence"))
        owner = (row.get("owner") or "claimed") if row.get("claimed") else "-"
        score = ("~%d" % _int(row.get("score"))) if not live else str(_int(row.get("score")))
        lines.append("%-8s %5s %5d %5s  %-10s %-9s %-4d %-15s %s" % (
            row.get("addr", "?"), score, _int(row.get("size")), twin[:5],
            row.get("recommendation", "?"), confidence, _int(row.get("attempts")),
            (owner + (" %s" % age if age else ""))[:15], row.get("difficulty_reason", "")))
        if row.get("penalties"):
            lines.append("         %s" % "; ".join(row["penalties"][:3]))
    if not rows:
        lines.append("  (no open candidates in this profile/size band)")
    return "\n".join(lines)
