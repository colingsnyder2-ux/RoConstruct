"""Verify the inactive native RBX::Network IdSerializer / Replicator base chain / Marker recovery (2008-06).

Builds (document-swap flags, VS2008 RTM 21022, current native headers only; no pending build):
  * tests/NativeReplicatorLayout.cpp       sizeof/base/field offsets;
  * native-classes/ReplicatorBases.cpp     StringSender, SharedStringDictionary, IdSerializer and the Replicator
                                           base-class template instances (explicit instantiation of
                                           DescribedNonCreatable<Replicator, IdSerializer, sReplicator>);
  * native-classes/ReplicatorMarker.cpp    Marker (constructor chain, newMarker, deleting destructor), the
                                           Marker "Received" signal descriptor initializer and its atexit row.

Every row must be relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals and the class-name arrays by
bytes, type descriptors and vtables by original RTTI names, own symbols by the row proven here, and the remaining
externals by the explicit EXTERNAL / DATA maps (call sites read in the original disassembly). A symbol must bind to
one address in every row. Vtable slots of every bound vtable are checked against the original slots.
Writes work/2008-06/shared-layouts/network-replicator-working.json.
"""
import json
import os
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

DISCOVER = os.environ.get('NR_DISCOVER') == '1'
R = ROOT / 'rebuild/2008-06'
OUT = R / 'out/native-replicator'
OUT.mkdir(parents=True, exist_ok=True)
BASES = R / 'native-classes/ReplicatorBases.cpp'
MARKER = R / 'native-classes/ReplicatorMarker.cpp'
HEADERS = [R / 'native-headers/Network/IdSerializer.h', R / 'native-headers/Network/ReplicatorMarker.h']
LAYOUT = R / 'tests/NativeReplicatorLayout.cpp'


