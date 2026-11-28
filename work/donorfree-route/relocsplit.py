"""python relocsplit.py: converted objects that address an original global as NEAREST NAMED SYMBOL + addend. The
converter named 0x973f48 (Instance::event_propertyChanged, unnamed in the registry then) `propArchivable + 0xd4`
(propArchivable = 0x973e74); natively the two are not adjacent, so ViewNew's propertyChanged connect read a garbage
"descriptor" (null vtable) and every script-parented Part crashed. For each DIR32 relocation S+d in renamed/obj with
S a data item at original address A_S (>= 0x800000) and a different named item N starting in (A_S, A_S+d] (or the
nearest one below A_S+d when d < 0), plan: retarget that relocation to N with addend A_S+d-A_N. N = registry name,
else dat_<A_N> (a placeholder quicktest aliases or stubs with original bytes). Writes auto/relocsplit_plan.json
{object basename: [[section index, relocation index, old symbol, new symbol, new addend]]}; quicktest applies it."""
import bisect, collections, json, os, pickle, re, struct
from pathlib import Path
H = Path(__file__).parent
reg = json.load(open(H.parents[0] / '2008-06/identity-registry.json'))
nc = collections.Counter((v or {}).get('name') for v in reg.values())
addr = {}   # name -> original address
named = {}   # original data address -> name to use
for a, v in reg.items():
    n = (v or {}).get('name')
    if n and re.fullmatch(r'[0-9a-f]{8}', a) and int(a, 16) >= 0x800000:
        if nc[n] == 1:
            addr[n] = int(a, 16)
        named.setdefault(int(a, 16), n)
for l in open(H / 'aliases_renamed.txt', errors='replace'):
    m = re.match(r'dat_([0-9a-f]{8})=(.+)$', l.strip())
    if m:
        a = int(m.group(1), 16); named.setdefault(a, 'dat_%08x' % a); addr.setdefault(m.group(2), a)
keys = sorted(named)
CF = H / 'auto/relocsplit_cache.pkl'


def dir32(p):
    """[(section index, reloc index, symbol name, stored addend)] for DIR32 relocations with a nonzero addend."""
    d = Path(p).read_bytes()
    _, nsec, _, sp, ns, opt, _ = struct.unpack_from('<HHIIIHH', d, 0)
    st = sp + ns * 18
    def name(k):
        raw = d[sp + 18 * k: sp + 18 * k + 8]
        if raw[:4] == bytes(4):
            o = st + struct.unpack_from('<I', raw, 4)[0]; return d[o:d.index(0, o)].decode('latin-1')
        return raw.rstrip(bytes(1)).decode('latin-1')
    out = []
    for sx in range(nsec):
        sh = 20 + opt + 40 * sx
        raw_ptr, rel_ptr = struct.unpack_from('<II', d, sh + 20)
        for r in range(struct.unpack_from('<H', d, sh + 32)[0]):
            ro, ri, rt = struct.unpack_from('<IIH', d, rel_ptr + 10 * r)
            if rt == 6:
                v = struct.unpack_from('<i', d, raw_ptr + ro)[0]
                if v:
                    out.append((sx, r, name(ri), v))
    return out


