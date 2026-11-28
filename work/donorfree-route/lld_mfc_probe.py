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
P = H / 'linkexp_mfcprobe/patched'
P.mkdir(parents=True, exist_ok=True)
DISCOVER = '--discover' in sys.argv   # only the unresolved list (plain link), written as link.exe-style link/link.log
lines = (H / 'linkexp_mfcprobe/donorfree.rsp').read_text().splitlines()
if '--test' in sys.argv:   # trial output only: never touch link/donorfree.exe
    lines = [('"/OUT:%s"' % (H / 'linkexp_mfcprobe/test.exe')) if l.startswith('"/OUT:') else ('"/MAP:%s"' % (H / 'linkexp_mfcprobe/test.map')) if l.startswith('"/MAP:') else l for l in lines]
if '--xtp-first' in sys.argv:   # XTP libs before mfc90.lib: their inline CString members win over the import (what link.exe effectively does)
    xtp = [l for l in lines if '/XTP' in l.replace(chr(92), '/') and l.lower().endswith('.lib"')]
    rest = [l for l in lines if l not in xtp]
    k = next((i for i, l in enumerate(rest) if l.lower().endswith('mfc90.lib"')), len(rest))
    lines = rest[:k] + xtp + rest[k:]
if DISCOVER:
    lines = [('"/OUT:%s"' % (H / 'linkexp_mfcprobe/discover.exe')) if l.startswith('"/OUT:') else ('"/MAP:%s"' % (H / 'linkexp_mfcprobe/discover.map')) if l.startswith('"/MAP:') else l for l in lines]
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
    cf = H / 'linkexp_mfcprobe/mfc90_dem.json'
    try:
        _MD.update(json.loads(cf.read_text()))
        return _MD
    except Exception:
        pass
    lib = next((l.strip('"') for l in (H / 'linkexp_mfcprobe/donorfree.rsp').read_text().splitlines() if l.lower().endswith('mfc90.lib"')), None)
    names = sorted(set(m.decode() for m in re.findall(rb'(?<![_A-Za-z])(\?[A-Za-z0-9_@?$]{4,})\x00', Path(lib).read_bytes()))) if lib else []
    for i in range(0, len(names), 200):
        und = subprocess.run([str(H.parents[1] / 'tools/msvc800sp1/VC/bin/undname.exe')] + names[i:i + 200], capture_output=True, text=True).stdout
        for a, b in re.findall(r'Undecoration of :- "(.*)"' + r'\s*\nis :- "(.*)"', und):
            _MD[b.replace(' ', '')] = a
    cf.write_text(json.dumps(_MD))
    return _MD


rsp = H / 'linkexp_mfcprobe/lld_final.rsp'
FIX = H / 'linkexp_mfcprobe/lld_fixes.json'
try:
    _fx = json.loads(FIX.read_text())
except Exception:
    _fx = {'replaced': [], 'dropped_alias': []}
REPLACED = {}
CANDS = ['??A?$CSimpleStringT@D$00@ATL@@QBEDH@Z']   # known mangled names of 'was replaced' symbols (undname lookup)
t0 = time.time()
_drop = set(_fx['dropped_alias'])
out = [l for l in out if not (l.lower().startswith('"/alternatename:') and l.split(':', 1)[1].split('=')[0] in _drop)]
for _mang in _fx['replaced']:   # known import/definition collisions: patch the mfc90.lib copy before the first try
    for i, l in enumerate(out):
        p = l.strip('"')
        if p.lower().endswith('mfc90.lib') and Path(p).exists():
            (P / ('lib%d' % i)).mkdir(exist_ok=True)
            q = P / ('lib%d' % i) / Path(p).name
            if Path(p).resolve() != q.resolve():
                q.write_bytes(Path(p).read_bytes())
            q.write_bytes(q.read_bytes().replace(_mang.encode(), (_mang[:-1] + ('Y' if _mang[-1] != 'Y' else 'X')).encode()))
            out[i] = '"%s"' % q
