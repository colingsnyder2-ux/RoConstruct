// >>> native-status (generated) -- do not edit >>>
// GuiDrawImage | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src f5a94f05 | roc native-status --write
#include "gui/GuiDraw.h"
#include "AppDraw/Textures.h"
namespace RBX {
void GuiDrawImage::setImageFromName(Adorn* adorn, const std::string& name)
{
    ContentId id = ContentId::fromAssets("Textures\\" + name + ".png");
    setImage(adorn, id);
}
}

#include "gui/GuiDraw.h"
#include "AppDraw/Textures.h"
namespace RBX {
void GuiDrawImage::draw(Adorn* adorn, G3D::ReferenceCountedPointer<TextureProxyBase> texture, const Rect& rect, const G3D::Color4& behind, const G3D::Color4& inFront)
	{
		G3D::Rect2D rect2D = rect.toRect2D();

		if (texture.notNull())
		{
			adorn->setTexture(0, texture);
			adorn->rect2d(rect2D, G3D::Color4(1.0f, 1.0f, 1.0f, 1.0f));
			adorn->setTexture(0, NULL);
		}
		else if (normal.notNull())
		{
			adorn->rect2d(rect2D, behind);
			draw(adorn, normal, rect, G3D::Color4::clear(), G3D::Color4::clear());
			adorn->rect2d(rect2D, inFront);
		}
	}
}

#include "gui/GuiDraw.h"
#include "AppDraw/Textures.h"
namespace RBX {
void GuiDrawImage::render2d(Adorn* adorn, bool enabled, Rect& rect, Widget::WidgetState state)
	{
		if (!enabled)
		{
			draw(adorn, disable, rect, G3D::Color4::clear(), G3D::Color4(1.0f, 1.0f, 1.0f, 0.5f));
		}
		else if (state == Widget::NOTHING)
		{
			draw(adorn, normal, rect, G3D::Color4::clear(), G3D::Color4::clear());
		}
		else if (state != Widget::HOVER && state != Widget::DOWN_AWAY)
		{
			draw(adorn, down, rect, G3D::Color3::blue(), G3D::Color4::clear());
		}
		else
		{
			draw(adorn, hover, rect, G3D::Color3::yellow(), G3D::Color4::clear());
		}
	}
}
