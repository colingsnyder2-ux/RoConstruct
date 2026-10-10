"""Compare repair history on one client with a single shared cloud budget."""
import argparse
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import benchmark, metrics, providers


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--client", default="2007-08")
    parser.add_argument("--repeats", type=int, default=2)
    parser.add_argument("--max-cloud-cost", type=float, default=0.75)
    parser.add_argument("--session", required=True)
    parser.add_argument("--manifest", type=Path)
    parser.add_argument("--allow-cloud", action="store_true")
    args = parser.parse_args()
    corpus = json.loads(args.manifest.read_text()) if args.manifest else benchmark.load()
    corpus = [row for row in corpus if row["client"] == args.client]
    if not corpus:
        raise SystemExit("No benchmark targets for " + args.client)
    budget = providers.CloudBudget(requests=150, tokens=1000000, cost=args.max_cloud_cost)
    metrics.PATH = Path("work") / args.session / "metrics.jsonl"
    sessions = []
    for repeat in range(args.repeats):
        for arm in (("control", "compact") if repeat % 2 == 0 else ("compact", "control")):
            session = "%s-%s-r%d" % (args.session, arm, repeat + 1)
            sessions.append(session)
            for target in corpus:
                benchmark.run_local([target], ["deepseek:deepseek-flash"], rounds=3,
                    session=session, candidate_dir=Path("work") / args.session / session,
                    provider_options=dict(allow_cloud=args.allow_cloud, budget=budget,
                        max_tokens=2048, thinking="disabled", seed=42,
                        history_keep_last=0 if arm == "compact" and target["size"] > 48 else 2))
    rows = metrics.recent_rows()
    rows = [row for row in rows if row.get("session") in sessions and row.get("event") == "job"]
    result = {"client": args.client, "requests": budget.requests, "reserved_cost": budget.cost,
              "limit": args.max_cloud_cost, "rows": rows}
    output = Path("work") / args.session / "report.json"
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(result, indent=2), encoding="utf-8")
    for arm in ("control", "compact"):
        jobs = [row for row in rows if "-" + arm + "-" in row["session"]]
        print(arm, "jobs", len(jobs), "exact", sum(row["score"] == 100 for row in jobs),
              "mean", round(sum(row["score"] for row in jobs) / len(jobs), 2),
              "input", sum(row["input_tokens"] for row in jobs),
              "cost", round(sum(row.get("estimated_cost") or 0 for row in jobs), 6), flush=True)
    print("Total reserved cost:", budget.cost, flush=True)


if __name__ == "__main__":
    main()
