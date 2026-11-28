"""python autoflip.py [--max N] [--par P]: crash-driven exact-vs-native search, unattended and PARALLEL.
Every startup crash so far was an exact copy and a native/library copy disagreeing. For the functions on the current
crash stack, try flipping each (converted exact object -> dropped so native/library wins; native function with a
server-exact analog -> converted so exact wins). Each trial reuses the baseline's final lld command line
(linkexp/lld_final.rsp from quicktest.py: alias conflicts already resolved, extra stubs included) with ONE object added or
removed, links into its own exe/map and probes, P trials at a time. A flip is kept when the client gets further
(no crash, a different crash site, or a later crash). Kept flips go to renamed/bisect_exclude.json / addrmap so the
cycle job picks them up. Log: auto/autoflip.log."""
import json, os, re, shutil, subprocess, sys, time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT))
from roc import rebuild
MAX = int(sys.argv[sys.argv.index('--max') + 1]) if '--max' in sys.argv else 30
PAR = int(sys.argv[sys.argv.index('--par') + 1]) if '--par' in sys.argv else 6
SECS = '40'
LLD = r'C:\Program Files\LLVM\bin\lld-link.exe'
ENV = rebuild.env(rebuild.toolchain(21022))
LOG = H / 'auto/autoflip.log'
BX = H / 'renamed/bisect_exclude.json'
TD = H / 'linkexp/af'
TD.mkdir(parents=True, exist_ok=True)
ff = json.load(open(ROOT / 'work/native-client/layout/function-files.json'))
by_name = {}
for a, v in ff.items():
    n = (v or {}).get('name') or ''
    if n:
        by_name.setdefault(n, a)


def log(m):
    line = time.strftime('%H:%M:%S ') + m
    print(line, flush=True)
    with open(LOG, 'a') as f:
        f.write(line + '\n')


def parse(t):
    site = next((l for l in t.splitlines() if l.startswith(('exception', 'process exited', 'ENTRY hit'))), 'NO CRASH')
    if site == 'NO CRASH' and 'windows:' in t and not t.split('windows:', 1)[1].lstrip('\r\n').startswith('  '):
        site = 'HANG (no window)'   # excluding do_lock: no crash, but the main thread blocked before any window
    if site.startswith('ENTRY hit'):   # CRT abort (_invalid_parameter / _purecall): its caller stack is the evidence
        blk = t.split('ENTRY hit', 1)[1]
        site = 'ENTRY hit (CRT abort) ' + ' '.join(l.split(None, 1)[1].split('+')[0] for l in blk.splitlines()
                                                     if re.match(r'^\s{4}[0-9a-f]{8} ', l))[:200]
    m = re.search(r'crash after ([0-9.]+)s', t)
    secs = float(m.group(1)) if m else (999.0 if site == 'NO CRASH' else 0.0)
    frames = [l.split(None, 2)[2].split('+')[0] for l in t.splitlines() if l.startswith('  stack ')]
    if 'ENTRY hit' in t:
        frames = [l.split(None, 1)[1].split('+')[0] for l in t.split('ENTRY hit', 1)[1].splitlines()
                  if re.match(r'^\s{4}[0-9a-f]{8} ', l)] + frames
    elif 'C++ throw #1' in t and 'process exited' in t:   # unhandled C++ exception: the first throw's stack is the evidence
        blk = t.split('C++ throw #1', 1)[1].split('C++ throw #2', 1)[0]
        frames = [l.split(None, 1)[1].split('+')[0] for l in blk.splitlines() if re.match(r'^\s{4}[0-9a-f]{8} ', l)] + frames
    m2 = re.match(r'exception \S+ at \S+ (\S+?)\+', site)
    if m2:
        frames = [m2.group(1)] + frames
    key = re.sub(r'[0-9a-f]{8}|tid \d+|main \d+|\+[0-9a-f]+|after \S+', '', site)
    return secs, key, frames, site


def probe(exe, mp, tag):
    penv = dict(os.environ, FASTFWD='0', ROC_IE_ALLOW='1', ROC_PROBE_VISIBLE='1', SECOND_CHANCE_ONLY='1', POSTCMD='0xE100',
                BPIMP='_invalid_parameter_noinfo,_purecall,abort')
    p = subprocess.run([sys.executable, str(ROOT / 'work/native-client/shortcut/crashsite.py'), str(exe), str(mp), SECS],
                       capture_output=True, text=True, env=penv, cwd=H)
    (TD / ('%s.txt' % tag)).write_text(p.stdout + p.stderr)
    return parse(p.stdout)


