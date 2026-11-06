"""Verify the inactive native RBX::Feature / Hole / MotorFeature / VelocityMotor recovery (2008-06).

Builds (document-swap flags plus /fp:fast /U_RELEASEASSERT, VS2008 RTM 21022):
  * tests/NativeFeatureLayout.cpp   sizeof/offset probes (mov eax, imm32; ret), in both builds below;
  * native-classes/Feature.cpp      the whole original unit (00609a30..0060ca00, initializers 007f7ac0..007f7c80,
                                    atexit rows) plus the template instances whose original bodies live elsewhere
                                    (COMDAT / ICF), against the current native headers;
  * Feature.cpp with NATIVE_FEATURE_PENDING against out/native-feature-pending/ (generated copies, no shared header
    is edited): tests/NativeFeaturePendingJointInstance.h as v8datamodel/JointInstance.h (2008 JointInstance:
    weak_ptr part[2] +0x140, joint +0x150, askSetParent/onAncestorChanged), tests/NativeFeaturePendingWorkspace.h,
    reflection/reflection.h with IIDREF __declspec(novtable), donor reflection/signal.h with the 2008
    connect(source, slot, int group), donor v8world/MotorJoint.h without `polarity`, donor v8kernel/IStage.h with
    KERNEL_STAGE = 7, and native-headers/part-embedded (PartInstance with the embedded Primitive at +0x228).
    Rows exact only in this build are recorded exact=false (pending-build-only) and are not counted.
    The RefPropDescriptor<VelocityMotor, Hole> constructor 0060b8c0 and the boost::function rows of the setHole slot
    (0060a300, 0060aac0, 0060abe0; explicit slot instantiation in Feature.cpp) are counted from the main build.

Every row must be relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, string literals by bytes,
type descriptors and vtables by original RTTI names (and complete-object offset), own symbols by the row
proven here, ICF folds by the FOLDED map, and the remaining externals by the EXTERNAL map (call sites read in
the original disassembly). A symbol must bind to one address in every row. Each vtable the main build emits
for Feature/Hole/MotorFeature/VelocityMotor (and their FactoryProduct/DescribedCreatable bases) is compared slot by
slot with the original vtable it binds to (main build object, not the pending one). A main row is counted only when
every vtable it references passes that check; vtables bound only by pending rows are compared the same way (main
build object) and their mismatching slots are reported.
Writes work/2008-06/shared-layouts/feature-working.json.
"""
import json
import shutil
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
SRC = R / 'native-classes/Feature.cpp'
HDR = R / 'native-headers/v8datamodel/Feature.h'
LAYOUT = R / 'tests/NativeFeatureLayout.cpp'
JI_OVERLAY = R / 'tests/NativeFeaturePendingJointInstance.h'
WS_OVERLAY = R / 'tests/NativeFeaturePendingWorkspace.h'
DONOR = ROOT / 'tools/rbxgs/Client/App/include'
# Unit profile: the VelocityMotor float setters 0060c580/0060c5c0/0060c600 need /fp:fast (fucom st(1) order); the
# 2008 rbx_static_cast has no RBXASSERT dynamic_cast, so IPipelined::getWorld inlines (0060a0f0, /U_RELEASEASSERT).
UNIT = ['/fp:fast', '/U_RELEASEASSERT']

# ---- generated pending headers (copies under out/; shared, donor and other owners' headers are not edited) -----
pending = OUT / 'native-feature-pending'
for sub in ('v8datamodel', 'reflection', 'v8world', 'v8kernel'):
    (pending / sub).mkdir(parents=True, exist_ok=True)
if (pending / 'v8datamodel/VelocityMotor.h').exists():   # stale overlay of the previous recorder version
    (pending / 'v8datamodel/VelocityMotor.h').unlink()
shutil.copyfile(JI_OVERLAY, pending / 'v8datamodel/JointInstance.h')
shutil.copyfile(WS_OVERLAY, pending / 'v8datamodel/Workspace.h')
GENERATED = {
    # path: (source text, anchor, replacement, proposal)
    'reflection/reflection.h': (
        R / 'native-headers/reflection/reflection.h', '\tclass IIDREF\n', '\tclass __declspec(novtable) IIDREF\n',
        'native-headers/reflection/reflection.h (reflection owner): declare IIDREF __declspec(novtable) (same proposal '
        'as record_native_body_movers.py / record_native_network_players.py): RefPropDescriptor<VelocityMotor, Hole> '
        'constructor 0060b8c0 stores only the derived IIDREF vptr 00842fb8.'),
    'reflection/signal.h': (
        DONOR / 'reflection/signal.h',
        'boost::signals::connection connect(SignalSource* source, const boost::slot<boost::function<CallbackSignature>>& slot)',
        'boost::signals::connection connect(SignalSource* source, const boost::slot<boost::function<CallbackSignature>>& '
        'slot, int group);\n\t\t\tboost::signals::connection connect(SignalSource* source, const '
        'boost::slot<boost::function<CallbackSignature>>& slot)',
        'reflection/signal.h (signal owner; same as the Seat/SpawnLocation proposals): the 2008 SignalDesc::connect '
        'takes a third `int group` argument (004a3340); VelocityMotor::setHole 0060c400 passes 10.'),
    'v8world/MotorJoint.h': (
        DONOR / 'v8world/MotorJoint.h', '\t\tint polarity;\n', '',
        'v8world/MotorJoint.h (engine owner): the 2008 MotorJoint has no `polarity`: constructor 005e5bf0 stores '
        'link +0x88, currentAngle +0x8c, maxVelocity +0x90, desiredAngle +0x94, and VelocityMotor() 0060bbb0 '
        'allocates 0x98. The donor layout puts maxVelocity at +0x94.'),
    'v8kernel/IStage.h': (
        DONOR / 'v8kernel/IStage.h', 'KERNEL_STAGE = 0x8,', 'KERNEL_STAGE = 0x7,',
        'v8kernel/IStage.h (engine owner): the 2008 KERNEL_STAGE is 7. IPipelined::getWorld, inlined in '
        'VelocityMotor::onAncestorChanged 0060a0f0 and JointInstance::onAncestorChanged 005e3a80, compares the stage '
        'type with 7. Which donor stage is absent in 2008 is not proven here, so only the value changes.'),
}
for path, (source, anchor, replacement, _) in GENERATED.items():
    text = Path(source).read_text()
    if path == 'reflection/reflection.h' and replacement in text:
        assert text.count(replacement) == 1 and anchor not in text
        (pending / path).write_text(text)
        continue
    assert text.count(anchor) == 1, (path, anchor)
    (pending / path).write_text(text.replace(anchor, replacement))
PART_EMBEDDED = R / 'native-headers/part-embedded'   # existing opt-in PartInstance with the embedded Primitive
PENDING_FLAGS = ['/I' + str(pending), '/I' + str(PART_EMBEDDED), '/DNATIVE_FEATURE_PENDING']


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + UNIT + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeFeatureLayout', LAYOUT)
pend_layout_obj, pend_layout_flags = build('NativeFeatureLayoutPending', LAYOUT, PENDING_FLAGS)
main_obj, main_flags = build('NativeFeature', SRC)
pend_obj, pend_flags = build('NativeFeaturePending', SRC, PENDING_FLAGS)


# ---- layout ---------------------------------------------------------------------------------------
def probes(obj):
    out = {}
    for name, body, refs in match.coff_functions(Path(obj).read_bytes()):
        if name.startswith('?native') and len(body) == 6 and body[0] == 0xb8 and body[5] == 0xc3:
            out[name[1:name.index('@@')]] = struct.unpack_from('<I', body, 1)[0]
    return out


