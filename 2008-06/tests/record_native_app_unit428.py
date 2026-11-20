"""Record the 2008-06 application range 00428000..0042c000 (inactive) and verify its CLuaHtmlView::Binder template rows.

Step 1, unit map. The range holds two translation units, each with RTTI / string / import evidence that the recorder
re-checks against the original binary (row lists from work/2008-06/functions.jsonl):
  * the LogManager unit (app-unit424-2008 maps it as 0x427890..0x42a62f): LogManager (vtable 0x81030c, slot 0 dtor
    0x428cf0), ThreadLogManager (0x8104b4, slot 0 0x429300), MainLogManager (0x8104cc / 0x8104c0, ctor 0x42a1c0),
    the crash / assert / G3D-error hooks ('Pure Call Error', 'Assertion failed', 'G3D Error'), the log-file archive
    helpers ('error\\', 'archive\\', '*.dmp', DeleteFileA / MoveFileA / FindFirstFileA) and the std::string vector /
    list instances they use. It stays blocked: native-headers/CRobloxApp.h (maintainer exclusion, proposal only)
    declares ThreadLogManager / MainLogManager with bases that contradict the RTTI, and no class an existing native
    header declares is redeclared here (the app-unit424-2008 proposal stands);
  * the CLuaHtmlView unit (0x42a630..0x42ced0): EventHandler (vtable 0x810598) and CLuaHtmlView::Binder /
    PropBinding with their boost / std / ATL instances. EventHandler rows are counted by app-leaves2008, the Binder
    methods by luahtml-binder2008 (its 'instances' are proven there but not counted).
Rows other receipts count are found with the top-level exact_function_rows rule (receipts without that key: their
exact_addresses / exact_unique_addresses lists, else the methods marked exact) and written as 'ADDR counted by
RECEIPT' text; every other address of a row not counted here is written 0x-prefixed (local_backpack /
viewnew_brick_build / viewnew_part_mesh read any quoted bare address as counted).

Step 2, recovery. native-classes/AppUnit428BinderTemplates.cpp explicitly instantiates the boost / std templates whose
arguments name CLuaHtmlView::Binder or PropBinding (no other unit can emit them; their RTTI type names are in .rdata)
against native-headers/LuaHtmlBinder2008/LuaHtmlBinder2008.h, included read-only. Build profile: as
record_native_luahtml_binder2008.py (VS2008 RTM 21022, document-swap flags, native-headers/mfc-noinline-pcxstr,
std-noinline-string and boost-function-pod-vtable first). A row counts only if its bytes match exactly and every
relocation is bound to the address the original instruction uses and verified: imports by DLL name / ordinal,
literals by bytes, RTTI and vtables by original RTTI names, own symbols by the row proven here, the boost
thread / signals library and CRT by the explicit EXTERNAL map (the bindings other recorders prove), evidence names by
offline/evidence.json, and any other inline body by bytes at the called address with its own targets verified the
same way (recursively; listed under 'instances', not counted). Catch funclets are separate function-list rows and are
compared as their own piece of the emitted body. Vtable slots of sp_counted_impl_p<Binder> / <PropBinding> are
compared slot by slot from the object built from the current headers (there is no pending build).
Writes work/2008-06/shared-layouts/app-unit428-working.json.
"""
import glob
import json
import os
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_bind as nb  # noqa: E402
from native_bind import ROOT, OUT, LOCAL_EH, Original, flags, match, rebuild, sha  # noqa: E402

HDR = ROOT / 'rebuild/2008-06/native-headers'
SRC = ROOT / 'rebuild/2008-06/native-classes'
UNIT_CPP = SRC / 'AppUnit428BinderTemplates.cpp'
BINDER_H = HDR / 'LuaHtmlBinder2008/LuaHtmlBinder2008.h'
PROFILE = ['/I' + str(HDR / d) for d in ('mfc-noinline-pcxstr', 'std-noinline-string', 'boost-function-pod-vtable')]
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit428-working.json'
LO, HI = 0x428000, 0x42c000
LOG_LO, LOG_HI = 0x427890, 0x42a630     # LogManager unit (app-unit424-2008 map)
HTML_LO, HTML_HI = 0x42a630, 0x42ced0   # CLuaHtmlView unit
H = lambda a: '0x%08x' % a
original = Original()


def d(address):
    return struct.unpack('<I', original.data(address, 4))[0]


FUNCS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        row = json.loads(line)
        FUNCS[int(row['addr'], 16)] = row
rows = sorted(a for a in FUNCS if LO <= a < HI)
EVIDENCE = json.loads((ROOT / 'rebuild/2008-06/offline/evidence.json').read_text())['names']


def build(source, name):
    OUT.mkdir(parents=True, exist_ok=True)
    obj = OUT / (name + '.obj')
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', PROFILE + flags() + ['/Fo' + str(obj), str(source)], OUT)
    assert code == 0, log
    return obj


