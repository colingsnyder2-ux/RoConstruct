"""Verify the inactive 2008-06 native rows of the application range 00500000..00504000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there as text).

Unit map summary (details in UNIT_MAP below):
  * ViewNew mesh builders 00500000..0050117f (HeadBuilder / HeadMesh, QuadVolume, FileMesh, PBBBuilder, BevelMesh
    builder): the viewnew owner's rows (viewnew-working.json counts 13 of them and records the others as near misses
    or pending), never rebuilt here.
  * RenderLib Profiler.cpp 00501180..00501c2f: RBX::Render::SpecData and its static helpers, built here from the new
    native-classes/AppUnit500Profiler.cpp with the new header native-headers/AppUnit500/RenderSpecData.h. The boost
    bad_lexical_cast / lexical_cast<std::string, int> bodies of the unit are boost library code (support bodies only),
    GetCyclesDifference 00501400 is an inline-asm rdtsc body and is not built.
  * RenderLib RenderScene.cpp from 00501c30 (continues past 00504000): the render-scene owner's unit (RenderStats
    constructor, RenderScene members, the RenderSceneBase inline members) with the G3D inline / template instances it
    emits; rows counted by render-scene-working.json and others; not rebuilt here.

Build: document-swap flags + /fp:fast, VS2008 RTM 21022 (without /fp:fast the SpecData constructor spills the
conditional shaderModel through a stack temporary, 333 / 325 B). No pending build. The new header path
AppUnit500/RenderSpecData.h exists in no donor include directory, so it shadows nothing.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, string literals by bytes, RTTI type
descriptors by name, vtables by their complete-object-locator RTTI, own symbols by the row proven here, COMDAT support
bodies by exactness at the bound address (their own targets verified recursively), the remaining externals by the
EXTERNAL map with asserted evidence (strings / imports / instruction bytes of the target), static data by one address
per symbol. A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit500-working.json.
Set NATIVE_APP_UNIT500_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit500'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {'profiler': R / 'native-classes/AppUnit500Profiler.cpp'}
UNIT = {'profiler': ['/fp:fast']}
HEADERS = [R / 'native-headers/AppUnit500/RenderSpecData.h']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT500_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit500-working.json'
LO, HI = 0x500000, 0x504000

OBJ, FLAGS = {}, {}
for _key, _src in SOURCES.items():
    OBJ[_key] = OUT / ('NativeAppUnit500_' + _key + '.obj')
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
PR = U['profiler']

# ---- rows ----------------------------------------------------------------------------------------------------------
ROWS = [
    (0x5011d0, 'profiler', '?getShaderModel@Render@RBX@@YAMXZ'),
    (0x5014b0, 'profiler', '?Delay@Render@RBX@@YAXI@Z'),
    (0x501520, 'profiler', '?DelayOverhead@Render@RBX@@YAXI@Z'),
    (0x501590, 'profiler', PR.sym('?getCPUMake@Render@RBX@@')),
    (0x501650, 'profiler', '?getCPUCount@Render@RBX@@YAHXZ'),
    (0x5016f0, 'profiler', '?getCPUSpeed@Render@RBX@@YAHXZ'),
    (0x5019f0, 'profiler', PR.sym('?getMaxRes@Render@RBX@@')),
    (0x501ae0, 'profiler', '??0SpecData@Render@RBX@@QAE@XZ'),
]
ROWS.sort()
for _a, _u, _s in ROWS:
    assert LO <= _a < HI and _a in FUNCTIONS, hex(_a)
    assert _s in U[_u].bodies, (hex(_a), _s)
assert len({a for a, _, _ in ROWS}) == len(ROWS) and len({s for _, _, s in ROWS}) == len(ROWS)
OWN = {s: a for a, _, s in ROWS}

# Identity of the rows (read from the binary):
IDENTITY = {}
# SpecData(): sizeof 0x84 stack object of the DebugSettings "Profile" getters (initializers 007f2c60 / 007f2c90 /
# 007f2cc0 name VideoMemory / CpuSpeed / CpuCount), which call 00501ae0 and read +0x4 / +0x8 / +0xc.
for _getter, _init, _name, _off in [(0x563230, 0x7f2c60, 'VideoMemory', 4), (0x563260, 0x7f2c90, 'CpuSpeed', 8),
                                    (0x563290, 0x7f2cc0, 'CpuCount', 0xc)]:
    assert FUNCTIONS[_init]['strings'] == ['Profile', _name], (hex(_init), FUNCTIONS[_init]['strings'])
    assert original.data(_getter, 6) == b'\x81\xec\x84\x00\x00\x00', hex(_getter)          # sub esp, 0x84
    assert original.data(_getter + 0xb, 1) == b'\xe8' and (_getter + 0x10 + struct.unpack(
        '<i', original.data(_getter + 0xc, 4))[0]) & 0xffffffff == 0x501ae0, hex(_getter)
    assert original.data(_getter + 0x10, 3) == bytes([0x8b, 0x70, _off]), hex(_getter)     # mov esi, [eax + off]
IDENTITY['00501ae0'] = ('constructor of the 0x84-byte stack SpecData of the DebugSettings "Profile" getters 00563230 / '
                        '00563260 / 00563290 (VideoMemory +0x4, CpuSpeed +0x8, CpuCount +0xc; initializers 007f2c60 / '
                        '007f2c90 / 007f2cc0), destroyed by the implicit destructor 005631c0')
# the helpers are reached from the constructor (own REL32 targets verified below) and read their own strings
for _a, _strings in [(0x501590, ['HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0\\'
                                 'ProcessorNameString']),
                     (0x501650, ['HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\%d']),
                     (0x5016f0, ['HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0\\~MHz']),
                     (0x5011d0, ['GL_ATI_fragment_shader', 'GL_NV_fragement_program', 'GL_ATI_texture_env_combine3',
                                 'GL_NV_texture_shader3', 'GL_NV_register_combiners'])]:
    assert all(s in FUNCTIONS[_a].get('strings', []) for s in _strings), (hex(_a), FUNCTIONS[_a].get('strings'))
for _a, _imports in [(0x5014b0, ['QueryPerformanceFrequency', 'QueryPerformanceCounter']),
                     (0x501520, ['QueryPerformanceFrequency', 'QueryPerformanceCounter']),
                     (0x5019f0, ['GetSystemMetrics'])]:
    assert all(any(i.endswith('!' + n) for i in FUNCTIONS[_a]['imports']) for n in _imports), (hex(_a), _imports)
# getCPUSpeed pushes Delay / DelayOverhead as the GetCyclesDifference callback (push imm32 at 00501772 / 00501780)
assert original.data(0x501772, 5) == b'\x68' + struct.pack('<I', 0x5014b0)
assert original.data(0x501780, 5) == b'\x68' + struct.pack('<I', 0x501520)
IDENTITY['005014b0'] = 'pushed as the GetCyclesDifference callback by getCPUSpeed (push 0x5014b0 at 00501772)'
IDENTITY['00501520'] = 'pushed as the GetCyclesDifference callback by getCPUSpeed (push 0x501520 at 00501780)'
for _a, _what in [(0x5011d0, 'shaderModel'), (0x5016f0, 'CPUSpeed'), (0x501650, 'cpuCount'), (0x501590, 'cpu'),
                  (0x5019f0, 'resolution')]:
    IDENTITY['%08x' % _a] = 'called by the SpecData constructor for %s (REL32 verified as an own row)' % _what

# ---- externals ------------------------------------------------------------------------------------------------------
EXTERNAL = {
    # G3D 6.09 GLCaps::supports(const std::string&): 16 bytes, Set<std::string>::contains (00470600) on the static
    # extensionSet 009336b0 (asserted below)
    '?supports@GLCaps@G3D@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x471060,
    # GLCaps::vendor / renderer: their assertion strings name them (asserted below)
    '?vendor@GLCaps@G3D@@SAABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ': 0x470880,
    '?renderer@GLCaps@G3D@@SAABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ': 0x4709a0,
    # G3D 6.09 library bodies (library recipe g3d-6.09 sources DXCaps.cpp / format.cpp / RegistryUtil.cpp; the
    # RegistryUtil entries are told apart by their imports, asserted below)
    '?videoMemorySize@DXCaps@G3D@@SA_KXZ': 0x476470,
    '?format@G3D@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBDZZ': 0x509b10,
    '?keyExists@RegistryUtil@G3D@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x513f50,
    '?readInt32@RegistryUtil@G3D@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAH@Z': 0x513fe0,
    '?readString@RegistryUtil@G3D@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAV34@@Z':
        0x514190,
    # GetCyclesDifference: evidence name, the inline-asm row of this unit (not built)
    '?GetCyclesDifference@Render@RBX@@YA_JP6AXI@ZI@Z': 0x501400,
    '__alldiv': 0x6a1c30,
    '__allmul': 0x6a16d0,
}
assert original.data(0x471060, 16) == bytes.fromhex('8b44240450b9b03693 00e891f5ffffc3'.replace(' ', '')), \
    original.data(0x471060, 16).hex()
assert 'Cannot call GLCaps::vendor before GLCaps::init().' in FUNCTIONS[0x470880]['strings']
assert 'Cannot call GLCaps::renderer before GLCaps::init().' in FUNCTIONS[0x4709a0]['strings']
_imp = {a: {i.split('!')[1] for i in FUNCTIONS[a]['imports']} for a in (0x513f50, 0x513fe0, 0x514190, 0x476470)}
assert 'RegQueryValueExA' not in _imp[0x513f50] and 'RegOpenKeyExA' in _imp[0x513f50]
assert 'RegQueryValueExA' in _imp[0x513fe0] and not any(i.startswith('??4') for i in _imp[0x513fe0])
assert 'RegQueryValueExA' in _imp[0x514190] and any(i.startswith('??4') for i in _imp[0x514190])
assert 'CoCreateInstance' in _imp[0x476470]
# __alldiv / __allmul / format / videoMemorySize are bound under the same names by committed receipts
# (app-unit440, app-unit5a4, render-settings, ...).
# G3D GLCaps extension flags read by the inline supports_GL_ARB_*() accessors (static bools of GLCaps)
DATA_EXTERNAL = {
    '?_supports_GL_ARB_fragment_shader@GLCaps@G3D@@0_NA',
    '?_supports_GL_ARB_vertex_shader@GLCaps@G3D@@0_NA',
    '?_supports_GL_ARB_shader_objects@GLCaps@G3D@@0_NA',
    '?_supports_GL_ARB_shading_language_100@GLCaps@G3D@@0_NA',
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
    return len(ht) == len(hb) and match.exact_match(ht, htr, hb, hr)


PENDING_HELPERS = []


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
        # COMDAT support body compiled here but not a counted row: exact at the bound address, never counted; its own
        # targets are verified recursively
        assert body_exact_at(unit, symbol, value) or DISCOVER, (where, symbol, hex(value))
        if symbol not in HELPERS:
            HELPERS[symbol] = '%#x (support body exact at the bound address, not counted here)' % value
            PENDING_HELPERS.append((value, symbol))
        return 'support body exact at the bound address (not counted here)'
    if symbol in unit.definitions or symbol in DATA_EXTERNAL or symbol.startswith(('__TI', '??_R')):
        assert any(lo <= value < hi for lo, hi in DATA_SECTIONS), (where, symbol, hex(value))
        LOCAL_STATIC.setdefault(symbol, value)
        return 'static data (one address per symbol)'
    return None


def check_body(unit, address, name, row):
    body, refs = unit.bodies[name]
    target, target_refs, _ = match.target('2008-06', '%08x' % address)
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


def verify(rows):
    out = []
    for address, key, name in rows:
        unit = U[key]
        body, refs = unit.bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        exact = len(target) == len(body) and match.exact_match(target, target_refs, body, refs)
        row = {'address': '%08x' % address, 'unit': key, 'symbol': name, 'size': len(body),
               'target_size': len(target), 'exact': bool(exact), 'verified_targets': {}, 'local_eh': []}
        out.append(row)
        if exact:
            check_body(unit, address, name, row)
    return out


rows = verify(ROWS)
# support bodies: verify their targets too (recursively; library bodies, never counted)
support_targets = {}
while PENDING_HELPERS:
    _value, _symbol = PENDING_HELPERS.pop()
    _row = {'verified_targets': {}, 'local_eh': []}
    check_body(PR, _value, _symbol, _row)
    support_targets[_symbol] = {'address': '%#x' % _value, 'verified_targets': _row['verified_targets']}
not_exact = [r for r in rows if not r['exact']]
if DISCOVER:
    for u in sorted(set(UNBOUND)):
        print('UNBOUND', u)
    for r in not_exact:
        print('NOT EXACT', r['address'], r['size'], r['target_size'], r['symbol'][:100])
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]
# the SpecData::glLoaded static is the byte the constructor compares (cmp byte ptr [0x972888], bl at 00501b06)
assert DISCOVER or LOCAL_STATIC.get('?glLoaded@SpecData@Render@RBX@@2_NA') == 0x972888, LOCAL_STATIC
assert original.data(0x501b06, 6) == b'\x38\x1d' + struct.pack('<I', 0x972888)


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


# bad_lexical_cast (boost library class): its vtable is stored by the support copy constructor; every compiled slot
# is a support body exact at the address the original vtable holds
vtable_checks = {}
_vt_symbol = '??_7bad_lexical_cast@boost@@6B@'
_vt_address = BINDING.get(_vt_symbol, (None,))[0]
if _vt_address is not None:
    _checked = []
    for _k, _s in sorted(compiled_vtables(PR).get(_vt_symbol, {}).items()):
        _got = struct.unpack('<I', original.data(_vt_address + 4 * _k, 4))[0]
        if _s in PR.bodies:
            assert body_exact_at(PR, _s, _got), (_k, _s, hex(_got))
            HELPERS.setdefault(_s, '%#x (support body exact at the vtable slot, not counted here)' % _got)
            _checked.append('%d %s = %#x (support body exact)' % (_k, _s[:60], _got))
        else:
            _checked.append('%d %s = %#x (deleting destructor, checked below as ??_G)' % (_k, _s[:60], _got))
    vtable_checks[_vt_symbol] = {'address': '%#x' % _vt_address, 'checked_slots': _checked}
assert DISCOVER or vtable_checks, BINDING.keys()
# The remaining boost bad_lexical_cast bodies of the unit (library code, support only, compared at their addresses):
# the scalar deleting destructor is vtable slot 0 (the compiled vtable names it ??_E, which MSVC folds onto ??_G when
# there is no array delete), the destructor 00501190 is reached only from unwind funclets (007cb361 / 007d3ec1 /
# 007d3ee1) and the copy constructor 00501860 only from the throw info's catchable types.
for _s, _a, _why in [('??_Gbad_lexical_cast@boost@@UAEPAXI@Z', 0x5011a0, 'vtable slot 0'),
                     ('??1bad_lexical_cast@boost@@UAE@XZ', 0x501190, 'unwind funclet target'),
                     ('??0bad_lexical_cast@boost@@QAE@ABV01@@Z', 0x501860, 'catchable-type copy constructor')]:
    if _a == 0x5011a0:
        assert struct.unpack('<I', original.data(_vt_address, 4))[0] == _a
    assert body_exact_at(PR, _s, _a), (_s, hex(_a))
    _row = {'verified_targets': {}, 'local_eh': []}
    check_body(PR, _a, _s, _row)
    HELPERS.setdefault(_s, '%#x (support body exact at the bound address, %s, not counted here)' % (_a, _why))
    support_targets[_s] = {'address': '%#x' % _a, 'verified_targets': _row['verified_targets']}
assert not UNBOUND or DISCOVER, UNBOUND


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
    ('viewnew mesh builders', 0x500000, 0x501180),
    ('profiler', 0x501180, 0x501c30),
    ('render scene', 0x501c30, 0x504000),
]
unit_rows = {}
for a in range_rows:
    unit = [u for u, lo, hi in UNITS if lo <= a < hi]
    assert len(unit) == 1, hex(a)
    unit_rows.setdefault(unit[0], []).append(a)
# boundary evidence read from the binary
assert original.vtable_class(0x827224)[0] == '.?AVbad_lexical_cast@boost@@'           # 00501190 / 005011a0 store it
assert original.data(0x501180, 6) == b'\xb8' + struct.pack('<I', 0x827230) + b'\xc3'   # what(): "bad lexical cast..."
assert original.string(0x827230).startswith('bad lexical cast')
assert FUNCTIONS[0x501c30]['callers'] == ['00504fd0'] and FUNCTIONS[0x501c30]['call_targets'] == ['00512060']
assert 0x501040 + FUNCTIONS[0x501040]['size'] <= 0x501180 < 0x501190                     # BevelMesh builder ends 0050117d

UNIT_MAP = {
    'viewnew mesh builders 00500000..0050117f': (
        'ViewNew mesh builder rows of the viewnew owner (native-headers/ViewNew/HeadMesh.h, QuadVolume.h, FileMesh.h, '
        'PBBMesh.h, BevelMesh.h): HeadBuilder build* 00500020..00500140 (HeadBuilder vtable slots bound by '
        'viewnew-working.json), HeadMesh constructors 00500180 / 00500350 / 005004d0, QuadVolume 00500690 / 00500ca0 '
        '/ 00500d80..00501000, FileMesh::loadFromMeshFile 00500780 with its catch funclet 00500b7f and 00500b90, '
        'PBBBuilder 00500d30, BevelMesh builder 00501040 (ends 0050117d). viewnew-working.json counts 13 of these and '
        'records the rest as near misses (x87 / register allocation) or pending (ContentProvider::requestContentFile); '
        'extending them is the viewnew owner\'s work, not rebuilt here.'),
    'profiler 00501180..00501c2f': (
        'RenderLib Profiler.cpp (donor Client/Rendering/RenderLib/Profiler.cpp, RBX::Render): the boost '
        'bad_lexical_cast virtuals what 00501180 (returns the "bad lexical cast..." literal 00827230), destructor '
        '00501190 and deleting destructor 005011a0 (vtable 00827224, RTTI .?AVbad_lexical_cast@boost@@), '
        'getShaderModel 005011d0 (GL extension strings), GetCyclesDifference 00501400 with its __except filter 00501484 '
        'and handler block 0050148a (inline-asm rdtsc, not built), Delay 005014b0 / DelayOverhead 00501520 '
        '(QueryPerformanceFrequency / Counter), getCPUMake 00501590, getCPUCount 00501650, getCPUSpeed 005016f0 '
        '(CentralProcessor registry keys), the boost lexical_cast<std::string, int> instance with lexical_stream '
        'operator>> 00501800, bad_lexical_cast copy constructor 00501860, throw_exception 00501890 and lexical_cast '
        '005018d0 (boost library templates also called from 005be233 / 005e013b / 00601206 / 00654f67, so not '
        'only this unit: support bodies only), getMaxRes 005019f0 (GetSystemMetrics) and SpecData::SpecData 00501ae0 '
        '(ends 00501c25). Built here: the eight RBX rows.'),
    'render scene 00501c30..00503fff': (
        'RenderLib RenderScene.cpp (render-scene owner, native-headers/RenderLib/RenderScene2008.h / '
        'RenderSceneRender2008.h / RenderSceneNew2008.h), continued past 00504000: RenderStats() 00501c30 (six '
        'G3D::Stopwatch constructors 00512060 at 0x58 strides; only caller the RenderScene constructor 00504fd0), G3D '
        'inline / template instances it emits (Vector3::operator+ 00501c70, CoordinateFrame::pointToObjectSpace '
        '00501ca0, Sphere(const Vector3&, float) 00501d10, LightingParameters::operator= 00501d80, '
        'Array<Vector3> / Array<GLight> inArray / realloc / resize / append 00501ee0..005026d0 and 00502f40..00503100, '
        'VAR constructor / operator= 00502910 / 00502ab0, Sky::getEnvironmentMap 00502a00, '
        'ReferenceCountedPointer<Shader> destructor 00502a70, G3D::Lighting constructor / destructor / create '
        '00503820 / 005038a0 / 00503940 / 00503960), the RenderSurface copy constructor 00502500, RenderScene members '
        '(00502100, 00502370, 005023e0, 00502560, 00502810, 00502b00, 00502b90, 00502d30, 00502e70, 00503090, '
        '00503110, 005032a0, 005033e0, 00503540, 005035e0, 00503cc0, 00503ea0, 00503fc0, 00503fe0) and the '
        'RenderSceneBase inline members 005039d0..00503cb0 ("shouldn\'t be here" 005039e0). Rows counted by '
        'render-scene-working.json, app-unit548 / app-unit550 support and viewnew-part-mesh are listed in '
        'range_rows_counted_by_other_receipts; the rest needs the render-scene owner\'s layout and is not rebuilt '
        'here (not attempted).'),
}
NOT_BUILT = {
    'GetCyclesDifference 00501400 (+ filter 00501484, handler block 0050148a)': (
        'the body is inline assembly (rdtsc, push / call DelayFunction / pop ebx) under __try / __except(1); inline '
        'assembly is not allowed in native sources. The header declares it with external linkage so getCPUSpeed can '
        'call it (the original is a static helper; the REL32 call is the same).'),
}
REJECTED = {
    'getCPUMake 00501590 / getMaxRes 005019f0 with external linkage': (
        '183 B not exact / 224 of 226 B: the sret pointer is loaded late (mov esi, [esp + 0x54] after the registry '
        'read). Exact only as static helpers, like the donor Profiler.cpp.'),
    'getCPUCount 00501650 as while (keyExists(format(...))) ++count;': (
        '158 of 160 B (the temporary is destroyed before the test). The scoped named key with an early break is '
        'exact; also rejected: for (;; ++i) return-in-loop (164 B), keyExists(format(...).c_str()) (163 B), '
        'do / while with a bool (111 B).'),
    'SpecData() without /fp:fast': '333 / 325 B: the conditional shaderModel is spilled through a stack temporary.',
    'whole unit under VS2005 50727': 'getShaderModel / getCPUSpeed / SpecData() not exact; VS2008 RTM 21022 kept.',
}
PROPOSALS = {
    'settings-items owner (DebugSettings "Profile" getters)': (
        'native-headers/AppUnit500/RenderSpecData.h now declares the 2008 RBX::Render::SpecData (0x84 bytes: '
        'shaderModel +0x0, videoMemory +0x4, CPUSpeed +0x8, cpuCount +0xc, glVendor +0x10, gfxcard +0x2c, cpu +0x48, '
        'ram +0x64, resolution +0x68; static glLoaded 00972888). The "Profile" getters 00563230..00563a50 and the '
        'implicit destructor 005631c0 listed as not attempted in settings-items-working.json can include it '
        'read-only (or the header can move to a shared RenderLib path with its owner\'s agreement).'),
}

receipt = {
    'class': 'RBX::Render::SpecData and the RenderLib Profiler.cpp helpers of the application range '
             '00500000..00504000 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)): nb.sha(p) for p in list(SOURCES.values()) + [Path(__file__).resolve()]
                + HEADERS},
    'objects': {k: nb.sha(p) for k, p in OBJ.items()},
    'layout': {
        'RBX::Render::SpecData': {
            'size': '0x84 (sub esp, 0x84 in the Profile getters 00563230 / 00563260 / 00563290)',
            'shaderModel': '+0x00 float', 'videoMemory': '+0x04 int', 'CPUSpeed': '+0x08 int', 'cpuCount': '+0x0c int',
            'glVendor': '+0x10 std::string', 'gfxcard': '+0x2c std::string', 'cpu': '+0x48 std::string',
            'ram': '+0x64 int', 'resolution': '+0x68 std::string', 'glLoaded': 'static bool 0x972888'},
    },
    'unit_map': UNIT_MAP,
    'unit_rows': {u: {'rows': len(v), 'span': '%#x..%#x' % (v[0], v[-1])} for u, v in unit_rows.items()},
    'range_rows_total': len(range_rows),
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any '"ADDR"' in another receipt as counted there and drop it.
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'rows': rows,
    'row_identity': IDENTITY,
    'support_bodies': HELPERS,
    'support_body_targets': support_targets,
    'local_statics': {k: '%#x' % v for k, v in sorted(LOCAL_STATIC.items())},
    'vtables_current_headers': vtable_checks,
    'not_exact': ['%s %s: %d/%d B, not counted' % (r['address'], r['symbol'][:60], r['size'], r['target_size'])
                  for r in not_exact],
    'pending_build_only': [],
    'not_built': NOT_BUILT,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
if not DISCOVER:
    RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit500: %d counted exact rows (%s); %d support bodies; %d range rows (%d counted elsewhere)' % (
    len(exact_rows), ' '.join(exact_rows), len(HELPERS), len(range_rows), len(range_counted)))
