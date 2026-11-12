// 2008-06 native RBX::Widget / RBX::VerbWidget unit (inactive): the original gui/Widget.cpp, 00641ff0..006426f0.
// Layout and addresses in native-headers/gui/Widget.h; verified by tests/record_native_widget.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// Widget | 2008-06 | 3 byte-exact, inactive (not link-selected)
// 3/8 mapped addresses byte-exact | named 1 | 5 unproved | no mapped strings | by auto (+2) (mixed 4)
// <<< native-status | src 2c5cc7da | roc native-status --write
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/widget-rect-2008
#include "gui/Widget.h"

namespace RBX
{
	// 00641ff0: Rect::pointInRect(G3D::Vector2int16) is out of line at 00573130.
	GuiResponse Widget::processMouse(const GuiEvent& event)
	{
		bool inWidget = getMyRect().pointInRect(event.mousePosition);

		switch (widgetState)
		{
		case NOTHING:
		case HOVER:
			if (inWidget)
			{
				if (!isEnabled())
				{
					widgetState = NOTHING;
					return GuiResponse::used();
				}

				switch (event.eventType)
				{
				case GuiEvent::MOUSE_LEFT_BUTTON_DOWN:
					widgetState = DOWN_OVER;
					onDown(event);
					return GuiResponse::used();

				case GuiEvent::MOUSE_MOVE:
					widgetState = HOVER;
					return GuiResponse::used();

				default:
					return GuiResponse::used();
				}
			}
			else
			{
				widgetState = NOTHING;
				return GuiResponse::notUsed();
			}

		case DOWN_OVER:
			switch (event.eventType)
			{
			case GuiEvent::MOUSE_LEFT_BUTTON_DOWN:
				return GuiResponse::used();

			case GuiEvent::MOUSE_LEFT_BUTTON_UP:
				widgetState = NOTHING;
				onUp(event);

				if (inWidget)
				{
					onClick(event);
					return GuiResponse::finished();
				}
				else
				{
					return GuiResponse::notUsed();
				}

			case GuiEvent::MOUSE_MOVE:
				if (!inWidget)
					widgetState = onDrag(event) ? NOTHING : DOWN_AWAY;

				return GuiResponse::used();
			}
			break;

		case DOWN_AWAY:
			switch (event.eventType)
			{
			case GuiEvent::MOUSE_LEFT_BUTTON_DOWN:
				return GuiResponse::used();

			case GuiEvent::MOUSE_LEFT_BUTTON_UP:
				widgetState = NOTHING;
				onUp(event);

				if (inWidget)
				{
					onClick(event);
					return GuiResponse::used();
				}
				else
				{
					return GuiResponse::notUsed();
				}

			case GuiEvent::MOUSE_MOVE:
				widgetState = inWidget ? DOWN_OVER : DOWN_AWAY;
				return GuiResponse::used();
			}
		}
		return GuiResponse::notUsed();
	}

	GuiResponse Widget::process(const GuiEvent& event)
	{
		// The 2008 build tests the mouse event range directly (cmp 1 / jl, cmp 7 / jg at 0064222e), not the chain of
		// equalities in the donor UIEvent::isMouseEvent.
		if (isEnabled() && event.eventType >= UIEvent::MOUSE_RIGHT_BUTTON_DOWN && event.eventType <= UIEvent::MOUSE_IDLE)
		{
			return processMouse(event);
		}
		else
		{
			return GuiResponse::notUsed();
		}
	}

	void VerbWidget::onClick(const GuiEvent& event)
	{
		if (verb && verb->isEnabled())
			verb->doIt(event.iDataState);
	}

	Widget::Widget()
		: widgetState(Widget::NOTHING)
	{
		setGuiSize(G3D::Vector2(100.0f, 24.0f));
	}

	VerbWidget::VerbWidget(Verb* verb)
		: verb(verb)
	{
	}

	bool VerbWidget::isEnabled()
	{
		return Widget::isEnabled() && verb && verb->isEnabled();
	}

	VerbWidget::~VerbWidget()
	{
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
}