unit_obj = build(UNIT_CPP, 'NativeAppUnit428BinderTemplates')

# ---- rows counted here ----------------------------------------------------------------------------------------
B = 'VBinder@CLuaHtmlView@@'
PB = 'VPropBinding@Binder@CLuaHtmlView@@'
SC_PB = '??$?0' + PB + '@shared_count@detail@boost@@QAE@PA' + PB + '@Z'
SC_B = '??$?0' + B + '@shared_count@detail@boost@@QAE@PA' + B + '@Z'
ROWS = [   # (address or (address, lo, hi) piece of the emitted body, symbol)
    # function0<bool>(OnChangeCall)
    (0x0042b6d0,
        '??$?0V?$bind_t@_NV?$mf0@_NVBinder@CLuaHtmlView@@@_mfi@boost@@V?$list1@V?$value@PAVBinder@CLuaHtmlVie'
        'w@@@_bi@boost@@@_bi@3@@_bi@boost@@@?$function0@_NV?$allocator@Vfunction_base@boost@@@std@@@boost@@QA'
        'E@V?$bind_t@_NV?$mf0@_NVBinder@CLuaHtmlView@@@_mfi@boost@@V?$list1@V?$value@PAVBinder@CLuaHtmlView@@'
        '@_bi@boost@@@_bi@3@@_bi@1@H@Z'),
    # functor_manager<OnChangeCall>::manage
    (0x0042aba0,
        '?manage@?$functor_manager@V?$bind_t@_NV?$mf0@_NVBinder@CLuaHtmlView@@@_mfi@boost@@V?$list1@V?$value@'
        'PAVBinder@CLuaHtmlView@@@_bi@boost@@@_bi@3@@_bi@boost@@V?$allocator@Vfunction_base@boost@@@std@@@fun'
        'ction@detail@boost@@SAXABTfunction_buffer@234@AAT5234@W4functor_manager_operation_type@234@@Z'),
    # functor_manager<OnChangeCall>::manager
    (0x0042a6c0,
        '?manager@?$functor_manager@V?$bind_t@_NV?$mf0@_NVBinder@CLuaHtmlView@@@_mfi@boost@@V?$list1@V?$value'
        '@PAVBinder@CLuaHtmlView@@@_bi@boost@@@_bi@3@@_bi@boost@@V?$allocator@Vfunction_base@boost@@@std@@@fu'
        'nction@detail@boost@@CAXABTfunction_buffer@234@AAT5234@W4functor_manager_operation_type@234@Ufunctio'
        'n_obj_tag@234@@Z'),
    # function0<void>(UpdateCall)
    (0x0042b950,
        '??$?0V?$bind_t@XV?$mf0@XVBinder@CLuaHtmlView@@@_mfi@boost@@V?$list1@V?$value@V?$shared_ptr@VBinder@C'
        'LuaHtmlView@@@boost@@@_bi@boost@@@_bi@3@@_bi@boost@@@?$function0@XV?$allocator@Vfunction_base@boost@'
        '@@std@@@boost@@QAE@V?$bind_t@XV?$mf0@XVBinder@CLuaHtmlView@@@_mfi@boost@@V?$list1@V?$value@V?$shared'
        '_ptr@VBinder@CLuaHtmlView@@@boost@@@_bi@boost@@@_bi@3@@_bi@1@H@Z'),
    # function0<void>::assign_to<UpdateCall>
    (0x0042b8b0,
        '??$assign_to@V?$bind_t@XV?$mf0@XVBinder@CLuaHtmlView@@@_mfi@boost@@V?$list1@V?$value@V?$shared_ptr@V'
        'Binder@CLuaHtmlView@@@boost@@@_bi@boost@@@_bi@3@@_bi@boost@@@?$function0@XV?$allocator@Vfunction_bas'
        'e@boost@@@std@@@boost@@AAEXABV?$bind_t@XV?$mf0@XVBinder@CLuaHtmlView@@@_mfi@boost@@V?$list1@V?$value'
        '@V?$shared_ptr@VBinder@CLuaHtmlView@@@boost@@@_bi@boost@@@_bi@3@@_bi@1@@Z'),
    # functor_manager<UpdateCall>::manage
    (0x0042b870,
        '?manage@?$functor_manager@V?$bind_t@XV?$mf0@XVBinder@CLuaHtmlView@@@_mfi@boost@@V?$list1@V?$value@V?'
        '$shared_ptr@VBinder@CLuaHtmlView@@@boost@@@_bi@boost@@@_bi@3@@_bi@boost@@V?$allocator@Vfunction_base'
        '@boost@@@std@@@function@detail@boost@@SAXABTfunction_buffer@234@AAT5234@W4functor_manager_operation_'
        'type@234@@Z'),
    # functor_manager<UpdateCall>::manager
    (0x0042b550,
        '?manager@?$functor_manager@V?$bind_t@XV?$mf0@XVBinder@CLuaHtmlView@@@_mfi@boost@@V?$list1@V?$value@V'
        '?$shared_ptr@VBinder@CLuaHtmlView@@@boost@@@_bi@boost@@@_bi@3@@_bi@boost@@V?$allocator@Vfunction_bas'
        'e@boost@@@std@@@function@detail@boost@@CAXABTfunction_buffer@234@AAT5234@W4functor_manager_operation'
        '_type@234@U?$bool_@$00@mpl@4@@Z'),
    # slot<function<void(const PropertyDescriptor*)>>(PropertyChangedCall)
    (0x0042b9a0,
        '??$?0V?$bind_t@XP6AXPBVPropertyDescriptor@Reflection@RBX@@ABV123@PAVBinder@CLuaHtmlView@@@ZV?$list3@'
        'V?$arg@$00@boost@@V?$reference_wrapper@$$CBVPropertyDescriptor@Reflection@RBX@@@2@V?$value@PAVBinder'
        '@CLuaHtmlView@@@_bi@2@@_bi@boost@@@_bi@boost@@@?$slot@V?$function@$$A6AXPBVPropertyDescriptor@Reflec'
        'tion@RBX@@@ZV?$allocator@X@std@@@boost@@@boost@@QAE@ABV?$bind_t@XP6AXPBVPropertyDescriptor@Reflectio'
        'n@RBX@@ABV123@PAVBinder@CLuaHtmlView@@@ZV?$list3@V?$arg@$00@boost@@V?$reference_wrapper@$$CBVPropert'
        'yDescriptor@Reflection@RBX@@@2@V?$value@PAVBinder@CLuaHtmlView@@@_bi@2@@_bi@boost@@@_bi@1@@Z'),
    # function<void(const PropertyDescriptor*)>(PropertyChangedCall)
    (0x0042b800,
        '??$?0V?$bind_t@XP6AXPBVPropertyDescriptor@Reflection@RBX@@ABV123@PAVBinder@CLuaHtmlView@@@ZV?$list3@'
        'V?$arg@$00@boost@@V?$reference_wrapper@$$CBVPropertyDescriptor@Reflection@RBX@@@2@V?$value@PAVBinder'
        '@CLuaHtmlView@@@_bi@2@@_bi@boost@@@_bi@boost@@@?$function@$$A6AXPBVPropertyDescriptor@Reflection@RBX'
        '@@@ZV?$allocator@X@std@@@boost@@QAE@V?$bind_t@XP6AXPBVPropertyDescriptor@Reflection@RBX@@ABV123@PAVB'
        'inder@CLuaHtmlView@@@ZV?$list3@V?$arg@$00@boost@@V?$reference_wrapper@$$CBVPropertyDescriptor@Reflec'
        'tion@RBX@@@2@V?$value@PAVBinder@CLuaHtmlView@@@_bi@2@@_bi@boost@@@_bi@1@H@Z'),
    # functor_manager<PropertyChangedCall>::manage
    (0x0042abe0,
        '?manage@?$functor_manager@V?$bind_t@XP6AXPBVPropertyDescriptor@Reflection@RBX@@ABV123@PAVBinder@CLua'
        'HtmlView@@@ZV?$list3@V?$arg@$00@boost@@V?$reference_wrapper@$$CBVPropertyDescriptor@Reflection@RBX@@'
        '@2@V?$value@PAVBinder@CLuaHtmlView@@@_bi@2@@_bi@boost@@@_bi@boost@@V?$allocator@X@std@@@function@det'
        'ail@boost@@SAXABTfunction_buffer@234@AAT5234@W4functor_manager_operation_type@234@@Z'),
    # functor_manager<PropertyChangedCall>::manager
    (0x0042a8a0,
        '?manager@?$functor_manager@V?$bind_t@XP6AXPBVPropertyDescriptor@Reflection@RBX@@ABV123@PAVBinder@CLu'
        'aHtmlView@@@ZV?$list3@V?$arg@$00@boost@@V?$reference_wrapper@$$CBVPropertyDescriptor@Reflection@RBX@'
        '@@2@V?$value@PAVBinder@CLuaHtmlView@@@_bi@2@@_bi@boost@@@_bi@boost@@V?$allocator@X@std@@@function@de'
        'tail@boost@@CAXABTfunction_buffer@234@AAT5234@W4functor_manager_operation_type@234@Ufunction_obj_tag'
        '@234@@Z'),
    # void_function_obj_invoker1<PropertyChangedCall>::invoke
    (0x0042b330,
        '?invoke@?$void_function_obj_invoker1@V?$bind_t@XP6AXPBVPropertyDescriptor@Reflection@RBX@@ABV123@PAV'
        'Binder@CLuaHtmlView@@@ZV?$list3@V?$arg@$00@boost@@V?$reference_wrapper@$$CBVPropertyDescriptor@Refle'
        'ction@RBX@@@2@V?$value@PAVBinder@CLuaHtmlView@@@_bi@2@@_bi@boost@@@_bi@boost@@XPBVPropertyDescriptor'
        '@Reflection@RBX@@@function@detail@boost@@SAXAATfunction_buffer@234@PBVPropertyDescriptor@Reflection@'
        'RBX@@@Z'),
    # std::for_each<list<shared_ptr<PropBinding>>::iterator, SetValueCall>
    (0x0042b7c0,
        '??$for_each@V?$_Iterator@$00@?$list@V?$shared_ptr@VPropBinding@Binder@CLuaHtmlView@@@boost@@V?$alloc'
        'ator@V?$shared_ptr@VPropBinding@Binder@CLuaHtmlView@@@boost@@@std@@@std@@V?$bind_t@XV?$mf1@XVPropBin'
        'ding@Binder@CLuaHtmlView@@PBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@_mfi@boos'
        't@@V?$list2@V?$arg@$00@boost@@V?$value@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@st'
        'd@@@_bi@2@@_bi@3@@_bi@boost@@@std@@YA?AV?$bind_t@XV?$mf1@XVPropBinding@Binder@CLuaHtmlView@@PBV?$bas'
        'ic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@_mfi@boost@@V?$list2@V?$arg@$00@boost@@V?$v'
        'alue@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@_bi@2@@_bi@3@@_bi@boost@@V?$_I'
        'terator@$00@?$list@V?$shared_ptr@VPropBinding@Binder@CLuaHtmlView@@@boost@@V?$allocator@V?$shared_pt'
        'r@VPropBinding@Binder@CLuaHtmlView@@@boost@@@std@@@0@0V123@@Z'),
    # shared_count(PropBinding*) and its catch funclet (checked_delete, rethrow)
    ((0x0042b280, 0, 0x6e), SC_PB),
    ((0x0042b2ee, 0x6e, 0x83), SC_PB),
    # checked_delete<PropBinding>
    (0x0042b0e0,
        '??$checked_delete@VPropBinding@Binder@CLuaHtmlView@@@boost@@YAXPAVPropBinding@Binder@CLuaHtmlView@@@'
        'Z'),
    # sp_counted_impl_p<PropBinding>::dispose
    (0x0042b310,
        '?dispose@?$sp_counted_impl_p@VPropBinding@Binder@CLuaHtmlView@@@detail@boost@@UAEXXZ'),
    # shared_count(Binder*) and its catch funclet; shared_ptr<Binder>(Binder*) with the enable_shared_from_this hookup
    ((0x0042a630, 0, 0x6e), SC_B),
    ((0x0042a69e, 0x6e, 0x83), SC_B),
    (0x0042aaf0, '??$?0' + B + '@?$shared_ptr@' + B + '@boost@@QAE@PA' + B + '@Z'),
]



