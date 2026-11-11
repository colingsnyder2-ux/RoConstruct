"""Totals for applied template promotions (reads claude-template-applied/*/applied*.json)."""
import glob, json
from collections import Counter
from pathlib import Path
HERE = Path(__file__).resolve().parent
c, addrs, lines, why = Counter(), set(), 0, Counter()
for p in glob.glob(str(HERE / 'claude-template-applied/*/applied*.json')):
    d = json.load(open(p)); c[d['applied']] += 1
    if d['applied']:
        addrs |= set(d['addresses']); lines += d['lines']
    else:
        why[d.get('reason')] += 1
reports = sorted(glob.glob(str(HERE / 'codex-native-recovery-report-v*.json')), key=lambda p: int(p.split('-v')[-1][:-5]))
known = set(json.load(open(reports[-1]))['byte_proved']['symbols'])
print(json.dumps({'sources_applied': c[True], 'sources_not_applied': c[False], 'reasons': dict(why), 'lines': lines,
                  'distinct_exact_addresses': len(addrs), 'not_in_codex_byte_proved': len(addrs - known),
                  'gate_done': len(glob.glob(str(HERE / 'claude-template-promote/*/promotion.json')))}))
