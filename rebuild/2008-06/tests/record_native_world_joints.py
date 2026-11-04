"""Verify the inactive native RBX::Joint family and the RBX::Connector family recovery (2008-06).

Builds (document-swap flags plus /fp:fast /U_RELEASEASSERT, VS2008 RTM 21022), all from the current native headers
native-headers/v8world/Joints2008.h and native-headers/v8kernel/Connector2008.h:
  * tests/NativeWorldJointsLayout.cpp           joint sizeof/offset probe (mov eax, imm32; ret); instantiating the
                                                inline-constructed joints emits the vtables and the COMDATs the
                                                original keeps in the JointInstance unit (RigidJoint ??_G 005e2760,
                                                RotatePJoint ??_G 005e28e0, Joint::align 005e28c0);
  * tests/NativeWorldJointsConnectorLayout.cpp  connector sizeof/offset probe; emits ContactConnector(k, kNeg,
                                                kFriction) 00606d40, the shared ??_G 006062c0, getBroken 00645a60 and
                                                ContactConnector::getBody 00606230;
  * native-classes/WorldJoint.cpp               the Joint unit (00645490..00645590);
  * native-classes/WorldJointRigid.cpp          RigidJoint::getChildInParent 00645930;
  * native-classes/WorldJointMulti.cpp          the MultiJoint unit (006468a0..00646ac0);
  * native-classes/WorldJointRotate.cpp         the RotateJoint unit rows that need no Primitive / World;
  * native-classes/WorldJointGlue.cpp           GlueJoint() 00646b60, getMaxForce 00646c10, ??_G 00646ca0;
  * native-classes/WorldJointMotor.cpp          the MotorJoint unit (005e5bf0..005e5ee0);
  * native-classes/KernelConnector.cpp          the Connector unit rows 00606150..00606250;
  * WorldJointMotor.cpp again with /DNATIVE_WORLD_JOINTS_PENDING and a generated copy of the donor v8kernel/IStage.h
    (KERNEL_STAGE = 7, under out/native-layouts/world-joints-pending): MotorJoint::setCurrentAngle 005e5da0 is exact
    only there and is recorded exact = false (pending-build-only), never counted.

The headers use non-colliding names (Joints2008.h, Connector2008.h): the original paths v8world/Joint.h ... and
v8kernel/Connector.h are reached by nearly every engine / datamodel unit through the donor Primitive.h / Kernel.h, so
headers at those paths would shadow the donors for every recorder that reaches them (see PROPOSALS).

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals by bytes, constants by bytes,
type descriptors and vtables by original RTTI names, own symbols by the row proven here, folded bodies by their
address, and the remaining externals by the explicit EXTERNAL / DATA maps (call sites read in the original
disassembly). A symbol binds to one address across all rows. Vtables are compared slot by slot from the objects built
with the current (non-pending) headers. Writes work/2008-06/shared-layouts/world-joints-working.json.
Set NATIVE_WORLD_JOINTS_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
"""
import json
import os
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
DONOR = ROOT / 'tools/rbxgs/Client/App/include'
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
LAYOUT = R / 'tests/NativeWorldJointsLayout.cpp'
CLAYOUT = R / 'tests/NativeWorldJointsConnectorLayout.cpp'
SOURCES = {
    'joint': R / 'native-classes/WorldJoint.cpp',
    'rigid': R / 'native-classes/WorldJointRigid.cpp',
    'multi': R / 'native-classes/WorldJointMulti.cpp',
    'rotate': R / 'native-classes/WorldJointRotate.cpp',
    'glue': R / 'native-classes/WorldJointGlue.cpp',
    'motor': R / 'native-classes/WorldJointMotor.cpp',
    'connector': R / 'native-classes/KernelConnector.cpp',
}
HEADERS = [R / 'native-headers/v8world/Joints2008.h', R / 'native-headers/v8kernel/Connector2008.h']
DISCOVER = bool(os.environ.get('NATIVE_WORLD_JOINTS_DISCOVER'))
UNIT = ['/fp:fast', '/U_RELEASEASSERT']   # no RBXASSERT code in any of these units (e.g. ~Joint 00645490, init)

# Pending: the 2008 KERNEL_STAGE is 7 (MotorJoint::setCurrentAngle 005e5dc8 `cmp eax, 7`); the donor IStage.h has 8.
PENDING = OUT / 'world-joints-pending'
(PENDING / 'v8kernel').mkdir(parents=True, exist_ok=True)
istage = (DONOR / 'v8kernel/IStage.h').read_text()
assert istage.count('KERNEL_STAGE = 0x8,') == 1
(PENDING / 'v8kernel/IStage.h').write_text(istage.replace('KERNEL_STAGE = 0x8,', 'KERNEL_STAGE = 0x7,'))
PENDING_FLAGS = ['/I' + str(PENDING), '/DNATIVE_WORLD_JOINTS_PENDING']


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + UNIT + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['layout'], FLAGS['layout'] = build('NativeWorldJointsLayout', LAYOUT)
OBJ['clayout'], FLAGS['clayout'] = build('NativeWorldJointsConnectorLayout', CLAYOUT)
for key, src in SOURCES.items():
    OBJ[key], FLAGS[key] = build('NativeWorldJoints_' + key, src)
