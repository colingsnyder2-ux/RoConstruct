#include "gui/Widget.h"
#include "gui/Button.h"

namespace RBX
{
	Widget::Widget()
		: widgetState(Widget::NOTHING)
	{
		setGuiSize(G3D::Vector2(100.0f, 25.0f));
	}

	void Widget::render2d(Adorn* adorn)
	{
		if (isVisible())
		{
			if (widgetState == Widget::HOVER || widgetState == Widget::DOWN_AWAY)
			{
				adorn->rect2d(getMyRect2D(), G3D::Color3::gray());
			}
			else if (widgetState == Widget::DOWN_OVER)
			{
				adorn->rect2d(getMyRect2D(), G3D::Color3::yellow());
			}

			label2d(adorn, getTitle(), isEnabled() ? getFontColor() : disabledFill(), G3D::Color4(0.5f, 0.5f, 0.5f, 0.25f), Adorn::XALIGN_LEFT);
		}
	}

	GuiResponse Widget::process(const GuiEvent& event)
	{
		if (isEnabled() && event.isMouseEvent())
		{
			return processMouse(event);
		}
		else
		{
			return GuiResponse();
		}
	}
}


namespace RBX
{
	void VerbWidget::onClick(const GuiEvent& event)
	{
		if (verb && verb->isEnabled())
			verb->doIt(event.iDataState);
	}

	bool VerbWidget::isEnabled()
	{
		return Widget::isEnabled() && verb && verb->isEnabled();
	}
}


namespace RBX
{
	void ImageWidget::render2d(Adorn* adorn)
	{
		if (isVisible())
			guiImageDraw.render2d(adorn, isEnabled(), getMyRect(), Widget::NOTHING);
	}
}
