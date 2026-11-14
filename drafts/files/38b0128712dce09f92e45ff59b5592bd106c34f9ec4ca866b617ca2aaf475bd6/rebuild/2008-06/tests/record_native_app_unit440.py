"""Record the 2008-06 application range 00440000..00444000 (inactive): unit map plus the reflection-metadata rows.

Step 1, unit map (boundary evidence asserted below and written to the receipt's unit_map):
  * ..0x4428ff  the Studio property grid unit CPropGrid.cpp (starts below the range at 0x437a20; app-unit438): the
                XItem<T> applyValue / OnValueChanged editor rows, the SoundService / SoundChannel Creatable instances
                its SoundItem uses, the CPropGrid message map accessor 0x440d20 (returns 0x8145dc, the CPropGrid
                message map), the editor factory CPropGrid::addProperty 0x440e30 (CPropGrid vtable 0x81564c slot 90),
                SoundItem / TextureItem browse, the SelectionGroup map instances, SelectionGroup::add,
                CPropGrid::addInstance and the CSelectionPropGrid bodies (onEvent 0x442490, setSelection 0x442650);
  * 0x442900..0x442c4f  the CDataModelPropGrid unit: update 0x442900 and the CPropGrid constructor / destructor /
                deleting destructor COMDATs it emits (0x442b20 / 0x442a30 / 0x442c30, adjustor 0x442b10), all
                storing the CPropGrid vtable 0x81564c;
  * 0x442c50..0x442f8f  RBXImage (counted by app-leaves2008);
  * 0x442f90..  the reflection-metadata unit (RTTI .?AV...@Metadata@Reflection@RBX@@, "ReflectionMetadata" class
                names): askAddChild bodies, the FactoryProduct<Reflection> constructor / destructor / adjustor thunks,
                Classes::lookup, Reflection::lookup, the metadata property descriptor instances (TypedPropertyDescriptor
                / BoundPropGetSet), findFirstChildOfType<C>, the member lookups, then the MergeBinder COMDATs it
                instantiates for Reflection::load (misc-leaves) from 0x443c60; it runs past the range to 0x44521f.
Rows other receipts count (top-level exact_function_rows rule; receipts without it: exact_addresses /
exact_unique_addresses / exact_distinct_addresses, else the rows marked exact) are written as 'ADDR counted by RECEIPT'
text. Every other address of a row not counted here is written 0x-prefixed (local_backpack / viewnew_brick_build /
viewnew_part_mesh read any quoted bare address as counted).

Step 2, recovery of the reflection-metadata rows against the read-only reflection/Metadata.h, v8tree/Instance.h and
reflection/reflection.h (VS2008 RTM 21022, document-swap flags, /fp:fast):
  * 'lookup': a generated unit that includes the committed native-classes/MetadataClassesLookup.cpp and
    MetadataReflectionLookup.cpp (unchanged) and then native-classes/AppUnit440Metadata.cpp, as one translation unit
    like the original, so Reflection::lookup(const ClassDescriptor&, bool) and Classes::lookup are visible (and inlined)
    in the member lookups;
  * 'classes' / 'register' / 'containers': the committed MetadataClassesLifetime.cpp, MetadataClassesRegister.cpp and
    MetadataContainersLifetime.cpp compiled unchanged, for the askAddChild bodies;
  * 'selgroup' / 'instances' / 'selevents' / 'selection' / 'dmupdate': the CPropGrid-unit owners' committed
    SelectionGroup.cpp, CPropGridInstances.cpp, CSelectionPropGridEvents.cpp, CSelectionPropGridSelection.cpp and
    CDataModelPropGridUpdate.cpp compiled unchanged with the property-grid probe flags (+ /fp:fast), for
    SelectionGroup::add, CPropGrid::addInstance, CSelectionPropGrid::onEvent / setSelection, CDataModelPropGrid::update
    and the five map<const ClassDescriptor*, vector<shared_ptr<Instance>>> instances only this unit calls (those
    sources' probe receipts list them relocation-masked, without exact_function_rows); CSelectionPropGrid.cpp /
    CDataModelPropGrid.cpp are compiled only for their vtables (slot checks).
A row counts only if its bytes match exactly and every REL32 / DIR32 is bound to the address the original instruction
uses and verified (imports by export name, type descriptors by RTTI name, own rows, EXTERNAL bindings other recorders
prove or evidence names), one address per symbol. Each counted virtual is slot-checked against the original vtables
whose RTTI names its class, from the objects built with the current headers (no pending build).
Bodies a row calls that the same object emits are proven by their bytes at the called address and their own targets
(recursively; 'helper_bodies_not_counted'). NATIVE_APP_UNIT440_DISCOVER=1 lists unbound targets instead of asserting.
Writes work/2008-06/shared-layouts/app-unit440-working.json.
"""
import glob
import json
import os
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_bind as nb  # noqa: E402
from native_bind import ROOT, LOCAL_EH, Original, match, rebuild, sha  # noqa: E402

R = ROOT / 'rebuild/2008-06'
HDR = R / 'native-headers'
NC = R / 'native-classes'
OUT = R / 'out/appunit440'
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit440-working.json'
LO, HI = 0x440000, 0x444000
H = lambda a: '0x%08x' % a
TC = rebuild.toolchain(21022)
UNIT_CPP = NC / 'AppUnit440Metadata.cpp'
OWNER = {
    'classes_lookup': NC / 'MetadataClassesLookup.cpp',
    'reflection_lookup': NC / 'MetadataReflectionLookup.cpp',
    'classes': NC / 'MetadataClassesLifetime.cpp',
    'register': NC / 'MetadataClassesRegister.cpp',
    'containers': NC / 'MetadataContainersLifetime.cpp',
}
original = Original()


