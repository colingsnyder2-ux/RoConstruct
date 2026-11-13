"""Verify the inactive 2008-06 native rows of the application range 004ac000..004b0000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map` and `unit_map_checks`; rows counted by other receipts in
`range_rows_counted_by_other_receipts`, written as 'ADDR counted by RECEIPT' text, never as quoted bare addresses):
the whole range is the COMDAT run of the Network/Replicator.cpp unit (it starts below 004ac000 and continues to the
Replicator constructor 004b9bd0, see app-unit4b0-2008 / app-unit4b4 / app-unit4b8): boost shared_count /
sp_counted_impl_p instances on the Replicator item classes, Name::callDoDeclare jumps, reflection property
templates, Peer members, STL list / map / set / deque instances on Replicator member types, boost::bind / function
instances on Replicator members, the Replicator item classes (ChangePropertyItem, MarkerItem, NewInstanceItem,
DeleteInstanceItem) and the JointsService descriptor block. No library unit (RakNet / CRT / MFC) and no excluded
class (CRobloxApp, CMainFrame, CRobloxDoc, CRobloxView) has a row here.

Builds (document-swap flags, VS2008 RTM 21022; the Peer unit with RakNet raknet30/Source and /fp:fast), all against
the committed native headers read-only, plus the new native-headers/AppUnit4AC/PeerHeartbeat.h (one declaration):
  * names:   native-classes/AppUnit4ACNames.cpp   Name::callDoDeclare<sC> for the seven joint class names;
  * marker:  native-classes/AppUnit4ACMarkerTemplates.cpp   shared_count<Marker>, sp_counted_impl_p<Marker>,
             deque<shared_ptr<Marker> >;
  * signals: native-classes/AppUnit4ACSignalMap.cpp   map<const SignalDescriptor*, shared_ptr<SignalInstance> > tree;
  * guids:   native-classes/AppUnit4ACGuidMap.cpp     map<Guid::Data, Instance*> tree;
  * peer:    native-classes/AppUnit4ACPeerHeartbeat.cpp   Peer::onEvent(const RunService*, Heartbeat).
There is no pending build (so no pending-build-only row) and no class vtable is emitted from a pending header; the one
vtable of the builds, sp_counted_impl_p<Marker>, is checked slot by slot against the original 008246f4.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, own symbols by the row proven here, COMDAT /
ICF support bodies by exactness at the bound address, vtables by the original RTTI, data by its bytes, declared-only
externals by their evidence name or by body evidence. The shared_count<Marker> row is compared split at the original
extent: the compiled 131-byte body is the 110-byte row 004ac040 followed by its 21-byte catch funclet row 004ac0ae
(reached only from the EH tables); both halves must be exact. A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit4ac-working.json.
Set NATIVE_APP_UNIT4AC_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = R / 'out/app-unit4ac'
OUT.mkdir(parents=True, exist_ok=True)
RAKNET = ROOT / 'tools/rbxgs/Client/Network/raknet30/Source'
NC = R / 'native-classes'
SOURCES = {'names': NC / 'AppUnit4ACNames.cpp', 'marker': NC / 'AppUnit4ACMarkerTemplates.cpp',
           'signals': NC / 'AppUnit4ACSignalMap.cpp', 'guids': NC / 'AppUnit4ACGuidMap.cpp',
           'peer': NC / 'AppUnit4ACPeerHeartbeat.cpp'}
UNIT_FLAGS = {'peer': ['/fp:fast']}
HEADERS = [R / 'native-headers' / h for h in (
    'AppUnit4AC/PeerHeartbeat.h', 'v8datamodel/JointInstance.h', 'util/Name.h', 'Network/ReplicatorMarker.h',
    'reflection/signal.h', 'util/GuidRegistry.h', 'Network/Peer2008.h')]
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT4AC_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit4ac-working.json'
LO, HI = 0x4ac000, 0x4b0000


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = ['/I' + str(RAKNET)] + nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build('NativeAppUnit4AC_' + _k, _src, UNIT_FLAGS.get(_k, ()))

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
dword = lambda a: struct.unpack('<I', original.data(a, 4))[0]

RAW = {k: Path(v).read_bytes() for k, v in OBJ.items()}
FUNCS = {k: match.coff_functions(v) for k, v in RAW.items()}
BODIES = {}
UNIT_OF = {}
for _k, _funcs in FUNCS.items():
    for _n, _b, _r in _funcs:
        BODIES.setdefault(_n, (_b, _r))
        UNIT_OF.setdefault(_n, _k)


def resolve(unit, prefix, suffix=''):
    hits = [x[0] for x in FUNCS[unit] if x[0].startswith(prefix) and suffix in x[0]
            and not nb.LOCAL_EH.match(x[0])]
    assert len(hits) == 1, (unit, prefix[:90], suffix, [h[:160] for h in hits])
    return hits[0]


# ---- counted rows -----------------------------------------------------------------------------------------------
JOINT_NAMES = ('Snap', 'Weld', 'Glue', 'Rotate', 'RotateP', 'RotateV', 'Motor')
NAME_ROWS = [(0x4ac320 + 0x10 * i, 'names', '??$callDoDeclare@$1?s%s@RBX@@3PADA@Name@RBX@@CAXXZ' % c, '')
             for i, c in enumerate(JOINT_NAMES)]
MARKER = 'VMarker@Network@RBX@@'
DQ = '?$deque@V?$shared_ptr@' + MARKER + '@boost@@V?$allocator@V?$shared_ptr@' + MARKER + '@boost@@@std@@@std@@'
SD = '?$_Tree@V?$_Tmap_traits@PBVSignalDescriptor@Reflection@RBX@@V?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@'
GD = '?$_Tree@V?$_Tmap_traits@UData@Guid@RBX@@PAVInstance@3@'
GD_IT = 'V?$_Tmap_traits@UData@Guid@RBX@@PAVInstance@3@'
ROW_SPEC = NAME_ROWS + [
    (0x4ac040, 'marker', '??$?0' + MARKER + '@shared_count@detail@boost@@QAE@PAVMarker@Network@RBX@@@Z', ''),
    (0x4ac390, 'marker', '?dispose@?$sp_counted_impl_p@' + MARKER + '@detail@boost@@UAEXXZ', ''),
    (0x4ae2f0, 'marker', '?pop_front@' + DQ + 'QAEXXZ', ''),
    (0x4af1b0, 'marker', '?_Tidy@' + DQ + 'IAEXXZ', ''),
    (0x4ae370, 'signals', '?_Insert@' + SD, ''),
    (0x4af270, 'signals', '?insert@' + SD, 'QAE?AU?$pair@Viterator@?$_Tree@'),
    (0x4af530, 'signals', '?erase@' + SD, 'QAE?AViterator@12@Vconst_iterator@12@@Z'),
    (0x4af4c0, 'guids', '?erase@' + GD, 'QAEIABUData@Guid@RBX@@@Z'),
    # const / non-const twins build the same bytes; the one the original erase(key) calls is the non-const one
    (0x4ad940, 'guids', '?_Eqrange@' + GD, '@std@@@std@@IAE?AU?$pair@Viterator@'),
    (0x4ad520, 'guids', '??$_Distance2@Viterator@?$_Tree@' + GD_IT, ''),
    (0x4add50, 'peer', '?onEvent@Peer@Network@RBX@@MAEXPBVRunService@3@VHeartbeat@3@@Z', ''),
]


def _resolve_insert():
    # insert(const value_type&) returning pair<iterator, bool> (not the hinted insert(iterator, const value_type&))
    hits = [x[0] for x in FUNCS['signals'] if x[0].startswith('?insert@' + SD) and not nb.LOCAL_EH.match(x[0])
            and x[0].endswith('@std@@_N@2@ABU?$pair@QBVSignalDescriptor@Reflection@RBX@@V?$shared_ptr@VSignalInstance'
                              '@Reflection@RBX@@@boost@@@2@@Z')]
    assert len(hits) == 1, hits
    return hits[0]


ROWS = []
for _a, _u, _p, _s in ROW_SPEC:
    if _a == 0x4af270:
        ROWS.append((_a, _insert := _resolve_insert()))
        continue
    if _p in BODIES and not _s:
        ROWS.append((_a, _p))
    else:
        ROWS.append((_a, resolve(_u, _p, _s)))
# the shared_count<Marker> body is compared split at the original extent: (row, catch-funclet row)
SPLIT = {ROWS[[a for a, _ in ROWS].index(0x4ac040)][1]: (0x4ac040, 0x4ac0ae)}
OWN = {name: address for address, name in ROWS}

# ---- support bodies (exact at the bound address; outside this range or ICF-shared; never counted here) -----------
SUPPORT_SPEC = [(0x4ab160 + 0x70 * i, '??$doDeclare@$1?s%s@RBX@@3PADA@Name@RBX@@CAABV01@XZ' % c)
                for i, c in enumerate(JOINT_NAMES)]
SUPPORT_SPEC += [
    (0x427b70, '??$checked_delete@' + MARKER + '@boost@@YAXPAVMarker@Network@RBX@@@Z'),
    (0x4983f0, resolve('guids', '?erase@' + GD, 'QAE?AViterator@12@Vconst_iterator@12@0@Z')),
]
SUPPORT = dict((n, a) for a, n in SUPPORT_SPEC)
# sp_counted_impl_p<Marker> virtuals other than dispose: ICF-shared generic bodies, bound through the vtable
VT_SUPPORT = {
    '??_E?$sp_counted_impl_p@' + MARKER + '@detail@boost@@UAEPAXI@Z': 0x415000,
    '?destroy@sp_counted_base@detail@boost@@UAEXXZ': 0x405e10,
    '?get_deleter@?$sp_counted_impl_p@' + MARKER + '@detail@boost@@UAEPAXABVtype_info@@@Z': 0x5f2310,
}
# ICF-shared bodies counted by other receipts (bound by the call site; that receipt must count the address and this
# build's body must be exact there). Filled from discovery.
COUNTED_ELSEWHERE = {}
# declared-only externals: (address, how verified)
EXTERNAL = {
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,
    '??$for_eachChild@P6AXPAVInstance@RBX@@@Z@Instance@RBX@@QBEXP6AXPAV01@@Z@Z': 0x45c470,
    '?getTick@System@G3D@@SANXZ': 0x5083d0,
    '??2@YAPAXI@Z': 0x6a0920,
    '??3@YAXPAX@Z': 0x6a0926,
    '__CxxThrowException@8': 0x6a158c,
    '?checkDisconnect@@YAXPAVInstance@RBX@@@Z': 0x4aaf50,
    '??MData@Guid@RBX@@QBE_NABU012@@Z': 0x5a8210,
}
VTABLES = {
    '??_7?$sp_counted_impl_p@' + MARKER + '@detail@boost@@6B@': (0x8246f4, '.?AV?$sp_counted_impl_p@' + MARKER + '@detail@boost@@'),
}
# data symbols: (address, expected bytes)
DATA = {'__real@3e4ccccd': (0x8249f8, struct.pack('<I', 0x3e4ccccd))}
for _i, _c in enumerate(JOINT_NAMES):
    DATA['?s%s@RBX@@3PADA' % _c] = (0x83e040 + 8 * _i, _c.encode() + b'\0')

support_out = {}
UNBOUND = []
binding = {}


def throw_info_type(address):
    array = dword(address + 12)
    return original.data(dword(dword(array + 4) + 4) + 8, 64).split(b'\0')[0].decode('latin-1')


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def site_target(unit, name):
    """(target bytes, target relocs, address of byte i) for a compiled body, joined across a funclet split."""
    if name in SPLIT:
        at, tail_at = SPLIT[name]
        head, head_refs = target_of(at)
        tail, tail_refs = target_of(tail_at)
        return (head + tail, list(head_refs) + [x + len(head) for x in tail_refs],
                lambda i: (at + i) if i < len(head) else (tail_at + i - len(head)), len(head))
    at = OWN.get(name, SUPPORT.get(name))
    body, refs = target_of(at)
    return body, refs, (lambda i: at + i), None


def check_body(symbol, value):
    sbody, srefs = BODIES[symbol]
    starget, strefs = target_of(value)
    return len(sbody) == len(starget) and match.exact_match(starget, strefs, sbody, srefs)


def bind_value(name, target, addr_of):
    unit = UNIT_OF[name]
    raw = RAW[unit]
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    body, _ = BODIES[name]
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
            value = (addr_of(offset) + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        else:
            value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
        if nb.LOCAL_EH.match(symbol):
            local.add(symbol)
            continue
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
            how = '%s!%s' % hit
        elif symbol in OWN:
            assert OWN[symbol] == value, (name, symbol, hex(value), hex(OWN[symbol]))
            how = 'own row'
        elif symbol in SUPPORT:
            assert SUPPORT[symbol] == value, (name, symbol, hex(value), hex(SUPPORT[symbol]))
            assert check_body(symbol, value), ('support body not exact', symbol, hex(value))
            support_out.setdefault(symbol, {'address': hex(value), 'reached_from': name,
                                            'note': 'COMDAT support body exact at the bound address; not counted'})
            how = 'support body exact at the bound address'
        elif symbol in COUNTED_ELSEWHERE:
            at, receipt = COUNTED_ELSEWHERE[symbol]
            assert at == value, (name, symbol, hex(value), hex(at))
            data = json.loads((ROOT / 'work/2008-06/shared-layouts' / receipt).read_text())
            assert '%08x' % value in data['exact_function_rows'], (symbol, receipt)
            assert check_body(symbol, value), ('ICF-shared body not exact', symbol, hex(value))
            how = 'ICF-shared row counted by %s (this build exact there)' % receipt
        elif symbol in VTABLES:
            at, rtti = VTABLES[symbol]
            assert at == value, (name, symbol, hex(value), hex(at))
            assert original.vtable_class(value)[0] == rtti, (symbol, original.vtable_class(value))
            how = 'vtable (original RTTI %s)' % rtti
        elif symbol in DATA:
            at, want = DATA[symbol]
            assert at == value and original.data(value, len(want)) == want, (name, symbol, hex(value))
            how = 'data, bytes %s' % want.hex()
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else ' (call site; body evidence)')
        elif symbol.startswith('??_7'):
            rtti = original.vtable_class(value)[0]
            assert rtti == '.?AV' + symbol[4:symbol.index('@@6B') + 2], (name, symbol, hex(value), rtti)
            how = 'vtable (original RTTI %s)' % rtti
        elif symbol.startswith('__TI'):
            assert throw_info_type(value) == '.' + symbol[symbol.index('?'):], (name, symbol, hex(value))
            how = 'throw info (original type %s)' % throw_info_type(value)
        elif symbol.startswith('??_C@'):
            lpos, lsec = definitions[symbol]
            literal = raw[sections[lsec][4] + lpos:sections[lsec][4] + sections[lsec][3]].split(b'\0')[0] + b'\0'
            assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
            how = 'literal %r' % literal[:-1].decode()
        elif symbol in BODIES and check_body(symbol, value):
            # a COMDAT body this build emits, exact at the referenced address (ICF-shared or outside this range)
            other = ELSEWHERE_ALL.get('%08x' % value)
            if other:
                how = 'ICF-shared body exact at the bound address (row counted by %s)' % ', '.join(sorted(set(other)))
            else:
                how = 'support body exact at the bound address'
                support_out.setdefault(symbol, {'address': hex(value), 'reached_from': name,
                                                'note': 'COMDAT / ICF-shared body exact at the bound address; not '
                                                        'counted here'})
        else:
            UNBOUND.append('    %r: %#x,   # %s in %s' % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        prev = binding.setdefault(symbol, (value, name))
        assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


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


def verify(rows):
    result = []
    for address, name in rows:
        body, refs = BODIES[name]
        target, target_refs, addr_of, split_at = site_target(UNIT_OF[name], name)
        exact = len(body) == len(target) and match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
                 'exact': exact, 'unit': UNIT_OF[name]}
        if split_at is not None:
            h = [x for x in refs if x < split_at]
            t = [x - split_at for x in refs if x >= split_at]
            head, head_refs = target_of(SPLIT[name][0])
            tail, tail_refs = target_of(SPLIT[name][1])
            exact = exact and match.exact_match(head, head_refs, body[:split_at], h) \
                and match.exact_match(tail, tail_refs, body[split_at:], t)
            entry.update({'exact': exact, 'target_size': len(head),
                          'split': 'compiled %d B = row %d B + catch-funclet row %s %d B (both halves exact)'
                                   % (len(body), len(head), '%08x' % SPLIT[name][1], len(tail))})
        if not exact:
            assert DISCOVER, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        verified, local = bind_value(name, target, addr_of)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


ELSEWHERE_ALL = counted_elsewhere()
counted = verify(ROWS)
# the catch funclet of shared_count<Marker> is its own row: counted with the split head above
counted.append({'address': '%08x' % 0x4ac0ae, 'symbol': ROWS[[a for a, _ in ROWS].index(0x4ac040)][1] + ' (catch funclet)',
                'size': 21, 'target_size': 21, 'exact': counted[[r['address'] for r in counted].index('004ac040')]['exact'],
                'unit': 'marker', 'split_of': '004ac040',
                'note': 'catch(...) funclet `boost::checked_delete(p); throw;` of shared_count<Marker>: the tail '
                        '21 bytes of the compiled body, exact with its relocations (checked_delete 00427b70, '
                        '_CxxThrowException 006a158c) verified in the 004ac040 entry'})

# sp_counted_impl_p<Marker> vtable: every slot of the compiled vtable against the original 008246f4
VT_OUT = []


def vtable_slots(unit, vsym):
    raw = RAW[unit]
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[vsym]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[index][0]
    return slots


for vsym, (vaddr, rtti) in VTABLES.items():
    slots = vtable_slots('marker', vsym)
    out = {}
    for slot, sym in sorted(slots.items()):
        value = dword(vaddr + 4 * slot)
        if sym in OWN:
            assert OWN[sym] == value, (vsym, slot, sym, hex(value))
            out[str(slot)] = '%s -> %s (own row)' % (sym, hex(value))
        elif sym in VT_SUPPORT:
            assert VT_SUPPORT[sym] == value, (vsym, slot, sym, hex(value), hex(VT_SUPPORT[sym]))
            body_sym = sym if sym in BODIES else sym.replace('??_E', '??_G', 1)   # ??_E aliases the ??_G body
            ok = check_body(body_sym, value)
            if not ok:
                assert DISCOVER, ('vtable slot body not exact', sym, hex(value))
            support_out.setdefault(sym, {'address': hex(value), 'reached_from': vsym,
                                         'note': 'ICF-shared generic body bound through vtable slot %d, exact '
                                                 'at the bound address; not counted' % slot})
            out[str(slot)] = '%s -> %s (ICF-shared support body exact)' % (sym, hex(value))
        else:
            UNBOUND.append('    vtable %s slot %d %r: %#x' % (vsym[:60], slot, sym, value))
    assert original.vtable_class(vaddr)[0] == rtti
    VT_OUT.append({'vtable': hex(vaddr), 'symbol': vsym, 'rtti': rtti, 'slots': out})

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for r in counted:
        if not r['exact']:
            print('NOT EXACT', r['address'], r['symbol'][:90], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, UNBOUND
assert all(r['exact'] for r in counted)
assert set(SUPPORT) <= set(binding), sorted(set(SUPPORT) - set(binding))
# the Marker rows are the instances the Marker code calls: newMarker 004b9190 -> shared_count 004ac040 and the
# sp_counted_impl_p<Marker> vtable 008246f4 slot 1 -> dispose 004ac390
assert dword(0x8246f4 + 4) == 0x4ac390
_nm, _ = target_of(0x4b9190)
_o = 0x4b91e2 - 0x4b9190   # call shared_count<Marker> in newMarker (after new(0x10) 006a0920 and Marker() 004b9140)
assert _nm[_o] == 0xe8 and 0x4b91e2 + 5 + struct.unpack_from('<i', _nm, _o + 1)[0] == 0x4ac040, 'newMarker call'
# checkDisconnect 004aaf50 (declared only): body evidence, dynamic_cast to Replicator then setParent(0)
_cd, _ = target_of(0x4aaf50)
assert struct.pack('<I', 0x938db4) in _cd and struct.pack('<I', 0x92907c) in _cd
assert original.data(0x938db4 + 8, 29) == b'.?AVReplicator@Network@RBX@@\0'
assert original.data(0x92907c + 8, 19) == b'.?AVInstance@RBX@@\0'
_sp = 0x4aaf7c + 5 + struct.unpack_from('<i', _cd, 0x4aaf7d - 0x4aaf50)[0]
assert names.get(_sp) == '?setParent@Instance@RBX@@QAEXPAV12@@Z', hex(_sp)
# the doDeclare support bodies declare the joint names (string checks through DATA)
# G3D::System::getTick 005083d0 (declared only; the same binding as app-unit5a8-2008): QueryPerformanceCounter
# (import 00802250) minus the start counter, divided by the frequency; System::time 00508410 is the same body plus
# the start time (fadd), so the bound address is getTick, not time.
_gt, _ = target_of(0x5083d0)
assert original.imported(0x802250)[1] == 'QueryPerformanceCounter' and b'\xff\x15' + struct.pack('<I', 0x802250) in _gt
assert len(_gt) == 59 and b'\xdc\x05' not in _gt


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
for vt, want in ((0x8246f4, '.?AV?$sp_counted_impl_p@VMarker@Network@RBX@@@detail@boost@@'),
                 (0x82471c, '.?AV?$sp_counted_impl_p@VNewInstanceItem@Replicator@Network@RBX@@@detail@boost@@'),
                 (0x824730, '.?AV?$sp_counted_impl_p@VChangePropertyItem@Replicator@Network@RBX@@@detail@boost@@'),
                 (0x824744, '.?AV?$sp_counted_impl_p@VDeleteInstanceItem@Replicator@Network@RBX@@@detail@boost@@'),
                 (0x824758, '.?AV?$sp_counted_impl_p@VMarkerItem@Replicator@Network@RBX@@@detail@boost@@'),
                 (0x824828, '.?AVChangePropertyItem@Replicator@Network@RBX@@'),
                 (0x8246e8, '.?AVMarkerItem@Replicator@Network@RBX@@'),
                 (0x824b20, '.?AVNewInstanceItem@Replicator@Network@RBX@@'),
                 (0x824b2c, '.?AVDeleteInstanceItem@Replicator@Network@RBX@@'),
                 (0x824944, '.?AVPeer@Network@RBX@@')):
    rtti = original.vtable_class(vt)
    assert rtti and rtti[0] == want, (hex(vt), rtti)
    MAP_CHECKS.append('vtable %s RTTI %s' % (hex(vt), want))
for at, want in ((0x824a04, 'Replication: Sending marker %d to %s'),):
    assert cstr(at) == want, (hex(at), cstr(at))
    MAP_CHECKS.append('string %s %r' % (hex(at), want))
for at, want in ((0x4ac040, '??$?0VMarker@Network@RBX@@@shared_count@detail@boost@@QAE@PAVMarker@Network@RBX@@@Z'),
                 (0x4add50, '?onEvent@Peer@Network@RBX@@MAEXPBVRunService@3@VHeartbeat@3@@Z'),
                 (0x4ae2f0, '?pop_front@' + DQ + 'QAEXXZ'),
                 (0x4af1b0, '?_Tidy@' + DQ + 'IAEXXZ')):
    assert names.get(at) == want, (hex(at), names.get(at))
    MAP_CHECKS.append('evidence name %s %s' % (hex(at), want[:80]))
# Peer Listener<RunService, Heartbeat> vtable 0082488c slot 0 is onEvent
assert dword(0x82488c) == 0x4add50
MAP_CHECKS.append('Peer Listener<RunService, Heartbeat> vtable 0x82488c slot 0 -> 0x4add50')

UNIT_MAP = {
    'Network/Replicator.cpp COMDAT run 004ac000..004b0000 (all 146 rows)': (
        'The range lies inside the Replicator.cpp unit (it starts below 004ac000; app-unit4b0-2008 maps it up to the '
        'Replicator constructor 004b9bd0). Blocks: 0x4ac040..0x4ac2ff boost::detail::shared_count(T*) for Marker, '
        'NewInstanceItem, ChangePropertyItem, DeleteInstanceItem and MarkerItem (vtables 008246f4..00824758), each a '
        '110-byte row plus its 21-byte catch funclet row; 0x4ac310..0x4ac38f Name::callDoDeclare for Lighting and the '
        'seven joint names; 0x4ac390..0x4ac82f sp_counted_impl_p / sp_counted_impl_pd members (the shared_count(T*, '
        'Deleter) rows of the creatable-shared-count fan-out), boost::function2<void, string, int>::operator() and '
        'the joint-name doDeclare-index jumps 0x4ac600 / 0x4ac610; 0x4ac830..0x4ac9df ~Peer and its ten adjustor '
        'thunks (network-client-server2008); 0x4ac9e0 a Peer logger toggle (PacketLogger new(0x210) 004ab630); '
        '0x4acac0..0x4ad7bf ChangePropertyItem members, list<shared_ptr<Replicator::Item> > members, reflection '
        'ConstProperty / Property get/set templates (dynamic_cast to TypedPropertyDescriptor<T>, std::bad_cast "bad '
        'cast"), boost::bind storage / list3 on Replicator members, the creatable shared_count rows of Stats::Item, '
        'Lighting, TypedStatsItem<bool> and JointsService, boost::function managers and ~Peer deleting dtor; '
        '0x4ad7c0..0x4ae7ff STL instances (list _Buynode, set / map _Eqrange / find / _Insert, the '
        'map<const SignalDescriptor*, shared_ptr<SignalInstance> > tree, deque<shared_ptr<Marker> >::pop_front), '
        'Peer::onEvent(Heartbeat) 0x4add50 and create<Lighting> 0x4adb60; 0x4ae800..0x4af9ff boost::function '
        'invokers on Replicator members, MarkerItem members ("Replication: Sending marker %d to %s" 0x4ae9a0), map '
        '<const Instance*, ...> / list / deque members on Replicator member types, the map<Guid::Data, Instance*> '
        'erase(key) and the network-physics-senders rows; 0x4afa30..0x4afc6f the JointsService descriptor block '
        '(services); 0x4afc70..0x4affff NewInstanceItem / DeleteInstanceItem constructors and members.'),
    'library / excluded': 'none: no RakNet, CRT, MFC/ATL, XTP, G3D, Ogre, zlib or Lua unit and no CRobloxApp / '
                          'CMainFrame / CRobloxDoc / CRobloxView row in this range.',
}

NOT_EXACT = [
    {'address': 'shared_count(T*) for NewInstanceItem / ChangePropertyItem / DeleteInstanceItem / MarkerItem '
                '(0x4ac0d0, 0x4ac160, 0x4ac1f0, 0x4ac280 with catch funclets 0x4ac13e .. 0x4ac2ee), the item '
                'members (ChangePropertyItem deleting dtor 0x4acac0, MarkerItem 0x4ae9a0, NewInstanceItem / '
                'DeleteInstanceItem 0x4afc70 / 0x4afd00 / 0x4afe90 / 0x4aff20 / 0x4aff70) and the '
                'list<shared_ptr<Replicator::Item> > members (0x4acb10, 0x4acb50, 0x4ad860, 0x4af100 ...)',
     'reason': 'Blocked, not attempted: Replicator::Item and its subclasses are nested in Replicator and no native '
               'header declares them (Replicator2008.h owner; proposal).'},
    {'address': 'Replicator-member templates (boost::bind / list3 / storage3 0x4ace50 / 0x4adbe0 / 0x4af830, '
                'function invokers / managers 0x4ae800 / 0x4ad6c0 / 0x4ad700, map<const Instance*, ...> '
                '0x4aec10 / 0x4aed00 / 0x4ae0f0, pointer-set find 0x4adfd0 / 0x4ae060, 0x4ae570 / 0x4ae690)',
     'reason': 'Blocked, not attempted: their element / bound types are Replicator members past +0x2b90 or '
               'Replicator member functions not declared by Replicator2008.h; the ICF-shared pointer-set bodies '
               'have no proven element type.'},
    {'address': 'Peer logger toggle 0x4ac9e0 and Peer network-simulator settings 0x4ae950',
     'reason': 'Not declared by Network/Peer2008.h (network-client-server2008 owner; proposal).'},
    {'address': 'reflection property templates 0x4accd0 .. 0x4ad360, 0x4adc90, 0x4adcf0, 0x4acb30, 0x4ae7b0, '
                '0x4ae7d0, 0x4ada80 .. 0x4adb20',
     'reason': 'Not attempted this batch: ConstProperty::getValue<T> / Property::setValue<T> instances (ICF-shared '
               'across value types); the value type of each must be proven from its type descriptor first.'},
    {'address': 'doDeclare-index jumps 0x4ac600 / 0x4ac610 (to 0x4ab470 / 0x4ab4d0: InterlockedIncrement on '
                '0x946610)', 'reason': 'Not attempted: the template they belong to is not identified.'},
]

REJECTED = {
    'template boost::detail::shared_count::shared_count<Marker>(Marker*) (explicit template argument list on the '
    'constructor)': 'C2143 on 21022; the deduced form `template shared_count::shared_count(Marker*);` is used.',
    'counting shared_count<Marker> 004ac040 at its 110-byte extent alone': 'the compiler emits the catch(...) funclet '
    'inside the body (131 B); compared split instead (head = row, tail = row 004ac0ae), never truncated.',
}

PROPOSALS = [
    'native-headers/Network/Replicator2008.h (Replicator family owner): declare Replicator::Item and its subclasses '
    'NewInstanceItem / DeleteInstanceItem / ChangePropertyItem / MarkerItem (RTTI vtables 00824b20, 00824b2c, '
    '00824828, 008246e8; shared_count(T*) rows 004ac0d0 / 004ac1f0 / 004ac160 / 004ac280 called by 004aff70, '
    '004b01e0, 004acdf0, 004ace20) and the members +0x2b90..+0x2d68 (incl. +0x2d4d bool disconnected, read by '
    'checkDisconnect 004aaf50). That unblocks checkDisconnect, the item rows and list<shared_ptr<Item> > members '
    'listed in not_exact.',
    'native-headers/Network/Peer2008.h (network-client-server2008 owner): declare the Peer logger toggle at 004ac9e0 '
    '(bool argument, ret 4: false -> rakPeer->DetachPlugin(logger) (slot 59) and reset; true -> logger.reset(new '
    '(0x210) PacketLogger-derived 004ab630(this)) then rakPeer->AttachPlugin (slot 58)) and the network-simulator '
    'apply at 004ae950 (rakPeer slot 64 with NetworkSettings 0049e890 +0x154 (int as double), +0x158 / +0x15c '
    '(unsigned short)). Peer::onEvent 004add50 is built here (native-classes/AppUnit4ACPeerHeartbeat.cpp) against '
    'the existing declaration; it could move into NetworkClientServer2008Peer.cpp with checkDisconnect once the '
    'Replicator +0x2d4d member is declared.',
    'BOUNDS note (server host; bounds.json not changed): shared_count(T*) rows 004ac040 / 004ac0d0 / 004ac160 / '
    '004ac1f0 / 004ac280 are each one function with their catch funclet rows 004ac0ae / 004ac13e / 004ac1ce / '
    '004ac25e / 004ac2ee (131 B extents; funclets reached only from the EH tables). This receipt verifies 004ac040 '
    'split at the current extents and counts both rows.',
]

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
counted_set = set(exact_rows)
receipt = {
    'class': 'RBX Network/Replicator.cpp COMDAT rows of the application range 004ac000..004b0000 (2008-06), inactive',
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
    'vtables': VT_OUT,
    'support_rows': support_out,
    'pending_rows': [],
    'not_exact': NOT_EXACT,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit4ac: %d counted exact rows (%s); 0 pending-build-only, %d range rows, %d counted elsewhere, '
      '%d support rows' % (len(exact_rows), ' '.join(exact_rows), len(RANGE_ROWS), len(range_counted), len(support_out)))
