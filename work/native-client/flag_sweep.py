"""Flag sweep on near-miss drafts (no model calls): every placeholder-lane 'draft' among the remaining functions is
re-judged with its saved answer under nearby compiler flag sets (inlining, frame pointer, fp model, size).  A draft
that turns byte-exact under a variant is recorded with that variant in results.json ('flags'), so the promoter writes
its Inferred_<addr>.cpp with those native-flags (per-function TU).  Owner rule: flag search only after source tries.
  python work/native-client/flag_sweep.py [--jobs 8]"""
import argparse
import json
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
BASE = '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL'
VARIANTS = [BASE.replace('/Ob2', '/Ob1'), BASE + ' /Oy-', BASE + ' /fp:fast', BASE.replace('/O2', '/O1'),
            BASE.replace('/GS-', '/GS'), BASE.replace('/Ob2', '/Ob1') + ' /Oy-', BASE + ' /Os', BASE.replace('/Ob2', '/Ob0')]

WORKER = r'''
import json, os, re, sys
from pathlib import Path
sys.path.insert(0, %(here)r); sys.argv = ['x', '--limit', '0']
src = open(%(lane)r, encoding='utf-8').read(); src = src[:src.index('if args.regate:')]
ns = {'__name__': 'sweep'}; exec(compile(src, %(lane)r, 'exec'), ns)
addr, variant = sys.argv[1], sys.argv[2]
out = ns['OUT'] / addr
answer = sorted(out.glob('try*.cpp'))[-1].read_text(errors='replace')
body = re.findall(r'```(?:cpp|c\+\+)\s*\n(.*?)```', answer, re.S)[-1]
work = Path(%(scratch)r) / addr
st, det, c, d = ns['judge'](work, addr, answer, body)                  # baseline: builds the probe + include list
probe = (work / 'probe.cpp')
incl = ' '.join(t for t in re.search(r'native-flags:(.*)', probe.read_text()).group(1).split() if t.startswith('/I')) if probe.is_file() else ''
os.environ['NATIVE_FLAGS'] = variant + ' ' + incl
st, det, c, d = ns['judge'](work, addr, answer, body)
print(json.dumps({'addr': addr, 'variant': variant, 'status': st, 'cls': c, 'decl': d}))
'''


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--jobs', type=int, default=8)
    args = ap.parse_args()
    results = json.loads((HERE / 'placeholder-lane/results.json').read_text())
    cl = json.loads((HERE / 'remaining-classified.json').read_text())
    drafts = sorted([a for a, v in results.items() if v.get('status') == 'draft' and a in cl], key=lambda a: cl[a]['size'])
    print('drafts to sweep: %d x %d flag sets' % (len(drafts), len(VARIANTS)), flush=True)
    script = WORKER % {'here': str(HERE), 'lane': str(HERE / 'native_placeholder_llm.py'),
                       'scratch': str(HERE / 'flag-sweep')}
    (HERE / 'flag-sweep').mkdir(exist_ok=True)
    (HERE / 'flag-sweep' / 'worker.py').write_text(script)

    def sweep(addr):
        for variant in VARIANTS:
            run = subprocess.run([sys.executable, str(HERE / 'flag-sweep' / 'worker.py'), addr, variant], cwd=HERE,
                                 capture_output=True, text=True, timeout=900)
            line = (run.stdout.strip().splitlines() or ['{}'])[-1]
            try:
                row = json.loads(line)
            except ValueError:
                continue
            if row.get('status') == 'inactive_exact':
                return addr, variant, row
        return addr, None, None

    found = 0
    with ThreadPoolExecutor(args.jobs) as pool:
        for addr, variant, row in pool.map(sweep, drafts):
            if variant:
                found += 1
                hits_path = HERE / 'flag-sweep-hits.json'          # merged by `lane_runner.py promote` (no results.json race)
                hits = json.loads(hits_path.read_text()) if hits_path.is_file() else {}
                hits[addr] = dict(flags=variant, cls=row.get('cls') or '', decl=row.get('decl') or '')
                hits_path.write_text(json.dumps(hits, indent=1))
                print('  %s exact with %s' % (addr, variant), flush=True)
    print('RESULT flag sweep: %d of %d drafts exact' % (found, len(drafts)), flush=True)


if __name__ == '__main__':
    main()
