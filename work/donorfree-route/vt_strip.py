"""python vt_strip.py: converted exact objects (renamed/obj) carry vtable COMDATs (??_7) compiled from analog/donor headers;
native objects carry their own. Converted objects link first, so their copy wins unless stripped. Per class, score each
copy against the ORIGINAL vtable (slot target bodies, current exe) and keep the better one: strip the converted copies only
where the native copy matches at least as well. Unstripped originals in renamed/obj_full/. Idempotent, cached."""
import hashlib, json, os, pickle, re, struct, sys
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
sys.path.insert(0, str(H.parents[1]))
sys.path.insert(0, str(H))
from roc import rebuild
from origcache import orig_body
def vt_slots(data):
    """{??_7 name: [slot target symbol names]} for every vtable this object defines"""
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    names, vts, i = {}, [], 0
    while i < nsym:
        raw, value, secnum, typ, cls, naux = struct.unpack_from('<8sIHHBB', data, symptr + 18 * i)
        secnum = secnum - 0x10000 if secnum >= 0xFFFE else secnum   # unsigned section number; -1 abs / -2 debug stay special
        if raw[:4] == b'\0\0\0\0':
            s = strtab + struct.unpack_from('<I', raw, 4)[0]
            name = bytes(data[s:data.find(b'\0', s)]).decode('latin-1')
        else:
            name = raw.rstrip(b'\0').decode('latin-1')
        names[i] = name
        if cls == 2 and secnum > 0 and name.startswith('??_7'):
            vts.append((name, secnum, value))
        i += 1 + naux
    out = {}
    for name, secnum, value in vts:
        _, _, _, rawsize, rawptr, relptr, _, nrel, _, _ = struct.unpack_from('<8sIIIIIIHHI', data, 20 + optsz + 40 * (secnum - 1))
        sl = {}
        for k in range(nrel):
            off, idx, typ = struct.unpack_from('<IIH', data, relptr + 10 * k)
            if off >= value and (off - value) % 4 == 0:
                sl[(off - value) // 4] = names.get(idx, '?')
        out[name] = [sl.get(j, '') for j in range(max(sl) + 1)] if sl else []
    return out
def data_defs(data):
    """{name: size} of external DATA definitions (sections without code): globals, function-local statics, guards"""
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    out, i = {}, 0
    while i < nsym:
        raw, value, secnum, typ, cls, naux = struct.unpack_from('<8sIHHBB', data, symptr + 18 * i)
        secnum = secnum - 0x10000 if secnum >= 0xFFFE else secnum   # unsigned section number; -1 abs / -2 debug stay special
        if cls == 2 and (secnum > 0 or (secnum == 0 and value > 0)):   # defined, or a common symbol (value = size)
            if raw[:4] == b'\0\0\0\0':
                st_ = strtab + struct.unpack_from('<I', raw, 4)[0]
                name = bytes(data[st_:data.find(b'\0', st_)]).decode('latin-1')
            else:
                name = raw.rstrip(b'\0').decode('latin-1')
            if secnum > 0:
                ch = struct.unpack_from('<I', data, 20 + optsz + 40 * (secnum - 1) + 36)[0]
                size = struct.unpack_from('<I', data, 20 + optsz + 40 * (secnum - 1) + 16)[0]
                if not ch & 0x20 and not name.startswith(('??_7', '??_R', '??_C@', '__real@', '__xmm@')):
                    out[name] = size
            elif secnum == 0 and value > 0:
                out[name] = value
        i += 1 + naux
    return out


rsp = [l.strip().strip('"') for l in (H / 'link/donorfree.rsp').read_text().splitlines()]
objs = [Path(l) for l in rsp if l.lower().endswith('.obj') and 'renamed' + chr(92) + 'obj' not in l and 'renamed/obj' not in l]
cache = H / 'link/native_vt2.pkl'
try:
    c = pickle.load(open(cache, 'rb'))
except Exception:
    c = {}
native = {}
native_data = {}   # data symbol -> largest native section size
for o in objs:
    try:
        st = o.stat()
    except OSError:
        continue
    k = str(o)
    if k not in c or c[k][0] != st.st_mtime:
        _b = o.read_bytes()
        c[k] = (st.st_mtime, vt_slots(_b), data_defs(_b))
    if len(c[k]) < 3:
        _b = o.read_bytes(); c[k] = (c[k][0], c[k][1], data_defs(_b))
    for n, s in c[k][1].items():
        native.setdefault(n, s)
    for n, z in c[k][2].items():
        native_data[n] = max(native_data.get(n, 0), z)
pickle.dump(c, open(cache, 'wb'), protocol=4)
# scoring material: original vtables (vtdiff cache), our exe + map
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
MASK = re.compile(r'0x[0-9a-f]{5,8}')
def body(b, a):
    out = []
    for i in md.disasm(b[a - 0x400000:a - 0x400000 + 0x400], a):
        out.append(i.mnemonic + ' ' + MASK.sub('X', i.op_str))
        if i.mnemonic in ('ret', 'int3', 'jmp') or len(out) >= 60:
            break
    return out
try:
    bo, vo = pickle.load(open(H / 'auto/orig_vt.pkl', 'rb'))
    bn = bytes(pefile.PE(str(H / 'link/donorfree.exe')).get_memory_mapped_image())
    addr = {}
    for l in open(H / 'link/donorfree.map', errors='replace'):
        m = re.match(r'\s*0001:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})', l)
        if m:
            addr.setdefault(m.group(1), int(m.group(2), 16))
except Exception as e:
    vo, addr = {}, {}
_nb = {}
def score(name, slots):
    m = re.fullmatch(r'\?\?_7(.+)6B@', name)
    if not m:
        return None
    ov = vo.get(('.?AV' + m.group(1), 0)) or vo.get(('.?AU' + m.group(1), 0))
    if not ov:
        return None
    s = 0
    for t, sym in zip(ov[1], slots):
        a = addr.get(sym)
        if a is None:
            continue
        if a not in _nb:
            _nb[a] = body(bn, a)
        s += orig_body(body, bo, t, 'vt') == _nb[a]
    return s - 0.5 * abs(len(ov[1]) - len(slots))
full = H / 'renamed/obj_full'
full.mkdir(exist_ok=True)
sf = H / 'renamed/vt_stripped.json'
try:
    done = json.loads(sf.read_text())
except Exception:
    done = {}
conv = {}
# speed: an object whose stat still equals what we last wrote is unchanged; its parsed backup comes from the cache
# (was: read + md5 + parse 1.4 GB every run, most of renamed_link's minutes)
_ccf = H / 'renamed/vt_conv.pkl'
try:
    cc = pickle.load(open(_ccf, 'rb'))
except Exception:
    cc = {}
_st = lambda p: (p.stat().st_mtime_ns, p.stat().st_size)
for o in sorted((H / 'renamed/obj').glob('*.obj')):
    bk = full / o.name
    e = cc.get(o.name)
    if not (e and bk.exists() and e[0] == _st(o)):
        cur = o.read_bytes()
        if done.get(o.name) != hashlib.md5(cur).hexdigest() or not bk.exists():
            bk.write_bytes(cur)
        b_ = bk.read_bytes()
        e = cc[o.name] = [_st(o), vt_slots(b_), data_defs(b_), None]
    conv[o] = e[1]
best_conv = {}
for o, d in conv.items():
    for n, s in d.items():
        if n in native and (n not in best_conv or len(s) > len(best_conv[n])):
            best_conv[n] = s
_SC = {}


def _copy_score(n_, slots):
    k_ = (n_, tuple(slots))
    if k_ not in _SC:
        _SC[k_] = score(n_, slots)
    return _SC[k_]


decide, kept = {}, 0
for n, s in best_conv.items():
    sn, sc = score(n, native[n]), score(n, s)
    decide[n] = not (sn is not None and sc is not None and sc > sn)   # True: strip converted copies (native wins / unknown)
    kept += not decide[n]
import pickle as _pkr
native_rtti = set()
try:
    # only natives actually IN this link: the cache also holds objects that left it, and dropping the converted copy
    # for one of those left the name undefined -> a zero placeholder (??_R0?AUException@@@8 had no type name, so a
    # throw of that type faulted inside msvcr90's dispatcher -> the 2.4 s jump to 0)
    _linked_n = {os.path.normcase(str(o)) for o in objs}
    for _p, _v in _pkr.load(open(H / 'link/obj_ext_cache.pkl', 'rb')).items():
        if 'renamed' + chr(92) + 'obj' not in _p and 'renamed/obj' not in _p and os.path.normcase(_p) in _linked_n:
            native_rtti |= {n_ for n_, d_ in _v[2].items() if d_ and n_.startswith('??_R')}
except Exception:
    pass
orig_classes = {k[0] for k in vo}
n_inv = [0]
def _cls(n_):
    m_ = re.match(r'^\?\?_7(.+?@@)6B', n_) or re.match(r'^\?\?_R4(.+?@@)6B', n_) or re.match(r'^\?\?_R[23](.+?@@)8$', n_)         or re.match(r'^\?\?_R0\?A[VU](.+?@@)@8$', n_) or re.match(r'^\?\?_R1.+?@(\w+@@)8$', n_)
    return m_.group(1) if m_ and '?$' not in m_.group(1) else None
def _externalize(data, name):
    """the analog defined its function `static` (file-local): after renaming it is still invisible to other objects, so
    every caller linked a stub (1,214 converted objects). Flip that symbol's storage class STATIC (3) -> EXTERNAL (2)."""
    data = bytearray(data)
    _, _, _, symptr, nsym, _, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab, i, hit = symptr + nsym * 18, 0, 0
    while i < nsym:
        at = symptr + 18 * i
        raw, val, sec, typ, cls, naux = struct.unpack_from('<8sIHHBB', data, at)
        sec = sec - 0x10000 if sec >= 0xFFFE else sec   # unsigned section number; -1 abs / -2 debug stay special
        nm = (bytes(data[strtab + struct.unpack_from('<I', raw, 4)[0]:]).split(b'\0', 1)[0] if raw[:4] == b'\0\0\0\0' else raw.rstrip(b'\0'))
        if cls == 3 and sec > 0 and val == 0 and typ == 0x20 and nm.decode('latin-1') == name:
            data[at + 16] = 2; hit += 1
        i += 1 + naux
    return bytes(data), hit


try:
    _RJ = json.loads((H / 'renamed/rename.json').read_text())
    _MAINSYM = {a: (r_ or {}).get('symbol') for a, r_ in _RJ.items()}
    _RENMAP = {a: (r_ or {}).get('renamed') or {} for a, r_ in _RJ.items()}
except Exception:
    _MAINSYM, _RENMAP = {}, {}
_n_ext = [0]


def _rename(data, ren):
    """rename external symbols by name (new strings appended to the string table)"""
    data = bytearray(data)
    _, _, _, symptr, nsym, _, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    size = struct.unpack_from('<I', data, strtab)[0]
    extra, i = bytearray(), 0
    while i < nsym:
        at = symptr + 18 * i
        raw = bytes(data[at:at + 8]); naux = data[at + 17]
        if raw[:4] == b'\0\0\0\0':
            s0 = strtab + struct.unpack_from('<I', raw, 4)[0]
            nm = bytes(data[s0:data.index(b'\0', s0)]).decode('latin-1')
        else:
            nm = raw.rstrip(b'\0').decode('latin-1')
        if nm in ren:
            struct.pack_into('<II', data, at, 0, size + len(extra))
            extra += ren[nm].encode('latin-1') + b'\0'
        i += 1 + naux
    data = data[:strtab + size] + extra
    struct.pack_into('<I', data, strtab, size + len(extra))
    return bytes(data)
try:
    _mainren = json.loads((H / 'renamed/main_rename.json').read_text())
except Exception:
    _mainren = {}
try:
    _vstrip = json.loads((H / 'renamed/vendor_strip.json').read_text())
except Exception:
    _vstrip = {}
# vtables only the CONVERTED side defines whose every copy has a different slot count than the ORIGINAL exe's vtable:
# compiled from the wrong header (stock Ogre 1.4.5 SceneNode vs Roblox's rgmain build: 2 extra virtuals shift every
# slot -> RbxSceneManager::createSceneNode's nodes called the wrong method, ret to ffffffff in AdornRbxGfx's ctor).
# Drop them; quicktest.py links the original-bytes copy (relocated slots) instead, ahead of rgmain.lib's code thunk.
_lens = {}
for d_ in conv.values():
    for n_, s_ in d_.items():
        if n_ not in native and s_:
            _lens.setdefault(n_, set()).add(len(s_))
_origcopy = set()
for n_, ls_ in _lens.items():
    m_ = re.fullmatch(r'\?\?_7(.+)6B@', n_)
    ov_ = m_ and (vo.get(('.?AV' + m_.group(1), 0)) or vo.get(('.?AU' + m_.group(1), 0)))
    if ov_ and len(ov_[1]) not in ls_:
        _origcopy.add(n_)
(H / 'renamed/vt_origcopy.json').write_text(json.dumps(sorted(_origcopy), indent=0))
try:   # vtorig.py's original vtables: a converted PLAIN definition would beat its COMDAT regardless of link order
    _origcopy |= set(json.loads((H / 'renamed/vt_orig_names.json').read_text()))
except (OSError, ValueError):
    pass
print('vtables with a wrong slot count in every converted copy (original-bytes copy linked instead): %d' % len(_origcopy))
n_obj = n_vt = 0
smaller = 0
_jobs, _jobmeta = [], []
for o, d in conv.items():
    e = cc[o.name]
    drop = {n for n in d if decide.get(n) or n in _origcopy}
    _dd = e[2]
    _dn = {n for n in _dd if n in native_data}   # data the native side defines: theirs (right size/layout) must win
    smaller += sum(1 for n in _dn if _dd[n] < native_data[n])
    drop |= _dn
    # RTTI (??_R4 complete-object locators carry subobject offsets, ??_R1/2/3 class hierarchy): the converted analog's
    # copies describe the analog's guessed layout; dynamic_cast and the vtable's locator must use the native class
    if len(e) < 5:
        e.append(sorted(n_ for n_, d_ in rebuild.coff_externals((full / o.name).read_bytes()).items() if d_ and n_.startswith('??_R')))
    drop |= {n_ for n_ in e[4] if n_ in native_rtti}
    drop |= set(_vstrip.get(o.stem, ()))   # vendor-library helpers (renamed_link.py): the library's copy wins
    # a vtable copy rename.py renamed from ANOTHER class's analog vtable (Shirt's ctor analog carried VelocityMotor's
    # 6-slot render vtable as ??_7Shirt@RBX@@6B@) holds the wrong slots: the native definition must win (layout session
    # 2026-11-24: 116 objects / 86 classes, 46 copies won the link)
    # per COPY, not per name: only the longest copy was scored, and when it beat the native one every copy of that name
    # was kept, so a wrong copy could win by link order
    for n_ in d:
        if n_ in native and not decide.get(n_, True) and d[n_] != best_conv.get(n_):
            if _copy_score(n_, d[n_]) is None or _copy_score(n_, d[n_]) <= _copy_score(n_, native[n_]):
                drop.add(n_)
    # classes the ORIGINAL never had (analog-invented `Holder` for a boost::any holder): another object's unrelated
    # class of that name must not supply this vtable/RTTI -> keep this object's own copy under a unique name
    inv = set()
    for n_ in list(d) + list(e[4]):
        c_ = _cls(n_)
        if False and c_ and ('.?AV' + c_) not in orig_classes and ('.?AU' + c_) not in orig_classes:   # ponytail: off; rename.py decides with the original address
            inv.add(n_)
    drop -= inv
    ren = {n_: n_ + '_roc' + o.stem for n_ in inv}
    if o.stem in _mainren:   # renamed_link.py: excluded template instance linked only as func_<addr>
        ren[_mainren[o.stem]] = 'func_' + o.stem
        drop.discard(_mainren[o.stem])
    if drop:
        n_obj += 1; n_vt += len(drop)
    key_ = sorted(drop) + ['>' + x for x in sorted(ren)] + ['!ext']
    if e[3] == key_ and e[0] == _st(o):
        continue   # same strip as last run on an unchanged object
    # the write phase runs on a process pool (vt_pool.py): single-core it took 10+ minutes when every object changed
    _jobs.append({'full': str(full / o.name), 'out': str(o), 'drop': sorted(drop), 'ren': ren, 'main': _MAINSYM.get(o.stem)})
    _jobmeta.append((o, e, key_))
if _jobs:
    _jf = H / 'renamed/vt_jobs.json'
    _jf.write_text(json.dumps(_jobs))
    import subprocess as _sp9, sys as _sy9
    print(_sp9.run([_sy9.executable, str(H / 'vt_pool.py'), str(_jf)], capture_output=True, text=True).stdout.strip())
    _res = json.loads((H / 'renamed/vt_jobs.json.result.json').read_text())
    for o, e, key_ in _jobmeta:
        r_ = _res.get(str(o))
        if r_:
            done[o.name] = r_[0]; n_inv[0] += bool(r_[1]); _n_ext[0] += bool(r_[2])
            e[0], e[3] = _st(o), key_
sf.write_text(json.dumps(done))
pickle.dump(cc, open(_ccf, 'wb'), protocol=4)
print('static main functions made external: %d objects' % _n_ext[0])
print('data symbols also defined natively dropped from converted objects; %d of them were SMALLER than native (overflow bugs)' % smaller)
print('vtables: native %d | both copies %d -> converted copy kept (matches original better) %d, native kept %d | %d objects stripped (%d copies)'
      % (len(native), len(best_conv), kept, len(best_conv) - kept, n_obj, n_vt))
print('objects whose analog-invented classes keep their own vtable/RTTI under a unique name: %d' % n_inv[0])
