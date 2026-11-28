"""python native_data.py: original data address -> native global symbol, from native declarations that name the address
('namespace RBX { extern int renderMode; }   // 00942ec4', 'extern bool shadowsEnabled;   // 0096de64'). Exact objects
read such globals as dat_<addr> placeholders while native code writes the named global (renderMode stayed 2 ->
"Invalid factory type"); renamed_link.py aliases dat_<addr> to the native symbol. Only names exactly one defined
symbol matches. Writes renamed/native_data.json {addr: symbol}. Seconds."""
import json, re
from pathlib import Path
EXTRA_INPUTS = ['link/obj_ext_cache.pkl', 'renamed/data_overrides.json']
OUTPUTS = ['renamed/native_data.json', 'renamed/native_data_sizes.json']
# skip when no native source / input changed since the last run (stat of ~3.6k files: well under a second)
import os as _os0, json as _j0
_ins = [p for d in ('rebuild/2008-06/native-classes', 'rebuild/2008-06/native-findings', 'rebuild/2008-06/native-findings-new', 'rebuild/2008-06/native-findings-mew')
        for p in (Path(__file__).parents[2] / d).glob('*.cpp')] + [Path(__file__).parent / x for x in EXTRA_INPUTS]
_sig = '%d:%.0f' % (len(_ins), max((p.stat().st_mtime for p in _ins if p.exists()), default=0))
_sf = Path(__file__).parent / ('renamed/.%s.sig' % Path(__file__).stem)
if _sf.exists() and _sf.read_text() == _sig and all((Path(__file__).parent / o).exists() for o in OUTPUTS):
    print('%s: inputs unchanged, outputs kept' % Path(__file__).name); raise SystemExit(0)
H = Path(__file__).parent
ROOT = H.parents[1]
import time as _T
_T0 = _T.time()
_tm = (lambda l: print('  [nd %5.1fs] %s' % (_T.time() - _T0, l))) if _os0.environ.get('ND_TIMING') else (lambda l: None)
D = [d for d in json.load(open(H / 'renamed/defined.json')) if not d.startswith(('func_', 'dat_', '??_', '?$'))]
idx = {}
for d in D:   # ?name@NS@@3... (variable) / _name (C)
    m = re.match(r'^\?([A-Za-z_]\w*)@(?:[\w@]*?@)?@?[23]', d) or re.match(r'^_([A-Za-z_]\w*)$', d)
    if m:
        idx.setdefault(m.group(1), set()).add(d)
DECL = re.compile(r'\bextern\s+(?:"C"\s+)?[\w:<>\s\*&]+?\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\])?\s*;[^/\n]*(?:\}\s*)?//\s*(?:0x)?([0-9a-fA-F]{8})\b')
out, amb = {}, 0
for d in ('native-classes', 'native-headers'):
    for f in (ROOT / 'rebuild/2008-06' / d).rglob('*.[ch]*'):
        for m in DECL.finditer(f.read_text(errors='replace')):
            name, addr = m.group(1), m.group(2).lower()
            if not (0x800000 <= int(addr, 16) < 0x9a0000):
                continue
            c = idx.get(name, set())
            if len(c) == 1:
                s = next(iter(c))
                if out.get(addr, s) != s:
                    amb += 1
                out[addr] = s
            elif c:
                amb += 1
_tm('decl scan')
# (2) dynamically-initialised globals: the original ??__E<name> initializer constructs the object at its start address
#     (mov ecx, start; call ctor). dat_<start> is that object (static signal/property descriptors read as dat_ stayed
#     unconstructed: a SignalDescriptor with a NULL vptr)
import struct
import pefile
img = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
Dset = set(json.load(open(H / 'renamed/defined.json')))
_by3 = {}   # '?name@@3...' indexed by name: a scan of all 271k names per initializer took ~14 s
for d in Dset:
    if d.startswith('?') and '@@3' in d:
        _by3.setdefault(d[1:d.index('@@3')], []).append(d)
n2 = 0
for a, row in json.load(open(ROOT / 'work/native-client/layout/function-files.json')).items():
    nm = (row or {}).get('name') or ''
    m = re.match(r'^\?\?__E(.+)@@YAXXZ$', nm)
    if not m:
        continue
    inner = m.group(1)
    cands = [inner] if inner.startswith('?') else ['_' + inner] + sorted(_by3.get(inner, ()))
    sym = next((c for c in cands if c in Dset), None)
    if not sym:
        continue
    o = int(a, 16) - 0x400000
    for k in range(o, o + 48):
        if img[k] == 0xb9:
            st = struct.unpack_from('<I', img, k + 1)[0]
            if 0x800000 <= st < 0x9a0000 and '%08x' % st not in out:
                out['%08x' % st] = sym; n2 += 1
            break
_tm('dyn init')
print('%d more from dynamic initializers' % n2)
# (3) unnamed initializers of reflection descriptors (func_007d6520: mov ecx, 0097a88c; push "LightingChanged"): the
#     native static with that member name (?event_LightingChanged@Lighting@RBX@@2V...) when exactly one exists
byname = {}
for d in Dset:
    m = re.match(r'^\?(?:event|prop|func|desc|sig|callback)_(\w+?)@(\w+)@.*@@[23]', d)
    if m:
        byname.setdefault(m.group(1), set()).add(d)
n3 = 0
lo, hi = 0x7c0000, 0x800000   # static-initializer region (??__E functions sit at the end of .text)
def cstr(va):
    o = va - 0x400000
    if not (0 <= o < len(img)):
        return None
    e = img.find(b'\0', o, o + 64)
    s = bytes(img[o:e]) if e > o else b''
    return s.decode('latin-1') if s and all(32 < c < 127 for c in s) else None
