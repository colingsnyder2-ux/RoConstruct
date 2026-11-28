"""One-command boot cycle: relink the donor-free exe (skipping links whose inputs did not change) and probe it once.

    python boot.py [RESULTS_JSON ...] [--file-new] [--no-probe] [--secs N] [--show]

RESULTS_JSON: native_check_runner results whose compiled objects replace older objects of the same source.
--file-new  post File->New (0xE100) to the (hidden) main window; the window stays hidden unless --show.
--no-probe  link only.
Prints a compact summary (stub count, first meaningful stub hits, crash/windows) and appends timing to metrics.jsonl
(see rates.py). Replaces the old boot.py/cycle steps: no restub pass unless the object set changed."""
import hashlib, json, os, re, shutil, subprocess, sys, time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
R = str(ROOT) + '/'
H = R + 'work/donorfree-route/'
args = sys.argv[1:]
FILE_NEW = '--file-new' in args
NO_PROBE = '--no-probe' in args
SHOW = '--show' in args
secs = '25'
if '--secs' in args:
    secs = args[args.index('--secs') + 1]
results = [a for a in args if a.endswith('.json')]
t0 = time.time()
# one boot cycle at a time across processes/sessions (they share link/ and run/): wait, steal a lock older than 15 min
import atexit
LOCK = H + 'link/boot.lock'
while True:
    try:
        _fd = os.open(LOCK, os.O_CREAT | os.O_EXCL | os.O_WRONLY)
        os.write(_fd, str(os.getpid()).encode()); os.close(_fd)
        break
    except FileExistsError:
        try:   # owner process gone (killed job): take the lock over at once
            _pid = int(open(LOCK).read().strip() or 0)
            import ctypes as _c
            _h = _c.windll.kernel32.OpenProcess(0x1000, False, _pid) if _pid else 0
            _alive = False
            if _h:
                _code = _c.c_ulong(); _c.windll.kernel32.GetExitCodeProcess(_h, _c.byref(_code)); _alive = _code.value == 259
                _c.windll.kernel32.CloseHandle(_h)
            if not _alive:
                os.remove(LOCK)
                continue
        except (OSError, ValueError):
            pass
        try:
            if time.time() - os.path.getmtime(LOCK) > 900:
                os.remove(LOCK)
                continue
        except OSError:
            continue
        if time.time() - t0 > 900:
            print('boot lock held by another cycle for 15 min: giving up'); sys.exit(2)
        time.sleep(5)
atexit.register(lambda: os.path.exists(LOCK) and os.remove(LOCK))
objs = [(H + 'link/stubs.obj').replace('/', chr(92))]
extra = H + 'extra/objs.txt'
for a in results:
    rows = json.load(open(a))
    rows = rows if isinstance(rows, list) else rows['results']
    objs += [r['object'] for r in rows if r['status'] == 'complete']
    open(H + 'extra/sources.txt', 'a').write(''.join(os.path.basename(r['source']) + chr(10) for r in rows if r['status'] == 'complete'))


_SRC = {}


def _src_of(obj):   # source basename of an extra object, from its run's results.json (one parse per results file)
    p = os.path.join(os.path.dirname(os.path.dirname(obj)), 'results.json')
    if p not in _SRC:
        try:
            rows = json.load(open(p))
            rows = rows if isinstance(rows, list) else rows['results']
            _SRC[p] = {os.path.normcase(os.path.abspath(r.get('object') or '')): os.path.basename(r['source']).lower() for r in rows}
        except Exception:
            _SRC[p] = {}
    return _SRC[p].get(os.path.normcase(os.path.abspath(obj)))


if len(objs) > 1:
    fresh = {_src_of(o) for o in objs[1:]} - {None}
    old = [l.strip() for l in open(extra) if l.strip()] if os.path.exists(extra) else []
    keep = [o for o in old if _src_of(o) not in fresh]   # a recompiled source replaces its older object
    open(extra, 'w').write(chr(10).join(keep + objs[1:]) + chr(10))
