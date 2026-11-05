// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-client roc_unit_8c2419f17cad6261.cpp

// Candidate translation unit (score above; library headers required).
// Edited vendor unit: 2008-06 TextureProxy ctor proves TextureProxyBase is 0x30
// (texture@0x30, loaded@0x34, textureManager@0x38, root@0x40, shadeTexture@0x44);
// openrbx/rbxgs headers say base 0x28. Predefine both include guards and replay the
// classes with 8 extra POD bytes in the base, then compile the authentic .cpp.
#define RBXGRAPHICS_TEXTUREPROXYBASE_H 1
#define RENDERLIB_TEXTUREPROXY_H 1
#include <G3D/ReferenceCount.h>
#include <G3D/Vector2.h>
#include <G3D/Color3.h>
#include <G3D/Color3uint8.h>
#include <GLG3D/Texture.h>
#include <GLG3D/TextureManager.h>
#include <string>

namespace G3D {
class RenderDevice;
}

namespace RBX {

typedef G3D::ReferenceCountedPointer<class TextureProxyBase> TextureProxyBaseRef;

class TextureProxyBase : public G3D::ReferenceCountedObject
{
public:
	std::string filename; // 0x0c
	int extra0;           // 0x28: 8 proven bytes before TextureProxy::texture@0x30
	int extra1;           // 0x2c

	TextureProxyBase() {}
	virtual ~TextureProxyBase() {}

	virtual G3D::Vector2 getSize() = 0; // vtable+0x04
};

namespace Render {

class TextureProxy;

typedef G3D::ReferenceCountedPointer<TextureProxy> TextureProxyRef;

class TextureProxy : public TextureProxyBase
{
protected:
	G3D::ReferenceCountedPointer<G3D::Texture> texture; // 0x30
	bool loaded;                                        // 0x34
	G3D::TextureManager* textureManager;                // 0x38
	bool tiled;                                         // 0x3c
	TextureProxyRef root;                               // 0x40
	TextureProxyRef shadeTexture;                       // 0x44
	G3D::Color3 shadeColor;                             // 0x48

	TextureProxy(TextureProxyRef root) : loaded(false), textureManager(NULL), root(root) { filename = ""; }

public:
	TextureProxy(G3D::TextureManager& textureManager, const std::string& filename, bool tiled)
		: loaded(false), textureManager(&textureManager), tiled(tiled)
	{
		this->filename = filename;
	}

	TextureProxyRef shade(const G3D::Color3& baseColor, const TextureProxyRef& baseTex);

	TextureProxyRef alphaOnlyVersion();

	virtual G3D::ReferenceCountedPointer<G3D::Texture> getIfResolved() const;
	virtual G3D::ReferenceCountedPointer<G3D::Texture> resolve(G3D::RenderDevice* rd);

	static void shadePixel(const G3D::Color3uint8& base, G3D::Color3uint8& lighting);

	virtual G3D::Vector2 getSize(); // vtable+0x04
};

} // namespace Render
} // namespace RBX

#include "Rendering/RenderLib/TextureProxy.cpp"
