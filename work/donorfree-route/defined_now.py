"""python defined_now.py: the names the donor-free link really defines NOW: native objects (link/obj_ext_cache.pkl, kept
fresh by auto_aliases.py) + every public symbol of every .lib in link/donorfree.rsp (archive linker member) + the
conversion jobs' own symbols. Writes renamed/defined.json for rename.py (ROC_RENAME_DEFINED).
Replaces the old 'every symbol ever seen' cache: 80k stale names made the converter skip remapping calls to functions
nothing defines any more (??0Instance@RBX@@IAE@XZ from 397 exact objects -> stubs)."""
import json, os, pickle, struct
from pathlib import Path
H = Path(__file__).parent


def lib_symbols(path):
    """public symbols from a COFF archive's first linker member ("/": big-endian count, offsets, names). Reads only that
    member (was: the whole archive, 80 MB tmplinst.lib, 3+ times per quicktest run); memoized per (path, mtime, size)."""
    p = Path(path)
    st = p.stat()
    k = (str(p), st.st_mtime_ns, st.st_size)
    if k in _LS:
        return set(_LS[k])
    with open(p, 'rb') as f:
        head = f.read(68)
        if not head.startswith(b'!<arch>\n') or head[8:24].strip() != b'/':
            _LS[k] = frozenset()
            return set()
        body = f.read(int(head[56:66].strip()))
    n = struct.unpack_from('>I', body, 0)[0]
    names = body[4 + 4 * n:].split(b'\0')[:n]
    _LS[k] = frozenset(x.decode('latin-1') for x in names if x)
    return set(_LS[k])


_LS = {}


def _signature():
    """inputs of this run: rsp text, stat of every native object/library it names, quicktest's swapped results, addrmap,
    the toolchain LIB path. Unchanged -> outputs are current (the run took ~9.5 s of every renamed_link)."""
    import hashlib
    h = hashlib.md5()
    rsp = (H / 'link/donorfree.rsp').read_text()
    h.update(rsp.encode('latin-1', 'replace'))
    for _l in rsp.splitlines():
        _p = _l.strip().strip('"')
        if _p.lower().endswith(('.obj', '.lib')) and 'renamed' + os.sep + 'obj' not in os.path.normpath(_p):
            try:
                _st = os.stat(_p); h.update(('%s|%d|%d' % (_p, _st.st_mtime_ns, _st.st_size)).encode('latin-1', 'replace'))
            except OSError:
                h.update(_p.encode('latin-1', 'replace'))
    for _f in ('linkexp/qt_results.txt', 'renamed/addrmap.json'):
        try:
            _st = os.stat(H / _f); h.update(('%s|%d|%d' % (_f, _st.st_mtime_ns, _st.st_size)).encode())
            if _f.endswith('.txt'):
                for _r in (H / _f).read_text().split():
                    _st = os.stat(_r); h.update(('%s|%d' % (_r, _st.st_mtime_ns)).encode('latin-1', 'replace'))
        except OSError:
            pass
    h.update((os.environ.get('LIB') or '').encode('latin-1', 'replace'))
    return h.hexdigest()


