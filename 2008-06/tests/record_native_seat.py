"""Verify the inactive native RBX::Seat recovery (2008-06).

Builds (document-swap flags, VS2008 RTM 21022), all from the current native headers:
  * tests/NativeSeatLayout.cpp   sizeof probes (mov eax, imm32; ret);
  * native-classes/Seat.cpp      the Seat unit 0063c430..0063d710 without seatCharacter / onEvent_seatTouched /
                                 onServiceProvider and their boost::bind / boost::function / slot plumbing
                                 (NOT_ATTEMPTED below), plus classDescriptor 005c3a40, doDeclare 005bfe90,
                                 callDoDeclare 005c0060 and the classDescriptor atexit 007fe6a0.

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals by bytes, type descriptors and
vtables by original RTTI names, own symbols by the row proven here, folded bodies by their address, and the remaining
externals by the explicit EXTERNAL / DATA maps (call sites read in the original disassembly). A symbol binds to one
address across all rows. The Seat vtable is compared slot by slot from the object built with the current headers.

Seat rows that depend on PartInstance's layout (constructors, destructors, onEvent_humanoidSeated, the vtordisp
deleting thunks) are compiled and recorded with exact=false: the current native PartInstance.h has sizeof 0x2ec where
the 2008 PartInstance's non-virtual part is 0x3e8 (the bodies have the original sizes; only field and base offsets
differ). Writes work/2008-06/shared-layouts/seat-working.json.
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
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
SEAT_SRC = R / 'native-classes/Seat.cpp'
SEAT_H = R / 'native-headers/v8datamodel/Seat.h'
LAYOUT = R / 'tests/NativeSeatLayout.cpp'


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeSeatLayout', LAYOUT)
seat_obj, seat_flags = build('NativeSeat', SEAT_SRC)

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()


def probe(prefix):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert len(body) == 6 and body[0] == 0xb8 and body[5] == 0xc3, (prefix, body.hex())
    return struct.unpack_from('<I', body, 1)[0]


assert probe('?nativeSeatInstanceSize@@') == 0x130
compiled_sizes = {'Instance': probe('?nativeSeatInstanceSize@@'), 'PartInstance': probe('?nativeSeatPartInstanceSize@@'),
                  'Seat': probe('?nativeSeatSize@@')}
LAYOUT_PENDING = compiled_sizes['Seat'] != 0x43c

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


STR = '?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
EXTERNAL = {
    '??3@YAXPAX@Z': 0x6a067a, '_atexit': 0x6a17af,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,                  # doDeclare 005bfec7
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,                   # getClassName 0063cbea
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,  # classDescriptor 005c3a80
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,            # atexit 007fe6a5
    '?classDescriptor@?$Described@VPartInstance@RBX@@$1?sPart@2@3PADAV?$FactoryProduct@VPartInstance@RBX@@VPVInstance@2@$1?sPart@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x59c7f0,
    # PartInstance virtuals reached through Seat's vtordisp thunks 0063d570 / 0063d5b0 / 0063d610 / 0063d700
    '?onCameraNear@PartInstance@RBX@@UAEXM@Z': 0x59e430,
    '?getCameraIgnorePrimitives@PartInstance@RBX@@UAEXAAV?$vector@PBVPrimitive@RBX@@V?$allocator@PBVPrimitive@RBX@@@std@@@std@@@Z': 0x59c0d0,
    '?getLocation@PartInstance@RBX@@UBE?BVCoordinateFrame@G3D@@XZ': 0x59bbf0,
    '?getPrimaryPart@PartInstance@RBX@@UAEPAV12@XZ': 0x59bb10,
    '?getPrimaryPartConst@PartInstance@RBX@@UBEPBV12@XZ': 0x59bb10,   # ICF-folded with getPrimaryPart (both lea eax, [ecx-0x3ec])
}
DATA = {
    '?sSeat@RBX@@3PADA': 0x961598,   # "Seat" (doDeclare 005bfeba, classDescriptor 005c3a68, Seat::Seat 0063d514)
}
assert original.string(0x961598) == 'Seat'

FP = '?$FactoryProduct@VSeat@RBX@@VPartInstance@2@$1?sSeat@2@3PADA@RBX@@'
DC = '?$DescribedCreatable@VSeat@RBX@@VPartInstance@2@$1?sSeat@2@3PADA@RBX@@'
DS = '?$Described@VSeat@RBX@@$1?sSeat@2@3PADAV' + FP[:-6] + '@2@@Reflection@RBX@@'

# ICF / trivial-wrapper folds: the original keeps one body where this unit emits several identical ones.
FOLDED = {
    '??1' + DC + 'UAE@XZ': 0x63c780,                  # same 5-byte jmp as ~Described (0063c780)
    '??_G' + DC + 'UAEPAXI@Z': 0x63c630,              # deleting destructor folded with FactoryProduct's
    '?className@' + FP + 'SAABVName@2@XZ': 0x63cbe0,
    '??$declare@$1?sSeat@RBX@@3PADA@Name@RBX@@SAABV01@XZ': 0x63cbe0,
}
# Call targets whose own rows are not exact (layout-dependent or not attempted): bound by the address the original
# instruction uses; listed separately so they never count as proof.
UNPROVEN = {
    '??1' + FP + 'MAE@XZ': 0x63c430,
    '??0' + FP + 'IAE@XZ': 0x63c650,
    '??0' + DC + 'IAE@XZ': 0x63d1b0,
    '??0Seat@RBX@@QAE@XZ': 0x63d390,
    '??1Seat@RBX@@UAE@XZ': 0x63d640,
    '?onEvent_humanoidSeated@Seat@RBX@@AAEX_N@Z': 0x63c810,
    '?onServiceProvider@Seat@RBX@@MAEXPBVServiceProvider@2@0@Z': 0x63d0d0,   # vtable slot 12; body not attempted
}

SEAT_ROWS = [
    (0x63c5f0, '??_E' + FP + 'OBKA@AEPAXI@Z'), (0x63c600, '??_E' + FP + 'OBA@AEPAXI@Z'),
    (0x63c610, '??_E' + FP + 'OCE@AEPAXI@Z'), (0x63c620, '??_E' + FP + 'OGE@AEPAXI@Z'),
    (0x63c630, '??_G' + FP + 'MAEPAXI@Z'),
    (0x63c780, '??1' + DS + 'UAE@XZ'),
    (0x63cbe0, '?getClassName@' + FP + 'UBEABVName@2@XZ'),
    (0x63d320, '??_E' + FP + 'OEE@AEPAXI@Z'), (0x63d330, '??_E' + FP + 'OIE@AEPAXI@Z'),
    (0x63d340, '??_E' + FP + 'OKE@AEPAXI@Z'), (0x63d350, '??_E' + FP + 'OME@AEPAXI@Z'),
    (0x63d360, '??_E' + FP + 'OBE@AEPAXI@Z'), (0x63d370, '??_E' + FP + 'OBDA@AEPAXI@Z'),
    (0x63d560, '??_ESeat@RBX@@WGE@AEPAXI@Z'),
    (0x63d570, '?onCameraNear@PartInstance@RBX@@$4PPPPPPPM@DI@AEXM@Z'),
    (0x63d580, '??_ESeat@RBX@@WIE@AEPAXI@Z'), (0x63d590, '??_ESeat@RBX@@WKE@AEPAXI@Z'),
    (0x63d5a0, '??_ESeat@RBX@@WME@AEPAXI@Z'),
    (0x63d5b0, '?getLocation@PartInstance@RBX@@$4PPPPPPPM@DI@'),
    (0x63d5c0, '??_ESeat@RBX@@WBKA@AEPAXI@Z'), (0x63d5d0, '??_ESeat@RBX@@WBA@AEPAXI@Z'),
    (0x63d5e0, '??_ESeat@RBX@@WBE@AEPAXI@Z'), (0x63d600, '??_ESeat@RBX@@WBDA@AEPAXI@Z'),
    (0x63d610, '?getPrimaryPart@PartInstance@RBX@@$4PPPPPPPM@DI@AEPAV12@XZ'),
    (0x63d610, '?getPrimaryPartConst@PartInstance@RBX@@$4PPPPPPPM@DI@BEPBV12@XZ'),   # ICF: same thunk (IPrimaryPart slots 0/1)
    (0x63d620, '??_ESeat@RBX@@WCE@AEPAXI@Z'), (0x63d630, '??_ESeat@RBX@@WEE@AEPAXI@Z'),
    (0x63d6e0, '??_GSeat@RBX@@UAEPAXI@Z'),
    (0x63d700, '?getCameraIgnorePrimitives@PartInstance@RBX@@$4PPPPPPPM@DI@'),
    (0x5c3a40, '?classDescriptor@' + DS + 'SAAAVClassDescriptor@23@XZ'),
    (0x5bfe90, '??$doDeclare@$1?sSeat@RBX@@3PADA@Name@RBX@@CAABV01@XZ'),
    (0x5c0060, '??$callDoDeclare@$1?sSeat@RBX@@3PADA@Name@RBX@@CAXXZ'),
    (0x7fe6a0, '??__Ffoo@?1??classDescriptor@' + DS),
]
# Compiled, not exact: they depend on the 2008 PartInstance layout (non-virtual size 0x3e8) that the native
# PartInstance.h does not have yet. Recorded with exact=false and the reason.
LAYOUT_ROWS = [
    (0x63c430, '??1' + FP + 'MAE@XZ', 'stores PartInstance-layout vtables and vtordisp values (lea [eax-0x2b8])'),
    (0x63c650, '??0' + FP + 'IAE@XZ', 'PartInstance base construction, vbtable at +0x400, vtordisp values'),
    (0x63d1b0, '??0' + DC + 'IAE@XZ', 'vbtable at +0x400, vtables and vtordisp values'),
    (0x63d380, '??_E' + FP + '$2PPPPPPPM@', 'vtordisp deleting thunk: vbase offset 0x3fc'),
    (0x63d390, '??0Seat@RBX@@QAE@XZ', 'fields +0x3e8..+0x41c, vbtable at +0x438, vtordisp values (lea [eax-0x2f0])'),
    (0x63d5f0, '??_ESeat@RBX@@$4PPPPPPPM@', 'vtordisp deleting thunk: vbase offset 0x434'),
    (0x63d640, '??1Seat@RBX@@UAE@XZ', 'weld +0x41c, scoped_connections +0x3fc / +0x3e8'),
    (0x63c810, '?onEvent_humanoidSeated@Seat@RBX@@AAEX_N@Z', 'humanoidSeated +0x3fc, sleepTime +0x410, weld +0x418'),
]
NOT_ATTEMPTED = {
    '0063c8a0': 'Seat::seatCharacter (829 bytes): Creatable::create<Weld> 004b2620, getTorso, CoordinateFrame algebra, '
                'Primitive::getAssembly 005e7570 (+0x24 -> +0x1c root primitive), static Velocity 0097d568, '
                'JointInstance setters; needs native Humanoid / Primitive / Assembly declarations and the PartInstance layout',
    '0063cf30': 'Seat::onEvent_seatTouched: Humanoid::modelIsCharacter 005d9a20, getTorso 005d8b10, a Humanoid byte at '
                '+0x1e8 tested with 0xa, Workspace::contextInWorkspace 005a33d0, setSit 005dc2b0, Humanoid "Seated" '
                'SignalDesc 0097a558 connect 004d8390 with a third argument 10; needs native Humanoid.h, signal.h',
    '0063d0d0': 'Seat::onServiceProvider: PartInstance::event_Touched (00976164) SignalDesc connect 004a3340 with a third '
                'argument 10 (the boost::signal group) that the donor reflection/signal.h connect lacks',
    '0063c530/0063c590/0063c790/0063c7d0': 'boost::function functor_manager<bind_t<..Seat..>> manage/clone for the two binds '
                '(instantiated only by the bodies above)',
    '0063c870/0063cc00/0063cc30': 'boost::bind<void, Seat, bool> and the two void_function_obj_invoker1::invoke instances '
                '(0063cc30 calls the mf1 helper 005d2180 shared with SpawnLocation)',
    '0063ccd0/0063cd30/0063cd90/0063ce60': 'boost::function assign_to and boost::slot<function<...>> constructors for the '
                'two binds',
}

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for row in rows:
        address, key = row[0], row[1]
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not LOCAL_EH.match(x[0])]
        assert len(hits) == 1, (address, key, [h[0] for h in hits])
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
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
            elif symbol in UNPROVEN:
                assert UNPROVEN[symbol] == value, (name, symbol, hex(value))
                how = 'call target of a non-exact row'
            elif symbol.startswith('??_B?1??') or symbol.startswith('?$S') or '?$TSS' in symbol or symbol.startswith('?flag@') \
                    or symbol.startswith('?foo@') or symbol.startswith('?n@'):
                how = 'local static'
            else:
                UNBOUND.append('%s in %s -> %s' % (symbol, name, hex(value)))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


seat_rows = resolve(seat_obj, SEAT_ROWS)
layout_rows = resolve(seat_obj, LAYOUT_ROWS)
own = {}
for address, name in seat_rows:
    own.setdefault(name, address)
seat_out = verify(seat_obj, seat_rows, own)
layout_out = verify(seat_obj, layout_rows, own, strict=False)
for row, (_, _, why) in zip(layout_out, LAYOUT_ROWS):
    if row['exact']:   # would need re-review: these depend on the PartInstance layout
        raise AssertionError('layout-dependent row unexpectedly exact: %s' % row['address'])
    assert row['size'] == row['target_size'], row
    row['reason'] = 'needs the 2008 PartInstance layout: ' + why
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- vtable from the object built with the current headers, slot by slot ---------------------------------------
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


def check_vtable(obj, symbol, address):
    out = []
    for i, slot in enumerate(compiled_vtable(obj, symbol)):
        value = d(address + 4 * i)
        if slot.startswith('??_E') and '??_G' + slot[4:] in slot_names:
            expect = slot_names['??_G' + slot[4:]]
        else:
            expect = slot_names.get(slot)
        if expect is not None:
            ok, how = expect == value, 'bound'
        else:
            ok, how = norm(names.get(value, '')) == norm(slot), 'evidence name'
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
    return out


# Slots bound to an inherited body must hold the same address as PartInstance's own vtable 00832d4c (constructor
# 0059d4d0).
assert original.vtable_class(0x832d4c) == ('.?AVPartInstance@RBX@@', 0)


def inherited(rows, reference, own_class):
    bad = []
    for s in rows:
        if s['ok']:
            continue
        cls = s['symbol'].split('@')[1] if s['symbol'].startswith('?') and not s['symbol'].startswith('??') else ''
        if cls != own_class and int(s['original'], 16) == d(reference + 4 * s['slot']):
            s['ok'] = True
            s['how'] = 'inherited (%s slot of the base vtable %08x)' % (s['symbol'].split('@')[0][1:], reference)
        else:
            bad.append(s)
    return bad


vt = {'Seat': check_vtable(seat_obj, '??_7Seat@RBX@@6B?$GuidItem@VInstance@RBX@@@1@@', 0x849f74)}
assert not inherited(vt['Seat'], 0x832d4c, 'Seat'), [s for s in vt['Seat'] if not s['ok']]
assert len(vt['Seat']) == 26, len(vt['Seat'])
assert vt['Seat'][12]['symbol'].startswith('?onServiceProvider@Seat') and vt['Seat'][12]['original'] == '0063d0d0'
assert vt['Seat'][1]['original'] == '00598c20'   # PartInstance::setName, also called by Seat::Seat 0063d533
# The Seat vtable overrides only slot 12 (onServiceProvider) of PartInstance's 26 slots.
part = [d(0x832d4c + 4 * i) for i in range(26)]
assert [i for i, s in enumerate(vt['Seat']) if int(s['original'], 16) != part[i]] == [12]

# The other 16 Seat vtables: the compiled constructor (same size as 0063d390; non-exact only in field and vtordisp
# offsets) stores each ??_7Seat symbol at the instruction offset where the original stores its vtable address. Each
# address is checked by its RTTI locator (class Seat and the sub-object offset), then slot by slot: own/bound symbols
# by address, the rest must be the same body as the corresponding slot of the PartInstance vtable for that sub-object
# (read from PartInstance's constructor 0059d4d0 by locator offset).
def vtable_stores(obj, symbol, address):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    table = sections[section]
    target, _, _ = match.target('2008-06', '%08x' % address)
    out = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        name = symbols[index][0]
        if kind == 6 and name.startswith('??_7') and start <= offset < start + len(target):
            out.setdefault(name, struct.unpack_from('<I', target, offset - start)[0])
    return out


def locator_offset(vtable):
    return struct.unpack('<I', original.data(d(vtable - 4) + 4, 4))[0]


part_vtables = {}
part_ctor, _, _ = match.target('2008-06', '0059d4d0')
for i in range(len(part_ctor) - 5):
    value = struct.unpack_from('<I', part_ctor, i)[0]
    try:
        rtti, at = original.vtable_class(value)
    except Exception:
        continue
    if rtti == '.?AVPartInstance@RBX@@':
        part_vtables.setdefault(at, value)
layout_slots = {name: address for address, name in layout_rows}
# PartInstance's IPrimaryPart vtable (vbase +0x3ec, 00832c80) also holds one thunk (0059bb80) in both slots:
# getPrimaryPart and getPrimaryPartConst are one folded body (0059bb10), so Seat's two vtordisp thunks fold into
# 0063d610 as well.
assert part_vtables[0x3ec] == 0x832c80 and d(0x832c80) == d(0x832c84) == 0x59bb80
seat_vtables = {k: v for k, v in vtable_stores(seat_obj, '??0Seat@RBX@@QAE@XZ', 0x63d390).items() if k.startswith('??_7Seat@')}
assert len(seat_vtables) == 17, sorted(seat_vtables)   # the 0x849f74 one (checked above) and 16 more
for symbol, address in sorted(seat_vtables.items(), key=lambda x: x[1]):
    rtti, at = original.vtable_class(address)
    assert rtti == '.?AVSeat@RBX@@', (symbol, hex(address), rtti)
    rows = check_vtable(seat_obj, symbol, address)
    # PartInstance's virtual-base sub-objects sit 0x38 lower (+0x3ec/+0x3f4/+0x3fc there, +0x424/+0x42c/+0x434 here).
    part_at = at - 0x38 if at >= 0x420 else at
    for s in rows:   # layout-blocked deleting thunks: bound by the original slot address of the non-exact row
        if not s['ok'] and s['symbol'] in layout_slots:
            s['ok'] = layout_slots[s['symbol']] == int(s['original'], 16)
            s['how'] = 'layout-blocked row (not proof)'
    if part_at in part_vtables:
        reference = part_vtables[part_at]
        for s in rows:
            if not s['ok'] and not s['symbol'].startswith('??_E') and int(s['original'], 16) == d(reference + 4 * s['slot']):
                s['ok'], s['how'] = True, 'inherited (slot of PartInstance vtable %08x)' % reference
    bad = [s for s in rows if not s['ok']]
    assert not bad, (symbol, hex(address), bad)
    vt['Seat+%#x' % at] = rows

# ---- RTTI, allocation size and strings ----------------------------------------------------------------------
assert original.vtable_class(0x849f74) == ('.?AVSeat@RBX@@', 0)
body, _, _ = match.target('2008-06', '005c3080')     # Creatable<Instance>::create<Seat>
at = body.index(b'\x68' + struct.pack('<I', 0x43c))
call = body.index(b'\xe8', at + 5)
while (0x5c3080 + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != 0x63d390:
    call = body.index(b'\xe8', call + 1)
assert original.string(0x83d918) == 'Seated' and original.string(0x83d8e0) == 'active'   # SignalDesc 0097a558 (007f6950)
assert struct.unpack('<d', original.data(0x828b90, 8))[0] == 3.0                          # onEvent_seatTouched 0063cf5f


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


sb = bases(0x849f74)
assert '.?AVPartInstance@RBX@@' in sb and '.?AV?$DescribedCreatable@VSeat@RBX@@VPartInstance@2@$1?sSeat@2@3PADA@RBX@@' in sb, sb

sha = nb.sha
paths = [Path(__file__).resolve(), SEAT_H, SEAT_SRC, LAYOUT]
exact_rows = sorted({r['address'] for r in seat_out if r['exact']})
receipt = {
    'class': 'RBX::Seat', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'seat': seat_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, seat_obj)},
    'layout': {'Seat': '0x43c (005c3080); PartInstance non-virtual part to +0x3e8, scoped_connection seatTouched +0x3e8, '
                       'scoped_connection humanoidSeated +0x3fc, double sleepTime +0x410, shared_ptr<Weld> +0x418, '
                       'vtordisp +0x420, virtual bases from +0x424'},
    'compiled_sizes': compiled_sizes,
    'layout_pending': LAYOUT_PENDING,
    'rows': {'seat': seat_out, 'layout_blocked': layout_out},
    'exact_function_rows': exact_rows,
    'vtables': vt,
    'layout_blocked_note': 'layout_blocked rows compile to the original sizes but need native PartInstance.h with the 2008 '
                           'non-virtual size 0x3e8 (currently sizeof 0x%x including virtual bases).' % compiled_sizes['PartInstance'],
    'not_attempted': NOT_ATTEMPTED,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/seat-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Seat: %d rows exact (%d distinct function addresses); %d layout-blocked rows not counted; '
      'targets and vtable verified' % (sum(r['exact'] for r in seat_out), len(exact_rows), len(layout_out)))