main_layout, pend_layout = probes(layout_obj), probes(pend_layout_obj)
for layout in (main_layout, pend_layout):
    for key, value in (('nativeFeatureSize', 0x150), ('nativeHoleSize', 0x150), ('nativeMotorFeatureSize', 0x150),
                       ('nativeFeatureRenderableOffset', 0x130), ('nativeVelocityMotorRenderableOffset', 0x130),
                       ('nativeVelocityMotorJointOwnerOffset', 0x140)):
        assert layout[key] == value, (key, hex(layout[key]))
# current shared JointInstance.h (0x144, joint +0x140): VelocityMotor's own fields start right after it
ji = main_layout['nativeJointInstanceSize']
assert (main_layout['nativeVelocityMotorHoleOffset'], main_layout['nativeVelocityMotorConnectionOffset'],
        main_layout['nativeVelocityMotorSize']) == (ji, ji + 8, ji + 0x1c), main_layout
# generated 2008 JointInstance.h: the offsets the binary uses
for key, value in (('nativeJointInstanceSize', 0x154), ('nativeVelocityMotorJointOffset', 0x150),
                   ('nativeVelocityMotorHoleOffset', 0x154), ('nativeVelocityMotorConnectionOffset', 0x15c),
                   ('nativeVelocityMotorSize', 0x170)):
    assert pend_layout[key] == value, (key, hex(pend_layout[key]))

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,                       # NonFactoryProduct ctor 00609b50
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                       # Feature dtor 0060a360
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,
    '??1IRenderable@RBX@@QAE@XZ': 0x47d410,                    # Feature dtor 0060a360 (empty body, ICF `ret`)
    '___RTDynamicCast': 0x6a17c6, '_atexit': 0x6a17af,
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,              # doDeclare 00609c60
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,               # getClassName 0060ab60
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,
    '??0CoordinateFrame@G3D@@QAE@XZ': 0x4782d0,                # render3dSelect 0060a520
    '?selectColor@Draw@RBX@@SAABVColor3@G3D@@XZ': 0x676c50,
    '?black@Color3@G3D@@SAABV12@XZ': 0x5149f0,                 # Hole::render3dAdorn 0060a580
    '?yellow@Color3@G3D@@SAABV12@XZ': 0x514980,                # MotorFeature::render3dAdorn 0060a5e0
    '?cylinder@DrawAdorn@RBX@@SAXPAVAdorn@2@ABVCoordinateFrame@G3D@@HMMABVColor3@5@@Z': 0x6773f0,
    # EnumDesc constructors/destructors 0060b1d0.. / 0060acc0..
    '??0EnumDescriptor@Reflection@RBX@@IAE@PBDABVtype_info@@@Z': 0x56c590,
    '??1EnumDescriptor@Reflection@RBX@@MAE@XZ': 0x56c080,
    '?getNullName@Name@RBX@@SAABV12@XZ': None,                 # filled from the constructor call site below
    # dynamic initializers 007f7bc0..007f7c80: EnumPropDescriptor constructors (not recovered, see NON_EXACT)
    '??$?0P8Feature@RBX@@BE?AW4NormalId@1@XZP801@AEXW421@@Z@?$EnumPropDescriptor@VFeature@RBX@@W4NormalId@2@@Reflection@RBX@@QAE@PBD0P8Feature@2@BE?AW4NormalId@2@XZP832@AEXW442@@ZW4Functionality@PropertyDescriptor@12@@Z': 0x60bd80,
    '??$?0P8Feature@RBX@@BE?AW4TopBottom@01@XZP801@AEXW4201@@Z@?$EnumPropDescriptor@VFeature@RBX@@W4TopBottom@12@@Reflection@RBX@@QAE@PBD0P8Feature@2@BE?AW4TopBottom@32@XZP832@AEXW4432@@ZW4Functionality@PropertyDescriptor@12@@Z': 0x60c040,
    '??$?0P8Feature@RBX@@BE?AW4LeftRight@01@XZP801@AEXW4201@@Z@?$EnumPropDescriptor@VFeature@RBX@@W4LeftRight@12@@Reflection@RBX@@QAE@PBD0P8Feature@2@BE?AW4LeftRight@32@XZP832@AEXW4432@@ZW4Functionality@PropertyDescriptor@12@@Z': 0x60c180,
    '??$?0P8Feature@RBX@@BE?AW4InOut@01@XZP801@AEXW4201@@Z@?$EnumPropDescriptor@VFeature@RBX@@W4InOut@12@@Reflection@RBX@@QAE@PBD0P8Feature@2@BE?AW4InOut@32@XZP832@AEXW4432@@ZW4Functionality@PropertyDescriptor@12@@Z': 0x60c260,
    # Feature::getRenderCoord: not exact (NON_EXACT); address from the render3dSelect/render3dAdorn call sites
    '?getRenderCoord@Feature@RBX@@IBE_NAAVCoordinateFrame@G3D@@@Z': 0x60a490,
    # EnumDesc helpers: one ICF-shared STL/addPair body for every enum (call sites in 0060b1d0.. / 0060acc0..)
    '?_Tidy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ': 0x4077d0,
    # MotorFeature::join 0060ca00: VelocityMotor factory (allocates 0x170, calls 0060bbb0), Instance::setParent
    '??$create@VVelocityMotor@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VVelocityMotor@RBX@@@boost@@XZ': 0x5804a0,
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': 0x55a8f0,
    # VelocityMotor (call sites in 0060bbb0 / 0060a650 / 00609af0 / 00609cd0 / 0060bab0 / 0060a0f0 / 0060a020 / 0060c400)
    '??0MotorJoint@RBX@@QAE@XZ': 0x5e5bf0,                      # VelocityMotor() 0060bbb0
    '??0JointInstance@RBX@@QAE@PAVJoint@1@@Z': 0x5e3870,       # FactoryProduct(Joint*) 00609cd0
    '??1JointInstance@RBX@@QAE@XZ': 0x5e2e10,                  # ~FactoryProduct 00609af0 (tail jmp)
    '??1JointInstance@RBX@@UAE@XZ': 0x5e2e10,
    '??1scoped_connection@signals@boost@@QAE@XZ': 0x5954b0,    # ~VelocityMotor 0060a650
    '?onAncestorChanged@JointInstance@RBX@@MAEXABUAncestorChanged@2@@Z': 0x5e3a80,   # 0060a0f0 (pending overlay)
    '?askSetParent@JointInstance@RBX@@MBE_NPBVInstance@2@@Z': 0x5e3790,
    '?shouldRender3dAdorn@JointInstance@RBX@@MBE_NXZ': 0x5e27a0,
    '?render3dAdorn@JointInstance@RBX@@MAEXPAVAdorn@2@@Z': 0x5e2af0,
    '?getWorldIfInWorkspace@Workspace@RBX@@SAPAVWorld@2@PBVInstance@2@@Z': 0x5a3390,
    '?removeJoint@World@RBX@@QAEXPAVJoint@2@@Z': 0x5ea3a0,
    '?insertJoint@World@RBX@@QAEXPAVJoint@2@@Z': 0x5ea320,
    '?computeLocalCoordinateFrame@Feature@RBX@@QBE?AVCoordinateFrame@G3D@@XZ': 0x609da0,   # setPart 0060a020
    # CoordinateFrame copy (inlined): Matrix3 copy constructor, ICF-shared with Matrix3::operator= (evidence name)
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,
    '?setJointCoord@Joint@RBX@@QAEXHABVCoordinateFrame@G3D@@@Z': 0x645750,
    '?setCurrentAngle@MotorJoint@RBX@@QAEXM@Z': 0x5e5da0,       # setCurrentAngle 0060c600
    '??$shared_from@VHole@RBX@@@RBX@@YA?AV?$shared_ptr@VHole@RBX@@@boost@@PAVHole@0@@Z': 0x618a40,   # setHole 0060c400
    '??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z': 0x4025b0,
    '??4scoped_connection@signals@boost@@QAEAAV012@ABVconnection@12@@Z': 0x595540,
    '?connect@?$TSignalDesc@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@Z@Reflection@RBX@@QAE?AVconnection@signals@boost@@PAVSignalSource@23@ABV?$slot@V?$function@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@ZV?$allocator@X@std@@@boost@@@6@H@Z': 0x4a3340,
    '??1connection@signals@boost@@QAE@XZ': 0x595370,
    '?disconnect@connection@signals@boost@@QBEXXZ': 0x595230,
    # boost::slot<function<void(shared_ptr<Instance>)>> from the bind_t (0060b650, setHole call site; not exact here:
    # boost 1.34 slot construction shape, see NON_EXACT)
    '??$?0V?$bind_t@XV?$mf0@XVVelocityMotor@RBX@@@_mfi@boost@@V?$list1@V?$value@PAVVelocityMotor@RBX@@@_bi@boost@@@_bi@3@@_bi@boost@@@?$slot@V?$function@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@ZV?$allocator@X@std@@@boost@@@boost@@QAE@ABV?$bind_t@XV?$mf0@XVVelocityMotor@RBX@@@_mfi@boost@@V?$list1@V?$value@PAVVelocityMotor@RBX@@@_bi@boost@@@_bi@3@@_bi@1@@Z': 0x60b650,
    '??1?$slot@V?$function@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@ZV?$allocator@X@std@@@boost@@@boost@@QAE@XZ': 0x49f710,
    # property descriptors 0060ba00 / 0060b8c0
    '??0?$TypedPropertyDescriptor@M@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@M@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x445610,
    '??0PropertyDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@ABVType@12@PBD2W4Functionality@012@@Z': 0x56c650,
    '??0Type@Reflection@RBX@@IAE@PBDABVtype_info@@0@Z': 0x4897a0,   # RefType::singleton 0060a260 ("Object", "Ref")
    # Described<JointInstance>::classDescriptor (evidence name; the shared header's sJointInstance mangles 3PADA)
    '?classDescriptor@?$Described@VJointInstance@RBX@@$1?sJointInstance@2@3PADAV?$NonFactoryProduct@VInstance@RBX@@$1?sJointInstance@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x5c08d0,
    '?classDescriptor@?$Described@VJointInstance@RBX@@$1?sJointInstance@2@3QBDBV?$NonFactoryProduct@VInstance@RBX@@$1?sJointInstance@2@3QBDB@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x5c08d0,
}
for _e in ('TopBottom', 'LeftRight', 'InOut'):
    _tree = '?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4%s@Feature@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4%s@Feature@2@@std@@@6@$0A@@std@@@std@@' % (_e, _e)
    EXTERNAL['?addPair@?$EnumDesc@W4%s@Feature@RBX@@@Reflection@RBX@@AAEXW4%s@Feature@3@PBD@Z' % (_e, _e)] = 0x64d530
    EXTERNAL['??0' + _tree + 'QAE@ABU?$less@PBVName@RBX@@@1@ABV?$allocator@U?$pair@QBVName@RBX@@W4%s@Feature@2@@std@@@1@@Z' % _e] = 0x446110
    EXTERNAL['??1' + _tree + 'QAE@XZ'] = 0x553d80
