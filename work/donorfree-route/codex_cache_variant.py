"""python quicktest.py [secs]: test a fix NOW without waiting for a cycle round. Takes the cycle's last link inputs
(link/donorfree.rsp + link/stubs.obj), swaps in the current converted-object set (renamed/results.json) and the policy
exclusions, links with lld into linkexp/qt.exe (separate files: never touches the cycle's exe/map), copies it next to the
runtime files and runs a fast-forward File->New probe. ~1 min. Prints the crash / fast-forward sites."""
import json, os, re, shutil, subprocess, sys
from pathlib import Path
H = Path(__file__).parent
QTAG = os.environ.get('QT_TAG', '')   # parallel variants: every output path gets this tag (qtB.exe, RobloxQTB.exe)
def QP(rel):
    if 'qt_results.txt' in rel:   # the sticky --results list is shared input
        return H / rel
    return H / rel.replace('linkexp/qt', 'linkexp/qt' + QTAG, 1).replace('run/RobloxQT', 'run/RobloxQT' + QTAG, 1)
secs = sys.argv[1] if len(sys.argv) > 1 else '30'
import time as _tt
_CRT_STD = {'_CxxThrowException': '__CxxThrowException@8'}   # stdcall CRT exports
_t0 = [_tt.time()]
_QT_START = _tt.time()
import gc as _gc0
_gc0.set_threshold(200000, 50, 100)   # millions of short-lived objects (symbol sets): default thresholds spent tens of seconds in GC
import builtins as _bi
_oprint = _bi.print


def print(*a, **k):   # every quicktest line carries its elapsed time: which step is slow is visible in each log
    _oprint('[%5.0fs]' % (_tt.time() - _QT_START), *a, **k)
def _tm(label):
    if os.environ.get('QT_TIMING', '1') == '1':
        print('  [qt %6.1fs] %s' % (_tt.time() - _t0[0], label), flush=True)
rsp = (H / 'link/donorfree.rsp').read_text().splitlines()
conv = [r['object'] for r in json.load(open(H / 'renamed/results.json'))]
conv_set = {os.path.normcase(os.path.abspath(o)) for o in conv}
out, seen_conv = [], False
for l in rsp:
    p = l.strip().strip('"')
    if p.lower().endswith('.obj') and ('renamed' + os.sep + 'obj') in os.path.normpath(p):
        if not seen_conv:   # converted objects go first (exact definitions win), in the current set
            out += ['"%s"' % o for o in conv]
            seen_conv = True
        continue
    if l.startswith('"/OUT:'):
        l = '"/OUT:%s"' % (QP('linkexp/qt.exe'))
    elif l.startswith('"/MAP:'):
        l = '"/MAP:%s"' % (QP('linkexp/qt.map'))
    out.append(l)
if not seen_conv:
    out = ['"%s"' % o for o in conv] + out
# aliasaudit.py dropped func_<A>=S (S = native code of another function): link A's own converted body when one exists
# (it was left out because the alias claimed the name; func_00490c30 find<Service> vs SpawnLocation::onServiceProvider)
if (H / 'auto/alias_drop.json').exists() and not os.environ.get('QT_NO_ALIASDROP'):
    _cv = {os.path.basename(o_) for o_ in conv}
    for _dl in json.loads((H / 'auto/alias_drop.json').read_text()):
        _da = _dl.split('=', 1)[0][5:]
        _do = H / 'renamed/obj' / (_da + '.obj')
        if _do.exists() and _da + '.obj' not in _cv:
            out.insert(0, '"%s"' % _do)
# FIRST-WINS converted bodies (auto/first_wins.json [addr]): the original's version must beat inline copies in native
# drafts (ATL::AtlThrowImpl: the drafts' plain-ATL copy RaiseException(0xC000001D)s instead of MFC's
# AfxThrowOleException, so MFC TRY/CATCH never caught a failed HRESULT -> File->New crash)
if (H / 'auto/first_wins.json').exists() and not os.environ.get('QT_NO_FIRSTWINS'):
    out = ['"%s"' % (H / 'renamed/obj' / (a_ + '.obj')) for a_ in json.loads((H / 'auto/first_wins.json').read_text())
           if (H / 'renamed/obj' / (a_ + '.obj')).exists()] + [l_ for l_ in out if not any(l_.strip('"').endswith(a_ + '.obj') and 'renamed' in l_ for a_ in json.loads((H / 'auto/first_wins.json').read_text()))]
# vtorig.py: the ORIGINAL vtables of wrong-layout classes (COMDAT-any), FIRST so they win over converted/native copies
_vto = Path(os.environ['VTORIG_OBJ']) if os.environ.get('VTORIG_OBJ') else H / 'linkexp/vt_orig.obj'   # per-variant vtable set
if _vto.exists() and not os.environ.get('QT_NO_VTORIG'):
    out = ['"%s"' % _vto] + out
    # Listener-interface tables of native classes whose own ??_7X@@6B@ is NOT the offset-0 subobject (SoundService:
    # the Listener<RunService,Heartbeat> at 0x130): the original table for that offset, linked first (COMDAT any)
    if (H / 'linkexp/vt_orig_remap.obj').exists() and not os.environ.get('QT_NO_VTREMAP'):
        out = ['"%s"' % (H / 'linkexp/vt_orig_remap.obj')] + out
    # dat_<X> placeholders that are original vtables, as real tables with an RTTI locator (vtorig.py VTORIG_DAT=1)
    if (H / 'linkexp/vt_dat.obj').exists() and not os.environ.get('QT_NO_VTDAT'):
        out = out + ['"%s"' % (H / 'linkexp/vt_dat.obj')]
# nameinit.py: real `const RBX::Name&` globals (tag_version...) instead of zero base stubs (NULL refs broke XML load)
if (H / 'linkexp/nameinit.obj').exists() and not os.environ.get('QT_NO_NAMEINIT'):
    out.append('"%s"' % (H / 'linkexp/nameinit.obj'))
# libalias.py: library functions (compiled XTP...) whose body equals an original placeholder's, kept-only copies
if (H / 'linkexp/createinst.obj').exists():   # createinst.py: Creatable<Instance>::create<C>() from native headers
    out.append('"%s"' % (H / 'linkexp/createinst.obj'))
if (H / 'linkexp/libalias_objs.txt').exists() and not os.environ.get('QT_NO_LIBALIAS'):
    out += ['"%s"' % l_ for l_ in (H / 'linkexp/libalias_objs.txt').read_text().split() if os.path.exists(l_)]
# converted dynamic initializers registered in .CRT$XCU (xcu_gen.py): the CRT runs them like the original's table
_xo = Path(os.environ['XCU_OBJ']) if os.environ.get('XCU_OBJ') else H / 'linkexp/xcu_init.obj'   # per-variant initializer set
if _xo.exists() and not os.environ.get('QT_NO_XCU'):
    out.append('"%s"' % _xo)
# creatorinit.py: original factory-creator registrations no native object performs (BoolValue, Decal...: Insert Object)
if (H / 'linkexp/xcu_creators.obj').exists() and not os.environ.get('QT_NO_CREATORS'):
    out.append('"%s"' % (H / 'linkexp/xcu_creators.obj'))
if (H / 'linkexp/dllvt.obj').exists() and not os.environ.get('QT_NO_DLLVT'):   # dllvt.py: local rgmain vtables/RTTI
    out.append('"%s"' % (H / 'linkexp/dllvt.obj'))
if (H / 'linkexp/abszero.obj').exists():   # zeroreloc.py: __roc_abs_zero
    out.append('"%s"' % (H / 'linkexp/abszero.obj'))
if (H / 'linkexp/xcu_descs.obj').exists() and not os.environ.get('QT_NO_DESCINIT'):   # descinit.py: original descriptor initializers
    out.append('"%s"' % (H / 'linkexp/xcu_descs.obj'))
# --results R.json: native_check_runner results whose objects replace the linked object of the same source (seconds,
# instead of a boot.py relink)
_rr = [sys.argv[i + 1] for i, a in enumerate(sys.argv) if a == '--results']
for _i, _a in enumerate(sys.argv):   # --results-file F: one results.json path per line (300+ --results overflowed the command line)
    if _a == '--results-file':
        _rr += [l.strip() for l in open(sys.argv[_i + 1]) if l.strip()]
_rf = QP('linkexp/qt_results.txt')   # sticky: every later quicktest/autoflip baseline applies them until boot.py relinks
_rr = list(dict.fromkeys(([l for l in _rf.read_text().splitlines() if l.strip()] if _rf.exists() else []) + [str(Path(x).resolve()) for x in _rr]))
_rr = [x for x in _rr if os.path.exists(x) and os.path.getmtime(x) > os.path.getmtime(H / 'link/donorfree.rsp')]
_rf_new = '\n'.join(_rr) + '\n'
if not _rf.exists() or _rf.read_text() != _rf_new:
    _rf.write_text(_rf_new)
_rr = [x for x in _rr if not any(t_ and t_ in x for t_ in os.environ.get('QT_SKIP_RESULTS', '').split(','))]   # bisect: leave these run ids out
# single result OBJECTS kept out (auto/quarantined_objects.txt: one path per line), e.g. a unit whose link breaks lld
_QOBJ = {os.path.normcase(x) for x in (H / 'auto/quarantined_objects.txt').read_text().split()} if (H / 'auto/quarantined_objects.txt').exists() else set()
_QUAR = set((H / 'auto/quarantined_llm_results.txt').read_text().split()) if (H / 'auto/quarantined_llm_results.txt').exists() else set()
if _rr:
    _new = {}
    for _f in _rr:
        _j = json.load(open(_f))
        for _r in (_j if isinstance(_j, list) else _j['results']):
            if _r.get('status') == 'complete' and _r.get('object'):
                # LLM drafts of static initializers / atexit (0x7c0000-0x800000) build globals with invented classes:
                # 80 accepted ones crashed startup in static init (2026-11-24). Quarantined results stay out too.
                _ma = re.search(r'AutoRecover_([0-9a-f]{8})', _r.get('source', ''))
                if (_ma and 0x7c0000 <= int(_ma.group(1), 16) < 0x800000) or _f in _QUAR or os.path.normcase(_r['object']) in _QOBJ:
                    continue
                _new[os.path.normcase(_r['source'])] = _r['object']
    import pickle as _pk0
    _rcf = H / 'linkexp/receipt_cache.pkl'
    try:
        _rcc = _pk0.load(open(_rcf, 'rb'))
    except Exception:
        _rcc = {}
    _rcdirty = False
    def _receipt_src(p):
        global _rcdirty
        d = os.path.dirname(p)
        if d in _rcc:
            return _rcc[d]
        try:
            s = json.load(open(os.path.join(d, 'receipt.json'))).get('source', '')
        except Exception:
            s = ''
        _rcc[d] = s; _rcdirty = True
        return s
    def _src(l):
        return os.path.normcase(_receipt_src(l.strip().strip('"')))
    _hit = set()
    for i, l in enumerate(out):
        if l.strip().strip('"').lower().endswith('candidate.obj'):
            s_ = _src(l)
            if s_ in _new:
                out[i] = '"%s"' % _new[s_]; _hit.add(s_)
    _added = {'"%s"' % o for s, o in _new.items() if s not in _hit}   # gap-fill objects (branch/findings natives): treated like drafts
    out += sorted(_added)
    print('--results: %d objects replaced, %d added' % (len(_hit), len(_new) - len(_hit)))
# LLM drafts (AutoRecover_*) declare fake versions of real classes (a 2-vtable RBX::DebugSettings): their inline ctors /
# vtables are COMDATs and the first object wins, so real native objects must come before drafts
def _is_draft(l):
    p = l.strip().strip('"')
    if not p.lower().endswith('candidate.obj'):
        return False
    try:
        return 'AutoRecover_' in _receipt_src(p)
    except Exception:
        try:
            return 'AutoRecover_' in json.load(open(os.path.join(os.path.dirname(p), 'receipt.json'))).get('source', '')
        except Exception:
            return False
try:
    _added
except NameError:
    _added = set()
# gap-fill objects get the draft rules: linked last, never defining a DLL export (Mfcafxstate.cpp's static
# AfxGetModuleState replaced MFC's module state -> no current app) or a name a real native object defines
_dr = [l for l in out if _is_draft(l) or l in _added]
if '_rcdirty' in dir() and _rcdirty:
    try:
        _pk0.dump(_rcc, open(_rcf, 'wb'), protocol=4)
    except OSError:
        pass
if os.environ.get('QT_EXCLUDE'):   # bisect without renamed_link: leave these converted objects (addr list JSON) out
    _qx = set(json.load(open(os.environ['QT_EXCLUDE'])))
    out = [l for l in out if not (re.search(r'[\\/]([0-9a-f]{8})\.obj"?$', l) and re.search(r'[\\/]([0-9a-f]{8})\.obj"?$', l).group(1) in _qx)]
    print('QT_EXCLUDE: %d converted objects left out' % len(_qx))
_tm('results swap + draft scan')
_drs = set(_dr)
sys.path.insert(0, str(H.parents[1]))
from roc import rebuild as _rb
# drafts that DEFINE a function a DLL exports (AutoRecover_0069fd44: Ogre::SceneNode::setParent via an invented import,
# rgmain.dll exports the real one): the DLL's import wins -> strip those definitions from a cached copy of the draft
sys.path.insert(0, str(H))
import defined_now as _dn0   # noqa: E402  (lib_symbols; module run refreshes renamed/defined.json too)
_exp = set()
for _l in out:
    _p = _l.strip().strip('"')
    if _p.lower().endswith('.lib') and os.path.exists(_p) and os.path.getsize(_p) < 20_000_000:
        _s = _dn0.lib_symbols(_p)
        if any(x.startswith('__imp_') for x in _s):
            _exp |= {x[6:] for x in _s if x.startswith('__imp_?')}
_ds = H / 'linkexp/draftstrip'
_ds.mkdir(exist_ok=True)
# ... and drafts must not define what a REAL native object defines, nor members of a real native class (a draft's fake
# RBX::JointsService with invented Primary/SecondaryBase: its inline ctor built JointsService without its primary vtable)
import pickle as _pk1, hashlib as _hl
from shardcache import ShardCache as _SC1
_xc1 = _SC1(H / 'link/obj_ext_cache.pkl')
_real = set()
for _l in out:
    _p = _l.strip().strip('"')
    if _p.lower().endswith('.obj') and _l not in _drs and 'renamed' + os.sep + 'obj' not in os.path.normpath(_p):
        _v = _xc1.get(_p)
        if _v:
            _real |= {n for n, d in _v[2].items() if d}
_rcls = {m.group(1) for n in _real for m in [re.match(r'^\?\?_7(\w+@\w+)@@6B', n)] if m}
_mem = re.compile(r'^(?:\?\?[0-9A-Z_]|\?\?_[0-9A-Z]|\?\w+@)(\w+@\w+)@@')
_ndr = []
# per-draft defined names cached by (mtime, size): re-reading + COFF-parsing every draft each run was most of this
# phase (~18 s); the bytes are only read again when a definition must actually be stripped
_dcf = H / 'linkexp/draft_defs_cache.pkl'
try:
    _dcc = _pk1.load(open(_dcf, 'rb'))
except Exception:
    _dcc = {}
_ddirty = False
# draftstrip safety net: a stripped definition that the finished link left to a stub (or nowhere) was the only copy
# (converted Peer::Peer, silentGetTextureProxyBase): listed here after the link, never stripped again
_dskf = H / 'auto/draftstrip_keep.json'
_dskeep = set(json.loads(_dskf.read_text())) if _dskf.exists() else set()
_dstripped = set()
# deliberate exe-local copies of DLL CONST data (OgreConstImports.cpp: native Ogre drafts reference Vector3::ZERO,
# Renderable::msDummyPlaneList... without dllimport, which resolved to jmp thunks): exempt from the DLL-export rules
_dsok = set()
for _sx in ((H / 'auto/dllshadow_ok.txt').read_text().split() if (H / 'auto/dllshadow_ok.txt').exists() else []):
    _dsok |= {o_ for s_, o_ in _new.items() if s_.endswith(os.path.normcase(_sx))} if '_new' in dir() else set()
