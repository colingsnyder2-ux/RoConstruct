"""Verify the inactive native 2008-06 Roblox Lua object bridge (RBX::Lua userdata wrappers).

Step 1 (boundary proof, recorded in the receipt under 'boundary'): the bridge range is 0061a420..006217e2.
  * Before it: the boost 1.34.1 thread tss_hooks unit (0061a090..0061a3f0; 0061a3f0 is the TLS callback that calls
    on_process_exit 0061a110 for DLL_PROCESS_DETACH) and 0061a400 (31 bytes, called only from 0061b190).
  * First bridge function: RBX::Lua::newweaktable 0061a420 (exact row below).
  * After it: Lua 5.1.1 ldo.c (luaD_seterrorobj 006217f0, luaD_rawrunprotected 00621920, ...), compiled as C++,
    which calls only Lua internals.
  * .data: every unit's data block of this range starts with the std::bad_alloc message pointer ("bad allocation"),
    followed by its constant-initialized Bridge<T>::className statics: 0095af74 "Object" (instance bridge);
    0095b1bc..0095b1c8 "Color3" "Vector3" "BrickColor" "CFrame" (atomic classes); 0095b1d4..0095b1dc "Enums"
    "Enum" "EnumItem" (enum bridges); 0095b1e4/0095b1e8 "RBXScriptSignal" "RBXScriptConnection" (signal bridge).
    The recorder re-reads all of them from the image.
Step 2: three inactive units built with the document-swap flags (VS2008 RTM 21022):
  native-classes/LuaBridge2008Instance.cpp, LuaBridge2008Atomic.cpp, LuaBridge2008Signal.cpp
  (declarations: native-headers/LuaBridge2008/LuaBridge2008.h, LuaSignalBridge2008.h).
Every relocation of an exact row is bound to the address the original instruction uses and verified: imports by
DLL name / ordinal, literals by bytes, RTTI and vtables by original RTTI names, Bridge<T>::className statics by the
string their constant pointer names, Lua library functions and other externals by the offline evidence name at that
address (one address per symbol), inline bodies this unit emits by bytes equal at the called address (recursively).
Vtable slots are compared from the objects built from the current headers. No pending build exists: code needing
missing shared declarations is guarded by NATIVE_LUABRIDGE_PENDING and is not compiled or counted.
Writes work/2008-06/shared-layouts/lua-bridge2008-working.json.
"""
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_bind as nb  # noqa: E402
from native_bind import ROOT, OUT, LOCAL_EH, Original, flags, match, rebuild, sha  # noqa: E402

HDR = ROOT / 'rebuild/2008-06/native-headers'
SRC = ROOT / 'rebuild/2008-06/native-classes'
BRIDGE_H = HDR / 'LuaBridge2008/LuaBridge2008.h'
SIGNAL_H = HDR / 'LuaBridge2008/LuaSignalBridge2008.h'
UNITS = {'instance': SRC / 'LuaBridge2008Instance.cpp', 'atomic': SRC / 'LuaBridge2008Atomic.cpp',
         'signal': SRC / 'LuaBridge2008Signal.cpp'}
original = Original()


def d(address):
    return struct.unpack('<I', original.data(address, 4))[0]


def build(source, name, extra=()):
    OUT.mkdir(parents=True, exist_ok=True)
    obj = OUT / (name + '.obj')
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags() + list(extra) + ['/Fo' + str(obj), str(source)], OUT)
    assert code == 0, log
    return obj


OBJ = {k: build(v, 'NativeLuaBridge2008' + k.capitalize()) for k, v in UNITS.items()}
LIBS = []
ATLS_INDEX = {}