def MFC_NAMES():
    """every decorated name mfc90.lib exports (cached)"""
    cf = H / 'linkexp_mfcprobe/mfc90_names.json'
    try:
        return set(json.loads(cf.read_text()))
    except Exception:
        pass
    lib = next((l.strip('"') for l in (H / 'linkexp_mfcprobe/donorfree.rsp').read_text().splitlines() if l.lower().endswith('mfc90.lib"')), None)
    names = sorted(set(m.decode() for m in re.findall(rb'(?<![_A-Za-z])(\?[A-Za-z0-9_@?$]{4,})\x00', Path(lib).read_bytes()))) if lib else []
    cf.write_text(json.dumps(names))
    return set(names)


def apply_mfc_static(out):
    """static copies (verified library objects) of functions mfc90.dll exports: rename them inside patched copies of those
    libraries so the DLL import wins, as in the original exe and the link.exe build (CWnd::get_accRole & co.)"""
    names = _fx.get('mfc_static', [])
    if not names:
        return out
    pats = [(n.encode('latin-1') + b'\0', (n[:-1] + ('Y' if n[-1] != 'Y' else 'X')).encode('latin-1') + b'\0') for n in names]
    for i, l in enumerate(out):
        p = l.strip('"')
        if not p.lower().endswith('.lib') or 'mfc90' in p.lower() or not Path(p).exists() or str(P) in p:
            continue
        b = Path(p).read_bytes()
        hit = [x for x in pats if x[0] in b]
        if not hit:
            continue
        for a_, b_ in hit:
            b = bytearray(b)
            pos = b.find(a_)
            while pos >= 0:
                if pos == 0 or b[pos - 1] not in b'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_?@$':
                    b[pos:pos + len(a_)] = b_
                pos = b.find(a_, pos + len(a_))
            b = bytes(b)
        (P / ('ms%d' % i)).mkdir(exist_ok=True)
        q = P / ('ms%d' % i) / Path(p).name
        q.write_bytes(b)
        out[i] = '"%s"' % q
    return out


_fx.setdefault('mfc_static', [])
out = apply_mfc_static(out)
for rnd in range(40):
    rsp.write_text('\n'.join(out) + '\n')
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
        new = (mang[:-1] + ('Y' if mang[-1] != 'Y' else 'X')).encode()
        for i, l in enumerate(out):
            p = l.strip('"')
            if p.lower().endswith('.lib') and Path(p).exists() and mang.encode() in Path(p).read_bytes() and 'mfc90' in p.lower():   # drop the import: the inline copy is the same code
                (P / ('lib%d' % i)).mkdir(exist_ok=True)
                q = P / ('lib%d' % i) / Path(p).name   # same file name: objects' /DEFAULTLIB:mfc90.lib must still match it
                q.write_bytes(Path(p).read_bytes().replace(mang.encode(), new))
                out[i] = '"%s"' % q
        REPLACED[dem] = mang
        _fx['replaced'] = sorted(set(_fx['replaced']) | {mang}); FIX.write_text(json.dumps(_fx))
        continue
    m = re.search(r'/alternatename: conflicts: ([^=\s]+)=', log)
    if not m:
        break
    key = m.group(1)
    if any(l.lower().startswith('"/alternatename:') and l.split(':', 1)[1].split('=')[0] == key for l in out):
        out = [l for l in out if not (l.lower().startswith('"/alternatename:') and l.split(':', 1)[1].split('=')[0] == key)]
        _fx['dropped_alias'] = sorted(set(_fx['dropped_alias']) | {key}); FIX.write_text(json.dumps(_fx))
        continue
    pat = re.compile(rb'/alternatename:' + re.escape(key.encode('latin1')) + rb'=[^\s"]+', re.I)
    first = True
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
(H / 'linkexp_mfcprobe/lld.log').write_text(log)
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
        (H / 'linkexp_mfcprobe/lld.log').write_text(log)
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
