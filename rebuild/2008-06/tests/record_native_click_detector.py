"""Verify the inactive native RBX::ClickDetector recovery (2008-06).

Builds (document-swap flags + /fp:fast, VS2008 RTM 21022):
  * tests/NativeClickDetectorLayout.cpp   sizeof / base-offset probes (mov eax, imm32; ret) and compile-time
                                          offset asserts;
  * native-classes/ClickDetector.cpp      the original unit (00629340..00629b9a, initializers 007f7d20..007f7d90,
                                          atexit 00800330..00800370) plus the ClickDetector template instances whose
                                          original bodies live elsewhere (COMDAT / ICF);
    The former NATIVE_CLICKDETECTOR_PENDING rows (findFirstChildOfType<ClickDetector> 006294a0, askSetParent
    006298d0, setFrontendMouseClick 00629a70, isClickable 00629b20) are built and counted from this object: the
    committed native Instance.h, Service.h, Camera.h, ModelInstance.h and Workspace.h declare what they need.

Every row must be relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, string literals by bytes,
float constants by bits, type descriptors and vtables by original RTTI names, own symbols by the row proven here,
descriptor statics and the class-name array by the DATA map, ICF folds by the FOLDED map, and the remaining
externals by the EXTERNAL map (call sites read in the original disassembly). A symbol must bind to one address in
every row. Each ClickDetector / FactoryProduct / DescribedCreatable vtable of the main build (never the pending
one) is compared slot by slot with the original vtable it binds to. Writes
work/2008-06/shared-layouts/click-detector-working.json.
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
SRC = R / 'native-classes/ClickDetector.cpp'
HDR = R / 'native-headers/v8datamodel/ClickDetector.h'
LAYOUT = R / 'tests/NativeClickDetectorLayout.cpp'
UNIT_FLAGS = ['/fp:fast']   # click 00629ac0 (`fld [esi+0x144]; fcomp [esp+0xc]`), isClickable 00629b20,
                            # BoundPropGetSet<ClickDetector>::setValue 005bd680

# The former pending build (generated Instance.h / Service.h / Camera.h / Workspace.h copies) is folded into the main
# build: the committed native headers declare findFirstChildOfType, findServiceProvider, Camera and Workspace.
assert (R / 'native-headers/v8tree/Instance.h').read_text().count('Type* findFirstChildOfType() const') == 1
assert (R / 'native-headers/v8tree/Service.h').read_text().count('static const ServiceProvider* findServiceProvider(const Instance*);') == 1


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeClickDetectorLayout', LAYOUT)
main_obj, main_flags = build('NativeClickDetector', SRC, UNIT_FLAGS)

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
for prefix, value in (('?nativeClickDetectorSize@@', 0x14c), ('?nativeClickDetectorRenderable@@', 0x130),
                      ('?nativeInstanceSize@@', 0x130)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,                       # FactoryProduct ctor 006293a0
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                       # FactoryProduct dtor 00629340 (tail jmp)
    '??1IRenderable@RBX@@QAE@XZ': 0x47d410,                    # ~ClickDetector 006299a0 (shared ret)
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,   # click 00629ac0
    '?backendProcessing@Players@Network@RBX@@SA_NPBVInstance@3@_N@Z': 0x495eb0,                  # 00629a70 / 00629ac0
    '?findServiceProvider@ServiceProvider@RBX@@SAPBV12@PBVInstance@2@@Z': 0x4898d0,              # 00629a70 (pending)
    '?findSignalInstance@SignalDescriptor@Reflection@RBX@@IBEPAVSignalInstance@23@PBVSignalSource@23@@Z': 0x56b620,
    '??R?$signal0@XU?$last_value@X@boost@@HU?$less@H@std@@V?$function@$$A6AXXZV?$allocator@X@std@@@2@@boost@@QAE?AUunusable@?$last_value@X@1@XZ': 0x4b5950,
    '??0SignalDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD@Z': 0x56bab0,             # initializer 007f7d20
    '??1?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@QAE@XZ': 0x4199e0,  # atexit 00800370
    '___RTDynamicCast': 0x6a17c6, '_atexit': 0x6a17af,
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,              # doDeclare<sClickDetector> 005bf800
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,               # getClassName 00629540
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,   # classDescriptor 005c02b0
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,      # atexit 007fe800
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,
    # TypedPropertyDescriptor<T> constructors called by the PropDescriptor / BoundProp constructors 00629560 / 00629610
    '??0?$TypedPropertyDescriptor@_N@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@_N@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x40a290,
    '??0?$TypedPropertyDescriptor@M@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@M@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x445610,
}
# Descriptor objects: the `this` the dynamic initializers 007f7d20..007f7d90 pass; the class-name char array.
DATA = {
    '?event_MouseClick@ClickDetector@RBX@@2V?$SignalDesc@VClickDetector@RBX@@$$A6AXXZ@Reflection@2@A': 0x97bf80,
    '?desc_FrontendMouseClick@RBX@@3V?$PropDescriptor@VClickDetector@RBX@@_N@Reflection@2@A': 0x97bf64,
    '_desc_FrontendMouseClick': 0x97bf64,
    '?prop_MaxActivationDistance@ClickDetector@RBX@@2V?$BoundProp@M$00@Reflection@2@A': 0x97bfb4,
    '?sClickDetector@RBX@@3PADA': 0x95b3c8,
}

CD = 'ClickDetector@RBX@@'
FP = '?$FactoryProduct@VClickDetector@RBX@@VInstance@2@$1?sClickDetector@2@3PADA@RBX@@'
DC = '?$DescribedCreatable@VClickDetector@RBX@@VInstance@2@$1?sClickDetector@2@3PADA@RBX@@'
DS = '?$Described@VClickDetector@RBX@@$1?sClickDetector@2@3PADAV' + FP[:-6] + '@2@@Reflection@RBX@@'
GS_B = '?$GetSetImpl@P8ClickDetector@RBX@@BE_NXZP812@AEX_N@Z@?$PropDescriptor@VClickDetector@RBX@@_N@Reflection@RBX@@'
BP_F = '?$BoundPropGetSet@VClickDetector@RBX@@@?$BoundProp@M$00@Reflection@RBX@@'

# ICF / trivial-wrapper folds: the original keeps one body where this unit emits several identical ones.
FOLDED = {}

# (address, symbol or unique symbol prefix)
ROWS = [
    (0x629340, '??1' + FP + 'MAE@XZ'),
    (0x6293a0, '??0' + FP + 'IAE@XZ'),
    (0x629410, '??_G' + FP + 'MAEPAXI@Z'),
    (0x629440, '??1' + DS + 'UAE@XZ'),
    (0x629450, '??$getset@P8ClickDetector@RBX@@BE_NXZ'),
    (0x629540, '?getClassName@' + FP + 'UBEABVName@2@XZ'),
    (0x629560, '??$?0P8ClickDetector@RBX@@BE_NXZ'),
    (0x629610, '??$?0VClickDetector@RBX@@@?$BoundProp@M$00@'),
    (0x6296e0, '??0' + DC + 'IAE@XZ'),
    (0x6297e0, '??0ClickDetector@RBX@@QAE@XZ'),
    (0x6299a0, '??1ClickDetector@RBX@@UAE@XZ'),
    (0x629a50, '??_GClickDetector@RBX@@UAEPAXI@Z'),
    (0x629ac0, '?click@' + CD),
    (0x7f7d20, '??__E?event_MouseClick@' + CD),
    (0x7f7d50, '??__Edesc_FrontendMouseClick@RBX@@YAXXZ'),
    (0x7f7d90, '??__E?prop_MaxActivationDistance@' + CD),
    (0x800330, '??__F?prop_MaxActivationDistance@' + CD),
    (0x800350, '??__Fdesc_FrontendMouseClick@RBX@@YAXXZ'),
    (0x800370, '??__F?event_MouseClick@' + CD),
    (0x7fe800, '??__Ffoo@?1??classDescriptor@' + DS),
    # template instances / inline members whose original bodies live outside the unit (COMDAT / ICF-shared)
    (0x5c02b0, '?classDescriptor@' + DS + 'SAAAVClassDescriptor@23@XZ'),
    (0x5bf800, '??$doDeclare@$1?sClickDetector@RBX@@3PADA@Name@RBX@@CAABV01@XZ'),
    (0x5bff70, '??$callDoDeclare@$1?sClickDetector@RBX@@3PADA@Name@RBX@@CAXXZ'),
    (0x68e8c0, '?getFrontendMouseClick@' + CD),
    (0x565ff0, '?askAddChild@' + CD),
    (0x565950, '?shouldRender3dAdorn@' + CD),
    (0x598310, '??_G?$PropDescriptor@VClickDetector@RBX@@_N@Reflection@RBX@@UAEPAXI@Z'),
    (0x41bdf0, '??_G?$SignalDesc@VClickDetector@RBX@@$$A6AXXZ@Reflection@RBX@@UAEPAXI@Z'),
    # GetSet bodies (getset vtables 00845950 / 0084593c slots 0..3, checked below)
    (0x60a2f0, '?isReadOnly@' + GS_B + 'UBE_NXZ'),
    (0x5cf660, '?getValue@' + GS_B),
    (0x48abf0, '?setValue@' + GS_B),
    (0x60a2f0, '?isReadOnly@' + BP_F + 'UBE_NXZ'),
    (0x62a130, '?getValue@' + BP_F),
    (0x5bd680, '?setValue@' + BP_F),
]
# Deleting-destructor adjustor thunks (sub ecx, N; jmp ??_G), read from the original bodies:
# FactoryProduct ones jump to 00629410, ClickDetector ones to 00629a50.
THUNKS = {
    'leaf': {'BE': 0x629920, 'CE': 0x629930, 'EE': 0x629940, 'GE': 0x629950, 'IE': 0x629960, 'KE': 0x629970,
             'ME': 0x629980, 'BA': 0x629990},
    'base': {'CE': 0x629400, 'BA': 0x629430, 'EE': 0x629780, 'GE': 0x629790, 'IE': 0x6297a0, 'KE': 0x6297b0,
             'ME': 0x6297c0, 'BE': 0x6297d0},
}
ROWS += [(0x629410, '??_G' + DC + 'UAEPAXI@Z'), (0x629440, '??1' + DC + 'UAE@XZ')]
for adj, address in sorted(THUNKS['leaf'].items(), key=lambda x: x[1]):
    ROWS.append((address, '??_EClickDetector@RBX@@W' + adj + '@AEPAXI@Z'))
for adj, address in sorted(THUNKS['base'].items(), key=lambda x: x[1]):
    ROWS.append((address, '??_E' + FP + 'O' + adj + '@AEPAXI@Z'))
    ROWS.append((address, '??_E' + DC + 'W' + adj + '@AEPAXI@Z'))

# Former pending rows (NATIVE_CLICKDETECTOR_PENDING removed): built and counted from the main object.
PENDING_ROWS = [
    (0x6294a0, '??$findFirstChildOfType@VClickDetector@RBX@@@Instance@RBX@@QBEPAVClickDetector@1@XZ'),
    (0x6298d0, '?askSetParent@' + CD),
    (0x629a70, '?setFrontendMouseClick@' + CD),
    (0x629b20, '?isClickable@' + CD),
]
PENDING_REASON = {
    '006294a0': 'Instance::findFirstChildOfType<ClickDetector> (member template absent from the native Instance.h)',
    '006298d0': 'askSetParent: dynamic_cast to ModelInstance needs a native ModelInstance.h that compiles (donor '
                'Camera.h passes &sCamera)',
    '00629a70': 'setFrontendMouseClick: ServiceProvider::findServiceProvider absent from the native Service.h',
    '00629b20': 'isClickable: findFirstChildOfType<ClickDetector> and a complete RBX::Workspace',
}
PROPOSALS = [
    'native-headers/v8tree/Instance.h (shared, not edited; same as the Team proposal): member template '
    '`template<class Type> Type* findFirstChildOfType() const` walking `children` with dynamic_cast, the donor '
    'body (006294a0 = <ClickDetector>, 005d5f40 = <Humanoid>).',
    'native-headers/v8tree/Service.h (shared, not edited): `static const ServiceProvider* '
    'findServiceProvider(const Instance* context);` in ServiceProvider (004898d0; evidence name '
    '?findServiceProvider@ServiceProvider@RBX@@SAPBV12@PBVInstance@2@@Z, called by setFrontendMouseClick 00629a70).',
    'v8datamodel/Camera.h (donor, reached through the native ModelInstance.h): declare `extern char sCamera[];` and '
    'derive from DescribedCreatable<Camera, Instance, sCamera> (2008 const-char-array template parameter), as in the '
    'record_native_appearance.py proposal; needed for dynamic_cast<const ModelInstance*> in askSetParent 006298d0.',
    'v8datamodel/Workspace.h: a native header that compiles against the 2008 reflection.h (isClickable 00629b20 only '
    'needs a complete polymorphic Workspace for dynamic_cast, type descriptor 009481b8).',
]

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}   # symbol -> (address, row) for the one-address-per-symbol check


def resolve(obj, rows):
    raw = Path(obj).read_bytes()
    funcs = match.coff_functions(raw)
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key)
                                                       and not LOCAL_EH.match(x[0])]
        assert len(hits) == 1, (hex(address), key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def data_address(symbol):
    hits = [v for k, v in DATA.items() if symbol == k]
    return hits[0] if len(hits) == 1 else None


def classify(symbol, value, own, raw, sections, definitions, where):
    """Return how a relocation target bound to `value` is verified, or None when unknown."""
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol.startswith('??_C@'):
        pos, at = definitions[symbol]
        literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
        assert original.data(value, len(literal)) == literal, (where, symbol, hex(value))
        return 'literal %r' % literal[:-1].decode()
    if symbol.startswith('__real@') and len(symbol) == 15:
        bits = struct.pack('<I', int(symbol[7:], 16))
        assert original.data(value, 4) == bits, (where, symbol, hex(value))
        return 'float constant %r' % struct.unpack('<f', bits)
    if symbol.startswith('??_R0') and symbol.endswith('@8'):
        rtti = original.string(value + 8)
        assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
        return 'RTTI %s' % rtti
    if symbol.startswith('??_7'):
        rtti, at = original.vtable_class(value)
        cls = symbol[4:symbol.index('@@6B') + 2]
        assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
        return 'vtable RTTI %s offset %#x' % (rtti, at)
    if symbol in own:
        assert own[symbol] == value, (where, symbol, hex(value), hex(own[symbol]))
        return 'own row'
    if symbol.startswith('??_E') and ('??_G' + symbol[4:]) in own:
        assert own['??_G' + symbol[4:]] == value, (where, symbol, hex(value))
        return 'own row (??_G)'
    if symbol in FOLDED:
        assert FOLDED[symbol] == value, (where, symbol, hex(value))
        return 'folded'
    at = data_address(symbol)
    if at is not None:
        assert at == value, (where, symbol, hex(value), hex(at))
        return 'data'
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
        return 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
    if symbol.startswith('??_B?1??') or symbol.startswith('?$S') or '?$TSS' in symbol or symbol.startswith('?flag@') \
            or symbol.startswith('?foo@') or symbol.startswith('?root@') or symbol.startswith('?n@?1???$doDeclare@'):
        return 'local static'
    return None


def verify(obj, rows, own):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        assert match.exact_match(target, target_refs, body, refs), (name, hex(address), len(body), len(target))
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
            how = classify(symbol, value, own, raw, sections, definitions, name)
            if how is None:
                UNBOUND.append('%s in %s -> %s' % (symbol, name, hex(value)))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        result.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'exact': True,
                       'verified_targets': verified, 'local_eh': sorted(local)})
    return result


ROWS += PENDING_ROWS
main_rows = resolve(main_obj, ROWS)
own = {}
for address, name in main_rows:
    own.setdefault(name, address)
main_out = verify(main_obj, main_rows, own)
pend_out = []   # no pending build
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- vtables of the main build, slot by slot against the original vtable each one binds to -----------
INSTANCE_VTABLES = {0x0: 0x82d884, 0x10: 0x82d878, 0x14: 0x82d870, 0x20: 0x82d868, 0x24: 0x82d858, 0x44: 0x82d848,
                    0x64: 0x82d838, 0x84: 0x82d828, 0xa4: 0x82d818, 0xc4: 0x82d808}
for at, vt in INSTANCE_VTABLES.items():
    assert original.vtable_class(vt) == ('.?AVInstance@RBX@@', at), (hex(vt), original.vtable_class(vt))
CLASSES = (CD, FP, DC)
raw = main_obj.read_bytes()
sections, symbols, definitions, starts = match._coff_data_index(raw)
vtables = {}
for symbol, (value, sec) in definitions.items():
    if not symbol.startswith('??_7') or symbol not in binding:
        continue
    if not any(symbol[4:].startswith(c + '6B') for c in CLASSES):
        continue
    vt = binding[symbol][0]
    rtti, at = original.vtable_class(vt)
    table = sections[sec]
    end = min([x for x in starts[sec + 1] if x > value] + [table[3]])
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if value <= offset < end:
            slots[(offset - value) // 4] = symbols[index][0]
    assert slots and max(slots) == len(slots) - 1, (symbol, sorted(slots))
    checked = {}
    for slot, sym in sorted(slots.items()):
        value_orig = d(vt + 4 * slot)
        how = classify(sym, value_orig, own, raw, sections, definitions, symbol)
        if how is None and at in INSTANCE_VTABLES and d(INSTANCE_VTABLES[at] + 4 * slot) == value_orig \
                and 'ClickDetector' not in sym:
            how = 'inherited (Instance vtable %#x slot %d)' % (INSTANCE_VTABLES[at], slot)
        if how is None and at == 0x130 and sym.endswith('@IRenderable@RBX@@UAEXPAVAdorn@2@@Z') \
                and value_orig == 0x70bdf0:
            how = 'inherited IRenderable default (shared empty body 0070bdf0, as Instance vtable slot 7)'
        if how is None and at == 0x130 and sym in ('?shouldRender2d@IRenderable@RBX@@MBE_NXZ',) and value_orig == 0x60a2f0:
            how = 'inherited IRenderable default (ICF-shared return false 0060a2f0)'
        if how is None and at == 0x130 and sym.startswith('?render3dSelect@IRenderable@RBX@@') and value_orig == 0x458e90:
            how = 'inherited IRenderable default (ICF-shared 00458e90, as Instance vtable slot 12)'
        if how is None:
            UNBOUND.append('vtable %s slot %d %s -> %s' % (symbol, slot, sym, hex(value_orig)))
            continue
        prev = binding.setdefault(sym, (value_orig, symbol))
        assert prev[0] == value_orig, ('inconsistent', sym, hex(prev[0]), prev[1], hex(value_orig), symbol)
        checked[slot] = '%s = %s (%s)' % (sym, hex(value_orig), how)
    vtables[symbol] = {'address': hex(vt), 'rtti': rtti, 'offset': hex(at), 'slots': checked}
assert not UNBOUND, '\n'.join(UNBOUND)
for vt in (0x845afc, 0x845a68):
    assert any(v['address'] == hex(vt) for v in vtables.values()), (hex(vt), 'vtable not checked')
assert original.vtable_class(0x845afc) == ('.?AVClickDetector@RBX@@', 0)
assert original.vtable_class(0x845a68) == ('.?AVClickDetector@RBX@@', 0x130)
assert d(0x845afc + 8) == 0x565ff0 and d(0x845afc + 12) == 0x6298d0   # askAddChild, askSetParent overridden
assert d(0x82d884 + 8) == 0x68e880 and d(0x82d884 + 12) == 0x68e880   # Instance defaults
assert [d(0x845a68 + 4 * i) for i in range(5)] == [0x60a2f0, 0x565950, 0x70bdf0, 0x70bdf0, 0x458e90]
# getset vtables (2008 GetSet: isReadOnly, isWriteOnly, getValue, setValue): bodies are rows above
for vt, rtti, getter, setter in ((0x845950, 'GetSetImpl@P8ClickDetector', 0x5cf660, 0x48abf0),
                                 (0x84593c, 'BoundPropGetSet@VClickDetector', 0x62a130, 0x5bd680)):
    assert rtti in original.vtable_class(vt)[0], (hex(vt), original.vtable_class(vt))
    assert [d(vt + 4 * i) for i in range(4)] == [0x60a2f0, 0x60a2f0, getter, setter], hex(vt)
# descriptor vtables stored by the initializers / constructors
assert original.vtable_class(0x845a58)[0] == '.?AV?$SignalDesc@VClickDetector@RBX@@$$A6AXXZ@Reflection@RBX@@'
assert original.vtable_class(0x845964)[0] == '.?AV?$PropDescriptor@VClickDetector@RBX@@_N@Reflection@RBX@@'
assert d(0x845a58) == 0x41bdf0 and d(0x845964) == 0x598310

# ---- allocation size, RTTI bases and strings -----------------------------------------------------------
body, _, _ = match.target('2008-06', '005c0b60')
at = body.index(b'\x68' + struct.pack('<I', 0x14c))
call = body.index(b'\xe8', at + 5)
while (0x5c0b60 + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != 0x6297e0:
    call = body.index(b'\xe8', call + 1)
for address, text in ((0x95b3c8, 'ClickDetector'), (0x845b3c, 'ClickDetector'), (0x845b4c, 'MouseClick'),
                      (0x845b58, 'FrontendMouseClick'), (0x845b6c, 'MaxActivationDistance'), (0x82d944, 'Behavior'),
                      (0x822490, 'Data')):
    assert original.string(address) == text, (hex(address), text)
assert struct.unpack('<f', original.data(0x833eac, 4))[0] == 32.0
# initializer arguments: FrontendMouseClick Functionality 4 (STREAMING), MaxActivationDistance member 0x144 / 5
body, _, _ = match.target('2008-06', '007f7d50')
assert body[:3] == b'\x56\x6a\x04', body[:3].hex()
body, _, _ = match.target('2008-06', '007f7d90')
assert body[:7] == b'\x6a\x05\x68' + struct.pack('<I', 0x144), body[:7].hex()
locator = d(0x845afc - 4)
hierarchy = d(locator + 16)
items = [d(d(hierarchy + 12) + 4 * i) for i in range(d(hierarchy + 8))]
bases = {original.string(d(item) + 8): struct.unpack('<i', original.data(item + 8, 4))[0] for item in items}
assert len(items) == 22 and bases['.?AVIRenderable@RBX@@'] == 0x130 and ('.?AV' + DC) in bases, bases

exact = [r['address'] for r in main_out]
sha = nb.sha
paths = [Path(__file__).resolve(), HDR, SRC, LAYOUT]
receipt = {
    'class': 'RBX::ClickDetector', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'main': main_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, main_obj)},
    'layout': {'ClickDetector': '0x14c (create<ClickDetector> 005c0b60 allocates 0x14c); IRenderable +0x130, '
                                'int +0x140 (constructor stores 0; no other access found), maxActivationDistance '
                                '+0x144, frontendMouseClick +0x148 (not initialized by the constructor); RTTI 22 bases'},
    'methods': main_out,
    'exact_count': len(main_out), 'exact_unique_addresses': len(set(exact)),
    'pending_methods': pend_out,
    'pending_note': 'No pending build: the former pending rows (former reasons in former_pending_reasons) compile '
                    'against the committed native headers and are counted from the main build.',
    'former_pending_reasons': PENDING_REASON,
    'non_exact': {},
    'proposals': PROPOSALS,
    'vtables': vtables,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/click-detector-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native ClickDetector: %d rows exact (%d unique addresses), %d pending-only (%d unique), %d vtables checked' % (
    len(main_out), len(set(exact)), len(pend_out), len({r['address'] for r in pend_out}), len(vtables)))
