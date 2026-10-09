"""Run bounded real worker jobs and save isolated profiling telemetry."""
import argparse
import json
import sys
import threading
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import metrics, providers, worker


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--jobs", type=int, default=16)
    parser.add_argument("--workers", default="auto")
    parser.add_argument("--order", default="auto", choices=("auto", "random", "unmatched", "best"))
    parser.add_argument("--max-size", type=int, default=512)
    parser.add_argument("--session", default="live-worker-" + time.strftime("%Y%m%d-%H%M%S"))
    parser.add_argument("--max-cloud-cost", type=float, default=2)
    args = parser.parse_args()
    settings = worker.load_settings()
    if not settings.get("cloud_allowed"):
        raise SystemExit("Cloud consent missing; use roc setup first.")
    model = "deepseek:deepseek-flash"
    if not providers.available(model) or not providers.has_pricing(model):
        raise SystemExit("DeepSeek key and pricing required.")
    api = worker.Api(settings["server"], settings.get("token"))
    api.call("/v1/info", timeout=5)
    folder = worker.ROOT / "work" / "worker-review"
    folder.mkdir(parents=True, exist_ok=True)
    rows, requests, lock = [], {}, threading.Lock()
    original_record, original_call = metrics.record, worker.Api.call

    def record(session, **fields):
        row = original_record(session, experiment=args.session, **fields)
        with lock:
            rows.append(row)
        return row

    def call(api, path, *values, **fields):
        started = time.monotonic()
        try:
            return original_call(api, path, *values, **fields)
        finally:
            with lock:
                name = path.split("?", 1)[0]
                count, elapsed = requests.get(name, (0, 0))
                requests[name] = count + 1, elapsed + time.monotonic() - started

    metrics.record, worker.Api.call = record, call
    started = time.monotonic()
    with (folder / (args.session + ".log")).open("w", encoding="utf-8") as logfile:
        def log(message):
            with lock:
                logfile.write(str(message) + "\n")
                logfile.flush()
                worker.pretty_log(message)

        try:
            worker.run_concurrent(settings["server"], settings["user"], settings.get("token"),
                                  model=model, rounds="auto", max_tokens="auto", max_size=args.max_size,
                                  workers=args.workers, max_jobs=args.jobs, use_revng=False, order=args.order,
                                  cloud_allowed=True, cloud_budget=providers.CloudBudget(100, 1000000, args.max_cloud_cost),
                                  thinking="auto", reasoning_effort="auto", verbosity="compact", log=log)
        finally:
            metrics.record, worker.Api.call = original_record, original_call
            jobs = [row for row in rows if row.get("event") == "job"]
            summary = dict(experiment=args.session, jobs=len(jobs),
                           exact=sum(row.get("score") == 100 for row in jobs),
                           improved=sum(bool(row.get("improved")) for row in jobs),
                           failures=sum(bool(row.get("failure")) for row in jobs),
                           tokens=sum((row.get("input_tokens") or 0) + (row.get("output_tokens") or 0) for row in jobs),
                           seconds=round(time.monotonic() - started, 3), requests=requests)
            (folder / (args.session + ".json")).write_text(json.dumps(dict(summary=summary, rows=rows), indent=2), encoding="utf-8")
            print(json.dumps(summary), flush=True)


if __name__ == "__main__":
    main()
