"""Verify the inactive native RBX::Network physics sender/receiver recovery (2008-06).

Builds (document-swap flags, VS2008 RTM 21022, current native headers only; no pending build):
  * tests/NativeNetworkPhysicsLayout.cpp   sizeof/field offsets (DirectPhysicsReceiver 8, RoundRobinPhysicsSender 0x18);
  * native-classes/NetworkPhysics.cpp      RoundRobinPhysicsSender constructor / deleting destructor / step,
                                           the inline ~MechanismTracker copy, DirectPhysicsReceiver deleting
                                           destructor / step.

Every row must be relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified (native_bind.verify): imports by export name, vtables by original RTTI
names, own symbols by the row proven here, the remaining externals by the EXTERNAL map below (call sites read in the
original disassembly), one address per symbol. The two vtables are slot-checked against the original (slot count,
every slot bound). The owner's allocation sizes, the inlined DirectPhysicsReceiver construction and the RTTI base
lists are asserted from the original bytes.
Writes work/2008-06/shared-layouts/network-physics-working.json.
"""
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = R / 'out/native-network-physics'
OUT.mkdir(parents=True, exist_ok=True)
UNIT = R / 'native-classes/NetworkPhysics.cpp'
HEADERS = [R / 'native-headers/Network/PhysicsReplication.h']
LAYOUT = R / 'tests/NativeNetworkPhysicsLayout.cpp'