OBJ['motor_pending'], FLAGS['motor_pending'] = build('NativeWorldJoints_motor_pending', SOURCES['motor'], PENDING_FLAGS)

# ---- layout ---------------------------------------------------------------------------------------
SIZES = {
    'layout': {'nativeJointSize': 0x88, 'nativeRigidJointSize': 0x88, 'nativeWeldJointSize': 0x88,
               'nativeSnapJointSize': 0x88, 'nativeMultiJointSize': 0xc0, 'nativeRotateJointSize': 0xc4,
               'nativeRotatePJointSize': 0xc8, 'nativeRotateVJointSize': 0xc8, 'nativeGlueJointSize': 0x120,
               'nativeMotorJointSize': 0x98, 'nativeRevoluteLinkSize': 0xd0},
    'clayout': {'nativeConnectorSize': 0x8, 'nativeContactConnectorSize': 0x50,
                'nativePointToPointBreakConnectorSize': 0x1c, 'nativeNormalBreakConnectorSize': 0x20,
                'nativeRotateConnectorSize': 0x34},
}
for which, sizes in SIZES.items():
    raw = OBJ[which].read_bytes()
    for fn, size in sizes.items():
        name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?' + fn + '@@'))
        assert body_ == b'\xb8' + struct.pack('<I', size) + b'\xc3', (fn, body_.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol


# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a,
    '??0Edge@RBX@@QAE@PAVPrimitive@1@0@Z': 0x659260,                         # 006455d5 / 006456a7 (evidence name)
    '??0CoordinateFrame@G3D@@QAE@XZ': 0x4782d0,                             # 006455ed, Joint::align 005e28c7
    '?snapToGrid@Math@RBX@@SA?AVCoordinateFrame@G3D@@ABV34@M@Z': 0x5deed0,  # 0064560e / 00645647 (evidence name)
    '?canBuildJoint@Joint@RBX@@CA_NPAVPrimitive@2@0W4NormalId@2@1MM@Z': 0x6454b0,   # 00645584 / 006455b4
    '?inverse@CoordinateFrame@G3D@@QBE?AV12@XZ': 0x478330,                  # getChildInParent 00645957
    '??DCoordinateFrame@G3D@@QBE?AV01@ABV01@@Z': 0x476700,                  # getChildInParent 00645964
    '?putInKernel@IPipelined@RBX@@UAEXPAVKernel@2@@Z': 0x645830,            # MultiJoint::putInKernel 00646970
    '?removeFromKernel@IPipelined@RBX@@UAEXXZ': 0x645860,                   # 00646a74
    '?getKernel@IPipelined@RBX@@QBEPAVKernel@2@XZ': 0x645850,              # 006469b9, 00646a05
    '?insertConnector@Kernel@RBX@@QAEXPAVConnector@2@@Z': 0x5fb160,        # addToMultiJoint 006469c0
    '?removeConnector@Kernel@RBX@@QAEXPAVConnector@2@@Z': 0x5fb1f0,        # removeFromKernel 00646a0c
    '?deletePoint@Kernel@RBX@@QAEXPAVPoint@2@@Z': 0x5fb3c0,                # 00646a2c / 00646a3d
    # Constants: the callees return 8 (0063e420, folded with MotorJoint::getJointType) and 19 (006492d0); the donor
    # Constants.cpp table gives worldStepsPerUiStep 8 and kernelStepsPerWorldStep 19. RotatePJoint::stepWorld reaches
    # 006492d0 through the donor KernelInput::steps(), which names kernelStepsPerUiStep (see PROPOSALS).
    '?worldStepsPerUiStep@Constants@RBX@@SA?BHXZ': 0x63e420,               # RotateVJoint::stepWorld 00645d11
    '?kernelStepsPerWorldStep@Constants@RBX@@SA?BHXZ': 0x6492d0,           # 00645d28
    '?kernelStepsPerUiStep@Constants@RBX@@SA?BHXZ': 0x6492d0,              # RotatePJoint::stepWorld 00645ce4
    '?getKmsMaxJointForce@Constants@RBX@@SA?BMMM@Z': 0x649670,             # GlueJoint::getMaxForce 00646c86
    '?kmsForceToRbx@Units@RBX@@SAMM@Z': 0x6601b0,                          # 00646c91
    '??0Link@RBX@@QAE@XZ': 0x613d20,                                        # MotorJoint() 005e5c45 (evidence name)
    '?dirty@Link@RBX@@IAEXXZ': 0x613cb0,                                    # setCurrentAngle 005e5de9 (pending)
    '??0GeoPair@RBX@@QAE@XZ': 0x613060,                                     # ContactConnector() 00606d75 (evidence)
}
DATA = {
    '?v@?1??zero@Vector3@G3D@@SAABV23@XZ@4V23@A': 0x96f044,                # Vector3::zero() static (guard 0096f050)
}
# ICF / trivial-wrapper folds: the original keeps one body where these units emit several identical ones.
FOLDED = {
    '?getEdgeType@Joint@RBX@@MBE?AW4EdgeType@Edge@2@XZ': 0x416690,         # `xor eax, eax; ret`
    '?getJointType@Joint@RBX@@UBE?AW4JointType@12@XZ': 0x416690,
    '?isBreakable@Joint@RBX@@UBE_NXZ': 0x60a2f0,                            # `xor al, al; ret`
    '?isBroken@Joint@RBX@@UBE_NXZ': 0x60a2f0,
    '?joinsFace@Joint@RBX@@UBE_NPAVPrimitive@2@W4NormalId@2@@Z': 0x5eed40,  # `xor al, al; ret 8`
    '?isAligned@Joint@RBX@@UAE_NXZ': 0x565950,                              # `mov al, 1; ret`
    '?canStepWorld@Joint@RBX@@UBE_NXZ': 0x60a2f0,
    '?canStepUi@Joint@RBX@@UBE_NXZ': 0x60a2f0,
    '?stepWorld@Joint@RBX@@UAEXXZ': 0x47d410,                               # `ret`
    '?stepUi@Joint@RBX@@UAEXH@Z': 0x70bdf0,                                 # `ret 4`
    '?getJointType@WeldJoint@RBX@@EBE?AW4JointType@Joint@2@XZ': 0x5cb9d0,   # `mov eax, 6`
    '?getJointType@SnapJoint@RBX@@EBE?AW4JointType@Joint@2@XZ': 0x77d800,   # `mov eax, 7`
    '?getJointType@RotateJoint@RBX@@EBE?AW4JointType@Joint@2@XZ': 0x7286a0,  # `mov eax, 1`
    '?getJointType@RotatePJoint@RBX@@EBE?AW4JointType@Joint@2@XZ': 0x77d810,  # `mov eax, 2`
    '?getJointType@RotateVJoint@RBX@@EBE?AW4JointType@Joint@2@XZ': 0x5e2790,  # `mov eax, 3`
    '?getJointType@GlueJoint@RBX@@EBE?AW4JointType@Joint@2@XZ': 0x6fa3f0,   # `mov eax, 4`
    '?getJointType@MotorJoint@RBX@@EBE?AW4JointType@Joint@2@XZ': 0x63e420,  # `mov eax, 8`
    '?isBroken@MotorJoint@RBX@@EBE_NXZ': 0x60a2f0,
    '?canStepUi@MotorJoint@RBX@@EBE_NXZ': 0x565950,
    '?canStepWorld@DynamicRotateJoint@RBX@@EBE_NXZ': 0x565950,
    '?canStepUi@DynamicRotateJoint@RBX@@EBE_NXZ': 0x565950,
    '?isBreakable@GlueJoint@RBX@@EBE_NXZ': 0x565950,
    '??_GWeldJoint@RBX@@UAEPAXI@Z': 0x5e2760, '??_GSnapJoint@RBX@@UAEPAXI@Z': 0x5e2760,
    '??_GRotateVJoint@RBX@@UAEPAXI@Z': 0x5e28e0,
    '??1Link@RBX@@QAE@XZ': 0x47d410,                                        # ~MotorJoint 005e5e38 (empty, folded)
    '?canThrottle@Connector@RBX@@UBE_NXZ': 0x565950,
    '?getBroken@Connector@RBX@@UAE_NXZ': 0x60a2f0,
    '?potentialEnergy@Connector@RBX@@UAEMXZ': 0x5e72c0,                     # `fldz; ret`
    '??_GContactConnector@RBX@@UAEPAXI@Z': 0x6062c0, '??_GPointToPointBreakConnector@RBX@@UAEPAXI@Z': 0x6062c0,
    '??_GNormalBreakConnector@RBX@@UAEPAXI@Z': 0x6062c0, '??_GRotateConnector@RBX@@UAEPAXI@Z': 0x6062c0,
}
# Bodies emitted by these units whose bytes equal the folded original body (checked, not counted).
FOLD_PROOF = [
    ('layout', '??_GWeldJoint@RBX@@UAEPAXI@Z', 0x5e2760), ('layout', '??_GSnapJoint@RBX@@UAEPAXI@Z', 0x5e2760),
    ('layout', '??_GRotateVJoint@RBX@@UAEPAXI@Z', 0x5e28e0),
    ('clayout', '??_GContactConnector@RBX@@UAEPAXI@Z', 0x6062c0),
    ('clayout', '??_GPointToPointBreakConnector@RBX@@UAEPAXI@Z', 0x6062c0),
    ('clayout', '??_GNormalBreakConnector@RBX@@UAEPAXI@Z', 0x6062c0),
    ('connector', '??_GRotateConnector@RBX@@UAEPAXI@Z', 0x6062c0),
]
NON_EXACT_ROWS = [
    (0x606250, '?canThrottle@ContactConnector@RBX@@UBE_NXZ', 'connector',
     'the donor v8kernel/Body.h puts Body::canThrottle at +0x24; the 2008 body reads +0x30 of both bodies (no native '
     'Body header yet); everything else in the body is identical'),
]
UNPROVEN = {'?canThrottle@ContactConnector@RBX@@UBE_NXZ': 0x606250}
PENDING_ROWS = [
    (0x5e5da0, '?setCurrentAngle@MotorJoint@RBX@@QAEXM@Z', 'motor_pending',
     'exact only with the generated v8kernel/IStage.h (KERNEL_STAGE = 7); the donor IStage.h compares the stage with 8'),
]
# Vtable slots whose bodies are not built here: bound to the address the original vtable holds (names / call sites).
SLOT_EXTERNAL = {
    '?setPrimitive@Joint@RBX@@UAEXHPAVPrimitive@2@@Z': 0x6456e0,            # body read above (World, pending)
    '?isAligned@RigidJoint@RBX@@UAE_NXZ': 0x645870,                         # evidence name
    '?align@RigidJoint@RBX@@UAE?AVCoordinateFrame@G3D@@PAVPrimitive@2@0@Z': 0x6458d0,   # evidence name
    '?putInKernel@RotateJoint@RBX@@EAEXPAVKernel@2@@Z': 0x646550,           # news 0x1c / 0x34 connectors
    '?stepUi@DynamicRotateJoint@RBX@@EAEXH@Z': 0x6463f0,                    # shared RotateP / RotateV slot 14
    '?putInKernel@GlueJoint@RBX@@EAEXPAVKernel@2@@Z': 0x647190,             # news 0x20 NormalBreakConnectors
    '?isAligned@MotorJoint@RBX@@EAE_NXZ': 0x5e5d00,                         # evidence name
    '?computeForce@PointToPointBreakConnector@RBX@@UAEXM_N@Z': 0x6065d0,
    '?computeForce@NormalBreakConnector@RBX@@UAEXM_N@Z': 0x606670,
    '?computeForce@RotateConnector@RBX@@UAEXM_N@Z': 0x6064a0,
    '?computeForce@ContactConnector@RBX@@UAEXM_N@Z': 0x606780,
    '?setPrimitive@Edge@RBX@@UAEXHPAVPrimitive@2@@Z': 0x659290,
    '__purecall': 0x6a16be,                                                 # import thunk, verified below
    '?setCurrentAngle@MotorJoint@RBX@@QAEXM@Z': 0x5e5da0,                   # MotorJoint::stepUi calls (pending row)
}