def baseline():
    subprocess.run([sys.executable, str(H / 'renamed_link.py')], capture_output=True, text=True)
    subprocess.run([sys.executable, str(H / 'quicktest.py'), SECS], capture_output=True, text=True)
    base = (H / 'linkexp/qt.final.rsp').read_text().splitlines()
    t = (H / 'auto/qt_probe.txt').read_text(errors='replace')
    return base, parse(t)


def owners():
    o = {}
    for l in open(H / 'linkexp/qt.map', errors='replace'):
        p = l.split()
        if len(p) >= 4 and re.match(r'000\d:', p[0]):
            o.setdefault(p[1], p[-1])
    return o


try:
    NATIVE = set(json.load(open(H / 'link/native_defined.json')))
except Exception:
    NATIVE = None


def candidates(frames, tried, own):
    out = []
    R = json.load(open(H / 'renamed/rename.json'))
    for fn in list(dict.fromkeys(frames))[:16]:
        m = re.search(r'([0-9a-f]{8})\.obj$', own.get(fn, ''))
        if m and ('exclude', m.group(1)) not in tried:
            _na = {}
            try:
                _na = json.load(open(H / 'renamed/native_addrs.json'))
            except Exception:
                pass
            if NATIVE is None or fn in NATIVE or m.group(1) in _na:   # a native/library definition takes over (by name or address)
                out.append(('exclude', m.group(1), fn))
            continue
        a = by_name.get(fn) or (re.search(r'func_([0-9a-f]{8})', fn) or [None, None])[1]
        if a and R.get(a, {}).get('status') != 'renamed' and ('exact', a) not in tried:
            src = ROOT / 'src/2008-06' / (a + '.cpp')
            if src.exists() and src.read_text(errors='replace').startswith('// from server: 100%'):
                out.append(('exact', a, fn))
    return out


def convert(a):
    """exact conversion of one address (serial: rename.py shares its json)"""
    nm = (ff.get(a) or {}).get('name') or ''
    am = json.load(open(H / 'renamed/addrmap.json'))
    am[nm if nm.startswith('?') and not re.match(r'^\?\?(?:2|3|_U|_V)@Y', nm) else 'func_' + a] = {'exact': [a]}
    (H / 'renamed/addrmap.json').write_text(json.dumps(am, indent=0))
    R = H / 'renamed'
    env = dict(os.environ, ROC_ADDRMAP=str(R / 'addrmap.json'), ROC_RENAME_OUT=str(R / 'obj'), ROC_RENAME_JSON=str(R / 'af_one.json'),
               ROC_RENAME_PLACEHOLDER='1', ROC_RENAME_DEFINED=str(R / 'defined.json'), ROC_RENAME_KEEP_HELPERS='1')
    (R / 'af_one.json').unlink(missing_ok=True)
    subprocess.run([sys.executable, str(ROOT / 'work/native-client/rename.py'), a], env=env, cwd=ROOT, capture_output=True)
    try:
        one = json.load(open(R / 'af_one.json'))
        return one if one.get(a, {}).get('status') == 'renamed' else None
    except Exception:
        return None


def trial(k, base, kind, a):
    """one flip: edit the object list of the baseline's final lld command, link to its own exe, probe"""
    obj = str((H / 'renamed/obj' / (a + '.obj')).resolve())
    norm = lambda s: os.path.normcase(s.strip().strip('"'))
    lines = [l for l in base if not (kind == 'exclude' and norm(l) == os.path.normcase(obj))]
    if kind == 'exact':
        lines = ['"%s"' % obj] + lines
    exe, mp = H / ('run/RobloxAF%d.exe' % k), TD / ('af%d.map' % k)
    lines = [('"/OUT:%s"' % exe) if l.startswith('"/OUT:') else ('"/MAP:%s"' % mp) if l.startswith('"/MAP:') else l for l in lines]
    rsp = TD / ('af%d.rsp' % k)
    rsp.write_text('\n'.join(lines) + '\n')
    if exe.exists():
        exe.unlink()
    r = subprocess.run([LLD, '@' + str(rsp)], capture_output=True, text=True, env=ENV, errors='replace')
    if not exe.exists():
        return k, None, (r.stdout + r.stderr)[-300:]
    t = mp.read_text(errors='replace')
    mp.write_text(re.sub(r'(?<=\s)0{8}([0-9a-f]{8})(?=\s)', r'\1', t))
    return k, probe(exe, mp, 'af%d' % k), ''


