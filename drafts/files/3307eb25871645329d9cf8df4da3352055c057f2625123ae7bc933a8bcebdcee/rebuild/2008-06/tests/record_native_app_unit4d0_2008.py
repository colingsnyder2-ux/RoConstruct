"""Record the unit map of the 2008-06 application range 004d0000..004d4000 (inactive; no native unit is built).

The whole range is RakNet 3.0 library code (recipes openrbx-raknet / rbxgs-raknet in roc/libs.py, Roblox's
Network/RakNet30 tree), in this link order: the rest of ReliabilityLayer.cpp (it starts before 004d0000 at
SplitPacketIndexComp 004ce9a0; app-unit4c8-2008 maps 004cdcc0..004d4000 as RakNet), with its DataStructures template
instances (BPlusTree<unsigned, InternalPacket*, 32>, RangeList<unsigned>, OrderedList / List of RangeNode<unsigned>),
then RPCMap.cpp, SimpleMutex.cpp and Rand.cpp (the Mersenne-Twister seedMT / reloadMT; reloadMT runs past 004d4000).
There is no RBX translation unit and no Roblox-only template instantiation here: every template instance is one the
RakNet source itself instantiates. So no row is recovered and none is counted (exact_function_rows is empty). Library
code is never recovered in native-classes.

Evidence (checked here against the original binary, not taken from the analog server labels): every row of the range
is compiled from the unmodified upstream RakNet 3.0 source file named by its block (VS2008 RTM 21022, through
roc.match.compile_text with the recipe's roc-lib pointer, the same path the server uses) and must be relocation-masked
byte-identical to one function of that object. Where identical-code folding makes several compiled functions equal,
all of them are listed and the chosen name is the one the call / import targets prove (SimpleMutex::Lock calls
EnterCriticalSection, Unlock calls LeaveCriticalSection). Every relocation of the chosen body is then bound to the
original operand: imports by DLL export name / mfc90 ordinal, in-range targets by the symbol this map assigns to that
address, targets outside the range whose symbol the same object defines by an exact body match at that address, and
each symbol must resolve to one address across all rows. The blocks must tile the range and every range row must be
mapped. Rows other receipts count are listed (top-level exact_function_rows rule, as in record_native_app_unit474_2008.py).
Writes work/2008-06/shared-layouts/app-unit4d0-2008-working.json.
"""
import glob
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = R / 'out/app-unit4d0-2008'
OUT.mkdir(parents=True, exist_ok=True)
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit4d0-2008-working.json'
RANGE = ('004d0000', '004d4000')
LIB = 'openrbx-raknet'
FLAGS = '/O2 /GS- /EHsc /MD'

original = nb.Original()
FUNCS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        row = json.loads(line)
        FUNCS[int(row['addr'], 16)] = row
lo, hi = int(RANGE[0], 16), int(RANGE[1], 16)
range_functions = sorted(a for a in FUNCS if lo <= a < hi)

# ---- blocks: [start, end) by row start, with the upstream RakNet 3.0 file each block is compiled from -----------------
BLOCKS = [
    ('raknet-reliabilitylayer', 0x4d0000, 0x4d3c90, 'ReliabilityLayer.cpp',
     'RakNet 3.0 ReliabilityLayer.cpp, continued from 004ce9a0 (004cff00 runs into the range to 004d02c4), with its '
     'DataStructures BPlusTree / RangeList / OrderedList / List instances'),
    ('raknet-rpcmap', 0x4d3c90, 0x4d3f80, 'RPCMap.cpp', 'RakNet 3.0 RPCMap.cpp (ctor, Clear, lookups, dtor)'),
    ('raknet-simplemutex', 0x4d3f80, 0x4d3fb0, 'SimpleMutex.cpp',
     'RakNet 3.0 SimpleMutex.cpp (ctor, Lock, Unlock; the dtor is folded elsewhere)'),
    ('raknet-rand', 0x4d3fb0, 0x4d4000, 'Rand.cpp',
     'RakNet 3.0 Rand.cpp (Mersenne Twister seedMT / reloadMT; reloadMT ends 004d4113, past the range)'),
]
EXTRA_FLAGS = {0x4d1380: ' /fp:fast'}   # GetStatistics: x87 ordering of the bitrate averages needs /fp:fast

