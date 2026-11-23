// =============================================================================
// TextureProxy.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/renderlib/include/renderlib/TextureProxy.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "RbxGraphics/TextureProxyBase.h"
#include <G3D/Color3uint8.h>
#include <GLG3D/RenderDevice.h>
#include <GLG3D/Texture.h>
#include <GLG3D/TextureManager.h>

namespace RBX
{
	namespace Render
	{
		class TextureProxy : public TextureProxyBase
		{
		protected:
			G3D::ReferenceCountedPointer<G3D::Texture> texture;
			bool loaded;
			G3D::TextureManager* textureManager;
			bool tiled;
			G3D::ReferenceCountedPointer<TextureProxy> root;
			G3D::ReferenceCountedPointer<TextureProxy> shadeTexture;
			G3D::Color3 shadeColor;
		public:
			//TextureProxy(const TextureProxy&);
			TextureProxy(G3D::TextureManager& textureManager, const std::string& filename, bool tiled)
				: textureManager(&textureManager),
				  loaded(false),
				  tiled(tiled)
			{
				this->filename = filename;
			}
		protected:
			TextureProxy(G3D::ReferenceCountedPointer<TextureProxy> root)
				: root(root),
				  loaded(false),
				  textureManager(NULL)
			{
				this->filename = "";
			}
		public:
			G3D::ReferenceCountedPointer<TextureProxy> shade(
				const G3D::Color3& baseColor,
				const G3D::ReferenceCountedPointer<TextureProxy>& baseTex);
			G3D::ReferenceCountedPointer<TextureProxy> alphaOnlyVersion();
			virtual G3D::ReferenceCountedPointer<G3D::Texture> getIfResolved() const;
			virtual G3D::ReferenceCountedPointer<G3D::Texture> resolve(G3D::RenderDevice* rd);
			virtual G3D::Vector2 getSize();
			virtual ~TextureProxy();
			//TextureProxy& operator=(const TextureProxy&);

			static void shadePixel(const G3D::Color3uint8&, G3D::Color3uint8&);
		};
	}
}