_dsok = {'"%s"' % o_ for o_ in _dsok}
# later passes copy objects under new names (vto_ns_<date>_<time>_<run>_unit_<n>_candidate_obj_<hash>.obj): match by run+unit
_dstags = set()
for l_ in _dsok:
    m_ = re.search(r'-([0-9a-f]{8})[\\/]unit-(\d+)[\\/]', l_)
    if m_:
        _dstags.add('%s_unit_%s' % (m_.group(1), m_.group(2)))
_dr = [l for l in _dr if l not in _dsok]
_drs -= _dsok   # stays in `out` at its place (line: out = [l not in _drs] + _dr)
for _l in _dr:
    _p = _l.strip().strip('"')
    _st = os.stat(_p)
    _ck = (_st.st_mtime_ns, _st.st_size)
    _ce = _dcc.get(_p)
    _b = None
    if _ce and _ce[0] == _ck:
        _defs = _ce[1]
    else:
        _b = Path(_p).read_bytes()
        _defs = [n for n, d in _rb.coff_externals(_b).items() if d]
        _dcc[_p] = (_ck, _defs); _ddirty = True
    _bad = {n for n in _defs if n in _exp or n in _real
            or (n.startswith(('??0', '??_7', '??_R', '??_G', '??_E', '??1'))   # a fake class's ctor / vtable / RTTI
                and (lambda m_: bool(m_) and m_.group(1) in _rcls)(_mem.match(n)))}
    _bad -= _dskeep   # names an earlier link proved nothing else defines (draftstrip_keep.json): keep this copy
    _bad = {n for n in _bad if not n.startswith('??_C@')}   # string literals: identical COMDATs the linker dedups;
    # stripping them left Lua's keyword literals to zero stubs once their "real" definer left the link
    _dstripped |= _bad
    _dyn = [n[5:-7] for n in _defs if n.startswith('??__E') and n.endswith('@@YAXXZ')]   # ??__E<global>@@YAXXZ initializers
    if _l in _added and any(g in _exp for g in _dyn):
        continue   # it constructs a DLL's exported global in the exe (Ogre AnimableObject::msAnimableDictionary): drop it
    if _l in _added and _defs and sum(1 for n in _defs if n in _exp) >= max(1, 0.3 * len(_defs)):
        continue   # a gap-fill copy of DLL code (OgreMainOgreAnimable.cpp): its static initializers would build the DLL's
                   # data in the exe (msAnimableDictionary) -> drop the whole object, the DLL has it
    if _bad:
        _q = _ds / (re.sub(r'\W', '_', _p[-50:]) + '_' + _hl.md5(''.join(sorted(_bad)).encode()).hexdigest()[:8] + '.obj')
        if not _q.exists() or _q.stat().st_mtime < os.path.getmtime(_p):
            _q.write_bytes(bytes(_rb.strip_symbols(_b if _b is not None else Path(_p).read_bytes(), drop=_bad)))
        _l = '"%s"' % _q
    _ndr.append(_l)
_dr = _ndr
if _ddirty:
    _pk1.dump(_dcc, open(_dcf, 'wb'), protocol=4)
_tm('draft/gap-fill strip')
# class-name strings defined as `char* sX = "X"` (4-byte pointer) in some natives and `char sX[]` arrays in others mangle
# alike (?sX@RBX@@3PADA): the pointer copy winning made the name text read as pointer bytes. odrdiff.py lists them;
# strip the 4-byte definitions so the array copy is the one linked
try:
    _odr = json.loads((H / 'auto/odrdiff.json').read_text())
    _ptr = {}
    for _n, _bys in _odr.items():
        if '4' in _bys and any(int(z) > 4 for z in _bys) and _n.endswith('@3PADA'):
            for _o in _bys['4']:
                _ptr.setdefault(_o, set()).add(_n)
    _nfix = 0
    for i, _l in enumerate(out):
        _p = _l.strip().strip('"')
        _hit = [_ns for _o, _ns in _ptr.items() if _p.endswith(_o)]
        if _hit and os.path.exists(_p):
            _drop = set().union(*_hit)
            _q = _ds / ('odr_' + re.sub(r'\W', '_', _p[-50:]) + '.obj')
            if not _q.exists() or _q.stat().st_mtime < os.path.getmtime(_p):
                _q.write_bytes(bytes(_rb.strip_symbols(Path(_p).read_bytes(), drop=_drop)))
            out[i] = '"%s"' % _q; _nfix += 1
    if _nfix:
        print('class-name pointer copies stripped from %d objects (array definitions win)' % _nfix)
except Exception as _e:
    print('odr fix skipped:', _e)
# Strip bogus single-inheritance Stats::Item AbstractFactoryProduct vtable (20-slot, no -0x10 thunk) from unit_554 so unit_090's real 2-slot +0x10 vtable wins
out = [l for l in out if l not in _drs] + _dr
_bad_afp = {
    '??_7Item@Stats@RBX@@6B?$AbstractFactoryProduct@VInstance@RBX@@@2@@',
    '??_7?$NonFactoryProduct@VInstance@RBX@@$1?sStatsItem@Stats@2@3PADA@RBX@@6B?$AbstractFactoryProduct@VInstance@RBX@@@1@@',
    '??_7?$DescribedNonCreatable@VItem@Stats@RBX@@VInstance@3@$1?sStatsItem@23@3PADA@RBX@@6B?$AbstractFactoryProduct@VInstance@RBX@@@1@@',
}
_nafp = 0
for i, _l in enumerate(out):
    _p = _l.strip().strip('"')
    if ('unit-554' in _p or 'unit_554' in _p) and ('20261124-015202-c0ad3e45' in _p or '20261124_015202_c0ad3e45' in _p) and os.path.exists(_p):
        _q = _ds / ('afp_' + os.path.basename(_p))
        if not _q.exists() or _q.stat().st_mtime < os.path.getmtime(_p):
            _q.write_bytes(bytes(_rb.strip_symbols(Path(_p).read_bytes(), drop=_bad_afp)))
        out[i] = '"%s"' % _q; _nafp += 1
if _nafp:
    print('Stats::Item bogus AbstractFactoryProduct vtable stripped from %d object(s)' % _nafp)
out = [l for l in out if os.path.normcase(l.strip().strip('"')) not in _QOBJ]   # quarantined objects from the base list too
# auto/prefer_converted.json [symbol]: the exact converted body must win. Native drafts define functions as plain
# symbols, which beat the converted objects' COMDATs whatever the order (native TextXmlParser::parse threw on every file:
# its helpers disagreed with the converted ctor/readTag) -> strip those definitions from cached copies of the natives
try:
    _pcf = H / 'auto/prefer_converted.json'
    _pcs = set(json.loads(_pcf.read_text())) if _pcf.exists() and not os.environ.get('QT_NO_PREFERCONV') else set()
    if _pcs:
        _pcr = re.compile(b'|'.join(re.escape(n_.encode('latin-1')) for n_ in sorted(_pcs)))
        _npc = 0
        for i, l in enumerate(out):
            _p = l.strip().strip('"')
            if not _p.lower().endswith('.obj') or ('renamed' in _p and Path(_p).parent.name == 'obj') or not os.path.exists(_p):
                continue
            _b = Path(_p).read_bytes()
            if not _pcr.search(_b):
                continue
            _dd = {n_ for n_, d_ in _rb.coff_externals(_b).items() if d_} & _pcs
            if _dd:
                _q = _ds / ('pc_' + re.sub(r'\W', '_', _p[-60:]) + '.obj')
                _q.write_bytes(bytes(_rb.strip_symbols(_b, drop=_dd))); out[i] = '"%s"' % _q; _npc += 1
        # the converted object defines func_<addr> (rename.json symbol -> address): alias the stripped name to it
        _pca = {}
        for _ad, _x in json.load(open(H / 'renamed/rename.json')).items():
            if _x.get('symbol') in _pcs:
                _pca.setdefault(_x['symbol'], 'func_' + _ad)
        (H / 'aliases_preferconv.txt').write_text(''.join('%s=%s' % kv + chr(10) for kv in sorted(_pca.items())))   # read by the alias rebuild below
        print('prefer_converted: %d native objects stripped of %d listed symbols, %d aliased to func_<addr>' % (_npc, len(_pcs), len(_pca)))
except Exception as _epc:
    print('prefer_converted skipped:', _epc)
# vt_orig.obj's ORIGINAL vtables must win over every other copy. Converted copies are dropped by vt_strip.py; NATIVE
# objects define theirs as plain (non-COMDAT) symbols, which beat vt_orig's COMDATs whatever the order: the stock-header
# ??_SCamera@Ogre@@6BShadowCaster@1@@ in candidate.obj kept the near-clip getter returning 0. Strip those definitions
# from cached copies of the natives that carry them.
try:
    _vto2 = Path(os.environ['VTORIG_OBJ']) if os.environ.get('VTORIG_OBJ') else H / 'linkexp/vt_orig.obj'
    if _vto2.exists() and not os.environ.get('QT_NO_VTORIG'):
        _vtn = {n_ for n_, d_ in _rb.coff_externals(_vto2.read_bytes()).items() if d_}
        if (H / 'linkexp/vt_orig_remap.obj').exists() and not os.environ.get('QT_NO_VTREMAP'):
            _vtn |= {n_ for n_, d_ in _rb.coff_externals((H / 'linkexp/vt_orig_remap.obj').read_bytes()).items() if d_}
        _nvs = 0
        for i, _l in enumerate(out):
            _p = _l.strip().strip('"')
            if not _p.lower().endswith('.obj') or 'renamed' + os.sep + 'obj' in os.path.normpath(_p) or _p == str(_vto2) or _p.endswith('vt_orig_remap.obj'):
                continue
            _v = _xc1.get(_p)
            _defs2 = {n for n, d in _v[2].items() if d} if _v else set()
            _hit2 = _defs2 & _vtn
            if not _hit2:
                continue
            _q = _ds / ('vto_' + re.sub(r'\W', '_', _p[-50:]) + '_' + _hl.md5(''.join(sorted(_hit2)).encode()).hexdigest()[:8] + '.obj')
            if not _q.exists() or _q.stat().st_mtime < os.path.getmtime(_p):
                _q.write_bytes(bytes(_rb.strip_symbols(Path(_p).read_bytes(), drop=_hit2)))
            out[i] = '"%s"' % _q; _nvs += 1
        print('native objects stripped of vtables vt_orig.obj supplies: %d' % _nvs)
except Exception as _e:
    print('native vtable strip skipped:', _e)
# ANY non-converted object that is mostly a copy of DLL code (>= 30% of its definitions exported by a DLL import lib:
# OgreMainOgreAnimable.cpp reached the link as an ns_ copy): drop it, its static initializers build DLL data in the exe
_dll_copy = []
for _l in list(out):
    _p = _l.strip().strip('"')
    if _l in _dsok or _l.strip('"').endswith('dllvt.obj') or any(t_ in _l for t_ in _dstags):
        continue   # dllshadow_ok.txt: deliberate local copies of DLL const data
    if _p.lower().endswith('.obj') and 'renamed' + os.sep + 'obj' not in os.path.normpath(_p) and not _p.lower().endswith('stubs.obj'):
        _v = _xc1.get(_p)
        if _v:
            _dd = [n for n, d in _v[2].items() if d]
        else:
            try:
                _dd = [n for n, d in _rb.coff_externals(Path(_p).read_bytes()).items() if d] if os.path.exists(_p) else None
            except Exception:
                _dd = None
        _dyn = []
        if os.path.exists(_p) and ('draftstrip' in _p or not _v):   # static ??__E<global> initializers are not externals:
            try:                                                    # look for one built on a DLL-exported global
                _st2 = os.stat(_p); _k2 = ('dyn', _p)                # (cached by mtime/size with the draft defs)
                _e2 = _dcc.get(_k2)
                if _e2 and _e2[0] == (_st2.st_mtime_ns, _st2.st_size):
                    _all = _e2[1]
                else:
                    _all = [m_.decode('latin-1') for m_ in re.findall(rb'\?\?__E(\?[!-~]+?)@@YAXXZ', Path(_p).read_bytes())]
                    _dcc[_k2] = ((_st2.st_mtime_ns, _st2.st_size), _all); _ddirty = True
                _dyn = [g for g in _all if g in _exp]
            except Exception:
                _dyn = []
        if _dd and (sum(1 for n in _dd if n in _exp) >= max(1, 0.3 * len(_dd)) or _dyn):
            out.remove(_l); _dll_copy.append(os.path.basename(_p))
if _dll_copy:
    print('dropped %d objects that copy DLL code: %s' % (len(_dll_copy), ' '.join(_dll_copy[:5])))
if _ddirty:   # the DLL-copy scan adds its own cache entries
    _pk1.dump(_dcc, open(_dcf, 'wb'), protocol=4)
# aliases: rebuild from the CURRENT alias files (the old rsp lacks aliases added since, e.g. DLL!name import labels)
out = [l for l in out if not l.lower().startswith(('"/alternatename:', '/alternatename:', '"/include:__imp_', '/include:__imp_'))]
_pre_procs = [subprocess.Popen([sys.executable, str(H / _sc)], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, creationflags=0x08000000)
              for _sc in ('qualname_alias.py', 'draft_imports.py', 'rtclass.py', 'stubalias.py', 'createinst.py')]
for _pp_ in _pre_procs:
    _pp_.wait()
# binding audits (audits_all.py): normally already run in the background right after the previous link on that map
_t0w = _tt.time()
_stamp = H / 'auto/audits_stamp.json'
_pidf = H / 'auto/audits.pid'
while _pidf.exists() and _tt.time() - _t0w < float(os.environ.get('QT_AUDIT_WAIT', '0')):   # a post-link run is still going: wait briefly (its plans are one link old otherwise)
    try:
        os.kill(int(_pidf.read_text()), 0)
    except (OSError, ValueError):
        break
    _tt.sleep(2)
_mt = (H / 'linkexp/qt.map').stat().st_mtime if (H / 'linkexp/qt.map').exists() else 0
# stale audits no longer block the link (290 s when they were rerun inline): last run's plans apply; QT_AUDITS=1 forces
if os.environ.get('QT_AUDITS') or not _stamp.exists():
    subprocess.run([sys.executable, str(H / 'audits_all.py')], capture_output=True)