def d(address):
    return struct.unpack('<I', original.data(address, 4))[0]


FUNCS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        row = json.loads(line)
        FUNCS[int(row['addr'], 16)] = row
rows = sorted(a for a in FUNCS if LO <= a < HI)
EVIDENCE = json.loads((R / 'offline/evidence.json').read_text())['names']


PG_FLAGS = json.loads((ROOT / 'work/2008-06/shared-layouts/property-grid-working-probe.json').read_text())['flags']


def compile_obj(name, src, base=None):
    OUT.mkdir(parents=True, exist_ok=True)
    obj = OUT / (name + '.obj')
    flags = (base or nb.flags()) + ['/fp:fast', '/Fo' + str(obj), str(src)]
    code, log = rebuild.run(TC, 'cl', flags, OUT)
    assert code == 0, log[-3000:]
    return obj


combined = OUT / 'AppUnit440MetadataCombined.cpp'
OUT.mkdir(parents=True, exist_ok=True)
combined.write_text(''.join('#include "%s"\n' % p.as_posix() for p in (
    OWNER['classes_lookup'], OWNER['reflection_lookup'], UNIT_CPP)))
OBJ = {
    'lookup': compile_obj('AppUnit440MetadataCombined', combined),
    'classes': compile_obj('AppUnit440_MetadataClassesLifetime', OWNER['classes']),
    'register': compile_obj('AppUnit440_MetadataClassesRegister', OWNER['register']),
    'containers': compile_obj('AppUnit440_MetadataContainersLifetime', OWNER['containers']),
}
PG = {'selgroup': 'SelectionGroup', 'instances': 'CPropGridInstances', 'selevents': 'CSelectionPropGridEvents',
      'selection': 'CSelectionPropGridSelection', 'dmupdate': 'CDataModelPropGridUpdate'}
for _k, _n in PG.items():
    OWNER[_k] = NC / (_n + '.cpp')
    OBJ[_k] = compile_obj('AppUnit440_' + _n, OWNER[_k], PG_FLAGS)
# vtable-only objects: the owners' CSelectionPropGrid.cpp / CDataModelPropGrid.cpp emit the CSelectionPropGrid /
# CDataModelPropGrid vtables (current headers) used to slot-check onEvent 0x442490 and update 0x442900.
VT_OBJ = {}
for _k, _n in (('vt_selection', 'CSelectionPropGrid'), ('vt_datamodel', 'CDataModelPropGrid')):
    OWNER[_k] = NC / (_n + '.cpp')
    VT_OBJ[_k] = compile_obj('AppUnit440_' + _n, OWNER[_k], PG_FLAGS)
BODIES = {k: {n: (b, r) for n, b, r in match.coff_functions(Path(o).read_bytes())} for k, o in OBJ.items()}

# ---- rows counted here ----------------------------------------------------------------------------------------
MD = 'Metadata@Reflection@RBX@@'
FFC = '??$findFirstChildOfType@V%s@' + MD + '@Instance@RBX@@QBEPAV%s@Metadata@Reflection@1@XZ'
RL = '?lookup@Reflection@Metadata@RBX@@QBEPAVMember@213@ABV%s@13@@Z'
ROWS = [
    (0x00442fc0, 'classes', '?askAddChild@Classes@' + MD + 'MBE_NPBVInstance@4@@Z'),
    (0x00442ff0, 'register', '?askAddChild@Class@' + MD + 'MBE_NPBVInstance@4@@Z'),
    (0x00443020, 'containers', '?askAddChild@Members@' + MD + 'MBE_NPBVInstance@4@@Z'),
    (0x00443140, 'lookup', '?lookup@Classes@' + MD + 'QBEPAVClass@234@ABVClassDescriptor@34@_N@Z'),
    (0x00443210, 'lookup', '?lookup@Reflection@Metadata@RBX@@QBEPAVClass@213@ABVClassDescriptor@13@_N@Z'),
    (0x004436e0, 'lookup', FFC % ('Classes', 'Classes')),
    (0x00443780, 'lookup', FFC % ('Properties', 'Properties')),
    (0x00443820, 'lookup', FFC % ('Functions', 'Functions')),
    (0x004438c0, 'lookup', FFC % ('Events', 'Events')),
    (0x00443ab0, 'lookup', RL % 'PropertyDescriptor'),
    (0x00443b00, 'lookup', RL % 'FunctionDescriptor'),
    (0x00443b50, 'lookup', RL % 'SignalDescriptor'),
    (0x00442350, 'selgroup', '?add@SelectionGroup@RBX@@QAEXPAVInstance@2@@Z'),
    (0x004423f0, 'instances', '?addInstance@CPropGrid@@QAEXV?$shared_ptr@VInstance@RBX@@@boost@@@Z'),
    (0x00442490, 'selevents', '?onEvent@CSelectionPropGrid@@UAEXPBVSelection@RBX@@VSelectionChanged@3@@Z'),
    (0x00442650, 'selection', '?setSelection@CSelectionPropGrid@@QAEXPAVSelection@RBX@@@Z'),
    (0x00442900, 'dmupdate', '?update@CDataModelPropGrid@@UAEXV?$shared_ptr@VDataModel@RBX@@@boost@@0@Z'),
]
# The SelectionGroup map<const ClassDescriptor*, vector<shared_ptr<Instance>>> instances in the range: every caller
# of each row lies inside the CPropGrid unit (0x440640 <- 0x4417f0 / 0x441f20; 0x4417f0 <- 0x441f20; 0x441f20 <-
# 0x442140; 0x442140 <- SelectionGroup::add 0x442350; 0x442100 <- itself / 0x442270 / setSelection 0x442650),
# asserted below, so they are this unit's own template instances. (prefix, required substring) -> unique symbol.
MAPT = '?$_Tree@V?$_Tmap_traits@PBVClassDescriptor@Reflection@RBX@@V?$vector@V?$shared_ptr@VInstance@RBX@@@'
MAP_ROWS = [
    (0x00440640, 'selgroup', ('?_Insert@' + MAPT, '')),
    (0x004417f0, 'selgroup', ('?insert@' + MAPT, '@std@@_N@2@ABU?$pair@')),
    (0x00441f20, 'selgroup', ('?insert@' + MAPT, 'QAE?AViterator@12@Vconst_iterator@12@')),
    (0x00442100, 'selection', ('?_Erase@' + MAPT, '')),
    (0x00442140, 'selgroup', ('??A?$map@PBVClassDescriptor@Reflection@RBX@@V?$vector@V?$shared_ptr@VInstance@RBX@@@', '')),
]
MAP_CALLERS = {0x440640: {0x4417f0, 0x441f20}, 0x4417f0: {0x441f20}, 0x441f20: {0x442140}, 0x442140: {0x442350},
               0x442100: {0x442100, 0x442270, 0x442650}}
