"""Route 1, no LLM: link the server's byte-exact analogs under their real names.
For each unresolved symbol with an exact analog (link/addrmap.json):
  1. compile src/2008-06/ADDR.cpp with its own '// roc-cl' / '// roc-flags'
  2. find the object function that is byte-identical to ADDR (fingerprint.Target.same)
  3. rename it to the real mangled symbol; rename every symbol its relocations reach to the real name of the
     2008 address the exe relocation points at (native_asm.label: rebuilt names, IAT, MFC thunks)
  4. keep only that one definition (strip_symbols), write link/renamed/ADDR.obj
Any relocation whose 2008 target has no known real name is a blocker; that object is not emitted.
usage: python work/native-client/rename.py [ADDR ...]   -> link/rename.json"""
import json, os, re, struct, subprocess, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[2]))
from roc import rebuild, match, native_asm, fingerprint

ROOT = rebuild.ROOT
CLIENT = '2008-06'
NC = ROOT / 'work/native-client'
WORK = NC / 'rename'
OUT = Path(os.environ['ROC_RENAME_OUT']) if os.environ.get('ROC_RENAME_OUT') else NC / 'link/renamed'
WORK.mkdir(exist_ok=True)
OUT.mkdir(parents=True, exist_ok=True)
REL32, DIR32 = 0x14, 0x06
_SC = {}
exec(open(ROOT / 'work/rbxgs-rebase/symcheck.py', encoding='utf-8').read(), _SC)


def known_symbols():
    """Every symbol some link input defines (engine + shell objects, module/vendor libs): a name the analog
    already spells this way resolves to real code as-is."""
    rsp = NC / 'link/link.rsp'
    out = set()
    for line in rsp.read_text().splitlines():
        p = Path(line.strip().strip('"'))
        if p.suffix == '.obj' and p.exists():
            out |= {n for n, k in _SC['symbols'](p.read_bytes()).items() if k != 'undef'}
        elif p.suffix == '.lib' and p.exists():
            out |= _SC['archive_symbols'](p)
    return out


def symtab(data):
    """[(index, name, secnum, cls)] and the parsed header."""
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    out, i = [], 0
    while i < nsym:
        raw, value, secnum, typ, cls, naux = struct.unpack_from('<8sIHHBB', data, symptr + 18 * i)
        secnum = secnum - 0x10000 if secnum >= 0xFFFE else secnum   # unsigned section number; -1 abs / -2 debug stay special
        if raw[:4] == b'\0\0\0\0':
            off = strtab + struct.unpack_from('<I', raw, 4)[0]
            name = data[off:data.index(b'\0', off)]
        else:
            name = raw.rstrip(b'\0')
        out.append((i, name.decode('latin-1'), secnum, cls, value))
        i += 1 + naux
    return out, (nsec, symptr, nsym, optsz, strtab)


def relocations(data, func_symbol):
    """[(offset in function, type, symbol index)] for the named function."""
    syms, (nsec, symptr, nsym, optsz, _) = symtab(data)
    s = next((x for x in syms if x[1] == func_symbol and x[2] > 0), None) or next(x for x in syms if x[1] == func_symbol)   # the definition, not an earlier reference
    if s[2] <= 0:   # the matched name is undefined/absolute in this object: no relocations to map
        return []
    sec, value = s[2] - 1, s[4]
    _, _, _, rawsize, rawptr, relptr, _, nrel, _, _ = struct.unpack_from('<8sIIIIIIHHI', data, 20 + optsz + 40 * sec)
    out = []
    for k in range(nrel):
        off, idx, typ = struct.unpack_from('<IIH', data, relptr + 10 * k)
        out.append((off - value, typ, idx, rawptr + off))
    return out


def rename(data, mapping):
    """Rename symbols by index -> new name (appended to the string table)."""
    data = bytearray(data)
    _, _, _, symptr, nsym, _, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    size = struct.unpack_from('<I', data, strtab)[0]
    extra = bytearray()
    for idx, name in mapping.items():
        struct.pack_into('<II', data, symptr + 18 * idx, 0, size + len(extra))
        extra += name.encode('latin-1') + b'\0'
    struct.pack_into('<I', data, strtab, size + len(extra))
    return bytes(data[:strtab + size] + extra + data[strtab + size:])


def vtable_name(va):
    """Single-inheritance vtable at va -> ??_7Class@@6B@ from its RTTI complete object locator."""
    base, image = match._image(CLIENT)
    rd = lambda a: struct.unpack_from('<I', image, a - base)[0] if base <= a < base + len(image) - 4 else None
    col = rd(va - 4)
    if not col or rd(col) != 0 or rd(col + 4) != 0:      # signature 0, offset 0: the primary vtable only
        return None
    td = rd(col + 12)
    if not td:
        return None
    raw = bytes(image[td + 8 - base:td + 8 - base + 200]).split(b'\0', 1)[0].decode('latin-1')
    if not raw.startswith(('.?AV', '.?AU')):
        return None
    return '??_7' + raw[4:] + '6B@'


HEADER_NAMES = {}   # addr -> mangled, from namer.py (header-declared members, compiler-decorated)
REGISTRY = {}


def load_registry():
    try:
        return json.loads((ROOT / 'work/2008-06/identity-registry.json').read_text())
    except (OSError, ValueError):
        return {}


DUPNAMES = set()   # donor-free: addresses whose registry name is shared by several addresses (identity unproved: 49 of 77
                   # create<X> labels named the wrong class) -> treated as unnamed, the call goes to func_<addr>
if os.environ.get('ROC_RENAME_DEFINED'):
    try:
        DUPNAMES = {a for a, v in json.load(open(ROOT / 'work/native-client/layout/function-files.json')).items()
                    if (v or {}).get('requires_identity_review') and (v.get('duplicate_target_name_count') or 1) > 1}
    except Exception:
        pass


def _openrbx_fallback():
    """This checkout lacks tools/openrbx/3rdparty: point the openrbx recipes at the same libraries elsewhere in tools/
    (in-process only; a header difference can only produce 'nomatch', never different accepted bytes)."""
    from roc import libs
    L = libs.LIBS
    alt = {'../openrbx/3rdparty/RakNet30/Source': '../openrbx/Client/Network/raknet30/Source',
           '../openrbx/3rdparty/boost_1_34_1': 'boost_1_34_1',
           # OpenRBX's own G3D (moved under Client/): G3D::Sky::setNumStars exists only there (252 Sky.cpp analogs)
           '../openrbx/3rdparty/g3d/source/include': '../openrbx/Client/Rendering/g3d/include',
           '../openrbx/3rdparty/lua-5.1.1/src': '../openrbx/Client/App/lua-5.1.1/src',
           '../openrbx/3rdparty/g3d/source/png': 'libpng-1.2.6',
           '../openrbx/3rdparty/g3d/source/zlib': 'zlib-1.2.3',
           '../openrbx/3rdparty/SDL-1.2.6/include': 'SDL-1.2.11/include'}
    alt = {k: v for k, v in alt.items() if not (L / k).exists() and (L / v).exists()}
    for r in libs.RECIPES.values():
        if r.get('src') in alt:
            r['src'] = alt[r['src']]
        if r.get('include'):
            r['include'] = [alt.get(i, i) for i in r['include']]


if os.environ.get('ROC_RENAME_DEFINED'):
    try:
        _openrbx_fallback()
    except Exception:
        pass


_CF = []
def _conv_failed():
    """addresses whose exact analog failed to convert (stub_exact.py cache): func_<addr> would stay a stub"""
    if not _CF:
        _CF.append(set())
        try:
            _CF[0] |= set(json.load(open(os.path.join(os.path.dirname(os.environ.get('ROC_ADDRMAP', '')), 'stub_exact_fail.json'))))
        except Exception:
            pass
    return _CF[0]


def _vec_cls(n):
    """True when a vector instance's element type is a class (size unknown), False for scalars/pointers (4/8 bytes)"""
    m = re.search(r'\?\$vector@(.)', n or '')
    return bool(m) and m.group(1) in 'VU'


def _tmpl_member(n):
    """('??0' / 'insert', '_Tree') for a member of a class template instance, else None"""
    m = re.match(r'^(\?\?[0-9A-Z_]|\?\w+@)\?\$(\w+)@', n or '')
    return m and m.groups()


def real_name(va):
    if '%08x' % va in DUPNAMES:
        return None
    _r = _real_name(va)
    if _r and os.environ.get('ROC_RENAME_DEFINED') and '@?A0x' in _r:
        return None   # anonymous-namespace (file-local) name: no other object can link to it -> func_/dat_ placeholder
    return _r