# Descriptor objects: the `this` the dynamic initializers 007f7bc0..007f7c80 pass; char arrays pushed by doDeclare.
DATA = {
    '_prop_FaceId': 0x97be5c, '_prop_TopBottom': 0x97bdd8, '_prop_LeftRight': 0x97bdb4, '_prop_InOut': 0x97be38,
    '?prop_FaceId@RBX@@3V?$EnumPropDescriptor@VFeature@RBX@@W4NormalId@2@@Reflection@2@A': 0x97be5c,
    '?prop_TopBottom@RBX@@3V?$EnumPropDescriptor@VFeature@RBX@@W4TopBottom@12@@Reflection@2@A': 0x97bdd8,
    '?prop_LeftRight@RBX@@3V?$EnumPropDescriptor@VFeature@RBX@@W4LeftRight@12@@Reflection@2@A': 0x97bdb4,
    '?prop_InOut@RBX@@3V?$EnumPropDescriptor@VFeature@RBX@@W4InOut@12@@Reflection@2@A': 0x97be38,
    '?sFeature@RBX@@3QBDB': 0x842998, '?sHole@RBX@@3QBDB': 0x8429a0, '?sMotorFeature@RBX@@3QBDB': 0x8429a8,
    '?sVelocityMotor@RBX@@3QBDB': 0x8429b8,
    # VelocityMotor descriptors: `this` of the dynamic initializers 007f7ac0..007f7b80
    '_prop_Hole': 0x97bdfc, '_prop_MaxVelocity': 0x97be1c, '_prop_DesiredAngle': 0x97be9c, '_prop_CurrentAngle': 0x97be80,
    '?prop_Hole@RBX@@3V?$RefPropDescriptor@VVelocityMotor@RBX@@VHole@2@@Reflection@2@A': 0x97bdfc,
    '?prop_MaxVelocity@RBX@@3V?$PropDescriptor@VVelocityMotor@RBX@@M@Reflection@2@A': 0x97be1c,
    '?prop_DesiredAngle@RBX@@3V?$PropDescriptor@VVelocityMotor@RBX@@M@Reflection@2@A': 0x97be9c,
    '?prop_CurrentAngle@RBX@@3V?$PropDescriptor@VVelocityMotor@RBX@@M@Reflection@2@A': 0x97be80,
    # the 2008 event_ancestryChanged SignalDesc (setHole 0060c400: mov ecx, 0097... before connect 004a3340)
    '?type@?1???$singleton@PAVVelocityMotor@RBX@@@RefType@Reflection@RBX@@SAABV123@XZ@4V123@A': 0x97b9f8,  # 0060a260
    '?event_ancestryChanged@Instance@RBX@@2V?$SignalDesc@VInstance@RBX@@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@Z@Reflection@2@A': 0x973c38,
}
# ICF / trivial-wrapper folds: the original keeps one body where this unit emits several identical ones.
FOLDED = {
    # boost::function manager for the setHole bind_t: the function_obj_tag overload is ICF-folded into the
    # bool_<true> one (0060aac0 calls 0060a300)
    '?manager@?$functor_manager@V?$bind_t@XV?$mf0@XVVelocityMotor@RBX@@@_mfi@boost@@V?$list1@V?$value@PAVVelocityMotor@RBX@@@_bi@boost@@@_bi@3@@_bi@boost@@V?$allocator@X@std@@@function@detail@boost@@CAXABTfunction_buffer@234@AAT5234@W4functor_manager_operation_type@234@Ufunction_obj_tag@234@@Z': 0x60a300,
}

