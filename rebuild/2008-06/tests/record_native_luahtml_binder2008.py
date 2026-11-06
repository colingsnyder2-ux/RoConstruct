"""Verify the inactive native 2008-06 CLuaHtmlView::Binder and CLuaHtmlView::Binder::PropBinding.

Builds (document-swap flags, VS2008 RTM 21022), with three profile header directories put first:
  native-headers/mfc-noinline-pcxstr (onChange 0042c000 calls the mfc90 CString PCXSTR operator through the IAT),
  native-headers/std-noinline-string (updateElement 0042be20 calls basic_string::c_str through msvcp90),
  native-headers/boost-function-pod-vtable (the boost::function static vtables are constant-initialized: the
  function0<bool> constructor 0042b6d0 stores 00810610 with no guard, and the destructor's operator= uses 00810658).
  * tests/NativeLuaHtmlBinder2008Layout.cpp       sizeof/offsetof checks;
  * native-classes/LuaHtmlBinder2008.cpp          native-headers/LuaHtmlBinder2008/LuaHtmlBinder2008.h;
  * the same unit again with NATIVE_LUAHTMLBINDER2008_PENDING against generated header copies in
    out/native-layouts/luahtml-binder2008-pending/ (no shared header is edited):
      v8tree/Instance.h with `static Reflection::SignalDesc<Instance, void(const Reflection::PropertyDescriptor*)>
      event_propertyChanged;` (00973f48, the descriptor the PropBinding constructor 0042c630 connects through;
      record_native_instance_property_worker.py binds the same name to 00973f48 from raisePropertyChanged 0040db00).
    Rows exact only there are recorded exact=false (pending-build-only) and are not counted; so is bind 0042c760,
    whose PropBinding constructor call target is pending-only. (EventHandler::handler is public in
    AppLeaves2008/EventHandler2008.h since 2026-11-06, so ~Binder 0042c3c0 and its ??_G 0042c4e0 build and count here.)
Inline/library instances a row calls (ATL, boost, STL, SecurityContext) are bound by bytes: the instance this build
emits must equal the function at the called address, with every one of its own targets verified the same way
(recursively); they are listed under 'instances' and not counted.
Every relocation of an exact row is bound to the address the original instruction uses and verified: imports by
DLL name / ordinal, literals by bytes, GUIDs by their 16 bytes, RTTI and vtables by original RTTI names, own symbols
by the row proven here, everything else by the explicit EXTERNAL / DATA maps below (one address per symbol).
Vtable slots are compared from the object built from the current headers (never the pending one).
Writes work/2008-06/shared-layouts/luahtml-binder2008-working.json.
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
LAYOUT = Path(__file__).resolve().parent / 'NativeLuaHtmlBinder2008Layout.cpp'
BINDER_H = HDR / 'LuaHtmlBinder2008/LuaHtmlBinder2008.h'
BINDER_CPP = SRC / 'LuaHtmlBinder2008.cpp'
INSTANCE_H = HDR / 'v8tree/Instance.h'
EH_H = HDR / 'AppLeaves2008/EventHandler2008.h'
PROFILE = ['/I' + str(HDR / d) for d in ('mfc-noinline-pcxstr', 'std-noinline-string', 'boost-function-pod-vtable')]
PENDING = OUT / 'luahtml-binder2008-pending'
original = Original()


def d(address):
    return struct.unpack('<I', original.data(address, 4))[0]


def build(source, name, pre=(), extra=()):
    OUT.mkdir(parents=True, exist_ok=True)
    obj = OUT / (name + '.obj')
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', list(pre) + PROFILE + flags() + list(extra) +
                            ['/Fo' + str(obj), str(source)], OUT)
    assert code == 0, log
    return obj


# ---- generated pending header copies ------------------------------------------------------------------------
(PENDING / 'v8tree').mkdir(parents=True, exist_ok=True)
# The EventHandler proposal is applied in the native header: drop the copy older runs generated here (it would shadow it).
if (PENDING / 'AppLeaves2008/EventHandler2008.h').exists():
    (PENDING / 'AppLeaves2008/EventHandler2008.h').unlink()
inst = INSTANCE_H.read_text()
ANCHOR = ('    static Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>, const Reflection::PropertyDescriptor*)>'
          ' event_itemChanged;\n')
PROPOSED = '    static Reflection::SignalDesc<Instance, void(const Reflection::PropertyDescriptor*)> event_propertyChanged;\n'
assert inst.count(ANCHOR) == 1 and 'event_propertyChanged' not in inst
(PENDING / 'v8tree/Instance.h').write_text(inst.replace(ANCHOR, ANCHOR + PROPOSED))
eh = EH_H.read_text()
assert eh.count('\n    boost::function0<bool> handler;') == 1 and \
    eh.index('\npublic:') < eh.index('boost::function0<bool> handler;') < eh.index('\nprotected:')

layout_obj = build(LAYOUT, 'NativeLuaHtmlBinder2008Layout')
binder_obj = build(BINDER_CPP, 'NativeLuaHtmlBinder2008')
binder_pobj = build(BINDER_CPP, 'NativeLuaHtmlBinder2008Pending', pre=['/I' + str(PENDING)],
                    extra=['/DNATIVE_LUAHTMLBINDER2008_PENDING'])
LIBS = []
ATLS = ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/lib/atls.lib'


class ArchiveIndex(dict):
    """symbol -> member object path; a member is written under out/ only when one of its symbols is needed."""
    def __init__(self, path):
        dict.__init__(self)
        data, i, k = Path(path).read_bytes(), 8, 0
        assert data[:8] == b'!<arch>\n'
        self.members = {}
        while i < len(data):
            size = int(data[i + 48:i + 58])
            member = data[i + 60:i + 60 + size]
            if member[:2] == b'\x4c\x01':
                names = [n for n, _, _ in match.coff_functions(member)]
                if names:
                    obj = OUT / ('atls-member-%d.obj' % k)
                    self.members[obj] = member
                    k += 1
                    for n in names:
                        self.setdefault(n, obj)
            i += 60 + size + (size & 1)

    def get(self, symbol, default=None):
        obj = dict.get(self, symbol, default)
        if obj is not None and obj in self.members and not obj.exists():
            obj.write_bytes(self.members[obj])
        return obj

    def __getitem__(self, symbol):
        return self.get(symbol)


def archive_index(path):
    return ArchiveIndex(path)


ATLS_INDEX = archive_index(ATLS)

# ---- rows ---------------------------------------------------------------------------------------------------
PB = '@PropBinding@Binder@CLuaHtmlView@@'
STR = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
ROWS = {   # object -> [(address, symbol)]
    'binder': [(0x0042bd70, '?getValue' + PB + 'QBE?A' + STR + 'XZ'),
               (0x0042bcd0, '?setValue' + PB + 'QAEXPB' + STR + '@Z'),
               # the implicit PropBinding destructor (~scoped_connection, then the shared_ptr release); only
               # checked_delete<PropBinding> 0042b0e0 and sp_counted_impl_p<PropBinding>::dispose 0042b310 call it.
               (0x0042a720, '??1PropBinding@Binder@CLuaHtmlView@@QAE@XZ'),
               (0x0042c000, '?onChange@Binder@CLuaHtmlView@@AAE_NXZ'),
               (0x0042be20, '?updateElement@Binder@CLuaHtmlView@@AAEXXZ'),
               (0x0042c0d0, '??0Binder@CLuaHtmlView@@QAE@PAUIHTMLInputElement@@@Z'),
               (0x0042c500, '?requestUpdate@Binder@CLuaHtmlView@@AAEXXZ'),
               (0x0042c570, '?onPropertyChanged@Binder@CLuaHtmlView@@CAXPBVPropertyDescriptor@Reflection@RBX@@'
                            'ABV345@PAV12@@Z'),
               (0x0042c3c0, '??1Binder@CLuaHtmlView@@UAE@XZ'),
               (0x0042c4e0, '??_GBinder@CLuaHtmlView@@UAEPAXI@Z')],
}
PENDING_ROWS = {
    'pending': [(0x0042c630, '??0PropBinding@Binder@CLuaHtmlView@@QAE@V?$shared_ptr@VInstance@RBX@@@boost@@'
                             'ABVPropertyDescriptor@Reflection@RBX@@PAV12@@Z')],
    # Byte-exact in the current build too, but it calls a pending-only row (the PropBinding constructor).
    'pending_gated': [(0x0042c760, '?bind@Binder@CLuaHtmlView@@QAEXV?$shared_ptr@VInstance@RBX@@@boost@@'
                                   'ABVPropertyDescriptor@Reflection@RBX@@@Z')],
}
HELPERS = {}
OBJ = {'layout': layout_obj, 'binder': binder_obj, 'pending': binder_pobj, 'pending_gated': binder_obj}

# Explicit bindings (address the original instruction uses; evidence in the comment).
EXTERNAL = {
    # boost 1.34.1 thread library tss (the bindings record_native_network_player.py proves).
    '?get@tss@detail@boost@@QBEPAXXZ': 0x005a7570,
    '?set@tss@detail@boost@@QAEXPAX@Z': 0x005a76b0,
    '?cleanup@tss@detail@boost@@QAEXPAX@Z': 0x005a6ff0,
    # boost 1.34.1 signals library connection (the bindings record_native_feature.py / record_native_body_movers.py
    # prove: ~connection 00595370, scoped_connection::operator= 00595540, ~scoped_connection 005954b0).
    '??1connection@signals@boost@@QAE@XZ': 0x00595370,
    '??4scoped_connection@signals@boost@@QAEAAV012@ABVconnection@12@@Z': 0x00595540,
    '??1scoped_connection@signals@boost@@QAE@XZ': 0x005954b0,
    # boost signals slot_base::create_connection (record_native_history_start_trial.py binds it from 0057acb0).
    '?create_connection@slot_base@detail@signals@boost@@IAEXXZ': 0x00595840,
    # boost signals signal_base_impl::connect_slot (record_native_history_start_trial.py binds it to 0056a900).
    '?connect_slot@signal_base_impl@detail@signals@boost@@QAE?AVconnection@34@ABVany@4@ABVstored_group@234@'
    'V?$shared_ptr@Udata_t@slot_base@detail@signals@boost@@@4@W4connect_position@34@@Z': 0x0056a900,
    # CRT (record_native_guid_critical_section.py / record_native_adorn.py bindings).
    '??2@YAPAXI@Z': 0x006a0920,
    '??3@YAXPAX@Z': 0x006a067a,
    '__CxxThrowException@8': 0x006a158c,
    # Marshaller::post (native-headers/AppLeaves2008/Marshaller2008.h; exact row of record_native_app_leaves2008.py).
    '?post@Marshaller@@QAEXV?$function0@XV?$allocator@Vfunction_base@boost@@@std@@@boost@@@Z': 0x0041a530,
    # EventHandler::EventHandler (native-headers/AppLeaves2008/EventHandler2008.h; exact row of
    # record_native_app_leaves2008.py; 0042c178 calls it on the new(0x30) block).
    '??0EventHandler@@QAE@V?$function0@_NV?$allocator@Vfunction_base@boost@@@std@@@boost@@@Z': 0x0042acb0,
}
DATA = {
    # htmlMarshaller (native-headers/AppLeaves2008/DHTMLWindowService2008.h): record_native_app_leaves2008_services.py
    # binds it to 0096cc4c (stored by 0041bc40).
    '?htmlMarshaller@@3PAVMarshaller@@A': 0x0096cc4c,
    # Instance::event_propertyChanged (pending header copy only): record_native_instance_property_worker.py binds the
    # same name to 00973f48 from raisePropertyChanged 0040db00.
    '?event_propertyChanged@Instance@RBX@@2V?$SignalDesc@VInstance@RBX@@$$A6AXPBVPropertyDescriptor@Reflection@2@@Z'
    '@Reflection@2@A': 0x00973f48,
}

def first(address):
    return address[0] if isinstance(address, tuple) else address


# GUID constants (uuid.lib data in the original): verified by their 16 bytes.
GUIDS = {'__GUID_3050f434_98b5_11cf_bb82_00aa00bdce0b': '3050f434-98b5-11cf-bb82-00aa00bdce0b',  # IHTMLElement2
         '_IID_IUnknown': '00000000-0000-0000-c000-000000000046', '_IID_IDispatch': '00020400-0000-0000-c000-000000000046',
         '_IID_IGlobalInterfaceTable': '00000146-0000-0000-c000-000000000046',
         '_CLSID_StdGlobalInterfaceTable': '00000323-0000-0000-c000-000000000046'}

all_rows = [x for v in ROWS.values() for x in v] + [x for v in PENDING_ROWS.values() for x in v] + \
    [x for v in HELPERS.values() for x in v]
own = {}
for addr, sym in all_rows:   # a split body binds to the address of its first piece
    own.setdefault(sym, first(addr))
pending_addrs = {addr for v in PENDING_ROWS.values() for addr, _ in v}
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
        return 'evidence name'
    return instance(symbol, value, where)


EVIDENCE = json.loads((ROOT / 'rebuild/2008-06/offline/evidence.json').read_text())['names']
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
    for obj in CURRENT[-1:] + LIBS + ([ATLS_INDEX[symbol]] if symbol in ATLS_INDEX else []):
        if symbol in bodies_of(obj):
            break
    else:
        return data_instance(symbol, value, where)
    library = obj in LIBS or obj == ATLS_INDEX.get(symbol)
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
            raise
        del INSTANCES[symbol]   # a donor-library body that differs proves nothing: leave the symbol unbound here
        return None
    finally:
        LENIENT.pop()
    row['status'] = 'instance (%s), bytes equal, not counted' % (
        ('library ' + ('atls.lib member' if obj == ATLS_INDEX.get(symbol) else Path(obj).stem) +
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
results.update({k: verify(OBJ[k], v, False) for k, v in PENDING_ROWS.items()})
for r in results['pending_gated']:
    assert any('pending-build-only' in v for v in r['verified_targets'].values()), r['address']
    r['status'] = 'pending-build-only (bytes exact in the current build; it calls a pending-only row)'
# A counted row may not depend on a pending-only row.
for k in ROWS:
    for r in results[k]:
        assert not any('pending-build-only' in v for v in r['verified_targets'].values()), (r['address'], r['verified_targets'])


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


VTABLES = {'??_7Binder@CLuaHtmlView@@6B@': (binder_obj, 0x00810654, '.?AVBinder@CLuaHtmlView@@', 1),
           '??_7?$sp_counted_impl_p@VPropBinding@Binder@CLuaHtmlView@@@detail@boost@@6B@':
               (binder_obj, 0x00810524, '.?AV?$sp_counted_impl_p@VPropBinding@Binder@CLuaHtmlView@@@detail@boost@@', 4)}
vtables = {}
for symbol, (vobj, vt, rtti_name, count) in VTABLES.items():
    assert original.vtable_class(vt) == (rtti_name, 0), (hex(vt), original.vtable_class(vt))
    raw, sections, definitions, slots = vtable_slots(vobj, symbol)
    assert sorted(slots) == list(range(count)), (symbol, sorted(slots))
    checked = {}
    CURRENT.append(vobj)
    for slot, sym in sorted(slots.items()):
        value = d(vt + 4 * slot)
        how = classify(sym, value, raw, sections, definitions, symbol)
        if how is None and sym.startswith('??_E') and ('??_G' + sym[4:]) in bodies_of(vobj):
            # the compiler emits the scalar deleting destructor body as ??_G; the vtable names it ??_E
            how = instance('??_G' + sym[4:], value, symbol)
            how = how and how + ' via ??_G'
        assert how is not None, ('unbound vtable slot', symbol, slot, sym, hex(value))
        prev = binding.setdefault(sym, value)
        assert prev == value, ('inconsistent', sym, hex(prev), hex(value))
        checked[slot] = '%s = %s (%s)' % (sym, hex(value), how)
    CURRENT.pop()
    vtables[symbol] = {'address': hex(vt), 'rtti': rtti_name, 'slots': checked}
# The Binder vtable has one slot: the next dword 00810658 is the constant boost::function vtable the destructor
# assigns (manager 0042c2c0, invoker 0042c2b0), checked as a data instance of the pending build.
assert not (0x00401000 <= d(0x00810654 + 4) < 0x0042c2c0) and d(0x00810658) == 0x0042c2c0

exact = sorted({r['address'] for k in ROWS for r in results[k]})
pending = sorted({r['address'] for k in PENDING_ROWS for r in results[k]})
paths = [Path(__file__).resolve(), ROOT / 'rebuild/2008-06/tests/native_bind.py', LAYOUT, BINDER_H, BINDER_CPP,
         INSTANCE_H, EH_H, HDR / 'AppLeaves2008/DHTMLWindowService2008.h', HDR / 'AppLeaves2008/Marshaller2008.h',
         HDR / 'mfc-noinline-pcxstr/atlsimpstr.h', HDR / 'std-noinline-string/xstring',
         HDR / 'boost-function-pod-vtable/boost/function/function_template.hpp',
         HDR / 'boost-function-pod-vtable/boost/function/function_base.hpp']
receipt = {
    'family': 'LuaHtmlBinder2008 (CLuaHtmlView::Binder, CLuaHtmlView::Binder::PropBinding)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': PROFILE + flags(),
    'profile': 'document-swap flags with native-headers/mfc-noinline-pcxstr, std-noinline-string and '
               'boost-function-pod-vtable first',
    'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {k: sha(v) for k, v in OBJ.items()},
    'layout': {
        'CLuaHtmlView::Binder': '0x34 (0042c8c0 news 0x34): vptr 00810654 +0, enable_shared_from_this<Binder> +4 '
                                '(weak_ptr +4/+8), list<shared_ptr<PropBinding>> +0xc (0x1c), updatePending +0x28, '
                                'CComPtr<EventHandler> handler +0x2c, CComPtr<IHTMLInputElement> element +0x30',
        'CLuaHtmlView::Binder::PropBinding': '0x20 (0042c760 news 0x20): shared_ptr<Instance> +0, const '
                                'PropertyDescriptor* +8, boost::signals::scoped_connection +0xc (0x14)',
    },
    'methods': results, 'instances': INSTANCES, 'exact': exact, 'exact_count': len(exact),
    'pending_build_only': pending,
    'not_counted': {'instances': 'ATL / boost / STL / SecurityContext bodies proven by bytes and targets (see instances)'},
    'left': {
        '0042c8c0': 'CLuaHtmlView method that finds an element by id (IHTMLDocument3 0081056c, IHTMLInputElement '
                    '0081057c), news the Binder and binds it; CLuaHtmlView itself is not natively declared',
        '0042c590 / 0042ccd0 / 0042ce50': 'string-signal slot-call iterator / signal1 operator() / SignalDescImpl '
                    'fire instances of the same unit, not Binder code',
    },
    'vtables': vtables,
    'proposals': [
        'native-headers/v8tree/Instance.h (owner): `static Reflection::SignalDesc<Instance, void(const '
        'Reflection::PropertyDescriptor*)> event_propertyChanged;` (00973f48: PropBinding::PropBinding 0042c630 '
        'connects through it, group 10, via 0042b680; raisePropertyChanged 0040db00 raises it). Unlocks 0042c630 '
        'and, with it, bind 0042c760.',
    ],
    'applied': ['2026-11-06: native-headers/AppLeaves2008/EventHandler2008.h makes `boost::function0<bool> handler` '
                'public (~Binder 0042c3c0 assigns it directly); ~Binder and ??_G 0042c4e0 count.'],
    'scope': 'Inactive. Exact rows with verified targets; pending rows excluded from counts. No active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/luahtml-binder2008-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native luahtml binder2008: %d exact (%s), %d pending-only (%s), %d vtables checked, %d instances' % (
    len(exact), ' '.join(exact), len(pending), ' '.join(pending), len(vtables), len(INSTANCES)))
