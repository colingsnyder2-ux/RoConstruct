"""Verify the inactive 2008-06 native rows of the application range 004c8000..004d4000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map`; rows counted by other receipts in
`range_rows_counted_by_other_receipts`):
  * 004c8010..004c978f  the physics-replication receiver unit continued from 004bc000..004c8000 (its rows are built
    and counted by native-classes/AppUnit4BC_2008Receiver.cpp / app-unit4bc-2008-working.json).
  * 004c9790..004c992f  RakNet GetTime.cpp (GetTimeNS / GetTime): library code.
  * 004c9930..004cdcbf  the physics-replication sender unit: RoundRobinPhysicsSender (network-physics-working.json),
    the PhysicsSender container members (network-physics-senders2008-working.json), ServiceProvider::create<
    PhysicsService>(const Instance*) 004cd8d0 (built here), PhysicsSender::step 004cd920.
  * 004cdcc0..004d4000  RakNet 3.x HuffmanEncodingTree.cpp, SocketLayer.cpp, ReliabilityLayer.cpp and their
    DataStructures template instances (library code, never recovered here).

Build (document-swap flags, VS2008 RTM 21022): native-classes/AppUnit4C8_2008PhysicsServiceCreate.cpp against the
committed native headers only (no pending build). Every counted row is relocation-masked exact against the original
and every REL32/DIR32 target is bound to the address the original instruction uses and verified (native_bind.verify):
imports by DLL export name, type descriptors by RTTI name, the member create<PhysicsService>() const by the receipt that
counts it (its symbol is checked there). A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit4c8-2008-working.json.
"""
import glob
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = R / 'out/app-unit4c8-2008'
OUT.mkdir(parents=True, exist_ok=True)
UNIT = R / 'native-classes/AppUnit4C8_2008PhysicsServiceCreate.cpp'
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit4c8-2008-working.json'
LO, HI = 0x4c8000, 0x4d4000


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


obj, flags = build('NativeAppUnit4C8_2008PhysicsServiceCreate', UNIT)
original = nb.Original()

ROWS = [
    (0x4cd8d0, '??$create@VPhysicsService@RBX@@@ServiceProvider@RBX@@SAPAVPhysicsService@1@PBVInstance@1@@Z'),
]
functions = {n for n, b, r in match.coff_functions(obj.read_bytes())}
for address, symbol in ROWS:
    assert symbol in functions, (hex(address), symbol)

# The member create<PhysicsService>() const the row tail-jumps to (004cd90c): counted, with the same symbol, by
# world-service-actions-secure-trial.json.
MEMBER = '??$create@VPhysicsService@RBX@@@ServiceProvider@RBX@@QBEPAVPhysicsService@1@XZ'
trial = json.loads((ROOT / 'work/2008-06/shared-layouts/world-service-actions-secure-trial.json').read_text())


def find_row(o, address):
    if isinstance(o, dict):
        if o.get('address') == address:
            return o
        o = list(o.values())
    if isinstance(o, list):
        for e in o:
            hit = find_row(e, address)
            if hit:
                return hit
    return None


member_row = find_row(trial, '004cd7e0')
assert member_row and member_row.get('symbol') == MEMBER and member_row.get('exact') is True, member_row
EXTERNAL = {MEMBER: 0x4cd7e0}

rows = nb.verify(original, obj, [(s, a) for a, s in ROWS], EXTERNAL)
for row in rows:
    row['verified_targets'][MEMBER] += ' (row counted by world-service-actions-secure-trial.json)'


def counted_elsewhere():
    out = {}
    for path in glob.glob(str(ROOT / 'work/2008-06/shared-layouts/*.json')):
        if Path(path).name == RECEIPT.name:
            continue
        try:
            data = json.loads(Path(path).read_text())
        except Exception:
            continue
        if not isinstance(data, dict):
            continue
        rows_ = []
        for key in ('exact_function_rows', 'exact_addresses', 'exact_unique_addresses', 'exact_distinct_addresses'):
            if isinstance(data.get(key), (list, dict)):
                rows_ = list(data[key])
                break
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        rows_.append(o['address'])
                    else:
                        for v in o.values():
                            walk(v)
            walk(data.get('methods', []))
        for r in rows_:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
exact_rows = sorted({r['address'] for r in rows})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '%08x' % LO <= a < '%08x' % HI}