def build(name, src):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeReplicatorLayout', LAYOUT)
bases_obj, bases_flags = build('NativeReplicatorBases', BASES)
marker_obj, marker_flags = build('NativeReplicatorMarker', MARKER)

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
for prefix, value in (('?nativeStringSenderSize@@', 0xe24), ('?nativeStringReceiverOffset@@', 0xe24),
                      ('?nativeSharedStringDictionarySize@@', 0x2a24), ('?nativeIdSerializerSize@@', 0x2b74),
                      ('?nativeMarkerSize@@', 0x10)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


ID = 'IdSerializer@Network@RBX@@'
NFP = '?$NonFactoryProduct@VIdSerializer@Network@RBX@@$1?sReplicator@23@3QBDB@RBX@@'
DNC = '?$DescribedNonCreatable@VReplicator@Network@RBX@@VIdSerializer@23@$1?sReplicator@23@3QBDB@RBX@@'
DESC_R = '?$Described@VReplicator@Network@RBX@@$1?sReplicator@23@3QBDBV?$NonFactoryProduct@'
MFP = '?$NonFactoryProduct@VDescribedBase@Reflection@RBX@@$1?sMarker@Network@3@3QBDB@RBX@@'
DESC_M = '?$Described@VMarker@Network@RBX@@$1?sMarker@23@3QBDBV?$NonFactoryProduct@'
STR = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
WAITVEC = 'V?$vector@UWaitItem@IdSerializer@Network@RBX@@V?$allocator@UWaitItem@IdSerializer@Network@RBX@@@std@@@std@@'
THUNKS = (('WBA', 0x4b9b90), ('WBE', 0x4b9660), ('WCE', 0x4b9640), ('WEE', 0x4b9650), ('WGE', 0x4b9560),
          ('WIE', 0x4b9ba0), ('WKE', 0x4b9b70), ('WME', 0x4b9b80))

# Externals: the address the original instruction uses (call sites in the rows below); names checked against the
# evidence names where those exist; one address per symbol across every row.
EXTERNAL = {
    '_atexit': 0x6a17af,
    '??0Instance@RBX@@IAE@XZ': 0x55b7e0,
    '??1Instance@RBX@@MAE@XZ': 0x55a540,
    '??3?$Creatable@VInstance@RBX@@@RBX@@CAXPAX@Z': 0x8028c0,
    '??3@YAXPAX@Z': 0x6a067a,
    '??2@YAPAXI@Z': 0x6a0920,
    '??_L@YGXPAXIHP6EX0@Z1@Z': 0x6a1598,
    '??_M@YGXPAXIHP6EX0@Z@Z': 0x6a165b,
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,
    '?rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ': 0x40ad20,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,
    '??1SignalSource@Reflection@RBX@@UAE@XZ': 0x56bd40,
    '??0SignalDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD@Z': 0x56bab0,
    '?sp_enable_shared_from_this@detail@boost@@YAXABVshared_count@12@ZZ': 0x47d410,
    '??$?0VMarker@Network@RBX@@@shared_count@detail@boost@@QAE@PAVMarker@Network@RBX@@@Z': 0x4ac040,
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,
    '??1?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@QAE@XZ': 0x4199e0,
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,
    # std::map / _Tree members shared by identical-code folding with other instantiations (evidence names differ):
    # map<string, unsigned char> constructor and destructor, map<Guid::Data, vector<WaitItem> >::erase.
    '??0?$_Tree@V?$_Tmap_traits@' + STR + 'EU?$less@' + STR + '@2@V?$allocator@U?$pair@$$CB' + STR + 'E@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@' + STR + '@1@ABV?$allocator@U?$pair@$$CB' + STR + 'E@std@@@1@@Z': 0x699b30,
    '??1?$_Tree@V?$_Tmap_traits@' + STR + 'EU?$less@' + STR + '@2@V?$allocator@U?$pair@$$CB' + STR + 'E@std@@@2@$0A@@std@@@std@@QAE@XZ': 0x46b070,
    '??0?$_Tree@V?$_Tmap_traits@UData@Guid@RBX@@' + WAITVEC + 'U?$less@UData@Guid@RBX@@@5@V?$allocator@U?$pair@$$CBUData@Guid@RBX@@' + WAITVEC + '@std@@@5@$0A@@std@@@std@@QAE@ABU?$less@UData@Guid@RBX@@@1@ABV?$allocator@U?$pair@$$CBUData@Guid@RBX@@' + WAITVEC + '@std@@@1@@Z': 0x699b30,
    '?erase@?$_Tree@V?$_Tmap_traits@UData@Guid@RBX@@V?$vector@UWaitItem@IdSerializer@Network@RBX@@V?$allocator@UWaitItem@IdSerializer@Network@RBX@@@std@@@std@@U?$less@UData@Guid@RBX@@@5@V?$allocator@U?$pair@$$CBUData@Guid@RBX@@V?$vector@UWaitItem@IdSerializer@Network@RBX@@V?$allocator@UWaitItem@IdSerializer@Network@RBX@@@std@@@std@@@std@@@5@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z': 0x4b8a80,
    # Instance constructor/destructor: the current Instance.h declares them public/virtual (evidence names
    # ??0Instance@RBX@@IAE@XZ protected, ??1Instance@RBX@@MAE@XZ protected virtual); same addresses.
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,
    '??1Instance@RBX@@UAE@XZ': 0x55a540,
    '?lockedDown@ClassDescriptor@Reflection@RBX@@2_NA': 0x974c85,
}
# Descriptor objects (the `this` the dynamic initializer 007f2290 passes).
DATA = {
    '_event_Received': 0x971690,
}

# (address, symbol or unique symbol prefix, object)
ROWS = [
    # IdSerializer and its string dictionaries
    (0x4b3c90, '??0StringSender@Network@RBX@@QAE@XZ', 'bases'),
    (0x4b36f0, '??1StringSender@Network@RBX@@QAE@XZ', 'bases'),
    (0x4b3d10, '??0SharedStringDictionary@Network@RBX@@QAE@XZ', 'bases'),
    (0x4b3d70, '??1SharedStringDictionary@Network@RBX@@QAE@XZ', 'bases'),
    (0x4b94a0, '??0' + ID + 'QAE@XZ', 'bases'),
    (0x4b9440, '??1' + ID + 'UAE@XZ', 'bases'),
    (0x4b9bb0, '??_G' + ID + 'UAEPAXI@Z', 'bases'),
    (0x4b93d0, '??1?$_Tree@V?$_Tmap_traits@UData@Guid@RBX@@V?$vector@UWaitItem@' + ID, 'bases'),
    # Replicator base-class template instances
    (0x4b9570, '??0' + NFP + 'QAE@XZ', 'bases'),
    (0x4b96a0, '??1' + NFP + 'UAE@XZ', 'bases'),
    (0x4b9bb0, '??_G' + NFP + 'UAEPAXI@Z', 'bases'),
    (0x4b9ad0, '??0' + DNC + 'IAE@XZ', 'bases'),
    (0x4b9bb0, '??_G' + DNC + 'UAEPAXI@Z', 'bases'),
    (0x4b3800, '?classDescriptor@' + DESC_R, 'bases'),
    (0x4b95d0, '??$doDeclare@$1?sReplicator@Network@RBX@@3QBDB@Name@RBX@@CAABV01@XZ', 'bases'),
    (0x4b9670, '??$callDoDeclare@$1?sReplicator@Network@RBX@@3QBDB@Name@RBX@@CAXXZ', 'bases'),
    (0x4b9680, '?getClassName@' + NFP + 'UBEABVName@2@XZ', 'bases'),
    # Marker
    (0x4b9140, '??0Marker@Network@RBX@@AAE@XZ', 'marker'),
    (0x4b85b0, '??0' + MFP + 'QAE@XZ', 'marker'),
    (0x4b8600, '??_GMarker@Network@RBX@@UAEPAXI@Z', 'marker'),
    (0x4b8600, '??_G' + MFP + 'UAEPAXI@Z', 'marker'),
    (0x4b9190, '?newMarker@Marker@Network@RBX@@SA?AV?$shared_ptr@VMarker@Network@RBX@@@boost@@XZ', 'marker'),
    (0x4b18d0, '?classDescriptor@' + DESC_M, 'marker'),
    (0x7f2290, '??__Eevent_Received@Network@RBX@@YAXXZ', 'marker'),
]
for suffix, address in THUNKS:
    for cls in (ID, NFP, DNC):
        ROWS.append((address, '??_E' + cls + suffix + '@AEPAXI@Z', 'bases'))
# atexit rows: the destructor address is the immediate the initializer / function-local static pushes before
# `call _atexit`.
ATEXIT = {
    0x7f2290: ('??__Fevent_Received@Network@RBX@@YAXXZ', 'marker'),
    0x4b3800: ('??__Ffoo@?1??classDescriptor@' + DESC_R, 'bases'),
    0x4b18d0: ('??__Ffoo@?1??classDescriptor@' + DESC_M, 'marker'),
}
# Original rows of this family that are not compiled here (recorded with the reason, not counted).
NOT_EXACT = [
    ('004ac040', 'shared_count::shared_count<Marker> (110 bytes); this build emits a 131-byte body with a catch '
                 'funclet; bound as an external (the address newMarker 004b9190 calls).'),
]

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}
OBJECTS = {'bases': bases_obj, 'marker': marker_obj}