FPH = '?$FactoryProduct@VHole@RBX@@VFeature@2@$1?sHole@2@3QBDB@RBX@@'
FPM = '?$FactoryProduct@VMotorFeature@RBX@@VFeature@2@$1?sMotorFeature@2@3QBDB@RBX@@'
DCH = '?$DescribedCreatable@VHole@RBX@@VFeature@2@$1?sHole@2@3QBDB@RBX@@'
DCM = '?$DescribedCreatable@VMotorFeature@RBX@@VFeature@2@$1?sMotorFeature@2@3QBDB@RBX@@'
DNC = '?$DescribedNonCreatable@VFeature@RBX@@VInstance@2@$1?sFeature@2@3QBDB@RBX@@'
FPV = '?$FactoryProduct@VVelocityMotor@RBX@@VJointInstance@2@$1?sVelocityMotor@2@3QBDB@RBX@@'
DCV = '?$DescribedCreatable@VVelocityMotor@RBX@@VJointInstance@2@$1?sVelocityMotor@2@3QBDB@RBX@@'
DSV = '?$Described@VVelocityMotor@RBX@@$1?sVelocityMotor@2@3QBDBV' + FPV[:-6] + '@2@@Reflection@RBX@@'
NFP = '?$NonFactoryProduct@VInstance@RBX@@$1?sFeature@2@3QBDB@RBX@@'
DSF = '?$Described@VFeature@RBX@@$1?sFeature@2@3QBDBV' + NFP[:-6] + '@2@@Reflection@RBX@@'
DSH = '?$Described@VHole@RBX@@$1?sHole@2@3QBDBV' + FPH[:-6] + '@2@@Reflection@RBX@@'
DSM = '?$Described@VMotorFeature@RBX@@$1?sMotorFeature@2@3QBDBV' + FPM[:-6] + '@2@@Reflection@RBX@@'
EDT = '?$EnumDesc@W4TopBottom@Feature@RBX@@@Reflection@RBX@@'
EDL = '?$EnumDesc@W4LeftRight@Feature@RBX@@@Reflection@RBX@@'
EDI = '?$EnumDesc@W4InOut@Feature@RBX@@@Reflection@RBX@@'
TREE = '?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4%s@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4%s@@std@@@6@$0A@@std@@@std@@'
PD = '@?$PropDescriptor@VFeature@RBX@@W4%s@@Reflection@RBX@@SA?AV?$auto_ptr'