def keep(kind, a, one=None):
    s = set(json.load(open(BX))) if BX.exists() else set()
    if kind == 'exclude':
        s.add(a)
    else:
        s.discard(a)
        R = H / 'renamed'
        res = json.load(open(R / 'rename.json')); res.update(one or {}); (R / 'rename.json').write_text(json.dumps(res, indent=1))
        act = set(json.load(open(R / 'active.json'))) | {a}; (R / 'active.json').write_text(json.dumps(sorted(act)))
    if kind == 'exact':   # renamed_link's policy rules (stub shadow, vendor) must not undo a proven flip
        _fx = H / 'renamed/force_exact.json'
        fx = set(json.load(open(_fx))) if _fx.exists() else set()
        _fx.write_text(json.dumps(sorted(fx | {a})))
    BX.write_text(json.dumps(sorted(s)))


def drop_unkept_exact(a):
    """an exact conversion we tried and did not keep must not leak into the cycle link"""
    s = set(json.load(open(BX))) if BX.exists() else set()
    s.add(a)
    BX.write_text(json.dumps(sorted(s)))


base, (secs, key, frames, site) = baseline()
log('baseline: %s (%.1fs)' % (site[:120], secs))
tried, kept = set(), 0
for it in range(MAX):
    cand = candidates(frames, tried, owners())
    if not cand:
        log('no flip candidates on this crash stack: stop (needs a human/LLM fix)')
        break
    batch, conv = [], {}
    for kind, a, fn in cand[:PAR]:
        tried.add((kind, a))
        if kind == 'exact':
            one = convert(a)
            if not one:
                log('  exact %s (%s): conversion failed' % (a, fn[:60])); continue
            conv[a] = one
        batch.append((kind, a, fn))
    if not batch:
        continue
    t0 = time.time()
    with ThreadPoolExecutor(len(batch)) as ex:
        res = list(ex.map(lambda x: trial(x[0], base, x[1][0], x[1][1]), enumerate(batch)))
    best = None
    for (kind, a, fn), (k, r, err) in zip(batch, res):
        if r is None:
            log('  %s %s (%s): link failed %s' % (kind, a, fn[:50], err[-120:].replace(chr(10), ' ')))
            continue
        s2, k2, f2, site2 = r
        _m = re.match(r'exception \S+ at ([0-9a-f]{8})', site2)
        _wild = bool(_m) and not (0x401000 <= int(_m.group(1), 16) < 0x980000)   # null / out-of-image: a broken link, not progress
        # a new crash site counts, but not an EARLIER one (excluding tss::set: exit at 0.0s instead of a 2.3s crash)
        better = site2 == 'NO CRASH' or (not _wild and k2 != key and s2 >= secs - 1.0 and not site2.startswith('process exited'))
        log('  %s %s (%s): %s (%.1fs)%s' % (kind, a, fn[:45], site2[:80], s2, '  <- better' if better else ''))
        if better and (best is None or s2 > best[3][0]):
            best = (kind, a, k, r)
    log('batch of %d in %.0fs' % (len(batch), time.time() - t0))
    for kind, a, fn in batch:   # everything not kept is reverted
        if kind == 'exact' and not (best and best[1] == a):
            drop_unkept_exact(a)
    if not best:
        log('no flip in this batch helped' + ('' if len(cand) > PAR else ': stop'))
        if len(cand) <= PAR:
            break
        continue
    kind, a, k, r = best
    keep(kind, a, conv.get(a))
    kept += 1
    log('KEEP %s %s -> %s' % (kind, a, r[3][:110]))
    base, (secs, key, frames, site) = baseline()   # new baseline with the kept flip
    if site == 'NO CRASH':
        log('NO CRASH within %ss' % SECS)
        break
log('done: %d flips kept; last: %s' % (kept, site[:120]))
