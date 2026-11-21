"""Verify the inactive 2008-06 native rows of the application range 00564000..00570000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are written there as
'ADDR counted by RECEIPT' text, never as a quoted bare address).

Units built here (all VS2008 RTM 21022, document-swap flags, /fp:fast):
  * reflection type singletons: native-classes/AppUnit564_2008Type.cpp against the native reflection/type.h
    (read-only): the Type::singleton<T> explicit specializations 0056ca70..0056d120 (function-local static
    Type(name, typeid(T)) through the header-inline Type(const char*, const type_info&) COMDAT 0056bd90) and their
    atexit destructors 007fd210..007fd2f0.
  * Value::genericConvert<T> / convert<Objects>: native-classes/AppUnit564_2008GenericConvert.cpp (/Ob2, the body
    of the committed SoundValueGenericFloat.cpp), 0056d090 and 0056d410..0056de80.
  * Value::convert<T>: native-classes/AppUnit564_2008ValueConvert.cpp (/Ob1, the body shape of the committed
    SoundValueConvertFloat.cpp), 0056ea60 / 0056ebb0 / 0056ee50 and the forwarders 0056efa0..0056eff0.
  * Selection template instances: native-classes/AppUnit564_2008Selection.cpp against the native
    v8datamodel/Selection.h (read-only).
No new header is created (no shadowing).

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, string literals by bytes, type
descriptors and vtables by original RTTI names, own rows, local statics by one address per symbol, compiler helper /
COMDAT bodies by an exact comparison at the bound address (their own targets verified the same way), the remaining
externals by the explicit EXTERNAL map. A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit564-2008-working.json. Set NATIVE_APP_UNIT564_DISCOVER=1 to list unbound
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
OUT = nb.OUT / 'app-unit564-2008'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'type': (R / 'native-classes/AppUnit564_2008Type.cpp', []),
    'gconv': (R / 'native-classes/AppUnit564_2008GenericConvert.cpp', []),
    'vconv': (R / 'native-classes/AppUnit564_2008ValueConvert.cpp', ['/Ob1']),
    'sel': (R / 'native-classes/AppUnit564_2008Selection.cpp', []),
}
HEADERS = [R / 'native-headers/reflection/type.h', R / 'native-headers/reflection/reflection.h',
           R / 'native-headers/v8datamodel/Selection.h', R / 'native-headers/v8datamodel/SelectionChanged.h',
           R / 'native-headers/v8tree/Instance.h', R / 'native-headers/v8tree/Service.h',
           R / 'native-headers/util/Events.h']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT564_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit564-2008-working.json'
RANGE = ('00564000', '00570000')


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = ([x for x in extra if x.startswith('/I')] + nb.flags() + ['/fp:fast']
             + [x for x in extra if not x.startswith('/I')] + ['/Fo' + str(obj), str(src)])
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


# ---- pending header copy (generated, build-local): v8datamodel/Selection.h with the 2008 declarations ---------------
PENDING_DIR = OUT / 'pending'
(PENDING_DIR / 'v8datamodel').mkdir(parents=True, exist_ok=True)
_selection = (R / 'native-headers/v8datamodel/Selection.h').read_text()
_name_old = 'extern char sSelection[];'
_base_old = 'class __declspec(novtable) ISelectionBase {\n'
_member_anchor = '    std::vector<ISelectionBase*> filteredSelections;\n'
assert _selection.count(_name_old) == 1 and _selection.count(_base_old) == 1 and _selection.count(_member_anchor) == 1
PENDING_SELECTION = {
    # RTTI .?AV?$FactoryProduct@VSelection@RBX@@VInstance@2@$1?sSelection@2@3QBDB@RBX@@ (vtable 0082ece4): const array
    _name_old: 'extern const char sSelection[];',
    # raiseAdded 00566ba0 / raiseRemoved 00566d50 call ISelectionBase::onSelectionChanged (slot 0)
    _base_old: _base_old + '    friend class Selection;\n',
    _member_anchor: _member_anchor + (
        '    Selection();                                                // 00568180\n'
        '    virtual ~Selection();                                       // 00566f00 (??_G 00567160)\n'
        '    boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > getSelection2();          // 00566a80\n'
        '    void setSelection(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >);       // 00568330\n'
        '    void toggleSelection(Instance*);                            // 00567210\n'
        '    void addFilteredSelection(ISelectionBase*);                 // 00567180\n'
        'protected:\n'
        '    virtual void onEvent(const Instance*, AncestorChanged);     // 005682e0\n'
        'private:\n'
        '    void raiseAdded(boost::shared_ptr<Instance>);               // 00566ba0\n'
        '    void raiseRemoved(boost::shared_ptr<Instance>);             // 00566d50\n'
        'public:\n'),
}
_pending_selection = _selection
for _old, _new in PENDING_SELECTION.items():
    _pending_selection = _pending_selection.replace(_old, _new)
(PENDING_DIR / 'v8datamodel/Selection.h').write_text(
    '// generated by tests/record_native_app_unit564_2008.py (pending build only; proposal for v8datamodel/Selection.h)\n'
    + _pending_selection)

OBJ, FLAGS = {}, {}
for key, (src, extra) in SOURCES.items():
    OBJ[key], FLAGS[key] = build('NativeAppUnit564_2008_' + key, src, extra)
OBJ['sel_pending'], FLAGS['sel_pending'] = build(
    'NativeAppUnit564_2008_sel_pending', SOURCES['sel'][0], ['/DNATIVE_APPUNIT564_PENDING', '/I' + str(PENDING_DIR)])

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

OBJS = 'V?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@'
STR = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
TAB = 'V?$vector@VValue@Reflection@RBX@@V?$allocator@VValue@Reflection@RBX@@@std@@@std@@'
SING = '??$singleton@%s@Type@Reflection@RBX@@SAABV012@XZ'
ATEXIT = '??__Ftype@?1???$singleton@%s@Type@Reflection@RBX@@SAABV012@XZ@YAXXZ'
GEN = '??$genericConvert@%s@Value@Reflection@RBX@@QAEAA%sXZ'
CONV = '??$convert@%s@Value@Reflection@RBX@@QAEAA%sXZ'
# (Type argument, its return-type spelling in the mangled name)
SINGLETONS = [
    (0x56ca70, 0x7fd210, 'V?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@'),
    (0x56cae0, 0x7fd220, 'V?$shared_ptr@VInstance@RBX@@@boost@@'),
    (0x56cb50, 0x7fd230, OBJS),
    (0x56cbc0, 0x7fd240, 'H'),
    (0x56cc30, 0x7fd250, '_N'),
    (0x56cca0, 0x7fd260, 'M'),
    (0x56cd10, 0x7fd270, 'N'),
    (0x56cd80, 0x7fd280, 'VContentId@RBX@@'),
    (0x56cdf0, 0x7fd290, STR),
    (0x56ce60, 0x7fd2a0, 'VVector3@G3D@@'),
    (0x56ced0, 0x7fd2b0, 'VVector2int16@G3D@@'),
    (0x56cf40, 0x7fd2c0, 'VColor3@G3D@@'),
    (0x56cfb0, 0x7fd2d0, TAB),
    (0x56d120, 0x7fd2f0, 'VBrickColor@RBX@@'),
]
ROWS = {
    'type': [(0x56bd90, '??0Type@Reflection@RBX@@IAE@PBDABVtype_info@@@Z')]
            + [(a, SING % t) for a, _, t in SINGLETONS] + [(x, ATEXIT % t) for _, x, t in SINGLETONS],
    'gconv': [
        (0x56d090, CONV % (OBJS, 'V?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$'
                                 'shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@')),
        (0x56d410, GEN % ('H', 'H')),
        (0x56d530, GEN % ('_N', '_N')),
        (0x56d770, GEN % ('N', 'N')),
        (0x56d890, GEN % ('VVector3@G3D@@', 'VVector3@G3D@@')),
        (0x56d9b0, GEN % ('VCoordinateFrame@G3D@@', 'VCoordinateFrame@G3D@@')),
        (0x56dae0, GEN % ('VVector2int16@G3D@@', 'VVector2int16@G3D@@')),
        (0x56dc00, GEN % ('VColor3@G3D@@', 'VColor3@G3D@@')),
        (0x56dd20, GEN % ('VBrickColor@RBX@@', 'VBrickColor@2@')),
        (0x56de80, GEN % ('VContentId@RBX@@', 'VContentId@2@')),
        # boost::any instances for Roblox value types that only the genericConvert rows above call (functions.jsonl
        # callers): any_cast<T>(any*) and any::operator=(const T&)
        (0x56c6d0, '??$any_cast@VVector3@G3D@@@boost@@YAPAVVector3@G3D@@PAVany@0@@Z'),
        (0x56c710, '??$any_cast@VCoordinateFrame@G3D@@@boost@@YAPAVCoordinateFrame@G3D@@PAVany@0@@Z'),
        (0x56c750, '??$any_cast@VVector2int16@G3D@@@boost@@YAPAVVector2int16@G3D@@PAVany@0@@Z'),
        (0x56c790, '??$any_cast@VColor3@G3D@@@boost@@YAPAVColor3@G3D@@PAVany@0@@Z'),
        (0x56c7d0, '??$any_cast@VBrickColor@RBX@@@boost@@YAPAVBrickColor@RBX@@PAVany@0@@Z'),
        (0x56d220, '??$?4VCoordinateFrame@G3D@@@any@boost@@QAEAAV01@ABVCoordinateFrame@G3D@@@Z'),
        (0x56de40, '??$?4VContentId@RBX@@@any@boost@@QAEAAV01@ABVContentId@RBX@@@Z'),
    ],
    'vconv': [
        (0x56ea60, CONV % ('H', 'H')),
        (0x56ebb0, CONV % ('_N', '_N')),
        (0x56ee50, CONV % ('N', 'N')),
        (0x56efa0, CONV % ('VVector3@G3D@@', 'VVector3@G3D@@')),
        (0x56efb0, CONV % ('VCoordinateFrame@G3D@@', 'VCoordinateFrame@G3D@@')),
        (0x56efc0, CONV % ('VVector2int16@G3D@@', 'VVector2int16@G3D@@')),
        (0x56efd0, CONV % ('VColor3@G3D@@', 'VColor3@G3D@@')),
        (0x56efe0, CONV % ('VBrickColor@RBX@@', 'VBrickColor@2@')),
        (0x56eff0, CONV % ('VContentId@RBX@@', 'VContentId@2@')),
    ],
    'sel': [
        (0x5670f0, '?removeFilteredSelection@Selection@RBX@@QAEXPAVISelectionBase@2@@Z'),
    ],
}
FPS = '?$FactoryProduct@VSelection@RBX@@VInstance@2@$1?sSelection@2@3QBDB@RBX@@'
DCS = '?$DescribedCreatable@VSelection@RBX@@VInstance@2@$1?sSelection@2@3QBDB@RBX@@'
DSS = '?$Described@VSelection@RBX@@$1?sSelection@2@3QBDBV' + FPS[:-6] + '@2@@Reflection@RBX@@'
BFG = '?$BoundFuncDesc@VSelection@RBX@@$$A6A?AV?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@'
BFS = '?$BoundFuncDesc@VSelection@RBX@@$$A6AXV?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@'
# Exact only in the NATIVE_APPUNIT564_PENDING build (generated Selection.h copy): verified the same way, recorded
# exact=false and never counted.
PENDING_ROWS = {
    'sel_pending': [
        (0x566750, '??1' + FPS + 'MAE@XZ'),
        (0x5667b0, '??0' + FPS + 'IAE@XZ'),
        (0x566810, '??_E' + FPS + 'OIE@AEPAXI@Z'), (0x566820, '??_E' + FPS + 'OKE@AEPAXI@Z'),
        (0x566830, '??_E' + FPS + 'OME@AEPAXI@Z'), (0x566840, '??_E' + FPS + 'OCE@AEPAXI@Z'),
        (0x566850, '??_E' + FPS + 'OEE@AEPAXI@Z'),
        (0x566860, '??0SelectionChanged@RBX@@AAE@V?$shared_ptr@VInstance@RBX@@@boost@@0@Z'),
        (0x566950, '??1' + DSS + 'UAE@XZ'),
        (0x566a80, '?getSelection2@Selection@RBX@@QAE'),
        (0x566ab0, '?raise@?$Notifier@VSelection@RBX@@VSelectionChanged@2@@RBX@@IBEXVSelectionChanged@2@@Z'),
        (0x566b80, '?getClassName@' + FPS + 'UBEABVName@2@XZ'),
        (0x566ba0, '?raiseAdded@Selection@RBX@@AAEXV?$shared_ptr@VInstance@RBX@@@boost@@@Z'),
        (0x566d50, '?raiseRemoved@Selection@RBX@@AAEXV?$shared_ptr@VInstance@RBX@@@boost@@@Z'),
        (0x566f00, '??1Selection@RBX@@UAE@XZ'),
        (0x567050, '??_ESelection@RBX@@WBA@AEPAXI@Z'), (0x567060, '??_ESelection@RBX@@WBE@AEPAXI@Z'),
        (0x567070, '??_ESelection@RBX@@WBDA@AEPAXI@Z'), (0x567080, '??_ESelection@RBX@@WBFA@AEPAXI@Z'),
        (0x567090, '??_ESelection@RBX@@WCE@AEPAXI@Z'), (0x5670a0, '??_ESelection@RBX@@WEE@AEPAXI@Z'),
        (0x5670b0, '??_ESelection@RBX@@WGE@AEPAXI@Z'), (0x5670c0, '??_ESelection@RBX@@WIE@AEPAXI@Z'),
        (0x5670d0, '??_ESelection@RBX@@WKE@AEPAXI@Z'), (0x5670e0, '??_ESelection@RBX@@WME@AEPAXI@Z'),
        (0x567160, '??_GSelection@RBX@@UAEPAXI@Z'),
        (0x567180, '?addFilteredSelection@Selection@RBX@@QAEXPAVISelectionBase@2@@Z'),
        (0x5671a0, '?classDescriptor@' + DSS + 'SAAAVClassDescriptor@23@XZ'),
        (0x567210, '?toggleSelection@Selection@RBX@@QAEXPAVInstance@2@@Z'),
        (0x567420, '?addToSelection@Selection@RBX@@QAEXPAVInstance@2@@Z'),
        (0x5675d0, '?clearSelection@Selection@RBX@@QAEXXZ'),
        (0x567770, '?setSelection@Selection@RBX@@QAEXPAVInstance@2@@Z'),
        (0x567c10, '?removeFromSelection@Selection@RBX@@QAEXPBVInstance@2@@Z'),
        (0x567e20, '??0' + DCS + 'IAE@XZ'),
        (0x567ec0, '??_E' + FPS + 'OBA@AEPAXI@Z'), (0x567ed0, '??_E' + FPS + 'OBE@AEPAXI@Z'),
        (0x567ee0, '??_E' + FPS + 'OGE@AEPAXI@Z'),
        (0x567ef0, '??_G' + FPS + 'MAEPAXI@Z'),
        (0x567f10, '??0' + BFG),
        (0x567f80, '?execute@' + BFG),
        (0x567fe0, '??0' + BFS),
        (0x568080, '?execute@' + BFS),
        (0x568180, '??0Selection@RBX@@QAE@XZ'),
        (0x568330, '?setSelection@Selection@RBX@@QAEXV?$shared_ptr@$$CBV'),
    ],
}
# ---- externals: the address the original instruction uses (call site in parentheses) --------------------------------
EXTERNAL = {
    # call targets read at the original call sites (the bound address is the one the original instruction uses);
    # a const/non-const any_cast pair or Matrix3 copy/assign pair resolves to one identical-code-folded body
    '??$any_cast@H@boost@@YAHAAVany@0@@Z': 0x415ed0,   # no evidence name; call site in ??$convert@N@Value@Reflection@RBX@@QAEAANXZ
    '??$any_cast@_N@boost@@YA_NAAVany@0@@Z': 0x415f60,   # evidence: ??$any_cast@_N@boost@@YA_NABVany@0@@Z; call site in ??$convert@H@Value@Reflection@RBX@@QAEAAHXZ
    '??$any_cast@M@boost@@YAMAAVany@0@@Z': 0x415ff0,   # evidence: ??$any_cast@M@boost@@YAMABVany@0@@Z; call site in ??$convert@H@Value@Reflection@RBX@@QAEAAHXZ
    '??$any_cast@N@boost@@YANAAVany@0@@Z': 0x416080,   # evidence: ??$any_cast@N@boost@@YANABVany@0@@Z; call site in ??$convert@H@Value@Reflection@RBX@@QAEAAHXZ
    '??$any_cast@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@boost@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAVany@0@@Z': 0x416110,   # evidence: ??$any_cast@V?$basic_string@DU?$char_traits@D@std@@V?$alloca; call site in ??$convert@VContentId@RBX@@@Value@Reflection@RBX@@
    '?format@G3D@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBDZZ': 0x509b10,   # no evidence name; call site in ??$genericConvert@H@Value@Reflection@RBX@@QAEAAHXZ
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,   # evidence: ??4Matrix3@G3D@@QAEAAV01@ABV01@@Z; call site in ??0?$holder@VCoordinateFrame@G3D@@@any@boost@@QAE@
    '?identity@Matrix3@G3D@@SAABV12@XZ': 0x513e20,   # no evidence name; call site in ??0CoordinateFrame@G3D@@QAE@XZ
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,   # evidence name; call site in ??0Type@Reflection@RBX@@IAE@PBDABVtype_info@@0@Z
    '?getNullName@Name@RBX@@SAABV12@XZ': 0x554270,   # evidence name; call site in ??0ContentId@RBX@@QAE@ABV?$basic_string@DU?$char_t
    '?lookup@Name@RBX@@SAABV12@PBD@Z': 0x554290,   # evidence name; call site in ??0Type@Reflection@RBX@@IAE@PBDABVtype_info@@@Z
    '?convertToValue@?$StringConverter@VContentId@RBX@@@RBX@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAVContentId@2@@Z': 0x597480,   # evidence: ?convertToValue@?$StringConverter@VContentId@RBX@@@RBX@@SA_N; call site in ??$genericConvert@VContentId@RBX@@@Value@Reflectio
    '??$singleton@VCoordinateFrame@G3D@@@Type@Reflection@RBX@@SAABV012@XZ': 0x599a00,   # evidence: ??$singleton@VCoordinateFrame@G3D@@@Type@Reflection@RBX@@SAA; call site in ??$genericConvert@VCoordinateFrame@G3D@@@Value@Ref
    '?convertToValue@?$StringConverter@_N@RBX@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AA_N@Z': 0x5bde60,   # evidence: ?convertToValue@?$StringConverter@_N@RBX@@SA_NABV?$basic_str; call site in ??$genericConvert@_N@Value@Reflection@RBX@@QAEAA_N
    '?convertToValue@?$StringConverter@H@RBX@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAH@Z': 0x5be5a0,   # evidence: ?convertToValue@?$StringConverter@H@RBX@@SA_NABV?$basic_stri; call site in ??$genericConvert@H@Value@Reflection@RBX@@QAEAAHXZ
    '?convertToValue@?$StringConverter@N@RBX@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAN@Z': 0x5be680,   # no evidence name; call site in ??$genericConvert@N@Value@Reflection@RBX@@QAEAANXZ
    '?convertToValue@?$StringConverter@VVector2int16@G3D@@@RBX@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAVVector2int16@G3D@@@Z': 0x5be950,   # no evidence name; call site in ??$genericConvert@VVector2int16@G3D@@@Value@Reflec
    '?convertToValue@?$StringConverter@VVector3@G3D@@@RBX@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAVVector3@G3D@@@Z': 0x5bebb0,   # evidence: ?convertToValue@?$StringConverter@VVector3@G3D@@@RBX@@SA_NAB; call site in ??$genericConvert@VVector3@G3D@@@Value@Reflection@
    '?convertToValue@?$StringConverter@VColor3@G3D@@@RBX@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAVColor3@G3D@@@Z': 0x5bed50,   # evidence: ?convertToValue@?$StringConverter@VColor3@G3D@@@RBX@@SA_NABV; call site in ??$genericConvert@VColor3@G3D@@@Value@Reflection@R
    '?convertToValue@?$StringConverter@VBrickColor@RBX@@@RBX@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAVBrickColor@2@@Z': 0x5bf0a0,   # no evidence name; call site in ??$genericConvert@VBrickColor@RBX@@@Value@Reflecti
    '?convertToValue@?$StringConverter@VCoordinateFrame@G3D@@@RBX@@SA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAVCoordinateFrame@G3D@@@Z': 0x60a2f0,   # no evidence name; call site in ??$genericConvert@VCoordinateFrame@G3D@@@Value@Ref
    '_atexit': 0x6a17af,   # no evidence name; call site in ??$singleton@H@Type@Reflection@RBX@@SAABV012@XZ
    '__TI2?AVruntime_error@std@@': 0x8d1bc8,   # no evidence name; call site in ??$convert@V?$shared_ptr@$$CBV?$vector@V?$shared_p
    # pending Selection rows and the helper bodies they reach
    '?_Insert_n@?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@IAEXV?$_Vector_const_iterator@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@2@IABV?$shared_ptr@VInstance@RBX@@@boost@@@Z': 0x412240,   # evidence: ?_Insert_n@?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$; call site in ?insert@?$vector@V?$shared_ptr@VInstance@RBX@@@boo
    '?removeIndex@RaiseRange@RBX@@QAEXI@Z': 0x420740,   # evidence name; call site in ?removeListener@?$Notifier@VInstance@RBX@@UAncesto
    '??$?0V?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@shared_count@detail@boost@@QAE@PAV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@Z': 0x49a6c0,   # evidence: ??$?0V?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$alloc; call site in ??0?$CopyOnWrite@V?$vector@V?$shared_ptr@VInstance
    '?write@?$CopyOnWrite@V?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@RBX@@QAEAAV?$shared_ptr@V?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@XZ': 0x49add0,   # evidence: ?write@?$CopyOnWrite@V?$vector@V?$shared_ptr@VInstance@RBX@@; call site in ?addToSelection@Selection@RBX@@QAEXPAVInstance@2@@
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,   # no evidence name; call site in ?getClassName@?$FactoryProduct@VSelection@RBX@@VIn
    '??1Instance@RBX@@UAE@XZ': 0x55a540,   # evidence: ??1Instance@RBX@@MAE@XZ; call site in ??1?$FactoryProduct@VSelection@RBX@@VInstance@2@$1
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,   # evidence: ?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits; call site in ??0Selection@RBX@@QAE@XZ
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,   # evidence: ??0Instance@RBX@@IAE@XZ; call site in ??0?$FactoryProduct@VSelection@RBX@@VInstance@2@$1
    '?raise@?$Notifier@VSelection@RBX@@VSelectionChanged@2@@RBX@@IBEXVSelectionChanged@2@PAV?$Listener@VSelection@RBX@@VSelectionChanged@2@@2@@Z': 0x566960,   # no evidence name; call site in ?raise@?$Notifier@VSelection@RBX@@VSelectionChange
    '??0ClassDescriptor@Reflection@RBX@@AAE@XZ': 0x570820,   # evidence name; call site in ?rootDescriptor@ClassDescriptor@Reflection@RBX@@SA
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,   # no evidence name; call site in ?classDescriptor@?$Described@VInstance@RBX@@$1?sIn
    '??$singleton@X@Type@Reflection@RBX@@SAABV012@XZ': 0x594a50,   # evidence name; call site in ??0?$BoundFuncDesc@VSelection@RBX@@$$A6AXV?$shared
    '??0Value@Reflection@RBX@@QAE@XZ': 0x594ac0,   # evidence name; call site in ??0?$BoundFuncDesc@VSelection@RBX@@$$A6AXV?$shared
    '?addArgument@SignatureDescriptor@Reflection@RBX@@QAEXABVName@3@ABVType@23@ABVValue@23@@Z': 0x594b40,   # evidence: ?addArgument@SignatureDescriptor@Reflection@RBX@@QAEXABVName; call site in ??0?$BoundFuncDesc@VSelection@RBX@@$$A6AXV?$shared
    '??0FunctionDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBDW4Security@012@@Z': 0x595790,   # evidence: ??0FunctionDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor; call site in ??0?$BoundFuncDesc@VSelection@RBX@@$$A6A?AV?$share
    '??0?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@QAE@ABV01@@Z': 0x5acb00,   # evidence: ??0?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocato; call site in ??0?$CopyOnWrite@V?$vector@V?$shared_ptr@VInstance
    '__TI2?AVbad_alloc@std@@': 0x8d07d8,   # no evidence name; call site in ??$_Allocate@PAV?$Listener@VInstance@RBX@@UAncesto
    '__TI3?AVlength_error@std@@': 0x8d0cc0,   # no evidence name; call site in ?_Xlen@?$vector@PAV?$Listener@VInstance@RBX@@UAnce
    '__TI2?AVbad_weak_ptr@boost@@': 0x8d2354,   # no evidence name; call site in ??$throw_exception@Vbad_weak_ptr@boost@@@boost@@YA
    '__TI2?AVbad_cast@std@@': 0x8d362c,   # no evidence name; call site in ?execute@?$BoundFuncDesc@VSelection@RBX@@$$A6A?AV?
}
EXTERNAL = {k: v for k, v in EXTERNAL.items() if v is not None}
LOCAL_STATIC_AT = {}
LOCAL_STATIC = [
    # Type::singleton<T> statics / guards (each body: test byte [guard]; mov ecx, static) and the G3D Vector3::zero
    # static read by the CoordinateFrame() helper body 004782d0
    (r'^\?v@\?1\?\?zero@Vector3@G3D@@SAABV23@XZ@4V23@A$', 0x96f044),   # ??0CoordinateFrame@G3D@@QAE@XZ
    (r'^\?\?_B\?1\?\?zero@Vector3@G3D@@SAABV12@XZ@51$', 0x96f050),   # ??0CoordinateFrame@G3D@@QAE@XZ
    (r'^\?type@\?1\?\?\?\$singleton@V\?\$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@@Type@Reflection@RBX@@SAABV123@XZ@4V123@A$', 0x974b58),   # ??$singleton@V?$shared_ptr@VDescribedBase@Reflecti
    (r'^\?\$S2@\?1\?\?\?\$singleton@V\?\$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@@Type@Reflection@RBX@@SAABV123@XZ@4IA$', 0x974b68),   # ??$singleton@V?$shared_ptr@VDescribedBase@Reflecti
    (r'^\?type@\?1\?\?\?\$singleton@V\?\$shared_ptr@VInstance@RBX@@@boost@@@Type@Reflection@RBX@@SAABV123@XZ@4V123@A$', 0x974b6c),   # ??$singleton@V?$shared_ptr@VInstance@RBX@@@boost@@
    (r'^\?\$S3@\?1\?\?\?\$singleton@V\?\$shared_ptr@VInstance@RBX@@@boost@@@Type@Reflection@RBX@@SAABV123@XZ@4IA$', 0x974b7c),   # ??$singleton@V?$shared_ptr@VInstance@RBX@@@boost@@
    (r'^\?type@\?1\?\?\?\$singleton@V\?\$shared_ptr@\$\$CBV\?\$vector@V\?\$shared_ptr@VInstance@RBX@@@boost@@V\?\$allocator@V\?\$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@@Type@Reflection@RBX@@SAABV123@XZ@4V123@A$', 0x974b80),   # ??$singleton@V?$shared_ptr@$$CBV?$vector@V?$shared
    (r'^\?\$S4@\?1\?\?\?\$singleton@V\?\$shared_ptr@\$\$CBV\?\$vector@V\?\$shared_ptr@VInstance@RBX@@@boost@@V\?\$allocator@V\?\$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@@Type@Reflection@RBX@@SAABV123@XZ@4IA$', 0x974b90),   # ??$singleton@V?$shared_ptr@$$CBV?$vector@V?$shared
    (r'^\?type@\?1\?\?\?\$singleton@H@Type@Reflection@RBX@@SAABV123@XZ@4V123@A$', 0x974b94),   # ??$singleton@H@Type@Reflection@RBX@@SAABV012@XZ
    (r'^\?\$S5@\?1\?\?\?\$singleton@H@Type@Reflection@RBX@@SAABV123@XZ@4IA$', 0x974ba4),   # ??$singleton@H@Type@Reflection@RBX@@SAABV012@XZ
    (r'^\?type@\?1\?\?\?\$singleton@_N@Type@Reflection@RBX@@SAABV123@XZ@4V123@A$', 0x974ba8),   # ??$singleton@_N@Type@Reflection@RBX@@SAABV012@XZ
    (r'^\?\$S6@\?1\?\?\?\$singleton@_N@Type@Reflection@RBX@@SAABV123@XZ@4IA$', 0x974bb8),   # ??$singleton@_N@Type@Reflection@RBX@@SAABV012@XZ
    (r'^\?type@\?1\?\?\?\$singleton@M@Type@Reflection@RBX@@SAABV123@XZ@4V123@A$', 0x974bbc),   # ??$singleton@M@Type@Reflection@RBX@@SAABV012@XZ
    (r'^\?\$S7@\?1\?\?\?\$singleton@M@Type@Reflection@RBX@@SAABV123@XZ@4IA$', 0x974bcc),   # ??$singleton@M@Type@Reflection@RBX@@SAABV012@XZ
    (r'^\?type@\?1\?\?\?\$singleton@N@Type@Reflection@RBX@@SAABV123@XZ@4V123@A$', 0x974bd0),   # ??$singleton@N@Type@Reflection@RBX@@SAABV012@XZ
    (r'^\?\$S8@\?1\?\?\?\$singleton@N@Type@Reflection@RBX@@SAABV123@XZ@4IA$', 0x974be0),   # ??$singleton@N@Type@Reflection@RBX@@SAABV012@XZ
    (r'^\?type@\?1\?\?\?\$singleton@VContentId@RBX@@@Type@Reflection@RBX@@SAABV123@XZ@4V123@A$', 0x974be4),   # ??$singleton@VContentId@RBX@@@Type@Reflection@RBX@
    (r'^\?\$S9@\?1\?\?\?\$singleton@VContentId@RBX@@@Type@Reflection@RBX@@SAABV123@XZ@4IA$', 0x974bf4),   # ??$singleton@VContentId@RBX@@@Type@Reflection@RBX@
    (r'^\?type@\?1\?\?\?\$singleton@V\?\$basic_string@DU\?\$char_traits@D@std@@V\?\$allocator@D@2@@std@@@Type@Reflection@RBX@@SAABV123@XZ@4V123@A$', 0x974bf8),   # ??$singleton@V?$basic_string@DU?$char_traits@D@std
    (r'^\?\$S10@\?1\?\?\?\$singleton@V\?\$basic_string@DU\?\$char_traits@D@std@@V\?\$allocator@D@2@@std@@@Type@Reflection@RBX@@SAABV123@XZ@4IA$', 0x974c08),   # ??$singleton@V?$basic_string@DU?$char_traits@D@std
    (r'^\?type@\?1\?\?\?\$singleton@VVector3@G3D@@@Type@Reflection@RBX@@SAABV123@XZ@4V123@A$', 0x974c0c),   # ??$singleton@VVector3@G3D@@@Type@Reflection@RBX@@S
    (r'^\?\$S11@\?1\?\?\?\$singleton@VVector3@G3D@@@Type@Reflection@RBX@@SAABV123@XZ@4IA$', 0x974c1c),   # ??$singleton@VVector3@G3D@@@Type@Reflection@RBX@@S
    (r'^\?type@\?1\?\?\?\$singleton@VVector2int16@G3D@@@Type@Reflection@RBX@@SAABV123@XZ@4V123@A$', 0x974c20),   # ??$singleton@VVector2int16@G3D@@@Type@Reflection@R
    (r'^\?\$S12@\?1\?\?\?\$singleton@VVector2int16@G3D@@@Type@Reflection@RBX@@SAABV123@XZ@4IA$', 0x974c30),   # ??$singleton@VVector2int16@G3D@@@Type@Reflection@R
    (r'^\?type@\?1\?\?\?\$singleton@VColor3@G3D@@@Type@Reflection@RBX@@SAABV123@XZ@4V123@A$', 0x974c34),   # ??$singleton@VColor3@G3D@@@Type@Reflection@RBX@@SA
    (r'^\?\$S13@\?1\?\?\?\$singleton@VColor3@G3D@@@Type@Reflection@RBX@@SAABV123@XZ@4IA$', 0x974c44),   # ??$singleton@VColor3@G3D@@@Type@Reflection@RBX@@SA
    (r'^\?type@\?1\?\?\?\$singleton@V\?\$vector@VValue@Reflection@RBX@@V\?\$allocator@VValue@Reflection@RBX@@@std@@@std@@@Type@Reflection@RBX@@SAABV123@XZ@4V123@A$', 0x974c48),   # ??$singleton@V?$vector@VValue@Reflection@RBX@@V?$a
    (r'^\?\$S14@\?1\?\?\?\$singleton@V\?\$vector@VValue@Reflection@RBX@@V\?\$allocator@VValue@Reflection@RBX@@@std@@@std@@@Type@Reflection@RBX@@SAABV123@XZ@4IA$', 0x974c58),   # ??$singleton@V?$vector@VValue@Reflection@RBX@@V?$a
    (r'^\?type@\?1\?\?\?\$singleton@VBrickColor@RBX@@@Type@Reflection@RBX@@SAABV123@XZ@4V123@A$', 0x974c70),   # ??$singleton@VBrickColor@RBX@@@Type@Reflection@RBX
    (r'^\?\$S15@\?1\?\?\?\$singleton@VBrickColor@RBX@@@Type@Reflection@RBX@@SAABV123@XZ@4IA$', 0x974c80),   # ??$singleton@VBrickColor@RBX@@@Type@Reflection@RBX
    # pending Selection rows: Name::declare<sSelection> / classDescriptor statics, reached helper statics
    (r'^\?n@\?1\?\?\?\$doDeclare@\$1\?sSelection@RBX@@3QBDB@Name@RBX@@CAABV12@XZ@4ABV12@B$', 0x96c2fc),   # ??$doDeclare@$1?sSelection@RBX@@3QBDB@Name@RBX@@CA
    (r'^\?\?_B\?1\?\?\?\$doDeclare@\$1\?sSelection@RBX@@3QBDB@Name@RBX@@CAABV01@XZ@51$', 0x96c300),   # ??$doDeclare@$1?sSelection@RBX@@3QBDB@Name@RBX@@CA
    (r'^\?flag@\?1\?\?\?\$declare@\$1\?sSelection@RBX@@3QBDB@Name@RBX@@SAABV12@XZ@4JA$', 0x96c314),   # ?getClassName@?$FactoryProduct@VSelection@RBX@@VIn
    (r'^\?root@\?1\?\?rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV234@XZ@4V234@A$', 0x96c3a0),   # ??__Froot@?1??rootDescriptor@ClassDescriptor@Refle
    (r'^\?\?_B\?1\?\?rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ@51$', 0x96c460),   # ?rootDescriptor@ClassDescriptor@Reflection@RBX@@SA
    (r'^\?foo@\?1\?\?classDescriptor@\?\$Described@VInstance@RBX@@\$1\?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@34@XZ@4V534@A$', 0x96c468),   # ??__Ffoo@?1??classDescriptor@?$Described@VInstance
    (r'^\?\?_B\?1\?\?classDescriptor@\?\$Described@VInstance@RBX@@\$1\?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@51$', 0x96c528),   # ?classDescriptor@?$Described@VInstance@RBX@@$1?sIn
    (r'^\?foo@\?1\?\?classDescriptor@\?\$Described@VSelection@RBX@@\$1\?sSelection@2@3QBDBV\?\$FactoryProduct@VSelection@RBX@@VInstance@2@\$1\?sSelection@2@3QBDB@2@@Reflection@RBX@@SAAAVClassDescriptor@34@XZ@4V534@A$', 0x974920),   # ??__Ffoo@?1??classDescriptor@?$Described@VSelectio
    (r'^\?\?_B\?1\?\?classDescriptor@\?\$Described@VSelection@RBX@@\$1\?sSelection@2@3QBDBV\?\$FactoryProduct@VSelection@RBX@@VInstance@2@\$1\?sSelection@2@3QBDB@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@51$', 0x9749e0),   # ?classDescriptor@?$Described@VSelection@RBX@@$1?sS
]
USED_EXTERNAL = set()
UNBOUND = []
FOLDED = {}
binding = {}

FUNCTIONS = {int(json.loads(l)['addr'], 16) for l in
             (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()}
BODIES = {}
for key in list(SOURCES) + ['sel_pending']:
    for n, b, r in match.coff_functions(Path(OBJ[key]).read_bytes()):
        BODIES.setdefault(key, {})[n] = (b, r)


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def try_fold(which, symbol, value):
    """A compiler helper / COMDAT body bound outside the counted rows: the body compiled here must be exact there."""
    if symbol not in BODIES[which] or value not in FUNCTIONS:
        return False
    body, refs = BODIES[which][symbol]
    target, target_refs = target_of(value)
    if not match.exact_match(target, target_refs, body, refs):
        return False
    FOLDED.setdefault(symbol, (value, which))
    return FOLDED[symbol][0] == value


def local_static(symbol, value):
    for pattern, address in LOCAL_STATIC:
        if re.match(pattern, symbol):
            prev = LOCAL_STATIC_AT.setdefault(symbol, address)
            return prev == value == address
    return False


def resolve(rows, which):
    funcs = BODIES[which]
    out = []
    for address, name in rows:
        hits = [name] if name in funcs else [n for n in funcs if n.startswith(name) and not nb.LOCAL_EH.match(n)]
        assert len(hits) == 1 or DISCOVER, ('%08x' % address, name, hits[:4])
        if len(hits) == 1:
            out.append((address, hits[0]))
    return out


def verify(which, rows, own, strict=True, record=True):
    raw = Path(OBJ[which]).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = BODIES[which]
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict or DISCOVER, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
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
            if nb.LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol.startswith('__real@'):
                assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
                how = 'constant %s' % symbol[7:]
            elif symbol.startswith('??_C@'):
                pos, at = definitions[symbol]
                literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
                how = 'string %r' % literal[:-1].decode('latin-1')
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert rtti.replace('3QBDB', '3PBDB') == ('.?AV' + cls).replace('3QBDB', '3PBDB'), (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol.startswith('??_R0'):
                # type descriptor (typeid / __RTDynamicCast operand): its name string at +8 is the mangled type name
                assert original.string(value + 8) == '.' + symbol[5:-2] and symbol.endswith('@8'), (name, symbol, hex(value))
                how = 'RTTI type descriptor %s' % original.string(value + 8)
            elif symbol.startswith('__TI') and symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value))
                cta = d(value + 12)
                how = 'throw info, first catchable type %s' % original.string(d(d(cta + 4) + 4) + 8)
                USED_EXTERNAL.add(symbol)
            elif symbol.startswith('??_E') and ('??_G' + symbol[4:]) in own:
                # vector deleting dtor reference: no array new of the class, so the weak ??_E resolves to ??_G
                assert own['??_G' + symbol[4:]] == value, (name, symbol, hex(value))
                how = 'own row (??_G)'
            elif re.match(r'^\?s(\w+)@RBX@@3QBDB$', symbol):
                # class-name array: the original bytes are the class name
                assert original.string(value) == symbol[2:symbol.index('@')], (name, symbol, hex(value))
                how = 'class name %r' % original.string(value)
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
                USED_EXTERNAL.add(symbol)
            elif local_static(symbol, value):
                how = 'local static'
            elif try_fold(which, symbol, value):
                how = 'helper / COMDAT body, compared exact at the bound address'
            else:
                UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
                continue
            if record:
                prev = binding.setdefault(symbol, (value, name))
                assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


resolved = {k: resolve(rows, k) for k, rows in ROWS.items()}
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
groups = {k: verify(k, rows, own) for k, rows in resolved.items()}
resolved_pending = {k: resolve(rows, k) for k, rows in PENDING_ROWS.items()}
pending_own = dict(own)
for rows in resolved_pending.values():
    for address, name in rows:
        pending_own.setdefault(name, address)
PENDING_REASON = {
    'sel_pending': ('pending-build-only (NATIVE_APPUNIT564_PENDING with the generated v8datamodel/Selection.h copy: '
                    'const char sSelection[] and the 2008 Selection members; proposal); not counted'),
}
pending_out = []
for k, rows in resolved_pending.items():
    for row in verify(k, rows, pending_own, strict=False, record=False):
        row['pending_exact'], row['exact'] = row['exact'], False
        row['reason'] = PENDING_REASON[k]
        pending_out.append(row)

# the helper bodies' own call/data targets are verified like a row's (record=False: never counted); folds found while
# verifying a helper are verified in turn
folded_targets, done = {}, set()
while set(FOLDED) - done:
    for s in sorted(set(FOLDED) - done):
        v, w = FOLDED[s]
        done.add(s)
        folded_targets[s] = verify(w, [(v, s)], own, record=False)[0].get('verified_targets', {})
folded_out = [{'address': '%08x' % v, 'symbol': s, 'unit': w, 'verified_targets': folded_targets[s],
               'reason': 'compiler helper / COMDAT body bound at this address and compared exact (targets verified); '
                         'not counted'}
              for s, (v, w) in sorted(FOLDED.items())]

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in list(groups.values()) + [pending_out]:
        for r in g:
            if not r['exact'] and not r.get('pending_exact'):
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    print('FOLDED', {k: hex(v[0]) for k, v in FOLDED.items()})
    print('UNUSED EXTERNAL', sorted(set(EXTERNAL) - USED_EXTERNAL))
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
assert len(set(p for p, _ in LOCAL_STATIC)) == len(LOCAL_STATIC)
assert sorted(set(LOCAL_STATIC_AT.values())) == sorted(a for _, a in LOCAL_STATIC), LOCAL_STATIC_AT
assert sorted(USED_EXTERNAL) == sorted(EXTERNAL), sorted(set(EXTERNAL) - USED_EXTERNAL)
for symbol, address in EXTERNAL.items():
    assert address in FUNCTIONS or original.imported(address) is not None or symbol.startswith('__TI'), (symbol, hex(address))


# ---- counting rules ------------------------------------------------------------------------------------------------
def counted_elsewhere():
    """Rows other receipts count: their top-level exact_function_rows (or exact_addresses / exact_unique_addresses),
    else the rows marked exact in their counted method lists (keys `methods` or `*_methods`, never `pending_*`)."""
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
        if 'exact_function_rows' in data:
            rows = data['exact_function_rows']
        elif isinstance(data.get('exact_addresses'), list):
            rows = data['exact_addresses']
        elif isinstance(data.get('exact_unique_addresses'), list):
            rows = data['exact_unique_addresses']
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        rows.append(o['address'])
                    else:
                        for v in o.values():
                            walk(v)
            for key, value in data.items():
                if (key == 'methods' or key.endswith('_methods')) and not key.startswith('pending'):
                    walk(value)
        if isinstance(rows, dict):
            rows = list(rows)
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
pending_rows = sorted({r['address'] for r in pending_out})
assert not set(pending_rows) & set(exact_rows)
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if RANGE[0] <= a < RANGE[1]}
range_functions = sorted('%08x' % a for a in FUNCTIONS if int(RANGE[0], 16) <= a < int(RANGE[1], 16))
in_range_exact = [a for a in exact_rows if RANGE[0] <= a < RANGE[1]]

# Unit map of the range. Boundary evidence: vtables and RTTI (COL class names), constructors / destructors, class-name
# strings, local statics, callers / callees (functions.jsonl) and the evidence names. Addresses of rows that other
# receipts count are written in the range_rows_counted_by_other_receipts list only, as text.
UNIT_MAP = {
    'v8datamodel/DebugSettings.cpp (tail) 00564000..00565dff': (
        'The DebugSettings / GlobalSettingsItem<DebugSettings> unit that starts below the range: ??_E thunks of '
        'DebugSettings, FactoryProduct<DebugSettings, GlobalSettings::Item> getClassName, the SurfaceType map '
        'insert / operator[] instances, EnumDesc<World::EThrottle> registration (00564be0), the GlobalSettingsItem '
        'ctor and DebugSettings() (00565ac0), the PropDescriptor<DebugSettings, bool> accessors 00565bd0..00565dd0. '
        'Covered by settings-items-working.json (most rows counted there; 00565c80 / 00565cb0 / 00565ce0 / 00565d10 / '
        '00565d40 are its pending / proposal rows: World.h EThrottle, Camera / Workspace class names). Not rebuilt here. '
        'The ICF return-true bodies (mov al,1) shared by every unit are counted by other receipts.'),
    'v8datamodel/Team.cpp 00565e00..0056672f': (
        'RBX::Team (vtable 0082ea84, RTTI DescribedCreatable<Team, Instance, sTeam>, ctor 005665e0, factory '
        '00409140 new 0x13c): complete in team-working.json (team_methods, every row exact with targets verified). '
        'Not rebuilt here.'),
    'v8datamodel/Selection.cpp 00566750..0056841f': (
        'RBX::Selection (vtable 0082edc4 .?AVSelection@RBX@@, factory 00409620 new 0x174, ctor 00568180: '
        'DescribedCreatable<Selection> 00567e20 -> FactoryProduct<Selection> 005667b0 -> Instance() 0055b7e0, '
        'Notifier<Selection, SelectionChanged> at +0x130 (ctor 005e9ec0), Listener<Instance, AncestorChanged> vptr at '
        '+0x150, CopyOnWrite selection +0x154 (0049ad50), filteredSelections +0x15c, setName("Selection") 0082eedc; '
        'dtor 00566f00 / ??_G 00567160; class name "Selection" 0082ec58; func_getSelection / func_setSelection '
        'BoundFuncDesc ctors 00567f10 / 00567fe0, execute 00567f80 / 00568080, initializers 007f3330 / 007f3360). '
        'Built in native-classes/AppUnit564_2008Selection.cpp: removeFilteredSelection 005670f0 is counted; 45 '
        'more rows are exact only against the generated Selection.h copy (pending-build-only; proposal). Not built: '
        'onEvent 005682e0 (needs the non-const Instance::getRootAncestor 0042a5f0), Notifier<Selection>::raise('
        'event, listener) 00566960 (its function row is cut at 005669e9 by the function list: BOUNDS, see '
        'bounds_evidence), the initializers 007f3330 / 007f3360. 005683f0..00568450 are boost::lock_error / '
        'thread_resource_error header instances (library, not recovered).'),
    'v8datamodel/GlobalSettings.cpp 00568460..005691af': (
        'GlobalSettings (vtable 0082f4xx family, RTTI DescribedNonCreatable<GlobalSettings, ServiceProvider, '
        'sGlobalSettings>; ctor 00568f80 setName "Global Settings" 0082f4dc, Creatable::create<GlobalSettings> '
        '00569070 malloc 0x1c8, singleton 005690f0 with recursive_mutex lock 00563090 and atexit 007fd0d0), '
        'loadState 00568760 (ifstream, TextXmlParser, MergeBinder 00443e50), saveState 00568910 (ofstream, '
        'TextXmlWriter), eraseSettingsStore 005684d0 (DeleteFileA x2), the settings path helper 00568460 (Log '
        '005a7ac0), GlobalSettings::Item ctor 00568520 / doDeclare 00568580, shared_ptr<GlobalSettings> ctor '
        '00568690 (its shared_count 00568600 is counted by creatable-shared-count-working.json), and the inline '
        'ServiceProvider ctor / dtor emitted here: DescribedNonCreatable<ServiceProvider> 00568a50, ~ServiceProvider '
        '00568af0, ServiceProvider() 00568bf0 (stores the vtables 0082f1bc.., so the native Service.h '
        '__declspec(novtable) on ServiceProvider does not match the 2008 ctor; proposal), NonFactoryProduct<'
        'ServiceProvider, sGlobalSettings> 00568d70 / getClassName 00568eb0. Not built in this pass.'),
    'util/standardout.cpp 005691b0..00569869': (
        'RBX::StandardOut (ctor 00569530, singleton 00569620, print 005693a0, Notifier raise 00569780): covered by '
        'leaves2008-working.json (counted there; ~StandardOut 00569590 is its pending row). Not rebuilt here.'),
    'util/Http.cpp 00569870..0056a55f': (
        'ATL::AtlCrtErrorCheck 00569870, CSimpleStringT / CStringT instances 00569cb0..00569fe0 (ATL library '
        'templates, not recovered), RBX::Http post 00569a40 / get 00569ae0 / isScript 0056a040 and helpers '
        '00569920 / 00569bf0 / 0056a160 / 0056a2e0 (WinINet; donor util/Http.cpp). No native Http header; not built.'),
    'util/Debugable.cpp 0056a560': 'Debugable::dump 0056a560 (support row of seat / user-controller receipts).',
    'reflection/signal.cpp 0056a590..0056bd8f': (
        'Signal / SignalDescriptor / SignalInstance, boost::signals and std::list / map instances for the signal '
        'registry (0056a590..0056b6f0), MemberDescriptor(ClassDescriptor&, const char*, const char*) 0056b480, '
        'MemberDescriptorContainer<SignalDescriptor>::declare 0056b700, SignalDescriptor ctor 0056bab0, '
        'getSignalInstance 0056bb20 / 0056bd10, ~SignalSource 0056bd40, disconnect_all_slots 0056bd60. Not built '
        'in this pass (boost::signals 1.34 internals; support rows of other receipts).'),
    'reflection/type.cpp + reflection_property.cpp 0056bd90..0056c9ff': (
        'Type(const char*, const type_info&) 0056bd90 (built: header-inline COMDAT, counted), the Type / '
        'PropertyDescriptor support bodies 0056be00..0056c150, MemberDescriptorContainer<PropertyDescriptor>::'
        'declare 0056c170, allEnumsByName 0056c520, EnumDescriptor ctor 0056c590, PropertyDescriptor ctor 0056c650, '
        'boost::any any_cast<T>(any*) instances 0056c6d0..0056c7d0 (built, counted: only the genericConvert rows '
        'call them), any::holder<T> ctors 0056c810..0056c980 (helper bodies, also called elsewhere), '
        'XmlNameValuePair::setValue(ContentId) 0056c9e0.'),
    'reflection Type::singleton / Value conversions 0056ca70..0056f0af': (
        'Type::singleton<T> 0056ca70..0056d020 / 0056d120 (built and counted except singleton<Tuple> 0056d020: '
        'RBX::Reflection::Tuple is declared by no header), Value::convert<Objects> 0056d090, boost::any '
        'operator= / ctor instances 0056d190..0056d3a0 and 0056de40, map<BrickColor::Number, Color4uint8> '
        '_Buynode 0056d3d0, Value::genericConvert<T> 0056d410..0056de80 (built and counted; genericConvert<float> '
        '0056d650 is counted by sound-value-generic-float-integrated.json), TypedPropertyDescriptor<T>::'
        'getStringValue / setStringValue and PropDescriptor GetSet bodies 0056dfe0..0056e900 (not built), '
        'Value::convert<T> 0056ea60..0056eff0 (built and counted; convert<float> 0056ed00 is counted by '
        'sound-value-convert-float-integrated.json).'),
    'reflection Value conversions (tail) / reflection_object (head) 0056f0b0..0056ffff': (
        'Value::convert<std::string> 0056f0b0, convert<shared_ptr<Instance>> 0056f8c0 and the descriptor bodies '
        '0056f3b0..0056fdf0 (not built), ClassDescriptor::operator== 0056fe10, reflection_object sync() 0056fe30 / '
        'class registry 0056fe90..0056ff60 (support rows of app-unit570-2008-working.json), '
        'MemberDescriptorContainer<FunctionDescriptor>::declare 0056fff0.'),
}
BOUNDS = {
    '00566960 Notifier<Selection>::raise row extent': ('Notifier<Selection, SelectionChanged>::raise(SelectionChanged, Listener*) is one function '
                 '00566960..00566a0a: the row 00566960 (137 B) ends at the `call edx` 005669e7 and the continuation '
                 '005669e9 (34 B: ~SelectionChanged 00422c60, SEH epilogue, ret 0x14) is listed as a separate row; '
                 '00566a0b is its catch funclet (StandardOut::print "Exception caught in onEvent. %s"). raise(event) '
                 '00566ab0 calls 00566960 at 00566b4d.'),
}
REJECTED = {
    'Value::convert<Objects> 0056d090 in the /Ob1 unit': '103/144 B: /Ob1 keeps boost::any_cast<T>(any*) out of line',
    'Value::convert<Objects> 0056d090 with throw std::runtime_error(std::string("...")) (temporary)':
        '140/144 B: the original reloads the address of a named std::string local after its constructor',
    'Selection::clearSelection 005675d0 with the donor `while (!selection->empty())`':
        'pending build 415/415 B but not exact: the original tests size() > 0 (sar 3; test; jbe)',
}
PROPOSALS = {
    'v8datamodel/Selection.h (owner of the native Selection declaration)': (
        'Use `extern const char sSelection[];` (RTTI .?AV?$FactoryProduct@VSelection@RBX@@VInstance@2@$1?sSelection@2@'
        '3QBDB@RBX@@ at vtable 0082ece4 and .?AV?$DescribedCreatable@...3QBDB at 0082ee84; string 0082ec58; the '
        'committed NativeClassNames.cpp `char sSelection[]` would become const), give ISelectionBase `friend class '
        'Selection;` (raiseAdded 00566ba0 / raiseRemoved 00566d50 call slot 0 onSelectionChanged), and declare: '
        '`Selection();` (00568180), `virtual ~Selection();` (00566f00, ??_G 00567160), `boost::shared_ptr<const '
        'std::vector<boost::shared_ptr<Instance> > > getSelection2();` (00566a80), `void setSelection(boost::shared_'
        'ptr<const std::vector<boost::shared_ptr<Instance> > >);` (00568330), `void toggleSelection(Instance*);` '
        '(00567210), `void addFilteredSelection(ISelectionBase*);` (00567180), protected `virtual void onEvent(const '
        'Instance*, AncestorChanged);` (005682e0; without it the class is abstract), private `void raiseAdded('
        'boost::shared_ptr<Instance>);` / `void raiseRemoved(boost::shared_ptr<Instance>);`. Verified against '
        'out/native-layouts/app-unit564-2008/pending/v8datamodel/Selection.h: 45 rows exact (pending_build_only), '
        'which can then be counted here.'),
    'v8tree/Instance.h (core owner)': (
        'Declare `Instance* getRootAncestor();` (evidence name ?getRootAncestor@Instance@RBX@@QAEPAV12@XZ, '
        '0042a5f0, non-const), called twice by Selection::onEvent 005682e0 before removeFromSelection 00567c10.'),
    'v8tree/Service.h (owner of the native ServiceProvider declaration)': (
        'ServiceProvider is not novtable in 2008: ServiceProvider() 00568bf0 stores its vtables 0082f1bc / 0082f1b0 '
        '.. / 0082f200 / 0082f130 / 0082f120 after the three Notifier ctors, and ~ServiceProvider 00568af0 is emitted '
        'in the GlobalSettings unit. With `__declspec(novtable)` the implicit ctor cannot match.'),
    'reflection/type.h (reflection owner, information)': (
        'Type::singleton<Tuple> 0056d020 ("Tuple" 0082f6e8, type descriptor 00946340 .?AUTuple@Reflection@RBX@@) '
        'needs a declaration of struct RBX::Reflection::Tuple; its members are not derived here.'),
}

# rows not counted here never appear as a quoted bare address (see the receipt pitfall noted below)
for row in pending_out:
    row['address'] = '%s (pending-build-only, not counted)' % row['address']
for row in folded_out:
    row['address'] = '%s (helper body, not counted)' % row['address']
N_PENDING = len(pending_out)
PROPOSALS['v8datamodel/Selection.h (owner of the native Selection declaration)'] = PROPOSALS[
    'v8datamodel/Selection.h (owner of the native Selection declaration)'].replace('45 rows', '%d rows' % N_PENDING)
UNIT_MAP['v8datamodel/Selection.cpp 00566750..0056841f'] = UNIT_MAP[
    'v8datamodel/Selection.cpp 00566750..0056841f'].replace('45 more rows', '%d more rows' % N_PENDING)
assert '%d rows' % N_PENDING in str(PROPOSALS) and '%d more rows' % N_PENDING in str(UNIT_MAP)

sha = nb.sha
receipt = {
    'class': 'RBX reflection Type / Value conversion and Selection units of the application range 00564000..00570000 '
             '(2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), /fp:fast; the Value::convert unit /Ob1',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in
                [Path(__file__).resolve()] + [v[0] for v in SOURCES.values()] + HEADERS},
    'objects': {k: sha(v) for k, v in OBJ.items()},
    'unit_map': UNIT_MAP,
    'bounds_evidence': BOUNDS,
    'range_functions': len(range_functions),
    'range_exact_rows_here': len(in_range_exact),
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any '"ADDR"' in another receipt as counted there and drop it.
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'rows': groups,
    'pending_build_only': pending_out,
    'helper_bodies_not_counted': folded_out,
    'local_statics': {k: '%#x' % v for k, v in LOCAL_STATIC_AT.items()},
    'vtables': ('none compared: the only vtable-owning class here (Selection) cannot be built from the current '
                'headers (abstract without the onEvent override, class-name array mangled 3PADA against RTTI 3QBDB); '
                'its pending-build vtables are not used for slot checks'),
    'exact_function_rows': exact_rows,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit564-2008: %d counted exact rows (%d in range); %d pending-build-only, %d helper bodies compared; '
      '%d range rows, %d counted elsewhere'
      % (len(exact_rows), len(in_range_exact), len(pending_out), len(folded_out), len(range_functions),
         len(range_counted)))
print(' '.join(exact_rows))
