"""Run a second verified donor/layout pass after fresh refresh completes."""
import argparse
import json
import time

import psutil

from benchmarks import class_layout, followup_refresh, match_campaign
from benchmarks.library_branches import reserved_shapes


def main(wait_pid):
    if wait_pid > 0:
        try:
            process = psutil.Process(wait_pid)
            while process.is_running():
                time.sleep(10)
        except psutil.NoSuchProcess:
            pass
    root = followup_refresh.ROOT / "fresh-donors"
    campaign = followup_refresh.FreshCampaign(str(root), "http://127.0.0.1:8765")
    excluded = reserved_shapes()
    original_index = match_campaign.family_index

    def indexes(current):
        return {client: {addr: family for addr, family in rows.items()
                         if client != "2009-12" and match_campaign.match._functions(client)[addr].get("shape") not in excluded}
                for client, rows in original_index(current).items() if client != "2009-12"}

    match_campaign.family_index = indexes
    class_layout.family_index = indexes
    class_layout.Campaign = followup_refresh.FreshCampaign
    queue = root / "queue.json"
    queue.write_text(json.dumps({"state": "second chained propagation"}), encoding="utf-8")
    match_campaign.propagate(campaign, donor_limit=0)
    queue.write_text(json.dumps({"state": "second class-layout refresh"}), encoding="utf-8")
    class_layout.run(10000000, refresh=True)
    queue.write_text(json.dumps({"state": "second pass complete"}), encoding="utf-8")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--wait-pid", type=int, default=0)
    main(parser.parse_args().wait_pid)
