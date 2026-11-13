"""Verify the inactive 2008-06 native rows of the application range 005bc000..005c8000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map`, checked below; rows counted by other receipts are listed as
'ADDR counted by RECEIPT' text, never as a quoted bare address):
  * ..005bf0cf          the Soundscape sound unit (SoundService / SoundChannel / StockSound), starting below the range,
                        with its StringConverter / lexical_cast COMDATs;
  * 005bf0d0..005bf7ff  v8datamodel/GameSettings.cpp (settings-items);
  * 005bf800..005c3ecf  the class-registration unit: Name::doDeclare / callDoDeclare and Described<C>::classDescriptor
                        instances, the Creatable / FactoryProduct block, ObjectValue's inline members and the
                        registration constructor 005c3ca0;
  * 005c3ed0..005c43ff  util/Profiling.cpp;
  * 005c4400..005c52ff  v8datamodel/Visit.cpp;
  * 005c5300..          the command-verb / tool-verb unit, continuing past 005c8000.
  No library unit starts inside the range: the STL / boost rows are template instances emitted in these RBX units.

Builds (VS2008 RTM 21022, document-swap flags, /fp:fast), current native headers only (read-only):
  * native-classes/AppUnit5BC_2008Creators.cpp     FactoryProduct<C, D, N>::Creator::create() const,
    Creatable<Instance>::create<C>() and shared_ptr<C>(C*, Creatable<Instance>::Deleter) of the registration block;
  * native-classes/AppUnit5BC_2008Descriptors.cpp  Name::doDeclare / callDoDeclare and classDescriptor instances;
  * native-classes/AppUnit5BC_2008Visit.cpp        the Visit unit; with a generated reflection/reflection.h copy
    (out/app-unit5bc-2008/pending/) the SetPing BoundFuncDesc rows, recorded exact=false (pending-build-only) and
    never counted.

Every relocation of a counted row is resolved to the address the original instruction uses and verified, one address
per symbol over all rows: imports by DLL export name, string literals by bytes, type descriptors by RTTI name, vtables
by the original complete-object locator class, own rows by their row address, rows counted by other receipts by that
receipt (and the compiled body must be exact there), constructors by evidence name or by the complete-object vtable
they store. Every Creator::create row is slot 0 of the original Creator vtable whose RTTI names the class.
A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit5bc-2008-working.json. NATIVE_APP_UNIT5BC_DISCOVER=1 lists unbound
targets and non-exact rows instead of asserting.
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
OUT = R / 'out/app-unit5bc-2008'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'creators': R / 'native-classes/AppUnit5BC_2008Creators.cpp',
    'descriptors': R / 'native-classes/AppUnit5BC_2008Descriptors.cpp',
    'visit': R / 'native-classes/AppUnit5BC_2008Visit.cpp',
}
UNIT_FLAGS = {'creators': ['/fp:fast'], 'descriptors': ['/fp:fast'], 'visit': ['/fp:fast']}
HEADERS = [R / 'native-headers' / h for h in (
    'util/Object.h', 'v8datamodel/ClickDetector.h', 'v8datamodel/Explosion.h', 'v8datamodel/FlagStand.h',
    'v8datamodel/FlagStandService.h', 'v8datamodel/ForceField.h', 'v8datamodel/GeometryService.h',
    'v8datamodel/BodyMovers.h', 'v8datamodel/Rocket.h', 'v8datamodel/Value.h', 'v8datamodel/DebrisService.h',
    'v8datamodel/Seat.h', 'v8datamodel/Sparkles.h', 'v8datamodel/Visit.h', 'v8datamodel/JointInstance.h',
    'util/Name.h', 'reflection/reflection.h')]
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit5bc-2008-working.json'
LO, HI = 0x5bc000, 0x5c8000
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT5BC_DISCOVER'))


def build(name, src, extra=(), pre=()):
    obj = OUT / (name + '.obj')
    flags = list(pre) + nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


# ---- pending header copy: reflection/reflection.h with a body for the two-argument BoundFuncDesc constructor ---------
# The core header declares BoundFuncDesc<C, F, 2>(function, name, arg1Name, arg2Name, security) without a body; the copy
# gives it the shape of the one-argument constructor (FuncDesc(name, security), function, default1(), default2(),
# declareSignature(arg1Name, arg2Name)). Pending build only; proposal for the reflection.h owner.
PENDING = OUT / 'pending'
(PENDING / 'reflection').mkdir(parents=True, exist_ok=True)
_refl = (R / 'native-headers/reflection/reflection.h').read_text()
_two = _refl.index('class BoundFuncDesc<Class, Function, 2>')
_decl = ('\t\t\tBoundFuncDesc(\n\t\t\t\ttypename FunctionSig function,\n\t\t\t\tconst char* name,\n'
         '\t\t\t\tconst char* arg1Name,\n\t\t\t\tconst char* arg2Name,\n\t\t\t\tSecurity security);')
assert _refl.find(_decl, _two) == _refl.find('BoundFuncDesc(', _two) - 3, 'two-argument constructor declaration moved'
_at = _refl.find(_decl, _two)
_body = _decl[:-1] + ('\n\t\t\t\t: FuncDesc(name, security),\n\t\t\t\t  function(function),\n\t\t\t\t  default1(),\n'
                      '\t\t\t\t  default2()\n\t\t\t{\n\t\t\t\tdeclareSignature(arg1Name, arg2Name);\n\t\t\t}')
(PENDING / 'reflection/reflection.h').write_text(
    '// generated by tests/record_native_app_unit5bc_2008.py (pending build only; proposal for reflection/reflection.h)\n'
    + _refl[:_at] + _body + _refl[_at + len(_decl):])

OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build(_src.stem, _src, UNIT_FLAGS[_k])
OBJ['visit_pending'], FLAGS['visit_pending'] = build(
    'AppUnit5BC_2008Visit_pending', SOURCES['visit'], UNIT_FLAGS['visit'] + ['/DNATIVE_APPUNIT5BC_PENDING'],
    ['/I' + str(PENDING)])

original = nb.Original()
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    x = json.loads(line)
    FUNCTIONS[int(x['addr'], 16)] = x


def norm(s):
    return s.replace('3QBDB', '3PBDB')


# ---- rows --------------------------------------------------------------------------------------------------------
CI = '?$Creatable@VInstance@RBX@@@'
DEL = 'VDeleter@' + CI


def creator(c, base, mangle):
    return '?create@Creator@?$FactoryProduct@V%s@RBX@@V%s@2@$1?s%s@2@%s@RBX@@UBE?AV?$shared_ptr@VObject@RBX@@@boost@@XZ' % (
        c, base, c, mangle)


def create(c):
    return '??$create@V%s@RBX@@@%sRBX@@SA?AV?$shared_ptr@V%s@RBX@@@boost@@XZ' % (c, CI, c)


def sptr(c):
    return '??$?0V%s@RBX@@%s1@@?$shared_ptr@V%s@RBX@@@boost@@QAE@PAV%s@RBX@@%s3@@Z' % (c, DEL, c, c, DEL)


def scount(c):
    return '??$?0PAV%s@RBX@@%s1@@shared_count@detail@boost@@QAE@PAV%s@RBX@@%s4@@Z' % (c, DEL, c, DEL)


# Class -> (FactoryProduct base, symbol name mangling (native header), original RTTI mangling, Creator::create,
#           shared_ptr ctor, create<C>, shared_count, constructor C(), Creator vtable)
# The Creator vtables and their RTTI (.?AVCreator@?$FactoryProduct@...) are read from the original below.
CREATORS = {
    'ClickDetector': ('Instance', '3PADA', '3PADA', 0x5c0be0, 0x5c0ab0, 0x5c0b60, 0x5c0a20, 0x6297e0, 0x83882c),
    'Explosion': ('Instance', '3PADA', '3PADA', 0x5c0e50, 0x5c0d20, 0x5c0dd0, 0x5c0c90, 0x62adb0, 0x838848),
    'FlagStand': ('PartInstance', '3PADA', '3PADA', 0x5c10c0, 0x5c0f90, 0x5c1040, 0x5c0f00, 0x62c9c0, 0x838864),
    'FlagStandService': ('Instance', '3QBDB', '3QBDB', 0x5c1330, 0x5c1200, 0x5c12b0, 0x5c1170, 0x62ccd0, 0x838880),
    'ForceField': ('Instance', '3PADA', '3PADA', 0x5c15a0, 0x5c1470, 0x5c1520, 0x5c13e0, 0x62d6b0, 0x83889c),
    'GeometryService': ('Instance', '3PADA', '3PADA', 0x5c1810, 0x5c16e0, 0x5c1790, 0x5c1650, 0x62dee0, 0x8388b8),
    'BodyGyro': ('BodyMover', '3PADA', '3PADA', 0x5c1a80, 0x5c1950, 0x5c1a00, 0x5c18c0, 0x632070, 0x8388d4),
    'BodyForce': ('BodyMover', '3PADA', '3PADA', 0x5c1cf0, 0x5c1bc0, 0x5c1c70, 0x5c1b30, 0x6324f0, 0x8388f0),
    'BodyThrust': ('BodyMover', '3PADA', '3PADA', 0x5c1f60, 0x5c1e30, 0x5c1ee0, 0x5c1da0, 0x6325e0, 0x83890c),
    'BodyPosition': ('BodyMover', '3PADA', '3PADA', 0x5c21d0, 0x5c20a0, 0x5c2150, 0x5c2010, 0x632190, 0x838928),
    'BodyVelocity': ('BodyMover', '3PADA', '3PADA', 0x5c2440, 0x5c2310, 0x5c23c0, 0x5c2280, 0x632290, 0x838944),
    'BodyAngularVelocity': ('BodyMover', '3PADA', '3PADA', 0x5c26b0, 0x5c2580, 0x5c2630, 0x5c24f0, 0x632400, 0x838960),
    'Rocket': ('BodyMover', '3PADA', '3PADA', 0x5c2920, 0x5c27f0, 0x5c28a0, 0x5c2760, 0x632b50, 0x83897c),
    'DebrisService': ('Instance', '3PADA', '3PADA', 0x5c2e90, 0x5c2d60, 0x5c2e10, 0x5c2cd0, 0x63be90, 0x838a74),
    'Seat': ('PartInstance', '3PADA', '3PADA', 0x5c3100, 0x5c2fd0, 0x5c3080, 0x5c2f40, 0x63d390, 0x838a90),
    # native Sparkles.h declares `extern const char sSparkles[]` (symbol 3QBDB); the original RTTI names a char array
    'Sparkles': ('Instance', '3QBDB', '3PADA', 0x5c3370, 0x5c3240, 0x5c32f0, 0x5c31b0, 0x63da90, 0x838aac),
    'ObjectValue': ('Instance', '3PADA', '3PADA', 0x5c3e20, 0x5c2b90, 0x5c3da0, 0x5c2af0, 0x5c3ab0, 0x838998),
}
# shared_ptr / create<C> rows counted by the class receipts (their Creator rows are not counted anywhere)
COUNTED_PAIR = {'ForceField': 'debris-forcefield-working.json', 'GeometryService': 'geometry-service-working.json',
                'DebrisService': 'debris-forcefield-working.json'}
# create<FlagStand> 005c1040 / create<Seat> 005c3080 are not exact: they malloc 0x41c / 0x43c in the original, the native
# FlagStand.h / Seat.h (over the native PartInstance.h of other owners) give sizeof 0x304 / 0x324 (0x118 short each, the
# missing embedded Primitive of the PartInstance proposal). Their Creator / shared_ptr rows do not depend on the size;
# the Creator call to them is bound by identity (each calls its evidence-named constructor) and the row is not counted.
NOT_COUNTED_CREATE = {'FlagStand': 0x62c9c0, 'Seat': 0x63d390}
ROWS = {k: [] for k in SOURCES}
COUNTED_TARGETS = {}   # symbol -> (address, receipt[, receipt symbol])
EXTERNAL = {}
IDENTIFIED = {}
FIND_CONST = {}
for c, (base, mangle, rmangle, cr, sp, cc, sc, ctor, vt) in CREATORS.items():
    ROWS['creators'].append((cr, creator(c, base, mangle)))
    COUNTED_TARGETS[scount(c)] = (sc, 'creatable-shared-count-working.json')
    if c in COUNTED_PAIR:
        COUNTED_TARGETS[create(c)] = (cc, COUNTED_PAIR[c])
        COUNTED_TARGETS[sptr(c)] = (sp, COUNTED_PAIR[c])
    else:
        ROWS['creators'].append((sp, sptr(c)))
        if c in NOT_COUNTED_CREATE:
            IDENTIFIED[create(c)] = (cc, NOT_COUNTED_CREATE[c])
        else:
            ROWS['creators'].append((cc, create(c)))
    EXTERNAL['??0%s@RBX@@QAE@XZ' % c] = ctor

# Name / classDescriptor instances (AppUnit5BC_2008Descriptors.cpp): (row, symbol or unique compiled-symbol prefix)
NM = '@Name@RBX@@'
DESC_ROWS = [
    (0x5bf870, '??$doDeclare@$1?sExplosion@RBX@@3PADA' + NM + 'CAABV01@XZ'),
    (0x5bf950, '??$doDeclare@$1?sFlagStandService@RBX@@3QBDB' + NM + 'CAABV01@XZ'),
    (0x5bfdb0, '??$doDeclare@$1?sObjectValue@RBX@@3PADA' + NM + 'CAABV01@XZ'),
    (0x5bff80, '??$callDoDeclare@$1?sExplosion@RBX@@3PADA' + NM + 'CAXXZ'),
    (0x5bffa0, '??$callDoDeclare@$1?sFlagStandService@RBX@@3QBDB' + NM + 'CAXXZ'),
    (0x5c0040, '??$callDoDeclare@$1?sObjectValue@RBX@@3PADA' + NM + 'CAXXZ'),
    (0x5c0320, ('?classDescriptor@?$Described@VExplosion@RBX@@', 'SAAAVClassDescriptor@23@XZ')),
    (0x5c0390, ('?classDescriptor@?$Described@VFlagStandService@RBX@@', 'SAAAVClassDescriptor@23@XZ')),
    (0x5c05c0, ('?classDescriptor@?$Described@VVisit@RBX@@', 'SAAAVClassDescriptor@23@XZ')),
    (0x5c08d0, ('?classDescriptor@?$Described@VJointInstance@RBX@@', 'SAAAVClassDescriptor@23@XZ')),
    (0x5c2c60, ('?classDescriptor@?$Described@VObjectValue@RBX@@', 'SAAAVClassDescriptor@23@XZ')),
]
_desc_funcs = [n for n, _, _ in match.coff_functions(Path(OBJ['descriptors']).read_bytes()) if not nb.LOCAL_EH.match(n)]
for _a, _s in DESC_ROWS:
    if isinstance(_s, tuple):
        _hits = [n for n in _desc_funcs if n.startswith(_s[0]) and n.endswith(_s[1])]
        assert len(_hits) == 1, (hex(_a), _s, _hits)
        _s = _hits[0]
    ROWS['descriptors'].append((_a, _s))
# The class-name arrays (defined by the class units, not here): bound by the string at the address the original pushes.
NAME_DATA = {'?sExplosion@RBX@@3PADA': 'Explosion', '?sFlagStandService@RBX@@3QBDB': 'FlagStandService',
             '?sObjectValue@RBX@@3PADA': 'ObjectValue', '?sVisit@RBX@@3PADA': 'Visit',
             '?sJointInstance@RBX@@3PADA': 'JointInstance'}
EXTERNAL['?declare@Name@RBX@@SAABV12@PBDH@Z'] = 0x553f90
EXTERNAL['??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z'] = 0x5708f0
EXTERNAL['??1ClassDescriptor@Reflection@RBX@@UAE@XZ'] = 0x40abc0
EXTERNAL['?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@'
         'SAAAVClassDescriptor@23@XZ'] = 0x40ad80
EXTERNAL['_atexit'] = 0x6a17af
EXTERNAL['?call_once@boost@@YAXP6AXXZAAJ@Z'] = 0x557330

# Visit unit rows (AppUnit5BC_2008Visit.cpp): (row, compiled-symbol prefix, required substrings)
STR = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
FPV = '?$FactoryProduct@VVisit@RBX@@VInstance@2@$1?sVisit@2@3PADA@RBX@@'
BT = '?$bind_t@W4work_result@worker_thread@RBX@@'
VISIT_ROWS = [
    (0x5c4400, '?setUploadUrl@Visit@RBX@@', ()),
    (0x5c4450, '??1' + FPV + 'MAE@XZ', ()),
    (0x5c4510, '??0' + FPV + 'IAE@XZ', ()),
    (0x5c46a0, '??0?$storage2@V?$value@' + STR, ('QAE@V?$value@',)),
    (0x5c4720, '??0?$list2@V?$value@' + STR, ('QAE@V?$value@',)),
    (0x5c4790, '??1Visit@RBX@@UAE@XZ', ()),
    (0x5c48d0, '??_GVisit@RBX@@UAEPAXI@Z', ()),
    (0x5c48f0, '?getClassName@' + FPV + 'UBEABVName@2@XZ', ()),
    (0x5c4910, '??$bind@W4work_result@worker_thread@RBX@@' + STR, ()),
    (0x5c49d0, '?invoke@?$function_obj_invoker0@V' + BT, ()),
    (0x5c4a00, '??$_Construct@V' + BT, ()),
    (0x5c4a60, '?manager@?$functor_manager@V' + BT, ('U?$bool_@$0A@@mpl',)),
    (0x5c4ae0, '?manage@?$functor_manager@V' + BT, ()),
    (0x5c4bb0, '?setPing@Visit@RBX@@', ()),
    (0x5c4d10, '??0?$DescribedCreatable@VVisit@RBX@@VInstance@2@$1?sVisit@2@3PADA@RBX@@IAE@XZ', ()),
    (0x5c4de0, '??_G' + FPV + 'MAEPAXI@Z', ()),
    (0x5c4e00, '??0?$BoundFuncDesc@VVisit@RBX@@$$A6AX' + STR + '@Z$00@', ()),
    (0x5c4ea0, '?execute@?$BoundFuncDesc@VVisit@RBX@@$$A6AX' + STR + '@Z$00@', ()),
    (0x5c4f80, '??0?$BoundFuncDesc@VVisit@RBX@@$$A6A?AV' + STR[1:] + 'XZ$0A@', ()),
    (0x5c4ff0, '?execute@?$BoundFuncDesc@VVisit@RBX@@$$A6A?AV' + STR[1:] + 'XZ$0A@', ()),
    (0x5c5220, '??0Visit@RBX@@QAE@XZ', ()),
]
# Deleting-destructor adjustor thunks (sub ecx, N; jmp ??_G): the FactoryProduct<Visit> ones (shared, ICF, with the
# DescribedCreatable<Visit> ones, which the original vtables 00838e0c..00838e7c also hold) jump to 005c4de0, the Visit
# ones to 005c48d0; the this-adjustment is read from the original bytes and named by the vtable offset.
ADJ = {0x10: 'BA', 0x14: 'BE', 0x24: 'CE', 0x44: 'EE', 0x64: 'GE', 0x84: 'IE', 0xa4: 'KE', 0xc4: 'ME'}
VISIT_THUNKS = [('??_E' + FPV + 'O%s@AEPAXI@Z', 0x5c4de0,
                 [0x5c4570, 0x5c4580, 0x5c4590, 0x5c45a0, 0x5c45b0, 0x5c4db0, 0x5c4dc0, 0x5c4dd0]),
                ('??_EVisit@RBX@@W%s@AEPAXI@Z', 0x5c48d0,
                 [0x5c4850, 0x5c4860, 0x5c4870, 0x5c4880, 0x5c4890, 0x5c48a0, 0x5c48b0, 0x5c48c0])]
for _pattern, _g, _rows in VISIT_THUNKS:
    for _a in _rows:
        _b = original.data(_a, 11)
        if _b[:2] == b'\x83\xe9':
            _adj = _b[2]
            assert _b[3] == 0xe9 and _a + 8 + struct.unpack_from('<i', _b, 4)[0] == _g, hex(_a)
        else:
            assert _b[:2] == b'\x81\xe9' and _b[6] == 0xe9, hex(_a)
            _adj = struct.unpack_from('<I', _b, 2)[0]
            assert _a + 11 + struct.unpack_from('<i', _b, 7)[0] == _g, hex(_a)
        ROWS['visit'].append((_a, _pattern % ADJ[_adj]))
_visit_funcs = [n for n, _, _ in match.coff_functions(Path(OBJ['visit']).read_bytes()) if not nb.LOCAL_EH.match(n)]
for _a, _prefix, _contains in VISIT_ROWS:
    _hits = [n for n in _visit_funcs if n.startswith(_prefix) and all(c in n for c in _contains)]
    assert len(_hits) == 1, (hex(_a), _prefix, _hits)
    ROWS['visit'].append((_a, _hits[0]))
# Visit::ping 005c45c0 (210 B) and its catch(...) funclet row 005c4692 (13 B) are one function: the compiled ping is exact
# against the two rows concatenated (BOUNDS evidence for the server host; bounds.json is not changed here).
SPLIT_ROWS = {'?ping@Visit@RBX@@SA?AW4work_result@worker_thread@2@' + STR + 'H@Z': (0x5c45c0, 0x5c4692)}
IDENTIFIED_BY_NAME = {}
VECTOR_DTOR = {'??_E' + FPV + 'MAEPAXI@Z': '??_G' + FPV + 'MAEPAXI@Z',
               '??_EVisit@RBX@@UAEPAXI@Z': '??_GVisit@RBX@@UAEPAXI@Z'}
# Pending-build-only rows (exact only against the generated reflection.h copy; recorded exact=false, never counted)
PENDING_ROWS = []
_pending_funcs = [n for n, _, _ in match.coff_functions(Path(OBJ['visit_pending']).read_bytes()) if not nb.LOCAL_EH.match(n)]
for _a, _prefix, _contains in [
        (0x5c5050, '??0?$BoundFuncDesc@VVisit@RBX@@$$A6AX' + STR + 'H@Z$01@', ()),
        (0x5c50e0, '?execute@?$BoundFuncDesc@VVisit@RBX@@$$A6AX' + STR + 'H@Z$01@', ()),
        (0x5c44b0, '?declareSignature@?$BoundFuncDesc@VVisit@RBX@@$$A6AX' + STR + 'H@Z$01@', ())]:
    _hits = [n for n in _pending_funcs if n.startswith(_prefix) and all(c in n for c in _contains)]
    assert len(_hits) == 1, (hex(_a), _prefix, _hits)
    assert _hits[0] not in _visit_funcs, ('pending row emitted by the current-header build', _hits[0])
    PENDING_ROWS.append((_a, _hits[0]))
EXTERNAL['??0worker_thread@RBX@@QAE@ABV?$function0@W4work_result@worker_thread@RBX@@V?$allocator@Vfunction_base@boost@@@std@@@boost@@PBD@Z'] = 0x5971d0
EXTERNAL['??1worker_thread@RBX@@QAE@XZ'] = 0x595cb0
EXTERNAL['?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z'] = 0x55af90
EXTERNAL['??1Instance@RBX@@UAE@XZ'] = 0x55a540
EXTERNAL['??0Instance@RBX@@QAE@XZ'] = 0x55b7e0
EXTERNAL['??2@YAPAXI@Z'] = 0x6a0920
EXTERNAL['??3@YAXPAX@Z'] = 0x6a067a
EXTERNAL['___RTDynamicCast'] = 0x6a17c6
DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
TEXT = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
        for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]
BINDING = {}
UNBOUND = []
HELPERS = {}


def bind(symbol, value, where):
    prev = BINDING.setdefault(symbol, (value, where))
    assert prev[0] == value, ('one address per symbol', symbol, hex(prev[0]), prev[1], hex(value), where)


def receipt_symbols(name, address):
    """Symbols another receipt records as counted exact at `address` (top-level exact_function_rows, else exact rows)."""
    data = json.loads((ROOT / 'work/2008-06/shared-layouts' / name).read_text())
    if 'exact_function_rows' in data and '%08x' % address not in [str(r) for r in data['exact_function_rows']]:
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
    """Vtables a constructor body stores (C7 /0 imm32 into a register base), with their original RTTI class."""
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


CONSTRUCTOR_PROOF = {}
IDENTITY_PROOF = {}


def prove_identity(value, proof):
    x = FUNCTIONS[value]
    if proof[0] == 'push-counted':
        _, pushed, rsym, receipt = proof
        body, _, _ = match.target('2008-06', '%08x' % value)
        assert b'\x68' + struct.pack('<I', pushed) in body, (hex(value), hex(pushed))
        assert rsym in receipt_symbols(receipt, pushed), (hex(value), hex(pushed), rsym)
        return 'its call_once push of %s %#x (counted by %s)' % (rsym[3:rsym.index('@')], pushed, receipt)
    if proof[0] == 'declares':
        hits = [t for t in x['call_targets'] if FUNCTIONS[int(t, 16)]['strings'] == [proof[1]]]
        assert len(hits) == 1, (hex(value), proof, hits)
        return 'its Name::doDeclare callee %s, which declares %r' % (hits[0], proof[1])
    if proof[0] == 'calls-named':
        _, callee, sym = proof
        assert '%08x' % callee in x['call_targets'] and names.get(callee) == sym, (hex(value), proof)
        return 'its call to %s %#x (evidence name)' % (sym[:40], callee)
    raise AssertionError(proof)


def prove_constructor(symbol, value):
    cls = symbol[3:-len('@RBX@@QAE@XZ')]
    if names.get(value, '') == symbol:
        return 'evidence name'
    stores = [v for v, c in ctor_vtables(value) if c == ('.?AV%s@RBX@@' % cls, 0)]
    assert stores, (symbol, hex(value), ctor_vtables(value))
    return 'stores the .?AV%s@RBX@@ complete-object vtable %s' % (cls, hex(stores[0]))


def verify(build, obj, rows):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    own = {s: a for a, s in rows}
    out = []
    for address, name in rows:
        assert name in bodies, (build, hex(address), name)
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        exact = match.exact_match(target, target_refs, body, refs)
        row = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
               'exact': bool(exact), 'build': build, 'verified_targets': {}, 'local_eh': []}
        out.append(row)
        if not exact:
            continue
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
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
            where = '%08x+%#x' % (address, offset)
            if nb.LOCAL_EH.match(symbol):
                row['local_eh'].append(symbol)
                continue
            how = None
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol in own:
                assert own[symbol] == value, (where, symbol, hex(value))
                how = 'own row'
            elif symbol.startswith('??_C@'):
                pos, at = definitions[symbol]
                lit = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(lit)) == lit, (where, symbol, hex(value))
                how = 'literal %r' % lit[:-1].decode()
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in COUNTED_TARGETS:
                other, receipt, rsym = (COUNTED_TARGETS[symbol] + (symbol,))[:3]
                assert other == value, (where, symbol, hex(value), hex(other))
                assert rsym in receipt_symbols(receipt, value), (receipt, hex(value), rsym)
                if symbol in bodies:
                    hb, hr = bodies[symbol]
                    ht, htr, _ = match.target('2008-06', '%08x' % value)
                    assert match.exact_match(ht, htr, hb, hr), ('counted-elsewhere body not exact', symbol, hex(value))
                how = 'row counted by %s as %s (body exact at the bound address)' % (receipt, rsym[:24])
            elif symbol in FIND_CONST:
                other, proof = FIND_CONST[symbol]
                assert other == value, (where, symbol, hex(value), hex(other))
                how = 'open row (not counted), identified by ' + IDENTITY_PROOF.setdefault(symbol, prove_identity(value, proof))
            elif symbol in IDENTIFIED:
                other, ctor = IDENTIFIED[symbol]
                assert other == value, (where, symbol, hex(value), hex(other))
                cls = symbol[len('??$create@V'):symbol.index('@RBX@@@')]
                assert names.get(ctor) == '??0%s@RBX@@QAE@XZ' % cls, (symbol, hex(ctor))
                assert '%08x' % ctor in FUNCTIONS[value]['call_targets'], (symbol, hex(value), hex(ctor))
                how = 'open row of this range (not counted), identified by its call to ??0%s@RBX@@QAE@XZ %#x ' \
                      '(evidence name)' % (cls, ctor)
            elif re.match(r'\?\?0\?\$signal[12]@X', symbol) and symbol.endswith('@QAE@ABU?$last_value@X@1@ABU?$less@H@std@@@Z'):
                # boost signal constructor: one ICF-shared body 00499c00 for every signature (record_native_app_unit4b0
                # and humanoid2008 bind it the same way); bound by the call site, its body is not compared (the
                # original calls 0060a2f0 there, a boost.function configuration difference not built here)
                assert value == 0x499c00, (where, symbol, hex(value))
                how = 'external (ICF-shared boost signal constructor, body not compared)'
            elif symbol in NAME_DATA:
                assert original.string(value) == NAME_DATA[symbol], (where, symbol, hex(value))
                how = 'class-name array %r (string at the pushed address)' % NAME_DATA[symbol]
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
                if symbol.startswith('??0') and symbol.endswith('@RBX@@QAE@XZ'):
                    how = 'constructor: ' + CONSTRUCTOR_PROOF.setdefault(symbol, prove_constructor(symbol, value))
                else:
                    how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
            elif symbol in SPLIT_ROWS:
                # one compiled function whose original extent is split into two function rows (BOUNDS evidence):
                # the body must be exact against the two rows concatenated; neither row is counted
                parts = SPLIT_ROWS[symbol]
                assert parts[0] == value, (where, symbol, hex(value))
                ct, cr = b'', []
                for p in parts:
                    pt, ptr, _ = match.target('2008-06', '%08x' % p)
                    cr += [x + len(ct) for x in ptr]
                    ct += pt
                hb, hr = bodies[symbol]
                assert match.exact_match(ct, cr, hb, hr), (where, symbol, 'split body not exact')
                how = 'open row (not counted): exact against rows %s concatenated (BOUNDS)' % ' + '.join(
                    '%#x' % p for p in parts)
            elif symbol in bodies and names.get(value, '') == symbol and not match.exact_match(
                    *match.target('2008-06', '%08x' % value)[:2], *bodies[symbol]):
                how = 'open row identified by its evidence name (compiled body not exact; not counted)'
                IDENTIFIED_BY_NAME.setdefault('%08x' % value, symbol)
            elif symbol in bodies:
                # helper / COMDAT body compiled here but not a row: exact at the bound address, never counted
                hb, hr = bodies[symbol]
                ht, htr, _ = match.target('2008-06', '%08x' % value)
                assert match.exact_match(ht, htr, hb, hr) or DISCOVER, (where, symbol, hex(value))
                HELPERS.setdefault(symbol, '%#x' % value)
                how = 'helper body exact at the bound address (not counted)'
            elif symbol in definitions and symbol not in bodies:
                assert any(lo <= value < hi for lo, hi in DATA_SECTIONS), (where, symbol, hex(value))
                how = 'own static (bound by consistency)'
            elif symbol in VECTOR_DTOR and VECTOR_DTOR[symbol] in own:
                # the thunks jump to the vector deleting destructor; the original slot holds the ??_G row
                assert own[VECTOR_DTOR[symbol]] == value, (where, symbol, hex(value))
                how = 'own row %s (scalar deleting destructor; no array delete in the original)' % VECTOR_DTOR[symbol][:40]
            elif names.get(value, '') == symbol:
                how = 'external (evidence name)'
            if how is None:
                UNBOUND.append((where, symbol, hex(value), names.get(value, '')[:80]))
                continue
            bind(symbol, value, where)
            row['verified_targets'][symbol] = '%#x (%s)' % (value, how)
    return out


groups = {k: verify(k, OBJ[k], ROWS[k]) for k in SOURCES}
not_exact = [r for rows in groups.values() for r in rows if not r['exact']]
if DISCOVER:
    for u in UNBOUND:
        print('UNBOUND', u)
    for r in not_exact:
        print('NOT EXACT', r['address'], r['size'], r['target_size'], r['symbol'][:100])
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]
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


RDATA = [s for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.rdata'][0]
RDATA_VA = original.image + RDATA.VirtualAddress
RDATA_BYTES = RDATA.get_data()


def rdata_refs(value):
    pat = struct.pack('<I', value)
    return [RDATA_VA + m.start() for m in re.finditer(re.escape(pat), RDATA_BYTES) if m.start() % 4 == 0]


def derived_signal_desc(cls, rtti):
    """A compiled TSignalDesc<Sig> / SignalDescImpl<N, Sig> vtable slot found in an original SignalDesc<Class, Sig>
    vtable (the per-class derived template, not built here) of the same signature."""
    m = re.match(r'\?\$(?:TSignalDesc@|SignalDescImpl@\$0\d)\$\$A6A(.+)@Reflection@RBX@@$', cls)
    r = re.match(r'\.\?AV\?\$SignalDesc@V\w+@(?:\w+@)*?(?:RBX@@|\d)\$\$A6A(.+)@Reflection@RBX@@$', rtti)
    return bool(m and r and m.group(1) == r.group(1))


def slot_hits(obj, rows):
    compiled = compiled_vtables(obj)
    out = []
    for row in rows:
        symbol, address = row['symbol'], int(row['address'], 16)
        places = [(vt, i) for vt, slots in compiled.items() for i, s in slots.items() if s == symbol]
        if not places:
            continue
        hits = []
        for vt, i in places:
            cls = vt[4:vt.index('@@6B') + 2]
            for ref in rdata_refs(address):
                try:
                    rtti, at = original.vtable_class(ref - 4 * i)
                except Exception:
                    continue
                if norm(rtti) == norm('.?AV' + cls) or derived_signal_desc(cls, rtti):
                    hits.append({'vtable': hex(ref - 4 * i), 'rtti': rtti, 'offset': hex(at), 'slot': i, 'compiled': vt})
        assert hits or DISCOVER, (row['address'], symbol, places)
        row['vtable_slots'] = hits
        out.append((row['address'], len(hits)))
    return out


# counted rows: slots from the current-header objects only
pending = verify('visit_pending', OBJ['visit_pending'], PENDING_ROWS)

# counted rows: slots from the current-header objects only
SLOTS = []
for k in SOURCES:
    SLOTS += slot_hits(OBJ[k], groups[k])
# pending rows (never counted): slots from the pending object, informational
slot_hits(OBJ['visit_pending'], pending)

# ---- Creator vtables (original): slot 0 is the counted Creator::create row; the RTTI names the class ---------------
creator_vtables = []
for c, (base, mangle, rmangle, cr, sp, cc, sc, ctor, vt) in CREATORS.items():
    rtti, at = original.vtable_class(vt)
    want = '.?AVCreator@?$FactoryProduct@V%s@RBX@@V%s@2@$1?s%s@2@%s@RBX@@' % (c, base, c, rmangle)
    assert (rtti, at) == (want, 0), (c, hex(vt), rtti, at)
    assert d(vt) == cr, (c, hex(vt), hex(d(vt)), hex(cr))
    slots = 0
    while TEXT[0] <= d(vt + 4 * slots) < TEXT[1]:
        slots += 1
    assert slots == 1, (c, hex(vt), slots)
    creator_vtables.append({'vtable': hex(vt), 'rtti': rtti, 'original_slots': slots,
                            'slot0': '%s (Creator::create row)' % hex(cr)})


# ---- sizeof(C): the malloc size each create<C> passes ---------------------------------------------------------------
def malloc_size(address):
    body, _, _ = match.target('2008-06', '%08x' % address)
    sizes = [struct.unpack_from('<I', body, k.start() + 1)[0] for k in re.finditer(rb'\x68', body)]
    return [s for s in sizes if 0x40 <= s < 0x4000]


SIZES = {}
for c, (base, mangle, rmangle, cr, sp, cc, sc, ctor, vt) in CREATORS.items():
    got = malloc_size(cc)
    assert len(got) == 1, (c, hex(cc), [hex(x) for x in got])
    if c in NOT_COUNTED_CREATE:
        note = '; the native header gives a smaller sizeof, so that row is not exact and not counted'
    elif c in COUNTED_PAIR:
        note = '; that row is counted by ' + COUNTED_PAIR[c]
    else:
        note = ', exact here against the native header layout'
    SIZES[c] = 'sizeof %#x (malloc %#x in create<%s> %#x%s)' % (got[0], got[0], c, cc, note)
assert all(r['exact'] for r in pending) or DISCOVER, [r['address'] for r in pending if not r['exact']]


# ---- unit map evidence -------------------------------------------------------------------------------------------
def holds_string(address, text):
    """The row's bytes hold a DIR32 pointer to that exact NUL-terminated string."""
    x = FUNCTIONS[address]
    body = original.data(address, x['size'])
    for i in range(len(body) - 3):
        v = struct.unpack_from('<I', body, i)[0]
        if any(lo <= v < hi for lo, hi in DATA_SECTIONS):
            try:
                if original.string(v) == text:
                    return True
            except Exception:
                pass
    return False