for address, build, (prefix, part) in MAP_ROWS:
    hits = [n for n in BODIES[build] if n.startswith(prefix) and part in n]
    assert len(hits) == 1, (hex(address), hits)
    ROWS.append((address, build, hits[0]))
    assert {int(c, 16) for c in FUNCS[address]['callers']} == MAP_CALLERS[address], hex(address)
    assert all(0x437a20 <= c < 0x442900 for c in MAP_CALLERS[address]), hex(address)
own = {}
for address, build, symbol in ROWS:
    assert symbol in BODIES[build], ('not emitted', build, symbol)
    assert own.setdefault(symbol, address) == address, symbol

EXTERNAL = {
    # boost::recursive_mutex lock / unlock (record_native_selection_grid.py / record_native_app_unit438.py bindings)
    '?do_lock@recursive_mutex@boost@@AAEXXZ': 0x00563090,
    '?do_unlock@recursive_mutex@boost@@AAEXXZ': 0x005630e0,
    # CPropGrid::removeInstance: counted by app-unit438 (asserted below)
    '?removeInstance@CPropGrid@@QAEXV?$shared_ptr@VInstance@RBX@@@boost@@@Z': 0x00439cd0,
    # ServiceProvider::create<Selection>() (record_native_app_unit580.py external binding, JoinCommand::isEnabled)
    '??$create@VSelection@RBX@@@ServiceProvider@RBX@@QBEPAVSelection@1@XZ': 0x004153b0,
    # std exception throw infos (record_native_app_unit438.py bindings; types asserted below)
    '__TI2?AVbad_alloc@std@@': 0x008d07d8,
    '__TI3?AVlength_error@std@@': 0x008d0cc0,
    # Instance::findFirstChildByName (evidence name; bound the same way by the insert-object-dialog / class-tree
    # receipts that call it)
    '?findFirstChildByName@Instance@RBX@@QBEPAV12@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z':
        0x00557950,
}


def throw_info_type(address):
    array = d(address + 12)
    return original.string(d(d(array + 4) + 4) + 8)


assert throw_info_type(0x8d07d8) == '.?AVbad_alloc@std@@'
assert throw_info_type(0x8d0cc0) == '.?AVlength_error@std@@'
assert '00439cd0' in json.loads((ROOT / 'work/2008-06/shared-layouts/app-unit438-working.json').read_text())[
    'exact_function_rows']


def norm(s):
    # class-name template arguments: the binary's const char* const (3QBDB) vs the headers' char arrays (3PADA)
    return s.replace('3QBDB', '3PADA').replace('3PBDB', '3PADA')


def evidence_symbol(value):
    return EVIDENCE.get('%08x' % value, {}).get('symbol')


binding = {}


def bind(symbol, value, where):
    prev = binding.setdefault(symbol, (value, where))
    assert prev[0] == value, ('one address per symbol', symbol, hex(prev[0]), prev[1], hex(value), where)


DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT440_DISCOVER'))
UNBOUND = []
INSTANCES = {}


def classify(build, symbol, value, raw, sections, definitions, where):
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol.startswith('??_R0') and symbol.endswith('@8'):
        rtti = original.string(value + 8)
        assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
        return 'RTTI %s' % rtti
    if symbol.startswith('??_7'):
        rtti, at = original.vtable_class(value)
        assert norm(rtti) == norm('.?AV' + symbol[4:symbol.index('@@6B') + 2]), (where, symbol, hex(value), rtti)
        return 'vtable RTTI %s offset %#x' % (rtti, at)
    if symbol.startswith('??_C@'):
        pos, at = definitions[symbol]
        literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
        assert original.data(value, len(literal)) == literal, (where, symbol, hex(value))
        return 'literal %r' % literal[:-1].decode()
    if symbol in own:
        assert own[symbol] == value, (where, symbol, hex(value), hex(own[symbol]))
        return 'own row'
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
        return 'external' + (' (evidence name)' if evidence_symbol(value) == symbol else '')
    if evidence_symbol(value) == symbol:
        return 'evidence name'
    if symbol in BODIES[build]:
        return instance(build, symbol, value, where)
    return None


