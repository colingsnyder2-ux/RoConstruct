"""Compile trusted donor sources and emit byte-proven native candidates."""
import argparse
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


def rank_partials(raw, targets, names, exact_symbols, threshold=.8,
                  functions=match.coff_functions, similarity=match.similarity_ratio):
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
        if best:
            rows.append(best)
    return sorted(rows, key=lambda row: (-row["similarity"], row["symbol"]))


def classify_object(raw, targets, names, bindings, harvest=native_bulk.harvest, rank=rank_partials):
    rows = harvest(raw, targets, names, bindings)
    exact = [row for row in rows if row["status"] == "inactive_exact"]
    advisory = rank(raw, targets, names, {row["symbol"] for row in exact})
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
        },
        "exact_candidates": exact,
        "repair_candidates": partials,
        "proof_candidates": proof_blocked,
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