def first(spec):
    return spec[0] if isinstance(spec, tuple) else spec


EXTERNAL = {
    # boost 1.34.1 signals library (record_native_luahtml_binder2008.py / record_native_history_start_trial.py).
    '?create_connection@slot_base@detail@signals@boost@@IAEXXZ': 0x00595840,
    '??1connection@signals@boost@@QAE@XZ': 0x00595370,
    # CRT (record_native_guid_critical_section.py / record_native_adorn.py bindings).
    '??2@YAPAXI@Z': 0x006a0920,
    '??3@YAXPAX@Z': 0x006a067a,
    '__CxxThrowException@8': 0x006a158c,
    # Binder / PropBinding bodies counted by record_native_luahtml_binder2008.py.
    '??1PropBinding@Binder@CLuaHtmlView@@QAE@XZ': 0x0042a720,
}
own = {}
for spec, sym in ROWS:
    own.setdefault(sym, first(spec))
binding = {}


def classify(symbol, value, raw, sections, definitions, where):
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol.startswith('??_C@'):
        pos, at = definitions[symbol]
        literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
        assert original.data(value, len(literal)) == literal, (where, symbol, hex(value))
        return 'literal %r' % literal[:-1].decode()
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
        return 'own row'
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
        return 'external'
    if EVIDENCE.get('%08x' % value, {}).get('symbol') == symbol:
        return 'evidence name'
    return instance(symbol, value, where)