def _real_name(va):
    row = REGISTRY.get('%08x' % va)
    if row and not row.get('placeholder'):
        return row['name']
    if '%08x' % va in HEADER_NAMES:
        return HEADER_NAMES['%08x' % va]
    vt = vtable_name(va)
    if vt:
        return vt
    lab = native_asm.label(CLIENT, va)
    if not lab or lab.startswith('fn_'):
        return None
    lab = re.sub(r'^(MFC|ATL|CRT)\s+', '', lab).split()[0]
    if '!' in lab:          # IAT slot: dll!name -> the object refers to __imp_<decorated>; keep analog's own name
        return ''
    return lab


_NAME_ADDRS = None


def _name_addrs():
    """name -> set of original addresses it stands for (unique registry names, native_data, converted mains)"""
    global _NAME_ADDRS
    if _NAME_ADDRS is None:
        from collections import Counter, defaultdict
        m = defaultdict(set)
        cnt = Counter(v.get('name') for v in REGISTRY.values() if not v.get('placeholder'))
        for a, v in REGISTRY.items():
            n = v.get('name')
            if n and not v.get('placeholder') and cnt[n] == 1 and '@?A0x' not in n:
                m[n].add(int(a, 16))
        for a, n in _native_data_map().items():
            m[n].add(int(a, 16))
        try:
            for a, x in json.load(open(ROOT / 'work/donorfree-route/renamed/rename.json')).items():
                if x.get('status') == 'renamed' and x.get('symbol'):
                    m[x['symbol']].add(int(a, 16))
        except (OSError, ValueError):
            pass
        _NAME_ADDRS = m
    return _NAME_ADDRS


_IMPS = set()
_SPLITS = []   # (relocation record file offset, name) collected by _bind_validate


def _import_slots():
    """every IAT slot of the original exe (MSVCR/MFC/Win32 AND rgmain.dll's Ogre imports above 0x804000)"""
    if not _IMPS:
        try:
            import pefile
            from roc import clients
            pe = pefile.PE(str(clients.exe_path(CLIENT, clients.load()[CLIENT])), fast_load=True)
            pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
            _IMPS.update(i.address for e in pe.DIRECTORY_ENTRY_IMPORT for i in e.imports)
        except Exception:
            _IMPS.update(range(0x800000, 0x804000, 4))
    return _IMPS


def _reloc_entries(data, fsym, splits):
    """(patched-bytes file offset, name) -> (relocation RECORD file offset, name) in fsym's section"""
    syms_, (nsec, symptr, nsym, optsz, _) = symtab(data)
    s_ = next((x for x in syms_ if x[1] == fsym and x[2] > 0), None)
    if not s_:
        return []
    _, _, _, rawsize, rawptr, relptr, _, nrel, _, _ = struct.unpack_from('<8sIIIIIIHHI', data, 20 + optsz + 40 * (s_[2] - 1))
    rec = {rawptr + struct.unpack_from('<I', data, relptr + 10 * k)[0]: relptr + 10 * k for k in range(nrel)}
    return [(rec[fo], n) for fo, n in splits if fo in rec]


def _split_relocs(data, splits):
    """per-relocation targets: append one undefined external per new name (string table moved behind the new
    records) and point each listed relocation entry (file offset of its 10-byte record) at it"""
    if not splits:
        return data
    data = bytearray(data)
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    ssize = struct.unpack_from('<I', data, strtab)[0]
    strings = bytearray(data[strtab + 4:strtab + ssize])
    names = sorted({n for _, n in splits})
    idx_of, recs = {}, bytearray()
    for k, n in enumerate(names):
        nb = n.encode('latin-1')
        if len(nb) <= 8:
            raw = nb.ljust(8, bytes(1))
        else:
            raw = struct.pack('<II', 0, 4 + len(strings)); strings += nb + bytes(1)
        recs += raw + struct.pack('<IhHBB', 0, 0, 0x20 if not n.startswith('dat_') else 0, 2, 0)
        idx_of[n] = nsym + k
    out = data[:strtab] + recs + struct.pack('<I', 4 + len(strings)) + strings
    struct.pack_into('<I', out, 12, nsym + len(names))
    for ent, n in splits:
        struct.pack_into('<I', out, ent + 4, idx_of[n])
    return bytes(out)


def _bind_validate(data, fsym, syms, cls_of, va0, base, image, mapping, refs):
    """bindcheck.py inside the converter: a reference whose final name stands for a DIFFERENT original address than the
    one the original code reads at that site (sDecal for another class's name string, prop_SkyRt for another global,
    func_004d8680 called where the original calls 00446110) is rebound to that address's own name / placeholder.
    Only when every relocation of the symbol agrees on one address (otherwise one name cannot serve them all)."""
    names = _name_addrs()
    per, per_site = {}, {}
    for off, typ, idx, fo in relocations(bytes(data), fsym):
        if typ not in (DIR32, REL32) or off < 0:
            continue
        site = va0 + off
        if not (base <= site < base + len(image) - 4):
            continue
        addend = struct.unpack_from('<i', data, fo)[0]
        word = struct.unpack_from('<I', image, site - base)[0]
        va = (word - addend) if typ == DIR32 else (site + 4 + struct.unpack_from('<i', image, site - base)[0] - addend) & 0xffffffff
        per.setdefault(idx, set()).add(va)
        per_site.setdefault(idx, []).append((fo, va, typ))
    _SPLITS.clear()
    for idx, vas in per.items():
        name = syms[idx][0]
        fin = mapping.get(idx, name)
        self_call = name == fsym and any(v_ != va0 for v_ in vas)
        if len(vas) > 1 and fin.startswith('__imp_') and all(v_ in _import_slots() for v_ in vas) and not os.environ.get('ROC_NO_IMPORT_REBIND'):
            # one analog import name read from several ORIGINAL slots (Ogre MeshPtr ctor + dtor as basic_string's):
            # each read gets its own slot's DLL!name label (renamed_link aliases those to __imp_ names)
            for fo_, v_, t_ in per_site[idx]:
                lab_ = (native_asm.label(CLIENT, v_) or '').split(' ')[0]
                if '!' in lab_ and not lab_.split('!', 1)[1].startswith('#'):
                    _SPLITS.append((fo_, lab_))
                    refs['split:%s@%x' % (fin[:60], fo_)] = '%08x' % v_
            continue
        if not ((len(vas) > 1 or self_call) and cls_of.get(idx) != 3) or fin.startswith((
                '??_C@', '??_R', '??_7', '__real@', '__xmm@', '__imp_', '$', '.', '__ehhandler$', '__unwindfunclet$',
                '___security_cookie', '__CxxFrameHandler', '__except_handler', '__chkstk', '__EH_prolog', '_roc_')):
            continue
        if name in KEEPNAMES or fin in KEEPNAMES:
            continue
        # one analog name stands for several original targets (Type::singleton<T> over 3 types, func_004d8680 for
        # {00446110, 0064b2a0}, the analog calling ITSELF where the original calls its base): each relocation gets
        # its own target's name, so no single choice is wrong for the others
        for fo_, v_, t_ in per_site[idx]:
            if self_call and v_ == va0:
                continue
            if t_ == REL32 and v_ < 0x7c0000 and '%08x' % v_ not in STARTS:
                continue   # inside a function: not a call target we can name
            rn = real_name(v_)
            nn = rn if (rn and rn in DEFINED and '%08x' % v_ not in DUPNAMES) else ('func_%08x' if v_ < 0x7c0000 else 'dat_%08x') % v_
            if nn != fin:
                _SPLITS.append((fo_, nn))
                refs['split:%s@%x' % (fin[:60], fo_)] = '%08x' % v_
    for idx, vas in per.items():
        name = syms[idx][0]
        fin = mapping.get(idx, name)
        if len(vas) == 1 and fin.startswith('__imp_') and next(iter(vas)) in _import_slots() and not os.environ.get('ROC_NO_IMPORT_REBIND'):
            # an import call: the slot the ORIGINAL reads names the DLL function. An analog compiled from another
            # overload kept its own __imp_ (Http(const char*) called basic_string's COPY ctor -> bad_alloc at startup)
            _lab = (native_asm.label(CLIENT, next(iter(vas))) or '').split(' ')[0]
            if '!' in _lab and not _lab.startswith(('MFC ', 'ATL ', 'CRT ')):
                _imp = _lab.split('!', 1)[1]
                _mine = fin[6:]
                _same = _mine == _imp or (_mine if _mine.startswith('?') else re.sub(r'@\d+$', '', _mine[1:])) == _imp
                if not _same and not _imp.startswith('#'):
                    refs['rebound:' + fin] = '%08x' % next(iter(vas))
                    mapping[idx] = _lab
            continue
        if len(vas) != 1 or cls_of.get(idx) == 3 or name == fsym or fin.startswith((
                '??_C@', '??_R', '??_7', '__real@', '__xmm@', '__imp_', '$', '.', '__ehhandler$', '__unwindfunclet$',
                '___security_cookie', '__CxxFrameHandler', '__except_handler', '__chkstk', '__EH_prolog', '_roc_')):
            continue
        v = next(iter(vas))
        if name in KEEPNAMES or fin in KEEPNAMES or (v < 0x7c0000 and '%08x' % v not in STARTS):
            continue   # the analog's own helper copy (no function starts there in the original): stays as is
        m_ = re.fullmatch(r'_?(?:func|dat|fn|g)_([0-9a-f]{8})(?:@\d+)?', fin) or re.fullmatch(r'@fn_([0-9a-f]{8})@\d+', fin)
        want = {int(m_.group(1), 16)} if m_ else names.get(fin)
        if not want or v in want:
            continue
        rn = real_name(v)
        new = rn if (rn and rn in DEFINED and '%08x' % v not in DUPNAMES) else ('func_%08x' if v < 0x7c0000 else 'dat_%08x') % v
        if new != fin:
            refs['rebound:' + fin] = '%08x' % v
            mapping[idx] = new


