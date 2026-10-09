"""Compare full-history and cached-tail telemetry reads on the local log."""
import json
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import metrics


if __name__ == "__main__":
    started = time.perf_counter()
    old, invalid = [], 0
    for line in metrics.PATH.read_text(encoding="utf-8").splitlines()[-5000:]:
        try:
            row = json.loads(line)
        except ValueError:
            invalid += 1
            continue
        if isinstance(row, dict):
            old.append(row)
    legacy = time.perf_counter() - started
    metrics._RECENT["key"] = None
    started = time.perf_counter()
    recent = metrics.recent_rows()
    cold = time.perf_counter() - started
    started = time.perf_counter()
    for _ in range(100):
        metrics.recent_rows()
    cached = (time.perf_counter() - started) / 100
    print(json.dumps(dict(file_mb=round(metrics.PATH.stat().st_size / 1e6, 2),
                          rows=len(recent), invalid_rows=invalid, same_rows=old == recent,
                          legacy_seconds=round(legacy, 4), tail_seconds=round(cold, 4),
                          cached_seconds=round(cached, 6))))