ROWS = {
    'joint': [
        (0x6455c0, '??0Joint@RBX@@IAE@PAVPrimitive@1@0ABVCoordinateFrame@G3D@@1@Z'),
        (0x6456a0, '??0Joint@RBX@@IAE@XZ'),
        (0x645490, '??1Joint@RBX@@UAE@XZ'),
        (0x645680, '??_GJoint@RBX@@UAEPAXI@Z'),
        (0x645560, '?canBuildJointTight@Joint@RBX@@KA_NPAVPrimitive@2@0W4NormalId@2@1@Z'),
        (0x645590, '?canBuildJointLoose@Joint@RBX@@KA_NPAVPrimitive@2@0W4NormalId@2@1@Z'),
    ],
    'rigid': [
        (0x645930, '?getChildInParent@RigidJoint@RBX@@QAE?AVCoordinateFrame@G3D@@PAVPrimitive@2@0@Z'),
    ],
    'multi': [
        (0x6468a0, '?init@MultiJoint@RBX@@AAEXH@Z'),
        (0x646900, '??0MultiJoint@RBX@@IAE@H@Z'),
        (0x646920, '??0MultiJoint@RBX@@IAE@PAVPrimitive@1@0ABVCoordinateFrame@G3D@@1H@Z'),
        (0x646960, '??1MultiJoint@RBX@@MAE@XZ'),
        (0x646970, '?putInKernel@MultiJoint@RBX@@MAEXPAVKernel@2@@Z'),
        (0x646980, '?addToMultiJoint@MultiJoint@RBX@@IAEXPAVPoint@2@0PAVConnector@2@@Z'),
        (0x6469d0, '?getPoint@MultiJoint@RBX@@IAEPAVPoint@2@H@Z'),
        (0x6469e0, '?removeFromKernel@MultiJoint@RBX@@MAEXXZ'),
        (0x646a80, '?isBroken@MultiJoint@RBX@@MBE_NXZ'),
        (0x646ac0, '??_GMultiJoint@RBX@@MAEPAXI@Z'),
    ],
    'rotate': [
        (0x645a90, '??0RotateJoint@RBX@@QAE@PAVPrimitive@1@0ABVCoordinateFrame@G3D@@1@Z'),
        (0x645a70, '??0RotateJoint@RBX@@QAE@XZ'),
        (0x645ad0, '??1RotateJoint@RBX@@UAE@XZ'),
        (0x645ae0, '?removeFromKernel@RotateJoint@RBX@@EAEXXZ'),
        (0x645cb0, '?stepWorld@RotatePJoint@RBX@@EAEXXZ'),
        (0x645d00, '?stepWorld@RotateVJoint@RBX@@EAEXXZ'),
        (0x645d90, '??0RotatePJoint@RBX@@QAE@PAVPrimitive@1@0ABVCoordinateFrame@G3D@@1@Z'),
        (0x645dd0, '??0RotateVJoint@RBX@@QAE@PAVPrimitive@1@0ABVCoordinateFrame@G3D@@1@Z'),
        (0x645e10, '??_GRotateJoint@RBX@@UAEPAXI@Z'),
        (0x645e40, '?surfaceTypeToJoint@RotateJoint@RBX@@CAPAV12@W4SurfaceType@2@PAVPrimitive@2@1ABVCoordinateFrame@G3D@@2@Z'),
    ],
    'glue': [
        (0x646b60, '??0GlueJoint@RBX@@QAE@XZ'),
        (0x646c10, '?getMaxForce@GlueJoint@RBX@@AAEMXZ'),
        (0x646ca0, '??_GGlueJoint@RBX@@UAEPAXI@Z'),
    ],
    'motor': [
        (0x5e5bf0, '??0MotorJoint@RBX@@QAE@XZ'),
        (0x5e5e00, '??1MotorJoint@RBX@@UAE@XZ'),
        (0x5e5e70, '?stepUi@MotorJoint@RBX@@UAEXH@Z'),
        (0x5e5ee0, '??_GMotorJoint@RBX@@UAEPAXI@Z'),
    ],
    'layout': [
        (0x5e2760, '??_GRigidJoint@RBX@@UAEPAXI@Z'),
        (0x5e28e0, '??_GRotatePJoint@RBX@@UAEPAXI@Z'),
        (0x5e28c0, '?align@Joint@RBX@@UAE?AVCoordinateFrame@G3D@@PAVPrimitive@2@0@Z'),
    ],
    'connector': [
        (0x606150, '?getBody@PointToPointBreakConnector@RBX@@UAEPAVBody@2@H@Z'),
        (0x606170, '??0RotateConnector@RBX@@QAE@PAVPoint@1@000MM@Z'),
        (0x6061d0, '?getBody@RotateConnector@RBX@@UAEPAVBody@2@H@Z'),
        (0x6061f0, '?potentialEnergy@PointToPointBreakConnector@RBX@@UAEMXZ'),
    ],
    'clayout': [
        (0x606d40, '??0ContactConnector@RBX@@QAE@MMM@Z'),
        (0x6062c0, '??_GConnector@RBX@@UAEPAXI@Z'),
        (0x645a60, '?getBroken@PointToPointBreakConnector@RBX@@UAE_NXZ'),
        (0x606230, '?getBody@ContactConnector@RBX@@UAEPAVBody@2@H@Z'),
    ],
}

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}   # symbol -> (address, row) for the one-address-per-symbol check


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not LOCAL_EH.match(x[0])]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:120] for h in hits])
            continue
        assert len(hits) == 1, ('%08x' % address, key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def verify(obj, rows, own, strict=True, record=True):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict, (name, entry['address'], len(body), len(target))
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
            if LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol.startswith('??_C@'):
                pos, at = definitions[symbol]
                literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
                how = 'literal %r' % literal[:-1].decode()
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert norm(rtti) == norm('.' + symbol[5:-2]), (name, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('__real@'):
                assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
                how = 'constant %s' % symbol[7:]
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in FOLDED:
                assert FOLDED[symbol] == value, (name, symbol, hex(value))
                how = 'folded'
            elif symbol in DATA:
                assert DATA[symbol] == value, (name, symbol, hex(value))
                how = 'data'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
            elif symbol in UNPROVEN:
                assert UNPROVEN[symbol] == value, (name, symbol, hex(value))
                how = 'call target of a non-exact row'
            elif symbol in SLOT_EXTERNAL:
                assert SLOT_EXTERNAL[symbol] == value, (name, symbol, hex(value))
                how = 'call target bound at the call site (row not built / pending)'
            elif symbol.startswith('??_B?1??') or symbol.startswith('??_B?3??') or symbol.startswith('?$S') or '?$TSS' in symbol:
                how = 'local static'
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


resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
non_rows = [(resolve(OBJ[w], [(a, k)])[0], w) for a, k, w, _ in NON_EXACT_ROWS]
pend_rows = [(resolve(OBJ[w], [(a, k)])[0], w) for a, k, w, _ in PENDING_ROWS]
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
strict = not DISCOVER
groups = {k: verify(OBJ[k], rows, own, strict) for k, rows in resolved.items()}
non_out = [verify(OBJ[w], [r], own, strict=False)[0] for r, w in non_rows]
for row, (_, _, _, why) in zip(non_out, NON_EXACT_ROWS):
    if row['exact'] and not DISCOVER:
        raise AssertionError('non-exact row unexpectedly exact: %s' % row['address'])
    row['exact'], row['reason'] = False, why
pend_out = [verify(OBJ[w], [r], own, strict=False, record=False)[0] for r, w in pend_rows]
for row, (_, _, _, why) in zip(pend_out, PENDING_ROWS):
    if not row['exact'] and not DISCOVER:
        raise AssertionError('pending row not exact in the pending build: %s' % row['address'])
    row['pending_build_exact'] = row['exact']
    row['exact'], row['status'], row['reason'] = False, 'pending-build-only', why
# the same row from the current-header build must not be exact (it is not even built there)
assert not [x for x in match.coff_functions(OBJ['motor'].read_bytes()) if x[0].startswith('?setCurrentAngle@')]

fold_out = []
for which, symbol, address in FOLD_PROOF:
    body, refs = {n: (b, r) for n, b, r in match.coff_functions(OBJ[which].read_bytes())}[symbol]
    target, target_refs = target_of(address)
    ok = match.exact_match(target, target_refs, body, refs)
    assert ok or DISCOVER, ('fold body differs', symbol, hex(address))
    fold_out.append({'symbol': symbol, 'folded_into': '%08x' % address, 'body_equal': ok, 'counted': False})
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in list(groups.values()) + [non_out, pend_out]:
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
assert original.imported(0x6a16be)[1] == '_purecall', original.imported(0x6a16be)

# ---- vtables from the objects built with the current headers, slot by slot ---------------------------------
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL, UNPROVEN, SLOT_EXTERNAL):
    for k, v in table_.items():
        slot_names.setdefault(k, v)


def compiled_vtable(obj, symbol):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[index][0]
    return [slots[i] for i in range(len(slots))]


def check_vtable(obj, symbol, address):
    """Each slot holds the address bound to its symbol (row, fold, external) or the evidence name."""
    out, bad = [], []
    for i, slot in enumerate(compiled_vtable(obj, symbol)):
        value = d(address + 4 * i)
        if slot.startswith('??_E') and '??_G' + slot[4:] in slot_names:
            expect, how = slot_names['??_G' + slot[4:]], 'bound (??_G)'
        else:
            expect, how = slot_names.get(slot), 'bound'
        ok = expect == value if expect is not None else norm(names.get(value, '')) == norm(slot)
        if expect is None:
            how = 'evidence name'
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value)))
    assert not bad, (symbol, bad)
    return out


