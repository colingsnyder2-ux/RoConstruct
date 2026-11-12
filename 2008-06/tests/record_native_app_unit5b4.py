"""Verify the inactive 2008-06 native rows of the application range 005b4000..005bc000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there as text).

Unit map summary (details in UNIT_MAP below):
  * BrickColor unit tail ..005b658f (util/BrickColor.cpp, continued from app-unit5b0's map): BrickMap and its
    std::map instantiations, BrickColor statics. No committed native BrickColor header; not built here.
  * Sound unit 005b6590..005bbfff (util/Sound.cpp, continuing past 005bc000): built here from
    native-classes/AppUnit5B4SoundReflection.cpp against the committed native util/Sound.h (read-only): the
    FactoryProduct / DescribedCreatable base constructors and destructors of SoundService / SoundChannel / StockSound,
    the Name / classDescriptor instances, the property-descriptor constructors and getset factories, the
    EnumDesc<ReverbType> constructor and the two EnumDesc singletons with their destructors, the shared_ptr
    constructors of create<StockSound> and the stats items, five SoundChannel getters and the FactoryProduct<SoundService>
    deleting-destructor adjustor thunks.

Build: document-swap flags + the FMOD Ex include directory (tools/openrbx/3rdparty/fmod/api/inc, as the committed
sound recorders use), VS2008 RTM 21022. No pending build: every row here needs only declarations the committed native
headers already give.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, string literals by bytes, RTTI type
descriptors by name, vtables by their complete-object-locator RTTI, own symbols by the row proven here, COMDAT support
bodies by exactness at the bound address, rows counted by other receipts by that receipt's symbol, the remaining
externals by the explicit EXTERNAL map (evidence name, another receipt's binding, or identity proven here), the class
name arrays by their string, other static data by one address per symbol. A row is counted only when no other receipt
counts it. Compiled vtables of the base constructors are compared slot by slot with the original vtables they store.
Writes work/2008-06/shared-layouts/app-unit5b4-working.json.
Set NATIVE_APP_UNIT5B4_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit5b4'
OUT.mkdir(parents=True, exist_ok=True)
SOURCE = R / 'native-classes/AppUnit5B4SoundReflection.cpp'
HEADER = R / 'native-headers/util/Sound.h'
FMOD_INC = ROOT / 'tools/openrbx/3rdparty/fmod/api/inc'
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT5B4_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit5b4-working.json'
LO, HI = 0x5b4000, 0x5bc000

FLAGS = ['/I' + str(FMOD_INC)] + nb.flags()
OBJ = OUT / 'NativeAppUnit5B4_sound.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', FLAGS + ['/Fo' + str(OBJ), str(SOURCE)], OUT)
assert code == 0, log

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        x = json.loads(line)
        FUNCTIONS[int(x['addr'], 16)] = x


def norm(s):
    return s.replace('3QBDB', '3PBDB')


RAW = OBJ.read_bytes()
SECTIONS, SYMBOLS, DEFINITIONS, _ = match._coff_data_index(RAW)
BODIES = {n: (b, r) for n, b, r in match.coff_functions(RAW)}
COMPILED = [n for n in BODIES if not nb.LOCAL_EH.match(n)]


def sym(prefix, *contains, suffix=''):
    hits = [n for n in COMPILED if n.startswith(prefix) and n.endswith(suffix) and all(c in n for c in contains)]
    assert len(hits) == 1, (prefix, contains, suffix, hits)
    return hits[0]


# ---- rows ----------------------------------------------------------------------------------------------------------
SC = 'VSoundChannel@Soundscape@RBX@@'
SS = 'VSoundService@Soundscape@RBX@@'
FPS = '?$FactoryProduct@' + SS + 'VInstance@3@$1?sSoundService@23@3PADA@RBX@@'
FPC = '?$FactoryProduct@' + SC + 'VInstance@3@$1?sSoundChannel@23@3PADA@RBX@@'
FPK = '?$FactoryProduct@VStockSound@@' + SC + '$1?sStockSound@@3PADA@RBX@@'
DCS = '?$DescribedCreatable@' + SS + 'VInstance@3@$1?sSoundService@23@3PADA@RBX@@'
DCC = '?$DescribedCreatable@' + SC + 'VInstance@3@$1?sSoundChannel@23@3PADA@RBX@@'
DEL = 'VDeleter@?$Creatable@VInstance@RBX@@@'
PD = '@?$PropDescriptor@' + SC
RT = 'W4ReverbType@Soundscape@RBX@@'
ROWS = [
    (0x5b65a0, '?getPlayCount@SoundChannel@Soundscape@RBX@@QBEHXZ'),
    (0x5b6960, '?isPaused@SoundChannel@Soundscape@RBX@@QBE_NXZ'),
    (0x5b6990, '?isPlaying@SoundChannel@Soundscape@RBX@@QBE_NXZ'),
    (0x5b69c0, '?getVolume@SoundChannel@Soundscape@RBX@@QBEMXZ'),
    (0x5b69d0, '?getLooped@SoundChannel@Soundscape@RBX@@QBE_NXZ'),
    (0x5b69e0, '??1' + FPS + 'MAE@XZ'),
    (0x5b6a40, '??1' + FPC + 'MAE@XZ'),
    (0x5b6b60, '??0' + FPS + 'IAE@XZ'),
    (0x5b6bc0, '??0' + FPC + 'IAE@XZ'),
    (0x5b6ca0, '??$any_cast@VSoundId@Soundscape@RBX@@@boost@@YAPAVSoundId@Soundscape@RBX@@PAVany@0@@Z'),
    (0x5b6d50, '??0?$holder@VSoundId@Soundscape@RBX@@@any@boost@@QAE@ABVSoundId@Soundscape@RBX@@@Z'),
    (0x5b6db0, '?type@?$holder@VSoundId@Soundscape@RBX@@@any@boost@@UBEABVtype_info@@XZ'),
    (0x5b6dc0, '?clone@?$holder@VSoundId@Soundscape@RBX@@@any@boost@@UBEPAVplaceholder@23@XZ'),
    (0x5b6e20, '??_G' + FPC + 'MAEPAXI@Z'),
    (0x5b6ce0, '??$doDeclare@$1?sStockSound@@3PADA@Name@RBX@@CAABV01@XZ'),
    (0x5b7320, sym('??$getset@P8SoundChannel@Soundscape@RBX@@BEMXZP8123@AEXM@Z' + PD)),
    (0x5b7370, sym('??$getset@P8SoundChannel@Soundscape@RBX@@BE_NXZ' + PD)),
    (0x5b73b0, '??$callDoDeclare@$1?sStockSound@@3PADA@Name@RBX@@CAXXZ'),
    # ICF-folded tail jumps: ~DescribedCreatable<C> and ~Described<C> both compile to `jmp ~FactoryProduct<C>`
    (0x5b7660, '??1' + DCS + 'UAE@XZ'),
    (0x5b7670, '??1' + DCC + 'UAE@XZ'),
    (0x5b7800, '??1' + FPK + 'MAE@XZ'),
    (0x5b7c50, sym('??$?0VStockSound@@' + DEL, '?$shared_ptr@VStockSound@@@boost@@')),
    (0x5b7d00, sym('??$?0VSoundServiceStatsItem@@' + DEL, '?$shared_ptr@VSoundServiceStatsItem@@@boost@@')),
    (0x5b7db0, sym('??$getset@P8SoundService@Soundscape@RBX@@BE?AW4ReverbType@23@XZ')),
    (0x5b7e00, sym('??$getset@P8SoundChannel@Soundscape@RBX@@BE?AVSoundId@23@XZ' + 'P8123@AEXV423@@Z' + PD)),
    (0x5b7e50, sym('??$getset@P8SoundChannel@Soundscape@RBX@@BEHXZP8123@AEXH@Z' + PD)),
    (0x5b7ea0, sym('??$getset@P8SoundChannel@Soundscape@RBX@@BE_NXZP8123@AEX_N@Z' + PD)),
    (0x5b7f50, sym('??$?0V?$TypedStatsItem@I@Stats@RBX@@' + DEL, '?$shared_ptr@V?$TypedStatsItem@I@Stats@RBX@@@boost@@')),
    (0x5b8450, '??$declare@$1?sSoundService@Soundscape@RBX@@3PADA@Name@RBX@@SAABV01@XZ'),
    (0x5b8470, '??$declare@$1?sSoundChannel@Soundscape@RBX@@3PADA@Name@RBX@@SAABV01@XZ'),
    (0x5b8490, '??$declare@$1?sStockSound@@3PADA@Name@RBX@@SAABV01@XZ'),
    (0x5bac70, '??1?$EnumDesc@' + RT + '@Reflection@RBX@@EAE@XZ'),
    (0x5bae20, '??_G?$EnumDesc@' + RT + '@Reflection@RBX@@EAEPAXI@Z'),
    (0x5baeb0, '??1?$EnumDesc@W4SoundType@RBX@@@Reflection@RBX@@EAE@XZ'),
    (0x5bb040, '??_G?$EnumDesc@W4SoundType@RBX@@@Reflection@RBX@@EAEPAXI@Z'),
    (0x5bb2c0, '?singleton@?$EnumDesc@W4SoundType@RBX@@@Reflection@RBX@@SAABV123@XZ'),
    (0x5bb330, '??0?$EnumDesc@' + RT + '@Reflection@RBX@@AAE@XZ'),
    (0x5bb7f0, sym('?classDescriptor@?$Described@' + SS)),
    (0x5bb860, sym('?classDescriptor@?$Described@' + SC)),
    (0x5bb8d0, sym('?classDescriptor@?$Described@VStockSound@@')),
    (0x5bb940, sym('??$?0' + SS + '@?$BoundProp@M$00@')),
    (0x5bba10, sym('??$?0P8SoundChannel@Soundscape@RBX@@BE?AVSoundId@12@XZ' + 'P8012@AEXV312@@Z' + PD)),
    (0x5bbac0, sym('??$?0P8SoundChannel@Soundscape@RBX@@BEMXZP8012@AEXM@Z' + PD)),
    (0x5bbb70, sym('??$?0P8SoundChannel@Soundscape@RBX@@BEHXZP8012@AEXH@Z' + PD)),
    (0x5bbc20, sym('??$?0P8SoundChannel@Soundscape@RBX@@BE_NXZP8012@AEX_N@Z' + PD)),
    (0x5bbcd0, sym('??$?0P8SoundChannel@Soundscape@RBX@@BE_NXZH' + PD)),
    (0x5bbd70, sym('??$?0' + SC + '@?$BoundProp@_N$00@')),
    (0x5bbe40, '?singleton@?$EnumDesc@' + RT + '@Reflection@RBX@@SAABV123@XZ'),
    (0x5bbec0, '??0' + DCS + 'IAE@XZ'),
    (0x5bbf90, '??_G' + FPS + 'MAEPAXI@Z'),
    (0x5bbfb0, '??0' + DCC + 'IAE@XZ'),
]
# Deleting-destructor adjustor thunks of FactoryProduct<SoundService> (sub ecx, N; jmp ??_G 005bbf90). The
# this-adjustment is read from the original bytes and named by its mangled vtable offset; the thunks jump to the vector
# deleting destructor ??_E, whose original slot holds the ??_G row (VECTOR_DTOR).
ADJ = {0x10: 'BA', 0x14: 'BE', 0x24: 'CE', 0x44: 'EE', 0x64: 'GE', 0x84: 'IE', 0xa4: 'KE', 0xc4: 'ME'}
THUNKS = [('??_E' + FPS + 'O%s@AEPAXI@Z', 0x5bbf90,
           [0x5b6e50, 0x5b6e90, 0x5b6ea0, 0x5b6eb0, 0x5b6ec0, 0x5bbf60, 0x5bbf70, 0x5bbf80])]
for _pattern, _g, _rows in THUNKS:
    for _a in _rows:
        _b = original.data(_a, 11)
        if _b[:2] == b'\x83\xe9':
            _adj = _b[2]
            assert _b[3] == 0xe9 and _a + 8 + struct.unpack_from('<i', _b, 4)[0] == _g, hex(_a)
        else:
            assert _b[:2] == b'\x81\xe9' and _b[6] == 0xe9, hex(_a)
            _adj = struct.unpack_from('<I', _b, 2)[0]
            assert _a + 11 + struct.unpack_from('<i', _b, 7)[0] == _g, hex(_a)
        ROWS.append((_a, _pattern % ADJ[_adj]))
VECTOR_DTOR = {'??_E' + FPS + 'MAEPAXI@Z': '??_G' + FPS + 'MAEPAXI@Z'}
ROWS.sort()
for _a, _s in ROWS:
    assert LO <= _a < HI and _a in FUNCTIONS, hex(_a)
    assert _s in BODIES, (hex(_a), _s)
assert len({a for a, _ in ROWS}) == len(ROWS) and len({s for _, s in ROWS}) == len(ROWS)

# identity checks of the ICF / tail-jump rows: each is a 5-byte jmp to the row named
for _a, _to in [(0x5b73b0, 0x5b6ce0), (0x5b7660, 0x5b69e0), (0x5b7670, 0x5b6a40)]:
    _b = original.data(_a, 5)
    assert _b[0] == 0xe9 and _a + 5 + struct.unpack_from('<i', _b, 1)[0] == _to, hex(_a)

# Getter identity: the static initializer of each property descriptor (0x7f5330..0x7f5430) holds the getter's address
# as an immediate and calls the PropDescriptor constructor row of the matching type. (005b65a0 is ICF-folded with
# other `return field_0x168` getters of other classes, which call it directly; it is SoundChannel::getPlayCount here.)
TEXT_SECTION = [s for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]
TEXT_VA, TEXT_BYTES = original.image + TEXT_SECTION.VirtualAddress, TEXT_SECTION.get_data()
GETTER_PROOF = {}
for _getter, _ctor in [(0x5b65a0, 0x5bbb70), (0x5b6960, 0x5bbcd0), (0x5b6990, 0x5bbcd0), (0x5b69c0, 0x5bbac0),
                       (0x5b69d0, 0x5bbc20)]:
    _hits = []
    for _m in re.finditer(re.escape(struct.pack('<I', _getter)), TEXT_BYTES):
        _at = TEXT_VA + _m.start()
        _init = max(a for a in FUNCTIONS if a <= _at)
        if '%08x' % _ctor in FUNCTIONS[_init]['call_targets']:
            _hits.append((_at, _init))
    assert len(_hits) == 1, (hex(_getter), _hits)
    GETTER_PROOF['%08x' % _getter] = 'address held at %#x by the static initializer %#x, which calls the ' \
        'PropDescriptor constructor row %#x' % (_hits[0][0], _hits[0][1], _ctor)

# ---- externals ------------------------------------------------------------------------------------------------------
# Class-name arrays (defined by the Sound owners, not here): bound by the string at the address the original pushes.
NAME_DATA = {'?sSoundService@Soundscape@RBX@@3PADA': 'SoundService', '?sSoundChannel@Soundscape@RBX@@3PADA': 'Sound',
             '?sStockSound@@3PADA': 'StockSound'}
# Name::doDeclare / callDoDeclare of SoundService and SoundChannel live in another unit (0x437f20.. COMDAT copies
# linked first); each is bound by identity: the doDeclare row declares exactly its class string, the callDoDeclare row
# is a 5-byte tail jump to it.
DECLARED_ELSEWHERE = {
    '??$doDeclare@$1?sSoundService@Soundscape@RBX@@3PADA@Name@RBX@@CAABV01@XZ': (0x437f20, 'SoundService'),
    '??$doDeclare@$1?sSoundChannel@Soundscape@RBX@@3PADA@Name@RBX@@CAABV01@XZ': (0x437f90, 'Sound'),
    '??$callDoDeclare@$1?sSoundService@Soundscape@RBX@@3PADA@Name@RBX@@CAXXZ': (0x438830, 0x437f20),
    '??$callDoDeclare@$1?sSoundChannel@Soundscape@RBX@@3PADA@Name@RBX@@CAXXZ': (0x438840, 0x437f90),
}
# rows counted by other receipts that the bodies here call: (address, receipt, symbol recorded there)
SC_COUNT = 'creatable-shared-count-working.json'
COUNTED_TARGETS = {
    '??$?0PAVStockSound@@' + DEL + 'RBX@@@shared_count@detail@boost@@QAE@PAVStockSound@@' + DEL + 'RBX@@@Z':
        (0x5b7480, SC_COUNT),
    '??$?0PAVSoundServiceStatsItem@@' + DEL + 'RBX@@@shared_count@detail@boost@@QAE@PAVSoundServiceStatsItem@@' + DEL
    + 'RBX@@@Z': (0x5b7510, SC_COUNT),
}
EXTERNAL = {
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@'
    'SAAAVClassDescriptor@23@XZ': 0x40ad80,
    '_atexit': 0x6a17af,
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,
    '??2@YAPAXI@Z': 0x6a0920,
    '??3@YAXPAX@Z': 0x6a067a,
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,
    '??1Instance@RBX@@UAE@XZ': 0x55a540,
    '??0PropertyDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@ABVType@12@PBD2W4Functionality@012@@Z': 0x56c650,
    '??0?$TypedPropertyDescriptor@M@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$Typed'
    'PropertyDescriptor@M@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x445610,
    '??0?$TypedPropertyDescriptor@_N@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$Typed'
    'PropertyDescriptor@_N@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x40a290,
    # TypedPropertyDescriptor<int> ctor: bound to 004432a0 by the committed value / metadata receipts (own row there)
    '??0?$TypedPropertyDescriptor@H@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$Typed'
    'PropertyDescriptor@H@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x4432a0,
    '??0EnumDescriptor@Reflection@RBX@@IAE@PBDABVtype_info@@@Z': 0x56c590,
    # ~EnumDescriptor: bound to 0056c080 by the committed enum receipts
    '??1EnumDescriptor@Reflection@RBX@@MAE@XZ': 0x56c080,
    # EnumDesc<SoundType>() 00629120: ScriptApp2008SoundType.cpp (record_native_script_app2008.py)
    '??0?$EnumDesc@W4SoundType@RBX@@@Reflection@RBX@@AAE@XZ': 0x629120,
}
# Constructors / destructors not counted here that the rows call, identified by the complete-object vtable their body
# stores: ~SoundChannel 005b7680 (Sound owners) and TypedPropertyDescriptor<SoundId>(...) 005b7be0 (this range; the
# compiled inline constructor of reflection/property.h is a near miss there, see not_exact).
VTABLE_IDENTITY = {
    '??1SoundChannel@Soundscape@RBX@@UAE@XZ': (0x5b7680, '.?AVSoundChannel@Soundscape@RBX@@'),
    '??0?$TypedPropertyDescriptor@VSoundId@Soundscape@RBX@@@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr'
    '@VGetSet@?$TypedPropertyDescriptor@VSoundId@Soundscape@RBX@@@Reflection@RBX@@@std@@W4Functionality@'
    'PropertyDescriptor@12@@Z': (0x5b7be0, '.?AV?$TypedPropertyDescriptor@VSoundId@Soundscape@RBX@@@Reflection@RBX@@'),
}
LOCAL_STATIC = {}      # symbol -> address: guards, function-local statics, atexit destructors (one address per symbol)
DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
TEXT = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
        for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]
BINDING, UNBOUND, HELPERS = {}, [], {}
OWN = {s: a for a, s in ROWS}


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
            if o.get('address') == '%08x' % address and o.get('symbol') and o.get('exact') is True:
                found.append(o['symbol'])
            for v in o.values():
                walk(v)
        elif isinstance(o, list):
            for v in o:
                walk(v)
    walk(data)
    return found


def ctor_vtables(address):
    """Vtables a constructor / destructor body stores (C7 /0 imm32 into a register base), with their RTTI class."""
    body, _, _ = match.target('2008-06', '%08x' % address)
    found = []
    for i in range(len(body) - 6):
        if body[i] == 0xc7 and (body[i + 1] & 0xf8) in (0x00, 0x40, 0x80):
            off = {0x00: 0, 0x40: 1, 0x80: 4}[body[i + 1] & 0xc0]
            v = struct.unpack_from('<I', body, i + 2 + off)[0]
            try:
                c = original.vtable_class(v)
            except Exception:
                continue
            if c and c[0]:
                found.append((v, c))
    return found


def body_exact_at(symbol, value):
    hb, hr = BODIES[symbol]
    ht, htr, _ = match.target('2008-06', '%08x' % value)
    return match.exact_match(ht, htr, hb, hr)


def classify(symbol, value, where):
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol in OWN:
        assert OWN[symbol] == value, (where, symbol, hex(value), hex(OWN[symbol]))
        return 'own row'
    if symbol in VECTOR_DTOR and VECTOR_DTOR[symbol] in OWN:
        assert OWN[VECTOR_DTOR[symbol]] == value, (where, symbol, hex(value))
        return 'own row %s (scalar deleting destructor; no array delete in the original)' % VECTOR_DTOR[symbol][:30]
    if symbol.startswith('??_C@'):
        pos, at = DEFINITIONS[symbol]
        lit = RAW[SECTIONS[at][4] + pos:SECTIONS[at][4] + SECTIONS[at][3]].split(b'\0')[0] + b'\0'
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
    if symbol in NAME_DATA:
        assert original.string(value) == NAME_DATA[symbol], (where, symbol, hex(value))
        return 'class-name array %r (string at the pushed address)' % NAME_DATA[symbol]
    if symbol in COUNTED_TARGETS:
        other, receipt = COUNTED_TARGETS[symbol]
        assert other == value, (where, symbol, hex(value), hex(other))
        assert symbol in receipt_symbols(receipt, value), (receipt, hex(value), symbol)
        if symbol in BODIES:
            assert body_exact_at(symbol, value), ('counted-elsewhere body not exact', symbol, hex(value))
        return 'row counted by %s (same symbol; body exact at the bound address)' % receipt
    if symbol in DECLARED_ELSEWHERE:
        other, proof = DECLARED_ELSEWHERE[symbol]
        assert other == value, (where, symbol, hex(value), hex(other))
        if isinstance(proof, str):
            assert FUNCTIONS[value]['strings'] == [proof], (symbol, hex(value), FUNCTIONS[value]['strings'])
            if symbol in BODIES:
                assert body_exact_at(symbol, value), (symbol, hex(value))
            return 'Name::doDeclare of another unit: declares exactly %r (body exact at the bound address)' % proof
        b = original.data(value, 5)
        assert b[0] == 0xe9 and value + 5 + struct.unpack_from('<i', b, 1)[0] == proof, (symbol, hex(value))
        return 'callDoDeclare of another unit: tail jump to the doDeclare %#x' % proof
    if symbol in VTABLE_IDENTITY:
        other, rtti = VTABLE_IDENTITY[symbol]
        assert other == value, (where, symbol, hex(value), hex(other))
        stores = [v for v, c in ctor_vtables(value) if c == (rtti, 0)]
        assert stores, (symbol, hex(value), ctor_vtables(value))
        return 'open row (not counted), identified by the %s complete-object vtable %#x it stores' % (rtti, stores[0])
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
        return 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
    if symbol in BODIES:
        # COMDAT support body compiled here but not a counted row: exact at the bound address, never counted
        assert body_exact_at(symbol, value) or DISCOVER, (where, symbol, hex(value))
        HELPERS.setdefault(symbol, '%#x' % value)
        return 'support body exact at the bound address (not counted here)'
    if symbol in DEFINITIONS or symbol.startswith(('?flag@', '??_B', '?foo@', '?$S', '??__F', '?instance@',
                                                     '?inst@', '?desc@', '?singleton@')):
        if TEXT[0] <= value < TEXT[1]:
            # compiler-generated atexit destructor of a function-local static (??__F...): bound by consistency
            assert symbol.startswith('??__F'), (where, symbol, hex(value))
        else:
            assert any(lo <= value < hi for lo, hi in DATA_SECTIONS), (where, symbol, hex(value))
        LOCAL_STATIC.setdefault(symbol, value)
        return 'static (one address per symbol)'
    return None


def verify(rows):
    out = []
    for address, name in rows:
        body, refs = BODIES[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        exact = match.exact_match(target, target_refs, body, refs)
        row = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
               'exact': bool(exact), 'verified_targets': {}, 'local_eh': []}
        out.append(row)
        if not exact:
            continue
        start, section = DEFINITIONS[name]
        table = SECTIONS[section]
        code = RAW[table[4] + start:]
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', RAW, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = SYMBOLS[index][0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            where = '%08x+%#x' % (address, offset)
            if nb.LOCAL_EH.match(symbol):
                row['local_eh'].append(symbol)
                continue
            how = classify(symbol, value, where)
            if how is None:
                UNBOUND.append((where, symbol, hex(value), names.get(value, '')[:80]))
                continue
            bind(symbol, value, where)
            row['verified_targets'][symbol] = '%#x (%s)' % (value, how)
    return out


rows = verify(ROWS)
# near misses built here (recorded, never counted)
TPD_SOUNDID = [k for k in VTABLE_IDENTITY if k.startswith('??0?$TypedPropertyDescriptor')][0]
near = verify([(0x5b7be0, TPD_SOUNDID)])
assert not near[0]['exact'], 'near miss 005b7be0 became exact: move it to ROWS'
not_exact = [r for r in rows if not r['exact']]
if DISCOVER:
    for u in sorted(set(UNBOUND)):
        print('UNBOUND', u)
    for r in not_exact:
        print('NOT EXACT', r['address'], r['size'], r['target_size'], r['symbol'][:100])
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]


# ---- vtables of the base constructors (current headers; there is no pending build) ----------------------------------
def compiled_vtables():
    _, _, _, starts = match._coff_data_index(RAW)
    out = {}
    for name, (start, sec) in DEFINITIONS.items():
        if not name.startswith('??_7'):
            continue
        table = SECTIONS[sec]
        end = min([x for x in starts.get(sec + 1, ()) if x > start] + [table[3]])
        slots = {}
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', RAW, table[5] + 10 * i)
            if start <= offset < end:
                slots[(offset - start) // 4] = SYMBOLS[index][0]
        out[name] = slots
    return out


VTABLES = compiled_vtables()
vtable_checks = {}
for r in rows:
    for symbol, desc in r['verified_targets'].items():
        if not symbol.startswith('??_7') or symbol in vtable_checks:
            continue
        value = int(desc.split()[0], 16)
        slots = VTABLES.get(symbol, {})
        checked = []
        for k, s in sorted(slots.items()):
            got = struct.unpack('<I', original.data(value + 4 * k, 4))[0]
            if s in OWN:
                assert OWN[s] == got, ('vtable slot', symbol, k, s, hex(got))
                checked.append('%d %s = %#x (own row)' % (k, s[:60], got))
            elif s in VECTOR_DTOR and VECTOR_DTOR[s] in OWN:
                assert OWN[VECTOR_DTOR[s]] == got, ('vtable slot', symbol, k, s, hex(got))
                checked.append('%d %s = %#x (own ??_G row)' % (k, s[:60], got))
            elif re.match(r'\?\?_E.*O[A-Z]{2}@AEPAXI@Z$', s) and s in OWN:
                checked.append('%d thunk %#x' % (k, got))
        vtable_checks[symbol] = {'address': '%#x' % value, 'compiled_slots': len(slots), 'checked_own_slots': checked}
# the FactoryProduct<SoundService> vtables stored by 005b6b60 / 005b69e0 hold the ??_G row or one of its thunks
_fps_slots = [c for k, v in vtable_checks.items() if FPS in k for c in v['checked_own_slots']]
assert _fps_slots or DISCOVER, vtable_checks


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
for row in rows:
    if row['address'] in elsewhere:
        row['counted_elsewhere'] = row['exact']
        row['exact'] = False
        row['address'] = '%#x counted by %s' % (
            int(row['address'], 16), ', '.join(sorted(set(elsewhere[row['address']]))))
exact_rows = sorted({r['address'] for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}

UNITS = [
    ('brick-color tail', 0x5b4000, 0x5b6590),
    ('player inline', 0x5b6590, 0x5b65a0),
    ('sound', 0x5b65a0, 0x5bc000),
]
unit_rows = {}
for a in range_rows:
    unit = [u for u, lo, hi in UNITS if lo <= a < hi]
    assert len(unit) == 1, hex(a)
    unit_rows.setdefault(unit[0], []).append(a)
# boundary evidence checks (evidence names / strings / RTTI read from the binary)
assert names.get(0x5b4630, '').startswith('??0BrickMap@BrickColor@RBX@@')
assert names.get(0x5b62e0, '').startswith('?closest@BrickColor@RBX@@')
assert names.get(0x5b6590, '').startswith('?getCharacter@Player@Network@RBX@@')
assert FUNCTIONS[0x5b6ce0]['strings'] == ['StockSound']
assert original.vtable_class(0x837d84)[0].startswith('.?AV?$DescribedCreatable@VSoundService@Soundscape@RBX@@')
assert original.vtable_class(0x837e44)[0].startswith('.?AV?$DescribedCreatable@VSoundChannel@Soundscape@RBX@@')
assert original.string(0x837c24) == 'ReverbType' and original.string(0x837c18) == 'NoReverb'

UNIT_MAP = {
    'brick-color tail 005b4000..005b658f': (
        'util/BrickColor.cpp, continued from 005b2ec0 (app-unit5b0 unit map): the std::map<BrickColor::Number, '
        'std::string> erase / _Tree destructor 005b4050 / 005b43a0, BrickMap::generatePaletteMap 005b4130 / 005b42f0, '
        'BrickMap::insert 005b4410, ~BrickMap 005b4570, BrickMap() 005b4630 (5601 B: "White", "Grey", "Light yellow" '
        '...), BrickMap::singleton 005b5c20, BrickColor colorPalette 005b5c80 / getClosestPaletteIndex 005b5c90 / '
        'parse 005b5cb0 / random 005b5ee0 / closest(Color4) 005b5f30 / BrickColor(int) 005b6090 / name 005b61b0 / '
        'color4 005b6200 / color3 005b6270 / closest(Color3) 005b62e0 (evidence names) and unnamed helpers to 005b658f '
        '(vector<BrickColor> / map node helpers). The map instantiations are Roblox-instantiated STL templates of this '
        'unit. No committed native BrickColor header (the donor util/BrickColor.h is the only declaration; '
        'CPropertyGridItemBrickColor uses it through the donor path); not built here.'),
    'player inline 005b6590': (
        'Player::getCharacter (Network/Player.h header inline emitted in this unit), counted by '
        'network-player-working.json.'),
    'sound 005b65a0..005bbfff (continues past 005bc000)': (
        'util/Sound.cpp. Evidence: RTTI .?AV?$DescribedCreatable@VSoundService@Soundscape@RBX@@...3PADA (vtable '
        '00837d84) and ...SoundChannel... (00837e44), .?AV?$FactoryProduct@VStockSound@@VSoundChannel@... , the '
        'PropDescriptor<SoundChannel, SoundId / float / int / bool> vtables 00837c34 / 00837c68 / 00837c9c / 00837cd0, '
        'GetSetImpl / GetImpl / BoundPropGetSet vtables 00837570..0083765c, EnumDesc<ReverbType> 005bb330 ("ReverbType", '
        '"NoReverb" .. "UnderWater"), the FMOD import calls (getPaused / isPlaying 005b6960 / 005b6990, '
        '"FMOD %d: %s" checks 005b6fe0 / 005b87a0, FMOD_ErrorString table 005b65b0, the system init 005ba060 '
        '"Incorrect FMODEX DLL version"), classDescriptors 005bb7f0 / 005bb860 / 005bb8d0 ("SoundService", "Sound", '
        '"StockSound"). Contents in address order: SoundChannel::getPlayCount 005b65a0, FMOD_ErrorString 005b65b0, '
        'StringConverter<ContentId>::convertToString 005b6940 (open), the getters 005b6960..005b69d0, ~FactoryProduct<SoundService / SoundChannel> 005b69e0 / 005b6a40, std::_Tree helpers '
        '(_Min / _Max of several maps, 005b6aa0..005b6c40; 005b6c40 _Rrotate is ICF-shared with other units 00423e30, '
        '005539d0, 00668010 callers), FactoryProduct<SoundService / SoundChannel>() 005b6b60 / 005b6bc0, '
        'boost::any_cast<SoundId> / holder<SoundId> members 005b6ca0..005b6e1f and the separate FactoryProduct deleting destructor 005b6e20, the deleting-destructor adjustor thunks 005b6e40..'
        '005b6ec0 / 005b7770..005b7890 / 005bb230..005bb2b0 / 005bbf60..005bbf80, sanitize / FMOD vector helpers '
        '005b6ed0..005b7370, getset factories 005b7320 / 005b7370 / 005b7db0..005b7ea0, GetSetImpl::setValue / getValue '
        'rows 005b73c0..005b7450, the Creatable shared_count rows 005b7480..005b75a0 (creatable-shared-count), '
        '~SoundChannel 005b7680, TypedPropertyDescriptor<SoundId> 005b7be0, shared_ptr constructors 005b7c50 / 005b7d00 / '
        '005b7f50, SoundId value conversion rows 005b7a80 / 005b8090 / 005b86b0 (sound-value-* receipts), Name::declare '
        '005b8450..005b8490, the SoundService members (loadSound / stock sounds / garbage collection / openFmod '
        '005b84b0..005ba660, std::map<SoundId, shared_ptr<Sound>> instances), EnumDesc<ReverbType / SoundType> '
        'destructors and map helpers 005ba890..005bb110, ~SoundService 005bb120, EnumDesc<SoundType>::singleton '
        '005bb2c0, EnumDesc<ReverbType>() 005bb330, the SoundService / SoundChannel scalar deleting destructors 005bb5d0 '
        '/ 005b8220, the classDescriptors, the BoundProp / PropDescriptor constructors 005bb940..005bbd70, '
        'EnumDesc<ReverbType>::singleton 005bbe40, DescribedCreatable<SoundService / SoundChannel>() 005bbec0 / '
        '005bbfb0 and ??_G FactoryProduct<SoundService> 005bbf90. FMOD itself is a DLL import (no library code here). '
        'Built here from AppUnit5B4SoundReflection.cpp against the committed native util/Sound.h.'),
}

NOT_ATTEMPTED = {
    'BrickColor unit tail': 'no committed native BrickColor header (would need a new layout header; not this pass)',
    'SoundService / SoundChannel bodies (constructors, destructors 005bb120 / 005b7680, loadSound, openFmod 005ba060, '
    'garbage collection, setters, update3D)': (
        'larger members of the Sound owners; their scalar deleting destructors 005bb5d0 / 005b8220 and the adjustor '
        'thunks jumping to them (005b7770..005b77e0, 005bb230..005bb2b0) wait for ~SoundService / ~SoundChannel'),
    'thunks to the StockSound ??_G 005bd1b0 (005b7860, 005b7870, 005b7880) and ??_E FactoryProduct<StockSound> 0x130 '
    'thunks (005b77f0, 005b7890, 005bb250)': 'their targets are ~StockSound / ~SoundChannel / ~SoundService rows (not built)',
    '005bb320 / 005bbea0 (5-byte tail jumps to the two EnumDesc singletons)': (
        'identity not proven (no caller or name evidence; any `return singleton()` forwarder compiles the same)'),
    '005b6c40 _Rrotate': 'ICF-shared std::_Tree helper also called from 00423e30 / 005539d0 / 00668010 (not this unit only)',
}
BOUNDS_EVIDENCE = {}
REJECTED = {
    '005ba890 / 005bae40 / 005bb110 as std::map<const Name*, ReverbType / SoundType> erase / ~_Tree / ~map': (
        'relocation-masked matches only: ~EnumDesc<ReverbType / SoundType> call their ~_Tree at 00553d80 (support body '
        'above), and 005bae40 is called only from ~SoundService 005bb120, so these are a SoundService map; not counted'),
    '005b7630 _Uninit_copy / 005b7450 GetSetImpl<float>::setValue': (
        'ICF-shared with other units (005b7630 called from 004460e0 / 00446290; 005b7450 in 8 vtables of other '
        'classes); identity not unit-specific, not counted'),
}
PROPOSALS = {}

receipt = {
    'class': 'RBX Sound unit (util/Sound.cpp template instances and getters) of the application range '
             '005b4000..005bc000 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)): nb.sha(p) for p in [SOURCE, Path(__file__).resolve(), HEADER]},
    'objects': {'sound': nb.sha(OBJ)},
    'unit_map': UNIT_MAP,
    'unit_rows': {u: {'rows': len(v), 'span': '%#x..%#x' % (v[0], v[-1])} for u, v in unit_rows.items()},
    'range_rows_total': len(range_rows),
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any '"ADDR"' in another receipt as counted there and drop it.
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'rows': rows,
    'support_bodies': HELPERS,
    'local_statics': {k: '%#x' % v for k, v in sorted(LOCAL_STATIC.items())},
    'vtables_current_headers': vtable_checks,
    'getter_identity': GETTER_PROOF,
    'bounds_evidence': BOUNDS_EVIDENCE,
    'not_exact': ['%s %s: %d/%d B, not counted' % (r['address'], r['symbol'][:60], r['size'], r['target_size'])
                  for r in not_exact + near] + [
        '005b7be0: the inline TypedPropertyDescriptor(ClassDescriptor&, ...) constructor of the native '
        'reflection/property.h (core header, read-only) loads its arguments before calling Type::singleton<SoundId>() '
        '0056cd80; the original calls the singleton first (same 98 B, instruction order only)'],
    'pending_build_only': [],
    'not_attempted': NOT_ATTEMPTED,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
if not DISCOVER:
    RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit5b4: %d counted exact rows (%s); %d vtables checked, %d support bodies; %d range rows '
      '(%d counted elsewhere)' % (len(exact_rows), ' '.join(exact_rows), len(vtable_checks), len(HELPERS),
                                  len(range_rows), len(range_counted)))