BLOCKS = [
    ('rbx sound unit (Soundscape::SoundService / SoundChannel / StockSound; starts below the range)', LO, 0x5bf0d0,
     'rbx', [(0x5bc160, 'Soundscape'), (0x5bcc40, '# Sounds'), (0x5bcd80, 'fmod %08x'), (0x5bdb10, 'Sounds\\bass.wav')]),
    ('rbx v8datamodel/GameSettings.cpp (settings-items counts it)', 0x5bf0d0, 0x5bf800, 'rbx',
     [(0x5bf580, 'singleton %s already exists'), (0x5bf680, 'Game Options')]),
    ('rbx class-registration unit (Name / classDescriptor / Creatable instances, ObjectValue)', 0x5bf800, 0x5c3ed0,
     'rbx', [(0x5bf800, 'ClickDetector'), (0x5bf870, 'Explosion'), (0x5c3ab0, 'Value')]),
    ('rbx util/Profiling.cpp', 0x5c3ed0, 0x5c4400, 'rbx', []),
    ('rbx v8datamodel/Visit.cpp', 0x5c4400, 0x5c5300, 'rbx', [(0x5c4bb0, 'rbx_visit'), (0x5c5220, 'NoVisit')]),
    ('rbx command verbs / tool verbs unit (continues past the range)', 0x5c5300, HI, 'rbx',
     [(0x5c5300, 'TranslucentVerb'), (0x5c6010, 'AnchorVerb'), (0x5c7ea0, 'PlayDelete')]),
]
range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)
for a in range_rows:
    assert sum(lo <= a < hi for _, lo, hi, _, _ in BLOCKS) == 1, hex(a)