# ---- rows ---------------------------------------------------------------------------------------------------
CF = 'CoordinateFrame@G3D@@'
CFB = '@CoordinateFrameBridge@Lua@RBX@@CAHPAUlua_State@@@Z'
TGSW = 'TGenericSlotWrapper@'
ROWS = {
    'instance': [
        (0x0061a420, '?newweaktable@Lua@RBX@@YAXPAUlua_State@@PBD@Z'),
        (0x0061a4f0, '?getPtr@?$SharedPtrBridge@VDescribedBase@Reflection@RBX@@@Lua@RBX@@SA?AV?$shared_ptr@VDescribedBase'
                     '@Reflection@RBX@@@boost@@PAUlua_State@@I@Z'),
        (0x0061bb00, '?signals_end@DescribedBase@Reflection@RBX@@QAE?AVIterator@?$MemberDescriptorContainer@VSignalDescriptor'
                     '@Reflection@RBX@@@23@XZ'),
        (0x0061bb30, '?findSignal@DescribedBase@Reflection@RBX@@QAE?AVIterator@?$MemberDescriptorContainer@VSignalDescriptor'
                     '@Reflection@RBX@@@23@ABVName@3@@Z'),
    ],
    'atomic': [
        (0x0061c6f0, '??H' + CF + 'QBE?AV01@ABVVector3@1@@Z'),
        (0x0061c740, '??G' + CF + 'QBE?AV01@ABVVector3@1@@Z'),
        (0x0061c8c0, '?on_index@?$Bridge@VColor3@G3D@@$00@Lua@RBX@@KAHABVColor3@G3D@@PBDPAUlua_State@@@Z'),
        (0x0061ca60, '??$getValue@VVector3@G3D@@@?$Bridge@VVector3@G3D@@$00@Lua@RBX@@SA_NPAUlua_State@@IAAVVector3@G3D@@@Z'),
        (0x0061d230, '?pushRed@@YAHPAUlua_State@@@Z'),
        (0x0061d270, '?pushWhite@@YAHPAUlua_State@@@Z'),
        (0x0061d2b0, '?pushGray@@YAHPAUlua_State@@@Z'),
        (0x0061d2f0, '?pushDarkGray@@YAHPAUlua_State@@@Z'),
        (0x0061d330, '?pushBlack@@YAHPAUlua_State@@@Z'),
        (0x0061d370, '?pushYellow@@YAHPAUlua_State@@@Z'),
        (0x0061d3b0, '?pushGreen@@YAHPAUlua_State@@@Z'),
        (0x0061d3f0, '?pushBlue@@YAHPAUlua_State@@@Z'),
        (0x0061d5f0, '?randomBrickColor@BrickColorBridge@Lua@RBX@@CAHPAUlua_State@@@Z'),
        (0x0061d640, '?on_index@?$Bridge@VBrickColor@RBX@@$00@Lua@RBX@@KAHABVBrickColor@3@PBDPAUlua_State@@@Z'),
        (0x0061dbf0, '?on_add' + CFB),
        (0x0061dc70, '?on_sub' + CFB),
        (0x0061dcf0, '?on_inverse' + CFB),
        (0x0061dd60, '?on_toWorldSpace' + CFB),
        (0x0061de60, '?on_toObjectSpace' + CFB),
        (0x0061e2b0, '?on_components' + CFB),
        (0x0061e340, '?on_toEulerAnglesXYZ' + CFB),
        (0x0061ec30, '??$getValue@V' + CF + '@?$Bridge@V' + CF + '$00@Lua@RBX@@SA_NPAUlua_State@@IAAV' + CF + '@Z'),
        (0x0061ecc0, '?on_mul' + CFB),
    ],
    'signal': [
        (0x0061f180, '??$pushNewObject@Vconnection@signals@boost@@@?$Bridge@Vconnection@signals@boost@@$00@Lua@RBX@@'
                     'SAPAVconnection@signals@boost@@PAUlua_State@@V345@@Z'),
        (0x0061f2c0, '??1FunctionScriptSlot@@QAE@XZ'),
        (0x0061f350, '??1WaitScriptSlot@@QAE@XZ'),
        (0x0061f3d0, '?disconnect@SignalConnectionBridge@Lua@RBX@@CAHPAUlua_State@@@Z'),
        (0x0061f3f0, '??$checked_delete@Vconnection@signals@boost@@@boost@@YAXPAVconnection@signals@0@@Z'),
        (0x0061f410, '??0WaitScriptSlot@@QAE@ABV0@@Z'),
        (0x0061f480, '?on_index@?$Bridge@Vconnection@signals@boost@@$00@Lua@RBX@@KAHABVconnection@signals@boost@@'
                     'PBDPAUlua_State@@@Z'),
        # listed extent 110 bytes; the emitted body runs on through its 21-byte catch funclet 0061f60e (referenced only
        # from the EH tables), so the whole 131 bytes are compared with the image (BOUNDS evidence, bounds.json untouched).
        ((0x0061f5a0, 0, 131, 'raw'), '??$?0Vconnection@signals@boost@@@shared_count@detail@boost@@QAE@PAVconnection@signals@2@@Z'),
        (0x0061f630, '?dispose@?$sp_counted_impl_p@Vconnection@signals@boost@@@detail@boost@@UAEXXZ'),
        (0x0061f650, '??0?$' + TGSW + 'VWaitScriptSlot@@@Reflection@RBX@@AAE@ABVWaitScriptSlot@@@Z'),
        (0x0061f6a0, '??$any_cast@I@boost@@YAIABVany@0@@Z'),
        (0x0061f730, '??$any_cast@V?$shared_ptr@VInstance@RBX@@@boost@@@boost@@YA?AV?$shared_ptr@VInstance@RBX@@@0@ABVany@0@@Z'),
        (0x0061f900, '??_G?$' + TGSW + 'VWaitScriptSlot@@@Reflection@RBX@@UAEPAXI@Z'),
        (0x0061f9f0, '??$create@VWaitScriptSlot@@@GenericSlotWrapper@Reflection@RBX@@SAPAV012@VWaitScriptSlot@@@Z'),
        (0x0061fac0, '??_G?$' + TGSW + 'VFunctionScriptSlot@@@Reflection@RBX@@UAEPAXI@Z'),
        (0x00620190, '??0WaitScriptSlot@@QAE@PAUlua_State@@@Z'),
        (0x00620210, '??$connectGeneric@VWaitScriptSlot@@@SignalInstance@Reflection@RBX@@QAE?AVconnection@signals@boost@@'
                     'VWaitScriptSlot@@W4connect_position@45@@Z'),
        (0x00620470, '?wait@SignalBridge@Lua@RBX@@SAHPAUlua_State@@@Z'),
    ],
}
PENDING_ROWS = {}
HELPERS = {}

