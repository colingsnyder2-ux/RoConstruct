"""Verify the inactive 2008-06 native rows of the application range 005ac000..005b0000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there as text).

Unit map summary (details in UNIT_MAP below): the whole range lies inside the ScriptContext unit
(script/ScriptContext.cpp, 005a8590..005b071f; app-unit5a8-2008 maps its start and app-unit5b0-2008 its tail). There
is no library code and no maintainer-excluded class in the range.

Built here (no new header; every header is read-only, so nothing is shadowed and there is no pending build):
  * native-classes/AppUnit5ACScriptContext.cpp against the native script/ScriptContext.h / reflection/reflection.h:
    FactoryProduct<ScriptContext>::getClassName 005ac030, Described<ScriptContext>::classDescriptor 005ad200,
    DescribedCreatable<ScriptContext>() 005ad930, BoundFuncDesc<ScriptContext, void(double), 1>(function, name,
    arg1Name, security) 005ad9f0 and its execute 005ada90, scoped_ptr<Lua::YieldingThreads>::~scoped_ptr 005ae210;
  * native-classes/AppUnit5ACStatsItem.cpp against the Stats owner's native stats/Stats.h and v8tree/Service.h:
    DescribedNonCreatable<Stats::Item>(const char*) 005ad770, Stats::Item(const char*) 005ad810,
    Creatable<Instance>::create<Stats::Item, const char*> 005adb70, ServiceProvider::create<StatsService>(const
    Instance*) 005aecd0.

Build: document-swap flags, VS2008 RTM 21022 (no extra profile flag).

Every counted row is relocation-masked exact against the original with the same DIR32 field offsets on both sides,
and every REL32/DIR32 target is bound to the address the original instruction uses and verified: imports by DLL export
name, string literals by bytes, RTTI type descriptors by name, vtables by their complete-object-locator RTTI (and
their compiled slots against the original slots where the slot is a row proven here), own symbols by the row proven
here, COMDAT support bodies by exactness at the bound address (never counted), rows counted by other receipts by that
receipt's symbol and an exact body, the class-name arrays by their string, the remaining externals by the explicit
EXTERNAL map (evidence name or another receipt's binding), static data by one address per symbol. A row is counted
only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit5ac-working.json.
Set NATIVE_APP_UNIT5AC_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit5ac'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'script': R / 'native-classes/AppUnit5ACScriptContext.cpp',
    'stats': R / 'native-classes/AppUnit5ACStatsItem.cpp',
}
HEADERS = [R / 'native-headers/script/ScriptContext.h', R / 'native-headers/stats/Stats.h',
           R / 'native-headers/reflection/reflection.h']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT5AC_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit5ac-working.json'
LO, HI = 0x5ac000, 0x5b0000

FLAGS, OBJ = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k] = OUT / ('NativeAppUnit5AC_%s.obj' % _k)
    FLAGS[_k] = nb.flags() + ['/Fo' + str(OBJ[_k]), str(_src)]
    _code, _log = rebuild.run(rebuild.toolchain(21022), 'cl', FLAGS[_k], OUT)
    assert _code == 0, _log

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        x = json.loads(line)
        FUNCTIONS[int(x['addr'], 16)] = x


def norm(s):
    return s.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


class Obj:
    def __init__(self, path):
        self.raw = Path(path).read_bytes()
        self.sections, self.symbols, self.definitions, self.starts = match._coff_data_index(self.raw)
        self.bodies = {n: (b, r) for n, b, r in match.coff_functions(self.raw)}


OBJS = {k: Obj(v) for k, v in OBJ.items()}

# ---- rows ----------------------------------------------------------------------------------------------------------
SCX = 'VScriptContext@RBX@@'
FPS = '?$FactoryProduct@' + SCX + 'VInstance@2@$1?sScriptContext@2@3PADA@RBX@@'
DCS = '?$DescribedCreatable@' + SCX + 'VInstance@2@$1?sScriptContext@2@3PADA@RBX@@'
BFD = '?$BoundFuncDesc@' + SCX + '$$A6AXN@Z$00@Reflection@RBX@@'
ITEM = 'VItem@Stats@RBX@@'
ROWS = {
    'script': [
        # ICF: Name::declare<sScriptContext>, FactoryProduct::className and getClassName compile to the same 23-byte
        # body (call_once on callDoDeclare, then a tail jump to doDeclare); counted once, under the vtable symbol
        (0x5ac030, '?getClassName@' + FPS + 'UBEABVName@2@XZ'),
        (0x5ad200, '?classDescriptor@?$Described@' + SCX + '$1?sScriptContext@2@3PADAV?$FactoryProduct@' + SCX
         + 'VInstance@2@$1?sScriptContext@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ'),
        (0x5ad930, '??0' + DCS + 'IAE@XZ'),
        (0x5ad9f0, '??0' + BFD + 'QAE@P8ScriptContext@2@AEXN@ZPBD1W4Security@FunctionDescriptor@12@@Z'),
        (0x5ada90, '?execute@' + BFD + 'UBEXPAVDescribedBase@23@AAVArguments@FunctionDescriptor@23@@Z'),
        (0x5ae210, '??1?$scoped_ptr@VYieldingThreads@Lua@RBX@@@boost@@QAE@XZ'),
    ],
    'stats': [
        (0x5ad770, '??$?0PBD@?$DescribedNonCreatable@' + ITEM + 'VInstance@3@$1?sStatsItem@23@3PADA@RBX@@IAE@PBD@Z'),
        (0x5ad810, '??0Item@Stats@RBX@@QAE@PBD@Z'),
        (0x5adb70, '??$create@' + ITEM + 'PBD@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@' + ITEM + '@boost@@PBD@Z'),
        (0x5aecd0, '??$create@VStatsService@Stats@RBX@@@ServiceProvider@RBX@@SAPAVStatsService@Stats@1@PBVInstance@1@@Z'),
    ],
}
for _k, _rows in ROWS.items():
    for _a, _s in _rows:
        assert LO <= _a < HI and _a in FUNCTIONS, hex(_a)
        assert _s in OBJS[_k].bodies, (hex(_a), _s)
_all = [a for rows in ROWS.values() for a, _ in rows]
assert len(set(_all)) == len(_all)
OWN = {s: a for rows in ROWS.values() for a, s in rows}

# identity of the ICF row 005ac030: slot of the FactoryProduct<ScriptContext> vtables (checked below) and a body that
# tail-jumps to doDeclare<sScriptContext> 0042ced0 after call_once(callDoDeclare 0042d090, once flag 0096d12c)
_b = original.data(0x5ac030, 23)
assert _b[0x12] == 0xe9 and 0x5ac030 + 0x17 + struct.unpack_from('<i', _b, 0x13)[0] == 0x42ced0, _b.hex()
assert original.string(0x94c440) == 'ScriptContext'

# ---- externals ------------------------------------------------------------------------------------------------------
# Class-name arrays (defined by their owners, not here): bound by the string at the address the original pushes.
NAME_DATA = {'?sScriptContext@RBX@@3PADA': 'ScriptContext', '?sStatsItem@Stats@RBX@@3PADA': 'StatsItem'}
# rows counted by other receipts that the bodies here call: (address, receipt)
COUNTED_TARGETS = {
    '??$doDeclare@$1?sScriptContext@RBX@@3PADA@Name@RBX@@CAABV01@XZ': (0x42ced0, 'app-unit424-2008-working.json'),
    '??$callDoDeclare@$1?sScriptContext@RBX@@3PADA@Name@RBX@@CAXXZ': (0x42d090, 'app-unit424-2008-working.json'),
    '??$create@VStatsService@Stats@RBX@@@ServiceProvider@RBX@@QBEPAVStatsService@Stats@1@XZ':
        (0x458610, 'app-unit454-2008-working.json'),
}
EXTERNAL = {
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,
    # classDescriptor<Instance> (native mangling 3QBDB; humanoid2008 / app-unit5b4 bind it here)
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@'
    'SAAAVClassDescriptor@23@XZ': 0x40ad80,
    '_atexit': 0x6a17af,
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,
    '??2@YAPAXI@Z': 0x6a0920,
    '??3@YAXPAX@Z': 0x6a067a,
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,
    '??1Instance@RBX@@UAE@XZ': 0x55a540,
    '___RTDynamicCast': 0x6a17c6,
    '__CxxThrowException@8': 0x6a158c,
}
LOCAL_STATIC = {}      # symbol -> address: guards, function-local statics, atexit destructors (one address per symbol)
DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
TEXT = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
        for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]
BINDING, UNBOUND, HELPERS = {}, [], {}


def bind(symbol, value, where):
    prev = BINDING.setdefault(symbol, (value, where))
    assert prev[0] == value, ('one address per symbol', symbol, hex(prev[0]), prev[1], hex(value), where)


def receipt_symbols(name, address):
    data = json.loads((ROOT / 'work/2008-06/shared-layouts' / name).read_text())
    if '%08x' % address not in [str(r) for r in data.get('exact_function_rows', [])]:
        return []
    found = []

    def walk(o):
        if isinstance(o, dict):
            if o.get('address') in ('%08x' % address, '%#x' % address) and o.get('symbol') and o.get('exact') is True:
                found.append(o['symbol'])
            for v in o.values():
                walk(v)
        elif isinstance(o, list):
            for v in o:
                walk(v)
    walk(data)
    return found


def body_exact_at(obj, symbol, value):
    hb, hr = obj.bodies[symbol]
    ht, htr, _ = match.target('2008-06', '%08x' % value)
    return match.exact_match(ht, htr, hb, hr)


def classify(obj, symbol, value, where):
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol in OWN:
        assert OWN[symbol] == value, (where, symbol, hex(value), hex(OWN[symbol]))
        return 'own row'
    if symbol.startswith('??_C@'):
        pos, at = obj.definitions[symbol]
        lit = obj.raw[obj.sections[at][4] + pos:obj.sections[at][4] + obj.sections[at][3]].split(b'\0')[0] + b'\0'
        assert original.data(value, len(lit)) == lit, (where, symbol, hex(value))
        return 'literal %r' % lit[:-1].decode('latin-1')
    if symbol.startswith('??_R0') and symbol.endswith('@8'):
        rtti = original.string(value + 8)
        assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
        return 'RTTI %s' % rtti
    if symbol.startswith('??_7'):
        rtti, at = original.vtable_class(value)
        cls = symbol[4:symbol.index('@@6B') + 2]
        assert rtti == '.?AV' + cls, (where, symbol, hex(value), rtti)
        return 'vtable RTTI %s offset %#x' % (rtti, at)
    if symbol in NAME_DATA:
        assert original.string(value) == NAME_DATA[symbol], (where, symbol, hex(value))
        return 'class-name array %r (string at the pushed address)' % NAME_DATA[symbol]
    if symbol in COUNTED_TARGETS:
        other, receipt = COUNTED_TARGETS[symbol]
        assert other == value, (where, symbol, hex(value), hex(other))
        assert '%08x' % value in json.loads((ROOT / 'work/2008-06/shared-layouts' / receipt).read_text())[
            'exact_function_rows'], (receipt, hex(value))
        assert symbol in receipt_symbols(receipt, value), (receipt, hex(value), symbol)
        if symbol in obj.bodies:
            assert body_exact_at(obj, symbol, value), ('counted-elsewhere body not exact', symbol, hex(value))
        return 'row counted by %s (body exact at the bound address)' % receipt
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
        return 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
    if norm(names.get(value, '')) == norm(symbol) and not (TEXT[0] <= value < TEXT[1] and symbol in obj.bodies
                                                           and not body_exact_at(obj, symbol, value)):
        return 'external (evidence name)'
    if symbol in obj.bodies:
        # COMDAT support body compiled here but not a counted row: exact at the bound address, never counted
        assert body_exact_at(obj, symbol, value) or DISCOVER, (where, symbol, hex(value))
        HELPERS.setdefault(symbol, '%#x' % value)
        return 'support body exact at the bound address (not counted here)'
    if symbol in obj.definitions or symbol.startswith(('?flag@', '??_B', '?foo@', '?$S', '??__F', '?instance@')):
        if TEXT[0] <= value < TEXT[1]:
            # compiler-generated atexit destructor of a function-local static (??__F...): bound by consistency
            assert symbol.startswith('??__F'), (where, symbol, hex(value))
        else:
            assert any(lo <= value < hi for lo, hi in DATA_SECTIONS), (where, symbol, hex(value))
        LOCAL_STATIC.setdefault(symbol, value)
        return 'static (one address per symbol)'
    return None


def reloc_offsets(obj, name, size):
    start, section = obj.definitions[name]
    table = obj.sections[section]
    out = set()
    for i in range(table[7]):
        offset, _, kind = struct.unpack_from('<IIH', obj.raw, table[5] + 10 * i)
        offset -= start
        if 0 <= offset < size and kind != 20:      # DIR32 fields (the image's base relocations); REL32 are bound
            out.add(offset)
    return out


def verify(which, rows):
    obj = OBJS[which]
    out = []
    for address, name in rows:
        body, refs = obj.bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        exact = match.exact_match(target, target_refs, body, refs)
        same = exact and reloc_offsets(obj, name, len(body)) == set(target_refs)
        row = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
               'exact': bool(exact and same), 'verified_targets': {}, 'local_eh': []}
        if exact and not same:
            row['note'] = 'bytes equal under the union mask but the DIR32 field offsets differ'
        out.append(row)
        if not row['exact']:
            continue
        start, section = obj.definitions[name]
        table = obj.sections[section]
        code = obj.raw[table[4] + start:]
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', obj.raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = obj.symbols[index][0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            where = '%08x+%#x' % (address, offset)
            if nb.LOCAL_EH.match(symbol):
                row['local_eh'].append(symbol)
                continue
            how = classify(obj, symbol, value, where)
            if how is None:
                UNBOUND.append((where, symbol, hex(value), names.get(value, '')[:80]))
                continue
            bind(symbol, value, where)
            row['verified_targets'][symbol] = '%#x (%s)' % (value, how)
    return out


rows = {k: verify(k, v) for k, v in ROWS.items()}
all_rows = [r for v in rows.values() for r in v]
not_exact = [r for r in all_rows if not r['exact']]
if DISCOVER:
    for u in sorted(set(UNBOUND)):
        print('UNBOUND', u)
    for r in not_exact:
        print('NOT EXACT', r['address'], r['size'], r['target_size'], r['symbol'][:100], r.get('note', ''))
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]


# ---- vtables stored by the rows (current headers; there is no pending build) ----------------------------------------
def compiled_vtables(obj):
    out = {}
    for name, (start, sec) in obj.definitions.items():
        if not name.startswith('??_7'):
            continue
        table = obj.sections[sec]
        end = min([x for x in obj.starts.get(sec + 1, ()) if x > start] + [table[3]])
        slots = {}
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', obj.raw, table[5] + 10 * i)
            if start <= offset < end:
                slots[(offset - start) // 4] = obj.symbols[index][0]
        out[name] = slots
    return out


vtable_checks = {}
for _k, _rows in rows.items():
    _vt = compiled_vtables(OBJS[_k])
    for r in _rows:
        for symbol, desc in r['verified_targets'].items():
            if not symbol.startswith('??_7') or symbol in vtable_checks:
                continue
            value = int(desc.split()[0], 16)
            slots = _vt.get(symbol, {})
            checked, other = [], 0
            assert sorted(slots) == list(range(len(slots))), (symbol, sorted(slots))
            # same slot count: the original dword after the last compiled slot is not code (next COL / data)
            _after = struct.unpack('<I', original.data(value + 4 * len(slots), 4))[0]
            assert not TEXT[0] <= _after < TEXT[1], ('vtable longer in the original', symbol, hex(_after))
            for k, s in sorted(slots.items()):
                got = struct.unpack('<I', original.data(value + 4 * k, 4))[0]
                assert TEXT[0] <= got < TEXT[1], (symbol, k, hex(got))
                expect = OWN.get(s, BINDING.get(s, (None,))[0])
                if expect is None and s in HELPERS:
                    expect = int(HELPERS[s], 16)
                if expect is not None:
                    assert expect == got, ('vtable slot', symbol, k, s, hex(got), hex(expect))
                    checked.append('%d %s = %#x' % (k, s[:70], got))
                elif norm(names.get(got, '')) == norm(s):
                    checked.append('%d %s = %#x (evidence name)' % (k, s[:70], got))
                elif s in OBJS[_k].bodies and body_exact_at(OBJS[_k], s, got):
                    HELPERS.setdefault(s, '%#x' % got)
                    checked.append('%d %s = %#x (compiled body exact there)' % (k, s[:70], got))
                else:
                    other += 1
            vtable_checks[symbol] = {'address': '%#x' % value, 'compiled_slots': len(slots), 'checked_slots': checked,
                                     'slots_not_identified': other}
# the ICF getClassName row and the execute row must be slots of the vtables the rows store
_slot_hits = {c.split(' = ')[1] for v in vtable_checks.values() for c in v['checked_slots']}
assert {'0x5ac030', '0x5ada90'} <= _slot_hits or DISCOVER, _slot_hits


# ---- rows counted elsewhere / range map -----------------------------------------------------------------------------
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
        found = []
        for key in ('exact_function_rows', 'exact_addresses', 'exact_unique_addresses', 'exact_distinct_addresses'):
            if isinstance(data.get(key), (list, dict)):
                found = list(data[key])
                break
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        found.append(o['address'])
                    for v in o.values():
                        walk(v)
            walk(data.get('methods', []))
        for r in found:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
exact_rows = sorted({r['address'] for r in all_rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}

# boundary evidence (read from the binary): the ScriptContext unit runs through the whole range
assert original.vtable_class(0x83465c)[0] == '.?AV' + DCS
assert original.vtable_class(0x8346a0)[0] == '.?AV' + BFD
assert original.string(0x8346a8) == 'Game script timout'
assert names.get(0x5affa0, '').startswith('?startScript@ScriptContext@RBX@@')
assert names.get(0x5afd60, '').startswith('?onServiceProvider@ScriptContext@RBX@@')
assert names.get(0x5ae0d0, '').startswith('?resume@ScriptContext@RBX@@')
assert names.get(0x5ad380, '').startswith('?get@LuaArguments@Lua@RBX@@')

UNIT_MAP = {
    'script-context 005ac000..005affff': (
        'script/ScriptContext.cpp, the middle of the unit 005a8590..005b071f (start: app-unit5a8-2008 unit map, '
        'Lua::ScopedPopper::~ScopedPopper 005a8590 after Guid.cpp; tail: app-unit5b0-2008 unit map, Accoutrement.cpp '
        'from 005b0820). Evidence in this range: DescribedCreatable<ScriptContext> vtable 0083465c (RTTI ...3PADA), '
        'stored by DescribedCreatable<ScriptContext>() 005ad930, which ScriptContext() 005ae490 calls; the '
        'ScriptContext ??_E thunks 005ae690..005ae720, ~ScriptContext 005ae730 and ??_G 005aed20 (counted by '
        'app-unit5a8-2008); BoundFuncDesc<ScriptContext, void(double), 1> vtable 008346a0 (constructor 005ad9f0, '
        'called from the unit\'s dynamic initializer; execute 005ada90) and the timeout check 005adbf0 / hook '
        '005ae230 ("Game script timout" 008346a8, counter 00976b78, ScriptContext +0x1c8); the Lua C functions '
        'settings 005adc60 ("settings()"), the identity printer 005add30 ("Current identity is %d"), loadfile 005ade40 '
        '/ dofile 005adf80 (the active P6 ScriptFileLoad.cpp proves them; no receipt counts them), stats 005aeea0 '
        '("Stats", ServiceProvider::create<StatsService>(const Instance*) 005aecd0); resume 005ae0d0, closeState '
        '005ae280 ("Script memory leaks"), ScriptContext() 005ae490 ("Script Context"), the RunService handler '
        '005ae8f0 ("ScriptContext Timeout"), setThreadIdentity 005aeaf0, the call helpers 005aeb80 / 005aed40 ("Cannot '
        'call a nil function"), openState 005aefa0 ("Failed to create Lua state"), 005af830, executeInNewThread '
        '005af940 ("Unable to create trusted sandbox"), onServiceProvider 005afd60 ("disabled threads") and '
        'startScript 005affa0 (continues past 005b0000); reportError 005ac610 ("%s, line %d - %s %s"), LuaArguments '
        'get 005ad380 and the Value tuple helpers 005ad6d0 / 005ad270 / 005ad2b0; the Stats::Item COMDATs 005ad770 / '
        '005ad810 / 005adb70 (left to "the script unit" by stats-service); FactoryProduct<ScriptContext>::getClassName '
        '005ac030 and classDescriptor 005ad200 ("ScriptContext" 0094c440); the Lua bridge template COMDATs the unit '
        'instantiates first (Bridge<shared_ptr<DescribedBase>>::getValue / getPtr<Value> 005ac0d0..005ac270 / '
        '005ac560 / 005ac8d0, pushTable<vector<shared_ptr<Instance>>> 005ac2f0) and the STL / boost instantiations '
        'for set<Script*> (_Copy 005ac050, for_each 005ac450, _Tree() 005aca50), vector<shared_ptr<Script>> (for_each '
        '005ac4f0), vector<WaitingThread> (_Destroy_range 005aca00, ~vector 005ad190), vector<shared_ptr<Instance>> '
        '(copy constructor 005acb00), boost::function invokers / managers (005ac5f0, 005ac600, 005ac960, 005acaf0, '
        '005acc70..005ad140), boost::any holders (005acd00..005acf40) and scoped_ptr<YieldingThreads> 005ae210. '
        'Library code: none (Lua 5.1.1 lies at 006217f0..00628f73; its calls are bound by address). Maintainer '
        'exclusion: none.'),
}

NOT_ATTEMPTED = {
    'ScriptContext members (reportError 005ac610, resume 005ae0d0, closeState 005ae280, the timeout check / hook '
    '005adbf0 / 005ae230, the RunService handler 005ae8f0, the call helpers 005aeb80 / 005aed40, stats 005aeea0, '
    'openState 005aefa0, 005af830, executeInNewThread 005af940, onServiceProvider 005afd60, startScript 005affa0, the '
    'identity printer 005add30)': (
        'they need 2008 declarations the native script/ScriptContext.h does not have (the timeout fields +0x1c8.. and '
        'the 00976b78 counter, the SetTimeout member the BoundFuncDesc row binds, the 2008 YieldingThreads, '
        'LuaAllocator), and the inline getContext these bodies inline is defined by the app-unit5a8-2008 source; '
        'see proposals'),
    'ScriptContext() 005ae490': (
        'committed ScriptContextLifetime.cpp (owner) builds 504/504 B but not exact: a temporary at [esp+0x13] vs '
        '[esp+0x12] and the exeTime1 store scheduled after the exeState store (proposal to the owner)'),
    'loadfile 005ade40 / dofile 005adf80': 'owned by the active P6 native ScriptFileLoad.cpp (p6/script_context_owner.py)',
    'STL / boost / any instantiations (005ac050, 005ac450, 005ac4f0, 005ac5f0, 005ac600, 005ac960, 005aca00, 005aca50, '
    '005acaf0, 005acb00, 005acbf0..005ad140, 005ad190)': (
        'ICF-folded bodies shared by several instantiations (bytes match more than one candidate; 005ac4f0 calls a '
        'Replicator mf1 and 005acaf0 a Player mf0, so they are other units\' folded copies), identity not proven by a '
        'relocation; not counted'),
    'Lua bridge / LuaArguments rows (005ac0d0..005ac270, 005ac2f0, 005ac560, 005ad270, 005ad2b0, 005ad380, '
    '005ad6d0)': 'LuaBridge2008 / LuaArguments2008 owner templates; not exact in app-unit5a8-2008 (005ac560) or not built',
}
REJECTED = {
    '~vector<WaitingThread> 005ad190 as a counted row': (
        'the compiled donor body (float WaitingThread of script/ScriptEvent.h) is exact at 005ad190, but the '
        '_Destroy_range<WaitingThread> 005aca00 it calls is not (76 B; the 2008 element is {shared_ptr<ThreadRef>, '
        'double, double}), so its call target cannot be verified; kept as a support body of ~scoped_ptr only'),
}
PROPOSALS = {
    'native-headers/script/ScriptContext.h (owner)': (
        'Declare the 2008 timeout API: a `void setTimeout(double seconds)` member (the function bound by '
        'BoundFuncDesc<ScriptContext, void(double), 1> 005ad9f0 / execute 005ada90, which call [desc+0x38] with a '
        'double), the timeout state the check 005adbf0 reads at +0x1c8 (int, nonzero = armed) and the global counter '
        '00976b78 the hook 005ae230 tests; they unlock 005adbf0 / 005ae230 / 005ae8f0 and the descriptor initializer.'),
    'native-classes/ScriptContextLifetime.cpp (owner of script/ScriptContext.h)': (
        'ScriptContext() 005ae490 builds 504/504 B but not exact: the original stores exeTime1 (+0x1c0, fstp) before '
        'exeState (+0x1c8) and uses one less byte of temporaries ([esp+0x12] vs [esp+0x13]) for the date-time '
        'arguments; with DescribedCreatable() 005ad930 proven here the ctor is the next step.'),
}

receipt = {
    'class': 'RBX ScriptContext unit (script/ScriptContext.cpp template instances, Stats::Item COMDATs) of the '
             'application range 005ac000..005b0000 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022 (document-swap flags)',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)): nb.sha(p) for p in list(SOURCES.values()) + [Path(__file__).resolve()] + HEADERS},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'layout': {
        'Stats::Item': 'sizeof 0x158 (malloc 0x158 in Creatable<Instance>::create<Stats::Item, const char*> 005adb70); '
                       'val +0x130 (fldz/fstp in Item(const char*) 005ad810), sValue +0x138 (std::string() there)',
        'BoundFuncDesc<ScriptContext, void(double), 1>': 'function pointer-to-member +0x38/+0x3c (8 B: ScriptContext '
                       'has multiple bases), default1 Value +0x40, signature +0x14 (005ad9f0)',
        'DescribedCreatable<ScriptContext>': 'descriptor +0x1c; vptrs at +0, +0x10, +0x14, +0x20, +0x24, +0x44, +0x64, '
                       '+0x84, +0xa4, +0xc4 (005ad930)',
    },
    'unit_map': UNIT_MAP,
    'range_rows_total': len(range_rows),
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any '"ADDR"' in another receipt as counted there and drop it.
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'rows': rows,
    'support_bodies': HELPERS,
    'local_statics': {k: '%#x' % v for k, v in sorted(LOCAL_STATIC.items())},
    'vtables_current_headers': vtable_checks,
    'not_exact': ['%s %s: %d/%d B, not counted' % (r['address'], r['symbol'][:60], r['size'], r['target_size'])
                  for r in not_exact],
    'pending_build_only': [],
    'not_attempted': NOT_ATTEMPTED,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
if not DISCOVER:
    RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit5ac: %d counted exact rows (%s); %d vtables checked, %d support bodies; %d range rows '
      '(%d counted elsewhere)' % (len(exact_rows), ' '.join(exact_rows), len(vtable_checks), len(HELPERS),
                                  len(range_rows), len(range_counted)))