for name, lo, hi, kind, ev in BLOCKS:
    for a, text in ev:
        assert lo <= a < hi and holds_string(a, text), (name, hex(a), text)
assert names.get(0x5c3f00) == '?init@Profiling@RBX@@YAX_N@Z'
assert original.vtable_class(0x838c54)[0] == '.?AVProfiler@Profiling@RBX@@'
assert names.get(0x5bf260, '').startswith('?getClassName@?$FactoryProduct@VGameSettings@RBX@@')
assert names.get(0x5c4400, '').startswith('?setUploadUrl@Visit@RBX@@')
# the registration constructor 005c3ca0 calls the classDescriptor rows of the block (and of other units' classes)
_reg = set(FUNCTIONS[0x5c3ca0]['call_targets'])
assert {'%08x' % a for a in (0x5c0320, 0x5c0390, 0x5c05c0, 0x5c3a40, 0x5c3420)} <= _reg, sorted(_reg)
# the verb-registration function 005c7ea0 is called only from the CRobloxDoc initializer 00451b60 (maintainer
# exclusion covers CRobloxDoc itself; this unit is not a CRobloxDoc member, but its rows belong to the verb owners)
assert FUNCTIONS[0x5c7ea0]['callers'] == ['00451b60']


def counted_elsewhere():
    """Rows other receipts count: their top-level exact_function_rows (or an equivalent key); for receipts without
    one, every row object marked exact anywhere in the receipt (a conservative reading of their counted lists)."""
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
        rows = []
        for key in ('exact_function_rows', 'exact_addresses', 'exact_unique_addresses', 'exact_distinct_addresses'):
            if isinstance(data.get(key), (list, dict)):
                rows = list(data[key])
                break
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        rows.append(o['address'])
                    for v in o.values():
                        walk(v)
            walk(data)
        for r in rows:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}
