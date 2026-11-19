"""review-queue.json: the files most worth a human look, biggest first.

Reasons a file is queued:
  contested  a real build (exe string, 2007 PDB, iOS) names another file for some of its functions
  weak       most of its code was placed only by weak tiers (K callers, C class rule, O OpenRBX, B stubs, R range)
  split      its native pieces did not merge into one file (merge group with unexported pieces)
Run (after function_map.py and site_paths.py):  python work/native-client/layout/review_queue.py
"""
import collections
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
WEAK = set('KCOBR')


def build():
    fm = json.loads((ROOT / 'docs/function-map.json').read_text(encoding='utf-8'))
    by_file = collections.defaultdict(collections.Counter)
    for _addr, size, index, tier in fm['functions']:
        if index >= 0:
            by_file[fm['files'][index]][tier] += size
    queue = {}

    def add(path, reason, weight, detail):
        row = queue.setdefault(path, {'path': path, 'bytes': sum(by_file.get(path, {}).values()), 'reasons': {}})
        row['reasons'][reason] = detail
        row['score'] = row.get('score', 0) + weight

    for path, alts in fm.get('contested', {}).items():
        n = sum(alts.values())
        add(path, 'contested', n, 'another real build puts %d functions elsewhere: %s' % (n, ', '.join(alts)))
    for path, tiers in by_file.items():
        total = sum(tiers.values())
        weak = sum(v for t, v in tiers.items() if t in WEAK)
        if total >= 2048 and weak / total >= 0.6 and not path.startswith('libraries/'):
            add(path, 'weak', weak // 64, '%d of %d bytes placed only by weak tiers (%s)' % (
                weak, total, ', '.join('%s %d' % kv for kv in tiers.most_common() if kv[0] in WEAK)))
    rows = json.loads((HERE / 'source-layout-map.json').read_text(encoding='utf-8'))
    receipt_path = ROOT / 'rebuild/2008-06/layout/receipt.json'
    if receipt_path.exists():
        done = {s for u in json.loads(receipt_path.read_text(encoding='utf-8'))['merged_units'].values() for s in u['sources']}
        groups = collections.defaultdict(list)
        for key, row in rows.items():
            if row.get('merge_group') and key.endswith('.cpp'):
                groups[row['merge_group']].append(key)
        for group, members in groups.items():
            left = [m for m in members if m not in done]
            if left and len(left) < len(members) + 1 and any(m in done for m in members):
                add(group.removeprefix('rebuild/2008-06/').lower(), 'split', 30 * len(left), '%d of %d pieces did not merge' % (len(left), len(members)))
    return sorted(queue.values(), key=lambda r: (-r['score'], -r['bytes']))


if __name__ == '__main__':
    rows = build()
    (HERE / 'review-queue.json').write_text(json.dumps(rows, indent=1), encoding='utf-8')
    print(len(rows), 'files queued')
    for r in rows[:20]:
        print('%7d B  %-58s %s' % (r['bytes'], r['path'][:58], ', '.join(r['reasons'])))
