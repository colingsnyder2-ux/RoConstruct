"""Compare real cold target-index loads with and without single-load locking."""
import argparse
import sys
import threading
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import match


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--client", default="2007-08")
    parser.add_argument("--workers", type=int, default=8)
    args = parser.parse_args()
    path = match.ROOT / "work" / args.client / "functions.jsonl"
    original = Path.open
    for locked in (False, True):
        match._functions.cache_clear()
        reads = []
        barrier = threading.Barrier(args.workers)

        def counted(file, *values, **options):
            if file == path:
                reads.append(file)
            return original(file, *values, **options)

        def load(_):
            barrier.wait()
            return (match._functions if locked else match._functions.__wrapped__)(args.client)

        started = time.perf_counter()
        with patch.object(Path, "open", counted), ThreadPoolExecutor(max_workers=args.workers) as pool:
            results = list(pool.map(load, range(args.workers)))
        print("single_load=%s reads=%d rows=%d seconds=%.3f same_object=%s" %
              (locked, len(reads), len(results[0]), time.perf_counter() - started,
               all(row is results[0] for row in results)), flush=True)
        if locked:
            assert len(reads) == 1 and all(row is results[0] for row in results)
        del results


if __name__ == "__main__":
    main()
