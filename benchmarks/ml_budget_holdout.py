"""Freeze the medium/large re-attempt manifest for the output-budget benchmark.

Targets: the 67 medium/large rows of holdout-fresh-100-20261008.json (all
previously attempted, 0 exact / 0 compilable under the 1024-token budget).
Stratified sample of 40: 20 medium + 20 large, deterministic hash order.
Every arm of the budget benchmark uses this identical target list.
"""
import hashlib
import json
from pathlib import Path

SRC = Path("benchmarks/holdout-fresh-100-20261008.json")
OUT = Path("benchmarks/holdout-ml-budget-40-20261008.json")

rows = json.loads(SRC.read_text(encoding="utf-8"))
ml = [r for r in rows if r["bucket"] in ("medium", "large")]
ml.sort(key=lambda r: hashlib.sha256((r["client"] + r["addr"]).encode()).hexdigest())
picked = []
for bucket in ("medium", "large"):
    picked.extend([r for r in ml if r["bucket"] == bucket][:20])
picked.sort(key=lambda r: (r["bucket"], r["client"], r["addr"]))
for row in picked:
    row["prior_attempt"] = "holdout-fresh-100: 0 exact, 0 compilable (max_tokens=1024)"
OUT.write_text(json.dumps(picked, indent=1), encoding="utf-8")
print(OUT, len(picked),
      {b: sum(1 for r in picked if r["bucket"] == b) for b in ("medium", "large")})
