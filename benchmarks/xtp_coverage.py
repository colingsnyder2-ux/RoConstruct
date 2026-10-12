"""Resume exact XTP configuration pilots and transfer their winning sources."""
import argparse
import json
from collections import Counter, defaultdict
from pathlib import Path

from benchmarks.match_campaign import Campaign, digest
from roc import fingerprint, libs, match

ROOT = Path("work/xtp-2008-20261011")


def run(limit, transfer=False):
    campaign = Campaign(ROOT, "http://127.0.0.1:8765")
    stage = "ob1-transfer" if transfer else "ob1-files"
    previous = campaign.previous(stage)
    done = {r["key"] for r in previous}
    clients = list(campaign.info["clients"]) if transfer else ["2008-06"]
    targets, scores = {}, {}
    for client in clients:
        rows = campaign.api.call("/v1/sources?client=" + client, timeout=120)
        scores[client] = {r["addr"]: r["score"] for r in rows}
        target = fingerprint.Target(client)
        target.index = defaultdict(list)
        for addr, function in match._functions(client).items():
            if function.get("kind") == "code" and scores[client].get(addr, 0) < 100:
                if transfer or "CXTP" in function.get("unit", ""):
                    target.index[function["size"]].append(addr)
        targets[client] = target

    if transfer:
        sources = {}
        for pilot in ("ob1-pilot", "ob1-files"):
            for row in campaign.previous(pilot):
                for winner in row.get("winners", [row]):
                    if winner.get("submission", {}).get("improved"):
                        source = Path(winner["candidate_path"]).read_text()
                        sources[digest(source)] = source
        plans = [(client, source) for source in sources.values() for client in clients]
    else:
        manifest = ROOT / "ob1-files-manifest.json"
        if manifest.exists():
            plans = [tuple(row) for row in json.loads(manifest.read_text())]
        else:
            snapshot = json.loads((ROOT / "sources-2008-06.json").read_text())
            support = Counter()
            for row in snapshot:
                if row["score"] < 100:
                    directive = match.directives(row.get("source", ""))
                    recipe, _, path = directive.get("lib", "").partition(" ")
                    if recipe.startswith("xtp-") and path:
                        support[path.replace("\\", "/")] += 1
            recipe = libs.RECIPES["xtp-11.2.2-shared-mfc"]
            folder = libs.fetch("xtp-11.2.2-shared-mfc")
            paths = sorted(libs.files_of(recipe, folder),
                           key=lambda p: (-support[p.replace("\\", "/")], p))
            # Explicit inlining fixes the observed runtime-class call difference.
            # Test EH/cookies both ways; no global compiler settings are changed.
            plans = []
            for path in paths:
                for flags in ("/O2 /MD /GS /EHsc /Ob1", "/O2 /MD /GS- /Ob1"):
                    source = ("// roc-lang: cpp\n// roc-cl: 21022\n"
                              "// roc-flags: " + flags + "\n"
                              "// roc-lib: xtp-11.2.2-shared-mfc " + path + "\n")
                    plans.append(("2008-06", source))
            manifest.write_text(json.dumps(plans))

    for client, source in plans[:limit] if limit else plans:
        key = digest(client + source)
        if key in done:
            continue
        row = dict(key=key, client=client, directives=match.directives(source), winners=[])
        try:
            obj = match.compile_text(client, source)
            found = targets[client].match_obj(obj, source)
            if not transfer and found:
                baseline = source.replace(" /Ob1", "")
                base = fingerprint.Target(client)
                base.index = defaultdict(list)
                for addr in found:
                    base.index[match._functions(client)[addr]["size"]].append(addr)
                baseline_found = base.match_obj(match.compile_text(client, baseline), baseline)
                row["baseline_matches"] = list(baseline_found)
                row["ob1_only"] = [addr for addr in found if addr not in baseline_found]
            for addr in found:
                winner = campaign.submit_exact(stage, client, addr, source)
                winner["symbol"] = found[addr][1]
                row["winners"].append(winner)
                if winner.get("already_exact") or winner.get("submission", {}).get("score") == 100:
                    scores[client][addr] = 100
        except (RuntimeError, ValueError, OSError, SystemExit) as error:
            row["error"] = str(error)[-1000:]
        campaign.record(stage, row)
        print(stage, client, row["directives"]["lib"], len(row["winners"]),
              row.get("error", "")[:120], flush=True)

    winners = {(w["client"], w["addr"]) for row in campaign.previous(stage)
               for w in row.get("winners", []) if w.get("submission", {}).get("improved")}
    print("TOTAL", stage, len(winners), flush=True)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--limit", type=int, default=24, help="0 checks all frozen plans")
    parser.add_argument("--transfer", action="store_true")
    args = parser.parse_args()
    run(args.limit, args.transfer)
