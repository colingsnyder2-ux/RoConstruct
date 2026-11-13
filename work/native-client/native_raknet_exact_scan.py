"""Read-only: find fieldless queued symbols exactly emitted by cached real RakNet objects."""
import argparse
import json
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
import sys
sys.path.insert(0, str(ROOT))
from roc import match


def exact(address, body, relocs):
    try:
        target, original, _ = match.target('2008-06', address)
    except (KeyError, ValueError, SystemExit):
        return False
    return (len(target) == len(body) and set(original) <= set(relocs)
            and match.exact_match(target, original, body, relocs))


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--queue', type=Path, required=True)
    ap.add_argument('--objects', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    queue = json.loads(args.queue.read_text())['rows']
    objects = args.objects.resolve()
    wanted = {row['symbol']: row for row in queue
              if len(row['headers']) == 1 and not row['native_definition_sources']}
    matches = []
    for path in sorted(objects.glob('*/candidate.obj')):
        unit = path.parent.name
        if unit.startswith('roc_'):
            continue
        sources = sorted(ROOT.glob('tools/rbxgs/**/' + unit + '.cpp'))
        source = str(sources[0].relative_to(ROOT)).replace('\\', '/') if len(sources) == 1 else None
        for symbol, body, relocs in match.coff_functions(path.read_bytes()):
            row = wanted.get(symbol)
            if row and exact(row['address'], body, relocs):
                matches.append({'address': row['address'], 'symbol': symbol, 'owner': row['owner'],
                                'size': row['size'], 'header': row['headers'][0],
                                'destination': 'rebuild/2008-06/native-classes/' + row['owner'].rsplit('::', 1)[-1] + '.cpp',
                                'source': source, 'object': str(path.relative_to(ROOT)).replace('\\', '/')})
    groups = defaultdict(list)
    for row in matches:
        groups[(row['source'], row['header'], row['destination'])].append(row)
    rows = sorted(matches, key=lambda row: (row['source'] or '', row['header'], row['size'], row['address']))
    out = {'scope': 'direct cached-object byte proof; no native source/header edited',
           'summary': {'exact_candidates': len(rows), 'families': len(groups),
                       'objects_scanned': len(list(objects.glob('*/candidate.obj')))},
           'families': [{'source': key[0], 'header': key[1], 'destination': key[2],
                         'methods': sorted(value, key=lambda row: (row['size'], row['address']))}
                        for key, value in sorted(groups.items())], 'candidates': rows}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(out['summary']))


if __name__ == '__main__':
    main()
