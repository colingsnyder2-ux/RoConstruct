"""Verify the inactive 2008-06 native rows of the application range 005e0000..005e4000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there as text).

Unit map summary (details in UNIT_MAP below):
  * Lighting.cpp tail 005e0000..005e275f (the unit starts at 005df0c0; app-unit5dc-2008 maps its head). The Lighting
    constructor / destructor / child notifications / signal and the boost tokenizer / lexical_cast instances are
    counted by lighting2008-working.json. Built here from native-classes/AppUnit5E0LightingReflection.cpp (/fp:fast)
    against the committed native v8datamodel/Lighting2008.h and reflection/*.h (read-only): the property-descriptor
    constructors and getset factories, the BoundFuncDesc constructors / execute, getTimeStr and the boost
    to_simple_string formatter instances it calls.
  * JointInstance.cpp head 005e2760..005e3fff (continues to 005e50bf, app-unit5e4's map). Built here from
    native-classes/AppUnit5E0JointReflection.cpp: the three property getset factories, whose bodies and symbols depend
    only on member-pointer types. The rest needs the 2008 JointInstance declaration (no AutoJoint; class names
    const char[]), which the committed native JointInstance.h does not give (proposal); mapped only.

Build: document-swap flags, VS2008 RTM 21022; the Lighting unit adds /fp:fast (getMinutesAfterMidnight 005e0610 and the
setters' compare order need it; every counted Lighting row is exact with it). A pending build
(/DNATIVE_APPUNIT5E0_PENDING, /fp:fast) uses generated copies of v8datamodel/Lighting2008.h (proposed getter / setter
declarations) and reflection/reflection.h (the stats-service proposal: BoundFuncDesc::call assigns with
Value::operator=) under out/native-layouts/app-unit5e0/pending/; its rows are recorded exact=false (pending-build-
only) and never counted. Vtable slots are checked on the objects built from the current headers only.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, string literals by bytes, RTTI type
descriptors by name, vtables by their complete-object-locator RTTI, own symbols by the row proven here, COMDAT support
bodies by exactness at the bound address, the remaining externals by the explicit EXTERNAL map (evidence name or
another receipt's binding), static data by one address per symbol. A row is counted only when no other receipt
counts it. No new header is created, so no existing recorder is shadowed.
Writes work/2008-06/shared-layouts/app-unit5e0-working.json.
Set NATIVE_APP_UNIT5E0_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit5e0'
OUT.mkdir(parents=True, exist_ok=True)
PENDING_DIR = OUT / 'pending'
SOURCES = {
    'lighting': R / 'native-classes/AppUnit5E0LightingReflection.cpp',
    'lighting-pending': R / 'native-classes/AppUnit5E0LightingReflection.cpp',
    'joint': R / 'native-classes/AppUnit5E0JointReflection.cpp',
}
HEADERS = [R / 'native-headers/v8datamodel/Lighting2008.h', R / 'native-headers/v8datamodel/JointInstance.h',
           R / 'native-headers/reflection/reflection.h', R / 'native-headers/reflection/type.h']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT5E0_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit5e0-working.json'
LO, HI = 0x5e0000, 0x5e4000

# ---- pending header copies (proposals; the shared headers are not edited) -------------------------------------------
LIGHTING_ANCHOR = '\tprotected:\n\t\tvirtual bool askAddChild'
LIGHTING_PROPOSAL = '''\tpublic:
		// proposal (app-unit5e0): the Lighting reflection getters / setters, named after the descriptors built by
		// the static initializers 007f69d0..007f6c40 (member addresses as immediates)
		float getMoonPhase();                                   // 005df480 ("GetMoonPhase")
		double getMinutesAfterMidnight();                       // 005e0610
		void setMinutesAfterMidnight(double value);             // 005e26e0
		void setTimeStr(const std::string& value);              // 005e2730
		void setTime(const boost::posix_time::time_duration& value);   // 005e2570
		float getGeographicLatitude() const;                    // 005df490
		void setGeographicLatitude(float value);                // 005e2670
		G3D::Color3 getShadowColor3() const;                    // 005df4a0
		void setShadowColor3(G3D::Color3 value);                // 005e2540
		void setShadowColor(G3D::Color4 value);                 // 005e2030
		float getBrightness() const { return brightness; }                  // 004d6fe0
		void setBrightness(float value);                        // 005e2420
		G3D::Color3 getColorShiftTop() const { return colorShiftTop; }      // 004d6f80
		void setColorShiftTop(G3D::Color3 value);               // 005e22c0
		G3D::Color3 getColorShiftBottom() const { return colorShiftBottom; } // 004d6fb0
		void setColorShiftBottom(G3D::Color3 value);            // 005e2370
		G3D::Color3 getAmbient() const { return ambient; }                  // 004d6ff0
		void setAmbient(G3D::Color3 value);                     // 005e2490

'''
REFLECTION_ANCHOR = '\t\t\t\treturnValue.set<ReturnType>((o->*function)());\n'
REFLECTION_PROPOSAL = '\t\t\t\treturnValue = (o->*function)(); // 2008: Value::operator= (call<double> 005e17f0)\n'
(PENDING_DIR / 'v8datamodel').mkdir(parents=True, exist_ok=True)
(PENDING_DIR / 'reflection').mkdir(parents=True, exist_ok=True)
_t = (R / 'native-headers/v8datamodel/Lighting2008.h').read_text()
assert _t.count(LIGHTING_ANCHOR) == 1
(PENDING_DIR / 'v8datamodel/Lighting2008.h').write_text(_t.replace(LIGHTING_ANCHOR, LIGHTING_PROPOSAL + LIGHTING_ANCHOR))
_t = (R / 'native-headers/reflection/reflection.h').read_text()
assert _t.count(REFLECTION_ANCHOR) == 1
(PENDING_DIR / 'reflection/reflection.h').write_text(_t.replace(REFLECTION_ANCHOR, REFLECTION_PROPOSAL))

UNIT_PRE = {'lighting': [], 'lighting-pending': ['/I' + str(PENDING_DIR)], 'joint': []}
UNIT_POST = {'lighting': ['/fp:fast'], 'lighting-pending': ['/fp:fast', '/DNATIVE_APPUNIT5E0_PENDING'], 'joint': []}
OBJ, FLAGS = {}, {}
for _key, _src in SOURCES.items():
    OBJ[_key] = OUT / ('NativeAppUnit5E0_' + _key + '.obj')
    _flags = nb.flags()
    _i = next(k for k, x in enumerate(_flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    FLAGS[_key] = _flags[:_i] + UNIT_PRE[_key] + _flags[_i:] + UNIT_POST[_key]
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
LT, LP, JT = U['lighting'], U['lighting-pending'], U['joint']

# ---- rows ----------------------------------------------------------------------------------------------------------
L = 'VLighting@RBX@@'
BF = '?$BoundFuncDesc@' + L
BF_FLOAT, BF_V3, BF_DBL, BF_SET = BF + '$$A6AMXZ$0A@@', BF + '$$A6A?AVVector3@G3D@@XZ$0A@@', BF + '$$A6ANXZ$0A@@', \
    BF + '$$A6AXN@Z$00@'
STR = '?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
TD = 'Vtime_duration@'
ROWS = [
    (0x5e02d0, 'lighting', LT.sym('??$getset@P8Lighting@RBX@@BE' + STR + 'XZP812@AEXABV34@@Z@')),
    (0x5e0320, 'lighting', LT.sym('??$getset@P8Lighting@RBX@@BEMXZP812@AEXM@Z@')),
    (0x5e0370, 'lighting', LT.sym('??$getset@P8Lighting@RBX@@BE?AVColor3@G3D@@XZP812@AEXV34@@Z@')),
    (0x5e06b0, 'lighting', LT.sym('??$to_simple_string_type@D@posix_time@boost@@YA' + STR + TD)),
    (0x5e0ba0, 'lighting', LT.sym('?to_simple_string@posix_time@boost@@YA' + STR + TD)),
    (0x5e0be0, 'lighting', '?getTimeStr@Lighting@RBX@@QBE' + STR + 'XZ'),
    (0x5e1170, 'lighting', LT.sym('??$?0P8Lighting@RBX@@BE' + STR + 'XZ')),
    (0x5e1220, 'lighting', LT.sym('??$?0P8Lighting@RBX@@BEMXZP801@AEXM@Z@')),
    (0x5e12d0, 'lighting', LT.sym('??$?0P8Lighting@RBX@@BE?AVColor3@G3D@@XZ')),
    (0x5e1560, 'lighting', LT.sym('??0' + BF_FLOAT)),
    (0x5e1690, 'lighting', LT.sym('??0' + BF_V3)),
    (0x5e1780, 'lighting', LT.sym('??0' + BF_DBL)),
    (0x5e18c0, 'lighting', LT.sym('??0' + BF_SET)),
    (0x5e1960, 'lighting', LT.sym('?execute@' + BF_SET)),
    (0x5e2920, 'joint', JT.sym('??$getset@P8JointInstance@RBX@@BEPAVPartInstance@2@XZ')),
    (0x5e2970, 'joint', JT.sym('??$getset@P8JointInstance@RBX@@BEABVCoordinateFrame@G3D@@XZ')),
    (0x5e29c0, 'joint', JT.sym('??$getset@P8Motor@RBX@@BEMXZP812@AEXM@Z@')),
]
# Built from the current headers, not exact (recorded, never counted); the reason is in NEAR_REASON.
NEAR = [
    (0x5e15d0, 'lighting', LT.sym('??$call@M@' + BF_FLOAT)),
    (0x5e1630, 'lighting', LT.sym('?execute@' + BF_FLOAT)),
    (0x5e1700, 'lighting', LT.sym('?execute@' + BF_V3)),
    (0x5e17f0, 'lighting', LT.sym('??$call@N@' + BF_DBL)),
    (0x5e1860, 'lighting', LT.sym('?execute@' + BF_DBL)),
]
NEAR_REASON = {
    0x5e15d0: 'the native reflection.h call<ReturnType> uses Value::set<T>, which stays out of line (82 B); the '
              'original assigns through Value::operator= inline (94 B). Exact with the stats-service reflection.h '
              'proposal (pending build)',
    0x5e1630: 'execute calls call<float> (see 0x5e15d0): 105 vs 90 B; exact in the pending build',
    0x5e1700: 'execute with call<Vector3> inlined: same 114 B, different frame slots (the native template lets the '
              'bad_cast and the Vector3 temporaries share one slot; body-movers records the same near miss for '
              'BodyPosition 006328f0); not exact in the pending build either',
    0x5e17f0: 'call<double>, see 0x5e15d0 (39 vs 100 B); exact in the pending build. ICF-shared: stats-service binds '
              'BoundFuncDesc<Stats::Item, double()>::call<double> to the same body (pending-build-only there)',
    0x5e1860: 'execute calls call<double> (see 0x5e17f0): 105 vs 90 B; exact in the pending build',
}
# Pending build (generated header copies): exact=false here by rule, never counted.
PENDING_ROWS = [
    (0x5e0610, 'lighting-pending', '?getMinutesAfterMidnight@Lighting@RBX@@QAENXZ'),
    (0x5e15d0, 'lighting-pending', LP.sym('??$call@M@' + BF_FLOAT)),
    (0x5e1630, 'lighting-pending', LP.sym('?execute@' + BF_FLOAT)),
    (0x5e17f0, 'lighting-pending', LP.sym('??$call@N@' + BF_DBL)),
    (0x5e1860, 'lighting-pending', LP.sym('?execute@' + BF_DBL)),
    (0x5e2030, 'lighting-pending', '?setShadowColor@Lighting@RBX@@QAEXVColor4@G3D@@@Z'),
    (0x5e22c0, 'lighting-pending', '?setColorShiftTop@Lighting@RBX@@QAEXVColor3@G3D@@@Z'),
    (0x5e2370, 'lighting-pending', '?setColorShiftBottom@Lighting@RBX@@QAEXVColor3@G3D@@@Z'),
    (0x5e2420, 'lighting-pending', '?setBrightness@Lighting@RBX@@QAEXM@Z'),
    (0x5e2490, 'lighting-pending', '?setAmbient@Lighting@RBX@@QAEXVColor3@G3D@@@Z'),
    (0x5e2540, 'lighting-pending', '?setShadowColor3@Lighting@RBX@@QAEXVColor3@G3D@@@Z'),
    (0x5e2570, 'lighting-pending', '?setTime@Lighting@RBX@@QAEXABVtime_duration@posix_time@boost@@@Z'),
    (0x5e2670, 'lighting-pending', '?setGeographicLatitude@Lighting@RBX@@QAEXM@Z'),
    (0x5e26e0, 'lighting-pending', '?setMinutesAfterMidnight@Lighting@RBX@@QAEXN@Z'),
    (0x5e2730, 'lighting-pending', '?setTimeStr@Lighting@RBX@@QAEXABV' + STR[3:] + '@Z'),
]
ROWS.sort()
for _a, _u, _s in ROWS + NEAR + PENDING_ROWS:
    assert LO <= _a < HI and _a in FUNCTIONS, hex(_a)
    assert _s in U[_u].bodies, (hex(_a), _s)
assert len({a for a, _, _ in ROWS}) == len(ROWS) and len({s for _, _, s in ROWS}) == len(ROWS)
assert not {a for a, _, _ in ROWS} & {a for a, _, _ in NEAR + PENDING_ROWS}
OWN = {s: a for a, _, s in ROWS}
PENDING_OWN = {s: a for a, _, s in PENDING_ROWS}
NEAR_OWN = {s: a for a, _, s in NEAR}

# Identity of the Lighting descriptor rows: each static initializer of this unit holds the bound member functions as
# immediates, the descriptor object as `mov ecx, imm32` and calls exactly one constructor row; its strings are the
# descriptor name (and category / argument name).
INITIALIZERS = {
    0x7f69d0: (0x5e1170, ['Data', 'TimeOfDay'], [0x5e0be0, 0x5e2730], 0x97a91c),
    0x7f6a10: (0x5e1220, ['Data', 'GeographicLatitude'], [0x5df490, 0x5e2670], 0x97a9f8),
    0x7f6a50: (0x5e1560, ['GetMoonPhase'], [0x5df480], 0x97a8c0),
    0x7f6a80: (0x5e1690, ['GetMoonDirection'], [0x5df4d0], 0x97aa18),
    0x7f6ab0: (0x5e1690, ['GetSunDirection'], [0x5df500], 0x97a9b8),
    0x7f6ae0: (0x5e1780, ['GetMinutesAfterMidnight'], [0x5e0610], 0x97aa90),
    0x7f6b10: (0x5e18c0, ['minutes', 'SetMinutesAfterMidnight'], [0x5e26e0], 0x97a938),
    0x7f6b40: (0x5e12d0, ['Appearance', 'ShadowColor'], [0x5df4a0, 0x5e2540], 0x97aa58),
    0x7f6b80: (0x5e1220, ['Appearance', 'Brightness'], [0x4d6fe0, 0x5e2420], 0x97a980),
    0x7f6bc0: (0x5e12d0, ['Appearance', 'ColorShift_Top'], [0x4d6f80, 0x5e22c0], 0x97a900),
    0x7f6c00: (0x5e12d0, ['Appearance', 'ColorShift_Bottom'], [0x4d6fb0, 0x5e2370], 0x97a99c),
    0x7f6c40: (0x5e12d0, ['Appearance', 'Ambient'], [0x4d6ff0, 0x5e2490], 0x97aa74),
}
# pending static symbol -> descriptor object the matching initializer constructs
PENDING_STATICS = {'prop_Time': 0x97a91c, 'prop_GeographicLatitude': 0x97a9f8, 'prop_ShadowColor': 0x97aa58,
                   'prop_Brightness': 0x97a980, 'prop_ColorShiftTop': 0x97a900, 'prop_ColorShiftBottom': 0x97a99c,
                   'prop_Ambient': 0x97aa74}
IDENTITY = {}
for _init, (_ctor, _strings, _members, _obj) in INITIALIZERS.items():
    _f = FUNCTIONS[_init]
    assert _f['strings'] == _strings and '%08x' % _ctor in _f['call_targets'], (hex(_init), _f['strings'])
    _code = original.data(_init, 0x40)
    for _m in _members:
        assert struct.pack('<I', _m) in _code, (hex(_init), hex(_m))
    assert b'\xb9' + struct.pack('<I', _obj) in _code, (hex(_init), hex(_obj))
    IDENTITY.setdefault('%#x' % _ctor, []).append(
        'static initializer %#x (%s) calls this constructor for the object %#x with member(s) %s' % (
            _init, ' / '.join(_strings), _obj, ' / '.join('%#x' % m for m in _members)))
IDENTITY['%#x' % 0x5e0be0] = ['getter immediate of the TimeOfDay initializer 0x7f69d0 (mov edx, 0x5e0be0); reads '
                              'timeOfDay (+0x268) as declared in Lighting2008.h (getTimeStr 005e0be0)']
# getset factory identity: each is called by exactly one constructor (own row or a JointInstance-unit row)
for _a, _caller in [(0x5e02d0, 0x5e1170), (0x5e0320, 0x5e1220), (0x5e0370, 0x5e12d0), (0x5e2920, 0x5e3540),
                    (0x5e2970, 0x5e3630), (0x5e29c0, 0x5e36e0), (0x5e0ba0, 0x5e0be0), (0x5e06b0, 0x5e0ba0)]:
    assert '%08x' % _a in FUNCTIONS[_caller]['call_targets'], (hex(_a), hex(_caller))
    IDENTITY.setdefault('%#x' % _a, []).append('called by %#x' % _caller)

# ---- externals ------------------------------------------------------------------------------------------------------
EXTERNAL = {
    '??0FunctionDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBDW4Security@012@@Z': 0x595790,
    '??0Value@Reflection@RBX@@QAE@XZ': 0x594ac0,
    '?addArgument@SignatureDescriptor@Reflection@RBX@@QAEXABVName@3@ABVType@23@ABVValue@23@@Z': 0x594b40,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,
    '??$singleton@X@Type@Reflection@RBX@@SAABV012@XZ': 0x594a50,
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,
    '??2@YAPAXI@Z': 0x6a0920,
    '??3@YAXPAX@Z': 0x6a067a,
    '??$singleton@M@Type@Reflection@RBX@@SAABV012@XZ': 0x56cca0,
    '??$singleton@N@Type@Reflection@RBX@@SAABV012@XZ': 0x56cd10,
    '??$singleton@VVector3@G3D@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56ce60,
    '??$convert@N@Value@Reflection@RBX@@QAEAANXZ': 0x56ee50,
    # CRT 64-bit helpers, bound to these addresses by the committed lighting2008 / app-unit5dc-2008 recorders; __allrem
    # 006a1e90 starts like allrem.asm (push ebx; push edi; xor edi, edi; mov eax, [esp+0x10]; or eax, eax; jge)
    # std::operator<<(ostream&, char): the linked COMDAT is another unit's copy (evidence name; the copy compiled here
    # is not byte-identical), called by to_simple_string_type 005e06b0
    '??$?6U?$char_traits@D@std@@@std@@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@0@AAV10@D@Z': 0x44a640,
    '__alldiv': 0x6a1c30, '__allmul': 0x6a16d0, '__allrem': 0x6a1e90, '__ftol2_sse': 0x6a17f0,
    # pending rows only (same bindings as record_native_lighting2008.py)
    '??$find@VRunService@RBX@@@ServiceProvider@RBX@@SAPAVRunService@1@PBVInstance@1@@Z': 0x4651c0,
    '?findSignalInstance@SignalDescriptor@Reflection@RBX@@IBEPAVSignalInstance@23@PBVSignalSource@23@@Z': 0x56b620,
    '?invalidateRunViews@RunService@RBX@@QAEXXZ': 0x555350,
    '?setTime@LightingParameters@G3D@@QAEXN@Z': 0x7b59b0,
}
assert original.data(0x6a1e90, 10) == bytes.fromhex('5357' '33ff' '8b442410' '0bc0'), original.data(0x6a1e90, 10).hex()
LOCAL_STATIC = {}
DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
BINDING, UNBOUND, HELPERS, EVIDENCE_NAMED = {}, [], {}, {}


def norm(s):
    return s.replace('3QBDB', '3PBDB')


def bind(symbol, value, where):
    prev = BINDING.setdefault(symbol, (value, where))
    assert prev[0] == value, ('one address per symbol', symbol, hex(prev[0]), prev[1], hex(value), where)


def body_exact_at(unit, symbol, value):
    hb, hr = unit.bodies[symbol]
    ht, htr, _ = match.target('2008-06', '%08x' % value)
    return match.exact_match(ht, htr, hb, hr)


def classify(unit, symbol, value, where, own):
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol in own:
        assert own[symbol] == value, (where, symbol, hex(value), hex(own[symbol]))
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
    if symbol in unit.bodies and norm(names.get(value, '')) == norm(symbol) and not body_exact_at(unit, symbol, value):
        # library COMDAT linked from another unit's copy: bound by its evidence name only (never counted)
        EVIDENCE_NAMED.setdefault(symbol, '%#x' % value)
        return 'evidence-name binding (the linked COMDAT is another unit\'s copy; not exact here, not counted)'
    if symbol in unit.bodies:
        # COMDAT support body compiled here but not a counted row: exact at the bound address, never counted
        assert body_exact_at(unit, symbol, value) or DISCOVER, (where, symbol, hex(value))
        HELPERS.setdefault(symbol, '%#x (support body exact at the bound address, not counted here)' % value)
        return 'support body exact at the bound address (not counted here)'
    m = re.match(r'(?:\?|_)(prop_[A-Za-z]+)(?:@|$)', symbol)
    if m and m.group(1) in PENDING_STATICS:
        assert PENDING_STATICS[m.group(1)] == value, (where, symbol, hex(value))
        return 'descriptor object constructed at this address by its static initializer'
    if symbol in unit.definitions or symbol.startswith(('__TI', '??_R', '?event_LightingChanged@')):
        assert any(lo <= value < hi for lo, hi in DATA_SECTIONS), (where, symbol, hex(value))
        LOCAL_STATIC.setdefault(symbol, value)
        return 'static data (one address per symbol)'
    return None


def verify(rows, own, bind_targets=True):
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
            how = classify(unit, symbol, value, where, own)
            if how is None:
                UNBOUND.append((where, symbol, hex(value), names.get(value, '')[:80]))
                continue
            if bind_targets:
                bind(symbol, value, where)
            row['verified_targets'][symbol] = '%#x (%s)' % (value, how)
    return out


rows = verify(ROWS, OWN)
near = verify(NEAR, OWN)
for _r in near:
    assert not _r['exact'] or DISCOVER, ('near miss became exact: move it to ROWS', _r['address'])
pending = verify(PENDING_ROWS, dict(OWN, **PENDING_OWN), bind_targets=False)
not_exact = [r for r in rows if not r['exact']]
pending_not_exact = [r for r in pending if not r['exact']]
if DISCOVER:
    for u in sorted(set(UNBOUND)):
        print('UNBOUND', u)
    for r in not_exact + near + pending_not_exact:
        print('NOT EXACT' if not r['exact'] else 'EXACT(near)', r['unit'], r['address'], r['size'], r['target_size'],
              r['symbol'][:100])
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]
assert not pending_not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in pending_not_exact]
# pending rows: exact only with the generated header copies, therefore never counted
_pending_statics = {s: v for s, v in LOCAL_STATIC.items() if 'prop_' in s}
assert DISCOVER or not _pending_statics, _pending_statics
for _r in pending:
    _r['pending_build_exact'] = _r.pop('exact')
    _r['exact'] = False
    _r['address'] = '%#x' % int(_r['address'], 16)
for _r in near:
    _r['address'] = '%#x' % int(_r['address'], 16)
    _r['reason'] = NEAR_REASON[int(_r['address'], 16)]


# ---- vtables (current headers only; the pending object is never used for slot checks) -----------------------------
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
            elif s in NEAR_OWN:
                assert NEAR_OWN[s] == got, ('vtable slot', symbol, k, s, hex(got))
                checked.append('%d %s = %#x (near-miss row, not counted)' % (k, s[:70], got))
        vtable_checks[symbol] = {'address': '%#x' % value, 'compiled_slots': len(slots), 'checked_own_slots': checked}
# every BoundFuncDesc vtable stored by a counted constructor holds its execute row (own or near miss) in slot 1
for _bf in (BF_FLOAT, BF_V3, BF_DBL, BF_SET):
    _vt = [k for k in vtable_checks if k.startswith('??_7' + _bf)]
    assert len(_vt) == 1 and any(c.startswith('1 ') for c in vtable_checks[_vt[0]]['checked_own_slots']), (_bf, _vt)


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
    ('lighting tail', 0x5e0000, 0x5e2760),
    ('joint-instance head', 0x5e2760, 0x5e4000),
]
unit_rows = {}
for a in range_rows:
    unit = [u for u, lo, hi in UNITS if lo <= a < hi]
    assert len(unit) == 1, hex(a)
    unit_rows.setdefault(unit[0], []).append(a)
# boundary evidence checks (RTTI / strings read from the binary)
assert original.vtable_class(0x83dc94)[0] == '.?AV?$PropDescriptor@VLighting@RBX@@V?$basic_string@DU?$char_traits@D@' \
    'std@@V?$allocator@D@2@@std@@@Reflection@RBX@@', original.vtable_class(0x83dc94)
assert original.vtable_class(0x83de24)[0].startswith('.?AV?$BoundFuncDesc@VLighting@RBX@@$$A6AXN@Z$00@')
assert original.vtable_class(0x83e280)[0].startswith('.?AV?$GetSetImpl@P8JointInstance@RBX@@')
assert original.vtable_class(0x83e2a8)[0].startswith('.?AV?$GetSetImpl@P8Motor@RBX@@')
assert original.vtable_class(0x83f24c)[0] == '.?AVWeld@RBX@@'
assert '00557330' in FUNCTIONS[0x5e2ad0]['call_targets']
assert '005e2e10' in FUNCTIONS[0x5e34f0]['call_targets']        # ??_G of the JointInstance destructor

UNIT_MAP = {
    'lighting tail 005e0000..005e275f': (
        'v8datamodel/Lighting.cpp, from 005df0c0 (app-unit5dc-2008 maps the head). Evidence: the static initializers '
        '007f69b0..007f6c40 ("LightingChanged", "TimeOfDay", "GeographicLatitude", "GetMoonPhase", "GetMoonDirection", '
        '"GetSunDirection", "GetMinutesAfterMidnight", "SetMinutesAfterMidnight" / "minutes", "ShadowColor", '
        '"Brightness", "ColorShift_Top", "ColorShift_Bottom", "Ambient") call the descriptor constructors 005e1170 / '
        '005e1220 / 005e12d0 / 005e1560 / 005e1690 / 005e1780 / 005e18c0 with the member functions as immediates; '
        'RTTI of the PropDescriptor / GetSetImpl / BoundFuncDesc vtables 0083dc28..0083de24 names Lighting; the '
        'setters 005e2030..005e2730 push the descriptor objects 0097a900..0097aa90 and fire event_LightingChanged '
        '(0097a88c). Contents: lexical_cast / tokenizer / date_time instances 005e0020..005e0ae0 (lighting2008), the '
        'getset factories 005e02d0 / 005e0320 / 005e0370, getMinutesAfterMidnight 005e0610, replaceSky 005e0650, '
        'boost::posix_time::to_simple_string_type<char> 005e06b0 and to_simple_string 005e0ba0 (boost header '
        'template / inline instantiated by this unit, reached only from getTimeStr 005e0be0), duration_from_string '
        '005e0c20, classDescriptor 005e1100, the descriptor constructors / execute rows 005e1170..005e1960, '
        'Lighting() 005e1a40 with its thunks, ~Lighting 005e1d60, the signal call 005e1e00 / 005e1f00, the setters '
        'and onChild* rows 005e2030..005e2730. Built here: the template instances and getTimeStr (counted), the '
        'setters and getMinutesAfterMidnight (pending build).'),
    'joint-instance head 005e2760..005e3fff (continues to 005e50bf)': (
        'v8datamodel/JointInstance.cpp (app-unit5dc-2008 / app-unit5e4 map the rest). Evidence: RTTI of the Weld '
        'vtable 0083f24c (DescribedCreatable<Weld, JointInstance, sWeld 3QBDB> directly on JointInstance, no '
        'AutoJoint), GetSetImpl vtables 0083e280 / 0083e294 / 0083e2a8 (JointInstance PartInstance* / '
        'CoordinateFrame, Motor float), the per-joint getClassName rows 005e2ad0 / 005e3040 / 005e30e0 / 005e31b0 / '
        '005e3290 / 005e3330 / 005e33f0 / 005e3490 (Name::declare through call_once 00557330), ~JointInstance '
        '005e2e10 (??_G 005e34f0) and the FactoryProduct / NonFactoryProduct destructors and constructors. Contents: '
        '??_G of world-joints 005e2760, the ICF leaves 005e2790 (world-shapes) and 005e28c0 / 005e28e0 '
        '(world-joints), 005e28b0 (feature / stats-service thunk), shouldRender3dAdorn 005e27a0, getC0 / getC1 '
        '005e27b0 / 005e27c0, NonFactoryProduct<Instance, sJointInstance> 005e27e0 / 005e2840, the getset factories '
        '005e2920 / 005e2970 / 005e29c0, getPart0 / getPart1 005e2a10 / 005e2a70, render3dAdorn 005e2af0, setPart '
        '005e2cd0, ~JointInstance 005e2e10, the Snap .. Motor FactoryProduct destructors 005e2fa0..005e3410 with '
        'their ??_E adjustor thunks, RefPropDescriptor<JointInstance, PartInstance> 005e3540 / setRefValue 005e35f0, '
        'PropDescriptor<JointInstance, CoordinateFrame> / <Motor, float> constructors 005e3630 / 005e36e0, '
        'askSetParent 005e3790, DescribedNonCreatable<JointInstance>() 005e37d0, JointInstance(Joint*) 005e3870, '
        'onAncestorChanged 005e3a80, the FactoryProduct(Joint*) constructors 005e3b30..005e3dd0 and '
        'DescribedCreatable(Joint*) constructors 005e3e60 / 005e3f10. Built here: the three getset factories (their '
        'bytes and symbols depend on the member-pointer types only). The rest waits for the 2008 JointInstance '
        'declaration (proposal).'),
}
NOT_ATTEMPTED = {
    'JointInstance.cpp rows other than the getset factories': (
        'need the 2008 JointInstance / Snap .. Motor declarations: class names extern const char[] (RTTI '
        '$1?sJointInstance@2@3QBDB, the native header has char[] / 3PADA), joints derive from DescribedCreatable<C, '
        'JointInstance, sC> (RTTI 0083f24c), part[2] / getPart0 / setPart / askSetParent / onAncestorChanged are '
        'JointInstance members. The native JointInstance.h belongs to another owner (read-only here); proposal '
        'repeated below.'),
    'Lighting::getMoonPhase 005df480 / getGeographicLatitude 005df490 / getShadowColor3 005df4a0': (
        'outside this range (app-unit5dc-2008); declared in the pending header copy only'),
}
REJECTED = {
    '005e15d0 / 005e17f0 / 005e1630 / 005e1860 with the current reflection.h': (
        'Value::set<T> is not inlined into call<T> (82-byte COMDAT) where the original inlines the assignment: '
        'not exact; the only change that makes them exact is the stats-service reflection.h proposal '
        '(returnValue = ...), a core header (pending build here)'),
    'Lighting setters without /fp:fast': (
        'setShadowColor 207/201 B, the Color3 setters 176/172 B, setBrightness / setGeographicLatitude / '
        'getMinutesAfterMidnight same size but different compare / multiply order: /fp:fast is required (the '
        'original multiplies by 1/60000 at 0083dc60)'),
}
PROPOSALS = {
    'native-headers/v8datamodel/Lighting2008.h owner (lighting2008)': (
        'Declare the 2008 Lighting reflection members (the generated copy under out/native-layouts/app-unit5e0/'
        'pending/v8datamodel/Lighting2008.h, public section): getMoonPhase 005df480, getMinutesAfterMidnight 005e0610 '
        '(non-const: BoundFuncDesc<Lighting, double(), 0> stores `double (Lighting::*)()`), setMinutesAfterMidnight '
        '005e26e0, setTimeStr 005e2730, setTime(const time_duration&) 005e2570, getGeographicLatitude 005df490 / '
        'setGeographicLatitude 005e2670 (skyParameters.geoLatitude +0x224), getShadowColor3 005df4a0 / setShadowColor3 '
        '005e2540 / setShadowColor(Color4) 005e2030 (+0x254; the "ShadowColor" descriptor initializer 007f6b40 passes '
        '005df4a0 / 005e2540), inline getBrightness / getColorShiftTop / getColorShiftBottom / getAmbient (004d6fe0 / '
        '004d6f80 / 004d6fb0 / 004d6ff0) with setBrightness 005e2420, setColorShiftTop 005e22c0, setColorShiftBottom '
        '005e2370, setAmbient 005e2490. Signatures from the GetSetImpl RTTI (0083dc28 / 0083dc3c / 0083dc50: '
        'std::string () const with void (const std::string&); float () const with void (float); Color3 () const with '
        'void (Color3)) and the BoundFuncDesc RTTI 0083de00..0083de24. With them the 11 setter / getter rows of this '
        'range are exact (pending build, /fp:fast).'),
    'native-headers/reflection/reflection.h owner (core header)': (
        'Same change the stats-service receipt proposes: BoundFuncDesc<C, F, 0>::call<ReturnType> assigns '
        '`returnValue = (o->*function)();` (Value::operator= inline) instead of Value::set<ReturnType>. It makes '
        'call<float> 005e15d0, call<double> 005e17f0 and their execute rows 005e1630 / 005e1860 exact here.'),
    'native-headers/v8datamodel/JointInstance.h owner': (
        'Repeat of the app-unit5dc-2008 / app-unit5e4 proposal: the 2008 JointInstance.cpp block 005e2760..005e50bf '
        'has no AutoJoint; getPart0 / getPart1 005e2a10 / 005e2a70, setPart 005e2cd0, askSetParent 005e3790, '
        'onAncestorChanged 005e3a80 and getC0 / getC1 005e27b0 / 005e27c0 are JointInstance members; sJointInstance '
        'and sSnap .. sMotor are extern const char[] (RTTI 3QBDB); Snap .. Motor derive from DescribedCreatable<C, '
        'JointInstance, sC> (Weld vtable 0083f24c). About 110 uncounted rows of this range wait for it.'),
}

receipt = {
    'class': 'RBX Lighting.cpp reflection rows and JointInstance.cpp getset factories of the application range '
             '005e0000..005e4000 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)): nb.sha(p) for p in
                [SOURCES['lighting'], SOURCES['joint'], Path(__file__).resolve()] + HEADERS},
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
    'evidence_name_bindings': EVIDENCE_NAMED,
    'local_statics': {k: '%#x' % v for k, v in sorted(LOCAL_STATIC.items())},
    'vtables_current_headers': vtable_checks,
    'near_misses': near,
    'not_exact': ['%s %s: %d/%d B, not counted (%s)' % (r['address'], r['symbol'][:60], r['size'], r['target_size'],
                                                         r['reason']) for r in near],
    'pending_build_only': pending,
    'pending_note': 'exact only under /DNATIVE_APPUNIT5E0_PENDING with the generated header copies (Lighting2008.h '
                    'member declarations, reflection.h call<> assignment); exact=false, never counted',
    'not_attempted': NOT_ATTEMPTED,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
if not DISCOVER:
    RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit5e0: %d counted exact rows (%s); %d pending-build-only, %d near misses; %d vtables checked, '
      '%d support bodies; %d range rows (%d counted elsewhere)' % (
          len(exact_rows), ' '.join(exact_rows), len(pending), len(near), len(vtable_checks), len(HELPERS),
          len(range_rows), len(range_counted)))
