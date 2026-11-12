// Native GuiDrawImage layout: 00642750 uses TextureId +0x00, normal +0x20, disable +0x24, hover +0x28, down +0x2c, size +0x30.
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
		// INFERRED: 00642690 caches TextureProxyBase::getSize() at +0x30/+0x34 in a const method.
		mutable G3D::Vector2 size;

	private:
		void draw(Adorn*, G3D::ReferenceCountedPointer<TextureProxyBase>, const Rect&, const G3D::Color4&, const G3D::Color4&);
		void setImageFromName(Adorn*, const std::string&);
	public:
		GuiDrawImage(Adorn*, const std::string&);
		GuiDrawImage();
	public:
		void render2d(Adorn* adorn, bool enabled, Rect& rect, Widget::WidgetState state);
		void setImageSize(const G3D::Vector2&);
		G3D::Vector2 getImageSize() const;
		bool setImage(Adorn* adorn, const TextureId& textureId);
	};
}