CURRENT = []
INSTANCES = {}
BODIES = {}


def bodies_of(obj):
    if obj not in BODIES:
        BODIES[obj] = {n: (b, r) for n, b, r in match.coff_functions(Path(obj).read_bytes())}
    return BODIES[obj]


def instance(symbol, value, where):
    """An inline body this build emits, proven by bytes at the called address and by its own targets."""
    if symbol in INSTANCES:
        assert INSTANCES[symbol]['address'] == '%08x' % value, (where, symbol, hex(value))
        return 'instance (bytes equal, targets verified)'
    obj = CURRENT[-1]
    if symbol not in bodies_of(obj):
        return data_instance(symbol, value, where)
    body = bodies_of(obj)[symbol][0]
    try:
        target, _, _ = match.target('2008-06', '%08x' % value)
        unlisted = False
    except SystemExit:
        target, unlisted = b'', True
    merged = len(body) != len(target)
    spec = (value, 0, len(body), 'raw') if merged else value
    INSTANCES[symbol] = {'address': '%08x' % value, 'pending': True}
    row = verify(obj, [(spec, symbol)], False)[0]
    row['status'] = 'instance (emitted by this unit; every own target verified), bytes equal, not counted'
    if unlisted:
        row['status'] += '; not a listed function start, whole body compared with the image bytes'
    elif merged:
        row['status'] += '; listed extent %#x != body %#x, whole body compared with the image bytes' % (
            len(target), len(body))
    INSTANCES[symbol] = row
    return 'instance (bytes equal, targets verified)'


