"""Owner candidates for unnamed functions from address runs (TU contiguity).

MSVC keeps a translation unit's non-COMDAT functions together.  An unnamed
function whose nearest named neighbours on both sides are non-template members
of the same class is probably that class's member or a file-local helper of
its .cpp.  Output is a candidate list for compile probes, never an owner proof.
"""
import argparse
import json
import sys
from bisect import bisect_left
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match  # noqa: E402
from native_conversion_queue import owner  # noqa: E402


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--span', type=int, default=3, help='named neighbours required to agree on each side')
    args = ap.parse_args()
    functions = match._functions('2008-06')
    order = sorted(a for a, v in functions.items() if v.get('kind', 'code') == 'code')
    owners = {}
    for row in json.loads(args.closure.read_text())['bindings']:
        scope = owner(row['symbol'])
        # Template members and inline COMDATs are placed by first use, not by owner file.
        if row['function_start'] and scope and '<' not in scope and '<' not in row['symbol'].split('@')[0]:
            owners.setdefault(row['addr'], set()).add(scope)
    named = [a for a in order if len(owners.get(a, ())) == 1]
    rows = []
    for addr in order:
        if addr in owners:
            continue
        i = bisect_left(named, addr)
        before, after = named[max(0, i - args.span):i], named[i:i + args.span]
        if len(before) < args.span or len(after) < args.span:
            continue
        scopes = {next(iter(owners[a])) for a in before + after}
        if len(scopes) == 1:
            rows.append({'addr': addr, 'size': functions[addr]['size'], 'owner_candidate': scopes.pop(),
                         'previous_named': before[-1], 'next_named': after[0],
                         'gap_functions': order.index(after[0]) - order.index(before[-1]) - 1})
    by = Counter(r['owner_candidate'] for r in rows)
    args.output.write_text(json.dumps({'scope': 'address-run owner candidates; not proof',
                                       'summary': {'unnamed_functions': len(order) - len(owners),
                                                   'with_candidate': len(rows), 'owners': len(by)},
                                       'top_owners': by.most_common(40), 'rows': rows}, indent=1) + '\n')
    print(json.dumps({'unnamed': len(order) - len(owners), 'with_candidate': len(rows), 'owners': len(by)}))
    print(by.most_common(15))


if __name__ == '__main__':
    main()
