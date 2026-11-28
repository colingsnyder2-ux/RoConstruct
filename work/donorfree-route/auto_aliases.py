"""python auto_aliases.py: write aliases_auto.txt (symbol=target lines for /alternatename) linking draft helper names to the function
that another draft actually defines for the same address.
A draft that calls an unknown helper declares it as <name>_<8 hex address> (or fn_<address>); the helper's own draft (AutoRecover_<address>.cpp)
defines the function under whatever name it chose. Here: every unresolved symbol ending in _<address> (decorated or C) is mapped to the
function symbol its address-draft defines. Run after a link without stubs (boot.py does this); make_stubs.py then skips aliased symbols."""
import json, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
H = Path(__file__).parent
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(H))
from roc.rebuild import coff_externals as _coff_externals
import pickle as _pk, os as _os2
_XC_F = Path(__file__).parent / 'link/obj_ext_cache.pkl'   # path -> (mtime, size, externals): objects rarely change between links
from shardcache import ShardCache as _SC
_XC = _SC(_XC_F)   # sharded: only changed shards are rewritten
_XC_dirty = [False]
def coff_externals(data, _path=None):
    return _coff_externals(data)
def ext_of(path):
    st = _os2.stat(path)
    k = str(path)
    v = _XC.get(k)
    if v and v[0] == st.st_mtime and v[1] == st.st_size:
        return v[2]
    e = _coff_externals(Path(path).read_bytes())
    _XC[k] = (st.st_mtime, st.st_size, e); _XC_dirty[0] = True
    return e
import atexit as _ae
_ae.register(lambda: _XC_dirty[0] and _XC.save())
from donorfree_link_parse import parse_unresolved
import subprocess

UN = str(ROOT / 'tools/msvc800sp1/VC/bin/undname.exe')
log = (H / 'link/link.log').read_text(errors='replace')
unresolved = parse_unresolved(log)
want = {}
for s in unresolved:
    m = re.search(r'_([0-9a-f]{8})(?:@@|@|$)', s)
    if m:
        want.setdefault(int(m.group(1), 16), []).append(s)
# objects of address drafts: extra/objs.txt lines whose run results name AutoRecover_<addr>.cpp
obj_for = {}
_RC = {}   # results file -> {object path: source}, built once (was a Path.resolve per row per object)
import os as _os
for line in (H / 'extra/objs.txt').read_text().splitlines():
    o = line.strip()
    if not o:
        continue
    try:
        _p = Path(o).parent.parent / 'results.json'
        if _p not in _RC:
            _rows = json.load(open(_p))
            _rows = _rows if isinstance(_rows, list) else _rows['results']
            _RC[_p] = {_os.path.normcase(_os.path.abspath(r.get('object') or '')): r.get('source', '') for r in _rows}
        m = re.search(r'AutoRecover_([0-9a-f]{8})' + chr(92) + '.cpp', _RC[_p].get(_os.path.normcase(_os.path.abspath(o)), ''), re.I)
        if m:
            obj_for[int(m.group(1), 16)] = o
    except Exception:
        pass


def candidates(obj):
    out = []
    for name, is_def in ext_of(obj).items():
        if not is_def or name.startswith(('??_', '__', '_$', '??$', '?$', '??1', '??0')) or '$' in name[:6]:
            continue
        out.append(name)
    return out


lines = []
names = {int(a, 16): (r.get('name') or '') for a, r in json.load(open(ROOT / 'work/native-client/layout/function-files.json')).items()
         if not ((r or {}).get('requires_identity_review') and ((r or {}).get('duplicate_target_name_count') or 1) > 1)}
# ^ a registry name shared by several addresses is unproved (func_005c0160 = Backpack's classDescriptor was labelled
#   Instance's): aliasing by it sends calls to the wrong function. Those addresses stay stubs/conversions instead.
defined = set()
for line in (H / 'extra/objs.txt').read_text().splitlines():   # every symbol some native object defines
    try:
        defined |= {n for n, d in ext_of(line.strip()).items() if d}
    except Exception:
        pass