# Bridge<T>::className statics: constant-initialized pointers; the string each one names is read from the image.
CLASSNAMES = {
    'V?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@$0A@': (0x0095af74, 'Object'),
    'VColor3@G3D@@$00': (0x0095b1bc, 'Color3'), 'VVector3@G3D@@$00': (0x0095b1c0, 'Vector3'),
    'VBrickColor@RBX@@$00': (0x0095b1c4, 'BrickColor'), 'VCoordinateFrame@G3D@@$00': (0x0095b1c8, 'CFrame'),
    'V?$shared_ptr@VSignalInstance@Reflection@RBX@@@boost@@$0A@': (0x0095b1e4, 'RBXScriptSignal'),
    'Vconnection@signals@boost@@$00': (0x0095b1e8, 'RBXScriptConnection'),
}
EXTERNAL = {
    # G3D::format (record_native_network_player.py / record_native_lua_args.py bind it to 00509b10).
    '?format@G3D@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBDZZ': 0x00509b10,
    # boost 1.34.1 signals connection (libs/signals/src/connection.cpp): ~connection 00595370 and disconnect 00595230
    # are the bindings record_native_feature.py proves; the copy constructor 005950f0 and operator= 005953f0 are the
    # server-verified library matches of the same connection.cpp (roc-lib boost-1.34.1 libs/signals/src/connection.cpp).
    '??1connection@signals@boost@@QAE@XZ': 0x00595370,
    '?disconnect@connection@signals@boost@@QBEXXZ': 0x00595230,
    '??0connection@signals@boost@@QAE@ABV012@@Z': 0x005950f0,
    '??4connection@signals@boost@@QAEAAV012@ABV012@@Z': 0x005953f0,
    # G3D 6.09: Matrix3 copy constructor 00513220 (record_native_appearance.py; ICF-folded with Matrix3::operator=),
    # Matrix3::toEulerAnglesXYZ 00513720 (server-verified library match g3d-6.09 G3Dcpp/Matrix3.cpp) and
    # Vector4::xyz 00514890 (G3Dcpp/Vector4.cpp:169 `return Vector3(x, y, z)`, byte-identical to Vector3::xyz, the
    # server-verified library match at that address: the two are ICF-folded).
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x00513220,
    '?toEulerAnglesXYZ@Matrix3@G3D@@QBE_NAAM00@Z': 0x00513720,
    '?xyz@Vector4@G3D@@QBE?AVVector3@2@XZ': 0x00514890,
    # Reflection::GenericSlotWrapper::~GenericSlotWrapper (native reflection/signal.h, out-of-line virtual, empty): the
    # ??_G rows call the one-byte `ret` 0047d410 that every empty function folds to (record_native_adorn.py); its
    # byte is checked below.
    '??1GenericSlotWrapper@Reflection@RBX@@UAE@XZ': 0x0047d410,
}
assert original.data(0x0047d410, 1) == b'\xc3'
DATA = {}
for key, (address, text) in CLASSNAMES.items():
    assert original.string(d(address)) == text, (key, hex(address), original.string(d(address)))