def data_instance(symbol, value, where):
    """Initialized data this unit defines (a boost::function stored vtable): bytes equal at the referenced address with
    relocated fields masked, and every relocated field bound like a code target."""
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


def verify(obj, specs, exact_flag):
    CURRENT.append(obj)
    try:
        return verify_rows(obj, specs, exact_flag)
    finally:
        CURRENT.pop()


def verify_rows(obj, specs, exact_flag):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = bodies_of(obj)
    out = []
    for spec, name in specs:
        assert name in bodies, ('not emitted', name)
        body, refs = bodies[name]
        address, lo, hi = spec[:3] if isinstance(spec, tuple) else (spec, 0, len(body))
        body, refs = body[lo:hi], [r - lo for r in refs if lo <= r < hi]
        if isinstance(spec, tuple) and spec[3:] == ('raw',):
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
            assert how is not None, ('unbound relocation', name, symbol, hex(value))
            prev = binding.setdefault(symbol, value)
            assert prev == value, ('inconsistent binding', symbol, hex(prev), hex(value))
            verified[symbol] = '%s (%s)' % (hex(value), how)
        piece = '' if (lo, hi) == (0, len(bodies[name][0])) else ' [%#x:%#x]' % (lo, hi)
        out.append({'address': '%08x' % address, 'symbol': name + piece, 'size': len(body), 'exact': exact_flag,
                    'verified_targets': verified, 'local_eh': sorted(local)})
    return out


results = verify(unit_obj, ROWS, True)
for r in results:
    assert r['size'] == FUNCS[int(r['address'], 16)]['size'], (r['address'], r['size'])


# ---- vtables (object from the current headers) -----------------------------------------------------------------------
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


VTABLES = {'??_7?$sp_counted_impl_p@' + PB + '@detail@boost@@6B@':
           (0x00810524, '.?AV?$sp_counted_impl_p@' + PB + '@detail@boost@@', 4),
           '??_7?$sp_counted_impl_p@' + B + '@detail@boost@@6B@':
           (0x00810538, '.?AV?$sp_counted_impl_p@' + B + '@detail@boost@@', 4)}
vtables = {}
for symbol, (vt, rtti_name, count) in VTABLES.items():
    assert original.vtable_class(vt) == (rtti_name, 0), (hex(vt), original.vtable_class(vt))
    raw, sections, definitions, slots = vtable_slots(unit_obj, symbol)
    assert sorted(slots) == list(range(count)), (symbol, sorted(slots))
    checked = {}
    CURRENT.append(unit_obj)
    for slot, sym in sorted(slots.items()):
        value = d(vt + 4 * slot)
        how = classify(sym, value, raw, sections, definitions, symbol)
        if how is None and sym.startswith('??_E') and ('??_G' + sym[4:]) in bodies_of(unit_obj):
            how = instance('??_G' + sym[4:], value, symbol)
            how = how and how + ' via ??_G'
        assert how is not None, ('unbound vtable slot', symbol, slot, sym, hex(value))
        prev = binding.setdefault(sym, value)
        assert prev == value, ('inconsistent', sym, hex(prev), hex(value))
        checked[slot] = '%s = %s (%s)' % (sym, hex(value), how)
    CURRENT.pop()
    vtables[symbol] = {'address': hex(vt), 'rtti': rtti_name, 'slots': checked}

exact = sorted({r['address'] for r in results})
exact_ints = {int(a, 16) for a in exact}

# ---- step 1: what other receipts count (top-level exact_function_rows rule) ------------------------------------------
def addr_of(x):
    if isinstance(x, dict):
        x = x.get('address') or x.get('addr') or ''
    s = str(x).lower()
    s = s[2:] if s.startswith('0x') else s
    try:
        return int(s[:8], 16) if len(s) >= 6 and all(c in '0123456789abcdef' for c in s[:6]) else None
    except ValueError:
        return None


