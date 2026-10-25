"""Constant patching from exact twins.

An unmatched function whose instruction shape equals an exact twin's often differs
only in immediates (a shift count, a field mask, a loop bound). The two *target*
functions say which constants differ; substituting them for matching literals in the
twin's source is a binary-proven edit, not a guess. Candidates go through the same
(stub, unit) check as mutsearch, so roc-lib twins work too.
"""
import difflib
import json
import re

from roc import match, mutsearch

_NUM = re.compile(r"\b0x[0-9a-fA-F]+\b|\b\d+\b")
_COMMENT = re.compile(r"(?m)^[ \t]*//.*$")


def _value(token):
    return int(token, 16) if token.lower().startswith("0x") else int(token, 10)


def _numbers(text):
    """Number tokens outside // comment lines (address headers are not source)."""
    comments = [(m.start(), m.end()) for m in _COMMENT.finditer(text)]
    return [m for m in _NUM.finditer(text) if not any(s <= m.start() < e for s, e in comments)]


def twins(client, addr, limit=3):
    """Exact functions within 4 bytes of the target's size whose shape matches best (ratio >= 0.95)."""
    folder = match.ROOT / "work" / client
    rows = {r["addr"]: r for r in map(json.loads, (folder / "functions.jsonl").read_text().splitlines())}
    scores = json.loads((folder / "scores.json").read_text())
    want = rows[addr]
    shape = want.get("shape", "").split(" ; ")
    ranked = []
    for other, row in rows.items():
        if other != addr and scores.get(other) == 100 and abs(row["size"] - want["size"]) <= 4:
            ratio = difflib.SequenceMatcher(None, shape, row.get("shape", "").split(" ; "), autojunk=False).ratio()
            if ratio >= 0.95:
                ranked.append((ratio, other))
    return [other for _, other in sorted(ranked, reverse=True)[:limit]]


def constant_pairs(twin_code, target_code, limit=0x10000):
    """{(twin value, target value)} from same-mnemonic instructions whose operands differ
    only in numbers. Values at or above `limit` are addresses (relocated), never source."""
    pairs = set()
    a, b = match._insn_parts(twin_code), match._insn_parts(target_code)
    if len(a) != len(b):
        return pairs
    for (ma, oa), (mb, ob) in zip(a, b):
        if ma != mb or oa == ob or ma.startswith("j") or ma == "call" or _NUM.sub("#", oa) != _NUM.sub("#", ob):
            continue
        for x, y in zip(_NUM.findall(oa), _NUM.findall(ob)):
            x, y = _value(x), _value(y)
            if x != y and x < limit and y < limit:
                pairs.add((x, y))
    return pairs


def substitutions(text, pairs):
    """One variant per literal occurrence of a twin value, plus one replacing every pair."""
    out, everything = [], text
    for old, new in sorted(pairs):
        fmt = lambda m: hex(new) if m.group(0).lower().startswith("0x") else str(new)
        for m in [m for m in _numbers(text) if _value(m.group(0)) == old]:
            out.append(("%d->%d at %d" % (old, new, m.start()), text[:m.start()] + fmt(m) + text[m.end():]))
        for m in reversed([m for m in _numbers(everything) if _value(m.group(0)) == old]):
            everything = everything[:m.start()] + fmt(m) + everything[m.end():]
    if len(pairs) > 1 and everything != text:
        out.append(("all pairs", everything))
    return out


def patch(client, addr, twin, log=None):
    """Best result for one twin: mutsearch-style dict (score, precise, source, unit, path...)."""
    path = match.ROOT / "src" / client / (twin + ".cpp")
    stub = path.read_text(encoding="utf-8", errors="replace")
    pairs = constant_pairs(match.target(client, twin)[0], match.target(client, addr)[0])
    found = mutsearch.unit_of(stub)
    check = mutsearch._scratch_check(client, addr, *found[:3]) if found else \
        (lambda state: mutsearch._measure(client, addr, state[0]))
    unit = found[3] if found else None
    states = [("twin as is", (stub, unit))] + [
        (name, (stub, text) if found else (text, None)) for name, text in substitutions(unit if found else stub, pairs)]
    best = None
    for name, state in states:
        try:
            score, precise, diff = check(state)
        except match.CompileError:
            continue
        if best is None or (score, precise) > (best["score"], best["precise"]):
            best = dict(score=score, precise=precise, residue=mutsearch.residue(diff), source=state[0], unit=state[1],
                        path=["twin %s" % twin] + ([] if name == "twin as is" else [name]), twin=twin, pairs=sorted(pairs))
            if log:
                log("%s %s twin %s %s: %.3f%%" % (client, addr, twin, name, precise))
        if best["score"] == 100:
            break
    return best, stub