def instance(build, symbol, value, where):
    """A body this build emits, proven by its bytes at the referenced address and by its own targets (not counted)."""
    key = (symbol, value)
    if symbol in INSTANCES:
        assert INSTANCES[symbol]['address'] == H(value), (where, symbol, hex(value), INSTANCES[symbol]['address'])
        return 'helper body exact at the bound address, targets verified (not counted)'
    INSTANCES[symbol] = {'address': H(value), 'pending': True}
    row = verify_body(build, value, symbol, counted=False)
    if row is None:
        del INSTANCES[symbol]
        return None
    row['address'] = H(value)
    INSTANCES[symbol] = row
    return 'helper body exact at the bound address, targets verified (not counted)'


def verify_body(build, address, name, counted=True):
    obj = OBJ[build]
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    body, refs = BODIES[build][name]
    try:
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
    except SystemExit:
        target, target_refs = b'', []
    if counted:
        assert len(body) == len(target) == FUNCS[address]['size'] or DISCOVER, (name, hex(address), len(body), len(target))
    elif len(body) != len(target):
        target, target_refs = original.data(address, len(body)), []
    if not match.exact_match(target, target_refs, body, refs):
        if counted:
            assert DISCOVER, ('not exact', name, hex(address))
            UNBOUND.append(('NOT EXACT', hex(address), name[:90], len(body), len(target)))
        return None
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
        where = '%08x+%#x' % (address, offset)
        how = classify(build, symbol, value, raw, sections, definitions, where)
        if how is None:
            assert DISCOVER, ('unbound relocation', where, symbol, hex(value))
            UNBOUND.append(('UNBOUND', where, symbol[:110], hex(value), (evidence_symbol(value) or '')[:80]))
            continue
        bind(symbol, value, where)
        verified[symbol] = '%s (%s)' % (H(value), how)
    return {'address': '%08x' % address if counted else H(address), 'symbol': name, 'size': len(body),
            'exact': counted, 'build': build, 'verified_targets': verified, 'local_eh': sorted(local)}


def verify(build, specs):
    return [r for r in (verify_body(build, a, n) for a, n in specs) if r is not None]


results = []
for build in OBJ:
    results += verify(build, [(a, s) for a, b, s in ROWS if b == build])
if DISCOVER:
    for u in UNBOUND:
        print(*u)
    for k, v in INSTANCES.items():
        print('INSTANCE', v['address'], k[:120])
    sys.exit(0)
exact = sorted({r['address'] for r in results})
exact_ints = {int(a, 16) for a in exact}

# Identity of the four findFirstChildOfType<C> rows: each dynamic_casts to the RTTI of its own C (already bound above
# by name; asserted here so the mapping is explicit).
for a, c in ((0x4436e0, 'Classes'), (0x443780, 'Properties'), (0x443820, 'Functions'), (0x4438c0, 'Events')):
    r = [x for x in results if x['address'] == '%08x' % a][0]
    assert any(k == '??_R0?AV%s@%s@8' % (c, MD) for k in r['verified_targets']), (hex(a), c)
# The member lookups call their own findFirstChildOfType row (0x443ab0 -> 0x443780 Properties, 0x443b00 -> 0x443820
# Functions, 0x443b50 -> 0x4438c0 Events).
for a, c in ((0x443ab0, 0x443780), (0x443b00, 0x443820), (0x443b50, 0x4438c0)):
    r = [x for x in results if x['address'] == '%08x' % a][0]
    assert any(v.startswith(H(c)) for v in r['verified_targets'].values()), hex(a)

