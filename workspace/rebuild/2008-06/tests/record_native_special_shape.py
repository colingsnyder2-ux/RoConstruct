"""Verify the inactive native RBX::SpecialShape ("SpecialMesh") recovery (2008-06).

Builds (document-swap flags + /fp:fast, VS2008 RTM 21022):
  * tests/NativeSpecialShapeLayout.cpp   sizeof probe (mov eax, imm32; ret) and compile-time offset asserts;
  * native-classes/SpecialShape.cpp      the whole original unit (0059ece0..005a008d, initializers
                                         007f4c20..007f4d20, atexit 007fdfe0..007fe090) plus the template
                                         instances whose original bodies live elsewhere (COMDAT / ICF);
  * SpecialShape.cpp again against out/native-layouts/special-shape-pending/: generated copies of
    native-headers/reflection/{reflection,type}.h and the donor reflection/property.h carrying the proposed
    2008 declarations (EnumPropDescriptor call_once singleton + EnumDesc member at +0x20; Value::get<T> body;
    GetSet::isWriteOnly at slot 1; TypedPropertyDescriptor Value-based getValue/setValue virtuals).
    Rows exact only in this build are recorded exact=false (pending-build-only) and are not counted.

Every row must be relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, string literals by bytes,
type descriptors and vtables by original RTTI names, own symbols by the row proven here, descriptor statics and
the class-name array by the DATA map, and the remaining externals by the EXTERNAL map (call sites read in the
original disassembly). A symbol must bind to one address in every row. Each SpecialShape / FactoryProduct /
DescribedCreatable vtable of the main build (never the pending one) is compared slot by slot with the original
vtable it binds to. Writes work/2008-06/shared-layouts/special-shape-working.json.
"""
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
SRC = R / 'native-classes/SpecialShape.cpp'
HDR = R / 'native-headers/v8datamodel/SpecialShape.h'
LAYOUT = R / 'tests/NativeSpecialShapeLayout.cpp'
UNIT_FLAGS = ['/fp:fast']   # setScale/setVertColor 0059ff10/0059ff70 compare with `fld; fcomp mem`

# ---- generated header copies for the pending build (proposals; the shared headers are not edited) ----------
pending = OUT / 'special-shape-pending'
(pending / 'reflection').mkdir(parents=True, exist_ok=True)
text = (R / 'native-headers/reflection/reflection.h').read_text()
old = '''			std::auto_ptr<typename TypedPropertyDescriptor<Enum>::GetSet> getset;
		  \n		public:
			template<typename GetFunction, typename SetFunction>
			EnumPropDescriptor(char const* name, char const* category, typename GetFunction get, typename SetFunction set, Functionality flags)
				: EnumPropertyDescriptor(Class::classDescriptor(), EnumDesc<Enum>::singleton(), name, category, flags),
				  getset(PropDescriptor<Class, Enum>::getset<GetFunction, SetFunction>(get, set))
			{
			}
'''
new = '''			std::auto_ptr<typename TypedPropertyDescriptor<Enum>::GetSet> getset;
			const EnumDesc<Enum>& enumDesc;  // +0x20 (proposal: 0059fe00 stores singleton() here)

			static void callSingleton()      // 0059fac0 (proposal: jmp EnumDesc<Enum>::singleton)
			{
				EnumDesc<Enum>::singleton();
			}
			static const EnumDesc<Enum>& onceSingleton() // proposal: call_once(callSingleton, flag 009767fc)
			{
				static boost::once_flag flag = BOOST_ONCE_INIT;
				boost::call_once(&callSingleton, flag);
				return EnumDesc<Enum>::singleton();
			}

		public:
			template<typename GetFunction, typename SetFunction>
			EnumPropDescriptor(char const* name, char const* category, typename GetFunction get, typename SetFunction set, Functionality flags)
				: EnumPropertyDescriptor(Class::classDescriptor(), onceSingleton(), name, category, flags),
				  getset(PropDescriptor<Class, Enum>::getset<GetFunction, SetFunction>(get, set)),
				  enumDesc(onceSingleton())
			{
			}
'''
assert text.count(old) == 1
anchor = '#include "reflection/object.h"\n'
assert text.count(anchor) == 1
(pending / 'reflection/reflection.h').write_text(
    text.replace(old, new).replace(anchor, anchor + '#include <boost/thread/once.hpp>\n'))