def walk_methods(o, out):
    if isinstance(o, list):
        for e in o:
            walk_methods(e, out)
    elif isinstance(o, dict):
        if 'address' in o and o.get('exact') is True:
            out.append(o['address'])
        else:
            for v in o.values():
                walk_methods(v, out)


counted_elsewhere = {}
for f in sorted(glob.glob(str(ROOT / 'work/2008-06/shared-layouts/*.json'))):
    if Path(f).resolve() == RECEIPT.resolve():
        continue
    try:
        doc = json.loads(Path(f).read_text())
    except Exception:
        continue
    if not isinstance(doc, dict):
        continue
    if 'exact_function_rows' in doc:
        got = doc['exact_function_rows']
    elif isinstance(doc.get('exact_addresses'), list):
        got = doc['exact_addresses']
    elif isinstance(doc.get('exact_unique_addresses'), list):
        got = doc['exact_unique_addresses']
    else:
        got = []
        walk_methods(doc.get('methods', []), got)
    if isinstance(got, dict):
        got = list(got)
    for x in got:
        v = addr_of(x)
        if v is not None and LO <= v < HI:
            counted_elsewhere.setdefault(v, set()).add(os.path.basename(f)[:-5])
double = sorted(exact_ints & set(counted_elsewhere))
assert not double, ('counted elsewhere too', [H(a) for a in double])

# ---- step 1: per-row evidence and unit assignment --------------------------------------------------------------------
def rtti_of(v):
    if not 0x7c0000 <= v < 0x980000:
        return None
    try:
        name, _ = original.vtable_class(v)
    except Exception:
        return None
    return name if name and name.startswith('.?A') else None


def string_at(v):
    if not 0x7c0000 <= v < 0x980000:
        return None
    try:
        raw = original.data(v, 128)
    except Exception:
        return None
    end = raw.find(b'\0')
    if end < 3 or any(c < 0x20 and c not in (9, 10, 13) or c > 0x7e for c in raw[:end]):
        return None
    return raw[:end].decode('latin-1')


def evidence_of(a):
    r = FUNCS[a]
    ev = {}
    name = EVIDENCE.get('%08x' % a, {}).get('symbol')
    if name:
        ev['evidence_name'] = name
    vts = sorted({rtti_of(int(x, 16)) for x in r.get('data_refs', [])} - {None})
    if vts:
        ev['rtti_refs'] = vts
    strs = sorted({s for s in (string_at(int(x, 16)) for x in r.get('data_refs', [])) if s})
    if strs:
        ev['strings'] = strs[:4]
    imps = sorted({i.split('!', 1)[0] + '!' + i.split('!', 1)[1][:60] for i in r.get('imports', [])})
    if imps:
        ev['imports'] = imps[:4]
    if r.get('callers'):
        ev['callers'] = [H(int(c, 16)) for c in r['callers'][:6]]
    return ev


# Unit boundary checks: the vtables / strings that anchor the two units.
assert original.vtable_class(0x81030c)[0] == '.?AVLogManager@@' and d(0x81030c) == 0x428cf0
assert original.vtable_class(0x8104b4)[0] == '.?AVThreadLogManager@@' and d(0x8104b4) == 0x429300
assert original.vtable_class(0x8104c0)[0] == '.?AVMainLogManager@@'
assert original.vtable_class(0x8104cc)[0] == '.?AVMainLogManager@@'
assert original.vtable_class(0x810598)[0] == '.?AVEventHandler@@'
assert original.vtable_class(0x810654)[0] == '.?AVBinder@CLuaHtmlView@@'
assert '.?AVMainLogManager@@' in evidence_of(0x428d10).get('rtti_refs', [])
assert '.?AVThreadLogManager@@' in evidence_of(0x42a4f0).get('rtti_refs', [])
assert 'Pure Call Error' in evidence_of(0x4282a0).get('strings', [])
assert any('G3D Error' in s for s in evidence_of(0x428790).get('strings', []))
assert any('HtmlDocument' in s for s in evidence_of(0x42ae50).get('strings', []))
for a, b in zip(rows, rows[1:]):
    assert a + FUNCS[a]['size'] <= b, hex(a)