# row -> symbol this map assigns (the compiled function that is byte-identical; ICF equivalents are recorded too)
ROWS = {
    0x4d02d0: '?FixUnderflow@?$BPlusTree@IPAUInternalPacket@@$0CA@@DataStructures@@IAE_NHPAU?$Page@IPAUInternalPacket@@$0CA@@2@IPAUReturnAction@12@@Z',
    0x4d0550: '?Receive@ReliabilityLayer@@QAEHPAPAE@Z',
    0x4d05d0: '?IsOutgoingDataWaiting@ReliabilityLayer@@QAE_NXZ',
    0x4d0620: '?AreAcksWaiting@ReliabilityLayer@@QAE_NXZ',
    0x4d0630: '?CreateInternalPacketFromBitStream@ReliabilityLayer@@AAEPAUInternalPacket@@PAVBitStream@RakNet@@_J@Z',
    0x4d07d0: '?SplitPacket@ReliabilityLayer@@AAEXPAUInternalPacket@@H@Z',
    0x4d0a00: '?Serialize@?$RangeList@I@DataStructures@@QAEIPAVBitStream@RakNet@@H_N@Z',
    0x4d0b90: '?Insert@?$OrderedList@IU?$RangeNode@I@DataStructures@@$1??$RangeNodeComp@I@2@YAHABIABU12@@Z@DataStructures@@QAEIABIABU?$RangeNode@I@2@_NP6AH01@Z@Z',
    0x4d0bf0: '?RemoveAtIndex@?$List@U?$RangeNode@I@DataStructures@@@DataStructures@@QAEXI@Z',
    0x4d0c30: '?FreePages@?$BPlusTree@IPAUInternalPacket@@$0CA@@DataStructures@@IAEXXZ',
    0x4d0d60: '?InsertBranchDown@?$BPlusTree@IPAUInternalPacket@@$0CA@@DataStructures@@IAEPAU?$Page@IPAUInternalPacket@@$0CA@@2@IABQAUInternalPacket@@PAU32@PAUReturnAction@12@PA_N@Z',
    0x4d0fd0: '?FindDeleteRebalance@?$BPlusTree@IPAUInternalPacket@@$0CA@@DataStructures@@IAE_NIPAU?$Page@IPAUInternalPacket@@$0CA@@2@PA_NIPAUReturnAction@12@AAPAUInternalPacket@@@Z',
    0x4d1140: '?Send@ReliabilityLayer@@QAE_NPADHW4PacketPriority@@W4PacketReliability@@E_NH_J@Z',
    0x4d12e0: '?AddToOrderingList@ReliabilityLayer@@AAEXPAUInternalPacket@@@Z',
    0x4d1380: '?GetStatistics@ReliabilityLayer@@QAEQAURakNetStatistics@@XZ',
    0x4d1530: '?Insert@?$RangeList@I@DataStructures@@QAEXI@Z',
    0x4d1680: '?Deserialize@?$RangeList@I@DataStructures@@QAE_NPAVBitStream@RakNet@@@Z',
    0x4d1780: '?Delete@?$BPlusTree@IPAUInternalPacket@@$0CA@@DataStructures@@QAE_NIAAPAUInternalPacket@@@Z',
    0x4d1850: '?Insert@?$BPlusTree@IPAUInternalPacket@@$0CA@@DataStructures@@QAE_NIABQAUInternalPacket@@@Z',
    0x4d1940: '??1?$OrderedList@IU?$RangeNode@I@DataStructures@@$1??$RangeNodeComp@I@2@YAHABIABU12@@Z@DataStructures@@QAE@XZ',
    0x4d19f0: '?GenerateDatagram@ReliabilityLayer@@AAE_NPAVBitStream@RakNet@@HPA_N_JUSystemAddress@@AAV?$List@PAVPluginInterface@@@DataStructures@@@Z',
    0x4d2020: '?InsertIntoSplitPacketList@ReliabilityLayer@@AAEXPAUInternalPacket@@_J@Z',
    0x4d2200: '?BuildPacketFromSplitPacketList@ReliabilityLayer@@AAEPAUInternalPacket@@G_J@Z',
    0x4d23c0: '?DeleteOldUnreliableSplitPackets@ReliabilityLayer@@AAEX_J@Z',
    0x4d24e0: '??1?$RangeList@I@DataStructures@@QAE@XZ',
    0x4d2570: '??1?$BPlusTree@IPAUInternalPacket@@$0CA@@DataStructures@@QAE@XZ',
    0x4d25d0: '??0ReliabilityLayer@@QAE@XZ',
    0x4d2780: '?FreeThreadSafeMemory@ReliabilityLayer@@AAEXXZ',
    0x4d2c70: '?HandleSocketReceiveFromConnectedPlayer@ReliabilityLayer@@QAE_NPBDHUSystemAddress@@AAV?$List@PAVPluginInterface@@@DataStructures@@H@Z',
    0x4d3610: '?Update@ReliabilityLayer@@QAEXIUSystemAddress@@H_JIAAV?$List@PAVPluginInterface@@@DataStructures@@@Z',
    0x4d3b40: '??1ReliabilityLayer@@QAE@XZ',
    0x4d3c70: '?Reset@ReliabilityLayer@@QAEX_N@Z',
    0x4d3c90: '??0RPCMap@@QAE@XZ',
    0x4d3ca0: '?Clear@RPCMap@@QAEXXZ',
    0x4d3d10: '?GetNodeFromIndex@RPCMap@@QAEPAURPCNode@@E@Z',
    0x4d3d30: '?GetIndexFromFunctionName@RPCMap@@QAEEPBD@Z',
    0x4d3d90: '?AddIdentifierWithFunction@RPCMap@@QAEXPBDPAX_N@Z',
    0x4d3e20: '?AddIdentifierAtIndex@RPCMap@@QAEXPBDE@Z',
    0x4d3ee0: '?RemoveNode@RPCMap@@QAEXPBD@Z',
    0x4d3f20: '??1RPCMap@@QAE@XZ',
    0x4d3f80: '??0SimpleMutex@@QAE@XZ',
    0x4d3f90: '?Lock@SimpleMutex@@QAEXXZ',
    0x4d3fa0: '?Unlock@SimpleMutex@@QAEXXZ',
    0x4d3fb0: '?seedMT@@YAXI@Z',
    0x4d3ff0: '?reloadMT@@YAIXZ',
}
# rows whose import target decides between identical compiled bodies
IMPORT_PROOF = {0x4d3f80: 'InitializeCriticalSection', 0x4d3f90: 'EnterCriticalSection',
                0x4d3fa0: 'LeaveCriticalSection'}

