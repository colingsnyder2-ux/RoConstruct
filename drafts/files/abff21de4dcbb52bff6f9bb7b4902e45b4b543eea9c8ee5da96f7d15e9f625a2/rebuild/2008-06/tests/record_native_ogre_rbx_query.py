"""Verify the exe-local parts of Ogre 1.4.5's default scene queries in the June 2008 client (inactive; 2008-06).

DefaultAxisAlignedBoxSceneQuery, DefaultSphereSceneQuery, DefaultPlaneBoundedVolumeListSceneQuery, DefaultRaySceneQuery
and DefaultIntersectionSceneQuery are _OgreExport classes of rgmain.dll: their constructors, destructors and members are
imports. Roblox's RbxSceneManager fork constructs them (create*Query 0068cad0..0068cd90, `new Default...(this)`, counted
by record_native_ogre_scene_manager.py), so MSVC emitted local copies of their vtables, scalar deleting destructors and
the this-adjusting ??_E thunks of the +0x34 listener vtables into the exe. Those are the rows here.

Builds (document-swap flags plus the Ogre 1.4.5 client headers, VS2008 RTM 21022, /fp:fast) from the current header
native-headers/OgreRbxQuery/DefaultSceneQueries2008.h (new, non-colliding path: no donor or native header of that path
exists, so nothing is shadowed):
  * tests/NativeOgreRbxQueryLayout.cpp   sizeof / listener-offset probes (mov eax, imm32; ret) and nativeNew* scaffolding
                                         that constructs each class, which emits the vtables, ??_G and ??_E thunks.
No native-classes unit: no exe body of these classes is source code (the compiler-generated rows are emitted by the
RbxSceneManager unit's create*Query bodies in a client build).

Rows: the five ??_G and the five +0x34 ??_E adjustor thunks. Every row is relocation-masked exact against the original
and every REL32/DIR32 target is verified: imports by DLL export name, own rows by address (one address per symbol; the
??_E vector deleting destructor that a thunk jumps to is the linker alias of the class's ??_G, which is checked against
the vtable slot 0 of the primary vtable). All ten vtables are compared slot by slot with the compiled ones (the original
RTTI complete-object locators name the class at the expected offset; every slot but slot 0 is an rgmain import thunk),
and the RTTI hierarchies are checked. The create*Query call sites prove the allocation sizes and the vptr stores.
Writes work/2008-06/shared-layouts/ogre-rbx-query-working.json. NATIVE_OGRE_RBX_QUERY_DISCOVER=1 lists unbound targets
and non-exact rows instead of asserting.
"""
import json
import os
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
OGRE = '/I' + str(ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include')
LAYOUT = R / 'tests/NativeOgreRbxQueryLayout.cpp'
HEADER = R / 'native-headers/OgreRbxQuery/DefaultSceneQueries2008.h'
DISCOVER = bool(os.environ.get('NATIVE_OGRE_RBX_QUERY_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i + 1] + [OGRE] + flags[i + 1:] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeOgreRbxQueryLayout', LAYOUT, ['/fp:fast'])
raw = layout_obj.read_bytes()
FUNCS = {n: (b, r) for n, b, r in match.coff_functions(raw)}

# class key -> (class, listener base, new size, create*Query, ctor import call site, IAT slot of the ctor import,
#               primary vtable, +0x34 vtable, ??_G, ??_E +0x34 thunk, primary slot count)
CLASSES = {
    'aabb': ('DefaultAxisAlignedBoxSceneQuery', 'SceneQueryListener', 0x5c, 0x68cad0, 0x68cb09, 0x804810,
             0x84eab8, 0x84eaa8, 0x68cb60, 0x68d630, 12),
    'sphere': ('DefaultSphereSceneQuery', 'SceneQueryListener', 0x4c, 0x68cb80, 0x68cbb9, 0x804850,
               0x84eafc, 0x84eaec, 0x68cc10, 0x68d640, 12),
    'volume': ('DefaultPlaneBoundedVolumeListSceneQuery', 'SceneQueryListener', 0x54, 0x68cc30, 0x68cc69, 0x804860,
               0x84eb40, 0x84eb30, 0x68ccc0, 0x68d620, 12),
    'ray': ('DefaultRaySceneQuery', 'RaySceneQueryListener', 0x6c, 0x68cce0, 0x68cd19, 0x80486c,
            0x84eb84, 0x84eb74, 0x68cd70, 0x68d660, 17),
    'intersection': ('DefaultIntersectionSceneQuery', 'IntersectionSceneQueryListener', 0x3c, 0x68cd90, 0x68cdc9,
                     0x8048a0, 0x84ebdc, 0x84ebcc, 0x68ce10, 0x68d650, 12),
}
LISTENER = 0x34

# ---- layout -------------------------------------------------------------------------------------------------------
for key, c in CLASSES.items():
    for probe, value in (('Size', c[2]), ('Listener', LISTENER)):
        body_, _ = FUNCS['?nativeOgreRbxQuery_%s%s@@YAHXZ' % (key, probe)]
        assert body_ == b'\xb8' + struct.pack('<I', value) + b'\xc3', (key, probe, body_.hex())

original = nb.Original()
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


ROWS = []
for key, c in CLASSES.items():
    ROWS.append((c[8], '??_G%s@Ogre@@UAEPAXI@Z' % c[0]))
    ROWS.append((c[9], '??_E%s@Ogre@@WDE@AEPAXI@Z' % c[0]))
own = {name: address for address, name in ROWS}
# The vector deleting destructor ??_E<cls>@@UAEPAXI@Z (slot 0 of both vtables, target of the adjustor thunk) is not
# emitted: the class is never allocated with new[], so the linker resolves it to the scalar ??_G (weak alias). It is
# bound to the ??_G row here; the primary vtable slot-0 check below confirms the same address.
ALIAS = {'??_E%s@Ogre@@UAEPAXI@Z' % c[0]: c[8] for c in CLASSES.values()}


def weak_default(symbol):
    """The default symbol of an IMAGE_SYM_CLASS_WEAK_EXTERNAL (105) symbol of the compiled object."""
    pointer, count = struct.unpack_from('<II', raw, 8)
    strings = pointer + 18 * count
    i = 0
    names = []
    while i < count:
        entry = raw[pointer + 18 * i:pointer + 18 * i + 18]
        if entry[:4] == b'\0\0\0\0':
            offset = struct.unpack_from('<I', entry, 4)[0]
            name = raw[strings + offset:raw.index(b'\0', strings + offset)].decode('latin-1')
        else:
            name = entry[:8].rstrip(b'\0').decode('latin-1')
        names.append((i, name, entry[16], entry[17]))
        i += 1 + entry[17]
    index = {i: n for i, n, _, _ in names}
    for i, name, klass, aux in names:
        if name == symbol:
            assert klass == 105 and aux == 1, (symbol, klass, aux)
            return index[struct.unpack_from('<I', raw, pointer + 18 * (i + 1))[0]]
    raise AssertionError(symbol)


for symbol, address in ALIAS.items():
    assert weak_default(symbol) == '??_G' + symbol[4:], symbol
UNBOUND = []
binding = {}


def verify(rows, strict=True):
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    result = []
    for address, name in rows:
        body, refs = FUNCS[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
        verified, local = {}, set()
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = symbols[index][0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            if nb.LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in ALIAS:
                assert ALIAS[symbol] == value, (name, symbol, hex(value), hex(ALIAS[symbol]))
                how = 'own row (??_E resolved to ??_G)'
            else:
                UNBOUND.append('    %r: %#x,   # in %s' % (symbol, value, name[:60]))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local': sorted(local)})
        result.append(entry)
    return result


rows = verify(ROWS, not DISCOVER)
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for r in rows:
        if not r['exact']:
            print('NOT EXACT', r['address'], r['symbol'], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
assert all(r['exact'] for r in rows)

# ---- vtables from the object built with the current header, slot by slot ---------------------------------------------
# A __declspec(dllimport) class's exe-local vtables are the ??_S local vftables (with their own ??_R4 locators).


def compiled_vtable(symbol):
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[index][0]
    return [slots[i] for i in range(len(slots))]


VTABLE_SYMBOLS = sorted(s for s in match._coff_data_index(raw)[2] if s.startswith('??_S'))


def check_vtable(symbol, address, count, ddel):
    out, bad = [], []
    slots = compiled_vtable(symbol)
    assert len(slots) == count, (symbol, len(slots), count)
    for i, slot in enumerate(slots):
        value = d(address + 4 * i)
        hit = original.imported(value)
        if slot in own:
            ok, how = own[slot] == value, 'own row'
        elif slot in ALIAS:
            ok, how = ALIAS[slot] == value and i == 0, 'own row (??_E resolved to ??_G)'
        elif hit is not None:
            ok, how = i > 0 and hit[1] == nb.plain(slot), 'import thunk %s!%s' % hit
        else:
            ok, how = False, 'unbound'
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value), how))
    assert not bad, (symbol, bad)
    assert out[0]['original'] == '%08x' % ddel, (symbol, out[0])
    return out


def col(vtable):
    locator = d(vtable - 4)
    return original.string(d(locator + 12) + 8), d(locator + 4)


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


def mov_vptr(site, reg_offset, vtable):
    """mov dword ptr [esi(+disp8)], imm32 right after the imported constructor call."""
    code = original.data(site, 0x20)
    pattern = (b'\xc7\x06' if reg_offset == 0 else b'\xc7\x46' + bytes([reg_offset])) + struct.pack('<I', vtable)
    return pattern in code


EXPECTED_BASES = {
    'SceneQueryListener': lambda cls, mid: {'.?AV%s@Ogre@@' % cls: 0, '.?AV%s@Ogre@@' % mid: 0,
                                             '.?AVRegionSceneQuery@Ogre@@': 0, '.?AVSceneQuery@Ogre@@': 0,
                                             '.?AVSceneQueryListener@Ogre@@': LISTENER},
}
MIDDLE = {'aabb': 'AxisAlignedBoxSceneQuery', 'sphere': 'SphereSceneQuery',
          'volume': 'PlaneBoundedVolumeListSceneQuery', 'ray': 'RaySceneQuery',
          'intersection': 'IntersectionSceneQuery'}
vt, layout = {}, {}
for key, c in CLASSES.items():
    cls, listener, size, create, ctor_site, iat, primary, secondary, ddel, thunk, count = c
    psym = '??_S%s@Ogre@@6BSceneQuery@1@@' % cls
    ssym = '??_S%s@Ogre@@6B%s@1@@' % (cls, listener)
    assert psym in VTABLE_SYMBOLS and ssym in VTABLE_SYMBOLS, (key, VTABLE_SYMBOLS)
    vt[cls] = {'%08x' % primary: check_vtable(psym, primary, count, ddel),
               '%08x' % secondary: check_vtable(ssym, secondary, 3, thunk)}
    assert col(primary) == ('.?AV%s@Ogre@@' % cls, 0) and col(secondary) == ('.?AV%s@Ogre@@' % cls, LISTENER)
    if listener == 'SceneQueryListener':
        expect = EXPECTED_BASES[listener](cls, MIDDLE[key])
    else:
        expect = {'.?AV%s@Ogre@@' % cls: 0, '.?AV%s@Ogre@@' % MIDDLE[key]: 0, '.?AVSceneQuery@Ogre@@': 0,
                  '.?AV%s@Ogre@@' % listener: LISTENER}
    assert bases(primary) == expect, (key, bases(primary))
    # create*Query: operator new(size), then the imported constructor, then the two vptr stores.
    window = original.data(create, ctor_site - create)
    push = (b'\x6a' + bytes([size])) if size < 0x80 else (b'\x68' + struct.pack('<I', size))
    at = window.index(push + b'\x8b\xf9\xe8') + len(push) + 2            # push size; mov edi, ecx; call new
    assert create + at + 5 + struct.unpack_from('<i', window, at + 1)[0] == 0x6a0920, key
    assert original.data(ctor_site, 2) == b'\xff\x15' and d(ctor_site + 2) == iat
    assert original.imported(iat)[1] == '??0%s@Ogre@@QAE@PAVSceneManager@1@@Z' % cls, (key, original.imported(iat))
    assert mov_vptr(ctor_site + 6, 0, primary) and mov_vptr(ctor_site + 6, LISTENER, secondary), key
    layout[cls] = {'size': hex(size), 'listener_base': hex(LISTENER), 'create': '%08x' % create,
                   'ctor_import': '%08x' % iat}

# The vtables are referenced only by the create*Query bodies (one DIR32 each, in the .text section).
text = next(s for s in original.pe.sections if s.Name.startswith(b'.text'))
text_data, text_va = text.get_data(), original.image + text.VirtualAddress
for key, c in CLASSES.items():
    for vtable in (c[6], c[7]):
        hits = []
        start = 0
        pattern = struct.pack('<I', vtable)
        while True:
            start = text_data.find(pattern, start)
            if start < 0:
                break
            hits.append(text_va + start)
            start += 1
        assert len(hits) == 1 and c[4] < hits[0] < c[4] + 0x20, (key, hex(vtable), [hex(h) for h in hits])

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT, HEADER]
exact = sorted({r['address'] for r in rows if r['exact']})
receipt = {
    'class': 'Ogre::Default{AxisAlignedBox,Sphere,PlaneBoundedVolumeList,Ray,Intersection}SceneQuery '
             '(rgmain.dll _OgreExport classes; exe-local compiler-generated parts)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), /fp:fast',
    'flags': {'layout': layout_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {layout_obj.name: sha(layout_obj)},
    'layout': layout,
    'rows': rows,
    'exact_function_rows': exact,
    'vtables': vt,
    'imports_not_rows': 'constructors, destructors, setBox / setSphere / setVolumes / setRay and every non-slot-0 '
                        'vtable entry are rgmain.dll imports (import thunks verified by export name above)',
    'proposals': {},
    'scope': 'Inactive. Compiler-generated ??_G / ??_E thunk rows, exact with verified targets; no active build, swap '
             'or credit. nativeNew* are probe scaffolding, not recovered functions.',
}
(ROOT / 'work/2008-06/shared-layouts/ogre-rbx-query-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Ogre default scene queries: %d distinct function rows exact (%s); %d vtables verified slot by slot'
      % (len(exact), ', '.join(exact), sum(len(v) for v in vt.values())))
