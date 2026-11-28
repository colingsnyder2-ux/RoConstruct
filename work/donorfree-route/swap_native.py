"""python swap_native.py ADDR NATIVE_SYMBOL [RESULTS_JSON]: use a native function instead of the AutoRecover_<ADDR> draft.
Adds aliases.txt lines mapping every draft helper name for ADDR (fn_<addr> in any decoration, read from the AutoRecover sources)
to NATIVE_SYMBOL, and drops the draft's object from extra/objs.txt. RESULTS_JSON (a native_check_runner run that compiled
the native source) is passed on to boot.py by the caller. Caller ABI must match: fastcall(self, edx, args) == thiscall(args)."""
import json, os, re, sys
from pathlib import Path

H = Path(__file__).parent
NC = H.parents[1] / 'rebuild/2008-06/native-classes'
addr, sym = sys.argv[1].lower().zfill(8), sys.argv[2]
decorated = set()
for f in NC.glob('AutoRecover_*.cpp'):   # caller declarations -> C decoration (cl decorates extern "C" names by convention)
    for m in re.finditer(r'extern\s+"C"[^;{]*?(__fastcall|__stdcall|__cdecl)?\s*\**\s*(\w+_%s)\s*\(([^)]*)\)' % addr, f.read_text(errors='replace')):
        conv, name, params = m.group(1), m.group(2), m.group(3).strip()
        n = 0 if params in ('', 'void') else 4 * (params.count(',') + 1)
        decorated.add('@%s@%d' % (name, n) if conv == '__fastcall' else '_%s@%d' % (name, n) if conv == '__stdcall' else '_' + name)
member = bool(re.search(r'@@[QAIEUM][AB][EG]', sym) or sym.startswith(('??0', '??1')))
cdecl_free = '@@YA' in sym or bool(re.search(r'@@[SKC]A', sym))
safe = {d for d in decorated if (member and d.startswith('@')) or (cdecl_free and d.startswith('_') and '@' not in d[1:])}
if decorated - safe:
    print('ABI-incompatible caller declarations left alone (fix the caller): ' + ' '.join(sorted(decorated - safe)))
decorated = safe
if not decorated and '--keep-draft' not in sys.argv:
    print('no compatible caller declaration: draft kept'); sys.exit(0)
lines = (H / 'aliases.txt').read_text().splitlines()
have = {l.split('=')[0] for l in lines if '=' in l}
new = ['%s=%s' % (d, sym) for d in sorted(decorated) if d not in have and d != sym]
(H / 'aliases.txt').write_text('\n'.join(lines + new) + '\n')
keep, drop, _RC = [], 0, {}
for o in (H / 'extra/objs.txt').read_text().splitlines():
    o = o.strip()
    if not o:
        continue
    src = ''
    try:   # one parse per results file (was a Path.resolve per row per object: minutes)
        _p = Path(o).parent.parent / 'results.json'
        if _p not in _RC:
            _rr = json.load(open(_p)); _rr = _rr if isinstance(_rr, list) else _rr['results']
            _RC[_p] = {os.path.normcase(os.path.abspath(r.get('object') or '')): r.get('source', '') for r in _rr}
        src = _RC[_p].get(os.path.normcase(os.path.abspath(o)), '')
    except Exception:
        pass
    if re.search(r'AutoRecover_%s' % addr + chr(92) + '.cpp', src, re.I):
        drop += 1
    else:
        keep.append(o)
(H / 'extra/objs.txt').write_text('\n'.join(keep) + '\n')
print('aliases added: %s; draft objects dropped: %d' % (' '.join(new) or 'none', drop))
