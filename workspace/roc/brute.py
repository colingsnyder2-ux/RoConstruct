"""Evidence-indexed source portfolios for the reusable research grid.

This module searches existing C++ and authentic recipe configurations. It does not
invent layouts, mutate target bytes, bypass access rules or invoke a paid model.
"""
from collections import defaultdict, deque
from pathlib import Path

from roc import clients, draft, fingerprint, libs, match


def portfolios(root, client, stored, functions, recipes, spec):
    from roc import research
    root = Path(root).resolve()
    by_addr, by_shape, by_unit = defaultdict(list), defaultdict(list), defaultdict(list)
    seen_paths = set()
    available = {row["addr"]: dict(row) for row in stored}
    target_addresses = [addr for addr, function in functions.items()
                        if function.get("kind", "code") == "code" and available.get(addr, {}).get("score", 0) < 100]
    if spec.get("target_limit"):
        target_addresses.sort(key=lambda addr: (-available.get(addr, {}).get("score", 0), functions[addr].get("size", 0), addr))
        target_addresses = target_addresses[:spec["target_limit"]]
    target_addresses = set(target_addresses)
    source_roots = defaultdict(list)
    for name, recipe in libs.RECIPES.items():
        if recipe.get("src") and not recipe.get("archive"):
            source_roots[recipe["src"]].append(name)

    def add_file(addr, path, origin, score=0, expected_hash=None):
        if addr not in target_addresses:
            return
        path = Path(path)
        path = (path if path.is_absolute() else root / path).resolve()
        if not path.is_relative_to(root) or path.suffix.lower() != ".cpp" or (addr, path) in seen_paths:
            return
        seen_paths.add((addr, path))
        if not path.is_file():
            return
        source = path.read_text(encoding="utf-8", errors="replace")
        # A retained file can have been replaced since an old journal row.
        if expected_hash and research.digest(source) != expected_hash:
            score = 0
        by_addr[addr].append(dict(source=source, origin=origin, hint_score=score))

    # Assigned/manual best sources are identified by their client-scoped journals.
    for trial in research.journal_records(root / "work/agent-memory/attempts.jsonl"):
        if trial.get("client") != client or trial.get("kind") != "trial" or trial.get("profile") == "compiler-sweep" or not isinstance(trial.get("evidence"), str):
            continue
        for addr in trial.get("addresses", []):
            add_file(addr, Path(trial["evidence"]).parent / "best.cpp", "journal best",
                     trial.get("after") or 0, trial.get("source_hash"))
    # Research candidates retain their own recipe/client provenance.
    for name, recipe in recipes.items():
        if recipe.get("op") != "grid":
            continue
        for addr, path in recipe.get("seed_sources", {}).get(client, {}).items():
            add_file(addr, path, "prior recipe seed")
        folder = Path(recipe.get("output") or root / "work/research" / name)
        folder = folder if folder.is_absolute() else root / folder
        if client != "2008-06":
            folder /= client
        for trial in research.journal_records(folder / (name + ".jsonl")):
            if trial.get("client", recipe.get("client", "2008-06")) != client or not trial.get("candidate_path"):
                continue
            add_file(trial["addr"], trial["candidate_path"], "research partial",
                     trial.get("score") or 0, trial.get("source_sha256"))
    for addr, paths in spec.get("candidate_sources", {}).get(client, {}).items():
        for path in paths:
            add_file(addr, path, "recipe candidate")

    for row in stored:
        function = functions.get(row["addr"], {})
        if row.get("score") == 100 and row.get("source"):
            if function.get("shape"):
                by_shape[function["shape"]].append(row)
            if function.get("unit"):
                by_unit[function["unit"]].append(row)
    # File/class attribution is only a search clue; the verifier still decides.
    installed = fingerprint.local_versions({family for addr in target_addresses
        if not available.get(addr, {}).get("source")
        for family in [fingerprint.unit_family(functions[addr].get("unit") or "")] if family})

    result = []
    for addr, function in functions.items():
        row = available.get(addr, dict(addr=addr, score=0, source=""))
        if addr not in target_addresses:
            continue
        choices = []
        if row.get("source"):
            choices.append(dict(source=row["source"], origin="stored", hint_score=101))
        add_file(addr, root / "src" / client / (addr + ".cpp"), "local source")
        choices += sorted(by_addr[addr], key=lambda item: -item["hint_score"])
        donors = by_shape.get(function.get("shape"), [])
        donor_limit = spec.get("donors", 3)
        seen_donors = set()
        for donor in donors:
            signature = str(sorted(match.directives(donor["source"]).items())) + draft.clean_repair_context(donor["source"])
            if signature in seen_donors:
                continue
            seen_donors.add(signature)
            choices.append(dict(source=donor["source"], origin="verified same-shape " + donor["addr"], hint_score=0))
            if donor_limit and len(seen_donors) >= donor_limit:
                break
        family_sources = by_unit.get(function.get("unit"), [])
        family_limit = spec.get("family_sources", 4)
        seen_family = set()
        for donor in family_sources:
            directives = match.directives(donor["source"])
            signature = str(sorted(directives.items())) + draft.clean_repair_context(donor["source"])
            if "lib" not in directives or signature in seen_family:
                continue
            seen_family.add(signature)
            choices.append(dict(source=donor["source"], origin="exact native unit " + donor["addr"], hint_score=0))
            if family_limit and len(seen_family) >= family_limit:
                break
        if not row.get("source"):
            unit = function.get("unit") or ""
            for name, path in installed.get((fingerprint.unit_family(unit), fingerprint.unit_class(unit)), []):
                choices.append(dict(source=libs.source_for(name, path, build=clients.load()[client]["compiler_build"]),
                                    origin="installed native class " + name, hint_score=0))
        # Real alternate preprocessing/runtime recipes for the same physical native file.
        for candidate in list(choices):
            directives = match.directives(candidate["source"])
            if "lib" not in directives:
                continue
            name, _, path = directives["lib"].partition(" ")
            recipe = libs.RECIPES.get(name, {})
            folder = libs.LIBS / recipe.get("src", "__missing__")
            if not (folder / path).is_file():
                continue
            for alternate in source_roots.get(recipe.get("src"), []):
                if alternate == name:
                    continue
                flags = libs.compile_profiles(client, alternate, path)[0]
                source = libs.source_for(alternate, path, directives.get("lang"),
                                         clients.load()[client]["compiler_build"], flags)
                choices.append(dict(source=source, origin="native recipe " + alternate, hint_score=0))
        unique, seen = [], set()
        for candidate in choices:
            source = candidate["source"]
            directives = match.directives(source)
            if spec.get("native_only") and "lib" not in directives:
                continue
            try:
                match.reject_asm(source)
            except (RuntimeError, ValueError):
                continue
            signature = research.digest(str(sorted(directives.items())) + draft.clean_repair_context(source))
            if signature in seen:
                continue
            seen.add(signature)
            unique.append(candidate)
        if not unique:
            continue
        limit = spec.get("max_candidates", 8)
        chosen = unique
        if limit and len(unique) > limit:
            chosen, buckets = unique[:1], defaultdict(deque)
            for candidate in unique[1:]:
                origin = candidate["origin"]
                category = " ".join(origin.split()[:2])
                buckets[category].append(candidate)
            while len(chosen) < limit and any(buckets.values()):
                for queue in buckets.values():
                    if queue and len(chosen) < limit:
                        chosen.append(queue.popleft())
        result.append(dict(row, source=chosen[0]["source"], candidates=chosen[1:],
                           source_origin=chosen[0]["origin"], candidates_available=len(unique)))
    return result


def portfolio_sources(rows, client, builds, profiles, suffixes):
    """Compile each distinct portfolio context once, then inspect every emitted function."""
    from roc import research
    seen, bodies, pending = set(), set(), deque()
    targets = deque((row["addr"], iter([dict(source=row["source"], origin=row.get("source_origin", "stored")),
                                      *row.get("candidates", [])])) for row in rows)
    while targets:
        addr, candidates = targets.popleft()
        candidate = next(candidates, None)
        if candidate is None:
            continue
        targets.append((addr, candidates))
        key = research.digest(candidate["source"])
        if key in bodies:
            continue
        bodies.add(key)
        pending.append((iter(research.variants(candidate["source"], builds, profiles, suffixes, client=client)),
                        addr, candidate.get("origin", "candidate")))
    # Broad first gates before deeper contexts; a pilot must cover more than one family.
    while pending:
        gates, addr, origin = pending.popleft()
        gate = next(gates, None)
        if gate is None:
            continue
        pending.append((gates, addr, origin))
        source, build, flags = gate
        key = research.digest(source)
        if key not in seen:
            seen.add(key)
            yield source, dict(origin=origin, seed_addr=addr, build=build, flags=flags)
