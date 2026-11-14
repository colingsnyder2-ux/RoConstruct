"""Verify the inactive 2008-06 native rows of the application range 005a4000..005a8000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there as text).

Unit map summary (details in UNIT_MAP below):
  * Workspace.cpp tail 005a4000..005a67ef (the unit starts at 005a0090, app-unit5a0's map): the reflection
    descriptors of the unit (BoundFuncDesc InsertContent / MakeJoints / BreakJoints / SetPhysicsThrottleEnabled /
    ZoomToExtents, RefPropDescriptor CurrentCamera), the DescribedNonCreatable thunks, setCamera / getCamera helpers,
    the Workspace() constructor, the stats items (TypedStatsItem<double / float>, WorkspaceStatsItem) and
    onServiceProvider. Built here from native-classes/AppUnit5A4WorkspaceReflection.cpp (descriptors + setCamera)
    and AppUnit5A4StatsItems.cpp (TypedStatsItem update overrides).
  * boost.thread library code 005a67f0..005a6baf (barrier / thread / xtime), never recovered.
  * Log.cpp 005a6bb0..005a6fcf, counted by leaves2008-working.json.
  * boost.thread tss library code 005a6fd0..005a776f, never recovered.
  * FileSystem.cpp 005a7770..005a80cf: built here from the committed native-classes/FileSystem.cpp,
    read-only (the four RBX rows; no copy of its bodies is kept);
    the ATL CStringT<char> instances between them are library code (support bodies only).

Build: document-swap flags, VS2008 RTM 21022; the Workspace and stats units add /U_RELEASEASSERT (the app-unit5a0
profile of the same Workspace.cpp unit). No pending build and no new header: every row needs only declarations the
committed native headers already give, so no existing recorder is shadowed.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, string literals by bytes, RTTI type
descriptors by name, vtables by their complete-object-locator RTTI, own symbols by the row proven here, COMDAT support
bodies by exactness at the bound address, the remaining externals by the explicit EXTERNAL map (evidence name or
another receipt's binding), static data by one address per symbol. A row is counted only when no other receipt counts
it. Compiled vtables are compared slot by slot with the original vtables the rows store.
Writes work/2008-06/shared-layouts/app-unit5a4-working.json.
Set NATIVE_APP_UNIT5A4_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit5a4'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'workspace': R / 'native-classes/AppUnit5A4WorkspaceReflection.cpp',
    'stats': R / 'native-classes/AppUnit5A4StatsItems.cpp',
    'filesystem': R / 'native-classes/FileSystem.cpp',
}
UNIT = {'workspace': ['/U_RELEASEASSERT'], 'stats': ['/U_RELEASEASSERT'], 'filesystem': []}
HEADERS = [R / 'native-headers/v8datamodel/Workspace.h', R / 'native-headers/v8datamodel/Camera.h',
           R / 'native-headers/reflection/reflection.h', R / 'native-headers/stats/Stats.h',
           R / 'native-headers/util/FileSystem.h']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT5A4_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit5a4-working.json'
LO, HI = 0x5a4000, 0x5a8000

OBJ, FLAGS = {}, {}
for _key, _src in SOURCES.items():
    OBJ[_key] = OUT / ('NativeAppUnit5A4_' + _key + '.obj')
    FLAGS[_key] = nb.flags() + UNIT[_key]
    _code, _log = rebuild.run(rebuild.toolchain(21022), 'cl', FLAGS[_key] + ['/Fo' + str(OBJ[_key]), str(_src)], OUT)
    assert _code == 0, _log

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        x = json.loads(line)
        FUNCTIONS[int(x['addr'], 16)] = x


class Unit:
    def __init__(self, path):
        self.raw = path.read_bytes()
        self.sections, self.symbols, self.definitions, self.starts = match._coff_data_index(self.raw)
        self.bodies = {n: (b, r) for n, b, r in match.coff_functions(self.raw)}
        self.compiled = [n for n in self.bodies if not nb.LOCAL_EH.match(n)]

    def sym(self, prefix, *contains):
        hits = [n for n in self.compiled if n.startswith(prefix) and all(c in n for c in contains)]
        assert len(hits) == 1, (prefix, contains, hits)
        return hits[0]


U = {k: Unit(p) for k, p in OBJ.items()}
WS, ST, FS = U['workspace'], U['stats'], U['filesystem']

# ---- rows ----------------------------------------------------------------------------------------------------------
BF = '?$BoundFuncDesc@VWorkspace@RBX@@'
INSTANCES = 'V?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@'
BF_INSERT = BF + '$$A6A?AV?$shared_ptr@$$CBV?$vector'          # shared_ptr<const Instances>(ContentId)
BF_JOINTS = BF + '$$A6AX' + INSTANCES                             # void(shared_ptr<const Instances>)
BF_BOOL = BF + '$$A6AX_N@Z$00@'                                   # void(bool)
BF_VOID = BF + '$$A6AXXZ$0A@@'                                    # void()
EXECUTE = 'UBEXPAVDescribedBase@23@AAVArguments@FunctionDescriptor@23@@Z'
ROWS = [
    (0x5a4020, 'stats', '?update@?$TypedStatsItem@N@Stats@RBX@@MAEXXZ'),
    (0x5a4160, 'stats', '?update@?$TypedStatsItem@M@Stats@RBX@@MAEXXZ'),
    (0x5a4420, 'workspace', WS.sym('??0' + BF_INSERT)),
    (0x5a44d0, 'workspace', WS.sym('??$call@V?$shared_ptr@$$CBV?$vector', BF_INSERT)),
    (0x5a45b0, 'workspace', WS.sym('?execute@' + BF_INSERT)),
    (0x5a46a0, 'workspace', WS.sym('??0' + BF_JOINTS)),
    (0x5a4860, 'workspace', WS.sym('??0' + BF_BOOL)),
    (0x5a4910, 'workspace', WS.sym('?execute@' + BF_BOOL)),
    (0x5a4a00, 'workspace', WS.sym('??0' + BF_VOID)),
    (0x5a4a80, 'workspace', WS.sym('?execute@' + BF_VOID)),
    (0x5a5200, 'workspace', '?setCamera@Workspace@RBX@@QAEXPAVCamera@2@@Z'),
    (0x5a7770, 'filesystem', '??1VistaAPIs@RBX@@QAE@XZ'),
    (0x5a7780, 'filesystem', '?GetIntegrity@VistaAPIs@RBX@@QAGJPAE@Z'),
    (0x5a7ac0, 'filesystem', FS.sym('?getUserAppDataDirectory@FileSystem@RBX@@')),
    (0x5a7ea0, 'filesystem', FS.sym('?getCacheDirectory@FileSystem@RBX@@')),
]
NEAR = [(0x5a4750, 'workspace', WS.sym('?execute@' + BF_JOINTS))]
ROWS.sort()
for _a, _u, _s in ROWS + NEAR:
    assert LO <= _a < HI and _a in FUNCTIONS, hex(_a)
    assert _s in U[_u].bodies, (hex(_a), _s)
assert len({a for a, _, _ in ROWS}) == len(ROWS) and len({s for _, _, s in ROWS}) == len(ROWS)
OWN = {s: a for a, _, s in ROWS}

# Identity of the descriptor rows: each static initializer of this unit holds the bound member function as an
# immediate, the descriptor object as `mov ecx, imm32` and calls exactly one constructor row; its strings are the
# descriptor name (and argument name). Identity of the TypedStatsItem rows: slot 16 of the vtable by RTTI.
TEXT_SECTION = [s for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]
TEXT = (original.image + TEXT_SECTION.VirtualAddress, original.image + TEXT_SECTION.VirtualAddress
        + TEXT_SECTION.Misc_VirtualSize)
INITIALIZERS = {
    0x7f4d60: (0x5a4420, ['InsertContent']),
    0x7f4da0: (0x5a46a0, ['objects', 'MakeJoints']),
    0x7f4de0: (0x5a46a0, ['objects', 'BreakJoints']),
    0x7f4e20: (0x5a4860, ['value', 'SetPhysicsThrottleEnabled']),
    0x7f4e60: (0x5a4a00, ['ZoomToExtents']),
}
IDENTITY = {}
for _init, (_ctor, _strings) in INITIALIZERS.items():
    _f = FUNCTIONS[_init]
    assert _f['strings'] == _strings and '%08x' % _ctor in _f['call_targets'], (hex(_init), _f['strings'],
                                                                                  _f['call_targets'])
    IDENTITY.setdefault('%08x' % _ctor, []).append('static initializer %#x (%s) calls this constructor' % (
        _init, ' / '.join(_strings)))
for _a, _vt, _rtti in [(0x5a4020, 0x833b9c, '.?AV?$TypedStatsItem@N@Stats@RBX@@'),
                        (0x5a4160, 0x833c64, '.?AV?$TypedStatsItem@M@Stats@RBX@@')]:
    assert original.vtable_class(_vt) == (_rtti, 0), (hex(_vt), original.vtable_class(_vt))
    assert struct.unpack('<I', original.data(_vt + 16 * 4, 4))[0] == _a, hex(_a)
    IDENTITY['%08x' % _a] = 'slot 16 (update) of the vtable %#x (RTTI %s)' % (_vt, _rtti)
# setCamera: called with the camera by the CurrentCamera initializer's descriptor getset and by 005a5710; it pushes
# the CurrentCamera descriptor object constructed by the initializer 007f4ea0 ("Data", "CurrentCamera").
assert FUNCTIONS[0x7f4ea0]['strings'] == ['Data', 'CurrentCamera'], FUNCTIONS[0x7f4ea0]['strings']
IDENTITY['005a5200'] = ('pushes the CurrentCamera RefPropDescriptor object built by the static initializer 0x7f4ea0 '
                        '("Data", "CurrentCamera") before Instance::raisePropertyChanged')
for _a, _strings in [(0x5a7ac0, ['Shell32.dll', 'SHGetKnownFolderPath']), (0x5a7ea0, ['Shell32.dll'])]:
    assert all(s in FUNCTIONS[_a].get('strings', []) for s in _strings), (hex(_a), FUNCTIONS[_a].get('strings'))

# ---- externals ------------------------------------------------------------------------------------------------------
# (Described<Workspace>::classDescriptor 005a3b70, counted by app-unit5a0-2008, is compiled here and bound as a
# support body exact at its address.)
EXTERNAL = {
    '??0FunctionDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBDW4Security@012@@Z': 0x595790,
    '??0Value@Reflection@RBX@@QAE@XZ': 0x594ac0,
    '?addArgument@SignatureDescriptor@Reflection@RBX@@QAEXABVName@3@ABVType@23@ABVValue@23@@Z': 0x594b40,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,
    '??$convert@VContentId@RBX@@@Value@Reflection@RBX@@QAEAAVContentId@2@XZ': 0x56eff0,
    '??$convert@_N@Value@Reflection@RBX@@QAEAA_NXZ': 0x56ebb0,
    '??$singleton@_N@Type@Reflection@RBX@@SAABV012@XZ': 0x56cc30,
    '??$singleton@X@Type@Reflection@RBX@@SAABV012@XZ': 0x594a50,
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,
    '??$singleton@V?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance'
    '@RBX@@@boost@@@std@@@std@@@boost@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56cb50,
    # Type::singleton<ContentId>: no evidence name; bound to 0056cd80 by the committed app-unit564 / 57c / 58c receipts
    '??$singleton@VContentId@RBX@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56cd80,
    '??$formatValue@N@Item@Stats@RBX@@QAEXABN@Z': 0x5c90b0,
    '??$formatValue@M@Item@Stats@RBX@@QAEXABM@Z': 0x5c90e0,
    '??2@YAPAXI@Z': 0x6a0920,
    # atls.lib AtlThrowImpl (library body, evidence name; the header copy compiled here is not the linked one)
    '?AtlThrowImpl@ATL@@YGXJ@Z': 0x401000,
    '??3@YAXPAX@Z': 0x6a067a,
}
LOCAL_STATIC = {}
DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
BINDING, UNBOUND, HELPERS = {}, [], {}


def norm(s):
    return s.replace('3QBDB', '3PBDB')


def bind(symbol, value, where):
    prev = BINDING.setdefault(symbol, (value, where))
    assert prev[0] == value, ('one address per symbol', symbol, hex(prev[0]), prev[1], hex(value), where)


def body_exact_at(unit, symbol, value):
    hb, hr = unit.bodies[symbol]
    ht, htr, _ = match.target('2008-06', '%08x' % value)
    return match.exact_match(ht, htr, hb, hr)


def classify(unit, symbol, value, where):
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol in OWN:
        assert OWN[symbol] == value, (where, symbol, hex(value), hex(OWN[symbol]))
        return 'own row'
    if symbol.startswith('??_C@'):
        pos, at = unit.definitions[symbol]
        lit = unit.raw[unit.sections[at][4] + pos:unit.sections[at][4] + unit.sections[at][3]]
        if symbol.startswith('??_C@_1'):
            end = next(i for i in range(0, len(lit), 2) if lit[i:i + 2] == b'\0\0')
            lit = lit[:end + 2]
            assert original.data(value, len(lit)) == lit, (where, symbol, hex(value))
            return 'wide literal %r' % lit[:-2].decode('utf-16-le')
        lit = lit.split(b'\0')[0] + b'\0'
        assert original.data(value, len(lit)) == lit, (where, symbol, hex(value))
        return 'literal %r' % lit[:-1].decode('latin-1')
    if symbol.startswith('??_R0') and symbol.endswith('@8'):
        rtti = original.string(value + 8)
        assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
        return 'RTTI %s' % rtti
    if symbol.startswith('??_7'):
        rtti, at = original.vtable_class(value)
        cls = symbol[4:symbol.index('@@6B') + 2]
        assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
        return 'vtable RTTI %s offset %#x' % (rtti, at)
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
        return 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
    if symbol in unit.bodies:
        # COMDAT support body compiled here but not a counted row: exact at the bound address, never counted
        assert body_exact_at(unit, symbol, value) or DISCOVER, (where, symbol, hex(value))
        HELPERS.setdefault(symbol, '%#x (support body exact at the bound address, not counted here)' % value)
        return 'support body exact at the bound address (not counted here)'
    if symbol in unit.definitions or symbol.startswith(('?g_strmgr@', '?currentCameraProxyProp@', '__TI', '??_R')):
        assert any(lo <= value < hi for lo, hi in DATA_SECTIONS), (where, symbol, hex(value))
        LOCAL_STATIC.setdefault(symbol, value)
        return 'static data (one address per symbol)'
    return None


def verify(rows):
    out = []
    for address, key, name in rows:
        unit = U[key]
        body, refs = unit.bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        exact = match.exact_match(target, target_refs, body, refs)
        row = {'address': '%08x' % address, 'unit': key, 'symbol': name, 'size': len(body),
               'target_size': len(target), 'exact': bool(exact), 'verified_targets': {}, 'local_eh': []}
        out.append(row)
        if not exact:
            continue
        start, section = unit.definitions[name]
        table = unit.sections[section]
        code = unit.raw[table[4] + start:]
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', unit.raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = unit.symbols[index][0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) \
                    & 0xffffffff
            where = '%08x+%#x' % (address, offset)
            if nb.LOCAL_EH.match(symbol):
                row['local_eh'].append(symbol)
                continue
            how = classify(unit, symbol, value, where)
            if how is None:
                UNBOUND.append((where, symbol, hex(value), names.get(value, '')[:80]))
                continue
            bind(symbol, value, where)
            row['verified_targets'][symbol] = '%#x (%s)' % (value, how)
    return out


rows = verify(ROWS)
near = verify(NEAR)
assert not near[0]['exact'] or DISCOVER, 'near miss 005a4750 became exact: move it to ROWS'
not_exact = [r for r in rows if not r['exact']]
if DISCOVER:
    for u in sorted(set(UNBOUND)):
        print('UNBOUND', u)
    for r in not_exact + near:
        print('NOT EXACT' if not r['exact'] else 'EXACT(near)', r['address'], r['size'], r['target_size'],
              r['symbol'][:100])
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]
# The CurrentCamera initializer 007f4ea0 passes setCamera (mov ecx, 005a5200) as the setter member pointer and builds
# its descriptor at `mov ecx, 009769d8` before calling the RefPropDescriptor constructor 005a3be0: the descriptor static
# setCamera pushes must be that object.
assert original.data(0x7f4eab, 5) == b'\xb9' + struct.pack('<I', 0x5a5200), original.data(0x7f4eab, 5)
assert original.data(0x7f4ed9, 5) == b'\xb9' + struct.pack('<I', 0x9769d8), original.data(0x7f4ed9, 5)
assert original.data(0x7f4ee1, 1) == b'\xe8' and (0x7f4ee6 + struct.unpack('<i', original.data(0x7f4ee2, 4))[0]) \
    & 0xffffffff == 0x5a3be0
assert DISCOVER or LOCAL_STATIC.get('_currentCameraProxyProp') == 0x9769d8, LOCAL_STATIC
IDENTITY['005a5200'] += ('; the initializer also passes 005a5200 itself as the setter (mov ecx, 0x5a5200 at '
                         '007f4eab) and constructs the descriptor at 0x9769d8 through 005a3be0')


# ---- vtables (current headers; there is no pending build) ------------------------------------------------------------
def compiled_vtables(unit):
    out = {}
    for name, (start, sec) in unit.definitions.items():
        if not name.startswith('??_7'):
            continue
        table = unit.sections[sec]
        end = min([x for x in unit.starts.get(sec + 1, ()) if x > start] + [table[3]])
        slots = {}
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', unit.raw, table[5] + 10 * i)
            if start <= offset < end:
                slots[(offset - start) // 4] = unit.symbols[index][0]
        out[name] = slots
    return out


vtable_checks = {}
for r in rows:
    slots_of = compiled_vtables(U[r['unit']])
    for symbol, desc in r['verified_targets'].items():
        if not symbol.startswith('??_7') or symbol in vtable_checks:
            continue
        value = int(desc.split()[0], 16)
        slots = slots_of.get(symbol, {})
        checked = []
        for k, s in sorted(slots.items()):
            got = struct.unpack('<I', original.data(value + 4 * k, 4))[0]
            if s in OWN:
                assert OWN[s] == got, ('vtable slot', symbol, k, s, hex(got))
                checked.append('%d %s = %#x (own row)' % (k, s[:70], got))
            elif s == NEAR[0][2]:
                assert got == NEAR[0][0], ('vtable slot', symbol, k, s, hex(got))
                checked.append('%d %s = %#x (near-miss row)' % (k, s[:70], got))
        vtable_checks[symbol] = {'address': '%#x' % value, 'compiled_slots': len(slots), 'checked_own_slots': checked}
# every BoundFuncDesc vtable stored by a counted constructor holds its execute row (or the near miss) in slot 1
for _bf in (BF_INSERT, BF_JOINTS, BF_BOOL, BF_VOID):
    _vt = [k for k in vtable_checks if k.startswith('??_7' + _bf)]
    assert len(_vt) == 1 and vtable_checks[_vt[0]]['checked_own_slots'], (_bf, _vt)


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
            walk(data)
        for r in found:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
exact_rows = sorted({r['address'] for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}

UNITS = [
    ('workspace tail', 0x5a4000, 0x5a67f0),
    ('boost-thread (library)', 0x5a67f0, 0x5a6bb0),
    ('log', 0x5a6bb0, 0x5a6fd0),
    ('boost-thread-tss (library)', 0x5a6fd0, 0x5a7770),
    ('filesystem', 0x5a7770, 0x5a8000),
]
unit_rows = {}
for a in range_rows:
    unit = [u for u, lo, hi in UNITS if lo <= a < hi]
    assert len(unit) == 1, hex(a)
    unit_rows.setdefault(unit[0], []).append(a)
# boundary evidence checks (strings / RTTI / imports read from the binary)
assert original.vtable_class(0x833e00)[0].startswith('.?AV?$BoundFuncDesc@VWorkspace@RBX@@'), original.vtable_class(0x833e00)
assert FUNCTIONS[0x5a5c90]['strings'][:2] == ['Workspace', 'Environment Speed %'], FUNCTIONS[0x5a5c90]['strings']
assert '005a5c90' in FUNCTIONS[0x5a6620]['call_targets'] and '005a6620' in FUNCTIONS[0x5a66b0]['call_targets']
assert original.data(0x5a6b51, 2) == b'\xff\x15' and original.imported(struct.unpack('<I', original.data(0x5a6b53, 4))[0])[1] \
    == 'GetSystemTimeAsFileTime'
assert '00568430' in FUNCTIONS[0x5a6a80]['call_targets']           # boost::lock_error thrown by the thread code
assert original.imported(struct.unpack('<I', original.data(0x5a777a, 4))[0])[1] == 'FreeLibrary'

UNIT_MAP = {
    'workspace tail 005a4000..005a67ef': (
        'v8datamodel/Workspace.cpp, continued from app-unit5a0 (unit 005a0090..). Evidence: the static initializers '
        '007f4d60..007f4ea0 ("InsertContent", "MakeJoints" / "BreakJoints" with "objects", "SetPhysicsThrottleEnabled" '
        'with "value", "ZoomToExtents", "CurrentCamera" / "Data") call the BoundFuncDesc<Workspace, ...> constructors '
        '005a4420 / 005a46a0 / 005a4860 / 005a4a00 (vtables of RTTI .?AV?$BoundFuncDesc@VWorkspace@RBX@@..., e.g. '
        '00833e00) and the RefPropDescriptor<Workspace, Camera> constructor 005a3be0; the execute / call bodies '
        '005a44d0..005a4a80 ("bad cast"); TypedStatsItem<double / float> update 005a4020 / 005a4160 (vtables 00833b9c '
        '/ 00833c64 slot 16) and their function0 constructors 005a4190 / 005a4050; the shared_ptr / create helpers '
        '005a4af0 / 005a4bd0 / 005a4cb0 and the createChildItem-style templates 005a52c0 / 005a5430 / 005a55a0 called '
        'only by WorkspaceStatsItem() 005a5c90 ("Workspace", "Environment Speed %", "Physics CPU %", "Render CPU %"); '
        'Creatable<Instance>::create<WorkspaceStatsItem> 005a6620 (malloc 0x158) and onServiceProvider 005a66b0 '
        '(its only caller is the vtable); setCamera 005a5200 (+0x3fc currentCamera, raisePropertyChanged of the '
        'CurrentCamera descriptor), the camera helper 005a5710 (findFirstChildOfType<Camera> 005a15c0, clone of '
        'cameraTemplate +0x404, setCamera), 005a5890 (camera-walk over the children, caller 00581bc0), render3dAdorn '
        '005a59e0. The DescribedNonCreatable thunks 005a43e0..005a4410 / DescribedNonCreatable() 005a4280 are counted '
        'by app-unit5a0-2008, Workspace() 005a4d90 by the workspace-lifetime receipts, 005a4140 / 005a4150 / 005a6610 '
        'by stats-service, 005a4680 by humanoid2008.'),
    'boost-thread (library) 005a67f0..005a6baf': (
        'boost 1.34.1 thread library code compiled into the exe: barrier destructor 005a67f0 (condition 005f1c70, '
        'mutex 00594cb0), thread handle close / join 005a6840 / 005a6850 (CloseHandle, WaitForSingleObject), '
        'sleep 005a6870 (xtime_get 005a6b40, GetSystemTimeAsFileTime), barrier::wait 005a6900, thread_proxy / '
        'thread start helpers 005a6990 / 005a69f0, the lock_error throw 005a6a80 (00568430, called from several units). '
        'Library code, never recovered.'),
    'log 005a6bb0..005a6fcf': 'Log.cpp (native leaves2008/Log2008.h), counted by leaves2008-working.json.',
    'boost-thread-tss (library) 005a6fd0..005a776f': (
        'boost.thread thread_specific_ptr / tss support (TlsAlloc / TlsGetValue / TlsSetValue / TlsFree, lock_error); '
        'library code, never recovered (same map as app-unit5a0).'),
    'filesystem 005a7770..005a80cf': (
        'util/FileSystem.cpp: ~VistaAPIs 005a7770 (FreeLibrary), VistaAPIs::GetIntegrity 005a7780, '
        'FileSystem::getUserAppDataDirectory 005a7ac0, FileSystem::getCacheDirectory 005a7ea0 (built here from the committed native-classes/FileSystem.cpp, '
        'read-only, and counted). '
        'The ATL CStringT<char> template instances 005a7890 (operator=(const wchar_t*)), 005a7920 '
        '(CSimpleStringT::Append(const char*, int)), 005a79e0 (CStringT(const wchar_t*)) and 005a7a80 '
        '(operator+=(const char*)) are ATL library code (005a79e0 / 005a7a80 are also called from 005f8b60 / '
        '005f9c30); they are compiled here, exact at their addresses, and used only as support bodies. The '
        'committed inactive trial receipts filesystem-trial.json / content-cache-directory-trial.json carry no counted '
        'rows; their bodies match the ones built here.'),
}
NOT_ATTEMPTED = {
    'stats item chain 005a4050 / 005a4190 / 005a4af0 / 005a4bd0 / 005a4cb0 / 005a52c0 / 005a5430 / 005a55a0 / '
    '005a5c90 / 005a6620 / 005a66b0': (
        'TypedStatsItem<T>(boost::function0<T>) constructors (declared only in v8datamodel/Stats.h, without a body; '
        'stats/Stats.h has only the const T* constructor), an unidentified 0x178-byte item class built by 005a3f30, the '
        'createChildItem-style member templates, WorkspaceStatsItem() (2431 B) and its creator: v8datamodel/Workspace.h '
        'declares WorkspaceStatsItem(const Workspace*, const World*) but the creator 005a6620 forwards three '
        'arguments (workspace, world +0x2e4, RunService), as stats/WorkspaceStatsItem.h declares; the two headers '
        'define the class differently and cannot be included together (proposal)'),
    '005a5710 / 005a5890 (camera helpers)': (
        '005a5710 returns no value (no eax load before ret) although Workspace.h declares getCamera() const as '
        'returning Camera*; it inlines isDescendentOf (parent == this || isAncestorOf), which the native Instance.h '
        'declares out of line (00422ae0). 005a5890 has no name evidence. Not built.'),
    '005a59e0 render3dAdorn': 'rejected donor body (app-unit5a0)',
}
REJECTED = {
    '005a4750 BoundFuncDesc<Workspace, void(shared_ptr<const Instances>), 1>::execute': (
        'near miss 206/260 B: the original inlines call<void> (the 12-byte virtual-inheritance member-pointer call), '
        'the committed reflection.h compiles it out of line (82 B). Variants tried, all 206 B: /U_RELEASEASSERT on '
        'and off, /fp:fast, VS2005 50727, only the MakeJoints descriptor in the unit. The same instantiation shape '
        'inlines for Selection (app-unit564 00568080, single inheritance). Not counted.'),
}
PROPOSALS = {
    'v8datamodel/Workspace.h owner': (
        'WorkspaceStatsItem: Workspace.h declares WorkspaceStatsItem(const Workspace*, const World*), but '
        'Creatable<Instance>::create<WorkspaceStatsItem> 005a6620 pushes three arguments into the 2431-byte '
        'constructor 005a5c90 (onServiceProvider 005a66b0 passes this, [this+0x2e4] world and the RunService found by '
        '00452c80), as stats/WorkspaceStatsItem.h declares it. Drop the Workspace.h declaration in favour of '
        'stats/WorkspaceStatsItem.h (or give it the third const RunService* parameter) so the Workspace unit can '
        'include one consistent declaration.'),
    'stats/Stats.h owner (stats-service)': (
        'Add TypedStatsItem<T>(boost::function0<T> func) : func(func) {} (body evidence: 005a4050 for float, vtable '
        '00833c64, and 005a4190 for double: Item() 0045ebe0, the ten vtable stores, inline function0 copy into +0x158 '
        'through the manager clone call, then the by-value argument destroyed; ret 0x20). v8datamodel/Stats.h already '
        'declares this constructor without a body.'),
}

receipt = {
    'class': 'RBX Workspace.cpp descriptors / stats items and FileSystem.cpp rows of the application range '
             '005a4000..005a8000 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)): nb.sha(p) for p in list(SOURCES.values()) + [Path(__file__).resolve()]
                + HEADERS},
    'objects': {k: nb.sha(p) for k, p in OBJ.items()},
    'unit_map': UNIT_MAP,
    'unit_rows': {u: {'rows': len(v), 'span': '%#x..%#x' % (v[0], v[-1])} for u, v in unit_rows.items()},
    'range_rows_total': len(range_rows),
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any '"ADDR"' in another receipt as counted there and drop it.
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'rows': rows,
    'row_identity': IDENTITY,
    'support_bodies': HELPERS,
    'local_statics': {k: '%#x' % v for k, v in sorted(LOCAL_STATIC.items())},
    'vtables_current_headers': vtable_checks,
    'not_exact': ['%s %s: %d/%d B, not counted' % (r['address'], r['symbol'][:60], r['size'], r['target_size'])
                  for r in not_exact + near],
    'pending_build_only': [],
    'not_attempted': NOT_ATTEMPTED,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
if not DISCOVER:
    RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit5a4: %d counted exact rows (%s); %d vtables checked, %d support bodies; %d range rows '
      '(%d counted elsewhere)' % (len(exact_rows), ' '.join(exact_rows), len(vtable_checks), len(HELPERS),
                                  len(range_rows), len(range_counted)))