text = (R / 'native-headers/reflection/type.h').read_text()
old = '\t\t\ttemplate<typename T>\n\t\t\tT get() const;\n'
assert text.count(old) == 1
(pending / 'reflection/type.h').write_text(text.replace(old, '''			template<typename T>
			T get() const // proposal: Value::get<T> body as 0059f310 (MeshId instance)
			{
				if (isType<T>())
					return boost::any_cast<const T&>(value);
				Value copy(*this);
				return copy.convert<T>();
			}
'''))

text = (ROOT / 'tools/rbxgs/Client/App/include/reflection/property.h').read_text()
old = '\t\t\t\tvirtual bool isReadOnly() const = 0;\n\t\t\t\tvirtual PropType getValue'
assert text.count(old) == 1
text = text.replace(old, '\t\t\t\tvirtual bool isReadOnly() const = 0;\n'
                         '\t\t\t\tvirtual bool isWriteOnly() const { return false; } // proposal: slot 1 (0060a2f0)\n'
                         '\t\t\t\tvirtual PropType getValue')
old = '''			void setValue(DescribedBase* object, const PropType& value) const
			{
				getset->setValue(object, value);
			}
'''
assert text.count(old) == 1
text = text.replace(old, old + '''			virtual void getValue(const DescribedBase* object, Value& value) const // proposal: 2008 slot 4 (0059f280)
			{
				value = getset->getValue(object);
			}
			virtual void setValue(DescribedBase* object, const Value& value) const // proposal: 2008 slot 5 (0059f400)
			{
				getset->setValue(object, value.get<PropType>());
			}
''')
(pending / 'reflection/property.h').write_text(text)


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeSpecialShapeLayout', LAYOUT)
main_obj, main_flags = build('NativeSpecialShape', SRC, UNIT_FLAGS)
pend_obj, pend_flags = build('NativeSpecialShapePending', SRC, UNIT_FLAGS + ['/I' + str(pending)])

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?nativeSpecialShapeSize@@'))
assert body == b'\xb8' + struct.pack('<I', 0x18c) + b'\xc3', body.hex()

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,                       # FactoryProduct ctor 0059ed40
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                       # FactoryProduct dtor 0059ece0
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,
    '?getNullName@Name@RBX@@SAABV12@XZ': 0x554270,             # constructor 0059fbb0
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,
    '??9RBX@@YA_NABVContentId@0@0@Z': 0x55bd60,                 # setMeshId 0059ffd0 / setTextureId 005a0030
    '___RTDynamicCast': 0x6a17c6, '_atexit': 0x6a17af,
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,              # doDeclare<sSpecialShape> 0041df70
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,               # getClassName 0059f260
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,   # classDescriptor 0059f7e0
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,      # atexit 007fe080
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,
    '??0PropertyDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@ABVType@12@PBD2W4Functionality@012@@Z': 0x56c650,
    '??$singleton@VMeshId@RBX@@@Type@Reflection@RBX@@SAABV012@XZ': 0x615490,   # 0059ee50 (jmp 0056cd80)
    '??$singleton@VVector3@G3D@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56ce60,  # 0059a4b0
    # TypedPropertyDescriptor<TextureId> constructor: the PropDescriptor<SpecialShape, TextureId> constructor
    # 0059f9b0 calls 005978a0 (evidence name TypedPropertyDescriptor<bool>, ICF-identical code from another unit;
    # its instruction schedule differs from this unit's instance, so it is an external, not a row).
    '??0?$TypedPropertyDescriptor@VTextureId@RBX@@@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@VTextureId@RBX@@@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x5978a0,
    # EnumDesc<MeshType> constructor/destructor 0059f630 / 0059f480
    '??0EnumDescriptor@Reflection@RBX@@IAE@PBDABVtype_info@@@Z': 0x56c590,
    '??1EnumDescriptor@Reflection@RBX@@MAE@XZ': 0x56c080,
    '?addPair@?$EnumDesc@W4MeshType@SpecialShape@RBX@@@Reflection@RBX@@AAEXW4MeshType@SpecialShape@3@PBD@Z': 0x64d530,
    '?_Tidy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ': 0x4077d0,
    # pending rows: Value::convert<MeshId> (0059f310), bad_any_cast throw (0059f1d0)
    '??$convert@VMeshId@RBX@@@Value@Reflection@RBX@@QAEAAVMeshId@2@XZ': 0x6156c0,
    '??$throw_exception@Vbad_any_cast@boost@@@boost@@YAXABVbad_any_cast@0@@Z': 0x40a3f0,
}
_tree = '?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4MeshType@SpecialShape@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4MeshType@SpecialShape@2@@std@@@6@$0A@@std@@@std@@'
EXTERNAL['??0' + _tree + 'QAE@ABU?$less@PBVName@RBX@@@1@ABV?$allocator@U?$pair@QBVName@RBX@@W4MeshType@SpecialShape@2@@std@@@1@@Z'] = 0x446110
EXTERNAL['??1' + _tree + 'QAE@XZ'] = 0x553d80
# Descriptor objects: the `this` the dynamic initializers 007f4c20..007f4d20 pass; the class-name char array.
DATA = {
    '?desc_meshType@@': 0x976858, '?desc_scale@@': 0x97683c, '?desc_meshId@@': 0x976820,
    '?desc_textureId@@': 0x976804, '?desc_vertColor@@': 0x97687c,
    '?sSpecialShape@RBX@@3PADA': 0x94afac,
}
DATA.update({'_' + k[1:-2]: v for k, v in DATA.items() if k.startswith('?desc_')})   # static-storage names