def _funclet_map(data, fsym, syms, cls_of, va, base, image, mapping):
    """Pair the analog's __unwindfunclet$<fsym>$N with the original's unwind-map actions (same order) and map each
    funclet's call/jmp target symbol to the original target's real name / func_<addr>. Without this an invented class's
    destructor named in a funclet (??1FileList@@) bound to an unrelated real one (RakNet FileList) during unwinding."""
    import capstone
    rd = lambda a: struct.unpack_from('<I', image, a - base)[0]
    if image[va - base] != 0x6a or image[va - base + 2] != 0x68:   # push -1; push __ehhandler
        return
    hnd = rd(va + 3)
    if image[hnd - base] != 0xb8:   # mov eax, __ehfuncinfo
        return
    fi = rd(hnd + 1)
    nst, um = rd(fi + 4), rd(fi + 8)
    acts = []
    for i in range(min(nst, 64)):
        a = rd(um + 8 * i + 4)
        if a and a not in acts:
            acts.append(a)
    fun = sorted(((int(n.rsplit('$', 1)[1]), n) for i, (n, s) in syms.items()
                  if n.startswith('__unwindfunclet$' + fsym + '$') and n.rsplit('$', 1)[1].isdigit()))
    if not fun or len(fun) != len(acts):
        return
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    for (_, fname), act in zip(fun, acts):
        otg = []
        for ins in md.disasm(bytes(image[act - base:act - base + 64]), act):
            if ins.mnemonic in ('call', 'jmp') and ins.op_str.startswith('0x'):
                otg.append(int(ins.op_str, 16))
            if ins.mnemonic in ('jmp', 'ret'):
                break
        _all = symtab(data)[0]
        _me = next(x for x in _all if x[1] == fname)
        _nxt = [x[4] for x in _all if x[2] == _me[2] and x[4] > _me[4]]
        _len = (min(_nxt) - _me[4]) if _nxt else 64   # funclets share the function's section: only this funclet's bytes
        rel = [(off, idx) for off, typ, idx, fo in relocations(data, fname) if typ == REL32 and 0 <= off < _len]
        if len(rel) != len(otg):
            continue
        for (off, idx), t in zip(rel, otg):
            name = syms[idx][0]
            if cls_of.get(idx) == 3 or idx in mapping:
                continue
            real = CHAIN.get('%08x' % t) or real_name(t)
            if not real or (real not in DEFINED and t < 0x7c0000 and not real.startswith('__imp_')):
                real = 'func_%08x' % t
            if real != name:
                mapping[idx] = real