# (address, symbol or unique symbol prefix)
ROWS = [
    (0x609a60, '?canJoin@MotorFeature@RBX@@SA_NPAVInstance@2@0@Z'),
    (0x609a30, '?getFaceId@Feature@RBX@@QBE?AW4NormalId@2@XZ'),
    (0x4a1560, '?getTopBottom@Feature@RBX@@QBE?AW4TopBottom@12@XZ'),      # ICF-shared getter
    (0x609a40, '?getLeftRight@Feature@RBX@@QBE?AW4LeftRight@12@XZ'),
    (0x609a50, '?getInOut@Feature@RBX@@QBE?AW4InOut@12@XZ'),
    (0x609b50, '??0' + NFP + 'QAE@XZ'),
    (0x609c60, '??$doDeclare@$1?sFeature@RBX@@3QBDB@Name@RBX@@CAABV01@XZ'),
    (0x60a2e0, '??$callDoDeclare@$1?sFeature@RBX@@3QBDB@Name@RBX@@CAXXZ'),
    (0x60a2f0, '?shouldRender2d@IRenderable@RBX@@MBE_NXZ'),
    (0x60a360, '??1Feature@RBX@@UAE@XZ'),
    (0x60a410, '??_EFeature@RBX@@WCE@AEPAXI@Z'), (0x60a420, '??_EFeature@RBX@@WEE@AEPAXI@Z'),
    (0x60a430, '??_EFeature@RBX@@WGE@AEPAXI@Z'), (0x60a440, '??_EFeature@RBX@@WIE@AEPAXI@Z'),
    (0x60a450, '??_EFeature@RBX@@WKE@AEPAXI@Z'), (0x60a460, '??_EFeature@RBX@@WME@AEPAXI@Z'),
    (0x60a470, '??_EFeature@RBX@@WBA@AEPAXI@Z'), (0x60a480, '??_EFeature@RBX@@WBE@AEPAXI@Z'),
    (0x60a520, '?render3dSelect@Feature@RBX@@EAEXPAVAdorn@2@W4SelectState@2@@Z'),
    (0x60a580, '?render3dAdorn@Hole@RBX@@EAEXPAVAdorn@2@@Z'),
    (0x60a5e0, '?render3dAdorn@MotorFeature@RBX@@EAEXPAVAdorn@2@@Z'),
    (0x60a7c0, '??1' + FPM + 'MAE@XZ'),
    (0x60a820, '??_EMotorFeature@RBX@@WME@AEPAXI@Z'), (0x60a830, '??_EMotorFeature@RBX@@WIE@AEPAXI@Z'),
    (0x60a840, '??1' + FPH + 'MAE@XZ'),
    (0x60a8a0, '??_EHole@RBX@@WKE@AEPAXI@Z'), (0x60a8b0, '??_EHole@RBX@@WME@AEPAXI@Z'),
    (0x60a8c0, '??_EHole@RBX@@WCE@AEPAXI@Z'), (0x60a8d0, '??_EHole@RBX@@WEE@AEPAXI@Z'),
    (0x60a980, '??$getset@P8Feature@RBX@@BE?AW4NormalId@'),
    (0x60a9d0, '??$getset@P8Feature@RBX@@BE?AW4TopBottom@'),
    (0x60aa20, '??$getset@P8Feature@RBX@@BE?AW4LeftRight@'),
    (0x60aa70, '??$getset@P8Feature@RBX@@BE?AW4InOut@'),
    (0x60ab00, '??_GFeature@RBX@@UAEPAXI@Z'),
    (0x60ab40, '??1Hole@RBX@@UAE@XZ'),
    (0x60ab50, '??1MotorFeature@RBX@@UAE@XZ'),
    (0x60ab60, '?getClassName@' + NFP + 'UBEABVName@2@XZ'),
    (0x60ab80, '?getClassName@' + FPM + 'UBEABVName@2@XZ'),
    (0x60aba0, '?getClassName@' + FPH + 'UBEABVName@2@XZ'),
    (0x60acc0, '??1' + EDT + 'EAE@XZ'), (0x60ae50, '??1' + EDL + 'EAE@XZ'), (0x60afe0, '??1' + EDI + 'EAE@XZ'),
    (0x60b170, '??_G' + EDT + 'EAEPAXI@Z'), (0x60b190, '??_G' + EDL + 'EAEPAXI@Z'), (0x60b1b0, '??_G' + EDI + 'EAEPAXI@Z'),
    (0x60b1d0, '??0' + EDT + 'AAE@XZ'), (0x60b350, '??0' + EDL + 'AAE@XZ'), (0x60b4d0, '??0' + EDI + 'AAE@XZ'),
    (0x60b770, '?singleton@' + EDT + 'SAABV123@XZ'), (0x60b7e0, '?singleton@' + EDL + 'SAABV123@XZ'),
    (0x60b850, '?singleton@' + EDI + 'SAABV123@XZ'),
    (0x60bce0, '??0' + DNC + 'IAE@XZ'),
    (0x60be60, '??0Feature@RBX@@QAE@XZ'),
    (0x60bf60, '??0' + FPM + 'IAE@XZ'),
    (0x60bfd0, '??0' + FPH + 'IAE@XZ'),
    (0x60c340, '?setFaceId@Feature@RBX@@QAEXW4NormalId@2@@Z'),
    (0x60c370, '?setTopBottom@Feature@RBX@@QAEXW4TopBottom@12@@Z'),
    (0x60c3a0, '?setLeftRight@Feature@RBX@@QAEXW4LeftRight@12@@Z'),
    (0x60c3d0, '?setInOut@Feature@RBX@@QAEXW4InOut@12@@Z'),
    (0x60c640, '??0' + DCM + 'IAE@XZ'),
    (0x60c6e0, '??_EMotorFeature@RBX@@WBA@AEPAXI@Z'), (0x60c6f0, '??_EMotorFeature@RBX@@WEE@AEPAXI@Z'),
    (0x60c700, '??_EMotorFeature@RBX@@WGE@AEPAXI@Z'), (0x60c710, '??_EMotorFeature@RBX@@WKE@AEPAXI@Z'),
    (0x60c720, '??_G' + FPM + 'MAEPAXI@Z'),
    (0x60c740, '??0' + DCH + 'IAE@XZ'),
    (0x60c7e0, '??_EHole@RBX@@WBE@AEPAXI@Z'), (0x60c7f0, '??_EHole@RBX@@WGE@AEPAXI@Z'),
    (0x60c800, '??_EHole@RBX@@WIE@AEPAXI@Z'), (0x60c810, '??_EHole@RBX@@WBA@AEPAXI@Z'),
    (0x60c820, '??_G' + FPH + 'MAEPAXI@Z'),
    (0x60c840, '??0Hole@RBX@@QAE@XZ'),
    (0x60c910, '??0MotorFeature@RBX@@QAE@XZ'),
    (0x60c9e0, '??_EMotorFeature@RBX@@WCE@AEPAXI@Z'), (0x60c9f0, '??_EMotorFeature@RBX@@WBE@AEPAXI@Z'),
    (0x60ca00, '?join@MotorFeature@RBX@@SAXPAVInstance@2@0@Z'),
    # VelocityMotor rows whose bytes and targets do not depend on the JointInstance layout
    (0x60ab20, '??_GVelocityMotor@RBX@@UAEPAXI@Z'),
    (0x609d50, '??_G' + FPV + 'MAEPAXI@Z'),
    (0x609d50, '??_G' + DCV + 'UAEPAXI@Z'),                # ICF: DescribedCreatable<VelocityMotor> vtables hold 00609d50.. too
    (0x60a640, '??1' + DCV + 'UAE@XZ'),                       # jmp ~FactoryProduct (ICF with ~Described)
    (0x60a640, '??1' + DSV + 'UAE@XZ'),
    (0x60abc0, '?getClassName@' + FPV + 'UBEABVName@2@XZ'),
    (0x57d750, '??$doDeclare@$1?sVelocityMotor@RBX@@3QBDB@Name@RBX@@CAABV01@XZ'),
    (0x57dd90, '??$callDoDeclare@$1?sVelocityMotor@RBX@@3QBDB@Name@RBX@@CAXXZ'),
    (0x60b700, '?classDescriptor@' + DSV + 'SAAAVClassDescriptor@23@XZ'),
    (0x8002d0, '??__Ffoo@?1??classDescriptor@' + DSV),
    (0x60a260, '??$singleton@PAVVelocityMotor@RBX@@@RefType@Reflection@RBX@@SAABV012@XZ'),
    (0x8001c0, '??__Ftype@?1???$singleton@PAVVelocityMotor@RBX@@@RefType@'),
    (0x60a8e0, '??$getset@P8VelocityMotor@RBX@@BEPAVHole@'),
    (0x60a930, '??$getset@P8VelocityMotor@RBX@@BEMXZ'),
    (0x60ba00, '??$?0P8VelocityMotor@RBX@@BEMXZP801@AEXM@Z@?$PropDescriptor@VVelocityMotor@RBX@@M@Reflection@RBX@@QAE@'),
    (0x7f7ac0, '??__Eprop_Hole@RBX@@YAXXZ'),
    (0x7f7b00, '??__Eprop_MaxVelocity@RBX@@YAXXZ'),
    (0x7f7b40, '??__Eprop_DesiredAngle@RBX@@YAXXZ'),
    (0x7f7b80, '??__Eprop_CurrentAngle@RBX@@YAXXZ'),
    (0x8001d0, '??__Fprop_Hole@RBX@@YAXXZ'),
    (0x8002b0, '??__Fprop_MaxVelocity@RBX@@YAXXZ'),
    (0x800290, '??__Fprop_DesiredAngle@RBX@@YAXXZ'),
    (0x8001f0, '??__Fprop_CurrentAngle@RBX@@YAXXZ'),
    (0x7f7bc0, '??__Eprop_FaceId@RBX@@YAXXZ'),
    (0x7f7c00, '??__Eprop_TopBottom@RBX@@YAXXZ'),
    (0x7f7c40, '??__Eprop_LeftRight@RBX@@YAXXZ'),
    (0x7f7c80, '??__Eprop_InOut@RBX@@YAXXZ'),
    (0x800210, '??__Fprop_InOut@RBX@@YAXXZ'),
    (0x800230, '??__Fprop_LeftRight@RBX@@YAXXZ'),
    (0x800250, '??__Fprop_TopBottom@RBX@@YAXXZ'),
    (0x800270, '??__Fprop_FaceId@RBX@@YAXXZ'),
    (0x8002e0, '??__Fs@?1??singleton@' + EDI),
    (0x8002f0, '??__Fs@?1??singleton@' + EDL),
    (0x800300, '??__Fs@?1??singleton@' + EDT),
    # template instances / virtual defaults whose original bodies live outside the unit (COMDAT / ICF-shared)
    (0x5c0940, '?classDescriptor@' + DSF + 'SAAAVClassDescriptor@23@XZ'),
    (0x5c37a0, '?classDescriptor@' + DSH + 'SAAAVClassDescriptor@23@XZ'),
    (0x5c3730, '?classDescriptor@' + DSM + 'SAAAVClassDescriptor@23@XZ'),
    (0x7fe870, '??__Ffoo@?1??classDescriptor@' + DSF),
    (0x7fe760, '??__Ffoo@?1??classDescriptor@' + DSH),
    (0x7fe770, '??__Ffoo@?1??classDescriptor@' + DSM),
    (0x57d6e0, '??$doDeclare@$1?sHole@RBX@@3QBDB@Name@RBX@@CAABV01@XZ'),
    (0x57d670, '??$doDeclare@$1?sMotorFeature@RBX@@3QBDB@Name@RBX@@CAABV01@XZ'),
    (0x57dd80, '??$callDoDeclare@$1?sHole@RBX@@3QBDB@Name@RBX@@CAXXZ'),
    (0x57dd70, '??$callDoDeclare@$1?sMotorFeature@RBX@@3QBDB@Name@RBX@@CAXXZ'),
    (0x565ff0, '?askSetParent@Feature@RBX@@EBE_NPBVInstance@2@@Z'),
    (0x565ff0, '?askSetParent@VelocityMotor@RBX@@EBE_NPBVInstance@2@@Z'),
    (0x565950, '?shouldRender3dAdorn@Feature@RBX@@EBE_NXZ'),
    (0x7286a0, '?getCoordOrientation@Feature@RBX@@MBE?AW4InOutZ@12@XZ'),
    (0x416690, '?getCoordOrientation@Hole@RBX@@EBE?AW4InOutZ@Feature@2@XZ'),
    (0x70bdf0, '?render3dAdorn@IRenderable@RBX@@UAEXPAVAdorn@2@@Z'),
    (0x70bdf0, '?render2d@IRenderable@RBX@@UAEXPAVAdorn@2@@Z'),
    (0x458e90, '?render3dSelect@IRenderable@RBX@@UAEXPAVAdorn@2@W4SelectState@2@@Z'),   # ICF `ret 8` (JointInstance)
    # deleting destructors ICF-shared with the FactoryProduct ones (vtable slots and thunks use 0060c820/0060c720)
    (0x60c820, '??_GHole@RBX@@UAEPAXI@Z'),
    (0x60c720, '??_GMotorFeature@RBX@@UAEPAXI@Z'),
]
# Base-class deleting destructors and adjustor thunks: identical bodies ICF-folded into the leaf ones (the
# original FactoryProduct/DescribedCreatable/DescribedNonCreatable vtables hold the same addresses).
THUNKS = {
    'Feature': {'CE': 0x60a410, 'EE': 0x60a420, 'GE': 0x60a430, 'IE': 0x60a440, 'KE': 0x60a450, 'ME': 0x60a460,
                'BA': 0x60a470, 'BE': 0x60a480},
    'Hole': {'KE': 0x60a8a0, 'ME': 0x60a8b0, 'CE': 0x60a8c0, 'EE': 0x60a8d0, 'BE': 0x60c7e0, 'GE': 0x60c7f0,
             'IE': 0x60c800, 'BA': 0x60c810},
    'MotorFeature': {'ME': 0x60a820, 'IE': 0x60a830, 'BA': 0x60c6e0, 'EE': 0x60c6f0, 'GE': 0x60c700, 'KE': 0x60c710,
                     'CE': 0x60c9e0, 'BE': 0x60c9f0},
    # VelocityMotor (jmp 0060ab20) and its FactoryProduct base (jmp 00609d50)
    'VelocityMotor': {'CE': 0x60a740, 'EE': 0x60a750, 'GE': 0x60a760, 'IE': 0x60a770, 'KE': 0x60a780, 'ME': 0x60a790,
                      'BA': 0x60a7a0, 'BE': 0x60a7b0},
    'FactoryProductVelocityMotor': {'BA': 0x609d40, 'BE': 0x609d70, 'CE': 0x609d80, 'IE': 0x60bb60, 'KE': 0x60bb70,
                                    'ME': 0x60bb80, 'EE': 0x60bb90, 'GE': 0x60bba0},
    # DescribedNonCreatable<Feature>/NonFactoryProduct<Instance, sFeature> destroy only the Instance part: their
    # deleting dtor and thunks are the ICF-shared Instance-only ones (vtables 00843118..00843194 / 00842aa8..00842b24)
    'Instance': {'BA': 0x455f30, 'BE': 0x409d40, 'CE': 0x5e28b0, 'EE': 0x609d90, 'GE': 0x4c9c40, 'IE': 0x458580,
                 'KE': 0x45ebd0, 'ME': 0x455f20},
}
ROWS += [(0x455f00, '??_G' + DNC + 'UAEPAXI@Z'), (0x455f00, '??_G' + NFP + 'UAEPAXI@Z'),
         (0x60c820, '??_G' + DCH + 'UAEPAXI@Z'), (0x60c720, '??_G' + DCM + 'UAEPAXI@Z')]
