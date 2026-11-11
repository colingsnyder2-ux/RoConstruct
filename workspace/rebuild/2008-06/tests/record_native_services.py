"""Verify the inactive native RBX::JointsService, RBX::PhysicsService and RBX::NetworkSettings recovery (2008-06).

Builds (document-swap flags, VS2008 RTM 21022), all from the current native headers unless noted:
  * tests/NativeServicesLayout.cpp     sizeof/offset probes (mov eax, imm32; ret) plus the explicit
                                       Creatable<Instance>::create<...> instantiations, which emit the inline
                                       constructors, destructors, ??_E thunks and shared_ptr helpers the original keeps
                                       in the units that first create each service;
  * native-classes/JointsService.cpp   the JointsService unit 005e54c0..005e5860 (onServiceProvider 005e5b50 not
                                       attempted: needs a native Workspace);
  * native-classes/PhysicsService.cpp  the PhysicsService unit (destructor, AssemblyAdded/AssemblyRemoved signals,
                                       onAdded/onRemoved, class descriptor and name);
  * PhysicsService.cpp with NATIVE_PHYSICSSERVICE_PENDING against a generated copy of the donor v8world/World.h
    under out/native-layouts/services-pending/ that defines AssemblyPhysicsOn/AssemblyPhysicsOff (PROPOSAL_WORLD
    below): the two onEvent bodies 005e9110 / 005e9130. Rows exact only in this build are recorded exact=false
    (pending-build-only) and not counted;
  * native-classes/NetworkSettings.cpp the NetworkSettings unit 004a9b70..004aada0 with its class descriptor and name
                                       (0049e510/0049e580/0049ec80), 18 property initializers 007f1df0..007f2140 and their
                                       atexit functions (EnumPropDescriptor constructors not exact: 2008 reflection.h).

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals by bytes, type descriptors and
vtables by original RTTI names, own symbols by the row proven here, folded bodies by their address, and the remaining
externals by the explicit EXTERNAL / DATA maps (call sites read in the original disassembly; evidence names are noted
where the evidence file has one). A symbol binds to one address across all rows. Vtables are compared slot by slot from
the objects built with the current headers (never the pending one). Writes work/2008-06/shared-layouts/services-working.json.
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
LAYOUT = R / 'tests/NativeServicesLayout.cpp'
JOINTS_SRC = R / 'native-classes/JointsService.cpp'
PHYSICS_SRC = R / 'native-classes/PhysicsService.cpp'
NETWORK_SRC = R / 'native-classes/NetworkSettings.cpp'
JOINTS_H = R / 'native-headers/v8datamodel/JointsService.h'
PHYSICS_H = R / 'native-headers/v8datamodel/PhysicsService.h'
NETWORK_H = R / 'native-headers/Network/NetworkSettings.h'
DISCOVER = bool(os.environ.get('NATIVE_SERVICES_DISCOVER'))

# Proposed declarations for v8world/World.h (not edited here; generated copy for the pending build only). The member
# name is provisional: the onEvent bodies pass the event's only 4-byte member to PartInstance::fromPrimitive 00599f80.
PROPOSAL_WORLD_ANCHOR = '''	struct AutoDestroy
	{
		Joint* joint;
		AutoDestroy(Joint* j) : joint(j) {}
	};
'''
PROPOSAL_WORLD = '''
	struct AssemblyPhysicsOn
	{
		Primitive* primitive;
	};

	struct AssemblyPhysicsOff
	{
		Primitive* primitive;
	};
'''
pending = OUT / 'services-pending'
(pending / 'v8world').mkdir(parents=True, exist_ok=True)
text = (ROOT / 'tools/rbxgs/Client/App/include/v8world/World.h').read_text()
assert text.count(PROPOSAL_WORLD_ANCHOR) == 1
(pending / 'v8world/World.h').write_text(text.replace(PROPOSAL_WORLD_ANCHOR, PROPOSAL_WORLD_ANCHOR + PROPOSAL_WORLD))
world_overlay = OUT / 'services-world-overlay'
(world_overlay / 'v8world').mkdir(parents=True, exist_ok=True)
(world_overlay / 'v8world/World.h').write_text('#include "engine-world/v8world/World.h"\n')


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeServicesLayout', LAYOUT)
joints_obj, joints_flags = build('NativeJointsService', JOINTS_SRC)
physics_obj, physics_flags = build('NativePhysicsService', PHYSICS_SRC, ['/I' + str(world_overlay)])
physp_obj, physp_flags = build('NativePhysicsServicePending', PHYSICS_SRC,
                               ['/I' + str(world_overlay), '/I' + str(pending), '/DNATIVE_PHYSICSSERVICE_PENDING'])
HAVE_NETWORK = NETWORK_SRC.exists()
if HAVE_NETWORK:
    network_obj, network_flags = build('NativeNetworkSettings', NETWORK_SRC)

# ---- layout ---------------------------------------------------------------------------------------
SIZES = [('?nativeJointsServiceSize@@', 0x154), ('?nativePhysicsServiceSize@@', 0x158)]
if HAVE_NETWORK:
    SIZES.append(('?nativeNetworkSettingsSize@@', 0x160))
raw = layout_obj.read_bytes()
for prefix, value in SIZES:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


STR = '?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
SIG = '?$SignalDesc@VPhysicsService@RBX@@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@Z@Reflection@RBX@@'
NFP = '?$NonFactoryProduct@VInstance@RBX@@$1?sPhysicsService@2@3QBDB@RBX@@'
DNP = '?$DescribedNonCreatable@VPhysicsService@RBX@@VInstance@2@$1?sPhysicsService@2@3QBDB@RBX@@'
DSP = '?$Described@VPhysicsService@RBX@@$1?sPhysicsService@2@3QBDBV' + NFP[:-6] + '@2@@Reflection@RBX@@'
DLR = 'VDeleter@?$Creatable@VInstance@RBX@@@'

from record_native_services_maps import EXTERNAL, DATA, FOLDED, UNPROVEN, NOT_ATTEMPTED, NOT_ATTEMPTED_NETWORK  # noqa: E402  (tests/record_native_services_maps.py)

# Rows: (address, symbol or unique symbol prefix)
LAYOUT_ROWS = [
    # JointsService: inline constructor/destructor and thunks, emitted with Creatable<Instance>::create<JointsService>
    (0x4b0df0, '??$create@VJointsService@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VJointsService@RBX@@@boost@@XZ'),
    (0x4afa30, '??0JointsService@RBX@@QAE@XZ'),
    (0x4afb30, '?askAddChild@JointsService@RBX@@EBE_NPBVInstance@2@@Z'),
    (0x4afb60, '??_EJointsService@RBX@@WBE@AEPAXI@Z'), (0x4afb70, '??_EJointsService@RBX@@WBDA@AEPAXI@Z'),
    (0x4afb80, '??_EJointsService@RBX@@WBDE@AEPAXI@Z'), (0x4afb90, '??_EJointsService@RBX@@WCE@AEPAXI@Z'),
    (0x4afba0, '??_EJointsService@RBX@@WEE@AEPAXI@Z'), (0x4afbb0, '??_EJointsService@RBX@@WGE@AEPAXI@Z'),
    (0x4afbc0, '??_EJointsService@RBX@@WIE@AEPAXI@Z'), (0x4afbd0, '??_EJointsService@RBX@@WKE@AEPAXI@Z'),
    (0x4afbe0, '??_EJointsService@RBX@@WME@AEPAXI@Z'), (0x4afbf0, '??_EJointsService@RBX@@WBA@AEPAXI@Z'),
    (0x4afc00, '??1JointsService@RBX@@UAE@XZ'),
    (0x4afc50, '??_GJointsService@RBX@@UAEPAXI@Z'),
    (0x416690, '?write@JointsService@RBX@@EAEPAVXmlElement@@XZ'),        # folded return-NULL body
    # PhysicsService: inline constructor, base constructors, thunks and creator (create unit 004c9ac0..004cd760)
    (0x4cd760, '??$create@VPhysicsService@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VPhysicsService@RBX@@@boost@@XZ'),
    (0x4ad610, '??$?0VJointsService@RBX@@' + DLR + '1@@?$shared_ptr@VJointsService@RBX@@@boost@@QAE@PAVJointsService@RBX@@' + DLR + '3@@Z'),
    (0x4cb0c0, '??$?0VPhysicsService@RBX@@' + DLR + '1@@?$shared_ptr@VPhysicsService@RBX@@@boost@@QAE@PAVPhysicsService@RBX@@' + DLR + '3@@Z'),
    (0x4c9ac0, '??0' + NFP + 'QAE@XZ'),
    (0x4cd510, '??0' + DNP + 'IAE@XZ'),
    (0x4cd5b0, '??0PhysicsService@RBX@@QAE@XZ'),
    (0x4cd6a0, '??_EPhysicsService@RBX@@WCE@AEPAXI@Z'), (0x4cd6b0, '??_EPhysicsService@RBX@@WEE@AEPAXI@Z'),
    (0x4cd6c0, '??_EPhysicsService@RBX@@WGE@AEPAXI@Z'), (0x4cd6d0, '??_EPhysicsService@RBX@@WIE@AEPAXI@Z'),
    (0x4cd6e0, '??_EPhysicsService@RBX@@WKE@AEPAXI@Z'), (0x4cd6f0, '??_EPhysicsService@RBX@@WME@AEPAXI@Z'),
    (0x4cd700, '??_EPhysicsService@RBX@@WBA@AEPAXI@Z'), (0x4cd710, '??_EPhysicsService@RBX@@WBE@AEPAXI@Z'),
    (0x4cd720, '??_EPhysicsService@RBX@@WBDA@AEPAXI@Z'), (0x4cd730, '??_EPhysicsService@RBX@@WBDE@AEPAXI@Z'),
    (0x4cd740, '??_GPhysicsService@RBX@@UAEPAXI@Z'),
]
if NETWORK_SRC.exists():
    LAYOUT_ROWS += [
        (0x49e810, '??$create@VNetworkSettings@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VNetworkSettings@RBX@@@boost@@XZ'),
        (0x49e760, '??$?0VNetworkSettings@RBX@@' + DLR + '1@@?$shared_ptr@VNetworkSettings@RBX@@@boost@@QAE@PAVNetworkSettings@RBX@@' + DLR + '3@@Z'),
    ]
JOINTS_ROWS = [
    (0x5e54c0, '?onDescendentAdded@JointsService@RBX@@EAEXPAVInstance@2@@Z'),
    (0x5e5500, '?onEvent@JointsService@RBX@@EAEXPBVWorld@2@UAutoDestroy@2@@Z'),
    (0x5e5520, '?onDescendentRemoving@JointsService@RBX@@EAEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z'),
    (0x5e5560, '??$create@VSnap@RBX@@PAVJoint@2@@?$Creatable@VInstance@RBX@@@RBX@@'),
    (0x5e55e0, '??$create@VWeld@RBX@@PAVJoint@2@@?$Creatable@VInstance@RBX@@@RBX@@'),
    (0x5e5660, '??$create@VGlue@RBX@@PAVJoint@2@@?$Creatable@VInstance@RBX@@@RBX@@'),
    (0x5e56e0, '??$create@VRotate@RBX@@PAVJoint@2@@?$Creatable@VInstance@RBX@@@RBX@@'),
    (0x5e5760, '??$create@VRotateP@RBX@@PAVJoint@2@@?$Creatable@VInstance@RBX@@@RBX@@'),
    (0x5e57e0, '??$create@VRotateV@RBX@@PAVJoint@2@@?$Creatable@VInstance@RBX@@@RBX@@'),
    (0x5e5860, '?onEvent@JointsService@RBX@@EAEXPBVWorld@2@UAutoJoin@2@@Z'),
]
PHYSICS_ROWS = [
    (0x5e8d30, '??1PhysicsService@RBX@@UAE@XZ'),
    (0x5e8df0, '??0' + SIG + 'QAE@PBD0@Z'),
    (0x5e8f70, '?onAdded@PhysicsService@RBX@@AAEXPAVPartInstance@2@@Z'),
    (0x5e9040, '?onRemoved@PhysicsService@RBX@@AAEXPAVPartInstance@2@@Z'),
    (0x7f6e40, '??__Eevent_AssemblyAdded@RBX@@YAXXZ'),
    (0x7f6e60, '??__Eevent_AssemblyRemoved@RBX@@YAXXZ'),
    (0x7ffa30, '??__Fevent_AssemblyAdded@RBX@@YAXXZ'),
    (0x7ff9f0, '??__Fevent_AssemblyRemoved@RBX@@YAXXZ'),
    (0x4c9b70, '??$doDeclare@$1?sPhysicsService@RBX@@3QBDB@Name@RBX@@CAABV01@XZ'),
    (0x4ca340, '??$callDoDeclare@$1?sPhysicsService@RBX@@3QBDB@Name@RBX@@CAXXZ'),
    (0x4cb520, '?getClassName@' + NFP + 'UBEABVName@2@XZ'),
    (0x4cd300, '?classDescriptor@' + DSP + 'SAAAVClassDescriptor@23@XZ'),
    (0x7fc360, '??__Ffoo@?1??classDescriptor@' + DSP),
]
PHYSICS_PENDING_ROWS = [
    (0x5e9110, '?onEvent@PhysicsService@RBX@@MAEXPBVWorld@2@UAssemblyPhysicsOn@2@@Z'),
    (0x5e9130, '?onEvent@PhysicsService@RBX@@MAEXPBVWorld@2@UAssemblyPhysicsOff@2@@Z'),
]
try:
    from record_native_services_maps import NETWORK_ROWS  # noqa: E402
except ImportError:
    NETWORK_ROWS = []

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}   # symbol -> (address, row) for the one-address-per-symbol check


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not LOCAL_EH.match(x[0])]
        assert len(hits) == 1, (hex(address), key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def verify(obj, rows, own, strict=True):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
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
            elif symbol in DATA:
                assert DATA[symbol] == value, (name, symbol, hex(value))
                how = 'data'
            elif symbol in UNPROVEN:
                assert UNPROVEN[symbol] == value, (name, symbol, hex(value))
                how = 'call target of a non-exact row'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
            elif symbol.startswith('??_B?1??') or symbol.startswith('?$S') or '?$TSS' in symbol or symbol.startswith('?flag@') \
                    or symbol.startswith('?foo@') or symbol.startswith('?n@') or symbol.startswith('?root@'):
                how = 'local static'
            else:
                UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


layout_rows = resolve(layout_obj, LAYOUT_ROWS)
joints_rows = resolve(joints_obj, JOINTS_ROWS)
physics_rows = resolve(physics_obj, PHYSICS_ROWS)
physp_rows = resolve(physp_obj, PHYSICS_PENDING_ROWS)
network_rows = resolve(network_obj, NETWORK_ROWS) if HAVE_NETWORK else []
own = {}
for address, name in layout_rows + joints_rows + physics_rows + network_rows:
    own.setdefault(name, address)
strict = not DISCOVER
layout_out = verify(layout_obj, layout_rows, own, strict)
joints_out = verify(joints_obj, joints_rows, own, strict)
physics_out = verify(physics_obj, physics_rows, own, strict)
network_out = verify(network_obj, network_rows, own, strict) if HAVE_NETWORK else []
physp_out = verify(physp_obj, physp_rows, own, strict)
for row in physp_out:  # exact only under NATIVE_PHYSICSSERVICE_PENDING with a generated World.h copy: not counted
    row['exact'] = False
    row['exact_pending_build_only'] = True
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in (layout_out, joints_out, physics_out, network_out):
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:100], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- vtables from the objects built with the current headers, slot by slot ---------------------------------
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
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
vt['JointsService'] = check_vtable(layout_obj, '??_7JointsService@RBX@@' + GI, 0x824acc, 0x82d884, 'JointsService')
vt['JointsService_autojoin'] = check_vtable(layout_obj, '??_7JointsService@RBX@@6B?$Listener@VWorld@RBX@@UAutoJoin@2@@1@@', 0x824a44)
vt['JointsService_autodestroy'] = check_vtable(layout_obj, '??_7JointsService@RBX@@6B?$Listener@VWorld@RBX@@UAutoDestroy@2@@1@@', 0x824a38)
vt['PhysicsService'] = check_vtable(layout_obj, '??_7PhysicsService@RBX@@' + GI, 0x826aac, 0x82d884, 'PhysicsService')
vt['PhysicsService_on'] = check_vtable(layout_obj, '??_7PhysicsService@RBX@@6B?$Listener@VWorld@RBX@@UAssemblyPhysicsOn@2@@1@@', 0x826a24)
vt['PhysicsService_off'] = check_vtable(layout_obj, '??_7PhysicsService@RBX@@6B?$Listener@VWorld@RBX@@UAssemblyPhysicsOff@2@@1@@', 0x826a18)
assert len(vt['JointsService']) == len(vt['PhysicsService']) == 16
assert vt['JointsService'][12]['symbol'].startswith('?onServiceProvider@JointsService') and vt['JointsService'][12]['original'] == '005e5b50'
assert vt['PhysicsService'][12]['symbol'].startswith('?onServiceProvider@PhysicsService') and vt['PhysicsService'][12]['original'] == '005e8ec0'
if HAVE_NETWORK:
    from record_native_services_maps import network_vtables  # noqa: E402
    vt.update(network_vtables(check_vtable, layout_obj, network_obj, GI))

# ---- RTTI bases, allocation sizes and strings ------------------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


assert original.vtable_class(0x824acc) == ('.?AVJointsService@RBX@@', 0)
assert original.vtable_class(0x826aac) == ('.?AVPhysicsService@RBX@@', 0)
jb = bases(0x824acc)
assert jb['.?AV?$Listener@VWorld@RBX@@UAutoJoin@2@@RBX@@'] == 0x130 and jb['.?AV?$Listener@VWorld@RBX@@UAutoDestroy@2@@RBX@@'] == 0x134
assert jb['.?AVService@RBX@@'] == 0x138 and jb['.?AVIRenderableBucket@RBX@@'] == 0x138, jb
pb = bases(0x826aac)
assert pb['.?AV?$Listener@VWorld@RBX@@UAssemblyPhysicsOn@2@@RBX@@'] == 0x130 and pb['.?AV?$Listener@VWorld@RBX@@UAssemblyPhysicsOff@2@@RBX@@'] == 0x134
assert pb['.?AVService@RBX@@'] == 0x138, pb
for factory, size, ctor in ((0x4b0df0, 0x154, 0x4afa30), (0x4cd760, 0x158, 0x4cd5b0)) + (((0x49e810, 0x160, 0x4aabc0),) if HAVE_NETWORK else ()):
    body, _, _ = match.target('2008-06', '%08x' % factory)
    at = body.index(b'\x68' + struct.pack('<I', size))
    call = body.index(b'\xe8', at + 5)
    while (factory + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != ctor:
        call = body.index(b'\xe8', call + 1)
for address, text in ((0x83f858, 'PhysicsService'), (0x826a04, 'PhysicsService'), (0x824b0c, 'JointsService'),
                      (0x83f878, 'AssemblyAdded'), (0x83f888, 'AssemblyRemoved'), (0x81c960, 'part')):
    assert original.string(address) == text, (hex(address), text)

sha = nb.sha
paths = [Path(__file__).resolve(), R / 'tests/record_native_services_maps.py', LAYOUT, JOINTS_H, PHYSICS_H, JOINTS_SRC, PHYSICS_SRC]
objects = [layout_obj, joints_obj, physics_obj, physp_obj]
flags = {'layout': layout_flags, 'joints': joints_flags, 'physics': physics_flags, 'physics_pending': physp_flags}
if HAVE_NETWORK:
    paths += [NETWORK_H, NETWORK_SRC]
    objects.append(network_obj)
    flags['network'] = network_flags
groups = {'layout': layout_out, 'joints': joints_out, 'physics': physics_out, 'network': network_out, 'pending': physp_out}
exact_rows = sorted({r['address'] for g in (layout_out, joints_out, physics_out, network_out) for r in g if r['exact']})
receipt = {
    'class': 'RBX::JointsService, RBX::PhysicsService, RBX::NetworkSettings', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': flags,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in objects},
    'layout': {'JointsService': '0x154 (004b0df0); Listener<World,AutoJoin> +0x130, Listener<World,AutoDestroy> +0x134, Service and IRenderableBucket +0x138, world +0x150',
               'PhysicsService': '0x158 (004cd760); Listener<World,AssemblyPhysicsOn> +0x130, Listener<World,AssemblyPhysicsOff> +0x134, Service and std::set<PartInstance*> parts +0x138; class name "PhysicsService" (const char[] 0083f858)',
               'NetworkSettings': '0x160 (0049e810); GlobalSettingsItem<NetworkSettings, sNetworkSettings>, fields +0x130..+0x15c'},
    'rows': groups,
    'exact_function_rows': exact_rows,
    'vtables': vt,
    'pending_note': 'pending rows are exact only with a generated copy of the donor v8world/World.h that defines '
                    'AssemblyPhysicsOn/AssemblyPhysicsOff (PROPOSAL_WORLD) under out/native-layouts/services-pending.',
    'not_attempted': dict(NOT_ATTEMPTED, **(NOT_ATTEMPTED_NETWORK if HAVE_NETWORK else {})),
    'proposal_world_h': PROPOSAL_WORLD,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/services-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native JointsService/PhysicsService/NetworkSettings: %d distinct function addresses exact '
      '(layout %d, joints %d, physics %d, network %d); %d pending-build-only rows not counted; targets and %d vtables verified'
      % (len(exact_rows), sum(r['exact'] for r in layout_out), sum(r['exact'] for r in joints_out),
         sum(r['exact'] for r in physics_out), sum(r['exact'] for r in network_out), len(physp_out), len(vt)))