print('pre-link audits: %.0f s' % (_tt.time() - _t0w))
_azero = set(json.loads((H / 'auto/alias_zero.json').read_text())) if (H / 'auto/alias_zero.json').exists() else set()
_adrop = set(json.loads((H / 'auto/alias_drop.json').read_text())) if (H / 'auto/alias_drop.json').exists() and not os.environ.get('QT_NO_ALIASDROP') else set()
_adrop -= set(json.loads((H / 'auto/alias_drop_falsepos.json').read_text())) if (H / 'auto/alias_drop_falsepos.json').exists() else set()   # dropcheck.py: proven exact
for _an in ('aliases_override.txt', 'aliases.txt', 'aliases_auto.txt', 'aliases_renamed.txt', 'aliases_long.txt', 'aliases_twins.txt', 'aliases_qualname.txt', 'aliases_draftimp.txt', 'aliases_nameinit.txt', 'aliases_dllimports.txt', 'aliases_rtclass.txt', 'aliases_stubalias.txt', 'aliases_libalias.txt', 'aliases_bytealias.txt', 'aliases_createinst.txt', 'aliases_natdata.txt', 'aliases_access.txt', 'aliases_classdesc.txt', 'aliases_hardaddr.txt', 'auto/stub_aliases_dd4.txt', 'auto/stub_aliases_renamed.txt', 'auto/stub_aliases_thunks.txt', 'auto/stub_aliases_create.txt', 'aliases_preferconv.txt', 'aliases_boundprop.txt', 'aliases_createfix.txt', 'aliases_spell.txt', 'aliases_gemini.txt', 'aliases_deldtor.txt', 'aliases_zerodata.txt', 'aliases_srcaddr.txt', 'aliases_codematch.txt', 'aliases_datcode.txt', 'aliases_dupnative.txt', 'aliases_initgen.txt', 'aliases_colalias.txt', 'aliases_rbxinst.txt'):
    _af = H / _an
    if _an in os.environ.get('QT_SKIP_ALIASES', '').split(',') or (_an == 'aliases_colalias.txt' and os.environ.get('QT_NO_COLALIAS')):
        continue
    _gadj_off = bool(os.environ.get('QT_NO_GADJ')) and _an == 'aliases_deldtor.txt'   # bisect: deldtor_gen's general/COM adjustor wrappers
    if _af.exists():
        for _l in _af.read_text().splitlines():
            if _gadj_off and ('=?g@Dx_' in _l or '=?g@Dy_' in _l):
                continue
            if re.match(r'^\?s\w+@(?:\w+@)*@3(PADA|PBDB|QBDB)=\?s\w+@(?:\w+@)*@3(PADA|PBDB|QBDB)$', _l.strip()) and ((_l.strip().split('=')[0].endswith('PADA') != _l.strip().endswith('PADA')) if os.environ.get('QT_OLD_CLASSGUARD') else (_l.strip().split('=')[0].endswith('PBDB') != _l.strip().endswith('PBDB'))):   # array (PADA/QBDB: `const char sX[]` mangles 3QBDB too) vs pointer (PBDB)
                continue   # char[] class name <-> pointer variable: the Name read the pointer's bytes (Motor/Glue/Hat garbage -> Insert sort ran off the vector)
            if '=' in _l and not _l.startswith('#') and (_an == 'aliases_override.txt' or _l.strip() not in _adrop) and (_an in (('aliases_override.txt',) if os.environ.get('QT_OLD_AZERO') else ('aliases_override.txt', 'aliases_zerodata.txt', 'aliases_initgen.txt')) or _l.split('=', 1)[0].strip() not in _azero):   # override: proven bodies, read first   # aliasaudit.py: proven-foreign func_<A> bindings
                # ?G1_func_<X>@@ is the analog's name for what func_<X> CALLS, not func_<X> itself: aliasing it to
                # func_<X> turned the thunk 00433370 (jmp 006a10c4) into `jmp $` -> the client spun forever before
                # showing its frame. Point it at the real callee (converted callers' refs) or drop it.
                _gm = re.match(r'^\?G\d+_func_([0-9a-f]{8})@@\S*=func_([0-9a-f]{8})$', _l.strip())
                if _gm and _gm.group(1) == _gm.group(2):
                    _k = _l.strip().split('=', 1)[0]
                    try:
                        _ra = _g1refs
                    except NameError:
                        _ra = _g1refs = {}
                        for _x in json.load(open(H / 'renamed/rename.json')).values():
                            for _kk, _vv in (_x.get('refs') or {}).items():
                                if re.match(r'^\?G\d+_func_', _kk):
                                    _ra.setdefault(_kk, set()).add(_vv)
                    _tg = _ra.get(_k, set())
                    if len(_tg) == 1 and next(iter(_tg)) != _gm.group(1):
                        _tg0 = next(iter(_tg))
                        try:   # the callee is an IMPORT THUNK in the original (006a10c4 = jmp [mfc90 #3819]): the import itself
                            _gimp = _g1imp
                        except NameError:
                            import pefile as _pf5, struct as _st5
                            _o5 = _pf5.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True)
                            _o5.parse_data_directories(directories=[_pf5.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
                            _om5 = json.load(open(H / 'renamed/ordinals.json')).get('mfc90.dll', {})
                            _ia5 = {}
                            for _d5 in _o5.DIRECTORY_ENTRY_IMPORT:
                                for _i5 in _d5.imports:
                                    _n5 = _i5.name.decode() if _i5.name else (_om5.get(str(_i5.ordinal)) if _d5.dll.decode().lower() == 'mfc90.dll' else None)
                                    if _n5 and _n5.startswith('?'):
                                        _ia5[_i5.address] = _n5
                            _gimp = _g1imp = (_o5.get_memory_mapped_image(), _ia5, _st5)
                        _im5, _ia5, _st5 = _gimp
                        _o_ = int(_tg0, 16) - 0x400000
                        _imp = _ia5.get(_st5.unpack_from('<I', _im5, _o_ + 2)[0]) if _im5[_o_:_o_ + 2] == b'\xff\x25' else None
                        out.append('"/alternatename:%s=%s"' % (_k, _imp or ('func_' + _tg0)))
                    continue
                out.append('"/alternatename:%s"' % _l.strip())
                if _l.strip().split('=', 1)[1].startswith('__imp_'):
                    out.append('"/INCLUDE:%s"' % _l.strip().split('=', 1)[1])
# Diagnostic variant: original direct-import thunk bindings.
out += ['"/alternatename:func_0069fc5a=_FMOD_Memory_GetStats"',
        '"/alternatename:func_0078c560=_GetSysColor@4"']
# the reused stubs.obj predates the current aliases: its stub definitions would shadow them (/alternatename only fills
# undefined names), so strip every aliased name from a copy (init_tss_data stayed a stub -> tss::set threw)
# one /alternatename per name: alias files disagree (aliases_natdata dat_0092907c=??_R0?AVInstance@RBX@@@8 vs
# aliases_rtclass dat_0092907c=_g_0092907c, defined nowhere). The undefined target won, pass 2 zero-stubbed the name, and
# Instance's TypeDescriptor read "" -> dynamic_cast<Instance> NULL for Seat/Sky/LocalScript/... (Insert Object). Keep the
# first target the previous link DEFINED (non-stub); else the first one.
try:
    _pdef = _prev_defs
except NameError:
    _pdef = _prev_defs = set()
    if (H / 'linkexp/qt.map').exists():
        for _l in open(H / 'linkexp/qt.map', errors='replace'):
            _p = _l.split()
            if len(_p) >= 4 and ':' in _p[0] and 'stubs' not in _p[-1]:
                _pdef.add(_p[1])
_alt = {}
for _i, _l in enumerate(out):
    if _l.lower().startswith('"/alternatename:'):
        _k, _v = _l.split(':', 1)[1].rstrip('"').split('=', 1)
        _alt.setdefault(_k, []).append((_i, _v))
_drop = set()
# circular pairs (aliases_rtclass dat_0092907c=_g_0092907c + _g_0092907c=dat_0092907c; aliases_qualname QAE<->UAE dtor
# spellings) never reach a definition and, listed first, shadow the real alias: Instance's TypeDescriptor went zero again
_pair = {}
for _i, _l in enumerate(out):
    if _l.lower().startswith('"/alternatename:'):
        _k, _v = _l.split(':', 1)[1].rstrip('"').split('=', 1)
        _pair.setdefault((_k, _v), _i)
_circ = {_i for (_k, _v), _i in _pair.items() if (_v, _k) in _pair and _k not in _pdef and _v not in _pdef}   # one side
# defined -> the pair is a valid two-way spelling bridge (startup needed 136 of those)
if _circ and os.environ.get('QT_CIRC'):   # off by default (bisecting the File->New bad_alloc)
    print('circular alias pairs dropped: %d lines' % len(_circ))
    out = [l for i, l in enumerate(out) if i not in _circ]
    _alt = {}   # indices changed: rebuild
    for _i, _l in enumerate(out):
        if _l.lower().startswith('"/alternatename:'):
            _k, _v = _l.split(':', 1)[1].rstrip('"').split('=', 1)
            _alt.setdefault(_k, []).append((_i, _v))


def _reaches_def(_t, _seen=()):
    """the alias chain from _t (first entries) ends at a definition of the previous link; circular -> False"""
    for _ in range(6):
        if _t in _pdef:
            return True
        if _t in _seen or _t not in _alt:
            return False
        _seen = _seen + (_t,)
        _t = _alt[_t][0][1]
    return False


for _k, _vs in _alt.items():
    # only data placeholders (dat_<A>): the broad version (714 names) re-pointed code aliases whose first target is defined
    # by THIS link's new results (absent from the previous map) -> null XTP vtable slot at startup. A first target that is
    # only an alias back to the name (_g_0092907c=dat_0092907c) is circular: it zero-stubbed Instance's TypeDescriptor.
    if len(_vs) > 1 and _k.startswith('dat_') and not _reaches_def(_vs[0][1], (_k,)):
        _good = [x for x in _vs if _reaches_def(x[1], (_k,))]
        _win = (_good or _vs)[0][0]
        _drop |= {i for i, _ in _vs if i != _win}
if _drop:
    print('alias conflicts resolved: %d names, %d lines dropped' % (sum(1 for v in _alt.values() if len(v) > 1), len(_drop)))
    out = [l for i, l in enumerate(out) if i not in _drop]
_lhs = {l.split(':', 1)[1].rstrip('"').split('=', 1)[0] for l in out if l.lower().startswith('"/alternatename:')}
# objects swapped in by --results define names the older stubs.obj stubbed (AutoRecover_00603c60: buildControlHud)
try:
    from roc.rebuild import coff_externals as _cx2
    for _o in (_new.values() if _rr else []):
        _lhs |= {n_ for n_, d_ in _cx2(Path(_o).read_bytes()).items() if d_}
except NameError:
    pass
sys.path.insert(0, str(H.parents[1]))
from roc import rebuild as _rb
for i, l in enumerate(out):
    p = l.strip().strip('"')
    if os.path.basename(p).lower() == 'stubs.obj' and os.path.exists(p):
        _b = Path(p).read_bytes()
        _q = QP('linkexp/qt_base_stubs.obj')
        # extern "C" placeholder spellings the base stubs define as zero data (_g_00826be0, _dat_X, _func_X): the real
        # placeholder (original bytes, relocated pointers) instead
        _ph = {n: (('dat_' + n[3:]) if n.startswith('_g_') else ('func_' + n[4:]) if n.startswith('_fn_') else n[1:]) for n, d in _rb.coff_externals(_b).items()
               if d and re.match(r'^_(?:dat|func|g|fn)_[0-9a-f]{8}$', n)}
        out += ['"/alternatename:%s=%s"' % kv for kv in _ph.items()]
        _tlib = H / 'linkexp/tmplinst.lib'   # names tmplinst.lib instantiates: the library, not a stub
        _tls = _dn0.lib_symbols(_tlib) if _tlib.exists() else set()
        if (H / 'linkexp/ogreinline.lib').exists() and not os.environ.get('QT_NO_OGREINLINE'):
            _tls |= _dn0.lib_symbols(H / 'linkexp/ogreinline.lib')
        if (H / 'linkexp/tmplinst_rbx.lib').exists() and not os.environ.get('QT_NO_RBXTMPL'):
            _tls |= _dn0.lib_symbols(H / 'linkexp/tmplinst_rbx.lib')
        if (H / 'linkexp/extra_imports.lib').exists() and not os.environ.get('QT_NO_EXTRAIMP'):   # DLL exports: never base stubs
            _tls |= _dn0.lib_symbols(H / 'linkexp/extra_imports.lib')
        if (H / 'linkexp/nameinit.obj').exists() and not os.environ.get('QT_NO_NAMEINIT'):   # its Name& globals: never base stubs
            _tls |= {n_ for n_, d_ in _rb.coff_externals((H / 'linkexp/nameinit.obj').read_bytes()).items() if d_}
        # names a library IN this link defines (rgmain/atls/mfc import libs, CRT): the library, never a base stub
        # (?Create@CImage@ATL@@ stayed a base stub after the qt_stubs filter -> loadIcon got 0)
        for _ll in out:
            if _ll.lower().endswith('.lib"') and os.path.exists(_ll[1:-1]) and 'tmplinst' not in _ll.lower():
                _tls |= _dn0.lib_symbols(Path(_ll[1:-1]))
        # import THUNKS among the base stubs (func_0069fc7e = jmp [IAT] -> rgmain MemoryDataStream::read): alias to the
        # import instead of a `ret` stub (origcover: 4 rgmain DataStream thunks ran as base stubs on the File->New path)
        _bth = {}
        try:
            import pefile as _pf6, struct as _st6
            _o6 = _pf6.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True)
            _o6.parse_data_directories(directories=[_pf6.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
            _oi6 = _o6.get_memory_mapped_image()
            _iat6 = {i_.address: (d_.dll.decode().lower(), i_.name.decode()) for d_ in _o6.DIRECTORY_ENTRY_IMPORT for i_ in d_.imports if i_.name}
            try:   # mfc90 ordinal imports too (see _iat7)
                _om6 = json.load(open(H / 'renamed/ordinals.json')).get('mfc90.dll', {})
            except (OSError, ValueError):
                _om6 = {}
            _iat6.update({i_.address: ('mfc90.dll', _om6[str(i_.ordinal)]) for d_ in _o6.DIRECTORY_ENTRY_IMPORT for i_ in d_.imports
                          if not i_.name and d_.dll.decode().lower() == 'mfc90.dll' and str(i_.ordinal) in _om6})
            for n_, d_ in _rb.coff_externals(_b).items():
                m6 = re.match(r'^func_([0-9a-f]{8})$', n_) if d_ else None
                if not m6:
                    continue
                o6 = int(m6.group(1), 16) - 0x400000
                if _oi6[o6:o6 + 2] != b'\xff\x25':
                    continue
                dll6, nm6 = _iat6.get(_st6.unpack_from('<I', _oi6, o6 + 2)[0], (None, None))
                if nm6 and nm6.startswith('?'):
                    _bth[n_] = nm6
                elif nm6 and dll6 in ('msvcr90.dll', 'msvcp90.dll'):
                    _bth[n_] = _CRT_STD.get(nm6, '_' + nm6)
            out += ['"/alternatename:%s=%s"' % kv for kv in sorted(_bth.items())]
            print('base-stub import thunks aliased to their import: %d' % len(_bth))
        except Exception as _e6:
            print('base-stub thunk aliasing skipped:', _e6)
        # the base stubs' dat_ copies predate data_relocs' pointers into OTHER data: CRobloxApp's message map
        # dat_00816c50 kept lpEntries = 0 -> mfc90 called a NULL handler for WM_COMMAND. Drop them: the stub pass
        # rebuilds each with original bytes + current relocations (_data_item)
        _bdat = {n_ for n_, d_ in _rb.coff_externals(_b).items() if d_ and re.match(r'^dat_[0-9a-f]{8}$', n_)}
        print('base-stub dat_ copies rebuilt by the stub pass: %d' % len(_bdat))
        # named function stubs whose callee-pop bytes changed since the base was built (by-value class sizes learned
        # by valsizes.py: CMainFrame/DxUserInput::onEvent(Heartbeat) popped 8 of 12 -> RunService thread corrupted)
        try:
            import make_stubs as _ms8
            _old8 = json.load(open(H / 'link/undname_cache.json'))
            _bret = {n_ for n_, d_ in _rb.coff_externals(_b).items() if d_ and n_.startswith('?') and n_ in _old8
                     and _old8[n_] is not None and _ms8.signature_ret_bytes(n_) not in (None, _old8[n_])}
        except Exception as _e8:
            _bret = set(); print('base-stub ret check skipped:', _e8)
        print('base-stub functions with changed pop size, rebuilt: %d %s' % (len(_bret), sorted(_bret)[:3]))
        _bdat |= _bret
        try:   # base stubs the original-binary truth corrects: wrong pop size, or glue the stub pass can rebuild
            import glue as _gl9
            _sro9 = json.load(open(H / 'auto/stubret_override.json')) if (H / 'auto/stubret_override.json').exists() else {}
            _bg = {n_ for n_, d_ in _rb.coff_externals(_b).items() if d_ and ((n_ in _sro9 and not os.environ.get('QT_NO_SRO')) or (n_.startswith(('func_', '?')) and not os.environ.get('QT_NO_GLUE') and _gl9.item(n_)))}
            print('base stubs rebuilt for pop size / glue: %d' % len(_bg))
            _bdat |= _bg
        except Exception as _e9:
            print('base glue check skipped:', _e9)
        _bmm = set() if os.environ.get('QT_NO_MSGMAPFIX') else {n_ for n_, d_ in _rb.coff_externals(_b).items() if d_ and n_.startswith('?messageMap@?1??GetThisMessageMap@')}   # MFC message maps: qt_stubs rebuilds them from the original bytes (relocated base map + entries); zero here broke Explorer/Toolbox routing
        _q.write_bytes(bytes(_rb.strip_symbols(_b, drop=_lhs | set(_ph) | _tls | set(_bth) | _bdat | _bmm)))
        out[i] = '"%s"' % _q
# call-identity repair (callaudit.py, last link): converted objects whose analog callee NAME binds real code of another
# function get that symbol renamed to func_<original target> in a patched copy (func_00792440 called boost's
# basic_regex::compare instead of the thunk 0078e6e0 -> CXTButton::SetColorFace crashed)
try:
    import callfix as _cf
    _cfp = _cf.plan(QP('linkexp/qt.map'))
    # converted calls to the WRONG Lua API name (005aeaf0 set the script identity with lua_pushboolean instead of the
    # original's lua_pushlightuserdata 00612410 -> ScriptImpersonator left a nil on the stack, no script ever ran); the
    # validator dropped these renames, auto/callfix_lua_restore.json keeps them
    try:
        for _o, _m in json.loads((H / 'auto/callfix_lua_restore.json').read_text()).items():
            _cfp.setdefault(_o, {}).update(_m)
    except (OSError, ValueError):
        pass
    # EH cleanup aliases verified against original unwind maps and object relocations.
    try:
        for _o, _m in json.loads((H / 'auto/callfix_unwind_restore.json').read_text()).items():
            _cfp.setdefault(_o, {}).update(_m)
    except (OSError, ValueError):
        pass
    # + converted objects' private writable statics -> dat_<original address> (datafix.py; cached per rename.json):
    # SafeChat::singleton read its own _localScope while the converted init wrote dat_0097d944
    _dfc = H / 'auto/datafix_plan.json'
    if not os.environ.get('QT_NO_DATAFIX'):
        if not _dfc.exists() or _dfc.stat().st_mtime < max((H / 'renamed/rename.json').stat().st_mtime, (H / 'renamed/results.json').stat().st_mtime):
            import datafix as _df
            _dfc.write_text(json.dumps(_df.plan(QP('linkexp/qt.map'))))
        for _k, _v in json.loads(_dfc.read_text()).items():
            _cfp = dict(_cfp); _cfp.setdefault(_k, {}); _cfp[_k] = {**_v, **_cfp[_k]}
    # + foldaudit.py: one native static bound from several original addresses (registry-folded doDeclare<sDecal>::n:
    # 50 Names shared one slot -> NetworkClient overwrote Decal, clientIsPresent true, Run greyed) -> dat_<orig>
    if not os.environ.get('QT_NO_FOLDFIX') and (H / 'auto/foldfix_plan.json').exists():
        for _k, _v in json.loads((H / 'auto/foldfix_plan.json').read_text()).items():
            _cfp = dict(_cfp); _cfp.setdefault(_k, {}); _cfp[_k] = {**_v, **_cfp[_k]}
    _cfd = H / 'linkexp/callfix'
    _cfd.mkdir(exist_ok=True)
    _ncf = 0
    for i, l in enumerate(out):
        _bn = os.path.basename(l.strip('"'))
        if _bn in _cfp and l.strip('"').lower().endswith('.obj') and os.path.exists(l.strip('"')):
            _pp = _cf.patch(l.strip('"'), _cfp[_bn], _cfd)
            if _pp:
                out[i] = '"%s"' % _pp; _ncf += 1
    print('callfix: %d converted objects with callee symbols retargeted (plan %d)' % (_ncf, len(_cfp)))
    # natbody_check.py: a converted body whose registry name S is wrong (boost::mutex::do_lock 0x594ce0 named
    # recursive_mutex::do_lock) beat the native S at link -> recursive mutex never released, Run deadlocked.
    # Rename the converted DEFINITION S -> func_<A> in a patched copy: the native S wins, func_<A> keeps its body
    import struct
    _ndr = json.loads((H / 'auto/natbody_defrename.json').read_text()) if (H / 'auto/natbody_defrename.json').exists() and not os.environ.get('QT_NO_DEFRENAME') else {}
    _ndn = 0
    for i, l in enumerate(out):
        _pth = l.strip('"'); _bn = os.path.basename(_pth)
        _bn0 = _bn[3:] if _bn.startswith('cf_') else _bn
        _ren = _ndr.get(_bn) or _ndr.get(_bn0) or _ndr.get(re.sub(r'^.*?([0-9a-f]{8}\.obj)$', r'\1', _bn))
        if not _ren or not _pth.lower().endswith('.obj') or not os.path.exists(_pth):
            continue
        _d = bytearray(Path(_pth).read_bytes())
        _, _, _, _sp, _ns, _, _ = struct.unpack_from('<HHIIIHH', _d, 0)
        _st = _sp + _ns * 18; _tail = bytearray(_d[_st + 4:]); _k = 0; _hit = 0
        while _k < _ns:
            _at = _sp + 18 * _k; _raw = bytes(_d[_at:_at + 8]); _sec = struct.unpack_from('<H', _d, _at + 12)[0]; _na = _d[_at + 17]
            if _raw[:4] == b'\0\0\0\0':
                _o = _st + struct.unpack_from('<I', _raw, 4)[0]; _nm = bytes(_d[_o:_d.index(b'\0', _o)]).decode('latin-1')
            else:
                _nm = _raw.rstrip(b'\0').decode('latin-1')
            if _nm in _ren and 0 < _sec < 0xfffe:
                _nb = _ren[_nm].encode('latin-1')
                if len(_nb) <= 8:
                    _d[_at:_at + 8] = _nb.ljust(8, b'\0')
                else:
                    _d[_at:_at + 8] = struct.pack('<II', 0, 4 + len(_tail)); _tail += _nb + b'\0'
                _hit += 1
            _k += 1 + _na
        if _hit:
            _d = _d[:_st] + struct.pack('<I', 4 + len(_tail)) + _tail
            _q = _cfd / ('dr_' + _bn); _q.write_bytes(bytes(_d)); out[i] = '"%s"' % _q; _ndn += 1
    print('natbody defrename: %d converted objects gave a misnamed symbol back to its native definition' % _ndn)
except Exception as _ecf:
    print('callfix skipped:', _ecf)


import struct  # noqa: E402
# natdata.py: native statics that dat_ placeholders alias to (the XTP hook-manager singleton) must be EXTERNAL for
# /alternatename to bind them: link a copy whose symbol storage class is flipped static -> external
try:
    _nx = json.loads((H / 'auto/natdata_extern.json').read_text()) if (H / 'auto/natdata_extern.json').exists() else {}
    _nx[str(H / 'renamed/obj/0061fb20.obj')] = ['?pushArgs@@YAIPAUlua_State@@ABV?$vector@Vany@boost@@V?$allocator@Vany@boost@@@std@@@std@@@Z']
    def _nxkey(p_):   # unique key: base name, candidate.obj -> <unit dir>_candidate.obj, nx_ prefix stripped
        b_ = Path(p_).name
        b_ = b_[3:] if b_.startswith('nx_') else b_
        return Path(p_).parent.parent.name + '_' + Path(p_).parent.name + '_candidate.obj' if b_ == 'candidate.obj' else b_   # run dir + unit dir
    _nxb = {}
    for _k0, _v0 in _nx.items():
        _nxb.setdefault(_nxkey(_k0), []).append(_k0)
    _nxb = {k_: v_[0] for k_, v_ in _nxb.items() if len(v_) == 1}   # unique keys only
    _nxd = H / 'linkexp/natext'
    _nxd.mkdir(exist_ok=True)
    _nicf = _nxd / '_ni_cache.pkl'
    try:
        _nic = _pk1.load(open(_nicf, 'rb'))
    except Exception:
        _nic = {}
    _nidirty = False
    _nnx = 0
    for i, l in enumerate(out):
        _p = l.strip().strip('"')
        _nxk = _p if _p in _nx else _nxb.get(_nxkey(_p))   # keyed by path or by base name (nx_ stripped)
        if _nxk and os.path.exists(_p):
            _q = _nxd / ('nx_' + _nxkey(_p))
            _stx = os.stat(_p)
            _wkey = ('nx', _p, _stx.st_mtime_ns, _stx.st_size, tuple(sorted(_nx[_nxk])))
            if _nic.get(('nx', _p)) == _wkey and _q.exists():
                out[i] = '"%s"' % _q; _nnx += 1; continue
            _d = bytearray(Path(_p).read_bytes())
            _, _, _, _sp, _ns, _, _ = struct.unpack_from('<HHIIIHH', _d, 0)
            _st = _sp + _ns * 18; _k = 0; _want = set(_nx[_nxk])
            while _k < _ns:
                _raw = bytes(_d[_sp + 18 * _k:_sp + 18 * _k + 8]); _cls = _d[_sp + 18 * _k + 16]; _na = _d[_sp + 18 * _k + 17]
                if _raw[:4] == b'\0\0\0\0':
                    _o = _st + struct.unpack_from('<I', _raw, 4)[0]; _nm = bytes(_d[_o:_d.index(b'\0', _o)]).decode('latin-1')
                else:
                    _nm = _raw.rstrip(b'\0').decode('latin-1')
                if _nm in _want and _cls == 3:
                    _d[_sp + 18 * _k + 16] = 2
                _k += 1 + _na
            _q.write_bytes(bytes(_d)); out[i] = '"%s"' % _q; _nnx += 1
            _nic[('nx', _p)] = _wkey; _nidirty = True
    print('natdata: objects relinked with native statics made external: %d' % _nnx)
    # natinit.py targets (dat_X -> native global + offset) must be EXTERNAL too: a static native _prop_profileName left
    # the renamed reference undefined -> a never-constructed stub copy -> null manager on File->New
    _nif = H / 'auto/natinit_plan.json'
    _niw = {v_[0] for v_ in json.loads(_nif.read_text()).values()} if _nif.exists() and not os.environ.get('QT_NO_NIFLIP') else set()
    _nimt = _hl.md5('\n'.join(sorted(_niw)).encode('latin-1')).hexdigest()[:12] if _niw else ''
    _niwr = re.compile(b'|'.join(re.escape(n_.encode('latin-1')) for n_ in sorted(_niw))) if _niw else None
    _nflip = 0
    for i, l in enumerate(out):
        _p = l.strip().strip('"')
        if not _niw or not _p.lower().endswith('.obj') or ('renamed' in _p and Path(_p).parent.name == 'obj') or not os.path.exists(_p):
            continue
        _stf = os.stat(_p)
        _fk = (_stf.st_mtime_ns, _stf.st_size, _nimt)
        _fc = _nic.get(('nf', _p))
        if _fc and _fc[0] == _fk:
            if _fc[1] and os.path.exists(_fc[1]):
                out[i] = '"%s"' % _fc[1]; _nflip += 1
            continue
        _d = bytearray(Path(_p).read_bytes())
        if not _niwr.search(_d):
            _nic[('nf', _p)] = (_fk, None); _nidirty = True
            continue
        _, _, _, _sp, _ns, _, _ = struct.unpack_from('<HHIIIHH', _d, 0)
        _st = _sp + _ns * 18; _k = 0; _hit = False
        while _k < _ns:
            _raw = bytes(_d[_sp + 18 * _k:_sp + 18 * _k + 8]); _cls = _d[_sp + 18 * _k + 16]; _na = _d[_sp + 18 * _k + 17]
            _sec = struct.unpack_from('<h', _d, _sp + 18 * _k + 12)[0]
            if _cls == 3 and _sec > 0:
                _nm = bytes(_d[_st + struct.unpack_from('<I', _raw, 4)[0]:_d.index(b'\0', _st + struct.unpack_from('<I', _raw, 4)[0])]).decode('latin-1') if _raw[:4] == b'\0\0\0\0' else _raw.rstrip(b'\0').decode('latin-1')
                _ty = struct.unpack_from('<H', _d, _sp + 18 * _k + 14)[0]
                _g = _nm if _nm.startswith('?') else _nm[1:]
                # only the native object that CONSTRUCTS the global (its ??__E initializer is here), data symbols only:
                # flipping every same-named static (87 objects) made duplicates and crashed lld
                if _nm in _niw and _ty == 0 and ('??__E' + _g + '@@YAXXZ').encode('latin-1') in _d and not struct.unpack_from('<I', _d, 20 + struct.unpack_from('<H', _d, 16)[0] + 40 * (_sec - 1) + 36)[0] & 0x1000:   # not COMDAT (lld crashed)
                    _d[_sp + 18 * _k + 16] = 2; _hit = True
            _k += 1 + _na
        if _hit:
            _q = _nxd / ('nf_' + _nxkey(_p)); _q.write_bytes(bytes(_d)); out[i] = '"%s"' % _q; _nflip += 1
            _nic[('nf', _p)] = (_fk, str(_q)); _nidirty = True
        else:
            _nic[('nf', _p)] = (_fk, None); _nidirty = True
    if _nidirty:
        try:
            _pk1.dump(_nic, open(_nicf, 'wb'), protocol=4)
        except OSError:
            pass
    print('natinit targets made external in native objects: %d' % _nflip)
except Exception as _enx:
    print('natdata extern step skipped:', _enx)
# natcallaudit.py: native drafts whose callee symbol binds different code than the original call (ContentProvider's
# plain mutex declared recursive_mutex -> recursive do_lock corrupted its content map) -> callee renamed to func_<T>
try:
    if not os.environ.get('QT_NO_NATCALLFIX') and (H / 'auto/natcallfix_plan.json').exists():
        import callfix as _cf2
        _ncp = {Path(k).name: v for k, v in json.loads((H / 'auto/natcallfix_plan.json').read_text()).items()}
        _ncd = H / 'linkexp/natcallfix'; _ncd.mkdir(exist_ok=True); _nnc = 0
        for i, l in enumerate(out):
            _p = l.strip().strip('"'); _bn = Path(_p).name
            _r = _ncp.get(_bn) or (_ncp.get(_bn[3:]) if _bn.startswith('nx_') else None)
            if _r and _p.lower().endswith('.obj') and os.path.exists(_p):
                _pp = _cf2.patch(_p, _r, _ncd)
                if _pp:
                    out[i] = '"%s"' % _pp; _nnc += 1
        print('natcallfix: %d native objects with callees retargeted to the original target' % _nnc)
except Exception as _encf:
    print('natcallfix skipped:', _encf)
# hardaddr.py: dat_<X> copies of original data whose bytes are a REAL library/our symbol (c_dfDIMouse2: the copy's
# rgodf pointer was stale -> DirectInput E_INVALIDARG -> File->New aborted setDataModel). Rename the reference in each
# object: an alias alone lost to a stub copy.
try:
    if not os.environ.get('QT_NO_HARDADDR') and (H / 'aliases_hardaddr.txt').exists():
        import hardaddr as _ha, callfix as _cf3
        _hap = _ha.rename_plan([l.strip().strip('"') for l in out if l.strip().strip('"').lower().endswith('.obj')])
        _had = H / 'linkexp/hardaddr'; _had.mkdir(exist_ok=True); _nha = 0
        for i, l in enumerate(out):
            _p = l.strip().strip('"')
            if _p in _hap:
                _pp = _cf3.patch(_p, _hap[_p], _had)
                if _pp:
                    out[i] = '"%s"' % _pp; _nha += 1
        print('hardaddr: %d objects with dat_ copies renamed to the real data symbol' % _nha)
except Exception as _eha:
    print('hardaddr skipped:', _eha)
# collidefix.py: generic analog data names bound to DIFFERENT original addresses in different converted objects
# (163 objects shared the static guard ?flag@@3JA) -> each object's reference renamed to dat_<its original address>
try:
    if not os.environ.get('QT_NO_COLLIDE'):
        import collidefix as _clf, callfix as _cf4
        _clp = _clf.plan()
        _cld = H / 'linkexp/collide'; _cld.mkdir(exist_ok=True); _ncl = 0
        for i, l in enumerate(out):
            _p = l.strip().strip('"')
            _m = re.search(r'([0-9a-f]{8})\.obj$', _p)
            if not _m or not _p.lower().endswith('.obj') or not os.path.exists(_p):
                continue
            _r = _clp.get(_m.group(1) + '.obj')
            if _r and ('renamed' in _p or 'callfix' in _p or 'hardaddr' in _p or 'collide' in _p):
                _und = {n_ for n_, d_ in _rb.coff_externals(Path(_p).read_bytes()).items() if not d_}
                _r = {k_: v_ for k_, v_ in _r.items() if k_ in _und}
                if _r:
                    _pp = _cf4.patch(_p, _r, _cld)
                    if _pp:
                        out[i] = '"%s"' % _pp; _ncl += 1
        print('collidefix: %d converted objects with colliding data names renamed to dat_<original>' % _ncl)
except Exception as _ecl:
    print('collidefix skipped:', _ecl)
# dtorfix.py: registry ??1T names on the WRONG body (RTTI-proven, auto/dtoraudit.json): references -> Dtf_<true address>
try:
    if not os.environ.get('QT_NO_DTORFIX') and (H / 'auto/dtoraudit.json').exists():
        import dtorfix as _dtf, callfix as _cf6
        _dtp = _dtf.plan([l.strip().strip('"') for l in out if l.strip().strip('"').lower().endswith('.obj')])
        _dtd = H / 'linkexp/dtorfix'; _dtd.mkdir(exist_ok=True); _ndt = 0
        for i, l in enumerate(out):
            _p = l.strip().strip('"')
            if _p in _dtp:
                _pp = _cf6.patch(_p, _dtp[_p], _dtd)
                if _pp:
                    out[i] = '"%s"' % _pp; _ndt += 1
        out += ['"/alternatename:%s=%s"' % kv for kv in sorted(_dtf.aliases().items())]
        # the wrong body's own object DEFINES ??1T plainly (beats the native COMDAT ~T): rename that definition to
        # Dtw_<reg>, keep its address name pointing at it, and let ??1T fall to the true body
        _wh, _nwh = _dtf.wrong_holders(), 0
        _fx = _dtf._fixes()
        _newal = []
        for i, l in enumerate(out):
            _p = l.strip().strip('"')
            _r = _wh.get(Path(_p).name) if _p.lower().endswith('.obj') else None
            if _r and os.path.exists(_p):
                _pp = _dtf.rename_defs(_p, _r, _dtd)
                if _pp:
                    out[i] = '"%s"' % _pp; _nwh += 1
                    for _k, _v in _r.items():
                        _newal.append(('func_' + _v[4:], _v))
                        if _k in _fx:
                            _newal.append((_k, _fx[_k][1]))
        # an older func_<reg>=??1T alias (aliases_renamed) would win (first line) and send this body's own callers to T's
        # true destructor: drop earlier lines for these names
        _nk = {k for k, _ in _newal}
        out = [x for x in out if not (x.lower().startswith('"/alternatename:') and x.split(':', 1)[1].split('=', 1)[0] in _nk)]
        out += ['"/alternatename:%s=%s"' % kv for kv in _newal]
        print('dtorfix: %d objects with mislabeled destructor references retargeted, %d wrong definitions renamed' % (_ndt, _nwh))
except Exception as _edt:
    print('dtorfix skipped:', _edt)
# natinit.py: dat_X placeholders that are (members of) a NATIVE global paired by initializer literals
# (dat_00976b94 = ScriptContext::propScriptsDisabled + 0x18): every referencing object gets the symbol renamed to the
# native global and the addend raised by the member offset (a copy in linkexp/natinit)
try:
    _nip = json.loads((H / 'auto/natinit_plan.json').read_text()) if (H / 'auto/natinit_plan.json').exists() and not os.environ.get('QT_NO_NATINIT') else {}
    if _nip:
        _nid = H / 'linkexp/natinit'; _nid.mkdir(exist_ok=True); _nni = 0
        _nkeys = [k.encode() for k in _nip]
        _nip_set = set(_nip)   # set intersection / one regex instead of a per-key scan of every object (16 s)
        _nkre = re.compile(b'|'.join(re.escape(k_) for k_ in sorted(_nkeys, key=len, reverse=True)))
        for i, l in enumerate(out):
            _p = l.strip().strip('"')
            if not _p.lower().endswith('.obj') or not os.path.exists(_p):
                continue
            _v = _xc1.get(_p)
            if _v and _nip_set.isdisjoint(_v[2]):
                continue
            _d = bytearray(Path(_p).read_bytes())
            if _v is None and not _nkre.search(_d):
                continue
            _, _nsec, _, _sp, _ns, _opt, _ = struct.unpack_from('<HHIIIHH', _d, 0)
            _st = _sp + _ns * 18; _tail = bytearray(_d[_st + 4:]); _k = 0; _hit = {}; _canon = {}
            while _k < _ns:
                _at = _sp + 18 * _k; _raw = bytes(_d[_at:_at + 8]); _sec = struct.unpack_from('<h', _d, _at + 12)[0]; _na = _d[_at + 17]
                if _sec == 0:
                    if _raw[:4] == bytes(4):
                        _o = _st + struct.unpack_from('<I', _raw, 4)[0]; _nm = bytes(_d[_o:_d.index(0, _o)]).decode('latin-1')
                    else:
                        _nm = _raw.rstrip(bytes(1)).decode('latin-1')
                    if _nm in _nip:
                        _S, _off = _nip[_nm]
                        if _S not in _canon:
                            _canon[_S] = _k; _nb = _S.encode('latin-1')
                            _d[_at:_at + 8] = struct.pack('<II', 0, 4 + len(_tail)); _tail += _nb + bytes(1)
                        _hit[_k] = (_canon[_S], _off)
                _k += 1 + _na
            if not _hit:
                continue
            for _sx in range(_nsec):
                _sh = 20 + _opt + 40 * _sx
                _raw_ptr, _rel_ptr = struct.unpack_from('<II', _d, _sh + 20)
                _nrel = struct.unpack_from('<H', _d, _sh + 32)[0]
                for _r in range(_nrel):
                    _ra = _rel_ptr + 10 * _r
                    _ro, _ri, _rt = struct.unpack_from('<IIH', _d, _ra)
                    if _ri in _hit:
                        _ci, _off = _hit[_ri]
                        struct.pack_into('<I', _d, _ra + 4, _ci)
                        if _off and _rt in (6, 7):   # DIR32 / DIR32NB: the stored dword is the addend
                            _w = _raw_ptr + _ro; struct.pack_into('<I', _d, _w, (struct.unpack_from('<I', _d, _w)[0] + _off) & 0xffffffff)
            _d = _d[:_st] + struct.pack('<I', 4 + len(_tail)) + _tail
            _q = _nid / ('ni_' + Path(_p).name); _q.write_bytes(bytes(_d)); out[i] = '"%s"' % _q; _nni += 1
        print('natinit: %d objects rebound dat_ placeholders to native globals (+member offset)' % _nni)
except Exception as _eni:
    print('natinit skipped:', _eni)
# relocsplit.py: converted objects that addressed an unnamed original global as NEAREST SYMBOL + addend
# (0x973f48 = propArchivable+0xd4) read the wrong native object: retarget each such relocation to the item it lands in
try:
    if not os.environ.get('QT_NO_RELOCSPLIT'):
        import relocsplit as _rs
        print('relocsplit: %d objects, %d relocations retargeted' % _rs.apply(out))
except Exception as _ers:
    print('relocsplit skipped:', _ers)
# dllexstrip.py: local/analog copies of code rgmain.dll exports (Singleton<T>::getSingletonPtr read ms_Singleton
# through a jmp thunk) become undefined -> the DLL's export
try:
    if not os.environ.get('QT_NO_DLLEXSTRIP'):
        import dllexstrip as _dx
        print('dllexstrip: %d objects, %d rgmain-exported code copies sent to the DLL' % _dx.apply(out))
except Exception as _edx:
    print('dllexstrip skipped:', _edx)
# spellunify.py: one instantiation per template despite class-name spelling (two Part ClassDescriptors -> Insert Object
# use-after-free). References + COMDAT definitions renamed to the 3PADA spelling.
try:
    if not os.environ.get('QT_NO_SPELLUNIFY'):
        import spellunify as _su
        _sur = _su.renames()
        _sud = H / 'linkexp/spellunify'; _sud.mkdir(exist_ok=True); _nsu = 0
        if _sur:
            _suo = set(_su.plan([l.strip().strip('"') for l in out if l.strip().strip('"').lower().endswith('.obj')], _sur))
            for i, l in enumerate(out):
                _p = l.strip().strip('"')
                if _p in _suo:
                    _pp = _su.rename_comdat(_p, _sur, _sud)
                    if _pp:
                        out[i] = '"%s"' % _pp; _nsu += 1
            # aliases whose TARGET is a variant now point at a renamed definition (func_004a3dd0 -> 0, Insert crash): retarget
            _nal = 0
            for i, l in enumerate(out):
                if l.lower().startswith('"/alternatename:'):
                    _k, _v = l.split(':', 1)[1].rstrip('"').split('=', 1)
                    if _v in _sur:
                        out[i] = '"/alternatename:%s=%s"' % (_k, _sur[_v]); _nal += 1
            print('spellunify: %d alias targets moved to the 3PADA spelling' % _nal)
        print('spellunify: %d objects unified to the 3PADA instantiation (%d variant names)' % (_nsu, len(_sur)))
except Exception as _esu:
    print('spellunify skipped:', _esu)
# luaunify.py: ONE Lua runtime (the original's C-named one): strip the C++-mangled Lua copy, alias its names to C
try:
    if os.environ.get('QT_LUAUNIFY'):   # off by default: stripping the C++ Lua pulled a third copy from the Lua archive
        import luaunify as _lu
        _lum = _lu.mapping()
        _lud = H / 'linkexp/luaunify'; _lud.mkdir(exist_ok=True); _nlu = 0
        _luk = [k.encode('latin-1') for k in _lum]
        for i, l in enumerate(out):
            _p = l.strip().strip('"')
            if not _p.lower().endswith('.obj') or 'renamed' + os.sep + 'obj' in os.path.normpath(_p) or not os.path.exists(_p):
                continue   # original-derived objects use the C names already
            _b = Path(_p).read_bytes()
            if b'?lua' not in _b and b'?f_parser' not in _b:
                continue
            _ex = _rb.coff_externals(_b)
            _dd = [n for n, d in _ex.items() if d and n in _lum]
            _uu = {n: _lum[n] for n, d in _ex.items() if not d and n in _lum}
            if _dd or _uu:
                _q = _lud / ('lu_' + Path(_p).name)
                _q.write_bytes(_rb.strip_symbols(_b, drop=_dd) if _dd else _b)
                # references renamed to the C names too: an undefined C++ Lua name pulled a THIRD copy from the Lua
                # archive (lapi/lparser/... members) before the alias could apply
                if _uu:
                    import callfix as _cf7
                    _q2 = _cf7.patch(str(_q), _uu, _lud)
                    _q = Path(_q2) if _q2 else _q
                out[i] = '"%s"' % _q; _nlu += 1
        out = [x for x in out if not (x.lower().startswith('"/alternatename:') and x.split(':', 1)[1].split('=', 1)[0] in _lum)]
        out += ['"/alternatename:%s=%s"' % kv for kv in sorted(_lum.items())]
        print('luaunify: %d objects stripped of the C++ Lua copy, %d names aliased to the C Lua' % (_nlu, len(_lum)))
except Exception as _elu:
    print('luaunify skipped:', _elu)
# ONE Lua: Roblox's own (LuaRobloxL*.cpp, rbx luaconf: 12-byte extra space, lua_exception; built as C++ by the wrapper
# run in auto/luarbx_run.txt). Every other Lua definition (C drafts, C++ drafts, stock 5.1.4 archives) is stripped and
# every C-spelled reference renamed to the rbx C++ name: mixed copies kept separate statics and no script could load.
try:
    _lrf = H / 'auto/luarbx_run.txt'
    if not os.environ.get('QT_NO_LUARBX') and _lrf.exists():
        import callfix as _cf8
        _lrun = (H.parents[1] / _lrf.read_text().strip()).resolve()
        _lrj = json.load(open(_lrun / 'results.json')); _lrj = _lrj if isinstance(_lrj, list) else _lrj['results']
        _lrobjs = {str(Path(x['object']).resolve()).lower() for x in _lrj if x.get('object')}
        _lrid = _lrun.name.replace('-', '_')   # copies keep the run id in their names (vto_ns_<run>_unit_...)
        _ldefs = set()
        for _o in _lrobjs:
            _ldefs |= {n for n, d in _rb.coff_externals(Path(_o).read_bytes()).items() if d and re.match(r'^\?(lua|luaL_|luaopen_|luai_)', n)}
        _c2p = {}
        for _n in _ldefs:
            _m = re.match(r'^\?(\w+)@@', _n)
            if _m:
                _c2p['_' + _m.group(1)] = _n
        _kill = set(_ldefs) | set(_c2p)
        _lcd = H / 'linkexp/luacpp'; _lcd.mkdir(exist_ok=True); _nlc = 0
        _ck = re.compile(b'lua|f_parser')
        _lcf = H / 'linkexp/luarbx_cache.pkl'
        try:
            _lcc = _pk1.load(open(_lcf, 'rb'))
            if _lcc.get('_lrid') != _lrid:
                _lcc = {'_lrid': _lrid}
        except Exception:
            _lcc = {'_lrid': _lrid}
        _lcdirty = False
        for i, l in enumerate(out):
            _p = l.strip().strip('"')
            if not _p.lower().endswith('.obj') or not os.path.exists(_p) or str(Path(_p).resolve()).lower() in _lrobjs or _lrid in _p.replace('-', '_'):
                continue
            _st = os.stat(_p)
            _ckey = (_st.st_mtime_ns, _st.st_size)
            _ce = _lcc.get(_p)
            if _ce and _ce[0] == _ckey:
                if _ce[1] and os.path.exists(_ce[1]):
                    out[i] = '"%s"' % _ce[1]; _nlc += 1
                    continue
                elif _ce[1] is None:
                    continue
            _b = Path(_p).read_bytes()
            if not _ck.search(_b):
                _lcc[_p] = (_ckey, None); _lcdirty = True
                continue
            _ex = _rb.coff_externals(_b)
            _dd = [n for n, d in _ex.items() if d and n in _kill]
            _uu = {n: _c2p[n] for n, d in _ex.items() if not d and n in _c2p}
            if not _dd and not _uu:
                _lcc[_p] = (_ckey, None); _lcdirty = True
                continue
            _q = _lcd / ('lc_' + Path(_p).name)
            _q.write_bytes(_rb.strip_symbols(_b, drop=_dd) if _dd else _b)
            if _uu:
                _q2 = _cf8.patch(str(_q), _uu, _lcd)
                _q = Path(_q2) if _q2 else _q
            _lcc[_p] = (_ckey, str(_q)); _lcdirty = True
            out[i] = '"%s"' % _q; _nlc += 1
        if _lcdirty:
            _pk1.dump(_lcc, open(_lcf, 'wb'), protocol=4)
        out += ['"/alternatename:%s=%s"' % kv for kv in sorted(_c2p.items())]
        # the stock 5.1.4 Lua archives (out/Lua, out/LuaCpp) must not supply members any more: references to names the
        # rbx copy keeps static (luaB_*, f_parser) pulled whole stock files and their own C copy back in
        _nb = len(out)
        out = [x for x in out if not re.search(r'[\\/]out[\\/]Lua(Cpp)?[\\/]linked[\\/]linked\.lib', x, re.I)]
        print('luarbx: stock Lua archives dropped: %d' % (_nb - len(out)))
        print('luarbx: %d objects moved to Roblox Lua (%d rbx Lua names, %d C spellings)' % (_nlc, len(_ldefs), len(_c2p)))
except Exception as _elc:
    print('luarbx skipped:', _elc)
# dtorfix definition rename, AFTER every other object patch (natinit/callfix copies rebuilt from the original path lost
# the earlier rename: ??1Decal kept resolving to 0040b8a0's body -> Insert Object close freed garbage)
try:
    if not os.environ.get('QT_NO_DTORFIX') and (H / 'auto/dtoraudit.json').exists():
        import dtorfix as _dtf2
        _wh2, _nw2 = _dtf2.wrong_holders(), 0
        _dtd2 = H / 'linkexp/dtorfix'; _dtd2.mkdir(exist_ok=True)
        for i, l in enumerate(out):
            _p = l.strip().strip('"')
            if not _p.lower().endswith('.obj'):
                continue
            _bn = Path(_p).name
            _r = next((v for k, v in _wh2.items() if _bn == k or _bn.endswith('_' + k)), None)
            if _r and os.path.exists(_p):
                _pp = _dtf2.rename_defs(_p, _r, _dtd2)
                if _pp:
                    out[i] = '"%s"' % _pp; _nw2 += 1
        print('dtorfix (final): wrong destructor definitions renamed in %d objects' % _nw2)
except Exception as _edt2:
    print('dtorfix final skipped:', _edt2)


def _chain(lines_, through=frozenset()):
    """lld does not chain /alternatename (_fn_X -> func_X -> real name): point every alias at its final target"""
    al_ = {}
    for l_ in lines_:
        if l_.lower().startswith('"/alternatename:'):
            k_, _, v_ = l_[len('"/alternatename:'):].rstrip('"').partition('=')
            al_.setdefault(k_, v_)
    out_ = []
    for l_ in lines_:
        if l_.lower().startswith('"/alternatename:'):
            k_, _, v_ = l_[len('"/alternatename:'):].rstrip('"').partition('=')
            seen_ = {k_}
            # only through names the link left undefined, or placeholders (func_/dat_ carry an alias only when no
            # object defines them under that name)
            v0_ = v_
            while v_ in al_ and v_ not in seen_ and (v_ in through or v_.startswith(('func_', 'dat_'))):
                seen_.add(v_)
                v_ = al_[v_]
            if v_ in seen_:   # cycle (buildChatMenu=func_00603730=buildChatMenu): keep the direct target
                v_ = v0_
            while False:
                seen_.add(v_)
                v_ = al_[v_]
            l_ = '"/alternatename:%s=%s"' % (k_, v_)
        out_.append(l_)
    return out_


qr = QP('linkexp/qt.rsp')
_tm('aliases + base stubs + chain prep')
# previous run's stubs in the first link (copies, stripped of names an /alternatename now covers): usually no relink
# Isolated diagnostic: expose the original-matched native cache helper.
_cache_name = '?getLocalCachePath@RBX@@YA?AV?$CPathT@V?$CStringT@DV?$StrTraitATL@DV?$ChTraitsCRT@D@ATL@@@ATL@@@ATL@@@ATL@@_N@Z'
_cache_hits = 0
for _ci, _cl in enumerate(out):
    _cp = Path(_cl.strip().strip('"'))
    if '20261124-015202-c0ad3e45_unit-1135_candidate.obj' not in _cp.name:
        continue
    _cd = bytearray(_cp.read_bytes())
    _, _, _, _cs, _cn, _, _ = struct.unpack_from('<HHIIIHH', _cd, 0)
    _ct = _cs + _cn * 18
    _ci0 = 0
    while _ci0 < _cn:
        _at = _cs + 18 * _ci0
        _raw = bytes(_cd[_at:_at + 8])
        if _raw[:4] == b'\0\0\0\0':
            _pos = _ct + struct.unpack_from('<I', _raw, 4)[0]
            _nm = bytes(_cd[_pos:_cd.index(b'\0', _pos)]).decode('latin-1')
        else:
            _nm = _raw.rstrip(b'\0').decode('latin-1')
        if _nm == _cache_name and _cd[_at + 16] == 3:
            _cd[_at + 16] = 2
            _cache_hits += 1
        _ci0 += 1 + _cd[_at + 17]
    _cache_dir = H / 'linkexp/codex_cacheproof'
    _cache_dir.mkdir(exist_ok=True)
    _cache_obj = _cache_dir / _cp.name
    _cache_obj.write_bytes(_cd)
    out[_ci] = '"%s"' % _cache_obj
if _cache_hits != 1:
    raise RuntimeError('cache helper visibility target not unique: %d' % _cache_hits)
_prev = []
_aliased = {l_[len('"/alternatename:'):].split('=', 1)[0] for l_ in out if l_.lower().startswith('"/alternatename:')}
# tmplinst.lib (tmplinst.py: explicit STL/Ogre template instantiations) answers names the stubs used to: strip them from
# the reused stubs so the library members get pulled in, and link the library after every object
_tl = H / 'linkexp/tmplinst.lib'
if _tl.exists():
    import defined_now as _dn1
    _aliased |= _dn1.lib_symbols(_tl)
    out = out + ['"%s"' % _tl]
_ol = H / 'linkexp/ogreinline.lib'   # tmplinst.py --inline: Ogre header-inline members compiled locally
if _ol.exists() and not os.environ.get('QT_NO_OGREINLINE'):
    import defined_now as _dn1
    _aliased |= _dn1.lib_symbols(_ol)
    out = out + ['"%s"' % _ol]
_xi = H / 'linkexp/extra_imports.lib'   # dllimports.py: DLL exports we only had as stubs (FMOD C API, GDI+ flat API)
if _xi.exists() and not os.environ.get('QT_NO_EXTRAIMP'):
    import defined_now as _dn1
    _aliased |= _dn1.lib_symbols(_xi)
    out = out + ['"%s"' % _xi]
_rl = H / 'linkexp/tmplinst_rbx.lib'   # tmplinst.py --rbx: Roblox class-template instances (FactoryProduct<Camera>...)
if _rl.exists() and not os.environ.get('QT_NO_RBXTMPL'):
    import defined_now as _dn1
    _aliased |= _dn1.lib_symbols(_rl)
    out = out + ['"%s"' % _rl]
_absolute = {'__roc_abs_zero'} if (H / 'linkexp/abszero.obj').exists() else set()
_aliased |= _absolute
_pu = [u for u in (QP('linkexp/qt_prev_und.txt')).read_text().split() if u not in _absolute] if (QP('linkexp/qt_prev_und.txt')).exists() else []
for _n in ('qt_stubs', 'qt_stubs2'):
    _src = H / 'linkexp' / (_n + '.obj')
    if _src.exists() and '--fresh' not in sys.argv:
        _db = _src.read_bytes()
        _drop = {n for n, d in _rb.coff_externals(_db).items() if d} & _aliased   # symbol table once (substring search per alias took minutes)
        (H / 'linkexp' / (_n + '_prev.obj')).write_bytes(bytes(_rb.strip_symbols(_db, drop=_drop)) if _drop else _db)
        _prev.append('"%s"' % (H / 'linkexp' / (_n + '_prev.obj')))
print('dllshadow_ok: %d exempt, %d still in the link' % (len(_dsok), len([l for l in out if l in _dsok])))
qr.write_text('\n'.join(_chain(out) + _prev) + '\n')


def _predict_new_und():
    """names the first link would report undefined, resolved statically over EVERY linked object (per-object externals
    cached by mtime/size): undefined references minus object definitions, previous stubs, aliases, library symbols and
    last-map names owned by libraries/DLLs. Counting only CHANGED objects missed names whose definer LEFT the link
    (quarantined drafts, stripped copies) -> a third lld pass (~40-70 s). Non-empty -> skip the doomed first link and
    stub+link once. A false name is harmless (stubs link after every object, never shadowing a library member)."""
    import pickle as _pk7
    _exe, _map = QP('linkexp/qt.exe'), QP('linkexp/qt.map')
    if '--fresh' in sys.argv or not _exe.exists() or not _map.exists() or not _prev:
        return None
    objs_ = [l[1:-1] for l in out if l.startswith('"') and l.lower().endswith('.obj"')]
    _cf = QP('linkexp/qt_ext_cache.pkl')
    from shardcache import ShardCache as _SC7
    _c = _SC7(_cf)   # sharded: a changed object rewrites one shard, not 2 GB
    und_, def_, dirty = set(), set(), False
    _ren_dir = str((H / 'renamed/obj').resolve()).lower() + os.sep
    _ren_objs = [p for p in objs_ if p.lower().startswith(_ren_dir)]
    _oth_objs = [p for p in objs_ if not p.lower().startswith(_ren_dir)]
    _raf = QP('linkexp/ren_agg_cache.pkl')
    import hashlib as _hl7
    _rkey = (len(_ren_objs), int(os.stat(H / 'renamed/obj').st_mtime_ns) if (H / 'renamed/obj').exists() else 0, _hl7.md5('\n'.join(_ren_objs).encode('latin-1')).hexdigest()[:16])
    _rahit = False
    try:
        _ra = _pk7.load(open(_raf, 'rb'))
        if _ra[0] == _rkey:
            def_ |= _ra[1]; und_ |= _ra[2]; _rahit = True
    except Exception:
        pass
    if not _rahit:
        _rdef, _rund = set(), set()
        for p in _ren_objs:
            try:
                st = os.stat(p)
            except OSError:
                continue
            v = _c.get(p)
            if not v or v[0] != (st.st_mtime_ns, st.st_size):
                e = _rb.coff_externals(Path(p).read_bytes())
                v = _c[p] = ((st.st_mtime_ns, st.st_size), frozenset(n for n, d in e.items() if d), frozenset(n for n, d in e.items() if not d))
                dirty = True
            _rdef |= v[1]; _rund |= v[2]
        def_ |= _rdef; und_ |= _rund
        try:
            _pk7.dump((_rkey, frozenset(_rdef), frozenset(_rund)), open(_raf, 'wb'), protocol=4)
        except OSError:
            pass
    for p in _oth_objs:
        try:
            st = os.stat(p)
        except OSError:
            continue
        v = _c.get(p)
        if not v or v[0] != (st.st_mtime_ns, st.st_size):
            e = _rb.coff_externals(Path(p).read_bytes())
            v = _c[p] = ((st.st_mtime_ns, st.st_size), frozenset(n for n, d in e.items() if d), frozenset(n for n, d in e.items() if not d))
            dirty = True
        def_ |= v[1]; und_ |= v[2]
    if dirty:
        _c.save()
    global _pred_defs
    _pred_defs = def_   # every name an object now defines (COMDAT included): sticky stubs must not shadow them
    known = set(_pu) | _aliased | def_
    for l_ in _map.read_text(errors='replace').splitlines():
        p_ = l_.split()
        if len(p_) >= 4 and ':' in p_[0] and (':' in p_[-1] or not p_[-1].lower().endswith('.obj')):
            known.add(p_[1])   # owner 'lib:member' (CRT, MFC/Win32 DLL imports) or the linker itself (___ImageBase)
    import defined_now as _dn2
    for l in out:
        if l.lower().endswith('.lib"') and os.path.exists(l[1:-1]):
            known |= _dn2.lib_symbols(Path(l[1:-1]))
    try:   # DEFAULT libraries too (winspool/ole32/uuid/CRT via /DEFAULTLIB): defined_now.py lists them. Missing them
        known |= set(json.load(open(H / 'renamed/defined.json')))   # stubbed 654 Win32/CRT names (classscan G)
    except (OSError, ValueError):
        pass
    try:   # last run's pass-3 leftovers (names only library members / vt_orig.obj pull in): the same ~14 come back every
        # run and cost a whole second lld pass (~40 s); still-undefined ones are stubbed up front
        und_ = set(und_) | set((QP('linkexp/qt_und2.txt')).read_text().split())
    except OSError:
        pass
    return und_ - known


_pred = _predict_new_und() if not os.environ.get('QT_NO_PREDICT') else None
if _pred is not None:
    # the first link runs WITHOUT stubs, so it always "discovers" the previous ~22k stub names again (~40 s). The
    # prediction already covers new names; previous + predicted is the same list: skip the discovery link. Names no
    # longer needed are filtered below (library/linker names) or harmless (stubs link after every object).
    print('predicted %d new undefined names (e.g. %s): skipping the first link' % (len(_pred), sorted(_pred)[:3]))
    # an aliased name must not get a stub (a definition beats the alias): every /alternatename key the link will see,
    # not just _aliased (aliases _chain adds back were missed -> func_005a5200=?setCamera got a stub, camera never set)
    _alk2 = {l_[len('"/alternatename:'):].split('=', 1)[0] for l_ in qr.read_text().splitlines() if l_.lower().startswith('"/alternatename:')}
    # a previous stub name that an object now DEFINES (even as COMDAT) must not be stubbed again: the plain stub beat
    # the COMDAT definition (Lua keyword literals ??_C@_03...and -> zero, luaX_init marked garbage, no script parsed)
    _pdx = globals().get('_pred_defs') or set()
    log, und = '', sorted((set(_pu) - _aliased - _alk2 - _pdx) | (_pred - _alk2))
else:
    r = subprocess.run([sys.executable, str(H / 'lld_link.py'), '--xtp-first'], capture_output=True, text=True,
                       env=dict(os.environ, LLD_RSP=str(qr), LLD_LOG=str(QP('linkexp/qt_lld.log'))))
    log = r.stdout + r.stderr + (QP('linkexp/qt_lld.log')).read_text(errors='replace') if (QP('linkexp/qt_lld.log')).exists() else r.stdout + r.stderr
    print((r.stdout.strip().splitlines() or ['?'])[-1])
    und = sorted(set(re.findall(r'undefined symbol: (\S+)', log)) - _absolute)
_tm('first lld link')
und = [u for u in und if u not in _absolute]
und0 = list(und)
if not und:   # the previous stubs covered everything: keep their name list for stub_exact / stubhits
    (QP('linkexp/qt_und.txt')).write_text('\n'.join(_pu))
else:   # a relink is needed anyway: regenerate the stubs for previous + new names (later links drop the _prev copies)
    und = sorted(set(und) | (set(_pu) - _aliased - (globals().get('_pred_defs') or set())))
if und:   # names the reused stubs.obj does not cover (new objects): stub them like make_stubs (ret 0 / data), relink once
    sys.path.insert(0, str(H))
    import coffstub
    # draft spellings of real functions among the new undefined names: alias instead of stubbing
    (QP('linkexp/qt_und.txt')).write_text('\n'.join(sorted(set(und) | set(_pu))))
    subprocess.run([sys.executable, str(H / 'qualname_alias.py'), str(QP('linkexp/qt_und.txt'))], capture_output=True)
    _qa = dict(l.split('=', 1) for l in (H / 'aliases_qualname.txt').read_text().splitlines() if '=' in l and not l.startswith('#'))
    # extern "C" spellings of placeholders (_dat_00826bd4 from `extern "C" void* dat_00826bd4[]`) are the placeholder itself
    # (_g_00826be0: a draft's name for original data -> the dat_ placeholder, which carries the original bytes)
    _pl = lambda u: ('dat_' + u[3:]) if u.startswith('_g_') else ('func_' + u[4:]) if u.startswith('_fn_') else u[1:]
    _qa.update({u: _pl(u) for u in und if re.match(r'^_(?:dat|func|g|fn)_[0-9a-f]{8}$', u)})
    # fastcall spellings (@fn_00562730@16): the function at that address too
    _qa.update({u: 'func_' + re.match(r'^@fn_([0-9a-f]{8})@\d+$', u).group(1) for u in und
                if re.match(r'^@fn_[0-9a-f]{8}@\d+$', u) and u not in _qa})
    out += ['"/alternatename:%s=%s"' % (u, _qa[u]) for u in und if u in _qa]
    # names lld synthesizes: a stub copy wins over them (___ImageBase stubbed -> WinMain got a stub's address as
    # hInstance -> MFC's SetCurrentHandles threw CUserException at startup)
    _LINKER = {'___ImageBase', '__ImageBase', '___safe_se_handler_table', '___safe_se_handler_count', '__load_config_used',
               '___guard_check_icall_fptr', '___guard_fids_table', '___guard_fids_count', '___guard_flags', '___dynamic_value_reloc_table'}
    und = [u for u in und if u not in _LINKER]
    try:   # never stub a C name a library defines (a stub defined first wins over the lazily pulled library member)
        # C and C++ names: any name still undefined here but in defined.json is supplied by a LIBRARY (objects always
        # link) -- a stub of ATL's ?Create@CImage@ATL@@ shadowed atls.lib (stub hits: loadIcon)
        # only libraries actually IN this link (and names the last link resolved from a library/DLL): defined.json
        # also lists names whose definer is not linked, which then came back undefined (875 -> a third pass, ~50 s)
        import defined_now as _dn5
        _libc = set()
        for _l in out:
            if _l.lower().endswith('.lib"') and os.path.exists(_l[1:-1]):
                _libc |= _dn5.lib_symbols(Path(_l[1:-1]))
        if (QP('linkexp/qt.map')).exists():
            for _ml in (QP('linkexp/qt.map')).read_text(errors='replace').splitlines():
                _mp = _ml.split()
                if len(_mp) >= 4 and ':' in _mp[0] and ':' in _mp[-1]:
                    _libc.add(_mp[1])
        _libc = {d for d in _libc if not d.startswith(('func_', 'dat_', '_func_', '_dat_', '_g_', '_fn_', '@fn_'))}
        _libc -= set(json.load(open(H / 'renamed/addrmap.json')))   # conversion targets (may have failed): stubs still allowed
        _nl = len(und); und = [u for u in und if u not in _libc]
        if _nl != len(und):
            print('not stubbed (library-defined C names): %d' % (_nl - len(und)))
    except (OSError, ValueError):
        pass
    _uset = set(und)   # set: `in und` on a 19k-name list per name was quadratic (minutes)
    und += [_pl(u) for u in list(und) if re.match(r'^_(?:dat|func|g|fn)_[0-9a-f]{8}$', u) and _pl(u) not in _uset]
    # (reverted 2026-11-24: stubbing last run's pass-2 names up front pinned stubs over REAL code -- their qualname alias
    # targets exist, e.g. ??$?0H@Value@@ -> Value<int> ctor in 0042d280.obj. Find why lld leaves them undefined first.)
    _lo = set()
    und = [u for u in und if u not in _qa]
    fn = [u for u in und if u.startswith('func_') or (u.endswith('Z') and not u.startswith('??_R')) or re.match(r'^@\w+@\d+$', u) or re.match(r'^_[A-Za-z]\w*(@\d+)?$', u)]
    # C-spelled names converted callers bind to an original DATA address are variables, not functions: the call_once
    # flag _flagInitScriptCpp was a `mov eax,0; ret` in .text -> InterlockedIncrement on a code page (Insert Object)
    try:
        _cref = {}
        for _x9 in json.load(open(H / 'renamed/rename.json')).values():
            for _k9, _v9 in (_x9.get('refs') or {}).items():
                if re.match(r'^_[A-Za-z]\w*$', _k9):
                    _cref.setdefault(_k9, set()).add(_v9)
        _cdat = {k_ for k_, v_ in _cref.items() if len(v_) == 1 and int(next(iter(v_)), 16) >= 0x7c0000}
        if (H / 'auto/cdata.json').exists():   # cnames.py: C names no object ever calls (DIR32-only references)
            _cdat |= set(json.loads((H / 'auto/cdata.json').read_text()))
        fn = [u for u in fn if u not in _cdat]
        print('C-spelled data names stubbed as data (original data address): %d' % len(set(und) & _cdat))
    except Exception as _e9c:
        _cdat = set()
        print('C data-name check skipped:', _e9c)
    _fset = set(fn)   # built once (it was rebuilt for every name)
    da = [u for u in und if u not in _fset]
    import make_stubs as _ms0
    _ms = _ms0
    try:   # one undname process per 40 names (signature_ret_bytes alone started one per name: ~18 min for 19k stubs)
        _ms0.prefetch_demangle([u for u in und if u.startswith('?')])
    except Exception:
        pass
    try:   # callee-pop truth from the original binary (stubret.py: vtable slots + func_<X>)
        _sro = {} if os.environ.get('QT_NO_SRO') else json.load(open(H / 'auto/stubret_override.json'))
    except (OSError, ValueError):
        _sro = {}
    import glue as _glue

    def _sitem(u):   # trivial original glue (this-adjust / forwarding thunks) rebuilt with relocations, else a stub
        return (None if os.environ.get('QT_NO_GLUE') else _glue.item(u)) or (u, _ms._sret_body(u) or 0, _ret(u))

    def _ret(u):
        if u in _sro:
            return _sro[u]
        m = re.match(r'^(?:_|@)\w+@(\d+)$', u)
        if m:
            return max(int(m.group(1)) - (8 if u.startswith('@') else 0), 0)
        m = re.match(r'^func_([0-9a-f]{8})$', u)
        if m:
            return _ms0.addr_ret_bytes(int(m.group(1), 16))
        if u.startswith('?'):   # thiscall/stdcall C++ name: pop what its signature takes (draft ?raise@Signal@@QAEXUHeartbeat@@@Z)
            try:
                return _ms0.signature_ret_bytes(u) or 0
            except Exception:
                return 0
        return 0
    # dat_<addr>: original bytes with function / string pointers relocated (make_stubs' builder); zero 4 KB had
    # left a const char* global NULL (func_004492d0 -> string compare crash)
    import make_stubs as _ms
    # named data whose ORIGINAL address is known (unique registry name): original bytes + relocated pointers like dat_.
    # CMainFrame's ?messageMap@?1??GetThisMessageMap static was 4 KB of zeros: no WM_CREATE handler -> no MDI client ->
    # "Failed to create empty document."
    _nadr = {}
    try:
        _rg = json.load(open(H.parents[1] / 'work/2008-06/identity-registry.json'))
        _cn = {}
        for _a, _v in _rg.items():
            _n = (_v or {}).get('name')
            if _n and not _v.get('placeholder'):
                _cn[_n] = _cn.get(_n, 0) + 1
                _nadr[_n] = int(_a, 16)
        _nadr = {n_: a_ for n_, a_ in _nadr.items() if _cn[n_] == 1 and 0x7c0000 <= a_ < 0x9a0000}
    except Exception:
        _nadr = {}
    try:   # ANALOG-named globals (no registry name) whose converted callers all bind ONE original data address: original
        # bytes too. 114 such globals had non-zero bytes in the original (tables, function-pointer slots) but linked as
        # zero blocks; same class as the NULL Name& tags (vtaudit/datatype_audit session 2026-11-24)
        _rr = json.load(open(H / 'renamed/rename.json'))
        _aa = {}
        for _x in _rr.values():
            for _k, _v in (_x.get('refs') or {}).items():
                if _k.startswith('?') and re.search(r'@@[0-3]', _k) and not _k.startswith('??_'):
                    _aa.setdefault(_k, set()).add(_v)
        _n0 = len(_nadr)
        for _k, _vs in _aa.items():
            if len(_vs) == 1 and _k not in _nadr:
                _a = int(next(iter(_vs)), 16)
                if 0x7c0000 <= _a < 0x9a0000:
                    _nadr[_k] = _a
        _nadr.update({k_: int(next(iter(_cref[k_])), 16) for k_ in _cdat if k_ not in _nadr and len(_cref.get(k_, ())) == 1})   # C-spelled data too
        print('analog-named globals given their original bytes: %d' % (len(_nadr) - _n0))
    except Exception as _e8:
        print('analog global original bytes skipped:', _e8)
    _dl = []

    def _data_item(u, va):
        n_ = _ms.data_size(va)
        return (u, _ms.orig_bytes(va, n_), max(n_, 16), _ms.data_relocs(va, n_))
    # dat_<addr> whose address the registry names and REAL code in our link defines (vtables the native class owns:
    # the literal-rewritten AuthoringSettings ctor stored dat_0080bbd4 = a byte copy with null slots -> call 00000000):
    # alias to that definition instead of an original-bytes copy
    _own11 = {}
    try:
        for _l11 in QP('linkexp/qt.map').read_text(errors='replace').splitlines():
            _p11 = _l11.split()
            if len(_p11) >= 4 and ':' in _p11[0] and 'stubs' not in _p11[-1]:
                _own11.setdefault(_p11[1], _p11[-1])
        _rg11 = _rg
    except Exception:
        _rg11 = {}
    _dal = {}
    for u in da:
        _m = re.match(r'^dat_([0-9a-f]{8})$', u)
        _n11 = (_rg11.get(_m.group(1)) or {}).get('name') if _m else None
        if _m and _n11 and _n11 in _own11 and not _n11.startswith('dat_'):
            _dal[u] = _n11
            continue
        if _m:
            _dl.append(_data_item(u, int(_m.group(1), 16)))
        elif u in _nadr:
            _dl.append(_data_item(u, _nadr[u]))
        else:
            _dl.append((u, b'', 4096))
    if _dal:
        out = out + ['"/alternatename:%s=%s"' % kv for kv in sorted(_dal.items())]
    print('dat_ placeholders aliased to the real definition at their address (vtables...): %d' % len(_dal))
    _dl += [(s_, b_, len(b_) + 3 & ~3) for s_, b_ in sorted(_ms.STRS.items())]
    # relocation targets the link may not define (func_007a16a0, a vtable slot): stub them too, or the pointer is 0
    # (converted objects link first, so a duplicate stub never wins over a real definition)
    try:
        _def = {d for d in json.load(open(H / 'renamed/defined.json')) if not d.startswith(('func_', 'dat_'))}
    except Exception:
        _def = set()
    _def |= {'func_' + re.search(r'([0-9a-f]{8})\.obj$', o).group(1) for o in conv}   # linked converted objects
    _have = set(fn) | {i[0] for i in _dl}
    # relocation targets: dat_ ones are DATA (entry arrays...) -> their own original-bytes copies, a few levels deep;
    # the rest are functions -> stubs as before
    # alias keys never get a copy: a copy DEFINES the name and beats the alias (dat_0084ff0c=_c_dfDIMouse2 kept a stale
    # rgodf pointer -> DirectInput E_INVALIDARG -> File->New aborted setDataModel)
    _alk0 = {l_[len('"/alternatename:'):].split('=', 1)[0] for l_ in qr.read_text().splitlines() if l_.lower().startswith('"/alternatename:')} | set(_dal)
    _dl = [i for i in _dl if i[0] not in _alk0]
    for _lvl in range(4):
        _nd = sorted({t for i in _dl if len(i) > 3 for _, t in i[3] if t.startswith('dat_')} - _def - _have - _alk0)
        if not _nd:
            break
        for t in _nd:
            _dl.append(_data_item(t, int(t[4:], 16)))
        _have |= set(_nd)
    _dl += [(s_, b_, len(b_) + 3 & ~3) for s_, b_ in sorted(_ms.STRS.items()) if s_ not in _have]
    _have |= {i[0] for i in _dl}
    # alias keys resolve through /alternatename: a stub would beat the alias (func_005a5200 -> native setCamera, pointed
    # at by an original-bytes data copy, got a stub -> camera never set -> near clip 0)
    _alk3 = {l_[len('"/alternatename:'):].split('=', 1)[0] for l_ in qr.read_text().splitlines() if l_.lower().startswith('"/alternatename:')}
    fn += sorted({t for i in _dl if len(i) > 3 for _, t in i[3] if not t.startswith(('dat_', 'roc_str_'))} - _def - _have - _alk3)
    # predict pass 3: placeholder aliases (_g_X/_fn_X/@fn_X@n) whose chained target nothing defines would come back
    # undefined from this link. Stub the target (func_/dat_) or the source name now, saving a whole lld pass (~35 s).
    # ponytail: "defined" = defined.json + converted + this stub set; a lib-only target would be shadowed (pass 3 stays as fallback)
    try:
        _known = set(json.load(open(H / 'renamed/defined.json')))
    except Exception:
        _known = set()
    _known |= _def | _have | set(fn)
    # every alias SOURCE among this link's missing names, not only placeholders: the analog's invented names
    # (??1Base@@, ??0Pair@@, ?assign@S@@) get qualname aliases whose targets nothing defines -> third pass (~45 s)
    _srcs = set(und0) | set(und) | set(_qa)
    for _l in _chain(out, set(und0)):
        if _l.lower().startswith('"/alternatename:'):
            _k, _, _v = _l[16:].rstrip('"').partition('=')
            if (_k in _srcs or re.match(r'^(?:_(?:g|fn|dat|func)_[0-9a-f]{8}|@fn_[0-9a-f]{8}@\d+)$', _k)) and _v not in _known                     and not _v.startswith('_roc_') and _k not in _LINKER and _k not in _known \
                    and _v not in _alk3:   # the target is itself an alias key (func_005a5200=?setCamera): it resolves, never stub it
                _s = _v if re.match(r'^(?:func|dat)_[0-9a-f]{8}$', _v) else _k
                if _s.startswith('dat_'):
                    _va = int(_s[4:], 16)
                    _dl.append((_s, _ms.orig_bytes(_va, 0x100), 4096, _ms.data_relocs(_va, 0x100)))
                elif _s.startswith(('_dat_', '_g_')):
                    _dl.append((_s, b'', 4096))
                else:
                    fn.append(_s)
                _known.add(_v)
    # func_<addr> that is an IMPORT THUNK in the original (jmp [IAT], unnamed in the registry: 130, 110 into rgmain) ->
    # alias it to the imported function instead of a stub: ManualObject's vtable slot func_006a00f8 was a `ret` stub
    # that popped no arguments, shifting RbxSky's stack (a float read as the object pointer, crash in attachObject)
    try:
        import pefile as _pf7, struct
        _o7 = _pf7.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True)
        _o7.parse_data_directories(directories=[_pf7.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
        _oi7 = _o7.get_memory_mapped_image()
        _iat7 = {i.address: (d.dll.decode().lower(), i.name.decode()) for d in _o7.DIRECTORY_ENTRY_IMPORT for i in d.imports if i.name}
        # mfc90 imports by ORDINAL (006a10c4 = jmp [mfc90 #3819] = CHtmlView::GetThisClass): decorated name via the
        # ordinal map, so a func_<thunk> / G1 alias reaches the real export instead of nothing (jumped into zeros)
        try:
            _om7 = json.load(open(H / 'renamed/ordinals.json')).get('mfc90.dll', {})
        except (OSError, ValueError):
            _om7 = {}
        _iat7.update({i.address: ('mfc90.dll', _om7[str(i.ordinal)]) for d in _o7.DIRECTORY_ENTRY_IMPORT for i in d.imports
                      if not i.name and d.dll.decode().lower() == 'mfc90.dll' and str(i.ordinal) in _om7})
        def _thunk_of(u):
            m7 = re.match(r'^func_([0-9a-f]{8})$', u)
            if not m7:
                return None
            o7 = int(m7.group(1), 16) - 0x400000
            if _oi7[o7:o7 + 2] != b'\xff\x25':
                return None
            dll7, nm7 = _iat7.get(struct.unpack_from('<I', _oi7, o7 + 2)[0], (None, None))
            if nm7 and nm7.startswith('?'):
                return nm7   # C++ export: the import library's thunk of that name
            if nm7 and dll7 in ('msvcr90.dll', 'msvcp90.dll'):
                return _CRT_STD.get(nm7, '_' + nm7)   # cdecl CRT export (stdcall ones keep @N: _CxxThrowException -> __CxxThrowException@8, else it resolved to 0)
            return None
        _thk = {u: _thunk_of(u) for u in fn}
        _thk = {k: v for k, v in _thk.items() if v}
        if _thk:
            fn = [u for u in fn if u not in _thk]
            out = out + ['"/alternatename:%s=%s"' % (k, v) for k, v in sorted(_thk.items())]
            print('import thunks aliased to their import instead of stubbed: %d' % len(_thk))
    except Exception as _e7:
        print('thunk aliasing skipped:', _e7)
    def _fold_create(va, name, rg):   # ??$create@V<C>@...@V<C>@... with C = the class whose ctor the original calls
        m_ = re.match(r'^\?\?\$create@V(\w+)@RBX@@@', name)
        if not m_:
            return None
        import capstone as _cs9, pefile as _pf9
        global _o9img
        try:
            _o9img
        except NameError:
            _o9img = _pf9.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
        for i_ in _cs9.Cs(_cs9.CS_ARCH_X86, _cs9.CS_MODE_32).disasm(bytes(_o9img[va - 0x400000:va - 0x400000 + 0x80]), va):
            if i_.mnemonic == 'call' and i_.op_str.startswith('0x'):
                c_ = re.match(r'^\?\?0(\w+)@RBX@@QAE@XZ$', (rg.get('%08x' % int(i_.op_str, 16)) or {}).get('name') or '')
                if not c_:   # folded/inlined ctor: the primary vtable it stores names the class (Pants)
                    t_ = int(i_.op_str, 16)
                    for j_ in _cs9.Cs(_cs9.CS_ARCH_X86, _cs9.CS_MODE_32).disasm(bytes(_o9img[t_ - 0x400000:t_ - 0x400000 + 0x60]), t_):
                        if j_.mnemonic == 'mov' and j_.op_str.startswith(('dword ptr [esi], 0x', 'dword ptr [eax], 0x', 'dword ptr [ecx], 0x')):
                            c_ = re.match(r'^\?\?_7(\w+)@RBX@@6B@$', (rg.get('%08x' % int(j_.op_str.split(', ')[1], 16)) or {}).get('name') or '')
                            break
                        if j_.mnemonic == 'ret':
                            break
                if c_:
                    return name.replace('V%s@RBX@@' % m_.group(1), 'V%s@RBX@@' % c_.group(1))
        return None
    # SAME-ADDRESS aliases: a stub name that stands for exactly ONE original address (func_X, a unique registry name, or
    # every converted caller binding it there) whose converted object IS linked under another symbol (identical-code
    # folding: ??0MarshalLock@@ == ??0mutex@boost@@ at 00594c90) -> alias to that symbol. origcover.py found 89 of the 213
    # placeholders the original runs on the File->New path were exactly this.
    try:
        _rg9 = json.load(open(H.parents[1] / 'work/2008-06/identity-registry.json'))
        _bn9 = {}
        for _a9, _v9 in _rg9.items():
            _n9 = (_v9 or {}).get('name')
            if _n9:
                _bn9.setdefault(_n9, set()).add(_a9)
        _rr9 = json.load(open(H / 'renamed/rename.json'))
        _ra9 = {}
        for _x9 in _rr9.values():
            for _k9, _w9 in (_x9.get('refs') or {}).items():
                if not _k9.startswith(('collide:', 'split:', 'rebound:')):
                    _ra9.setdefault(_k9, set()).add(_w9)
        _lk9 = {re.search(r'([0-9a-f]{8})\.obj$', o).group(1) for o in conv}
        _real9 = set()   # names a non-stub object owned in the previous map
        for _l9 in QP('linkexp/qt.map').read_text(errors='replace').splitlines():
            _p9 = _l9.split()
            if len(_p9) >= 4 and ':' in _p9[0] and 'stubs' not in _p9[-1]:
                _real9.add(_p9[1])
        _sa, _xtra9 = {}, []
        for u in fn:
            m9 = re.match(r'^_?func_([0-9a-f]{8})$', u)
            c9 = {m9.group(1)} if m9 else (_bn9.get(u) if len(_bn9.get(u, ())) == 1 else _ra9.get(u, set()))
            if c9 and len(c9) == 1:
                a9 = next(iter(c9))
                s9 = (_rr9.get(a9) or {}).get('symbol')
                if a9 in _lk9 and s9 and s9 != u and (_rr9.get(a9) or {}).get('status') == 'renamed':
                    _sa[u] = s9
                elif m9:
                    # func_<addr> whose REGISTRY name has a real (native/library/template) body in the link: callers of
                    # a failed conversion (nomatch) still say func_0044bdc0 = Creatable<Instance>::create<Team>
                    _rn9 = ((_rg9.get(a9) or {}).get('name') or '')
                    if len(_bn9.get(_rn9, ())) > 1:   # FOLDED registry name: create<Team> names 4 create<X> (0x44bdc0 builds
                        # GameSettings) -> take the class from the constructor the original calls, else leave the stub
                        _rn9 = _fold_create(int(a9, 16), _rn9, _rg9) if not os.environ.get('QT_NO_FOLDCREATE') else _rn9
                    if _rn9 and _rn9.startswith('?') and _rn9 != u and _rn9 in _real9:
                        _sa[u] = _rn9
                    elif os.environ.get('QT_FOLDED_CONV') and len(_bn9.get(((_rg9.get(a9) or {}).get('name') or ''), ())) > 1 and (H / 'renamed/obj' / (a9 + '.obj')).exists()                             and (_rr9.get(a9) or {}).get('symbol') == u and (_rr9.get(a9) or {}).get('status') == 'renamed':
                        _xtra9.append('"%s"' % (H / 'renamed/obj' / (a9 + '.obj')))   # folded, no native: A's own converted body
        if _xtra9:
            _xn9 = {('func_' + re.search(r'([0-9a-f]{8})\.obj', x_).group(1)) for x_ in _xtra9}
            fn = [u for u in fn if u not in _xn9]
            out = _xtra9 + out
            qr.write_text(''.join(l_ + chr(10) for l_ in _xtra9) + qr.read_text())
        print('folded registry names: converted bodies linked instead of a stub: %d' % len(_xtra9))
        if _sa:
            fn = [u for u in fn if u not in _sa]
            out = out + ['"/alternatename:%s=%s"' % kv for kv in sorted(_sa.items())]
            qr.write_text(qr.read_text() + ''.join('"/alternatename:%s=%s"\n' % kv for kv in sorted(_sa.items())))
        print('stubs aliased to the linked converted body at their original address: %d' % len(_sa))
    except Exception as _e10:
        print('same-address aliases skipped:', _e10)
    # FINAL GUARD (one place instead of every list that adds stubs): never stub a name whose alias chain ends at REAL code
    # (owned by a non-stub object in the previous map). A stub definition beats /alternatename, so func_005a5200 ->
    # ?setCamera and 38 more ran as placeholders over real bodies. Dead aliases (target defined nowhere) keep their stub.
    try:
        _am = {}
        for l_ in qr.read_text().splitlines():
            if l_.lower().startswith('"/alternatename:'):
                k_, _, v_ = l_[len('"/alternatename:'):].rstrip('"').partition('=')
                _am.setdefault(k_, v_)
        _real = set()
        for l_ in (QP('linkexp/qt.map')).read_text(errors='replace').splitlines():
            p_ = l_.split()
            if len(p_) >= 4 and ':' in p_[0] and 'stubs' not in p_[-1]:
                _real.add(p_[1])

        def _ends_real(n_):
            for _ in range(8):
                if n_ not in _am:
                    return False
                n_ = _am[n_]
                if n_ in _real:
                    return True
            return False
        _n0 = len(fn)
        fn = [u for u in fn if not _ends_real(u)]
        _dl = [i for i in _dl if not _ends_real(i[0])]
        print('stubs dropped because their alias reaches real code: %d' % (_n0 - len(fn)))
    except Exception as _e9:
        print('alias guard skipped:', _e9)
    _tm('stub classification (qualname, ret bytes, data relocs)')
    # dat_ blocks mirror the ORIGINAL layout where placeholders are contiguous: each item was 16-aligned on its own, so
    # dat_00976b94 (= dat_00976b7c + 0x18, a member of the Descriptor the converted initializer builds) was a separate
    # zero dword -> DataModel::clearContents read null on Reset. Consecutive dat_ items whose original addresses are
    # within 12 bytes of the previous end become ONE block (original bytes + relocations over the whole range) with
    # the others as aliases at their original offsets.
    if not os.environ.get('QT_NO_DATMERGE'):
        _di = sorted((int(i[0][4:], 16), i) for i in _dl if re.fullmatch(r'dat_[0-9a-f]{8}', i[0]) and len(i) == 4 and i[2] <= 0x2000)
        _keep = [i for i in _dl if not (re.fullmatch(r'dat_[0-9a-f]{8}', i[0]) and len(i) == 4 and i[2] <= 0x2000)]
        _runs, _cur, _end = [], [], 0
        for _x, _it in _di:
            _n = _ms.data_size(_x)
            if _cur and _x <= _end + 12:   # contiguous with (or inside) the running block
                _cur.append((_x, _it, _n)); _end = max(_end, _x + _n)
            else:
                if _cur:
                    _runs.append(_cur)
                _cur, _end = [(_x, _it, _n)], _x + _n
        if _cur:
            _runs.append(_cur)
        _merged, _nm = [], 0
        for _r in _runs:
            if len(_r) == 1:
                _merged.append(_r[0][1]); continue
            _S = _r[0][0]; _E = max(x_ + n_ for x_, _, n_ in _r)
            _merged.append((_r[0][1][0], _ms.orig_bytes(_S, _E - _S), max(_E - _S, 16), _ms.data_relocs(_S, _E - _S),
                            [(it_[0], x_ - _S) for x_, it_, _ in _r[1:]]))
            _nm += len(_r) - 1
        _dl = _keep + _merged
        print('dat_ merge: %d placeholders placed inside their neighbour block at the original offset' % _nm)
    coffstub.write(str(QP('linkexp/qt_stubs.obj')), [_sitem(u) for u in fn], _dl)
    qr.write_text('\n'.join(_chain(out, set(und0)) + ['"%s"' % (QP('linkexp/qt_stubs.obj'))]) + '\n')
    r = subprocess.run([sys.executable, str(H / 'lld_link.py'), '--xtp-first'], capture_output=True, text=True,
                       env=dict(os.environ, LLD_RSP=str(qr), LLD_LOG=str(QP('linkexp/qt_lld.log'))))
    print('stubbed %d new names; %s' % (len(und), (r.stdout.strip().splitlines() or ['?'])[-1]))
    # alias chains can end at a name nothing defines (_fn_00678510 -> 0): stub what is still undefined, relink once
    _log2 = (QP('linkexp/qt_lld.log')).read_text(errors='replace') if (QP('linkexp/qt_lld.log')).exists() else ''
    _und2 = sorted(set(re.findall(r'undefined symbol: (\S+)', _log2)) - set(fn) - {i[0] for i in _dl} - _absolute)
    # what the pass-3 prediction missed, plus the names this run already stubbed up front from it (sticky: once pass 2
    # is no longer needed the list must not empty out, or the next run needs pass 2 again)
    (QP('linkexp/qt_und2.txt')).write_text(chr(10).join(sorted(set(_und2) | (_lo if '_lo' in dir() else set()))))
    try:   # same final guard for the second pass
        _und2 = [u for u in _und2 if not _ends_real(u)]
    except NameError:
        pass
    _thk2 = {}
    try:   # the second pass's leftovers too (func_005be110, a MSVCP90 stringstream thunk, still ran as a stub)
        _thk2 = {u: _thunk_of(u) for u in _und2}
        _thk2 = {k: v for k, v in _thk2.items() if v}
        if _thk2:
            _und2 = [u for u in _und2 if u not in _thk2]
            out = out + ['"/alternatename:%s=%s"' % (k, v) for k, v in sorted(_thk2.items())]
    except NameError:
        pass
    if _und2 or _thk2:   # new aliases need the relink even when no stub is left
        coffstub.write(str(QP('linkexp/qt_stubs2.obj')), [_sitem(u) for u in _und2 if not u.startswith(('dat_', '_dat_', '_g_'))],
                       [(u, b'', 4096) for u in _und2 if u.startswith(('dat_', '_dat_', '_g_'))])
        qr.write_text('\n'.join(_chain(out, set(und0)) + ['"%s"' % (QP('linkexp/qt_stubs.obj')), '"%s"' % (QP('linkexp/qt_stubs2.obj'))]) + '\n')
        r = subprocess.run([sys.executable, str(H / 'lld_link.py'), '--xtp-first'], capture_output=True, text=True,
                           env=dict(os.environ, LLD_RSP=str(qr), LLD_LOG=str(QP('linkexp/qt_lld.log'))))
        print('stubbed %d remaining; %s' % (len(_und2), (r.stdout.strip().splitlines() or ['?'])[-1]))
        (QP('linkexp/qt_und.txt')).write_text(chr(10).join(sorted(set((QP('linkexp/qt_und.txt')).read_text().split()) | set(_und2))))   # next run's first link covers these too
(QP('linkexp/qt_prev_und.txt')).write_text((QP('linkexp/qt_und.txt')).read_text() if (QP('linkexp/qt_und.txt')).exists() else '')
if not (QP('linkexp/qt.exe')).exists():
    print(log[-1500:]); sys.exit(1)
t = (QP('linkexp/qt.map')).read_text(errors='replace')
(QP('linkexp/qt.map')).write_text(re.sub(r'(?<=\s)0{8}([0-9a-f]{8})(?=\s)', r'\1', t))
try:   # draftstrip safety net (see _dskeep): stripped names the map shows only as stubs or not at all
    _own = {}
    for _l9 in QP('linkexp/qt.map').read_text(errors='replace').splitlines():
        _p9 = _l9.split()
        if len(_p9) >= 4 and ':' in _p9[0] and _p9[0] != '0000:00000000':
            _own.setdefault(_p9[1], set()).add('stubs' in _p9[-1])
    _lost = {n_ for n_ in _dstripped if not n_.startswith(('??_R', '??_7', '??_C')) and _own.get(n_) == {True}}   # bound to a stub only (absent = unreferenced or DLL-exported: draftstrip was right)
    if _lost:
        _dskf.write_text(json.dumps(sorted(_dskeep | _lost)))
    print('draftstrip safety net: %d stripped names had no other definition (kept next link)' % len(_lost))
except Exception as _eds:
    print('draftstrip safety net skipped:', _eds)
import xcudedup   # repeated .CRT$XCU initializers (duplicate objects) ran twice: MFC class-list cycle -> badClass
_xz = xcudedup.dedup(str(QP('linkexp/qt.exe')), str(QP('linkexp/qt.map')))
print('xcudedup: %d repeated initializer(s) zeroed' % len(_xz))
_z0 = [l_.split()[1] for l_ in QP('linkexp/qt.map').read_text(errors='replace').splitlines()
       if len(l_.split()) >= 4 and l_.split()[0] == '0000:00000000' and l_.split()[-1] == '<absolute>' and re.match(r'^(?:func_|dat_|\?|_)', l_.split()[1]) and not l_.split()[1].startswith(('__', '_tls', '___'))]
print('ZERO-ADDRESS names (an alias to a missing symbol resolves to 0): %d %s' % (len(_z0), _z0[:6]))
_zf = H / 'auto/alias_zero.json'   # grow-only: their aliases are skipped next link (stub instead of address 0)
_zf.write_text(json.dumps(sorted(set(json.loads(_zf.read_text()) if _zf.exists() else []) | set(_z0))))
if QP('linkexp/qt.exe').stat().st_mtime < _QT_START:   # lld errored and wrote nothing: never ship last run's exe
    _el = [l_ for l_ in (QP('linkexp/qt_lld.log').read_text(errors='replace').splitlines() if QP('linkexp/qt_lld.log').exists() else []) if 'error:' in l_]
    print('LINK FAILED: linkexp/qt.exe not rewritten (stale exe NOT copied). lld errors: %s' % _el[:5]); sys.exit(3)
# Do not terminate other client processes.   # a leftover test instance locked the copy
shutil.copy(QP('linkexp/qt.exe'), QP('run/RobloxQT.exe'))
_tm('second/third link + copy')
if secs == '0':
    # acceptance gate + audits for the NEXT link, both in the background (29 s + audits off the critical path):
    # linkgate's report lands in auto/linkgate.log
    subprocess.Popen('"%s" "%s" > "%s" 2>&1' % (sys.executable, H / 'linkgate.py', H / 'auto/linkgate.log'), shell=True, creationflags=0x08000000)
    subprocess.Popen([sys.executable, str(H / 'audits_all.py')], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, creationflags=0x08000000)   # audits for the NEXT link, hidden (CREATE_NO_WINDOW)
    print('linked (no probe)'); sys.exit(0)   # fixloop.py: link-only rounds while stub_exact closes func_ callees
subprocess.run([sys.executable, str(H / 'probe.py'), secs])   # probe.py: debugger probe + crash-reporter break
