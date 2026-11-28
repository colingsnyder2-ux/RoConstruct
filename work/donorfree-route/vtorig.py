"""python vtorig.py [--all]: linkexp/vt_orig.obj -- the ORIGINAL exe's vtables for classes whose linked vtable has a
shifted layout (vtaudit.py: our slots hold methods the original has at other indexes; e.g. stock Ogre 1.4.5 headers vs
Roblox's rgmain build: SceneNode lacks 2 virtuals, so RbxSceneManager's nodes dispatched to the wrong method and
AdornRbxGfx's ctor returned to ffffffff). Each vtable is a COMDAT-any section with the original slots relocated to our
symbols (make_stubs.data_relocs) plus the RTTI locator slot; quicktest.py links this object FIRST, so it wins over both
converted and native copies (COMDAT: first definition wins). Default: Ogre classes (rgmain.dll dispatches through them)
plus renamed/vt_origcopy.json; --all: every shifted vtable. Env VTORIG_MIN_SHIFT (default 2)."""
import json, pickle, re, struct, sys
from pathlib import Path
H = Path(__file__).parent
sys.path.insert(0, str(H))
import make_stubs as ms
import pefile as _pfv
_oi9v = _pfv.PE(str(Path(__file__).resolve().parents[2] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()

aud = json.loads((H / 'auto/vtaudit.json').read_text())
import os
mins = int(os.environ.get('VTORIG_MIN_SHIFT', '2'))
names = {n for n, v in aud.items() if v.get('shifted', 0) >= mins and ('--all' in sys.argv or '@Ogre@@' in n)}
try:   # sticky: once fixed by vt_orig a class no longer audits as shifted -- it must stay in
    names |= set(json.loads((H / 'renamed/vt_orig_names.json').read_text()))
except (OSError, ValueError):
    pass
if (H / 'renamed/vt_origcopy.json').exists():
    names |= set(json.loads((H / 'renamed/vt_origcopy.json').read_text()))
_, vo = pickle.load(open(H / 'auto/orig_vt.pkl', 'rb'))
orig = {'??_7' + c[4:] + '6B@': v for (c, off), v in vo.items() if off == 0 and c.startswith(('.?AV', '.?AU'))}
mapped = set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        mapped.add(p[1])
items = []   # (name, slot names list, col name or None)
# a name's subobject comes from OUR RTTI locator: MSVC names ??_7X@@6B@ after X's own new virtuals, which need not be
# offset 0 -- native SoundService's ??_7..@@6B@ is the Listener subobject at 0x130, and filling it with the original's
# offset-0 table made RunService call a `ret` no-op as onEvent (stack skew, heartbeat crash at 9 s)
try:
    import pefile as _pf0
    _q0 = _pf0.PE(str(H / 'run/RobloxQT.exe'), fast_load=True)
    _qi0 = _q0.get_memory_mapped_image(); _qb0 = _q0.OPTIONAL_HEADER.ImageBase
    _col0 = {}
    _other_offs = {}
    for l in open(H / 'linkexp/qt.map', errors='replace'):
        p = l.split()
        # only a NATIVE object's locator: a converted analog's COMDAT COL describes the analog's invented layout
        # (XItem<string> mapped to a 1-slot secondary table -> property grid called into RTTI data)
        if (len(p) >= 4 and p[1].startswith('??_R4') and '@@6B' in p[1] and not re.fullmatch(r'(?:ca_)?[0-9a-f]{8}\.obj', p[-1])
                and 'stubs' not in p[-1] and p[-1] != 'vt_orig.obj'):
            if p[1].endswith('@@6B@'):
                _col0.setdefault(p[1], int(p[2], 16))
            else:
                _va_r4 = int(p[2], 16)
                _cls_r4 = p[1][5:p[1].index('@@6B') + 2]
                _other_offs.setdefault(_cls_r4, set()).add(struct.unpack_from('<I', _qi0, _va_r4 - _qb0 + 4)[0])
except Exception:
    _col0, _other_offs = {}, {}
_vo_by_cls = {}
for (_vc, _voff), _vv in vo.items():
    if _vc.startswith(('.?AV', '.?AU')):
        _vo_by_cls.setdefault(_vc[4:], {})[_voff] = _vv
_nfix0 = 0
_nfix_rem = 0
_remapped = set()
_force = json.loads(Path(os.environ['VTORIG_FORCE']).read_text()) if os.environ.get('VTORIG_FORCE') else {}
names = set(names) | set(_force)
orig.update({n_: None for n_ in _force if n_ not in orig})
for n in sorted(names):
    if n not in orig:
        continue
    va, slots = (orig[n][0], orig[n][1]) if orig[n] else (None, [])
    _c0 = _col0.get('??_R4' + n[4:])
    if n in _force:   # authoritative table address (registry name, or native-ctor COL offset): auto/vt_force.json
        _fv = int(_force[n], 16)
        _ft = next(((va_, sl_) for (c_, o_), (va_, sl_) in vo.items() if va_ == _fv), None)
        if _ft:
            va, slots = _ft; _remapped.add(n)
        _c0 = None
    _remapped_this = False
    if _c0:
        _off0 = struct.unpack_from('<I', _qi0, _c0 - _qb0 + 4)[0]
        _cls0 = '.?AV' + n[4:-3]
        _ov0 = vo.get((_cls0, _off0)) or vo.get(('.?AU' + _cls0[4:], _off0))
        if _off0 and _ov0:
            va, slots = _ov0[0], _ov0[1]; _nfix0 += 1; _remapped.add(n); _remapped_this = True
    if not _remapped_this and n not in _force and n.endswith('@@6B@'):
        _cls_k = n[4:-3]
        _ooffs = _other_offs.get(_cls_k)
        if _ooffs and 0 in _ooffs:
            _rem = [o_ for o_ in _vo_by_cls.get(_cls_k, {}) if o_ not in _ooffs]
            if len(_rem) == 1:
                va, slots = _vo_by_cls[_cls_k][_rem[0]]; _nfix_rem += 1; _remapped.add(n)
    if va is None:
        continue
    rel = dict(ms.data_relocs(va, 4 * len(slots)))
    col = '??_R4' + n[4:]
    if col not in mapped:   # no locator of ours: the ORIGINAL one as a dat_ copy (null [-1] -> dynamic_cast threw
        # __non_rtti_object on PropDescriptor<PartInstance,CoordinateFrame> in CPropGrid::rebuild; 35 tables)
        _c4 = struct.unpack_from('<I', _oi9v, va - 0x400000 - 4)[0]
        col = 'dat_%08x' % _c4 if 0x7c0000 <= _c4 < 0x9a0000 else None
    items.append((n, [rel.get(4 * i) for i in range(len(slots))], col))

print('primary-named vtables matched by our COL offset (not 0): %d, by remaining-subobject: %d' % (_nfix0, _nfix_rem))

# EVERY Ogre vtable our link compiles locally -- secondary subobject tables (??_7X@@6BBase@@) and the "local vftables"
# (??_SX@@6B...) native code emits for dllimport classes -- not just primaries: the stock-header ??_SCamera@Ogre@@
# 6BShadowCaster@1@@ shifted slots, so a camera's near-clip getter returned 0 -> Frustum::setNearClipDistance(0) threw
# on File->New. Match each table to the original by (class, subobject offset): our own RTTI locator (??_R4 + the same
# suffix) holds that offset.
try:
    import pefile as _pf
    _q = _pf.PE(str(H / 'run/RobloxQT.exe'), fast_load=True)
    _qi = _q.get_memory_mapped_image(); _qb = _q.OPTIONAL_HEADER.ImageBase
    _qa = {}
    for l in open(H / 'linkexp/qt.map', errors='replace'):
        p = l.split()
        if len(p) >= 4 and ':' in p[0]:
            try:
                _qa.setdefault(p[1], int(p[2], 16))
            except ValueError:
                pass
    _have = {n for n, _, _ in items}
    _nsub = 0
    for n in sorted(_qa):
        if not (n.startswith(('??_7', '??_S')) and ('@Ogre@@6B' in n or ('--all' in sys.argv and '@@6B' in n))) or n in _have:
            continue
        suffix = n[4:]
        col = '??_R4' + suffix
        if col not in _qa:
            continue
        off = struct.unpack_from('<I', _qi, _qa[col] - _qb + 4)[0]
        cls = '.?AV' + suffix[:suffix.index('@@6B') + 2]
        ov = vo.get((cls, off)) or vo.get(('.?AU' + cls[4:], off))
        if not ov:
            continue
        va, slots = ov[0], ov[1]
        rel = dict(ms.data_relocs(va, 4 * len(slots)))
        items.append((n, [rel.get(4 * i) for i in range(len(slots))], col))
        _nsub += 1
    print('Ogre secondary/local vtables replaced by the original (class, offset) table: %d' % _nsub)
    # Also emit any stubbed RBX secondary vtables (e.g. Accoutrement, FactoryProduct<Hat>, StockSound)
    # whose class exists in orig_vt.pkl, so dynamic_cast never sees NULL vtable[-1] (Insert Object crash).
    _inst_offs = {
        '?$GuidItem@VInstance@RBX@@@': 0, '?$AbstractFactoryProduct@VInstance@RBX@@@': 16,
        '?$Described@VInstance@RBX@@': 20, 'Debugable@': 32,
        '?$Notifier@VInstance@RBX@@UChildAdded@2@@': 36, '?$Notifier@VInstance@RBX@@UChildRemoved@2@@': 68,
        '?$Notifier@VInstance@RBX@@UDescendantAdded@2@@': 100, '?$Notifier@VInstance@RBX@@UDescendantRemoving@2@@': 132,
        '?$Notifier@VInstance@RBX@@UAncestorChanged@2@@': 164, '?$Notifier@VInstance@RBX@@VPropertyChanged@2@@': 196,
        'IEquipable@': 304, 'IRenderable@': 320, 'ILocation@': 456, 'ICameraSubject@': 464,
    }
    _have = {n for n, _, _ in items}
    _nstubvt = 0
    for l in open(H / 'linkexp/qt.map', errors='replace'):
        p = l.split()
        if len(p) < 4 or 'stubs' not in p[-1] or not p[1].startswith('??_7') or '@@6B' not in p[1] or p[1] in _have:
            continue
        n = p[1]
        suffix = n[4:]
        bidx = suffix.index('@@6B')
        cls = '.?AV' + suffix[:bidx + 2]
        sub = suffix[bidx + 4:]
        col = '??_R4' + suffix
        off = None
        if col in _qa and _qa[col] >= _qb:
            off = struct.unpack_from('<I', _qi, _qa[col] - _qb + 4)[0]
        else:
            for sk, so in _inst_offs.items():
                if sub.startswith(sk):
                    off = so; break
        if off is None:
            continue
        ov = vo.get((cls, off)) or vo.get(('.?AU' + cls[4:], off))
        if not ov:
            continue
        va, slots = ov[0], ov[1]
        rel = dict(ms.data_relocs(va, 4 * len(slots)))
        if col not in mapped:
            _c4 = struct.unpack_from('<I', _oi9v, va - 0x400000 - 4)[0]
            col = 'dat_%08x' % _c4 if 0x7c0000 <= _c4 < 0x9a0000 else None
        items.append((n, [rel.get(4 * i) for i in range(len(slots))], col))
        _have.add(n); _nstubvt += 1
    if _nstubvt:
        print('Stubbed RBX secondary vtables emitted from original: %d' % _nstubvt)
except Exception as _e:
    print('secondary vtable pass skipped:', _e)

if os.environ.get('VTORIG_DAT'):
    # dat_<X> placeholders that ARE original vtables (1310): a data copy has the slots but no RTTI locator at [-1], so
    # dynamic_cast on such objects (Insert Object's shared_dynamic_cast<Instance>) read garbage. Emit each as a real
    # table: original slots + our link's COL for the same (class, subobject offset).
    _vb = {va_: (c_, o_, sl_) for (c_, o_), (va_, sl_) in vo.items()}
    import pefile as _pf9
    _oi9 = _pf9.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
    _colby = {}
    for l in open(H / 'linkexp/qt.map', errors='replace'):
        p = l.split()
        if len(p) >= 4 and p[1].startswith('??_R4') and 'stubs' not in p[-1]:
            try:
                a_ = int(p[2], 16)
                m_ = re.match(r'^\?\?_R4(.+?@@)6B', p[1])
                if m_ and a_:
                    _colby.setdefault(('.?AV' + m_.group(1), struct.unpack_from('<I', _qi0, a_ - _qb0 + 4)[0]), p[1])
            except (ValueError, struct.error):
                pass
    items, _ncol = [], 0
    for l in open(H / 'linkexp/qt.map', errors='replace'):
        p = l.split()
        if len(p) >= 4 and 'stubs' in p[-1] and re.fullmatch(r'dat_[0-9a-f]{8}', p[1]) and int(p[1][4:], 16) in _vb:
            c_, o_, sl_ = _vb[int(p[1][4:], 16)]
            rel = dict(ms.data_relocs(int(p[1][4:], 16), 4 * len(sl_)))
            col = _colby.get((c_, o_)) or _colby.get(('.?AV' + c_[4:], o_))
            _ncol += bool(col)
            if not col:   # the ORIGINAL locator, as a dat_ copy (its type descriptor / hierarchy relocated to dat_ copies)
                _c4 = struct.unpack_from('<I', _oi9, int(p[1][4:], 16) - 0x400000 - 4)[0]
                col = 'dat_%08x' % _c4 if 0x7c0000 <= _c4 < 0x9a0000 else None
            items.append((p[1], [rel.get(4 * i) for i in range(len(sl_))], col))
    print('dat_ vtable placeholders emitted as tables: %d (with our COL: %d)' % (len(items), _ncol))
elif os.environ.get('VTORIG_ONLY_REMAP'):   # emit only the COL-remapped tables (linked ahead of a validated vt_orig.obj)
    _okf = os.environ.get('VTORIG_REMAP_OK')   # JSON list: remaps validated as Listener-interface tables (slot 0 = on*)
    _ok = set(json.loads(Path(_okf).read_text())) if _okf else _remapped
    items = [it for it in items if it[0] in _remapped and it[0] in _ok]
# COFF: one .rdata COMDAT section per vtable: [COL ptr][slot 0..n-1], symbol at offset 4
secs, syms, ext = [], [], {}
for k, (n, sl, col) in enumerate(items):
    relocs = ([(0, col)] if col else []) + [(4 + 4 * i, s) for i, s in enumerate(sl) if s]
    secs.append((bytes(4 + 4 * len(sl)), relocs))
sym_index = {}
table = []   # (name, value, secnum, type, class, aux bytes or None)
for k, (n, sl, col) in enumerate(items):
    size = 4 + 4 * len(sl)
    aux = struct.pack('<IHHIHB3s', size, len(secs[k][1]), 0, 0, 0, 2, b'')   # selection 2 = IMAGE_COMDAT_SELECT_ANY
    table.append(('.rdata', 0, k + 1, 0, 3, aux))
    table.append((n, 4, k + 1, 0, 2, None))
for k, (_, relocs) in enumerate(secs):
    for _, t in relocs:
        if t not in ext:
            ext[t] = None
defined = {}
idx = 0
for e in table:
    defined.setdefault(e[0], idx) if e[4] == 2 else None
    idx += 1 + (1 if e[5] else 0)
for t in ext:
    if t not in defined:
        defined[t] = idx
        table.append((t, 0, 0, 0, 2, None))
        idx += 1
nsec = len(secs)
hdr = 20 + 40 * nsec
raw, sh, ptr = bytearray(), bytearray(), hdr
relblob = bytearray()
layout = []
for data, relocs in secs:
    layout.append((ptr + len(raw), len(data)))
    raw += data
rel_base = hdr + len(raw)
for k, (data, relocs) in enumerate(secs):
    rp = rel_base + len(relblob)
    for off, t in relocs:
        relblob += struct.pack('<IIH', off, defined[t], 6)   # IMAGE_REL_I386_DIR32
    sh += struct.pack('<8sIIIIIIHHI', b'.rdata', 0, 0, len(data), layout[k][0], rp if relocs else 0, 0, len(relocs), 0,
                      0x40301040)   # initialized data, COMDAT (0x1000), 4-byte align, read
sym_ptr = rel_base + len(relblob)
st, strtab = bytearray(), bytearray(4)
for name, val, sec, typ, cls, aux in table:
    nb = name.encode('latin-1')
    rawn = nb.ljust(8, b'\0') if len(nb) <= 8 else struct.pack('<II', 0, len(strtab))
    if len(nb) > 8:
        strtab += nb + b'\0'
    st += rawn + struct.pack('<IhHBB', val, sec, typ, cls, 1 if aux else 0)
    if aux:
        st += aux.ljust(18, b'\0')
struct.pack_into('<I', strtab, 0, len(strtab))
out = struct.pack('<HHIIIHH', 0x14c, nsec, 0, sym_ptr, idx, 0, 0) + sh + raw + relblob + st + strtab
_vout = os.environ.get('VTORIG_OUT')   # a variant's own object: the base vt_orig.obj and sticky name list stay untouched
(Path(_vout) if _vout else H / 'linkexp/vt_orig.obj').write_bytes(out)
if not _vout:
    (H / 'renamed/vt_orig_names.json').write_text(json.dumps([n for n, _, _ in items]))   # vt_strip.py drops converted copies of these
nslots = sum(len(sl) for _, sl, _ in items)
print('vt_orig.obj: %d original vtables (%d slots, %d unresolved -> null), linked first' %
      (len(items), nslots, sum(1 for _, sl, _ in items for s in sl if not s)))
print('  ' + ', '.join(n[4:40] for n, _, _ in items[:12]))