def classname(symbol, value):
    """Bridge<T>::className: the address must be the listed static and its constant pointer must name the string."""
    if not symbol.startswith('?className@?$Bridge@'):
        return None
    for key, (address, text) in CLASSNAMES.items():
        if symbol.startswith('?className@?$Bridge@' + key + '@Lua@RBX@@'):
            assert value == address and original.string(d(value)) == text, (symbol, hex(value))
            return 'className static -> %r' % text
    raise AssertionError(('unlisted className', symbol, hex(value)))


def first(address):
    return address[0] if isinstance(address, tuple) else address


GUIDS = {}
all_rows = [x for v in ROWS.values() for x in v] + [x for v in PENDING_ROWS.values() for x in v] + \
    [x for v in HELPERS.values() for x in v]
own = {}
for addr, sym in all_rows:
    assert sym not in own, ('one address per symbol', sym)
    own[sym] = first(addr)
pending_addrs = set()
binding = {}


def classify(symbol, value, raw, sections, definitions, where):
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol.startswith('??_C@_1'):   # wide literal: up to the first aligned L'\0'
        pos, at = definitions[symbol]
        data = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]]
        end = next(i for i in range(0, len(data), 2) if data[i:i + 2] == b'\0\0') + 2
        literal = data[:end]
        assert original.data(value, len(literal)) == literal, (where, symbol, hex(value))
        return 'wide literal %r' % literal[:-2].decode('utf-16le')
    if symbol.startswith('??_C@'):
        pos, at = definitions[symbol]
        literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
        assert original.data(value, len(literal)) == literal, (where, symbol, hex(value))
        return 'literal %r' % literal[:-1].decode()
    if symbol.startswith('__TI') and '?AV' in symbol:
        # _ThrowInfo: pCatchableTypeArray +12 -> first CatchableType -> TypeDescriptor name
        cta = d(value + 12)
        assert d(cta) == int(symbol[4]), (where, symbol, hex(value))
        name = original.string(d(d(cta + 4) + 4) + 8)
        assert name == '.' + symbol[5:], (where, symbol, hex(value), name)
        return 'throw info %s (%d catchable types)' % (name, d(cta))
    if symbol.startswith('??_R0') and symbol.endswith('@8'):
        rtti = original.string(value + 8)
        assert rtti == '.' + symbol[5:-2], (where, symbol, hex(value), rtti)
        return 'RTTI %s' % rtti
    if symbol.startswith('??_7'):
        rtti, at = original.vtable_class(value)
        assert rtti == '.?AV' + symbol[4:symbol.index('@@6B') + 2], (where, symbol, hex(value), rtti)
        return 'vtable RTTI %s offset %#x' % (rtti, at)
    if symbol in own:
        assert own[symbol] == value, (where, symbol, hex(value), hex(own[symbol]))
        return 'pending-build-only row' if value in pending_addrs else 'own row'
    if symbol.startswith('??_E') and ('??_G' + symbol[4:]) in own:
        assert own['??_G' + symbol[4:]] == value, (where, symbol, hex(value))
        return 'own row (??_G)'
    how = classname(symbol, value)
    if how:
        return how
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
        return 'external'
    if symbol in GUIDS:
        import uuid
        assert str(uuid.UUID(bytes_le=original.data(value, 16))) == GUIDS[symbol], (where, symbol, hex(value))
        return 'GUID {%s}' % GUIDS[symbol]
    if symbol in DATA:
        assert DATA[symbol] == value, (where, symbol, hex(value), hex(DATA[symbol]))
        return 'data'
    if EVIDENCE.get('%08x' % value, {}).get('symbol') == symbol:
        # an evidence name proves the target only when no other address carries the same symbol: e.g.
        # ?lua_tonumber@@YAN... names both the lapi.c function 00611f60 (score 100) and 0061c830 (score 30), a Roblox
        # clamping wrapper that itself calls 00611f60, so a call bound to either by name alone is not proven.
        assert EVIDENCE_ADDRS[symbol] == ['%08x' % value], ('ambiguous evidence name', where, symbol, hex(value),
                                                              EVIDENCE_ADDRS[symbol])
        return 'evidence name'
    return instance(symbol, value, where)


EVIDENCE = json.loads((ROOT / 'rebuild/2008-06/offline/evidence.json').read_text())['names']
EVIDENCE_ADDRS = {}
for _a, _v in sorted(EVIDENCE.items()):
    EVIDENCE_ADDRS.setdefault(_v.get('symbol'), []).append(_a)
