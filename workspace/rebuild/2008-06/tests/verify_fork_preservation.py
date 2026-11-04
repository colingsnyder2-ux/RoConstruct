"""Check an exact integration tree before committing or pushing; never modifies Git."""
import argparse
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc.fork_merge import preservation_losses

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('base')
parser.add_argument('candidate')
parser.add_argument('--output', type=Path)
args = parser.parse_args()
losses = preservation_losses(ROOT, args.base, args.candidate)
receipt = {'base': args.base, 'candidate': args.candidate, 'losses': losses,
           'passed': not losses,
           'scope': 'Native/proof file preservation only; compile, matching, dependency and runtime gates are separate.'}
if args.output:
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
print(json.dumps(receipt, indent=2))
raise SystemExit(bool(losses))
