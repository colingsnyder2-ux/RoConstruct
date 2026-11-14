"""Verify the inactive 2008-06 native rows of the application range 004b0000..004bc000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map`; rows counted by other receipts in
`range_rows_counted_by_other_receipts`, written as 'ADDR counted by RECEIPT' text, never as quoted bare addresses):
  * the Network/Replicator.cpp unit (starts below 004b0000) with its STL / boost / reflection instances, up to the
    Replicator constructor 004b9bd0 (ends 004ba225). Mostly counted by the network-replicator receipts. Its
    reflection-signal instances for void() and void(std::string, bool) (boost::any holders, signal0/signal2 connect
    and operator(), TSignalInstance, SignalDescImpl::fire) are built here: native-classes/AppUnit4B0_2008Signals.cpp
    against the read-only reflection/signal.h.
  * the joint-creator block 004b21c0..004b337f: FactoryProduct<C, D, N>::Creator::create() const,
    shared_count(C*, Deleter), shared_ptr<C>(C*, Deleter) and Creatable<Instance>::create<C>() for Lighting and the
    seven 2008 joint classes. Built here: native-classes/AppUnit4B0_2008Joints.cpp against the read-only
    v8datamodel/JointInstance.h, v8datamodel/Lighting2008.h and util/Object.h.
  * RakNet 3.x library code from 004ba230 (DataStructures templates, PacketLogger.cpp 004baa10..004bb39f,
    RakPeerInterface / RakPeer.cpp from 004bb3a0, continuing past 004bc000): never recovered here.

Build (document-swap flags, VS2008 RTM 21022, /fp:fast): the unit against the committed native headers only. There is
no pending build: every counted row is exact against the current headers.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, own symbols by the row proven here, bodies of
rows counted by other receipts by exactness at the bound address (or, for create<Lighting>, by the lighting2008
receipt that counts it), constructors by evidence name or by the vtable they store (original RTTI). The Creator rows
are also proven by the original Creator vtables: slot 0 of each is the row, and the vtable's RTTI names the class.
A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit4b0-2008-working.json.
Set NATIVE_APP_UNIT4B0_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = R / 'out/app-unit4b0-2008'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {'joints': R / 'native-classes/AppUnit4B0_2008Joints.cpp',
           'signals': R / 'native-classes/AppUnit4B0_2008Signals.cpp'}
HEADERS = [R / 'native-headers' / h for h in ('v8datamodel/JointInstance.h', 'v8datamodel/Lighting2008.h',
                                               'util/Object.h', 'reflection/signal.h')]
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT4B0_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit4b0-2008-working.json'
UNIT_FLAGS = ['/fp:fast']
LO, HI = 0x4b0000, 0x4bc000


def build(name, src, extra=(), include=()):
    obj = OUT / (name + '.obj')
    flags = ['/I' + str(p) for p in include] + nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build('NativeAppUnit4B0_2008_' + _k, _src, UNIT_FLAGS)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

CI = '?$Creatable@VInstance@RBX@@@'
DEL = 'VDeleter@' + CI


def creator(c, base, mangle='3PADA'):
    return '?create@Creator@?$FactoryProduct@V%s@RBX@@V%s@2@$1?s%s@2@%s@RBX@@UBE?AV?$shared_ptr@VObject@RBX@@@boost@@XZ' % (
        c, base, c, mangle)


def create(c):
    return '??$create@V%s@RBX@@@%sRBX@@SA?AV?$shared_ptr@V%s@RBX@@@boost@@XZ' % (c, CI, c)


def sptr(c):
    return '??$?0V%s@RBX@@%s1@@?$shared_ptr@V%s@RBX@@@boost@@QAE@PAV%s@RBX@@%s3@@Z' % (c, DEL, c, c, DEL)


def scount(c):
    return '??$?0PAV%s@RBX@@%s1@@shared_count@detail@boost@@QAE@PAV%s@RBX@@%s4@@Z' % (c, DEL, c, DEL)


# Class -> (Creator::create, shared_count, shared_ptr ctor, create<C>, constructor C(), Creator vtable)
JOINTS = {
    'Lighting': (0x4b21c0, None, None, None, None, 0x824bac),
    'Snap': (0x4b2430, 0x4b2270, 0x4b2300, 0x4b23b0, 0x5e4600, 0x824bb4),
    'Weld': (0x4b26a0, 0x4b24e0, 0x4b2570, 0x4b2620, 0x5e4810, 0x824bd0),
    'Glue': (0x4b2910, 0x4b2750, 0x4b27e0, 0x4b2890, 0x5e49a0, 0x824bec),
    'Rotate': (0x4b2b80, 0x4b29c0, 0x4b2a50, 0x4b2b00, 0x5e4ad0, 0x824c08),
    'RotateP': (0x4b2df0, 0x4b2c30, 0x4b2cc0, 0x4b2d70, 0x5e4c60, 0x824c24),
    'RotateV': (0x4b3060, 0x4b2ea0, 0x4b2f30, 0x4b2fe0, 0x5e4dd0, 0x824c40),
    'Motor': (0x4b32d0, 0x4b3110, 0x4b31a0, 0x4b3250, 0x5e4ee0, 0x824c5c),
}
# rows of the block counted by other receipts (bound by call site; bodies must be exact at that address)
OTHER_RECEIPT = {'Snap': 'humanoid2008', 'Motor': 'humanoid2008'}

ROWS = []
for c, (cr, sc, sp, cc, ctor, vt) in JOINTS.items():
    ROWS.append((cr, creator(c, 'Instance' if c == 'Lighting' else 'AutoJoint')))
    if c in ('Lighting',) or c in OTHER_RECEIPT:
        continue
    ROWS += [(sp, sptr(c)), (cc, create(c))]

# ---- reflection-signal instances (AppUnit4B0_2008Signals.cpp) ---------------------------------------------------------
STR = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
F0 = 'V?$function@$$A6AXXZV?$allocator@X@std@@@boost@@'
F2 = 'V?$function@$$A6AX' + STR + '_N@ZV?$allocator@X@2@@boost@@'
H0 = '?$holder@' + F0 + '@any@boost@@'
H2 = '?$holder@' + F2 + '@any@boost@@'
TS2 = '?$TSignalDesc@$$A6AX' + STR + '_N@Z@Reflection@RBX@@'
SIGNAL_ROWS = [
    (0x4b1940, '??0' + H0 + 'QAE@'), (0x4b1dc0, '??0' + H2 + 'QAE@'),
    (0x4b19a0, '?type@' + H0 + 'UBE'), (0x4b1e20, '?type@' + H2 + 'UBE'),
    (0x4b19b0, '?clone@' + H0 + 'UBE'), (0x4b1e30, '?clone@' + H2 + 'UBE'),
    (0x4b1aa0, '??$?0' + F0 + '@any@boost@@QAE@'), (0x4b1f20, '??$?0' + F2 + '@any@boost@@QAE@'),
    # connect(const slot&, connect_position), not the grouped connect(const int&, const slot&, connect_position)
    (0x4b1b00, ('?connect@?$signal0@XU?$last_value@X@boost@@', 'signals@2@ABV?$slot@')),
    (0x4b1f80, ('?connect@?$signal2@X' + STR + '_NU?$last_value', 'signals@2@ABV?$slot@')),
    (0x4b20e0, '??0TSignalInstance@' + TS2), (0x4b2150, '?newSignalInstance@' + TS2),
    (0x4b4fb0, '??$?RV?$slot_call_iterator@U?$caller@' + STR + '_N' + F2),
    (0x4b5f40, '?fire@?$SignalDescImpl@$0A@$$A6AXXZ@Reflection@RBX@@'),
    (0x4b6040, '?fire@?$SignalDescImpl@$01$$A6AX' + STR + '_N@Z@Reflection@RBX@@'),
]

EXTERNAL = {
    # create<Lighting> 004adb60 (Lighting Creator call 004b21e5): counted by lighting2008-working.json, which builds it
    # against its own Lighting declaration; this build's copy is not compared (it is not a row of this range).
    create('Lighting'): 0x4adb60,
}
COUNTED_ELSEWHERE = {}
for c, (cr, sc, sp, cc, ctor, vt) in JOINTS.items():
    if sc:
        COUNTED_ELSEWHERE[scount(c)] = (sc, 'creatable-shared-count')
    if c in OTHER_RECEIPT:
        COUNTED_ELSEWHERE[create(c)] = (cc, OTHER_RECEIPT[c])
    if ctor:
        EXTERNAL['??0%s@RBX@@QAE@XZ' % c] = ctor
# signal-unit bodies whose original address is a row counted by another receipt (bound by the call site; the compiled
# body must be relocation-masked exact there). Keys are symbol prefixes.
COUNTED_PREFIX = {
    '??R?$signal0@XU?$last_value@X@boost@@': (0x4b5950, 'humanoid2008'),   # fire 004b5f40
}
# ICF-shared generic bodies outside this range (one copy serves several signal signatures): accepted only when the
# compiled body is relocation-masked exact at the bound address; support rows, never counted here.
SUPPORT = {
    '??$?RUconnection_slot_pair@detail@signals@boost@@@?$caller@' + STR + '_N' + F2: 0x4ad760,   # 004b4fb0
    '?equal@?$slot_call_iterator@U?$caller@' + STR + '_N' + F2: 0x40b050,                       # signal2 operator()
    '?increment@?$slot_call_iterator@U?$caller@' + STR + '_N' + F2: 0x499ed0,                   # signal2 operator()
    '??0?$slot_call_iterator@U?$caller@' + STR + '_N' + F2: 0x4908a0,                           # signal2 operator()
    '??0?$args2@' + STR + '_NH@detail@signals@boost@@': 0x4ab090,                               # signal2 operator()
}
# boost.signals library bodies (signal_base.cpp / named_slot_map.cpp, not instantiated on RBX types), bound by the call
# sites in signal2::operator() 004b5a70.
for _sym, _value in (
        ('??0call_notification@detail@signals@boost@@QAE@ABV?$shared_ptr@Vsignal_base_impl@detail@signals@boost@@@3@@Z', 0x56a760),
        ('??1call_notification@detail@signals@boost@@QAE@XZ', 0x56a650),
        ('?begin@named_slot_map@detail@signals@boost@@QAE?AVnamed_slot_map_iterator@234@XZ', 0x571380),
        ('?end@named_slot_map@detail@signals@boost@@QAE?AVnamed_slot_map_iterator@234@XZ', 0x5713b0)):
    EXTERNAL[_sym] = _value
# boost signal constructor: one ICF-shared body 00499c00 for every signature (callers 0041b3f0, 0048e2d0, 004b1c60,
# 004b20e0, 00556220 ...; humanoid2008 binds it the same way). Bound by the call site 004b2116; its body is not
# compared (the original calls 0060a2f0 there, a boost.function config difference not built here).
SIG2 = ('?$signal2@X' + STR + '_NU?$last_value@X@boost@@HU?$less@H@2@V?$function@$$A6AX' + STR
        + '_N@ZV?$allocator@X@2@@4@@boost@@')
EXTERNAL['??0' + SIG2 + 'QAE@ABU?$last_value@X@1@ABU?$less@H@std@@@Z'] = 0x499c00
# signal2<void, std::string, bool>::operator() 004b5a70 (called by fire 004b6040) is an own row (SIGNAL_ROWS).
SIGNAL_ROWS.append((0x4b5a70, '??R' + SIG2 + 'QAE?AUunusable@?$last_value@X@1@' + STR + '_N@Z'))
# boost.signals library bodies (signal_base.cpp / slot.cpp, not instantiated on RBX types), bound by the call sites in
# connect 004b1b00 / 004b1f80: connect_slot 0056a900; slot_base::get_data 004915b0 (ICF-shared with the evidence name
# CopyOnWrite<vector<shared_ptr<Instance> > >::read: the same shared_ptr copy body).
EXTERNAL['?connect_slot@signal_base_impl@detail@signals@boost@@QAE?AVconnection@34@ABVany@4@ABVstored_group@234@V?$shared_ptr@Udata_t@slot_base@detail@signals@boost@@@4@W4connect_position@34@@Z'] = 0x56a900
EXTERNAL['?get_data@slot_base@detail@signals@boost@@QBE?AV?$shared_ptr@Udata_t@slot_base@detail@signals@boost@@@4@XZ'] = 0x4915b0
EXTERNAL['?findSignalInstance@SignalDescriptor@Reflection@RBX@@IBEPAVSignalInstance@23@PBVSignalSource@23@@Z'] = 0x56b620
VTABLES = {
    '??_7' + H0 + '6B@': (0x824b7c, '.?AV' + H0),
    '??_7' + H2 + '6B@': (0x824b94, '.?AV' + H2),
    '??_7TSignalInstance@' + TS2 + '6B@': (0x824ba4, '.?AVTSignalInstance@' + TS2),
    '??_7SignalInstance@Reflection@RBX@@6B@': (0x80ece0, '.?AVSignalInstance@Reflection@RBX@@'),
}
support_out = {}
UNBOUND = []
binding = {}


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
            print('UNRESOLVED', '%08x' % address, key[:120])
            continue
        assert len(hits) == 1, ('%08x' % address, key)
        out.append((address, hits[0][0]))
    return out


def ctor_vtable(address):
    """The first `mov dword ptr [reg], imm32` vtable store of a constructor body (C7 00/06/07 imm32)."""
    body, _ = target_of(address)
    found = []
    for i in range(len(body) - 6):
        if body[i] == 0xc7 and body[i + 1] in (0x00, 0x06, 0x07):
            v = struct.unpack_from('<I', body, i + 2)[0]
            try:
                c = original.vtable_class(v)
            except Exception:
                c = None
            if c:
                found.append((v, c))
    return found


def prefixed(table, symbol):
    for prefix, value in table.items():
        if symbol.startswith(prefix):
            return value
    return None


def bind_value(raw, sections, symbols, definitions, bodies, name, body, target, address, own):
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
        elif symbol in VTABLES:
            vt, rtti = VTABLES[symbol]
            assert vt == value and original.vtable_class(vt) == (rtti, 0), (name, symbol, hex(value), original.vtable_class(value))
            how = 'vtable by RTTI %s' % rtti
        elif symbol.startswith('??_R0?') and symbol.endswith('@8'):
            want = ('.' + symbol[5:-2]).encode()
            assert original.data(value + 8, len(want) + 1) == want + b'\0', (name, symbol, hex(value))
            how = 'type descriptor %s (by bytes)' % want.decode()
        elif prefixed(COUNTED_PREFIX, symbol) is not None:
            other = prefixed(COUNTED_PREFIX, symbol)
            assert other[0] == value, (name, symbol, hex(value), hex(other[0]))
            sbody, srefs = bodies[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('counted-elsewhere body not exact', symbol, hex(value))
            how = 'body exact at the bound address; row counted by %s' % other[1]
        elif prefixed(SUPPORT, symbol) is not None:
            sup = prefixed(SUPPORT, symbol)
            assert sup == value, (name, symbol, hex(value), hex(sup))
            sbody, srefs = bodies[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('support body not exact', symbol, hex(value))
            support_out.setdefault(symbol, {'address': hex(value), 'reached_from': name,
                                            'note': 'ICF-shared support body, exact at the bound address; not counted'})
            how = 'support body exact at the bound address'
        elif symbol in COUNTED_ELSEWHERE:
            other = COUNTED_ELSEWHERE[symbol]
            assert other[0] == value, (name, symbol, hex(value), hex(other[0]))
            sbody, srefs = bodies[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('counted-elsewhere body not exact', symbol, hex(value))
            how = 'body exact at the bound address; row counted by %s' % other[1]
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            if names.get(value, '') == symbol:
                how = 'external (evidence name)'
            elif symbol.startswith('??0') and symbol.endswith('@RBX@@QAE@XZ'):
                cls = symbol[3:-len('@RBX@@QAE@XZ')]
                stores = ctor_vtable(value)
                assert any(c[0] == '.?AV%s@RBX@@' % cls and c[1] == 0 for _, c in stores), (symbol, hex(value), stores)
                how = 'external constructor (stores the .?AV%s@RBX@@ vtable %s)' % (
                    cls, ' '.join(hex(v) for v, c in stores if c[0] == '.?AV%s@RBX@@' % cls))
            else:
                how = 'external'
        else:
            UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        prev = binding.setdefault(symbol, (value, name))
        assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


def verify(which, rows, own):
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
            assert DISCOVER, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        verified, local = bind_value(raw, sections, symbols, definitions, bodies, name, body, target, address, own)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


ROWS_BY_OBJ = {'joints': ROWS, 'signals': SIGNAL_ROWS}
resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS_BY_OBJ.items()}
counted = []
for k, rows in resolved.items():
    own = {name: address for address, name in rows}
    for r in verify(k, rows, own):
        r['unit'] = k
        counted.append(r)
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for r in counted:
        if not r['exact']:
            print('NOT EXACT', r['address'], r['symbol'][:90], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, UNBOUND
assert all(r['exact'] for r in counted)

# ---- Creator vtables (original): slot 0 is the counted Creator::create row; the RTTI names the class -------------------
TEXT_SECTION = next(x for x in original.pe.sections if x.Name.startswith(b'.text'))
TEXT = (original.image + TEXT_SECTION.VirtualAddress,
        original.image + TEXT_SECTION.VirtualAddress + TEXT_SECTION.Misc_VirtualSize)
creator_vtables = []
for c, (cr, sc, sp, cc, ctor, vt) in JOINTS.items():
    rtti, at = original.vtable_class(vt)
    base, mangle = ('Instance', '3PADA') if c == 'Lighting' else ('JointInstance', '3QBDB')
    want = '.?AVCreator@?$FactoryProduct@V%s@RBX@@V%s@2@$1?s%s@2@%s@RBX@@' % (c, base, c, mangle)
    assert (rtti, at) == (want, 0), (c, hex(vt), rtti, at)
    assert d(vt) == cr, (c, hex(vt), hex(d(vt)), hex(cr))
    slots = 0
    while TEXT[0] <= d(vt + 4 * slots) < TEXT[1]:
        slots += 1
    assert slots == 1, (c, hex(vt), slots)
    creator_vtables.append({'vtable': hex(vt), 'rtti': rtti, 'original_slots': slots,
                            'slot0': '%s (counted row Creator::create)' % hex(cr)})


def vtable_slots(obj, symbol):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    if symbol not in definitions:
        return None
    start, index = definitions[symbol]
    section = sections[index]
    slots = {}
    for i in range(section[7]):
        offset, sym, kind = struct.unpack_from('<IIH', raw, section[5] + 10 * i)
        if offset >= start and kind == 6:
            slots[(offset - start) // 4] = symbols[sym][0]
    return slots


# ---- vtables emitted by the signal object (current headers), slot by slot against the original -----------------------
signal_bodies = {n: (b, r) for n, b, r in match.coff_functions(Path(OBJ['signals']).read_bytes())}
signal_own = {name: address for address, name in resolved['signals']}
counted_addresses = {int(r['address'], 16) for r in counted}
vtables = []
for symbol, (vt, rtti) in VTABLES.items():
    slots = vtable_slots(OBJ['signals'], symbol)
    if slots is None:
        continue
    count = 0
    while TEXT[0] <= d(vt + 4 * count) < TEXT[1]:
        count += 1
    assert len(slots) == count, (symbol, slots, count)
    entries = {}
    for slot, name in sorted(slots.items()):
        value = d(vt + 4 * slot)
        body_name = '??_G' + name[4:] if name.startswith('??_E') else name
        if signal_own.get(body_name) is not None:
            assert signal_own[body_name] == value, (symbol, slot, name, hex(value))
            entries[slot] = '%s -> %s (own row)' % (name[:80], hex(value))
            continue
        assert value not in counted_addresses, (symbol, slot, name, hex(value))
        sbody, srefs = signal_bodies[body_name]
        starget, strefs = target_of(value)
        assert match.exact_match(starget, strefs, sbody, srefs), ('slot body not exact', symbol, slot, name, hex(value))
        entries[slot] = '%s -> %s (ICF-shared body exact at the original slot; not counted here)' % (name[:80], hex(value))
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
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '%08x' % LO <= a < '%08x' % HI}
FUNCTIONS = [json.loads(x) for x in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines()]
RANGE_ROWS = sorted(x['addr'] for x in FUNCTIONS if LO <= int(x['addr'], 16) < HI)

# ---- unit-map evidence checks (strings, RTTI) ------------------------------------------------------------------------
def cstr(a, n=64):
    return original.data(a, n).split(b'\0')[0].decode('latin-1')


MAP_CHECKS = []
for vt, want in ((0x8252cc, '.?AVIdSerializer@Network@RBX@@'), (0x825724, '.?AVPacketLogger@@'),
                 (0x826394, '.?AVRakPeerInterface@@'), (0x824f40, '.?AVReplicatorStatsItem@Replicator@Network@RBX@@'),
                 (0x8251e8, None), (0x8265e4, None)):
    if want is None:
        continue
    rtti = original.vtable_class(vt)
    assert rtti and rtti[0] == want, (hex(vt), rtti)
    MAP_CHECKS.append('vtable %s RTTI %s' % (hex(vt), want))

UNIT_MAP = {
    'replicator ..004b21bf': (
        'Network/Replicator.cpp (starts below 004b0000): NewInstanceItem / DeleteInstanceItem / ChangePropertyItem '
        'write/read bodies (strings "Replication: ~%s:%d << %s", "Replication: %s:%s.%s >> %s"), Replicator::Update '
        '004b1240 ("SendBuffer = %d"), the std::map<const SignalDescriptor*, shared_ptr<SignalInstance> > / '
        'map<ContentId, CachedContent> / deque<shared_ptr<Marker> > instances 004b0b90..004b16a0, '
        'Described<Marker>::classDescriptor 004b18d0 ("NetworkMarker"), the boost::function holders and '
        'TSignalDesc<void()> / TSignalDesc<void(std::string)> SignalInstance bodies 004b1940..004b2150 (vtables 00824b7c, '
        '00824b8c, 00824b94, 00824ba4). Mostly counted by network-replicator / network-replicator2008 / humanoid2008.'),
    'signal-instances 004b1940..004b2150, 004b4fb0, 004b5a70, 004b5f40, 004b6040': (
        'The two reflection-signal signatures of Replicator.cpp (void() and void(std::string, bool); RTTI of the '
        'TSignalInstance vtables 00824b8c / 00824ba4 and the boost::any holder vtables 00824b7c / 00824b94): holder '
        'ctor/type/clone, any(const function&), signal0/signal2::connect(slot), the TSignalInstance ctor and '
        'newSignalInstance, signal2::operator() 004b5a70, its slot_call_iterator caller 004b4fb0 and the '
        'SignalDescImpl<0/2>::fire bodies 004b5f40 / 004b6040. Built here: native-classes/AppUnit4B0_2008Signals.cpp '
        '(read-only reflection/signal.h). The void() TSignalInstance ctor / newSignalInstance / signal0::operator() '
        'are counted by humanoid2008.'),
    'joint-creators 004b21c0..004b337f': (
        'Compiler-emitted template instances in the order Lighting, Snap, Weld, Glue, Rotate, RotateP, RotateV, Motor. '
        'Per class: FactoryProduct<C, D, N>::Creator::create() const (175 B; slot 0 of the Creator vtables 00824bac, '
        '00824bb4, 00824bd0, 00824bec, 00824c08, 00824c24, 00824c40, 00824c5c, checked by RTTI below), '
        'shared_count(C*, Deleter) (131 B, sp_counted_impl_pd vtables 00824bbc..00824c64; counted by '
        'creatable-shared-count), shared_ptr<C>(C*, Deleter) (171 B) and Creatable<Instance>::create<C>() (120 B, '
        'malloc 0x154, then C() 005e4600 / 005e4810 / 005e49a0 / 005e4ad0 / 005e4c60 / 005e4dd0 / 005e4ee0). '
        'Lighting\'s create / shared_ptr / shared_count are below the range (create<Lighting> 004adb60, lighting2008). '
        'Built here: native-classes/AppUnit4B0_2008Joints.cpp.'),
    'replicator 004b3380..004ba22f': (
        'Network/Replicator.cpp continued: vector / map instances 004b3380..004b3b40 (004b3a50 counted by the '
        'world-service trials as an ICF-shared body), Described<Replicator> / BoundFuncDesc<Replicator> / '
        'BoundFuncDesc<Peer> reflection bodies 004b3c30..004b42e0 ("bad cast" throw paths), Peer and Client '
        'bodies 004b4640 ("Packets Thread") / 004b5700 (Peer::onServiceProvider, "Network"), TypedStatsItem<bool> '
        '004b5100..004b51d0, ReplicatorStatsItem 004b62c0..004b6710 (vtables 00824f40.., strings "Ping", '
        '"Bandwidth Exceeded", "%d avg:%d best:%d"), property serialisation 004b6890..004b7f20 ("   read %s %s, 1 bit"), '
        'NewInstanceItem::write 004b8620, OnReceive 004b8c20 ("Lost connection to %s"), Marker 004b9140 / '
        '004b9190 / 004b9210 ("Replicator: Requesting Marker %d of %s"), IdSerializer 004b94a0..004b9bb0 (vtables '
        '008252cc..), DescribedNonCreatable<Replicator> thunks 004b9a20..004b9ab0 and the Replicator constructor '
        '004b9bd0 (1622 B, "Replication", "Data In", "Data Out"). Worked by the network-replicator owners; not '
        'rebuilt here (their native Network/Replicator2008.h / IdSerializer.h / ReplicatorMarker.h are read-only for '
        'this lease).'),
    'raknet 004ba230..': (
        'RakNet 3.x library code: DataStructures templates 004ba230..004ba9d0 (called from RakPeer 004bff40, 004c42c0, '
        '004c1db0, 004c4d50), PacketLogger.cpp 004baa10..004bb39f (vtable 00825724 .?AVPacketLogger@@; strings '
        '"S|R,Typ,Pckt#,Frm #,PktID,BitLn,Time", "ID_INTERNAL_PING", "%sSnd,Raw,..."), RakPeerInterface / '
        'RakPeer.cpp members from 004bb3a0 (vtable 00826394 .?AVRakPeerInterface@@) continuing past 004bc000 '
        '(app-unit4bc-2008 map). Library code: never recovered here.'),
}

NOT_EXACT = [
    {'address': 'ICF-shared generic bodies', 'reason': 'Bodies this build also emits but does not count because one '
     'copy serves many instances (not attributable to this unit): the 5-byte findSig / iterator_facade::operator* / '
     'checked_delete<int> bodies (004b1690, 004b3750), the 9-byte slot_call_iterator increment/dereference body '
     '004b35d0, std::list<connection> destructor 004b0a80 (also list<SignatureDescriptor::Item>), and the 31-byte '
     'scalar deleting destructor 004bb530 (sp_counted_base / placeholder / Descriptor, inside the RakNet block).'},
    {'address': 'replicator rows', 'reason': 'Not attempted in this pass: the Replicator.cpp rows belong to the '
     'network-replicator owners\' native Network/Replicator2008.h / IdSerializer.h / ReplicatorMarker.h (read-only '
     'here); the uncounted ones are listed in range_rows_not_counted.'},
]

REJECTED = {
    'Creator rows against the original 2008 hierarchy': (
        'not tried as a build: the native JointInstance.h models Snap..Motor on AutoJoint (donor shape); the original '
        'RTTI is FactoryProduct<C, JointInstance, sC 3QBDB>. The bytes do not depend on it (same sizeof 0x154 and the '
        'Object base at +0x10), so the rows are codegen analogs with AutoJoint in their symbols'),
}

PROPOSALS = [
    'v8datamodel/JointInstance.h (Joint family owner): in 2008 Snap, Weld, Glue, Rotate, RotateP, RotateV and Motor '
    'derive from DescribedCreatable<C, JointInstance, sC> with `extern const char sC[];`, not from AutoJoint with a '
    'char array. Evidence: the Weld vtable 0083f24c RTTI lists DescribedCreatable@VWeld@RBX@@VJointInstance@2@$1?sWeld@2@'
    '3QBDB directly over JointInstance (no AutoJoint base), and the Creator vtables 00824bb4..00824c5c name '
    'FactoryProduct<C, JointInstance, sC 3QBDB>. sizeof(C) stays 0x154 (create<C> mallocs 0x154). The rows counted '
    'here are exact either way (codegen analogs), so this is a naming/ABI correction only; re-run the humanoid2008, '
    'script-app2008, seat, services-maps, feature and creatable-shared-count recorders after the change.',
]

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
counted_set = set(exact_rows)
receipt = {
    'class': 'RBX joint-creator and reflection-signal rows of the application range 004b0000..004bc000 (2008-06), '
             'inactive',
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
    'creator_vtables': creator_vtables,
    'vtables': vtables,
    'not_exact': NOT_EXACT,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit4b0-2008: %d counted exact rows (%s); 0 pending-build-only, %d range rows, %d counted elsewhere, '
      '%d creator vtables, %d signal vtables, %d support rows' % (
          len(exact_rows), ' '.join(exact_rows), len(RANGE_ROWS), len(range_counted), len(creator_vtables),
          len(vtables), len(support_out)))
