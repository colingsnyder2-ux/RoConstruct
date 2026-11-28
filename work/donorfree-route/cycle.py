"""python cycle.py [--no-link] [--no-ladder]: one fix cycle. Runs every bulk fixer on the LAST map (each is static
or compiles only its own generated sources), records new results.json files in work/native-client/STUB_RESULTS.txt,
links once with all of them (quicktest --results ...), then the feature ladder. Replaces the hand-run sequence.
Fixers (in order; each grow-only / idempotent):
  createfix      stubbed func_<X> that are create<T>()            -> aliases_createfix.txt
  creator_gen    stubbed FactoryProduct::Creator members          -> results + aliases_spell.txt
  facprod_gen    stubbed FactoryProduct<T,D,N>() constructors     -> results + aliases_override.txt
  boundprop_gen  stubbed BoundProp::BoundPropGetSet constructors  -> results + aliases_boundprop.txt
  spellalias     stubs differing from a real definition by type spelling -> aliases_spell.txt
  creatorinit    original creator registrations nothing runs      -> linkexp/xcu_creators.obj
  hardaddr       dat_ copies whose bytes are a real symbol        -> aliases_hardaddr.txt
  vtcolfix       vt_orig tables without an RTTI locator           -> linkexp/vt_orig.obj (in place)
Prints one line per fixer and the ladder."""
import re, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
SR = H.parent / 'native-client/STUB_RESULTS.txt'
FIX = ['classnames_gen.py', 'declare_gen.py', 'createfix.py', 'creator_gen.py', 'facprod_gen.py', 'boundprop_gen.py', 'spellalias.py', 'creatorinit.py', 'vtcolfix.py', 'deldtor_gen.py', 'zerodata_gen.py', 'datcode_alias.py', 'dupnative.py', 'zeroreloc.py', 'relocsplit.py', 'colalias.py'] + (['srcaddr_alias.py', 'dropcheck.py'] if '--full' in sys.argv else [])   # the two slow scanners (~90 s) only on --full


def run(args, timeout=1800):
    t = time.time()
    r = subprocess.run([sys.executable] + args, cwd=H, capture_output=True, text=True, timeout=timeout, env=dict(__import__('os').environ, PYTHONIOENCODING='utf-8'))
    return r.stdout + r.stderr, time.time() - t


new = []
for f in FIX:
    out, dt = run([f])
    lines = [l for l in out.splitlines() if l.strip()]
    res = [l.strip() for l in lines if l.strip().lower().endswith('results.json')]
    new += res
    summ = next((l for l in lines if l.startswith(f.split('.')[0].split('_')[0]) or ':' in l and f.split('.')[0] in l), lines[-1] if lines else '')
    print('%-15s %5.0fs  %s' % (f, dt, summ[:150]), flush=True)
out, dt = run(['-c', 'import hardaddr as h; s, o = h.stub_aliases(); print("hardaddr aliases", len(o))'])
print('%-15s %5.0fs  %s' % ('hardaddr', dt, out.strip().splitlines()[-1] if out.strip() else ''), flush=True)
have = [l.strip() for l in SR.read_text().splitlines() if l.strip()] if SR.exists() else []
GR = H.parent / 'native-client/GEMINI_RESULTS.txt'   # another agent's compiled results (bound, never written here)
extra = [l.strip() for l in GR.read_text().splitlines() if l.strip()] if GR.exists() else []
for r_ in new:
    if r_ not in have:
        have.append(r_)
SR.write_text('\n'.join(have) + '\n')
if '--no-link' in sys.argv:
    sys.exit(0)
args = (['-m', 'cProfile', '-o', str(H / 'auto/qt.prof')] if '--profile' in sys.argv else []) + [str(H / 'quicktest.py'), '0']
_rl = H / 'auto/cycle_results.txt'   # passed as a file: 300+ --results arguments overflowed the Windows command line
_rl.write_text(''.join(r_ + chr(10) for r_ in sorted(set(have) | set(extra)) if Path(r_).exists()))
args += ['--results-file', str(_rl)]
out, dt = run(args, timeout=3000)
(H / 'auto/cycle_quicktest.log').write_text(out)
fail = [l for l in out.splitlines() if 'LINK FAILED' in l or 'Traceback' in l]
print('%-15s %5.0fs  %s' % ('link', dt, fail[0] if fail else 'ok'), flush=True)
if fail or '--no-ladder' in sys.argv:
    sys.exit(1 if fail else 0)
out, dt = run(['featladder.py'], timeout=900)
print('\n'.join(out.strip().splitlines()[-11:]))
# Tiers 1/3/4/5 through -script (scripttest.py): the original's results are cached in auto/scripttest_orig.json
import json as _j
_oc = H / 'auto/scripttest_orig.json'
try:
    _orig = _j.loads(_oc.read_text())
except (OSError, ValueError):
    _orig = {}
for _lua in ('feature_test.lua', 'solo_test.lua'):
    _code = (
        'import json, scripttest as s; from pathlib import Path; L = Path(%r).read_text(); o = %r\n'
        'o = o or s.run(s.ORIG, L, 35); q = s.run(s.EXE, L, 35)\n'
        'print(json.dumps({"orig": o, "ours": q}))' % (_lua, _orig.get(_lua)))
    out, dt = run(['-c', _code], timeout=300)
    try:
        r_ = _j.loads(out.strip().splitlines()[-1])
    except (ValueError, IndexError):
        print('%-15s %5.0fs  ERROR %s' % (_lua, dt, out.strip()[-200:])); continue
    _orig[_lua] = r_['orig']
    of = set(sum((v['fail'] for kk, v in r_['orig'].items() if kk.startswith('R')), []))
    q = r_['ours']
    qs = {kk: v for kk, v in q.items() if kk.startswith('R')}
    bad = sorted(set(sum((v['fail'] for v in qs.values()), [])) - of) + ['stage %s missing' % kk for kk in r_['orig'] if kk.startswith('R') and kk not in qs]
    print('%-15s %5.0fs  %s' % (_lua, dt, q.get('_exit') or ('ok' if not bad else 'broken: %s' % bad)), flush=True)
_oc.write_text(_j.dumps(_orig))
