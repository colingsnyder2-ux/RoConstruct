"""Compile trusted donor sources and emit byte-proven native candidates."""
import argparse
from collections import defaultdict
import json
from pathlib import Path

from roc import libs, match, native_bulk, rebuild
from roc.native_drafts import lock


ROOT = Path(__file__).resolve().parents[1]
DONOR_ROOTS = (
    Path("tools/rbxgs/Client"),
    Path("tools/openrbx/Client"),
    Path("work/upstream/OpenRBX/Client"),
)
NATIVE_FLAGS = "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast"
ENGINE_DIRS = ("App", "Network", "RbxGraphics", "RbxView", "RbxViewBase", "Rendering", "win")


def resolve_sources(root, values):
    root = Path(root).resolve()
    allowed = [(root / path).resolve() for path in DONOR_ROOTS]
    sources = []
    for value in values:
        path = Path(value)
        path = (path if path.is_absolute() else root / path).resolve()
        if path.suffix.lower() != ".cpp" or not path.is_file():
            raise ValueError("donor source must be an existing .cpp: " + str(value))
        if not any(path.is_relative_to(folder) for folder in allowed):
            raise ValueError("source outside donor roots: " + str(value))
        sources.append(path)
    if len({path.stem.casefold() for path in sources}) != len(sources):
        raise ValueError("donor source basenames must be unique")
    return sources


def source_batches(sources, limit=128):
    batches, names = [], []
    for source in sources:
        stem = source.stem.casefold()
        slot = next((index for index, used in enumerate(names)
                     if len(batches[index]) < limit and stem not in used), None)
        if slot is None:
            slot = len(batches)
            batches.append([])
            names.append(set())
        batches[slot].append(source)
        names[slot].add(stem)
    return batches


def discover_lane(root, lane):
    root = Path(root).resolve()
    if lane == "rbx-engine":
        client = root / "work/upstream/OpenRBX/Client"
    elif lane == "rbxgs-engine":
        client = root / "tools/rbxgs/Client"
    else:
        raise ValueError("unknown donor lane: " + lane)
    return sorted(path.resolve() for name in ENGINE_DIRS for path in (client / name).rglob("*.cpp")
                  if path.is_file())


def identity_hypotheses(closure):
    names, bindings = {}, {}
    for row in closure.get("bindings", []):
        if not row.get("body_exact") or not row.get("function_start"):
            continue
        symbol = row.get("symbol")
        value = row.get("address", row.get("addr"))
        if not symbol or not value:
            continue
        address = native_bulk.address(value)
        names.setdefault(symbol, set()).add(address)
        bindings[symbol] = address if symbol not in bindings else (
            bindings[symbol] if bindings[symbol] == address else None)
    for symbol, address in bindings.items():
        if address is None:
            names.pop(symbol, None)
    return names, bindings


def module_hypotheses(owned):
    names, objects = defaultdict(set), set()
    for address, rows in owned.items():
        for row in rows:
            names[row["symbol"]].add(native_bulk.address(address))
            objects.add(row["object"])
    bindings = {symbol: next(iter(addresses)) if len(addresses) == 1 else None
                for symbol, addresses in names.items()}
    return {symbol: addresses for symbol, addresses in names.items() if bindings[symbol] is not None}, bindings, objects


def learn_reference_identities(rows, bindings):
    observed = defaultdict(list)
    prefix = "unproven reference identity: "
    for row in rows:
        for rejection in row.get("rejections", ()):
            errors = rejection.get("errors", ())
            if not errors or any(not error.startswith(prefix) for error in errors):
                continue
            unresolved = {error[len(prefix):] for error in errors}
            for reference in rejection.get("references", ()):
                if reference.get("external") and reference.get("symbol") in unresolved:
                    observed[reference["symbol"]].append(native_bulk.address(reference["address"]))
    learned, conflicts = {}, {}
    for symbol, addresses in observed.items():
        choices = sorted(set(addresses))
        bound = bindings.get(symbol)
        if len(choices) != 1 or symbol in bindings and bound != choices[0]:
            conflicts[symbol] = sorted(set(choices + ([bound] if bound else [])))
        elif symbol not in bindings:
            learned[symbol] = (choices[0], len(addresses))
    return learned, conflicts


def close_reference_identities(raw, targets, names, bindings, harvest=native_bulk.harvest, max_rounds=8):
    names = {symbol: set(addresses) for symbol, addresses in names.items()}
    bindings = dict(bindings)
    rows = harvest(raw, targets, names, bindings)
    evidence, conflicts = [], {}
    for round_ in range(1, max_rounds + 1):
        learned, blocked = learn_reference_identities(rows, bindings)
        conflicts.update(blocked)
        if not learned:
            break
        for symbol, (address, observations) in learned.items():
            bindings[symbol] = address
            names.setdefault(symbol, set()).add(address)
            evidence.append({"symbol": symbol, "address": address, "observations": observations, "round": round_})
        rows = harvest(raw, targets, names, bindings)
    return rows, evidence, conflicts