for family, bases in (('Instance', ((DNC, 'W'), (NFP, 'W'))), ('Hole', ((DCH, 'W'), (FPH, 'O'))),
                      ('MotorFeature', ((DCM, 'W'), (FPM, 'O'))), ('VelocityMotor', (('VelocityMotor@RBX@@', 'W'),)),
                      ('FactoryProductVelocityMotor', ((FPV, 'O'), (DCV, 'W')))):
    for base, kind in bases:
        for adj, address in sorted(THUNKS[family].items(), key=lambda x: x[1]):
            ROWS.append((address, '??_E' + base + kind + adj + '@AEPAXI@Z'))
# Exact only against the generated 2008 headers (see the module docstring); recorded exact=false.
# Former pending rows that compile exact against the current headers (Feature.cpp explicitly instantiates the
# setHole slot so the boost::function rows are emitted without the pending setHole; the RefPropDescriptor
# constructor needs the adopted IIDREF novtable).
ROWS += [
    (0x60b8c0, '??$?0P8VelocityMotor@RBX@@BEPAVHole@1@XZP801@AEXPAV21@@Z@?$RefPropDescriptor@VVelocityMotor@RBX@@VHole@2@@Reflection@RBX@@QAE@'),
    (0x60a300, '?manager@?$functor_manager@V?$bind_t@XV?$mf0@XVVelocityMotor@RBX@@@_mfi@boost@@V?$list1@V?$value@PAVVelocityMotor@RBX@@@_bi@boost@@@_bi@3@@_bi@boost@@V?$allocator@X@std@@@function@detail@boost@@CAXABTfunction_buffer@234@AAT5234@W4functor_manager_operation_type@234@U?$bool_@$00@mpl@4@@Z'),
    (0x60aac0, '?manage@?$functor_manager@V?$bind_t@XV?$mf0@XVVelocityMotor@'),
    (0x60abe0, '?invoke@?$void_function_obj_invoker1@V?$bind_t@XV?$mf0@XVVelocityMotor@'),
]
PENDING_ROWS = [
    # 00609af0 / 00609cd0 / 0060bab0: bytes and relocation targets exact in the main build too, but the
    # FactoryProduct/DescribedCreatable<VelocityMotor> vtables they store get Instance slots 3/4 from the current
    # JointInstance.h (original 005e3790 askSetParent / 005e3a80 onAncestorChanged): not counted until it declares them.
    (0x609af0, '??1' + FPV + 'MAE@XZ'),
    (0x609cd0, '??$?0PAVMotorJoint@RBX@@@' + FPV + 'IAE@PAVMotorJoint@1@@Z'),
    (0x60bab0, '??$?0PAVMotorJoint@RBX@@@' + DCV + 'IAE@PAVMotorJoint@1@@Z'),
    (0x60bbb0, '??0VelocityMotor@RBX@@QAE@XZ'),
    (0x60a650, '??1VelocityMotor@RBX@@UAE@XZ'),
    (0x60a020, '?setPart@VelocityMotor@RBX@@AAEXHPAVFeature@2@@Z'),
    (0x60a0f0, '?onAncestorChanged@VelocityMotor@RBX@@EAEXABUAncestorChanged@2@@Z'),
    (0x60a230, '?onEvent_HoleAncestorChanged@VelocityMotor@RBX@@AAEXXZ'),
    (0x60c400, '?setHole@VelocityMotor@RBX@@QAEXPAVHole@2@@Z'),
    (0x5b0820, '?getHole@VelocityMotor@RBX@@QBEPAVHole@2@XZ'),     # ICF-shared getter
    (0x60a240, '?getMaxVelocity@VelocityMotor@RBX@@QBEMXZ'),
    (0x60a250, '?getDesiredAngle@VelocityMotor@RBX@@QBEMXZ'),
    (0x5e2900, '?getCurrentAngle@VelocityMotor@RBX@@QBEMXZ'),      # ICF-shared getter
    (0x60c580, '?setMaxVelocity@VelocityMotor@RBX@@QAEXM@Z'),
    (0x60c5c0, '?setDesiredAngle@VelocityMotor@RBX@@QAEXM@Z'),
    (0x60c600, '?setCurrentAngle@VelocityMotor@RBX@@QAEXM@Z'),
]
# Original rows of the Feature/Hole/MotorFeature half that are not exact here (reason in the receipt).
NON_EXACT = {
    '00609da0': 'Feature::computeLocalCoordinateFrame: reads the part Primitive geometry through PartInstance '
                '+0x2c4 (embedded Primitive at +0x228, see part-embedded-primitive-evidence.json) and grid size at '
                'geometry +4; the shared native PartInstance.h (scoped_ptr primitive) and donor Primitive.h do not '
                'have that layout. Not attempted; declaration kept.',
    '0060a490': 'Feature::getRenderCoord: same instructions and targets, but the original allocates ecx/edx/eax '
                'where this unit allocates eax/ecx/edx for the computeLocalCoordinateFrame / operator* temporaries '
                '(131 bytes both; /fp:fast, VS2005 50727 and eight source spellings tried).',
    '0060bd80': 'EnumPropDescriptor<Feature, NormalId> constructor: the 2008 reflection.h constructor fetches '
                'EnumDesc<E>::singleton() through boost::call_once twice and stores it at +0x18 and +0x20 '
                '(PROPOSAL_REFLECTION); the shared native reflection.h has neither.',
    '0060c040': 'EnumPropDescriptor<Feature, TopBottom> constructor: as 0060bd80 (call_once 0060b7d0, flag 0097bda4).',
    '0060c180': 'EnumPropDescriptor<Feature, LeftRight> constructor: as 0060bd80 (call_once 0060b840).',
    '0060c260': 'EnumPropDescriptor<Feature, InOut> constructor: as 0060bd80 (call_once 0060b8b0, flag 0097bdac).',
    '0060b7d0': 'call_once wrapper of EnumDesc<TopBottom>::singleton (jmp 0060b770): only emitted by the 2008 '
                'EnumPropDescriptor constructor shape (PROPOSAL_REFLECTION).',
    '0060b840': 'call_once wrapper of EnumDesc<LeftRight>::singleton (jmp 0060b7e0), as 0060b7d0.',
    '0060b8b0': 'call_once wrapper of EnumDesc<InOut>::singleton (jmp 0060b850), as 0060b7d0.',
    '0060c120': 'EnumPropDescriptor<Feature, NormalId> virtual (string -> Name::lookup -> EnumDesc at +0x20 -> '
                'getset slot 3): depends on the 2008 +0x20 EnumDesc member (PROPOSAL_REFLECTION).',
    '0060b650': 'boost::slot<function<void(shared_ptr<Instance>)>> constructor from the setHole bind_t: 172 bytes '
                'against 170 here (boost slot/function construction shape of the 2008 boost build; not attempted).',
    '0060ac60': 'boost::function1 constructor from the setHole bind_t (84 bytes, calls 0060a2f0): this boost version '
                'emits a 54-byte body; not attempted.',
    '0060b970': 'RefPropDescriptor<VelocityMotor, Hole> helper (dynamic_cast to Hole, bad_cast on failure) used by its '
                'setRefValue: the shared reflection.h declares the RefPropDescriptor virtuals without bodies.',
    '0060b9c0': 'RefPropDescriptor<VelocityMotor, Hole>::setRefValue: as 0060b970.',
}
PROPOSAL_JOINT_INSTANCE = (
    'native-headers/v8datamodel/JointInstance.h (JointInstance owner, not edited): the 2008 class is '
    '`extern const char sJointInstance[]` (RTTI $1?sJointInstance@2@3QBDB) with `boost::weak_ptr<PartInstance> part[2]` '
    'at +0x140 and `Joint* joint` at +0x150 (constructor 005e3870, destructor 005e2e10), size 0x154, and it overrides '
    'askSetParent (005e3790) and onAncestorChanged (005e3a80). tests/NativeFeaturePendingJointInstance.h is that '
    'declaration. The shared header puts joint at +0x140 (size 0x144) and lacks both overrides. With it, the VelocityMotor '
    'constructor/destructor/FactoryProduct rows become main-build exact, and the FactoryProduct/Described vtables pass.')