def convert(addr, symbol, target):
    src = ROOT / 'src' / CLIENT / (addr + '.cpp')
    text = src.read_text(errors='replace')
    cl = int((re.search(r'//\s*roc-cl:\s*(\d+)', text) or [0, 21022])[1])
    flags = (re.search(r'//\s*roc-flags:\s*(.+)', text) or [0, '/O2 /GS- /EHsc /MD'])[1].split()
    if match.reject_asm(text) if hasattr(match, 'reject_asm') else False:
        return dict(status='rejected', why='inline asm')
    obj = WORK / (addr + '.obj')
    libref = re.search(r'//\s*roc-lib:\s*(\S+)\s+(\S+)', text)  # server analog that lives in a library recipe file
    data = None
    globals()['_ALT_INC'] = None
    try:   # the verifier's own compile (directives: lang, flags, cl, lib, archive; shared object cache): the bytes the server scored
        data = match.compile_text(CLIENT, text)
    except BaseException:
        data = None
    if data is None and libref:
        from roc import libs
        r_ = libs.RECIPES.get(libref.group(1)) or {}
        _p = lambda mine, other: mine if (libs.LIBS / mine).is_dir() else other
        # OpenRBX later moved its vendor trees under Client/ (the files the server compiled: G3D::Sky::setNumStars exists
        # only there). A missing recipe dir is silently skipped by cl, which then finds another G3D on INCLUDE: remap
        # missing dirs BEFORE the first preprocess; generic copies only when this checkout lacks both
        alt = {'../openrbx/3rdparty/boost_1_34_1': _p('../openrbx/Client/boost_1_34_1/boost', 'boost_1_34_1').replace('/boost_1_34_1/boost', '/boost_1_34_1'),
               '../openrbx/3rdparty/lua-5.1.1/src': _p('../openrbx/Client/App/lua-5.1.1/src', 'lua-5.1.1/src'),
               '../openrbx/3rdparty/g3d/source/include': _p('../openrbx/Client/Rendering/g3d/include', '../rbxgs/Client/Rendering/g3d/include'),
               '../openrbx/3rdparty/g3d/source/png': _p('../openrbx/Client/Rendering/g3d/png', '../openrbx/3rdparty/g3d/source/png'),
               '../openrbx/3rdparty/g3d/source/zlib': _p('../openrbx/Client/Rendering/g3d/zlib', '../openrbx/3rdparty/g3d/source/zlib'),
               '../openrbx/3rdparty/RakNet30/Source': _p('../openrbx/Client/Network/raknet30/Source', 'RakNet-master/Source'),
               '../openrbx/3rdparty/SDL-1.2.6/include': _p('../openrbx/Client/Rendering/SDL-1.2.6/include', 'SDL-1.2.11/include')}
        old_ = r_.get('include')
        _miss = [i for i in (old_ or []) if i in alt and not (libs.LIBS / i).is_dir()]
        try:   # the exact preprocessed unit the server compiled (recipe prelude, defines, patches, noinline edits)
            if _miss:
                r_['include'] = [alt.get(i, i) if i in _miss else i for i in old_]
                globals()['_ALT_INC'] = r_['include']   # the sockaddr retry re-preprocesses with the same mapping
            body = libs.unit(libref.group(1), libref.group(2), cl)
        except Exception as e:
            # this checkout has no openrbx/3rdparty tree: a cache miss cannot preprocess. Retry with the same libraries
            # from tools/libs / tools/rbxgs (a header difference only shows as 'nomatch', never as wrong bytes).
            try:
                if not old_ or not any(i in alt for i in old_):
                    raise e
                r_['include'] = [alt.get(i, i) for i in old_]
                body = libs.unit(libref.group(1), libref.group(2), cl)
                globals()['_ALT_INC'] = r_['include']   # the sockaddr retry re-preprocesses with the same mapping
            except Exception as e2:
                return dict(status='compile', why=['library unit: %s' % str(e2)[:160]])
            finally:
                if old_ is not None:
                    r_['include'] = old_
        finally:
            if old_ is not None:
                r_['include'] = old_
        src = WORK / (addr + ('.unit.c' if libref.group(2).lower().endswith('.c') else '.unit.cpp'))
        src.write_text(body, errors='replace')
    if os.environ.get('ROC_RENAME_DEFINED'):   # donor-free: analogs that include OpenRBX headers need boost on the include path
        flags = flags + ['/I' + str(ROOT / 'tools/rbxgs/Client/boost_1_34_1/src'), '/I' + str(ROOT / 'tools/rbxgs/Client/Rendering/g3d/include')]
    if data is None:
        # one library unit holds many analogs (Sky.cpp: 252): compile it once, reuse the object (keyed by text + flags)
        import hashlib, shutil as _sh
        _uk = hashlib.md5(src.read_bytes() + repr((cl, flags)).encode()).hexdigest()
        _uc = WORK / '_unitobj' / (_uk + '.obj')
        if libref and _uc.exists():
            _sh.copyfile(_uc, obj); code, log = 0, ''
        else:
            code, log = rebuild.run(rebuild.toolchain(cl), 'cl', ['/nologo', '/c', '/w'] + flags + ['/Fo' + obj.name, str(src)], WORK)
        _log0 = log   # first-stage (donor unit) error: later retries overwrite `log`
        if (code or not obj.exists()) and libref and (ROOT / 'tools/rbxgs-lock').is_dir():
            # the server compiled rbxgs units at research/native-source-lock.json's revision (5a2df2c); the local
            # tools/rbxgs is a later sync (42406f1) whose headers clash (const char* sInstance vs char[]): re-preprocess
            # the unit from the pinned worktree tools/rbxgs-lock
            from roc import libs
            r0 = libs.RECIPES.get(libref.group(1)) or {}
            if str(r0.get('src', '')).startswith('../rbxgs/') or any(str(i).startswith('../rbxgs/') for i in r0.get('include', [])):
                o_src, o_inc = r0.get('src'), r0.get('include')
                try:
                    r0['src'] = str(o_src).replace('../rbxgs/', '../rbxgs-lock/', 1)
                    if not globals().get('_PIN_UNITS'):   # generated units are text (libs.generated_units()), keyed by folder,
                        globals()['_PIN_UNITS'] = True     # and include each other: mirror all rbxgs ones into the pinned tree once
                        for _k, _files in libs.generated_units().items():
                            if str(_k).startswith('../rbxgs/'):
                                _dst = (libs.LIBS / str(_k).replace('../rbxgs/', '../rbxgs-lock/', 1)).resolve()
                                for _fn, _txt in _files.items():
                                    _t = _dst / _fn
                                    if not _t.exists():
                                        _t.parent.mkdir(parents=True, exist_ok=True); _t.write_text(_txt, encoding='utf-8')
                    src.write_text(libs.unit(libref.group(1), libref.group(2), cl), errors='replace')
                    code, log = rebuild.run(rebuild.toolchain(cl), 'cl', ['/nologo', '/c', '/w'] + flags + ['/Fo' + obj.name, str(src)], WORK)
                except Exception as e4:
                    log = log + chr(10) + 'error pinned-rbxgs retry: %s' % str(e4)[:160]
                finally:
                    r0['src'], r0['include'] = o_src, o_inc
        if (code or not obj.exists()) and 'error C2248' in log and os.environ.get('ROC_RENAME_DEFINED'):
            # donor unit failing only on access (IRenderable::indexFunc2d): override access BEFORE the native-header
            # retry rewrites the unit (that order lost ~117 FlagStand-unit analogs, incl. Tool's PropDescriptor ctors)
            code, log = rebuild.run(rebuild.toolchain(cl), 'cl', ['/nologo', '/c', '/w', '/Dprivate=public', '/Dprotected=public'] + flags + ['/Fo' + obj.name, str(src)], WORK)
        if (code or not obj.exists()) and libref and os.environ.get('ROC_RENAME_DEFINED'):
            # local tools/rbxgs mixes generated headers (TheDescriptor::Describing) with older reflection headers:
            # re-preprocess with the native headers first (they carry the matching declarations), then retry
            from roc import libs
            r_ = libs.RECIPES.get(libref.group(1)) or {}
            old_ = r_.get('include')
            try:
                r_['include'] = [str(ROOT / 'rebuild/2008-06/native-headers')] + list(old_ or [])
                _u = libs.unit(libref.group(1), libref.group(2), cl)
                # 2008 headers declare class-name strings as arrays (extern char sFlagStand[]; template argument), the
                # 2007 library source defines pointers (char* sFlagStand = "FlagStand"): same bytes, array form
                for _nm in set(re.findall(r'extern\s+(?:const\s+)?char\s+(\w+)\s*\[\]', _u)):
                    _u = re.sub(r'(?m)^(\s*)(const\s+)?char\s*\*\s*(?:const\s+)?%s\s*=\s*("[^"]*")' % _nm,
                                lambda m_, n_=_nm: '%s%schar %s[] = %s' % (m_.group(1), m_.group(2) or '', n_, m_.group(3)), _u)
                src.write_text(_u, errors='replace')
                code, log = rebuild.run(rebuild.toolchain(cl), 'cl', ['/nologo', '/c', '/w'] + flags + ['/Fo' + obj.name, str(src)], WORK)
            except Exception as e3:
                log = 'error native-header retry: %s' % str(e3)[:160]
            finally:
                if old_ is not None:
                    r_['include'] = old_
        if (code or not obj.exists()) and "'short' followed by 'wchar_t'" in log:
            # the unit typedefs wchar_t itself (old SDK/vendor headers): it was built with wchar_t as a typedef
            code, log = rebuild.run(rebuild.toolchain(cl), 'cl', ['/nologo', '/c', '/w', '/Zc:wchar_t-'] + flags + ['/Fo' + obj.name, str(src)], WORK)
        if (code or not obj.exists()) and 'error C2248' in log and os.environ.get('ROC_RENAME_DEFINED'):
            # the analog reaches a member our (newer) header made private: access never changes codegen or layout here,
            # and every callee is remapped by its original address below
            code, log = rebuild.run(rebuild.toolchain(cl), 'cl', ['/nologo', '/c', '/w', '/Dprivate=public', '/Dprotected=public'] + flags + ['/Fo' + obj.name, str(src)], WORK)
        if (code or not obj.exists()) and "error C2011: 'sockaddr'" in log:
            # windows.h pulled winsock.h before the unit's winsock2.h (library unit order differs from the original
            # project's PCH): winsock2.h first keeps winsock.h out (its _WINSOCKAPI_ guard); no codegen change
            if libref:   # a preprocessed library unit: /FI comes too late (and redefines vc_attributes); re-preprocess
                from roc import libs   # with _WINSOCKAPI_ defined (winsock2.h defines it itself), same include mapping
                r_ = libs.RECIPES.get(libref.group(1)) or {}
                o_def, o_inc = r_.get('defines', ''), r_.get('include')
                try:
                    r_['defines'] = (o_def + ' _WINSOCKAPI_').strip()
                    if globals().get('_ALT_INC'):
                        r_['include'] = globals()['_ALT_INC']
                    src.write_text(libs.unit(libref.group(1), libref.group(2), cl), errors='replace')
                    code, log = rebuild.run(rebuild.toolchain(cl), 'cl', ['/nologo', '/c', '/w'] + flags + ['/Fo' + obj.name, str(src)], WORK)
                    if (code or not obj.exists()) and 'error C2248' in log:
                        code, log = rebuild.run(rebuild.toolchain(cl), 'cl', ['/nologo', '/c', '/w', '/Dprivate=public', '/Dprotected=public'] + flags + ['/Fo' + obj.name, str(src)], WORK)
                except Exception as e5:
                    log = log + chr(10) + 'error winsock re-preprocess: %s' % str(e5)[:160]
                finally:
                    r_['defines'] = o_def
                    if o_inc is not None:
                        r_['include'] = o_inc
            else:
                code, log = rebuild.run(rebuild.toolchain(cl), 'cl', ['/nologo', '/c', '/w', '/FIwinsock2.h'] + flags + ['/Fo' + obj.name, str(src)], WORK)
        for _cn_try in range(3):
            # class-name constants: the analog defines `const char sCamera[] = "Camera"` / passes `&sInstance` as a
            # `const char*` template argument, the native headers declare `extern char sCamera[]` (C2373 redefinition,
            # C2440 'specialization' cannot convert char** -> const char*). Match the header from the compiler's own
            # error lines and recompile (~134 server-exact analogs failed here); names and codegen do not change.
            if not ((code or not obj.exists()) and ('error C2373' in log or ("error C2440: 'specialization'" in log))):
                break
            try:
                _t = src.read_text(errors='replace')
                _ls = _t.split('\n')
                for _m in re.finditer(r"error C2373: '(?:\w+::)*(s[A-Z]\w*)' : redefinition", log):
                    _t = re.sub(r'\bconst\s+char\s+%s\s*\[\]' % re.escape(_m.group(1)), 'char %s[]' % _m.group(1), _t)
                _ls = _t.split('\n')
                for _m in re.finditer(r"\((\d+)\) : error C2440: 'specialization'", log):
                    _n = int(_m.group(1)) - 1
                    if 0 <= _n < len(_ls):
                        _ls[_n] = re.sub(r'&\s*((?:RBX::)?s[A-Z]\w*)\b', r'\1', _ls[_n])
                _new = '\n'.join(_ls)
                if _new == src.read_text(errors='replace'):
                    break
                src.write_text(_new, errors='replace')
                code, log = rebuild.run(rebuild.toolchain(cl), 'cl', ['/nologo', '/c', '/w', '/Dprivate=public', '/Dprotected=public'] + flags + ['/Fo' + obj.name, str(src)], WORK)
            except Exception as _e6:
                log = log + chr(10) + 'error class-name retry: %s' % str(_e6)[:160]
                break
        if libref and not code and obj.exists() and not _uc.exists():   # final object of the retry chain, under the first unit's key
            _uc.parent.mkdir(exist_ok=True)
            _tmp = _uc.with_suffix('.%d.tmp' % os.getpid()); _sh.copyfile(obj, _tmp); os.replace(_tmp, _uc)
        if code or not obj.exists():
            return dict(status='compile', why=[l for l in log.splitlines() if 'error' in l][:3],
                        first=[l for l in _log0.splitlines() if 'error' in l][:3])
        data = obj.read_bytes()
    hit = next((f for f in match.coff_functions(data) if target.same(addr, f[1], f[2]) is not None), None)
    if not hit and os.environ.get('ROC_RENAME_DEFINED') and not libref:
        # sources without roc-flags were scored under a unit's own flags; /fp:fast is the common difference
        # (00557150 RunService heartbeat: its unit keeps the double->float copies on the x87 stack)
        for _extra in (['/fp:fast'], ['/fp:fast', '/Oy-'], ['/Oy-']):
            src2 = WORK / (addr + '.fpf.cpp')
            src2.write_text(text, errors='replace')
            obj.unlink(missing_ok=True)
            code2, log2 = rebuild.run(rebuild.toolchain(cl), 'cl', ['/nologo', '/c', '/w'] + flags + _extra + ['/Fo' + obj.name, str(src2)], WORK)
            if not code2 and obj.exists():
                d2 = obj.read_bytes()
                hit = next((f for f in match.coff_functions(d2) if target.same(addr, f[1], f[2]) is not None), None)
                if hit:
                    data = d2
                    break
    if not hit and os.environ.get('ROC_RENAME_DEFINED') and not libref:
        # ADDRESS LITERALS standing in for symbols: `tail((void*)0x7fc640)` scored 100% on the server (relocation bytes
        # masked) but compiles to a plain immediate with no relocation, so it never pairs with the original's
        # relocated operand (445 of 537 nomatch analogs). Rewrite each in-image pointer cast to a reference to the
        # link's own placeholder name (func_<addr> for a function start, else dat_<addr>): a real DIR32 relocation, bound
        # by address like every other reference.
        _lit = re.compile(r'\(\s*([A-Za-z_][\w\s:<>,]*?\*+)\s*\)\s*0x([0-9a-fA-F]{6,8})\b')
        _nm = lambda v: ('func_%08x' if ('%08x' % v) in STARTS else 'dat_%08x') % v
        _rc = re.compile(r'reinterpret_cast\s*<\s*([^<>]*?\*+)\s*>\s*\(\s*0x([0-9a-fA-F]{6,8})\s*\)')
        _bare = re.compile(r'(?<![\w&])0x([0-9a-fA-F]{6,8})\b')
        _in = lambda v: 0x401000 <= v < 0x9a0000
        _vs = sorted({int(m.group(1), 16) for m in _bare.finditer(text) if _in(int(m.group(1), 16))})
        _stages = []
        if _vs:
            _decl = ''.join('extern "C" char %s;\n' % _nm(v) for v in _vs)
            # stage A: pointer casts only (C-style and reinterpret_cast); stage B: also bare in-image integers
            # (`*(int*)this = 0x826be8` stores a vtable address). A wrong guess (a real integer constant) cannot be
            # accepted: the byte compare masks only real relocations, so it stays nomatch.
            _a = _lit.sub(lambda m: '(%s)&%s' % (m.group(1), _nm(int(m.group(2), 16))) if _in(int(m.group(2), 16)) else m.group(0), text)
            _a = _rc.sub(lambda m: 'reinterpret_cast<%s>(&%s)' % (m.group(1), _nm(int(m.group(2), 16))) if _in(int(m.group(2), 16)) else m.group(0), _a)
            _b = _bare.sub(lambda m: '((int)&%s)' % _nm(int(m.group(1), 16)) if _in(int(m.group(1), 16)) else m.group(0), _a)
            _stages = [_decl + _a] + ([_decl + _b] if _b != _a else [])
        for text3 in _stages:
            if hit:
                break
            for _extra in ([], ['/fp:fast'], ['/Oy-']):
                src3 = WORK / (addr + '.lit.cpp')
                src3.write_text(text3, errors='replace')
                obj.unlink(missing_ok=True)
                code3, log3 = rebuild.run(rebuild.toolchain(cl), 'cl', ['/nologo', '/c', '/w'] + flags + _extra + ['/Fo' + obj.name, str(src3)], WORK)
                if not code3 and obj.exists():
                    d3 = obj.read_bytes()
                    hit = next((f for f in match.coff_functions(d3) if target.same(addr, f[1], f[2]) is not None), None)
                    if hit:
                        data = d3
                        break
    if not hit:
        return dict(status='nomatch', why='no object function is byte-identical to the target')
    fsym = hit[0]
    syms = {i: (n, sec) for i, n, sec, cls, v in symtab(data)[0]}
    cls_of = {i: cls for i, n, sec, cls, v in symtab(data)[0]}
    base, image = match._image(CLIENT)
    mapping, blockers, refs = {}, [], {}
    KEEPNAMES.clear()
    data = bytearray(data)
    for off, typ, idx, fileoff in relocations(data, fsym):
        name, sec = syms[idx]
        addend = struct.unpack_from('<i', data, fileoff)[0]
        site = int(addr, 16) + off
        word = struct.unpack_from('<I', image, site - base)[0]
        if typ == DIR32:
            va = word - addend
        elif typ == REL32:
            va = (site + 4 + struct.unpack_from('<i', image, site - base)[0]) - addend
        else:
            continue
        if (os.environ.get('ROC_RENAME_DEFINED') and typ == DIR32 and 0x7c0000 <= word < 0x9a0000 and cls_of[idx] != 3
                and not name.startswith(('??_C@', '__imp_', '??_7', '??_R')) and real_name(word) is None):
            _ob = _data_object(word)
            if _ob and len({i_ for i_, t_ in mapping.items() if i_ == idx and t_ != _ob[0]}) == 0:
                # a field of a dynamically-initialised global (dat_0096d52c = prop_profileName+0x18): bind to the
                # object the link initialises, offset in the stored addend
                mapping[idx] = _ob[0]
                struct.pack_into('<i', data, fileoff, _ob[1])
                refs[name] = '%08x' % word
                continue
        if cls_of[idx] == 3 or name.startswith(('??_C@', '__ehhandler$', '__unwindfunclet$', '$', '.')):
            continue                      # object-local (EH funclet, string literal, jump table): travels with it
        if name.startswith(('___security_cookie', '__CxxFrameHandler', '__except_handler', '__chkstk', '__EH_prolog')):
            continue
        if os.environ.get('ROC_RENAME_DEFINED') and not name.startswith('__imp_') and typ == DIR32:
            # only an absolute reference reads the slot (call [slot] / mov reg,[slot]); a direct call (REL32) to a thunk
            # must stay a call to the function, or it jumps into the import table (GetAdaptersInfo crash)
            _lab = native_asm.label(CLIENT, va) or ''
            if '!' in _lab.split(' ')[0] and not _lab.startswith(('MFC ', 'ATL ', 'CRT ')):
                # the original reads an IMPORT SLOT here; the analog faked it with its own pointer variable named like the
                # function (extern "C" void* (*malloc)(unsigned)) -> in our link '_malloc' is the CRT FUNCTION, and
                # call [_malloc] jumped into its code bytes. Bind to the import slot ('DLL!name' -> __imp_ alias).
                mapping[idx] = _lab.split(' ')[0]
                refs[name] = '%08x' % va
                continue
        _nd_ = _native_data_map().get('%08x' % va) if (os.environ.get('ROC_RENAME_DEFINED') and typ == DIR32) else None
        if _nd_ and _nd_ in DEFINED and _nd_ != name:
            # a native source names this original data address (// 00976b4c: Log::provider): that global wins over the
            # registry's data label (G3D::_internal::_debugHook) -> setLogProvider and Log::current share one variable
            refs[name] = '%08x' % va
            mapping[idx] = _nd_
            continue
        real = CHAIN.get('%08x' % va) or real_name(va)
        if (os.environ.get('ROC_RENAME_DEFINED') and typ == DIR32 and 0x800000 <= va < 0x9a0000
                and (name.startswith('??_7') or (real or '').startswith('??_7'))):
            _nv = _native_vtable(va)
            if _nv:   # the vtable for this class + subobject offset in OUR link (layout-proved), not the stale label
                refs[name] = '%08x' % va
                if _nv != name:
                    mapping[idx] = _nv
                continue
            if _is_vtable(va):
                # no native vtable for this class (TypedStatsItem<Stopwatch>): the analog's own vtable has invented
                # slots (stubs) -> the ORIGINAL vtable's placeholder, whose slots relocate to the real functions
                refs[name] = '%08x' % va
                mapping[idx] = 'dat_%08x' % va
                continue
        _local_static = bool(re.search(r'@\?\d+\?\?|^\?\?_B\?\d+\?\?', name)) and '%08x' % va not in STARTS
        # template-owned statics (doGetClassIndex<LocalBackpack>'s index, getClassIndex<X>'s once flag) are one COMDAT
        # program-wide: share the native one when the link defines it (separate copies gave find/create different indices)
        _tmpl_shared = name in DEFINED and ('??$' in name or '@?$' in name) and '@boost@@' not in name   # boost: our 1.34.1 layout differs
        # ...but only when the ORIGINAL static is that same COMDAT: Tool::classDescriptor's analog was compiled from
        # Described<Instance>, so its ?foo@?1??classDescriptor@?$Described@VInstance static (shared by ~2000 converted
        # analogs) put every class's properties into ONE descriptor (CRenderSettings logged Tool's ActivationState)
        _rn_ = real_name(va) if _local_static else None
        if _tmpl_shared and _rn_ and _rn_ != name:
            _tmpl_shared = False
        # a static owned by the ANALOG main function, when that main became another function (Instance's classDescriptor
        # analog -> ModelInstance's func_00585100): the static AND its guard must move together. The registry can label
        # the guard with the analog's own (shared) name, which kept the guard shared and the moved foo never constructed
        _own_moved = _local_static and fsym != symbol and len(fsym) > 8 and fsym[1:] in name
        if _own_moved:
            _tmpl_shared = False
            if _rn_ == name:
                _rn_ = None
        if _local_static and os.environ.get('ROC_RENAME_DEFINED') and (real_name(va) != name or _own_moved) and not _tmpl_shared:
            # a function-local static / guard is named after the ANALOG function (?c@?3??axes@Shape@G3D...): several converted
            # objects whose analogs share that invented name shared one static + guard (Context::ptr's thread_specific_ptr
            # never constructed: the mutex getter set the guard). Bind it to the original's own data address instead.
            refs[name] = '%08x' % va
            # the original's own static by its registry name when it is a template COMDAT (native code instantiating the
            # same template shares it); otherwise the address placeholder (registry names can repeat invented names)
            mapping[idx] = _rn_ if (_rn_ and ('??$' in _rn_ or '@?$' in _rn_) and '@boost@@' not in _rn_) else 'dat_%08x' % va
            continue
        if (os.environ.get('ROC_RENAME_DEFINED') and typ == REL32 and real and real != name
                and _tmpl_member(name) and _tmpl_member(name) == _tmpl_member(real) and (_tmpl_member(name)[1] == '_Tree' or (_tmpl_member(name)[1] == 'vector' and _vec_cls(name) != _vec_cls(real)))   # all-template scope broke boost tss
                and '@boost@@' not in name and '@boost@@' not in real   # our boost 1.34.1 layout differs from the original's
                and _has_analog('%08x' % va) and '%08x' % va not in _conv_failed()):   # stub_exact.py converts it
            # ICF: the original folded identical std::_Tree instances under one label (BrickMap's map<Number,Color4> ctor
            # "called" the set<string> ctor). OUR instance of the label's type has another node layout (_Isnil offset) ->
            # map insert spun forever. The original address's own exact code is right for every folded user: bind to it.
            refs[name] = '%08x' % va
            mapping[idx] = 'func_%08x' % va
            continue
        if name in KNOWN:
            # already the real name of something the link defines - unless the analog INVENTED a class/function name that
            # collides with an unrelated one in our link (analog FileList : std::list vs RakNet FileList): the original
            # target is a known function start with a different real name, so map by address like any other helper.
            # (also when the address's real name is defined natively: create<RunService> called the invented ??0Object@@QAE@XZ)
            if not (os.environ.get('ROC_RENAME_DEFINED') and '%08x' % va in STARTS and va < 0x7c0000 and cls_of[idx] != 3
                    and real != name and name.startswith('?')
                    and ((sec > 0 and _has_analog('%08x' % va)) or (real and real in DEFINED))):
                continue
            refs['collide:' + name] = '%08x' % va
        refs[name] = '%08x' % va
        if os.environ.get('ROC_RENAME_DEFINED') and '%08x' % va not in STARTS and va < 0x7c0000 and cls_of[idx] != 3 and not name.startswith('__imp_'):
            KEEPNAMES.add(name)
            continue                      # target is not a known function start (template/inline helper): keep the analog's real name and its own copy
        if real and os.environ.get('ROC_RENAME_DEFINED') and real not in DEFINED and va < 0x7c0000 and not real.startswith('__imp_'):
            real = 'func_%08x' % va       # donor-free closure: a real name nothing in that link defines -> convert that address too
        if real is None and os.environ.get('ROC_RENAME_PLACEHOLDER'):  # shortcut closure pass: unnamed callee/data keep a placeholder name
            real = ('func_%08x' if va < 0x7c0000 else 'dat_%08x') % va
        if real is None:
            blockers.append('%s -> %08x (no real name known)' % (name, va))
        elif real and real != name:
            mapping[idx] = real
    if blockers:
        return dict(status='blocked', analog=fsym, why=blockers[:8], refs=refs)
    if os.environ.get('ROC_RENAME_DEFINED'):   # an invented class's destructor follows its renamed constructor (dtor calls sit in unwind funclets)
        for i_, real_ in list(mapping.items()):
            old_ = syms[i_][0]
            if old_.startswith('??0') and real_.startswith('??0') and '@@' in old_ and '@@' in real_:
                inv, path = old_[3:old_.index('@@')], real_[3:real_.index('@@')]
                dt = next((d for d in sorted(DEFINED) if d.startswith('??1' + path + '@@')), None)
                for j_, (n_, s_) in syms.items():
                    if dt and n_.startswith('??1' + inv + '@@') and j_ not in mapping:
                        mapping[j_] = dt
    if os.environ.get('ROC_RENAME_DEFINED'):   # unwind funclets: their jmp/call targets (destructors) map by the ORIGINAL funclet
        try:
            _funclet_map(data, fsym, syms, cls_of, int(addr, 16), base, image, mapping)
        except Exception:
            pass
    fidx = next(i for i, (n, s) in syms.items() if n == fsym)
    for _i in [i for i, t in mapping.items() if t == symbol and i != fidx and syms[i][1] > 0]:
        del mapping[_i]   # the analog's OWN defined helper must not take this function's name (call -> self -> recursion)
    for _i, _t in list(mapping.items()):   # a call to ANOTHER address that would bind to this object's own name
        _va = refs.get(syms[_i][0])
        if _t == symbol and _i != fidx and _va and _va != addr:
            mapping[_i] = 'func_' + _va
    mapping[fidx] = symbol
    for j_, (n_, s_) in syms.items():   # the analog's own copy of the real-named function: one object cannot define a name twice
        if n_ == symbol and j_ != fidx and j_ not in mapping:
            mapping[j_] = 'roc_dup%d_%s' % (j_, addr)
    _inv_keep = set()
    if os.environ.get('ROC_RENAME_DEFINED'):
        # helpers kept under their real names (KEEPNAMES: targets that are not function starts, i.e. inlined code) must
        # not become THE definition for everyone when the link already defines that name (OnFileNew's copy of
        # map<ContentId,CachedContent>::operator[] served ContentProvider with the analog's container layout)
        for j_, (n_, s_) in syms.items():
            if s_ > 0 and n_ in KEEPNAMES and n_ in DEFINED and j_ not in mapping and n_ != symbol:
                mapping[j_] = n_ + '_roc' + addr
                KEEPNAMES.add(mapping[j_])
    if os.environ.get('ROC_RENAME_DEFINED'):
        # polymorphic classes the ORIGINAL never had (an analog's `Holder` for boost::any): stripping their vtable / RTTI /
        # methods bound the object to an unrelated class of the same name elsewhere (any::holder copy -> garbage vptr).
        # Keep this object's own copies under unique names.
        _oc = _orig_classes()
        _inv = set()
        for j_, (n_, s_) in syms.items():
            m_ = re.match(r'^\?\?_7(\w+@@)6B', n_)
            if s_ > 0 and m_ and ('.?AV' + m_.group(1)) not in _oc and ('.?AU' + m_.group(1)) not in _oc:
                _inv.add(m_.group(1)[:-2])
        if _inv:
            _pat = re.compile(r'^(?:\?\?_[0-9A-Z]|\?\?_R[0-4]\S*?@|\?\w+@)(?:\?A[VU])?(%s)@@' % '|'.join(map(re.escape, _inv)))
            for j_, (n_, s_) in syms.items():
                if s_ > 0 and j_ not in mapping and n_ != symbol and _pat.match(n_):
                    # the vtable this code stores is the ORIGINAL one at a known address: its real (native) vtable
                    # wins (analog `Item` = RBX::Stats::Item); only a class with no real counterpart keeps a private copy
                    _va = refs.get(n_)
                    _real = vtable_name(int(_va, 16)) if _va and n_.startswith('??_7') else None
                    if _real and _real in DEFINED:
                        mapping[j_] = _real
                        continue
                    mapping[j_] = n_ + '_roc' + addr
                    _inv_keep.add(mapping[j_])
    if os.environ.get('ROC_RENAME_DEFINED'):
        _bind_validate(data, fsym, syms, cls_of, int(addr, 16), base, image, mapping, refs)
    data = rename(data, mapping)
    if os.environ.get('ROC_RENAME_DEFINED') and _SPLITS and not os.environ.get('ROC_NO_SPLIT'):
        data = _split_relocs(data, _reloc_entries(data, fsym, _SPLITS))
    if os.environ.get('ROC_RENAME_DEFINED'):   # donor-free: keep only helpers that stand in for non-start targets (other helpers use invented layouts)
        # an analog definition renamed to a dat_<addr> placeholder (its own vtable/global) must not define it: the
        # placeholder (original bytes, relocated slots) is the object -> drop, keeping only the references
        _datdefs = {t_ for i_, t_ in mapping.items() if t_.startswith('dat_') and syms[i_][1] > 0}
        data = rebuild.strip_symbols(data, keep=({symbol} | KEEPNAMES | _inv_keep) - _datdefs, drop=_datdefs)
    elif not os.environ.get('ROC_RENAME_KEEP_HELPERS'):  # shortcut closure pass keeps the analog's comdat helpers (std/boost templates)
        data = rebuild.strip_symbols(data, keep={symbol})
    (OUT / (addr + '.obj')).write_bytes(data)
    return dict(status='renamed', analog=fsym, renamed={syms[i][0]: n for i, n in mapping.items()}, refs=refs)