# Hand-classified open rows (address -> note); every row of the range must be classified.
LOG_NOTES = {
    0x4282a0: 'pure-call hook (MessageBox "Pure Call Error")', 0x4286e0: 'assert hook ("Assertion failed")',
    0x428790: 'G3D failure hook ("G3D Error")', 0x4284e0: 'crash-dump file scan ("*.dmp", FindFirstFileA)',
    0x428310: 'log-file rotation (DeleteFileA / MoveFileA)', 0x428050: 'log file name ("log_", ".txt")',
    0x428180: 'MainLogManager crash-reporter start (new(0x7d0) RobloxCrashReporter)',
    0x4285e0: 'LogManager log paths ("error\\\\", "archive\\\\"; vtable 0x81030c)',
    0x428cf0: 'LogManager destructor (vtable 0x81030c slot 0)',
    0x428d10: 'MainLogManager path / archive method (vtable 0x8104c0)',
    0x429300: 'ThreadLogManager deleting destructor (vtable 0x8104b4 slot 0)',
    0x429bc0: 'log archive scan ("*.dmp", "archive\\\\")', 0x429f30: 'log archive cleanup (DeleteFileA)',
    0x42a1c0: 'MainLogManager constructor ("_G3D.txt", GetCurrentThreadId)',
    0x42a4f0: 'ThreadLogManager lookup / creation (vtables 0x81030c / 0x8104b4)',
    0x42a5c0: 'current-thread log manager (GetCurrentThreadId)',
    0x42a5f0: 'ICF body (evidence name Instance::getRootAncestor)', 0x42a610: 'jmp operator delete (ICF stub)',
    0x428ae0: 'error-message formatter ("Unknown Error", lstrlenA / strcpy_s)',
    0x4290b0: 'string formatter (lstrlenA), shared by other units',
    0x429200: 'boost::detail::tss constructor (evidence name)', 0x4292b0: 'boost::thread_resource_error copy',
    0x4293d0: 'std::vector<shared_ptr<Instance>> constructor (evidence name), shared',
    0x42a620: 'boost::function invoker for void(*)(Security::Context*) (tss cleanup)',
}
HTML_NOTES = {
    0x42a7a0: 'functor_manager<void(*)(Security::Context*)>::manage (RTTI type .P6AXPAVContext@Security@RBX@@@Z): '
              'SecurityContext header instance, also reached from other units',
    0x42a800: 'shared_count<int> constructor (evidence name), also called by 0x4a3020 / 0x4d81c0',
    0x42a86e: 'catch funclet of 0x42a800', 0x42a890: 'sp_counted_impl_p<int>::dispose (evidence name)',
    0x42a8f0: 'std iterator helper (_invalid_parameter_noinfo), called by six units',
    0x42a930: 'ATL CComPtrBase::IsEqualObject-shaped QueryInterface compare (ATL library instance)',
    0x42ac20: 'boost::function1<void, std::string>::operator() (evidence name), string-signal instance',
    0x42ad40: 'InlineIsEqualGUID (ATL / Windows SDK library instance), called by other units',
    0x42ae50: 'CLuaHtmlView::setBody (CLuaHtmlView not natively declared; proposal of app-leaves2008)',
    0x42afc0: 'boost::function0<bool>::operator() (evidence name), shared',
    0x42b010: 'any::holder<function<void(const PropertyDescriptor*)>> constructor, shared signal instance',
    0x42b070: 'any::holder<function<void(const PropertyDescriptor*)>>::type, shared signal instance',
    0x42b080: 'any::holder<function<void(const PropertyDescriptor*)>>::clone, shared signal instance',
    0x42b100: 'signals caller<std::string, ...> (evidence name), string-signal instance',
    0x42b220: 'any::any<function<void(const PropertyDescriptor*)>>, shared (also called by 0x5594c0)',
    0x42b390: 'ICF body: evidence name list<shared_ptr<Replicator::Item>>::clear (also Binder list clear)',
    0x42b400: 'signal1<void, const PropertyDescriptor*>::connect, reached through TSignalDesc::connect 0x42b680 '
              '(shared with other units)',
    0x42b5f0: 'CLuaHtmlView::unbindAll (CLuaHtmlView not natively declared)',
    0x42b680: 'TSignalDesc<void(const PropertyDescriptor*)>::connect, Reflection instance shared with 0x4b52b0 / '
              '0x4b7250',
    0x42b730: 'functor_manager<tss_adapter<Security::Context>>::manager (RTTI .?AU?$tss_adapter@VContext@...)',
    0x42b910: 'functor_manager<tss_adapter<Security::Context>>::manage',
    0x42ba50: 'boost::function1 constructor from tss_adapter<Security::Context>',
    0x42baf0: 'thread_specific_ptr<Security::Context> constructor (evidence name)',
    0x42bbb0: 'Security::Context::ptr (evidence name), SecurityContext header instance',
    0x42bc10: 'Security::Impersonator constructor (evidence name), also called by the CMainFrame unit 0x42e0c0',
    0x42bc90: 'Security::Impersonator destructor shape (Context::ptr, tss get / set / cleanup)',
}
EXCLUDED_KINDS = {}
unit_rows = []
for a in rows:
    entry = {'row': H(a), 'size': FUNCS[a]['size']}
    if LOG_LO <= a < LOG_HI:
        entry['unit'] = 'LogManager'
        entry['kind'] = 'rbx-blocked (CRobloxApp.h log-manager declarations; std::string / boost instances are library)'
        note = LOG_NOTES.get(a)
        if note is None:
            nm = EVIDENCE.get('%08x' % a, {}).get('symbol', '')
            note = ('std library instance for std::string (evidence name)' if 'basic_string' in nm else
                    'LogManager unit body (vtables 0x81030c / 0x8104b4 / 0x8104c0, app-unit424-2008 map)')
        entry['note'] = note
    else:
        assert HTML_LO <= a < HTML_HI, hex(a)
        entry['unit'] = 'CLuaHtmlView'
        if a in exact_ints:
            entry['kind'] = 'counted here'
        elif a in counted_elsewhere:
            entry['kind'] = 'counted elsewhere'
        else:
            assert a in HTML_NOTES, ('unclassified', hex(a))
            entry['kind'] = 'open (shared / library / CLuaHtmlView)'
            entry['note'] = HTML_NOTES[a]
    if a in counted_elsewhere:
        entry['counted'] = '%08x counted by %s' % (a, ', '.join(sorted(counted_elsewhere[a])))
        entry['row'] = 'see counted'
    elif a in exact_ints:
        entry['counted'] = '%08x counted here' % a
    entry['evidence'] = evidence_of(a)
    unit_rows.append(entry)
