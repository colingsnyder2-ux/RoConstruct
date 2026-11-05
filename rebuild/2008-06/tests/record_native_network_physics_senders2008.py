"""Verify the inactive native RBX::Network::PhysicsSender / InterpolatingPhysicsReceiver recovery (2008-06).

Builds (document-swap flags, VS2008 RTM 21022, current native headers only; no pending build):
  * tests/NativeNetworkPhysicsSenders2008Layout.cpp   sizeof/field offsets (sender 0x74, receiver 0x3c, nodes);
  * native-classes/NetworkPhysicsSenders2008.cpp      (/fp:fast) both constructors, PhysicsSender destructor, both scalar
                                                      deleting destructors and the boost 1.34.1 multi_index_container
                                                      instantiations they reach.

Every row must be relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified (native_bind.verify): imports by export name, vtables by original RTTI
names, own symbols by the row proven here, the remaining externals by the EXTERNAL map (call sites read in the
original disassembly), one address per symbol. Identical-code-folded template instances (two compiled symbols, one
original address) are rows of their own and each is bound to the address its caller uses. Both vtables are
slot-checked against the original from the current-header object. Writes
work/2008-06/shared-layouts/network-physics-senders2008-working.json.
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
OUT = R / 'out/native-network-physics-senders2008'
OUT.mkdir(parents=True, exist_ok=True)
UNIT = R / 'native-classes/NetworkPhysicsSenders2008.cpp'
HEADERS = [R / 'native-headers/Network/PhysicsSenders2008.h', R / 'native-headers/Network/PhysicsReplication.h']
LAYOUT = R / 'tests/NativeNetworkPhysicsSenders2008Layout.cpp'


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeNetworkPhysicsSenders2008Layout', LAYOUT)
# /fp:fast: calculate_max_load 004ca090 keeps mlf * bucket_count() on the x87 stack (no fstp/fld float rounding) and
# compares with the float 2^32 constant; the default /fp:precise build stores and reloads it.
unit_obj, unit_flags = build('NativeNetworkPhysicsSenders2008', UNIT, ['/fp:fast'])

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
for prefix, value in (('?nativePhysicsSenderSize@@', 0x74), ('?nativeInterpolatingPhysicsReceiverSize@@', 0x3c),
                      ('?nativePhysicsSenderNodeSize@@', 0x78), ('?nativeInterpolatingPhysicsReceiverNodeSize@@', 0x298)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

NS = 'Network@RBX@@'
PS = 'PhysicsSender@' + NS
IR = 'InterpolatingPhysicsReceiver@' + NS
SI = 'UPartItem@' + PS        # sender item type in template arguments
RI = 'UPartItem@' + IR        # receiver item type

# Rows: (address, symbol prefix, substrings the symbol must contain). Each spec must select exactly one function.
SPECS = [
    # PhysicsSender
    (0x4ccb10, '??0' + PS + 'QAE@PAVReplicator@12@@Z', []),
    (0x4ccb90, '??1' + PS + 'UAE@XZ', []),
    (0x4ccde0, '??_G' + PS + 'UAEPAXI@Z', []),
    (0x4cc400, '??0?$multi_index_container@' + SI, []),
    (0x4cbdc0, '??0?$hashed_index@U?$member@' + SI, []),
    (0x4cacc0, '?empty_initialize@?$ordered_index@U?$member@' + SI + 'N$07@', []),
    (0x4cadd0, '?empty_initialize@?$ordered_index@U?$member@' + SI + 'H$0EE@', []),
    (0x4cb540, '??0?$bucket_array@V?$allocator@' + SI, []),
    (0x4ca090, '?calculate_max_load@?$hashed_index@U?$member@' + SI, []),
    (0x4ccab0, '??1?$multi_index_container@' + SI, []),
    (0x4cc460, '?delete_all_nodes_@?$hashed_index@U?$member@' + SI, []),
    # InterpolatingPhysicsReceiver
    (0x4b5e80, '??0' + IR + 'QAE@PAVReplicator@12@@Z', []),
    (0x4b6290, '??_G' + IR + 'UAEPAXI@Z', []),
    (0x4b0ae0, '??0?$multi_index_container@' + RI, []),
    (0x4acc30, '?empty_initialize@?$ordered_index@U?$member@' + RI + 'I$07@', []),
    (0x4cb540, '??0?$bucket_array@V?$allocator@' + RI, []),
    (0x4ca090, '?calculate_max_load@?$hashed_index@U?$member@' + RI, []),
    (0x4b58f0, '??1?$multi_index_container@' + RI, []),
    (0x4b43c0, '?delete_all_nodes_@?$hashed_index@U?$member@' + RI, []),
    (0x4af950, '??1PartItem@' + IR + 'QAE@XZ', []),
    (0x4ae910, '??1History@' + IR + 'QAE@XZ', []),
    # std templates reached by bucket_array (identical-code folded in the original)
    (0x4acf00, '??$_Lower_bound@PBIIH@std@@', []),
    (0x420b50, '??$_Allocate@Uhashed_index_node_impl@detail@multi_index@boost@@@std@@', []),
]

functions = [n for n, b, r in match.coff_functions(unit_obj.read_bytes()) if not nb.LOCAL_EH.match(n)]
ROWS = []
for address, prefix, contains in SPECS:
    hits = [n for n in functions if n.startswith(prefix) and all(c in n for c in contains)]
    assert len(hits) == 1, (hex(address), prefix, hits)
    ROWS.append((address, hits[0]))
assert len({s for a, s in ROWS}) == len(ROWS)

# Externals: the address the original instruction uses.
REAL_2_32 = '__real@4f800000'
EXTERNAL = {
    '??3@YAXPAX@Z': 0x6a067a,                                       # operator delete (004ccdf0, 004b62a3, 004cc4b7)
    '??2@YAPAXI@Z': 0x6a0920,                                       # operator new (004cc41f, 004b0b04)
    '??1scoped_connection@signals@boost@@QAE@XZ': 0x5954b0,         # 004ccbbf, 004ccbcc
    '??_M@YGXPAXIHP6EX0@Z@Z': 0x6a165b,                             # eh vector destructor iterator (004af982)
    REAL_2_32: 0x819778,                                            # 2^32 (004ca09d unsigned fild correction)
}
# The prime table of bucket_array_base (DIR32 in 004cb54e / 004cb553 / 004cb564): the original pushes 00824988 and
# 008249f8 = its end; the static is bound to its start.
raw_unit = unit_obj.read_bytes()
_, unit_symbols, unit_definitions, _ = match._coff_data_index(raw_unit)
prime_names = sorted({s[0] for s in unit_symbols.values() if s[0].startswith('?prime_list@') and 'next_prime@bucket_array_base@' in s[0]})
assert len(prime_names) == 1, prime_names
EXTERNAL[prime_names[0]] = 0x824988
# Verify the folded data the externals name: the 2^32 constant and the prime table (first primes 53, 97, ...; 28
# entries ending 4294967291).
assert original.data(0x819778, 4) == struct.pack('<f', 4294967296.0)
primes = struct.unpack('<28I', original.data(0x824988, 0x70))
assert primes[:3] == (53, 97, 193) and primes[-1] == 4294967291, primes

# std::_Allocate throws bad_alloc (00420b94 pushes the throw info 008d07d8): its catchable type array names
# bad_alloc then exception.
EXTERNAL['__TI2?AVbad_alloc@std@@'] = 0x8d07d8
catchable = d(0x8d07d8 + 12)
assert [original.string(d(d(catchable + 4 + 4 * i) + 4) + 8) for i in range(d(catchable))] == [
    '.?AVbad_alloc@std@@', '.?AVexception@std@@']

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
    '?step@' + PS + 'UAEXXZ': 0x4cd920,
    '?sendPackets@' + PS + 'UAEHH@Z': 0x4cce00,
    '?step@' + IR + 'UAEXI@Z': 0x4c8fa0,
    '?receivePacket@' + IR + 'UAEXAAVBitStream@RakNet@@I@Z': 0x4c9120,
}
VTABLES = {'??_7' + PS + '6B@': (0x826928, '.?AV' + PS), '??_7' + IR + '6B@': (0x824ee4, '.?AV' + IR)}
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

# ---- owner allocation sizes (Replicator constructor 004b9bd0) and header node sizes -------------------------
body, _, _ = match.target('2008-06', '004b9bd0')
at = lambda a: body[a - 0x4b9bd0:]
assert at(0x4ba094)[:2] == b'\x6a\x74'                                  # new(0x74) PhysicsSender
assert at(0x4ba0e8)[:2] == b'\x6a\x3c'                                  # new(0x3c) InterpolatingPhysicsReceiver
assert match.target('2008-06', '004cc400')[0][0x19:0x1b] == b'\x6a\x78'   # sender header node new(0x78)
assert match.target('2008-06', '004b0ae0')[0][0x1b:0x20] == b'\x68' + struct.pack('<I', 0x298)  # receiver node

NOT_EXACT = [
    ('004cd920', 'PhysicsSender::step (921 bytes): needs the native Replicator (+0x3c use), '
                 'ServiceProvider::create<PhysicsService> 004cd8d0, the static signal 0097abec connect 004a3340 '
                 'and the item update 004c9e30; declared only, bound through vtable 00826928 slot 1.'),
    ('004cce00', 'PhysicsSender::sendPackets (BitStream packet build, item copy 004c9d90, Replicator API); declared '
                 'only, bound through vtable slot 2.'),
    ('004c8fa0', 'InterpolatingPhysicsReceiver::step (iterates items, 004c6f70 interpolation; World/Clump/MotorJoint '
                 'API); declared only, bound through vtable 00824ee4 slot 1.'),
    ('004c9120', 'InterpolatingPhysicsReceiver::receivePacket (Replicator / IdSerializer deserialize 004a8b60); '
                 'declared only, bound through vtable slot 2.'),
]

sha = nb.sha
paths = [Path(__file__).resolve(), UNIT, LAYOUT] + HEADERS
exact_addresses = sorted({r['address'] for r in rows})
receipt = {
    'class': 'RBX::Network::PhysicsSender, RBX::Network::InterpolatingPhysicsReceiver',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'unit': unit_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, unit_obj)},
    'layout': 'PhysicsSender 0x74 (items multi_index_container +4 [hashed_unique part, ordered_non_unique priority '
              'greater<double>, ordered_non_unique int +0x44], index-1 iterator +0x38, replicator +0x3c, step count '
              '+0x40, shared_ptr<PhysicsService> +0x44, scoped_connection +0x4c/+0x60; PartItem 0x50); '
              'InterpolatingPhysicsReceiver 0x3c (replicator +4, items +8 [hashed_unique part, ordered_non_unique '
              'unsigned +8]; PartItem 0x280 with History[8] of 0x4c at +0x20).',
    'methods': rows, 'not_exact': NOT_EXACT, 'vtables': vtables, 'proposals': [],
    'exact_distinct_addresses': exact_addresses,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit. The four '
             'slot bodies need the native Replicator and remain open.',
}
(ROOT / 'work/2008-06/shared-layouts/network-physics-senders2008-working.json').write_text(
    json.dumps(receipt, indent=2) + '\n')
print('PASS native Network PhysicsSender/InterpolatingPhysicsReceiver: %d exact rows (%d distinct addresses), '
      '%d not-exact; %d vtables; targets verified' % (len(rows), len(exact_addresses), len(NOT_EXACT), len(vtables)))
