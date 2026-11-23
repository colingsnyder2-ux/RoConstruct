// =============================================================================
// GuiDraw.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/gui/GuiDraw.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "gui/Gui.h"
#include "gui/Widget.h"
#include "util/TextureId.h"

namespace RBX
{
	class GuiDrawImage
	{
	private:
		TextureId currentTexture;
		G3D::ReferenceCountedPointer<TextureProxyBase> normal;
		G3D::ReferenceCountedPointer<TextureProxyBase> disable;
		G3D::ReferenceCountedPointer<TextureProxyBase> hover;
		G3D::ReferenceCountedPointer<TextureProxyBase> down;
		mutable G3D::Vector2 size;

	private:
		void draw(
			Adorn* adorn,
			G3D::ReferenceCountedPointer<TextureProxyBase> texture,
			const Rect& rect,
			const G3D::Color4& behind,
			const G3D::Color4& inFront);
		void setImageFromName(Adorn* adorn, const std::string& name);
	public:
		GuiDrawImage(Adorn* adorn, const std::string& name)
		{
			setImageFromName(adorn, name);
		}
		GuiDrawImage()
		{
		}
	public:
		void render2d(Adorn* adorn, bool enabled, Rect& rect, Widget::WidgetState state);
		void setImageSize(const G3D::Vector2&);
		G3D::Vector2 getImageSize() const;
		bool setImage(Adorn* adorn, const TextureId& textureId);
	};
}
