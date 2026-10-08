"""Measure remote-request throughput using a fixed non-source prompt."""
import sys
import argparse
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import providers

parser = argparse.ArgumentParser()
parser.add_argument("--requests", type=int, default=8)
parser.add_argument("--limits", nargs="+", type=int, default=[1, 8])
parser.add_argument("--prompt-repeat", type=int, default=1,
                    help="repeat fixed context text to measure cache hits")
args = parser.parse_args()
prompt = "Reply only: ok\n" + "Fixed cache probe context.\n" * max(1, args.prompt_repeat)
for repeat, limits in enumerate((args.limits, list(reversed(args.limits))), 1):
    for limit in limits:
        gate = providers.CloudGate(limit)
        started = time.perf_counter()

        def request(_):
            return providers.generate("deepseek:deepseek-flash", prompt,
                                      options={"allow_cloud": True, "thinking": "disabled",
                                               "max_tokens": 8, "gate": gate})

        with ThreadPoolExecutor(max_workers=args.requests) as pool:
            results = list(pool.map(request, range(args.requests)))
        ok = sum(row.text.strip().lower() == "ok" for row in results)
        print("repeat=%d concurrency=%d correct=%d/%d tokens=%d cached=%d seconds=%.3f" % (
              repeat, limit, ok, args.requests, sum(row.input_tokens + row.output_tokens for row in results),
              sum(row.cached_tokens for row in results),
              time.perf_counter() - started), flush=True)