UNIT_MAP = {
    'physics-receiver (continued) 004c8010..004c978f': (
        'Continues the receiver unit of 004bc000..004c8000. Receiver index internals: ordered modify_ 004c8010 '
        '(in_place 004c71d0, rebalance_for_erase 004c69e0, link_point 004c7110, ~PartItem 004af950, rethrow; only '
        'caller the hashed modify_ 004c8b70 at 004c8c30), index_base / ordered / hashed insert_(value, node) '
        '004c8b20 / 004c8cf0 / 004c8e40 (counted by app-unit4bc-2008), hashed modify_ 004c8b70 (only caller '
        '004c8da0), 004c8da0 (ret 0x14, calls a modifier through [ebp+8], then modify_; called from receivePacket '
        '004c966e), container insert_(value) 004c8ef0 (new, hashed insert_ 004c8e40, delete on failure; called from '
        '004c96ce), the BitStream item reader 004c8150 (called from 004c964c), DirectPhysicsReceiver::receivePacket '
        '004c83b0 (vtable 008247d0 slot 2), InterpolatingPhysicsReceiver::step 004c8fa0 and receivePacket 004c9120 '
        '(vtable 00824ee4 slots 1/2; receivePacket ends 004c9789).'),
    'raknet-gettime 004c9790..004c992f': (
        'RakNet GetTime.cpp: GetTimeNS 004c9790 (QueryPerformanceFrequency / GetProcessAffinityMask / '
        'QueryPerformanceCounter, evidence name ?GetTimeNS@RakNet@@YA_JXZ) and GetTime 004c9910 '
        '(?GetTime@RakNet@@YAIXZ). Library code, not recovered.'),
    'physics-sender 004c9930..004cdcbf': (
        'boost ordered_index_node_impl::restore 004c9930 (library; called by the sender ordered replace_ 004cb8e0 / '
        '004cbfb0), RoundRobinPhysicsSender 004c99b0 / 004c99c0 / ??_G 004ca010 (network-physics-working.json), the '
        'PhysicsSender PartItems members 004c9b20..004cc5e0 (network-physics-senders2008-working.json: link, '
        'link_point, in_place, insert_, erase_, unchecked_rehash, reserve, PartItem copy / operator=), hash_value '
        '004ca5b0, PhysicsSender ctor / dtor 004ccb10 / 004ccb90, sendPackets 004cce00, PhysicsService members '
        '004cd5b0..004cd7e0 (physics-array / world-service trials), ServiceProvider::create<PhysicsService>(const '
        'Instance*) 004cd8d0 (this receipt), PhysicsSender::step 004cd920 (ends 004cdcb8).'),
    'raknet 004cdcc0..004d4000': (
        'RakNet 3.x library: HuffmanEncodingTree.cpp 004cdcc0..004ce2df (DecodeArray, FreeMemory, EncodeArray, '
        'GenerateFromFrequencyTable, CircularLinkedList / Queue instances), SocketLayer.cpp 004ce570..004ce97f '
        '(CreateBoundSocket ... GetLocalPort), ReliabilityLayer.cpp from 004ce9a0 (SplitPacketIndexComp, '
        'InitializeVariables, SendBitStream, BPlusTree / MemoryPool / RangeList / OrderedList instances, '
        'GenerateDatagram 004d19f0, InsertIntoSplitPacketList 004d2020 ...) running past 004d4000. Evidence names '
        'cover nearly every row. Library code: never recovered here (recipes rbxgs-raknet, raknet-4.081).'),
}

NOT_EXACT = [
    {'address': '004c8010', 'reason': 'receiver ordered_index::modify_: not emitted by the explicit container '
     'instantiation (only modify<Modifier> instantiates it, and the modifier type is not derived; see 004c8da0).'},
    {'address': '004c8b70', 'reason': 'receiver hashed_index::modify_: same blocker as 004c8010.'},
    {'address': '004c8da0', 'reason': 'modify(iterator, Modifier) helper (ret 0x14, the modifier is called through '
     'its first argument): the modifier type used by receivePacket 004c9120 is not derived.'},
    {'address': '004c8ef0', 'reason': 'receiver multi_index_container::insert_(const value_type&): 151 B original, '
     '172 B from the explicit instantiation; not derived.'},
    {'address': '004c8150', 'reason': 'receivePacket item reader (BitStream ReadNormQuat / Vector3 reads): needs '
     'the native Replicator / BitStream API; open.'},
    {'address': '004c83b0', 'reason': 'DirectPhysicsReceiver::receivePacket (1890 B): needs the native Replicator / '
     'IdSerializer API; open (network-physics receipt).'},
    {'address': '004c8fa0', 'reason': 'InterpolatingPhysicsReceiver::step: calls the PartItem step helper 004c6f70, '
     'which needs the 2008 PartInstance with the Primitive embedded at +0x228 (app-unit4bc-2008 not_exact).'},
    {'address': '004c9120', 'reason': 'InterpolatingPhysicsReceiver::receivePacket (1641 B): needs the native '
     'Replicator / IdSerializer deserialize 004a8b60 and the modifier of 004c8da0; open.'},
    {'address': '004cd920', 'reason': 'PhysicsSender::step (921 B): needs the native Replicator and the item update '
     '004c9e30 (PartInstance getCoordinateFrame 00598cb0); open (network-physics-senders2008 not_exact).'},
]

paths = [Path(__file__).resolve(), UNIT]
receipt = {
    'class': 'RBX rows of the application range 004c8000..004d4000 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': flags,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'objects': {obj.name: nb.sha(obj)},
    'unit_map': UNIT_MAP,
    'range_rows_counted_by_other_receipts': range_counted,
    'rows': rows,
    'not_exact': NOT_EXACT,
    'rejected': {},
    'proposals': [],
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit4c8-2008: %d counted exact rows (%s); %d range rows counted by other receipts; %d not exact'
      % (len(exact_rows), ' '.join(exact_rows), len(range_counted), len(NOT_EXACT)))
