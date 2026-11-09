"""List original field-access candidates near known callees; never infer receiver types.

Uses existing native-asm decoder and original call metadata. Direct callers only;
inline-only and indirect callers remain outside coverage. No compile or execution.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, native_asm

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--client', default='2008-06')
parser.add_argument('--anchor', action='append', default=[], help='Original function address')
parser.add_argument('--range', action='append', default=[], help='LO-HI original function range')
parser.add_argument('--offset', required=True, type=lambda x: int(x, 0))
parser.add_argument('--width', choices=['byte', 'word', 'dword', 'qword'], default='byte')
parser.add_argument('--output', required=True, type=Path)
args = parser.parse_args()
functions = match._functions(args.client)
anchors = {f'{int(a, 16):08x}' for a in args.anchor}
for interval in args.range:
    lo, hi = (int(a, 16) for a in interval.split('-'))
    anchors.update(a for a in functions if lo <= int(a, 16) < hi)
assert anchors and anchors <= functions.keys(), 'Missing/unknown anchor'
operand = re.compile(r'\b' + args.width + r' ptr \[(?!esp\b)[a-z]+ \+ '
                     + re.escape(hex(args.offset) if args.offset >= 10 else str(args.offset)) + r'\]')
rows = []
scanned = 0
for address, info in functions.items():
    calls = set(info.get('call_targets', [])) & anchors
    if not calls:
        continue
    scanned += 1
    code, _, _ = match.target(args.client, address)
    listing = native_asm.lines(code, int(address, 16))
    hits = [i for i, row in enumerate(listing) if operand.search(row[1])]
    if hits:
        rows.append({'function': address, 'original_code_sha256': hashlib.sha256(code).hexdigest(),
                     'anchor_calls': sorted(calls), 'hits': [
                         {'address': hex(listing[i][0]), 'instruction': listing[i][1],
                          'context': [{'address': hex(a), 'instruction': text}
                                      for a, text, *_ in listing[max(0, i-5):i+6]]}
                         for i in hits]})
receipt = {'scope': __doc__, 'receiver_type_proven': False,
           'tool_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
           'client': args.client, 'anchors': sorted(anchors), 'offset': args.offset,
           'width': args.width, 'callers_scanned': scanned, 'candidates': rows}
args.output.parent.mkdir(parents=True, exist_ok=True)
args.output.write_text(json.dumps(receipt, indent=2) + '\n')
print(f'{scanned} callers scanned; {len(rows)} candidate functions; {args.output}')
