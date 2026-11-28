# exec'd by libalias.py (shares its globals: o, stubs, al, keep, dirs, obj_funcs, ROOT, H).
# Scalar deleting destructors: one masked body for every class, so the signature is ambiguous; the class comes from
# the destructor it calls (registry name ??1Cls@@..) -> ??_GCls@@UAEPAXI@Z, from our link or a library object.
reg = json.load(open(ROOT / 'work/2008-06/identity-registry.json'))
defs_in, sig_of = {}, {}
for dd in dirs:
    for f in sorted(dd.glob('*.obj')):
        for n, sg_ in obj_funcs(f):
            defs_in.setdefault(n, str(f)); sig_of.setdefault(n, set()).add(sg_)
import bisect as _bs
_ff = sorted(int(a, 16) for a in json.load(open(ROOT / 'work/native-client/layout/function-files.json')))
linked = set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0] and 'stubs' not in p[-1]:
        linked.add(p[1])
gpat = re.compile(rb'^\x56\x8b\xf1\xe8(....)\xf6\x44\x24\x08\x01\x74.\x56\xe8(....)\x83\xc4\x04\x8b\xc6\x5e\xc2\x04\x00', re.S)
ng = 0
for s_ in stubs:
    if s_ in al:
        continue
    x = int(s_[5:], 16)
    m = gpat.match(bytes(o[x - 0x400000:x - 0x400000 + 40]))
    if not m:
        continue
    dn = (reg.get('%08x' % (x + 8 + struct.unpack('<i', m.group(1))[0])) or {}).get('name', '')
    mm = re.match(r'^\?\?1(.+?)@@(?:U|Q|M)AE@XZ$', dn)
    if not mm:
        continue
    g = '??_G%s@@UAEPAXI@Z' % mm.group(1)
    # the registry's destructor name can be a FOLDED label (CXTPNotifySinkImpl for an image-manager class): accept
    # only when the library's ??1Cls has the original destructor's body
    d_ = x + 8 + struct.unpack('<i', m.group(1))[0]
    _i = _bs.bisect_right(_ff, d_)
    dsig = orig_sig(o, d_, _ff[_i] if _i < len(_ff) else d_ + 0x200)
    if dsig is None or dsig not in sig_of.get('??1%s@@UAE@XZ' % mm.group(1), set()) | sig_of.get(dn, set()):
        continue
    if g in linked:
        al[s_] = g; ng += 1
    elif g in defs_in:
        al[s_] = g; keep[defs_in[g]].add(g); ng += 1
print('libalias: scalar deleting destructors named from their destructor: %d' % ng)
