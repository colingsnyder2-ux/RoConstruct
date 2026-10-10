"""Wait for existing sweeps, then propagate live donors and refresh class layouts."""
import argparse
import json
import shutil
import time
from pathlib import Path

import psutil

from benchmarks import class_layout, match_campaign
from benchmarks.followup_pilots import OLD, ROOT, live
from benchmarks.library_branches import reserved_shapes


class FreshCampaign(match_campaign.Campaign):
    def __init__(self, output, server=None):
        super().__init__(str(ROOT / "fresh-donors"), server)

    def snapshot(self):
        rows = live(self)
        for client, sources in rows.items():
            (self.root / ("sources-" + client + ".json")).write_text(json.dumps(list(sources.values())), encoding="utf-8")
        return rows


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--wait-pids", type=int, nargs="+", required=True)
    args = ap.parse_args()
    waiting = []
    for pid in args.wait_pids:
        try:
            waiting.append(psutil.Process(pid))
        except psutil.NoSuchProcess:
            pass
    root = ROOT / "fresh-donors"
    root.mkdir(parents=True, exist_ok=True)
    (root / "queue.json").write_text(json.dumps({"pids": args.wait_pids, "state": "waiting"}), encoding="utf-8")
    while (any(p.is_running() for p in waiting) or
           any(any(module in (p.info.get("cmdline") or [])
                   for module in ("benchmarks.library_branches", "benchmarks.branch_loop"))
               for p in psutil.process_iter(["cmdline"]))):
        time.sleep(10)
    for stage in ("propagation", "class-layout"):
        src, dst = OLD / (stage + ".jsonl"), root / (stage + ".jsonl")
        if src.exists() and not dst.exists():
            shutil.copyfile(src, dst)
    campaign = FreshCampaign(str(root), "http://127.0.0.1:8765")
    excluded = reserved_shapes()
    original_index = match_campaign.family_index

    def indexes(campaign):
        return {client: {a: family for a, family in rows.items()
                         if match_campaign.match._functions(client)[a].get("shape") not in excluded}
                for client, rows in original_index(campaign).items()}

    match_campaign.family_index = indexes
    class_layout.family_index = indexes
    class_layout.Campaign = FreshCampaign
    (root / "queue.json").write_text(json.dumps({"state": "propagating fresh live donors"}), encoding="utf-8")
    match_campaign.propagate(campaign, donor_limit=0)
    (root / "queue.json").write_text(json.dumps({"state": "refreshing layouts"}), encoding="utf-8")
    class_layout.run(10000000, refresh=True)
    (root / "queue.json").write_text(json.dumps({"state": "complete"}), encoding="utf-8")


if __name__ == "__main__":
    main()
