"""Verify the inactive native texture proxies and materials (2008-06): RBX::TextureProxyBase, Render::TextureProxy /
MegaTextureProxy, RenderNew::TextureProxy / MegaTextureProxy / BadConversion, RenderBase::MaterialBase::Level,
Render::Material / Material::Level and RenderNew::Material / Material::Level.

Builds (VS2008 RTM 21022, document-swap flags plus the Ogre 1.4.5 client headers tools/libs/ogre-1.4.5/ogrenew/
OgreMain/include, OGRE_NONCLIENT_BUILD undefined so TexturePtr / MaterialPtr members are rgmain.dll imports), all from
the current native headers. No donor header is shadowed: the new headers use names the donor tree does not have
(RbxGraphics/TextureProxyBase2008.h, RenderLib/TextureProxy2008.h, RenderLib/Material2008.h):
  * tests/NativeRenderMaterialLayout.cpp     sizeof/offset probes (mov eax, imm32; ret);
  * native-classes/TextureProxyBase2008.cpp   /Od /Ob0 /GS: TextureProxyBase (00551bf0..00551d7f) and the
                                              (TextureManager&, name, tiled) constructors 00551b30 / 00551e30 with the
                                              implicit Render::TextureProxy destructor 00551db0 and both ??_G;
  * native-classes/TextureProxyRender.cpp     Render::TextureProxy / MegaTextureProxy (007b8450..007b936f);
  * native-classes/TextureProxyRenderNew.cpp  RenderNew::TextureProxy / MegaTextureProxy, stringify / BadConversion
                                              (007adb70..007aea5f), TextureProxy(const std::string&) 0066ffb0;
  * native-classes/RenderMaterial.cpp         /fp:fast: Render::Material / Level (007b7540..007b80ef);
  * native-classes/RenderMaterialNew.cpp      /fp:fast: RenderNew::Material / Level, MaterialBase::Level defaults
                                              (007accc0..007ad9af).

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals and constants by bytes, type
descriptors and vtables by original RTTI names, own symbols by the row proven here, and the remaining externals by the
explicit EXTERNAL map (each checked below: G3D / CRT helpers whose bodies this probe also compiles are compared byte for
byte with the bound address; the others by evidence name or body shape). A symbol binds to one address across all rows.
Rows that compile to the bytes of a body the linker folded onto another unit's function (identical-code folding) are
verified like the others but recorded as folded and not counted. Vtables are compared slot by slot from the objects
built with the current headers. Writes work/2008-06/shared-layouts/render-material-working.json.
Set NATIVE_RENDER_MATERIAL_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = R / 'out/native-render-material'
OUT.mkdir(parents=True, exist_ok=True)
OGRE = '/I' + str(ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include')
LAYOUT = R / 'tests/NativeRenderMaterialLayout.cpp'
UNITS = {
    'base': (R / 'native-classes/TextureProxyBase2008.cpp', ['/Od', '/Ob0', '/GS']),
    'render_proxy': (R / 'native-classes/TextureProxyRender.cpp', []),
    'new_proxy': (R / 'native-classes/TextureProxyRenderNew.cpp', []),
    'render_material': (R / 'native-classes/RenderMaterial.cpp', ['/fp:fast']),
    'new_material': (R / 'native-classes/RenderMaterialNew.cpp', ['/fp:fast']),
}
HEADERS = [R / 'native-headers/RbxGraphics/TextureProxyBase2008.h', R / 'native-headers/RenderLib/TextureProxy2008.h',
           R / 'native-headers/RenderLib/Material2008.h']
DISCOVER = bool(os.environ.get('NATIVE_RENDER_MATERIAL_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i + 1] + [OGRE] + flags[i + 1:] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeRenderMaterialLayout', LAYOUT)
OBJ, FLAGS = {}, {'layout': layout_flags}
for key, (src, extra) in UNITS.items():
    OBJ[key], FLAGS[key] = build('NativeRenderMaterial_' + key, src, extra)

# ---- layout -------------------------------------------------------------------------------------------------------
# Evidence: TextureProxyBase ctor 00551bf0 (+0xc string, +0x28 = 1, +0x2c = 1.0f); Render::TextureProxy ctor 00551b30
# (+0x30..+0x48) and the allocation sizes pushed before the constructors (factories 00551920 / 00551a30: 0x60 / 0x54,
# 0x64 / 0x58; shade 007b8500 / 007aded0: 0x54 / 0x60); MegaTextureProxy ctors 007b8fb0 / 007ae4b0 (+0x54 / +0x60);
# RenderNew getSize 007adb70 (TexturePtr pRep at +0x58); Material() 007ad960 / 007b80a0 (+0xc..+0x14); the Level strides
# 0x38 / 0x2c (getLevel 007acdb0 / 007b7590), Level constructors 007ad230 / 007b78b0 (+0x4..+0x28), the RenderNew level
# MaterialPtr at +0x2c (007ad20b), veryTransparent 007acd70 (+0x28).
raw = layout_obj.read_bytes()
SIZES = {
    'proxyBaseSize': 0x30, 'proxyBaseFilename': 0xc, 'proxyBaseIntProperty': 0x28, 'proxyBaseFloatProperty': 0x2c,
    'renderProxySize': 0x54, 'renderProxyTexture': 0x30, 'renderProxyLoaded': 0x34, 'renderProxyManager': 0x38,
    'renderProxyTiled': 0x3c, 'renderProxyRoot': 0x40, 'renderProxyShadeTexture': 0x44, 'renderProxyShadeColor': 0x48,
    'renderMegaSize': 0x58, 'renderMegaScalar': 0x54, 'newProxySize': 0x60, 'newProxyRoot': 0x40,
    'newProxyShadeColor': 0x48, 'newProxyOgreTexture': 0x54, 'newMegaSize': 0x64, 'newMegaScalar': 0x60,
    'renderMaterialSize': 0x18, 'renderMaterialLevels': 0xc, 'renderLevelSize': 0x2c, 'renderLevelEmpty': 0x4,
    'renderLevelMatte': 0x8, 'renderLevelBaseTexture': 0xc, 'renderLevelColor': 0x10, 'renderLevelSpecular': 0x1c,
    'renderLevelShiny': 0x20, 'renderLevelReflect': 0x24, 'renderLevelTransparent': 0x28, 'newMaterialSize': 0x18,
    'newMaterialLevels': 0xc, 'newLevelSize': 0x38, 'newLevelTransparent': 0x28, 'newLevelOgreMaterial': 0x2c,
    'baseLevelSize': 0x4,
}
for fn, size in SIZES.items():
    name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?native' + fn + '@@'))
    assert body_ == b'\xb8' + struct.pack('<I', size) + b'\xc3', (fn, body_.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

TEX = '?$ReferenceCountedPointer@VTexture@G3D@@@G3D@@'
PROXY_BASE_REF = '?$ReferenceCountedPointer@VTextureProxyBase@RBX@@@G3D@@'
EXTERNAL = {
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a, '___RTDynamicCast': 0x6a17c6, '__CxxThrowException@8': 0x6a158c,
    '__ftol2_sse': 0x6a17f0, '_atexit': 0x6a17af,
    '?ReferenceCountedObject_zeroWeakPointers@ReferenceCountedObject@G3D@@QAEXXZ': 0x45ad90,     # evidence name
    '?setPointer@' + PROXY_BASE_REF + 'AAEXPAVTextureProxyBase@RBX@@@Z': 0x598fa0,              # ICF (evidence: Shader)
    '?setPointer@' + TEX + 'AAEXPAVTexture@2@@Z': 0x598fa0,
    '?setPointer@?$ReferenceCountedPointer@VTextureProxy@Render@RBX@@@G3D@@AAEXPAVTextureProxy@Render@RBX@@@Z': 0x598fa0,
    '?setPointer@?$ReferenceCountedPointer@VTextureProxy@RenderNew@RBX@@@G3D@@AAEXPAVTextureProxy@RenderNew@RBX@@@Z':
        0x598fa0,
    '??1' + TEX + 'QAE@XZ': 0x502a70,                                                          # ICF (evidence: Shader)
    '??1?$ReferenceCountedPointer@VTextureProxy@Render@RBX@@@G3D@@QAE@XZ': 0x502a70,
    '??1?$ReferenceCountedPointer@VTextureProxy@RenderNew@RBX@@@G3D@@QAE@XZ': 0x502a70,
    '??0' + TEX + 'QAE@XZ': 0x4f0810,                       # optimized default ctor (compared with the compiled body)
    '??0?$ReferenceCountedPointer@VTextureProxy@Render@RBX@@@G3D@@QAE@XZ': 0x4f0810,
    '??0?$ReferenceCountedPointer@VTextureProxy@RenderNew@RBX@@@G3D@@QAE@XZ': 0x5410b0,   # /Od copy (compared below)
    '??0ReferenceCountedObject@G3D@@IAE@XZ': 0x472990,      # compared with the compiled optimized body
    '??1ReferenceCountedObject@G3D@@UAE@XZ': 0x7accf0,      # compared with the compiled optimized body
    '??0Color3@G3D@@QAE@XZ': 0x7188c0,                      # `mov eax, ecx; ret` (ICF; evidence name getKernel)
    '?white@Color3@G3D@@SAABV12@XZ': 0x514a60,              # G3D static accessor (also called by 00478650)
    '?alignedMalloc@System@G3D@@SAPAXII@Z': 0x508580,
    '?alignedFree@System@G3D@@SAXPAX@Z': 0x507d20,          # as bound by record_native_* (reads the size word at -4)
    '?setSpecularCoefficient@RenderDevice@G3D@@QAEXM@Z': 0x478650,   # Color3::white() * s (body checked below)
    '?setShininess@RenderDevice@G3D@@QAEXM@Z': 0x476b10,             # glMaterialf(.., GL_SHININESS 0x1601, s)
    '?setTexture@RenderDevice@G3D@@QAEXIV?$ReferenceCountedPointer@VTexture@G3D@@@2@@Z': 0x479450,
    '?setTextureCombineMode@RenderDevice@G3D@@QAEXIW4CombineMode@12@@Z': 0x477970,
    '??0runtime_error@std@@QAE@ABV01@@Z': 0x409e90,         # evidence name
    '??1BadConversion@RenderNew@RBX@@UAE@XZ': 0x5f5a90,      # ~runtime_error body (compared with the compiled body)
    '___security_cookie': 0x965cc0,                          # /GS cookie of the /Od rows (as record_native_render_scene)
}
# Bodies folded by the linker onto another unit's identical function: verified by bytes, recorded, not counted.
FOLDED = {
    '??_GBadConversion@RenderNew@RBX@@UAEPAXI@Z': 0x409dc0,   # runtime_error ??_G (BadConversion adds no members)
    '?reflect@Level@Material@Render@RBX@@UBEMXZ': 0x503cb0,    # fld [ecx+0x24]; ret, kept at 00503cb0 by the linker
    '?reflect@Level@Material@RenderNew@RBX@@UBEMXZ': 0x503cb0,
}
LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}

BASE_ROWS = [
    (0x551bf0, '??0TextureProxyBase@RBX@@QAE@XZ'),
    (0x551c70, '?setIntProperty@TextureProxyBase@RBX@@UAEXH@Z'),
    (0x551c90, '?getIntProperty@TextureProxyBase@RBX@@UBEHXZ'),
    (0x551cb0, '?setFloatProperty@TextureProxyBase@RBX@@UAEXM@Z'),
    (0x551cd0, '?getFloatProperty@TextureProxyBase@RBX@@UBEMXZ'),
    (0x551cf0, '??1TextureProxyBase@RBX@@UAE@XZ'),
    (0x551d50, '??_GTextureProxyBase@RBX@@UAEPAXI@Z'),
    (0x551b30, '??0TextureProxy@Render@RBX@@QAE@AAVTextureManager@G3D@@'),
    (0x551d80, '??_GTextureProxy@Render@RBX@@UAEPAXI@Z'),
    (0x551db0, '??1TextureProxy@Render@RBX@@UAE@XZ'),
    (0x551e30, '??0TextureProxy@RenderNew@RBX@@QAE@AAVTextureManager@G3D@@'),
    (0x551f00, '??_GTextureProxy@RenderNew@RBX@@UAEPAXI@Z'),
]
RENDER_PROXY_ROWS = [
    (0x7b8450, '??0TextureProxy@Render@RBX@@IAE@V?$ReferenceCountedPointer@VTextureProxy@Render@RBX@@@G3D@@@Z'),
    (0x7b8500, '?shade@TextureProxy@Render@RBX@@UAE?AV' + PROXY_BASE_REF),
    (0x7b85e0, '?getIfResolved@TextureProxy@Render@RBX@@UBE?AV' + TEX + 'XZ'),
    (0x7b8eb0, '?alphaOnlyVersion@TextureProxy@Render@RBX@@QAE'),
    (0x7b8f40, '?getSize@TextureProxy@Render@RBX@@UAE?AVVector2@G3D@@XZ'),
    (0x7b8fb0, '??0MegaTextureProxy@Render@RBX@@QAE@AAVTextureManager@G3D@@'),
    (0x7b8fe0, '?shade@MegaTextureProxy@Render@RBX@@UAE?AV' + PROXY_BASE_REF),
    (0x7b9350, '??_GMegaTextureProxy@Render@RBX@@UAEPAXI@Z'),
]
NEW_PROXY_ROWS = [
    (0x7adb70, '?getSize@TextureProxy@RenderNew@RBX@@UAE?AVVector2@G3D@@XZ'),
    (0x7adbe0, '?stringify@RenderNew@RBX@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@N@Z'),
    (0x7adcf0, '??0BadConversion@RenderNew@RBX@@QAE@ABV012@@Z'),     # implicit copy ctor (thrown-object copy)
    (0x7ade10, '??0TextureProxy@RenderNew@RBX@@IAE@V?$ReferenceCountedPointer@VTextureProxy@RenderNew@RBX@@@G3D@@@Z'),
    # TextureProxy(const std::string&): emitted in the AdornRbxGfx image block (its only caller, createTextureProxy
    # 00670380, news 0x60 first; record_native_adorn.py binds the call to this address).
    (0x66ffb0, '??0TextureProxy@RenderNew@RBX@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z'),
    (0x7aded0, '?shade@TextureProxy@RenderNew@RBX@@UAE?AV' + PROXY_BASE_REF),
    (0x7ae3b0, '??1TextureProxy@RenderNew@RBX@@UAE@XZ'),
    (0x7ae4b0, '??0MegaTextureProxy@RenderNew@RBX@@QAE@AAVTextureManager@G3D@@'),
    (0x7b8fe0, '?shade@MegaTextureProxy@RenderNew@RBX@@UAE?AV' + PROXY_BASE_REF),   # same body as the Render one
    (0x7aea40, '??_GMegaTextureProxy@RenderNew@RBX@@UAEPAXI@Z'),
]
LEVEL_R = '@Level@Material@Render@RBX@@'
LEVEL_N = '@Level@Material@RenderNew@RBX@@'
LEVEL_B = '@Level@MaterialBase@RenderBase@RBX@@'
RET_LEVEL = 'ABVLevel@MaterialBase@RenderBase@3@'


def material_rows(ns, level, stride_rows):
    return [
        (0x7acda0, '?levelCount@Material@%s@RBX@@UBEIXZ' % ns),
        (0x7acd70, '?veryTransparent@Material@%s@RBX@@UBE_NXZ' % ns),
        (0x7acef0, '?isEmptyLevel' + level + 'UBE_NXZ'),
        (0x7ad0a0, '?baseTexture' + level + 'UBE?AV' + TEX + 'PAVRenderDevice@'),
        (0x7ad0e0, '?setBaseTexture' + level + 'UAEXV' + PROXY_BASE_REF + '@Z'),
        (0x7ad160, '?matte' + level + 'UBE?AV' + TEX + 'PAVRenderDevice@'),
        (0x7b7810, '?baseTexture' + level + 'UBE?AV' + PROXY_BASE_REF + 'XZ'),
        (0x7b76a0, '?color' + level + 'UBEABVColor3@G3D@@XZ'),
        (0x7b76b0, '?specular' + level + 'UBEMXZ'),
        (0x7b76c0, '?shiny' + level + 'UBEMXZ'),
        (0x7b76d0, '?transparent' + level + 'UBEMXZ'),
    ] + stride_rows


RENDER_MATERIAL_ROWS = material_rows('Render', LEVEL_R, [
    (0x7b7540, '??1?$Array@VLevel@Material@Render@RBX@@@G3D@@QAE@XZ'),
    (0x7b7590, '?getLevel@Material@Render@RBX@@UAEAAVLevel@MaterialBase@RenderBase@3@H@Z'),
    (0x7b75a0, '?detailLevel@Material@Render@RBX@@UBEPBVLevel@MaterialBase@RenderBase@3@M@Z'),
    (0x7b7600, '??0Level@Material@Render@RBX@@QAE@ABV0123@@Z'),
    (0x7b76e0, '??4Level@Material@Render@RBX@@QAEAAV0123@ABV0123@@Z'),
    (0x7b7740, '?realloc@?$Array@VLevel@Material@Render@RBX@@@G3D@@AAEXH@Z'),
    (0x7b7840, '??0Level@Material@Render@RBX@@QAE@XZ'),
    (0x7b78b0, '??0Level@Material@Render@RBX@@QAE@V' + PROXY_BASE_REF + 'VColor3@5@MMMM@Z'),
    (0x7b7a60, '??1Level@Material@Render@RBX@@UAE@XZ'),
    (0x7b7b10, '?configureRenderDevice' + LEVEL_R + 'UBEXPAVRenderDevice@G3D@@@Z'),
    (0x7b7bf0, '??_GMaterial@Render@RBX@@UAEPAXI@Z'),
    (0x7b7c50, '?resize@?$Array@VLevel@Material@Render@RBX@@@G3D@@QAEXH_N@Z'),
    (0x7b7dc0, '??_GLevel@Material@Render@RBX@@UAEPAXI@Z'),
    (0x7b7de0, '?append@?$Array@VLevel@Material@Render@RBX@@@G3D@@QAEXABVLevel@Material@Render@RBX@@@Z'),
    (0x7b7ed0, '?appendEmptyLevel@Material@Render@RBX@@UAE' + RET_LEVEL + 'XZ'),
    (0x7b7ef0, '?appendLevel@Material@Render@RBX@@UAE' + RET_LEVEL + 'V' + PROXY_BASE_REF + 'VColor3@'),
    (0x7b7ff0, '?appendLevel@Material@Render@RBX@@UAE' + RET_LEVEL + 'VColor3@G3D@@MMMM@Z'),
    (0x7b80a0, '??0Material@Render@RBX@@QAE@XZ'),
])
NEW_MATERIAL_ROWS = material_rows('RenderNew', LEVEL_N, [
    (0x7accc0, '??1' + LEVEL_B[1:] + 'UAE@XZ'),
    (0x7accd0, '?isEmptyLevel' + LEVEL_B + 'UBE_NXZ'),          # the shared throwing default (see FOLDED_SLOTS)
    (0x7acd00, '??_G' + LEVEL_B[1:] + 'UAEPAXI@Z'),
    (0x7acd20, '??1?$Array@VLevel@Material@RenderNew@RBX@@@G3D@@QAE@XZ'),
    (0x7acdb0, '?getLevel@Material@RenderNew@RBX@@UAEAAVLevel@MaterialBase@RenderBase@3@H@Z'),
    (0x7acdd0, '?detailLevel@Material@RenderNew@RBX@@UBEPBVLevel@MaterialBase@RenderBase@3@M@Z'),
    (0x7ace40, '??0Level@Material@RenderNew@RBX@@QAE@ABV0123@@Z'),
    (0x7acf00, '??4Level@Material@RenderNew@RBX@@QAEAAV0123@ABV0123@@Z'),
    (0x7acf70, '?realloc@?$Array@VLevel@Material@RenderNew@RBX@@@G3D@@AAEXH@Z'),
    (0x7ad060, '?setBaseTexture' + LEVEL_B + 'UAEXV' + PROXY_BASE_REF + '@Z'),
    (0x7ad1a0, '??0Level@Material@RenderNew@RBX@@QAE@XZ'),
    (0x7ad230, '??0Level@Material@RenderNew@RBX@@QAE@V' + PROXY_BASE_REF + 'VColor3@5@MMMM@Z'),
    (0x7ad310, '??1Level@Material@RenderNew@RBX@@UAE@XZ'),
    (0x7ad450, '??_GMaterial@RenderNew@RBX@@UAEPAXI@Z'),
    (0x7ad4b0, '?resize@?$Array@VLevel@Material@RenderNew@RBX@@@G3D@@QAEXH_N@Z'),
    (0x7ad640, '??_GLevel@Material@RenderNew@RBX@@UAEPAXI@Z'),
    (0x7ad660, '?append@?$Array@VLevel@Material@RenderNew@RBX@@@G3D@@QAEXABVLevel@Material@RenderNew@RBX@@@Z'),
    (0x7ad760, '?appendEmptyLevel@Material@RenderNew@RBX@@UAE' + RET_LEVEL + 'XZ'),
    (0x7ad790, '?appendLevel@Material@RenderNew@RBX@@UAE' + RET_LEVEL + 'V' + PROXY_BASE_REF + 'VColor3@'),
    (0x7ad8a0, '?appendLevel@Material@RenderNew@RBX@@UAE' + RET_LEVEL + 'VColor3@G3D@@MMMM@Z'),
    (0x7ad960, '??0Material@RenderNew@RBX@@QAE@XZ'),
])
# The other MaterialBase::Level throwing defaults compile to the bytes of 007accd0 and are folded onto it (vtable
# 00874a8c holds 007accd0 in every slot but 1 and 4); verified by bytes and kept out of the counts.
for slot_name in ('?baseTexture' + LEVEL_B + 'UBE?AV' + TEX + 'PAVRenderDevice@6@@Z',
                  '?baseTexture' + LEVEL_B + 'UBE?AV' + PROXY_BASE_REF + 'XZ',
                  '?matte' + LEVEL_B + 'UBE?AV' + TEX + 'PAVRenderDevice@6@@Z',
                  '?color' + LEVEL_B + 'UBEABVColor3@G3D@@XZ', '?specular' + LEVEL_B + 'UBEMXZ',
                  '?shiny' + LEVEL_B + 'UBEMXZ', '?reflect' + LEVEL_B + 'UBEMXZ', '?transparent' + LEVEL_B + 'UBEMXZ',
                  '?configureRenderDevice' + LEVEL_B + 'UBEXPAVRenderDevice@G3D@@@Z'):
    FOLDED[slot_name] = 0x7accd0
FOLDED_ROWS = {
    'new_proxy': [(0x409dc0, '??_GBadConversion@RenderNew@RBX@@UAEPAXI@Z')],
    'render_material': [(0x503cb0, '?reflect@Level@Material@Render@RBX@@UBEMXZ')],
    'new_material': [(0x503cb0, '?reflect@Level@Material@RenderNew@RBX@@UBEMXZ')] +
                    [(a, k) for k, a in FOLDED.items() if a == 0x7accd0],
}
NON_EXACT_ROWS = []
UNPROVEN = {}
# Vtable slots whose bodies are not built here (bound to the address the original vtable holds).
SLOT_EXTERNAL = {   # keyed by symbol prefix (the RenderDevice back-reference index differs per class)
    '?resolve@TextureProxy@Render@RBX@@UAE?AV' + TEX: 0x7b8610,
    '?resolve@MegaTextureProxy@Render@RBX@@UAE?AV' + TEX: 0x7b9000,
    '?resolve@TextureProxy@RenderNew@RBX@@UAE?AV' + TEX: 0x7aec70,
    '?resolve@MegaTextureProxy@RenderNew@RBX@@UAE?AV' + TEX: 0x7ae4e0,
    '?what@runtime_error@std@@UBEPBDXZ': 0x409db0,
}

ROWS = {'base': BASE_ROWS, 'render_proxy': RENDER_PROXY_ROWS, 'new_proxy': NEW_PROXY_ROWS,
        'render_material': RENDER_MATERIAL_ROWS, 'new_material': NEW_MATERIAL_ROWS}


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
            elif symbol.startswith('__TI') or symbol.startswith('__CT') or symbol.startswith('__CTA'):
                how = check_throw_info(raw, sections, symbols, definitions, symbol, value)
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
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
            elif symbol in UNPROVEN:
                assert UNPROVEN[symbol] == value, (name, symbol, hex(value))
                how = 'call target of a non-exact row'
            elif symbol.startswith('??_B') or symbol.startswith('?minSize@'):
                how = check_static(raw, sections, definitions, symbol, value, name, address)
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


def check_throw_info(raw, sections, symbols, definitions, symbol, value):
    """Throw information: the original structure must name the same type descriptors (by RTTI name)."""
    pos, at = definitions[symbol]
    sec = sections[at]
    # Compare the relocations of the compiled structure with the original words at the same offsets.
    data_start = sec[4] + pos
    checked = []
    for i in range(sec[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, sec[5] + 10 * i)
        if not pos <= offset < pos + 0x20:
            continue
        inner = symbols[index][0]
        word = d(value + offset - pos)
        hit = original.imported(word)
        if hit is not None:
            assert hit[1] == nb.plain(inner), (symbol, inner, hex(word), hit)
            checked.append('%s=%s!%s' % (inner, hit[0], hit[1]))
        elif inner.startswith('??_R0'):
            assert original.string(word + 8) == '.' + inner[5:-2], (symbol, inner, hex(word))
            checked.append('%s=RTTI' % inner)
        elif inner in own_all:
            assert own_all[inner] == word, (symbol, inner, hex(word))
            checked.append('%s=own' % inner)
        elif inner.startswith('__C') or inner.startswith('__TI'):
            checked.append('%s=%s' % (inner, check_throw_info(raw, sections, symbols, definitions, inner, word)))
        elif inner in EXTERNAL:
            assert EXTERNAL[inner] == word, (symbol, inner, hex(word))
            checked.append('%s=external' % inner)
        else:
            UNBOUND.append("    %r: %#x,   # inside %s" % (inner, word, symbol))
    return 'throw info [%s]' % ', '.join(checked)


def check_static(raw, sections, definitions, symbol, value, name, address):
    """Function-local static / its guard word: bound to the address the original row uses (unit-local)."""
    statics.setdefault((symbol, address), value)
    return 'unit-local static of %08x' % address


statics = {}
resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
folded_resolved = {k: resolve(OBJ[k], rows) for k, rows in FOLDED_ROWS.items()}
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
own_all = dict(own)
strict = not DISCOVER
groups = {k: verify(OBJ[k], rows, own, strict, unit=k) for k, rows in resolved.items()}
folded_out = {k: verify(OBJ[k], rows, own, strict, unit=k) for k, rows in folded_resolved.items()}
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in list(groups.values()) + list(folded_out.values()):
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
# Function-local statics of the two Array<Level>::resize instances (minSize, guarded dynamic init): each instance owns
# its own pair, the guard word follows minSize as the compiler lays them out, and the two units do not share storage.
pairs = {}
for (symbol, address), value in statics.items():
    pairs.setdefault(address, {})['guard' if symbol.startswith('??_B') else 'minSize'] = value
assert sorted(pairs) == [0x7ad4b0, 0x7b7c50], pairs
for address, pair in pairs.items():
    assert pair['guard'] == pair['minSize'] + 4, (hex(address), pair)
assert pairs[0x7ad4b0]['minSize'] != pairs[0x7b7c50]['minSize']

# ---- externals named by structure ----------------------------------------------------------------------------------


def body(address):
    return match.target('2008-06', '%08x' % address)[0]


def compiled(unit, symbol):
    raw_ = Path(OBJ[unit]).read_bytes()
    return next((b, r) for n, b, r in match.coff_functions(raw_) if n == symbol)


# G3D inline helpers whose out-of-line copies this probe compiles: the bound address holds the same bytes.
for unit, symbol in (('render_proxy', '??0' + TEX + 'QAE@XZ'),
                     ('base', '??0?$ReferenceCountedPointer@VTextureProxy@RenderNew@RBX@@@G3D@@QAE@XZ'),
                     ('new_material', '??0ReferenceCountedObject@G3D@@IAE@XZ'),
                     ('new_material', '??1ReferenceCountedObject@G3D@@UAE@XZ'),
                     ('render_proxy', '??1' + TEX + 'QAE@XZ'),
                     ('render_proxy', '?setPointer@' + TEX + 'AAEXPAVTexture@2@@Z'),
                     ('render_proxy', '??0Color3@G3D@@QAE@XZ'),
                     ('new_proxy', '??1BadConversion@RenderNew@RBX@@UAE@XZ'),
                     ('new_material', '?ReferenceCountedObject_zeroWeakPointers@ReferenceCountedObject@G3D@@QAEXXZ')):
    b, r = compiled(unit, symbol)
    t, tr, _ = match.target('2008-06', '%08x' % EXTERNAL[symbol])
    assert match.exact_match(t, tr, b, r), ('helper body', symbol, hex(EXTERNAL[symbol]))
assert struct.pack('<I', 0x81e1e0) in body(0x472990) and struct.pack('<I', 0x81e1e0) in body(0x7accf0)
assert original.vtable_class(0x81e1e0) == ('.?AVReferenceCountedObject@G3D@@', 0)
assert b'\x68\x01\x16\x00\x00' in body(0x476b10)                  # setShininess: GL_SHININESS
assert b'\xe8' in body(0x478650) and (0x478650 + 6 + 5 + struct.unpack_from('<i', body(0x478650), 7)[0]) == 0x514a60
assert b'\x8b\x40\xfc' in body(0x507d20)                            # alignedFree reads the stored size word

# ---- vtables from the objects built with the current headers, slot by slot -----------------------------------------
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL, UNPROVEN):
    for k, v in table_.items():
        slot_names.setdefault(k, v)


def compiled_vtable(obj, symbol):
    raw_ = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw_)
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw_, table[5] + 10 * i)
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
            if expect is None and value == 0x6a16be:
                expect, how = value, '_purecall (static CRT, 006a16be)'
        elif slot in slot_names:
            expect, how = slot_names[slot], 'bound'
        else:
            hits = [v for k, v in SLOT_EXTERNAL.items() if slot.startswith(k)]
            expect, how = (hits[0] if len(hits) == 1 else None), 'slot body not built here'
        ok = expect == value
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value), hex(expect) if expect is not None else None))
    assert not bad, (symbol, bad)
    return out


vt = {}
for key, cls, address, count in (
        ('base', 'TextureProxyBase@RBX', 0x82d168, 8),
        ('base', 'TextureProxy@Render@RBX', 0x82d140, 9),
        ('base', 'TextureProxy@RenderNew@RBX', 0x82d18c, 8),
        ('render_proxy', 'MegaTextureProxy@Render@RBX', 0x875cec, 9),
        ('new_proxy', 'MegaTextureProxy@RenderNew@RBX', 0x874bd8, 8),
        ('new_proxy', 'BadConversion@RenderNew@RBX', 0x874b34, 2),
        ('render_material', 'Material@Render@RBX', 0x875bc4, 8),
        ('render_material', 'Level@Material@Render@RBX', 0x875be8, 12),
        ('new_material', 'Material@RenderNew@RBX', 0x874ac0, 8),
        ('new_material', 'Level@Material@RenderNew@RBX', 0x874ae4, 12),
        ('new_material', 'Level@MaterialBase@RenderBase@RBX', 0x874a8c, 12)):
    assert original.vtable_class(address) == ('.?AV%s@@' % cls, 0), (cls, original.vtable_class(address))
    vt[cls] = check_vtable(OBJ[key], '??_7%s@@6B@' % cls, address)
    assert len(vt[cls]) == count, (cls, len(vt[cls]))

# ---- RTTI bases (original) -----------------------------------------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


RCO = '.?AVReferenceCountedObject@G3D@@'
BASE = '.?AVTextureProxyBase@RBX@@'
assert bases(0x82d168) == {BASE: 0, RCO: 0}
for vtable, ns in ((0x82d140, 'Render'), (0x82d18c, 'RenderNew')):
    assert bases(vtable) == {'.?AVTextureProxy@%s@RBX@@' % ns: 0, BASE: 0, RCO: 0}, ns
for vtable, ns in ((0x875cec, 'Render'), (0x874bd8, 'RenderNew')):
    assert bases(vtable) == {'.?AVMegaTextureProxy@%s@RBX@@' % ns: 0, '.?AVTextureProxy@%s@RBX@@' % ns: 0, BASE: 0,
                             RCO: 0}, ns
for vtable, ns in ((0x875bc4, 'Render'), (0x874ac0, 'RenderNew')):
    assert bases(vtable) == {'.?AVMaterial@%s@RBX@@' % ns: 0, '.?AVMaterialBase@RenderBase@RBX@@': 0, RCO: 0}, ns
for vtable, ns in ((0x875be8, 'Render'), (0x874ae4, 'RenderNew')):
    assert bases(vtable) == {'.?AVLevel@Material@%s@RBX@@' % ns: 0, '.?AVLevel@MaterialBase@RenderBase@RBX@@': 0}, ns
assert bases(0x874a8c) == {'.?AVLevel@MaterialBase@RenderBase@RBX@@': 0}
assert bases(0x874b34) == {'.?AVBadConversion@RenderNew@RBX@@': 0, '.?AVruntime_error@std@@': 0,
                           '.?AVexception@std@@': 0}

# Allocation sizes pushed before the constructors.


def alloc_before(function, size, callee):
    b = body(function)
    at = b.index(b'\x68' + struct.pack('<I', size)) if size > 0x7f else b.index(b'\x6a' + bytes([size]))
    call = b.index(b'\xe8', at)
    while (function + call + 5 + struct.unpack_from('<i', b, call + 1)[0]) & 0xffffffff != callee:
        call = b.index(b'\xe8', call + 1)
    return at


alloc_before(0x551920, 0x60, 0x551e30)   # RenderNew::TextureProxy
alloc_before(0x551920, 0x54, 0x551b30)   # Render::TextureProxy
alloc_before(0x551a30, 0x64, 0x7ae4b0)   # RenderNew::MegaTextureProxy
alloc_before(0x551a30, 0x58, 0x7b8fb0)   # Render::MegaTextureProxy
alloc_before(0x7b8500, 0x54, 0x7b8450)
alloc_before(0x7aded0, 0x60, 0x7ade10)
alloc_before(0x7b8eb0, 0x54, 0x7b8450)

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT] + [s for s, _ in UNITS.values()] + HEADERS
exact = sorted({r['address'] for g in groups.values() for r in g if r['exact']})
assert all(r['exact'] for g in folded_out.values() for r in g)
# Bodies of other units kept by identical-code folding (00409dc0 runtime_error ??_G, 00503cb0): never counted. The
# MaterialBase::Level throwing defaults folded onto the counted row 007accd0 add no address.
folded = sorted({r['address'] for g in folded_out.values() for r in g} - set(exact))
assert set(folded) == {'00409dc0', '00503cb0'}, folded
groups['folded_not_counted'] = [r for g in folded_out.values() for r in g]
groups['not_exact'] = []
PROPOSALS = {}
receipt = {
    'class': 'RBX::TextureProxyBase; RBX::Render::TextureProxy / MegaTextureProxy; RBX::RenderNew::TextureProxy / '
             'MegaTextureProxy / BadConversion (stringify); RBX::RenderBase::MaterialBase::Level; RBX::Render::Material '
             '/ Material::Level; RBX::RenderNew::Material / Material::Level',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in [layout_obj] + list(OBJ.values())},
    'layout': {k: hex(v) for k, v in SIZES.items()},
    'rows': groups,
    'exact_function_rows': exact,
    'folded_rows_not_counted': folded,
    'function_local_statics': {'%s @ %08x' % k: hex(v) for k, v in sorted(statics.items())},
    'vtables': vt,
    'proposals': PROPOSALS,
    'not_built': {
        '00551920/00551a30': 'texture-proxy factories: select on the unnamed global 00942ec4 (render mode) and throw '
                             'std::exception("Invalid factory type"); no declaration derivable for the global',
        '007b8610/007b9000': 'Render::TextureProxy::resolve / MegaTextureProxy::resolve (2204 / 843 bytes)',
        '007aec70/007ae4e0': 'RenderNew::TextureProxy::resolve / MegaTextureProxy::resolve (4073 / 1368 bytes, Ogre)',
        '007ad9d0/007ada80/007add10/007ad9b0': 'RenderNew resolve helpers (pixel shading, power-of-two) not attempted',
        '007b8180/007b82f0/007b8400': 'Render unit helpers used by resolve, not attempted',
    },
    'naming': 'TextureProxyBase intProperty / floatProperty and MegaTextureProxy::scalar have no symbol evidence; '
              'intProperty selects the texture combine mode in configureRenderDevice 007b7b10. The evidence names '
              'reflect (007b76c0) / transparent (00503cb0) were matched against the donor non-virtual layout (no vptr); '
              'in 2008 the level has a vptr, so +0x20 / +0x24 are shiny / reflect (constructor argument order).',
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/render-material-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native render material: %d distinct function rows exact (%s); %d folded rows verified, not counted; '
      'targets and %d vtables verified' % (len(exact), ', '.join('%s %d' % (k, sum(r['exact'] for r in g))
                                                                 for k, g in groups.items()
                                                                 if k not in ('not_exact', 'folded_not_counted')),
                                           len(folded), len(vt)))