# ---- vtable slots of the counted virtuals (objects built from the current headers) ----------------------------------
RDATA = [s for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.rdata'][0]
RDATA_VA = original.image + RDATA.VirtualAddress
RDATA_BYTES = RDATA.get_data()


def rdata_refs(value):
    pat = struct.pack('<I', value)
    return [RDATA_VA + m.start() for m in re.finditer(re.escape(pat), RDATA_BYTES) if m.start() % 4 == 0]


def compiled_vtables(obj):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, starts = match._coff_data_index(raw)
    out = {}
    for name, (start, sec) in definitions.items():
        if not name.startswith('??_7'):
            continue
        table = sections[sec]
        end = min([x for x in starts.get(sec + 1, ()) if x > start] + [table[3]])
        slots = {}
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            if start <= offset < end:
                slots[(offset - start) // 4] = symbols[index][0]
        out[name] = slots
    return out


SLOT_CHECKS = {}
ALL_VTABLES = {}
for _o in list(OBJ.values()) + list(VT_OBJ.values()):
    for _vt, _slots in compiled_vtables(_o).items():
        ALL_VTABLES.setdefault(_vt, _slots)
for r in results:
    compiled = ALL_VTABLES
    address = int(r['address'], 16)
    places = [(vt, i) for vt, slots in compiled.items() for i, s in slots.items() if s == r['symbol']]
    hits = []
    for vt, i in places:
        cls = vt[4:vt.index('@@6B') + 2]
        found = []
        for ref in rdata_refs(address):
            try:
                rtti, at = original.vtable_class(ref - 4 * i)
            except Exception:
                continue
            if rtti and norm(rtti) == norm('.?AV' + cls):
                found.append('%s (%s +%#x) slot %d' % (H(ref - 4 * i), rtti, at, i))
        assert found, ('compiled vtable slot not found in an original vtable of the class', r['address'], vt, i)
        hits += found
    if places:
        r['vtable_slots'] = hits
        SLOT_CHECKS[r['address']] = len(hits)
assert set(SLOT_CHECKS) == {'00442fc0', '00442ff0', '00443020', '00442490', '00442900'}, SLOT_CHECKS


# ---- step 1: what other receipts count -----------------------------------------------------------------------------
def addr_of(x):
    if isinstance(x, dict):
        x = x.get('address') or x.get('addr') or ''
    m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', str(x))
    return int(m.group(1), 16) if m else None


def counted_elsewhere():
    out = {}
    for f in sorted(glob.glob(str(ROOT / 'work/2008-06/shared-layouts/*.json'))):
        if Path(f).name == RECEIPT.name:
            continue
        try:
            doc = json.loads(Path(f).read_text())
        except Exception:
            continue
        if not isinstance(doc, dict):
            continue
        got = None
        for key in ('exact_function_rows', 'exact_addresses', 'exact_unique_addresses', 'exact_distinct_addresses'):
            if isinstance(doc.get(key), (list, dict)):
                got = list(doc[key])
                break
        if got is None:
            got = []

            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        got.append(o['address'])
                    else:
                        for v in o.values():
                            walk(v)
            walk(doc.get('methods', []))
        for x in got:
            v = addr_of(x)
            if v is not None and LO <= v < HI:
                out.setdefault(v, set()).add(Path(f).name[:-5])
    return out


elsewhere = counted_elsewhere()
double = sorted(exact_ints & set(elsewhere))
assert not double, ('counted elsewhere too', [H(a) for a in double])


# ---- step 1: unit map and per-row evidence -------------------------------------------------------------------------
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
    name = evidence_symbol(a)
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


def stores_vtable(a, rtti):
    body = original.data(a, FUNCS[a]['size'])
    for i in range(len(body) - 3):
        v = struct.unpack_from('<I', body, i)[0]
        if rtti_of(v) == rtti:
            return True
    return False


# Boundary anchors.
assert d(0x81564c + 90 * 4) == 0x440e30                                       # CPropGrid slot 90 = addProperty
assert original.vtable_class(0x81564c)[0] == '.?AVCPropGrid@@'
assert original.data(0x440d20, 6) == b'\xb8' + struct.pack('<I', 0x8145dc) + b'\xc3'   # CPropGrid message map
assert struct.unpack('<2I', original.data(0x8145dc, 8)) == (0x6fbf70, 0x8145e8)
for a in (0x442a30, 0x442b20):
    assert stores_vtable(a, '.?AVCPropGrid@@'), hex(a)                        # CPropGrid dtor / ctor COMDATs
assert original.data(0x442b10, 11) == b'\x81\xe9\x88\x01\x00\x00\xe9' + struct.pack('<i', 0x442c30 - 0x442b1b)
assert stores_vtable(0x443050, '.?AV?$FactoryProduct@VReflection@Metadata@1RBX@@VInstance@3@$1?sReflection@213@3PADA@RBX@@')
assert stores_vtable(0x4430b0, '.?AV?$FactoryProduct@VReflection@Metadata@1RBX@@VInstance@3@$1?sReflection@213@3PADA@RBX@@')
for a, t in ((0x442f90, 0x92a950), (0x442fc0, 0x92ac4c), (0x442ff0, 0x929e58), (0x443020, 0x92ac78)):
    assert original.data(a + 7, 4) == struct.pack('<I', t), hex(a)            # askAddChild dynamic_cast targets
assert original.string(0x92a950 + 8) == '.?AVClasses@' + MD
for a in rows:
    assert a + FUNCS[a]['size'] <= ([b for b in rows if b > a] + [HI + 0x10000])[0], hex(a)

BLOCKS = [
    (LO, 0x442900, 'CPropGrid.cpp unit (Studio property grid; app-unit438, starts below the range)'),
    (0x442900, 0x442c50, 'CDataModelPropGrid unit (update; CPropGrid ctor / dtor / deleting dtor COMDATs)'),
    (0x442c50, 0x442f90, 'RBXImage (app-leaves2008)'),
    (0x442f90, HI, 'reflection-metadata unit (Metadata.cpp; continues past the range to 0x44521f)'),
]

NOTES = {
    0x4402b4: 'catch funclet of a CPropGrid.cpp editor row (AfxMessageBox(e.what()), returns into 0x4402a1): '
              'funclet of 0x43ff70 XItem applyValue (propgrid-items2008 unresolved slot); open',
    0x4402d0: 'XItem<int, Enum>::applyValue (propgrid-items2008 unresolved slot; template body owned by '
              'PropertyGridItems.h); not attempted',
    0x440621: 'catch funclet of 0x4402d0 (AfxMessageBox(e.what())); open with its parent',
    0x440640: 'map<const ClassDescriptor*, vector<shared_ptr<Instance>>>::_Insert (SelectionGroup map instance, '
              'masked-exact with SelectionGroup.cpp); not attempted (CPropGrid unit owner)',
    0x4408d0: 'shared_ptr<Soundscape::SoundService>(p, Creatable<Instance>::Deleter) (app-unit580 support row, exact '
              'there, not counted); left to the Soundscape owner',
    0x440980: 'Creatable<Instance>::create<Soundscape::SoundService>() (app-unit580 support row); left to the '
              'Soundscape owner',
    0x440a00: 'FactoryProduct<SoundService>::Creator::create (Soundscape Creatable instance); left to the Soundscape owner',
    0x440b40: 'shared_ptr<Soundscape::SoundChannel>(p, Deleter) (Soundscape Creatable instance); Soundscape owner',
    0x440bf0: 'create<Soundscape::SoundChannel>() (Soundscape Creatable instance); Soundscape owner',
    0x440c70: 'FactoryProduct<SoundChannel>::Creator::create (Soundscape Creatable instance); Soundscape owner',
    0x440d20: 'CPropGrid::GetMessageMap (mov eax, 0x8145dc; ret; identical-code folded with other 6-byte returns); '
              'CPropGrid owner (selection-grid probe); not attempted',
    0x440e30: 'CPropGrid::addProperty editor factory (CPropGrid vtable slot 90; propgrid-items2008 layout source); '
              'not attempted (CPropGrid owner)',
    0x441360: 'XItem<bool>::OnValueChanged (PropertyGridItems.h template; masked-exact in app-unit438 build); '
              'propgrid-items owner',
    0x4413e0: 'XItem<float>::OnValueChanged (propgrid-items2008 pending-build-only proposal)',
    0x441460: 'XItem<int>::OnValueChanged (propgrid-items2008 pending-build-only proposal)',
    0x4414e0: 'XItem<Color3>::OnValueChanged (propgrid-items owner)',
    0x441560: 'XItem<BrickColor>::OnValueChanged (propgrid-items2008 pending-build-only)',
    0x4415d0: 'XItem<std::string>::OnValueChanged (propgrid-items owner)',
    0x441660: 'XItem<Vector3>::OnValueChanged (propgrid-items2008 pending-build-only)',
    0x4416e0: 'XItem<TextureId / SoundId>::OnValueChanged (propgrid-items2008 pending-build-only)',
    0x4417f0: 'map<const ClassDescriptor*, vector<shared_ptr<Instance>>>::insert (SelectionGroup instance); not attempted',
    0x4418e0: 'CPropGrid.cpp editor row (Espeon analog); not attempted',
    0x441bc0: 'SoundItem::browse (propgrid-items2008 declared, not attempted)',
    0x441d60: 'TextureItem::browse (propgrid-items2008 declared, not attempted)',
    0x441f20: 'map<const ClassDescriptor*, vector<...>>::insert(hint) (SelectionGroup instance); not attempted',
    0x442100: 'map<const ClassDescriptor*, vector<...>>::_Erase (SelectionGroup instance); not attempted',
    0x442140: 'map<const ClassDescriptor*, vector<...>>::operator[] (SelectionGroup instance); not attempted',
    0x442270: 'set<CPropGrid::Item*>::erase (ICF-shared std instance); not attempted',
    0x442350: 'SelectionGroup::add (selection-grid probe, masked-exact with SelectionGroup.cpp); CPropGrid owner',
    0x4423f0: 'CPropGrid::addInstance (selection-grid probe, masked-exact with CPropGridInstances.cpp); CPropGrid owner',
    0x442490: 'CSelectionPropGrid::onEvent(Selection, SelectionChanged) (selection-grid probe); CPropGrid owner',
    0x4425e0: 'set<CPropGrid::Item*> / _Tree destructor (ICF-shared std instance, also called by ~CPropGrid 0x442a30)',
    0x442650: 'CSelectionPropGrid::setSelection (selection-grid probe); CPropGrid owner',
    0x442900: 'CDataModelPropGrid::update (pane-callbacks probe, masked-exact with CDataModelPropGridUpdate.cpp)',
    0x442a30: 'CPropGrid::~CPropGrid COMDAT (stores CPropGrid vtable 0x81564c; property-grid probe)',
    0x442b10: 'CPropGrid deleting-destructor adjustor thunk (sub ecx, 0x188; jmp 0x442c30)',
    0x442b20: 'CPropGrid::CPropGrid COMDAT (stores CPropGrid vtable 0x81564c; property-grid probe)',
    0x442c30: 'CPropGrid scalar deleting destructor (calls ~CPropGrid 0x442a30)',
    0x442cd0: 'iterator _Mynode / _Checked_iterator_base 4-byte ICF-shared std leaf (RBXImage neighbour); shared',
    0x442f90: 'Reflection::askAddChild (dynamic_cast to Classes 0x92a950): bytes exact with the committed '
              'MetadataReflectionLifetime.cpp, but blocked: reflection/Metadata.h declares the class as '
              'RBX::Metadata::Reflection while the original RTTI names .?AVReflection@Metadata@Reflection@RBX@@ (and '
              'FactoryProduct<RBX::Reflection::Metadata::Reflection>), so its vtable slot cannot be proven (proposal)',
    0x443050: 'FactoryProduct<Reflection>::~FactoryProduct (stores the FactoryProduct<Reflection> vtables 0x815854.., '
              'jmp ~Instance): blocked by the Reflection namespace (proposal)',
    0x4430b0: 'FactoryProduct<Reflection>::FactoryProduct (Instance() then the same vtables): blocked by the Reflection '
              'namespace (proposal)',
    0x443110: 'adjustor thunk (sub ecx, 0x24) to the Reflection deleting destructor 0x4449d0: blocked (namespace)',
    0x443120: 'adjustor thunk (sub ecx, 0x64) to 0x4449d0: blocked (namespace)',
    0x443130: 'adjustor thunk (sub ecx, 0x84) to 0x4449d0: blocked (namespace)',
    0x443190: 'BoundPropGetSet<C, bool>::getValue (ICF-shared reflection instance; effects / team support row); the '
              'metadata property descriptors (static initializer 0x444680..) are not declared; not attempted',
    0x4431b0: 'BoundPropGetSet<Item, std::string>::getValue; metadata property descriptors undeclared; not attempted',
    0x4431f0: 'BoundPropGetSet<C, int>::getValue (ICF-shared; effects support row); not attempted',
    0x443230: 'TypedPropertyDescriptor<std::string> constructor (shared reflection instance, 11 callers in other units; '
              'hopper-family support row)',
    0x4432a0: 'TypedPropertyDescriptor<int> constructor (shared reflection instance, 17 callers; hopper-family / mouse '
              'support row)',
    0x443310: 'TypedPropertyDescriptor GetSet vcall forwarder (shared reflection instance; contact-unit2008 evidence)',
    0x443320: 'auto_ptr<GetSet> assignment (shared reflection instance; app-unit564 helper body)',
    0x443370: 'boost::any_cast<T> helper (bad_cast throw; shared reflection instance); not attempted',
    0x443490: 'TypedPropertyDescriptor<std::string>::equalValues (hopper-family support row)',
    0x443530: 'TypedPropertyDescriptor<int>::equalValues (hopper-family / mouse support row)',
    0x443570: 'std::auto_ptr<XmlElement>::~auto_ptr (Reflection::load local; masked-exact with the committed '
              'MetadataReflectionLoad.cpp); not attempted (load owner)',
    0x443590: 'Reflection::Value assignment from std::string (shared reflection instance; app-unit414 support)',
    0x4435d0: 'TypedPropertyDescriptor<std::string>::getValue into Value (shared; app-unit414 support)',
    0x443660: 'FactoryProduct<Reflection>::getClassName (Name::declare<sReflection> call_once 0x557330): blocked by '
              'the Reflection namespace (proposal)',
    0x443680: 'TypedPropertyDescriptor<int>::getValue into Value (shared reflection instance); not attempted',
    0x443ba0: 'TypedPropertyDescriptor<std::string>::setStringValue (shared reflection instance); not attempted',
    0x443c10: 'TypedPropertyDescriptor<int>::setStringValue (shared reflection instance); not attempted',
    0x443cf0: 'std::vector<MergeBinder::IDREFItem>::~vector (misc-leaves not_exact: not emitted there); masked-exact '
              'with MergeBinder.cpp; MergeBinder owner',
}


unit_rows = []
for a in rows:
    block = [n for lo, hi, n in BLOCKS if lo <= a < hi]
    assert len(block) == 1, hex(a)
    entry = {'row': H(a), 'size': FUNCS[a]['size'], 'unit': block[0]}
    if a in exact_ints:
        entry['kind'] = 'counted here'
        entry['counted'] = '%08x counted here' % a
    elif a in elsewhere:
        entry['kind'] = 'counted elsewhere'
        entry['counted'] = '%08x counted by %s' % (a, ', '.join(sorted(elsewhere[a])))
        entry['row'] = 'see counted'
    else:
        assert a in NOTES, ('unclassified', hex(a))
        entry['kind'] = 'blocked' if 'blocked' in NOTES[a] else 'open (owner / shared instance / not attempted)'
        entry['note'] = NOTES[a]
    entry['evidence'] = evidence_of(a)
    unit_rows.append(entry)
assert sum(1 for e in unit_rows if e['kind'] == 'counted here') == len(exact)

paths = [Path(__file__).resolve(), R / 'tests/native_bind.py', UNIT_CPP] + list(OWNER.values()) + [
    HDR / 'reflection/Metadata.h', HDR / 'v8tree/Instance.h', HDR / 'reflection/reflection.h',
    HDR / 'reflection/member.h', HDR / 'reflection/descriptor.h']
range_counted = ['%08x counted by %s' % (a, ', '.join(sorted(v))) for a, v in sorted(elsewhere.items())]
receipt = {
    'family': 'app unit 00440000: CPropGrid / CDataModelPropGrid / RBXImage tails and the reflection-metadata unit',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': nb.flags() + ['/fp:fast'],
    'profile': 'document-swap flags, /fp:fast; the owners\' MetadataClassesLookup.cpp / MetadataReflectionLookup.cpp '
               'included read-only ahead of AppUnit440Metadata.cpp in one generated unit; MetadataClassesLifetime.cpp, '
               'MetadataClassesRegister.cpp and MetadataContainersLifetime.cpp compiled unchanged; the property-grid '
               'owners\' SelectionGroup.cpp / CPropGridInstances.cpp / CSelectionPropGridEvents.cpp / '
               'CSelectionPropGridSelection.cpp / CDataModelPropGridUpdate.cpp compiled unchanged with the '
               'property-grid-working-probe flags + /fp:fast',
    'pg_flags': PG_FLAGS + ['/fp:fast'],
    'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {k: sha(v) for k, v in list(OBJ.items()) + list(VT_OBJ.items())},
    'range': [H(LO), H(HI)],
    'range_rows': len(rows),
    'unit_map': {
        '%s..%s %s' % (H(lo), H(hi - 1), n): {'rows_in_range': sum(1 for a in rows if lo <= a < hi)}
        for lo, hi, n in BLOCKS},
    'unit_map_evidence': [
        'CPropGrid vtable 0x81564c (RTTI .?AVCPropGrid@@) slot 90 = 0x440e30 (addProperty); 0x440d20 returns the '
        'CPropGrid message map 0x8145dc (WM_CREATE 0x4385f0 in app-unit438).',
        '0x442a30 / 0x442b20 store the CPropGrid vtable (dtor / ctor COMDATs emitted after CDataModelPropGrid::update '
        '0x442900); 0x442b10 is sub ecx, 0x188; jmp 0x442c30 (deleting destructor).',
        '0x442c50..0x442f8f RBXImage rows, counted by app-leaves2008.',
        '0x442f90 / 0x442fc0 / 0x442ff0 / 0x443020 dynamic_cast to .?AVClasses / Class / Members / Member@Metadata@'
        'Reflection@RBX@@ (askAddChild); 0x443050 / 0x4430b0 store the FactoryProduct<Reflection> vtable 0x815854; '
        'the unit ends with Reflection::singleton 0x445020 after the MergeBinder COMDATs 0x443c60.. (misc-leaves).',
        'Library: no separately compiled library unit lies in the range; the std / boost / reflection rows are template '
        'instances emitted by these RBX units. Excluded classes: none (no CRobloxApp / CMainFrame / CRobloxDoc / '
        'CRobloxView row).',
    ],
    'layout': {
        'Metadata::Reflection': 'classes child pointer at +0x130 (0x443210 / 0x443ab0 read [ecx+0x130]; constructor '
                                '0x444c50 clears it; creator 0x40b320 allocates 0x134), as reflection/Metadata.h',
        'MemberDescriptor': 'name +4 and owner +0xc (0x443ab0 reads [esi+0xc] then [eax+4]+4 for the owner name, '
                            '[esi+4]+4 for the member name), as reflection/member.h / descriptor.h',
        'Instance': 'children copy-on-write vector at +0x108 (findFirstChildOfType 0x4436e0 reads [edi+0x108]), as '
                    'v8tree/Instance.h',
    },
    'rows': unit_rows,
    'methods': results,
    # helper bodies are not counted: their addresses are written 0x-prefixed (never as quoted bare addresses)
    'helper_bodies_not_counted': INSTANCES,
    'range_rows_counted_by_other_receipts': range_counted,
    'proposals': [
        'reflection/Metadata.h owner: declare Reflection (and sReflection) in namespace RBX::Reflection::Metadata, not '
        'RBX::Metadata. Evidence: the original RTTI is .?AV?$FactoryProduct@VReflection@Metadata@1RBX@@VInstance@3@'
        '$1?sReflection@213@3PADA@RBX@@ (vtable 0x815854 stored by 0x443050 / 0x4430b0), i.e. '
        'FactoryProduct<RBX::Reflection::Metadata::Reflection, Instance, RBX::Reflection::Metadata::sReflection>. With '
        'the current namespace the Reflection vtables cannot be slot-checked, which blocks Reflection::askAddChild '
        '0x442f90, FactoryProduct<Reflection>() / ~FactoryProduct 0x4430b0 / 0x443050, the adjustor thunks 0x443110 / '
        '0x443120 / 0x443130 and getClassName 0x443660 (all byte-exact, relocation-masked, with the committed '
        'MetadataReflectionLifetime.cpp). The non-virtual Reflection rows counted here (lookup 0x443210 and the member '
        'lookups 0x443ab0 / 0x443b00 / 0x443b50) do not depend on the mangled class name. The committed '
        'MetadataReflection*.cpp sources would follow the namespace change.',
        'reflection/Metadata.h owner, FYI: the member lookups 0x443ab0 / 0x443b00 / 0x443b50 are defined in '
        'native-classes/AppUnit440Metadata.cpp as `lookup(descriptor.owner, false)` then '
        'findFirstChildOfType<Properties / Functions / Events>() then findFirstChildByName(descriptor.name); this needs '
        'Reflection::lookup(ClassDescriptor, bool) / Classes::lookup visible in the same unit (they are inlined).',
    ],
    'rejected': [
        'member lookup 0x443ab0 as `Instance* item = classes ? classes->findFirstChildByName(owner name) : NULL; ...` '
        '(69 B vs 73; the original materializes NULL before one shared test, which the inlined lookup(owner, false) '
        'gives).',
        'the same with an early `if (!item) return NULL;` (69 B, different branch layout).',
    ],
    'shadowing': 'none (no new header; every native header is included read-only)',
    'counted_from_owner_probes': 'SelectionGroup::add 0x442350, CPropGrid::addInstance 0x4423f0, '
                                 'CSelectionPropGrid::onEvent 0x442490 / setSelection 0x442650 (selection-grid probe) '
                                 'and CDataModelPropGrid::update 0x442900 (pane-callbacks probe) were relocation-masked '
                                 'matches there; they are counted once here with every target verified.',
    'exact_function_rows': exact,
    'scope': 'Inactive. Exact rows with every target verified; no pending build; no active build, swap or credit.',
}
text = json.dumps(receipt, indent=2) + '\n'
bare = set(re.findall(r'"([0-9a-f]{8})"', text))
assert bare <= set(exact), sorted(bare - set(exact))
RECEIPT.write_text(text)
in_range_counted = len(elsewhere)
print('PASS native app unit440: %d rows mapped, %d exact (%s), %d counted elsewhere, coverage %d/%d -> %d/%d, '
      '%d slot-checked virtuals' % (len(rows), len(exact), ' '.join(exact), in_range_counted, in_range_counted,
                                    len(rows), in_range_counted + len(exact), len(rows), len(SLOT_CHECKS)))