assert sum(1 for e in unit_rows if e['kind'] == 'counted here') == len(exact)

paths = [Path(__file__).resolve(), ROOT / 'rebuild/2008-06/tests/native_bind.py', UNIT_CPP, BINDER_H,
         HDR / 'AppLeaves2008/EventHandler2008.h', HDR / 'AppLeaves2008/Marshaller2008.h',
         HDR / 'mfc-noinline-pcxstr/atlsimpstr.h', HDR / 'std-noinline-string/xstring',
         HDR / 'boost-function-pod-vtable/boost/function/function_template.hpp',
         HDR / 'boost-function-pod-vtable/boost/function/function_base.hpp']
n_log = sum(1 for a in rows if LOG_LO <= a < LOG_HI)
n_html = len(rows) - n_log
receipt = {
    'family': 'app unit 00428000 (LogManager unit tail, CLuaHtmlView unit head): CLuaHtmlView::Binder template rows',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': PROFILE + flags(),
    'profile': 'document-swap flags with native-headers/mfc-noinline-pcxstr, std-noinline-string and '
               'boost-function-pod-vtable first (as record_native_luahtml_binder2008.py)',
    'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {'binder_templates': sha(unit_obj)},
    'range': [H(LO), H(HI)],
    'range_rows': len(rows),
    'unit_map': {
        'LogManager unit 0x427890..0x42a62f': {
            'rows_in_range': n_log, 'kind': 'rbx-blocked',
            'why': 'native-headers/CRobloxApp.h (maintainer exclusion) declares ThreadLogManager without a base and '
                   'MainLogManager : LogManagerSink, ThreadLogManager; RTTI says LogManager (no bases), '
                   'ThreadLogManager : LogManager, MainLogManager : RBX::ILogProvider, LogManager. Not redeclared '
                   'here; the app-unit424-2008 proposal stands. Its std::string vector / list rows are library '
                   'instances (evidence names) and are not recovered.'},
        'CLuaHtmlView unit 0x42a630..0x42ced0': {
            'rows_in_range': n_html, 'kind': 'rbx',
            'why': 'EventHandler rows counted by app-leaves2008, Binder methods by luahtml-binder2008; the Binder-only '
                   'template rows are counted here; the rest are SecurityContext / signals / any / ATL instances '
                   'other units also reach, or CLuaHtmlView methods (not natively declared).'},
    },
    'rows': unit_rows,
    'methods': results,
    # instance rows are not counted: their addresses are written 0x-prefixed (never as quoted bare addresses)
    'instances': {k: dict(v, address='0x' + v['address']) for k, v in INSTANCES.items()},
    'vtables': vtables,
    'counted_elsewhere': ['%08x counted by %s' % (a, ', '.join(sorted(v))) for a, v in sorted(counted_elsewhere.items())],
    'proposals': [
        'native-headers/CRobloxApp.h (maintainer exclusion; proposal only, as app-unit424-2008): declare LogManager, '
        'ThreadLogManager : LogManager and MainLogManager : RBX::ILogProvider, LogManager per the RTTI of vtables '
        '0x81030c / 0x8104b4 / 0x8104cc / 0x8104c0 in a separate LogManager header; unlocks the LogManager unit.',
    ],
    'rejected': [],
    'shadowing': 'none (no new header; LuaHtmlBinder2008.h and the profile headers are included read-only)',
    'exact_function_rows': exact,
    'scope': 'Inactive. Exact rows with every target verified; no pending build; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native app unit428: %d rows mapped (%d LogManager, %d CLuaHtmlView), %d exact (%s), %d counted '
      'elsewhere, %d vtables checked, %d instances' % (len(rows), n_log, n_html, len(exact), ' '.join(exact),
                                                     len(counted_elsewhere), len(vtables), len(INSTANCES)))
