"""Bounded 2008-only G3D vendor-inlining and GitHub-source experiment."""
import argparse
import hashlib
import json
import subprocess
from collections import Counter, defaultdict
from pathlib import Path

from benchmarks.match_campaign import Campaign
from roc import fingerprint, libs, match


def run(submit=False):
    root = Path(__file__).resolve().parent.parent
    output = root / "work/g3d-github-2008-20261011"
    campaign = Campaign(output, "http://127.0.0.1:8765")
    client = "2008-06"
    rows = campaign.api.call("/v1/sources?client=" + client, timeout=120)
    scores = {r["addr"]: r["score"] for r in rows}
    if submit:
        accepted = {r["addr"] for r in campaign.previous("matches")
                    if r.get("submission", {}).get("verified") or r.get("already_exact")}
        for previous in campaign.previous("matches"):
            if previous.get("submitted") is False and previous["addr"] not in accepted:
                result = campaign.submit_exact("g3d-pilot-resume", client, previous["addr"],
                                               Path(previous["candidate_path"]).read_text())
                campaign.record("matches", result)
                accepted.add(previous["addr"])
    (output / "before-pilot.json").write_text(json.dumps(rows))
    counts = Counter()
    for row in rows:
        recipe, _, path = match.directives(row.get("source", "")).get("lib", "").partition(" ")
        if row["score"] < 100 and recipe in ("g3d-6.09", "rbxgs-g3d"):
            counts[path] += 1
    paths = [path for path, _ in counts.most_common(12)]
    flags = ["/O2 /Ob1 /GF /GS /EHsc /MD", "/O2 /Ob1 /GF /GS- /EHsc /MD",
             "/O2 /Ob1 /GF /GS /EHsc /MD /arch:SSE2 /fp:fast",
             "/O2 /Ob1 /GF /GS- /EHsc /MD /arch:SSE2 /fp:fast"]
    github = root / "tools/external/g3d609-github"
    revision = subprocess.check_output(["git", "-C", str(github), "rev-parse", "HEAD"], text=True).strip()
    plans = [("g3d-6.09", path, flag) for path in paths for flag in flags]
    plans += [("g3d-6.09", path, flag) for path in dict.fromkeys(paths + ["GLG3Dcpp/GFont.cpp"])
              for flag in ("/O2 /GS- /EHsc /MD /fp:fast", "/O2 /GS /EHsc /MD /fp:fast")]
    # The GitHub fork changes two implementation files and two GLG3D headers.
    name = "g3d-github-2008-pilot-" + revision[:12]
    libs.RECIPES[name] = {**libs.RECIPES["g3d-6.09"],
                          "src": str(github), "include": [str(github / "include"),
                          str(github / "boost/include"), "WINSDK", "SDL-1.2.11/include"]}
    plans += [(name, path, flag) for path in ("GLG3Dcpp/Sky.cpp", "GLG3Dcpp/ToneMap.cpp",
                                            "GLG3Dcpp/RenderDevice.cpp") for flag in flags]
    (output / "manifest.json").write_text(json.dumps({"client": client, "github_commit": revision,
        "unresolved_candidate_paths": dict(counts), "plans": plans}, indent=2))
    target = fingerprint.Target(client)
    target.index = defaultdict(list)
    for addr, function in match._functions(client).items():
        if function.get("kind") == "code" and scores.get(addr, 0) < 100:
            target.index[function["size"]].append(addr)
    build = campaign.info["clients"][client]["compiler_build"]
    done = {(r["recipe"], r["path"], r["flags"]) for r in campaign.previous("compile")}
    for recipe, path, flag in plans:
        if (recipe, path, flag) in done:
            continue
        row = {"recipe": recipe, "path": path, "flags": flag}
        try:
            source = libs.source_for(recipe, path, "cpp", build, flag)
            if recipe == name:
                # Flatten to independently verifiable source; verifier needs no experimental recipe.
                source = "// GitHub RBLXDecomp/g3d commit %s; %s\n" % (revision, path) + \
                         "\n".join(line for line in source.splitlines() if not line.startswith("// roc-lib:")) + \
                         "\n" + libs.unit(recipe, path, build)
            obj = match.compile_text(client, source)
            row["object_sha256"] = hashlib.sha256(obj).hexdigest()
            hits = target.match_obj(obj, source)
            row["hits"] = {addr: hit[1] for addr, hit in hits.items()}
            for addr, hit in hits.items():
                candidate = output / "local-candidates" / (addr + ".cpp")
                candidate.parent.mkdir(exist_ok=True)
                candidate.write_text(source)
                stage = "g3d-vendor-ob1" if "/Ob1" in flag else "g3d-x87-fast"
                result = campaign.submit_exact(stage, client, addr, source) if submit else \
                         {"addr": addr, "local_score": match.check_text(client, addr, source)[0],
                          "candidate_path": str(candidate), "submitted": False}
                campaign.record("matches", result)
        except (match.CompileError, ValueError, RuntimeError, OSError) as error:
            row["error"] = str(error)
        campaign.record("compile", row)
        print(recipe, path, flag, "hits", len(row.get("hits", {})), row.get("error", "")[:160], flush=True)
    # Concrete residuals: decodeTGA differs in stack extent; GFont in x87 multiply order.
    completed = {(r["addr"], r["flags"]) for r in campaign.previous("residual")}
    for original in rows:
        if original["addr"] not in ("0050bb30", "007b6b30") or original["score"] == 100:
            continue
        source = original["source"]
        original_flags = match.directives(source)["flags"]
        for suffix in ("/fp:strict", "/fp:precise", "/fp:fast", "/GS", "/GS /Oy-", "/Oi-", "/Oi"):
            flag = original_flags + " " + suffix
            if (original["addr"], flag) in completed:
                continue
            candidate = source.replace("// roc-flags: " + original_flags, "// roc-flags: " + flag)
            row = {"addr": original["addr"], "flags": flag, "server_before": original["score"]}
            try:
                score, symbol, diff, spans = match.check_text(client, original["addr"], candidate)
                row.update(score=score, symbol=symbol, diff=diff)
                if score == 100:
                    saved = output / "local-candidates" / (original["addr"] + ".cpp")
                    saved.parent.mkdir(exist_ok=True)
                    saved.write_text(candidate)
                    result = campaign.submit_exact("g3d-residual", client, original["addr"], candidate) if submit else \
                             {"addr": original["addr"], "local_score": score, "submitted": False,
                              "candidate_path": str(saved)}
                    campaign.record("matches", result)
            except (match.CompileError, ValueError, RuntimeError, OSError) as error:
                row["error"] = str(error)
            campaign.record("residual", row)
            print("residual", original["addr"], suffix, row.get("score"), row.get("error", "")[:160], flush=True)
    results = campaign.previous("matches")
    summary = {"client": client, "configurations": len(campaign.previous("compile")),
               "compile_errors": sum("error" in row for row in campaign.previous("compile")),
               "residual_trials": len(campaign.previous("residual")),
               "local_candidates": len({r["addr"] for r in results}),
               "verified_gains": sorted({r["addr"] for r in results
                                         if r.get("submission", {}).get("improved")
                                         and r["submission"].get("verified")}), "ai_cost_usd": 0}
    (output / "summary.json").write_text(json.dumps(summary, indent=2))
    print(json.dumps(summary), flush=True)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--submit", action="store_true")
    run(parser.parse_args().submit)
