"""Verify the inactive native RBX::RenderBase scene pieces (2008-06): Chunk (base members), SceneManager /
SimpleSceneManager, AggregateChunk, AggregatingSceneManager, RenderSceneBase, and RBX::ViewBase / ViewNew::ViewRbxGfx.

Builds (VS2008 RTM 21022), all from the current native headers (native-headers/RenderLib/{AggregateChunk2008,
SceneManager2008,RenderScene2008,ViewBase2008,ViewNew2008}.h; the *2008.h names never shadow a donor header):
  * tests/NativeRenderSceneLayout.cpp      sizeof/offset probes (mov eax, imm32; ret), document-swap flags + /fp:fast;
  * native-classes/SceneManager2008.cpp    document-swap flags (/O2) + /fp:fast: Chunk ctor / dtor / +0x14 accessors,
                                           SceneManager ctor / dtor / ??_G / addToScene / removeFromScene,
                                           SimpleSceneManager (invalidateModel, addModel, removeModel, clear and the
                                           empty setSleeping / prerender);
  * native-classes/AggregateChunk2008.cpp  the RenderBase library profile: /Od /Ob0 /GS (frame pointer, no inlining,
                                           EH frames carry the security cookie 00965cc0: every RenderBase body
                                           0053f0d0..005543b0 is compiled that way) plus the Ogre 1.4.5 client headers
                                           (RenderLib/Material2008.h): AggregateChunk ctor / dtor / ??_G and leaves;
  * native-classes/SceneManagerAggregating2008.cpp  same /Od profile: AggregatingSceneManager ctor / dtor / ??_G /
                                           addModel, BucketKey ctor, Bucket ctor / dtor / ??_G;
  * native-classes/RenderSceneBase2008.cpp document-swap flags + /fp:fast: RenderSceneBase ctor / dtor / ??_G /
                                           presetLighting default;
  * native-classes/RenderSceneViewBase2008.cpp  document-swap flags + /fp:fast: ViewBase ctor / ??_G; built again with
                                           NATIVE_VIEWBASE_PENDING and a generated MaterialFactory header under
                                           out/render-scene-pending for the dtor (pending-build-only, never counted);
  * native-classes/RenderSceneViewRbxGfx2008.cpp  document-swap flags + /fp:fast: ViewRbxGfx leaves;
  * native-classes/RenderSceneNew2008.cpp  document-swap flags + /fp:fast + Ogre 1.4.5 client headers:
                                           RenderNew::RenderScene ??_G / setThrottle / setLighting / presetLighting
                                           (RenderLib/RenderSceneNew2008.h); its ctor is built but not exact (see
                                           NON_EXACT_ROWS). RenderSceneBase2008.cpp also holds Render::RenderScene
                                           (RenderLib/RenderSceneRender2008.h).

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, constants by bytes, vtables by original RTTI
names, own symbols by the row proven here, data by address (each named below with its evidence) and the remaining
externals by the explicit EXTERNAL map (call sites read in the original disassembly). A symbol binds to one address
across all rows. Vtables are compared slot by slot from the objects built with the current headers (never a pending
build). Rows not built here (RenderSceneBase layout / RenderBase::MaterialBase missing) are listed under 'blocked' and are
not counted. Writes work/2008-06/shared-layouts/render-scene-working.json. Set NATIVE_RENDER_SCENE_DISCOVER=1 to list
unbound targets and non-exact rows instead of asserting.
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
LAYOUT = R / 'tests/NativeRenderSceneLayout.cpp'
OGRE = '/I' + str(ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include')
UNITS = {
    'scene': (R / 'native-classes/SceneManager2008.cpp', ['/fp:fast']),
    'aggregate': (R / 'native-classes/AggregateChunk2008.cpp', ['/Od', '/Ob0', '/GS', OGRE]),
    'aggregating': (R / 'native-classes/SceneManagerAggregating2008.cpp', ['/Od', '/Ob0', '/GS', OGRE]),
    'scenebase': (R / 'native-classes/RenderSceneBase2008.cpp', ['/fp:fast', OGRE]),
    'viewbase': (R / 'native-classes/RenderSceneViewBase2008.cpp', ['/fp:fast']),
    'viewrbxgfx': (R / 'native-classes/RenderSceneViewRbxGfx2008.cpp', ['/fp:fast']),
    'scenenew': (R / 'native-classes/RenderSceneNew2008.cpp', ['/fp:fast', OGRE]),
}
HEADERS = [R / 'native-headers/RenderLib/AggregateChunk2008.h', R / 'native-headers/RenderLib/SceneManager2008.h',
           R / 'native-headers/RenderLib/RenderScene2008.h', R / 'native-headers/RenderLib/ViewBase2008.h',
           R / 'native-headers/RenderLib/ViewNew2008.h', R / 'native-headers/RenderLib/RenderSceneRender2008.h',
           R / 'native-headers/RenderLib/RenderSceneNew2008.h']
# Pending build only (never counted): the ViewBase dtor needs a complete 2008 ViewNew::MaterialFactory (owner: the
# ViewNew material-factory recovery); a minimal declaration is generated here, outside the source tree.
PENDING_DIR = OUT / 'render-scene-pending'
PENDING_DIR.mkdir(parents=True, exist_ok=True)
PENDING_HEADER = PENDING_DIR / 'ViewNewMaterialFactoryPending.h'
PENDING_HEADER.write_text('''#pragma once
// Generated by tests/record_native_render_scene.py for the NATIVE_VIEWBASE_PENDING build only (not a source file).
// 2008 ViewNew::MaterialFactory: 0x10 bytes (new 0x10 before its ctor 004f0920), out-of-line dtor 004d7460.
namespace RBX
{
	namespace ViewNew
	{
		class MaterialFactory
		{
		public:
			~MaterialFactory();                                          // 004d7460
		};
	}
}
''')
DISCOVER = bool(os.environ.get('NATIVE_RENDER_SCENE_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeRenderSceneLayout', LAYOUT, ['/fp:fast', OGRE])
OBJ, FLAGS = {}, {'layout': layout_flags}
for key, (src, extra) in UNITS.items():
    OBJ[key], FLAGS[key] = build('NativeRenderScene_' + key, src, extra)
PENDING_OBJ, FLAGS['viewbase_pending'] = build('NativeRenderScene_viewbase_pending', UNITS['viewbase'][0],
                                               ['/fp:fast', '/I' + str(PENDING_DIR), '/DNATIVE_VIEWBASE_PENDING'])

# ---- layout -------------------------------------------------------------------------------------------------------
# Evidence: Chunk ctor 004e8160 (stores +0x4/+0x8 ReferenceCountedObject, +0xc/+0x10 NULL, +0x14 0.0f, +0x18 the
# float argument, +0x1c G3D::inf(), +0x20 weak-pointer vtable 00826ea0 / +0x24 NULL), dtor 004e81d0 (+0xc/+0x10,
# +0x20); AggregateChunk ctor 00551f30 (+0x28/+0x2c RCP ctors, +0x30 CoordinateFrame, +0x60/+0x61 from slots 3/4,
# +0x68 GLight ctor 00514390, +0xb8 VAR ctor 00489470, +0xd8 / +0xe4 Array ctors, +0xf0 std::vector ctor), new 0x108
# at 0053ffc3; SceneManager ctor 004d6f60 (+0x4); new 8 before the inlined SimpleSceneManager ctor (004d9a8a);
# Bucket new 0x24 (0053f3b9), ctor 00540390 (vector +0xc); BucketKey ctor 0053f200 (+0x0 / +0x1 / +0x4 / +0x8);
# AggregatingSceneManager new 0x68 (004dbcf4), ctor 0053f0d0 (map +0x8, sets +0x28 / +0x48).
raw = layout_obj.read_bytes()
SIZES = {
    'chunkSize': 0x28, 'chunkEntity': 0xc, 'chunkSubEntity': 0x10, 'chunkSortValue': 0x14, 'chunkPolygonOffset': 0x18,
    'chunkRadius': 0x1c, 'chunkAggregate': 0x20, 'aggregateChunkSize': 0x108, 'aggregateMaterial': 0x28,
    'aggregateMesh': 0x2c, 'aggregateCframe': 0x30, 'aggregateCastsShadows': 0x60, 'aggregateCullable': 0x61,
    'aggregateShadowSource': 0x68, 'aggregateShadowVAR': 0xb8, 'aggregateShadowIndexArray': 0xd8,
    'aggregateShadowIndexArray16': 0xe4, 'aggregateComponents': 0xf0, 'sceneManagerSize': 0x8,
    'sceneManagerRenderScene': 0x4, 'simpleSceneManagerSize': 0x8, 'bucketSize': 0x24, 'bucketQueue': 0xc,
    'bucketKeySize': 0xc, 'bucketKeyCullable': 0x1, 'bucketKeyPolygonOffset': 0x4, 'bucketKeyMaterial': 0x8,
    'aggregatingSize': 0x68, 'aggregatingBuckets': 0x8, 'aggregatingInvalidSleeping': 0x28,
    'aggregatingInvalidMoving': 0x48,
    # RenderSceneBase: ctor 00504fd0 (+0x8 array, +0x14 Color4, +0x24 / +0x28 floats, RenderStats ctor 00501c30 on
    # +0x30), Render::RenderScene members from +0x268; RenderStats = 6 Stopwatch (0x58, 00512060) + 10 ints;
    # presetLighting ret 0x114 = 4 + LightingParameters + 2 * 0xc.
    'sceneBaseSize': 0x268, 'sceneBaseChunkArray': 0x8, 'sceneBaseColorClearValue': 0x14,
    'sceneBaseShadingQuality': 0x24, 'sceneBaseMeshDetail': 0x28, 'sceneBaseRenderStats': 0x30,
    'renderStatsSize': 0x238, 'lightingParametersSize': 0xf8,
    # ViewBase: ctor 004d8a20 / dtor 004d8920 (see ViewBase2008.h); ViewRbxGfx new 0x4c (0045b3ba), +0x48 bool (ctor
    # 004d99fa, invalidateLighting 004d7180); TextureManager new 0x18 (004d9a38); scoped_connection 0x14.
    'viewBaseSize': 0x48, 'viewBaseSceneManager': 0x4, 'viewBaseRenderLibScene': 0x8, 'viewBaseTextureManager': 0xc,
    'viewBaseMaterialFactory': 0x10, 'viewBaseDataModel': 0x14, 'viewBaseLightingChanged': 0x1c,
    'viewBaseDescendentAdded': 0x30, 'viewBaseLightingValid': 0x44, 'scopedConnectionSize': 0x14,
    'textureManagerSize': 0x18, 'viewRbxGfxSize': 0x4c, 'viewRbxGfxSkyValid': 0x48,
    # Render::RenderScene: new 0x500 (00551820), ctor 00505040 / dtor 00503a60 (RenderSceneRender2008.h);
    # RenderSurface stride 0x44 with the RCP at +0x40 (007aa980), copy ctor 00502500.
    'renderSceneSize': 0x500, 'renderSceneProxyArray': 0x268, 'renderSceneDiffuseProxyArray': 0x274,
    'renderSceneReflectProxyArray': 0x280, 'renderSceneTransparentProxyArray': 0x28c,
    'renderSceneShadowProxyArray': 0x298, 'renderSceneShadowCachingChunkArray': 0x2a4, 'renderSceneShadowVAR': 0x2b0,
    'renderSceneShadowVARArea': 0x2d0, 'renderSceneEffectSettings': 0x2d4, 'renderSceneDesiredLighting': 0x2e8,
    'renderSceneLighting': 0x2ec, 'renderSceneShadows': 0x2f0, 'renderSceneCameraDistance': 0x2f4,
    'renderSceneShadowIndexArray': 0x2f8, 'renderSceneDebugShadowVolumes': 0x304, 'renderSceneSky': 0x308,
    'renderSceneDesiredSkyParameters': 0x310, 'renderSceneSkyParameters': 0x408, 'effectSettingsSize': 0x14,
    'renderSurfaceSize': 0x44, 'renderSurfaceZ': 0x30, 'renderSurfaceMaterial': 0x34,
    'renderSurfacePolygonOffset': 0x38, 'renderSurfaceMesh': 0x3c, 'renderSurfaceFullMesh': 0x40,
    'lightingShadowedLightArray': 0x4c, 'lightingAmbientTop': 0x18,
    # RenderNew::RenderScene: ctor 007aae40 / dtor 007aaa30 / ViewRbxGfx 004dab50 copies (RenderSceneNew2008.h);
    # RenderNew::EffectSettings stores in update 007afce0.
    'renderNewSceneSize': 0x590,
    'renderNewSceneRootNode': 0x268,
    'renderNewSceneEntity': 0x26c,
    'renderNewSceneMaterial': 0x270,
    'renderNewSceneMesh': 0x27c,
    'renderNewSceneProxyArray': 0x288,
    'renderNewSceneShadowProxyArray': 0x2b8,
    'renderNewSceneShadowCachingChunkArray': 0x2c4,
    'renderNewSceneShadowVAR': 0x2d0,
    'renderNewSceneShadowVARArea': 0x2f0,
    'renderNewSceneEffectSettings': 0x2f4,
    'renderNewSceneDesiredLighting': 0x308,
    'renderNewSceneLighting': 0x30c,
    'renderNewSceneShadows': 0x310,
    'renderNewSceneCameraDistance': 0x314,
    'renderNewSceneShadowIndexArray': 0x318,
    'renderNewSceneDebugShadowVolumes': 0x324,
    'renderNewSceneShadowColor': 0x328,
    'renderNewSceneColorShiftTop': 0x338,
    'renderNewSceneColorShiftBottom': 0x344,
    'renderNewSceneBrightness': 0x350,
    'renderNewSceneAmbient': 0x354,
    'renderNewSceneLightingTerm0': 0x360,
    'renderNewSceneLightingTerm4': 0x390,
    'renderNewSceneDesiredSkyParameters': 0x3a0,
    'renderNewSceneSkyParameters': 0x498,
    'renderNewSceneEffectSettingsSize': 0x14,
    'renderNewSceneEffectSettingsFarCullZ': 0x8,
    'renderNewSceneEffectSettingsLODShift': 0x10,
}
for fn, size in SIZES.items():
    name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?native' + fn + '@@'))
    assert body_ == b'\xb8' + struct.pack('<I', size) + b'\xc3', (fn, body_.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

CHUNK_RCP = '?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@'
EXTERNAL = {
    '??3@YAXPAX@Z': 0x6a067a,
    # Ogre::RbxEntity (RTTI .?AVRbxEntity@Ogre@@) unit 0067c890..0067d3d0; called by ~Chunk 004e820a and
    # SimpleSceneManager::invalidateModel 004d7335 (checked below: erases from a std::vector and deletes the argument)
    '?removeSubEntity@RbxEntity@Ogre@@QAEXPAVRbxSubEntity@2@@Z': 0x67d2d0,
    # WeakReferenceCountedPointer<AggregateChunk>::zeroPointer: ICF copy (evidence names the donor Render::Chunk one)
    '?zeroPointer@?$WeakReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@AAEXXZ': 0x4f0840,
    # ReferenceCountedPointer<Mesh> copy constructor (/Od call in getMesh 0055273a): ICF copy (evidence: TextureProxyBase)
    '??0?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@QAE@ABV01@@Z': 0x4f0820,
    # /Od COMDATs called by the Bucket rows (structure checked below)
    '??0ReferenceCountedObject@G3D@@IAE@XZ': 0x472990,        # stores 0081e1e0, zeroes +0x4 / +0x8
    '??1ReferenceCountedObject@G3D@@UAE@XZ': 0x7accf0,        # stores 0081e1e0 (ICF O2 copy)
    '??0noncopyable@noncopyable_@boost@@IAE@XZ': 0x7188c0,    # mov eax, ecx; ret (ICF; evidence: Kernel::getKernel)
    '??1noncopyable@noncopyable_@boost@@IAE@XZ': 0x47d410,    # ret (ICF)
    '?addToScene@SceneManager@RenderBase@RBX@@IAEXABV?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@Z': 0x4d7db0,
    # VS2008 <xutility> / <xmemory> helpers shared by every std container of the exe (/Od COMDAT copies the linker
    # kept; bound to the address the original call uses, bodies checked below where they are trivial)
    '??0_Aux_cont@std@@QAE@QBV_Container_base_aux@1@@Z': 0x6f6a20,
    '??0_Container_base_aux@std@@QAE@XZ': 0x7188c0,           # mov eax, ecx; ret (ICF)
    '??1_Container_base_aux@std@@QAE@XZ': 0x47d410,           # ret (ICF)
    '??2@YAPAXIPAX@Z': 0x401670,                              # placement new (evidence name)
    '?allocate@?$allocator@V_Aux_cont@std@@@std@@QAEPAV_Aux_cont@2@I@Z': 0x4034a0,
    '?deallocate@?$allocator@V_Aux_cont@std@@@std@@QAEXPAV_Aux_cont@2@I@Z': 0x4dc3e0,
    # RCP<Chunk> scalar deleting destructor: the linker kept the O2 copy from the ViewRbxGfx unit (72 bytes, checked
    # below: releases the pointer through ReferenceCountedObject_zeroWeakPointers 0045ad90, then operator delete)
    '??_G?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@QAEPAXI@Z': 0x4d76e0,
    '??0bad_alloc@std@@QAE@PBD@Z': 0x402390,                  # evidence name
    '??0length_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z': 0x402480,
    # --- AggregateChunk / AggregatingSceneManager (/Od callers; O2 or ICF copies the linker kept, bound to the address
    # the original call uses; trivial bodies checked below)
    '??0?$Array@I@G3D@@QAE@XZ': 0x481520,
    '??0?$ReferenceCountedPointer@VMaterialBase@RenderBase@RBX@@@G3D@@QAE@ABV01@@Z': 0x4f0820,
    '??0?$ReferenceCountedPointer@VMaterialBase@RenderBase@RBX@@@G3D@@QAE@XZ': 0x4f0810,
    '??0?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@QAE@XZ': 0x4f0810,
    '??0?$ReferenceCountedPointer@VTextureProxyBase@RBX@@@G3D@@QAE@PAVTextureProxyBase@RBX@@@Z': 0x4e6030,
    '??0CoordinateFrame@G3D@@QAE@XZ': 0x4782d0,              # evidence name
    '??0GLight@G3D@@QAE@XZ': 0x514390,
    '??0VAR@G3D@@QAE@XZ': 0x489470,
    '??1?$Array@G@G3D@@QAE@XZ': 0x6433e0,
    '??1?$Array@I@G3D@@QAE@XZ': 0x6433e0,
    '??1?$ReferenceCountedPointer@VMaterialBase@RenderBase@RBX@@@G3D@@QAE@XZ': 0x502a70,
    '??1?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@QAE@XZ': 0x502a70,
    '??1VAR@G3D@@QAE@XZ': 0x502a70,                           # ICF with ~RCP (VAR's only non-trivial member)
    '??1CoordinateFrame@G3D@@QAE@XZ': 0x47d410,               # ret (ICF)
    '??4?$ReferenceCountedPointer@VMaterialBase@RenderBase@RBX@@@G3D@@QAEAAV01@PAVMaterialBase@RenderBase@RBX@@@Z': 0x4dc4e0,
    '??4?$ReferenceCountedPointer@VMaterialBase@RenderBase@RBX@@@G3D@@QAEABV01@ABV01@@Z': 0x4d7560,
    '??C?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@QBEPAVChunk@RenderBase@RBX@@XZ': 0x71f210,
    '??C?$ReferenceCountedPointer@VMaterialBase@RenderBase@RBX@@@G3D@@QBEPAVMaterialBase@RenderBase@RBX@@XZ': 0x71f210,
    '??HColor3@G3D@@QBE?AV01@ABV01@@Z': 0x501c70,
    '??KColor3@G3D@@QBE?AV01@M@Z': 0x514c40,
    '?wheelRandom@Color3@G3D@@SAABV12@XZ': 0x514a90,
    '?white@Color3@G3D@@SAABV12@XZ': 0x514a60,
    # unnamed material factory (Render / RenderNew Material on the render-mode global 00942ec4); name from the donor
    '?createMaterial@RenderBase@RBX@@YAPAVMaterialBase@12@XZ': 0x551730,
    # AggregatingSceneManager::invalidateModel (/Od): std::set<WeakRCP<Chunk>>::insert (00540291 / 005402d0) and the
    # WeakRCP<Chunk> ctor / dtor callees (/Od COMDATs at the addresses the original rows call)
    '?insert@?$_Tree@V?$_Tset_traits@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@U?$less@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@std@@V?$allocator@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tset_traits@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@U?$less@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@std@@V?$allocator@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@4@$0A@@std@@@std@@_N@2@ABV?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@Z': 0x540b10,
    '??0_WeakPtr@G3D@@QAE@XZ': 0x4e5c00,
    # AggregatingSceneManager::clear / setSleeping (/Od): std::set / std::map COMDATs, Bucket::clear 005404b0,
    # queueSleepingChunk 0053f340 and SceneManager::clearScene (ICF with SimpleSceneManager::clear 004d8310), each
    # bound to the address the original call uses
    '??9const_iterator@?$_Tree@V?$_Tmap_traits@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@U?$less@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@@std@@V?$allocator@U?$pair@$$CBUBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@@std@@@8@$0A@@std@@@std@@QBE_NABV012@@Z': 0x540f20,
    '??C?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@QBEPAVBucket@AggregatingSceneManager@RenderBase@RBX@@XZ': 0x540e80,
    '??Citerator@?$_Tree@V?$_Tmap_traits@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@U?$less@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@@std@@V?$allocator@U?$pair@$$CBUBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@@std@@@8@$0A@@std@@@std@@QBEPAU?$pair@$$CBUBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@@2@XZ': 0x540e90,
    '??Eiterator@?$_Tree@V?$_Tmap_traits@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@U?$less@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@@std@@V?$allocator@U?$pair@$$CBUBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@@std@@@8@$0A@@std@@@std@@QAEAAV012@XZ': 0x540eb0,
    '?begin@?$_Tree@V?$_Tmap_traits@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@U?$less@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@@std@@V?$allocator@U?$pair@$$CBUBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@@std@@@8@$0A@@std@@@std@@QAE?AViterator@12@XZ': 0x54f140,
    '?clear@?$_Tree@V?$_Tset_traits@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@U?$less@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@std@@V?$allocator@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@4@$0A@@std@@@std@@QAEXXZ': 0x540d60,
    '?clear@Bucket@AggregatingSceneManager@RenderBase@RBX@@QAEXXZ': 0x5404b0,
    '?clearScene@SceneManager@RenderBase@RBX@@IAEXXZ': 0x4d8310,
    '?end@?$_Tree@V?$_Tmap_traits@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@U?$less@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@@std@@V?$allocator@U?$pair@$$CBUBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@@std@@@8@$0A@@std@@@std@@QAE?AViterator@12@XZ': 0x5409b0,
    '?queueSleepingChunk@AggregatingSceneManager@RenderBase@RBX@@AAEXABV?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@Z': 0x53f340,
    # AggregatingSceneManager::removeModel (/Od): set erase (0053f5c5 / 0053f5f6), the private helpers
    # deconstructAggregate 005400f0 / dequeueSleepingChunk 0053f470 (bodies not built), and ICF O2 RCP COMDATs
    '?erase@?$_Tree@V?$_Tset_traits@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@U?$less@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@std@@V?$allocator@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@4@$0A@@std@@@std@@QAEIABV?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@Z': 0x540ce0,
    '?deconstructAggregate@AggregatingSceneManager@RenderBase@RBX@@AAEXV?$ReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@@Z': 0x5400f0,
    '?dequeueSleepingChunk@AggregatingSceneManager@RenderBase@RBX@@AAEXABV' + CHUNK_RCP + '@Z': 0x53f470,
    '?createStrongPtr@?$WeakReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@QBE?AV?$ReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@2@XZ': 0x4e6c00,
    '?notNull@?$ReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@QBE_NXZ': 0x402410,                 # xor eax, eax; cmp [ecx], eax; setne al (checked)
    '??1?$ReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@QAE@XZ': 0x502a70,
    '?setPointer@?$ReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@AAEXPAVAggregateChunk@RenderBase@RBX@@@Z': 0x598fa0,
    '??1_WeakPtr@G3D@@UAE@XZ': 0x4e5b30,
    '?getPointer@?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@QBEPAVChunk@RenderBase@RBX@@XZ': 0x71f210,
    '?setPointer@?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@AAEXPAVChunk@RenderBase@RBX@@@Z': 0x542770,
    '?zeroPointer@?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@AAEXXZ': 0x542820,
    # --- RenderSceneBase / ViewBase
    '??0RenderStats@@QAE@XZ': 0x501c30,                       # 6 Stopwatch ctors 00512060 at +0 .. +0x1b8 (checked)
    '?setPointer@?$ReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@AAEXPAVChunk@RenderBase@RBX@@@Z': 0x598fa0,
    '??1scoped_connection@signals@boost@@QAE@XZ': 0x5954b0,   # bound the same way by the Player / Seat / Tool recorders
    '?freeMemory@?$Table@VTextureArgs@TextureManager@G3D@@V?$ReferenceCountedPointer@VTexture@G3D@@@3@@G3D@@AAEXXZ': 0x45c680,  # record_native_adorn.py row
    '??1ViewBase@RBX@@UAE@XZ': 0x4d8920,                      # pending-build-only row (??_G calls it out of line)
    '??1MaterialFactory@ViewNew@RBX@@QAE@XZ': 0x4d7460,
    # --- RenderNew::RenderScene (call sites in the original rows)
    '??1RenderScene@RenderNew@RBX@@UAE@XZ': 0x7aaa30,            # ??_G 007aae23 (dtor not built)
    '?update@EffectSettings@RenderNew@RBX@@QAE?AV?$ReferenceCountedPointer@VLighting@G3D@@@G3D@@MM_NMABV45@ABVLightingParameters@5@AAV65@@Z': 0x7afce0,
    '??0Color4@G3D@@QAE@ABV01@@Z': 0x476550,                    # ctor 007ab068 (checked below: copies 4 floats, ret 4)
    # --- Render::RenderScene (call sites in the original rows; G3D library code and the RCP setPointer ICF copy)
    '??0LightingParameters@G3D@@QAE@XZ': 0x7b6860,           # ctor 0050515e / 00505169 on +0x310 / +0x408
    '??4LightingParameters@G3D@@QAEAAV01@ABV01@@Z': 0x501d80, # evidence name (presetLighting 00503d06)
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,                # RenderSurface copy ctor 00502509 (ret 4; evidence names
                                                             # the ICF-identical Matrix3::operator=)
    '?append@?$Array@VGLight@G3D@@@G3D@@QAEXABVGLight@2@@Z': 0x503000,
    '?create@Lighting@G3D@@SA?AV?$ReferenceCountedPointer@VLighting@G3D@@@2@XZ': 0x503960,
    '?directional@GLight@G3D@@SA?AV12@ABVVector3@2@ABVColor3@2@_N2@Z': 0x514510,   # presetLighting 00503da4
    '?getEnvironmentMap@Sky@G3D@@QBE?AV?$ReferenceCountedPointer@VTexture@G3D@@@2@XZ': 0x502a00,
    '?setPointer@?$ReferenceCountedPointer@VLighting@G3D@@@G3D@@AAEXPAVLighting@2@@Z': 0x598fa0,
    '?setPointer@?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@AAEXPAVMesh@RenderBase@RBX@@@Z': 0x598fa0,
    '?setPointer@?$ReferenceCountedPointer@VSky@G3D@@@G3D@@AAEXPAVSky@2@@Z': 0x598fa0,
    '?setPointer@?$ReferenceCountedPointer@VTexture@G3D@@@G3D@@AAEXPAVTexture@2@@Z': 0x598fa0,
    # EffectSettings::update (donor RenderLib/EffectSettings.h): this = +0x2d4, ret 0x20 (checked below)
    '?update@EffectSettings@Render@RBX@@QAE?AV?$ReferenceCountedPointer@VLighting@G3D@@@G3D@@MM_NMABV45@ABVLightingParameters@5@AAV65@@Z': 0x506dd0,
    # callees of the G3D::Array COMDAT rows (bound to the original call sites)
    '?ReferenceCountedObject_zeroWeakPointers@ReferenceCountedObject@G3D@@QAEXXZ': 0x45ad90,   # evidence name
    '?alignedFree@System@G3D@@SAXPAX@Z': 0x507d20,
    '?init@?$Array@G@G3D@@AAEXHH@Z': 0x47b4e0,
    '?realloc@?$Array@V' + CHUNK_RCP + '@G3D@@AAEXH@Z': 0x475a40,
    '__ftol2_sse': 0x6a17f0,                                  # statically linked CRT helper
    # /Od std::map<BucketKey, ...> / std::set<WeakRCP<Chunk>> ctor / dtor COMDATs called by the AggregatingSceneManager
    # ctor / dtor (each is exact against these addresses in this object, but their _Tree helpers are not bound here)
    '??0?$map@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@U?$less@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@@std@@V?$allocator@U?$pair@$$CBUBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@@std@@@8@@std@@QAE@XZ': 0x540800,
    '??0?$set@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@U?$less@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@std@@V?$allocator@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@4@@std@@QAE@XZ': 0x540a80,
    '??1?$map@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@U?$less@UBucketKey@AggregatingSceneManager@RenderBase@RBX@@@std@@V?$allocator@U?$pair@$$CBUBucketKey@AggregatingSceneManager@RenderBase@RBX@@V?$ReferenceCountedPointer@VBucket@AggregatingSceneManager@RenderBase@RBX@@@G3D@@@std@@@8@@std@@QAE@XZ': 0x540330,
    '??1?$set@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@U?$less@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@std@@V?$allocator@V?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@@4@@std@@QAE@XZ': 0x540350,
}
DATA = {
    '?chunkCount@RenderStats@@2HA': 0x97288c,          # ++ in Chunk() 004e81b2, -- in ~Chunk() 004e81f5
    '?i@?1??inf@G3D@@YAABNXZ@4NB': 0x96f018,           # G3D::inf() local static (Chunk ctor 004e8199 / 004e819f)
    '??_B?1??inf@G3D@@YAABNXZ@51': 0x96f020,           # its init guard (004e8181 / 004e8189)
    '___security_cookie': 0x965cc0,                    # /GS cookie (holds the CRT default 0xbb40e64e)
    '__TI3?AVlength_error@std@@': 0x8d0cc0,            # throw info of std::length_error (checked below)
    '__TI2?AVbad_alloc@std@@': 0x8d07d8,               # throw info of std::bad_alloc (checked below)
    '__TI1?AVexception@std@@': 0x8d997c,               # throw info of std::exception (checked below)
    '?aggregateChunkCount@RenderStats@@2HA': 0x972894, # ++ in AggregateChunk() 0055208a, -- in ~AggregateChunk() 005521a5
    '?aggregatedChunkCount@RenderStats@@2HA': 0x972890, # -= components.size() in ~AggregateChunk() 005521c2
    '?randomColors@AggregateChunk@RenderBase@RBX@@2_NA': 0x9738a0,
    # Array<RCP<Chunk>>::resize local static minSize and its init guard (resize 004d7890)
    '?minSize@?3??resize@?$Array@V' + CHUNK_RCP + '@G3D@@QAEXH_N@Z@4HB': 0x972718,
    '??_B?3??resize@?$Array@V' + CHUNK_RCP + '@G3D@@QAEXH_N@Z@53': 0x97271c,  # tested twice in AggregateChunk() 0055203b / 005520a6
}
FOLDED = {}
# Rows at shared (ICF) addresses: 00458e90 is a generic `ret 8` body; 004e5b70 is also Block::getRadius (evidence
# name); 004d7350 serves both SceneManager and SimpleSceneManager. Each counts once as a distinct address.
LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}

SCENE_ROWS = [
    (0x4e8160, '??0Chunk@RenderBase@RBX@@QAE@M@Z'),
    (0x4e81d0, '??1Chunk@RenderBase@RBX@@UAE@XZ'),
    (0x4e5b60, '?setSortValue@Chunk@RenderBase@RBX@@UAEXM@Z'),
    (0x4e5b70, '?getSortValue@Chunk@RenderBase@RBX@@UBEMXZ'),
    (0x4d6f60, '??0SceneManager@RenderBase@RBX@@IAE@PAVRenderSceneBase@12@@Z'),
    (0x4d6f50, '??1SceneManager@RenderBase@RBX@@UAE@XZ'),
    (0x4d7350, '??_GSceneManager@RenderBase@RBX@@UAEPAXI@Z'),
    (0x4d7350, '??_GSimpleSceneManager@RenderBase@RBX@@UAEPAXI@Z'),
    (0x4d7320, '?invalidateModel@SimpleSceneManager@RenderBase@RBX@@UAEXABV' + CHUNK_RCP + '_N@Z'),
    (0x458e90, '?setSleeping@SimpleSceneManager@RenderBase@RBX@@UAEXABV' + CHUNK_RCP + '_N@Z'),
    (0x458e90, '?prerender@SimpleSceneManager@RenderBase@RBX@@UAEXN@Z'),
    # RenderSceneBase chunk array (RenderLib/RenderScene2008.h): SimpleSceneManager::addModel has addToScene inlined
    # and is the same 11 bytes (one address, 004d7db0); removeModel tail-calls removeFromScene; clear inlines clearScene.
    (0x4d7db0, '?addToScene@SceneManager@RenderBase@RBX@@IAEXABV' + CHUNK_RCP + '@Z'),
    (0x4d7db0, '?addModel@SimpleSceneManager@RenderBase@RBX@@UAEXABV' + CHUNK_RCP + '@Z'),
    (0x4d8320, '?removeFromScene@SceneManager@RenderBase@RBX@@IAEXABV' + CHUNK_RCP + '@Z'),
    (0x4d8380, '?removeModel@SimpleSceneManager@RenderBase@RBX@@UAEXABV' + CHUNK_RCP + '@Z'),
    (0x4d8310, '?clear@SimpleSceneManager@RenderBase@RBX@@UAEXXZ'),
    # O2 G3D::Array<RCP<Chunk>> COMDATs called by addToScene / removeFromScene / clear
    (0x4d7ae0, '?append@?$Array@V' + CHUNK_RCP + '@G3D@@QAEXABV' + CHUNK_RCP[:-6] + '@2@@Z'),
    (0x4d7890, '?resize@?$Array@V' + CHUNK_RCP + '@G3D@@QAEXH_N@Z'),
]
AGGREGATE_ROWS = [
    (0x5526d0, '?cachesShadows@AggregateChunk@RenderBase@RBX@@UBE_NXZ'),
    (0x552690, '?castsShadows@AggregateChunk@RenderBase@RBX@@UBE_NXZ'),
    (0x5526b0, '?cullable@AggregateChunk@RenderBase@RBX@@UBE_NXZ'),
    (0x552720, '?getMesh@AggregateChunk@RenderBase@RBX@@UAE?AV?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@XZ'),
    (0x552760, '?cframe@AggregateChunk@RenderBase@RBX@@UAEABVCoordinateFrame@G3D@@XZ'),
    (0x5526e0, '?getMaterial@AggregateChunk@RenderBase@RBX@@UAE?AV?$ReferenceCountedPointer@VMaterialBase@RenderBase@RBX@@@G3D@@XZ'),
    (0x551f30, '??0AggregateChunk@RenderBase@RBX@@QAE@ABV' + CHUNK_RCP + '@Z'),
    (0x552160, '??1AggregateChunk@RenderBase@RBX@@UAE@XZ'),
    (0x552780, '??_GAggregateChunk@RenderBase@RBX@@UAEPAXI@Z'),
    (0x5527f0, '??0?$Array@G@G3D@@QAE@XZ'),                            # /Od COMDAT (ctor of shadowIndexArray16)
    (0x546320, '?size@?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@QBEIXZ'),
]
AGGREGATING_ROWS = [
    (0x53f0d0, '??0AggregatingSceneManager@RenderBase@RBX@@QAE@PAVRenderSceneBase@12@@Z'),
    (0x53f160, '??1AggregatingSceneManager@RenderBase@RBX@@UAE@XZ'),
    (0x540300, '??_GAggregatingSceneManager@RenderBase@RBX@@UAEPAXI@Z'),
    (0x53f200, '??0BucketKey@AggregatingSceneManager@RenderBase@RBX@@QAE@ABV' + CHUNK_RCP + '@Z'),
    (0x540390, '??0Bucket@AggregatingSceneManager@RenderBase@RBX@@QAE@XZ'),
    (0x540440, '??1Bucket@AggregatingSceneManager@RenderBase@RBX@@UAE@XZ'),
    (0x540410, '??_GBucket@AggregatingSceneManager@RenderBase@RBX@@UAEPAXI@Z'),
    (0x53f1e0, '?addModel@AggregatingSceneManager@RenderBase@RBX@@UAEXABV' + CHUNK_RCP + '@Z'),
    (0x540240, '?invalidateModel@AggregatingSceneManager@RenderBase@RBX@@UAEXABV' + CHUNK_RCP + '_N@Z'),
    (0x53f580, '?removeModel@AggregatingSceneManager@RenderBase@RBX@@UAEXABV' + CHUNK_RCP + '@Z'),
    (0x53f6a0, '?clear@AggregatingSceneManager@RenderBase@RBX@@UAEXXZ'),
    (0x53fa50, '?setSleeping@AggregatingSceneManager@RenderBase@RBX@@UAEXABV' + CHUNK_RCP + '_N@Z'),
    (0x5410d0, '??0?$ReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@QAE@ABV01@@Z'),     # /Od RCP<AggregateChunk> copy ctor (by-value argument 0053f640)
    # /Od WeakReferenceCountedPointer<Chunk> COMDATs called by invalidateModel (vtable 0082cf04 checked by RTTI)
    (0x540fb0, '??0?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@QAE@ABV' + CHUNK_RCP[:-6] + '@1@@Z'),
    (0x541030, '??1?$WeakReferenceCountedPointer@VChunk@RenderBase@RBX@@@G3D@@UAE@XZ'),
    (0x540560, '??0?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@QAE@XZ'),
    (0x5405d0, '??1?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@QAE@XZ'),
    (0x54e310, '??0?$allocator@V' + CHUNK_RCP + '@std@@QAE@XZ'),
    (0x54da40, '??0?$_Vector_val@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@IAE@V?$allocator@V'
               + CHUNK_RCP + '@1@@Z'),
    (0x5411c0, '??1?$_Vector_val@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@QAE@XZ'),
    (0x5530e0, '?_Buy@?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@IAE_NI@Z'),
    (0x5414d0, '?_Tidy@?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@IAEXXZ'),
    (0x54ef60, '??0?$_Container_base_aux_alloc_real@V?$allocator@V' + CHUNK_RCP + '@std@@@std@@IAE@V?$allocator@V'
               + CHUNK_RCP + '@1@@Z'),
    (0x553220, '??0?$allocator@V' + CHUNK_RCP + '@std@@QAE@ABV01@@Z'),
    (0x541580, '??1?$_Container_base_aux_alloc_real@V?$allocator@V' + CHUNK_RCP + '@std@@@std@@IAE@XZ'),
    (0x5414a0, '?_Destroy@?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@IAEXPAV' + CHUNK_RCP
               + '0@Z'),
    (0x553270, '?_Xlen@?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@KAXXZ'),
    (0x542de0, '?allocate@?$allocator@V' + CHUNK_RCP + '@std@@QAEPAV' + CHUNK_RCP + 'I@Z'),
    (0x543610, '?deallocate@?$allocator@V' + CHUNK_RCP + '@std@@QAEXPAV' + CHUNK_RCP + 'I@Z'),
    (0x542a30, '?max_size@?$vector@V' + CHUNK_RCP + 'V?$allocator@V' + CHUNK_RCP + '@std@@@std@@QBEIXZ'),
    (0x553220, '??$?0V' + CHUNK_RCP + '@?$allocator@V_Aux_cont@std@@@std@@QAE@ABV?$allocator@V' + CHUNK_RCP + '@1@@Z'),
    (0x546070, '??$_Allocate@V' + CHUNK_RCP + '@std@@YAPAV' + CHUNK_RCP + 'IPAV12@@Z'),
    (0x545f10, '??$_Destroy_range@V?$allocator@V' + CHUNK_RCP + '@std@@@std@@YAXPAV' + CHUNK_RCP
               + '0AAV?$allocator@V' + CHUNK_RCP + '@0@@Z'),
    (0x5446f0, '?max_size@?$allocator@V' + CHUNK_RCP + '@std@@QBEIXZ'),
    (0x5469b0, '??$_Destroy_range@V?$allocator@V' + CHUNK_RCP + '@std@@@std@@YAXPAV' + CHUNK_RCP
               + '0AAV?$allocator@V' + CHUNK_RCP + '@0@U_Nonscalar_ptr_iterator_tag@0@@Z'),
    (0x546900, '??$_Ptr_cat@PAV' + CHUNK_RCP + 'PAV12@@std@@YA?AU_Nonscalar_ptr_iterator_tag@0@AAPAV' + CHUNK_RCP
               + '0@Z'),
    (0x546d20, '?destroy@?$allocator@V' + CHUNK_RCP + '@std@@QAEXPAV' + CHUNK_RCP + '@Z'),
    (0x546fd0, '??$_Destroy@V' + CHUNK_RCP + '@std@@YAXPAV' + CHUNK_RCP + '@Z'),
]
SCENEBASE_ROWS = [
    (0x504fd0, '??0RenderSceneBase@RenderBase@RBX@@QAE@XZ'),
    (0x5039d0, '??1RenderSceneBase@RenderBase@RBX@@UAE@XZ'),
    (0x503a30, '??_GRenderSceneBase@RenderBase@RBX@@UAEPAXI@Z'),
    (0x5039e0, '?presetLighting@RenderSceneBase@RenderBase@RBX@@UAEXV?$ReferenceCountedPointer@VSky@G3D@@@G3D@@'
               'VLightingParameters@5@VColor3@5@2@Z'),
    (0x475f20, '??1?$Array@V' + CHUNK_RCP + '@G3D@@QAE@XZ'),
    # Render::RenderScene (RenderLib/RenderSceneRender2008.h)
    (0x505040, '??0RenderScene@Render@RBX@@QAE@XZ'),
    (0x503a60, '??1RenderScene@Render@RBX@@UAE@XZ'),
    (0x503fc0, '??_GRenderScene@Render@RBX@@UAEPAXI@Z'),
    (0x502d30, '?setThrottle@RenderScene@Render@RBX@@UAEXMM_NM@Z'),
    (0x502e70, '?setLighting@RenderScene@Render@RBX@@QAEXABV?$ReferenceCountedPointer@VLighting@G3D@@@G3D@@@Z'),
    (0x503cc0, '?presetLighting@RenderScene@Render@RBX@@UAEXV?$ReferenceCountedPointer@VSky@G3D@@@G3D@@'
               'VLightingParameters@5@VColor3@5@2@Z'),
    (0x505220, '?materialPtrSortProc@Render@RBX@@YA_NABQAVRenderSurface@12@0@Z'),
    (0x5051e0, '?materialDepthPtrSortProc@Render@RBX@@YA_NABQAVRenderSurface@12@0@Z'),
    (0x505240, '?depthPtrSortProc@Render@RBX@@YA_NABQAVRenderSurface@12@0@Z'),
    (0x505860, '?sortByMaterialAndDepth@Render@RBX@@YAXAAV?$Array@PAVRenderSurface@Render@RBX@@@G3D@@@Z'),
    (0x505890, '?sortByMaterial@Render@RBX@@YAXAAV?$Array@PAVRenderSurface@Render@RBX@@@G3D@@@Z'),
    (0x5058c0, '?sortByDepth@Render@RBX@@YAXAAV?$Array@PAVRenderSurface@Render@RBX@@@G3D@@@Z'),
    # std::sort<RenderSurface**, bool (*)(RenderSurface* const&, RenderSurface* const&)> helpers (evidence names)
    (0x505780, '??$_Sort@PAPAVRenderSurface@Render@RBX@@'),
    (0x505270, '??$_Push_heap@PAPAVRenderSurface@Render@RBX@@'),
    (0x5052e0, '??$_Med3@PAPAVRenderSurface@Render@RBX@@'),
    (0x505340, '??$_Adjust_heap@PAPAVRenderSurface@Render@RBX@@'),
    (0x5053b0, '??$_Median@PAPAVRenderSurface@Render@RBX@@'),
    (0x505460, '??$_Make_heap@PAPAVRenderSurface@Render@RBX@@'),
    (0x5054a0, '??$_Insertion_sort1@PAPAVRenderSurface@Render@RBX@@'),
    (0x505570, '??$_Unguarded_partition@PAPAVRenderSurface@Render@RBX@@'),
    (0x505730, '??$_Sort_heap@PAPAVRenderSurface@Render@RBX@@'),
    (0x502500, '??0RenderSurface@Render@RBX@@QAE@ABV012@@Z'),
    (0x7aa980, '??1?$Array@VRenderSurface@Render@RBX@@@G3D@@QAE@XZ'),
]
SCENENEW_ROWS = [
    # RenderNew::RenderScene (RenderLib/RenderSceneNew2008.h)
    (0x7aae20, '??_GRenderScene@RenderNew@RBX@@UAEPAXI@Z'),
    (0x7aa770, '?setThrottle@RenderScene@RenderNew@RBX@@UAEXMM_NM@Z'),
    (0x7aa8b0, '?setLighting@RenderScene@RenderNew@RBX@@QAEXABV?$ReferenceCountedPointer@VLighting@G3D@@@G3D@@@Z'),
    (0x7aacc0, '?presetLighting@RenderScene@RenderNew@RBX@@UAEXV?$ReferenceCountedPointer@VSky@G3D@@@G3D@@'
               'VLightingParameters@5@VColor3@5@2@Z'),
]
VIEWBASE_ROWS = [
    (0x4d8a20, '??0ViewBase@RBX@@IAE@V?$shared_ptr@VDataModel@RBX@@@boost@@@Z'),
    (0x4d8ac0, '??_GViewBase@RBX@@UAEPAXI@Z'),
]
VIEWRBXGFX_ROWS = [
    (0x4d76d0, '?getMeshDetail@ViewRbxGfx@ViewNew@RBX@@UBEMXZ'),
    (0x4db660, '?updateSettings@ViewRbxGfx@ViewNew@RBX@@UAEXMM_NM@Z'),
    (0x4db6f0, '?getRenderStats@ViewRbxGfx@ViewNew@RBX@@UAEAAVRenderStats@@XZ'),
    (0x4d7180, '?invalidateLighting@ViewRbxGfx@ViewNew@RBX@@EAEX_N@Z'),
]
# Exact bodies at addresses whose code is ICF-shared with functions other recorders count (or a generic `ret`):
# verified with every target like a row, but not counted here. 00503cb0 / 007b76d0 are counted by
# record_native_render_material.py (Material::Level accessors), 0064a390 by record_native_kernel_stages.py.
FOLDED_ROWS = {
    'scenebase': [(0x503cb0, '?getShadingQuality@RenderSceneBase@RenderBase@RBX@@UBEMXZ'),
                  (0x7b76d0, '?getMeshDetail@RenderSceneBase@RenderBase@RBX@@UBEMXZ')],
    'viewrbxgfx': [(0x64a390, '?getShadingQuality@ViewRbxGfx@ViewNew@RBX@@UBEMXZ'),
                   (0x47d410, '?updateLighting@ViewRbxGfx@ViewNew@RBX@@EAEXXZ')],
}
PENDING_ROWS = [(0x4d8920, '??1ViewBase@RBX@@UAE@XZ')]
PENDING_REASON = ('pending-build-only: ~ViewBase destroys the auto_ptr<ViewNew::MaterialFactory> member, whose 2008 class '
                  '(0x10 bytes, dtor 004d7460, ctor 004f0920) is not declared; built with a generated header under '
                  'out/render-scene-pending (NATIVE_VIEWBASE_PENDING) and never counted')
# Built and compared, never counted (the row must stay non-exact; if it becomes exact, move it to its ROWS list).
NON_EXACT_ROWS = [
    ('scenenew', 0x7aae40, '??0RenderScene@RenderNew@RBX@@QAE@XZ',
     'RenderNew::RenderScene ctor: identical except the colorClearValue assignment at the end. The original copies the '
     '(0.5, 0.5, 1, 1) Color4 through an out-of-line copy ctor call (007ab068 -> 00476550, the ICF copy also called by '
     'G3D 00511070), so the 2008 G3D Color4 copy ctor was not inline; the donor G3D Color4.inl defines it inline and '
     'this build inlines it (560 vs 606 bytes, frame 8 vs 0x28). Needs the 2008 G3D Color4 declaration (tools/, read-only).'),
]
UNPROVEN = {}
# Vtable slots whose bodies are not built here (bound to the address the original vtable holds; see BLOCKED).
SLOT_EXTERNAL = {
    '?renderShadows@AggregateChunk@RenderBase@RBX@@UAEXPAVRenderDevice@G3D@@ABVGLight@5@_NM@Z': 0x552300,
    '?prerender@AggregatingSceneManager@RenderBase@RBX@@UAEXN@Z': 0x53fc00,
    '?render@RenderScene@Render@RBX@@UAEXPAVRenderDevice@G3D@@ABVGCamera@5@@Z': 0x504bf0,
    '?render@RenderScene@RenderNew@RBX@@UAEXPAVRenderDevice@G3D@@ABVGCamera@5@@Z': 0x7ab0a0,
}
BLOCKED = {
    '004d8920': 'ViewBase dtor: exact only in the NATIVE_VIEWBASE_PENDING build (2008 ViewNew::MaterialFactory missing)',
    '004d9990': 'ViewRbxGfx ctor: MaterialFactory ctor (RenderNew::RenderScene is declared in RenderSceneNew2008.h, but its ctor '
                '007aae40 is not exact), Lighting::event_LightingChanged and '
                'Instance::event_descendentAdded connections (DataModel / Workspace / Lighting owners)',
    '004db4f0': 'ViewRbxGfx dtor: ServiceProvider::create<Lighting> 004b3380 and the ViewNew mesh-cache flushes '
                '004db130 / 004db040 / 004daf50 / 004e5670 / 004db310 / 004db220 / 004db400 (other owners); its ??_G '
                '004db5d0 is emitted only with the vtable (ctor / dtor)',
    '004daf10': 'ViewRbxGfx::render: Workspace +0x288 camera interface (Workspace owner) and 004dab50',
    '004d9c90': 'ViewRbxGfx::suppressSkybox: Lighting service (owner) accessors',
    '004d7370': 'ViewRbxGfx/ViewG3D::getWorkspace: Workspace* -> Instance* needs the complete Workspace (owner)',
    '004db7c0': 'ViewRbxGfx/ViewG3D::onWorkspaceDescendentAdded: PartInstance / Decal views (other owners)',
    '004dbbe0': 'ViewG3D ctor: map member +0x4c key / value types not derived. Its tree ctor 00446110, head node 0056d3d0 '
                '(new 0x18: 8-byte value) and erase 00553ca0 are ICF-shared bodies with no value dtor, so they fix only a '
                'trivially destructible 8-byte value_type; +0x48 is a ReferenceCountedPointer<G3D::Sky> (updateLighting '
                '004dc0eb). Also the Lighting / DataModel connections (other owners)',
    '004dc270': 'ViewG3D dtor (and ??_G 004dc340): same map member, plus the Lighting / mesh-cache calls',
    '004db610': 'ViewG3D::invalidateLighting: the ViewG3D class needs the +0x4c map type to be declared',
    '004db690': 'ViewG3D::render: Workspace +0x288 camera interface (Workspace owner)',
    '007aaa30': 'RenderNew::RenderScene dtor: deletes the Ogre::RbxSceneNode (+0x268, via its creator root node) and '
                'Ogre::RbxEntity (+0x26c) forks, which are owned by the Ogre fork recoveries and not declared here',
    '007ab0a0': 'RenderNew::RenderScene::render (7199 bytes): Ogre camera / RbxSceneNode / RbxEntity calls (Ogre fork owners)',
    '00504bf0': 'Render::RenderScene::render: the G3D draw path (RenderDevice state, shadow volumes) is not built',
}

ROWS = {'scene': SCENE_ROWS, 'aggregate': AGGREGATE_ROWS, 'aggregating': AGGREGATING_ROWS,
        'scenebase': SCENEBASE_ROWS, 'viewbase': VIEWBASE_ROWS, 'viewrbxgfx': VIEWRBXGFX_ROWS,
        'scenenew': SCENENEW_ROWS}


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
                prev = binding.setdefault(symbol, (value, name))
                assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local': sorted(local)})
        result.append(entry)
    return result


resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
folded_resolved = {k: resolve(OBJ[k], rows) for k, rows in FOLDED_ROWS.items()}
own = {}
for rows in list(resolved.values()) + list(folded_resolved.values()):
    for address, name in rows:
        own.setdefault(name, address)
strict = not DISCOVER
groups = {k: verify(OBJ[k], rows, own, strict) for k, rows in resolved.items()}
folded_rows = [r for k, rows in folded_resolved.items() for r in verify(OBJ[k], rows, own, strict)]
pending_rows = verify(PENDING_OBJ, resolve(PENDING_OBJ, PENDING_ROWS), own, strict=False, record=False)
for row in pending_rows:
    row['exact_in_pending_build'] = row['exact']
    row['exact'] = False
    row['reason'] = PENDING_REASON
non_out = []
for key_, address_, symbol_, reason_ in NON_EXACT_ROWS:
    for row in verify(OBJ[key_], resolve(OBJ[key_], [(address_, symbol_)]), own, strict=False, record=False):
        assert not row['exact'], ('now exact: move it to its ROWS list', row['address'])
        row['reason'] = reason_
        non_out.append(row)
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in groups.values():
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- externals named by structure ------------------------------------------------------------------------------------


def body_has(address, imm):
    body, _, _ = match.target('2008-06', '%08x' % address)
    return struct.pack('<I', imm) in body


# 0067d2d0: compares its argument with the std::vector elements, memmoves the tail, and calls the argument's
# virtual deleting destructor with 1 (push 1; call [vtable+0]); the vector sits at +0xd8..+0xe8 of the entity.
body, _, _ = match.target('2008-06', '0067d2d0')
assert b'\x8b\xae\xe8\x00\x00\x00' in body and b'\xff\x15\x50\x28\x80\x00' in body   # mov ebp, [esi+0xe8]; memmove
assert b'\x6a\x01\x8b\xcd\xff\xd2' in body
for address, imm in ((0x472990, 0x81e1e0), (0x7accf0, 0x81e1e0)):
    assert body_has(address, imm), hex(address)                     # ReferenceCountedObject ctor / dtor
assert match.target('2008-06', '007188c0')[0] == bytes.fromhex('8bc1c3')    # trivial ctors (ICF)
assert match.target('2008-06', '0047d410')[0] == bytes.fromhex('c3')        # trivial dtors (ICF)
body, _, _ = match.target('2008-06', '004d76e0')                             # RCP<Chunk>::`scalar deleting dtor'
assert b'\xe8' + struct.pack('<i', 0x45ad90 - 0x4d76fe) in body and b'\xe8' + struct.pack('<i', 0x6a067a - 0x4d771f) in body


def throw_info(address, count, first):
    cta = d(address + 12)
    assert d(cta) == count, (hex(address), d(cta))
    assert original.string(d(d(cta + 4) + 4) + 8) == first, hex(address)


throw_info(0x8d0cc0, 3, '.?AVlength_error@std@@')
throw_info(0x8d07d8, 2, '.?AVbad_alloc@std@@')
throw_info(0x8d997c, 1, '.?AVexception@std@@')
assert original.string(0x82743c) == "shouldn't be here"
assert match.target('2008-06', '00506dd0')[0].endswith(bytes.fromhex('c22000'))   # EffectSettings::update: ret 0x20
assert match.target('2008-06', '007afce0')[0].endswith(bytes.fromhex('c22000'))   # RenderNew::EffectSettings::update
assert match.target('2008-06', '00476550')[0] == bytes.fromhex('8bc18b4c2404d901d918d94104d95804d94108d95808d9410cd9580cc20400')
assert match.target('2008-06', '00513220')[0].endswith(bytes.fromhex('c20400'))   # Matrix3 copy: one argument
assert match.target('2008-06', '00402410')[0] == bytes.fromhex('33c03901 0f95c0c3'.replace(' ', ''))   # RCP::notNull
# trivial / structural externals of the new rows
assert match.target('2008-06', '0071f210')[0] == bytes.fromhex('8b01c3')     # RCP::operator-> (mov eax, [ecx]; ret)
assert match.target('2008-06', '00514a60')[0].endswith(bytes.fromhex('b868379700c3'))   # Color3::white static
body, _, _ = match.target('2008-06', '00501c30')                             # RenderStats(): 6 Stopwatch ctors
assert body.count(b'\xe8') == 6 and all(b'\xe8' + struct.pack('<i', 0x512060 - (0x501c30 + i + 5)) == body[i:i + 5]
                                         for i in (3, 0xb, 0x16, 0x21, 0x2c, 0x37))
for address in (0x4dc4e0, 0x4d7560, 0x4e6030):                             # RCP operator= / ctor(T*) -> setPointer
    b_, _, _ = match.target('2008-06', '%08x' % address)
    at = b_.index(b'\xe8')
    assert (address + at + 5 + struct.unpack_from('<i', b_, at + 1)[0]) & 0xffffffff == 0x598fa0, hex(address)
body, _, _ = match.target('2008-06', '00551730')                             # createMaterial: new 0x18 + Material ctors
assert b'\x6a\x18' in body and body_has(0x551730, 0x942ec4)
for ctor in (0x7ad960, 0x7b80a0):
    assert any((0x551730 + i + 5 + struct.unpack_from('<i', body, i + 1)[0]) & 0xffffffff == ctor
               for i in range(len(body) - 5) if body[i] == 0xe8), hex(ctor)
assert original.vtable_class(0x826ea0) == ('.?AV?$WeakReferenceCountedPointer@VAggregateChunk@RenderBase@RBX@@@G3D@@', 0)
assert body_has(0x4e8160, 0x826ea0) and body_has(0x4e81d0, 0x826ea0)

# ---- vtables from the objects built with the current headers, slot by slot -----------------------------------------
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
        ('scene', 'SceneManager@RenderBase@RBX', 0x826b44, 7),
        ('scene', 'SimpleSceneManager@RenderBase@RBX', 0x826b64, 7),
        ('aggregating', 'Bucket@AggregatingSceneManager@RenderBase@RBX', 0x82cef0, 1),
        ('aggregating', 'AggregatingSceneManager@RenderBase@RBX', 0x82ced0, 7),
        ('aggregate', 'AggregateChunk@RenderBase@RBX', 0x82d258, 10),
        ('scenebase', 'RenderSceneBase@RenderBase@RBX', 0x827424, 6),
        ('scenebase', 'RenderScene@Render@RBX', 0x827454, 6),
        ('scenenew', 'RenderScene@RenderNew@RBX', 0x8749dc, 6),
        ('viewbase', 'ViewBase@RBX', 0x826c24, 11)):
    assert original.vtable_class(address) == ('.?AV%s@@' % cls, 0), (cls, original.vtable_class(address))
    vt[cls] = check_vtable(OBJ[key], '??_7%s@@6B@' % cls, address)
    assert len(vt[cls]) == count, (cls, len(vt[cls]))

# ---- RTTI bases (original) -------------------------------------------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


RCO = '.?AVReferenceCountedObject@G3D@@'
assert bases(0x826b44) == {'.?AVSceneManager@RenderBase@RBX@@': 0}
assert bases(0x826b64) == {'.?AVSimpleSceneManager@RenderBase@RBX@@': 0, '.?AVSceneManager@RenderBase@RBX@@': 0}
assert bases(0x82cef0) == {'.?AVBucket@AggregatingSceneManager@RenderBase@RBX@@': 0, RCO: 0,
                           '.?AVnoncopyable@noncopyable_@boost@@': 0xc}
assert bases(0x82ced0) == {'.?AVAggregatingSceneManager@RenderBase@RBX@@': 0, '.?AVSceneManager@RenderBase@RBX@@': 0}
assert d(0x82ced0 + 4) == 0x53f1e0                                   # slot 1 addModel (row)
assert bases(0x82d258) == {'.?AVAggregateChunk@RenderBase@RBX@@': 0, '.?AVChunk@RenderBase@RBX@@': 0, RCO: 0}
assert original.vtable_class(0x81e1e0) == (RCO, 0) and body_has(0x4e8160, 0x81e1e0)   # novtable Chunk
# AggregateChunk vtable slots that are rows here (the rest are blocked or out of scope)
for slot, address in ((1, 0x5526d0), (3, 0x552690), (4, 0x5526b0), (6, 0x552720), (7, 0x552760), (8, 0x4e5b60),
                      (9, 0x4e5b70), (0, 0x552780)):
    assert d(0x82d258 + 4 * slot) == address, (slot, hex(d(0x82d258 + 4 * slot)))


def alloc_before(function, size, callee):
    body, _, _ = match.target('2008-06', '%08x' % function)
    at = body.index(b'\x68' + struct.pack('<I', size)) if size > 0x7f else body.index(b'\x6a' + bytes([size]))
    call = body.index(b'\xe8', at)
    while (function + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != callee:
        call = body.index(b'\xe8', call + 1)
    return at


alloc_before(0x53fe10, 0x108, 0x551f30)      # new AggregateChunk
alloc_before(0x551820, 0x500, 0x505040)      # new Render::RenderScene (base RenderSceneBase, members from +0x268)
alloc_before(0x551820, 0x590, 0x7aae40)      # new RenderNew::RenderScene
alloc_before(0x45b3a0, 0x4c, 0x4d9990)       # new ViewRbxGfx (ViewBase 0x48 + bool)
alloc_before(0x45d850, 0x6c, 0x4dbbe0)       # new ViewG3D
alloc_before(0x4d9990, 0x10, 0x4f0920)       # new MaterialFactory (ViewRbxGfx ctor)
for vtable, cls in ((0x827454, 'RenderScene@Render@RBX'), (0x8749dc, 'RenderScene@RenderNew@RBX')):
    assert bases(vtable) == {'.?AV%s@@' % cls: 0, '.?AVRenderSceneBase@RenderBase@RBX@@': 0}, cls
for vtable, cls in ((0x826c70, 'ViewRbxGfx@ViewNew@RBX'), (0x826e04, 'ViewG3D@ViewNew@RBX')):
    assert bases(vtable) == {'.?AV%s@@' % cls: 0, '.?AVViewBase@RBX@@': 0}, cls
# ViewRbxGfx slots that are rows / folded rows here (both views share 3, 4, 7 through ICF)
for slot, address in ((2, 0x64a390), (3, 0x4d76d0), (4, 0x4db660), (7, 0x4db6f0), (9, 0x47d410), (10, 0x4d7180)):
    assert d(0x826c70 + 4 * slot) == address, (slot, hex(d(0x826c70 + 4 * slot)))
for slot in (2, 3, 4, 7):
    assert d(0x826e04 + 4 * slot) == d(0x826c70 + 4 * slot)
alloc_before(0x4dbbe0, 0x68, 0x53f0d0)       # new AggregatingSceneManager (ViewG3D ctor; size recorded only)
body, _, _ = match.target('2008-06', '004d9990')  # ViewRbxGfx ctor: new 8, inlined SimpleSceneManager ctor
at = body.index(b'\x6a\x08')
assert body.index(struct.pack('<I', 0x826b64)) > at

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT] + [u[0] for u in UNITS.values()] + HEADERS
exact = sorted({r['address'] for g in groups.values() for r in g if r['exact']})
groups['not_exact'] = non_out
assert not set(exact) & {r['address'] for r in folded_rows}
PROPOSALS = {
    'ViewNew::MaterialFactory (owner: whoever recovers the ViewNew material factory; not declared anywhere yet)':
        '0x10 bytes (new 0x10 at 004d9ac1 before its ctor 004f0920(G3D::TextureManager*)), out-of-line dtor 004d7460 '
        '(releases four ReferenceCountedPointers at +0xc, +0x8, +0x4, +0x0). The ctor fills +0x4 / +0x8 from the '
        'texture-proxy factory 00551920(textureManager, name, true / false) and +0x0 from 00551a30; +0xc is released '
        'through slot 0 but its pointee type is not derived. Once a header declares the class (even with only its '
        'dtor), ViewBase2008.h can include it and the ViewBase dtor 004d8920 (exact in the NATIVE_VIEWBASE_PENDING '
        'build) becomes a counted row.',
    'Material owner (RenderLib/Material2008.h), FYI': 'the unnamed factory 00551730 (new 0x18 RenderNew::Material '
        '007ad960 when 00942ec4 == 0, Render::Material 007b80a0 when 1, else throws std::exception) is declared in '
        'AggregateChunk2008.h as RenderBase::createMaterial() (donor name) because the AggregateChunk ctor calls it; '
        'move it next to MaterialBase if you recover its body.',
    'Workspace / Lighting / DataModel owners, FYI': 'ViewRbxGfx / ViewG3D render (004daf10 / 004db690) read '
        'dataModel->workspace (+0x204) and call slot 2 of the Workspace subobject at +0x288 for the camera; '
        'getWorkspace 004d7370 needs Workspace* -> Instance*; the ctors / dtors use Lighting::event_LightingChanged, '
        'Instance::event_descendentAdded and ServiceProvider::create<Lighting> 004b3380.',
}
receipt = {
    'class': 'RBX::RenderBase::Chunk (base), SceneManager, SimpleSceneManager, AggregateChunk, AggregatingSceneManager, '
             'RenderSceneBase, Render::RenderScene, RenderNew::RenderScene; RBX::ViewBase, ViewNew::ViewRbxGfx (leaves)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in [layout_obj] + list(OBJ.values()) + [PENDING_OBJ]},
    'layout': {k: hex(v) for k, v in SIZES.items()},
    'rows': groups,
    'exact_function_rows': exact,
    'folded_rows_not_counted': folded_rows,
    'pending_build_rows': pending_rows,
    'notes': ['RenderSceneBase +0x4 is not a member: MSVC pads the vfptr to the class alignment (8, from the doubles in '
              'G3D::Stopwatch), so chunkArray starts at +0x8 (layout probe sceneBaseChunkArray).'],
    'blocked': BLOCKED,
    'vtables': vt,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/render-scene-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native render scene: %d distinct function rows exact (%s); %d folded and %d pending-build-only rows not '
      'counted; %d blocked rows not built; targets and %d vtables verified'
      % (len(exact), ', '.join('%s %d' % (k, sum(r['exact'] for r in g)) for k, g in groups.items() if k != 'not_exact'),
         len(folded_rows), len(pending_rows), len(BLOCKED), len(vt)))
