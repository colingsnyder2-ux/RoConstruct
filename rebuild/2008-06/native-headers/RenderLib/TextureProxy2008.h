#pragma once
// >>> native-status (generated) -- do not edit >>>
// TextureProxy2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 3ea0ee86 | roc native-status --write
// RBX::Render::TextureProxy / MegaTextureProxy and RBX::RenderNew::TextureProxy / MegaTextureProxy / BadConversion as
// compiled into the June 2008 client (inactive native recovery).
//
// Non-colliding name: units include the donor RenderLib/TextureProxy.h at its original path, so the 2008 interface is
// declared here and only included by the native TextureProxy / RenderMaterial units. The RenderNew classes need the
// Ogre 1.4.5 client headers (tools/libs/ogre-1.4.5/ogrenew/OgreMain/include, OGRE_NONCLIENT_BUILD undefined: the
// TexturePtr constructor / destructor are rgmain.dll imports).
//
// Evidence (original Roblox.exe):
//   * RTTI: Render::TextureProxy 0082d140 and RenderNew::TextureProxy 0082d18c -> TextureProxyBase -> G3D::
//     ReferenceCountedObject; Render::MegaTextureProxy 00875cec / RenderNew::MegaTextureProxy 00874bd8 -> TextureProxy.
//   * Allocation sizes (the factories 00551920 / 00551a30 and shade 007b8500 / 007aded0, alphaOnlyVersion 007b8eb0):
//     Render::TextureProxy 0x54, Render::MegaTextureProxy 0x58, RenderNew::TextureProxy 0x60,
//     RenderNew::MegaTextureProxy 0x64.
//   * Render::TextureProxy(TextureManager&, const std::string&, bool) 00551b30 (/Od): TextureProxyBase() 00551bf0,
//     Ref() +0x30, +0x34 = false, +0x38 = &manager, +0x3c = tiled, Ref() +0x40 / +0x44, Color3() +0x48, then
//     filename = name (basic_string::operator= import). The root constructor 007b8450: +0x30 = 0, +0x34 = false,
//     +0x38 = 0, +0x40 = root (setPointer), +0x44 = 0, filename = "" (operator=(const char*) import).
//   * Render::TextureProxy has no user destructor: 00551db0 (reached through ??_G 00551d80 and MegaTextureProxy ??_G
//     007b9350) releases +0x44 / +0x40 / +0x30 and calls ~TextureProxyBase 00551cf0 without a vptr store.
//   * RenderNew::TextureProxy(const std::string&) 0066ffb0 (out of line; called by AdornRbxGfx::createTextureProxy
//     00670380 after new(0x60)): TextureProxyBase() 00551bf0, vptr 0082d18c, +0x30 / +0x40 / +0x44 = 0, +0x34 = false,
//     TexturePtr() at +0x54, then filename = name (basic_string::operator= import); +0x38 / +0x3c / +0x48 untouched.
//   * RenderNew::TextureProxy adds Ogre::TexturePtr at +0x54 (ctor 00551e30 calls the rgmain import at +0x54; getSize
//     007adb70 reads its pRep at +0x58) and declares a destructor 007ae3b0 (vptr store, ~TexturePtr, +0x44 / +0x40 /
//     +0x30 released, inlined ~TextureProxyBase).
//   * Vtable slot order (beyond the TextureProxyBase slots): 5 getSize, 6 resolve, 7 shade; Render::TextureProxy adds
//     slot 8 getIfResolved 007b85e0 (returns the +0x30 reference).
//   * MegaTextureProxy(TextureManager&, const std::string&) 007b8fb0 / 007ae4b0: TextureProxy(manager, name, false),
//     float +0x54 / +0x60 = 0, vptr. Its shade slot is 007b8fe0 (returns a null reference, shared by both namespaces).
//   * RenderNew::BadConversion (RTTI 00874b34 -> std::runtime_error -> std::exception): the copy constructor 007adcf0
//     (runtime_error copy 00409e90, vptr); thrown by stringify(double) 007adbe0 with "stringify(double)".
#include <string>
#include <stdexcept>
#include <G3D/Color3.h>
#include <GLG3D/RenderDevice.h>
#include <GLG3D/Texture.h>
#include <GLG3D/TextureManager.h>
#include "RbxGraphics/TextureProxyBase2008.h"
#include <OgreTexture.h>

struct NativeRenderMaterialLayout;

namespace RBX
{
	namespace Render
	{
		class TextureProxy : public TextureProxyBase
		{
			friend struct ::NativeRenderMaterialLayout;

