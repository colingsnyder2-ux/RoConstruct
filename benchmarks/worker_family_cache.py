"""Replay cold/warm family retrieval with real compilers and a local API fixture.

Isolates the family stage: automatic/reference candidates and LLM output are
disabled. No network requests, provider spending, or live submissions.
"""
import argparse
import hashlib
import importlib.util
import json
import sys
from contextlib import ExitStack
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import match, metrics, worker


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("manifest", type=Path)
    parser.add_argument("--control-worker", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    corpus = json.loads(args.manifest.read_text())
    spec = importlib.util.spec_from_file_location("roc._family_control", args.control_worker)
    control = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(control)
    results = []
    for arm, module in (("control", control), ("fixed", worker)):
        for family in corpus:
            if hashlib.sha256(family["source"].encode()).hexdigest() != family["source_sha256"]:
                raise SystemExit("Donor source changed")
            assert match.check_text(family["client"], family["donor"], family["source"])[0] == 100
            cache, calls, generated = {}, [], []

            class Api:
                server, token = "http://localhost:8765", None

                def call(self, path, data=None):
                    calls.append(path)
                    if path.startswith("/v1/examples"):
                        return [{"addr": family["donor"], "source": family["source"]}]
                    if path == "/v1/submit":
                        # Independently compile the proposed source before accepting it.
                        match.compile_text.cache_clear()
                        score = match.check_text(data["client"], data["addr"], data["source"])[0]
                        assert score == data["score"]
                        folder = args.output / arm / data["client"]
                        folder.mkdir(parents=True, exist_ok=True)
                        (folder / (data["addr"] + ".cpp")).write_text(data["source"], encoding="utf-8")
                        return {"stored": score}
                    return {}

            def llm(*values, **options):
                generated.append(values[1])
                return 0, None

            with ExitStack() as stack:
                stack.enter_context(patch("roc.auto.candidates", return_value=[]))
                stack.enter_context(patch("roc.abi_graph.target_evidence", return_value={}))
                stack.enter_context(patch.object(module, "callee_source_hints", return_value=[]))
                stack.enter_context(patch.object(metrics, "quarantined_keys", return_value=set()))
                stack.enter_context(patch("roc.refsource.prompt_hints", return_value=[]))
                stack.enter_context(patch.object(module.draft, "llm_rounds", side_effect=llm))
                for index, target in enumerate(family["targets"]):
                    job = {**target, "score": 0, "source": None, "lease": "local-fixture"}
                    before = len(generated)
                    score = module.work_one(Api(), "benchmark", job, {"clients": {job["client"]: {}}},
                        "deepseek:deepseek-flash", 2, False, lambda _: None,
                        examples_cache=cache, provider_options={"family_exemplars": True, "near_repair": True})
                    results.append({"arm": arm, "client": job["client"], "addr": job["addr"],
                                    "family": family["family"], "warm": index > 0,
                                    "score": score, "model_calls": len(generated) - before})
                    print(arm, job["addr"], score, "model calls", len(generated) - before, flush=True)
            assert sum(path.startswith("/v1/examples") for path in calls) == 1
    args.output.mkdir(parents=True, exist_ok=True)
    (args.output / "report.json").write_text(json.dumps({
        "manifest": corpus, "control_sha256": hashlib.sha256(args.control_worker.read_bytes()).hexdigest(),
        "rows": results}, indent=1), encoding="utf-8")
    for arm in ("control", "fixed"):
        rows = [row for row in results if row["arm"] == arm]
        print(arm, "exact", sum(row["score"] == 100 for row in rows), "/", len(rows),
              "model calls", sum(row["model_calls"] for row in rows), flush=True)


if __name__ == "__main__":
    main()
