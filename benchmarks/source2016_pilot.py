"""Retry preserved 2016 vendor code on 2008-06 near misses, with full journals."""
import argparse
import hashlib
import json
import tempfile
from collections import defaultdict
from pathlib import Path

from benchmarks.match_campaign import Campaign, digest
from roc import fingerprint, libs, match

CLIENT = "2008-06"
ROOT = Path("work/source2016-pilot-20261011")


def groups(rows):
    available = {}
    for name in ("rbx2016-g3d", "rbx2016-lua", "rbx2016-jpeg", "rbx2016-png", "rbx2016-raknet"):
        recipe = libs.RECIPES[name]
        for path in libs.files_of(recipe, libs.fetch(name)):
            available[name, Path(path).name.lower()] = path
    result = defaultdict(list)
    for row in sorted(rows, key=lambda r: (-r["score"], r["addr"])):
        if not 80 <= row["score"] < 100:
            continue
        directive = match.directives(row.get("source", ""))
        old, _, path = directive.get("lib", "").partition(" ")
        family = next((f for f in ("g3d", "lua", "jpeg", "png", "raknet") if f in old), None)
        if family and ("rbx2016-" + family, Path(path).name.lower()) in available:
            name = "rbx2016-" + family
            result[name, available[name, Path(path).name.lower()]].append(row)
    return result


def candidates(name, path):
    recipe = libs.RECIPES[name]
    folder = libs.fetch(name).resolve()
    original = folder / path
    evidence = {"recipe": name, "path": str(original), "vendor_sha256": hashlib.sha256(original.read_bytes()).hexdigest(),
                "compiler": 21022, "reason": "same source filename as stored 80-99% candidate"}
    modes = ["existing-recipe", "DLL-preprocess"]
    if name == "rbx2016-raknet" and path == "PacketLogger.cpp":
        modes.append("PacketLogger-enabled")
    for mode in modes:
        body = None
        if mode != "existing-recipe":
            include = ";".join([str(folder)] + [libs.winsdk_include() if i == "WINSDK" else
                                str(libs._case_path(libs.LIBS / i)) for i in recipe.get("include", [])])
            if name == "rbx2016-lua":
                tree = libs._case_path(libs.LIBS / libs.REF).resolve()
                include += ";" + str(tree / "App/include") + ";" + str(tree / "Base/include")
            evidence["preprocess_include"] = include
            evidence["preprocess_defines"] = (recipe.get("defines", "") + " _DLL").strip()
            try:
                if mode == "PacketLogger-enabled":
                    with tempfile.TemporaryDirectory() as temp:
                        wrapper = Path(temp) / "packet.cpp"
                        wrapper_source = ('#include "%s"\n#undef _RAKNET_SUPPORT_PacketLogger\n'
                                          '#define _RAKNET_SUPPORT_PacketLogger 1\n#include "%s"\n' %
                                          ((folder / "NativeFeatureIncludesOverrides.h").as_posix(), original.as_posix()))
                        wrapper.write_text(wrapper_source)
                        evidence["wrapper_source"] = wrapper_source
                        body = libs.preprocess(21022, wrapper, include, (recipe.get("defines", "") + " _DLL").strip())
                elif name == "rbx2016-lua":
                    # This fork includes eh.h; vendor .c files must be preprocessed as C++.
                    with tempfile.TemporaryDirectory() as temp:
                        wrapper = Path(temp) / "lua.cpp"
                        wrapper_source = '#include "%s"\n' % original.as_posix()
                        wrapper.write_text(wrapper_source)
                        evidence["wrapper_source"] = wrapper_source
                        body = libs.preprocess(21022, wrapper, include, (recipe.get("defines", "") + " _DLL").strip())
                else:
                    body = libs.preprocess(21022, original, include, (recipe.get("defines", "") + " _DLL").strip())
            except (RuntimeError, OSError, SystemExit) as error:
                yield None, dict(evidence, mode=mode, error=str(error))
                continue
        for lang in recipe["langs"]:
            for flags in recipe.get("grid", libs.GRID):
                source = libs.source_for(name, path, lang, 21022, flags) if body is None else (
                    "// roc-lang: %s\n// roc-cl: 21022\n// roc-flags: %s\n" % (lang, flags) + body)
                yield source, dict(evidence, mode=mode, flags=flags, lang=lang)


