"""Compare first-round repair against a frozen worker with one shared budget."""
import argparse
import hashlib
import importlib.util
import json
import sys
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import benchmark, clients, draft, match, metrics, providers


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("manifest", type=Path)
    parser.add_argument("--control-draft", type=Path, required=True)
    parser.add_argument("--session", required=True)
    parser.add_argument("--repeats", type=int, default=1)
    parser.add_argument("--max-cloud-cost", type=float, default=0.5)
    parser.add_argument("--allow-cloud", action="store_true")
    parser.add_argument("--near-repair", action="store_true")
    args = parser.parse_args()
    corpus = json.loads(args.manifest.read_text())
    starts = {}
    for target in corpus:
        source = Path(target["source_path"]).read_text(encoding="utf-8")
        if hashlib.sha256(source.encode()).hexdigest() != target["source_sha256"]:
            raise SystemExit("Baseline source changed: " + target["addr"])
        score = match.check_text(target["client"], target["addr"], source,
                                 clients.load()[target["client"]].get("flags"))[0]
        if score != target["base_score"] or score == 100:
            raise SystemExit("Baseline score changed: " + target["addr"])
        starts[target["client"], target["addr"]] = source, score
    spec = importlib.util.spec_from_file_location("roc._repair_control", args.control_draft)
    control = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(control)
    fixed = draft.llm_rounds
    budget = providers.CloudBudget(requests=200, tokens=1000000, cost=args.max_cloud_cost)
    folder = Path("work") / args.session
    metrics.PATH = folder / "metrics.jsonl"
    sessions = []
    for repeat in range(args.repeats):
        for arm in (("control", "fixed") if repeat % 2 == 0 else ("fixed", "control")):
            session = "%s-%s-r%d" % (args.session, arm, repeat + 1)
            sessions.append(session)
            with patch.object(draft, "llm_rounds", control.llm_rounds if arm == "control" else fixed):
                benchmark.run_local(corpus, ["deepseek:deepseek-flash"], rounds=3,
                    session=session, candidate_dir=folder / session, initial_sources=starts,
                    provider_options=dict(allow_cloud=args.allow_cloud, budget=budget,
                        max_tokens=2048, thinking="disabled", seed=42, near_repair=args.near_repair))
    rows = [row for row in metrics.recent_rows()
            if row.get("session") in sessions and row.get("event") == "job"]
    result = {"requests": budget.requests, "reserved_cost": budget.cost,
              "limit": args.max_cloud_cost, "manifest": corpus,
              "control_sha256": hashlib.sha256(args.control_draft.read_bytes()).hexdigest(),
              "rows": rows}
    folder.mkdir(parents=True, exist_ok=True)
    (folder / "report.json").write_text(json.dumps(result, indent=2), encoding="utf-8")
    for arm in ("control", "fixed"):
        jobs = [row for row in rows if "-" + arm + "-" in row["session"]]
        print(arm, "jobs", len(jobs), "exact", sum(row["score"] == 100 for row in jobs),
              "improved", sum(row["improved"] for row in jobs),
              "mean", round(sum(row["score"] for row in jobs) / len(jobs), 2),
              "cost", round(sum(row.get("estimated_cost") or 0 for row in jobs), 6), flush=True)
    print("Total reserved cost:", budget.cost, flush=True)


if __name__ == "__main__":
    main()
