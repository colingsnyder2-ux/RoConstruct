"""python classscan.py: static scan of the last link (linkexp/qt.map + renamed/rename.json) for known bug CLASSES, so a
whole class is fixed in one batch instead of one crash per run. Seconds; read-only. Writes auto/classscan.json.
  A  converted objects whose main function is not defined by them in the link (static main / stripped / shadowed)
  B  converted objects binding an original data address that a native source names, under another name
  C  stubbed func_<addr> names whose address has an exact source that did not convert (failures on a referenced path)
  D  real names defined by BOTH a converted object and a native object (first one wins: possible wrong copy)"""
import json, os, re
from collections import defaultdict
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
defs = defaultdict(set)            # symbol -> {object basename}
for l in (H / 'linkexp/qt.map').read_text(errors='replace').splitlines():
    p = l.split()
    if len(p) >= 4 and ':' in p[0] and re.fullmatch(r'[0-9a-f]{8}', p[2]):
        defs[p[1]].add(p[-1])
r = json.loads((H / 'renamed/rename.json').read_text())
linked = {os.path.basename(x['object'])[:8] for x in json.loads((H / 'renamed/results.json').read_text())}
mren = json.loads((H / 'renamed/main_rename.json').read_text()) if (H / 'renamed/main_rename.json').exists() else {}
nd = json.loads((H / 'renamed/native_data.json').read_text()) if (H / 'renamed/native_data.json').exists() else {}
out = {}
# A
a_bad = []
for a in sorted(linked):
    sym = 'func_' + a if a in mren else (r.get(a) or {}).get('symbol')
    if sym and defs.get(sym) and all(o.lower().endswith(('stubs.obj', 'stubs2.obj')) for o in defs[sym]):   # referenced but stub-only (absent = unreferenced, removed by the linker: fine)
        a_bad.append(a)
out['A_main_not_defined_by_its_object'] = a_bad
# B
out['B_native_data_under_other_name'] = sorted(a for a in linked if any(v in nd and nd[v] != k for k, v in ((r.get(a) or {}).get('refs') or {}).items()))
# C
stub_objs = {o for s, os_ in defs.items() for o in os_ if o.lower().endswith('stubs.obj')}
c_bad = []
for s, os_ in defs.items():
    m = re.fullmatch(r'func_([0-9a-f]{8})', s)
    if m and os_ and all(o.lower().endswith(('stubs.obj', 'stubs2.obj')) for o in os_):
        f = ROOT / 'src/2008-06' / (m.group(1) + '.cpp')
        if f.exists() and f.open(errors='replace').readline().startswith('// from server: 100%'):
            c_bad.append((m.group(1), (r.get(m.group(1)) or {}).get('status', 'no job')))
out['C_stubbed_but_exact_source'] = c_bad
# D
d_bad = []
for s, os_ in defs.items():
    if s.startswith('?') and not s.startswith(('??_C', '??_R', '??_7', '?_')) and len(os_) > 1:
        conv = [o for o in os_ if re.fullmatch(r'[0-9a-f]{8}\.obj', o)]
        nat = [o for o in os_ if o not in conv and not o.lower().endswith(('stubs.obj', 'stubs2.obj')) and ':' not in o]
        if conv and nat:
            d_bad.append((s, conv[:2], nat[:2]))
out['D_converted_and_native_both_define'] = d_bad
(H / 'auto/classscan.json').write_text(json.dumps(out, indent=1))
for k, v in out.items():
    ex = v[:3]
    print('%-40s %6d   e.g. %s' % (k, len(v), str(ex)[:150]))
# F: 'DLL!name' import labels aliased to a DIFFERENT function's __imp_ symbol (EnterCriticalSection -> SysFreeString
#    made every lock free its critical section: heap corruption). Seconds, from aliases_renamed.txt.
_fb = []
try:
    for _l in (H / 'aliases_renamed.txt').read_text().splitlines():
        if '!' in _l and '=' in _l and not _l.startswith('#'):
            _k, _v = _l.split('=', 1)
            _n = _k.split('!', 1)[1]
            if _n.startswith(('?', '#')):
                continue
            if re.sub(r'@\d+$', '', _v.replace('__imp_', '', 1)).lstrip('_') != _n.lstrip('_'):
                _fb.append(_l)
except OSError:
    pass
out['F_import_alias_to_other_function'] = _fb
(H / 'auto/classscan.json').write_text(json.dumps(out, indent=1))
print('%-40s %6d   e.g. %s' % ('F_import_alias_to_other_function', len(_fb), str(_fb[:3])[:150]))
# G: names a STUB object defines in the final link although a library / CRT / import library / the linker provides them
#    (my missing-name predictor stubbed ___ImageBase: WinMain got a stub's address as hInstance -> MFC threw at startup).
#    Stubs link last, so a stub only wins when the real definition was never pulled in.
_LINKER = {'___ImageBase', '__ImageBase', '___safe_se_handler_table', '___safe_se_handler_count', '__load_config_used',
           '___guard_check_icall_fptr', '___guard_fids_table', '___guard_fids_count', '___guard_flags'}
try:
    _libdef = set(json.load(open(H / 'renamed/defined.json')))
    _amap = set(json.load(open(H / 'renamed/addrmap.json')))   # conversion targets: stubs allowed when conversion failed
except (OSError, ValueError):
    _libdef, _amap = set(), set()
_gb = sorted(s for s, os_ in defs.items()
             if os_ and all(o.lower().endswith(('stubs.obj', 'stubs2.obj')) for o in os_)
             and not re.match(r'^_?(?:func|dat|fn|g)_[0-9a-f]{8}|^@fn_|^_roc_|^roc_str_', s)
             and (s in _LINKER or (s in _libdef and s not in _amap)))
out['G_stub_shadows_library_or_linker_name'] = _gb
(H / 'auto/classscan.json').write_text(json.dumps(out, indent=1))
print('%-40s %6d   e.g. %s' % ('G_stub_shadows_library_or_linker_name', len(_gb), str(_gb[:4])[:150]))
