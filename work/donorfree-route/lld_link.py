"""python lld_link.py: link the donor-free exe with LLVM lld-link (multithreaded) from link/donorfree.rsp.
lld refuses conflicting /alternatename pairs that link.exe silently resolves (first wins). This keeps link.exe's behaviour:
command-line aliases are deduplicated (first wins) and, for each conflict lld reports, every later input that embeds that
alias directive is copied to linkexp/patched/ with the directive blanked. Output: link/donorfree.exe + link/donorfree.map
(+ link/lld.log). Exit code = lld's."""
import json, os, re, shutil, subprocess, sys, time
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[2]))
from roc import rebuild
ENV = rebuild.env(rebuild.toolchain(21022))   # same LIB/INCLUDE as link.exe: lld finds msvcprt.lib etc.

H = Path(__file__).parent
LLD = r'C:\Program Files\LLVM\bin\lld-link.exe'
_TAG = os.environ.get('QT_TAG', '')   # quicktest.py parallel variant: own patched copies + fixes file, no races
P = H / ('linkexp/patched' + _TAG)
P.mkdir(parents=True, exist_ok=True)
DISCOVER = '--discover' in sys.argv   # only the unresolved list (plain link), written as link.exe-style link/link.log
lines = Path(os.environ.get('LLD_RSP') or (H / 'link/donorfree.rsp')).read_text().splitlines()   # LLD_RSP: quicktest.py's own input
if '--test' in sys.argv:   # trial output only: never touch link/donorfree.exe
    lines = [('"/OUT:%s"' % (H / 'linkexp/test.exe')) if l.startswith('"/OUT:') else ('"/MAP:%s"' % (H / 'linkexp/test.map')) if l.startswith('"/MAP:') else l for l in lines]
if '--xtp-first' in sys.argv:   # XTP libs before mfc90.lib: their inline CString members win over the import (what link.exe effectively does)
    xtp = [l for l in lines if '/XTP' in l.replace(chr(92), '/') and l.lower().endswith('.lib"')]
    rest = [l for l in lines if l not in xtp]
    k = next((i for i, l in enumerate(rest) if l.lower().endswith('mfc90.lib"')), len(rest))
    lines = rest[:k] + xtp + rest[k:]
if DISCOVER:
    lines = [('"/OUT:%s"' % (H / 'linkexp/discover.exe')) if l.startswith('"/OUT:') else ('"/MAP:%s"' % (H / 'linkexp/discover.map')) if l.startswith('"/MAP:') else l for l in lines]
out, seen = ['"/SAFESEH:NO"', '"/DYNAMICBASE:NO"', '"/NXCOMPAT:NO"', '"/demangle:no"'], set()   # VS2008 link.exe defaults: fixed base 0x400000, no DEP opt-in   # link.exe never required SafeSEH here; MASM stubs.obj has no SEH table
for l in lines:
    if l.lower().startswith('"/alternatename:'):
        k = l.split(':', 1)[1].split('=')[0]
        if k in seen:
            continue
        seen.add(k)
    out.append(l)
_MD = {}


def MFC_DEM():
    """demangled (spaces removed) -> mangled for every name exported through mfc90.lib; cached in linkexp/mfc90_dem.json."""
    if _MD:
        return _MD
    cf = H / 'linkexp/mfc90_dem.json'
    try:
        _MD.update(json.loads(cf.read_text()))
        return _MD
    except Exception:
        pass
    lib = next((l.strip('"') for l in (H / 'link/donorfree.rsp').read_text().splitlines() if l.lower().endswith('mfc90.lib"')), None)
    names = sorted(set(m.decode() for m in re.findall(rb'(?<![_A-Za-z])(\?[A-Za-z0-9_@?$]{4,})\x00', Path(lib).read_bytes()))) if lib else []
    for i in range(0, len(names), 200):
        und = subprocess.run([str(H.parents[1] / 'tools/msvc800sp1/VC/bin/undname.exe')] + names[i:i + 200], capture_output=True, text=True).stdout
        for a, b in re.findall(r'Undecoration of :- "(.*)"' + r'\s*\nis :- "(.*)"', und):
            _MD[b.replace(' ', '')] = a
    cf.write_text(json.dumps(_MD))
    return _MD


