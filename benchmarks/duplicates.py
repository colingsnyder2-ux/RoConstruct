"""Check whether stopping repeated candidates would have lost historical matches."""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import metrics

cases = lost_matches = saved_tokens = 0
for line in metrics.PATH.read_text(encoding="utf-8").splitlines():
    row = json.loads(line)
    rounds = [r for r in row.get("rounds", []) if isinstance(r.get("round"), int)]
    for i in range(1, len(rounds) - 1):
        if rounds[i].get("duplicate") and rounds[i - 1].get("duplicate"):
            cases += 1
            later = rounds[i + 1:]
            lost_matches += any(r.get("score") == 100 for r in later)
            saved_tokens += sum((r.get("input_tokens") or 0) + (r.get("output_tokens") or 0)
                                for r in later)
            break
print("two repeated candidates: cases=%d later_exact=%d avoidable_tokens=%d" %
      (cases, lost_matches, saved_tokens))