LENIENT = []          # inside a library body: unprovable library-internal targets are listed, not asserted
CURRENT = []          # object whose relocations are being bound (instances are looked up there first)
INSTANCES = {}        # symbol -> verified instance record
BODIES = {}


def bodies_of(obj):
    if obj not in BODIES:
        BODIES[obj] = {n: (b, r) for n, b, r in match.coff_functions(Path(obj).read_bytes())}
    return BODIES[obj]


def instance(symbol, value, where):
    """An inline / library body this build emits, proven by bytes at the called address and by its own targets."""
    if symbol in INSTANCES:
        assert INSTANCES[symbol]['address'] == '%08x' % value, (where, symbol, hex(value))
        return 'library instance (bytes equal)' if 'library' in INSTANCES[symbol].get('status', '') else \
            'instance (bytes equal, targets verified)'
    for obj in CURRENT[-1:] + LIBS:
        if symbol in bodies_of(obj):
            break
    else:
        return data_instance(symbol, value, where)
    library = obj in LIBS
    body = bodies_of(obj)[symbol][0]
    try:
        target, _, _ = match.target('2008-06', '%08x' % value)
        unlisted = False
    except SystemExit:   # not a listed function start (inside a merged extent): image bytes compared
        target, unlisted = b'', True
    merged = len(body) != len(target)
    # The function list cuts bodies at catch funclets / SEH filters and runs some library functions into their
    # neighbours; then the whole emitted body is compared with the image bytes at the called address.
    spec = (value, 0, len(body), 'raw') if merged else value
    INSTANCES[symbol] = {'address': '%08x' % value, 'pending': True}
    LENIENT.append(library)
    try:
        row = verify(obj, [(spec, symbol)], False)[0]
    except AssertionError:
        if not library:
            del INSTANCES[symbol]
            raise
        del INSTANCES[symbol]   # a donor-library body that differs proves nothing: leave the symbol unbound here
        return None
    finally:
        LENIENT.pop()
    row['status'] = 'instance (%s), bytes equal, not counted' % (
        ('library ' + Path(obj).stem +
         '; its own targets bound where provable, library-internal ones listed as not followed')
        if library else 'emitted by this unit; every own target verified')
    if unlisted:
        row['status'] += '; not a listed function start, whole body compared with the image bytes'
    elif merged:
        row['status'] += '; listed extent %#x != body %#x, whole body compared with the image bytes' % (
            len(target), len(body))
    INSTANCES[symbol] = row
    return 'library instance (bytes equal)' if library else 'instance (bytes equal, targets verified)'


def data_instance(symbol, value, where):
    """Initialized data this unit defines (an ATL function-local static such as the window class info): bytes equal
    at the referenced address with relocated fields masked, and every relocated field bound like a code target."""
    if not CURRENT:
        return None
    obj = CURRENT[-1]
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, starts = match._coff_data_index(raw)
    if symbol not in definitions:
        return None
    pos, sec = definitions[symbol]
    table = sections[sec]
    if table[9] & 0x20 or not table[9] & 0x40 or not table[4]:
        return None
    end = min([x for x in starts[sec + 1] if x > pos] + [table[3]])
    data = raw[table[4] + pos:table[4] + end]
    mine = original.data(value, len(data))
    fields = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if pos <= offset < end:
            assert kind == 6, (symbol, kind)
            fields[offset - pos] = symbols[index][0]
    mask = set(x + k for x in fields for k in range(4))
    assert all(a == b for i, (a, b) in enumerate(zip(data, mine)) if i not in mask), ('data bytes', symbol, hex(value))
    INSTANCES[symbol] = {'address': '%08x' % value, 'pending': True}
    verified = {}
    for off, target_symbol in sorted(fields.items()):
        target = (struct.unpack_from('<I', mine, off)[0] - struct.unpack_from('<i', data, off)[0]) & 0xffffffff
        how = classify(target_symbol, target, raw, sections, definitions, symbol)
        assert how is not None, ('unbound data field', symbol, off, target_symbol, hex(target))
        prev = binding.setdefault(target_symbol, target)
        assert prev == target, ('inconsistent binding', target_symbol, hex(prev), hex(target))
        verified['+%#x %s' % (off, target_symbol)] = '%s (%s)' % (hex(target), how)
    INSTANCES[symbol] = {'address': '%08x' % value, 'symbol': symbol, 'size': len(data), 'exact': False,
                         'status': 'data instance emitted by this unit (bytes equal, fields verified), not counted',
                         'verified_targets': verified}
    return 'data instance (bytes equal, fields verified)'