def resolve(rows):
    out = []
    for address, key, unit in rows:
        funcs = match.coff_functions(OBJECTS[unit].read_bytes())
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key)
                                                       and not LOCAL_EH.match(x[0])]
        assert len(hits) == 1, (hex(address), key, [h[0] for h in hits])
        out.append((address, hits[0][0], unit))
    return out


def bind(symbol, value, where):
    prev = binding.setdefault(symbol, (value, where))
    assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), where)


def literal_of(raw, sections, definitions, symbol):
    pos, at = definitions[symbol]
    return raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'


def verify(rows, own):
    result = []
    for address, name, unit in rows:
        raw = OBJECTS[unit].read_bytes()
        sections, symbols, definitions, _ = match._coff_data_index(raw)
        bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        ok = match.exact_match(target, target_refs, body, refs)
        if DISCOVER and not ok:
            print('NOT EXACT', hex(address), name)
            continue
        assert ok, (name, hex(address), len(body), len(target))
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
                assert hit[1] == nb.plain(symbol) or EXTERNAL.get(symbol) == value, (name, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol.startswith('??_C@'):
                literal = literal_of(raw, sections, definitions, symbol)
                assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
                how = 'literal %r' % literal[:-1].decode()
            elif symbol in ('?sReplicator@Network@RBX@@3QBDB', '?sMarker@Network@RBX@@3QBDB'):
                literal = literal_of(raw, sections, definitions, symbol)
                assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
                how = 'class-name array %r' % literal[:-1].decode()
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
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in DATA:
                assert DATA[symbol] == value, (name, symbol, hex(value))
                how = 'data'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
            elif symbol.startswith('??_B?1??') or symbol.startswith('?$S') or symbol.startswith('?foo@') \
                    or symbol.startswith('?n@') or symbol.startswith('?flag@'):
                how = 'local static'
            else:
                UNBOUND.append('%s in %s -> %s (%s)' % (symbol, name, hex(value), names.get(value, '')))
                continue
            bind(symbol, value, name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        result.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'exact': True,
                       'verified_targets': verified, 'local_eh': sorted(local)})
    return result


atexit_rows = []
for init, (key, unit) in ATEXIT.items():
    body, _, _ = match.target('2008-06', '%08x' % init)
    call = max(i for i in range(len(body) - 4) if body[i] == 0xe8
               and (init + i + 5 + struct.unpack_from('<i', body, i + 1)[0]) & 0xffffffff == EXTERNAL['_atexit'])
    push = body.rindex(b'\x68', 0, call)
    atexit_rows.append((struct.unpack_from('<I', body, push + 1)[0], key, unit))

