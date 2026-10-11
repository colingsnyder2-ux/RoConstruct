"""Immutable CPU job inputs and the shared compile-once comparator."""
import hashlib
import json
import re
from pathlib import Path

from roc import clients, match


def identity():
    registry = {k: v for k, v in clients.load().items() if k != "2009-12" and not v.get("donor")}
    return hashlib.sha256(b"roc-cluster-v1" + json.dumps(registry, sort_keys=True).encode() +
                          Path(match.__file__).read_bytes() + Path(__file__).read_bytes()).hexdigest()


def cpu_manifest(client, source, addrs, user, model):
    entry = clients.load().get(client)
    if client == "2009-12" or not entry or entry.get("donor"):
        raise ValueError("Client excluded or unknown")
    if not isinstance(source, str) or not source.strip() or len(source) > 200000:
        raise ValueError("Need bounded source")
    if not isinstance(addrs, list) or not 1 <= len(addrs) <= 1000 or not all(
            isinstance(a, str) and re.fullmatch(r"[0-9a-f]{8}", a) for a in addrs):
        raise ValueError("Need 1-1000 lowercase addresses")
    match.reject_asm(source)
    return {"client": client, "source": source, "addrs": sorted(set(addrs)),
            "user": user, "model": model, "registry": entry, "identity": identity(),
            "source_hash": hashlib.sha256(source.encode()).hexdigest()}


def _source_class_token(source):
    path = source.rsplit(": ", 1)[-1].split(" ", 1)[-1]
    token = re.sub(r"[^a-z0-9]", "", Path(path).stem.lower())
    recipe = source.rsplit(": ", 1)[-1].split(" ", 1)[0].lower()
    for prefix in (("ogre",) if recipe.startswith("ogre-") else ("cxtp", "xtp", "rbx", "c")):
        if token.startswith(prefix) and len(token) > len(prefix) + 3:
            token = token[len(prefix):]
            break
    return token if len(token) >= 5 else None


def check_many_text(client, addrs, source):
    obj = match.compile_text(client, source)
    funcs = match.coff_functions(obj)
    token = _source_class_token(source)
    class_funcs = [r for r in funcs if token and token in re.sub(r"[^a-z0-9]", "", r[0].lower())]
    if class_funcs:
        funcs = class_funcs
    by_size = {}
    for row in funcs:
        by_size.setdefault(len(row[1]), []).append(row)
    results = []
    for addr in addrs:
        code, relocs, _ = match.target(client, addr)
        wiggle = max(8, len(code) // 4)
        candidates = [r for size in range(max(1, len(code) - wiggle), len(code) + wiggle + 1)
                      for r in by_size.get(size, ())]
        if not candidates:
            results.append((addr, 0, []))
            continue
        exacts = [r for r in candidates if match.exact_match(code, relocs, r[1], r[2])]
        best = exacts[0] if exacts else max(candidates, key=lambda r: match.score(code, relocs, r[1], r[2]))
        score, spans = match.score(code, relocs, best[1], best[2]), []
        if score == 100:
            best, spans, bad = match.select_exact_data(client, addr, code, obj, exacts or [best])
            if bad:
                score, spans = 99, []
        results.append((addr, score, spans))
    return results
