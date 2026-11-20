"""Delta-debug native-Doc provider candidates with cached isolated relinks.

Tests all candidates, binary halves, then every survivor combination. Lower
unique-unresolved is better. A missing closure is recorded as a compile failure.
"""
import itertools
import json
import os
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).parent
ROOT = HERE.parents[2]
OUT = HERE.parent / 'out' / 'p6-bisect'
sources = [Path(value).resolve() for value in sys.argv[1:]]
if len(sources) < 2:
    raise SystemExit('need two or more C++ sources')
if any(not source.is_file() for source in sources):
    raise SystemExit('missing candidate source')

OUT.mkdir(parents=True, exist_ok=True)
seen, results = {}, []
def probe(group):
    names = tuple(str(source) for source in group)
    if names in seen:
        return seen[names]
    label = 'base' if not group else '-'.join(source.stem for source in group)
    label = re.sub(r'[^A-Za-z0-9_.-]+', '_', label)[:120]
    out = OUT / ('%02d-%s' % (len(results), label))
    out.mkdir(parents=True, exist_ok=True)
    env = os.environ.copy()
    env['ROC_NATIVE_DOC_EXTRA'] = ';'.join(names)
    run = subprocess.run([sys.executable, str(HERE / 'build_client.py'), '--native-doc',
                          '--native-doc-cache', '--native-doc-out', str(out)],
                         cwd=ROOT, env=env, text=True, stdout=subprocess.PIPE,
                         stderr=subprocess.STDOUT)
    closure = out / 'native-doc-closure.json'
    data = json.loads(closure.read_text()) if closure.exists() else {}
    result = {'sources': names, 'exit': run.returncode,
              'unresolved': data.get('unique_unresolved'), 'out': str(out)}
    if not closure.exists():
        result['failure_tail'] = run.stdout[-1600:]
    (out / 'bisect.log').write_text(run.stdout)
    seen[names] = result
    results.append(result)
    print('%s -> %s' % (label, result['unresolved']))
    return result

base = probe([])
probe(sources)
def halves(group):
    if len(group) < 2:
        return
    cut = len(group) // 2
    left, right = group[:cut], group[cut:]
    probe(left); probe(right)
    halves(left); halves(right)
halves(sources)
for size in range(2, len(sources)):
    for group in itertools.combinations(sources, size):
        probe(group)

def score(result):
    return result['unresolved'] if isinstance(result['unresolved'], int) else 10**9
results.sort(key=score)
(OUT / 'results.json').write_text(json.dumps({'baseline': base, 'results': results}, indent=2) + '\n')
print('best:', results[0])