def verify(obj, rows, exact_flag):
    CURRENT.append(obj)
    try:
        return verify_rows(obj, rows, exact_flag)
    finally:
        CURRENT.pop()


def verify_rows(obj, rows, exact_flag):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = bodies_of(obj)
    out = []
    for spec, name in rows:
        body, refs = bodies[name]
        address, lo, hi = spec[:3] if isinstance(spec, tuple) else (spec, 0, len(body))
        body, refs = body[lo:hi], [r - lo for r in refs if lo <= r < hi]
        if isinstance(spec, tuple) and spec[3:] == ('raw',):
            # Not a listed function: compare with the image bytes; every masked field is bound below.
            target, target_refs = original.data(address, len(body)), []
        else:
            target, target_refs, _ = match.target('2008-06', '%08x' % address)
        assert match.exact_match(target, target_refs, body, refs), (name, hex(address), len(body), len(target))
        start, section = definitions[name]
        start += lo
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
            if LOCAL_EH.match(symbol) or symbol.startswith('__sehtable$'):
                local.add(symbol)
                continue
            how = classify(symbol, value, raw, sections, definitions, name)
            if how is None and LENIENT and LENIENT[-1]:
                verified[symbol] = '%s (library-internal, not followed)' % hex(value)
                continue
            assert how is not None, ('unbound relocation', name, symbol, hex(value))
            prev = binding.setdefault(symbol, value)
            assert prev == value, ('inconsistent binding', symbol, hex(prev), hex(value))
            verified[symbol] = '%s (%s)' % (hex(value), how)
        row = {'address': '%08x' % address, 'symbol': name + ('' if (lo, hi) == (0, len(bodies[name][0])) else ' [%#x:%#x]' % (lo, hi)),
               'size': len(body), 'exact': exact_flag,
               'verified_targets': verified, 'local_eh': sorted(local)}
        if not exact_flag:
            row['status'] = 'pending-build-only'
        out.append(row)
    return out


results = {k: verify(OBJ[k], v, True) for k, v in ROWS.items()}


