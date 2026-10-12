"""Find (and optionally submit) 2008 functions a recipe compiles to exactly.

Compiles every file of each recipe under each grid flag set, matches the objects
against the client's unmatched functions, and writes work/<client>/probe-<recipe>.json.
With --submit, sends each exact to the server for verification.
"""
import argparse
import json
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

from benchmarks.match_campaign import Campaign
from roc import fingerprint, libs, match

ROOT = Path(__file__).resolve().parent.parent


def probe(client, recipes, server, submit, jobs):
    campaign = Campaign(ROOT / "work" / "recipe-probe", server)
    scores = {r["addr"]: r["score"] for r in campaign.api.call("/v1/sources?client=" + client, timeout=300)}
    target = fingerprint.Target(client)
    target.index = defaultdict(list)
    for addr, f in match._functions(client).items():
        if f.get("kind") == "code" and scores.get(addr, 0) < 100:
            target.index[f["size"]].append(addr)
    build = campaign.info["clients"][client]["compiler_build"]
    plans = []
    for name in recipes:
        r = libs.RECIPES[name]
        for path in libs.files_of(r, libs.fetch(name)):
            for lang in r["langs"]:
                for flags in r.get("grid", libs.GRID):
                    plans.append(libs.source_for(name, path, lang, build, flags))

    def one(source):
        try:
            return source, target.match_obj(match.compile_text(client, source), source)
        except BaseException:
            return source, {}

    found = {}
    with ThreadPoolExecutor(jobs) as pool:
        for source, hits in pool.map(one, plans):
            for addr, hit in hits.items():
                found.setdefault(addr, (source, hit[1]))
    print(client, "plans", len(plans), "exact", len(found), flush=True)
    won = 0
    for addr, (source, symbol) in sorted(found.items()):
        line = [addr, symbol[:70], match.directives(source)["lib"]]
        if submit:
            try:
                w = campaign.submit_exact("probe", client, addr, source)
                campaign.record("probe", w)
                won += bool(w.get("submission", {}).get("improved"))
                line.append(w.get("submission", {}).get("improved"))
            except (ValueError, RuntimeError, OSError) as e:
                line.append("ERR " + str(e)[:80])
        print(*line, flush=True)
    out = ROOT / "work" / client / ("probe-%s.json" % "+".join(recipes))
    out.write_text(json.dumps({a: s for a, (s, _) in found.items()}, indent=1))
    if submit:
        print("verified", won, flush=True)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("recipes", nargs="+")
    parser.add_argument("--client", default="2008-06")
    parser.add_argument("--server", default="http://127.0.0.1:8765")
    parser.add_argument("--submit", action="store_true")
    parser.add_argument("--jobs", type=int, default=3)
    a = parser.parse_args()
    probe(a.client, a.recipes, a.server, a.submit, a.jobs)
