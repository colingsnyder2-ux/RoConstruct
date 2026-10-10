"""Paired discovery/holdout test of Auto reliability with one shared budget."""
import argparse
import hashlib
import importlib.util
import json
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import benchmark, draft, match, metrics, providers, worker


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("manifest", type=Path)
    parser.add_argument("--control-dir", type=Path, required=True)
    parser.add_argument("--session", required=True)
    parser.add_argument("--max-cloud-cost", type=float, default=1.5)
    parser.add_argument("--allow-cloud", action="store_true")
    parser.add_argument("--adaptive-only", action="store_true", help="Keep control's starting cap and hint policy")
    args = parser.parse_args()
    corpus = json.loads(args.manifest.read_text())
    controls = {}
    for name in ("draft", "worker"):
        spec = importlib.util.spec_from_file_location("roc._auto_control_" + name,
                                                      args.control_dir / ("control_" + name + ".py"))
        controls[name] = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(controls[name])
    fixed = draft.llm_rounds
    folder = Path("work") / args.session
    metrics.PATH = folder / "metrics.jsonl"
    budget = providers.CloudBudget(requests=300, tokens=1500000, cost=args.max_cloud_cost)
    gate = providers.CloudGate(4)
    sessions = []
    for split_index, split in enumerate(("discovery", "holdout")):
        targets = [row for row in corpus if row["split"] == split]
        for repeat in range(2):
            arms = ("control", "reliable") if (repeat + split_index) % 2 == 0 else ("reliable", "control")
            for arm in arms:
                session = "%s-%s-%s-r%d" % (args.session, split, arm, repeat + 1)
                sessions.append(session)
                policy = controls["worker"] if arm == "control" or args.adaptive_only else worker

                def run(target):
                    row = match._functions(target["client"])[target["addr"]]
                    thinking, effort = policy.auto_reasoning(row, "auto", "auto", "deepseek:deepseek-flash")
                    options = dict(allow_cloud=args.allow_cloud, budget=budget, gate=gate,
                        max_tokens=policy.resolve_output_tokens(row, "auto"), thinking=thinking,
                        reasoning_effort=effort, seed=42, auto_output=arm == "reliable")
                    if arm == "control" or args.adaptive_only:
                        options["source_hint_max_size"] = 128
                    benchmark.run_local([target], ["deepseek:deepseek-flash"],
                        rounds=policy.resolve_rounds(row, "auto", "deepseek:deepseek-flash"),
                        session=session, provider_options=options, candidate_dir=folder / session,
                        strategies=("direct",), log=lambda _: None)

                with patch.object(draft, "llm_rounds", controls["draft"].llm_rounds if arm == "control" else fixed):
                    with ThreadPoolExecutor(max_workers=4) as pool:
                        list(pool.map(run, targets))
                jobs = [r for r in metrics.recent_rows() if r.get("session") == session and r.get("event") == "job"]
                print(session, "jobs", len(jobs), "exact", sum(r["score"] == 100 for r in jobs),
                      "compiling", sum(r["compile_ok"] > 0 for r in jobs),
                      "cost", round(sum(r.get("estimated_cost") or 0 for r in jobs), 6), flush=True)
    rows = [r for r in metrics.recent_rows() if r.get("session") in sessions and r.get("event") == "job"]
    folder.mkdir(parents=True, exist_ok=True)
    (folder / "report.json").write_text(json.dumps({"manifest": corpus,
        "manifest_sha256": hashlib.sha256(args.manifest.read_bytes()).hexdigest(),
        "limit": args.max_cloud_cost, "adaptive_only": args.adaptive_only,
        "reserved_cost": budget.cost, "requests": budget.requests,
        "rows": rows}, indent=1), encoding="utf-8")
    print("Total reserved cost:", budget.cost, flush=True)


if __name__ == "__main__":
    main()