# ---- vtables of the current-header objects ------------------------------------------------------------------
def vtable_slots(obj, symbol):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, starts = match._coff_data_index(raw)
    value, sec = definitions[symbol]
    table = sections[sec]
    end = min([x for x in starts[sec + 1] if x > value] + [table[3]])
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if value <= offset < end:
            slots[(offset - value) // 4] = symbols[index][0]
    return raw, sections, definitions, slots


VTABLES = {
    '??_7?$sp_counted_impl_p@Vconnection@signals@boost@@@detail@boost@@6B@':
        (OBJ['signal'], 0x0084463c, '.?AV?$sp_counted_impl_p@Vconnection@signals@boost@@@detail@boost@@'),
    '??_7?$TGenericSlotWrapper@VWaitScriptSlot@@@Reflection@RBX@@6B@':
        (OBJ['signal'], 0x00844688, '.?AV?$TGenericSlotWrapper@VWaitScriptSlot@@@Reflection@RBX@@'),
    '??_7?$TGenericSlotWrapper@VFunctionScriptSlot@@@Reflection@RBX@@6B@':
        (OBJ['signal'], 0x00844694, '.?AV?$TGenericSlotWrapper@VFunctionScriptSlot@@@Reflection@RBX@@'),
}
vtables = {}
for symbol, (vobj, vt, rtti_name) in VTABLES.items():
    assert original.vtable_class(vt) == (rtti_name, 0), (hex(vt), original.vtable_class(vt))
    raw, sections, definitions, slots = vtable_slots(vobj, symbol)
    count = len(slots)
    assert sorted(slots) == list(range(count)), (symbol, sorted(slots))
    checked = {}
    CURRENT.append(vobj)
    for slot, sym in sorted(slots.items()):
        value = d(vt + 4 * slot)
        try:
            how = classify(sym, value, raw, sections, definitions, symbol)
        except AssertionError:
            how = None
        if how is None and sym.startswith('??_E') and ('??_G' + sym[4:]) in bodies_of(vobj):
            how = instance('??_G' + sym[4:], value, symbol)
            how = how and how + ' via ??_G'
        if how is None:   # a slot whose body is not exact yet: listed, not proven (the vtable itself is by RTTI)
            checked[slot] = '%s = %s (NOT VERIFIED: body not exact in this build)' % (sym, hex(value))
            continue
        prev = binding.setdefault(sym, value)
        assert prev == value, ('inconsistent', sym, hex(prev), hex(value))
        checked[slot] = '%s = %s (%s)' % (sym, hex(value), how)
    CURRENT.pop()
    vtables[symbol] = {'address': hex(vt), 'rtti': rtti_name, 'slots': checked}

# ---- layout: userdata sizes pushed to lua_newuserdata (00612c40) by exact rows ---------------------------------
NEWUSERDATA = 0x00612c40
# Target bytes only (a layout fact, not a match claim): the exact rows plus newColor3 0061caf0 / newVector3 0061ce80 /
# newBrickColor 0061d430, which are not counted (they call the 0061c830 lua_tonumber wrapper, see NOT_EXACT).
BYTE_ONLY = [0x0061caf0, 0x0061ce80, 0x0061d430]
USERDATA = {0x0061caf0: [0xc], 0x0061ce80: [0xc], 0x0061d230: [4], 0x0061d270: [4], 0x0061d2b0: [4], 0x0061d2f0: [4],
            0x0061d330: [4], 0x0061d370: [4], 0x0061d3b0: [4], 0x0061d3f0: [4], 0x0061d430: [4, 4], 0x0061d5f0: [4],
            0x0061f180: [0x10]}
userdata = {}
for address in [first(a) for k in ROWS for a, _ in ROWS[k]] + BYTE_ONLY:
    body = match.target('2008-06', '%08x' % address)[0]
    sizes = []
    for i in range(len(body) - 4):
        if body[i] == 0xe8 and (address + i + 5 + struct.unpack_from('<i', body, i + 1)[0]) & 0xffffffff == NEWUSERDATA:
            j = body.rfind(b'\x6a', max(0, i - 16), i)   # push imm8 (size), then push L
            sizes.append(body[j + 1])
    if sizes:
        userdata['%08x' % address] = sizes
assert userdata == {'%08x' % a: v for a, v in USERDATA.items()}, userdata
assert binding.get('?lua_newuserdata@@YAPAXPAUlua_State@@I@Z') == NEWUSERDATA

# ---- coverage of the bridge range -----------------------------------------------------------------------------
LO, HI = 0x0061a420, 0x006217f0
listed = [json.loads(line)['addr'] for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines()]
in_range = sorted(a for a in listed if LO <= int(a, 16) < HI)
exact = sorted({r['address'] for k in ROWS for r in results[k]})
instances_in_range = sorted({v['address'] for v in INSTANCES.values() if LO <= int(v['address'], 16) < HI} - set(exact))
NOT_EXACT = {
    '0061e690': 'Bridge<CoordinateFrame>::on_index: bytes exact, but it pushes the not-yet-exact cfunctions '
                'on_pointToWorldSpace 0061df50 / on_pointToObjectSpace 0061e050 / on_vectorToWorldSpace 0061e150 / '
                'on_vectorToObjectSpace 0061e3b0, so not every target is verified (not counted)',
    '0061caf0 / 0061ce80 / 0061d430': 'newColor3 / newVector3 / newBrickColor: bytes exact, but each calls 0061c830 (a '
                'Roblox clamping wrapper around lua_tonumber 00611f60, evidence-named ?lua_tonumber at score 30) where this '
                'unit calls lua_tonumber itself, so the call target is not verified (not counted)',
    '00620760': 'SignalBridge::on_index: bytes exact, but it pushes SignalBridge::connect 00620620, not exact yet '
                '(not counted)',
    '0061fa60': 'TGenericSlotWrapper<FunctionScriptSlot> constructor: bytes exact, but it calls the FunctionScriptSlot '
                'copy constructor 0061f960, which is not exact: the 2008 FunctionScriptSlot has one more dword at +0x50 '
                '(0061f960 copies [src+0x50]) than the donor declaration (not counted)',
    '0061f960': 'FunctionScriptSlot copy constructor: 124/130 bytes; the 2008 layout has a dword at +0x50 the donor '
                'declaration lacks (FunctionScriptSlot is declared in the read-only donor script/LuaSignalBridge.h)',
    '00620910': 'std::_Allocate<map<const Name*, const ICreator*> node>: counted by scorehud-leaderboard-working.json',
    '0061f60e': 'catch funclet of shared_count<connection> 0061f5a0, compared as part of that row (not counted separately)',
    '00620357 / 00620422 / 00620a3e': 'catch funclets (EH-table pieces of execute / shared_count bodies not exact yet)',
}
receipt = {
    'family': 'LuaBridge2008 (RBX::Lua instance / atomic / signal bridges, 2008-06)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': flags(), 'profile': 'document-swap flags',
    'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in
                [Path(__file__).resolve(), ROOT / 'rebuild/2008-06/tests/native_bind.py', BRIDGE_H, SIGNAL_H] +
                list(UNITS.values())},
    'objects': {k: sha(v) for k, v in OBJ.items()},
    'boundary': {
        'range': '0061a420..006217e2 (functions listed 0061a420 <= addr < 006217f0: %d)' % len(in_range),
        'before': '0061a090..0061a3f0 boost thread tss_hooks unit (0061a3f0 TLS callback: DLL_PROCESS_DETACH -> '
                  'on_process_exit 0061a110; 0061a260 creates the tss cleanup list); 0061a400 (31 bytes) is called only '
                  'from 0061b190 (enum conversion) and is left unattributed',
        'first': '0061a420 RBX::Lua::newweaktable (exact row; pushes the literal "__mode")',
        'after': '006217f0 luaD_seterrorobj, 00621920 luaD_rawrunprotected, 00621a70 luaD_reallocstack ... (Lua 5.1.1 '
                 'ldo.c compiled as C++, calls only Lua internals)',
        'last': '006217d0 (pushes 0.0 and calls 006214e0; ThreadRef/YieldingThreads part, not exact yet)',
        'units': 'instance bridge 0061a420..0061c6ef (data: bad_alloc message 0095af70, className "Object" 0095af74); '
                 'atomic classes 0061c6f0..0061ecaf (data 0095b1b8: Color3/Vector3/BrickColor/CFrame classNames '
                 '0095b1bc..0095b1c8); enum bridges 0061edb0..0061f0f0 (data 0095b1d0: Enums/Enum/EnumItem '
                 '0095b1d4..0095b1dc); signal bridge 0061f180..00620a3e (data 0095b1e0: RBXScriptSignal 0095b1e4, '
                 'RBXScriptConnection 0095b1e8); thread refs / YieldingThreads 00620a60..006217d0 '
                 '(YieldingThreads ctor 00621330)',
        'rtti_vtables': {'0084463c': 'sp_counted_impl_p<boost::signals::connection>',
                         '00844688': 'TGenericSlotWrapper<WaitScriptSlot>',
                         '00844694': 'TGenericSlotWrapper<FunctionScriptSlot>'},
        'classNames': {'%08x' % a: t for a, t in CLASSNAMES.values()},
    },
    'layout': {
        'userdata_sizes_pushed_to_lua_newuserdata': userdata,
        'note': 'Color3 / Vector3 0xc (target bytes of 0061caf0 / 0061ce80, not counted rows), BrickColor 4, boost::signals::connection 0x10 (pushNewObject<connection> '
                '0061f180), metatables named by the Bridge<T>::className statics above. The bridges are static-only '
                'classes (no fields). FunctionScriptSlot 2008 layout has a dword at +0x50 beyond the donor declaration.',
    },
    'methods': results, 'instances': INSTANCES, 'exact': exact, 'exact_count': len(exact),
    'instances_in_range_not_counted': instances_in_range,
    'pending_build_only': [],
    'not_exact': NOT_EXACT,
    'left': sorted(set(in_range) - set(exact) - set(instances_in_range) - {'0061f60e'}),
    'bounds_evidence': ['0061f5a0 shared_count<boost::signals::connection> ctor: 131 bytes (listed 110) including its catch '
                        'funclet 0061f60e, which only the EH tables reference; whole body byte-exact against the image'],
    'vtables': vtables,
    'proposals': [
        'native-headers/v8tree/Instance.h (owner): `typedef std::vector<boost::shared_ptr<Instance> > Instances;` in '
        'namespace RBX and `void setParent2(boost::shared_ptr<Instance>)` (shape from the donor). Needed by the '
        'Instances branch of the property push 0061abe0 / LuaArguments::push and by ObjectBridge::on_newindex; '
        'guarded with NATIVE_LUABRIDGE_PENDING in native-classes/LuaBridge2008Instance.cpp; no row depends on it yet.',
    ],
    'scope': 'Inactive. Exact rows with every call/data target verified; no pending build, no active build, swap or '
             'credit. Lua library functions are external targets bound by address (offline evidence names).',
}
(ROOT / 'work/2008-06/shared-layouts/lua-bridge2008-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native lua bridge2008: %d exact (%s), %d vtables checked, %d instances (%d in range, not counted), '
      '%d of %d range functions left' % (len(exact), ' '.join(exact), len(vtables), len(INSTANCES),
                                         len(instances_in_range), len(receipt['left']), len(in_range)))