def build(name, src):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeNetworkPhysicsLayout', LAYOUT)
unit_obj, unit_flags = build('NativeNetworkPhysics', UNIT)

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
for prefix, value in (('?nativeDirectPhysicsReceiverSize@@', 0x8), ('?nativeRoundRobinPhysicsSenderSize@@', 0x18)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

NS = 'Network@RBX@@'
RR = 'RoundRobinPhysicsSender@' + NS
DR = 'DirectPhysicsReceiver@' + NS
# Externals: the address the original instruction uses.
EXTERNAL = {
    '??3@YAXPAX@Z': 0x6a067a,                                # operator delete (004ca023, 004ab5bb)
    '?stopTracking@MechanismTracker@RBX@@AAEXXZ': 0x5e5320,  # 004ca016 call, 004c99b0 jmp
    '?getLocalTime@System@G3D@@SANXZ': 0x508410,             # 004c99f3 (inline G3D::System::time())
}
# (address, symbol)
ROWS = [
    (0x4c99c0, '??0' + RR + 'QAE@PAVReplicator@12@@Z'),
    (0x4ca010, '??_G' + RR + 'UAEPAXI@Z'),
    (0x47d410, '?step@' + RR + 'UAEXXZ'),
    (0x4c99b0, '??1MechanismTracker@RBX@@QAE@XZ'),
    (0x4ab5b0, '??_G' + DR + 'UAEPAXI@Z'),
    (0x70bdf0, '?step@' + DR + 'UAEXI@Z'),
]
# Original rows of this family that are not compiled here (recorded with the reason, not counted).
NOT_EXACT = [
    ('004cd420', 'RoundRobinPhysicsSender::sendPackets (225 bytes): needs World::getSimJobStage 005e93b0, the '
                 'Workspace world (+0x2e4) and an unidentified 0x13c-byte local type (004cbd40 / 004c9a70); declared '
                 'only, bound through vtable 00826760 slot 2.'),
    ('004c83b0', 'DirectPhysicsReceiver::receivePacket (1890 bytes): needs the native Replicator / IdSerializer '
                 'deserialize API (004a8b60); declared only, bound through vtable 008247d0 slot 2.'),
    ('004ccb10 004ccb90 004ccde0 004cd920 004cce00', 'PhysicsSender (0x74): not declared; its +4 '
                 'boost::multi_index_container value type (0x50 bytes) is not derived yet.'),
    ('004b5e80 004b6290 004c8fa0 004c9120', 'InterpolatingPhysicsReceiver (0x3c): not declared; its +8 '
                 'multi_index_container value type (0x290-byte value) is not derived yet.'),
]

rows = nb.verify(original, unit_obj, [(s, a) for a, s in ROWS], EXTERNAL)
own = {s: a for a, s in ROWS}
for row in rows:
    for symbol, how in row['verified_targets'].items():
        if symbol in EXTERNAL and '!' not in how:
            row['verified_targets'][symbol] = '%s (external%s)' % (
                how, ', evidence name' if names.get(EXTERNAL[symbol], '') == symbol else '')

# ---- vtables (current-header object) ----------------------------------------------------------------
text = next(x for x in original.pe.sections if x.Name.startswith(b'.text'))
TEXT = (original.image + text.VirtualAddress, original.image + text.VirtualAddress + text.Misc_VirtualSize)


def original_slots(vt):
    n = 0
    while TEXT[0] <= d(vt + 4 * n) < TEXT[1]:
        n += 1
    return n


def vtable_slots(obj, symbol):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, index = definitions[symbol]
    section = sections[index]
    slots = {}
    for i in range(section[7]):
        offset, sym, kind = struct.unpack_from('<IIH', raw, section[5] + 10 * i)
        if offset >= start and kind == 6:
            slots[(offset - start) // 4] = symbols[sym][0]
    return slots


# Declared-only slot functions: bound to the original vtable slot (not rows).
SLOT_ONLY = {
    '?sendPackets@' + RR + 'UAEHH@Z': 0x4cd420,
    '?receivePacket@' + DR + 'UAEXAAVBitStream@RakNet@@I@Z': 0x4c83b0,
}
VTABLES = {'??_7' + RR + '6B@': (0x826760, '.?AV' + RR), '??_7' + DR + '6B@': (0x8247d0, '.?AV' + DR)}
# Constructor vtable stores: RoundRobin 004c99c0 and the inlined DirectPhysicsReceiver construction 004ba125.
for row in rows:
    for symbol, how in row['verified_targets'].items():
        if symbol in VTABLES:
            assert how.startswith(hex(VTABLES[symbol][0])), (symbol, how)
vtables = []
for symbol, (vt, rtti) in VTABLES.items():
    assert original.vtable_class(vt) == (rtti, 0), (hex(vt), original.vtable_class(vt))
    slots = vtable_slots(unit_obj, symbol)
    count = original_slots(vt)
    assert len(slots) == count == 3, (symbol, slots, count)
    entries = {}
    for slot, name in sorted(slots.items()):
        value = d(vt + 4 * slot)
        if name.startswith('??_E') and ('??_G' + name[4:]) in own:
            assert own['??_G' + name[4:]] == value, (symbol, slot, name, hex(value))
            how = 'own row (??_G)'
        elif name in own:
            assert own[name] == value, (symbol, slot, name, hex(value))
            how = 'own row'
        else:
            assert SLOT_ONLY.get(name) == value, (symbol, slot, name, hex(value))
            how = 'declared only (open)'
        entries[slot] = '%s -> %s (%s)' % (name, hex(value), how)
    vtables.append({'vtable': hex(vt), 'symbol': symbol, 'rtti_offset': 0, 'original_slots': count, 'slots': entries})

# ---- RTTI base lists: Impl -> I* -> noncopyable (mdisp 4, private) ---------------------------------------
for vt, iface in ((0x826760, 'IPhysicsSender'), (0x826928, 'IPhysicsSender'), (0x8247d0, 'IPhysicsReceiver'),
                  (0x824ee4, 'IPhysicsReceiver')):
    locator = d(vt - 4)
    hierarchy = d(locator + 16)
    items = [d(d(hierarchy + 12) + 4 * i) for i in range(d(hierarchy + 8))]
    bases = [(original.string(d(item) + 8), d(item + 4), struct.unpack('<i', original.data(item + 8, 4))[0],
              d(item + 20)) for item in items]
    assert [b[0] for b in bases[1:]] == ['.?AV%s@%s' % (iface, NS), '.?AVnoncopyable@noncopyable_@boost@@'], bases
    assert [b[1] for b in bases] == [2, 1, 0] and bases[2][2] == 4 and bases[2][3] & 4, bases
# No vtable of the interfaces exists (novtable): no complete-object locator (signature 0, type descriptor at +12)
# names their type descriptors; only base class descriptors reference them.
image = original.pe.get_memory_mapped_image()
for iface in ('IPhysicsSender', 'IPhysicsReceiver'):
    name_at = image.find(('.?AV%s@%s' % (iface, NS)).encode() + b'\0')
    assert name_at > 0
    td = original.image + name_at - 8
    pos, refs = 0, []
    while True:
        pos = image.find(struct.pack('<I', td), pos)
        if pos < 0:
            break
        refs.append(pos)
        pos += 1
    assert refs, iface
    locators = [r for r in refs if r >= 12 and struct.unpack_from('<I', image, r - 12)[0] == 0
                and struct.unpack_from('<I', image, r - 8)[0] == 0]
    assert not locators, (iface, [hex(original.image + r - 12) for r in locators])
# Owner allocation sizes (Replicator constructor 004b9bd0).
body, _, _ = match.target('2008-06', '004b9bd0')
base = 0x4b9bd0
at = lambda a: body[a - base:]
assert at(0x4ba073)[:2] == b'\x6a\x18' and at(0x4ba08d)[0] == 0xe8      # new(0x18) RoundRobinPhysicsSender
assert at(0x4ba094)[:2] == b'\x6a\x74'                                  # new(0x74) PhysicsSender
assert at(0x4ba0e8)[:2] == b'\x6a\x3c'                                  # new(0x3c) InterpolatingPhysicsReceiver
assert at(0x4ba117)[:2] == b'\x6a\x08'                                  # new(8) DirectPhysicsReceiver, inlined:
assert at(0x4ba125)[:6] == b'\xc7\x00' + struct.pack('<I', 0x8247d0)     #   vtable store
assert at(0x4ba12b)[:3] == b'\x89\x70\x04'                              #   +4 = Replicator (esi)
assert at(0x4ba0bd)[:6] == b'\x89\x86' + struct.pack('<I', 0x2b80)       # sender slot
assert at(0x4ba138)[:6] == b'\x89\x86' + struct.pack('<I', 0x2b84)       # receiver slot

sha = nb.sha
paths = [Path(__file__).resolve(), UNIT, LAYOUT] + HEADERS
exact_addresses = sorted({r['address'] for r in rows})
receipt = {
    'class': 'RBX::Network::IPhysicsSender/IPhysicsReceiver, RoundRobinPhysicsSender, DirectPhysicsReceiver',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'unit': unit_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, unit_obj)},
    'layout': 'DirectPhysicsReceiver 8 (replicator +4); RoundRobinPhysicsSender 0x18 (replicator +4, MechanismTracker '
              '+8, lastSendTime double +0x10); interfaces novtable, private boost::noncopyable at mdisp 4.',
    'methods': rows, 'not_exact': NOT_EXACT, 'vtables': vtables, 'proposals': [],
    'exact_distinct_addresses': exact_addresses,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit. PhysicsSender '
             'and InterpolatingPhysicsReceiver remain open (multi_index value types).',
}
(ROOT / 'work/2008-06/shared-layouts/network-physics-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Network physics sender/receiver: %d exact rows (%d distinct addresses), %d not-exact groups; '
      '%d vtables; targets verified' % (len(rows), len(exact_addresses), len(NOT_EXACT), len(vtables)))