allx = (sorted(set(l.strip() for l in open(extra) if l.strip())) if os.path.exists(extra) else []) + [objs[0]]   # stubs last: first definition wins
env = dict(os.environ, EXTRA_OBJS=';'.join(allx), DROP_SOURCES=';'.join(sorted(set(l.strip() for l in open(H + 'extra/sources.txt') if l.strip()))))


def fingerprint(paths):
    h = hashlib.sha1()
    for p in paths:
        try:
            st = os.stat(p)
            h.update(('%s|%d|%d;' % (p, st.st_size, int(st.st_mtime))).encode())
        except OSError:
            h.update((p + '|missing;').encode())
    return h.hexdigest()


stamp = Path(H + 'link/inputs.json')
last = json.loads(stamp.read_text()) if stamp.exists() else {}
TOOLS = [H + n for n in ('make_stubs.py', 'donorfree_link.py', 'auto_aliases.py', 'aliases.txt', 'aliases_renamed.txt', 'aliases_twins.txt')]   # tool edits must retrigger the link
fp_plain = fingerprint(allx[:-1] + TOOLS)
t_link = 0.0
PH = {}
optimistic_ok = False
if fp_plain != last.get('plain') and os.path.exists(H + 'link/stubs.obj') and '--full' not in args:
    # optimistic single link with the existing stubs (real definitions come first, so /FORCE:MULTIPLE keeps them);
    # only new unresolved symbols need the full plain-link -> aliases -> stubs pass
    t = time.time()
    subprocess.run([sys.executable, H + 'donorfree_link.py'], env=env, capture_output=True, text=True)
    t_link += time.time() - t
    _log = open(H + 'link/link.log', errors='replace').read() if os.path.exists(H + 'link/link.log') else ''
    if os.path.exists(H + 'link/donorfree.exe') and not re.search(r'LNK20(01|19)', _log):
        optimistic_ok = True
        last['plain'] = fp_plain
        last['final'] = fingerprint(allx + TOOLS + [H + 'aliases_auto.txt'])
        stamp.write_text(json.dumps(last))
if optimistic_ok:
    pass
elif fp_plain != last.get('plain') or not os.path.exists(H + 'link/stubs.obj'):
    t = time.time()   # object set changed: link without stubs, rebuild stubs.obj from the real unresolved list
    subprocess.run([sys.executable, H + 'donorfree_link.py'], env=dict(env, EXTRA_OBJS=';'.join(allx[:-1]), ROC_LINK_DISCOVER='1'), capture_output=True, text=True)   # lld: unresolved list in seconds
    PH['discover'] = time.time() - t; _t = time.time()
    _aa = subprocess.run([sys.executable, H + 'auto_aliases.py'], capture_output=True, text=True)
    PH['aliases'] = time.time() - _t   # draft helper names -> the function their address-draft defines
    print('aliases:', (_aa.stdout.strip() or _aa.stderr.strip()[-300:])[:300])
    # no relink here: make_stubs drops aliased symbols itself (saved one ~30s link per cycle)
    shutil.copy(H + 'link/link.log', H + 'link/discover.log')   # make_stubs input: the discovery link's unresolved list
    if os.path.exists(H + 'link/extra_unresolved.txt'):
        # keep last link's leftovers (saves the second stub pass + relink) minus anything some object now defines
        try:
            _def = set(json.load(open(H + 'link/defined_cache.json')))
        except Exception:
            _def = set()
        _keep = [u for u in open(H + 'link/extra_unresolved.txt').read().split() if u not in _def]
        open(H + 'link/extra_unresolved.txt', 'w').write(chr(10).join(_keep))
    _t = time.time()
    subprocess.run([sys.executable, H + 'make_stubs.py'], capture_output=True, text=True)
    PH['stubs'] = time.time() - _t
    t_link += time.time() - t
    last['plain'] = fp_plain
    last.pop('final', None)
fp_final = fingerprint(allx + TOOLS + [H + 'aliases_auto.txt'])
if fp_final != last.get('final') or not os.path.exists(H + 'link/donorfree.exe'):
    t = time.time()
    subprocess.run([sys.executable, H + 'donorfree_link.py'], env=env, capture_output=True, text=True)
    PH['final'] = time.time() - t
    t_link += time.time() - t
    last['final'] = fp_final
    stamp.write_text(json.dumps(last))