rows = resolve(ROWS + atexit_rows)
own = {}
for address, name, unit in rows:
    assert own.setdefault(name, address) == address, (name, hex(address))
out = verify(rows, own)
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- vtables (current-header objects), RTTI, allocation sizes and strings ----------------------------
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]


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


# Constructor vtable stores: every store of the original constructor must be one bound vtable symbol.
STORES = {
    0x4b94a0: ('.?AVIdSerializer@Network@RBX@@', [0x82534c, 0x82533c, 0x825334, 0x82532c, 0x82531c, 0x82530c,
                                                  0x8252fc, 0x8252ec, 0x8252dc, 0x8252cc]),
    0x4b9570: ('.?AV' + NFP, [0x82540c, 0x825400, 0x8253f8, 0x8253f0, 0x8253e0, 0x8253d0, 0x8253c0, 0x8253b0,
                              0x8253a0, 0x825390]),
    0x4b9ad0: ('.?AV' + DNC, [0x8255d4, 0x8255c8, 0x8255c0, 0x8255b8, 0x8255a8, 0x825598, 0x825588, 0x825578,
                              0x825568, 0x825558]),
    0x4b85b0: ('.?AV' + MFP, [0x8251e8]),
    0x4b9140: ('.?AVMarker@Network@RBX@@', [0x82529c]),
}
bound_vts = {v: s for s, (v, _) in binding.items() if s.startswith('??_7')}
for ctor, (rtti, vts) in STORES.items():
    body, _, _ = match.target('2008-06', '%08x' % ctor)
    for vt in vts:
        assert struct.pack('<I', vt) in body, (hex(ctor), hex(vt))
        assert original.vtable_class(vt)[0] == rtti, (hex(vt), original.vtable_class(vt), rtti)
        assert vt in bound_vts, ('vtable store not bound', hex(ctor), hex(vt))

text = next(x for x in original.pe.sections if x.Name.startswith(b'.text'))
TEXT = (original.image + text.VirtualAddress, original.image + text.VirtualAddress + text.Misc_VirtualSize)


def original_slots(vt):
    n = 0
    while TEXT[0] <= d(vt + 4 * n) < TEXT[1]:
        n += 1
    return n


# Vtables of the classes recovered here (every vtable their constructors store) are slot-checked against the
# original: same slot count and every slot bound. Other vtables the rows reference (Instance bases, the Marker
# signal descriptor) are verified by RTTI only. Known slot-count difference, recorded rather than hidden:
# util/Object.h declares NonFactoryProduct::getClassName `virtual`, which adds a slot 1 to Marker and
# NonFactoryProduct<DescribedBase, sMarker> (DescribedBase has no getClassName); the 2008 vtables 0082529c and
# 008251e8 have one slot. PROPOSAL below; the pending build confirms it.
KNOWN_EXTRA_SLOT = {0x82529c: 1, 0x8251e8: 1}
checked = sorted({vt for _, vts in STORES.values() for vt in vts})
vtables = []
for vt in checked:
    symbol = bound_vts[vt]
    obj = next(OBJECTS[u] for u in OBJECTS if symbol in match._coff_data_index(OBJECTS[u].read_bytes())[2])
    slots = vtable_slots(obj, symbol)
    count = original_slots(vt)
    assert len(slots) == count + KNOWN_EXTRA_SLOT.get(vt, 0), (hex(vt), symbol, len(slots), count)
    entries = {}
    for slot, name in sorted(slots.items()):
        if slot >= count:
            entries[slot] = '%s -> (no slot in the 2008 vtable; util/Object.h proposal)' % name
            continue
        value = d(vt + 4 * slot)
        if name.startswith('??_E') and ('??_G' + name[4:]) in own:
            assert own['??_G' + name[4:]] == value, (symbol, slot, name, hex(value))
            how = 'own row (??_G)'
        elif name in own:
            assert own[name] == value, (symbol, slot, name, hex(value), hex(own[name]))
            how = 'own row'
        elif name in EXTERNAL:
            assert EXTERNAL[name] == value, (symbol, slot, name, hex(value))
            how = 'external'
        else:
            how = 'evidence name' if norm(names.get(value, '')) == norm(name) else 'bound (consistent across rows/slots)'
        bind(name, value, symbol)
        entries[slot] = '%s -> %s (%s)' % (name, hex(value), how)
    vtables.append({'vtable': hex(vt), 'symbol': symbol, 'rtti_offset': original.vtable_class(vt)[1],
                    'original_slots': count, 'slots': entries})

