// Rebuild glue: Message and RefPropertyDescriptor members rbxgs declares but never defines.
// RefPropertyDescriptor string access follows OpenRBX reflection/property.h (2008-verified: empty
// string, setting fails). Message::renderPersonalMsg is a behavioural reconstruction in the style of
// rbxgs Message::renderFullScreen (a personal message is a banner at the top, not a screen overlay).
#include "v8datamodel/Message.h"
#include "reflection/property.h"
#include <G3D/Rect2D.h>

namespace RBX
{
	void Message::renderPersonalMsg(Adorn* adorn)
	{
		G3D::Rect2D viewport = adorn->getViewport();
		G3D::Rect2D banner = G3D::Rect2D::xywh(viewport.x0(), viewport.y0(), viewport.width(), 30.0f);
		adorn->rect2d(banner, G3D::Color4(0.5f, 0.5f, 0.5f, 0.5f));
		adorn->drawFont2D(text, banner.center(), 12.0, G3D::Color3::white(), G3D::Color3::black(),
						  Adorn::XALIGN_CENTER, Adorn::YALIGN_CENTER, Adorn::PROPORTIONAL_SPACING);
	}

	// a Hint is a dark bar along the bottom of the screen with its text in it
	void Hint::render2d(Adorn* adorn)
	{
		if (text.empty())
			return;
		G3D::Rect2D viewport = adorn->getViewport();
		G3D::Rect2D bar = G3D::Rect2D::xywh(viewport.x0(), viewport.y1() - 20.0f, viewport.width(), 20.0f);
		adorn->rect2d(bar, G3D::Color4(0.0f, 0.0f, 0.0f, 1.0f));
		adorn->drawFont2D(text, bar.center(), 12.0, G3D::Color3::white(), G3D::Color3::black(),
						  Adorn::XALIGN_CENTER, Adorn::YALIGN_CENTER, Adorn::PROPORTIONAL_SPACING);
	}

	namespace Reflection
	{
		std::string RefPropertyDescriptor::getStringValue(const DescribedBase*) const
		{
			return std::string();
		}

		bool RefPropertyDescriptor::setStringValue(DescribedBase*, const std::string&) const
		{
			return false;
		}
	}
}
