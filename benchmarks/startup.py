"""Measure duplicate source-index loads versus one-time worker warmup."""
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import refsource

read_text = Path.read_text
for prewarm in (False, True):
    refsource._INDEX = None
    reads = []

    def counted(path, *args, **kwargs):
        if path == refsource.CACHE:
            reads.append(path)
        return read_text(path, *args, **kwargs)

    started = time.perf_counter()
    with patch.object(Path, "read_text", counted):
        if prewarm:
            refsource.build_index(log=lambda _: None)
        with ThreadPoolExecutor(max_workers=8) as pool:
            list(pool.map(lambda _: refsource.build_index(log=lambda _: None), range(8)))
    print("prewarm=%s cache_reads=%d seconds=%.3f" %
          (prewarm, len(reads), time.perf_counter() - started), flush=True)