def run(server, limit, submit):
    campaign = Campaign(ROOT, server)
    try:
        rows = campaign.api.call("/v1/sources?client=" + CLIENT, timeout=300)
        (ROOT / "initial-scores.json").write_text(json.dumps(rows), encoding="utf-8")
        scores = {r["addr"]: r["score"] for r in rows}
        target = fingerprint.Target(CLIENT)
        target.index = defaultdict(list)
        for addr, f in match._functions(CLIENT).items():
            if f.get("kind") == "code" and scores.get(addr, 0) < 100:
                target.index[f["size"]].append(addr)
        done = {r["key"] for r in campaign.previous("attempts")}
        selected = list(groups(rows).items())[:limit]
        campaign.record("plans", {"client": CLIENT, "units": [{"recipe": n, "path": p,
                               "targets": [{"addr": r["addr"], "score": r["score"]} for r in rs]}
                              for (n, p), rs in selected]})
        for (name, path), near in selected:
            for source, evidence in candidates(name, path):
                key = digest(source) if source is not None else digest(json.dumps(evidence, sort_keys=True))
                if key in done:
                    continue
                row = {"key": key, "evidence": evidence, "partials": [], "winners": []}
                if source is None:
                    row["error"] = evidence["error"]
                else:
                    saved = ROOT / "sources" / (key + ".cpp")
                    saved.parent.mkdir(exist_ok=True)
                    saved.write_text(source, encoding="utf-8")
                    row["source_path"] = str(saved)
                    try:
                        obj = match.compile_text(CLIENT, source)
                        for r in near:
                            score, symbol, diff, spans = match.check_text(CLIENT, r["addr"], source)
                            row["partials"].append({"addr": r["addr"], "stored_score": r["score"], "score": score,
                                "symbol": symbol, "diff": diff, "reason": "exact" if score == 100 else
                                "improved partial" if score > r["score"] else "no improvement"})
                        for addr in sorted(target.match_obj(obj, source)):
                            result = campaign.submit_exact("source2016", CLIENT, addr, source) if submit else {"addr": addr, "score": 100, "local_only": True}
                            row["winners"].append(result)
                    except (RuntimeError, ValueError, OSError, SystemExit) as error:
                        row["error"] = str(error)
                campaign.record("attempts", row)
                done.add(key)
                print(name, path, evidence["mode"], evidence.get("flags"),
                      [(r["addr"], r["stored_score"], r["score"]) for r in row["partials"]],
                      "exact", len(row["winners"]), row.get("error", "")[-180:], flush=True)
        attempts = campaign.previous("attempts")
        wins = {w["addr"] for r in attempts for w in r["winners"] if w.get("submission", {}).get("improved")}
        partials = {(p["addr"], r["key"]) for r in attempts for p in r["partials"] if p["stored_score"] < p["score"] < 100}
        summary = {"client": CLIENT, "units_selected": len(selected), "candidates_attempted": len(attempts),
                   "functions_attempted": len({p["addr"] for r in attempts for p in r["partials"]}),
                   "new_server_verified_exacts": len(wins), "improved_partial_candidates": len(partials),
                   "compile_or_preprocess_errors": sum("error" in r for r in attempts), "paid_ai_cost": 0}
        (ROOT / "summary.json").write_text(json.dumps(summary, indent=2), encoding="utf-8")
        print(summary, flush=True)
    finally:
        campaign.api.close()


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--server", default="http://127.0.0.1:8765")
    parser.add_argument("--units", type=int, default=10)
    parser.add_argument("--submit", action="store_true")
    args = parser.parse_args()
    run(args.server, args.units, args.submit)
