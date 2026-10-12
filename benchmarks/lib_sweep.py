"""Replay every file of library recipes against every client's unmatched functions.

The XTP 2008 method (docs/investigations/xtp-2008-coverage-20261011.md) generalised:
once a recipe's build configuration is fixed, recompile every file under its grid and
submit each function the server verifies byte-exact. Resumable; run several
--shard i/n processes side by side (each keeps its own journal).
"""
import argparse
from collections import defaultdict
from pathlib import Path

from benchmarks.match_campaign import Campaign, digest
from benchmarks.xtp_coverage_run import transfer_sources
from roc import fingerprint, libs, match, setup

ROOT = Path("work/libs-2008-20261011")


def plans_for(names, clients):
    """[(client, source)]: each recipe file x flags x build, for clients built with that compiler."""
    have, plans = setup.compilers(), []
    for name in names:
        r = libs.RECIPES[name]
        folder = libs.fetch(name)
        for build in [b for b in r.get("builds", libs.BUILDS) if b in have]:
            same = [c for c, e in clients.items() if e.get("compiler_build") == build]
            for f in libs.files_of(r, folder) if same else ():
                try:
                    libs.unit(name, f, build)
                except match.CompileError:
                    continue
                for lang in r["langs"]:
                    for flags in r.get("grid", libs.GRID):
                        source = libs.source_for(name, f, lang, build, flags)
                        plans += [(c, source) for c in same]
    return plans


def run(names, server, shard, only=("2008-06",)):
    campaign = Campaign(ROOT, server)
    stage = "sweep" + ("-%d" % shard[0] if shard else "")
    done = {r["key"] for r in campaign.previous(stage) if "error" not in r}
    plans = plans_for(names, {c: e for c, e in campaign.info["clients"].items() if c in only})
    sources = sorted({s for _, s in plans})
    if shard:
        keep = set(sources[shard[0]::shard[1]])
        plans = [(c, s) for c, s in plans if s in keep]
    targets = {}
    for client in {c for c, _ in plans}:
        scores = {r["addr"]: r["score"] for r in campaign.api.call("/v1/sources?client=" + client, timeout=300)}
        target = fingerprint.Target(client)
        target.index = defaultdict(list)
        for addr, function in match._functions(client).items():
            if function.get("kind") == "code" and scores.get(addr, 0) < 100:
                target.index[function["size"]].append(addr)
        targets[client] = target
    print("plans", len(plans), "sources", len({s for _, s in plans}), flush=True)
    transfer_sources(campaign, plans, targets, done, stage)
    wins = {(w["client"], w["addr"]) for row in campaign.previous(stage)
            for w in row.get("winners", []) if w.get("submission", {}).get("improved")}
    print("TOTAL", stage, len(wins), flush=True)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("names", nargs="+", help="libs.RECIPES entries")
    parser.add_argument("--server", default="http://127.0.0.1:8765")
    parser.add_argument("--shard", help="i/n: this process takes every n-th source from i")
    parser.add_argument("--client", action="append", help="client(s) to sweep (default 2008-06)")
    args = parser.parse_args()
    run(args.names, args.server, tuple(map(int, args.shard.split("/"))) if args.shard else None,
        tuple(args.client or ["2008-06"]))