_RVT = []
def _realvt():
    """vtable names real (non-draft) native objects define (defined_now.py: renamed/defined_nodraft.json)"""
    if not _RVT:
        try:
            _RVT.append(set(json.load(open(ROOT / 'work/donorfree-route/renamed/defined_nodraft.json'))))
        except Exception:
            _RVT.append(DEFINED)
    return _RVT[0]


_NVT = []
def _native_vtable(va):
    """original vtable address -> our link's vtable symbol of the same RTTI class and subobject offset (latest quicktest
    exe + map). Registry vtable labels were derived from an older native layout (JointsService's primary 00824acc was
    labelled 6BDebugable: the exact constructor stored the wrong vtable at offset 0)."""
    if not _NVT:
        tab = {}
        try:
            import pefile
            d = ROOT / 'work/donorfree-route'
            img = pefile.PE(str(d / 'run/RobloxQT.exe'), fast_load=True).get_memory_mapped_image()
            def _td(img_, v):
                col = struct.unpack_from('<I', img_, v - 4 - 0x400000)[0]
                off = struct.unpack_from('<I', img_, col + 4 - 0x400000)[0]
                td = struct.unpack_from('<I', img_, col + 12 - 0x400000)[0]
                return img_[td + 8 - 0x400000:img_.index(b'\0', td + 8 - 0x400000)].decode('latin-1'), off
            for m in re.finditer(r'\s(\?\?_7\S+)\s+([0-9a-f]{8})\s+(\S+)', (d / 'linkexp/qt.map').read_text(errors='replace')):
                if 'stubs' in m.group(3) or m.group(1) not in _realvt():   # stub zeros / a converted object's own (analog) vtable: not native
                    continue
                try:
                    tab.setdefault(_td(img, int(m.group(2), 16)), m.group(1))
                except Exception:
                    pass
        except Exception:
            pass
        _NVT.append(tab)
    try:
        base, image = match._image(CLIENT)
        col = struct.unpack_from('<I', image, va - 4 - base)[0]
        off = struct.unpack_from('<I', image, col + 4 - base)[0]
        td = struct.unpack_from('<I', image, col + 12 - base)[0]
        cls = bytes(image[td + 8 - base:td + 8 - base + 200]).split(b'\0', 1)[0].decode('latin-1')
    except Exception:
        return None
    if not cls.startswith(('.?AV', '.?AU')):
        return None
    hit = _NVT[0].get((cls, off))
    if hit:
        return hit
    # this class's vtable is missing from the last link: learn the native name suffix for this subobject offset from
    # classes with the same base layout (Instance-derived: offset 0 -> 6B?$GuidItem@VInstance@RBX@@@1@@)
    if len(_NVT) < 2:
        byc = {}
        for (c_, o_), s_ in _NVT[0].items():
            byc.setdefault(c_, {})[o_] = s_
        _NVT.append(byc)
    mine = set(_NVT[1].get(cls, {})) - {off}
    votes = {}
    for c_, offs in _NVT[1].items():   # classes with the same other subobjects (same base layout) vote for the suffix
        if c_ != cls and off in offs and mine and mine <= set(offs):
            k_ = offs[off].find('@@6B')
            if k_ > 0:
                votes[offs[off][k_ + 2:]] = votes.get(offs[off][k_ + 2:], 0) + 1
    s_ = max(votes, key=votes.get) if votes else None
    cand = '??_7' + cls[4:] + s_ if s_ else None
    return cand if cand and cand in _realvt() else None


