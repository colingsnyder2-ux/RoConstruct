"""dllexstrip.py (quicktest pass): rgmain.dll exports Ogre's inline/template code itself (Singleton<T>::getSingletonPtr,
StringInterface::getParamDictionary ...), but the converted analog TUs and native Ogre drafts carry their own copies
(often LOCAL statics) compiled without dllimport, so each copy reads the DLL's data through lld's jmp thunk:
Singleton<Root>::ms_Singleton read as thunk bytes (gemini dll_data_audit: 18 singletons, ~1000 references).
For every linked object: code definitions (external or static) of names rgmain exports and the original exe did NOT have
its own copy of (no identity-registry address) become undefined externals -> the DLL's export.
Data (vtables, statics, RTTI) is never touched (dllvt.py / OgreConstImports.cpp own those)."""
import json, os, pickle, re, struct, sys
from pathlib import Path
H = Path(__file__).parent
sys.path.insert(0, str(H.parents[1])); sys.path.insert(0, str(H))
from roc import rebuild as rb
DATA = re.compile(r'^\?[A-Za-z_]\w*(@\w+)*@@[0-3]|^\?\?_[78RC]')


def all_defs(d):
    """every defined (external or static, non-section) symbol name"""
    _, nsec, _, sp, ns, opt, _ = struct.unpack_from('<HHIIIHH', d, 0); st = sp + 18 * ns; out = set(); k = 0
    while k < ns:
        at = sp + 18 * k; raw = d[at:at + 8]; sec, typ, cls, na = struct.unpack_from('<hHBB', d, at + 12)
        if sec > 0 and (cls == 2 or (cls == 3 and not na)):
            if raw[:4] == bytes(4):
                o = st + struct.unpack_from('<I', raw, 4)[0]; out.add(d[o:d.index(0, o)].decode('latin-1'))
            else:
                out.add(raw.rstrip(b'\0').decode('latin-1'))
        k += 1 + na
    return out


def apply(out):
    lib = next((l.strip().strip('"') for l in out if 'rgmain' in l.lower() and l.strip().strip('"').lower().endswith('.lib')), None)
    if not lib:
        return 0, 0
    import defined_now as dn
    exp = {x[6:] for x in dn.lib_symbols(lib) if x.startswith('__imp_')}
    exp = {n for n in exp if n.startswith('?') and not DATA.match(n) and re.search(r'\?\$Singleton@V\w+@Ogre@@@Ogre@@', n)}
    # only Ogre::Singleton<T> members: stripping every rgmain-exported copy (333k in 279 objects) broke File->New
    reg = json.load(open(H.parents[0] / '2008-06/identity-registry.json'))
    exp -= {(v or {}).get('name') for v in reg.values()}
    skip = set((H / 'auto/dllshadow_ok.txt').read_text().split()) if (H / 'auto/dllshadow_ok.txt').exists() else set()
    cf = H / 'auto/dllexstrip_cache.pkl'
    try:
        cache = pickle.load(open(cf, 'rb'))
    except Exception:
        cache = {}
    dd = H / 'linkexp/dllexstrip'; dd.mkdir(exist_ok=True); nobj = nsym = 0
    for i, l in enumerate(out):
        p = l.strip().strip('"')
        if not p.lower().endswith('.obj') or not os.path.exists(p) or 'stubs' in p or p.endswith(('dllvt.obj', 'abszero.obj')):
            continue
        st_ = os.stat(p); key = (st_.st_mtime_ns, st_.st_size)
        c = cache.get(p)
        if not c or c[0] != key:
            b = Path(p).read_bytes()
            c = cache[p] = (key, frozenset(all_defs(b)) if b'Ogre@@' in b else frozenset())
        hit = c[1] & exp
        if not hit:
            continue
        q = dd / ('dx_' + Path(p).name)
        if not q.exists() or q.stat().st_mtime < os.path.getmtime(p):
            q.write_bytes(rb.strip_symbols(Path(p).read_bytes(), drop=hit, statics=True))
        out[i] = '"%s"' % q; nobj += 1; nsym += len(hit)
    pickle.dump(cache, open(cf, 'wb'))
    return nobj, nsym
