"""Post-draft brute force: every cheap compiler/config route in one command.

A drafted or repaired source usually sits at 90-99% under ONE build x flag
profile. Before any paid repair, this sweeps the full grid — both compiler
builds x the extended flag profiles (including /fp:fast for x87 ordering,
/Oi /Ot for the Ogre-exe profile, GS on/off, Ob levels) — then fans the
winning source out to same-shape siblings. The object cache makes each
re-check ~0.3s, so the whole grid is seconds, not minutes.

Usage:
  roc bruteforce 2008-06 004acd50            # grid + family on one function
  roc bruteforce 2008-06 --file cand.cpp 004acd50
  roc bruteforce 2008-06 --near 95          # every 95%+ stored source
"""
import json
import re
import sys
from datetime import datetime, timezone
from pathlib import Path

from roc import clients, match, research

ROOT = Path(__file__).resolve().parent.parent

# The extended grid: wider than the automatic worker's 3 GATES. Every entry is
# binary-proven useful on some 2008 family (lessons + recipes).
EXTRA_PROFILES = (
    "/O2 /GS- /EHsc /MD",            # the workhorse
    "/O2 /Ob2 /GS- /EHsc /MD",
    "/O1 /GS- /EHsc /MD",
    "/Od /Ob0 /GS /EHsc /MD",
    "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD",          # Ogre exe / XTP winners
    "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast", # x87 ordering (CLAUDE.md lesson)
    "/O2 /GS /EHsc /MD",                         # GS on (the /GS- sweep failed everywhere)
    "/O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD",  # Ogre 1.4.5 exe profile
    "/O2 /Ob1 /GS- /EHsc /MD",
    "/O2 /GS- /EHsc /MD /fp:fast",
)


def sweep_one(client, addr, source, log=print, full=True):
    """(best_score, best_source, best_config, results) after the full grid."""
    builds = research.BUILDS if client == research.CLIENT else (clients.load()[client]["compiler_build"],)
    profiles = EXTRA_PROFILES if full else research.GATES
    best_score, best_source, best_config = -1, source, "keep"
    results = []
    for candidate, build, flags in research.variants(source, builds=builds, profiles=("keep", *profiles), client=client):
        try:
            score = match.check_text(client, addr, candidate)[0]
        except match.CompileError:
            results.append({"build": build, "flags": flags, "score": 0, "error": "compile"})
            continue
        results.append({"build": build, "flags": flags, "score": score})
        if score > best_score:
            best_score, best_source, best_config = score, candidate, "%s %s" % (build, flags)
    return best_score, best_source, best_config, results


def family_fanout(client, addr, source, log=print, limit=24):
    """Check the source against same-shape open siblings; return [(addr, score)] gains."""
    import difflib
    functions = match._functions(client)
    want = functions.get(addr, {})
    shape = (want.get("shape") or "").split(" ; ")
    if not shape or shape == [""]:
        return []
    siblings = []
    for other, row in functions.items():
        if other == addr or row.get("score", 0) >= 100 or row.get("kind", "code") != "code":
            continue
        ratio = difflib.SequenceMatcher(None, shape, (row.get("shape") or "").split(" ; "), autojunk=False).ratio()
        if ratio > 0.75:
            siblings.append((ratio, other))
    siblings.sort(reverse=True)
    out = []
    for ratio, other in siblings[:limit]:
        try:
            score = match.check_text(client, other, source)[0]
        except match.CompileError:
            continue
        if score >= 90:  # only meaningful hits count as family gains
            out.append((other, score))
            log("  sibling %s: %d%%" % (other, score))
    return out


def run(client, addr=None, file=None, near=None, full=True, family=True, log=print):
    """Brute-force one function, a scratch file, or every near-miss in a band."""
    targets = []
    if file:
        if not addr:
            raise SystemExit("--file needs an address")
        text = Path(file).read_text(encoding="utf-8", errors="replace")
        targets.append((addr, text))
    elif addr:
        path = ROOT / "src" / client / ("%s.cpp" % addr)
        if not path.exists():
            raise SystemExit("No stored source for %s (roc pull %s)" % (addr, client))
        targets.append((addr, path.read_text(encoding="utf-8", errors="replace")))
    elif near is not None:
        import json as _json
        scores = _json.loads((ROOT / "work" / client / "scores.json").read_text())
        for a, s in sorted(scores.items(), key=lambda kv: -kv[1]):
            if not near <= s < 100:
                continue
            p = ROOT / "src" / client / ("%s.cpp" % a)
            if p.exists():
                targets.append((a, p.read_text(encoding="utf-8", errors="replace")))
    else:
        raise SystemExit("give --addr, --file, or --near")

    grand = {"grid_wins": 0, "family_wins": []}
    for one_addr, source in targets:
        before = match.check_text(client, one_addr, source)[0]
        log("%s: %d%% under current config" % (one_addr, before))
        best, best_source, config, results = sweep_one(client, one_addr, source, log=log, full=full)
        log("  grid best: %d%% (%s)" % (best, config))
        if best > before:
            grand["grid_wins"] += 1
            path = ROOT / "src" / client / ("%s.cpp" % one_addr)
            if path.exists() and file is None:
                # pin the winning config only when the source came from the store
                path.write_text(best_source, encoding="utf-8")
                log("  pinned winning config in %s" % path.name)
            research.append(ROOT / "work" / "agent-memory" / "attempts.jsonl", dict(
                kind="trial", date=datetime.now(timezone.utc).isoformat(), client=client,
                addresses=[one_addr], hypothesis="bruteforce grid", source_hash=research.digest(best_source),
                before=before, after=best, change=config, outcome="improved" if best > before else "no_gain"))
        if family:
            source_for_family = best_source if best >= before else source
            hits = family_fanout(client, one_addr, source_for_family, log=log)
            grand["family_wins"] += hits
    return grand
