"""python fixloop.py [--has BYTES] [--secs N]: one command for the link-fix cycle that used to be 4-6 manual steps.
1. --has BYTES: reconvert only converted analogs whose object contains BYTES (after a rename.py rule change)
2. stub_exact.py until no stubbed exact address becomes active (closure of func_<addr> callees)
3. renamed_link.py, 4. quicktest.py probe; prints the first crash (or NO CRASH) and a timing line per step."""
import re, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
PY = sys.executable
args = sys.argv[1:]
secs = args[args.index('--secs') + 1] if '--secs' in args else '40'
T = []


def step(name, cmd, keep=lambda l: False):
    t = time.time()
    prof = []   # cProfile wrapping broke renamed_link/quicktest (exited at once): profile them by hand instead
    p = subprocess.run([PY] + prof + cmd, cwd=H, capture_output=True, text=True)
    out = p.stdout + p.stderr
    T.append('%s %.0fs' % (name, time.time() - t))
    for l in out.splitlines():
        if keep(l):
            print('  ' + l[:170], flush=True)
    return out


if '--has' in args:
    step('reconvert', ['rename_par.py', '14', '--retry', 'renamed', '--has', args[args.index('--has') + 1]],
         lambda l: l.startswith('Counter'))
if '--failed' in args:   # objects bound to func_<addr> whose own conversion failed (stub): reconvert just those
    import json, re as _re
    _f = set(json.load(open(H / 'renamed/stub_exact_fail.json')))
    _am = json.load(open(H / 'renamed/addrmap.json'))
    _sel = []
    for v in _am.values():
        o = H / 'renamed/obj_full' / (v['exact'][0] + '.obj')
        if o.exists() and any(m.decode() in _f for m in _re.findall(rb'func_([0-9a-f]{8})', o.read_bytes())):
            _sel.append(v['exact'][0])
    (H / 'renamed/fixloop_addrs.json').write_text(json.dumps(sorted(set(_sel))))
    print('  %d objects reference failed func_ addresses' % len(set(_sel)))
    step('reconvert', ['rename_par.py', '12', '--addrs', str(H / 'renamed/fixloop_addrs.json')], lambda l: l.startswith('Counter'))
# new func_<addr> stubs only show after a link (linkexp/qt_und.txt): link, close them, relink while anything new appears.
# Close the PREVIOUS link's stubs first, so their objects join this link instead of forcing a second ~4-min round
if (H / 'linkexp/qt_und.txt').exists():
    step('stub_exact-pre', ['stub_exact.py'], lambda l: l.startswith(('converted', '0 stubbed')))
step('link', ['renamed_link.py'], lambda l: 'ready' in l or '[rl ' in l)
for i in range(4):
    step('qt-link', ['quicktest.py', '0'], lambda l: l.startswith(('stubbed', '  [qt', 'predicted')))
    out = step('stub_exact', ['stub_exact.py'], lambda l: l.startswith(('converted', '0 stubbed')))
    _na = re.search(r'newly active (\d+)', out)
    if not _na or int(_na.group(1)) < 20:   # a handful of new objects is not worth a 4-minute relink: next loop takes them
        break
    step('link', ['renamed_link.py'], lambda l: 'ready' in l or '[rl ' in l)
# static layout checks on the fresh link (seconds): class layout drift / ODR size breaks show before they crash
_lay = [subprocess.Popen([PY] + c, cwd=H, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)   # overlap with the probe
        for c in (['layoutdiff.py', 'run/RobloxQT.exe', 'linkexp/qt.map'], ['odrdiff.py'])]
step('classscan', ['classscan.py'], lambda l: True)   # 2 s: known bug classes over the whole link
_sc = step('startcheck', ['startcheck.py', '15'], lambda l: True)   # 15 s, no debugger
if '3221226356' in _sc:
    # heap corruption (0xC0000374): run the page-heap copy (IFEO GlobalFlag set for RobloxPH.exe by the owner) under
    # the debugger; the verifier stop names the bad free/write and its stack in ~1 min instead of a bisect
    import shutil as _sh7, os as _os7
    _sh7.copy2(H / 'run/RobloxQT.exe', H / 'run/RobloxPH.exe'); _sh7.copy2(H / 'linkexp/qt.map', H / 'run/RobloxPH.map')
    _p7 = subprocess.run([PY, str(H.parents[1] / 'work/native-client/shortcut/crashsite.py'), str(H / 'run/RobloxPH.exe'),
                          str(H / 'run/RobloxPH.map'), '30'], cwd=H, capture_output=True, env=dict(_os7.environ, STOP_ON_BP='1', PROBE_IDLE='10'))
    _o7 = _p7.stdout.decode('latin-1', 'replace').replace('\x00', '')
    (H / 'auto/pageheap_probe.txt').write_text(_o7)
    T.append('pageheap')
    for _l in _o7.splitlines():
        if re.search(r'VERIFIER STOP|Heap block|BREAKPOINT \(unplanned\)', _l) or _l.startswith('  stack'):
            print('  ' + _l.strip()[:170])
if _sc.strip().startswith('DIALOG'):
    # no crash, but an error box (Failed to create empty document): which placeholders ran before it? Usually a stub's
    # 0 = FALSE/NULL. One stubhits variant (File->New), ~40 s; its targets also feed the workers (stub_hit_targets.txt)
    import os as _os8
    _env8 = dict(_os8.environ, STUBHIT_VARIANTS='0xE100', SKIPAV='15')
    _p8 = subprocess.run([PY, 'stubhits.py', '30'], cwd=H, capture_output=True, text=True, env=_env8)
    T.append('stubhits %s' % ('ok' if _p8.returncode == 0 else 'failed'))
    print('  ' + ((_p8.stdout.strip().splitlines() or ['stubhits: no output'])[-1])[:170])
    try:
        import json as _j8
        for _h in _j8.loads((H / 'auto/stub_hits.json').read_text())[:12]:
            print('    stub hit: %s  <- %s' % (str(_h.get('name'))[:80], str(_h.get('caller'))[:70]))
    except Exception:
        pass