import re as _re
try:   # symbols the last link defined (base native objects are not in extra/objs.txt)
    for ml in (H / 'link/donorfree.map').read_text(errors='replace').splitlines():
        mm = _re.match(r'\s*0001:[0-9a-f]{8}\s+(\?\S+)\s+[0-9a-f]{8}', ml)
        if mm:
            defined.add(mm.group(1))
except Exception:
    pass
for _l in (H / 'link/donorfree.rsp').read_text().splitlines():   # every object the link reads, not just the map (/OPT:REF drops unreferenced functions)
    _o = _l.strip().strip('"')
    if _o.lower().endswith('.obj') and 'stubs.obj' not in _o:
        try:
            defined |= {n for n, d in ext_of(_o).items() if d}
        except Exception:
            pass
_cache = H / 'link/defined_cache.json'   # /OPT:REF drops unreferenced functions from the map, so remember every symbol ever seen defined
try:
    defined |= set(json.loads(_cache.read_text()))
except Exception:
    pass
_cache.write_text(json.dumps(sorted(defined)))
try:   # linked byte-exact converted objects: their func_<addr> beats a registry-named native (fn_00563090 -> native lock crashed)
    _exact = {int(re.search(r'([0-9a-f]{8})\.obj$', r['object']).group(1), 16)
              for r in json.load(open(H / 'renamed/results.json'))}
except Exception:
    _exact = set()
for addr, syms in sorted(want.items()):
    nm = names.get(addr, '')
    if addr in _exact:
        lines += ['%s=func_%08x' % (s, addr) for s in syms if s != 'func_%08x' % addr]
        continue
    if nm.startswith('?') and nm in defined:   # helper address is a named function some object already defines: alias to it
        lines += ['%s=%s' % (s, nm) for s in syms if s != nm]
        continue
    obj = obj_for.get(addr)
    if not obj:
        continue
    cands = candidates(obj)
    # prefer a symbol that carries the address, else the only function-like definition
    pick = next((c for c in cands if ('%08x' % addr) in c), None) or (cands[0] if len(cands) == 1 else None)
    if not pick:
        continue
    for s in syms:
        if s != pick:
            lines.append('%s=%s' % (s, pick))
# rename.py placeholders: func_<addr> -> whatever aliases.txt already maps that address's fn_ names to (natives)
_man = {}
for _l in (H / 'aliases.txt').read_text().splitlines():
    _m = re.match(r'^[_@]?fn_([0-9a-f]{8})(?:@[0-9]+)?=(.+)$', _l.strip())
    if _m:
        _man.setdefault(int(_m.group(1), 16), _m.group(2))
for addr, syms in sorted(want.items()):
    for s_ in syms:
        if s_ == 'func_%08x' % addr and addr in _man and not any(l.startswith(s_ + '=') for l in lines):
            lines.append('%s=%s' % (s_, _man[addr]))
for addr, syms in sorted(want.items()):   # converted analogs define func_<addr>: every fn_<addr> spelling resolves to it
    if 'func_%08x' % addr in defined:
        for s_ in syms:
            if s_ != 'func_%08x' % addr and not any(l.startswith(s_ + '=') for l in lines):
                lines.append('%s=func_%08x' % (s_, addr))
# merge with the previous file: the plain link already applies it, so aliased helpers stop showing as unresolved
_prev = {}
try:
    for _l in (H / 'aliases_auto.txt').read_text().splitlines():
        if '=' in _l and not _l.startswith('#'):
            _k, _v = _l.split('=', 1)
            if _v in defined:
                _prev[_k] = _v
except OSError:
    pass
for _k in list(_prev):   # older aliases of an address that now has a linked exact object go to that object
    _m = re.search(r'_([0-9a-f]{8})(?:@@|@|$)', _k)
    if _m and int(_m.group(1), 16) in _exact and _k != 'func_' + _m.group(1):
        _prev[_k] = 'func_' + _m.group(1)
_prev.update(dict(_l.split('=', 1) for _l in lines))
lines = ['%s=%s' % kv for kv in sorted(_prev.items())]
(H / 'aliases_auto.txt').write_text('# generated by auto_aliases.py\n' + '\n'.join(lines) + '\n')
print('%d aliases for %d helper addresses (%d unresolved helper symbols, %d had no draft object)' % (
    len(lines), len(want), sum(len(v) for v in want.values()), sum(1 for a in want if a not in obj_for)))
