// 2008-06 native gui ChatWidget unit (inactive): ChatWidget 0064e8a0..0064ea70, UnifiedImageWidget::render2dMe
// 0064e840, and the UnifiedImageWidget / ChatButton constructors 00601c50 / 00601d00.
// Layout and addresses in native-headers/gui/WidgetChat.h; verified by tests/record_native_widget.py.
#include "gui/WidgetChat.h"

namespace RBX
{
	// Both bodies below read UnifiedWidget::menuState (+0x144) directly (0064e851, 0064e8a0): a unit-local inline
	// accessor in the pattern of the unit-local Verb::getName (RunStateCommands.cpp), since gui/Gui.h declares it out of
	// line (proposal for the Gui.h owner: make it inline there).
	inline UnifiedWidget::MenuState UnifiedWidget::getMenuState() const { return menuState; }

	// 0064e840
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

	// 0064e8a0
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
