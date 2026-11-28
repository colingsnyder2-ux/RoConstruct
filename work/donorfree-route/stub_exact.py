"""python stub_exact.py: stubbed fn_/func_<addr> names whose address has a server-exact analog that was never converted
(fn_0056be10, a function-static mutex getter, returned 0 and crashed at static init). Adds addrmap jobs, converts them
in parallel (rename_par.py --addrs), marks the converted ones active so renamed_link.py links them."""
import json, os, re, subprocess, sys
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
R = H / 'renamed'
import hashlib as _hl
_inp = [H / 'link/stubs.json', H / 'linkexp/qt_und.txt', R / 'stub_exact_fail.json', R / 'rename.json']
_key = _hl.md5(''.join('%s%s' % (f, f.stat().st_mtime if f.exists() else 0) for f in _inp).encode()).hexdigest() + ' '.join(sys.argv[1:])
_kf = R / 'stub_exact_last.txt'
if _kf.exists() and _kf.read_text() == _key:
    print('0 stubbed addresses with exact analogs (inputs unchanged since the last run)'); print('converted 0 / 0; newly active 0'); sys.exit(0)
S = json.load(open(H / 'link/stubs.json'))['functions']
try:   # names quicktest had to stub on top (new drafts / converted objects since the last cycle link)
    S = list(S) + (H / 'linkexp/qt_und.txt').read_text().split()
except OSError:
    pass
res = json.load(open(R / 'rename.json'))
ff = json.load(open(ROOT / 'work/native-client/layout/function-files.json'))
_ex = lambda a: (ROOT / 'src/2008-06' / (a + '.cpp')).exists() and \
    (ROOT / 'src/2008-06' / (a + '.cpp')).open(errors='replace').readline().startswith('// from server: 100%')
refd = set()   # addresses some placeholder references: stubbed names + function pointers inside dat_ placeholder data
for s in S:
    m = re.search(r'(?:fn|func)_([0-9a-f]{8})', s)
    if m:
        refd.add(m.group(1))
# boost::function vtables, callback tables: the original data holds pointers to functions (dat_008102e8 -> invoker
# 00427630 + manager 004276e0); make_stubs relocates them to the exact object when one is linked, else a native/stub
import pefile, struct as _st
_img = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
_dat = sorted({int(m.group(1), 16) for d in json.load(open(H / 'link/stubs.json'))['data']
               for m in [re.search(r'dat_([0-9a-f]{8})', d)] if m})
for i, va in enumerate(_dat):
    end = min(_dat[i + 1] if i + 1 < len(_dat) else va + 512, va + 512)
    for p in range(va, end - 3, 4):
        t = _st.unpack_from('<I', _img, p - 0x400000)[0]
        if 0x401000 <= t < 0x7c0000 and '%08x' % t in ff:
            refd.add('%08x' % t)
refd = {a for a in refd if _ex(a)}
if '--all-exact' in sys.argv:   # every server-exact source, not only the ones a stub references (11k had no job)
    refd |= {f[:8] for f in os.listdir(ROOT / 'src/2008-06') if f.endswith('.cpp') and len(f) == 12 and _ex(f[:8])}
want = {a for a in refd if (res.get(a) or {}).get('status') != 'renamed'}
# failures are deterministic until the analog source or the converter changes: skip them (was 100 s every cycle)
_FC = R / 'stub_exact_fail.json'
try:
    _fail = {} if '--all' in sys.argv else json.loads(_FC.read_text())
except Exception:
    _fail = {}
_conv = (ROOT / 'work/native-client/rename.py').stat().st_mtime
_key = lambda a: [(ROOT / 'src/2008-06' / (a + '.cpp')).stat().st_mtime]   # converter edits rarely fix these: --all retries
_skip = {a for a in want if _fail.get(a) == _key(a)}
want -= _skip
_inactive = {a for a in refd if (res.get(a) or {}).get('status') == 'renamed'}
from collections import Counter as _C
_ncount = _C((v or {}).get('name') for v in ff.values())
am = json.load(open(R / 'addrmap.json'))
have = {v['exact'][0] for v in am.values()}
for a in sorted(want - have):   # same naming rule as autoflip.convert
    nm = (ff.get(a) or {}).get('name') or ''
    # a registry name on several addresses is an ICF label (0043 8060 / 0056be10 'G3D::Shape::axes' are mutex getters)
    key = (nm if nm.startswith('?') and not re.match(r'^\?\?(?:2|3|_U|_V)@Y', nm) and nm not in am and _ncount.get(nm, 0) == 1
           else 'func_' + a)
    am[key] = {'exact': [a]}
(R / 'addrmap.json').write_text(json.dumps(am, indent=0))
(R / 'stub_exact.json').write_text(json.dumps(sorted(want)))
print('%d stubbed addresses with exact analogs (%d known failures skipped)' % (len(want), len(_skip)))
if want:
    subprocess.run([sys.executable, str(H / 'rename_par.py'), os.environ.get('SE_JOBS', '8'), '--addrs', str(R / 'stub_exact.json')])
res = json.load(open(R / 'rename.json'))
ok = {a for a in want if (res.get(a) or {}).get('status') == 'renamed'}
_fail.update({a: _key(a) for a in want - ok})
_FC.write_text(json.dumps(_fail))
old_act = set(json.load(open(R / 'active.json')))
act = old_act | ok | _inactive
(R / 'active.json').write_text(json.dumps(sorted(act)))
print('converted %d / %d; newly active %d' % (len(ok), len(want), len(act - old_act)))
_kf.write_text(_hl.md5(''.join('%s%s' % (f, f.stat().st_mtime if f.exists() else 0) for f in _inp).encode()).hexdigest() + ' '.join(sys.argv[1:]))