o = lo - 0x400000
while o < hi - 0x400000 - 5:
    if img[o] == 0xb9:
        st = struct.unpack_from('<I', img, o + 1)[0]
        if 0x900000 <= st < 0x9a0000 and '%08x' % st not in out:
            lits = []
            for k in range(o - 48, o + 48):   # string literals pushed around the ctor call
                if img[k] == 0x68:
                    s_ = cstr(struct.unpack_from('<I', img, k + 1)[0])
                    if s_:
                        lits.append(s_)
            c = set()
            for s_ in lits:
                c |= byname.get(s_, set())
            if len(c) == 1:
                out['%08x' % st] = next(iter(c)); n3 += 1
    o += 1
_tm('literals')
print('%d more from descriptor initializer literals' % n3)
# (4) the address in the comment line(s) right above a declaration or definition
#     ('// 00962da8: the 2D text font ...' / 'Ogre::SharedPtr<Ogre::RbxFont> font2d;')
ADDR_C = re.compile(r'^\s*//\s*(?:0x)?([0-9a-fA-F]{8})\s*:')
VAR = re.compile(r'^\s*(?:extern\s+)?(?:static\s+)?[\w:]+(?:<[^;()]*>)?[\s\*&]+((?:[A-Za-z_]\w*::)*[A-Za-z_]\w*)\s*(?:\[[^\]]*\])?\s*;')
n4 = 0
for d in ('native-classes', 'native-headers'):
    for f in (ROOT / 'rebuild/2008-06' / d).rglob('*.[ch]*'):
        lines = f.read_text(errors='replace').splitlines()
        for i, l in enumerate(lines):
            m = ADDR_C.match(l)
            if not m or not (0x800000 <= int(m.group(1), 16) < 0x9a0000) or m.group(1).lower() in out:
                continue
            for l2 in lines[i + 1:i + 6]:
                if l2.strip().startswith('//'):
                    continue
                v = VAR.match(l2)
                if v:
                    _parts = v.group(1).split('::')   # Log::provider: plain name + qualifiers ('@Log@' in the decorated name)
                    c = {x for x in idx.get(_parts[-1], set()) if all('@%s@' % q in x for q in _parts[:-1])}
                    if len(c) == 1:
                        out[m.group(1).lower()] = next(iter(c)); n4 += 1
                break
_tm('comments')
print('%d more from comments above declarations' % n4)
try:   # hand-verified library globals the registry labels wrongly (0097f2ec is ATL::g_strmgr, not XTP's m_strINIFileName)
    out.update(json.loads((H / 'renamed/data_overrides.json').read_text()))
except Exception:
    pass
(H / 'renamed/native_data.json').write_text(json.dumps(out, indent=0, sort_keys=True))
print('%d data addresses named from native declarations (%d ambiguous)' % (len(out), amb))
# symbol sizes of these globals (next symbol in the same section, or the section end): rename.py binds a dat_<addr>
# inside one (font2d pRep 00962dac -> font2d+4) only within that size
import os, pickle as _pk, struct as _st
_want = set(json.loads((H / 'renamed/native_data.json').read_text()).values())
_sizes = {}
_cf = H / 'renamed/nd_size_cache.pkl'   # per object (mtime, size) -> {data symbol: size}: the scan took ~55 s every run
try:
    _cache = _pk.load(open(_cf, 'rb'))
except Exception:
    _cache = {}
from shardcache import ShardCache as _SCn
for _p in _SCn(H / 'link/obj_ext_cache.pkl'):
    if not os.path.exists(_p) or 'renamed' + os.sep + 'obj' in os.path.normpath(_p):
        continue
    _stt = os.stat(_p)
    _c = _cache.get(_p)
    if _c and _c[0] == (_stt.st_mtime, _stt.st_size):
        for nm, z in _c[1].items():
            if nm in _want:
                _sizes[nm] = max(_sizes.get(nm, 0), z)
        continue
    _b = open(_p, 'rb').read()
    _mine = {}
    _cache[_p] = ((_stt.st_mtime, _stt.st_size), _mine)
    if b'@@3' not in _b:
        continue
    _, _ns, _, _sp, _n, _opt, _ = _st.unpack_from('<HHIIIHH', _b, 0)
    _str = _sp + _n * 18
    _secsz = [_st.unpack_from('<I', _b, 20 + _opt + 40 * k + 16)[0] for k in range(_ns)]
    _syms, i = [], 0
    while i < _n:
        raw, val, sec, typ, cls, aux = _st.unpack_from('<8sIHHBB', _b, _sp + 18 * i)
        sec = sec - 0x10000 if sec >= 0xFFFE else sec   # unsigned section number; -1 abs / -2 debug stay special
        nm = _b[_str + _st.unpack_from('<I', raw, 4)[0]:].split(b'\0', 1)[0] if raw[:4] == b'\0\0\0\0' else raw.rstrip(b'\0')
        if sec > 0:
            _syms.append((sec, val, nm.decode('latin-1'), cls))
        i += 1 + aux
    for sec, val, nm, cls in _syms:
        if cls == 2 and '@@3' in nm:   # every global data symbol (cache stays valid when native_data.json grows)
            nxt = [v for s_, v, n_, c_ in _syms if s_ == sec and v > val]
            _mine[nm] = (min(nxt) if nxt else _secsz[sec - 1]) - val
            if nm in _want:
                _sizes[nm] = max(_sizes.get(nm, 0), _mine[nm])
_pk.dump(_cache, open(_cf, 'wb'), protocol=4)
_tm('sizes')
(H / 'renamed/native_data_sizes.json').write_text(json.dumps(_sizes))
print('%d native global sizes' % len(_sizes))
_sf.write_text(_sig)