		protected:
			G3D::ReferenceCountedPointer<G3D::Texture> texture;                  // +0x30
			bool loaded;                                                          // +0x34
			G3D::TextureManager* textureManager;                                  // +0x38
			bool tiled;                                                           // +0x3c
			G3D::ReferenceCountedPointer<TextureProxy> root;                      // +0x40
			G3D::ReferenceCountedPointer<TextureProxy> shadeTexture;              // +0x44
			G3D::Color3 shadeColor;                                               // +0x48 (size 0x54)

		public:
			TextureProxy(G3D::TextureManager& textureManager, const std::string& filename, bool tiled);   // 00551b30
		protected:
			TextureProxy(G3D::ReferenceCountedPointer<TextureProxy> root);                               // 007b8450
		public:
			G3D::ReferenceCountedPointer<TextureProxy> alphaOnlyVersion();                               // 007b8eb0
			virtual G3D::Vector2 getSize();                                                               // slot 5 007b8f40
			virtual G3D::ReferenceCountedPointer<G3D::Texture> resolve(G3D::RenderDevice* rd);           // slot 6 007b8610
			virtual TextureProxyBaseRef shade(const G3D::Color3& color, const TextureProxyBaseRef& base); // slot 7 007b8500
			virtual G3D::ReferenceCountedPointer<G3D::Texture> getIfResolved() const;                    // slot 8 007b85e0
		};

		class MegaTextureProxy : public TextureProxy
		{
			friend struct ::NativeRenderMaterialLayout;

		protected:
			float scalar;                                                         // +0x54 (ctor: 0; size 0x58; name is a choice)

		public:
			MegaTextureProxy(G3D::TextureManager& textureManager, const std::string& filename);          // 007b8fb0
			virtual G3D::ReferenceCountedPointer<G3D::Texture> resolve(G3D::RenderDevice* rd);           // slot 6 007b9000
			virtual TextureProxyBaseRef shade(const G3D::Color3& color, const TextureProxyBaseRef& base) // slot 7 007b8fe0
			{
				return NULL;
			}
		};
	}

	namespace RenderNew
	{
		class BadConversion : public std::runtime_error
		{
		public:
			BadConversion(const std::string& s)
				: std::runtime_error(s)
			{
			}
		};

		std::string stringify(double x);                                          // 007adbe0

		class TextureProxy : public TextureProxyBase
		{
			friend struct ::NativeRenderMaterialLayout;

		protected:
			G3D::ReferenceCountedPointer<G3D::Texture> texture;                  // +0x30
			bool loaded;                                                          // +0x34
			G3D::TextureManager* textureManager;                                  // +0x38
			bool tiled;                                                           // +0x3c
			G3D::ReferenceCountedPointer<TextureProxy> root;                      // +0x40
			G3D::ReferenceCountedPointer<TextureProxy> shadeTexture;              // +0x44
			G3D::Color3 shadeColor;                                               // +0x48
			Ogre::TexturePtr ogreTexture;                                         // +0x54 (size 0x60)

		public:
			TextureProxy(G3D::TextureManager& textureManager, const std::string& filename, bool tiled);   // 00551e30
			TextureProxy(const std::string& name);                                                       // 0066ffb0
		protected:
			TextureProxy(G3D::ReferenceCountedPointer<TextureProxy> root);                               // 007ade10
		public:
			~TextureProxy();                                                                              // 007ae3b0
			virtual G3D::Vector2 getSize();                                                               // slot 5 007adb70
			virtual G3D::ReferenceCountedPointer<G3D::Texture> resolve(G3D::RenderDevice* rd);           // slot 6 007aec70
			virtual TextureProxyBaseRef shade(const G3D::Color3& color, const TextureProxyBaseRef& base); // slot 7 007aded0
		};

		class MegaTextureProxy : public TextureProxy
		{
			friend struct ::NativeRenderMaterialLayout;

		protected:
			float scalar;                                                         // +0x60 (ctor: 0; size 0x64; name is a choice)

		public:
			MegaTextureProxy(G3D::TextureManager& textureManager, const std::string& filename);          // 007ae4b0
			virtual G3D::ReferenceCountedPointer<G3D::Texture> resolve(G3D::RenderDevice* rd);           // slot 6 007ae4e0
			virtual TextureProxyBaseRef shade(const G3D::Color3& color, const TextureProxyBaseRef& base) // slot 7 007b8fe0
			{
				return NULL;
			}
		};
	}
}