SS = 'SpecialShape@RBX@@'
FP = '?$FactoryProduct@VSpecialShape@RBX@@VInstance@2@$1?sSpecialShape@2@3PADA@RBX@@'
DC = '?$DescribedCreatable@VSpecialShape@RBX@@VInstance@2@$1?sSpecialShape@2@3PADA@RBX@@'
ED = '?$EnumDesc@W4MeshType@SpecialShape@RBX@@@Reflection@RBX@@'
GS = '@?$PropDescriptor@VSpecialShape@RBX@@V%s@Reflection@RBX@@UBE'

# (address, symbol or unique symbol prefix)
ROWS = [
    (0x59ece0, '??1' + FP + 'MAE@XZ'),
    (0x59ed40, '??0' + FP + 'IAE@XZ'),
    (0x59edb0, '??_G' + FP + 'MAEPAXI@Z'),
    (0x59ee00, '?getValue@?$GetSetImpl@P8SpecialShape@RBX@@BEABVVector3@G3D@@XZ'),
    (0x59ee40, '??1' + DC + 'UAE@XZ'),
    (0x59ee50, '??0?$TypedPropertyDescriptor@VMeshId@RBX@@@Reflection@RBX@@IAE@'),
    (0x59f050, '??$getset@P8SpecialShape@RBX@@BE?BW4MeshType@'),
    (0x59f0a0, '??$getset@P8SpecialShape@RBX@@BEABVVector3@'),
    (0x59f0f0, '??$getset@P8SpecialShape@RBX@@BE?BVMeshId@'),
    (0x59f140, '??$getset@P8SpecialShape@RBX@@BE?BVTextureId@'),
    (0x59f260, '?getClassName@' + FP + 'UBEABVName@2@XZ'),
    (0x59f470, '??1?$map@PBVName@RBX@@W4MeshType@SpecialShape@2@'),   # ICF-shared map destructor (jmp 00553d80)
    (0x59f480, '??1' + ED + 'EAE@XZ'),
    (0x59f610, '??_G' + ED + 'EAEPAXI@Z'),
    (0x59f630, '??0' + ED + 'AAE@XZ'),
    (0x59f7e0, '?classDescriptor@?$Described@VSpecialShape@RBX@@'),
    (0x59f850, '??$?0P8SpecialShape@RBX@@BEABVVector3@'),
    (0x59f900, '??$?0P8SpecialShape@RBX@@BE?BVMeshId@'),
    (0x59f9b0, '??$?0P8SpecialShape@RBX@@BE?BVTextureId@'),
    (0x59fa60, '?singleton@' + ED + 'SAABV123@XZ'),
    (0x59fad0, '??0' + DC + 'IAE@XZ'),
    (0x59fbb0, '??0SpecialShape@RBX@@QAE@XZ'),
    (0x59fd70, '??1SpecialShape@RBX@@UAE@XZ'),
    (0x59fde0, '??_GSpecialShape@RBX@@UAEPAXI@Z'),
    (0x59fee0, '?setMeshType@' + SS),
    (0x59ff10, '?setScale@' + SS),
    (0x59ff70, '?setVertColor@' + SS),
    (0x59ffd0, '?setMeshId@' + SS),
    (0x5a0030, '?setTextureId@' + SS),
    (0x7f4c20, '??__Edesc_meshType@@YAXXZ'),
    (0x7f4c60, '??__Edesc_scale@@YAXXZ'),
    (0x7f4ca0, '??__Edesc_meshId@@YAXXZ'),
    (0x7f4ce0, '??__Edesc_textureId@@YAXXZ'),
    (0x7f4d20, '??__Edesc_vertColor@@YAXXZ'),
    (0x7fdfe0, '??__Fdesc_meshType@@YAXXZ'),
    (0x7fe000, '??__Fdesc_vertColor@@YAXXZ'),
    (0x7fe020, '??__Fdesc_textureId@@YAXXZ'),
    (0x7fe040, '??__Fdesc_meshId@@YAXXZ'),
    (0x7fe060, '??__Fdesc_scale@@YAXXZ'),
    (0x7fe080, '??__Ffoo@?1??classDescriptor@?$Described@VSpecialShape@RBX@@'),
    (0x7fe090, '??__Fs@?1??singleton@' + ED),
    # template instances / inline members whose original bodies live outside the unit (COMDAT / ICF-shared)
    (0x41df70, '??$doDeclare@$1?sSpecialShape@RBX@@3PADA@Name@RBX@@CAABV01@XZ'),
    (0x41e0e0, '??$callDoDeclare@$1?sSpecialShape@RBX@@3PADA@Name@RBX@@CAXXZ'),
    (0x4e5f20, '?getMeshId@' + SS),
    (0x4e5f50, '?getTextureId@' + SS),
    (0x4e5ba0, '?getVertColor@' + SS),
    (0x68e8b0, '?getScale@' + SS),
    (0x565e30, '?getMeshType@' + SS),
    (0x62e190, '?askSetParent@' + SS),
    (0x59a4b0, '??0?$TypedPropertyDescriptor@VVector3@G3D@@@Reflection@RBX@@IAE@'),
    # GetSetImpl bodies (getset vtables 008332c8 / 008332dc / 008332f0 / 00833304 slots 0..3, checked below)
    (0x60a2f0, '?isReadOnly@?$GetSetImpl@P8SpecialShape@RBX@@BE?BW4MeshType@'),
    (0x60a2f0, '?isReadOnly@?$GetSetImpl@P8SpecialShape@RBX@@BEABVVector3@'),
    (0x60a2f0, '?isReadOnly@?$GetSetImpl@P8SpecialShape@RBX@@BE?BVMeshId@'),
    (0x60a2f0, '?isReadOnly@?$GetSetImpl@P8SpecialShape@RBX@@BE?BVTextureId@'),
    (0x5cf660, '?getValue@?$GetSetImpl@P8SpecialShape@RBX@@BE?BW4MeshType@'),
    (0x563b00, '?setValue@?$GetSetImpl@P8SpecialShape@RBX@@BE?BW4MeshType@'),
    (0x5b73c0, '?setValue@?$GetSetImpl@P8SpecialShape@RBX@@BEABVVector3@'),
    (0x5cf5d0, '?getValue@?$GetSetImpl@P8SpecialShape@RBX@@BE?BVMeshId@'),
    (0x5b73c0, '?setValue@?$GetSetImpl@P8SpecialShape@RBX@@BE?BVMeshId@'),
    (0x5cf5d0, '?getValue@?$GetSetImpl@P8SpecialShape@RBX@@BE?BVTextureId@'),
    (0x5b73c0, '?setValue@?$GetSetImpl@P8SpecialShape@RBX@@BE?BVTextureId@'),
]
# Deleting-destructor adjustor thunks (original vtables 00833274.. / 008334b0.. share the FactoryProduct ones).
THUNKS = {
    'leaf': {'BA': 0x59fcf0, 'BE': 0x59fd00, 'CE': 0x59fd10, 'EE': 0x59fd20, 'GE': 0x59fd30, 'IE': 0x59fd40,
             'KE': 0x59fd50, 'ME': 0x59fd60},
    'base': {'BA': 0x59eda0, 'BE': 0x59edd0, 'CE': 0x59fb90, 'EE': 0x59fba0, 'GE': 0x59fb70, 'IE': 0x59ede0,
             'KE': 0x59edf0, 'ME': 0x59fb80},
}
ROWS += [(0x59edb0, '??_G' + DC + 'UAEPAXI@Z')]
for adj, address in sorted(THUNKS['leaf'].items(), key=lambda x: x[1]):
    ROWS.append((address, '??_ESpecialShape@RBX@@W' + adj + '@AEPAXI@Z'))
