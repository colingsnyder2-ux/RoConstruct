#!/usr/bin/env python3
"""Deterministically shard independent native-bulk source families."""
import argparse
import concurrent.futures
import json
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('config', type=Path)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--shards', type=int, default=4)
    ap.add_argument('--run', action='store_true')
    args = ap.parse_args()
    if args.shards < 1:
        raise SystemExit('--shards must be positive')
    source = json.loads(args.config.read_text())
    units = []
    for family in source['families']:
        for path in family['sources']:
            unit = dict(family)
            unit['name'] = family['name'] + '-' + Path(path).stem
            unit['sources'] = [path]
            units.append(unit)
    if not units:
        raise SystemExit('config has no sources')
    buckets = [[] for _ in range(min(args.shards, len(units)))]
    for index, unit in enumerate(sorted(units, key=lambda x: x['sources'][0])):
        buckets[index % len(buckets)].append(unit)
    out = args.out.resolve()
    configs = out / 'configs'
    configs.mkdir(parents=True, exist_ok=True)
    paths = []
    for index, families in enumerate(buckets):
        shard = {key: value for key, value in source.items() if key not in ('families', 'metadata')}
        shard['families'] = families
        shard['metadata'] = {'parent': str(args.config), 'shard': index, 'source_count': len(families)}
        path = configs / ('shard-%03d.json' % index)
        path.write_text(json.dumps(shard, indent=2) + '\n')
        paths.append(path)
    print('sources=%d shards=%d' % (len(units), len(paths)))
    if not args.run:
        return
    def execute(path):
        index = path.stem.rsplit('-', 1)[1]
        command = [str(ROOT / 'roc.cmd'), 'native-bulk', str(path), '--out',
                   str(out / 'runs' / ('shard-' + index))]
        return subprocess.run(command, cwd=ROOT, text=True, capture_output=True)
    with concurrent.futures.ThreadPoolExecutor(max_workers=len(paths)) as pool:
        results = list(pool.map(execute, paths))
    failed = [result for result in results if result.returncode]
    for result in results:
        print(result.stdout, end='')
        print(result.stderr, end='')
    if failed:
        raise SystemExit('%d native-bulk shard(s) failed' % len(failed))


if __name__ == '__main__':
    main()
