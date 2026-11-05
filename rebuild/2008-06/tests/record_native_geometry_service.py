"""Verify the inactive native RBX::GeometryService recovery (2008-06).

Builds (document-swap flags, VS2008 RTM 21022), all from the current native headers:
  * tests/NativeGeometryServiceLayout.cpp  sizeof/offset probe (mov eax, imm32; ret), the explicit
                                           Creatable<Instance>::create<GeometryService> instantiation and the two
                                           G3D::Array<PartInstance*> members the original keeps in this unit;
  * native-classes/GeometryService.cpp     (/fp:fast) the unit 0062d8f0..0062e070 plus class descriptor 005c0470,
                                           doDeclare 005bfa30 / callDoDeclare 005bffc0 and atexit 007fe710. The
                                           current bounds separate Array<PartInstance*>::resize (0062d9e0,
                                           256 bytes) and the folded ~Described jump (0062dae0, 5 bytes);
                                           each is compared against its complete analyzed extent;
  * GeometryService.cpp with NATIVE_GEOMETRYSERVICE_PENDING against out/native-layouts/geometry-service-pending/
    (declaration-only Workspace of tests/NativeGeometryServicePendingWorkspace.h, native engine-world World.h; FilterStairs
    from the native v8datamodel/Filters2008.h): getPartsTouchingExtents 0062db60
    and getHitLocationFilterStairs 0062dc10. Rows of this build are recorded exact=false (pending-build-only) and not
    counted; their symbols bind only as UNPROVEN.

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals by bytes, type descriptors and
vtables by original RTTI names, own symbols by the row proven here, folded bodies by their address, and the remaining
externals by the explicit EXTERNAL / DATA maps (call sites read in the original disassembly). A symbol binds to one
address across all rows. Vtables are compared slot by slot from the objects built with the current headers.
Writes work/2008-06/shared-layouts/geometry-service-working.json. Set NATIVE_GEOMETRY_DISCOVER=1 to list unbound
targets and non-exact rows instead of asserting.
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
OUT = R / 'out/native-geometry-service'
OUT.mkdir(parents=True, exist_ok=True)
LAYOUT = R / 'tests/NativeGeometryServiceLayout.cpp'
SRC = R / 'native-classes/GeometryService.cpp'
HDR = R / 'native-headers/v8datamodel/GeometryService.h'
PENDING_WORKSPACE = R / 'tests/NativeGeometryServicePendingWorkspace.h'
FILTERS_HDR = R / 'native-headers/v8datamodel/Filters2008.h'
PENDING = OUT / 'geometry-service-pending'
(PENDING / 'v8datamodel').mkdir(parents=True, exist_ok=True)
(PENDING / 'v8datamodel/Workspace.h').write_text(PENDING_WORKSPACE.read_text())
# FilterStairs comes from the native v8datamodel/Filters2008.h (tests/record_native_hit_filters.py); drop a stale overlay.
(PENDING / 'v8datamodel/FilterStairs.h').unlink(missing_ok=True)
DISCOVER = bool(os.environ.get('NATIVE_GEOMETRY_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeGeometryServiceLayout', LAYOUT, ['/fp:fast'])
unit_obj, unit_flags = build('NativeGeometryService', SRC, ['/fp:fast'])
pend_obj, pend_flags = build('NativeGeometryServicePending', SRC,
                             ['/fp:fast', '/I' + str(PENDING), '/I' + str(R / 'native-headers/engine-world'),
                              '/DNATIVE_GEOMETRYSERVICE_PENDING'])

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?nativeGeometryServiceSize@@'))
assert body_ == b'\xb8' + struct.pack('<I', 0x140) + b'\xc3', body_.hex()

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


FP = '?$FactoryProduct@VGeometryService@RBX@@VInstance@2@$1?sGeometryService@2@3PADA@RBX@@'
DC = '?$DescribedCreatable@VGeometryService@RBX@@VInstance@2@$1?sGeometryService@2@3PADA@RBX@@'
DS = '?$Described@VGeometryService@RBX@@$1?sGeometryService@2@3PADAV' + FP[:-6] + '@2@@Reflection@RBX@@'
DLR = 'VDeleter@?$Creatable@VInstance@RBX@@@'
APART = '?$Array@PAVPartInstance@RBX@@@G3D@@'

# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '??RDeleter@?$Creatable@VInstance@RBX@@@RBX@@QAEXPAVInstance@2@@Z': 0x405e30,  # shared_count call 005c1711; independently bound in service recorders.
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                                   # ~FactoryProduct 0062d93e tail jump
    '??0Instance@RBX@@QAE@PBD@Z': 0x55b960,                                # FactoryProduct ctor 0062d958
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a, '_atexit': 0x6a17af,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,                         # doDeclare 005bfa67
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,                          # getClassName 0062dbfa
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,       # classDescriptor 005c04b0
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,  # 005c04a5
    '??$create@VWorkspace@RBX@@@ServiceProvider@RBX@@QBEPAVWorkspace@1@XZ': 0x490af0,   # onServiceProvider 0062ddab
    '?alignedFree@System@G3D@@SAXPAX@Z': 0x507d20,                         # ~GeometryService 0062e02b
    '?alignedMalloc@System@G3D@@SAPAXII@Z': None,
}
# Array<PartInstance*>::realloc: resize 0062d9e0 calls 00502080 (ICF-shared pointer-array realloc, evidence unnamed).
EXTERNAL['?realloc@' + APART + 'AAEXH@Z'] = 0x502080
EXTERNAL['__ftol2_sse'] = 0x6a17f0   # resize 0062da86 (CRT float-to-int helper, statically linked)
EXTERNAL = {k: v for k, v in EXTERNAL.items() if v is not None}
DATA = {
    '?sGeometryService@RBX@@3PADA': 0x95c530,       # "Geometry" (doDeclare 005bfa5b, classDescriptor 005c0499, ctor 0062def8)
}
assert original.string(0x95c530) == 'Geometry'

# ICF / trivial-wrapper folds: the original keeps one body where this unit emits several identical ones.
FOLDED = {
    '??_G' + DC + 'UAEPAXI@Z': 0x62dec0,
    '?className@' + FP + 'SAABVName@2@XZ': 0x62dbf0,
    '??$declare@$1?sGeometryService@RBX@@3PADA@Name@RBX@@SAABV01@XZ': 0x62dbf0,
    '??1' + DC + 'UAE@XZ': 0x62dae0,
}
NON_EXACT_ROWS = [
]
UNPROVEN = {}

LAYOUT_ROWS = [
    (0x5c1650, '??$?0PAVGeometryService@RBX@@' + DLR + '1@@shared_count@detail@boost@@'),
    (0x5c1790, '??$create@VGeometryService@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VGeometryService@RBX@@@boost@@XZ'),
    (0x5c16e0, '??$?0VGeometryService@RBX@@' + DLR + '1@@?$shared_ptr@VGeometryService@RBX@@@boost@@QAE@PAVGeometryService@RBX@@' + DLR + '3@@Z'),
    (0x62d9e0, '?resize@' + APART + 'QAEXH_N@Z'),
    (0x62daf0, '?append@' + APART + 'QAEXABQAVPartInstance@RBX@@@Z'),
]
UNIT_ROWS = [
    (0x62d8f0, '??1' + FP + 'MAE@XZ'),
    (0x62d950, '??$?0PBD@' + FP + 'IAE@PBD@Z'),
    (0x62d9c0, '??_E' + FP + 'OEE@AEPAXI@Z'), (0x62d9d0, '??_E' + FP + 'OKE@AEPAXI@Z'),
    (0x62dae0, '??1' + DS + 'UAE@XZ'),
    (0x62dbf0, '?getClassName@' + FP + 'UBEABVName@2@XZ'),
    (0x62dda0, '?onServiceProvider@GeometryService@RBX@@MAEXPBVServiceProvider@2@0@Z'),
    (0x62ddc0, '??$?0PBD@' + DC + 'IAE@PBD@Z'),
    (0x62de60, '??_E' + FP + 'OBA@AEPAXI@Z'), (0x62de70, '??_E' + FP + 'OBE@AEPAXI@Z'),
    (0x62de80, '??_E' + FP + 'OCE@AEPAXI@Z'), (0x62de90, '??_E' + FP + 'OGE@AEPAXI@Z'),
    (0x62dea0, '??_E' + FP + 'OIE@AEPAXI@Z'), (0x62deb0, '??_E' + FP + 'OME@AEPAXI@Z'),
    (0x62dec0, '??_G' + FP + 'MAEPAXI@Z'),
    (0x62dee0, '??0GeometryService@RBX@@QAE@XZ'),
    (0x62df80, '??_EGeometryService@RBX@@WME@AEPAXI@Z'), (0x62df90, '??_EGeometryService@RBX@@WBA@AEPAXI@Z'),
    (0x62dfa0, '??_EGeometryService@RBX@@WBE@AEPAXI@Z'), (0x62dfb0, '??_EGeometryService@RBX@@WCE@AEPAXI@Z'),
    (0x62dfc0, '??_EGeometryService@RBX@@WEE@AEPAXI@Z'), (0x62dfd0, '??_EGeometryService@RBX@@WGE@AEPAXI@Z'),
    (0x62dfe0, '??_EGeometryService@RBX@@WIE@AEPAXI@Z'), (0x62dff0, '??_EGeometryService@RBX@@WKE@AEPAXI@Z'),
    (0x62e000, '??1GeometryService@RBX@@UAE@XZ'),
    (0x62e070, '??_GGeometryService@RBX@@UAEPAXI@Z'),
    (0x5c0470, '?classDescriptor@' + DS + 'SAAAVClassDescriptor@23@XZ'),
    (0x5bfa30, '??$doDeclare@$1?sGeometryService@RBX@@3PADA@Name@RBX@@CAABV01@XZ'),
    (0x5bffc0, '??$callDoDeclare@$1?sGeometryService@RBX@@3PADA@Name@RBX@@CAXXZ'),
    (0x7fe710, '??__Ffoo@?1??classDescriptor@' + DS),
]
# Built with NATIVE_GEOMETRYSERVICE_PENDING against the generated overlays: never counted.
PENDING_ROWS = [
    (0x62db60, '?getPartsTouchingExtents@GeometryService@RBX@@'),
    (0x62dc10, '?getHitLocationFilterStairs@GeometryService@RBX@@'),
]
PENDING_REASONS = {
    '0062db60': 'needs the native Workspace layout: the original loads World* inline from Workspace +0x2e4 (0062db6d); '
                'the pending overlay declares Workspace::getWorld() out of line (proposal), so this build calls it',
    '0062dc10': 'needs the native Workspace layout (Workspace +0x2e4 at 0062dc81); the pending overlay declares '
                'Workspace::getWorld() out of line. RBX::FilterStairs (constructor 006604a0) now comes from the native '
                'v8datamodel/Filters2008.h',
}
PENDING_EXTERNAL = {
    '?getPrimitivesTouchingExtents@ContactManager@RBX@@QAEXABVExtents@2@PBVPrimitive@2@AAV?$Array@PAVPrimitive@RBX@@@G3D@@@Z': 0x60d140,  # 0062db99
    '?resize@?$Array@PAVPrimitive@RBX@@@G3D@@QAEXH_N@Z': 0x599a70,         # 0062db87 (evidence name)
    '?fromPrimitive@PartInstance@RBX@@SAPAV12@PAVPrimitive@2@@Z': 0x599f80,   # 0062dbb9 (evidence fromPrimitiveConst, ICF)
    '??0FilterStairs@RBX@@QAE@PAVInstance@1@@Z': 0x6604a0,                 # 0062dc74
    '??0?$vector@PBVPrimitive@RBX@@V?$allocator@PBVPrimitive@RBX@@@std@@@std@@QAE@XZ': 0x4293d0,   # 0062dca2 (ICF)
    '?getHit@ContactManager@RBX@@QBEPAVPrimitive@2@ABVRay@G3D@@PBV?$vector@PBVPrimitive@RBX@@V?$allocator@PBVPrimitive@RBX@@@std@@@std@@PBVHitTestFilter@2@AAVVector3@5@AA_N@Z': 0x60db10,  # 0062dcc7
    '?unit@Ray@G3D@@QBE?AV12@XZ': 0x60cc70,                                 # 0062dcd9
}
PENDING_DATA = {
    '?ignoreBool@ContactManager@RBX@@2_NA': 0x97beb8,                      # 0062dca7 (getHit default `inside`)
    '?ZERO@Vector3@G3D@@2V12@B': 0x973810,                                 # 0062dc3e (zero-initialized static Vector3)
}

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}   # symbol -> (address, row) for the one-address-per-symbol check


def target_of(address):
    if isinstance(address, tuple) and address[0] == 'slice':
        _, row, lo, hi = address
        body, refs, _ = match.target('2008-06', '%08x' % row)
        assert len(body) >= hi, (hex(row), len(body), hi)
        return body[lo:hi], [r - lo for r in refs if lo <= r < hi]
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def first(address):
    if isinstance(address, tuple) and address[0] == 'slice':
        return address[1] + address[2]
    return address


def label(address):
    if isinstance(address, tuple) and address[0] == 'slice':
        return '%08x[%02x:%02x]' % address[1:]
    return '%08x' % address


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not LOCAL_EH.match(x[0])]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', label(address), key[:120], [h[0][:120] for h in hits])
            continue
        assert len(hits) == 1, (label(address), key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def verify(obj, rows, own, strict=True, external=EXTERNAL, data=DATA, record=True):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        if exact:
            assert set(target_refs) <= set(refs), (name, 'missing original relocation')
        entry = {'address': label(address), 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
        verified, local = {}, set()
        base = first(address)
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = symbols[index][0]
            assert kind in (6, 20), (name, symbol, 'unsupported relocation', kind)
            if kind == 20:
                value = (base + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            if LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol.startswith('??_C@'):
                pos, at = definitions[symbol]
                literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
                how = 'literal %r' % literal[:-1].decode()
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert norm(rtti) == norm('.' + symbol[5:-2]), (name, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('__real@'):
                assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
                how = 'constant %s' % symbol[7:]
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol.startswith('??_E') and ('??_G' + symbol[4:]) in own:
                assert own['??_G' + symbol[4:]] == value, (name, symbol, hex(value))
                how = 'own row (??_G)'
            elif symbol.startswith('??_E') and ('??_G' + symbol[4:]) in FOLDED:
                assert FOLDED['??_G' + symbol[4:]] == value, (name, symbol, hex(value))
                how = 'folded (??_G)'
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in FOLDED:
                assert FOLDED[symbol] == value, (name, symbol, hex(value))
                how = 'folded'
            elif symbol in data:
                assert data[symbol] == value, (name, symbol, hex(value))
                how = 'data'
            elif symbol in external:
                assert external[symbol] == value, (name, symbol, hex(value), hex(external[symbol]))
                how = 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
            elif symbol in UNPROVEN:
                assert UNPROVEN[symbol] == value, (name, symbol, hex(value))
                how = 'call target of a non-exact row'
            elif symbol.startswith('??_B?1??') or symbol.startswith('??_B?3??') or symbol.startswith('?$S') or '?$TSS' in symbol or symbol.startswith('?flag@') \
                    or symbol.startswith('?foo@') or symbol.startswith('?n@') or symbol.startswith('?root@') \
                    or symbol.startswith('?minSize@'):
                how = 'local static'
            else:
                UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
                continue
            if record:
                prev = binding.setdefault(symbol, (value, name))
                assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


layout_rows = resolve(layout_obj, LAYOUT_ROWS)
unit_rows = resolve(unit_obj, UNIT_ROWS)
pend_rows = resolve(pend_obj, PENDING_ROWS)
OBJ = {'layout': layout_obj, 'unit': unit_obj}
non_rows = [(resolve(OBJ[w], [(a, k)])[0], w) for a, k, _, w in NON_EXACT_ROWS]
own = {}
for address, name in layout_rows + unit_rows:
    own.setdefault(name, first(address))
strict = not DISCOVER
layout_out = verify(layout_obj, layout_rows, own, strict)
unit_out = verify(unit_obj, unit_rows, own, strict)
# Pending-build rows: exact only under NATIVE_GEOMETRYSERVICE_PENDING with generated overlays; never counted, and
# their target bindings are kept out of the one-address-per-symbol table.
pend_out = verify(pend_obj, pend_rows, own, strict=False, external=dict(EXTERNAL, **PENDING_EXTERNAL),
                  data=dict(DATA, **PENDING_DATA), record=False)
for row in pend_out:
    row['exact_pending_build_only'] = row['exact']
    row['exact'] = False
    row['reason'] = PENDING_REASONS[row['address']]
non_out = [verify(OBJ[w], [r], own, strict=False)[0] for r, w in non_rows]
for row, (_, _, why, _) in zip(non_out, NON_EXACT_ROWS):
    if row['exact'] and not DISCOVER:
        raise AssertionError('non-exact row unexpectedly exact: %s' % row['address'])
    row['exact'], row['reason'] = False, why
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for r in pend_out:
        print('PENDING', r['address'], r['exact_pending_build_only'], r['symbol'][:100], r['size'], r['target_size'])
    for g in (layout_out, unit_out):
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

# ---- vtables from the objects built with the current headers, slot by slot ---------------------------------
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL, UNPROVEN):
    for k, v in table_.items():
        slot_names.setdefault(k, v)


def compiled_vtable(obj, symbol):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[index][0]
    return [slots[i] for i in range(len(slots))]


def check_vtable(obj, symbol, address, reference=None, own_class=''):
    """Each slot holds the address bound to its symbol, the evidence name, or (for an inherited slot) the same
    address as the base class's vtable at `reference`."""
    out, bad = [], []
    for i, slot in enumerate(compiled_vtable(obj, symbol)):
        value = d(address + 4 * i)
        if slot.startswith('??_E') and '??_G' + slot[4:] in slot_names:
            expect, how = slot_names['??_G' + slot[4:]], 'bound (??_G)'
        else:
            expect, how = slot_names.get(slot), 'bound'
        ok = expect == value if expect is not None else norm(names.get(value, '')) == norm(slot)
        if expect is None:
            how = 'evidence name'
        if not ok and reference is not None:
            cls = slot.split('@')[1] if slot.startswith('?') and not slot.startswith('??') else ''
            if cls != own_class and value == d(reference + 4 * i):
                ok, how = True, 'inherited (same slot of the base vtable %08x)' % reference
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value)))
    assert not bad, (symbol, bad)
    return out


