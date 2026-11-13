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


def compile_sources(sources, output):
    spec = rebuild.load_module("2008-06", "rbxgs-app-openrbx-selective")
    recipe = libs.RECIPES["rbxgs"]
    with lock(Path(output).parent / "compile.lock"):
        overlay = rebuild.build_overlay("2008-06", "RbxgsAppOpenRBXProbe", spec.get("overlay"))
        return rebuild.compile_direct(
            "2008-06", sources, output,
            [(libs.LIBS / folder).resolve() for folder in recipe["include"] if folder != "WINSDK"],
            recipe["defines"] + " BOOST_ALL_NO_LIB",
            "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD", overlay=overlay)


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