def _is_vtable(va):
    """va is an original vtable: the word before it points to an RTTI complete object locator (signature 0)"""
    try:
        base, image = match._image(CLIENT)
        col = struct.unpack_from('<I', image, va - 4 - base)[0]
        if not (0x800000 <= col < 0x9a0000) or struct.unpack_from('<I', image, col - base)[0] != 0:
            return False
        td = struct.unpack_from('<I', image, col + 12 - base)[0]
        return bytes(image[td + 8 - base:td + 12 - base]) in (b'.?AV', b'.?AU')
    except Exception:
        return False


_OC = []
def _orig_classes():
    """RTTI type names of the original exe's polymorphic classes (vtdiff cache auto/orig_vt.pkl)"""
    if not _OC:
        try:
            import pickle
            _OC.append({k[0] for k in pickle.load(open(ROOT / 'work/donorfree-route/auto/orig_vt.pkl', 'rb'))[1]})
        except Exception:
            _OC.append(None)
    return _OC[0] if _OC[0] else _ALL


class _AllClasses(set):   # no RTTI cache: treat every class as original (no renames)
    def __contains__(self, x):
        return True
_ALL = _AllClasses()


_DOBJ = []
_NDM = []
def _native_data_map():
    """renamed/native_data.json: original data address -> native global (native_data.py)"""
    if not _NDM:
        try:
            _NDM.append(json.load(open(os.path.join(os.path.dirname(os.environ.get('ROC_ADDRMAP', '')), 'native_data.json'))))
        except Exception:
            _NDM.append({})
    return _NDM[0]