def _main():
    out = set()
    from shardcache import ShardCache
    c = ShardCache(H / 'link/obj_ext_cache.pkl')
    # every object the link reads, not only extra/objs.txt (native-check-runs candidate.obj defines _prop_profileName etc.)
    import sys as _s0
    _s0.path.insert(0, str(H.parents[1]))
    from roc.rebuild import coff_externals as _cx
    _dirty = False
    for _l in (H / 'link/donorfree.rsp').read_text().splitlines():
        _p = _l.strip().strip('"')
        if _p.lower().endswith('.obj') and os.path.exists(_p) and 'renamed' + os.sep + 'obj' not in os.path.normpath(_p) and not os.path.basename(_p).lower().endswith('stubs.obj'):
            _st = os.stat(_p)
            _v = c.get(_p)
            if not _v or _v[0] != _st.st_mtime or _v[1] != _st.st_size:
                c[_p] = (_st.st_mtime, _st.st_size, _cx(Path(_p).read_bytes())); _dirty = True
    try:   # objects quicktest swaps in from native_check_runner results (linkexp/qt_results.txt) before a boot relink
        for _f in (H / 'linkexp/qt_results.txt').read_text().split():
            _j = json.load(open(_f))
            for _r in (_j if isinstance(_j, list) else _j['results']):
                _p = _r.get('object') or ''
                if _r.get('status') == 'complete' and os.path.exists(_p) and _p not in c:
                    _st = os.stat(_p)
                    c[_p] = (_st.st_mtime, _st.st_size, _cx(Path(_p).read_bytes())); _dirty = True
    except OSError:
        pass
    if _dirty:
        c.save()
    nodraft = set()   # vtables etc. defined by REAL native objects (LLM AutoRecover drafts declare fake classes)
    for p, v in c.items():
        if 'renamed' + os.sep + 'obj' not in os.path.normpath(p):
            _d = {n for n, d in v[2].items() if d}
            out |= _d
            try:
                _src = json.load(open(os.path.join(os.path.dirname(p), 'receipt.json'))).get('source', '')
            except Exception:
                _src = ''
            if 'AutoRecover_' not in _src:
                nodraft |= _d
    (H / 'renamed/defined_nodraft.json').write_text(json.dumps(sorted(n for n in nodraft if n.startswith('??_7'))))
    (H / 'renamed/defined_nodraft_fn.json').write_text(json.dumps(sorted(n for n in nodraft if n.startswith('?') and not n.startswith(('??_7', '??_R', '??_C', '??_B')))))   # renamed_link: converted helpers yield to these
    libs = 0
    for l in (H / 'link/donorfree.rsp').read_text().splitlines():
        p = l.strip().strip('"')
        if p.lower().endswith('.lib') and os.path.exists(p):
            s = lib_symbols(p)
            out |= s
            out |= {x[6:] for x in s if x.startswith('__imp_')}   # import libs: the function name as well as its __imp_ slot
            libs += 1
    # default libraries the objects pull in through /DEFAULTLIB (CRT, C++ runtime, Win32 import libs): from the toolchain LIB path
    import sys
    sys.path.insert(0, str(H.parents[1]))
    from roc import rebuild
    _env = rebuild.env(rebuild.toolchain(21022))
    DEFAULT = ('msvcrt.lib', 'msvcprt.lib', 'oldnames.lib', 'kernel32.lib', 'user32.lib', 'gdi32.lib', 'advapi32.lib', 'shell32.lib',
               'ole32.lib', 'oleaut32.lib', 'uuid.lib', 'comctl32.lib', 'comdlg32.lib', 'winmm.lib', 'ws2_32.lib', 'wsock32.lib',
               'shlwapi.lib', 'version.lib', 'wininet.lib', 'winspool.lib', 'imm32.lib', 'opengl32.lib', 'glu32.lib', 'd3d9.lib',
               'd3dx9.lib', 'dinput8.lib', 'dxguid.lib', 'urlmon.lib', 'oledlg.lib', 'rpcrt4.lib', 'psapi.lib', 'dbghelp.lib', 'iphlpapi.lib')
    for d in (_env.get('LIB') or '').split(';'):
        for n in DEFAULT:
            p = os.path.join(d, n)
            if d and os.path.exists(p):
                s = lib_symbols(p)
                out |= s
                out |= {x[6:] for x in s if x.startswith('__imp_')}
                libs += 1
    am = json.load(open(H / 'renamed/addrmap.json'))
    out |= set(am)
    (H / 'renamed/defined.json').write_text(json.dumps(sorted(out)))
    print('defined now: %d names (%d libraries)' % (len(out), libs))


_SIGF = H / 'renamed/.defined_now.sig'
_OUTS = [H / 'renamed/defined.json', H / 'renamed/defined_nodraft.json', H / 'renamed/defined_nodraft_fn.json']
_sig = _signature()
if _SIGF.exists() and _SIGF.read_text() == _sig and all(o.exists() for o in _OUTS):
    print('defined now: inputs unchanged, outputs current')
else:
    _main()
    _SIGF.write_text(_sig)