rsp = Path(os.environ['LLD_RSP']).with_suffix('.final.rsp') if os.environ.get('LLD_RSP') else H / 'linkexp/lld_final.rsp'   # own file per caller (cycle vs quicktest/autoflip raced)
FIX = H / ('linkexp/lld_fixes%s.json' % _TAG)
if _TAG and not FIX.exists() and (H / 'linkexp/lld_fixes.json').exists():   # a variant starts from the shared fixes
    FIX.write_text((H / 'linkexp/lld_fixes.json').read_text())
try:
    _fx = json.loads(FIX.read_text())
except Exception:
    _fx = {'replaced': [], 'dropped_alias': []}
REPLACED = {}
CANDS = ['??A?$CSimpleStringT@D$00@ATL@@QBEDH@Z']   # known mangled names of 'was replaced' symbols (undname lookup)
t0 = time.time()
_drop = set(_fx['dropped_alias'])


def _dedup_alias(out, keys):
    """for each conflicting KEY keep its FIRST /alternatename line, drop the rest. Dropping EVERY line (the old rule)
    left the name undefined -> a stub over real code (??$?0H@Value@@ -> the Value<int> ctor in 0042d280.obj: 49 such)"""
    seen, res = set(), []
    for l in out:
        if l.lower().startswith('"/alternatename:'):
            k = l.split(':', 1)[1].split('=')[0]
            if k in keys:
                if k in seen:
                    continue
                seen.add(k)
        res.append(l)
    return res


out = _dedup_alias(out, _drop)
_rvo = set(_fx.get('rsp_alias_vs_obj', []))   # our line loses to an object's own directive: drop it up front
out = [l for l in out if not (l.lower().startswith('"/alternatename:') and l.split(':', 1)[1].split('=')[0] in _rvo)]
_fx['mfc_static'] = sorted(set(_fx.get('mfc_static', [])) | set(_fx.get('replaced', [])))
_fx['replaced'] = []
def MFC_NAMES():
    """every decorated name mfc90.lib exports (cached)"""
    cf = H / 'linkexp/mfc90_names.json'
    try:
        return set(json.loads(cf.read_text()))
    except Exception:
        pass
    lib = next((l.strip('"') for l in (H / 'link/donorfree.rsp').read_text().splitlines() if l.lower().endswith('mfc90.lib"')), None)
    names = sorted(set(m.decode() for m in re.findall(rb'(?<![_A-Za-z])(\?[A-Za-z0-9_@?$]{4,})\x00', Path(lib).read_bytes()))) if lib else []
    cf.write_text(json.dumps(names))
    return set(names)


def _rename_defs_only(b, ren):
    """ren {name\\0: newname\\0} (same length). Rename only where the name is DEFINED: in the archive's linker members
    (they index definitions) and inside the member object that defines it. Members that merely reference the name keep
    it, so they bind to the mfc90.dll import (XTP's calls to AfxGetModuleState used to follow the rename to the static,
    uninitialised module-state copy and crashed in theme creation)."""
    import struct as _s
    b = bytearray(b)
    if not b.startswith(b'!<arch>\n'):
        return bytes(b)
    pos = 8
    while pos + 60 <= len(b):
        name = bytes(b[pos:pos + 16]).rstrip()
        size = int(bytes(b[pos + 48:pos + 58]).strip() or b'0')
        d0, d1 = pos + 60, pos + 60 + size
        if name == b'/':   # linker members: definitions only
            for a_, n_ in ren.items():
                q = b.find(a_, d0, d1)
                while q >= 0:
                    if q == d0 or b[q - 1] == 0 or q > 0:
                        b[q:q + len(a_)] = n_
                    q = b.find(a_, q + len(a_), d1)
        elif name != b'//' and size >= 20 and _s.unpack_from('<H', b, d0)[0] == 0x14c:
            try:
                symptr, nsym = _s.unpack_from('<II', b, d0 + 8)
                strtab = d0 + symptr + nsym * 18
                i = 0
                while i < nsym:
                    at = d0 + symptr + 18 * i
                    raw = bytes(b[at:at + 8]); sec = _s.unpack_from('<h', b, at + 12)[0]; cls = b[at + 16]; naux = b[at + 17]
                    if cls == 2 and sec > 0 and raw[:4] == b'\0\0\0\0':
                        so = strtab + _s.unpack_from('<I', raw, 4)[0]
                        e = b.find(b'\0', so)
                        key = bytes(b[so:e + 1])
                        if key in ren:
                            b[so:e + 1] = ren[key]
                    i += 1 + naux
            except Exception:
                pass
        pos = d1 + (d1 & 1)
    return bytes(b)


