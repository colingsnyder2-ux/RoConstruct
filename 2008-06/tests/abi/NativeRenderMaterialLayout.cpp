// Layout probes for the inactive native RBX::TextureProxyBase, Render/RenderNew TextureProxy / MegaTextureProxy and
// Render/RenderNew Material / Material::Level (2008-06). Each probe compiles to `mov eax, imm32; ret`;
// tests/record_native_render_material.py compares the immediates with the sizes and offsets read from the original
// (allocation sizes, constructor stores, field accesses).
#include "RenderLib/TextureProxy2008.h"
#include "RenderLib/Material2008.h"
#include <stddef.h>

using namespace RBX;

struct NativeRenderMaterialLayout
{
	static int proxyBaseSize() { return sizeof(TextureProxyBase); }
	static int proxyBaseFilename() { return offsetof(TextureProxyBase, filename); }
	static int proxyBaseIntProperty() { return offsetof(TextureProxyBase, intProperty); }
	static int proxyBaseFloatProperty() { return offsetof(TextureProxyBase, floatProperty); }
	static int renderProxySize() { return sizeof(Render::TextureProxy); }
	static int renderProxyTexture() { return offsetof(Render::TextureProxy, texture); }
	static int renderProxyLoaded() { return offsetof(Render::TextureProxy, loaded); }
	static int renderProxyManager() { return offsetof(Render::TextureProxy, textureManager); }
	static int renderProxyTiled() { return offsetof(Render::TextureProxy, tiled); }
	static int renderProxyRoot() { return offsetof(Render::TextureProxy, root); }
	static int renderProxyShadeTexture() { return offsetof(Render::TextureProxy, shadeTexture); }
	static int renderProxyShadeColor() { return offsetof(Render::TextureProxy, shadeColor); }
	static int renderMegaSize() { return sizeof(Render::MegaTextureProxy); }
	static int renderMegaScalar() { return offsetof(Render::MegaTextureProxy, scalar); }
	static int newProxySize() { return sizeof(RenderNew::TextureProxy); }
	static int newProxyRoot() { return offsetof(RenderNew::TextureProxy, root); }
	static int newProxyShadeColor() { return offsetof(RenderNew::TextureProxy, shadeColor); }
	static int newProxyOgreTexture() { return offsetof(RenderNew::TextureProxy, ogreTexture); }
	static int newMegaSize() { return sizeof(RenderNew::MegaTextureProxy); }
	static int newMegaScalar() { return offsetof(RenderNew::MegaTextureProxy, scalar); }
	static int renderMaterialSize() { return sizeof(Render::Material); }
	static int renderMaterialLevels() { return offsetof(Render::Material, levels); }
	static int renderLevelSize() { return sizeof(Render::Material::Level); }
	static int renderLevelEmpty() { return offsetof(Render::Material::Level, emptyLevel); }
	static int renderLevelMatte() { return offsetof(Render::Material::Level, mMatte); }
	static int renderLevelBaseTexture() { return offsetof(Render::Material::Level, mBaseTexture); }
	static int renderLevelColor() { return offsetof(Render::Material::Level, mColor); }
	static int renderLevelSpecular() { return offsetof(Render::Material::Level, mSpecular); }
	static int renderLevelShiny() { return offsetof(Render::Material::Level, mShiny); }
	static int renderLevelReflect() { return offsetof(Render::Material::Level, mReflect); }
	static int renderLevelTransparent() { return offsetof(Render::Material::Level, mTransparent); }
	static int newMaterialSize() { return sizeof(RenderNew::Material); }
	static int newMaterialLevels() { return offsetof(RenderNew::Material, levels); }
	static int newLevelSize() { return sizeof(RenderNew::Material::Level); }
	static int newLevelTransparent() { return offsetof(RenderNew::Material::Level, mTransparent); }
	static int newLevelOgreMaterial() { return offsetof(RenderNew::Material::Level, ogreMaterial); }
	static int baseLevelSize() { return sizeof(RenderBase::MaterialBase::Level); }
};

#define PROBE(name) int native##name() { return NativeRenderMaterialLayout::name(); }
PROBE(proxyBaseSize) PROBE(proxyBaseFilename) PROBE(proxyBaseIntProperty) PROBE(proxyBaseFloatProperty)
PROBE(renderProxySize) PROBE(renderProxyTexture) PROBE(renderProxyLoaded) PROBE(renderProxyManager)
PROBE(renderProxyTiled) PROBE(renderProxyRoot) PROBE(renderProxyShadeTexture) PROBE(renderProxyShadeColor)
PROBE(renderMegaSize) PROBE(renderMegaScalar) PROBE(newProxySize) PROBE(newProxyRoot) PROBE(newProxyShadeColor)
PROBE(newProxyOgreTexture) PROBE(newMegaSize) PROBE(newMegaScalar) PROBE(renderMaterialSize)
PROBE(renderMaterialLevels) PROBE(renderLevelSize) PROBE(renderLevelEmpty) PROBE(renderLevelMatte)
PROBE(renderLevelBaseTexture) PROBE(renderLevelColor) PROBE(renderLevelSpecular) PROBE(renderLevelShiny)
PROBE(renderLevelReflect) PROBE(renderLevelTransparent) PROBE(newMaterialSize) PROBE(newMaterialLevels)
PROBE(newLevelSize) PROBE(newLevelTransparent) PROBE(newLevelOgreMaterial) PROBE(baseLevelSize)
