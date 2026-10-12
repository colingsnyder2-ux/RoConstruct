"""Match remaining upstream G3D files against 2008-06 using proven fast x87 flags."""
import argparse
import hashlib
import json
from collections import defaultdict
from pathlib import Path

from benchmarks.match_campaign import Campaign
from roc import fingerprint, libs, match


def run(no_eh=False, fork=False):
    root = Path(__file__).resolve().parent.parent
    output = root / ("work/g3d-fork%s-2008-20261011" % ("-noeh" if no_eh else "") if fork else
                     "work/g3d-noeh-2008-20261011" if no_eh else "work/g3d-remaining-2008-20261011")
    campaign = Campaign(output, "http://127.0.0.1:8765")
    client, recipe = "2008-06", "rbxgs-g3d" if fork else "g3d-6.09"
    flags = "/O2 /GS- /MD /fp:fast" if no_eh else "/O2 /GS- /EHsc /MD /fp:fast"
    manifest_path = output / "manifest.json"
    if not manifest_path.exists():
        pilot = [json.loads(line) for line in
                 (root / "work/g3d-github-2008-20261011/compile.jsonl").read_text().splitlines()]
        excluded = {r["path"].replace("\\", "/") for r in pilot
                    if r["recipe"] == recipe and r["flags"] == flags and "error" not in r}
        files = {path.replace("\\", "/") for path in libs.files_of(libs.RECIPES[recipe], libs.fetch(recipe))}
        manifest_path.write_text(json.dumps({"client": client, "recipe": recipe, "flags": flags,
            "pilot_files": sorted(excluded), "files": sorted(files - excluded)}, indent=2))
    manifest = json.loads(manifest_path.read_text())
    rows = campaign.api.call("/v1/sources?client=" + client, timeout=120)
    scores = {r["addr"]: r["score"] for r in rows}
    if not (output / "before.json").exists():
        (output / "before.json").write_text(json.dumps(rows))
    target = fingerprint.Target(client)
    target.index = defaultdict(list)
    functions = match._functions(client)
    for addr, function in functions.items():
        if function.get("kind") == "code" and scores.get(addr, 0) < 100:
            target.index[function["size"]].append(addr)
    build = campaign.info["clients"][client]["compiler_build"]
    candidates = output / "local-candidates"
    candidates.mkdir(exist_ok=True)
    # Saved candidates survive interruptions between matching and server submission.
    for path in sorted(candidates.glob("*.cpp")):
        if scores.get(path.stem, 0) == 100:
            continue
        try:
            result = campaign.submit_exact("g3d-remaining-resume", client, path.stem, path.read_text())
        except (match.CompileError, ValueError, RuntimeError, OSError) as error:
            result = {"addr": path.stem, "error": str(error)}
        campaign.record("matches", result)
    done = {r["path"] for r in campaign.previous("compile") if "error" not in r}
    print("remaining cohort", len(manifest["files"]), "completed", len(done), flush=True)
    for number, path in enumerate(manifest["files"], 1):
        if path in done:
            continue
        # SDL expands GApp's main() calls after its declaration, which precedes SDL.h.
        file_flags = flags + " /DSDL_main=main" if path == "GLG3Dcpp/GApp.cpp" else flags
        source = libs.source_for(recipe, path, "cpp", build, file_flags)
        row = {"path": path, "flags": file_flags}
        try:
            obj = match.compile_text(client, source)
            row["object_sha256"] = hashlib.sha256(obj).hexdigest()
            hits = target.match_obj(obj, source)
            row["hits"] = {addr: hit[1] for addr, hit in hits.items()}
            print(number, "/", len(manifest["files"]), path, "local hits", len(hits), flush=True)
            for addr in hits:
                saved = candidates / (addr + ".cpp")
                saved.write_text(source)
                try:
                    result = campaign.submit_exact("g3d-remaining-x87-fast", client, addr, source)
                except (match.CompileError, ValueError, RuntimeError, OSError) as error:
                    result = {"addr": addr, "candidate_path": str(saved), "error": str(error)}
                campaign.record("matches", result)
                if result.get("score") != 100:
                    target.index[functions[addr]["size"]].append(addr)
                print("verify", addr, result.get("submission", {}), result.get("error", "")[:160], flush=True)
        except (match.CompileError, ValueError, RuntimeError, OSError) as error:
            row["error"] = str(error)
            print(number, "/", len(manifest["files"]), path, "error", str(error)[:160], flush=True)
        campaign.record("compile", row)
    results = campaign.previous("matches")
    wins = sorted({r["addr"] for r in results if r.get("submission", {}).get("verified")
                   and r["submission"].get("improved")})
    final = campaign.api.call("/v1/sources?client=" + client, timeout=120)
    final_scores = {r["addr"]: r["score"] for r in final}
    compiled = {r["path"] for r in campaign.previous("compile") if "error" not in r}
    summary = {"client": client, "files_planned": len(manifest["files"]),
               "files_compiled": len(compiled), "failed_files": sorted(set(manifest["files"]) - compiled),
               "local_candidates": len(list(candidates.glob("*.cpp"))), "verified_gains": wins,
               "stored_exact": sum(final_scores.get(addr) == 100 for addr in wins),
               "regressions": [addr for addr in wins if final_scores.get(addr) != 100], "ai_cost_usd": 0}
    (output / "summary.json").write_text(json.dumps(summary, indent=2))
    print("FINAL", json.dumps(summary), flush=True)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--no-eh", action="store_true", help="Test fast x87 without /EHsc in a separate journal")
    parser.add_argument("--fork", action="store_true", help="Test the Roblox G3D fork in a separate journal")
    args = parser.parse_args()
    run(args.no_eh, args.fork)
