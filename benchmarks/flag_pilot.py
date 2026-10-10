"""Frozen random source sample; per-target flag changes, no global config writes."""
import json
import random
import re
import argparse

from benchmarks.match_campaign import Campaign, digest
from roc import flags, match


def run(client_filter=None):
    campaign = Campaign("work/match-campaign-20261010", "http://127.0.0.1:8765")
    manifest = campaign.root / ("flag-pilot-%s-manifest.json" % (client_filter or "all"))
    if not manifest.exists():
        rows = []
        for client, sources in campaign.snapshot().items():
            for addr, row in sources.items():
                source = row.get("source", "")
                if (not client_filter or client == client_filter) and 0 < row.get("score", 0) < 100 and source and len(source) < 6000:
                    if not any(k in match.directives(source) for k in ("lib", "archive")):
                        rows.append(dict(client=client, addr=addr, source=source))
        random.Random(20261010).shuffle(rows)
        manifest.write_text(json.dumps(rows[:30], indent=1), encoding="utf-8")
    done = {(r["client"], r["addr"]) for r in campaign.previous("flag-pilot")}
    for row in json.loads(manifest.read_text(encoding="utf-8")):
        client, addr, source = row["client"], row["addr"], row["source"]
        if client not in campaign.info["clients"] or (client, addr) in done:
            continue
        result = dict(client=client, addr=addr, source_sha256=digest(source), variants=[])
        try:
            result["before"] = match.check_text(client, addr, source)[0]
            current = match.directives(source).get("flags", match.DEFAULT_FLAGS).split()
            best = result["before"]
            for group in flags.GROUPS:
                for option in group:
                    trial = " ".join([v for v in current if v not in group] + ([option] if option else []))
                    if trial == " ".join(current):
                        continue
                    try:
                        score = match.check_text(client, addr, source, trial)[0]
                        result["variants"].append(dict(flags=trial, score=score))
                        if score > best:
                            best = score
                        if score == 100 and result["before"] < 100:
                            candidate = re.sub(r"(?m)^\s*//\s*roc-flags:.*$", "", source)
                            result["winner"] = campaign.submit_exact("flag-pilot", client, addr, candidate, trial)
                            break
                    except (RuntimeError, ValueError, OSError, SystemExit) as error:
                        result["variants"].append(dict(flags=trial, error=str(error)[-300:]))
                if "winner" in result:
                    break
            result["best"] = best
        except (RuntimeError, ValueError, OSError, SystemExit) as error:
            result["error"] = str(error)[-300:]
        campaign.record("flag-pilot", result)
        print(client, addr, result.get("before"), result.get("best"), flush=True)


if __name__ == "__main__":
    ap = argparse.ArgumentParser()
    ap.add_argument("--client")
    run(ap.parse_args().client)
