"""Verify the inactive 2008-06 native rows of the application range 004b8000..004bc000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map` and `unit_map_checks`; rows counted by other receipts in
`range_rows_counted_by_other_receipts`, written as 'ADDR counted by RECEIPT' text, never as quoted bare addresses):
  * Network/Replicator.cpp (starts below 004b0000) up to 004ba22f: Replicator members (stats item setup 004b82d0,
    marker processing 004b8490, NewInstanceItem::write 004b8620, onServiceProvider 004b87f0, the packet processing
    004b8970 / 004b8b60, OnReceive 004b8c20), Marker 004b9140 / newMarker 004b9190, the marker request 004b9210,
    the IdSerializer bases 004b93d0..004b96a0 / 004b9ad0..004b9bb0 (network-replicator receipt), ~Replicator 004b96b0
    with its thunks 004b9a20..004b9ab0 and the Replicator constructor 004b9bd0. Except for the IdSerializer
    waitItems tree instance erase(first, last) 004b8a80, every open row reads Replicator members past +0x2b90 that
    the read-only native-headers/Network/Replicator2008.h does not declare yet (proposal to its owner).
  * RakNet 3.x library code from 004ba230: StringCompressor.cpp with its HuffmanEncodingTree map instances
    004ba230..004ba9d0, PacketLogger.cpp 004baa10..004bb39f (vtable 00825724 .?AVPacketLogger@@) and RakPeer.cpp
    from 004bb3a0 (vtable 00826394 .?AVRakPeerInterface@@), continuing past 004bc000. Library: never counted here.

Build (document-swap flags, VS2008 RTM 21022, RakNet 3.x headers tools/rbxgs/Client/Network/raknet30/Source):
  * templates: native-classes/AppUnit4B8IdSerializerTemplates.cpp, an explicit instantiation of the
    map<Guid::Data, vector<IdSerializer::WaitItem> > tree against the read-only native-headers/Network/IdSerializer.h.
No new header (so no shadowing), no pending build and no class with a vtable (no vtable slot check).

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, COMDAT support bodies by exactness at the bound
address, rows counted by other receipts by that receipt's exact_function_rows. A row is counted only when no other
receipt counts it. Writes work/2008-06/shared-layouts/app-unit4b8-working.json.
Set NATIVE_APP_UNIT4B8_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = R / 'out/app-unit4b8'
OUT.mkdir(parents=True, exist_ok=True)
RAKNET = ROOT / 'tools/rbxgs/Client/Network/raknet30/Source'
SOURCES = {'templates': R / 'native-classes/AppUnit4B8IdSerializerTemplates.cpp'}
HEADERS = [R / 'native-headers/Network/IdSerializer.h']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT4B8_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit4b8-working.json'
LO, HI = 0x4b8000, 0x4bc000


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = ['/I' + str(RAKNET)] + nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build('NativeAppUnit4B8_' + _k, _src)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

W = 'UWaitItem@IdSerializer@Network@RBX@@'
VW = 'V?$vector@' + W + 'V?$allocator@' + W + '@std@@@std@@'
GT = '?$_Tree@V?$_Tmap_traits@UData@Guid@RBX@@' + VW
# (address, symbol prefix, symbol suffix)
TEMPLATE_ROWS = [
    (0x4b8a80, '?erase@' + GT, 'QAE?AViterator@12@Vconst_iterator@12@0@Z'),
]
# COMDAT bodies of the same tree that the counted row calls: exact at the bound address; support rows outside this
# range, never counted here.
SUPPORT_SPEC = [
    (0x4a8d50, '?erase@' + GT, 'QAE?AViterator@12@Vconst_iterator@12@@Z'),
    (0x4b7e10, '?_Erase@' + GT, ''),
]
# ICF-shared bodies counted by other receipts (bound by the call site; the receipt must count the address and this
# build's body must be exact there).
COUNTED_ELSEWHERE_SPEC = [
    (0x68d1a0, '?_Inc@const_iterator@' + GT, '', 'ogre-scene-manager-working.json'),
]
UNBOUND = []
binding = {}
support_out = {}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(funcs, address, prefix, suffix):
    hits = [x[0] for x in funcs if x[0].startswith(prefix) and x[0].endswith(suffix) and not nb.LOCAL_EH.match(x[0])]
    assert len(hits) == 1, ('%08x' % address, prefix[:80], suffix, [h[:160] for h in hits])
    return hits[0]


raw = Path(OBJ['templates']).read_bytes()
FUNCS = match.coff_functions(raw)
BODIES = {n: (b, r) for n, b, r in FUNCS}
ROWS = [(a, resolve(FUNCS, a, p, s)) for a, p, s in TEMPLATE_ROWS]
SUPPORT = {resolve(FUNCS, a, p, s): a for a, p, s in SUPPORT_SPEC}
COUNTED_ELSEWHERE = {resolve(FUNCS, a, p, s): (a, rc) for a, p, s, rc in COUNTED_ELSEWHERE_SPEC}


def bind_value(sections, symbols, definitions, name, body, target, address, own):
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
        elif symbol in SUPPORT:
            assert SUPPORT[symbol] == value, (name, symbol, hex(value), hex(SUPPORT[symbol]))
            sbody, srefs = BODIES[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('support body not exact', symbol, hex(value))
            support_out.setdefault(symbol, {'address': hex(value), 'reached_from': name,
                                            'note': 'COMDAT support body of the same tree, exact at the bound '
                                                    'address (outside this range); not counted'})
            how = 'support body exact at the bound address'
        elif symbol in COUNTED_ELSEWHERE:
            at, receipt = COUNTED_ELSEWHERE[symbol]
            assert at == value, (name, symbol, hex(value), hex(at))
            data = json.loads((ROOT / 'work/2008-06/shared-layouts' / receipt).read_text())
            assert '%08x' % value in data['exact_function_rows'], (symbol, receipt)
            sbody, srefs = BODIES[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('ICF-shared body not exact', symbol, hex(value))
            how = 'ICF-shared row counted by %s (this build exact there)' % receipt
        else:
            UNBOUND.append('    %r: %#x,   # %s in %s' % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        prev = binding.setdefault(symbol, (value, name))
        assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


def verify(rows, own):
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    result = []
    for address, name in rows:
        body, refs = BODIES[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
                 'exact': exact, 'unit': 'templates'}
        if not exact:
            assert DISCOVER, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        verified, local = bind_value(sections, symbols, definitions, name, body, target, address, own)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


counted = verify(ROWS, {name: address for address, name in ROWS})
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for r in counted:
        if not r['exact']:
            print('NOT EXACT', r['address'], r['symbol'][:90], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, UNBOUND
assert all(r['exact'] for r in counted)
# the string dictionary tree of the same header builds identical bytes: 004b8a80's relocations must name the
# Guid::Data tree helpers (checked through the support bindings above)
assert set(SUPPORT) <= set(binding), sorted(set(SUPPORT) - set(binding))


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
            walk({k: v for k, v in data.items() if 'pending' not in k})
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
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '%08x' % LO <= a < '%08x' % HI}
FUNCTIONS = [json.loads(x) for x in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines()]
RANGE_ROWS = sorted(x['addr'] for x in FUNCTIONS if LO <= int(x['addr'], 16) < HI)
assert set(exact_rows) <= set(RANGE_ROWS), sorted(set(exact_rows) - set(RANGE_ROWS))


# ---- unit-map evidence checks (strings, RTTI, evidence names) ------------------------------------------------------
def cstr(a, n=96):
    return original.data(a, n).split(b'\0')[0].decode('latin-1')


MAP_CHECKS = []
for at, want in ((0x8251c8, 'Received marker %d from %s'), (0x8251ec, 'Replication: %s:%s >> %s'),
                 (0x825208, 'Replicator::OnReceive packet %d: %s'), (0x825280, 'Lost connection to %s\n'),
                 (0x8252a0, 'Replicator: Requesting Marker %d of %s'), (0x82444c, 'Replication'),
                 (0x82564c, 'Bits Received'), (0x825614, 'Split Messages Sent'),
                 (0x8257bc, 'ID_READY_EVENT_QUERY'), (0x825fd4, '%sSnd,Raw,NIL,NIL,%s,%i,%i,%u:%i,%u:%i%s')):
    assert cstr(at) == want, (hex(at), cstr(at))
    MAP_CHECKS.append('string %s %r' % (hex(at), want))
for vt, want in ((0x8254fc, '.?AVReplicator@Network@RBX@@'), (0x82529c, '.?AVMarker@Network@RBX@@'),
                 (0x82534c, '.?AVIdSerializer@Network@RBX@@'), (0x825724, '.?AVPacketLogger@@'),
                 (0x826394, '.?AVRakPeerInterface@@')):
    rtti = original.vtable_class(vt)
    assert rtti and rtti[0] == want, (hex(vt), rtti)
    MAP_CHECKS.append('vtable %s RTTI %s' % (hex(vt), want))
for at, want in ((0x4b8620, '?write@NewInstanceItem@Replicator@Network@RBX@@UAEXAAVBitStream@RakNet@@@Z'),
                 (0x4b8c20, '?OnReceive@Replicator@Network@RBX@@UAE?AW4PluginReceiveResult@@PAVRakPeerInterface@@PAUPacket@@@Z'),
                 (0x4b9140, '??0Marker@Network@RBX@@AAE@XZ'),
                 (0x4b9aa0, '??_EReplicator@Network@RBX@@WPJI@AEPAXI@Z')):
    assert names.get(at) == want, (hex(at), names.get(at))
    MAP_CHECKS.append('evidence name %s %s' % (hex(at), want[:70]))
# the RakNet part: the StringCompressor bodies are proven exact as library evidence by app-unit49c-2008, and the
# PacketLogger constructor by app-leaves2008 (bytes equal, not counted there)
for receipt, key, want in (('app-unit49c-2008-working.json', 'library_evidence',
                            '?EncodeString@StringCompressor@@QAEXPBDHPAVBitStream@RakNet@@H@Z'),
                           ('app-unit49c-2008-working.json', 'library_evidence',
                            '?DecodeString@StringCompressor@@QAE_NPADHPAVBitStream@RakNet@@H@Z')):
    data = json.loads((ROOT / 'work/2008-06/shared-layouts' / receipt).read_text())
    assert want in data[key], (receipt, want)
    MAP_CHECKS.append('%s %s: %s' % (receipt, key, data[key][want][:60]))

UNIT_MAP = {
    'replicator ..004ba22f': (
        'Network/Replicator.cpp (starts below 004b0000; app-unit4b0-2008 maps its head). In this range: 004b82d0 '
        '(assigns statsItem +0x2b88 = create<ReplicatorStatsItem> 004b7e50, parent "Network"), 004b8490 ("Received '
        'marker %d from %s", pops the incomingMarkers deque +0x2cdc), NewInstanceItem::write 004b8620 ("Replication: '
        '%s:%s >> %s"), the NonFactoryProduct<DescribedBase, sMarker> ctor 004b85b0 and deleting dtor 004b8600, '
        'Replicator::onServiceProvider 004b87f0 (vtable slot 12), the packet handlers 004b8970 (Security::Impersonator) '
        'and 004b8b60 (profilers +0x2d1c..), the waitItems tree erase(first, last) 004b8a80, OnReceive 004b8c20 ("Lost '
        'connection to %s"), Marker() 004b9140 / newMarker 004b9190 / the marker request 004b9210 ("Replicator: '
        'Requesting Marker %d of %s"), the IdSerializer bases and thunks 004b93d0..004b96a0 / 004b9ad0..004b9bb0 '
        '(vtables 008252cc.., 0082534c), ~Replicator 004b96b0 with its ??_E thunks 004b9a20..004b9ab0 and the '
        'Replicator constructor 004b9bd0 ("Replication" .. "Split Messages Sent" profilers).'),
    'raknet 004ba230..': (
        'RakNet 3.x library code: StringCompressor.cpp (Instance 004ba230, EncodeString 004ba4f0, DecodeString '
        '004ba650; proven as library evidence by app-unit49c-2008) with its DataStructures::Map / OrderedList '
        'instances on HuffmanEncodingTree* to 004ba9d0; PacketLogger.cpp 004baa10..004bb39f (ctor 004baa10, vtable '
        '00825724 .?AVPacketLogger@@, the message-id name table 004baab0 "ID_READY_EVENT_QUERY".., the log formatters '
        '004bae70 / 004baf80 / 004bb090 "%sSnd,Raw,..."); RakPeerInterface / RakPeer.cpp from 004bb3a0 (vtable '
        '00826394 .?AVRakPeerInterface@@) continuing past 004bc000 (app-unit4bc-2008 map). Library: never recovered.'),
}

NOT_EXACT = [
    {'address': 'Replicator members 004b82d0, 004b8490, 004b87f0, 004b8970, 004b8b60, OnReceive 004b8c20, the '
                'marker request 004b9210, ~Replicator 004b96b0 and the constructor 004b9bd0',
     'reason': 'Blocked, not attempted: each reads Replicator members past +0x2b90 (peer +0x2d50, remotePlayerId '
               '+0x2d54, incomingMarkers +0x2cdc, the ThreadProfiler/CodeProfiler scoped_ptrs +0x2d1c..+0x2d48, '
               'Players* +0x2c70 ...) that the read-only Network/Replicator2008.h leaves pending, and the profiler '
               'members also need a native util/Profiling.h. Proposal filed for the Replicator2008.h owner.'},
    {'address': 'NewInstanceItem::write 004b8620', 'reason': 'Blocked: Replicator::NewInstanceItem / Item are not '
               'declared by any native header (Replicator2008.h owner); not attempted.'},
    {'address': 'RakNet rows 004ba230..004bbfff', 'reason': 'Library code (StringCompressor, PacketLogger, RakPeer): '
               'never recovered or counted here.'},
]

REJECTED = {
    'explicit instantiation of the member erase(const_iterator, const_iterator) alone':
        'C2248 on 21022: the explicit member instantiation applies the access check to the protected '
        'IdSerializer::WaitItem; the explicit class instantiation of the tree does not.',
}

PROPOSALS = [
    'native-headers/Network/Replicator2008.h (Replicator family owner): declare the members +0x2b90..+0x2d68 '
    '(layout already in that header comment and TANDEM 2026-11-05/07) plus a native util/Profiling.h '
    '(ThreadProfiler/CodeProfiler 0xc048 bytes, const char* ctors 005c43a0 / 005c43d0, parent +0xc040). In this range '
    'they unblock: the statsItem setup 004b82d0 (reads peer +0x2d50 and remotePlayerId +0x2d54, calls peer slot '
    'GetStatistics, create<ReplicatorStatsItem> 004b7e50), the marker pop 004b8490 (deque<shared_ptr<Marker> > '
    '+0x2cdc, pop_front 004ae2f0), onServiceProvider 004b87f0, the packet handlers 004b8970 / 004b8b60, OnReceive '
    '004b8c20, the marker request 004b9210 (newMarker 004b9190, push_back 004b0c10), ~Replicator 004b96b0 and the '
    'constructor 004b9bd0; also Replicator::Item / NewInstanceItem declarations for NewInstanceItem::write 004b8620 '
    '(writeItemType 004ab5d0).',
]

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
counted_set = set(exact_rows)
receipt = {
    'class': 'RBX::Network Replicator.cpp rows of the application range 004b8000..004bc000 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'range_rows': len(RANGE_ROWS),
    'unit_map': UNIT_MAP,
    'unit_map_checks': MAP_CHECKS,
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any quoted bare address in another receipt as counted there.
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_not_counted': ' '.join(a for a in RANGE_ROWS if a not in range_counted and a not in counted_set),
    'rows': counted,
    'support_rows': support_out,
    'pending_rows': [],
    'not_exact': NOT_EXACT,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit4b8: %d counted exact rows (%s); 0 pending-build-only, %d range rows, %d counted elsewhere, '
      '%d support rows' % (len(exact_rows), ' '.join(exact_rows), len(RANGE_ROWS), len(range_counted), len(support_out)))