# Pending build: Marker unit against a generated util/Object.h copy where NonFactoryProduct::getClassName is not
# declared virtual (it still overrides where the base declares it). Only the Marker vtable slot counts are checked
# there; no row is counted from it.
pending = OUT / 'pending'
(pending / 'util').mkdir(parents=True, exist_ok=True)
OBJECT_H = R / 'native-headers/util/Object.h'
ANCHOR = """	class NonFactoryProduct : public DerivedClass
	{
	public:
		NonFactoryProduct()
			: DerivedClass()
		{
		}

		template<typename T0>
		NonFactoryProduct(T0 arg0)
			: DerivedClass(arg0)
		{
		}

		virtual const Name& getClassName() const;
"""
text_h = OBJECT_H.read_text()
assert text_h.count(ANCHOR) == 1
(pending / 'util/Object.h').write_text(text_h.replace(ANCHOR, ANCHOR.replace('\t\tvirtual const Name& getClassName', '\t\tconst Name& getClassName')))
pend_obj = OUT / 'NativeReplicatorMarkerPending.obj'
pend_flags = nb.flags()
i = next(k for k, x in enumerate(pend_flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
pend_flags = pend_flags[:i] + ['/I' + str(pending)] + pend_flags[i:] + ['/Fo' + str(pend_obj), str(MARKER)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', pend_flags, OUT)
assert code == 0, log
pend_raw = pend_obj.read_bytes()
pend_defs = match._coff_data_index(pend_raw)[2]
for vt in KNOWN_EXTRA_SLOT:
    symbol = bound_vts[vt]
    assert symbol in pend_defs, symbol
    assert len(vtable_slots(pend_obj, symbol)) == original_slots(vt), (hex(vt), symbol)
PROPOSALS = [
    'util/Object.h (NonFactoryProduct): declare `const Name& getClassName() const;` without `virtual` (it still '
    'overrides Object/Instance getClassName); 2008 Marker 0082529c and NonFactoryProduct<DescribedBase, sMarker> '
    '008251e8 vtables have one slot (the deleting destructor 004b8600); with `virtual` the current header adds slot 1. '
    'Verified by the pending Marker build in this recorder (slot counts equal).',
]

# Replicator RTTI: PluginInterface directly after IdSerializer (sizeof 0x2b74).
locator = d(0x8254fc - 4)
hierarchy = d(locator + 16)
items = [d(d(hierarchy + 12) + 4 * i) for i in range(d(hierarchy + 8))]
bases = {original.string(d(item) + 8): struct.unpack('<i', original.data(item + 8, 4))[0] for item in items}
assert bases['.?AVPluginInterface@@'] == 0x2b74, bases
assert bases['.?AVIdSerializer@Network@RBX@@'] == 0, bases
body, _, _ = match.target('2008-06', '004b9190')
assert b'\x6a\x10' in body  # newMarker: operator new(0x10)
assert original.string(0x8244e4) == 'NetworkReplicator' and original.string(0x8244f8) == 'NetworkMarker'
assert original.string(0x825710) == 'Received'

sha = nb.sha
paths = [Path(__file__).resolve(), BASES, MARKER, LAYOUT] + HEADERS
exact_addresses = sorted({r['address'] for r in out})
receipt = {
    'class': 'RBX::Network::IdSerializer / Replicator base chain / Marker', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'bases': bases_flags, 'marker': marker_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, bases_obj, marker_obj)},
    'layout': 'StringSender 0xe24 (dictionary +0x00 map 0x20, strings[128] +0x20, lastIndex +0xe20 = 1); StringReceiver '
              'strings[256] (0x1c00) at +0xe24 of SharedStringDictionary (0x2a24); IdSerializer 0x2b74 (Instance, '
              'scopeNames +0x130, waitItems +0x2b54); Replicator PluginInterface +0x2b74; Marker 0x10 (returned +0xc).',
    'methods': out, 'not_exact': NOT_EXACT, 'vtables': vtables, 'proposals': PROPOSALS,
    'pending_flags': pend_flags,
    'exact_distinct_addresses': exact_addresses,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit. Replicator '
             'itself (layout past +0x2b74, constructor 004b9bd0, destructor 004b96b0) and its Item classes remain open.',
}
(ROOT / 'work/2008-06/shared-layouts/network-replicator-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Network::IdSerializer/Replicator bases/Marker: %d exact rows (%d distinct addresses), %d not exact; '
      '%d vtables; targets verified' % (len(out), len(exact_addresses), len(NOT_EXACT), len(vtables)))