NOTES = {
    'analog labels': ('The analog server labels name several rows from other RakNet files that compile to identical '
                      'code (ConnectionGraph OrderedList<SystemAddress>::Insert at row 004d0b90, DS_Table '
                      'BPlusTree<Row*,16> dtor at row 004d2570, FileList dtor at row 004d3f20, G3D GMutex / '
                      'AtomicInt32 at rows 004d3f80..004d3fa0, PhysicsSender unit names). This map uses the '
                      'symbol of the block\'s own file that is byte-identical and whose call / import targets agree.'),
    'icf': ('Row 004d0bf0 is List<RangeNode<unsigned>>::RemoveAtIndex and the identical OrderedList::RemoveAtIndex; '
            'row 004d3c90 is RPCMap::RPCMap and the identical List<RPCNode*>::List; rows 004d3f90 / 004d3fa0 are '
            'SimpleMutex::Lock / Unlock (each shape-identical to the dtor, told apart by the import called).'),
    'callers': ('Callers outside the range (checked below from functions.jsonl) are the RakPeer.cpp rows '
                '004bb5d0..004c65c0 (server analog labels: RemoteSystemStruct ctor / dtor, RPC registration, ban '
                'list, Shutdown, ~RakPeer, InitializeSecurity, ...) and 0078de50, the XTP 11.2.2 '
                'CXTPOffice2007Image ctor, which calls the folded critical-section ctor body of row 004d3f80. No RBX '
                'class, RTTI, vtable or static initializer references the range.'),
}