VTABLES = (('joint', 'Joint', 0x84ad44, 15), ('layout', 'RigidJoint', 0x83e07c, 15),
           ('layout', 'WeldJoint', 0x83e0bc, 15), ('layout', 'SnapJoint', 0x83e0fc, 15),
           ('multi', 'MultiJoint', 0x84ae14, 15), ('rotate', 'RotateJoint', 0x84adc4, 15),
           ('layout', 'RotatePJoint', 0x83e13c, 15), ('layout', 'RotateVJoint', 0x83e17c, 15),
           ('glue', 'GlueJoint', 0x84ae7c, 15), ('motor', 'MotorJoint', 0x83f764, 15),
           ('clayout', 'Connector', 0x83d1f4, 6), ('clayout', 'ContactConnector', 0x842834, 6),
           ('clayout', 'PointToPointBreakConnector', 0x84ada8, 6), ('clayout', 'NormalBreakConnector', 0x84ae5c, 6),
           ('connector', 'RotateConnector', 0x842804, 6))
vt = {}
for which, cls, address, count in VTABLES:
    assert original.vtable_class(address) == ('.?AV%s@RBX@@' % cls, 0), (cls, original.vtable_class(address))
    vt[cls] = check_vtable(OBJ[which], '??_7%s@RBX@@6B@' % cls, address)
    assert len(vt[cls]) == count, (cls, len(vt[cls]))