def apply(out, plan=None):
    """quicktest: patch copies (linkexp/relocsplit) of the planned objects in the link list `out` (in place)."""
    plan = plan if plan is not None else (json.load(open(H / 'auto/relocsplit_plan.json')) if (H / 'auto/relocsplit_plan.json').exists() else {})
    dd = H / 'linkexp/relocsplit'; dd.mkdir(exist_ok=True); nobj = nrel = 0
    for i, l in enumerate(out):
        p = l.strip().strip('"')
        m = re.search(r'([0-9a-f]{8}\.obj)$', p)
        rows = plan.get(m.group(1)) if m and p.lower().endswith('.obj') else None
        if not rows or not os.path.exists(p):
            continue
        d = bytearray(Path(p).read_bytes())
        _, nsec, _, sp, ns, opt, _ = struct.unpack_from('<HHIIIHH', d, 0)
        st = sp + ns * 18; tail = bytearray(d[st + 4:]); syms = bytearray(); new = {}; hit = 0
        def name(k):
            raw = d[sp + 18 * k: sp + 18 * k + 8]
            if raw[:4] == bytes(4):
                o = st + struct.unpack_from('<I', raw, 4)[0]; return d[o:d.index(0, o)].decode('latin-1')
            return bytes(raw).rstrip(bytes(1)).decode('latin-1')
        for sx, r, old, nn, add in rows:
            if sx >= nsec:
                continue
            sh = 20 + opt + 40 * sx
            raw_ptr, rel_ptr = struct.unpack_from('<II', d, sh + 20)
            if r >= struct.unpack_from('<H', d, sh + 32)[0]:
                continue
            ra = rel_ptr + 10 * r
            ro, ri, rt = struct.unpack_from('<IIH', d, ra)
            if rt not in (6, 20) or ri >= ns or name(ri) != old:
                continue   # an earlier quicktest pass changed this object: leave it
            if nn not in new:   # append an external symbol (indices of existing symbols stay valid)
                new[nn] = ns + len(new)
                syms += struct.pack('<II', 0, 4 + len(tail)) + struct.pack('<IhHBB', 0, 0, 0, 2, 0); tail += nn.encode('latin-1') + bytes(1)
            struct.pack_into('<I', d, ra + 4, new[nn]); struct.pack_into('<i', d, raw_ptr + ro, add); hit += 1
        if not hit:
            continue
        struct.pack_into('<I', d, 12, ns + len(new))
        d = d[:st] + syms + struct.pack('<I', 4 + len(tail)) + tail
        q = dd / ('rs_' + Path(p).name); q.write_bytes(bytes(d)); out[i] = '"%s"' % q; nobj += 1; nrel += hit
    return nobj, nrel


def main():
    # native extent of each defined data symbol: distance to the next symbol in the last link map
    va = sorted((int(p[2], 16), p[1]) for p in (l.split() for l in open(H / 'linkexp/qt.map', errors='replace'))
                if len(p) >= 4 and p[0][:5] in ('0002:', '0003:') and re.fullmatch(r'[0-9a-f]{8}', p[2]))
    natsize = {n: va[i + 1][0] - v for i, (v, n) in enumerate(va[:-1]) if va[i + 1][0] > v}
    cache = pickle.load(open(CF, 'rb')) if CF.exists() else {}
    plan, n_obj = {}, 0
    for o in (H / 'renamed/obj').glob('*.obj'):
        st_ = o.stat(); key = (st_.st_mtime_ns, st_.st_size)
        c = cache.get(o.name)
        if not c or c[0] != key:
            c = cache[o.name] = (key, dir32(o))
        for sx, r, s, v in c[1]:
            a_s = addr.get(s) if not s.startswith('dat_') else int(s[4:], 16)
            if a_s is None or a_s < 0x800000:
                continue
            t = a_s + v
            j = bisect.bisect_right(keys, t) - 1
            if j < 0:
                continue
            a_n = keys[j]
            if a_n == a_s or (v > 0 and a_n < a_s) or (v < 0 and a_n > a_s):
                continue   # still inside S (or no other named item between S and the target)
            if v < 0 and a_n == a_s:
                continue
            nn, rr = named[a_n], t - a_n
            if rr and not (0 < rr < natsize.get(nn, 0)):
                nn, rr = 'dat_%08x' % t, 0   # past N's native extent: a separate unnamed original object (SignalDesc+52)
            plan.setdefault(o.name, []).append([sx, r, s, nn, rr])
    pickle.dump(cache, open(CF, 'wb'))
    try:   # zeroreloc.py: relocations on immediates that are 0 in the original
        for k, v in json.load(open(H / 'auto/relocsplit_extra.json')).items():
            plan.setdefault(k, []).extend(r_ for r_ in v if not (os.environ.get('QT_NO_TIFIX') and r_[3].startswith('__TI')))
    except (OSError, ValueError):
        pass
    json.dump(plan, open(H / 'auto/relocsplit_plan.json', 'w'), indent=0)
    tot = sum(len(v) for v in plan.values())
    ex = next((v for k, v in plan.items() if k.startswith('004eae10')), None)
    print('relocsplit: S+addend relocations crossing into another original item: %d in %d objects (004eae10: %s)' % (tot, len(plan), ex))


if __name__ == '__main__':
    main()
