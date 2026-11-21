"""No-model regate of 'wrong-signature' answers.  The lane rejects an answer whose compiled symbol differs from the
registry name without comparing bytes; many registry names in the remaining pool are inferred and wrong (shared names
on identical bodies, shifted template arguments).  This re-judges the saved answer with the symbol it actually
compiled to: byte-exact ones are kept as inactive_exact under that (INFERRED) name.
  python work/native-client/wrongsig_regate.py [--jobs 6]"""
import argparse
import collections
import json
import re
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ap = argparse.ArgumentParser()
ap.add_argument('--jobs', type=int, default=6)
args, _ = ap.parse_known_args()
if (HERE / 'prove-out/CENSUS.lock').is_file():
    sys.exit('a census is running: try again when it finishes')
sys.argv = [sys.argv[0], '--limit', '0']
sys.path.insert(0, str(HERE))
src = (HERE / 'native_placeholder_llm.py').read_text(encoding='utf-8')
lane = {'__name__': 'wrongsig', '__file__': str(HERE / 'native_placeholder_llm.py')}
exec(compile(src[:src.index('if args.polish:')], str(HERE / 'native_placeholder_llm.py'), 'exec'), lane)
m, OUT, NAMED, results_store = lane['m'], lane['OUT'], lane['NAMED'], lane['results_store']
CODE = re.compile(r'```(?:cpp|c\+\+)\s*\n(.*?)```', re.S)
GOT = re.compile(r'Compiled symbol (\S+) but the binary symbol is')
reg = m.load_registry()


def number(p):
    return int(re.sub(r'\D', '', p.stem) or 0)


def one(addr):
    work = OUT / addr
    errs = sorted(work.glob('err*.txt'), key=number)
    pick = next(((e, GOT.search(e.read_text(errors='replace'))) for e in reversed(errs)
                 if GOT.search(e.read_text(errors='replace'))), None)
    if not pick:
        return addr, 'skip', ''
    err, hit = pick
    answer = work / err.name.replace('err', 'try').replace('.txt', '.cpp')
    if not answer.is_file():
        return addr, 'skip', ''
    reply = answer.read_text(errors='replace')
    code = CODE.findall(reply)
    if not code:
        return addr, 'skip', ''
    compiled = hit.group(1)
    NAMED[addr] = (compiled, (reg.get(addr) or {}).get('signature') or compiled)   # judge with the compiled symbol
    try:
        status, detail, cls, decl = lane['judge'](work, addr, reply, code[-1])
    except Exception as error:                                   # noqa: BLE001
        return addr, 'harness-error', repr(error)[:100]
    if status == 'inactive_exact':
        n = number(sorted(work.glob('try*.cpp'), key=number)[-1]) + 1
        (work / ('try%d.cpp' % n)).write_text(reply)            # the promoter reads the last try
        (work / ('err%d.txt' % n)).write_text('inactive_exact\ncompiled symbol %s (registry name differs: INFERRED name)' % compiled)
        row = dict(results_store.load().get(addr) or {})
        row.update(status=status, detail='', model='wrongsig-regate', **({'class': cls, 'decl': decl} if cls else {}))
        results_store.save({addr: row})
        lane['record'](addr, len(m.match.target('2008-06', addr)[0]), status, 'wrongsig-regate', cls, decl)
    return addr, status, compiled[:70]


cl = json.loads((HERE / 'remaining-classified.json').read_text())
todo = [a for a in cl if any(GOT.search(e.read_text(errors='replace')) for e in (OUT / a).glob('err*.txt'))]
print('wrong-signature answers to regate: %d' % len(todo), flush=True)
counts = collections.Counter()
with ThreadPoolExecutor(args.jobs) as pool:
    for addr, status, detail in pool.map(one, todo):
        counts[status] += 1
        print(addr, status, detail, flush=True)
print('RESULT wrong-signature regate: %s' % dict(counts), flush=True)