for a in range_functions:
    assert a in ROWS, ('unmapped range row', hex(a))
assert set(ROWS) == set(range_functions), sorted(hex(a) for a in set(ROWS) - set(range_functions))
assert BLOCKS[0][1] == lo and BLOCKS[-1][2] == hi
for x, y in zip(BLOCKS, BLOCKS[1:]):
    assert x[2] == y[1], (x[0], y[0])


outside_callers = sorted({int(c, 16) for a in range_functions for c in FUNCS[a].get('callers', [])
                          if not lo <= int(c, 16) < hi})
assert all(0x4bb5d0 <= c <= 0x4c65c0 for c in outside_callers if c != 0x78de50), [hex(c) for c in outside_callers]
assert [c for c in outside_callers if c == 0x78de50] and \
    [int(c, 16) for c in FUNCS[0x78de50].get('call_targets', []) if lo <= int(c, 16) < hi] == [0x4d3f80]


def block_of(address):
    hits = [b for b in BLOCKS if b[1] <= address < b[2]]
    assert len(hits) == 1, hex(address)
    return hits[0]


OBJECTS = {}


def compiled(file, flags):
    key = (file, flags)
    if key not in OBJECTS:
        text = '// roc-lang: cpp\n// roc-cl: 21022\n// roc-flags: %s\n// roc-lib: %s %s\n' % (flags, LIB, file)
        raw = match.compile_text('2008-06', text)
        path = OUT / ('%s%s.obj' % (Path(file).stem, flags.replace(' ', '').replace('/', '_').replace(':', '')))
        path.write_bytes(raw)
        OBJECTS[key] = (raw, text, path)
    return OBJECTS[key]


