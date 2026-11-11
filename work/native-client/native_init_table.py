"""Dynamic-initializer table (.CRT$XCU) as translation-unit order evidence.

Finds the longest run of consecutive relocated pointers to function starts
that contains bound `??__E` dynamic initializers.  Each entry is one
translation unit's static-init function, in link order.  If entry addresses
rise monotonically, link order equals address order and every entry marks a
position inside its translation unit's code range.
"""
import argparse
import json
import struct
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match  # noqa: E402
from roc.native_bulk import Targets  # noqa: E402


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    targets = Targets('2008-06')
    starts = {int(a, 16) for a in match._functions('2008-06')}
    names = defaultdict(list)
    for row in json.loads(args.closure.read_text())['bindings']:
        names[int(row['addr'], 16)].append(row['symbol'])
    inits = {a for a, s in names.items() if any(n.startswith('??__E') for n in s)}
    runs, run = [], []
    for va in targets.sorted_relocs:
        value = struct.unpack('<I', targets.data(va, 4))[0]
        if value in starts and (not run or va == run[-1][0] + 4):
            run.append((va, value))
        else:
            if len(run) > 8:
                runs.append(run)
            run = [(va, value)] if value in starts else []
    if len(run) > 8:
        runs.append(run)
    best = max(runs, key=lambda r: sum(v in inits for _, v in r))
    entries = [{'slot': i, 'table_va': '%08x' % va, 'function': '%08x' % value,
                'symbols': names.get(value, [])} for i, (va, value) in enumerate(best)]
    rising = sum(b[1] > a[1] for a, b in zip(best, best[1:]))
    out = {'scope': 'static-initializer table; translation-unit order evidence',
           'summary': {'entries': len(best), 'named_initializers': sum(v in inits for _, v in best),
                       'adjacent_pairs_rising_address': rising, 'adjacent_pairs': len(best) - 1,
                       'table_va': '%08x' % best[0][0]},
           'entries': entries}
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(out['summary']))
    print([(e['function'], (e['symbols'] or [''])[0][:50]) for e in entries[:8]])


if __name__ == '__main__':
    main()
