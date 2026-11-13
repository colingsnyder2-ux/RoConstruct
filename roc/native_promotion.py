"""Plan dependency-closed preflight batches for inactive native providers."""
import json

from roc.graph import Graph


def _key(value):
    return json.dumps(value, sort_keys=True, separators=(",", ":"), ensure_ascii=True)


def _address_key(value):
    if isinstance(value, int):
        return "%08x" % value
    text = str(value).lower().removeprefix("0x")
    return text.zfill(8) if text and all(c in "0123456789abcdef" for c in text) else text


def _family_provider(family, provider):
    return {
        "symbol": provider["symbol"],
        "owner": family,
        "origin": "native",
        "address": provider["address"],
        "identity": provider["identity"],
    }


def plan(families, baseline=()):
    """Choose unique providers and order dependency SCCs for manual preflight.

    `inactive_exact` is the only native family status eligible to provide a
    symbol. Other statuses remain visible as unavailable provider candidates.
    This planner makes no runtime or server-state claims.
    """
    by_name = {}
    for family in families:
        name = family["name"]
        if name in by_name:
            raise ValueError("duplicate family: " + name)
        by_name[name] = family

    native, exact_native = {}, {}
    for name, family in by_name.items():
        for provider in family.get("providers", []):
            symbol = provider["symbol"]
            if "identity" not in provider or provider["identity"] is None:
                raise ValueError("provider identity required: %s (%s)" % (name, symbol))
            candidate = _family_provider(name, provider)
            native.setdefault(symbol, []).append(candidate)
            if family.get("status") == "inactive_exact":
                exact_native.setdefault(symbol, []).append(candidate)

    baselines = {}
    for symbol, provider in dict(baseline).items():
        if "address" not in provider or "identity" not in provider or provider["identity"] is None:
            raise ValueError("baseline address and identity required: " + symbol)
        baselines[symbol] = {
            "symbol": symbol,
            "owner": provider.get("origin", "original"),
            "origin": "baseline",
            "address": provider["address"],
            "identity": provider["identity"],
        }

    selected, conflicts, conflict_owners = {}, [], {}
    symbols = sorted(set(native) | set(baselines))
    for symbol in symbols:
        candidates = sorted(native.get(symbol, []), key=lambda p: (p["owner"], str(p["address"])))
        signatures = {_key((_address_key(p["address"]), p["identity"])) for p in candidates}
        if len(signatures) > 1:
            conflicts.append({"symbol": symbol, "native_candidates": candidates,
                              "baseline": baselines.get(symbol)})
            conflict_owners[symbol] = sorted({p["owner"] for p in candidates})
            if symbol in baselines:
                selected[symbol] = baselines[symbol]
            continue
        eligible = sorted(exact_native.get(symbol, []), key=lambda p: (p["owner"], str(p["address"])))
        if eligible:
            chosen = dict(eligible[0])
            chosen["aliases"] = sorted({p["owner"] for p in eligible})
            selected[symbol] = chosen
        elif symbol in baselines:
            selected[symbol] = baselines[symbol]

    graph_edges, family_reasons = [], {name: [] for name in by_name}
    for name, family in by_name.items():
        if family.get("status") != "inactive_exact":
            family_reasons[name].append("status is not inactive_exact")
        family_reasons[name].extend(str(reason) for reason in family.get("blockers", []))
        for need in sorted(set(family.get("needs", []))):
            if need not in by_name:
                family_reasons[name].append("missing family dependency: " + need)
            else:
                graph_edges.append({"source": name, "target": need, "kind": "dependency"})
        for symbol in sorted(set(family.get("requires", []))):
            if symbol in conflict_owners:
                family_reasons[name].append("conflicting native providers: " + symbol)
            elif symbol not in selected:
                if symbol in native:
                    family_reasons[name].append("native provider is not inactive_exact: " + symbol)
                else:
                    family_reasons[name].append("missing provider: " + symbol)
            elif selected[symbol]["origin"] == "native":
                owner = selected[symbol]["owner"]
                if owner != name:
                    graph_edges.append({"source": name, "target": owner, "kind": "dependency"})
        for symbol, owners in conflict_owners.items():
            if name in owners:
                family_reasons[name].append("conflicting native providers: " + symbol)

    graph_edges.sort(key=lambda edge: (edge["source"], edge["target"]))
    graph = Graph({"nodes": {name: {} for name in sorted(by_name)}, "edges": graph_edges})
    components = graph.components()
    ordered = graph.order()
    group_for = {name: group for group in components for name in group}
    ready = {}
    batch_blockers = {}
    batches = []
    for group in ordered:
        group = sorted(group)
        key = tuple(group)
        blockers = sorted({reason for name in group for reason in family_reasons[name]})
        dependencies = sorted({tuple(group_for[edge["target"]]) for edge in graph_edges
                               if edge["source"] in group and group_for[edge["target"]] != group})
        for dependency in dependencies:
            if not ready[dependency]:
                label = "dependency batch [%s]" % ", ".join(dependency)
                blockers.extend(label + " blocked: " + reason for reason in batch_blockers[dependency])
        blockers = sorted(set(blockers))
        ready[key] = not blockers
        batch_blockers[key] = blockers
        batches.append({"families": group,
                        "depends_on": [list(dependency) for dependency in dependencies],
                        "blockers": blockers,
                        "ready_for_preflight": ready[key]})

    return {
        "selected_providers": {symbol: selected[symbol] for symbol in sorted(selected)},
        "retained_baseline": sorted(symbol for symbol, provider in selected.items()
                                     if provider["origin"] == "baseline"),
        "conflicts": conflicts,
        "batches": batches,
    }
