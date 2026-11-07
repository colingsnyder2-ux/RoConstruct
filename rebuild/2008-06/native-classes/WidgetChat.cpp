// 2008-06 native gui ChatWidget unit (inactive): ChatWidget 0064e8a0..0064ea70, UnifiedImageWidget::render2dMe
// 0064e840, and the UnifiedImageWidget / ChatButton constructors 00601c50 / 00601d00.
// Layout and addresses in native-headers/gui/WidgetChat.h; verified by tests/record_native_widget.py.
// >>> native-status (generated) -- do not edit >>>
// WidgetChat | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src cb61a1ed | roc native-status --write
#include "gui/WidgetChat.h"

namespace RBX
{
#ifdef NATIVE_WIDGET_PENDING
	// Both read UnifiedWidget::menuState (+0x144) directly (0064e851, 0064e8a0): they need
	// UnifiedWidget::getMenuState inline in gui/Gui.h (declared out of line there).
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
#endif

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