for adj, address in sorted(THUNKS['base'].items(), key=lambda x: x[1]):
    ROWS.append((address, '??_E' + FP + 'O' + adj + '@AEPAXI@Z'))
    ROWS.append((address, '??_E' + DC + 'W' + adj + '@AEPAXI@Z'))

# Rows exact only against the generated header copies (pending build); recorded exact=false, not counted.
PENDING_ROWS = [
    (0x59eec0, '??0?$holder@VMeshId@RBX@@@any@boost@@'),
    (0x59ef20, '?type@?$holder@VMeshId@RBX@@@any@boost@@'),
    (0x59ef30, '?clone@?$holder@VMeshId@RBX@@@any@boost@@'),
    (0x59ef90, '??$?0VMeshId@RBX@@@any@boost@@'),
    (0x59eff0, '??_G?$holder@VMeshId@RBX@@@any@boost@@'),
    (0x59f190, '??$?4VMeshId@RBX@@@any@boost@@'),
    (0x59f1d0, '??$any_cast@ABVMeshId@RBX@@@boost@@'),
    (0x59f280, '?getValue@?$TypedPropertyDescriptor@VMeshId@RBX@@@Reflection@RBX@@UBEXPBVDescribedBase@23@AAVValue@'),
    (0x59f310, '??$get@VMeshId@RBX@@@Value@Reflection@RBX@@QBE'),
    (0x59f400, '?setValue@?$TypedPropertyDescriptor@VMeshId@RBX@@@Reflection@RBX@@UBEXPAVDescribedBase@23@ABVValue@'),
    (0x59fac0, '?callSingleton@?$EnumPropDescriptor@VSpecialShape@RBX@@W4MeshType@'),
    (0x59fe00, '??$?0P8SpecialShape@RBX@@BE?BW4MeshType@'),
]
PENDING_REASON = {
    '0059eec0': 'boost::any::holder<MeshId> constructor', '0059ef20': 'holder<MeshId>::type',
    '0059ef30': 'holder<MeshId>::clone', '0059ef90': 'boost::any(const MeshId&)',
    '0059eff0': 'holder<MeshId> deleting destructor', '0059f190': 'boost::any::operator=(const MeshId&)',
    '0059f1d0': 'any_cast<const MeshId&>', '0059f310': 'Value::get<MeshId>',
    '0059f280': 'TypedPropertyDescriptor<MeshId> Value-based getValue (2008 vtable 008333d8 slot 4)',
    '0059f400': 'TypedPropertyDescriptor<MeshId> Value-based setValue (slot 5)',
    '0059fac0': 'EnumPropDescriptor call_once target (jmp EnumDesc<MeshType>::singleton)',
    '0059fe00': 'EnumPropDescriptor<SpecialShape, MeshType> constructor',
}
PROPOSALS = [
    'native-headers/reflection/reflection.h EnumPropDescriptor (shared, not edited; same as the 2026-11-04 Feature '
    'proposal): constructor = PropertyDescriptor via EnumPropertyDescriptor(Class::classDescriptor(), '
    'onceSingleton(), name, category, flags); getset(+0x1c); then a `const EnumDesc<Enum>& enumDesc` member at '
    '+0x20 = onceSingleton(), where onceSingleton() is boost::call_once(&callSingleton, flag) + '
    'EnumDesc<Enum>::singleton() and callSingleton is `jmp singleton` (0059fe00 / 0059fac0, flag 009767fc).',
    'native-headers/reflection/type.h Value::get<T>() const body (declared only): if (isType<T>()) return '
    'boost::any_cast<const T&>(value); Value copy(*this); return copy.convert<T>(); (0059f310, MeshId).',
    'reflection/property.h (donor include, no native override yet): TypedPropertyDescriptor<T>::GetSet gets '
    '`virtual bool isWriteOnly() const` at slot 1 (getset vtables 008332c8..00833304 hold 0060a2f0 twice; same '
    'as the Clothing proposal), and TypedPropertyDescriptor<T> gets the 2008 Value-based virtuals '
    '`void getValue(const DescribedBase*, Value&) const { value = getset->getValue(object); }` and '
    '`void setValue(DescribedBase*, const Value&) const { getset->setValue(object, value.get<T>()); }` '
    '(PropDescriptor<SpecialShape, MeshId> vtable 008333d8 slots 4/5 = 0059f280 / 0059f400). The full 2008 '
    'descriptor vtable has 12 slots; only these two bodies are proven here.',
]

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}   # symbol -> (address, row) for the one-address-per-symbol check