# Instance's own vtable 0082d884 (Instance constructor 0055b7e0) is the reference for inherited slots.
assert original.vtable_class(0x82d884) == ('.?AVInstance@RBX@@', 0)
GI = '6B?$GuidItem@VInstance@RBX@@@1@@'
vt = {}
vt['GeometryService'] = check_vtable(unit_obj, '??_7GeometryService@RBX@@' + GI, 0x846a84, 0x82d884, 'GeometryService')
assert len(vt['GeometryService']) == 16
assert vt['GeometryService'][12]['symbol'].startswith('?onServiceProvider@GeometryService') and \
    vt['GeometryService'][12]['original'] == '0062dda0'
vt['GeometryService_FactoryProduct'] = check_vtable(unit_obj, '??_7' + FP + GI, 0x846904, 0x82d884, 'GeometryService')
vt['GeometryService_DescribedCreatable'] = check_vtable(unit_obj, '??_7' + DC + GI, 0x8469c4, 0x82d884, 'GeometryService')

# ---- RTTI bases, allocation size -------------------------------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


assert original.vtable_class(0x846a84) == ('.?AVGeometryService@RBX@@', 0)
gb = bases(0x846a84)
assert gb['.?AVService@RBX@@'] == 0x130 and gb['.?AV' + DC] == 0, gb
factory, size, ctor = 0x5c1790, 0x140, 0x62dee0
body, _, _ = match.target('2008-06', '%08x' % factory)
at = body.index(b'\x68' + struct.pack('<I', size))
call = body.index(b'\xe8', at + 5)
while (factory + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != ctor:
    call = body.index(b'\xe8', call + 1)

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT, HDR, SRC, PENDING_WORKSPACE, FILTERS_HDR]
objects = [layout_obj, unit_obj, pend_obj]
groups = {'layout': layout_out, 'unit': unit_out}
exact = sorted({r['address'] for g in groups.values() for r in g if r['exact']})
groups['not_exact'] = non_out
groups['pending'] = pend_out
exact_rows = sorted(e for e in exact if '[' not in e)
exact_slices = sorted(e for e in exact if '[' in e)   # one function of a two-function row: not a whole row
PROPOSALS = {
    'v8datamodel/Workspace.h': 'World* getWorld() const { return world; } with World* world at Workspace +0x2e4 '
                               '(GeometryService 0062db6d / 0062dc81, PhysicsService 005e8ec0, JointsService 005e5b50, '
                               'WorkspaceStatsItem 005a66b0)',
}
receipt = {
    'class': 'RBX::GeometryService', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'unit': unit_flags, 'pending': pend_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in objects},
    'layout': {'GeometryService': '0x140 (005c1790); Service empty base (mdisp 0x130), workspace +0x130, '
                                  'G3D::Array<Primitive*> primitives +0x134; class name "Geometry" (char[] 0095c530)'},
    'rows': groups,
    'exact_function_rows': exact_rows,
    'exact_row_slices': exact_slices,
    'vtables': vt,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/geometry-service-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native GeometryService: %d distinct function rows exact + %d row slices (layout %d, unit %d); '
      '%d pending-build-only rows (%d exact there) and %d non-exact rows not counted; targets and %d vtables verified'
      % (len(exact_rows), len(exact_slices), sum(r['exact'] for r in layout_out), sum(r['exact'] for r in unit_out),
         len(pend_out), sum(r['exact_pending_build_only'] for r in pend_out), len(non_out), len(vt)))
