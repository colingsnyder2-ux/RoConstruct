// Rebuild glue: GUI layout and widget input rbxgs declares but never defines (replacing empty stubs).
// Children of a menu bar are laid out in order along its layout style (as TopMenuBar::getSize sums
// them); a relative panel sits on the canvas by its Rect locations plus offset (as
// Rect::positionChild); a widget tracks hover/press and clicks on release over itself.
// Behavioural reconstruction, not byte-verified.
#include "gui/Gui.h"
#include "gui/Widget.h"
#include "gui/Layout.h"
#include "util/Rect.h"

namespace RBX
{
	G3D::Vector2 TopMenuBar::getChildPosition(const GuiItem* child) const
	{
		G3D::Vector2 position = getPosition();
		for (size_t i = 0; i < numChildren(); ++i)
		{
			const GuiItem* current = getGuiItem((int)i);
			if (!current)
				continue;
			if (current == child)
				break;
			G3D::Vector2 size = current->getSize();
			if (layoutStyle == Layout::VERTICAL)
				position.y += size.y;
			else
				position.x += size.x;
		}
		return position;
	}

	G3D::Vector2 RelativePanel::getPosition() const
	{
		// relative panels hang off the GUI root, so they are placed on the whole canvas
		Rect area(GuiRoot::getCanvasSize());
		Rect placed = area.positionChild(Rect(getSize()), xLocation, yLocation);
		return placed.low + G3D::Vector2(offset.x, offset.y);
	}

	// GUI sizes are already in canvas pixels in this build
	G3D::Vector2 GuiRoot::toPixelSize(const G3D::Vector2& size)
	{
		return size;
	}

	bool GuiRoot::askSetParent(const Instance*) const
	{
		return true;
	}

	void GuiItem::label2d(Adorn* adorn, const std::string& text, const G3D::Color4& color, const G3D::Color4& outline, Adorn::XAlign xalign) const
	{
		G3D::Rect2D rect = getMyRect2D();
		float x = xalign == Adorn::XALIGN_LEFT ? rect.x0() + 2.0f : xalign == Adorn::XALIGN_RIGHT ? rect.x1() - 2.0f : rect.center().x;
		adorn->drawFont2D(text, G3D::Vector2(x, rect.center().y), getFontSize(), color, outline, xalign, Adorn::YALIGN_CENTER, Adorn::PROPORTIONAL_SPACING);
	}

	GuiResponse Widget::processMouse(const GuiEvent& event)
	{
		G3D::Vector2 mouse(event.mousePosition.x, event.mousePosition.y);
		bool over = getMyRect2D().contains(mouse);
		switch (event.eventType)
		{
		case UIEvent::MOUSE_MOVE:
			if (widgetState == DOWN_OVER || widgetState == DOWN_AWAY)
			{
				widgetState = over ? DOWN_OVER : DOWN_AWAY;
				onDrag(event);
				return GuiResponse::used(this);
			}
			widgetState = over ? HOVER : NOTHING;
			return over ? GuiResponse::used(this) : GuiResponse::notUsed();
		case UIEvent::MOUSE_LEFT_BUTTON_DOWN:
			if (!over)
				return GuiResponse::notUsed();
			widgetState = DOWN_OVER;
			onDown(event);
			return GuiResponse::used(this);
		case UIEvent::MOUSE_LEFT_BUTTON_UP:
			if (widgetState != DOWN_OVER && widgetState != DOWN_AWAY)
				return GuiResponse::notUsed();
			onUp(event);
			widgetState = over ? HOVER : NOTHING;
			if (over)
				onClick(event);
			return GuiResponse::used();
		default:
			return GuiResponse::notUsed();
		}
	}
}