def rank_partials(raw, targets, names, exact_symbols, threshold=.8,
                  functions=match.coff_functions, similarity=match.similarity_ratio,
                  diagnose=match.diagnose):
    rows = []
    for symbol, body, relocs in functions(raw):
        if symbol in exact_symbols:
            continue
        best = None
        for address in names.get(symbol, ()):
            try:
                target, target_relocs = targets.body(address)
            except (KeyError, ValueError, SystemExit):
                continue
            ratio = similarity(target, target_relocs, body, relocs)
            if ratio >= threshold and (best is None or ratio > best["similarity"]):
                proof_blocked = ratio == 1.0
                best = {"symbol": symbol, "addr": address, "similarity": round(ratio, 4),
                        "status": "proof_candidate" if proof_blocked else "repair_candidate",
                        "proof": "advisory-reference-unproved" if proof_blocked else "advisory-not-exact"}
                if not proof_blocked:
                    details = diagnose(target, target_relocs, body, relocs)
                    best["diagnosis"] = {key: details[key] for key in (
                        "mismatch_class", "classifications", "byte_diffs")}
                    best["diagnosis"].update(target_size=len(target), candidate_size=len(body))
        if best:
            rows.append(best)
    return sorted(rows, key=lambda row: (-row["similarity"], row["symbol"]))


def attach_blockers(advisory, harvested):
    blockers = {
        (row["symbol"], rejection["addr"]): rejection.get("errors", [])
        for row in harvested for rejection in row.get("rejections", [])
    }
    for row in advisory:
        row["blockers"] = blockers.get((row["symbol"], row["addr"]), [])


def classify_object(raw, targets, names, bindings, harvest=native_bulk.harvest, rank=rank_partials):
    rows, learned, conflicts = close_reference_identities(raw, targets, names, bindings, harvest=harvest)
    exact = [row for row in rows if row["status"] == "inactive_exact"]
    advisory = rank(raw, targets, names, {row["symbol"] for row in exact})
    attach_blockers(advisory, rows)
    partials = [row for row in advisory if row["status"] == "repair_candidate"]
    proof_blocked = [row for row in advisory if row["status"] == "proof_candidate"]
    return {
        "summary": {
            "functions": len(rows),
            "exact": len(exact),
            "draft": sum(row["status"] == "draft" for row in rows),
            "ambiguous": sum(row["status"] == "ambiguous" for row in rows),
            "repair_candidates": len(partials),
            "proof_candidates": len(proof_blocked),
            "reference_identities": len(learned),
            "identity_conflicts": len(conflicts),
        },
        "exact_candidates": exact,
        "repair_candidates": partials,
        "proof_candidates": proof_blocked,
        "learned_identities": learned,
        "identity_conflicts": conflicts,
        "functions": rows,
    }


def label_candidates(rows, integration):
    native = set(integration.get("native", ()))
    inactive = set(integration.get("inactive", ()))
    counts = {"integrated": 0, "waiting": 0, "missing": 0}
    for row in rows:
        state = "integrated" if row["addr"] in native else "waiting" if row["addr"] in inactive else "missing"
        row["integration"] = state
        counts[state] += 1
    return counts


def label_module_candidates(rows, report):
    owned = {native_bulk.address(address) for address in report.get("owned_addrs", ())}
    linked = report.get("linked") is True
    counts = {"integrated": 0, "waiting": 0, "missing": 0}
    for row in rows:
        state = ("integrated" if linked and row["addr"] in owned else
                 "waiting" if row["addr"] in owned else "missing")
        row["integration"] = state
        counts[state] += 1
    return counts


def donor_includes(root, recipe):
    return ([(libs.LIBS / folder).resolve() for folder in recipe["include"] if folder != "WINSDK"]
            + [(Path(root) / "rebuild/2008-06/native-donor-2007").resolve()])


def compile_sources(sources, output):
    spec = rebuild.load_module("2008-06", "rbxgs-app-openrbx-selective")
    recipe = libs.RECIPES["rbxgs"]
    with lock(Path(output).parent / "compile.lock"):
        overlay = rebuild.build_overlay("2008-06", "RbxgsAppOpenRBXProbe", spec.get("overlay"))
        return rebuild.compile_direct(
            "2008-06", sources, output,
            donor_includes(ROOT, recipe),
            recipe["defines"] + " BOOST_ALL_NO_LIB",
            NATIVE_FLAGS, overlay=overlay)


def convert(root, values, output):
    root, output = Path(root).resolve(), Path(output).resolve()
    sources = resolve_sources(root, values)
    objects = output.parent / "objects"
    compiled = compile_sources(sources, objects)
    closure_path = root / "work/native-client/claude-identity-closure.json"
    names, bindings = identity_hypotheses(json.loads(closure_path.read_text(encoding="utf-8")))
    integration_path = root / "docs/integration.json"
    integration = json.loads(integration_path.read_text(encoding="utf-8"))
    targets = native_bulk.Targets("2008-06")
    units = []
    for source in sources:
        ok, message = compiled[str(source)]
        unit = {"source": str(source), "compiled": ok, "compiler": message}
        obj = objects / (source.stem + ".obj")
        if ok and obj.is_file():
            unit.update(classify_object(obj.read_bytes(), targets, names, bindings))
            unit["summary"].update(label_candidates(unit["exact_candidates"], integration))
        units.append(unit)
    report = {
        "version": 1,
        "mode": "read-only-candidates",
        "closure": str(closure_path),
        "integration": str(integration_path),
        "summary": {
            "sources": len(units),
            "compiled": sum(unit["compiled"] for unit in units),
            "exact": sum(unit.get("summary", {}).get("exact", 0) for unit in units),
            "missing": sum(unit.get("summary", {}).get("missing", 0) for unit in units),
        },
        "units": units,
    }
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    return report