def apply_mfc_static(out):
    """static copies (verified library objects) of functions mfc90.dll exports: rename them inside patched copies of those
    libraries so the DLL import wins, as in the original exe and the link.exe build (CWnd::get_accRole & co.)"""
    names = _fx.get('mfc_static', [])
    if not names:
        return out
    pats = [(n.encode('latin-1') + b'\0', (n[:-1] + ('Y' if n[-1] != 'Y' else 'X')).encode('latin-1') + b'\0') for n in names]
    # cached per library (stat + name-list hash): re-reading and re-patching every big MFC/XTP .lib on every link was
    # most of the wrapper's minutes; unchanged inputs reuse the earlier decision / patched copy
    import hashlib as _hl2
    _nk = _hl2.md5('\n'.join(sorted(names)).encode('latin-1')).hexdigest()
    _cf = H / ('linkexp/mfc_static_cache%s.json' % _TAG)
    try:
        _c = json.loads(_cf.read_text())
    except Exception:
        _c = {}
    for i, l in enumerate(out):
        p = l.strip('"')
        if not p.lower().endswith('.lib') or 'mfc90' in p.lower() or not Path(p).exists() or str(P) in p:
            continue
        st = Path(p).stat()
        key = '%d:%d:%s' % (st.st_mtime_ns, st.st_size, _nk)
        q = P / ('ms%d' % i) / Path(p).name
        e = _c.get(p)
        if e and e[0] == key and (e[1] is None or Path(e[1]).exists()):
            if e[1]:
                out[i] = '"%s"' % e[1]
            continue
        b = Path(p).read_bytes()
        hit = [x for x in pats if x[0] in b]
        if not hit:
            _c[p] = [key, None]
            continue
        b = _rename_defs_only(b, dict(hit))
        (P / ('ms%d' % i)).mkdir(exist_ok=True)
        q.write_bytes(b)
        out[i] = '"%s"' % q
        _c[p] = [key, str(q)]
    _cf.write_text(json.dumps(_c))
    return out


def _blank_alias(out, key, keep_first=True):
    """an /alternatename directive for KEY in several objects conflicts: keep the first, blank it (same length) in copies
    of the others. keep_first=False blanks EVERY object's directive (the response file's alias to real code wins)"""
    pat = re.compile(rb'/alternatename:' + re.escape(key.encode('latin1')) + rb'=[^\s"]+', re.I)
    first = keep_first
    for i, l in enumerate(out):
        p = l.strip('"')
        if not p.lower().endswith(('.obj', '.lib')):
            continue
        try:
            b = Path(p).read_bytes()
        except OSError:
            continue
        if not pat.search(b):
            continue
        if first:
            first = False
            continue
        b = pat.sub(lambda mm: b' ' * len(mm.group(0)), b)   # same length: offsets inside the COFF stay valid
        q = P / ('%d_%s' % (i, Path(p).name))
        q.write_bytes(b)
        out[i] = '"%s"' % q
    return out


_fx.setdefault('mfc_static', [])
_tp = time.time()
out = apply_mfc_static(out)
print('[lld_link] mfc static patch %.1fs' % (time.time() - _tp), flush=True)
# (removed 2026-11-24: per-key pre-apply loops over alt_conflict / obj_alias_blank. Each key re-read ALL ~19.8k objects
#  -- 26+ keys = tens of GB per link, the 2-5 min "lld" time while lld itself takes 19 s. _preresolve_aliases below
#  resolves both conflict kinds in one cached pass.)