PROPOSAL_REFLECTION = (
    'native-headers/reflection/reflection.h EnumPropDescriptor (shared, not edited): the 2008 constructor '
    '(0060bd80/0060c040/0060c180/0060c260) is call_once(&callSingleton<E>, flag); PropertyDescriptor(classDescriptor(), '
    'EnumDesc<E>::singleton(), name, category, flags) (0056c650); this->enumDescriptor(+0x18) = &singleton; vtable; '
    'getset(+0x1c) = getset(get, set); then call_once again and a typed `const EnumDesc<E>& enumDesc` member at +0x20 '
    '= singleton(). callSingleton<E> is a one-instruction `jmp EnumDesc<E>::singleton` (0060b7d0/0060b840/0060b8b0).')

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


def classify(symbol, value, own, raw, sections, definitions, where):
    """Return how a relocation target bound to `value` is verified, or None when unknown."""
    hit = original.imported(value)
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
        # vector deleting dtor reference: no array new of the class, so ??_E resolves to ??_G
        assert own['??_G' + symbol[4:]] == value, (where, symbol, hex(value))
        return 'own row (??_G)'
    if symbol in FOLDED:
        assert FOLDED[symbol] == value, (where, symbol, hex(value))
        return 'folded'
    if symbol in DATA:
        assert DATA[symbol] == value, (where, symbol, hex(value))
        return 'data'
    if symbol in EXTERNAL:
        if EXTERNAL[symbol] is None:
            EXTERNAL[symbol] = value
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
for row in pend_out:  # exact only under NATIVE_FEATURE_PENDING with the overlay: not counted as exact
    row['exact'] = False
    row['exact_pending_build_only'] = True
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- vtables of the main build, slot by slot against the original vtable each one binds to -----------
# Instance's own vtables by subobject offset (Instance constructor 0055b7e0 / destructor 0055a540 store them):
# an inherited slot must hold the same address as the Instance vtable of the same subobject.
INSTANCE_VTABLES = {0x0: 0x82d884, 0x10: 0x82d878, 0x14: 0x82d870, 0x20: 0x82d868, 0x24: 0x82d858, 0x44: 0x82d848,
                    0x64: 0x82d838, 0x84: 0x82d828, 0xa4: 0x82d818, 0xc4: 0x82d808}
for at, vt in INSTANCE_VTABLES.items():
    assert original.vtable_class(vt) == ('.?AVInstance@RBX@@', at), (hex(vt), original.vtable_class(vt))
CLASSES = ('Feature@RBX@@', 'Hole@RBX@@', 'MotorFeature@RBX@@', 'VelocityMotor@RBX@@', FPH, FPM, FPV, DCH, DCM, DCV,
           DSV, DNC)