open_rows = ['%08x' % a for a in range_rows if '%08x' % a not in exact_rows and '%08x' % a not in range_counted]

def category(a):
    n = names.get(a, '')
    if not n:
        return 'unnamed'
    head = n.split('@@')[0]
    if re.search(r'@(std|boost)$|@(algorithm|detail|signals|_bi|any|function)@', head) or n.startswith('??$_') or \
            '@std@@' in head or '@boost@@' in head:
        return 'STL/boost template instance'
    return 'RBX'


OPEN_CATEGORIES = {}
for a in open_rows:
    OPEN_CATEGORIES.setdefault(category(int(a, 16)), []).append('%#x' % int(a, 16))
OPEN_CATEGORIES = {}
for a in open_rows:
    OPEN_CATEGORIES.setdefault(category(int(a, 16)), []).append('%#x' % int(a, 16))

UNIT_MAP = {
    'rbx sound unit 005bc000..005bf0cf (starts below the range)': (
        'The Soundscape unit (SoundService, SoundChannel, StockSound, SoundServiceStatsItem): BoundFuncDesc<SoundChannel, '
        'void()> 0x5bc090 (Play/Pause/Stop initializers 0x7f5480..0x7f54e0), SoundService members with the fmodex '
        'imports (set3DListenerAttributes / update / Channel userdata, 0x5bc2c0..0x5bc6ff), TypedStatsItem<unsigned> and '
        'SoundServiceStatsItem (strings "# Sounds" / "fmod %08x", 0x5bc860..0x5bd0ef), DescribedCreatable<StockSound, '
        'SoundChannel> and the StockSound Creator 0x5bda60 (vtable 0x837b18, RTTI names sStockSound a char array), the '
        'stock sound list 0x5bdb10 ("Sounds\\\\bass.wav", ...), and the StringConverter<T> / boost::lexical_cast COMDATs '
        '0x5bde30..0x5bf0cf (evidence names; T = bool, int, unsigned, float, double, BrickColor, Vector3, Color3). '
        'Not recovered: no native SoundService / SoundChannel class header exists (util/Sound.h is the Sound item only).'),
    'rbx v8datamodel/GameSettings.cpp 005bf0d0..005bf7ff': (
        'GameSettings (GlobalSettingsItem<GameSettings>; "Game Options", "singleton %s already exists"); counted by '
        'settings-items-working.json.'),
    'rbx class-registration unit 005bf800..005c3ecf': (
        'One unit whose COMDAT run holds, in link order: Name::doDeclare<sC> (101 B) for ClickDetector, Explosion, '
        'FlagStand, FlagStandService, ForceField, Geometry, BodyGyro..BodyAngularVelocity, RocketPropulsion, ObjectValue, '
        'Debris, Seat, Sparkles (their static initializers 0x7f5650..0x7f5b50), the matching Name::callDoDeclare<sC> '
        'jumps 0x5bff70..0x5c0070, Described<C>::classDescriptor() 0x5c0080..0x5c09ff and 0x5c3420..0x5c3a3f (StarterPack, '
        'Hopper, Backpack, ShirtGraphic, BodyColors, ClickDetector, Explosion, FlagStandService, ForceField, Geometry, '
        'LocalBackpackItem, LocalBackpack, Visit, ControllerService, Debris, Timer, Sparkles, SpawnerService, Humanoid, '
        'JointInstance, Feature, BackpackItem, the seven joints, MotorFeature, Hole, Tool, Flag, FlagStand, Seat), the '
        'Creatable / FactoryProduct block 0x5c0a20..0x5c33ff (shared_count, shared_ptr(C*, Deleter), create<C>, '
        'Creator::create for 16 classes; Creator vtables 0x83882c..0x838aac), the ObjectValue FactoryProduct / '
        'DescribedCreatable bodies, thunks and inline constructor 0x5c29d0..0x5c2c5f / 0x5c3960..0x5c3d9f (vtables '
        '0x8389a0.., RTTI .?AVObjectValue@RBX@@ 0x838bf8), the registration constructor 0x5c3ca0 (calls every '
        'classDescriptor above and in other units) and create<ObjectValue> 0x5c3da0 / its Creator 0x5c3e20.'),
    'rbx util/Profiling.cpp 005c3ed0..005c43ff': (
        'Profiler / CodeProfiler / CountProfiler (RTTI vtables 0x838c54 / 0x838c5c / 0x838c64) and Profiling::init '
        '0x5c3f00 (evidence name). Not recovered: util/Profiling.h belongs to its owner and these rows are not '
        'instantiated by this receipt.'),
    'rbx v8datamodel/Visit.cpp 005c4400..005c52ff': (
        'Visit::setUploadUrl 0x5c4400 (inline, first emitted here), FactoryProduct<Visit> / DescribedCreatable<Visit> '
        'constructors, destructors and adjustor thunks (vtables 0x838c74..0x838ce4 and 0x838e0c..0x838e7c, ICF-shared '
        'between the two templates), the boost::bind / function0 instances of setPing, Visit::ping 0x5c45c0 with its '
        'catch(...) funclet 0x5c4692, ~Visit 0x5c4790, the Visit thunks 0x5c4850..0x5c48df, getClassName 0x5c48f0, '
        'setPing 0x5c4bb0 ("rbx_visit"), the BoundFuncDesc<Visit> instances of SetUploadUrl / GetUploadUrl / SetPing '
        '(vtables 0x838ed0 / 0x838edc / 0x838ee8) and Visit() 0x5c5220 ("NoVisit", setName("Visit")). sizeof 0x150: '
        'uploadUrl +0x130 (0x1c bytes), pingThread +0x14c (constructor and destructor).'),
    'rbx command verbs / tool verbs unit 005c5300..005c8000 (continues past the range)': (
        'BoolPropertyVerb subclasses (TranslucentVerb 0x5c5300, CanCollideVerb, AnchorVerb), MoveUp*Verb, the tool-name '
        'Name::doDeclare instances 0x5c5520..0x5c5fa0 (Fill .. AxisMove), the ICF-shared 5-byte verb leaves '
        '0x5c60b0..0x5c623f, TToolVerb<T, RunStateVerb> instances and the tool classes (ArrowTool .. LaserTool, RTTI '
        '0x8390c8..0x839b74), and the verb-registration function 0x5c7ea0 (2676 B, runs past the range) that the '
        'CRobloxDoc initializer 0x451b60 calls. Not recovered here: the tool / verb rows are worked by the tool and '
        'document owners (tool-checked-multi-trial, resize-tool-*, axis-move-tool-*, document-initialize-trial).'),
    'library code': (
        'No separately compiled library unit starts in the range. The STL / boost rows are template instances emitted '
        'in these RBX units (lexical_cast, boost::bind / function, shared_ptr); fmodex is reached through imports only. '
        'Generic library instances are not recovered except where instantiated on this unit\'s Visit signatures and '
        'every caller is a counted row (bind / storage2 / list2 / functor_manager / invoker of setPing).'),
    'excluded': (
        'No CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView member lies in the range; 0x5c7ea0 is only called by the '
        'CRobloxDoc initializer 0x451b60 and is mapped with the verbs unit, not recovered.'),
}
NOT_EXACT = {
    '0x5c1040 / 0x5c3080 Creatable<Instance>::create<FlagStand> / create<Seat>': (
        'malloc 0x41c / 0x43c in the original; the native FlagStand.h / Seat.h (over the native PartInstance.h of other '
        'owners) give sizeof 0x304 / 0x324 (0x118 short each). Open; their shared_ptr and Creator rows are exact and '
        'counted, the Creator call is bound by identity (evidence-named constructor).'),
    '0x5c45c0 Visit::ping + 0x5c4692 catch funclet': (
        'the compiled ping is byte-exact against the two rows concatenated (223 B = 210 + 13), every target bound; '
        'neither row is counted until the extent is fixed (BOUNDS proposal).'),
    '0x5c4b20 function0<work_result>(bind_t) constructor': (
        '121 / 124 B compiled against 135 B in the original (boost.function assign_to configuration); open, bound by '
        'its evidence name where setPing calls it.'),
    '0x5c4710': 'a 5-byte jmp to ~FactoryProduct<Visit> 0x5c4450: the ICF-folded ~Described / ~DescribedCreatable '
                '<Visit>; which symbol it is cannot be derived; open.',
    '0x5c5050 / 0x5c50e0 / 0x5c44b0 BoundFuncDesc<Visit, void(std::string, int), 2> (SetPing)': (
        'pending-build-only: the core reflection/reflection.h declares the two-argument constructor without a body, so '
        'the current-header build emits no SetPing descriptor; exact (constructor, execute, declareSignature) with the '
        'generated copy out/app-unit5bc-2008/pending/reflection/reflection.h (proposal).'),
    'joint classDescriptors 0x5c3420..0x5c36c0 (Snap, Weld, Glue, Rotate, RotateP, RotateV, Motor)': (
        'each calls JointInstance::classDescriptor 0x5c08d0 directly; the native JointInstance.h derives the joints '
        'from AutoJoint, so the compiled body calls AutoJoint\'s descriptor. Not built (JointInstance.h proposal of '
        'app-unit4b0 / app-unit5dc).'),
}
REJECTED = {
    'Visit::ping with the donor catch (std::exception&) and G3D::format / StandardOut::print': (
        '335 B against 210 + 13 B: the 2008 handler 0x5c4692 is an empty catch(...) that resumes at 0x5c464b'),
}
PROPOSALS = {
    'native-headers/reflection/reflection.h (core owner)': (
        'give BoundFuncDesc<Class, Function, 2>(function, name, arg1Name, arg2Name, security) the body of its '
        'one-argument sibling: `: FuncDesc(name, security), function(function), default1(), default2() { '
        'declareSignature(arg1Name, arg2Name); }`. Evidence: Visit SetPing descriptor 0x5c5050 (initializer 0x7f5c00, '
        '"SetPing" / "pingUrl" / "interval", vtable 0x838ee8): FuncDesc ctor 0x595790 with Visit::classDescriptor, '
        'function pointer stored at +0x38/+0x3c, Value() 0x594ac0 at +0x40 and +0x48, then declareSignature 0x5c44b0. '
        'With the generated copy the constructor, execute 0x5c50e0 and declareSignature are byte-exact with every '
        'target bound (pending_build_only here, exact=false).'),
    'v8datamodel/FlagStand.h / Seat.h / PartInstance.h (owners)': (
        'sizeof(FlagStand) is 0x41c and sizeof(Seat) 0x43c in 2008 (mallocs in create<FlagStand> 0x5c1040 / '
        'create<Seat> 0x5c3080); the native headers give 0x304 / 0x324, 0x118 short each (the missing embedded '
        'Primitive of the PartInstance proposal, as for SpawnLocation 0x424).'),
    'v8datamodel/Sparkles.h (effects owner), FYI': (
        'the original RTTI names sSparkles a non-const char array ($1?sSparkles@2@3PADA in the Creator vtable 0x838aac '
        'RTTI); the header declares `extern const char sSparkles[]`. The rows counted here are exact either way (symbol '
        'mangling only).'),
    'BOUNDS (server host; bounds.json not changed)': (
        'function row 0x5c45c0 (Visit::ping, 210 B) and row 0x5c4692 (13 B) are one function: the second is the '
        'catch(...) funclet of the first (`mov [ebp-4], 0; mov eax, 0x5c464b; ret`), so the 0x5c45c0 extent is 0xdf.'),
}

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
receipt = {
    'class': 'RBX class-registration / Visit unit rows of the application range 005bc000..005c8000 (2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), document-swap flags, /fp:fast',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'layout': SIZES,
    'unit_map': UNIT_MAP,
    'unit_blocks': ['%#x..%#x %s (%s)' % (lo, hi, n, k) for n, lo, hi, k, _ in BLOCKS],
    'range_functions': len(range_rows),
    # 'ADDR counted by RECEIPT' text, never a quoted bare address (local_backpack / viewnew_brick_build /
    # viewnew_part_mesh treat any quoted bare address in another receipt as counted there).
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_open': ['%#x (open)' % int(a, 16) for a in open_rows],
    'range_rows_open_by_category': OPEN_CATEGORIES,
    'rows': groups,
    'creator_vtables': creator_vtables,
    'helper_bodies_not_counted': HELPERS,
    'identified_by_evidence_name_not_counted': {'%#x' % int(k, 16): v for k, v in IDENTIFIED_BY_NAME.items()},
    'pending_build_only': [{'row': '%#x (pending-build-only, exact=false)' % int(r['address'], 16),
                            'symbol': r['symbol'], 'exact': False, 'pending_exact': r['exact'],
                            'verified_targets': r['verified_targets'],
                            'vtable_slots_in_pending_object': [dict(h, vtable=h['vtable'] + ' (pending object)')
                                                               for h in r.get('vtable_slots', [])]}
                           for r in pending],
    'not_exact': NOT_EXACT,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
# pending rows carry their address only as text
for _r in pending:
    _r['address'] = '%#x (pending-build-only)' % int(_r['address'], 16)
text = json.dumps(receipt, indent=2) + '\n'
bare = set(re.findall(r'"([0-9a-f]{8})"', text))
assert bare <= set(exact_rows), sorted(bare - set(exact_rows))
if DISCOVER:
    print('DISCOVER: receipt not written; %d exact rows' % len(exact_rows))
    sys.exit(0)
RECEIPT.write_text(text)
print('PASS app-unit5bc-2008: %d counted exact rows (%s); %d range rows, %d counted elsewhere, %d open; %d Creator '
      'vtables checked; %d pending-build-only' % (len(exact_rows), ' '.join(exact_rows), len(range_rows),
                                                  len(range_counted), len(open_rows), len(creator_vtables), len(pending)))