if os.path.exists(H + 'link/donorfree.exe') and os.path.exists(H + 'link/discover.log'):
    # second pass: symbols still unresolved after the final link call address 0 -> stub them too and relink once
    sys.path.insert(0, H)
    from donorfree_link_parse import parse_unresolved as _pu
    _left = [u for u in _pu(open(H + 'link/link.log', errors='replace').read()) if '!' not in u]
    _seen = set(open(H + 'link/extra_unresolved.txt').read().split()) if os.path.exists(H + 'link/extra_unresolved.txt') else set()
    if _left and not set(_left) <= _seen:
        open(H + 'link/extra_unresolved.txt', 'w').write(chr(10).join(sorted(_seen | set(_left))))
        _t = time.time()
        subprocess.run([sys.executable, H + 'make_stubs.py'], capture_output=True, text=True)
        PH['stubs2'] = time.time() - _t
        t = time.time()
        subprocess.run([sys.executable, H + 'donorfree_link.py'], env=env, capture_output=True, text=True)
        PH['final2'] = time.time() - t
        t_link += time.time() - t
if not os.path.exists(H + 'link/donorfree.exe') and 'LNK1104' in open(H + 'link/link.log', errors='replace').read():
    time.sleep(5)   # exe briefly locked (antivirus scan of the previous image): retry once
    subprocess.run([sys.executable, H + 'donorfree_link.py'], env=env, capture_output=True, text=True)
if not os.path.exists(H + 'link/donorfree.exe'):
    print('LINK FAILED: see link/link.log')
    sys.exit(1)
shutil.copy(H + 'link/donorfree.exe', H + 'run/RobloxDonorFree.exe')
try:
    stubs = json.load(open(H + 'link/stubs.json'))
    n_stubs = len(stubs['functions']) + len(stubs['data'])
except Exception:
    n_stubs = -1
summary = {'ts': int(time.time()), 'objs': len(allx), 'stubs': n_stubs, 'link_s': round(t_link, 1)}
lines = ['linked in %.0fs (%d objects, %d stub symbols) | %s' % (t_link, len(allx), n_stubs, ' '.join('%s %.0fs' % kv for kv in PH.items()))]
if not NO_PROBE:
    penv = dict(os.environ, BPSTUBS='1')
    if FILE_NEW:
        penv.update(POSTCMD='0xE100', ROC_PROBE_VISIBLE='1')
    if SHOW:
        penv['ROC_SHOW_WINDOW'] = '1'
    t = time.time()
    out = subprocess.run([sys.executable, R + 'work/native-client/shortcut/crashsite.py', H + 'run/RobloxDonorFree.exe', H + 'link/donorfree.map', secs],
                         env=penv, capture_output=True, text=True).stdout
    summary['probe_s'] = round(time.time() - t, 1)
    noise = re.compile(r'hasStringValue|isReadOnly|raisePropertyChanged|convertToString|InitializeAllIcons|loadBrowserIcons|\?\$')
    seen = []
    for l in out.splitlines():
        if l.startswith('STUB ') and not noise.search(l[:120]):
            seen.append(l[5:].split(' <- ')[0][:90])
    exc = [l for l in out.splitlines() if l.startswith('exception ')]
    lines.append('stub hits (non-noise, call order): ' + ('; '.join(seen[:6]) or 'none'))
    if exc:
        lines.append(exc[0][:170])
        summary['crash'] = exc[0][:120]
        for l in out.splitlines():
            if l.startswith('eax '):
                lines.append(l[:110])
                break
    else:
        lines.append('no crash within %ss' % secs)
        win = [l.strip() for l in out.splitlines() if 'class=' in l and 'title=' in l and 'IME' not in l and 'Cicero' not in l][:4]
        if win:
            lines.append('windows: ' + ' | '.join(win))
print('\n'.join(lines))
with open(H + 'metrics.jsonl', 'a') as f:
    f.write(json.dumps(summary) + chr(10))
