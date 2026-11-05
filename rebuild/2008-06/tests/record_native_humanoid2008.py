"""Verify the inactive native RBX::Humanoid recovery (2008-06), header native-headers/humanoid/Humanoid2008.h.

Builds (document-swap flags + /fp:fast /U_RELEASEASSERT, VS2008 RTM 21022):
  * tests/NativeHumanoid2008Layout.cpp   sizeof / base-offset probes (mov eax, imm32; ret) and compile-time field
                                         offset asserts;
  * native-classes/Humanoid2008.cpp      the original unit's bodies that do not need a complete PartInstance
                                         (constructor, destructor, descriptors, setters, virtual leaves);
  * native-classes/Humanoid2008Parts.cpp the bodies that need a complete PartInstance (limb getters, part setters,
                                         takeDamage, moveTo2, the Torso/LeftLeg/RightLeg/WalkToPart descriptors). The
                                         native PartInstance.h reaches the donor v8kernel/Connector.h, which cannot
                                         share a translation unit with v8kernel/Connector2008.h, so this unit selects
                                         the donor Connector (same Connector size; it defines no virtuals and no
                                         vtable of this unit is checked from it);
  * both units again with NATIVE_HUMANOID2008_PENDING against out/native-layouts/humanoid2008-pending/: a generated
    copy of the native v8datamodel/ModelInstance.h with the proposed member template findModifierOfType<T>, and
    tests/NativeHumanoid2008PendingWorkspace.h copied as v8datamodel/Workspace.h (declaration-only overlay: the donor
    Workspace.h fails with C2440 on &sWorkspace). Rows exact only in these builds are recorded exact=false
    (pending-build-only) and are not counted.

Every row must be relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, string literals by bytes, float
constants by bits, type descriptors and vtables by original RTTI names, own symbols by a row proven here,
descriptor statics and the class-name array by the DATA map (the `this` / operand the original initializers and
setters use), and the remaining externals by the EXTERNAL map (call sites read in the original disassembly). Rows
are the SEEDS plus their closure: a call/jump target, atexit function or vtable slot defined in the same object is
added as a row only when its compiled body is exact at the address the original uses. A symbol binds to one address
in every row. Each Humanoid / FactoryProduct / DescribedCreatable vtable of the main build (never the pending one) is
compared slot by slot with the original vtable it binds to. Writes work/2008-06/shared-layouts/humanoid2008-working.json.
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
HDR = R / 'native-headers/humanoid/Humanoid2008.h'
SRC = R / 'native-classes/Humanoid2008.cpp'
PARTS = R / 'native-classes/Humanoid2008Parts.cpp'
LAYOUT = R / 'tests/NativeHumanoid2008Layout.cpp'
# /fp:fast: setHealth 005dbe70 / setMaxHealth 005dbf10 compare with fcom on the loaded value (x87 order).
# /U_RELEASEASSERT: no RBXASSERT code in the unit (~Humanoid 005d7d20 has neither the donor RBXASSERT(!world) nor the
# ~KernelIndex assert on +0x134).
UNIT_FLAGS = ['/fp:fast', '/U_RELEASEASSERT']

PENDING = OUT / 'humanoid2008-pending'
(PENDING / 'v8datamodel').mkdir(parents=True, exist_ok=True)
# The native v8datamodel/Camera.h (char sCamera[]) now exists, so the Camera.h copy of the first pass is not needed;
# remove the one an earlier run of this recorder generated.
if (PENDING / 'v8datamodel/Camera.h').exists():
    (PENDING / 'v8datamodel/Camera.h').unlink()
# (1) native v8datamodel/ModelInstance.h (other owner): member template findModifierOfType<T>() walking the existing
#     `modifiers` vector (005d8690 = <Humanoid>; same proposal as record_native_appearance.py, 005d4460 = <Skin>).
MODEL_TEMPLATE = '''\t\ttemplate<class T> T* findModifierOfType() const   // proposal (005d4460 = <Skin>, 005d8690 = <Humanoid>)
\t\t{
\t\t\tstd::vector<IModelModifier*>::const_iterator end = modifiers.end();
\t\t\tfor (std::vector<IModelModifier*>::const_iterator iter = modifiers.begin(); iter != end; ++iter)
\t\t\t{
\t\t\t\tif (T* result = dynamic_cast<T*>(*iter))
\t\t\t\t\treturn result;
\t\t\t}
\t\t\treturn NULL;
\t\t}
'''
text = (R / 'native-headers/v8datamodel/ModelInstance.h').read_text()
anchor = '\t\tPartInstance* getPrimaryPartInternal() const;\n'
assert text.count(anchor) == 1
(PENDING / 'v8datamodel/ModelInstance.h').write_text(text.replace(anchor, MODEL_TEMPLATE + anchor))
# (2) v8datamodel/Workspace.h: declaration-only overlay (findWorkspace 005a3380, contextInWorkspace 005a33d0).
WORKSPACE_OVERLAY = R / 'tests/NativeHumanoid2008PendingWorkspace.h'
(PENDING / 'v8datamodel/Workspace.h').write_text(WORKSPACE_OVERLAY.read_text())
PENDING_FLAGS = ['/I' + str(PENDING), '/DNATIVE_HUMANOID2008_PENDING']


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeHumanoid2008Layout', LAYOUT)
main_obj, main_flags = build('NativeHumanoid2008', SRC, UNIT_FLAGS)
ENGINE_WORLD = ['/I' + str(R / 'native-headers/engine-world')]   # getContactManager 005d77b0: World +0x84
parts_obj, parts_flags = build('NativeHumanoid2008Parts', PARTS, UNIT_FLAGS + ENGINE_WORLD)
pend_obj, pend_flags = build('NativeHumanoid2008Pending', SRC, UNIT_FLAGS + PENDING_FLAGS)
pend_parts_obj, pend_parts_flags = build('NativeHumanoid2008PartsPending', PARTS, UNIT_FLAGS + PENDING_FLAGS + ENGINE_WORLD)

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
for prefix, value in (('?nativeHumanoid2008Size@@', 0x22c), ('?nativeHumanoid2008Connector@@', 0x130),
                      ('?nativeHumanoid2008Controllable@@', 0x138), ('?nativeHumanoid2008Renderable@@', 0x13c),
                      ('?nativeHumanoid2008CharacterSubject@@', 0x14c), ('?nativeHumanoid2008ModelModifier@@', 0x1a0),
                      ('?nativeHumanoid2008Listener@@', 0x1a4), ('?nativeHumanoid2008Instance@@', 0x130)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    # RefType::singleton<Humanoid*> function-local static, emitted once the merged native reflection.h instantiates
    # the singleton in this unit; read at the same relocation in singleton<Humanoid*> and its atexit ??__F destructor.
    '?type@?1???$singleton@PAVHumanoid@RBX@@@RefType@Reflection@RBX@@SAABV123@XZ@4V123@A': 0x975588,
    # Instance / reflection / signals runtime (evidence names where the evidence map has one)
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,                       # FactoryProduct ctor 005d7890 (evidence: IAE)
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                       # FactoryProduct dtor 005d77d0 tail jmp (evidence: MAE)
    '??1IRenderable@RBX@@QAE@XZ': 0x47d410,                    # ~Humanoid 005d7d20 on +0x13c
    '??0ICharacterSubject@RBX@@QAE@XZ': 0x641320,              # Humanoid() 005db280 on +0x14c, push 0
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,
    '?findFirstChildByName@Instance@RBX@@QBEPAV12@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x557950,
    '?findSignalInstance@SignalDescriptor@Reflection@RBX@@IBEPAVSignalInstance@23@PBVSignalSource@23@@Z': 0x56b620,
    '?removeIndex@RaiseRange@RBX@@QAEXI@Z': 0x420740,
    '??$create@VRunService@RBX@@@ServiceProvider@RBX@@QBEPAVRunService@1@XZ': 0x4530f0,   # onServiceProvider 005db600
    '?isProtected@ForceField@RBX@@SA_NPAVInstance@2@@Z': 0x62d3d0,   # takeDamage 005dbf40 (ForceField.h name)
    '?sInstance@RBX@@3QBDB': 0x82d6a0,                         # classDescriptor<Instance> (string checked below)
    '?v@?1??zero@Vector3@G3D@@SAABV23@XZ@4V23@A': 0x96f044,    # G3D::Vector3::zero() static, setWalkDirection 005dbf80
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,
    '??0ClassDescriptor@Reflection@RBX@@AAE@XZ': 0x570820,
    '??0SignalDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD@Z': 0x56bab0,
    '??0PropertyDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@ABVType@12@PBD2W4Functionality@012@@Z': 0x56c650,
    '??0FunctionDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBDW4Security@012@@Z': 0x595790,
    '??0Value@Reflection@RBX@@QAE@XZ': 0x594ac0,
    '?addArgument@SignatureDescriptor@Reflection@RBX@@QAEXABVName@3@ABVType@23@ABVValue@23@@Z': 0x594b40,
    '??$singleton@M@Type@Reflection@RBX@@SAABV012@XZ': 0x56cca0,
    '??$singleton@_N@Type@Reflection@RBX@@SAABV012@XZ': 0x56cc30,
    '??$singleton@X@Type@Reflection@RBX@@SAABV012@XZ': 0x594a50,
    '??$singleton@VVector3@G3D@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56ce60,
    '??$singleton@V?$shared_ptr@VInstance@RBX@@@boost@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56cae0,
    '?_Buynode@?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@IAEPAU_Node@?$_List_nod@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@2@PAU342@0ABUItem@SignatureDescriptor@Reflection@RBX@@@Z': 0x417f00,
    '??0call_notification@detail@signals@boost@@QAE@ABV?$shared_ptr@Vsignal_base_impl@detail@signals@boost@@@3@@Z': 0x56a760,
    '??1call_notification@detail@signals@boost@@QAE@XZ': 0x56a650,
    '?begin@named_slot_map@detail@signals@boost@@QAE?AVnamed_slot_map_iterator@234@XZ': 0x571380,
    '?end@named_slot_map@detail@signals@boost@@QAE?AVnamed_slot_map_iterator@234@XZ': 0x5713b0,
    '_atexit': 0x6a17af,
    '??$convert@M@Value@Reflection@RBX@@QAEAAMXZ': 0x56ed00,                    # TakeDamage execute 005daeb0
    '??$convert@V?$shared_ptr@VInstance@RBX@@@boost@@@Value@Reflection@RBX@@QAEAAV?$shared_ptr@VInstance@RBX@@@boost@@XZ': 0x56f8c0,
    '??$convert@VVector3@G3D@@@Value@Reflection@RBX@@QAEAAVVector3@G3D@@XZ': 0x56efa0,   # MoveTo call 005db040
    # boost signal constructors (identical code for the three signatures, one body 00499c00), called by the
    # TSignalInstance constructors reached from the Humanoid SignalDesc vtables.
    '??0?$signal0@XU?$last_value@X@boost@@HU?$less@H@std@@V?$function@$$A6AXXZV?$allocator@X@std@@@2@@boost@@QAE@ABU?$last_value@X@1@ABU?$less@H@std@@@Z': 0x499c00,
    '??0?$signal1@XMU?$last_value@X@boost@@HU?$less@H@std@@V?$function@$$A6AXM@ZV?$allocator@X@std@@@2@@boost@@QAE@ABU?$last_value@X@1@ABU?$less@H@std@@@Z': 0x499c00,
    '??0?$signal1@X_NU?$last_value@X@boost@@HU?$less@H@std@@V?$function@$$A6AX_N@ZV?$allocator@X@std@@@2@@boost@@QAE@ABU?$last_value@X@1@ABU?$less@H@std@@@Z': 0x499c00,
    # Second pass (getTopOfHead, renderWaypoint, getLocation, moveTo, setTargetPoint, newJoint, pending rows)
    '?v@?1??unitX@Vector3@G3D@@SAABV23@XZ@4V23@A': 0x9737f4,   # G3D::Vector3::unitX() static, moveTo 005dc3d0
    '?identity@Matrix3@G3D@@SAABV12@XZ': 0x513e20,             # getTopOfHead 005d76a0, renderWaypoint 005d7750
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,                  # copy ctor (evidence: ICF operator=), same call sites
    '?getCoordinateFrame@PartInstance@RBX@@QBEABVCoordinateFrame@G3D@@XZ': 0x598cb0,   # getLocation 005d9210, moveTo
    '?green@Color3@G3D@@SAABV12@XZ': 0x5148e0,                 # renderWaypoint 005d7750
    '?cylinder@DrawAdorn@RBX@@SAXPAVAdorn@2@ABVCoordinateFrame@G3D@@HMMABVColor3@5@@Z': 0x6773f0,   # 005d779e
    '?setMaxVelocity@Motor@RBX@@QAEXM@Z': 0x5e4fe0,            # newJoint 005d8469
    '??0Motor@RBX@@QAE@XZ': 0x5e4ee0,                          # Creatable<Instance>::create<Motor> 004b3294
    '??0Snap@RBX@@QAE@XZ': 0x5e4600,                           # Creatable<Instance>::create<Snap> 004b23f4
    # boost::detail::shared_count(T*, Creatable<Instance>::Deleter) (not exact here), bound at 004b32b1 / 004b2411
    '??$?0PAVMotor@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@shared_count@detail@boost@@QAE@PAVMotor@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@4@@Z': 0x4b3110,
    '??$?0PAVSnap@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@shared_count@detail@boost@@QAE@PAVSnap@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@4@@Z': 0x4b2270,
    # pending rows only
    '?findLocalCharacter@Players@Network@RBX@@SAPAVModelInstance@3@PBVInstance@3@@Z': 0x49aca0,   # 005d9bb5
    '?findWorkspace@Workspace@RBX@@SAPAV12@PBVInstance@2@@Z': 0x5a3380,                          # 005d79c0
    '?contextInWorkspace@Workspace@RBX@@SA_NPBVInstance@2@@Z': 0x5a33d0,                         # 005d79d3
    # Humanoid members declared here whose bodies are not recovered (bound at the listed call sites)
    '?getIntendedMovementVector@Humanoid@RBX@@AAE?AVVector3@G3D@@_N@Z': 0x5d9a50,   # 005d9bf0 / 005d9c10
    # RefPropDescriptor<Humanoid, PartInstance> constructor (shared reflection.h template): not exact, the two
    # vtable stores are ordered differently (see PROPOSALS); bound at initializers 007f62d0..007f63f0.
    '??$?0P8Humanoid@RBX@@BEPAVPartInstance@1@XZP801@AEXPAV21@@Z@?$RefPropDescriptor@VHumanoid@RBX@@VPartInstance@2@@Reflection@RBX@@QAE@PBD0P8Humanoid@2@BEPAVPartInstance@2@XZP832@AEXPAV42@@ZW4Functionality@PropertyDescriptor@12@@Z': 0x5da4e0,
}
# ---- data: descriptor statics (the `this` of the original initializers, the operand of raisePropertyChanged /
#      findSignalInstance in the setters) and the class-name array ------------------------------------------
DATA = {  # plain C++ name -> address (matched against the mangled or internal-linkage symbol)
    'sHumanoid': 0x9537e8,
    'propTorso': 0x97a538,
    'propLeftLeg': 0x97a3b0,
    'propRightLeg': 0x97a5dc,
    'propWalkToPart': 0x97a328,
    'propWalkToPoint': 0x97a4cc,
    'propWalkDirection': 0x97a4e8,
    'propWalkRotationalVelocity': 0x97a2d8,
    'propJump': 0x97a26c,
    'propTargetPoint': 0x97a4b0,
    'propSit': 0x97a3ec,
    'propStrafe': 0x97a5c0,
    'propHealth': 0x97a460,
    'propMaxHealth': 0x97a3d0,
    'func_TakeDamage': 0x97a288,
    'func_MoveTo': 0x97a408,
    'Humanoid::event_Died': 0x97a37c,
    'Humanoid::event_Running': 0x97a504,
    'Humanoid::event_Climbing': 0x97a58c,
    'Humanoid::event_Jumping': 0x97a5fc,
    'Humanoid::event_FreeFalling': 0x97a47c,
    'Humanoid::event_GettingUp': 0x97a630,
    'Humanoid::event_Strafing': 0x97a348,
    'Humanoid::event_FallingDown': 0x97a2f4,
    'Humanoid::event_Seated': 0x97a558,
}

HU = 'Humanoid@RBX@@'
# Seeds: (address, symbol or unique prefix). Initializers are mapped by the descriptor each one constructs (the
# `mov ecx, imm32` operand, checked through DATA); the rest are the unit's own bodies. Their callees, atexit
# functions and vtable slots join by closure.
SEEDS_MAIN = [
    (0x5db280, '??0Humanoid@RBX@@QAE@XZ'),
    (0x5d7d20, '??1Humanoid@RBX@@UAE@XZ'),
    (0x5d74b0, '?getHealth@' + HU),
    (0x5d74c0, '?getMaxHealth@' + HU),
    (0x5d74d0, '?getWalkDirection@' + HU),
    (0x5d7500, '?getWalkRotationalVelocity@' + HU),
    (0x5d7510, '?getWalkToPoint@' + HU),
    (0x5d7520, '?getJump@' + HU),
    (0x5d7530, '?getSit@' + HU),
    (0x5d7540, '?getStrafe@' + HU),
    (0x5d7550, '?getTargetPoint@' + HU),
    (0x5d9bf0, '?getIntendedMovementVector@' + HU + 'EAE'),
    (0x5d9c10, '?updateWalkDirection@' + HU),
    (0x5dbe70, '?setHealth@' + HU),
    (0x5dbf10, '?setMaxHealth@' + HU),
    (0x5dbf80, '?setWalkDirection@' + HU),
    (0x5dc090, '?setWalkRotationalVelocity@' + HU),
    (0x5dc0c0, '?setWalkToPoint@' + HU),
    (0x5dc230, '?setStrafe@' + HU),
    (0x5dc270, '?setJump@' + HU),
    (0x5dc2b0, '?setSit@' + HU),
    (0x5db600, '?onServiceProvider@' + HU),
    (0x5d80c0, '?getIntendedRotationAboutYAxis@' + HU),
    (0x5d80e0, '?computeForce@' + HU),
    (0x5d7fe0, '?getCameraIgnorePrimitives@' + HU),
    (0x5d7640, '?askSetParent@' + HU),
    (0x5d7670, '?getCharacterFromHumanoid@' + HU),
    (0x5d76a0, '?getTopOfHead@' + HU),
    (0x5d7750, '?renderWaypoint@' + HU),
    (0x7f6450, '??__EpropWalkToPoint@RBX@@YAXXZ'),
    (0x7f64b0, '??__EpropWalkDirection@RBX@@YAXXZ'),
    (0x7f6510, '??__EpropWalkRotationalVelocity@RBX@@YAXXZ'),
    (0x7f6570, '??__EpropJump@RBX@@YAXXZ'),
    (0x7f65d0, '??__EpropTargetPoint@RBX@@YAXXZ'),
    (0x7f6630, '??__EpropSit@RBX@@YAXXZ'),
    (0x7f6690, '??__EpropStrafe@RBX@@YAXXZ'),
    (0x7f66f0, '??__EpropHealth@RBX@@YAXXZ'),
    (0x7f6750, '??__EpropMaxHealth@RBX@@YAXXZ'),
    (0x7f67b0, '??__Efunc_TakeDamage@RBX@@YAXXZ'),
    (0x7f67f0, '??__Efunc_MoveTo@RBX@@YAXXZ'),
    (0x7f6840, '??__E?event_Died@' + HU),
    (0x7f6870, '??__E?event_Running@' + HU),
    (0x7f6890, '??__E?event_Climbing@' + HU),
    (0x7f68b0, '??__E?event_Jumping@' + HU),
    (0x7f68d0, '??__E?event_FreeFalling@' + HU),
    (0x7f68f0, '??__E?event_GettingUp@' + HU),
    (0x7f6910, '??__E?event_Strafing@' + HU),
    (0x7f6930, '??__E?event_FallingDown@' + HU),
    (0x7f6950, '??__E?event_Seated@' + HU),
]
SEEDS_PARTS = [
    (0x5d8a10, '?getHead@' + HU),
    (0x5d8b10, '?getTorso@' + HU),
    (0x5d8c10, '?getLeftLeg@' + HU),
    (0x5d8d10, '?getRightLeg@' + HU),
    (0x5d8e10, '?getLeftArm@' + HU),
    (0x5d8f10, '?getRightArm@' + HU),
    (0x5d7980, '?getWalkToPart@' + HU),
    (0x5dbf40, '?takeDamage@' + HU),
    (0x5dc150, '?setWalkToPart@' + HU),
    (0x5dc480, '?setLeftLeg@' + HU),
    (0x5dc540, '?setRightLeg@' + HU),
    (0x5dc600, '?setTorso@' + HU),
    (0x5dca00, '?moveTo2@' + HU),
    (0x5d77b0, '?getContactManager@' + HU),
    (0x5d75a0, '?getHeadFromCharacter@' + HU),
    (0x5d9210, '?getLocation@' + HU),
    (0x5dc3d0, '?moveTo@' + HU),
    (0x5dc2f0, '?setTargetPoint@' + HU),
    (0x5d9010, '?findRightShoulder@' + HU),
    (0x5d8420, '?newJoint@RBX@@'),
    (0x7f62d0, '??__EpropTorso@RBX@@YAXXZ'),
    (0x7f6330, '??__EpropLeftLeg@RBX@@YAXXZ'),
    (0x7f6390, '??__EpropRightLeg@RBX@@YAXXZ'),
    (0x7f63f0, '??__EpropWalkToPart@RBX@@YAXXZ'),
]
PENDING_SEEDS_MAIN = [
    (0x5d9a20, '?modelIsCharacter@' + HU),
    (0x5d9bb0, '?getLocalHumanoidFromContext@' + HU),
]
PENDING_SEEDS_PARTS = [
    (0x5d79b0, '?hasWalkToPoint@' + HU),
]
PENDING_REASON = {
    '005d9a20': 'modelIsCharacter: dynamic_cast<const ModelInstance*> then ModelInstance::findModifierOfType<Humanoid> '
                '(member template proposed for the native ModelInstance.h owner)',
    '005d9bb0': 'getLocalHumanoidFromContext: Network::Players::findLocalCharacter 0049aca0 + inlined modelIsCharacter '
                '(same findModifierOfType proposal)',
    '005d8690': 'ModelInstance::findModifierOfType<Humanoid> (proposed member template; callers 005d9a20, 005d9bb0, '
                '005d9c30, 005db4c0, 005db960)',
    '005d79b0': 'hasWalkToPoint: Workspace::findWorkspace 005a3380 / contextInWorkspace 005a33d0 (no native '
                'Workspace.h; declaration-only overlay tests/NativeHumanoid2008PendingWorkspace.h)',
}
PROPOSALS = [
    'native v8datamodel/ModelInstance.h (other owner): add the member template `template<class T> T* '
    'findModifierOfType() const` walking the existing `modifiers` vector (same text as the appearance proposal, '
    '005d4460 = <Skin>). 005d8690 is the <Humanoid> instantiation; with it modelIsCharacter 005d9a20 and '
    'getLocalHumanoidFromContext 005d9bb0 are exact (pending build), and render2d 005db960, render3dAdorn 005d9c30 '
    'and onLocalHumanoidEnteringWorkspace 005db4c0 call it.',
    'v8datamodel/Workspace.h (no native header; the donor fails with C2440 on &sWorkspace; other owner): a 2008 '
    'Workspace declaring at least findWorkspace 005a3380, getWorldIfInWorkspace 005a3390 and contextInWorkspace '
    '005a33d0. hasWalkToPoint 005d79b0 is exact against the declaration-only overlay '
    'tests/NativeHumanoid2008PendingWorkspace.h. render2d / onLocalHumanoidEnteringWorkspace also need its '
    'ICameraOwner subobject at Workspace+0x288 (getCamera slot 1, getGCamera slot 2) and Camera::getCameraType '
    '(+0x1d4), getCameraSubject 005cc420, setCameraSubject 005cde10.',
    'v8kernel/Connector2008.h vs the donor v8kernel/Connector.h (Connector2008.h owner): a shared 2008 Connector '
    'reachable from v8world/Primitive.h would let the Humanoid limb/part bodies share one translation unit with the '
    'constructor (today Humanoid2008Parts.cpp selects the donor Connector, see the header comment).',
    'Shared reflection.h RefPropDescriptor constructor template (other owner): the RefPropDescriptor<Humanoid, '
    'PartInstance> constructor 005da4e0 differs only in the order of the two vtable stores (+0 / +0x18) against '
    'the native template; not exact here.',
    'Donor reflection/property.h TypedPropertyDescriptor<T>::GetSet (reached through the native reflection.h; '
    'other owner): the 2008 GetSet vtables have four slots (isReadOnly, isWriteOnly, getValue, setValue), e.g. '
    'GetSetImpl<const Vector3& getter> 0083d308 = [0060a2f0, 0060a2f0, 005d7b60, 005d7bb0]; the donor class has '
    'three (no isWriteOnly). The getset factories here bind those vtables by RTTI only; the GetSetImpl '
    'getValue/setValue bodies 005d7b20/005d7b60/005d7bb0/005d7bf0/005d7c30 are not counted until the slot is added.',
    'native v8datamodel/PartInstance.h (other owner): the 2008 Primitive is embedded at PartInstance+0x228 '
    '(collectAllDescendantCharacterPrims 005d9d10 pushes part+0x228; onEvent 005dc740 calls Primitive 005e75b0 on '
    'torso+0x228; cameraSetWalkOrientation 005dc7f0 reads the body at +0x2c8). Blocks getIgnorePrims 005db9e0, '
    'tellCameraNear 005d9df0, onEvent 005dc740, cameraSetWalkOrientation 005dc7f0 and buildJoints 005d9340.',
    'native v8tree/Instance.h (other owner): the template visitDescendents(F) const (instantiated at 005d8540 for '
    'boost::bind(&collectAllDescendantCharacterPrims, _1, boost::ref(vector<Primitive*>)), used by getIgnorePrims '
    'and tellCameraNear).',
    'humanoid/HumanoidState.h (HumanoidState owner): onAncestorChanged 005db560 calls a cdecl static at 00643280 '
    'that returns `new Running(humanoid)` (operator new 0xcc, Running ctor 00666ac0); it needs a declaration (name '
    'unknown in the binary) before onAncestorChanged can be built.',
]

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}   # symbol -> (address, row)


def functions(obj):
    return {n: (b, r) for n, b, r in match.coff_functions(Path(obj).read_bytes())}


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key)
                                                       and not LOCAL_EH.match(x[0])]
        assert len(hits) == 1, (hex(address), key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def target(address):
    try:
        return match.target('2008-06', '%08x' % address)
    except Exception:
        return None


def exact_at(obj_funcs, symbol, address):
    if symbol not in obj_funcs:
        return False
    t = target(address)
    if t is None:
        return False
    body, refs = obj_funcs[symbol]
    return len(body) == len(t[0]) and match.exact_match(t[0], t[1], body, refs)


def relocations(raw, sections, symbols, definitions, name, size):
    start, section = definitions[name]
    table = sections[section]
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if 0 <= offset < size:
            yield offset, symbols[index][0], kind


def vtable_slots(raw, sections, symbols, definitions, starts, symbol):
    value, sec = definitions[symbol]
    table = sections[sec]
    end = min([x for x in starts[sec + 1] if x > value] + [table[3]])
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if value <= offset < end:
            slots[(offset - value) // 4] = symbols[index][0]
    return slots


def close(obj, rows):
    """Add callees / atexit functions / vtable slots defined in `obj` whose bodies are exact at the address the
    original uses (a vtable's address is the DIR32 operand of the original instruction; its RTTI is checked when the
    referencing row is verified). Slots are followed only for the Humanoid descriptor templates (GetSetImpl,
    PropDescriptor, SignalDesc, BoundFuncDesc instances over Humanoid), not into the shared signal/runtime classes."""
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, starts = match._coff_data_index(raw)
    funcs = functions(obj)
    rows = list(rows)
    seen = {name for _, name in rows}
    seen_vt = set()
    i = 0
    while i < len(rows):
        address, name = rows[i]
        body, refs = funcs[name]
        t = target(address)
        for offset, symbol, kind in relocations(raw, sections, symbols, definitions, name, len(body)):
            if symbol.startswith('??_E') and '??_G' + symbol[4:] in funcs:
                symbol = '??_G' + symbol[4:]
            if symbol.startswith('??_7') and 'Humanoid@RBX@@' in symbol and symbol in definitions and kind != 20 \
                    and symbol not in seen_vt:
                seen_vt.add(symbol)
                code = raw[sections[definitions[name][1]][4] + definitions[name][0]:]
                vt = (struct.unpack_from('<I', t[0], offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
                for slot, sym in vtable_slots(raw, sections, symbols, definitions, starts, symbol).items():
                    if sym.startswith('??_E') and '??_G' + sym[4:] in funcs:
                        sym = '??_G' + sym[4:]
                    if sym not in seen and sym in funcs and exact_at(funcs, sym, d(vt + 4 * slot)):
                        rows.append((d(vt + 4 * slot), sym))
                        seen.add(sym)
                continue
            if symbol in seen or symbol not in funcs or LOCAL_EH.match(symbol):
                continue
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', t[0], offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', t[0], offset)[0]
                         - struct.unpack_from('<i', raw, definitions[name][0] + sections[definitions[name][1]][4] + offset)[0]) & 0xffffffff
            if exact_at(funcs, symbol, value):
                rows.append((value, symbol))
                seen.add(symbol)
        i += 1
    return rows


def data_name(symbol):
    """`?name@RBX@@3...`, `?name@Humanoid@RBX@@2...` or the internal-linkage `_name` -> DATA key."""
    if symbol.startswith('_') and symbol[1:] in DATA:
        return symbol[1:]
    for key in DATA:
        short = key.split('::')[-1]
        prefix = '?%s@%sRBX@@' % (short, 'Humanoid@' if key.startswith('Humanoid::') else '')
        if symbol.startswith(prefix) and symbol[len(prefix)] in '23':
            return key
    return None


def classify(symbol, value, own, raw, sections, definitions, where):
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
    if symbol.startswith('??_8'):
        cls = symbol[4:symbol.index('@@7B') + 2]
        return None if cls != HU else 'vbtable (checked below)'
    if symbol in own:
        assert own[symbol] == value, (where, symbol, hex(value), hex(own[symbol]))
        return 'own row'
    if symbol.startswith('??_E') and ('??_G' + symbol[4:]) in own:
        assert own['??_G' + symbol[4:]] == value, (where, symbol, hex(value))
        return 'own row (??_G)'
    if symbol.startswith('__TI') and '?AV' in symbol:
        # _ThrowInfo -> CatchableTypeArray -> first CatchableType -> TypeDescriptor name
        cta = d(value + 12)
        first = d(cta + 4)
        rtti = original.string(d(first + 4) + 8)
        assert rtti == '.' + symbol[symbol.index('?AV'):], (where, symbol, hex(value), rtti)
        return 'throw info %s' % rtti
    key = data_name(symbol)
    if key is not None:
        assert DATA[key] == value, (where, symbol, hex(value), hex(DATA[key]))
        return 'data %s' % key
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
        return 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
    if symbol.startswith('??_B?1??') or symbol.startswith('?$S') or '?$TSS' in symbol or symbol.startswith('?flag@') \
            or symbol.startswith('?foo@') or symbol.startswith('?root@') or symbol.startswith('?n@?1???$doDeclare@'):
        return 'local static'
    return None


def verify(obj, rows, own):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    funcs = functions(obj)
    result = []
    for address, name in rows:
        body, refs = funcs[name]
        t, t_refs, _ = match.target('2008-06', '%08x' % address)
        assert match.exact_match(t, t_refs, body, refs), (name, hex(address), len(body), len(t))
        code = raw[sections[definitions[name][1]][4] + definitions[name][0]:]
        verified, local = {}, set()
        for offset, symbol, kind in relocations(raw, sections, symbols, definitions, name, len(body)):
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', t, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', t, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
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


main_rows = close(main_obj, resolve(main_obj, SEEDS_MAIN))
parts_rows = close(parts_obj, resolve(parts_obj, SEEDS_PARTS))
pend_rows = close(pend_obj, resolve(pend_obj, PENDING_SEEDS_MAIN))
pend_parts_rows = close(pend_parts_obj, resolve(pend_parts_obj, PENDING_SEEDS_PARTS))

# ---- vtables of the main build, slot by slot against the original vtable each one binds to -----------
INSTANCE_VTABLES = {0x0: 0x82d884, 0x10: 0x82d878, 0x14: 0x82d870, 0x20: 0x82d868, 0x24: 0x82d858, 0x44: 0x82d848,
                    0x64: 0x82d838, 0x84: 0x82d828, 0xa4: 0x82d818, 0xc4: 0x82d808}
for at, vt in INSTANCE_VTABLES.items():
    assert original.vtable_class(vt) == ('.?AVInstance@RBX@@', at), (hex(vt), original.vtable_class(vt))
FP = '?$FactoryProduct@VHumanoid@RBX@@VInstance@2@$1?sHumanoid@2@3PADA@RBX@@'
DC = '?$DescribedCreatable@VHumanoid@RBX@@VInstance@2@$1?sHumanoid@2@3PADA@RBX@@'
CLASSES = (HU, FP, DC)
# Original Humanoid vtables by subobject offset (constructor 005db280 stores them) and the Connector vtable
# 0083d1f4 the destructor restores.
HUMANOID_VTABLES = {0x0: 0x83d47c, 0x10: 0x83d46c, 0x14: 0x83d464, 0x20: 0x83d45c, 0x24: 0x83d44c, 0x44: 0x83d43c,
                    0x64: 0x83d42c, 0x84: 0x83d41c, 0xa4: 0x83d40c, 0xc4: 0x83d3fc, 0x130: 0x83d3e0,
                    0x138: 0x83d3d4, 0x13c: 0x83d3bc, 0x14c: 0x83d388, 0x1a0: 0x83d380, 0x1a4: 0x83d374,
                    0x228: 0x83d36c}
for at, vt in HUMANOID_VTABLES.items():
    assert original.vtable_class(vt) == ('.?AVHumanoid@RBX@@', at), (hex(vt), original.vtable_class(vt))
# Slots whose body this recovery declares but does not define (or defines only in the pending build): bound by
# position in the original vtable only, recorded as such.
SLOT_ONLY = {
    '?onAncestorChanged@' + HU + 'EAEXABUAncestorChanged@2@@Z': 'onAncestorChanged 005db560 (not recovered)',
    '?getBody@' + HU + 'EAEPAVBody@2@H@Z': 'getBody 005d9310 (not recovered: Primitive/Body layout)',
    '?render2d@' + HU + 'EAEXPAVAdorn@2@@Z': 'render2d 005db960 (not recovered)',
    '?render3dAdorn@' + HU + 'EAEXPAVAdorn@2@@Z': 'render3dAdorn 005d9c30 (not recovered)',
    '?tellCameraNear@' + HU + 'EAEXM@Z': 'tellCameraNear 005d9df0 (not recovered)',
    '?cameraSetWalkOrientation@' + HU + 'EAEXM_N@Z': 'cameraSetWalkOrientation 005dc7f0 (not recovered)',
    '?onEvent@' + HU + 'EAEXPBVRunService@2@VStepped@2@@Z': 'onEvent 005dc740 (not recovered)',
    '?getIgnorePrims@' + HU + 'UAEXAAV?$vector@PBVPrimitive@RBX@@V?$allocator@PBVPrimitive@RBX@@@std@@@std@@@Z':
        'getIgnorePrims 005db9e0 (not recovered)',
}
# Inherited defaults at the same address in the original base vtables (IRenderable, ICameraSubject,
# ICharacterSubject, Connector, Instance): read from the original vtable and checked to be the shared body.
SHARED_DEFAULTS = {0x70bdf0: 'shared empty body (ret 4)', 0x458e90: 'shared empty body (ret 8)',
                   0x60a2f0: 'shared return false', 0x565950: 'shared return true', 0x5e72c0: 'shared fldz',
                   0x584940: 'ICameraSubject::getLerp (0.9f)', 0x641390: 'ICharacterSubject::zoom',
                   0x641800: 'ICharacterSubject::stepGoalAndFocus'}

main_raw = main_obj.read_bytes()
sections, symbols, definitions, starts = match._coff_data_index(main_raw)
main_funcs = functions(main_obj)
vtables = {}
slot_only = {}
own = {}
for address, name in main_rows + parts_rows:   # pending-build rows never bind a main-build target or slot
    own.setdefault(name, address)
pending_vt = []
for symbol, (value, sec) in sorted(definitions.items()):
    if not symbol.startswith('??_7') or not any(symbol[4:].startswith(c + '6B') for c in CLASSES):
        continue
    table = sections[sec]
    end = min([x for x in starts[sec + 1] if x > value] + [table[3]])
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', main_raw, table[5] + 10 * i)
        if value <= offset < end:
            slots[(offset - value) // 4] = symbols[index][0]
    pending_vt.append((symbol, slots))
# The vtable addresses come from the constructor/destructor rows (DIR32 targets).
ctor_targets = {}
for address, name in main_rows:
    body, refs = main_funcs[name]
    t = target(address)
    for offset, symbol, kind in relocations(main_raw, sections, symbols, definitions, name, len(body)):
        if symbol.startswith('??_7') and kind != 20:
            code = main_raw[sections[definitions[name][1]][4] + definitions[name][0]:]
            ctor_targets[symbol] = (struct.unpack_from('<I', t[0], offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
# Slot symbols defined in the main object that are exact at the original slot address become rows (thunks etc.).
for symbol, slots in pending_vt:
    if symbol not in ctor_targets:
        continue
    vt = ctor_targets[symbol]
    for slot, sym in slots.items():
        value = d(vt + 4 * slot)
        if sym not in own and exact_at(main_funcs, sym, value):
            main_rows.append((value, sym))
            own[sym] = value
main_rows = close(main_obj, main_rows)
for address, name in main_rows:
    own.setdefault(name, address)
main_out = verify(main_obj, main_rows, own)
parts_out = verify(parts_obj, parts_rows, own)
own_pending = dict(own)
for address, name in pend_rows + pend_parts_rows:
    own_pending.setdefault(name, address)
pend_out = verify(pend_obj, pend_rows, own_pending) + verify(pend_parts_obj, pend_parts_rows, own_pending)
for row in pend_out:
    row['exact'] = False
    row['exact_pending_build_only'] = True
    row['what'] = PENDING_REASON.get(row['address'], 'callee of a pending-build-only row')

for symbol, slots in pending_vt:
    if symbol not in ctor_targets:
        continue
    vt = ctor_targets[symbol]
    rtti, at = original.vtable_class(vt)
    assert slots and max(slots) == len(slots) - 1, (symbol, sorted(slots))
    checked = {}
    for slot, sym in sorted(slots.items()):
        value_orig = d(vt + 4 * slot)
        how = classify(sym, value_orig, own, main_raw, sections, definitions, symbol)
        if how is None and sym in SLOT_ONLY:
            how = 'slot only: ' + SLOT_ONLY[sym]
            slot_only[sym] = hex(value_orig)
        if how is None and value_orig in SHARED_DEFAULTS and 'Humanoid' not in sym:
            how = 'inherited default (%s)' % SHARED_DEFAULTS[value_orig]
        if how is None and at in INSTANCE_VTABLES and d(INSTANCE_VTABLES[at] + 4 * slot) == value_orig \
                and 'Humanoid' not in sym:
            how = 'inherited (Instance vtable %#x slot %d)' % (INSTANCE_VTABLES[at], slot)
        if how is None:
            UNBOUND.append('vtable %s slot %d %s -> %s' % (symbol, slot, sym, hex(value_orig)))
            continue
        if not how.startswith('slot only') and not how.startswith('inherited'):
            prev = binding.setdefault(sym, (value_orig, symbol))
            assert prev[0] == value_orig, ('inconsistent', sym, hex(prev[0]), prev[1], hex(value_orig), symbol)
        checked[slot] = '%s = %s (%s)' % (sym, hex(value_orig), how)
    vtables[symbol] = {'address': hex(vt), 'rtti': rtti, 'offset': hex(at), 'slots': checked}

if UNBOUND:
    print('\n'.join(sorted(set(UNBOUND))))
    raise SystemExit('UNBOUND targets')
for at, vt in HUMANOID_VTABLES.items():
    assert any(v['address'] == hex(vt) for v in vtables.values()), (hex(vt), 'vtable not checked')
# Overridden slots (see Humanoid2008.h).
assert [d(0x83d47c + 4 * i) for i in (3, 4, 12)] == [0x5d7640, 0x5db560, 0x5db600]
assert [d(0x83d3e0 + 4 * i) for i in range(6)] == [0x5d80a0, 0x5d80e0, 0x60a2f0, 0x60a2f0, 0x5d9310, 0x5e72c0]
assert [d(0x83d3bc + 4 * i) for i in range(5)] == [0x565950, 0x565950, 0x5db960, 0x5d9c30, 0x458e90]
# vbtable of the ICharacterSubject subobject: {-4, 0xd8} (ILocation at +0x150 + 0xd8 = +0x228), stored by the
# constructor when most-derived.
assert [struct.unpack('<i', original.data(0x83d7d8 + 4 * i, 4))[0] for i in range(2)] == [-4, 0xd8]
body, _, _ = match.target('2008-06', '005db280')
assert b'\xc7\x86\x50\x01\x00\x00' + struct.pack('<I', 0x83d7d8) in body

# ---- allocation size, RTTI bases and strings -----------------------------------------------------------
body, _, _ = match.target('2008-06', '00490770')
at = body.index(b'\x68' + struct.pack('<I', 0x22c))
call = body.index(b'\xe8', at + 5)
while (0x490770 + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != 0x5db280:
    call = body.index(b'\xe8', call + 1)
assert body[call - 4:call] == b'\x6a\x01\x8b\xc8', 'most-derived flag (push 1; mov ecx, eax)'
for address, text in ((0x9537e8, 'Humanoid'), (0x82d6a0, 'Instance'), (0x83d7cc, 'Humanoid'), (0x83d828, 'Control'), (0x822490, 'Data'),
                      (0x83d88c, 'Game'), (0x83d884, 'Health'), (0x83d894, 'MaxHealth'), (0x83d87c, 'Strafe'),
                      (0x83d8a0, 'TakeDamage'), (0x83d8b4, 'Died'), (0x83d918, 'Seated')):
    assert original.string(address) == text, (hex(address), text)
locator = d(0x83d47c - 4)
hierarchy = d(locator + 16)
items = [d(d(hierarchy + 12) + 4 * i) for i in range(d(hierarchy + 8))]
bases = {original.string(d(item) + 8): struct.unpack('<i', original.data(item + 8, 4))[0] for item in items}
assert len(items) == 30, len(items)
for base, offset in (('.?AVConnector@RBX@@', 0x130), ('.?AVIControllable@RBX@@', 0x138),
                     ('.?AVIRenderable@RBX@@', 0x13c), ('.?AVICharacterSubject@RBX@@', 0x14c),
                     ('.?AVIModelModifier@RBX@@', 0x1a0), ('.?AV?$Listener@VRunService@RBX@@VStepped@2@@RBX@@', 0x1a4),
                     ('.?AV' + DC, 0)):
    assert bases.get(base) == offset, (base, bases.get(base))

exact = [r['address'] for r in main_out + parts_out]
sha = nb.sha
paths = [Path(__file__).resolve(), HDR, SRC, PARTS, LAYOUT, WORKSPACE_OVERLAY]
receipt = {
    'class': 'RBX::Humanoid', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'main': main_flags, 'parts': parts_flags, 'pending': pend_flags,
              'pending_parts': pend_parts_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, main_obj, parts_obj, pend_obj, pend_parts_obj)},
    'layout': {'Humanoid': '0x22c (create<Humanoid> 00490770 mallocs 0x22c, constructor 005db280(1)); Connector '
                           '+0x130, IControllable +0x138, IRenderable +0x13c, ICharacterSubject +0x14c (vbptr +0x150), '
                           'IModelModifier +0x1a0, Listener<RunService, Stepped> +0x1a4, fields +0x1a8..+0x220, '
                           'vtordisp +0x224, ILocation +0x228; RTTI 30 bases'},
    'methods': main_out + parts_out,
    'exact_count': len(main_out) + len(parts_out), 'exact_unique_addresses': len(set(exact)),
    'pending_methods': pend_out,
    'pending_note': 'Pending rows are exact only with NATIVE_HUMANOID2008_PENDING against '
                    'out/native-layouts/humanoid2008-pending/ (generated ModelInstance.h with findModifierOfType<T>, '
                    'Workspace.h overlay from tests/NativeHumanoid2008PendingWorkspace.h); not counted.',
    'near_miss': {'005d9a50': 'getIntendedMovementVector(bool): 337/337 bytes, only the x87 store order of the '
                              'delta (x, z, then y = 0 around the (dy + 3) magnitude) differs; body not kept',},
    'slot_only': slot_only,
    'proposals': PROPOSALS,
    'vtables': vtables,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/humanoid2008-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Humanoid2008: %d rows exact (%d unique addresses), %d pending-only (%d unique), %d vtables checked' % (
    len(main_out) + len(parts_out), len(set(exact)), len(pend_out), len({r['address'] for r in pend_out}),
    len(vtables)))