_DSZ = {}   # native-data start -> its size (native_data_sizes.json)


def _type_size(sym):
    """size of a global from the type in its decorated name, for the common small types: a 256-byte guess made the ATL
    thunk-pool globals (0097f308/0097f310) 'fields' of CXTRegistryManager::m_strINIFileName (a 4-byte CString) and ATL
    called a CString field as its allocator (NULL call in InitInstance)"""
    t_ = sym.split('@@', 1)[-1] if '@@' in sym else ''
    for pat, n_ in (('V?$CStringT@', 4), ('V?$basic_string@', 0x1c), ('V?$shared_ptr@', 8), ('V?$weak_ptr@', 8),
                    ('V?$scoped_ptr@', 4), ('V?$intrusive_ptr@', 4)):
        if pat in t_[:40]:
            return n_
    if re.match(r'^[0-9][A-Z]?(?:P[A-Z]|[HIJKMNDEFC_])', t_):   # pointer or scalar storage class + type
        return 4 if not t_[1:2] in ('N',) else 8
    return None


def _data_object(va):
    """(symbol, offset) when va lies inside a global that a dynamic initializer ??__E<name> constructs (mov ecx, start)
    and the link defines that global; else None."""
    import bisect
    if not _DOBJ:
        base_, img_ = match._image(CLIENT)
        starts = {}
        _by3 = {}   # '?name@@3...' indexed by name: scanning all ~271k DEFINED names per initializer took ~100 s per worker
        for d_ in DEFINED:
            if d_.startswith('?') and '@@3' in d_:
                _by3.setdefault(d_[1:d_.index('@@3')], []).append(d_)
        _einit = {}   # initializer's global symbol -> start addresses its initializers construct
        for a_, row in REGISTRY.items():
            nm = (row or {}).get('name') or ''
            m_ = re.match(r'^\?\?__E(.+)@@YAXXZ$', nm)
            if not m_:
                continue
            inner = m_.group(1)
            cands = [inner] if inner.startswith('?') else ['_' + inner] + sorted(_by3.get(inner, ()))
            sym = next((c for c in cands if c in DEFINED), None)
            if not sym:
                continue
            o_ = int(a_, 16) - base_
            for k_ in range(o_, o_ + 48):
                if img_[k_] == 0xb9:
                    st_ = struct.unpack_from('<I', img_, k_ + 1)[0]
                    if 0x800000 <= st_ < 0x9a0000:
                        _einit.setdefault(sym, set()).add(st_)
                    break
        # one name claimed by SEVERAL initializers' globals: identical initializer bodies folded under one registry name
        # (8 string initializers all labeled ??__EdummyString@RenderDevice@G3D: an int and 7 other globals became
        # G3D's dummyString). Ambiguous -> no binding; those globals stay dat_<addr> placeholders (original bytes).
        for sym, sts_ in _einit.items():
            if len(sts_) == 1:
                starts.setdefault(next(iter(sts_)), sym)
        try:   # native globals named by address in native sources (native_data.py: font2d 00962da8 -> pRep 00962dac)
            _d = os.path.dirname(os.environ.get('ROC_ADDRMAP', ''))
            _sz = json.load(open(os.path.join(_d, 'native_data_sizes.json')))
            for a_, sym in json.load(open(os.path.join(_d, 'native_data.json'))).items():
                if sym in DEFINED and _sz.get(sym):
                    starts.setdefault(int(a_, 16), sym)
                    _DSZ[int(a_, 16)] = _sz[sym]
        except Exception:
            pass
        _DOBJ.append(sorted(starts.items()))
    lst = _DOBJ[0]
    i_ = bisect.bisect_right(lst, (va, '￿')) - 1
    if i_ >= 0 and va - lst[i_][0] < (_DSZ.get(lst[i_][0]) or _type_size(lst[i_][1]) or 0x100) and (i_ + 1 >= len(lst) or lst[i_ + 1][0] > va):
        return lst[i_][1], va - lst[i_][0]
    return None


