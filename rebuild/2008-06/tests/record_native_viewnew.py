"""Verify the inactive native RBX::ViewNew mesh builders / meshes and their RenderBase::Mesh base (2008-06).

Builds (document-swap flags, VS2008 RTM 21022, /fp:fast), all from the current native headers
(native-headers/ViewNew/*.h; no shared header is touched and no donor header is shadowed: the donor tree has no
ViewNew/ directory):
  * tests/NativeViewNewLayout.cpp       sizeof/offset probes (mov eax, imm32; ret);
  * native-classes/ViewNewQuadVolume.cpp LevelBuilder (00500ca0..0050103f) + G3D::Array<unsigned>::append(3) 00500690;
  * native-classes/ViewNewBevelMesh.cpp  BevelMesh::Builder::build 00501040;
  * native-classes/ViewNewSphereMesh.cpp SphereBuilder / SphereMesh (004fce90..004fd40f), the vertex function kept
                                         at 004fabb0, the header-inline Level constructor 004dd2e0, ??_G rows;
  * native-classes/ViewNewCylinderMesh.cpp CylinderBuilder / CylinderAlongXMesh (004fd430..004fdaef);
  * native-classes/ViewNewHeadMesh.cpp   HeadBuilder / HeadMesh (004fdaf0..0050068f);
  * native-classes/ViewNewWedgeMesh.cpp  WedgeBuilder / WedgeMesh (004f6e30..004f7d8f), with the BevelMesh::Builder
                                         copy constructor 004f6e30 and the builder-as-functor buildFace instances;
  * native-classes/ViewNewTorsoMesh.cpp  TorsoBuilder / TorsoMesh (004fa050..004fab2f) and the builder dtor 004fab30;
  * native-classes/ViewNewPBBMesh.cpp    PBBBuilder / PBBMesh (004f1eb0, 004f2030, 004f4790..004f4caf; the surface
                                         ctor 004f4cb0 needs the unnamed shadow helper 004e3570 and is not built).
  * native-classes/ViewNewFileMesh.cpp  FileMesh::create 00500b90 and the shared ??_G 004e54c0; loadFromMeshFile 00500780
                                         is compiled only with NATIVE_VIEWNEW_FILEMESH_PENDING against a generated copy of
                                         util/NativeContentProvider.h under out/ (ContentProvider::requestContentFile
                                         00562670 is not declared there) and is recorded exact=false (pending-build-only).
  * the per-face grid templates of native-headers/ViewNew/QuadVolumeFace.h (included by the Sphere / Cylinder / Head /
    Wedge / Torso / PBB units): every outer instance buildFace<id, F>(F, Vector2int16, Purpose), the strips
    buildFace<id, F>(F, Rect2D, ..) of the plain vertex function and of EndcapTransform / CylinderTransform, and the
    COMDATs LevelBuilder::offset 004f1ff0 and Rect2D::xyxy 004f35d0. The strips of the Wedge / Torso Deform* and
    PBB Face / Side functors are rows too (their class-inline operator() bodies are recovered from the strips, which
    inline them); the Wedge / Torso builder-as-functor strips differ in EH-frame stack layout and are
    non-exact rows.

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, constants by bytes, type descriptors and
vtables by original RTTI names, own symbols by the row proven here, folded bodies by their address, switch tables by
their position inside the row, and the remaining externals by the explicit EXTERNAL map (call sites read in the
original disassembly; checked below against the bodies they name). A symbol binds to one address across all rows.
Vtables are compared slot by slot from the objects built with the current headers. Rows that are not exact are
recorded with exact=false and a reason and are not counted.
Writes work/2008-06/shared-layouts/viewnew-working.json. Set NATIVE_VIEWNEW_DISCOVER=1 to list unbound targets and
non-exact rows instead of asserting.
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
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
LAYOUT = R / 'tests/NativeViewNewLayout.cpp'
UNITS = {
    'quad': R / 'native-classes/ViewNewQuadVolume.cpp',
    'bevel': R / 'native-classes/ViewNewBevelMesh.cpp',
    'sphere': R / 'native-classes/ViewNewSphereMesh.cpp',
    'cylinder': R / 'native-classes/ViewNewCylinderMesh.cpp',
    'head': R / 'native-classes/ViewNewHeadMesh.cpp',
    'wedge': R / 'native-classes/ViewNewWedgeMesh.cpp',
    'torso': R / 'native-classes/ViewNewTorsoMesh.cpp',
    'pbb': R / 'native-classes/ViewNewPBBMesh.cpp',
    'filemesh': R / 'native-classes/ViewNewFileMesh.cpp',
}
HEADERS = sorted((R / 'native-headers/ViewNew').glob('*.h'))
DISCOVER = bool(os.environ.get('NATIVE_VIEWNEW_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeViewNewLayout', LAYOUT, ['/fp:fast'])
OBJ, FLAGS = {}, {'layout': layout_flags}
for key, src in UNITS.items():
    OBJ[key], FLAGS[key] = build('NativeViewNew_' + key, src, ['/fp:fast'])

# ---- layout -------------------------------------------------------------------------------------------------------
# Evidence: Mesh ctor 00548570 (member ctors at +0xc / +0x18 / +0x50 / +0x68, stores +0x4c / +0x80 / +0x84), the
# factories 004eea30 / 004eef30 / 004ef430 (push 0x8c before 004fcfb0 / 004fd6b0 / 00500180), SphereMesh 004fcfb0
# (push 0x28 before the Level ctor 004dd2e0, which stores +0xc..+0x24), LevelBuilder ctor 00500d80 (+0x4..+0x1c),
# the BevelMesh::Builder copy ctor 004f6e30 (+0x20), the face slots (+0x20 / +0x24), CylinderBuilder ctor 004fd430
# (+0x20), HeadBuilder ctor 004fdaf0 (+0x20 / +0x24), ShadowSurface ctor 0054a9f0 (+0x30 last member).
raw = layout_obj.read_bytes()
SIZES = {
    'meshSize': 0x88, 'meshLevels': 0xc, 'meshShadowSurface': 0x18, 'meshDebugBoundingRadius': 0x4c,
    'meshShadowIndices': 0x50, 'meshShadowVertices': 0x68, 'meshSubMesh': 0x80, 'meshKind': 0x84,
    'shadowSurfaceSize': 0x34, 'levelSize': 0x28, 'levelIndexArray': 0xc, 'levelPrimitive': 0x18, 'levelDirty': 0x1c,
    'levelVertexStart': 0x20, 'levelSubMesh': 0x24, 'levelBuilderSize': 0x20, 'levelBuilderHalfSize': 0x4,
    'levelBuilderSurfaceTypes': 0x10, 'levelBuilderLevel': 0x14, 'levelBuilderTextureScale': 0x18,
    'bevelBuilderSize': 0x24, 'bevelBuilderBevel': 0x20, 'sphereBuilderSize': 0x24, 'sphereBuilderElements': 0x20,
    'cylinderBuilderSize': 0x24, 'cylinderBuilderElements': 0x20, 'headBuilderSize': 0x28, 'headBuilderBevel': 0x20,
    'headBuilderElements': 0x24, 'sphereMeshSize': 0x8c, 'cylinderMeshSize': 0x8c, 'headMeshSize': 0x8c,
    'bevelMeshSize': 0x88,
    # WedgeBuilder: the by-value copies in 004f7bd0 / 004f7c80 / 004f7d30 (sub esp, 0x24); TorsoBuilder: 004faa30 /
    # 004faaf0 (sub esp, 0x28; +0x24 copied after the Builder copy ctor); PBBBuilder ctor 004f1eb0 (+0x20..+0x24);
    # the factories 004ee030 / 004ee530 / 004edd50 push 0x8c before 004f7780 / 004fa590 / 004f49d0.
    'wedgeBuilderSize': 0x24, 'torsoBuilderSize': 0x28, 'torsoBuilderShoulderInset': 0x24, 'pbbBuilderStrips': 0x20,
    'wedgeMeshSize': 0x8c, 'torsoMeshSize': 0x8c, 'pbbMeshSize': 0x8c,
}
for fn, size in SIZES.items():
    name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?native' + fn + '@@'))
    assert body_ == b'\xb8' + struct.pack('<I', size) + b'\xc3', (fn, body_.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

LEVEL = '?$ReferenceCountedPointer@VLevel@Mesh@RenderBase@RBX@@@G3D@@'
FN = 'P6AXAAVVector3@G3D@@0AAVVector2@2@ABV12@ABVVector2int16@2@@Z'
EXTERNAL = {
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a,
    '??0Mesh@RenderBase@RBX@@IAE@XZ': 0x548570,               # stores the Mesh vtable 0082d028 (checked below)
    '??1Mesh@RenderBase@RBX@@UAE@XZ': 0x548a90,               # stores 0082d028 first (checked below)
    '??1Level@Mesh@RenderBase@RBX@@UAE@XZ': 0x5489b0,         # stores the Level vtable 00826e4c first (checked below)
    '?allocVertex@Mesh@RenderBase@RBX@@SAIII@Z': 0x547fc0,    # returns its first argument after the ref-count update
    '?ReferenceCountedObject_zeroWeakPointers@ReferenceCountedObject@G3D@@QAEXXZ': 0x45ad90,   # evidence name
    '?setPointer@' + LEVEL + 'AAEXPAVLevel@Mesh@RenderBase@RBX@@@Z': 0x598fa0,                # ICF (evidence: Shader)
    '?append@?$Array@V' + LEVEL + '@G3D@@QAEXABV?$ReferenceCountedPointer@VLevel@Mesh@RenderBase@RBX@@@2@@Z': 0x4dcbb0,  # push_back
    '?append@?$Array@I@G3D@@QAEXABI000@Z': 0x4dc6a0,          # 4-value append (00500eb0 QUADS case)
    '?resize@?$Array@I@G3D@@QAEXH_N@Z': 0x4805b0,              # 00500722
    '?mapToUvw_Legacy@RBX@@YA?AVVector3@G3D@@ABV23@W4NormalId@1@@Z': 0x5ec9d0,                  # evidence name
    '?xy@Vector3@G3D@@QBE?AVVector2@2@XZ': 0x5185d0,          # ICF with Rect2D::x0y0 (evidence name)
    '?yz@Vector3@G3D@@QBE?AVVector2@2@XZ': 0x518610,          # 004fd53f
    # FileMesh::create 00500c46 (ICF, evidence: Shader; the same body as the Level instance above)
    '?setPointer@?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@AAEXPAVMesh@RenderBase@RBX@@@Z': 0x598fa0,
}
# The per-face grid template LevelBuilder::buildFace<NormalId, Function>(Function, Vector2int16, Purpose): instances not
# recovered here; each is bound to the address its call sites in the original use (the face slots of every builder
# that shares the instance agree: SphereBuilder and CylinderBuilder share the plain function-pointer instances, whose
# bodies sit in the TorsoMesh unit 004fbdb0..004fcbc0; HeadBuilder's EndcapTransform instances sit at 004fef10 /
# 004ff1e0). Checked below: each address starts a function of the original list inside 004fbdb0..004ffd40.
FACE = ('@LevelBuilder@ViewNew@RBX@@IAEXP6AXAAVVector3@G3D@@0AAVVector2@4@ABV34@ABVVector2int16@4@@ZV64@'
        'W4Purpose@012@@Z')
ENDCAP = ('VEndcapTransform@ViewNew@RBX@@@LevelBuilder@ViewNew@RBX@@IAEXVEndcapTransform@12@VVector2int16@G3D@@'
          'W4Purpose@012@@Z')
BUILD_FACE = {
    '??$buildFace@$0A@' + FN + FACE: 0x4fbdb0,      # NORM_X     (SphereBuilder 004fceab, CylinderBuilder 004fd5ab)
    '??$buildFace@$00' + FN + FACE: 0x4fc080,       # NORM_Y     (004fcedb, 004fd5e1)
    '??$buildFace@$01' + FN + FACE: 0x4fc350,       # NORM_Z     (004fcf0b, 004fd611)
    '??$buildFace@$02' + FN + FACE: 0x4fc620,       # NORM_X_NEG (004fcf3b, 004fd63b)
    '??$buildFace@$03' + FN + FACE: 0x4fc8f0,       # NORM_Y_NEG (004fcf6b, 004fd671)
    '??$buildFace@$04' + FN + FACE: 0x4fcbc0,       # NORM_Z_NEG (004fcf9b, 004fd6a1)
    '??$buildFace@$00' + ENDCAP: 0x4fef10,          # HeadBuilder::buildTop 00500044
    '??$buildFace@$03' + ENDCAP: 0x4ff1e0,          # HeadBuilder::buildBottom 00500074
}
EXTERNAL.update(BUILD_FACE)
# The same grid template for the Wedge / Torso / PBB deformers and builder functors: instances not recovered here, each
# bound to the address its only call site uses (checked below: each starts a function of the original list inside
# 004f2110..004fa18f of more than 600 bytes). V = the instance's functor class, N = the NormalId template argument.
GRID = 'VVector2int16@G3D@@W4Purpose@012@@Z'


def grid(n, functor):
    return '??$buildFace@%sV%s@ViewNew@RBX@@@LevelBuilder@ViewNew@RBX@@IAEXV%s@12@%s' % (n, functor, functor, GRID)


GRID_FACE = {
    grid('$0A@', 'DeformSide3'): 0x4f5b80,      # WedgeBuilder::buildRight 004f6ec8
    grid('$00', 'DeformTop3'): 0x4f5e50,        # WedgeBuilder::buildTop 004f6f09
    grid('$02', 'DeformSide3'): 0x4f6120,       # WedgeBuilder::buildLeft 004f6f54
    grid('$04', 'DeformFront'): 0x4f6400,       # WedgeBuilder::buildFront 004f6f89
    grid('$01', 'WedgeBuilder'): 0x4f6fa0,      # 004f7c2c
    grid('$03', 'WedgeBuilder'): 0x4f7390,      # 004f7cdc
    grid('$0A@', 'DeformSide'): 0x4f8e50,       # TorsoBuilder::buildRight 004fa085
    grid('$00', 'DeformTop'): 0x4f9120,         # TorsoBuilder::buildTop 004fa0c5
    grid('$01', 'DeformFrontBack'): 0x4f9400,   # TorsoBuilder::buildBack 004fa105
    grid('$02', 'DeformSide'): 0x4f96e0,        # TorsoBuilder::buildLeft 004fa145
    grid('$04', 'DeformFrontBack'): 0x4f99c0,   # TorsoBuilder::buildFront 004fa185
    grid('$03', 'TorsoBuilder'): 0x4fa190,      # 004faa93
    grid('$00', 'Face'): 0x4f3650,              # PBBBuilder::buildTop 004f47d7
    grid('$03', 'Face'): 0x4f3930,              # PBBBuilder::buildBottom 004f4837
    grid('$02', 'Side'): 0x4f3c10,              # PBBBuilder::buildLeft 004f4897
    grid('$0A@', 'Side'): 0x4f3ef0,             # PBBBuilder::buildRight 004f48f7
    grid('$04', 'Side'): 0x4f41d0,              # PBBBuilder::buildFront 004f4957
    grid('$01', 'Side'): 0x4f44b0,              # PBBBuilder::buildBack 004f49b7
}
EXTERNAL.update(GRID_FACE)
EXTERNAL['__ftol2_sse'] = 0x6a17f0                # PBBBuilder ctor 004f1f0a (CRT float-to-int helper, statically linked)
# Unit-local data, bound per unit (the same internal symbol names a different object in each unit) and checked by bytes:
# `static const float bevel = 0.065f` of the Wedge unit (00827080, read by 004f7985 / 004f7ae1) and of the Torso unit
# (008270f8, read by 004fa7c2 / 004fa93e).
UNIT_DATA = {('wedge', '_bevel'): 0x827080, ('torso', '_bevel'): 0x8270f8}
# BrickMesh::normalPerturbation (0.05f, checked by bytes below): read by the BrickMesh unit 004de50e.. and by Face 004f2040.
DATA = {'?normalPerturbation@BrickMesh@ViewNew@RBX@@2MB': 0x826e3c,
        # BrickMesh's other 0.0f class constant: read only by the PBB Face / Side strips (004f228d.. six sites); the
        # BrickMesh unit folds it (checked by bytes below)
        '?bevel@BrickMesh@ViewNew@RBX@@2MB': 0x826e38}
FOLDED = {}
LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}

QUAD_ROWS = [
    (0x500ca0, '?buildFace@LevelBuilder@ViewNew@RBX@@QAEXW4NormalId@3@W4Purpose@123@@Z'),
    (0x500d30, '?build@LevelBuilder@ViewNew@RBX@@UAEXW4Purpose@123@@Z'),
    (0x500d80, '??0LevelBuilder@ViewNew@RBX@@IAE@AAV' + LEVEL + 'VVector3@4@VRenderSurfaceTypes@12@@Z'),
    (0x500de0, '?appendQuadFromVertexIndices@LevelBuilder@ViewNew@RBX@@IAEXIII@Z'),
    (0x500eb0, '?appendQuadFromVertexIndices@LevelBuilder@ViewNew@RBX@@IAEXIIII@Z'),
    (0x500fd0, '?appendQuadFromIndexArray@LevelBuilder@ViewNew@RBX@@IAEXHHH@Z'),
    (0x501000, '?appendQuadFromIndexArray@LevelBuilder@ViewNew@RBX@@IAEXHHHH@Z'),
    (0x500690, '?append@?$Array@I@G3D@@QAEXABI00@Z'),
]
BEVEL_ROWS = [
    (0x501040, '?build@Builder@BevelMesh@ViewNew@RBX@@UAEXW4Purpose@LevelBuilder@34@@Z'),
]
SPHERE_ROWS = [
    (0x4fce90, '?buildRight@SphereBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fcec0, '?buildTop@SphereBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fcef0, '?buildBack@SphereBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fcf20, '?buildLeft@SphereBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fcf50, '?buildBottom@SphereBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fcf80, '?buildFront@SphereBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fcfb0, '??0SphereMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@VRenderSurfaceTypes@12@@Z'),
    (0x4fd270, '??0SphereMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@ABVVector2@4@@Z'),
    (0x4fabb0, '?SphereTransform@ViewNew@RBX@@YAXAAVVector3@G3D@@0AAVVector2@4@ABV34@ABVVector2int16@4@@Z'),
    (0x4dd2e0, '??0Level@Mesh@RenderBase@RBX@@QAE@W4Primitive@RenderDevice@G3D@@@Z'),
    (0x4dd340, '??_GLevel@Mesh@RenderBase@RBX@@UAEPAXI@Z'),
    (0x4e54c0, '??_GSphereMesh@ViewNew@RBX@@UAEPAXI@Z'),
]
CYLINDER_ROWS = [
    (0x4fd430, '??0CylinderBuilder@ViewNew@RBX@@QAE@AAV' + LEVEL + 'VVector3@4@VRenderSurfaceTypes@12@I@Z'),
    (0x4fd4a0, '?EndcapTransform@ViewNew@RBX@@YAXAAVVector3@G3D@@0AAVVector2@4@ABV34@ABVVector2int16@4@@Z'),
    (0x4fd530, '?CylinderTransform@ViewNew@RBX@@YAXAAVVector3@G3D@@0AAVVector2@4@ABV34@ABVVector2int16@4@@Z'),
    (0x4fd590, '?buildRight@CylinderBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fd5c0, '?buildTop@CylinderBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fd5f0, '?buildBack@CylinderBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fd620, '?buildLeft@CylinderBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fd650, '?buildBottom@CylinderBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fd680, '?buildFront@CylinderBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x4fd6b0, '??0CylinderAlongXMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@VRenderSurfaceTypes@12@@Z'),
    (0x4fd800, '??0CylinderAlongXMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@@Z'),
    (0x4fd960, '??0CylinderAlongXMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@ABVVector2@4@@Z'),
    (0x4e54c0, '??_GCylinderAlongXMesh@ViewNew@RBX@@UAEPAXI@Z'),
]
HEAD_ROWS = [
    (0x4fdaf0, '??0HeadBuilder@ViewNew@RBX@@QAE@V' + LEVEL + 'VVector3@4@VRenderSurfaceTypes@12@IM@Z'),
    (0x4fdbd0, '??RCylinderTransform@ViewNew@RBX@@QAEXAAVVector3@G3D@@0AAVVector2@4@ABV34@ABVVector2int16@4@@Z'),
    (0x500020, '?buildTop@HeadBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x500050, '?buildBottom@HeadBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z'),
    (0x500180, '??0HeadMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@VRenderSurfaceTypes@12@@Z'),
    (0x4e54c0, '??_GHeadMesh@ViewNew@RBX@@UAEPAXI@Z'),
]
SLOT = 'MAEXW4Purpose@LevelBuilder@23@@Z'
WEDGE_ROWS = [
    (0x4f6e30, '??0Builder@BevelMesh@ViewNew@RBX@@QAE@ABV0123@@Z'),   # implicit copy ctor (callers 004f7bd0.. / 004faa30..)
    (0x4f6e90, '?buildRight@WedgeBuilder@ViewNew@RBX@@' + SLOT),
    (0x4f6ee0, '?buildTop@WedgeBuilder@ViewNew@RBX@@' + SLOT),
    (0x4f6f20, '?buildLeft@WedgeBuilder@ViewNew@RBX@@' + SLOT),
    (0x4f6f60, '?buildFront@WedgeBuilder@ViewNew@RBX@@' + SLOT),
    (0x4f7780, '??0WedgeMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@VRenderSurfaceTypes@12@@Z'),
    (0x4f78d0, '??0WedgeMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@@Z'),
    (0x4f7a30, '??0WedgeMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@ABVVector2@4@@Z'),
    (0x4f7bd0, '??$buildFace@$01VWedgeBuilder@ViewNew@RBX@@@LevelBuilder@ViewNew@RBX@@IAEXVWedgeBuilder@12@IIW4Purpose@012@@Z'),
    (0x4f7c80, '??$buildFace@$03VWedgeBuilder@ViewNew@RBX@@@LevelBuilder@ViewNew@RBX@@IAEXVWedgeBuilder@12@IIW4Purpose@012@@Z'),
    (0x4f7d30, '?buildBack@WedgeBuilder@ViewNew@RBX@@' + SLOT),
    (0x4f7d60, '?buildBottom@WedgeBuilder@ViewNew@RBX@@' + SLOT),
    (0x4e54c0, '??_GWedgeMesh@ViewNew@RBX@@UAEPAXI@Z'),
]
TORSO_ROWS = [
    (0x4fa050, '?buildRight@TorsoBuilder@ViewNew@RBX@@' + SLOT),
    (0x4fa090, '?buildTop@TorsoBuilder@ViewNew@RBX@@' + SLOT),
    (0x4fa0d0, '?buildBack@TorsoBuilder@ViewNew@RBX@@' + SLOT),
    (0x4fa110, '?buildLeft@TorsoBuilder@ViewNew@RBX@@' + SLOT),
    (0x4fa150, '?buildFront@TorsoBuilder@ViewNew@RBX@@' + SLOT),
    (0x4fa590, '??0TorsoMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@VRenderSurfaceTypes@12@@Z'),
    (0x4fa700, '??0TorsoMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@@Z'),
    (0x4fa880, '??0TorsoMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@ABVVector2@4@@Z'),
    (0x4faa30, '??$buildFace@$03VTorsoBuilder@ViewNew@RBX@@@LevelBuilder@ViewNew@RBX@@IAEXVTorsoBuilder@12@IIW4Purpose@012@@Z'),
    (0x4faaf0, '?buildBottom@TorsoBuilder@ViewNew@RBX@@' + SLOT),
    # implicit builder dtor (level +0x14 released, then zeroed): the body the EH unwind funclets 007caede.. jump to;
    # ~LevelBuilder / ~BevelMesh::Builder / ~TorsoBuilder compile to the same bytes (ICF), kept at the Torso unit's end.
    (0x4fab30, '??1TorsoBuilder@ViewNew@RBX@@QAE@XZ'),
    (0x4e54c0, '??_GTorsoMesh@ViewNew@RBX@@UAEPAXI@Z'),
]
PBB_ROWS = [
    (0x4f1eb0, '??0PBBBuilder@ViewNew@RBX@@QAE@AAV' + LEVEL + 'VVector3@4@VRenderSurfaceTypes@12@@Z'),
    (0x4f2030, '??0Face@ViewNew@RBX@@QAE@XZ'),
    (0x4f4790, '?buildTop@PBBBuilder@ViewNew@RBX@@' + SLOT),
    (0x4f47f0, '?buildBottom@PBBBuilder@ViewNew@RBX@@' + SLOT),
    (0x4f4850, '?buildLeft@PBBBuilder@ViewNew@RBX@@' + SLOT),
    (0x4f48b0, '?buildRight@PBBBuilder@ViewNew@RBX@@' + SLOT),
    (0x4f4910, '?buildFront@PBBBuilder@ViewNew@RBX@@' + SLOT),
    (0x4f4970, '?buildBack@PBBBuilder@ViewNew@RBX@@' + SLOT),
    (0x4f49d0, '??0PBBMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@@Z'),
    (0x4f4b20, '??0PBBMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@ABVVector2@4@@Z'),
    (0x4e54c0, '??_GPBBMesh@ViewNew@RBX@@UAEPAXI@Z'),
]
FILEMESH_ROWS = [
    (0x500b90, '?create@FileMesh@ViewNew@RBX@@SA?AV?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@'
               'PAVContentProvider@3@ABVVector3@5@VMeshId@3@@Z'),
    (0x4e54c0, '??_GFileMesh@ViewNew@RBX@@UAEPAXI@Z'),
]
LOAD_FROM_MESH_FILE = '?loadFromMeshFile@FileMesh@ViewNew@RBX@@QAE_NPAVContentProvider@3@ABVVector3@G3D@@VMeshId@3@@Z'
# ---- the per-face grid templates (native-headers/ViewNew/QuadVolumeFace.h, included by the builder units) -----------
# Outer grid instances buildFace<id, F>(F, Vector2int16, Purpose) are the BUILD_FACE / GRID_FACE addresses above (the
# call sites of the face slots); each outer calls its strip buildFace<id, F>(F, Rect2D, depth, origin, extent, axis,
# divisions) right after Rect2D::xyxy 004f35d0 (read from the original below, STRIP_OF). Rows are attributed to the unit
# whose face slots use them (the plain vertex-function instances, shared by Sphere and Cylinder, to 'sphere').
FACE_IDS = {'$0A@': 0, '$00': 1, '$01': 2, '$02': 3, '$03': 4, '$04': 5}
STRIP_FN = '@LevelBuilder@ViewNew@RBX@@IAEXP6AXAAVVector3@G3D@@0AAVVector2@4@ABV34@ABVVector2int16@4@@ZVRect2D@4@MV54@6HV64@@Z'


def strip(n, functor):
    return ('??$buildFace@%sV%s@ViewNew@RBX@@@LevelBuilder@ViewNew@RBX@@IAEXV%s@12@VRect2D@G3D@@MVVector2@5@2HVVector2int16@5@@Z'
            % (n, functor, functor))


def call_after_xyxy(address):
    body, _, _ = match.target('2008-06', '%08x' % address)
    calls = [(address + i + 5 + struct.unpack_from('<i', body, i + 1)[0]) & 0xffffffff
             for i in range(len(body) - 5) if body[i] == 0xe8]
    k = calls.index(0x4f35d0)
    return next(c for c in calls[k + 1:] if 0x4f0000 <= c < 0x500000)


OUTER_ROWS = {'sphere': [
    # COMDATs every grid instance calls: the header-inline LevelBuilder::offset (jump table 004f2018) and G3D's
    # Rect2D::xyxy(const Vector2&, const Vector2&) (evidence name)
    (0x4f1ff0, '?offset@LevelBuilder@ViewNew@RBX@@KAMW4RenderSurfaceType@23@@Z'),
    (0x4f35d0, '?xyxy@Rect2D@G3D@@SA?AV12@ABVVector2@2@0@Z'),
], 'head': [], 'wedge': [], 'torso': [], 'pbb': []}
STRIP_ROWS = {'sphere': [], 'head': [], 'wedge': [], 'torso': [], 'pbb': []}
STRIP_OF = {}
for n in FACE_IDS:
    outer = BUILD_FACE['??$buildFace@' + n + FN + FACE]
    OUTER_ROWS['sphere'].append((outer, '??$buildFace@' + n + FN + FACE))
    STRIP_OF['??$buildFace@' + n + FN + STRIP_FN] = call_after_xyxy(outer)
    STRIP_ROWS['sphere'].append((STRIP_OF['??$buildFace@' + n + FN + STRIP_FN], '??$buildFace@' + n + FN + STRIP_FN))
HEAD_CYLINDER = {'$02': 0x4ff4b0, '$0A@': 0x4ff790, '$04': 0x4ffa60, '$01': 0x4ffd40}   # HeadBuilder side slots
for n, outer in HEAD_CYLINDER.items():
    EXTERNAL[grid(n, 'CylinderTransform')] = outer       # call sites 00500080 / 005000c0 / 00500100 / 00500140
for n in ('$00', '$03'):
    OUTER_ROWS['head'].append((BUILD_FACE['??$buildFace@' + n + ENDCAP], '??$buildFace@' + n + ENDCAP))
    STRIP_OF[strip(n, 'EndcapTransform')] = call_after_xyxy(BUILD_FACE['??$buildFace@' + n + ENDCAP])
for n, outer in HEAD_CYLINDER.items():
    OUTER_ROWS['head'].append((outer, grid(n, 'CylinderTransform')))
    STRIP_OF[strip(n, 'CylinderTransform')] = call_after_xyxy(outer)
for key in [k for k in STRIP_OF if 'EndcapTransform' in k or 'CylinderTransform' in k]:
    STRIP_ROWS['head'].append((STRIP_OF[key], key))
UNIT_OF = {'DeformSide3': 'wedge', 'DeformTop3': 'wedge', 'DeformFront': 'wedge', 'WedgeBuilder': 'wedge',
           'DeformSide': 'torso', 'DeformTop': 'torso', 'DeformFrontBack': 'torso', 'TorsoBuilder': 'torso',
           'Face': 'pbb', 'Side': 'pbb'}
for symbol, outer in GRID_FACE.items():
    n, functor = symbol[len('??$buildFace@'):].split('V', 1)
    functor = functor.split('@', 1)[0]
    OUTER_ROWS[UNIT_OF[functor]].append((outer, symbol))
    STRIP_OF[strip(n, functor)] = call_after_xyxy(outer)
# The Deform* / PBB Face / Side functors have class-inline operator() bodies (recovered from the strips, which inline
# them), so their strips are counted rows. Strips whose stack layout differs (the builder-as-functor strips carry an EH
# frame) are bound to the address the outer's call uses and recorded as non-exact.
STRIP_NON_EXACT = {
    'WedgeBuilder': 'same instructions and size; the EH frame of the by-value builder places the locals 8 bytes '
                    'differently (stack layout only)',
    'TorsoBuilder': 'same instructions and size; the EH frame of the by-value builder places the locals 8 bytes '
                    'differently (stack layout only)',
}
STRIP_NON = []
for symbol, address in STRIP_OF.items():
    functor = symbol[len('??$buildFace@'):].split('V', 1)[1].split('@', 1)[0] if 'P6AX' not in symbol else None
    if functor in STRIP_NON_EXACT:
        EXTERNAL[symbol] = address
        STRIP_NON.append((address, symbol, STRIP_NON_EXACT[functor], UNIT_OF[functor]))
    elif functor in UNIT_OF:
        STRIP_ROWS[UNIT_OF[functor]].append((address, symbol))
EXTERNAL.update({
    # face-space transforms uvwToObject<id> (cdecl, hidden result; util/NormalId.h declares the template, the 2008 image
    # has one out-of-line body per face; NORM_Z is the identity, folded with another identity copy at 006784d0)
    '??$uvwToObject@$0A@@RBX@@YA?AVVector3@G3D@@ABV12@@Z': 0x5ec1a0,
    '??$uvwToObject@$00@RBX@@YA?AVVector3@G3D@@ABV12@@Z': 0x5ec1c0,
    '??$uvwToObject@$01@RBX@@YA?AVVector3@G3D@@ABV12@@Z': 0x6784d0,
    '??$uvwToObject@$02@RBX@@YA?AVVector3@G3D@@ABV12@@Z': 0x5ec1e0,
    '??$uvwToObject@$03@RBX@@YA?AVVector3@G3D@@ABV12@@Z': 0x5ec200,
    '??$uvwToObject@$04@RBX@@YA?AVVector3@G3D@@ABV12@@Z': 0x5ec220,
    '?zero@Vector2@G3D@@SAABV12@XZ': 0x509ba0,                 # function-local static (0, 0) (guard 009735bc)
    '?allocVertex@Mesh@RenderBase@RBX@@SAIABVVector3@G3D@@0ABVVector2@5@_N@Z': 0x548000,
    '?freeVertex@Mesh@RenderBase@RBX@@SAXI@Z': 0x548640,
    '??_U@YAPAXI@Z': 0x6a0956, '??_V@YAXPAX@Z': 0x6a094a,       # operator new[] / delete[] (MFC thunks)
})
NON_EXACT_ROWS = [
    (0x4fd110, '??0SphereMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@@Z',
     'EH state numbering only: the original FuncInfo 008e597c has seven states, 1->0 / 2->0 / 3->2 with no unwind '
     'action before the live 4 (new Level) / 5 (level) / 6 (builder), i.e. three objects of an eliminated block; the '
     'source of that block is not derivable from the bytes', 'sphere'),
    (0x4fdcc0, '??REndcapTransform@ViewNew@RBX@@QAEXAAVVector3@G3D@@0AAVVector2@4@ABV34@ABVVector2int16@4@@Z',
     'x87 register allocation: the original keeps fabs(y) / fabs(x) from the comparison and spills the chosen one '
     'across the xy() call; no tried spelling reproduces the shared tail', 'head'),
    (0x500080, '?buildLeft@HeadBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z',
     'the original reloads elements (+0x24) after storing the functor (no CSE); tried temp / named functor, int / '
     'size_t member, reference parameter', 'head'),
    (0x5000c0, '?buildRight@HeadBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z', 'same as 00500080', 'head'),
    (0x500100, '?buildFront@HeadBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z', 'same as 00500080', 'head'),
    (0x500140, '?buildBack@HeadBuilder@ViewNew@RBX@@MAEXW4Purpose@LevelBuilder@23@@Z', 'same as 00500080', 'head'),
    (0x500350, '??0HeadMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@@Z',
     'register allocation around the null check of new Level (edi preset to 0 in the original)', 'head'),
    (0x5004d0, '??0HeadMesh@ViewNew@RBX@@QAE@ABVVector3@G3D@@W4NormalId@2@ABVVector2@4@@Z', 'same as 00500350', 'head'),
]
UNPROVEN = {
    # EndcapTransform::operator() (a non-exact row of this recorder) is called by the EndcapTransform strips 004fdd90 /
    # 004fe070 (call 004fdeef)
    '??REndcapTransform@ViewNew@RBX@@QAEXAAVVector3@G3D@@0AAVVector2@4@ABV34@ABVVector2int16@4@@Z': 0x4fdcc0,
    # FileMesh::loadFromMeshFile (pending-build-only row, below) is called by FileMesh::create 00500c2e
    LOAD_FROM_MESH_FILE: 0x500780,
}
# Vtable slots whose bodies are not built here (bound to the address the original vtable holds).
SLOT_EXTERNAL = {}

ROWS = {'quad': QUAD_ROWS, 'bevel': BEVEL_ROWS, 'sphere': SPHERE_ROWS, 'cylinder': CYLINDER_ROWS, 'head': HEAD_ROWS,
        'wedge': WEDGE_ROWS, 'torso': TORSO_ROWS, 'pbb': PBB_ROWS, 'filemesh': FILEMESH_ROWS}
for _k in OUTER_ROWS:
    ROWS[_k] = ROWS[_k] + OUTER_ROWS[_k] + STRIP_ROWS[_k]
NON_EXACT_ROWS += STRIP_NON


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


def verify(obj, rows, own, strict=True, record=True, unit=None):
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
            _, sym_value, sym_section, _ = symbols[index]
            if kind == 6 and sym_section == section + 1 and symbol.startswith('$LN'):
                # switch-table entry inside the row: the original entry must name the same offset in the function
                assert value == address + sym_value - start, (name, symbol, hex(value), hex(address + sym_value - start))
                local.add('%s: switch target +%#x verified' % (symbol, sym_value - start))
                continue
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
                assert rtti == '.' + symbol[5:-2], (name, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('__real@'):
                assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
                how = 'constant %s' % symbol[7:]
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert rtti == '.?AV' + cls, (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif (unit, symbol) in UNIT_DATA:
                assert UNIT_DATA[(unit, symbol)] == value, (name, symbol, hex(value))
                pos, at = definitions[symbol]
                compiled = raw[sections[at][4] + pos:sections[at][4] + pos + 4]
                assert original.data(value, 4) == compiled, (name, symbol, hex(value), compiled.hex())
                how = 'unit-local constant %s (bytes)' % compiled.hex()
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
                how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
            elif symbol in UNPROVEN:
                assert UNPROVEN[symbol] == value, (name, symbol, hex(value))
                how = 'call target of a non-exact row'
            else:
                UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
                continue
            if record:
                prev = binding.setdefault((unit, symbol) if (unit, symbol) in UNIT_DATA else symbol, (value, name))
                assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local': sorted(local)})
        result.append(entry)
    return result


resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
non_rows = [(resolve(OBJ[w], [(a, k)]), w) for a, k, _, w in NON_EXACT_ROWS]
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
strict = not DISCOVER
groups = {k: verify(OBJ[k], rows, own, strict, unit=k) for k, rows in resolved.items()}
non_out = []
for (rows, w), (_, _, why, _) in zip(non_rows, NON_EXACT_ROWS):
    if not rows:
        continue
    row = verify(OBJ[w], rows, own, strict=False, record=False, unit=w)[0]
    if row['exact'] and not DISCOVER:
        raise AssertionError('non-exact row unexpectedly exact: %s' % row['address'])
    row['exact'], row['reason'] = False, why
    non_out.append(row)
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in groups.values():
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    for r in non_out:
        if r['exact']:
            print('NOW EXACT', r['address'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- externals named by structure: the bodies they bind to store the expected vtables -------------------------------


def body_has(address, imm):
    body, _, _ = match.target('2008-06', '%08x' % address)
    return struct.pack('<I', imm) in body


assert body_has(0x548570, 0x82d028) and body_has(0x548a90, 0x82d028)   # Mesh ctor / dtor
assert body_has(0x5489b0, 0x826e4c)                                  # ~Level
FUNCTIONS = {int(json.loads(l)['addr'], 16): json.loads(l).get('size') for l in
             (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()} \
    if (ROOT / 'work/2008-06/functions.jsonl').exists() else None
for symbol, address in BUILD_FACE.items():
    assert 0x4fbdb0 <= address <= 0x4ffd40, symbol
    if FUNCTIONS is not None:
        assert address in FUNCTIONS and FUNCTIONS[address] > 600, (symbol, hex(address))
for symbol, address in GRID_FACE.items():
    assert 0x4f2110 <= address < 0x4fa190 or address == 0x4fa190, symbol
    if FUNCTIONS is not None:
        assert address in FUNCTIONS and FUNCTIONS[address] > 600, (symbol, hex(address))
assert original.data(0x826e3c, 4) == struct.pack('<f', 0.05), 'normalPerturbation'
assert original.data(0x826e38, 4) == struct.pack('<f', 0.0), 'BrickMesh::bevel'
# Vector2::zero 00509ba0: a guarded function-local static (0, 0) whose address is returned.
_zero, _, _ = match.target('2008-06', '00509ba0')
assert _zero[-6:-5] == b'\xb8' and _zero[-1:] == b'\xc3' and b'\xd9\xee' in _zero and len(_zero) == 39, _zero.hex()
# uvwToObject<id> bodies (cdecl: [esp+4] result, [esp+8] source): decode fld [ecx+s] / fchs / fstp [eax+d] triples and
# compare with the face mapping of util/NormalId.cpp uvwToObject(v, id) (NORM_Z: the identity copy at 006784d0).
UVW = {0x5ec1a0: ((8, 0), (4, 0), (0, 1)), 0x5ec1c0: ((0, 1), (8, 0), (4, 0)), 0x6784d0: ((0, 0), (4, 0), (8, 0)),
       0x5ec1e0: ((8, 1), (4, 0), (0, 0)), 0x5ec200: ((0, 0), (8, 1), (4, 0)), 0x5ec220: ((0, 1), (4, 0), (8, 1))}
for address, expect in UVW.items():
    body, _, _ = match.target('2008-06', '%08x' % address)
    got, i, pending = {}, 0, None
    while i < len(body) and body[i] != 0xc3:
        if body[i] == 0xd9 and body[i + 1] in (0x01, 0x41):
            pending = [0 if body[i + 1] == 0x01 else body[i + 2], 0]; i += 2 + (body[i + 1] == 0x41)
        elif body[i:i + 2] == b'\xd9\xe0':
            pending[1] = 1; i += 2
        elif body[i] == 0xd9 and body[i + 1] in (0x18, 0x58):
            got[0 if body[i + 1] == 0x18 else body[i + 2]] = tuple(pending); i += 2 + (body[i + 1] == 0x58)
        elif body[i] == 0x8b:
            i += 4
        else:
            raise AssertionError(('uvwToObject body', hex(address), i, body.hex()))
    assert tuple(got[k] for k in (0, 4, 8)) == expect, (hex(address), got)
assert original.vtable_class(0x82d028) == ('.?AVMesh@RenderBase@RBX@@', 0)
assert original.vtable_class(0x826e4c) == ('.?AVLevel@Mesh@RenderBase@RBX@@', 0)

# ---- vtables from the objects built with the current headers, slot by slot -----------------------------------------
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL, UNPROVEN, SLOT_EXTERNAL):
    for k, v in table_.items():
        slot_names.setdefault(k, v)
for address, symbol, _, _ in NON_EXACT_ROWS:
    slot_names.setdefault(symbol, address)    # slot identity only; these rows stay uncounted


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
    out, bad = [], []
    for i, slot in enumerate(compiled_vtable(obj, symbol)):
        value = d(address + 4 * i)
        if slot.startswith('??_E') and '??_G' + slot[4:] in slot_names:
            expect, how = slot_names['??_G' + slot[4:]], 'bound (??_G)'
        elif slot == '__purecall':
            hit = original.imported(value)
            expect, how = (value if hit is not None and hit[1] == '_purecall' else None), 'import _purecall'
        else:
            expect, how = slot_names.get(slot), 'bound'
        ok = expect == value
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value)))
    assert not bad, (symbol, bad)
    return out


vt = {}
for key, cls, address, count in (
        ('quad', 'LevelBuilder@ViewNew@RBX', 0x8270c8, 7),
        ('sphere', 'SphereBuilder@ViewNew@RBX', 0x827134, 7),
        ('sphere', 'SphereMesh@ViewNew@RBX', 0x827154, 1),
        ('sphere', 'Level@Mesh@RenderBase@RBX', 0x826e4c, 1),
        ('cylinder', 'CylinderBuilder@ViewNew@RBX', 0x827164, 7),
        ('cylinder', 'CylinderAlongXMesh@ViewNew@RBX', 0x827184, 1),
        ('head', 'HeadBuilder@ViewNew@RBX', 0x827194, 7),
        ('head', 'HeadMesh@ViewNew@RBX', 0x8271b8, 1),
        ('wedge', 'WedgeBuilder@ViewNew@RBX', 0x8270a8, 7),
        ('wedge', 'WedgeMesh@ViewNew@RBX', 0x8270e8, 1),
        ('torso', 'TorsoBuilder@ViewNew@RBX', 0x827100, 7),
        ('torso', 'TorsoMesh@ViewNew@RBX', 0x827124, 1),
        ('pbb', 'PBBBuilder@ViewNew@RBX', 0x82704c, 7),
        ('pbb', 'PBBMesh@ViewNew@RBX', 0x827070, 1),
        ('filemesh', 'FileMesh@ViewNew@RBX', 0x8271cc, 1)):
    assert original.vtable_class(address) == ('.?AV%s@@' % cls, 0), (cls, original.vtable_class(address))
    vt[cls] = check_vtable(OBJ[key], '??_7%s@@6B@' % cls, address)
    assert len(vt[cls]) == count, (cls, len(vt[cls]))

# ---- RTTI bases (original) and the compiled base class descriptors -------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


RCO = '.?AVReferenceCountedObject@G3D@@'
assert bases(0x8270c8) == {'.?AVLevelBuilder@ViewNew@RBX@@': 0}
for vtable, cls in ((0x827134, 'SphereBuilder'), (0x827164, 'CylinderBuilder'), (0x827194, 'HeadBuilder'),
                    (0x827088, 'Builder@BevelMesh')):
    assert bases(vtable) == {'.?AV%s@ViewNew@RBX@@' % cls: 0, '.?AVLevelBuilder@ViewNew@RBX@@': 0}, cls
for vtable, cls in ((0x827154, 'SphereMesh'), (0x827184, 'CylinderAlongXMesh'), (0x8271b8, 'HeadMesh')):
    assert bases(vtable) == {'.?AV%s@ViewNew@RBX@@' % cls: 0, '.?AVMesh@RenderBase@RBX@@': 0, RCO: 0,
                             '.?AV?$MeshFactory@V%s@ViewNew@RBX@@$00@ViewNew@RBX@@' % cls: 0x89}, cls
    raw = OBJ[{'SphereMesh': 'sphere', 'CylinderAlongXMesh': 'cylinder', 'HeadMesh': 'head'}[cls]].read_bytes()
    _, _, definitions, _ = match._coff_data_index(raw)
    assert '??_R1IJ@?0A@EA@?$MeshFactory@V%s@ViewNew@RBX@@$00@ViewNew@RBX@@8' % cls in definitions, cls
for vtable, cls in ((0x8270a8, 'WedgeBuilder'), (0x827100, 'TorsoBuilder')):
    assert bases(vtable) == {'.?AV%s@ViewNew@RBX@@' % cls: 0, '.?AVBuilder@BevelMesh@ViewNew@RBX@@': 0,
                             '.?AVLevelBuilder@ViewNew@RBX@@': 0}, cls
assert bases(0x82704c) == {'.?AVPBBBuilder@ViewNew@RBX@@': 0, '.?AVLevelBuilder@ViewNew@RBX@@': 0}
for vtable, cls, key, n, extra in ((0x8270e8, 'WedgeMesh', 'wedge', '$00', {'.?AVBevelMesh@ViewNew@RBX@@': 0}),
                                   (0x827124, 'TorsoMesh', 'torso', '$00', {'.?AVBevelMesh@ViewNew@RBX@@': 0}),
                                   (0x827070, 'PBBMesh', 'pbb', '$03', {})):
    expect = {'.?AV%s@ViewNew@RBX@@' % cls: 0, '.?AVMesh@RenderBase@RBX@@': 0, RCO: 0,
              '.?AV?$MeshFactory@V%s@ViewNew@RBX@@%s@ViewNew@RBX@@' % (cls, n): 0x89}
    expect.update(extra)
    assert bases(vtable) == expect, cls
    _, _, definitions, _ = match._coff_data_index(OBJ[key].read_bytes())
    assert '??_R1IJ@?0A@EA@?$MeshFactory@V%s@ViewNew@RBX@@%s@ViewNew@RBX@@8' % (cls, n) in definitions, cls
assert bases(0x8271cc) == {'.?AVFileMesh@ViewNew@RBX@@': 0, '.?AVMesh@RenderBase@RBX@@': 0, RCO: 0}
assert bases(0x826e7c) == {'.?AVBrickMesh@ViewNew@RBX@@': 0, '.?AVMesh@RenderBase@RBX@@': 0, RCO: 0}
assert bases(0x82d028) == {'.?AVMesh@RenderBase@RBX@@': 0, RCO: 0}
assert bases(0x826e4c) == {'.?AVLevel@Mesh@RenderBase@RBX@@': 0, RCO: 0}

# Allocation sizes: the factories push 0x8c before the surface constructors; SphereMesh pushes 0x28 before Level().


def alloc_before(function, size, callee):
    body, _, _ = match.target('2008-06', '%08x' % function)
    at = body.index(b'\x68' + struct.pack('<I', size)) if size > 0x7f else body.index(b'\x6a' + bytes([size]))
    call = body.index(b'\xe8', at)
    while (function + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != callee:
        call = body.index(b'\xe8', call + 1)
    return at


alloc_before(0x4eea30, 0x8c, 0x4fcfb0)
alloc_before(0x4eef30, 0x8c, 0x4fd6b0)
alloc_before(0x4ef430, 0x8c, 0x500180)
alloc_before(0x4fcfb0, 0x28, 0x4dd2e0)
alloc_before(0x4ee030, 0x8c, 0x4f7780)    # WedgeMesh
alloc_before(0x4ee530, 0x8c, 0x4fa590)    # TorsoMesh
alloc_before(0x4edd50, 0x8c, 0x4f49d0)    # PBBMesh (decal)
alloc_before(0x500b90, 0x88, 0x548570)   # FileMesh::create: new 0x88, Mesh(), then the FileMesh vtable 008271cc
assert body_has(0x500b90, 0x8271cc)
for ctor in (0x4f7780, 0x4f78d0, 0x4f7a30, 0x4fa590, 0x4fa700, 0x4fa880, 0x4f49d0, 0x4f4b20):
    alloc_before(ctor, 0x28, 0x4dd2e0)   # new Level(QUADS)

# ---- pending-build-only row: FileMesh::loadFromMeshFile 00500780 ----------------------------------------------------
# It calls ContentProvider::requestContentFile(const ContentId&, Status*, std::string&) 00562670 (thiscall, ret 0xc;
# status 1 = succeeded: cmp [ebp+0x58], 1), which util/NativeContentProvider.h (another owner) does not declare. The
# PENDING build compiles against a generated copy of that header with the proposed declarations; the row is recorded
# exact=false and is not counted. The original keeps the catch funclet (mov eax, 005007e5; ret) right after the extent
# at 00500b7f, so the pending body is compared with the extent plus those 6 bytes.
PENDING_DIR = OUT / 'viewnew-filemesh-pending'
(PENDING_DIR / 'util').mkdir(parents=True, exist_ok=True)
_provider = (R / 'native-headers/util/NativeContentProvider.h').read_text()
_anchor = '    std::string getFile(ContentId);\n'
assert _provider.count(_anchor) == 1
PENDING_DECL = ('    enum Status { Failed, Succeeded, Pending };\n'
                '    void requestContentFile(const ContentId& id, Status* status, std::string& filename);   // 00562670\n'
                '    Status requestContentFile(const ContentId& id, std::string& filename)\n'
                '    {\n        Status status;\n        requestContentFile(id, &status, filename);\n        return status;\n    }\n')
(PENDING_DIR / 'util/NativeContentProvider.h').write_text(_provider.replace(_anchor, _anchor + PENDING_DECL))
pending_obj, FLAGS['filemesh_pending'] = build('NativeViewNew_filemesh_pending', UNITS['filemesh'],
                                               ['/fp:fast', '/DNATIVE_VIEWNEW_FILEMESH_PENDING', '/I' + str(PENDING_DIR)])
_bodies = {n: (b, r) for n, b, r in match.coff_functions(pending_obj.read_bytes())}
_body, _refs = _bodies[LOAD_FROM_MESH_FILE]
_target, _target_refs = target_of(0x500780)
_tail = original.data(0x500780 + len(_target), 6)
assert _tail[:1] == b'\xb8' and _tail[5:] == b'\xc3' and 0x500780 < struct.unpack('<I', _tail[1:5])[0] < 0x500b7f
_pending_exact = match.exact_match(_target + _tail, list(_target_refs) + [len(_target) + 1], _body, _refs)
_create = _bodies[FILEMESH_ROWS[0][1]]
groups['pending'] = [{
    'address': '00500780', 'symbol': LOAD_FROM_MESH_FILE, 'size': len(_body), 'target_size': len(_target),
    'exact': False, 'pending_build_exact': _pending_exact,
    'reason': 'pending-build-only: needs ContentProvider::requestContentFile (00562670) in util/NativeContentProvider.h; '
              'the PENDING body is the extent plus the catch funclet 00500b7f',
}]
assert _pending_exact, 'pending loadFromMeshFile no longer exact'

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT] + list(UNITS.values()) + HEADERS
exact = sorted({r['address'] for k, g in groups.items() if k != 'pending' for r in g if r['exact']})
groups['not_exact'] = non_out
PROPOSALS = {
    'util/NativeContentProvider.h (owner: ContentProvider)': 'declare in class ContentProvider: enum Status { Failed, '
        'Succeeded, Pending }; void requestContentFile(const ContentId&, Status*, std::string&) (00562670, thiscall, '
        'three pointer arguments, ret 0xc) and the inline Status requestContentFile(const ContentId&, std::string&) '
        'wrapper (FileMesh::loadFromMeshFile 00500780 keeps the status in the dead provider argument slot [ebp+0x58], '
        'which the inline wrapper reproduces). Only Succeeded == 1 is derived (cmp [ebp+0x58], 1); the other '
        'enumerator names are the donor hint. Makes 00500780 a counted row.',
    'RenderBase/Mesh.h (new native header, owner: RenderBase)': 'promote ViewNew/RenderBaseMesh.h: Mesh 0x88 '
        '(levels +0xc, ShadowSurface +0x18, debugBoundingRadius +0x4c, std::vector<unsigned short> +0x50, '
        'std::vector<12-byte> +0x68, owned Ogre sub-mesh +0x80, meshKind +0x84), Level 0x28 (indexArray +0xc, '
        'primitive +0x18, dirty +0x1c, +0x20 = -1, sub-mesh +0x24) with the header-inline Level(Primitive) 004dd2e0',
}
receipt = {
    'class': 'RBX::ViewNew::LevelBuilder, BevelMesh::Builder, SphereBuilder/SphereMesh, CylinderBuilder/'
             'CylinderAlongXMesh, HeadBuilder/HeadMesh, WedgeBuilder/WedgeMesh, TorsoBuilder/TorsoMesh, PBBBuilder/'
             'PBBMesh (decal / texture ctors); RBX::RenderBase::Mesh / Mesh::Level (base declarations)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in [layout_obj] + list(OBJ.values())},
    'layout': {k: hex(v) for k, v in SIZES.items()},
    'rows': groups,
    'exact_function_rows': exact,
    'vtables': vt,
    'proposals': PROPOSALS,
    'not_built': {
        '004f4cb0': 'PBBMesh(size, surfaceTypes): after build it calls the unnamed shadow helper 004e3570 (cdecl: half '
                    'size, Mesh +0x68, Mesh +0x50) when the unnamed byte flag 0096de64 is set; no declaration derivable',
        '004e53c0': 'BrickMesh ctor (meshKind 1, ret 0x1c): unnamed helpers 004e2c80 / 004e3720 / 004e3570 and globals '
                    '00942ec4 / 00972758',
        '00826ec4/00826f94/00826ef8/00826f2c': 'ViewNew::PartChunk / Part / Decal / Texture derive from '
                    'RenderBase::Chunk and read PartInstance (+0x1c8, +0x224): other owners',
    },
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/viewnew-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native ViewNew: %d distinct function rows exact (%s); %d non-exact rows not counted; targets and %d '
      'vtables verified' % (len(exact), ', '.join('%s %d' % (k, sum(r['exact'] for r in g))
                                                   for k, g in groups.items() if k not in ('not_exact', 'pending')),
                            len(non_out), len(vt)) + '; 1 pending-build-only row (00500780) not counted')