def reloc_values(raw, symbol, address, target_code):
    """[(offset, kind, symbol, original value)] for every relocation of the compiled `symbol`."""
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    table = sections[section]
    code = raw[table[4] + start:]
    out = []
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if not 0 <= offset < len(target_code):
            continue
        name = symbols[index][0]
        if kind == 20:
            value = (address + offset + 4 + struct.unpack_from('<i', target_code, offset)[0]) & 0xffffffff
        else:
            value = (struct.unpack_from('<I', target_code, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
        out.append((offset, 'REL32' if kind == 20 else 'DIR32', name, value))
    return out


rows, addr_of = [], {}
for address in range_functions:
    name, start, end, file, _ = block_of(address)
    flags = FLAGS + EXTRA_FLAGS.get(address, '')
    raw, text, path = compiled(file, flags)
    target, target_relocs, _ = match.target('2008-06', '%08x' % address)
    bodies = match.coff_functions(raw)
    exact = sorted({n for n, b, r in bodies if match.exact_match(target, target_relocs, b, r)})
    symbol = ROWS[address]
    assert symbol in exact, (hex(address), symbol, exact[:4])
    rows.append({'row': '%08x' % address, 'block': name, 'file': file, 'flags': flags, 'symbol': symbol,
                 'size': len(target), 'icf_equivalents': [s for s in exact if s != symbol],
                 'relocs': reloc_values(raw, symbol, address, target)})
    assert addr_of.setdefault(symbol, address) == address

# ---- relocation targets ----------------------------------------------------------------------------------------------
bound = {}
for row in rows:
    address = int(row['row'], 16)
    raw = compiled(row['file'], row['flags'])[0]
    defined = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    checks = {}
    for offset, kind, symbol, value in row.pop('relocs'):
        if nb.LOCAL_EH.match(symbol):
            checks.setdefault('local_eh', []).append(symbol)
            continue
        assert bound.setdefault(symbol, value) == value, ('one address per symbol', symbol, hex(value), hex(bound[symbol]))
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == nb.plain(symbol), (row['row'], symbol, hit)
            checks[symbol] = 'import %s!%s' % hit
        elif symbol in addr_of:
            assert addr_of[symbol] == value, (row['row'], symbol, hex(value))
            checks[symbol] = 'in-range row %08x' % value
        elif symbol in defined and value in FUNCS:
            tcode, trel, _ = match.target('2008-06', '%08x' % value)
            body, refs = defined[symbol]
            assert match.exact_match(tcode, trel, body, refs), (row['row'], symbol, hex(value))
            checks[symbol] = 'out-of-range row %08x, body exact from the same object' % value
        else:
            checks[symbol] = 'extern library target at %08x (one address per symbol)' % value
    if address in IMPORT_PROOF:
        assert any(v.endswith('!' + IMPORT_PROOF[address]) for v in checks.values() if isinstance(v, str)), \
            (row['row'], checks)
    row['targets'] = checks
for row in rows:
    row['row'] = 'row ' + row['row']   # never a quoted bare address: nothing is counted here


# ---- counting rules (same as record_native_app_unit474_2008.py) ------------------------------------------------------
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
        found = []
        if 'exact_function_rows' in data:
            found = data['exact_function_rows']
        elif isinstance(data.get('exact_addresses'), list):
            found = data['exact_addresses']
        elif isinstance(data.get('exact_unique_addresses'), list):
            found = data['exact_unique_addresses']
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        found.append(o['address'])
                    else:
                        for v in o.values():
                            walk(v)
            walk(data.get('methods', []))
        if isinstance(found, dict):
            found = list(found)
        for r in found:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
range_counted = ['%s counted by %s' % (a, ', '.join(sorted(set(v))))
                 for a, v in sorted(elsewhere.items()) if RANGE[0] <= a < RANGE[1]]

UNIT_MAP = {}
for name, start, end, file, what in BLOCKS:
    mine = [r for r in rows if r['block'] == name]
    UNIT_MAP['%s %08x..%08x' % (name, start, end - 1)] = {
        'unit': what, 'upstream_file': file, 'library': True, 'recovered': False, 'rows': len(mine),
        'bytes': sum(r['size'] for r in mine)}

exact_rows = []
receipt = {
    'class': 'unit map of the application range 004d0000..004d4000 (2008-06): RakNet 3.0 library, inactive',
    'result': ('No RBX translation unit and no Roblox-only template instantiation in the range: every row is RakNet '
               '3.0 library code (ReliabilityLayer.cpp with its DataStructures instances, RPCMap.cpp, '
               'SimpleMutex.cpp, Rand.cpp), each reproduced byte-identically from the upstream file. Nothing is '
               'recovered or counted here.'),
    'compiler': 'VS2008 RTM 21022',
    'library_recipe': '%s (roc/libs.py), flags %s' % (LIB, FLAGS),
    'sources': {str(Path(__file__).resolve().relative_to(ROOT)).replace('\\', '/'): nb.sha(Path(__file__).resolve())},
    'objects': {p.name: hashlib.sha256(raw).hexdigest() for raw, _, p in OBJECTS.values()},
    'unit_map': UNIT_MAP,
    'library_rows': rows,
    'notes': NOTES,
    'range_functions': len(range_functions),
    'range_bytes': sum(FUNCS[a]['size'] for a in range_functions),
    'range_rows_counted_by_other_receipts': range_counted,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive map receipt. No native source, no counted row, no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit4d0-2008: %d range rows (%d bytes) in %d blocks, all byte-identical to upstream RakNet 3.0 '
      '(%s), %d relocation targets bound; %d counted elsewhere; 0 counted here (RakNet library range)'
      % (len(range_functions), receipt['range_bytes'], len(BLOCKS), LIB, len(bound), len(range_counted)))