KNOWN, CHAIN = set(), {}
KEEPNAMES = set()
_HA = {}
def _has_analog(a):   # a server-verified 100% analog exists for that address (so func_<addr> can be converted, never stubbed)
    if a not in _HA:
        try:
            _HA[a] = open(ROOT / 'src' / CLIENT / (a + '.cpp'), errors='replace').readline().startswith('// from server: 100%')
        except Exception:
            _HA[a] = False
    return _HA[a]
try:
    STARTS = set(json.load(open(ROOT / 'work/native-client/layout/function-files.json')))
except Exception:
    STARTS = set()
DEFINED = set(json.load(open(os.environ['ROC_RENAME_DEFINED']))) if os.environ.get('ROC_RENAME_DEFINED') else set()


def apply_registry(paths, gates):
    """Rename tracked placeholders only; never guess source identifiers."""
    changed, planned, blocked = [], {}, []
    for root in paths:
        root = Path(root)
        files = root.rglob('*') if root.is_dir() else [root]
        for path in files:
            if path.suffix.lower() not in ('.c', '.cc', '.cpp', '.cxx', '.h', '.hpp', '.inl', '.inc'):
                continue
            text = path.read_text(errors='surrogateescape')
            new = text
            for addr, row in REGISTRY.items():
                if row.get('placeholder'):
                    continue
                pattern = r'\b(?:roc_)?func_' + addr + r'\b'
                if not re.search(pattern, new):
                    continue
                if not re.fullmatch(r'[A-Za-z_][A-Za-z_0-9]*', row['name']):
                    blocked.append({'path': str(path), 'address': addr, 'linker_name': row['name']})
                    continue
                new = re.sub(pattern, lambda _: row['name'], new)
            if new != text:
                planned[path] = new
    if blocked:
        raise SystemExit(json.dumps({'status': 'semantic-rename-required', 'blocked': blocked,
                                     'renames_applied': 0}))
    if planned and not gates:
        raise SystemExit('source renames require affected gates via --gate=COMMAND')
    for path, new in planned.items():
        path.write_text(new, errors='surrogateescape')
        changed.append(str(path))
    for gate in gates:
        if subprocess.run(gate, cwd=ROOT, shell=True).returncode:
            raise SystemExit('affected gate failed: ' + gate)
    print(json.dumps({'renames_applied': len(changed), 'changed_files': changed, 'gates': gates}))


def main():
    global REGISTRY
    if '--apply-registry' in sys.argv:
        at = sys.argv.index('--apply-registry')
        tail = sys.argv[at + 1:]
        gates = [x[7:] for x in tail if x.startswith('--gate=')]
        paths = [x for x in tail if not x.startswith('--gate=')]
        if not paths:
            raise SystemExit('--apply-registry needs source/header paths')
        REGISTRY = load_registry()
        apply_registry(paths, gates)
        return
    amap = json.load(open(os.environ.get('ROC_ADDRMAP') or NC / 'link/addrmap.json'))
    jobs = {v['exact'][0]: s for s, v in amap.items() if v['exact']}
    # global allocation operators / CRT entry names belong to the CRT import: a converted object that defined them would
    # replace them for the whole exe (00508530, a G3D allocator labelled ??2@YAPAXI@Z, made operator new call itself)
    _GLOBAL = re.compile(r'^\?\?(?:2|3|_U|_V)@Y|^_(?:malloc|free|realloc|calloc|memset|memcpy|memmove|strlen|_purecall|atexit)$')
    # anonymous-namespace (file-local) names cannot be linked from another object: address name instead
    # anonymous-namespace (file-local) names cannot be linked from another object; a name the registry gives to several
    # addresses is unproved (0064a310, a JointStage factory, was labelled as the JointStage constructor it calls -> self
    # recursion): address name instead
    _nm_count = {}
    for _a, _v in json.load(open(ROOT / 'work/native-client/layout/function-files.json')).items():
        _n = (_v or {}).get('name') or ''
        if _n.startswith('?'):
            _nm_count[_n] = _nm_count.get(_n, 0) + 1
    jobs = {a: ('func_' + a if (_GLOBAL.match(s_) or '@?A0x' in s_ or a in DUPNAMES or _nm_count.get(s_, 0) > 1) else s_)
            for a, s_ in jobs.items()}
    RJ = Path(os.environ['ROC_RENAME_JSON']) if os.environ.get('ROC_RENAME_JSON') else NC / 'link/rename.json'
    res = json.load(open(RJ)) if RJ.exists() else {}
    for obj in ([] if sys.argv[1:] else OUT.glob('*.obj')):   # earlier conversions stay recorded (only for a full run:
        # with explicit addresses rename_par merges results itself, and re-parsing ~21k objects per worker took minutes)
        if res.get(obj.stem, {}).get('status') != 'renamed':
            try:   # an empty/truncated object (process killed mid-write) must not abort every later conversion batch
                defs = [n for n, k in _SC['symbols'](obj.read_bytes()).items() if k == 'strong']
            except Exception:
                continue
            res[obj.stem] = dict(symbol=defs[0] if defs else '?', status='renamed')
    sel = sys.argv[1:] or sorted(a for a in jobs if res.get(a, {}).get('status') != 'renamed')
    target = fingerprint.Target(CLIENT)
    REGISTRY = load_registry()
    global KNOWN
    KNOWN = set(DEFINED) if os.environ.get('ROC_RENAME_DEFINED') else known_symbols()   # donor-free: names THIS link defines
    if (NC / 'link/names.json').exists():
        HEADER_NAMES.update(json.load(open(NC / 'link/names.json')))
    CHAIN.update({a: r['symbol'] for a, r in res.items() if r.get('status') == 'renamed'})
    CHAIN.update({a: s for a, s in jobs.items()})   # calls between targets resolve to their real names
    if os.environ.get('ROC_RENAME_DEFINED'):   # identical-code-folded addresses whose registry name means something else in our build
        _ov = Path(os.environ['ROC_RENAME_DEFINED']).parent / 'name_overrides.json'
        if _ov.exists():
            CHAIN.update(json.load(open(_ov)))
    DEFINED.update(jobs.values())   # names this conversion set itself will define
    for addr in sel:
        try:
            res[addr] = dict(symbol=jobs[addr], **convert(addr, jobs[addr], target))
        except (Exception, SystemExit) as e:      # one bad analog must not stop the batch (a library sys.exit too)
            import traceback as _tb
            res[addr] = dict(symbol=jobs[addr], status='error', why=repr(e)[:200], where=_tb.format_exc()[-600:])
        print(addr, res[addr]['status'], res[addr].get('why', '') if res[addr]['status'] != 'renamed' else '', flush=True)
        _done_n = globals().get('_done_n', 0) + 1; globals()['_done_n'] = _done_n
        if _done_n % 50 == 0:   # partial results survive a killed worker (rename_par re-queues only the rest)
            json.dump(res, open(RJ, 'w'), indent=1)
    json.dump(res, open(RJ, 'w'), indent=1)
    from collections import Counter
    print(Counter(r['status'] for r in res.values()))


if __name__ == '__main__':
    main()