def _preresolve_aliases(out):
    """resolve EVERY /alternatename conflict before the first lld run (lld reports one per run: 28 rounds = +6 min).
    Index each linked object's embedded directives (cached by mtime/size), then: a key our response file sets -> ours
    wins, blank it in every object; a key several objects set to DIFFERENT targets -> the first object's wins.
    Several response-file lines for one key -> the first. Blanking is batched: one patched copy per object."""
    import pickle
    pat = re.compile(rb'/alternatename:([^=\s"]+)=([^\s"]+)', re.I)
    cf = H / ('linkexp/obj_alias_cache%s.pkl' % _TAG)
    if _TAG and not cf.exists() and (H / 'linkexp/obj_alias_cache.pkl').exists():
        shutil.copyfile(H / 'linkexp/obj_alias_cache.pkl', cf)
    try:
        cache = pickle.load(open(cf, 'rb'))
    except Exception:
        cache = {}
    dirty = False
    objs = []   # (index in out, path, {key: value})
    for i, l in enumerate(out):
        p = l.strip('"')
        # libraries too: their members' directives caused the 6 conflicts left after the object-only pass (each one a
        # full lld run + a reread of every object, ~40 s apiece). Same-length blanking keeps archive offsets valid.
        if not p.lower().endswith(('.obj', '.lib')):
            continue
        try:
            st = os.stat(p)
        except OSError:
            continue
        k = (st.st_mtime_ns, st.st_size)
        v = cache.get(p)
        if not v or v[0] != k:
            b = Path(p).read_bytes()
            v = cache[p] = (k, {m.group(1).decode('latin-1'): m.group(2).decode('latin-1') for m in pat.finditer(b)} if b'/alternatename:' in b.lower() or b'/ALTERNATENAME:' in b else {})
            dirty = True
        if v[1]:
            objs.append((i, p, v[1]))
    if dirty:
        pickle.dump(cache, open(cf, 'wb'), protocol=4)
    ours = {}
    keep = []
    for l in out:   # response-file aliases: the first line per key wins
        if l.lower().startswith('"/alternatename:'):
            k_, _, v_ = l[len('"/alternatename:'):].rstrip('"').partition('=')
            if k_ in ours:
                continue
            ours[k_] = v_
        keep.append(l)
    out = keep
    first = {}
    blank = {}   # object index -> keys to blank there
    for i, p, al in objs:
        for k_, v_ in al.items():
            if k_ in ours:
                if v_ != ours[k_]:
                    blank.setdefault(i, set()).add(k_)
            elif k_ in first:
                if first[k_] != v_:
                    blank.setdefault(i, set()).add(k_)
            else:
                first[k_] = v_
    for i, ks in blank.items():
        p = out[i].strip('"')
        b = Path(p).read_bytes()
        for k_ in ks:
            b = re.sub(rb'/alternatename:' + re.escape(k_.encode('latin-1')) + rb'=[^\s"]+', lambda mm: b' ' * len(mm.group(0)), b, flags=re.I)
        q = P / ('pre%d_%s' % (i, Path(p).name))
        q.write_bytes(b)
        out[i] = '"%s"' % q
    print('alias conflicts pre-resolved: %d keys blanked in %d objects' % (sum(map(len, blank.values())), len(blank)))
    return out


_tp = time.time()
try:
    out = _preresolve_aliases(out)
except Exception as _e:
    print('alias pre-resolution skipped:', _e)