def summarize_mass_units(source_count, batch_count, compiled, units):
    rank = {"missing": 0, "waiting": 1, "integrated": 2}
    exact = {}
    for unit in units:
        for row in unit.get("exact_candidates", ()):
            old = exact.get(row["addr"])
            if old is None or rank[row["integration"]] > rank[old]:
                exact[row["addr"]] = row["integration"]
    summary = {"sources": source_count, "batches": batch_count, "compiled": compiled, "exact": len(exact)}
    summary.update({state: sum(value == state for value in exact.values())
                    for state in ("integrated", "waiting", "missing")})
    summary["repair_candidates"] = sum(unit.get("summary", {}).get("repair_candidates", 0) for unit in units)
    summary["proof_candidates"] = sum(unit.get("summary", {}).get("proof_candidates", 0) for unit in units)
    return summary


def convert_mass(root, lane, output, limit=None):
    root, output = Path(root).resolve(), Path(output).resolve()
    sources = discover_lane(root, lane)
    if limit is not None:
        sources = sources[:limit]
    reports = []
    batch_root = output.parent / (output.stem + "-batches")
    for index, batch in enumerate(source_batches(sources)):
        report_path = batch_root / ("%03d" % index) / "report.json"
        reports.append((report_path, convert(root, batch, report_path)))
    units = [unit for _, report in reports for unit in report["units"]]
    summary = summarize_mass_units(len(sources), len(reports),
                                   sum(report["summary"]["compiled"] for _, report in reports), units)
    result = {"version": 1, "mode": "mass-read-only-candidates", "lane": lane, "summary": summary,
              "reports": [{"path": str(path), "summary": report["summary"]} for path, report in reports]}
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(result, indent=2), encoding="utf-8")
    return result


def summarize_module_units(units):
    exact = {row["addr"]: row for unit in units for row in unit.get("exact_candidates", ())}
    summary = {"objects": len(units), "scanned": sum(unit["compiled"] for unit in units),
               "exact": len(exact)}
    summary.update({state: sum(row["integration"] == state for row in exact.values())
                    for state in ("integrated", "waiting", "missing")})
    summary["repair_candidates"] = sum(unit.get("summary", {}).get("repair_candidates", 0) for unit in units)
    summary["proof_candidates"] = sum(unit.get("summary", {}).get("proof_candidates", 0) for unit in units)
    return summary


def convert_module(root, module, output):
    root, output = Path(root).resolve(), Path(output).resolve()
    out_root = root / "rebuild/2008-06/out"
    module_dir = next((path for path in out_root.iterdir()
                       if path.is_dir() and path.name.casefold() == module.casefold()), None)
    if module_dir is None:
        raise ValueError("unknown built module: " + module)
    report_path, owned_path = module_dir / "report.json", module_dir / "owned-symbols.json"
    if not report_path.is_file() or not owned_path.is_file():
        raise ValueError("module lacks report/owned symbols: " + module)
    module_report = json.loads(report_path.read_text(encoding="utf-8"))
    owned = json.loads(owned_path.read_text(encoding="utf-8"))
    names, bindings, object_names = module_hypotheses(owned)
    targets, units = native_bulk.Targets("2008-06"), []
    for object_name in sorted(object_names):
        layer = module_report.get("choices", {}).get(object_name)
        candidates = ([module_dir / layer / object_name] if layer else [])
        candidates += list(module_dir.rglob(object_name))
        obj = next((path for path in candidates if path.is_file()), None)
        if obj is None:
            units.append({"object": object_name, "compiled": False, "compiler": "selected object missing"})
            continue
        unit = {"object": str(obj), "compiled": True}
        unit.update(classify_object(obj.read_bytes(), targets, names, bindings))
        unit["summary"].update(label_module_candidates(unit["exact_candidates"], module_report))
        units.append(unit)
    summary = summarize_module_units(units)
    result = {"version": 1, "mode": "module-object-candidates", "module": module_report.get("module", module),
              "module_report": str(report_path), "summary": summary, "units": units}
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(result, indent=2), encoding="utf-8")
    return result


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("sources", nargs="+")
    parser.add_argument("--output", type=Path, default=ROOT / "work/donor-converter/report.json")
    args = parser.parse_args(argv)
    try:
        report = convert(ROOT, args.sources, args.output)
    except ValueError as error:
        parser.error(str(error))
    print(json.dumps(report["summary"], indent=2))
    return 0 if report["summary"]["compiled"] == report["summary"]["sources"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