# ---- RTTI bases ------------------------------------------------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


JOINT_BASES = {'.?AVJoint@RBX@@': 0, '.?AVEdge@RBX@@': 0, '.?AVIPipelined@RBX@@': 0}
assert bases(0x84ad44) == JOINT_BASES
for address, extra in ((0x83e07c, ('RigidJoint',)), (0x83e0bc, ('WeldJoint', 'RigidJoint')),
                       (0x83e0fc, ('SnapJoint', 'RigidJoint')), (0x84ae14, ('MultiJoint',)),
                       (0x84adc4, ('RotateJoint', 'MultiJoint')), (0x84ae7c, ('GlueJoint', 'MultiJoint')),
                       (0x83e13c, ('RotatePJoint', 'DynamicRotateJoint', 'RotateJoint', 'MultiJoint')),
                       (0x83e17c, ('RotateVJoint', 'DynamicRotateJoint', 'RotateJoint', 'MultiJoint')),
                       (0x83f764, ('MotorJoint',))):
    want = dict(JOINT_BASES)
    want.update({'.?AV%s@RBX@@' % c: 0 for c in extra})
    assert bases(address) == want, (hex(address), bases(address))
CONNECTOR_BASES = {'.?AVConnector@RBX@@': 0, '.?AVKernelIndex@RBX@@': 4}
assert bases(0x83d1f4) == CONNECTOR_BASES
for address, extra in ((0x842834, ('ContactConnector',)), (0x842804, ('RotateConnector',)),
                       (0x84ada8, ('PointToPointBreakConnector',)),
                       (0x84ae5c, ('NormalBreakConnector', 'PointToPointBreakConnector'))):
    want = dict(CONNECTOR_BASES)
    want.update({'.?AV%s@RBX@@' % c: 0 for c in extra})
    assert bases(address) == want, (hex(address), bases(address))
