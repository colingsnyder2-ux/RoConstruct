#pragma once
// >>> native-status (generated) -- do not edit >>>
// TextureProxyBase2008 | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src d2bbd67d | roc native-status --write
// RBX::TextureProxyBase as compiled into the June 2008 client (inactive native recovery).
//
// Non-colliding name: many units include the donor RbxGraphics/TextureProxyBase.h at its original path (a later, smaller
// interface), so the 2008 interface is declared here and only included by the native TextureProxy / RenderMaterial units.
//
// Evidence (original Roblox.exe):
//   * RTTI: vtable 0082d168, .?AVTextureProxyBase@RBX@@ -> .?AVReferenceCountedObject@G3D@@ (offset 0).
//   * Constructor 00551bf0 (/Od body, out of line: the optimized RenderLib units call it, e.g. 007ade34 / 007b8474):
//     ReferenceCountedObject() 00472990, vptr 0082d168, std::string() at +0x0c (msvcp90 import), +0x28 = 1, +0x2c = 1.0f.
//   * Destructor 00551cf0: vptr 0082d168, ~basic_string at +0x0c, ~ReferenceCountedObject 007accf0. It is inline: the
//     optimized RenderNew::TextureProxy destructor 007ae3b0 inlines it (vptr 0082d168, ~basic_string, vptr 0081e1e0).
//   * Size 0x30: the derived members start at +0x30 (Render::TextureProxy ctor 00551b30).
//   * Vtable (8 slots): 0 scalar deleting dtor 00551d50, 1 00551c70 (store int +0x28), 2 00551c90 (load +0x28),
//     3 00551cb0 (store float +0x2c), 4 00551cd0 (load float +0x2c), 5..7 _purecall (getSize / resolve / shade, the
//     overriders in Render::TextureProxy 007b8f40 / 007b8610 / 007b8500 and RenderNew::TextureProxy 007adb70 / 007aec70 /
//     007aded0).
//   * The two property pairs have no symbol evidence; the names below are naming choices (intProperty / floatProperty),
//     not original names.
#include <string>
#include <G3D/ReferenceCount.h>
#include <G3D/Vector2.h>
#include <G3D/Color3.h>

namespace G3D
{
	class Texture;
	class RenderDevice;
}

namespace RBX
{
	class TextureProxyBase;
	typedef G3D::ReferenceCountedPointer<TextureProxyBase> TextureProxyBaseRef;

	class TextureProxyBase : public G3D::ReferenceCountedObject
	{
	public:
		std::string filename;                                                     // +0x0c
		int intProperty;                                                          // +0x28 (ctor: 1)
		float floatProperty;                                                      // +0x2c (ctor: 1.0f)

	public:
		TextureProxyBase();                                                       // 00551bf0
		virtual ~TextureProxyBase()                                               // slot 0: 00551cf0 / ??_G 00551d50
		{
		}
		virtual void setIntProperty(int value);                                   // slot 1: 00551c70
		virtual int getIntProperty() const;                                       // slot 2: 00551c90
		virtual void setFloatProperty(float value);                               // slot 3: 00551cb0
		virtual float getFloatProperty() const;                                   // slot 4: 00551cd0
		virtual G3D::Vector2 getSize() = 0;                                       // slot 5
		virtual G3D::ReferenceCountedPointer<G3D::Texture> resolve(G3D::RenderDevice* rd) = 0;              // slot 6
		virtual TextureProxyBaseRef shade(const G3D::Color3& color, const TextureProxyBaseRef& base) = 0;   // slot 7
	};
}