print('[lld_link] alias pre-resolution %.1fs' % (time.time() - _tp), flush=True)
for rnd in range(40):
    rsp.write_text('\n'.join(out) + '\n')
    r = subprocess.run([LLD, '@' + str(rsp)], capture_output=True, text=True, env=ENV, errors='replace')
    log = r.stdout + r.stderr
    for _w in range(5):   # output/map briefly locked (a reader or a scanner): wait and retry instead of losing the link
        if 'permission denied' not in log:
            break
        time.sleep(3)
        r = subprocess.run([LLD, '@' + str(rsp)], capture_output=True, text=True, env=ENV, errors='replace')
        log = r.stdout + r.stderr
    mr = re.search(r'error: (.+?) was replaced', log)
    if mr and not re.search(r'/alternatename: conflicts', log):
        # a static definition (vendor lib) collides with an import thunk: rename it, same length, inside a copy of each
        # library that defines it, so those objects keep their own copy and everything else uses the import (= link.exe)
        dem = mr.group(1)
        _k = dem.replace(' ', '')
        _tail = lambda x: x[x.find('__'):] if '__' in x else x   # from the calling convention on (lld prints conversion-operator return types)
        mang = (dem if dem.startswith('?') else None) or REPLACED.get(dem) or MFC_DEM().get(_k) or next((v for kk, v in MFC_DEM().items() if _tail(kk) == _tail(_k)), None)
        if not mang:
            und = subprocess.run([str(H.parents[1] / 'tools/msvc800sp1/VC/bin/undname.exe')] + CANDS, capture_output=True, text=True).stdout
            mang = next((a for a, b in re.findall(r'Undecoration of :- "(.*)"'+r'\s*\nis :- "(.*)"', und) if dem.replace(' ', '') in b.replace(' ', '')), None)
        if not mang:
            break
        print('unresolved MFC static/import conflict:', mang)
        break
    m = re.search(r'/alternatename: conflicts: ([^=\s]+)=', log)
    if not m:
        break
    key = m.group(1)
    _nk = sum(1 for l in out if l.lower().startswith('"/alternatename:') and l.split(':', 1)[1].split('=')[0] == key)
    if _nk > 1:   # several response-file lines for KEY: keep the first (dropping all left a stub over real code)
        out = _dedup_alias(out, {key})
        _fx['dropped_alias'] = sorted(set(_fx['dropped_alias']) | {key}); FIX.write_text(json.dumps(_fx))
        _drop.add(key)
        continue
    if _nk == 1:
        # our alias (to real code: the Value<int> ctor) vs an object's own directive (to an analog name nothing defines):
        # ours wins -- blank every object's directive in copies. Dropping ours left the name at address 0 (absolute).
        # Remembered, so later links pre-apply it instead of one lld run per key (26 rounds, +4 min).
        out = _blank_alias(out, key, keep_first=False)
        _fx['obj_alias_blank'] = sorted(set(_fx.get('obj_alias_blank', [])) | {key}); FIX.write_text(json.dumps(_fx))
        continue
    out = _blank_alias(out, key)
    _fx['alt_conflict'] = sorted(set(_fx.get('alt_conflict', [])) | {key}); FIX.write_text(json.dumps(_fx))
Path(os.environ.get('LLD_LOG') or (H / 'link/lld.log')).write_text(log)
_mapl0 = next((l[6:-1] for l in out if l.startswith('"/MAP:')), None)
if not DISCOVER and _mapl0 and Path(_mapl0).exists() and not os.environ.get('ROC_LLD_NO_MFCFIX'):
    _mn = MFC_NAMES()
    _won = sorted({m.group(1) for m in re.finditer(r'^\s*0001:[0-9a-f]+\s+(\?\S+)\s+[0-9a-f]+\s+(?:f\s+)?(?:i\s+)?linked:\S+', Path(_mapl0).read_text(errors='replace'), re.M)
                   if m.group(1) in _mn} - set(_fx['mfc_static']))
    if _won:   # static MFC copies won over the DLL import: patch them out and link once more
        _fx['mfc_static'] = sorted(set(_fx['mfc_static']) | set(_won)); FIX.write_text(json.dumps(_fx))
        out = apply_mfc_static(out)
        rsp.write_text('\n'.join(out) + '\n')
        r = subprocess.run([LLD, '@' + str(rsp)], capture_output=True, text=True, env=ENV, errors='replace')
        log = r.stdout + r.stderr
        Path(os.environ.get('LLD_LOG') or (H / 'link/lld.log')).write_text(log)
        print('mfc90 imports restored over %d static MFC copies' % len(_won))
_mapl = next((l[6:-1] for l in out if l.startswith('"/MAP:')), None)
if _mapl and Path(_mapl).exists():   # lld prints 16-digit addresses; our tools read link.exe's 8-digit map
    _t = Path(_mapl).read_text(errors='replace')
    Path(_mapl).write_text(re.sub(r'(?<=\s)0{8}([0-9a-f]{8})(?=\s)', r'\1', _t))
if DISCOVER:
    und = sorted(set(re.findall(r'undefined symbol: (' + chr(92) + 'S+)', log)))
    (H / 'link/link.log').write_text(''.join('lld.obj : error LNK2001: unresolved external symbol %s' % u + chr(10) for u in und))
    print('discover: %d unresolved in %.0fs' % (len(und), time.time() - t0))
    sys.exit(0)
print('lld exit %d in %.0fs (%d conflict rounds); undefined %d' % (r.returncode, time.time() - t0, rnd, log.count('undefined symbol')))
sys.exit(r.returncode)
