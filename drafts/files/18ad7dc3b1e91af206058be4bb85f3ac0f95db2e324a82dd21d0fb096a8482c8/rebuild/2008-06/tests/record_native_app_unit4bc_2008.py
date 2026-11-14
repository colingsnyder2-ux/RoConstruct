"""Verify the inactive 2008-06 native rows of the application range 004bc000..004c8000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map`; rows counted by other receipts in `range_rows_counted_by_other_receipts`):
  * RakNet 3.x (RakPeer.cpp with its DataStructures template instances) from before 004bc000 to 004c65c0: library code,
    never recovered here.
  * boost 1.34.1 multi_index ordered_index_node_impl helpers 004c66c0..004c69e0 (shared by the sender and receiver
    containers; library code), the ICF-shared checked vector subscript 004c6ce0 and the unreferenced 004c6d10.
  * The physics-replication receiver unit from 004c6d30 (continues past 004c8000 to the receiver's step 004c8fa0 /
    receivePacket 004c9120 and the DirectPhysicsReceiver packet handler 004c83b0): Association<Instance> Item /
    TItem<TimeStamp> members, InterpolatingPhysicsReceiver::PartItem helpers and the receiver's multi_index_container
    instances. Built here: native-classes/AppUnit4BC_2008Receiver.cpp against the read-only Network/PhysicsSenders2008.h
    and the new AppUnit4BC_2008/AssociationTimeStamp.h.

Build (document-swap flags, VS2008 RTM 21022, /fp:fast): the unit against the committed native headers only (counted
rows and the vtable slot checks). Batch 21 applied the batch-20 proposals to Network/PhysicsSenders2008.h (now in this
lease): boost::hash<shared_ptr<PartInstance> > with the out-of-line hash_value 004ca5b0 and the user-declared
PartItem(const shared_ptr<PartInstance>&) 004c7a10, so there is no pending build any more. The receiver unit continues
past 004c8000; its index rows there (insert_ 004c8b20 / 004c8cf0 / 004c8e40) are counted here, the rest of that range is
mapped by tests/record_native_app_unit4c8_2008.py.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, vtables by original RTTI names,
constants by bytes, own symbols by the row proven here, support bodies by exactness at the bound address, the
remaining externals by the EXTERNAL map (call sites read in the original), local statics by one address per symbol.
A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit4bc-2008-working.json.
Set NATIVE_APP_UNIT4BC_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
"""
import glob
import json
import os
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = R / 'out/app-unit4bc-2008'
OUT.mkdir(parents=True, exist_ok=True)
UNIT = R / 'native-classes/AppUnit4BC_2008Receiver.cpp'
HEADERS = [R / 'native-headers/AppUnit4BC_2008/AssociationTimeStamp.h', R / 'native-headers/Network/PhysicsSenders2008.h',
           R / 'native-headers/Network/PhysicsReplication.h']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT4BC_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit4bc-2008-working.json'
UNIT_FLAGS = ['/fp:fast']

