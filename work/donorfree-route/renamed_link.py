import time as _tt0
_T0 = _tt0.time()
_tm = lambda l: print('  [rl %6.1fs] %s' % (_tt0.time() - _T0, l), flush=True)
"""python renamed_link.py: put rename.py's byte-exact converted analogs (renamed/rename.json, renamed/obj/*.obj) into the
donor-free link in place of the LLM drafts for the same addresses. Writes renamed/results.json (boot.py input) and drops
the AutoRecover_<addr> objects of converted addresses from extra/objs.txt. Then: python boot.py renamed/results.json"""
import json, os, re
from pathlib import Path

H = Path(__file__).parent
res = json.loads((H / 'renamed/rename.json').read_text())
# most records lost their 'renamed' map (rename_par merges): rebuild it from each object's undefined externals, so the
# import-label aliases (KERNEL32.dll!EnterCriticalSection -> __imp_...) and the func_ closure see every object
# (missing: lock's EnterCriticalSection fell to _roc_stub_data and the client jumped into data)
import pickle as _pk0, sys as _sys0
_sys0.path.insert(0, str(H.parents[1]))
from roc.rebuild import coff_externals as _cx
_cf0 = H / 'renamed/ext_cache.pkl'
# one directory scan instead of ~4 exists()/stat() calls per object (21k objects: ~2 s per pass); on Windows the
# DirEntry stat comes from the directory listing itself
_SCAN = {}
for _d in ('obj', 'obj_full'):
    try:
        _SCAN[_d] = {e_.name: e_.stat() for e_ in os.scandir(H / 'renamed' / _d) if e_.name.endswith('.obj')}
    except OSError:
        _SCAN[_d] = {}
try:
    _ec = _pk0.load(open(_cf0, 'rb'))
except Exception:
    _ec = {}
_dirty = False
for a, r in res.items():
    o = H / 'renamed/obj' / (a + '.obj')
    if r.get('status') != 'renamed' or r.get('renamed') or (a + '.obj') not in _SCAN['obj']:
        continue
    st = _SCAN['obj'][a + '.obj']
    v = _ec.get(a)
    if not v or v[0] != (st.st_mtime, st.st_size):
        v = _ec[a] = ((st.st_mtime, st.st_size), sorted(n for n, d in _cx(o.read_bytes()).items() if not d))
        _dirty = True
    r['renamed'] = {n: n for n in v[1]}
if _dirty:
    _pk0.dump(_ec, open(_cf0, 'wb'), protocol=4)
done = {a for a, r in res.items() if r.get('status') == 'renamed' and (a + '.obj') in _SCAN['obj']}
# link only reachable/requested converted objects (linking all of them: 10-min links, 21k stubs)
_mf = H / 'renamed/addrmap_mass.json'
if _mf.exists() and not os.environ.get('ROC_LINK_ALL'):   # ROC_LINK_ALL=1: every converted exact (lld links in ~15 s now)
    _mass = {v['exact'][0] for v in json.loads(_mf.read_text()).values()}
    _want = set(json.loads((H / 'renamed/active.json').read_text())) if (H / 'renamed/active.json').exists() else set()
    try:
        _want |= {r['addr'] for r in json.loads((H / 'auto/reach.json').read_text())}
    except Exception:
        pass
    done = {a for a in done if a not in _mass or a in _want}
# closure: a linked converted object's func_<addr> callees are linked too when their converted object exists
_all = {a for a, r in res.items() if r.get('status') == 'renamed' and (a + '.obj') in _SCAN['obj']}
_todo = list(done)
while _todo:
    a_ = _todo.pop()
    for t_ in (res[a_].get('renamed') or {}).values():
        m_ = re.fullmatch(r'func_([0-9a-f]{8})', t_)
        if m_ and m_.group(1) in _all and m_.group(1) not in done:
            done.add(m_.group(1)); _todo.append(m_.group(1))
