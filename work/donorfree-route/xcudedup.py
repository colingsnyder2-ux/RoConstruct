"""python xcudedup.py EXE MAP: zero repeated pointers in the CRT initializer table (__xc_a..__xc_z) of a linked exe.
The same object linked twice (unit_2127/unit_2596 were one candidate obj), or two objects defining one global, put the
same ??__E initializer into .CRT$XCU twice. lld resolves both to one function, so it RAN TWICE: a second AfxClassInit
re-added CXTPReportRecordItem to the MFC class list -> cycle, every class registered before it unreachable ->
CXTPControls::DoPropExchange threw CArchiveException(badClass) loading IDESettings.xml. _initterm skips null entries,
so the first occurrence (original order) runs once and later copies become no-ops.
Also by NAME: ~10 drafts each carried their own ??__E?prop_SkyRt@Sky@RBX@@... (file-local copies at different
addresses), so the one external global was constructed ~10 times and its property registered again each time ->
CPropGrid walked half-overwritten descriptors (intermittent File->New crash). Per initializer name only one runs: the
copy in the object whose definition of the global won the link (else the first in table order)."""
import collections, re, struct, sys


def dedup(exe, mp):
    xa = xz = None
    at = collections.defaultdict(list)   # address -> [(name, object)]
    owner = {}                           # symbol -> object of its first (winning) definition
    for l in open(mp, errors='replace'):
        p = l.split()
        if len(p) >= 4 and p[1] in ('___xc_a', '___xc_z'):
            if p[1] == '___xc_a':
                xa = int(p[2], 16)
            else:
                xz = int(p[2], 16)
        if len(p) >= 4 and ':' in p[0] and p[0] != '0000:00000000':
            try:
                v = int(p[2], 16)
            except ValueError:
                continue
            at[v].append((p[1], p[-1]))
            owner.setdefault(p[1], p[-1])
    import pefile
    pe = pefile.PE(exe, fast_load=True)
    base = pe.OPTIONAL_HEADER.ImageBase
    off = pe.get_offset_from_rva(xa - base)
    data = bytearray(open(exe, 'rb').read())
    n = (xz - xa) // 4
    ents = [(i, struct.unpack_from('<I', data, off + 4 * i)[0]) for i in range(n)]
    seen, zeroed = set(), []
    byname = collections.defaultdict(list)
    for i, v in ents:
        if not v:
            continue
        if v in seen:
            struct.pack_into('<I', data, off + 4 * i, 0); zeroed.append(v)
            continue
        seen.add(v)
        for nm, ob in at.get(v, ()):
            m = re.fullmatch(r'\?\?__E(.+)@@YAXXZ', nm)
            if m:
                g = m.group(1)
                byname[nm].append((i, v, ob, g if g.startswith('?') else '_' + g))
                break
    for nm, lst in byname.items():
        if len(lst) < 2:
            continue
        g = lst[0][3]
        keep = next((e for e in lst if e[2] == owner.get(g)), lst[0])
        for i, v, ob, _ in lst:
            if (i, v) != keep[:2]:
                struct.pack_into('<I', data, off + 4 * i, 0); zeroed.append(v)
    if zeroed:
        pe.close()
        open(exe, 'wb').write(data)
    return zeroed


if __name__ == '__main__':
    z = dedup(sys.argv[1], sys.argv[2])
    print('xcudedup: %d repeated initializer(s) zeroed %s' % (len(z), ' '.join('%08x' % v for v in z[:12])))
