"""Verify the inactive 2008-06 native rows of the application range 004b4000..004b8000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map` and `unit_map_checks`; rows counted by other receipts in
`range_rows_counted_by_other_receipts`, written as 'ADDR counted by RECEIPT' text, never as quoted bare addresses):
the whole range is Network/Replicator.cpp (it starts below 004b0000, app-unit4b0-2008 maps its head, and continues to
004ba22f, app-unit4b8 map): the BoundFuncDesc reflection bodies of Replicator / Peer (RequestCharacter, CloseConnection,
GetPlayer, LogPackets; static initializers 007f21d0..007f2280), Peer constructor / onServiceProvider, the
replication items' write/read bodies, the boost::signals slot / function instances bound to Replicator members, the
Stats::TypedStatsItem<bool> instances, shared_ptr<SharedStringDictionary>, ReplicatorStatsItem and the property
serialisation bodies. No library code (every boost / STL body here is a Roblox-instantiated template of this unit).

Build (document-swap flags, VS2008 RTM 21022, RakNet 3.x headers tools/rbxgs/Client/Network/raknet30/Source):
  * templates: native-classes/AppUnit4B4Templates.cpp, explicit instantiations against the read-only native headers
    stats/Stats.h and Network/IdSerializer.h (TypedStatsItem<bool>, Creatable<Instance>::create /
    Item::createBoundChildItem<bool>, shared_count(SharedStringDictionary*), the waitItems tree).
No new header (so no shadowing) and no pending build. Vtable slot checks (TypedStatsItem<bool> 00824e9c,
sp_counted_impl_p<SharedStringDictionary> 00824708) use this object, built from the current headers.

The shared_count constructor row 004b5d20 is the 110-byte head of the compiled function; its catch(...) funclet is the
separate row 004b5d8e (functions.jsonl splits the original 131-byte extent there): the head is compared over the row's
extent and the compiled remainder must equal the compiled funclet, which is compared with 004b5d8e.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, vtables by original RTTI name, own rows,
COMDAT support bodies by exactness at the bound address, rows counted by other receipts by that receipt, and the
remaining externals by evidence names / constructor vtable stores. A row is counted only when no other receipt counts
it. Writes work/2008-06/shared-layouts/app-unit4b4-working.json.
Set NATIVE_APP_UNIT4B4_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = R / 'out/app-unit4b4'
OUT.mkdir(parents=True, exist_ok=True)
RAKNET = ROOT / 'tools/rbxgs/Client/Network/raknet30/Source'
SOURCES = {'templates': R / 'native-classes/AppUnit4B4Templates.cpp'}
HEADERS = [R / 'native-headers/stats/Stats.h', R / 'native-headers/Network/IdSerializer.h']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT4B4_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit4b4-working.json'
LO, HI = 0x4b4000, 0x4b8000


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = ['/I' + str(RAKNET)] + nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build('NativeAppUnit4B4_' + _k, _src)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

TSB = '?$TypedStatsItem@_N@Stats@RBX@@'
SSD = 'VSharedStringDictionary@Network@RBX@@'
W = 'UWaitItem@IdSerializer@Network@RBX@@'
VW = 'V?$vector@' + W + 'V?$allocator@' + W + '@std@@@std@@'
GT = '?$_Tree@V?$_Tmap_traits@UData@Guid@RBX@@' + VW
# (address, symbol prefix, symbol suffix)
TEMPLATE_ROWS = [
    (0x4b51d0, '?update@' + TSB, 'MAEXXZ'),
    (0x4b5ca0, '??$create@V' + TSB + 'PB_N@?$Creatable@VInstance@RBX@@@RBX@@', ''),
    (0x4b60c0, '??$createBoundChildItem@_N@Item@Stats@RBX@@', ''),
    (0x4b5200, '??$checked_delete@' + SSD + '@boost@@', ''),
    (0x4b5e60, '?dispose@?$sp_counted_impl_p@' + SSD + '@detail@boost@@', ''),
    (0x4b7e10, '?_Erase@' + GT, ''),
]
# the shared_count constructor (head row) and its catch(...) funclet (separate row)
SPLIT_HEAD = (0x4b5d20, '??$?0' + SSD + '@shared_count@detail@boost@@QAE@PA' + SSD + '@Z')
SPLIT_FUNCLET = (0x4b5d8e, '__catch$' + SPLIT_HEAD[1] + '$0')
# COMDAT bodies the counted rows call: exact at the bound address, not counted here (outside this range or counted by
# no receipt but not claimed: support evidence only).
SUPPORT_SPEC = [
    (0x4ad560, '??$?0V' + TSB + 'VDeleter@?$Creatable@VInstance@RBX@@@2@@?$shared_ptr@V' + TSB + '@boost@@', ''),
]
# bodies counted by other receipts (bound by the call site; that receipt must count the address and this build's body
# must be exact there)
COUNTED_ELSEWHERE_SPEC = [
    (0x4b3d70, '??1SharedStringDictionary@Network@RBX@@QAE@XZ', '', 'network-replicator-working.json'),
    (0x5c9170, '??$formatValue@_N@Item@Stats@RBX@@QAEXAB_N@Z', '', 'stats-service-working.json'),
    (0x4a7fa0, '??1' + VW[1:] + 'QAE@XZ', '', 'app-unit49c-2008-working.json'),
]
EXTERNAL = {
    '??2@YAPAXI@Z': (0x6a0920, 'operator new (same binding as record_native_adorn.py / app_unit40c_2008)'),
    '??3@YAXPAX@Z': (0x6a067a, 'operator delete (same binding as record_native_adorn.py / app_unit40c_2008)'),
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': (0x55a8f0, 'evidence name'),
    '??R?$function0@_NV?$allocator@Vfunction_base@boost@@@std@@@boost@@QBE_NXZ': (0x42afc0, 'evidence name'),
    '??0?$TypedStatsItem@_N@Stats@RBX@@QAE@PB_N@Z': (0x4b5100, 'constructor: stores vtable 00824e9c (checked below)'),
}
EVIDENCE_NAMED = {'?setParent@Instance@RBX@@QAEXPAV12@@Z', '??R?$function0@_NV?$allocator@Vfunction_base@boost@@@std@@@boost@@QBE_NXZ'}
UNBOUND = []
binding = {}
support_out = {}
elsewhere_out = {}


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
assert SPLIT_HEAD[1] in BODIES and SPLIT_FUNCLET[1] in BODIES, 'shared_count(SharedStringDictionary*) not built'
SUPPORT = {resolve(FUNCS, a, p, s): a for a, p, s in SUPPORT_SPEC}
# a body defined in this object is resolved by prefix; an external (explicit specialization defined in its own unit)
# is keyed by its exact symbol and must carry that evidence name
COUNTED_ELSEWHERE = {(resolve(FUNCS, a, p, s) if any(n.startswith(p) for n in BODIES) else p): (a, rc)
                     for a, p, s, rc in COUNTED_ELSEWHERE_SPEC}
OWN = {name: address for address, name in ROWS}
OWN[SPLIT_HEAD[1]] = SPLIT_HEAD[0]
OWN[SPLIT_FUNCLET[1]] = SPLIT_FUNCLET[0]
INDEX = match._coff_data_index(raw)


def receipt_counts(receipt, address):
    data = json.loads((ROOT / 'work/2008-06/shared-layouts' / receipt).read_text())
    if 'exact_function_rows' in data:
        return '%08x' % address in data['exact_function_rows']
    found = []

    def walk(o):
        if isinstance(o, list):
            for e in o:
                walk(e)
        elif isinstance(o, dict):
            if o.get('exact') is True and str(o.get('address', '')).lower().lstrip('0x').zfill(8)[-8:] == '%08x' % address:
                found.append(o)
            for v in o.values():
                walk(v)
    walk(data)
    return bool(found)


def bind_value(name, size, target, address):
    sections, symbols, definitions, _ = INDEX
    start, section = definitions[name]
    table = sections[section]
    code = raw[table[4] + start:]
    verified, local = {}, set()
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if not 0 <= offset < size:
            continue
        symbol = symbols[index][0]
        assert kind in (6, 20), (name, symbol, 'unsupported relocation', kind)
        if kind == 20:
            value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        else:
            value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
        if nb.LOCAL_EH.match(symbol) and symbol not in OWN:
            local.add(symbol)
            continue
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
            how = '%s!%s' % hit
        elif symbol in OWN:
            assert OWN[symbol] == value, (name, symbol, hex(value), hex(OWN[symbol]))
            how = 'own row'
        elif symbol.startswith('??_7'):
            rtti, at = original.vtable_class(value)
            assert rtti == '.?AV' + symbol[4:symbol.index('@@6B') + 2], (name, symbol, hex(value), rtti)
            how = 'vtable RTTI %s offset %#x' % (rtti, at)
        elif symbol.startswith('??_R0') and symbol.endswith('@8'):
            rtti = original.string(value + 8)
            assert rtti == '.' + symbol[5:-2], (name, symbol, hex(value), rtti)
            how = 'RTTI %s' % rtti
        elif symbol in SUPPORT:
            assert SUPPORT[symbol] == value, (name, symbol, hex(value), hex(SUPPORT[symbol]))
            sbody, srefs = BODIES[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('support body not exact', symbol, hex(value))
            support_out.setdefault(symbol, {'address': '%08x support body, not counted' % value, 'reached_from': name,
                                            'note': 'COMDAT support body, exact at the bound address; not counted'})
            how = 'support body exact at the bound address'
        elif symbol in COUNTED_ELSEWHERE:
            at, receipt = COUNTED_ELSEWHERE[symbol]
            assert at == value, (name, symbol, hex(value), hex(at))
            assert receipt_counts(receipt, value), (symbol, receipt)
            if symbol in BODIES:
                sbody, srefs = BODIES[symbol]
                starget, strefs = target_of(value)
                assert match.exact_match(starget, strefs, sbody, srefs), ('counted-elsewhere body not exact', symbol,
                                                                          hex(value))
                how = 'counted by %s (this build exact there)' % receipt
            else:
                assert names.get(value) == symbol, (symbol, hex(value), names.get(value))
                how = 'counted by %s (external here; evidence name)' % receipt
            elsewhere_out[symbol] = '%08x %s' % (value, how)
        elif symbol in EXTERNAL:
            at, why = EXTERNAL[symbol]
            assert at == value, (name, symbol, hex(value), hex(at))
            if symbol in EVIDENCE_NAMED:
                assert names.get(at) == symbol, (symbol, hex(at), names.get(at))
            how = 'external: ' + why
        else:
            UNBOUND.append('    %r: %#x,   # %s in %s' % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        prev = binding.setdefault(symbol, (value, name))
        assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


def verify_row(address, name, body, refs, note=None, split_head=False):
    target, target_refs = target_of(address)
    if split_head and len(body) > len(target):   # split head only: compare over the row's extent
        refs = [r for r in refs if r + 4 <= len(target)]
        body = body[:len(target)]
    exact = len(body) == len(target) and match.exact_match(target, target_refs, body, refs)
    entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
             'exact': exact, 'unit': 'templates'}
    if note:
        entry['note'] = note
    if not exact:
        assert DISCOVER, (name, entry['address'], len(body), len(target))
        return entry
    assert set(target_refs) <= set(refs), (name, 'missing original relocation')
    verified, local = bind_value(name, len(body), target, address)
    entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
    return entry


counted = [verify_row(a, n, *BODIES[n]) for a, n in ROWS]
head_body, head_refs = BODIES[SPLIT_HEAD[1]]
fun_body, fun_refs = BODIES[SPLIT_FUNCLET[1]]
head_len = len(target_of(SPLIT_HEAD[0])[0])
assert head_len + len(fun_body) == len(head_body), (head_len, len(fun_body), len(head_body))
assert head_body[head_len:] == fun_body, 'compiled remainder of the shared_count body is not its catch funclet'
assert SPLIT_HEAD[0] + head_len == SPLIT_FUNCLET[0], 'the funclet row does not follow the head row'
counted.append(verify_row(SPLIT_HEAD[0], SPLIT_HEAD[1], head_body, head_refs,
                          'head of the 131-byte compiled shared_count constructor; the compiled remainder equals the '
                          'catch(...) funclet row 004b5d8e (BOUNDS evidence: one original extent 004b5d20..004b5da2)',
                          split_head=True))
counted.append(verify_row(SPLIT_FUNCLET[0], SPLIT_FUNCLET[1], fun_body, fun_refs,
                          'catch(...) funclet of the shared_count(SharedStringDictionary*) constructor: '
                          'checked_delete(p); throw;'))

# the non-exact TypedStatsItem<bool> constructor is bound by its vtable store
ctor_target = target_of(0x4b5100)[0]
assert b'\xc7\x06' + struct.pack('<I', 0x824e9c) in ctor_target
assert original.vtable_class(0x824e9c)[0] == '.?AV?$TypedStatsItem@_N@Stats@RBX@@'
ctor_entry = {'address': '004b5100 (not exact, not counted)', 'symbol': '??0?$TypedStatsItem@_N@Stats@RBX@@QAE@PB_N@Z',
              'size': len(BODIES['??0?$TypedStatsItem@_N@Stats@RBX@@QAE@PB_N@Z'][0]), 'target_size': len(ctor_target),
              'exact': False}


# ---- vtable slot checks (object built from the current headers) ---------------------------------------------------
def compiled_vtable(symbol):
    sections, symbols, definitions, _ = INDEX
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, sym, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[sym][0]
    return [slots[i] for i in range(len(slots))]


def d(a):
    return struct.unpack('<I', original.data(a, 4))[0]


VTABLE_CHECKS = []
SLOT_EXPECT = {'?destroy@sp_counted_base@detail@boost@@UAEXXZ': 0x405e10}
for vsym_prefix, vt, required in (('??_7' + TSB, 0x824e9c, {16: 0x4b51d0}),
                                  ('??_7?$sp_counted_impl_p@' + SSD + '@detail@boost@@', 0x824708,
                                   {1: 0x4b5e60, 2: 0x405e10})):
    sections, symbols, definitions, _ = INDEX
    # the primary vtable (offset 0): the one that holds the class's own new virtual (update / dispose)
    cands = [s for s in definitions if s.startswith(vsym_prefix) and '@@6B' in s
             and any(x in OWN and OWN[x] in required.values() for x in compiled_vtable(s))]
    assert len(cands) == 1, (vsym_prefix, cands)
    assert original.vtable_class(vt)[1] == 0, hex(vt)
    rtti = original.vtable_class(vt)[0]
    assert rtti == '.?AV' + cands[0][4:cands[0].index('@@6B') + 2], (hex(vt), rtti)
    slots = compiled_vtable(cands[0])
    checked, named = [], []
    for i, slot in enumerate(slots):
        value = d(vt + 4 * i)
        want = OWN.get(slot, SLOT_EXPECT.get(slot, binding.get(slot, (None,))[0]))
        if want is not None:
            assert want == value, (cands[0][:60], i, slot, hex(value), hex(want))
            checked.append(i)
        elif names.get(value) == slot:
            named.append(i)
    for i, at in required.items():
        assert i in checked and d(vt + 4 * i) == at, (hex(vt), i)
    VTABLE_CHECKS.append({'vtable': 'vtable %08x' % vt, 'rtti': rtti, 'compiled_slots': len(slots),
                          'slots_bound_and_equal': checked, 'slots_equal_by_evidence_name': named})

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for r in counted:
        if not r['exact']:
            print('NOT EXACT', r['address'], r['symbol'][:90], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, UNBOUND
assert all(r['exact'] for r in counted)
assert set(SUPPORT) <= set(binding) and set(COUNTED_ELSEWHERE) <= set(binding), 'unused support binding'


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


# ---- unit-map evidence checks (strings, RTTI, static initializers, evidence names) ---------------------------------
def cstr(a, n=96):
    return original.data(a, n).split(b'\0')[0].decode('latin-1')


MAP_CHECKS = []
for at, want in ((0x8256d4, 'RequestCharacter'), (0x8256e8, 'CloseConnection'), (0x8256f8, 'GetPlayer'),
                 (0x825704, 'LogPackets'), (0x824cdc, 'Packets Thread'), (0x8244e4, 'NetworkReplicator'),
                 (0x8244d8, 'NetworkPeer')):
    assert cstr(at) == want, (hex(at), cstr(at))
    MAP_CHECKS.append('string %s %r' % (hex(at), want))
for vt, want in ((0x824cb4, '.?AV?$BoundFuncDesc@VReplicator@Network@RBX@@$$A6AXXZ$0A@@Reflection@RBX@@'),
                 (0x824cc0, '.?AV?$BoundFuncDesc@VReplicator@Network@RBX@@$$A6A?AV?$shared_ptr@VInstance@RBX@@@boost@@XZ$0A@@Reflection@RBX@@'),
                 (0x824ccc, '.?AV?$BoundFuncDesc@VPeer@Network@RBX@@$$A6AX_N@Z$00@Reflection@RBX@@'),
                 (0x824e9c, '.?AV?$TypedStatsItem@_N@Stats@RBX@@'),
                 (0x824708, '.?AV?$sp_counted_impl_p@VSharedStringDictionary@Network@RBX@@@detail@boost@@'),
                 (0x824fbc, '.?AVReplicatorStatsItem@Replicator@Network@RBX@@'),
                 (0x824944, '.?AVPeer@Network@RBX@@'), (0x8254fc, '.?AVReplicator@Network@RBX@@')):
    rtti = original.vtable_class(vt)
    assert rtti and rtti[0] == want, (hex(vt), rtti)
    MAP_CHECKS.append('vtable %s RTTI %s' % (hex(vt), want))


def rel_call(at):
    assert original.data(at, 1) == b'\xe8', hex(at)
    return (at + 5 + struct.unpack('<i', original.data(at + 1, 4))[0]) & 0xffffffff


# static initializers of the reflection descriptors: (call site, ctor, name string push, member function push)
for call, ctor, string, member in ((0x7f21e5, 0x4b40a0, 0x8256d4, 0x4b49e0), (0x7f2215, 0x4b40a0, 0x8256e8, 0x4aafd0),
                                   (0x7f2245, 0x4b4170, 0x8256f8, 0x4ae860), (0x7f227a, 0x4b4240, 0x825704, 0x4ac9e0)):
    assert rel_call(call) == ctor, hex(call)
    window = original.data(call - 0x1a, 0x1a)
    assert struct.pack('<I', string) in window and struct.pack('<I', member) in window, hex(call)
    MAP_CHECKS.append('static initializer call %s -> BoundFuncDesc ctor %s (name %s, member %s)'
                      % (hex(call), hex(ctor), cstr(string), hex(member)))
for at, want in ((0x4b5950, '??R?$signal0@XU?$last_value@X@'), (0x4b62c0, '??0ReplicatorStatsItem@Replicator@Network@RBX@@'),
                 (0x4b6530, '?update@ReplicatorStatsItem@Replicator@Network@RBX@@'),
                 (0x4b6d10, '?write@ChangePropertyItem@Replicator@Network@RBX@@'),
                 (0x4b47b0, '?write@DeleteInstanceItem@Replicator@Network@RBX@@'),
                 (0x4b5700, '?onServiceProvider@Peer@Network@RBX@@'),
                 (0x4b7e50, '??$create@VReplicatorStatsItem@Replicator@Network@RBX@@')):
    assert names.get(at, '').startswith(want), (hex(at), names.get(at))
    MAP_CHECKS.append('evidence name %s %s' % (hex(at), names[at][:80]))
# callers of the rows built here
for call, callee in ((0x4b63a9, 0x4b60c0), (0x5afe8f, 0x4b60c0), (0x4b67c0, 0x4b5d20), (0x4b5d92, 0x4b5200),
                     (0x4b60e8, 0x4b5ca0), (0x4b5ce9, 0x4b5100)):
    assert rel_call(call) == callee, (hex(call), hex(callee))
    MAP_CHECKS.append('call %s -> %s' % (hex(call), hex(callee)))

UNIT_MAP = {
    'replicator 004b4000..004b7fff (whole range)': (
        'Network/Replicator.cpp continued (head below 004b0000 in app-unit4b0-2008, tail to 004ba22f in app-unit4b8). '
        'BoundFuncDesc bodies 004b4040..004b42e0: execute / constructor of BoundFuncDesc<Replicator, void()> (vtable '
        '00824cb4; RequestCharacter 004b49e0 and CloseConnection 004aafd0, static initializers 007f21d0 / 007f2200), '
        '<Replicator, shared_ptr<Instance>()> (00824cc0; GetPlayer 004ae860, 007f2230) and <Peer, void(bool)> '
        '(00824ccc; LogPackets 004ac9e0, 007f2260, argument "value"); the multi_index delete_all_nodes 004b43c0; the '
        'boost::signals slot / function0 instances bound to Replicator members 004b4410 / 004b44c0 / 004b45b0 / '
        '004b4d80 / 004b5050 / 004b5220 / 004b5be0 / 004b5db0 / 004b61d0 and the connect helpers 004b5f60 / 004b7d30; '
        'Peer::Peer 004b4640 ("Packets Thread"); DeleteInstanceItem::write 004b47b0 (+ eh 004b4965); requestCharacter '
        '004b49e0; the signal-instance creators 004b4bb0 / 004b52b0 (Security::Impersonator, map<const '
        'SignalDescriptor*, ...>); Stats::Item create 004b4e50; slot_call_iterator / signal0 / signal2 bodies 004b4ed0 / '
        '004b4fb0 / 004b5950 / 004b5a70 and SignalDescImpl::fire 004b5f40 / 004b6040; TypedStatsItem<bool> 004b5100 / '
        '004b51d0 / 004b5ca0 / createBoundChildItem<bool> 004b60c0; Peer::onServiceProvider 004b5700 ("Network"); '
        'shared_ptr<SharedStringDictionary> 004b5d20 (+ catch 004b5d8e) / checked_delete 004b5200 / dispose 004b5e60; '
        'the physics receiver 004b58f0 / 004b5e80 / 004b6290; the Replicator member 004b5ed0 (push_back on the vector +0x2c58, then 004b52b0); '
        'ReplicatorStatsItem 004b62c0..004b6710 (vtable 00824fbc; ??_E thunks 004b64b0..004b6520); the signal-instance '
        'map lookup 004b6730 (+0x2b90, new 0x2a24 SharedStringDictionary); property serialisation 004b6890 / 004b6ab0; '
        'ChangePropertyItem::write 004b6d10; the item readers 004b6f00 / 004b7250 / 004b7a30 / 004b7f20; the waitItems '
        'tree _Erase 004b7e10; create<ReplicatorStatsItem> 004b7e50. No library code.'),
}

NOT_EXACT = [
    {'address': 'TypedStatsItem<bool> constructor 004b5100',
     'reason': 'Known Stats.h gap (as TypedStatsItem<unsigned int> 005bc860, <int> 0045eef0, <G3D::Stopwatch> '
               '0045ecc0 in their receipts): the original inlines boost::function0::assign_to down to has_empty_target '
               '(194 bytes); this build keeps assign_to out of line (%d bytes). Bound by its vtable store only.'
               % ctor_entry['size']},
    {'address': 'BoundFuncDesc rows 004b4040, 004b40a0, 004b4110, 004b4170, 004b41e0, 004b4240, 004b42e0',
     'reason': 'Blocked, not attempted: the descriptors bind member pointers to Replicator::requestCharacter() '
               '004b49e0 / closeConnection() 004aafd0 / getPlayer() 004ae860 and Peer::logPackets(bool) 004ac9e0, '
               'which the read-only Network/Replicator2008.h / Peer2008.h do not declare (proposals below).'},
    {'address': 'Replicator / Peer members 004b47b0, 004b49e0, 004b4bb0, 004b52b0, 004b5700, 004b5ed0, 004b62c0, '
                '004b6530, 004b6730, 004b6890, 004b6ab0, 004b6d10, 004b6f00, 004b7250, 004b7a30, 004b7f20',
     'reason': 'Blocked, not attempted: they read Replicator members past +0x2b90 (or Replicator::Item / '
               'ChangePropertyItem / DeleteInstanceItem, not declared natively) that Network/Replicator2008.h leaves '
               'pending; Peer::onServiceProvider 004b5700 is declared only in Peer2008.h (owner network-client-server).'},
    {'address': 'slot / function instances 004b4410, 004b44c0, 004b45b0, 004b4d80, 004b5050, 004b5220, 004b5be0, '
                '004b5db0, 004b61d0, 004b5f60, 004b7d30',
     'reason': 'Blocked, not attempted: their functors are boost::bind_t over Replicator member functions (mf2 / '
               'value<shared_ptr<...>>) that no native header declares; the bound types follow from the pending '
               'Replicator members.'},
    {'address': 'ReplicatorStatsItem ??_E thunks 004b64b0..004b6520 and ??_G 004b6710',
     'reason': 'Bytes equal to this build\'s TypedStatsItem<bool> / Item thunks, but their relocations name '
               'ReplicatorStatsItem\'s own ??_G 004b6710 / destructor 004b6690, emitted only with the (open) '
               'ReplicatorStatsItem constructor (network-replicator2008 receipt); not claimable here.'},
]

REJECTED = {
    'counting 004b5d20 at the compiled 131-byte extent':
        'functions.jsonl splits the original extent at the catch funclet 004b5d8e (110 + 21 bytes); the head is '
        'compared over the row extent and the remainder is proven equal to the funclet row instead.',
}

PROPOSALS = [
    'native-headers/Network/Replicator2008.h (Replicator family owner): declare the reflected members '
    'void requestCharacter() 004b49e0 (static initializer 007f21d0, "RequestCharacter"), void closeConnection() '
    '004aafd0 (007f2200, "CloseConnection") and boost::shared_ptr<Instance> getPlayer() 004ae860 (007f2230, '
    '"GetPlayer"); they unblock BoundFuncDesc<Replicator, void()> (vtable 00824cb4: constructor 004b40a0, execute '
    '004b4110) and BoundFuncDesc<Replicator, shared_ptr<Instance>()> (00824cc0: constructor 004b4170, execute '
    '004b4040 with invoke 004b3fa0). Together with the pending +0x2b90..+0x2d68 members (app-unit4b8 proposal) they '
    'also unblock the ReplicatorStatsItem constructor 004b62c0 (then ??_E thunks 004b64b0..004b6520 / ??_G 004b6710 / '
    'destructor 004b6690) and the signal-instance lookup 004b6730.',
    'native-headers/Network/Peer2008.h (network-client-server owner): declare void logPackets(bool) 004ac9e0 '
    '(static initializer 007f2260, "LogPackets", argument "value"); unblocks BoundFuncDesc<Peer, void(bool)> '
    '(vtable 00824ccc: constructor 004b4240, execute 004b42e0).',
    'work/2008-06/bounds.json (server host): 004b5d20 and 004b5d8e are one original 131-byte extent (shared_count '
    'constructor with its catch(...) funclet), like the pinned Creatable shared_count rows; BOUNDS evidence only.',
]

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
counted_set = set(exact_rows)
receipt = {
    'class': 'RBX::Network Replicator.cpp rows of the application range 004b4000..004b8000 (2008-06), inactive',
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
    'compiled_not_exact': [ctor_entry],
    'support_rows': support_out,
    'counted_elsewhere_targets': sorted(elsewhere_out.values()),
    'vtable_checks': VTABLE_CHECKS,
    'pending_rows': [],
    'not_exact': NOT_EXACT,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit4b4: %d counted exact rows (%s); 0 pending-build-only, %d range rows, %d counted elsewhere, '
      '%d support rows' % (len(exact_rows), ' '.join(exact_rows), len(RANGE_ROWS), len(range_counted), len(support_out)))