_EXCL = set()   # excluded by policy (native/vendor wins): written to renamed/excluded.json so cycle.py stops re-queuing them
# exact objects that call STUBS while a native object defines the same real name: use the native one (it has real callees)
try:
    import pickle as _pk
    _xc = _pk.load(open(H / 'link/obj_ext_cache.pkl', 'rb'))
    _native = set()
    for _p, _v in _xc.items():
        if 'renamed' + os.sep + 'obj' not in os.path.normpath(_p):
            _native |= {n for n, d in _v[2].items() if d}
    _stubs = set(json.load(open(H / 'link/stubs.json'))['functions'])
    _shadow = {a for a in done if res[a].get('symbol', '').startswith('?') and res[a]['symbol'] in _native
               and '@boost@@' not in res[a]['symbol']   # boost: library 1.34.1 build differs from the original (tss ABI)
               and any(t_ in _stubs or (t_.startswith('func_') and t_[5:] not in done) for t_ in (res[a].get('renamed') or {}).values())}
    if os.environ.get('ROC_EXACT_FIRST'):   # experiment: byte-exact code everywhere it exists, natives only fill gaps
        _shadow = set()
    done -= _shadow
    _EXCL |= _shadow
    print('exact objects that call stubs/drafts replaced by their native definitions: %d' % len(_shadow))
except Exception as _e:
    print('stub-shadow check skipped:', _e)
