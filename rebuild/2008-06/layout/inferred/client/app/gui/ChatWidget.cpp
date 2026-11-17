#include "gui/WidgetChat.h"

namespace RBX
{
	inline UnifiedWidget::MenuState UnifiedWidget::getMenuState() const { return menuState; }

	void UnifiedImageWidget::render2dMe(Adorn* adorn)
	{
		if (isVisible())
		{
			Widget::WidgetState state;
			switch (getMenuState())
			{
			case HOVER:
				state = Widget::HOVER;
				break;
			case SHOWN_APPEARING:
			case SHOWN:
				state = Widget::DOWN_OVER;
				break;
			default:
				state = Widget::NOTHING;
				break;
			}
			guiImageDraw.render2d(adorn, true, getMyRect(), state);
		}
	}

	void ChatWidget::onMenuStateChanged()
	{
		if (getMenuState() == HOVER)
			setMenuState(SHOWN);
	}

	ChatWidget::ChatWidget(const std::string& title, std::string code)
	{
		setName(title);
		this->code = code;
	}

	UnifiedImageWidget::UnifiedImageWidget(Adorn* adorn, const std::string& name)
		: guiImageDraw(adorn, name)
	{
	}

	G3D::Vector2 UnifiedImageWidget::getSize() const
	{
		return guiImageDraw.getImageSize();
	}

	ChatButton::ChatButton(Adorn* adorn, const std::string& name)
		: UnifiedImageWidget(adorn, name)
	{
	}
}
