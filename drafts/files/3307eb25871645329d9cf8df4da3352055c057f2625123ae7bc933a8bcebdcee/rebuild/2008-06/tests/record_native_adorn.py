"""Verify the inactive native RBX::Adorn interface, RBX::AdornG3D and RBX::AdornRbxGfx (2008-06).

Builds (document-swap flags plus the Ogre 1.4.5 client headers, VS2008 RTM 21022, /fp:fast), all from the current native
headers (native-headers/RbxGraphics/Adorn2008.h, AppDraw/AdornG3D2008.h, RbxGraphics/AdornRbxGfx2008.h and the
committed RbxGraphics/TextureProxyBase2008.h / RenderLib/TextureProxy2008.h; non-colliding names, so no donor header is
shadowed for any other unit):
  * tests/NativeAdornLayout.cpp        sizeof/offset probes (mov eax, imm32; ret) and nativeNewAdornG3D, which
                                       instantiates the header-inline constructor so that the object carries the
                                       AdornG3D vtable, ??_G and G3D::Table<TextureArgs, TextureRef>::freeMemory;
  * native-classes/AdornG3D.cpp        AdornG3D method bodies 00676480..00676aff;
  * tests/NativeAdornRbxGfxLayout.cpp  AdornRbxGfx sizeof/offset probes;
  * native-classes/AdornRbxGfx.cpp     AdornRbxGfx bodies that need only its own layout, and the container COMDATs of
                                       its image block (0066fc30..00671d5f).

A second, pending-only build of AdornRbxGfx.cpp (/DNATIVE_ADORNRBXGFX_PENDING plus generated header copies under
out/native-layouts/adornrbxgfx-pending/, ahead of native-headers for that build only) holds bodies that need proposed
declarations; its rows would be recorded exact=false (pending-build-only) and not counted; vtable checks use
current-header objects only. It is empty since 2026-11-06: RenderLib/TextureProxy2008.h declares the
RenderNew::TextureProxy(const std::string&) constructor 0066ffb0 (counted by record_native_render_material.py), so
createTextureProxy 00670380 is built and counted in the current build.

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, constants by bytes, vtables by original RTTI
names, own symbols by the row proven here, folded bodies by their bytes, data by address, and the remaining externals
by the explicit EXTERNAL map (call sites read in the original disassembly, structure checked below). One address per
symbol. Rows folded by the linker onto bodies outside the class block are compared and recorded, not counted.
Writes work/2008-06/shared-layouts/adorn-working.json. Set NATIVE_ADORN_DISCOVER=1 to list unbound targets and
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
OGRE = '/I' + str(ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include')
LAYOUT = R / 'tests/NativeAdornLayout.cpp'
UNIT = R / 'native-classes/AdornG3D.cpp'
GFX_LAYOUT = R / 'tests/NativeAdornRbxGfxLayout.cpp'
GFX_UNIT = R / 'native-classes/AdornRbxGfx.cpp'
HEADERS = [R / 'native-headers/RbxGraphics/Adorn2008.h', R / 'native-headers/AppDraw/AdornG3D2008.h',
           R / 'native-headers/RbxGraphics/AdornRbxGfx2008.h', R / 'native-headers/RenderLib/TextureProxy2008.h']
DISCOVER = bool(os.environ.get('NATIVE_ADORN_DISCOVER'))

# ---- pending proposal headers (generated, build-local; not part of the native tree) ---------------------------------
# None since 2026-11-06: the RenderNew::TextureProxy(const std::string&) constructor 0066ffb0 that the former copy of
# RenderLib/TextureProxy2008.h added is declared in the native header (checked here); the stale copy is removed.
PENDING_DIR = OUT / 'adornrbxgfx-pending'
_proxy = (R / 'native-headers/RenderLib/TextureProxy2008.h').read_text()
assert _proxy.count('\t\t\tTextureProxy(const std::string& name);') == 1, 'TextureProxy2008.h: 0066ffb0 declaration'
if (PENDING_DIR / 'RenderLib/TextureProxy2008.h').exists():
    (PENDING_DIR / 'RenderLib/TextureProxy2008.h').unlink()
PENDING_HEADERS = {}
PENDING_DIR.mkdir(parents=True, exist_ok=True)
for rel, text in PENDING_HEADERS.items():
    path = PENDING_DIR / rel
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text)


def build(name, src, extra=(), before_native=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(before_native) + flags[i:i + 1] + [OGRE] + flags[i + 1:] + list(extra) + \
        ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeAdornLayout', LAYOUT, ['/fp:fast'])
unit_obj, unit_flags = build('NativeAdorn_g3d', UNIT, ['/fp:fast'])
gfx_layout_obj, gfx_layout_flags = build('NativeAdornRbxGfxLayout', GFX_LAYOUT, ['/fp:fast'])
gfx_obj, gfx_flags = build('NativeAdorn_rbxgfx', GFX_UNIT, ['/fp:fast'])
pending_obj, pending_flags = build('NativeAdorn_rbxgfx_pending', GFX_UNIT, ['/fp:fast', '/DNATIVE_ADORNRBXGFX_PENDING'],
                                   ['/I' + str(PENDING_DIR)])
OBJ = {'layout': layout_obj, 'g3d': unit_obj, 'rbxgfx_layout': gfx_layout_obj, 'rbxgfx': gfx_obj,
       'pending': pending_obj}
FLAGS = {'layout': layout_flags, 'g3d': unit_flags, 'rbxgfx_layout': gfx_layout_flags, 'rbxgfx': gfx_flags,
         'pending': pending_flags}

# ---- layout -------------------------------------------------------------------------------------------------------
# Evidence: 0045d850 pushes 0x20 to operator new, stores the vtable 00819d24 at +0, the RenderDevice at +4 and calls the
# TextureManager(size_t) constructor 0047e400 on +8; ??_G 0045d820 destroys the 0x18-byte TextureManager at +8.
raw = layout_obj.read_bytes()
SIZES = {'adornSize': 0x4, 'adornG3DSize': 0x20, 'adornG3DRenderDevice': 0x4, 'adornG3DTextureManager': 0x8,
         'textureManagerSize': 0x18}
for fn, size in SIZES.items():
    name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?native' + fn + '@@'))
    assert body_ == b'\xb8' + struct.pack('<I', size) + b'\xc3', (fn, body_.hex())

# AdornRbxGfx: operator new(0x144) in 0045b425; constructor stores 00674210 / 006743eb (see AdornRbxGfx2008.h).
GFX_SIZES = {'size': 0x144, 'visualEngine': 0x4, 'texture2d': 0x8, 'textureMaterial': 0x24, 'rootNode': 0x30,
             'renderNode': 0x34, 'solidMaterial': 0x38, 'particleCount': 0x44, 'freeSubEntities': 0x48,
             'usedSubEntities': 0x60, 'meshes': 0x78, 'entity': 0x98, 'explosionRoot': 0x9c, 'explosionNodes': 0xa0,
             'explosions': 0xb8, 'sparkleRoot': 0xd8, 'sparkleNodes': 0xdc, 'sparkles': 0xf4, 'objectToWorld': 0x114,
             'materialPtrSize': 0xc, 'meshMapSize': 0x20, 'nodeVectorSize': 0x18}
raw = gfx_layout_obj.read_bytes()
for fn, size in GFX_SIZES.items():
    name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?nativeAdornRbxGfx_' + fn + '@@'))
    assert body_ == b'\xb8' + struct.pack('<I', size) + b'\xc3', (fn, body_.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

TABLE = '?$Table@VTextureArgs@TextureManager@G3D@@V?$ReferenceCountedPointer@VTexture@G3D@@@3@@G3D@@'
def pick(obj, prefix, *contains, suffix=''):
    names = [n for n, _, _ in match.coff_functions(Path(obj).read_bytes())
             if n.startswith(prefix) and n.endswith(suffix) and all(c in n for c in contains)]
    assert len(names) == 1, (prefix, contains, suffix, [x[:100] for x in names])
    return names[0]


EXTERNAL = {
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a,
    # G3D::RenderDevice (GLG3D, not recovered here); call sites in the AdornG3D bodies, structure checked below.
    '?getViewport@RenderDevice@G3D@@QBE?AVRect2D@2@XZ': 0x476d60,          # 00676489
    '?getWidth@RenderDevice@G3D@@QBEHXZ': 0x478450,                         # 006764a3 (tail jump)
    '?getHeight@RenderDevice@G3D@@QBEHXZ': 0x478cd0,                        # 006764b3 (tail jump)
    '?setObjectToWorldMatrix@RenderDevice@G3D@@QAEXABVCoordinateFrame@2@@Z': 0x4777e0,   # 00676573 (tail jump)
    '?beginPrimitive@RenderDevice@G3D@@QAEXW4Primitive@12@@Z': 0x47b410,    # 006766d6 (push 5 = QUADS)
    '?sendVertex@RenderDevice@G3D@@QAEXABVVector3@2@@Z': 0x477ec0,          # 006766e3 / f0 / fd / 0670a
    '?endPrimitive@RenderDevice@G3D@@QAEXXZ': 0x478990,                     # 00676712
    '?setTexture@RenderDevice@G3D@@QAEXIV?$ReferenceCountedPointer@VTexture@G3D@@@2@@Z': 0x479450,   # 006768e4
    '?rect2DBounds@Texture@G3D@@QBE?AVRect2D@2@XZ': 0x473f90,               # 006767a4
    # G3D::GFont / G3D::Draw (GLG3D library bodies in the 007b.... range).
    '?get2DStringBounds@GFont@G3D@@QBE?AVVector2@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@NW4Spacing@12@@Z': 0x7b6b30,   # 00676988
    '?draw2D@GFont@G3D@@QBE?AVVector2@2@PAVRenderDevice@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ABV32@NABVColor4@2@3W4XAlign@12@W4YAlign@12@W4Spacing@12@@Z': 0x7b6fc0,   # 00676a48
    '?ray@Draw@G3D@@SAXABVRay@2@PAVRenderDevice@2@ABVColor4@2@M@Z': 0x7b05b0,                  # 00676646
    '?lineSegment@Draw@G3D@@SAXABVLineSegment@2@PAVRenderDevice@2@ABVColor4@2@M@Z': 0x7b0250,  # 00676676
    '?axes@Draw@G3D@@SAXPAVRenderDevice@2@ABVColor4@2@11M@Z': 0x7b1490,                         # 006766ab
    # RBX::DrawPrimitives / RBX::Fonts and G3D reference counting: evidence names.
    '?line2d@DrawPrimitives@RBX@@SAXABVVector2@G3D@@0PAVRenderDevice@4@ABVColor4@4@@Z': 0x6781f0,
    '?outlineRect2d@DrawPrimitives@RBX@@SAXABVRect@2@MPAVRenderDevice@G3D@@ABVColor4@5@@Z': 0x678080,
    '?rect2d@DrawPrimitives@RBX@@SAXABVRect@2@PAVRenderDevice@G3D@@ABVColor4@5@@Z': 0x678280,
    '?rawBox@DrawPrimitives@RBX@@SAXABVAABox@G3D@@PAVRenderDevice@4@@Z': 0x677f60,
    '?rawSphere@DrawPrimitives@RBX@@SAXMPAVRenderDevice@G3D@@@Z': 0x677de0,
    '?rawCylinderAlongX@DrawPrimitives@RBX@@SAXMMPAVRenderDevice@G3D@@@Z': 0x677e20,
    '?getFont@Fonts@RBX@@SA?AV?$ReferenceCountedPointer@VGFont@G3D@@@G3D@@XZ': 0x678310,
    '?ReferenceCountedObject_zeroWeakPointers@ReferenceCountedObject@G3D@@QAEXXZ': 0x45ad90,
    # G3D::System memory (G3D library): free 00507d00 forwards to the allocator 00507c00, alignedFree 00507d20 frees
    # the block whose pointer sits at p[-4] (checked below).
    '?free@System@G3D@@SAXPAX@Z': 0x507d00,                                  # 0045c680 node delete
    '?alignedFree@System@G3D@@SAXPAX@Z': 0x507d20,                           # 0045c680 bucket array
    # pending-build-only targets (rows not counted)
    '??0TextureProxy@Render@RBX@@QAE@AAVTextureManager@G3D@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z': 0x551b30,   # 00676ae8
    '?setPointer@?$ReferenceCountedPointer@VTextureProxyBase@RBX@@@G3D@@AAEXPAVTextureProxyBase@RBX@@@Z': 0x598fa0,   # ICF (evidence: Shader)
    # AdornRbxGfx (rbxgfx unit).
    '?convertToString@?$StringConverter@H@RBX@@SA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ABH@Z': 0x5bdef0,   # 0066fc21
    # vector<RbxSubEntity*>::_Insert_n is folded with vector<const Primitive*>::_Insert_n 004c7890 (evidence name; the
    # same code for any 4-byte pointer element); called by insert 004c7c60 (folded row below).
    '?_Insert_n@?$vector@PAVRbxSubEntity@Ogre@@V?$allocator@PAVRbxSubEntity@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@PAVRbxSubEntity@Ogre@@V?$allocator@PAVRbxSubEntity@Ogre@@@std@@@2@IABQAVRbxSubEntity@Ogre@@@Z': 0x4c7890,
    # map node allocators _Buynode(left, parent, right, value, color): their catch(...) funclet lies outside the
    # recorded extents (target 126 / 135 bytes, compiled 147 / 156), so they are bound by call site, not compared.
    pick(gfx_obj, '?_Buynode@?$_Tree@', 'VMeshPtr@Ogre@@U?$less', suffix='@D@Z'): 0x670780,          # _Insert 00670850
    pick(gfx_obj, '?_Buynode@?$_Tree@', 'PAVSceneNode@Ogre@@U?$less', suffix='@D@Z'): 0x690030,      # _Insert 00691d90
    # RenderNew::TextureProxy(const std::string&) 0066ffb0: exact row of record_native_render_material.py
    # (native-classes/TextureProxyRenderNew.cpp); structure checked below
    '??0TextureProxy@RenderNew@RBX@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x66ffb0,   # 006703be
}
# Bodies folded by the linker with other identical bodies: verified by their bytes below.
FOLDED = {
    '?prepareRenderPass@Adorn@RBX@@UAEXXZ': 0x47d410,   # one-byte `ret`
    '?finishRenderPass@Adorn@RBX@@UAEXXZ': 0x47d410,
    '?sparkle@Adorn@RBX@@UAEXXZ': 0x47d410,
}
DATA = {
    '_nameCounter': 0x97da58,                                    # uniqueName 0066fc08 / 0066fc16; finishRenderPass 00671fb0
    '??_C@_0BM@PAPJHAGI@invalid?5map?1set?$DMT?$DO?5iterator?$AA@': 0x80b270,   # literal checked below
    '??_C@_0BE@JONHPENG@map?1set?$DMT?$DO?5too?5long?$AA@': 0x80b28c,               # literal checked below
    '__TI3?AVout_of_range@std@@': 0x8d0c3c,                      # throw info checked below
    '__TI3?AVlength_error@std@@': 0x8d0cc0,
}
LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}

LAYOUT_ROWS = [
    (0x45d820, '??_GAdornG3D@RBX@@UAEPAXI@Z'),
    (0x45c680, '?freeMemory@' + TABLE + 'AAEXXZ'),
    (0x45b640, '??1Entry@' + TABLE + 'QAE@XZ'),
]
G3D_ROWS = [
    (0x676480, '?getViewport@AdornG3D@RBX@@UBE?AVRect2D@G3D@@XZ'),
    (0x6764a0, '?getWidth@AdornG3D@RBX@@UBEHXZ'),
    (0x6764b0, '?getHeight@AdornG3D@RBX@@UBEHXZ'),
    (0x6764c0, '?rect2d@AdornG3D@RBX@@UBEXABVRect2D@G3D@@ABVColor4@4@@Z'),
    (0x676500, '?outlineRect2d@AdornG3D@RBX@@UBEXABVRect2D@G3D@@MABVColor4@4@@Z'),
    (0x676550, '?line2d@AdornG3D@RBX@@UBEXABVVector2@G3D@@0ABVColor4@4@@Z'),
    (0x676570, '?setObjectToWorldMatrix@AdornG3D@RBX@@UAEXABVCoordinateFrame@G3D@@@Z'),
    (0x676580, '?box@AdornG3D@RBX@@UAEXABVAABox@G3D@@ABVColor4@4@1@Z'),
    (0x6765b0, '?sphere@AdornG3D@RBX@@UAEXABVSphere@G3D@@ABVColor4@4@1@Z'),
    (0x6765e0, '?explosion@AdornG3D@RBX@@UAEXABVSphere@G3D@@ABVColor4@4@1@Z'),
    (0x6765f0, '?cylinderAlongX@AdornG3D@RBX@@UAEXMMABVColor4@G3D@@0@Z'),
    (0x676630, '?ray@AdornG3D@RBX@@UAEXABVRay@G3D@@ABVColor4@4@M@Z'),
    (0x676660, '?lineSegment@AdornG3D@RBX@@UAEXABVLineSegment@G3D@@ABVColor4@4@M@Z'),
    (0x676690, '?axes@AdornG3D@RBX@@UAEXABVColor4@G3D@@00M@Z'),
    (0x6766c0, '?quad@AdornG3D@RBX@@UAEXABVVector3@G3D@@000ABVColor4@4@@Z'),
    (0x676720, '?setColor@AdornG3D@RBX@@UAEXABVColor4@G3D@@@Z'),
    (0x676940, '?get2DStringBounds@AdornG3D@RBX@@UBE?AVVector2@G3D@@ABV?$basic_string@DU?$char_traits@D@std@@'
               'V?$allocator@D@2@@std@@NW4Spacing@Adorn@2@@Z'),
    (0x6769e0, '?drawFont2D@AdornG3D@RBX@@UBE?AVVector2@G3D@@ABV?$basic_string@DU?$char_traits@D@std@@'
               'V?$allocator@D@2@@std@@ABV34@NABVColor4@4@2W4XAlign@Adorn@2@W4YAlign@92@W4Spacing@92@@Z'),
]
G3D_ROWS += [
    # The texture rows use the committed RbxGraphics/TextureProxyBase2008.h (resolve = slot 6, +0x18) and
    # RenderLib/TextureProxy2008.h (out-of-line Render::TextureProxy(TextureManager&, const std::string&, bool) 00551b30).
    (0x676aa0, '?createTextureProxy@AdornG3D@RBX@@UAE?AV?$ReferenceCountedPointer@VTextureProxyBase@RBX@@@G3D@@'
               'ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z'),
    (0x676890, '?setTexture@AdornG3D@RBX@@UAEXHV?$ReferenceCountedPointer@VTextureProxyBase@RBX@@@G3D@@@Z'),
    (0x676750, '?getTextureSize@AdornG3D@RBX@@UBE?AVRect2D@G3D@@V?$ReferenceCountedPointer@VTextureProxyBase@RBX@@@4@@Z'),
]


MESH = 'VMeshPtr@Ogre@@U?$less'          # std::map<std::string, Ogre::MeshPtr> (+0x78)
NODE = 'PAVSceneNode@Ogre@@U?$less'      # std::map<std::string, Ogre::SceneNode*> (+0xb8 / +0xf4)
SUB = '?$vector@PAVRbxSubEntity@Ogre@@'  # std::vector<Ogre::RbxSubEntity*> (+0x48 / +0x60)
PAIR = '?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@VMeshPtr@Ogre@@@std@@'
G = gfx_obj
# AdornRbxGfx image block rows. Identical instantiations of the two maps are folded by the linker; the row symbol is
# the MeshPtr map's unless the body only exists for the SceneNode map (00671910, 006713b0).
RBXGFX_ROWS = [
    (0x66fac0, '?setObjectToWorldMatrix@AdornRbxGfx@RBX@@UAEXABVCoordinateFrame@G3D@@@Z'),
    (0x66faf0, '?getObjectToWorld@AdornRbxGfx@RBX@@AAEXAAVMatrix4@Ogre@@ABVVector3@4@1ABVQuaternion@4@@Z'),
    (0x66fba0, '?getObjectToWorld@AdornRbxGfx@RBX@@AAEXAAVMatrix4@Ogre@@@Z'),
    (0x66fc00, '?uniqueName@AdornRbxGfx@RBX@@AAE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ'),
    (0x671e20, '?releaseSubEntities@AdornRbxGfx@RBX@@AAEXXZ'),
    (0x670380, '?createTextureProxy@AdornRbxGfx@RBX@@UAE?AV?$ReferenceCountedPointer@VTextureProxyBase@RBX@@@G3D@@'
               'ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z'),
    (0x66fc30, '??1' + PAIR + 'QAE@XZ'),
    (0x66fc80, pick(G, '??0' + PAIR, 'QAE@ABV?$basic_string', suffix='ABVMeshPtr@Ogre@@@Z')),
    (0x66fce0, '??0' + PAIR + 'QAE@ABU01@@Z'),
    (0x66fed0, pick(G, '?_Lbound@?$_Tree@', MESH)),
    (0x6710e0, pick(G, '?find@?$_Tree@', MESH, 'QAE?AViterator')),
    (0x671160, pick(G, '?_Erase@?$_Tree@', MESH)),
    (0x6711f0, pick(G, '?insert@?$_Tree@', MESH, 'QAE?AU?$pair@Viterator')),
    (0x6713b0, pick(G, '?insert@?$_Tree@', NODE, 'QAE?AViterator@12@Vconst_iterator@12@ABU')),
    (0x6715f0, pick(G, '?insert@?$_Tree@', MESH, 'QAE?AViterator@12@Vconst_iterator@12@ABU')),
    (0x671830, pick(G, '?erase@?$_Tree@', MESH, 'Vconst_iterator@12@0@Z')),
    (0x671910, pick(G, '??A?$map@', NODE)),
    (0x6719f0, pick(G, '??A?$map@', MESH)),
    (0x671ae0, pick(G, '??0?$_Tree@', MESH, 'QAE@ABU?$less')),
    (0x671c20, pick(G, '??1?$_Tree@', MESH)),
    (0x66ff20, pick(G, '?_Dec@const_iterator@?$_Tree@', MESH)),
    (0x670740, pick(G, '?_Buynode@?$_Tree@', NODE, suffix='@XZ')),
    (0x670850, pick(G, '?_Insert@?$_Tree@', MESH)),
    (0x670a50, pick(G, '?erase@?$_Tree@', MESH, 'QAE?AViterator@12@Vconst_iterator@12@@Z')),
]
# Bodies of this unit that the linker folded onto identical bodies elsewhere (other classes' instantiations, shared empty
# virtuals): compared exact and recorded, not counted.
RBXGFX_FOLDED_ROWS = [
    (0x693970, pick(G, '?_Erase@?$_Tree@', NODE)),
    (0x553980, pick(G, '?_Lbound@?$_Tree@', NODE)),
    (0x696f30, pick(G, '?find@?$_Tree@', NODE, 'QAE?AViterator')),
    (0x696c50, pick(G, '?erase@?$_Tree@', NODE, 'QAE?AViterator@12@Vconst_iterator@12@@Z')),
    (0x699b30, pick(G, '??0?$_Tree@', NODE, 'QAE@ABU?$less')),
    (0x4213a0, pick(G, '?push_back@' + SUB)),
    (0x445dc0, pick(G, '?erase@' + SUB, suffix='@2@0@Z')),
    (0x4c7c60, pick(G, '?insert@' + SUB, suffix='@2@ABQAVRbxSubEntity@Ogre@@@Z')),
    (0x409f60, pick(G, '?_Inc@const_iterator@?$_Tree@', MESH)),
    (0x4dc620, pick(G, '?_Lrotate@?$_Tree@', MESH)),
    (0x5b6aa0, pick(G, '?_Max@?$_Tree@', MESH)),
    (0x5b6ac0, pick(G, '?_Min@?$_Tree@', MESH)),
    (0x5b6ae0, pick(G, '?_Rrotate@?$_Tree@', MESH)),
    (0x55c000, pick(G, '??R?$less@V?$basic_string@')),
    (0x5b78a0, pick(G, '?_Buynode@?$_Tree@', MESH, suffix='@XZ')),
    (0x5ecca0, pick(G, '??8const_iterator@?$_Tree@', MESH)),
    (0x5ecca0, pick(G, '??8const_iterator@?$_Tree@', NODE)),
    (0x68cfd0, pick(G, '?_Rrotate@?$_Tree@', NODE)),
    (0x68d060, pick(G, '?_Max@?$_Tree@', NODE)),
    (0x68d080, pick(G, '?_Min@?$_Tree@', NODE)),
    (0x68d1a0, pick(G, '?_Inc@const_iterator@?$_Tree@', NODE)),
    (0x68d350, pick(G, '?_Dec@const_iterator@?$_Tree@', NODE)),
    (0x68df00, pick(G, '?_Lrotate@?$_Tree@', NODE)),
    (0x691d90, pick(G, '?_Insert@?$_Tree@', NODE)),
    (0x693cd0, pick(G, '?insert@?$_Tree@', NODE, 'QAE?AU?$pair@Viterator')),
    (0x70bdf0, '?setColor@AdornRbxGfx@RBX@@UAEXABVColor4@G3D@@@Z'),
    (0x6ad2a0, '?lineSegment@AdornRbxGfx@RBX@@UAEXABVLineSegment@G3D@@ABVColor4@4@M@Z'),
    (0x4e83a0, '?axes@AdornRbxGfx@RBX@@UAEXABVColor4@G3D@@00M@Z'),
]
PENDING_ROWS = []
PENDING_REASON = 'pending-build-only: needs a proposed declaration (generated header copy, /DNATIVE_ADORNRBXGFX_PENDING)'
ROWS = {'layout': LAYOUT_ROWS, 'g3d': G3D_ROWS, 'rbxgfx': RBXGFX_ROWS}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:120] for h in funcs if key[:20] in h[0]][:5])
            continue
        assert len(hits) == 1, ('%08x' % address, key)
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
folded_resolved = resolve(OBJ['rbxgfx'], RBXGFX_FOLDED_ROWS)
for address, name in folded_resolved:
    FOLDED.setdefault(name, address)
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
strict = not DISCOVER
groups = {k: verify(OBJ[k], rows, own, strict) for k, rows in resolved.items()}
# Folded rows: exact and target-verified like the counted rows, then recorded with exact=False (not counted).
folded_out = []
for row in verify(OBJ['rbxgfx'], folded_resolved, own, strict):
    row['folded_exact'], row['exact'] = row['exact'], False
    row['reason'] = 'folded by the linker onto an identical body outside the AdornRbxGfx block; not counted'
    folded_out.append(row)

# Pending-build-only rows: compared and their targets checked, but never counted (exact=False).
pending_out = []
pending_own = dict(own)
for address, key in PENDING_ROWS:
    pending_own[key] = address
for row in verify(OBJ['pending'], resolve(OBJ['pending'], PENDING_ROWS), pending_own, strict=False, record=False):
    row['pending_build_exact'] = row['exact']
    row['exact'], row['reason'] = False, PENDING_REASON
    pending_out.append(row)
# The pending build must not change any counted body.
pending_bodies = {n: b for n, b, _ in match.coff_functions(Path(OBJ['pending']).read_bytes())}
current_bodies = {n: b for n, b, _ in match.coff_functions(Path(OBJ['rbxgfx']).read_bytes())}
for _, name in resolved['rbxgfx'] + folded_resolved:
    assert pending_bodies[name] == current_bodies[name], name

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in list(groups.values()) + [pending_out, folded_out]:
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'],
                      r.get('pending_build_exact'), r.get('folded_exact'))
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- externals: structure of the bodies they bind to ---------------------------------------------------------------


def body(address):
    return match.target('2008-06', '%08x' % address)[0]


FUNCTIONS = {int(json.loads(l)['addr'], 16) for l in
             (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()} \
    if (ROOT / 'work/2008-06/functions.jsonl').exists() else None
if FUNCTIONS is not None:
    for symbol, address in list(EXTERNAL.items()) + list(FOLDED.items()):
        assert address in FUNCTIONS, (symbol, hex(address))
assert body(0x507d00) == bytes.fromhex('8b4424048b0d') + body(0x507d00)[6:] and b'\x8b\x40\xfc' in body(0x507d20)
assert body(0x47d410) == b'\xc3'                                         # folded empty virtuals
assert body(0x476d60)[:6] == bytes.fromhex('d981c0030000')               # getViewport reads the viewport at +0x3c0
assert body(0x478450)[:6] == bytes.fromhex('8b81e8030000')               # getWidth / getHeight read the window +0x3e8
assert body(0x478cd0)[:6] == bytes.fromhex('8b81e8030000')
assert original.vtable_class(0x819cd8) == ('.?AV' + TABLE, 0)                # ~Table vtable stored by ??_G
assert original.vtable_class(0x82d140) == ('.?AVTextureProxy@Render@RBX@@', 0)
assert original.vtable_class(0x82d168) == ('.?AVTextureProxyBase@RBX@@', 0)
assert body(0x551b30).count(struct.pack('<I', 0x82d140)) == 1          # TextureProxy ctor stores its vtable

# Allocation size and inline construction in 0045d850 (the only reference to the AdornG3D vtable).
ctor_site = body(0x45d850)
at = ctor_site.index(b'\x6a\x20')                                        # push 0x20
assert ctor_site.index(b'\xc7\x07' + struct.pack('<I', 0x819d24)) > at  # mov [edi], 00819d24
assert ctor_site.index(b'\x68' + struct.pack('<I', 0xa00000)) > at      # TextureManager(10 MiB)
assert body(0x676aa0).startswith(bytes.fromhex('6aff')) and b'\x6a\x54' in body(0x676aa0)   # new(0x54) TextureProxy

def calls(address, target):
    code = body(address)
    return any(code[i] == 0xe8 and address + i + 5 + struct.unpack_from('<i', code, i + 1)[0] == target
               for i in range(len(code) - 4))


# AdornRbxGfx externals and data.
assert original.vtable_class(0x82d18c) == ('.?AVTextureProxy@RenderNew@RBX@@', 0)
assert body(0x66ffb0).count(struct.pack('<I', 0x82d18c)) == 1          # RenderNew::TextureProxy(const string&) vptr
assert calls(0x66ffb0, 0x551bf0) and b'\x6a\x60' in body(0x670380)    # TextureProxyBase(); new(0x60) in 00670380
assert original.string(0x80b270) == 'invalid map/set<T> iterator'
assert original.string(0x80b28c) == 'map/set<T> too long'


def throw_info_type(ti):
    array = d(ti + 12)                                                   # CatchableTypeArray
    return original.string(d(d(array + 4) + 4) + 8)                     # first CatchableType -> TypeDescriptor name


assert throw_info_type(0x8d0c3c) == '.?AVout_of_range@std@@'
assert throw_info_type(0x8d0cc0) == '.?AVlength_error@std@@'
# finishRenderPass 00671f90 resets the uniqueName counter (mov dword ptr [0097da58], 0) and tail-jumps to
# releaseSubEntities 00671e20.
assert bytes.fromhex('c705') + struct.pack('<I', 0x97da58) + b'\0\0\0\0' in body(0x671f90)
assert body(0x671f90).endswith(b'\xe9' + struct.pack('<i', 0x671e20 - 0x671fcd))
for address in (0x670780, 0x690030):                                     # _Buynode(l, p, r, value, color): new
    assert calls(address, 0x6a0920), hex(address)
assert calls(0x670850, 0x670780) and calls(0x691d90, 0x690030)          # called by _Insert (MeshPtr / SceneNode*)

# ---- vtable from the object built with the current headers, slot by slot -------------------------------------------
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL):
    for k, v in table_.items():
        slot_names.setdefault(k, v)
SLOT_PENDING = {key: address for address, key in PENDING_ROWS}   # slot identity only; rows stay uncounted


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
        elif slot in slot_names:
            expect, how = slot_names[slot], 'bound'
        elif slot in SLOT_PENDING:
            expect, how = SLOT_PENDING[slot], 'pending-build-only row (identity only)'
        else:
            expect, how = None, 'unbound'
        ok = expect == value
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value)))
    assert not bad, (symbol, bad)
    return out


assert original.vtable_class(0x819d24) == ('.?AVAdornG3D@RBX@@', 0)
vt = {'AdornG3D@RBX': check_vtable(OBJ['layout'], '??_7AdornG3D@RBX@@6B@', 0x819d24)}
assert len(vt['AdornG3D@RBX']) == 25

# ---- RTTI bases (original) -----------------------------------------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


assert bases(0x819d24) == {'.?AVAdornG3D@RBX@@': 0, '.?AVAdorn@RBX@@': 0}
assert bases(0x84d2a4) == {'.?AVAdornRbxGfx@RBX@@': 0, '.?AVAdorn@RBX@@': 0}
# AdornRbxGfx (not built here): same 25-slot interface; slots 2 / 3 / 19 are real bodies there.
rbxgfx_slots = ['%08x' % d(0x84d2a4 + 4 * i) for i in range(25)]
assert rbxgfx_slots[19] == '00674790' and body(0x674790)[-1:] == b'\xc3'   # sparkle(): no arguments (plain ret)
# Slot identities of the AdornRbxGfx rows (no vtable is emitted here: the constructor / destructor are not built).
assert rbxgfx_slots[0] == '006741f0' and rbxgfx_slots[14] == '0066fac0'   # ??_G, setObjectToWorldMatrix row
assert (rbxgfx_slots[1], rbxgfx_slots[15], rbxgfx_slots[22], rbxgfx_slots[23]) == \
    ('00670380', '0070bdf0', '006ad2a0', '004e83a0')                   # createTextureProxy row, folded empties

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT, UNIT, GFX_LAYOUT, GFX_UNIT] + HEADERS
exact = sorted({r['address'] for g in groups.values() for r in g if r['exact']})
groups['not_exact'] = pending_out
groups['folded_not_counted'] = folded_out
PROPOSALS = {
    'Ogre::VisualEngine (exe-local, unowned; whoever recovers RbxSceneManagerFactory / VisualEngine)':
        'AdornRbxGfx +0x4 is the window\'s Ogre::VisualEngine (new(0x808) in 0045cc9c, ctor 006786c0, vtable 0084df2c, '
        'RTTI .?AVVisualEngine@Ogre@@; dtor 0067a130). Observed members: +0x4 Ogre::SceneManager* (destroySceneManager '
        'in the dtor; createSceneNode slot +0xa8 / getRootSceneNode slot +0xb4 in 006743eb), +0xc Ogre::RenderTarget* '
        '(detachRenderTarget), +0x10 Ogre::Viewport* (getActualLeft/Top/Width/Height in 00670020 / 0066f900 / 0066f910), '
        '+0x14 an object deleted through slot 0 that AdornRbxGfx uses for 2D drawing (0066f920 / 0066f9c0 / 0066fa50 call '
        '00682d60 / 00683000 / 006830b0 on it), +0x18 a sub-object (ctor 006785b0) passed to RbxEntity 0067c510, +0x7f8 = '
        '-1. +0x8 is not yet derived. A declaration would unblock getViewport, getWidth, getHeight, the 2D draws, '
        'finishRenderPass and the AdornRbxGfx constructor / destructor.',
    'Ogre::RbxSceneNode / RbxEntity / RbxSubEntity / RbxFont (exe-local Ogre subclasses, unowned)':
        'AdornRbxGfx holds RbxSceneNode* +0x34 (new(0x248), ctor 00674160, vtable 0084d30c), RbxEntity* +0x98 '
        '(new(0x2bc), ctor 0067d1f0, vtable 0084e45c) and vectors of RbxSubEntity* (new(0x15c), ctor 00685660, vtable '
        '0084e90c); the font is a SharedPtr<RbxFont> global at 00962da8 (loaded in the ctor from "Fonts\\comics.fnt" '
        'through 00684eb0). Their methods (0067c510, 0067d3d0, 0067da50, 006850a0, 00685660, 0066fe70, 00670670) are needed '
        'for allocateSubEntity 00671d60, addMesh 00671f00, box / sphere / quad / ray / cylinderAlongX / explosion / '
        'sparkle and the constructor / destructor. AdornRbxGfx2008.h forward-declares them only.',
    'TextureProxyBase::resolve argument (owner: texture proxies)':
        'AdornRbxGfx::setTexture 006700e0 and getTextureSize 00670210 call resolve (slot 6, +0x18) with the '
        'VisualEngine* at +0x4, not a G3D::RenderDevice*; the 2008 resolve parameter type (or a conversion) is unknown, '
        'so these two rows are not attempted.',
    'RbxGraphics/Adorn.h (donor path, owner: rendering)':
        '2008 Adorn is __declspec(novtable) with 25 slots: an extra no-argument virtual after explosion() (slot 19, '
        'AdornRbxGfx 00674790) and non-pure empty prepareRenderPass / finishRenderPass; see RbxGraphics/Adorn2008.h.',
}
receipt = {
    'class': 'RBX::Adorn (interface), RBX::AdornG3D, RBX::AdornRbxGfx',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'pending_headers': {k: __import__('hashlib').sha256(v.encode()).hexdigest() for k, v in PENDING_HEADERS.items()},
    'objects': {p.name: sha(p) for p in OBJ.values()},
    'layout': {k: hex(v) for k, v in SIZES.items()},
    'rows': groups,
    'exact_function_rows': exact,
    'vtables': vt,
    'adorn_rbxgfx_vtable_0084d2a4': rbxgfx_slots,
    'adorn_rbxgfx_layout': {k: hex(v) for k, v in GFX_SIZES.items()},
    'adorn_rbxgfx_open': 'Built: setObjectToWorldMatrix, the two getObjectToWorld transform helpers, uniqueName, '
        'releaseSubEntities, createTextureProxy and the container COMDATs of the block. Not built: '
        'ctor 00674210 (+ try/catch continuation 006743eb), dtor 00673a90 / ??_G 006741f0, getViewport / getWidth / '
        'getHeight / the 2D draws / get2DStringBounds / drawFont2D / prepareRenderPass / finishRenderPass (VisualEngine), '
        'setTexture / getTextureSize (resolve argument), box / sphere / explosion / sparkle / cylinderAlongX / ray / quad '
        '/ allocateSubEntity 00671d60 / addMesh 00671f00 (RbxEntity / RbxSubEntity / RbxSceneNode / RbxFont), the '
        'map destructor tail jump 00671d50 (emitted with the AdornRbxGfx destructor), the _Buynode(value) bodies '
        '00670780 / 00690030 (catch funclet outside the recorded extents) and 006740e0 / 0066fd40 (8-byte element '
        'vector of an RbxEntity type).',
    'proposals': PROPOSALS,
    'applied': ['2026-11-06: RenderLib/TextureProxy2008.h declares RenderNew::TextureProxy(const std::string&) 0066ffb0 '
                '(body in TextureProxyRenderNew.cpp, counted by render-material-working.json); createTextureProxy '
                '00670380 is counted here.'],
    'scope': 'Inactive. Exact bodies with verified call/data targets; pending-build-only rows not counted; no active '
             'build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/adorn-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Adorn: %d distinct function rows exact (%s); %d pending-build-only rows not counted (%d exact in '
      'the pending build); %d folded rows exact, not counted; targets and %d vtable verified'
      % (len(exact), ', '.join('%s %d' % (k, sum(r['exact'] for r in g)) for k, g in groups.items()
                               if k not in ('not_exact', 'folded_not_counted')),
         len(pending_out), sum(1 for r in pending_out if r['pending_build_exact']),
         sum(1 for r in folded_out if r['folded_exact']), len(vt)))