if _sc.strip().startswith('OK'):
    (H / 'auto/qt_probe.txt').write_text('NO CRASH in 15s (startcheck: %s)' % _sc.strip())   # healthy: skip the debugger probe
else:
    # crash-continue probe beside the normal one (own exe copy): skips each AV and lists the next sites, so one relink
    # can fix several crash classes (diagnostic only; auto/skipav.txt)
    import shutil as _sh0, os as _os9
    _sh0.copy2(H / 'run/RobloxQT.exe', H / 'run/RobloxSK.exe')
    _skp = subprocess.Popen([PY, str(H.parents[1] / 'work/native-client/shortcut/crashsite.py'), str(H / 'run/RobloxSK.exe'),
                             str(H / 'linkexp/qt.map'), secs], cwd=H, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True,
                            env=dict(_os9.environ, SKIPAV='15', FASTFWD='30', PROBE_IDLE='12',
                                     BPIMP='_invalid_parameter_noinfo,_purecall,abort,_invoke_watson,_amsg_exit'))
    step('probe', ['probe.py', secs], lambda l: l.startswith(('exception', 'NO CRASH', '  stack', 'ENTRY hit', '   mem ')))
    _sko = _skp.communicate()[0]
    (H / 'auto/skipav.txt').write_text(_sko)
    for _l in _sko.splitlines():
        if _l.startswith(('SKIPAV', 'FASTFWD', 'no crash within', 'process exited')):
            print('  ' + _l[:200])
for _pp in _lay:
    for _l in _pp.communicate()[0].splitlines():
        if 'differ' in _l or 'different sizes' in _l:
            print('  ' + _l[:170])
print('timing: ' + ', '.join(T))
# crash classifier: was the fault caused by a placeholder stub (its result is garbage)? The newest stub called just
# before the crash (call target inside a *stubs.obj symbol, read from the return addresses on the stack) is queued
# for the API workers (auto/worker_queue.txt); everything else is printed as UNKNOWN for a person to look at
import re as _re2, struct as _s2, bisect as _b2
_pr = (H / 'auto/qt_probe.txt').read_text(errors='replace')
_m = _re2.search(r'^exception \S+ at ([0-9a-f]{8})', _pr, _re2.M)
if _m:
    _syms = []
    for _l in (H / 'linkexp/qt.map').read_text(errors='replace').splitlines():
        _p = _l.split()
        if len(_p) >= 4 and _re2.fullmatch(r'[0-9a-f]{8}', _p[2]) and ':' in _p[0]:
            _syms.append((int(_p[2], 16), _p[1], _p[-1]))
    _syms.sort(); _ks = [x[0] for x in _syms]
    _own = lambda v: _syms[_b2.bisect_right(_ks, v) - 1]
    import pefile as _pf
    _img = _pf.PE(str(H / 'run/RobloxQT.exe'), fast_load=True).get_memory_mapped_image()
    _found = []
    for _ra in [int(x, 16) for x in _re2.findall(r'^\s+stack ([0-9a-f]{8})', _pr, _re2.M)] + [int(_m.group(1), 16)]:
        _o = _ra - 0x400000 - 5
        if 0 <= _o < len(_img) - 5 and _img[_o] == 0xe8:
            _t = _ra + _s2.unpack_from('<i', _img, _o + 1)[0]
            _st = _own(_t)
            if _st[2].lower().endswith('stubs.obj'):
                _found.append(_st[1])
    if _found:
        _n = _found[0]
        _a = _re2.search(r'(?:func|fn)_([0-9a-f]{8})', _n)
        print('CLASSIFIED: stub %s returned garbage%s' % (_n[:100], ' -> queued %s for workers' % _a.group(1) if _a else ' (no address)'))
        if _a:
            _q = H / 'auto/worker_queue.txt'
            _old = _q.read_text().split() if _q.exists() else []
            if _a.group(1) not in _old:
                _q.write_text('\n'.join(_old + [_a.group(1)]))
    else:
        print('UNKNOWN crash class at %s %s' % (_m.group(1), _own(int(_m.group(1), 16))[1][:90]))
# RobloxPlay.exe = the best build so far for a person to try (never the file the next link overwrites): copied when the
# probe shows no crash, or a crash later than the current RobloxPlay's (auto/play_best.json)
import shutil as _sh, json as _js
_pr2 = (H / 'auto/qt_probe.txt').read_text(errors='replace')
_t = re.search(r'crash after ([\d.]+)s', _pr2) if False else _re2.search(r'crash after ([\d.]+)s', _pr2)
_score = 1e9 if 'NO CRASH' in _pr2 or not _t else float(_t.group(1))
_bf = H / 'auto/play_best.json'
_best = _js.loads(_bf.read_text()).get('score', 0) if _bf.exists() else 0
if _score >= max(_best, 15):   # never a build that dies before its window is up
    try:
        _sh.copy2(H / 'run/RobloxQT.exe', H / 'run/RobloxPlay.exe')
        _sh.copy2(H / 'linkexp/qt.map', H / 'run/RobloxPlay.map')   # matching map: probes of the best build stay symbolized
        _bf.write_text(_js.dumps({'score': _score}))
        print('RobloxPlay.exe updated (%s)' % ('no crash' if _score == 1e9 else 'crash after %.1fs' % _score))
    except OSError as _e:
        print('RobloxPlay.exe not updated (in use?): %s' % _e)