# No DynamicRotateJoint vtable: its type descriptor has no complete-object locator of its own.

# ---- allocation sizes in the original creators --------------------------------------------------------------


def alloc_before(function, size, callee):
    body, _, _ = match.target('2008-06', '%08x' % function)
    push = (b'\x6a' + bytes([size])) if size < 0x80 else (b'\x68' + struct.pack('<I', size))
    at = body.index(push)
    while True:
        new = body.index(b'\xe8', at)
        if (function + new + 5 + struct.unpack_from('<i', body, new + 1)[0]) & 0xffffffff == 0x6a0920:
            break
        at = new + 1
    call = body.index(b'\xe8', new + 5)
    while (function + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != callee:
        call = body.index(b'\xe8', call + 1)
    return push.hex()


ALLOC = [
    (0x645e40, 0xc4, 0x645a90, 'RotateJoint::surfaceTypeToJoint -> RotateJoint(p0, p1, c0, c1)'),
    (0x645e40, 0xc8, 0x645d90, 'RotateJoint::surfaceTypeToJoint -> RotatePJoint(p0, p1, c0, c1)'),
    (0x5e4c60, 0xc8, 0x645a70, 'RotateP() (JointInstance) -> RotateJoint() + inline RotatePJoint'),
    (0x646f60, 0x120, 0x646cc0, 'GlueJoint::canBuildJoint -> GlueJoint(p0, p1, c0, c1)'),
    (0x5e5bf0, 0xd0, 0x613d20, 'MotorJoint() -> new RevoluteLink -> Link()'),
    (0x646550, 0x34, 0x606170, 'RotateJoint::putInKernel -> RotateConnector(...)'),
]
alloc = [{'creator': '%08x' % f, 'size': hex(s), 'constructor': '%08x' % c, 'note': n, 'push': alloc_before(f, s, c)}
         for f, s, c, n in ALLOC]
for function, size in ((0x646550, 0x1c), (0x647190, 0x20)):   # P2P / NormalBreak constructors are inlined
    body, _, _ = match.target('2008-06', '%08x' % function)
    assert b'\x6a' + bytes([size]) in body, hex(function)
assert names.get(0x646f60, '').startswith('?canBuildJoint@GlueJoint@RBX@@')

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT, CLAYOUT] + list(SOURCES.values()) + HEADERS
exact = sorted({r['address'] for g in groups.values() for r in g if r['exact']})
assert not set(exact) & {r['address'] for r in pend_out + non_out}
all_groups = dict(groups)
all_groups['not_exact'] = non_out
all_groups['pending_build_only'] = pend_out
PROPOSALS = {
    'v8world/Joint.h, RigidJoint.h, WeldJoint.h, SnapJoint.h, MultiJoint.h, RotateJoint.h, GlueJoint.h, MotorJoint.h '
    '(original paths, engine owner)': 'promote Joints2008.h to the original include paths once the owners of the units '
        'that include Primitive.h / World.h / JointInstance.h / Feature.h have re-run their recorders against it. '
        'Differences from the donor: Joint has 15 slots (two extra virtuals 11 `bool () const` / 13 `void ()`, analog '
        'names canStepWorld / stepWorld, between isAligned/align and stepUi: 0084ad44); RotatePJoint / RotateVJoint '
        'derive from a vtable-less DynamicRotateJoint (RTTI 0083e13c / 0083e17c) holding the float +0xc4; RotateP/V, '
        'GlueJoint and Weld/Snap have no user-declared destructor (??_G 005e28e0 / 00646ca0 call the base destructor '
        'without a vtable store); MotorJoint has no polarity (0x98); no RBXASSERT anywhere in these units.',
    'v8kernel/Connector.h (original path, kernel owner)': 'promote Connector2008.h: six slots (a pure `Body* (int)` '
        'slot 4 between getBroken and potentialEnergy, 0083d1f4), Connector::canThrottle returns true (00565950).',
    'v8kernel/IStage.h (engine owner; same as record_native_feature.py)': 'KERNEL_STAGE = 7 in 2008 '
        '(MotorJoint::setCurrentAngle 005e5dc8, Joint::setPrimitive 00645708, Joint::setJointCoord 006457ac compare the '
        'stage type with 7). setCurrentAngle 005e5da0 is exact with a generated copy and recorded pending-build-only.',
    'v8kernel/KernelInput.h (kernel owner)': 'KernelInput::steps() calls the function returning 19 (006492d0; '
        'RotatePJoint::stepWorld 00645ce4), which the donor Constants table names kernelStepsPerWorldStep, not '
        'kernelStepsPerUiStep (152): steps() should return Constants::kernelStepsPerWorldStep().',
    'v8kernel/Body.h (kernel owner)': 'Body::canThrottle is at +0x30 in 2008 (ContactConnector::canThrottle 00606250 '
        'reads +0x30 of both bodies; the donor layout puts it at +0x24).',
    'v8world/World.h (engine owner)': 'a World declaration reachable without the donor joint headers (World.h -> '
        'Primitive.h -> RigidJoint.h -> Joint.h) is needed for Joint::setPrimitive 006456e0 (onJointPrimitiveNulling '
        '005e9240 / onJointPrimitiveSet 005e9250), Joint::setJointCoord 00645750 (removeJoint 005ea3a0 / insertJoint '
        '005ea320) and DynamicRotateJoint::stepUi 006463f0 (ticklePrimitive 005e9410 takes a second argument, pushed '
        '1); these bodies are guarded with NATIVE_WORLD_JOINTS_PENDING_WORLD and not built.',
}
receipt = {
    'class': 'RBX::Joint, RigidJoint, WeldJoint, SnapJoint, MultiJoint, RotateJoint, DynamicRotateJoint, RotatePJoint, '
             'RotateVJoint, GlueJoint, MotorJoint; RBX::Connector, ContactConnector, PointToPointBreakConnector, '
             'NormalBreakConnector, RotateConnector',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in OBJ.values()},
    'layout': {
        'Joint': '0x88: Edge (0x20), jointOwner +0x20, active +0x24, jointCoord0 +0x28, jointCoord1 +0x58 (006455c0)',
        'MultiJoint': '0xc0: numConnector +0x88, point[8] +0x8c, connector[4] +0xac, numBreakingConnectors +0xbc (006468a0)',
        'RotateJoint': '0xc4 (00645e40): rotateConnector +0xc0',
        'DynamicRotateJoint / RotatePJoint / RotateVJoint': '0xc8 (00645e40): channelValue +0xc4 (analog name)',
        'GlueJoint': '0x120 (00646f60): overlapInP0 +0xc0, overlapInP1 +0xf0',
        'MotorJoint': '0x98: link +0x88, currentAngle +0x8c, maxVelocity +0x90, desiredAngle +0x94 (005e5bf0)',
        'Connector': '0x8: vptr, KernelIndex +0x4 (RTTI mdisp 4)',
        'ContactConnector': '0x50 (00606d40): geoPair +0x8, k +0x2c, kFriction +0x30, kNeg +0x34, firstApproach +0x38, '
                            'threshold +0x3c, forceMagLast +0x40, frictionOffset +0x44',
        'PointToPointBreakConnector': '0x1c (00646550): point0 +0x8, point1 +0xc, k +0x10, breakForce +0x14, broken +0x18',
        'NormalBreakConnector': '0x20 (00647190): normalIdBody0 +0x1c',
        'RotateConnector': '0x34 (00646550, 00606170): k +0x8, base0 +0xc, ray0 +0x10, ref0 +0x14, ref1 +0x18, '
                           'lastRotation +0x1c, windings +0x20, kernelInput +0x24',
    },
    'rows': all_groups,
    'fold_proof': fold_out,
    'exact_function_rows': exact,
    'vtables': vt,
    'allocations': alloc,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/world-joints-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native world joints: %d distinct function rows exact (%s); %d non-exact and %d pending-build-only rows '
      'not counted; %d fold proofs; targets and %d vtables verified'
      % (len(exact), ', '.join('%s %d' % (k, sum(r['exact'] for r in g)) for k, g in groups.items()), len(non_out),
         len(pend_out), len(fold_out), len(vt)))