def build(name, extra=(), include=()):
    obj = OUT / (name + '.obj')
    flags = ['/I' + str(p) for p in include] + nb.flags() + list(extra) + ['/Fo' + str(obj), str(UNIT)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['cur'], FLAGS['cur'] = build('NativeAppUnit4BC_2008_cur', UNIT_FLAGS)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

AI = 'Association@VInstance@RBX@@@RBX@@'
IR = 'InterpolatingPhysicsReceiver@Network@RBX@@'
RI = 'UPartItem@' + IR
HASHED = '@?$hashed_index@U?$member@' + RI
ORDERED = '@?$ordered_index@U?$member@' + RI + 'I$07@'
VF = '?$vector@MV?$allocator@M@std@@@std@@'
TWO_ARG = 'ABUPartItem@' + IR + 'PAU5234@@Z'   # insert_(const value_type&, node*), not the hinted overload

# (address, symbol or unique prefix): one entry per counted address (current-header build)
ROWS = [
    (0x4c6d30, '??1Item@?$' + AI + 'UAE@XZ'),
    (0x4c7090, '??_GItem@?$' + AI + 'UAEPAXI@Z'),
    (0x4c70b0, '?link_point' + HASHED),
    (0x4c70f0, '?first_nonempty@?$bucket_array@V?$allocator@' + RI),
    (0x4c7110, '?link_point' + ORDERED),
    (0x4c71d0, '?in_place' + ORDERED),
    (0x4c77b0, '??0' + VF + 'QAE@ABV01@@Z'),
    (0x4c7c10, '??0History@' + IR + 'QAE@ABU0123@@Z'),
    (0x4c7dd0, '??0PartItem@' + IR + 'QAE@ABU0123@@Z'),
    (0x4c7e80, '?erase_' + ORDERED),
    (0x4c7ef0, '??$get@UTimeStamp@@@?$' + AI + 'QAEAAUTimeStamp@@XZ'),
    # boost::hash<shared_ptr<PartInstance> > with the out-of-line hash_value 004ca5b0 (batch 21 header change)
    (0x4c72b0, '??$find@V?$shared_ptr@VPartInstance@RBX@@@boost@@U?$hash@'),
    (0x4c7330, '?unchecked_rehash' + HASHED),
    (0x4c7730, '?reserve' + HASHED),
    # the user-declared PartItem(const shared_ptr<PartInstance>&) 004c7a10 and the implicit History() it reaches
    (0x4c76a0, '??0History@' + IR + 'QAE@XZ'),
    (0x4c7a10, '??0PartItem@' + IR + 'QAE@ABV?$shared_ptr@VPartInstance@RBX@@@boost@@@Z'),
    # receiver insert path past 004c8000 (receivePacket 004c9120 inserts new PartItems): the two-argument insert_
    # (value, node) of index_base / the ordered index / the hashed index (hash_value call 004c8e60)
    (0x4c8b20, ('?insert_@?$index_base@' + RI, TWO_ARG)),
    (0x4c8cf0, ('?insert_' + ORDERED, TWO_ARG)),
    (0x4c8e40, ('?insert_' + HASHED, TWO_ARG)),
]
# identical-code-folded symbols of counted rows (bound to the same address, not counted twice)
FOLDED = [
    (0x4c7090, '??_G?$TItem@UTimeStamp@@@?$' + AI + 'UAEPAXI@Z'),
]

# ---- externals: address the original instruction uses (call site in parentheses) ----------------------------------
EXTERNAL = {
    '??2@YAPAXI@Z': 0x6a0920,                                                 # operator new (004c7fd5, 004c76c7)
    '??3@YAXPAX@Z': 0x6a067a,                                                 # operator delete (004c70a1)
    '??0CoordinateFrame@G3D@@QAE@XZ': 0x4782d0,                               # History() 004c76bd (evidence name)
    # History(const&) 004c7c28: the compiled implicit copy calls the Matrix3 copy constructor; the original calls
    # 00513220, whose evidence name is the identical-code-folded Matrix3::operator= (same body).
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,
    '??1History@' + IR + 'QAE@XZ': 0x4ae910,                                  # 004c7a4f / 004c7e14 (network-physics-senders2008 row)
    '??1PartItem@' + IR + 'QAE@XZ': 0x4af950,                                 # erase_ 004c7ec3 (network-physics-senders2008 row)
    '??_L@YGXPAXIHP6EX0@Z1@Z': 0x6a1598,                                     # eh vector constructor iterator (004c7a6e)
    '??__C@YGXPAX0IHP6EX00@ZP6EX0@Z@Z': 0x6a1bb6,                             # eh vector copy constructor iterator (004c7e41)
    # find 004c72ba, unchecked_rehash 004c73e5, insert_ 004c8e60 (row counted by network-physics-senders2008, which
    # builds the definition; its bytes are also checked below)
    '?hash_value@RBX@@YAIABV?$shared_ptr@VPartInstance@RBX@@@boost@@@Z': 0x4ca5b0,
    '__real@4f800000': 0x819778,                                              # 2^32 (reserve 004c7751; checked by bytes)
}
# Bodies emitted in the unit whose original address is a row counted by another receipt (ICF-shared COMDATs): bound by
# the call site and accepted only when the compiled body is relocation-masked exact at that address (no recursion: the
# owning receipt verifies their targets). Keys are symbol prefixes.
COUNTED_ELSEWHERE = {
    '?_Xlen@': (0x4c6d40, 'humanoid2008 / misc-leaves'),                     # vector copy ctor 004c77e5, get 004c7c7f
    '?insert@?$vector@PAVItem@?$' + AI: (0x4c7c60, 'humanoid2008'),         # get<TimeStamp> 004c7f8b (vector<const Primitive*> ICF)
    '??$_Allocate@': (0x420b50, 'network-physics-senders2008'),              # vector copy ctor 004c77f3, rehash 004c739f
    '??0?$bucket_array@V?$allocator@' + RI: (0x4cb540, 'network-physics-senders2008'),  # rehash 004c737e
}
# Library bodies (boost ordered_index_node_impl, not instantiated on RBX types) emitted in the unit: accepted only when
# relocation-masked exact at the bound address, with their own targets bound recursively; support rows, never counted.
SUPPORT = {
    '?increment@ordered_index_node_impl@detail@multi_index@boost@@SAXAAPAU1234@@Z': 0x4c66c0,     # in_place 004c71e0
    '?decrement@ordered_index_node_impl@detail@multi_index@boost@@SAXAAPAU1234@@Z': 0x4c6710,     # in_place 004c721a
    '?rebalance_for_erase@ordered_index_node_impl@detail@multi_index@boost@@': 0x4c69e0,         # erase_ 004c7eb? (ordered)
    '?rotate_left@ordered_index_node_impl@detail@multi_index@boost@@': 0x4c6770,                 # rebalance_for_erase
    '?rotate_right@ordered_index_node_impl@detail@multi_index@boost@@': 0x4c67f0,                # rebalance_for_erase
    '?rebalance@ordered_index_node_impl@detail@multi_index@boost@@SAXPAU': 0x4c6870,             # link 004c6980
    '?link@ordered_index_node_impl@detail@multi_index@boost@@': 0x4c6980,                        # ordered insert_
}
SUPPORT_PREFIX = {}
LOCAL_STATIC_AT = {
    # Association<Instance>::count() (shared with other get<T> instances: 005aaeaa ...)
    '?c@?1??count@?$' + AI + 'CAAAIXZ@4IA': 0x971a80,
}
LOCAL_STATIC = re.compile(r'^(\?\$S\d+@|\?\w+@\?\d+\?\?|\?\?_B\?\d+\?\?)')
VTABLES = {
    '??_7Item@?$' + AI + '6B@': (0x8265e4, '.?AVItem@?$' + AI),
    '??_7?$TItem@UTimeStamp@@@?$' + AI + '6B@': (0x8265ec, '.?AV?$TItem@UTimeStamp@@@?$' + AI),
}
UNBOUND = []
binding = {}
support_out = {}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        key, contains = key if isinstance(key, tuple) else (key, '')
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and contains in x[0]
                                                      and not nb.LOCAL_EH.match(x[0])]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:120] for h in hits])
            continue
        assert len(hits) == 1, ('%08x' % address, key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def support_address(symbol):
    for prefix, value in SUPPORT.items():
        if symbol.startswith(prefix):
            return value
    return None


def counted_address(symbol):
    for prefix, value in COUNTED_ELSEWHERE.items():
        if symbol.startswith(prefix):
            return value
    return None


def bind_value(raw, sections, symbols, definitions, bodies, name, body, target, address, own, record=True, depth=0):
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
        sup = support_address(symbol)
        other = counted_address(symbol)
        if hit is not None:
            assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
            how = '%s!%s' % hit
        elif symbol.startswith('__real@'):
            assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
            how = 'constant %s' % symbol[7:]
        elif symbol in own:
            assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
            how = 'own row'
        elif symbol in VTABLES:
            vt, rtti = VTABLES[symbol]
            assert vt == value and original.vtable_class(vt) == (rtti, 0), (name, symbol, hex(value))
            how = 'vtable by RTTI %s' % rtti
        elif other is not None:
            assert other[0] == value, (name, symbol, hex(value), hex(other[0]))
            sbody, srefs = bodies[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('counted-elsewhere body not exact', symbol, hex(value))
            how = 'body exact at the bound address; row counted by %s' % other[1]
        elif sup is not None:
            assert sup == value, (name, symbol, hex(value), hex(sup))
            sbody, srefs = bodies[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('support body not exact', symbol, hex(value))
            if depth < 3:
                sv, _ = bind_value(raw, sections, symbols, definitions, bodies, symbol, sbody, starget, value, own,
                                   record, depth + 1)
                support_out.setdefault(symbol, {'address': '%08x' % value, 'verified_targets': sv})
            how = 'support body exact at the bound address'
        elif symbol.startswith('?prime_list@') and 'next_prime@bucket_array_base@' in symbol:
            assert value == 0x824988, (name, symbol, hex(value))
            how = 'boost prime table (checked by bytes)'
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
        elif LOCAL_STATIC.match(symbol) and symbol in LOCAL_STATIC_AT:
            assert LOCAL_STATIC_AT[symbol] == value, (name, symbol, hex(value), hex(LOCAL_STATIC_AT[symbol]))
            how = 'local static'
        elif LOCAL_STATIC.match(symbol) and '?1???$get@UTimeStamp@@' in symbol:
            # the index static of get<TimeStamp> (value 00971a84) and its guard (00971a88): one address per symbol
            how = 'local static (get<TimeStamp> index)'
            expected = 0x971a88 if symbol.startswith('?$S') else 0x971a84
            assert value == expected, (name, symbol, hex(value), hex(expected))
        else:
            UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        if record:
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


def verify(which, rows, own, strict=True, record=True):
    raw = Path(OBJ[which]).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict or DISCOVER, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        verified, local = bind_value(raw, sections, symbols, definitions, bodies, name, body, target, address, own, record)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


# Data the externals name, checked by bytes: the boost prime table (53, 97, 193 ... 4294967291) and the 2^32 constant.
primes = struct.unpack('<28I', original.data(0x824988, 0x70))
assert primes[:3] == (53, 97, 193) and primes[-1] == 4294967291, primes
assert original.data(0x819778, 4) == struct.pack('<f', 4294967296.0)
# The out-of-line hash find / unchecked_rehash / insert_ call: 004ca5b0 is `return p + (p >> 3)` of the shared_ptr's pointer (cdecl).
assert target_of(0x4ca5b0)[0] == bytes.fromhex('8b4424048b088bc1c1e80303c1c3'), target_of(0x4ca5b0)[0].hex()

cur_rows = resolve(OBJ['cur'], ROWS)
folded_rows = resolve(OBJ['cur'], FOLDED)
own = {}
for address, name in cur_rows + folded_rows:
    own.setdefault(name, address)
counted = verify('cur', cur_rows, own)
folded = verify('cur', folded_rows, own)
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for r in counted + folded:
        if not r['exact']:
            print('NOT EXACT', r['address'], r['symbol'][:90], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, UNBOUND
assert all(r['exact'] for r in counted + folded)

# ---- vtables (current-header object) ----------------------------------------------------------------------------
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


vtables = []
for symbol, (vt, rtti) in VTABLES.items():
    assert original.vtable_class(vt) == (rtti, 0), (hex(vt), original.vtable_class(vt))
    slots = vtable_slots(OBJ['cur'], symbol)
    count = original_slots(vt)
    assert len(slots) == count == 1, (symbol, slots, count)
    entries = {}
    for slot, name in sorted(slots.items()):
        value = d(vt + 4 * slot)
        assert name.startswith('??_E') and own.get('??_G' + name[4:]) == value, (symbol, slot, name, hex(value))
        entries[slot] = '%s -> %s (own row ??_G)' % (name, hex(value))
    vtables.append({'vtable': hex(vt), 'symbol': symbol, 'rtti': rtti, 'original_slots': count, 'slots': entries})


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
        rows = []
        if 'exact_function_rows' in data:
            rows = data['exact_function_rows']
        elif isinstance(data.get('exact_addresses'), list):
            rows = data['exact_addresses']
        elif isinstance(data.get('exact_unique_addresses'), list):
            rows = data['exact_unique_addresses']
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        rows.append(o['address'])
                    else:
                        for v in o.values():
                            walk(v)
            walk(data.get('methods', []))
        if isinstance(rows, dict):
            rows = list(rows)
        for r in rows:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
exact_rows = sorted({r['address'] for r in counted})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '004bc000' <= a < '004c8000'}

UNIT_MAP = {
    'raknet ..004c66bf': (
        'RakNet 3.x RakPeer.cpp and the DataStructures templates it instantiates (List, Queue, OrderedList, '
        'BPlusTree, MemoryPool; BitStream calls 004a5050 ?Read<bool>@BitStream@RakNet, 004a50c0..004a5790), from '
        'before 004bc000 (RakPeerInterface/RakPeer members 004bb550..004bbf90) to 004c65c0 (243 B, the network '
        'simulator / ReliabilityLayer at RakPeer +0x744, vtable refs 008245d4/008264b4). Strings: "[UNKNOWN]" '
        '004c1db0, "127.0.0.1" / "0.0.0.0" 004c3c80. Library code: never recovered here (recipes rbxgs-raknet, '
        'raknet-4.081 in roc/libs.py).'),
    'multi-index-node-impl 004c66c0..004c6cdf': (
        'boost 1.34.1 multi_index ordered_index_node_impl helpers (non-template on RBX types): 004c66c0 / 004c6710 '
        '(rotate), 004c6770 / 004c67f0, 004c6870, 004c6980 (link), 004c69e0 (rebalance_for_erase, 762 B); called '
        'by both the sender (004cae60, 004caf40, 004cb8e0, 004cbfb0, 004ccc30) and the receiver (004c71d0, '
        '004c7e80, 004c8010, 004c8fa0) containers. Library code, not recovered.'),
    'shared 004c6ce0..004c6d2f': (
        '004c6ce0 (38 B) checked vector<T*> subscript at +0xc, ICF-shared by other units (callers 004b8c20, '
        '00549610, 00549a50): not attributed. 004c6d10 (17 B, `if (+4) delete(+8)`) has no code or data reference: '
        'not attributed.'),
    'physics-receiver 004c6d30..(004c9790)': (
        'Association<Instance>::Item::~Item 004c6d30 (vtable 008265e4), the PartItem helpers 004c6dc0 (interpolate '
        'two History entries: CoordinateFrame lerp 00518a50, then motor angles), 004c6ed0 (apply one History), '
        '004c6f70 (per-item step; only caller the receiver step 004c8fa0), Item ??_G 004c7090 (slot 0 of 008265e4 and '
        'of TItem<TimeStamp> 008265ec), the receiver multi_index instances 004c70b0..004c7330 / 004c7730 / 004c7e80, '
        'shared_from_polymorphic_downcast<Stats::Item, Instance> 004c7530 (COMDAT shared with 0049d770 / 004b5700 / '
        '004b82d0: not counted here), History() 004c76a0 / History(const&) 004c7c10, std::vector<float> instances '
        '004c7700 (_Ufill), 004c71b0 (fill), 004c77b0 (copy ctor), 004c7a90 (_Insert_n, ICF-shared with 00679120), '
        '004c7d20 / 004c7e60 (resize, shared with 0067fd60 / 00549a50), PartItem(const shared_ptr&) 004c7a10, '
        'PartItem(const&) 004c7dd0, vector<Item*> 004c7890 / 004c7c60 (ICF with vector<const Primitive*>, counted by '
        'humanoid2008), Association<Instance>::get<TimeStamp> 004c7ef0 (282 B, ends 004c800a). The unit continues '
        'past 004c8000: 004c8010..004c8e40 receiver index internals, DirectPhysicsReceiver::receivePacket 004c83b0, '
        'InterpolatingPhysicsReceiver::step 004c8fa0 / receivePacket 004c9120 (outside this range).'),
}

NOT_EXACT = [
    {'address': '004c6dc0', 'reason': 'PartItem helper (interpolate two History entries, ret 0xc). Not built: '
     'the body reaches the part\'s embedded Primitive at PartInstance +0x228 (`lea ecx, [edi + 0x228]` before '
     'getAssembly 005e7570); the native v8datamodel/PartInstance.h getPrimitive() returns primitive.get(), a load, '
     'and PhysicsSenders2008.h declares no PartItem members. Needs the 2008 PartInstance layout (embedded Primitive, '
     'same blocker as contact-unit2008 / app-unit609) and a PartItem member declaration.'},
    {'address': '004c6ed0', 'reason': 'PartItem helper (apply one History: setCoordinateFrame 005997f0, then '
     'Assembly motors 005e62d0 / 005e6400 / MotorJoint::setCurrentAngle 005e5da0). Not built: same blocker as 004c6dc0.'},
    {'address': '004c6f70', 'reason': 'PartItem per-item step (getDragging 00598d10, history search over the ring '
     '`(head + 8) % 8`, unsigned timestamps with the 2^32 correction 00811240 / 00819778). Not built: same blocker.'},
    {'address': '004c7530', 'reason': 'shared_from_polymorphic_downcast<Stats::Item, Instance>: COMDAT referenced by '
     'other units (0049d770, 004b5700, 004b82d0); not a row of this unit.'},
]

REJECTED = {
    'get<TimeStamp> with one function-local static in get() (`static size_t index = count()++;`)': (
        '256 vs 282 bytes: the original tests the guard again for every loop compare and for the subscript'),
    'get<TimeStamp> with the index helper returning size_t by value': '280 vs 282 bytes (register allocation)',
    'get<TimeStamp> with `while (Index::get() >= items.size())`': 'not exact (operand order)',
    'unit without /fp:fast': 'hashed reserve 004c7730 121 vs 117 B; unchecked_rehash 504 vs 497 B',
    'explicit instantiation of the three-argument hashed_index::find<Key, Hash, Pred>': (
        'C3190 under 21022; the one-argument find<Key> instantiation emits the three-argument body 004c72b0'),
}

PROPOSALS = [
    'Applied in batch 21 (Network/PhysicsSenders2008.h is in this lease now): the receiver and sender containers hash '
    'through boost::hash<shared_ptr<PartInstance> > with the out-of-line RBX::hash_value 004ca5b0 (defined and counted '
    'by NetworkPhysicsSenders2008.cpp), and PartItem(const shared_ptr<PartInstance>&) 004c7a10 is declared.',
    'Open: the PartItem helpers 004c6dc0 / 004c6ed0 / 004c6f70 need PartItem member declarations and the 2008 '
    'PartInstance with the Primitive embedded at +0x228 (owner of v8datamodel/PartInstance.h; same evidence as the '
    'contact-unit2008 / app-unit609 receipts).',
]

paths = [Path(__file__).resolve(), UNIT] + HEADERS
receipt = {
    'class': 'RBX physics-replication receiver rows of the application range 004bc000..004c8000 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'unit_map': UNIT_MAP,
    'range_rows_counted_by_other_receipts': range_counted,
    'rows': counted,
    'folded_rows': folded,
    'pending_rows': [],
    'support_rows': support_out,
    'vtables': vtables,
    'not_exact': NOT_EXACT,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit4bc-2008: %d counted exact rows (%s); 0 pending-build-only, %d not exact, %d support rows, '
      '%d vtables' % (len(exact_rows), ' '.join(exact_rows), len(NOT_EXACT), len(support_out),
                      len(vtables)))