# vendor library builds (rebuild/2008-06/out/*/linked/linked.lib: XTP, MFC/ATL, boost, G3D, Lua... compiled from the
# authentic source) define these real names consistently with their own class layouts; a converted copy (analog-guessed
# layout) linked first broke e.g. XTP's CXTPImageManager maps (m_nBlockSize read as 0 -> CPlex::Create threw). Library wins.
try:
    import struct as _st
    def _libsyms(p):
        b = Path(p).read_bytes()
        if not b.startswith(b'!<arch>\n') or b[8:24].strip() != b'/':
            return set()
        n = _st.unpack_from('>I', b, 68)[0]
        return {x.decode('latin-1') for x in b[68 + 4 + 4 * n:68 + int(b[56:66].strip())].split(b'\0')[:n] if x}
    _vend = set()
    for _l in (H / 'link/donorfree.rsp').read_text().splitlines():
        _p = _l.strip().strip('"')
        _bn = os.path.basename(_p).lower()
        if (_bn == 'linked.lib' or _bn.startswith(('atls', 'comsupp'))) and _bn.endswith('.lib') and os.path.exists(_p):
            if os.sep + 'Boost' + os.sep in _p or '/Boost/' in _p:
                continue   # our boost 1.34.1 build differs from the original's (tss, function, mutex ABI): exact wins, C names too
            _vend |= _libsyms(_p)
    _vx = {a for a in done if (res[a].get('symbol') or '').startswith('?') and res[a]['symbol'] in _vend
           and '@boost@@' not in res[a]['symbol']}   # boost: our 1.34.1 library build differs from the original's (tss/function ABI): exact wins
    # ... and any converted object that publicly DEFINES a vendor-library name (0070e700.obj carried XTP's
    # CXTPStatusBar::CalcFixedLayout as a kept helper; the analog's frame broke the status bar layout)
    import pickle as _pk3
    _vstrip = {}
    # helpers a converted object carries besides its main symbol (the analog's inline copy of e.g.
    # silentGetTextureProxyBase used the 2007 ContentProvider::singleton -> null) yield to the native definition
    try:
        import subprocess as _sp9, sys as _sy9
        _sp9.run([_sy9.executable, str(H / 'defined_now.py')], capture_output=True)
        _nhelp = set() if os.environ.get('ROC_EXACT_FIRST') else set(json.loads((H / 'renamed/defined_nodraft_fn.json').read_text()))
    except Exception:
        _nhelp = set()
    _mains = {res[a_].get('symbol'): a_ for a_ in done if (res[a_].get('symbol') or '').startswith('?')}   # main symbol -> owner
    _dcf = H / 'renamed/defs_cache.pkl'
    try:
        _dc = _pk3.load(open(_dcf, 'rb'))
    except Exception:
        _dc = {}
    _dd = False
    # names rgmain.dll EXPORTS: the original exe imported them. A converted object's stock-Ogre copy (0068d580's
    # analog carried 60 SceneManager methods) would win over the DLL and, worse, its inline `new SceneNode` stores a
    # file-local stock-layout vtable (2 virtuals short) -> AdornRbxGfx's ctor dispatched into the wrong slot.
    try:
        import pefile as _pf8
        _pe8 = _pf8.PE(str(H / 'run/rgmain.dll'), fast_load=True)
        _pe8.parse_data_directories(directories=[_pf8.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXPORT']])
        _dllx = {e.name.decode() for e in _pe8.DIRECTORY_ENTRY_EXPORT.symbols if e.name}
    except Exception:
        _dllx = set()
    for a in done - _vx:
        _k = 'obj_full' if (a + '.obj') in _SCAN['obj_full'] else 'obj'   # pre-strip copy (vt_strip rewrites renamed/obj in place)
        o = H / 'renamed' / _k / (a + '.obj')
        st = _SCAN[_k][a + '.obj']
        v = _dc.get(a)
        if not v or v[0] != (st.st_mtime, st.st_size):
            v = _dc[a] = ((st.st_mtime, st.st_size), sorted(n for n, d in _cx(o.read_bytes()).items() if d))
            _dd = True
        _hv = [n for n in v[1] if n != res[a].get('symbol') and (('@boost@@' not in n and (n in _vend or n in _nhelp))
               or (n in _mains and _mains[n] != a) or n in _dllx)]   # another linked object's MAIN symbol: its owner wins
        if _hv:
            _vstrip[a] = _hv   # vt_strip.py drops these helper definitions: the library's copy wins, the object stays
    if _dd:
        _pk3.dump(_dc, open(_dcf, 'wb'), protocol=4)
    (H / 'renamed/vendor_strip.json').write_text(json.dumps(_vstrip))
    print('converted objects whose vendor-library helpers yield to the library: %d' % len(_vstrip))
    done -= _vx
    _EXCL |= _vx
    print('converted objects replaced by authentic vendor-library definitions: %d' % len(_vx))
except Exception as _e:
    print('vendor-library preference skipped:', _e)
# native sources name addresses in '// <addr>' comments (native_addrs.py): an UNNAMED exact func_<addr> that reads
# dat_ placeholders loses to its native implementation, which owns the real (often file-static) globals
# (func_004492d0 read prop_profileName's field as dat_0096d52c = NULL; native CRenderSettings::checkProfile has it)
_NA_alias = []
try:
    import subprocess as _sp0, sys as _sy0
    _sp0.run([_sy0.executable, str(H / 'native_addrs.py')], capture_output=True)
    _NA = json.loads((H / 'renamed/native_addrs.json').read_text())
    _stubs0 = set(json.load(open(H / 'link/stubs.json'))['functions'])
    _nx = {a for a in done if a in _NA and res[a].get('symbol') == 'func_' + a
           and (_NA[a].startswith('??$')   # template instance: its statics are one program-wide COMDAT -> native
                or any(t_.startswith('dat_') for t_ in (res[a].get('renamed') or {}).values())
                # calls a stub (00642750's inline helper used the 2007 ContentProvider::singleton -> null this)
                or any(t_ in _stubs0 for t_ in (res[a].get('renamed') or {}).values()))}
    if os.environ.get('ROC_EXACT_FIRST'):
        _nx = set()
    done -= _nx
    _EXCL |= _nx
    _NA_alias = ['func_%s=%s' % (a, s) for a, s in _NA.items() if a not in done]
    print('unnamed exact objects replaced by native implementations (dat_ globals): %d' % len(_nx))
except Exception as _e:
    print('native address names skipped:', _e)
_bx = H / 'renamed/bisect_exclude.json'   # bisect.py: temporarily leave these converted objects out
if _bx.exists():
    done -= set(json.loads(_bx.read_text()))
    _EXCL |= set(json.loads(_bx.read_text()))
_fx = H / 'renamed/force_exact.json'   # autoflip proved these exact objects get the client further: they override policy
if _fx.exists():
    _force = set(json.loads(_fx.read_text())) & _all
    done |= _force
    _EXCL -= _force
(H / 'renamed/excluded.json').write_text(json.dumps(sorted(_EXCL)))
# ICF: rename.py binds folded std::_Tree calls to func_<addr> (the original's code fits every folded user). An excluded
# template-instance object (native defines its label) still supplies that code: link it with its main symbol renamed
# to func_<addr> by vt_strip.py, so the native keeps the label and func_<addr> is never a stub (RunService views map)
_mainren = {a: res[a]['symbol'] for a in _EXCL & _all if '?$' in (res[a].get('symbol') or '') and a not in done}
# an UNNAMED address (registry func_<addr>) whose converted object claims a real name a native defines: that name is the
# analog's guess (00490d70 is find<StarterPackService> but exported create<StarterPackService>, shadowing the native
# create -> the service was never created). The native keeps the name; the object answers only to func_<addr>
try:
    _ndef = set(json.loads((H / 'renamed/defined_nodraft_fn.json').read_text()))
    _ffn = json.load(open(H.parents[1] / 'work/native-client/layout/function-files.json'))
    _guess = {a: res[a]['symbol'] for a in done if (res[a].get('symbol') or '') in _ndef
              and not ((_ffn.get(a) or {}).get('name') or '').startswith('?')}
    _mainren.update(_guess)
    print('unnamed exact objects whose guessed real name yields to the native definition: %d' % len(_guess))
except Exception as _e:
    print('guessed-name check skipped:', _e)
done |= set(_mainren)
(H / 'renamed/main_rename.json').write_text(json.dumps(_mainren))
print('excluded template instances linked as func_<addr> only: %d' % len(_mainren))
rows = [{'status': 'complete', 'source': str(H / ('renamed/Renamed_%s.cpp' % a)), 'object': str((H / 'renamed/obj' / (a + '.obj')).resolve())}
        for a in sorted(done)]
(H / 'renamed/results.json').write_text(json.dumps(rows))
_tm('selection policies')
ff = json.load(open(H.parents[1] / 'work/native-client/layout/function-files.json'))
al = list(_NA_alias)   # native implementations for func_<addr> (native_addrs.py)
try:   # names native headers DECLARE (address in the comment) but nothing defines: the converted func_<addr> body
    # (Workspace::verifyCamera -> func_005a5710; as a stub the Camera never existed -> near clip 0 on the first frame)
    al += ['%s=%s' % (n_, f_) for n_, f_ in json.loads((H / 'renamed/native_calls.json').read_text()).items() if f_[5:] in done]
except (OSError, ValueError):
    pass
try:   # FOLDED bodies: a stubbed name whose converted callers bind it to an address converted under ANOTHER symbol
    # (identical-code folding: InstanceHandle(Instance*) == ChildAdded(Instance*) at 00594e00; as a stub the camera's
    # XML clone got no handle -> "circular reference"). /alternatename: only used when nothing defines the name.
    # ponytail: analog-name guesses can be wrong; a stub returning 0 is the worse default (bisect via QT_EXCLUDE if one bites).
    _fa = {}
    _stb = set(json.load(open(H / 'link/stubs.json'))['functions'])
    for _a, _x in res.items():
        for _k, _v in (_x.get('refs') or {}).items():
            if _k.startswith('?') and _k in _stb and (res.get(_v) or {}).get('status') == 'renamed' and _v in done:
                _s = res[_v].get('symbol')
                if _s and _s != _k:
                    _fa.setdefault(_k, set()).add(_s)
    _fa = {k_: next(iter(s_)) for k_, s_ in _fa.items() if len(s_) == 1}
    al += ['%s=%s' % kv for kv in sorted(_fa.items())]
    print('stubbed names aliased to the folded converted body their callers use: %d' % len(_fa))
except Exception as _e:
    print('fold aliases skipped:', _e)
try:   # dat_<addr> placeholders of globals native code names (native_data.py: renderMode 00942ec4)
    import subprocess as _sp1, sys as _sy1
    _sp1.run([_sy1.executable, str(H / 'native_data.py')], capture_output=True)
    al += ['dat_%s=%s' % (a, s) for a, s in json.loads((H / 'renamed/native_data.json').read_text()).items()]
except Exception as _e:
    print('native data names skipped:', _e)
for a in sorted(done):   # natives that call these functions by their real name get the exact converted object
    n = (ff.get(a) or {}).get('name') or ''
    if n.startswith('?') and res[a].get('symbol') == 'func_' + a:
        al.append('%s=func_%s' % (n, a))
# anonymous-namespace names (?init_tss_data@?A0x91ea0cf3@@YAXXZ) are file-local and their hash differs per compile:
# converted objects that still reference one get the exact func_<addr> whose registry name matches with the hash
# stripped, when unique (was a stub: tss::set threw thread_resource_error)
_anon = lambda s: re.sub(r'@\?A0x[0-9a-f]+@', '@?A0x@', s)
_an = {}
for a in done:
    n = (ff.get(a) or {}).get('name') or ''
    if '@?A0x' in n and res[a].get('symbol') == 'func_' + a:
        _an.setdefault(_anon(n), set()).add(a)
for r_ in [res[a] for a in done]:
    for t_ in (r_.get('renamed') or {}).values():
        if '@?A0x' in t_ and len(_an.get(_anon(t_), ())) == 1:
            al.append('%s=func_%s' % (t_, next(iter(_an[_anon(t_)]))))
for a in sorted(done):   # an object that defines a real name still answers to func_<addr> (mistarget_fix.py renames in place)
    _s = res[a].get('symbol') or ''
    # only a real decorated name ('?' alone is rename.py's placeholder for an object whose name was never recorded:
    # aliasing to it left the call at address 0 -- func_007a5f56, the ATL thunk-pool initializer)
    if _s != 'func_' + a and a not in _mainren and len(_s) > 2 and re.match(r'^[?_@][\w?@$]', _s):
        al.append('func_%s=%s' % (a, _s))
for r_ in res.values():   # rename.py labels IAT targets 'dll!name': the object reads the import pointer __imp_name
    for t_ in (r_.get('renamed') or {}).values():
        pass
_alk = {a.split('=', 1)[0] for a in al}   # alias keys once: any(startswith) over ~50k aliases per label was quadratic
for r_ in res.values():   # 'dll!name' import labels: the analog's own symbol was already the correct (decorated) __imp_ name
    for k_, t_ in (r_.get('renamed') or {}).items():
        if '!' in t_ and t_ not in _alk and not re.match(r'^#\d+$', t_.split('!', 1)[1]):
            # (imports BY ORDINAL go through the import library's ordinal table below: the analog's own __imp_ name is
            # invented -- mfc90.dll!#817 became __imp_??0String@@, undefined, stubbed as code; CIDEBrowserView jumped
            # to the stub's bytes)
            n_ = t_.split('!', 1)[1]
            if n_.startswith('?'):      # C++ export: the label carries the real decorated name (the analog's own spelling may differ)
                al.append('%s=__imp_%s' % (t_, n_)); _alk.add(t_)
            elif k_.startswith('__imp_') and re.sub(r'@\d+$', '', k_[7:]) in (n_, n_.lstrip('_')):
                # C export: the analog's __imp__name@N has the right decoration -- ONLY when it is the SAME function.
                # A rebound reference (rename.py: the original reads EnterCriticalSection's slot where the analog called
                # SysFreeString) keeps its old symbol name: using it here aliased EnterCriticalSection to SysFreeString
                # program-wide (every lock freed its critical section: heap corruption). Others go to the SDK table below.
                al.append('%s=%s' % (t_, k_)); _alk.add(t_)
al = sorted(set(al))
# still-unmapped 'dll!name' labels: find the decorated __imp_ symbol in the SDK import libraries
_need = {t_ for r_ in res.values() for t_ in (r_.get('renamed') or {}).values() if '!' in t_} - {a.split('=')[0] for a in al}
if _need:
    import glob as _g, re as _r
    _cf = H / 'renamed/imp_cache.json'   # SDK import-library scan is slow (hundreds of MB): cache the name -> __imp_ table
    try:
        _imp = json.loads(_cf.read_text())
    except Exception:
        _imp = {}
        for _lib in _g.glob(str(H.parents[1] / 'tools/vc2008sp1/Microsoft/Visual C++ for Python/9.0/WinSDK/Lib/*.Lib')):
            for _m in _r.finditer(rb'__imp__([A-Za-z0-9_]+)@(\d+)', open(_lib, 'rb').read()):
                _imp.setdefault(_m.group(1).decode(), '__imp__%s@%s' % (_m.group(1).decode(), _m.group(2).decode()))
        _cf.write_text(json.dumps(_imp))
    def _ordinals(lib):
        """{ordinal: decorated symbol} from an import library's short import objects (imports BY ORDINAL: mfc90.dll!#310)"""
        import struct as _s2
        b = Path(lib).read_bytes()
        out_, pos = {}, 8
        while pos + 60 <= len(b):
            size = int(b[pos + 48:pos + 58].strip() or b'0')
            d0 = pos + 60
            if size >= 20 and b[d0:d0 + 4] == b'\x00\x00\xff\xff':
                ordh, typ = _s2.unpack_from('<HH', b, d0 + 16)
                sym = b[d0 + 20:b.find(b'\0', d0 + 20)].decode('latin-1')
                if (typ >> 2) & 7 == 0:   # IMPORT_OBJECT_ORDINAL
                    out_[ordh] = sym
            pos = d0 + size + ((d0 + size) & 1)
        return out_
    _ordc = H / 'renamed/ordinals.json'
    try:
        _ord = {k: {int(o): s for o, s in v.items()} for k, v in json.loads(_ordc.read_text()).items()}
    except Exception:
        _ord = {}
        for _l in (H / 'link/donorfree.rsp').read_text().splitlines():
            _p = _l.strip().strip('"')
            if _p.lower().endswith('mfc90.lib') and os.path.exists(_p):
                _ord['mfc90.dll'] = _ordinals(_p)
        _ordc.write_text(json.dumps({k: {str(o): s for o, s in v.items()} for k, v in _ord.items()}))
    for t_ in sorted(_need):
        n_ = t_.split('!', 1)[1]
        _dll = t_.split('!', 1)[0].lower()
        if n_.startswith('#') and n_[1:].isdigit():   # import by ordinal: the import library knows its symbol
            _s = _ord.get(_dll, {}).get(int(n_[1:]))
            if _s:
                al.append('%s=__imp_%s' % (t_, _s))
            continue
        if n_ in _imp:
            al.append('%s=%s' % (t_, _imp[n_]))
        elif n_.startswith('?'):
            al.append('%s=__imp_%s' % (t_, n_))
        else:   # cdecl CRT import (MSVCR90.dll!fflush): __imp__fflush from msvcrt.lib
            al.append('%s=__imp__%s' % (t_, n_))
(H / 'aliases_renamed.txt').write_text('# generated by renamed_link.py' + chr(10) + chr(10).join(al) + chr(10))

_RC = {}
keep, drop = [], 0
for o in (H / 'extra/objs.txt').read_text().splitlines():
    o = o.strip()
    if not o:
        continue
    try:
        _p = Path(o).parent.parent / 'results.json'
        if _p not in _RC:   # object path -> source, built once per results file (was millions of Path.resolve calls)
            _rr = json.load(open(_p))
            _rr = _rr if isinstance(_rr, list) else _rr['results']
            _RC[_p] = {os.path.normcase(os.path.abspath(r.get('object') or '')): r.get('source', '') for r in _rr}
        src = _RC[_p].get(os.path.normcase(os.path.abspath(o)), '')
    except Exception:
        src = ''
    if 'renamed' + os.sep + 'obj' in os.path.normpath(o):   # converted objects are re-added from the active set below
        continue
    m = re.search(r'AutoRecover_([0-9a-f]{8})\.cpp', src, re.I)
    if m and m.group(1).lower() in done:
        drop += 1
    else:
        keep.append(o)
_np = lambda p_: os.path.normcase(os.path.abspath(p_))   # Path.resolve() per object cost ~1 ms on Windows (40k calls)
_have = {_np(k) for k in keep}
keep += [r['object'] for r in rows if _np(r['object']) not in _have]   # converted objects always linked
(H / 'extra/objs.txt').write_text('\n'.join(keep) + '\n')
print('%d converted analogs ready; %d draft objects replaced' % (len(rows), drop))
_tm('aliases + objs list')

import subprocess, sys as _s
print(subprocess.run([_s.executable, str(H / 'vt_strip.py')], capture_output=True, text=True).stdout.strip())
_tm('vt_strip')
