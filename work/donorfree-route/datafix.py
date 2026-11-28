"""Data-identity repair for FOREIGN analogs: a converted func_<X> compiled from another function's source (rename.json:
renamed analog name != the target's name) keeps that source's data names. When those names are real globals of the
other context, they alias other state: SafeChat::singleton (analog of Guid::getLocalScope) used Guid's call_once flag
and _localScope -> init skipped, returned Guid's pointer as SafeChat -> buildChatMenu(ChatOption* -1) crash.
For every DIR32 relocation in the function whose symbol is a data name defined by ANOTHER object (not a string, vtable,
RTTI, import or function) and whose original word lies in the original's data, rename that symbol in a patched copy to
dat_<original address - addend> (the original bytes at that address; quicktest stubs them with relocations).
plan() -> {obj_basename: {old: new}}; reuses callfix.patch for the rewrite."""
import json, re, struct, sys
from pathlib import Path
H = Path(__file__).parent
sys.path.insert(0, str(H.parents[0] / 'native-client'))


def _symtab(data):
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    out, i = {}, 0
    while i < nsym:
        raw, value, secnum, typ, cls, naux = struct.unpack_from('<8sIHHBB', data, symptr + 18 * i)
        if raw[:4] == b'\0\0\0\0':
            o = strtab + struct.unpack_from('<I', raw, 4)[0]
            name = data[o:data.index(b'\0', o)].decode('latin-1')
        else:
            name = raw.rstrip(b'\0').decode('latin-1')
        out[i] = (name, secnum, value, typ, cls)
        i += 1 + naux
    return out, optsz


FUNC = re.compile(r'@@[A-Z]{2}[A-Z]|@@Y[A-Z]|@@S[A-Z]|@@[IQUAEM][AB][EGI]')


def plan(mp=None):
    mp = mp or H / 'linkexp/qt.map'
    rr = json.loads((H / 'renamed/rename.json').read_text())
    import pefile
    img = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
    owner = {}
    for l in open(mp, errors='replace'):
        p = l.split()
        if len(p) >= 4 and ':' in p[0]:
            owner.setdefault(p[1], p[-1])
    out = {}
    for a, x in rr.items():
        sym = x.get('symbol')
        if x.get('status') != 'renamed' or not sym:
            continue
        f = H / 'renamed/obj' / (a + '.obj')
        if not f.exists():
            continue
        d = f.read_bytes()
        st, optsz = _symtab(d)
        fs = next(((i, v) for i, v in st.items() if v[0] == sym and 0 < v[1] < 0xfffe), None)
        if not fs:
            continue
        sec, val = fs[1][1] - 1, fs[1][2]
        _, _, _, rawsize, rawptr, relptr, _, nrel, _, _ = struct.unpack_from('<8sIIIIIIHHI', d, 20 + optsz + 40 * sec)
        r, bad = {}, set()
        for k in range(nrel):
            off, idx, typ = struct.unpack_from('<IIH', d, relptr + 10 * k)
            if typ != 6 or idx not in st:
                continue
            nm, sn, _, _, cls = st[idx]
            # a static DEFINED in this object, in a WRITABLE section: the analog's private copy of original state
            # or an UNDEFINED C-spelled global the link only has as a stub (_flagInitScriptCpp: a call_once flag the
            # analog declared extern; stubbed as code -> InterlockedIncrement on a code page in Insert Object)
            if sn == 0 and cls == 2 and re.fullmatch(r'_[A-Za-z]\w*', nm) and 'stubs' in owner.get(nm, 'stubs'):
                pass
            elif not (0 < sn < 0xfffe) or cls not in (2, 3) or nm.startswith(('dat_', '$', '.', '??_')):
                continue
            elif not struct.unpack_from('<I', d, 20 + optsz + 40 * (sn - 1) + 36)[0] & 0x80000000:
                continue
            o = int(a, 16) + off - val
            if not 0x401000 <= o < 0x7c0000:
                continue
            word = struct.unpack_from('<I', img, o - 0x400000)[0]
            add = struct.unpack_from('<i', d, rawptr + off)[0]
            if not 0x800000 <= word < 0x9a0000:
                continue
            new = 'dat_%08x' % (word - add)
            if r.get(nm, new) != new:
                bad.add(nm)
            r[nm] = new
        r = {k: v for k, v in r.items() if k not in bad}
        if r:
            out[a + '.obj'] = r
    return out


if __name__ == '__main__':
    p = plan()
    print('datafix plan: %d foreign-analog objects, %d data renames' % (len(p), sum(len(v) for v in p.values())))
    print(' 00658880.obj:', p.get('00658880.obj'))
    for k, v in list(p.items())[:6]:
        print(' ', k, list(v.items())[:2])