# vtables a counted (main) row references: strict. Vtables bound only by pending rows: compared the same way on the
# main build object, mismatching slots reported (the rows that store them are not counted anyway).
main_vtables = {k for r in main_out for k in r['verified_targets'] if k.startswith('??_7')}
raw = main_obj.read_bytes()
sections, symbols, definitions, starts = match._coff_data_index(raw)
vtables, pending_vtable_mismatches = {}, {}
for symbol, (value, sec) in definitions.items():
    if not symbol.startswith('??_7') or symbol not in binding:
        continue
    if not any(symbol[4:].startswith(c + '6B') for c in CLASSES):
        continue
    strict = symbol in main_vtables
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
                and not any(c in sym for c in ('Feature@RBX@@', 'Hole@RBX@@')):
            # a virtual of Instance or one of its bases (Notifier, GuidItem, Debugable, Described<Instance>)
            how = 'inherited (Instance vtable %#x slot %d)' % (INSTANCE_VTABLES[at], slot)
        if how is None or (not strict and sym in binding and binding[sym][0] != value_orig):
            if strict:
                UNBOUND.append('vtable %s slot %d %s -> %s' % (symbol, slot, sym, hex(value_orig)))
            else:
                pending_vtable_mismatches.setdefault(symbol, {})[slot] = '%s (current headers) vs original %s' % (
                    sym, hex(value_orig))
            continue
        prev = binding.setdefault(sym, (value_orig, symbol))
        assert prev[0] == value_orig, ('inconsistent', sym, hex(prev[0]), prev[1], hex(value_orig), symbol)
        checked[slot] = '%s = %s (%s)' % (sym, hex(value_orig), how)
    vtables[symbol] = {'address': hex(vt), 'rtti': rtti, 'offset': hex(at), 'slots': checked,
                       'checked_for': 'counted rows' if strict else 'pending rows only'}
assert not UNBOUND, '\n'.join(UNBOUND)
for vt, rtti in ((0x842c74, '.?AVFeature@RBX@@'), (0x84356c, '.?AVHole@RBX@@'), (0x843654, '.?AVMotorFeature@RBX@@'),
                  (0x842d54, '.?AVVelocityMotor@RBX@@')):
    assert original.vtable_class(vt) == (rtti, 0), (hex(vt), rtti)
    assert any(v['address'] == hex(vt) for v in vtables.values()), (hex(vt), 'main vtable not checked')
# Every mismatch in a pending-only vtable must be one the JointInstance.h proposal explains: an inherited
# JointInstance virtual (askSetParent 005e3790 / onAncestorChanged 005e3a80) the shared header does not declare.
for symbol, slots in pending_vtable_mismatches.items():
    for slot, text in slots.items():
        assert text.endswith(('0x5e3790', '0x5e3a80')) and 'Instance@RBX@@' in text, (symbol, slot, text)

# ---- allocation sizes, RTTI bases and strings -----------------------------------------------------------
for factory, size, ctor in ((0x580230, 0x150, 0x60c840), (0x57ffc0, 0x150, 0x60c910), (0x5804a0, 0x170, 0x60bbb0),
                           (0x60bbb0, 0x98, 0x5e5bf0)):   # create<VelocityMotor>; VelocityMotor() news MotorJoint
    body, _, _ = match.target('2008-06', '%08x' % factory)
    at = body.index(b'\x68' + struct.pack('<I', size))
    call = body.index(b'\xe8', at + 5)
    while (factory + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != ctor:
        call = body.index(b'\xe8', call + 1)
for address, text in ((0x842998, 'Feature'), (0x8429a0, 'Hole'), (0x8429a8, 'MotorFeature'), (0x8436a8, 'FaceId'),
                      (0x842f84, 'TopBottom'), (0x842f90, 'LeftRight'), (0x842fac, 'InOut'), (0x822490, 'Data'),
                      (0x8429b8, 'VelocityMotor'), (0x843104, 'VelocityMotor'), (0x8435b0, 'Hole'),
                      (0x83f6f0, 'MaxVelocity'), (0x83f6fc, 'DesiredAngle'), (0x83f70c, 'CurrentAngle')):
    assert original.string(address) == text, (hex(address), text)
locator = d(0x842c74 - 4)
hierarchy = d(locator + 16)
items = [d(d(hierarchy + 12) + 4 * i) for i in range(d(hierarchy + 8))]
bases = {original.string(d(item) + 8): struct.unpack('<i', original.data(item + 8, 4))[0] for item in items}
assert bases['.?AVIRenderable@RBX@@'] == 0x130, bases
assert '.?AV?$DescribedNonCreatable@VFeature@RBX@@VInstance@2@$1?sFeature@2@3QBDB@RBX@@' in bases, bases
locator = d(0x842d54 - 4)
hierarchy = d(locator + 16)
items = [d(d(hierarchy + 12) + 4 * i) for i in range(d(hierarchy + 8))]
vm_bases = {original.string(d(item) + 8): struct.unpack('<i', original.data(item + 8, 4))[0] for item in items}
assert vm_bases['.?AVIRenderable@RBX@@'] == 0x130 and vm_bases['.?AVIJointOwner@RBX@@'] == 0x140, vm_bases
assert '.?AV?$DescribedCreatable@VVelocityMotor@RBX@@VJointInstance@2@$1?sVelocityMotor@2@3QBDB@RBX@@' in vm_bases
assert '.?AV?$DescribedNonCreatable@VJointInstance@RBX@@VInstance@2@$1?sJointInstance@2@3QBDB@RBX@@' in vm_bases

exact = [r['address'] for r in main_out]
sha = nb.sha
paths = [Path(__file__).resolve(), HDR, SRC, LAYOUT, JI_OVERLAY, WS_OVERLAY]
receipt = {
    'class': 'RBX::Feature, RBX::Hole, RBX::MotorFeature, RBX::VelocityMotor', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'layout_pending': pend_layout_flags, 'main': main_flags, 'pending': pend_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'generated_pending_headers': {path: {'from': str(Path(src).relative_to(ROOT)).replace('\\', '/'),
                                         'sha256': sha(pending / path), 'proposal': why}
                                  for path, (src, _, _, why) in GENERATED.items()},
    'objects': {p.name: sha(p) for p in (layout_obj, pend_layout_obj, main_obj, pend_obj)},
    'layout': {'Feature': '0x150 (Hole/MotorFeature factories 00580230/0057ffc0 allocate 0x150); IRenderable +0x130; '
                          'faceId +0x140, topBottom +0x144, leftRight +0x148, inOut +0x14c',
               'Hole': '0x150, no fields', 'MotorFeature': '0x150, no fields',
               'VelocityMotor': '0x170 (create<VelocityMotor> 005804a0); IRenderable +0x130, IJointOwner +0x140, '
                                'joint +0x150 (JointInstance, 0x154), hole +0x154, holeAncestorChanged +0x15c. '
                                'Main build (shared JointInstance.h, %#x bytes): hole +%#x, size %#x; pending build: '
                                'the binary offsets.' % (main_layout['nativeJointInstanceSize'],
                                                          main_layout['nativeVelocityMotorHoleOffset'],
                                                          main_layout['nativeVelocityMotorSize'])},
    'methods': main_out,
    'exact_count': len(main_out), 'exact_unique_addresses': len(set(exact)),
    'pending_methods': pend_out,
    'pending_note': 'Rows exact only in the NATIVE_FEATURE_PENDING build against the generated headers '
                    '(generated_pending_headers, tests/NativeFeaturePendingJointInstance.h, '
                    'tests/NativeFeaturePendingWorkspace.h, native-headers/part-embedded); not counted as exact.',
    'non_exact': NON_EXACT,
    'proposal_reflection_h': PROPOSAL_REFLECTION,
    'proposal_joint_instance_h': PROPOSAL_JOINT_INSTANCE,
    'vtables': vtables,
    'pending_vtable_mismatches': pending_vtable_mismatches,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/feature-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Feature/Hole/MotorFeature/VelocityMotor: %d rows exact (%d unique addresses), %d pending-only '
      '(%d unique), %d non-exact, %d vtables checked' % (len(main_out), len(set(exact)), len(pend_out),
                                                         len({r['address'] for r in pend_out}), len(NON_EXACT),
                                                         len(vtables)))
