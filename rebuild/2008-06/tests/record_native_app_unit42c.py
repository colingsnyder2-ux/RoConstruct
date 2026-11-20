"""Record the 2008-06 application range 0042c000..00430000 (inactive) and verify its boost / std template rows.

Step 1, unit map. The range holds the tail of one translation unit and two more, each with RTTI / string / call
evidence that the recorder re-checks against the original binary (row lists from work/2008-06/functions.jsonl;
the app-unit424-2008 map of 0x424000..0x430000 is followed):
  * the CLuaHtmlView unit tail (0x42a630..0x42cecf): CLuaHtmlView::Binder (vtable 0x810654, ~Binder 0x42c3c0) and
    PropBinding with their boost / signals instances; the Binder methods are counted by luahtml-binder2008;
  * the CLuaFunction unit (0x42ced0..0x42e45f): the ScriptContext service templates (app-unit424-2008),
    boost::any holder<float> / holder<int> (library), the std::vector<Reflection::Value> instances, LuaArgs::push
    (lua-args-trial), CComObject<CLuaFunction> (vtable 0x80ebd8: slot 7 Invoke 0x42e0c0, slot 8 0x42da40) and MFC /
    G3D header instances;
  * the CMainFrame unit (MainFrm.cpp, 0x42e460..): CMainFrame, MyXTPCommandBars, CPatchedControlComboBox,
    CWrapperView and the XTP control overrides. Maintainer exclusion (CMainFrame / CWrapperView): mapped only.
Rows other receipts count are found with the top-level exact_function_rows rule (receipts without that key: their
exact_addresses / exact_unique_addresses lists, else the methods marked exact) and written as 'ADDR counted by
RECEIPT' text; every other address of a row not counted here is written 0x-prefixed (local_backpack /
viewnew_brick_build / viewnew_part_mesh read any quoted bare address as counted).

Step 2, recovery. Two inactive units with explicit template / member instantiations only (no helper function, no
new header; every header is included read-only):
  * native-classes/AppUnit42CBinderTemplates.cpp: function0<bool>::operator=(bool(*)()) 0x42c320 (+ catch funclet
    0x42c391), the only call of which is ~Binder 0x42c3c0, with functor_manager<bool(*)()>::manage 0x42c2c0 and
    function_invoker0<bool(*)(), bool>::invoke 0x42c2b0 (both reached through the stored vtable 0x810658). Profile
    as record_native_luahtml_binder2008.py (document-swap flags; mfc-noinline-pcxstr, std-noinline-string and
    boost-function-pod-vtable first);
  * native-classes/AppUnit42CValueVector.cpp: the std::vector<Reflection::Value> members insert 0x42d980, _Insert_n
    0x42d6a0 (+ catch funclet 0x42d8aa), _Tidy 0x42d5c0, ~vector 0x42d630, auto_ptr<ValueCollection>::~auto_ptr
    0x42d960 and what they emit at the rows of this unit. Profile as native-classes/LuaArgs.cpp (document-swap
    flags; mfc-noinline-pcxstr and std-noinline-string first).
A row counts only if its bytes match exactly, its listed extent equals the compiled size (catch funclets are separate
function-list rows and are compared as their own piece of the emitted body), and every relocation is bound to the
address the original instruction uses and verified: imports by DLL name / ordinal, literals by bytes, RTTI and
vtables by original RTTI names, own symbols by the row proven here, the CRT by the explicit EXTERNAL map (bindings
other recorders prove), evidence names by offline/evidence.json, and any other body this build emits by bytes at
the called address with its own targets verified the same way (recursively; listed under 'instances', not counted).
No class vtable is emitted by these units (the boost::function stored vtable is a data instance checked field by
field), so there is no slot check and no pending build.
Writes work/2008-06/shared-layouts/app-unit42c-working.json.
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
BINDER_CPP = SRC / 'AppUnit42CBinderTemplates.cpp'
VALUE_CPP = SRC / 'AppUnit42CValueVector.cpp'
BINDER_PROFILE = ['/I' + str(HDR / d) for d in ('mfc-noinline-pcxstr', 'std-noinline-string',
                                                 'boost-function-pod-vtable')]
VALUE_PROFILE = ['/I' + str(HDR / d) for d in ('mfc-noinline-pcxstr', 'std-noinline-string')]
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit42c-working.json'
LO, HI = 0x42c000, 0x430000
HTML_HI = 0x42ced0      # CLuaHtmlView unit tail ends (app-unit424-2008 map)
FUNC_HI = 0x42e460      # CLuaFunction unit ends, CMainFrame unit starts (app-unit424-2008 map)
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


def build(source, name, profile):
    OUT.mkdir(parents=True, exist_ok=True)
    obj = OUT / (name + '.obj')
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', profile + flags() + ['/Fo' + str(obj), str(source)], OUT)
    assert code == 0, log
    return obj


binder_obj = build(BINDER_CPP, 'NativeAppUnit42CBinderTemplates', BINDER_PROFILE)
value_obj = build(VALUE_CPP, 'NativeAppUnit42CValueVector', VALUE_PROFILE)

# ---- rows counted here ----------------------------------------------------------------------------------------
V = 'VValue@Reflection@RBX@@'
VEC = '?$vector@' + V + 'V?$allocator@' + V + '@std@@@std@@'
ASSIGN = '??$?4P6A_NXZ@?$function0@_NV?$allocator@Vfunction_base@boost@@@std@@@boost@@QAEAAV01@P6A_NXZ@Z'
UNINIT_FILL_N = ('??$_Uninit_fill_n@PA' + V + 'IV123@V?$allocator@' + V + '@std@@@std@@YAXPA' + V +
                 'IABV123@AAV?$allocator@' + V + '@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z')
INSERT_N = ('?_Insert_n@' + VEC + 'IAEXV?$_Vector_const_iterator@' + V + 'V?$allocator@' + V + '@std@@@2@IAB' + V +
            '@Z')
BINDER_ROWS = [   # (address or (address, lo, hi) piece of the emitted body, symbol)
    # function_invoker0<bool(*)(), bool>::invoke (stored vtable 0x810658 +4)
    (0x0042c2b0, '?invoke@?$function_invoker0@P6A_NXZ_N@function@detail@boost@@SA_NAATfunction_buffer@234@@Z'),
    # functor_manager<bool(*)()>::manage (stored vtable 0x810658 +0; type_info '.P6A_NXZ' 0x92eb08)
    (0x0042c2c0, '?manage@?$functor_manager@P6A_NXZV?$allocator@Vfunction_base@boost@@@std@@@function@detail@boost@@'
                 'SAXABTfunction_buffer@234@AAT5234@W4functor_manager_operation_type@234@@Z'),
    # function0<bool>::operator=(bool(*)()) and its catch funclet (clear the vtable, rethrow)
    ((0x0042c320, 0, 0x71), ASSIGN),
    ((0x0042c391, 0x71, 0x9e), ASSIGN),
]
VALUE_ROWS = [
    (0x0042cfc0, '??$_Construct@' + V + 'V123@@std@@YAXPA' + V + 'ABV123@@Z'),
    (0x0042d0a0, '??4Value@Reflection@RBX@@QAEAAV012@ABV012@@Z'),
    (0x0042d190, '??$_Copy_backward_opt@PA' + V + 'PAV123@Uforward_iterator_tag@std@@@std@@YAPA' + V +
                 'PAV123@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z'),
    (0x0042d370, '??$_Fill@PA' + V + 'V123@@std@@YAXPA' + V + '0ABV123@@Z'),
    (0x0042d3d0, '?destroy@?$allocator@' + V + '@std@@QAEXPA' + V + '@Z'),
    ((0x0042d470, 0, 0x4b), UNINIT_FILL_N),
    ((0x0042d4bb, 0x4b, 0x81), UNINIT_FILL_N),
    # ICF: _Unchecked_move_backward / _Move_backward_opt / _Copy_backward_opt<random access> compile to the same
    # bytes and the same call; _Insert_n calls the stdext one, so the row is bound to that symbol.
    (0x0042d500, '??$_Unchecked_move_backward@PA' + V + 'PAV123@@stdext@@YAPA' + V + 'PAV123@00@Z'),
    (0x0042d550, '?_Ufill@' + VEC + 'IAEPA' + V + 'PAV345@IABV345@@Z'),
    (0x0042d590, '?_Destroy@' + VEC + 'IAEXPA' + V + '0@Z'),
    (0x0042d5c0, '?_Tidy@' + VEC + 'IAEXXZ'),
    (0x0042d600, '??$_Umove@PA' + V + '@' + VEC + 'IAEPA' + V + 'PAV234@00@Z'),
    (0x0042d630, '??1' + VEC + 'QAE@XZ'),
    ((0x0042d6a0, 0, 0x20a), INSERT_N),
    ((0x0042d8aa, 0x20a, 0x2ac), INSERT_N),
    (0x0042d960, '??1?$auto_ptr@V' + VEC + '@std@@QAE@XZ'),
    (0x0042d980, '?insert@' + VEC + 'QAE?AV?$_Vector_iterator@' + V + 'V?$allocator@' + V +
                 '@std@@@2@V?$_Vector_const_iterator@' + V + 'V?$allocator@' + V + '@std@@@2@AB' + V + '@Z'),
]
ROWS = BINDER_ROWS + VALUE_ROWS


def first(spec):
    return spec[0] if isinstance(spec, tuple) else spec


EXTERNAL = {
    # CRT (record_native_guid_critical_section.py / record_native_adorn.py bindings).
    '??2@YAPAXI@Z': 0x006a0920,
    '??3@YAXPAX@Z': 0x006a067a,
    '__CxxThrowException@8': 0x006a158c,
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


results = verify(binder_obj, BINDER_ROWS, True) + verify(value_obj, VALUE_ROWS, True)
for r in results:
    assert r['size'] == FUNCS[int(r['address'], 16)]['size'], (r['address'], r['size'])

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


def rel32_calls(src, dst):
    size = FUNCS[src]['size']
    code = original.data(src, size)
    return any(code[i] in (0xe8, 0xe9) and (src + i + 5 + struct.unpack_from('<i', code, i + 1)[0]) & 0xffffffff == dst
               for i in range(size - 4))


# Unit boundary checks: the vtables / strings / calls that anchor the three units.
assert original.vtable_class(0x810654)[0] == '.?AVBinder@CLuaHtmlView@@'
assert rel32_calls(0x42c3c0, 0x42c320)                      # ~Binder -> function0<bool>::operator=(bool(*)())
assert original.string(0x92eb08 + 8) == '.P6A_NXZ'          # type_info compared by manage 0x42c2c0
assert d(0x810658) == 0x42c2c0 and d(0x81065c) == 0x42c2b0  # stored vtable referenced by 0x42c320
assert 'ScriptContext' in evidence_of(0x42ced0).get('strings', [])
assert original.vtable_class(0x80ebd8)[0] == '.?AV?$CComObject@VCLuaFunction@@@ATL@@'
assert d(0x80ebd8 + 7 * 4) == 0x42e0c0 and d(0x80ebd8 + 8 * 4) == 0x42da40
assert rel32_calls(0x42e0c0, 0x42db20) and rel32_calls(0x42e0c0, 0x42d630)   # Invoke -> LuaArgs::push / ~vector
assert rel32_calls(0x42daa0, 0x42d980)                      # push_back (lua-args-trial) -> insert
assert 'CMainFrameV2' in evidence_of(0x42e4c0).get('strings', [])
assert original.vtable_class(0x810804)[0] == '.?AVMyXTPCommandBars@@'
assert original.vtable_class(0x810914)[0] == '.?AVCPatchedControlComboBox@@'
assert original.vtable_class(0x810a9c)[0] == '.?AVCWrapperView@@'
for a, b in zip(rows, rows[1:]):
    assert a + FUNCS[a]['size'] <= b, hex(a)

# Hand-classified open rows (address -> note); every open row of the first two units must be classified.
HTML_NOTES = {
    0x42c590: 'last_value<void> over the std::string signal slot_call_iterator (evidence name): string-signal '
              'instance shared with other units',
    0x42c630: 'PropBinding::PropBinding (luahtml-binder2008 pending: needs Instance::event_propertyChanged, '
              'proposal to the v8tree/Instance.h owner)',
    0x42c760: 'Binder property binding body that news PropBinding (0x20): luahtml-binder2008 family, not counted '
              'there',
    0x42c8c0: 'CLuaHtmlView::bindElement (CLuaHtmlView is not a CHtmlView subclass in the native header; '
              'app-leaves2008 proposal)',
    0x42ccd0: 'signal1<void, std::string>::operator() (evidence name), string-signal instance shared with other '
              'units',
    0x42ce50: 'SignalDescImpl<void(std::string)>::fire (evidence name), called by 0x4a1070 / 0x63aca0 / 0x64e660',
}
FUNC_NOTES = {
    0x42cf40: 'boost::any::holder<float>::type (boost template of a built-in type, many units): library',
    0x42cf50: 'boost::any::holder<float>::clone: library', 0x42cf80: 'boost::any::holder<int>::type: library',
    0x42cf90: 'boost::any::holder<int>::clone: library',
    0x42d950: 'jmp ~vector<Value>: the implicit LuaArgs destructor, reached only from EH unwind funclets; an '
              'implicit destructor cannot be instantiated explicitly and no helper function is added',
    0x42da40: 'CComObject<CLuaFunction> vtable slot 8 (E_NOTIMPL stub under AFX_MANAGE_STATE): CLuaFunction is not '
              'natively declared',
    0x42dda4: 'catch funclet of LuaArgs::push 0x42db20 ($LN96 in lua-args-trial): that owner\'s row',
    0x42de90: 'ServiceProvider::find<ScriptContext>() const (app-unit424-2008 not_exact: ~shared_ptr inlined)',
    0x42e0c0: 'CComObject<CLuaFunction>::Invoke (vtable slot 7): CLuaFunction is not natively declared',
    0x42e350: 'catch funclet of Invoke 0x42e0c0 ("CLuaFunction::Call failed, %s")',
    0x42e3d0: 'G3D::Color3uint8::Color3uint8() (evidence name): G3D header instance, library',
    0x42e3e0: 'CWnd::SendMessage-shaped MFC header instance (USER32 SendMessageA through m_hWnd +0x20), called by '
              '0x70c410: library',
    0x42e400: 'CCmdTarget::InternalRelease wrapper (MFC header instance): library',
    0x42e410: 'XTP header predicate (2 / 3 / 5), called by XTP code 0x6c2820 / 0x73b4e0: library',
    0x42e430: 'XTP / MFC frame header instance (vtable +0x198 call, +0x138 store), called by 0x42fe00: library',
    0x42e450: 'jmp CXTPMDIFrameWnd method 0x6e1950: XTP header instance, library',
}
unit_rows = []
for a in rows:
    entry = {'row': H(a), 'size': FUNCS[a]['size']}
    if a < HTML_HI:
        entry['unit'], notes = 'CLuaHtmlView', HTML_NOTES
    elif a < FUNC_HI:
        entry['unit'], notes = 'CLuaFunction', FUNC_NOTES
    else:
        entry['unit'], notes = 'CMainFrame', None
    if a in exact_ints:
        entry['kind'] = 'counted here'
    elif a in counted_elsewhere:
        entry['kind'] = 'counted elsewhere'
    elif notes is None:
        entry['kind'] = 'excluded (maintainer exclusion: CMainFrame / CWrapperView unit, mapped only)'
    else:
        assert a in notes, ('unclassified', hex(a))
        entry['kind'] = 'open'
        entry['note'] = notes[a]
    if a in counted_elsewhere:
        entry['counted'] = '%08x counted by %s' % (a, ', '.join(sorted(counted_elsewhere[a])))
        entry['row'] = 'see counted'
    elif a in exact_ints:
        entry['counted'] = '%08x counted here' % a
    entry['evidence'] = evidence_of(a)
    unit_rows.append(entry)
assert sum(1 for e in unit_rows if e['kind'] == 'counted here') == len(exact)

paths = [Path(__file__).resolve(), ROOT / 'rebuild/2008-06/tests/native_bind.py', BINDER_CPP, VALUE_CPP,
         HDR / 'reflection/type.h', HDR / 'reflection/descriptor.h',
         HDR / 'mfc-noinline-pcxstr/atlsimpstr.h', HDR / 'std-noinline-string/xstring',
         HDR / 'boost-function-pod-vtable/boost/function/function_template.hpp',
         HDR / 'boost-function-pod-vtable/boost/function/function_base.hpp']
n_html = sum(1 for a in rows if a < HTML_HI)
n_func = sum(1 for a in rows if HTML_HI <= a < FUNC_HI)
n_main = len(rows) - n_html - n_func
def block(lo, hi):
    sel = [a for a in rows if lo <= a < hi]
    return {'rows_in_range': len(sel), 'counted_here': sum(1 for a in sel if a in exact_ints),
            'counted_elsewhere': sum(1 for a in sel if a in counted_elsewhere)}
receipt = {
    'family': 'app unit 0042c000 (CLuaHtmlView unit tail, CLuaFunction unit, CMainFrame unit head): boost::function0 '
              '<bool(*)()> and std::vector<Reflection::Value> template rows',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'binder_templates': BINDER_PROFILE + flags(), 'value_vector': VALUE_PROFILE + flags()},
    'profile': 'document-swap flags; BinderTemplates with native-headers/mfc-noinline-pcxstr, std-noinline-string '
               'and boost-function-pod-vtable first (as record_native_luahtml_binder2008.py); ValueVector with '
               'mfc-noinline-pcxstr and std-noinline-string first (as native-classes/LuaArgs.cpp)',
    'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {'binder_templates': sha(binder_obj), 'value_vector': sha(value_obj)},
    'range': [H(LO), H(HI)],
    'range_rows': len(rows),
    'unit_map': {
        'CLuaHtmlView unit 0x42a630..0x42cecf (tail in range)': dict(block(LO, HTML_HI), kind='rbx', why=
            'CLuaHtmlView::Binder (vtable 0x810654; ~Binder 0x42c3c0 is the only caller of 0x42c320). Binder methods '
            'are counted by luahtml-binder2008 (it proves 0x42c2b0 / 0x42c2c0 / 0x42c320 as uncounted instances); '
            'the function0<bool(*)()> rows are counted here; the rest are string-signal instances shared with other '
            'units, PropBinding (pending there) and CLuaHtmlView::bindElement (not natively declared).'),
        'CLuaFunction unit 0x42ced0..0x42e45f': dict(block(HTML_HI, FUNC_HI), kind='rbx', why=
            'starts with Name::doDeclare<sScriptContext> 0x42ced0 ("ScriptContext"; app-unit424-2008 counts the '
            'ScriptContext templates); CComObject<CLuaFunction> (vtable 0x80ebd8, Invoke 0x42e0c0 calls LuaArgs::push '
            '0x42db20 and ~vector<Value> 0x42d630). The vector<Value> instances are counted here; holder<float> / '
            'holder<int> and the MFC / XTP / G3D header instances are library; CLuaFunction is not natively '
            'declared.'),
        'CMainFrame unit 0x42e460..0x42ffff (head in range)': dict(block(FUNC_HI, HI), kind='excluded', why=
            'MainFrm.cpp: CMainFrame ("CMainFrameV2"), MyXTPCommandBars (0x810804), CPatchedControlComboBox '
            '(0x810914), CWrapperView (0x810a9c) and the XTP control overrides. Maintainer exclusion (CMainFrame / '
            'CWrapperView): mapped only; rows counted by patched-control-combo-box / wrapper-view / appearance stay '
            'theirs.'),
    },
    'library_rows': 'boost::any holder<float> / holder<int> 0x42cf40..0x42cf90, G3D Color3uint8() 0x42e3d0 and the '
                    'MFC / XTP header instances 0x42e3e0..0x42e450; no separately compiled library unit lies in the '
                    'range',
    'rows': unit_rows,
    'methods': results,
    # instance rows are not counted: their addresses are written 0x-prefixed (never as quoted bare addresses)
    'instances': {k: dict(v, address='0x' + v['address']) for k, v in INSTANCES.items()},
    'vtables': 'none emitted (the boost::function stored vtable 0x810658 is verified as a data instance)',
    'counted_elsewhere': ['%08x counted by %s' % (a, ', '.join(sorted(v))) for a, v in sorted(counted_elsewhere.items())],
    'not_exact': {},
    'proposals': [
        'luahtml-binder2008 owner (no header change): 0x42c2b0 / 0x42c2c0 / 0x42c320 (+ funclet 0x42c391) are '
        'counted here; keep them as uncounted instances there so no row is counted twice.',
        'CLuaFunction (no native header yet): CComObject<CLuaFunction> vtable 0x80ebd8 (12 bases: CLuaFunction, '
        'CComObjectRootEx<CComSingleThreadModel> +8, CComCoClass<CLuaFunction, &CLSID_LuaFunction> +0xc, '
        'ISupportErrorInfoImpl<&IID_ILuaFunction>); Invoke 0x42e0c0 reads the ScriptContext shared_ptr at +8 / +0xc, '
        'the callback at +0x10 and the security identity at +0x34. A future owner can declare it in a separate header.',
    ],
    'rejected': [],
    'shadowing': 'none (no new header; reflection/type.h and the profile headers are included read-only)',
    'exact_function_rows': exact,
    'scope': 'Inactive. Exact rows with every target verified; no pending build; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native app unit42c: %d rows mapped (%d CLuaHtmlView, %d CLuaFunction, %d CMainFrame), %d exact (%s), '
      '%d counted elsewhere, %d instances' % (len(rows), n_html, n_func, n_main, len(exact), ' '.join(exact),
                                             len(counted_elsewhere), len(INSTANCES)))
