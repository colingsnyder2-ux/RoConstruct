"""Native permuter (no model).  roc/mutate.py holds dozens of validated source mutations with a keep-the-best loop
(built for the mining near-misses).  This lane points it at the NATIVE near-miss drafts: for each draft with a
compiling probe (placeholder-lane/<addr>/probe.cpp), mutate the probe text, compile it with the native toolchain,
score the object against the original with roc.match.check_text, and keep improvements.  A variant that scores 100 is
confirmed through the native gate (bytes + identity + references) before it is recorded as inactive_exact; the
passing probe is left in place for the promoter.
  python work/native-client/native_permute.py [--jobs 6] [--limit N] [--only FILE.json]"""
import argparse
import collections
import hashlib
import json
import re
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ap = argparse.ArgumentParser()
ap.add_argument('--jobs', type=int, default=6)
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--only', default='')
args, _ = ap.parse_known_args()
sys.argv = [sys.argv[0], '--limit', '0']
sys.path.insert(0, str(HERE))
src = (HERE / 'native_placeholder_llm.py').read_text(encoding='utf-8')
lane = {'__name__': 'permute', '__file__': str(HERE / 'native_placeholder_llm.py')}
exec(compile(src[:src.index('if args.polish:')], str(HERE / 'native_placeholder_llm.py'), 'exec'), lane)
m, cg, LANE, results_store = lane['m'], lane['cg'], lane['OUT'], lane['results_store']
from roc import match, mutate, native_bulk, rebuild  # noqa: E402

ROOT = m.ROOT
WORK = HERE / 'permute'
RUNNER = native_bulk.checker()
TC = rebuild.toolchain(21022)
HDR = str(ROOT / 'rebuild/2008-06/native-headers')


def number(p):
    return int(re.sub(r'\D', '', p.stem) or 0)


def make_check(addr, flags_line):
    def check(client, address, text, flags=None, include_diagnosis=False):
        key = hashlib.sha1(text.encode('utf-8', 'replace')).hexdigest()[:16]
        base = WORK / addr / key
        base.mkdir(parents=True, exist_ok=True)
        source = base / 'probe.cpp'
        folder = base / 'job'                                # compile_job creates this folder itself
        obj = folder / 'candidate.obj'
        if not obj.is_file():
            if folder.is_dir():
                raise match.CompileError('native compile failed earlier')
            source.write_text(flags_line + '\n' + text)
            job = RUNNER.compile_job({'source': str(source), 'checks': [], 'ranges': [], 'layouts': []}, folder, TC)
            obj = Path(job.get('object') or obj)
        if not obj.is_file():
            raise match.CompileError('native compile failed')
        return match.check_text(client, address, text, flags, include_diagnosis=include_diagnosis, obj=obj.read_bytes())
    return check


def one(addr):
    probe = LANE / addr / 'probe.cpp'
    text = probe.read_text(errors='replace')
    first, rest = text.split('\n', 1)
    if not first.startswith('// native-flags:'):
        return addr, 'skip', 0, 0
    check = make_check(addr, first)
    try:
        base = check('2008-06', addr, rest)[0]
    except Exception:                                            # noqa: BLE001
        return addr, 'probe-no-compile', 0, 0
    if not base:
        return addr, 'probe-no-score', 0, 0
    try:
        result = mutate.improve('2008-06', addr, rest, flags=None, check=check, guided=True, permute=True)
    except Exception as error:                                   # noqa: BLE001
        return addr, 'error ' + repr(error)[:60], base, base
    score, best, tried = result[0], result[1], result[2]
    if score < 100:
        if score > base:                                         # keep the closer variant for the next round / an agent
            (LANE / addr / 'permuted-best.cpp').write_text(first + '\n' + best)
        return addr, 'improved' if score > base else 'no-gain', base, score
    # Confirm with the native gate (identity + references), using the same include roots as the probe.
    include_first = []
    for tok in first[len('// native-flags:'):].split():
        if tok.startswith('/I'):
            if tok[2:].lower() == HDR.lower():
                break
            include_first.append(tok[2:])
    symbol = check('2008-06', addr, best)[1]
    any_header = str(Path(HDR) / 'util/Name.h')
    status, detail = cg.gate_code(LANE / addr, [any_header], best, {addr: symbol}, include_first=include_first, raw_includes=[])
    st = status.get(addr, 'missing')
    if st == 'inactive_exact':
        tries = sorted((LANE / addr).glob('try*.cpp'), key=number)
        n = (number(tries[-1]) + 1) if tries else 0
        body = re.sub(r'^\s*#\s*include[^\n]*\n', '', best, flags=re.M).strip()
        (LANE / addr / ('try%d.cpp' % n)).write_text('```cpp\n%s\n```' % body)
        (LANE / addr / ('err%d.txt' % n)).write_text('inactive_exact\nnative permuter: %d variants tried' % tried)
        row = dict(results_store.load().get(addr) or {})
        row.update(status='inactive_exact', detail='', model='permuter')
        results_store.save({addr: row})
        lane['record'](addr, len(match.target('2008-06', addr)[0]), 'inactive_exact', 'permuter', row.get('class') or '', row.get('decl') or '')
        return addr, 'inactive_exact', base, 100
    return addr, 'bytes-100-gate-' + st, base, 100


r = results_store.load()
cl = json.loads((HERE / 'remaining-classified.json').read_text())
todo = []
for addr, v in r.items():
    if v.get('status') != 'draft' or addr not in cl:
        continue
    d = LANE / addr
    errs = sorted(d.glob('err*.txt'), key=number)
    if errs and errs[-1].read_text(errors='replace').startswith('draft') and (d / 'probe.cpp').is_file():
        todo.append((cl[addr]['size'], addr))
todo = [a for _, a in sorted(todo)]
if args.only:
    only = set(json.loads(Path(args.only).read_text()))
    todo = [a for a in todo if a in only]
todo = todo[:args.limit or None]
print('drafts to permute: %d' % len(todo), flush=True)
counts = collections.Counter()
with ThreadPoolExecutor(args.jobs) as pool:
    for addr, status, base, score in pool.map(one, todo):
        counts[status.split(' ')[0]] += 1
        print(addr, status, '%s -> %s' % (base, score), flush=True)
print('RESULT native permuter: %s' % dict(counts), flush=True)