def resolve(obj, rows):
    raw = Path(obj).read_bytes()
    funcs = match.coff_functions(raw)
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key)
                                                       and not LOCAL_EH.match(x[0])]
        assert len(hits) == 1, (hex(address), key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def data_address(symbol):
    hits = [v for k, v in DATA.items() if symbol == k or (k.endswith('@@') and symbol.startswith(k))]
    return hits[0] if len(hits) == 1 else None


def classify(symbol, value, own, raw, sections, definitions, where):
    """Return how a relocation target bound to `value` is verified, or None when unknown."""
    hit = original.imported(value)
    if hit is not None and symbol == '??9RBX@@YA_NABVContentId@0@0@Z':
        # RBX::operator!=(ContentId, ContentId) (out of line, ContentProvider.cpp) is a single
        # `jmp [string operator!=]` in the original (0055bd60), so the body itself is an import jump.
        assert value == EXTERNAL[symbol] and hit == ('msvcp90.dll', '??$?9DU?$char_traits@D@std@@V?$allocator@D@1@@std@@YA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@0@Z'), hit
        return 'external %s (jmp %s!%s)' % ((hex(value),) + hit)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol.startswith('??_C@'):
        pos, at = definitions[symbol]
        literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
        assert original.data(value, len(literal)) == literal, (where, symbol, hex(value))
        return 'literal %r' % literal[:-1].decode()
    if symbol.startswith('__real@') and len(symbol) == 15:
        bits = struct.pack('<I', int(symbol[7:], 16))
        assert original.data(value, 4) == bits, (where, symbol, hex(value))
        return 'float constant %r' % struct.unpack('<f', bits)
    if symbol.startswith('??_R0') and symbol.endswith('@8'):
        rtti = original.string(value + 8)
        assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
        return 'RTTI %s' % rtti
    if symbol.startswith('??_7'):
        rtti, at = original.vtable_class(value)
        cls = symbol[4:symbol.index('@@6B') + 2]
        assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
        return 'vtable RTTI %s offset %#x' % (rtti, at)
    if symbol in own:
        assert own[symbol] == value, (where, symbol, hex(value), hex(own[symbol]))
        return 'own row'
    if symbol.startswith('??_E') and ('??_G' + symbol[4:]) in own:
        assert own['??_G' + symbol[4:]] == value, (where, symbol, hex(value))
        return 'own row (??_G)'
    at = data_address(symbol)
    if at is not None:
        assert at == value, (where, symbol, hex(value), hex(at))
        return 'data'
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
        return 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
    if symbol.startswith('??_B?1??') or symbol.startswith('?$S') or '?$TSS' in symbol or symbol.startswith('?flag@') \
            or symbol.startswith('?foo@') or symbol.startswith('?s@?1??singleton@') or symbol.startswith('?root@') \
            or symbol.startswith('?n@?1???$doDeclare@'):
        return 'local static'
    return None


def verify(obj, rows, own):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        assert match.exact_match(target, target_refs, body, refs), (name, hex(address), len(body), len(target))
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
            how = classify(symbol, value, own, raw, sections, definitions, name)
            if how is None:
                UNBOUND.append('%s in %s -> %s' % (symbol, name, hex(value)))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        result.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'exact': True,
                       'verified_targets': verified, 'local_eh': sorted(local)})
    return result


