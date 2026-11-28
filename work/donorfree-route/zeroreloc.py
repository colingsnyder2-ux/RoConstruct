"""python zeroreloc.py: converted relocations on immediates that are 0 in the original (converter paired `mov [eax], 0`
with a vtable: RCP<TextureProxy>() 005410b0 stored Ogre::RenderableListener's vtable, MegaTextureProxy::resolve then
InterlockedDecrement'ed it). Writes auto/relocsplit_extra.json rows retargeting them to __roc_abs_zero (absolute 0,
linkexp/abszero.obj) and builds that object. relocsplit.py merges the rows."""
import json, re, struct
from pathlib import Path
import pefile
H = Path(__file__).parent
_pe = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe')); img = _pe.get_memory_mapped_image(); B = 0x400000
iat = {s_.address for d_ in _pe.DIRECTORY_ENTRY_IMPORT for s_ in d_.imports}
thunk = set()   # names our link resolves to a DLL import THUNK (code), not data
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and p[0].startswith('0001:') and re.search(r'^\w+:\w+\.dll$', p[-1], re.I) and not p[1].startswith('__imp_'):
        thunk.add(p[1])
dllthunk = {n for n in thunk if re.match(r'^\?[A-Za-z_]\w*(@\w+)*@@[0-3]', n) or n.startswith(('??_7', '??_R'))}
RR = json.loads((H / 'renamed/rename.json').read_text())
regname = {int(k, 16): (v or {}).get('name') for k, v in json.load(open(H.parents[0] / '2008-06/identity-registry.json')).items() if re.fullmatch(r'[0-9a-f]{8}', k)}
mapdefs = set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0] and 'stubs' not in p[-1]:
        mapdefs.add(p[1])
rows = {}
import glob
objs = sorted(Path(f).stem for f in glob.glob(str(H / 'renamed/obj/*.obj')) if re.fullmatch(r'[0-9a-f]{8}', Path(f).stem))
import pickle
CF = H / 'auto/zeroreloc_cache.pkl'
try:
    cache = pickle.load(open(CF, 'rb'))
except Exception:
    cache = {}


def candidates(X):
    """[(section, reloc index, symbol, original dword)] for DIR32 relocations with a zero stored addend in X's main body."""
    out = []
    d = (H / 'renamed/obj' / (X + '.obj')).read_bytes(); x = int(X, 16)
    _, nsec, _, sp, ns, opt, _ = struct.unpack_from('<HHIIIHH', d, 0); st = sp + 18 * ns
    def name(k):
        raw = d[sp + 18 * k: sp + 18 * k + 8]
        if raw[:4] == bytes(4):
            o_ = st + struct.unpack_from('<I', raw, 4)[0]
            return d[o_:d.index(0, o_)].decode('latin-1')
        return raw.rstrip(b'\0').decode('latin-1')
    # (not done: retargeting every code relocation to DLL data -> __imp_S. Most such sites are header-inline COMDATs of
    # the analog TUs compiled WITHOUT dllimport (fld [X], mov eax, offset X): __imp_X would load the IAT slot as the value.
    # Only original-verified IAT reads below qualify.)
    main = {'func_' + X, (RR.get(X) or {}).get('symbol')}
    k, msec = 0, None
    while k < ns:
        if name(k) in main and struct.unpack_from('<h', d, sp + 18 * k + 12)[0] > 0:
            msec = struct.unpack_from('<h', d, sp + 18 * k + 12)[0] - 1; mval = struct.unpack_from('<I', d, sp + 18 * k + 8)[0]
        k += 1 + d[sp + 18 * k + 17]
    if msec is None:
        return out
    sh = 20 + opt + 40 * msec; raw_ptr, rel_ptr = struct.unpack_from('<II', d, sh + 20)
    for r in range(struct.unpack_from('<H', d, sh + 32)[0]):
        ro, ri, rt = struct.unpack_from('<IIH', d, rel_ptr + 10 * r)
        off = ro - mval
        if rt != 6 or struct.unpack_from('<I', d, raw_ptr + ro)[0] != 0 or not 0 <= x - B + off < len(img) - 4:
            continue
        ov = struct.unpack_from('<I', img, x - B + off)[0]
        out.append((msec, r, name(ri), ov))
    return out


for X in objs:
    f = H / 'renamed/obj' / (X + '.obj'); st_ = f.stat(); key = (st_.st_mtime_ns, st_.st_size)
    c = cache.get(X)
    if not c or c[0] != key:
        c = cache[X] = (key, candidates(X))
    for msec, r, n_, ov in c[1]:
        if ov == 0:
            rows.setdefault(X + '.obj', []).append([msec, r, n_, '__roc_abs_zero', 0])
        elif ov in iat and n_ in thunk:   # original read the IAT slot: use __imp_S, not lld's jmp thunk
            rows.setdefault(X + '.obj', []).append([msec, r, n_, '__imp_' + n_, 0])
        elif n_.startswith('__TI') and (regname.get(ov) or '').startswith('__TI') and regname[ov] != n_ and regname[ov] in mapdefs:
            # analog ThrowInfo (__TI1?AUException@@) where the original threw runtime_error: catch(std::exception&) missed it
            rows.setdefault(X + '.obj', []).append([msec, r, n_, regname[ov], 0])
pickle.dump(cache, open(CF, 'wb'))
json.dump(rows, open(H / 'auto/relocsplit_extra.json', 'w'))
nm = b'__roc_abs_zero'
obj = struct.pack('<HHIIIHH', 0x14c, 0, 0, 20, 1, 0, 0) + struct.pack('<II', 0, 4) + struct.pack('<IhHBB', 0, -1, 0, 2, 0) \
    + struct.pack('<I', 4 + len(nm) + 1) + nm + b'\0'
(H / 'linkexp/abszero.obj').write_bytes(obj)
print('zeroreloc: retargeted %d (zero %d, IAT %d, ThrowInfo %d) in %d objects' % (sum(map(len, rows.values())), sum(1 for v in rows.values() for r_ in v if r_[3] == '__roc_abs_zero'), sum(1 for v in rows.values() for r_ in v if r_[3].startswith('__imp_')), sum(1 for v in rows.values() for r_ in v if r_[3].startswith('__TI')), len(rows)))