main_rows = resolve(main_obj, ROWS)
pend_rows = resolve(pend_obj, PENDING_ROWS)
own = {}
for address, name in main_rows + pend_rows:
    own.setdefault(name, address)
main_out = verify(main_obj, main_rows, own)
pend_out = verify(pend_obj, pend_rows, own)
for row in pend_out:  # exact only against the generated header copies: not counted as exact
    row['exact'] = False
    row['exact_pending_build_only'] = True
    row['what'] = PENDING_REASON[row['address']]
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- vtables of the main build, slot by slot against the original vtable each one binds to -----------
INSTANCE_VTABLES = {0x0: 0x82d884, 0x10: 0x82d878, 0x14: 0x82d870, 0x20: 0x82d868, 0x24: 0x82d858, 0x44: 0x82d848,
                    0x64: 0x82d838, 0x84: 0x82d828, 0xa4: 0x82d818, 0xc4: 0x82d808}
for at, vt in INSTANCE_VTABLES.items():
    assert original.vtable_class(vt) == ('.?AVInstance@RBX@@', at), (hex(vt), original.vtable_class(vt))
CLASSES = (SS, FP, DC)
raw = main_obj.read_bytes()
sections, symbols, definitions, starts = match._coff_data_index(raw)
vtables = {}
for symbol, (value, sec) in definitions.items():
    if not symbol.startswith('??_7') or symbol not in binding:
        continue
    if not any(symbol[4:].startswith(c + '6B') for c in CLASSES):
        continue
    vt = binding[symbol][0]
    rtti, at = original.vtable_class(vt)
    table = sections[sec]
    end = min([x for x in starts[sec + 1] if x > value] + [table[3]])
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if value <= offset < end:
            slots[(offset - value) // 4] = symbols[index][0]
    assert slots and max(slots) == len(slots) - 1, (symbol, sorted(slots))
    checked = {}
    for slot, sym in sorted(slots.items()):
        value_orig = d(vt + 4 * slot)
        how = classify(sym, value_orig, own, raw, sections, definitions, symbol)
        if how is None and at in INSTANCE_VTABLES and d(INSTANCE_VTABLES[at] + 4 * slot) == value_orig \
                and 'SpecialShape' not in sym:
            how = 'inherited (Instance vtable %#x slot %d)' % (INSTANCE_VTABLES[at], slot)
        if how is None:
            UNBOUND.append('vtable %s slot %d %s -> %s' % (symbol, slot, sym, hex(value_orig)))
            continue
        prev = binding.setdefault(sym, (value_orig, symbol))
        assert prev[0] == value_orig, ('inconsistent', sym, hex(prev[0]), prev[1], hex(value_orig), symbol)
        checked[slot] = '%s = %s (%s)' % (sym, hex(value_orig), how)
    vtables[symbol] = {'address': hex(vt), 'rtti': rtti, 'offset': hex(at), 'slots': checked}
assert not UNBOUND, '\n'.join(UNBOUND)
for vt, rtti in ((0x833584, '.?AVSpecialShape@RBX@@'),):
    assert original.vtable_class(vt) == (rtti, 0), (hex(vt), rtti)
    assert any(v['address'] == hex(vt) for v in vtables.values()), (hex(vt), 'main vtable not checked')
assert d(0x833584 + 12) == 0x62e190 and d(0x833584 + 8) == 0x68e880   # askSetParent overridden, askAddChild not
# getset vtables (2008 GetSet: isReadOnly, isWriteOnly, getValue, setValue): bodies are rows above
for vt, rtti, getter, setter in ((0x8332c8, 'MeshType', 0x5cf660, 0x563b00), (0x8332dc, 'Vector3', 0x59ee00, 0x5b73c0),
                                 (0x8332f0, 'MeshId', 0x5cf5d0, 0x5b73c0), (0x833304, 'TextureId', 0x5cf5d0, 0x5b73c0)):
    assert rtti in original.vtable_class(vt)[0], (hex(vt), original.vtable_class(vt))
    assert [d(vt + 4 * i) for i in range(4)] == [0x60a2f0, 0x60a2f0, getter, setter], hex(vt)
assert d(0x8333d8 + 16) == 0x59f280 and d(0x8333d8 + 20) == 0x59f400   # PropDescriptor<SpecialShape, MeshId>

# ---- allocation size, RTTI bases and strings -----------------------------------------------------------
body, _, _ = match.target('2008-06', '0041ec30')
at = body.index(b'\x68' + struct.pack('<I', 0x18c))
call = body.index(b'\xe8', at + 5)
while (0x41ec30 + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != 0x59fbb0:
    call = body.index(b'\xe8', call + 1)
for address, text in ((0x94afac, 'SpecialMesh'), (0x8334fc, 'Mesh'), (0x833394, 'MeshType'), (0x833614, 'Scale'),
                      (0x83361c, 'MeshId'), (0x833624, 'TextureId'), (0x833630, 'VertexColor'), (0x822490, 'Data')):
    assert original.string(address) == text, (hex(address), text)
locator = d(0x833584 - 4)
hierarchy = d(locator + 16)
items = [d(d(hierarchy + 12) + 4 * i) for i in range(d(hierarchy + 8))]
bases = [original.string(d(item) + 8) for item in items]
assert len(bases) == 21 and bases[1] == '.?AV' + DC, bases[:3]

exact = [r['address'] for r in main_out]
sha = nb.sha
paths = [Path(__file__).resolve(), HDR, SRC, LAYOUT]
receipt = {
    'class': 'RBX::SpecialShape ("SpecialMesh")', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'main': main_flags, 'pending': pend_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, main_obj, pend_obj)},
    'layout': {'SpecialShape': '0x18c (create<SpecialShape> 0041ec30 allocates 0x18c); meshType +0x130, scale +0x134, '
                               'textureId +0x140, meshId +0x160, vertColor +0x180; no mesh base class (RTTI 21 bases)'},
    'methods': main_out,
    'exact_count': len(main_out), 'exact_unique_addresses': len(set(exact)),
    'pending_methods': pend_out,
    'pending_note': 'Pending rows are exact only against generated copies of reflection.h / type.h / property.h '
                    'under out/native-layouts/special-shape-pending/; not counted as exact.',
    'non_exact': {},
    'proposals': PROPOSALS,
    'vtables': vtables,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/special-shape-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native SpecialShape: %d rows exact (%d unique addresses), %d pending-only (%d unique), %d vtables checked' % (
    len(main_out), len(set(exact)), len(pend_out), len({r['address'] for r in pend_out}), len(vtables)))
