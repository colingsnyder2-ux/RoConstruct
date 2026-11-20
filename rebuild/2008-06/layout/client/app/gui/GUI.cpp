#include "gui/Gui.h"

namespace RBX
{
	const G3D::Color4& GuiItem::menuSelect()
	{
		static G3D::Color4 c(0.7f, 0.7f, 0.7f, 1.0f);
		return c;
	}

	Rect GuiItem::getMyRect() const
	{
		G3D::Vector2 position = getPosition();
		return Rect(position, position + getSize());
	}

	void GuiItem::label2d(Adorn* adorn, const std::string& label, const G3D::Color4& fill, const G3D::Color4& border,
		Adorn::XAlign align) const
	{
		if (label.size() == 0)
			return;

		Rect myRect = getMyRect();

		G3D::Vector2 size = myRect.size();
		G3D::Vector2 pos = myRect.center();

		switch (align)
		{
		case Adorn::XALIGN_RIGHT:
			pos.x = myRect.high.x - size.x * 0.1f;
			break;

		case Adorn::XALIGN_CENTER:
			break;

		default:
			pos.x = myRect.low.x + size.x * 0.1f;
			break;
		}

		adorn->drawFont2D(label, pos, getFontSize(), fill, border, align, Adorn::YALIGN_CENTER, Adorn::PROPORTIONAL_SPACING);
	}

	G3D::Vector2 UnifiedWidget::childOffset() const
	{
		return G3D::Vector2(0.0f, 28.0f);
	}

	void TopMenuBar::render2d(Adorn* adorn)
	{
		if (isVisible())
		{
			if (backdropColor != G3D::Color4::clear())
				adorn->rect2d(getMyRect2D(), backdropColor);

			for (size_t i = 0; i < numChildren(); i++)
			{
				GuiItem* current = dynamic_cast<GuiItem*>(getChild(i));
				if (current)
					current->render2d(adorn);
			}
		}
	}

	void UnifiedWidget::render2dMe(Adorn* adorn)
	{
		adorn->rect2d(getMyRect2D(), menuState != NOTHING ? menuSelect() : G3D::Color4(G3D::Color3::white()));
		adorn->outlineRect2d(getMyRect2D(), 1.0f, G3D::Color3::black());
		label2d(adorn, getName(), G3D::Color3::black(), G3D::Color4::clear(), Adorn::XALIGN_CENTER);
	}

	void UnifiedWidget::render2dChildren(Adorn* adorn)
	{
		if (showChildren())
		{
			for (size_t i = 0; i < numChildren(); ++i)
			{
				GuiItem* item = dynamic_cast<GuiItem*>(getChild(i));
				if (item)
					item->render2d(adorn);
			}
		}
	}

	void UnifiedWidget::render2d(Adorn* adorn)
	{
		if (isVisible())
		{
			render2dMe(adorn);
			render2dChildren(adorn);
		}
	}

	G3D::Vector2 UnifiedWidget::firstChildPosition() const
	{
		G3D::Vector2 position = getPosition();
		G3D::Vector2 size = getSize();
		position.x = (size.x + 4.0f) + position.x;
		int rowHeight = int(size.y) + 4;
		int maxRows = (int(GuiRoot::getCanvasSize().y) - 120) / rowHeight;
		int row = (int(position.y) - 20) / rowHeight;
		int half = int(numChildren()) / 2;
		maxRows -= half;
		row = std::max(half, row);
		row = std::min(maxRows, row);
		position.y = float((row - half) * rowHeight + 20);
		return position;
	}

	G3D::Vector2 UnifiedWidget::getChildPosition(const GuiItem* child) const
	{
		G3D::Vector2 position = firstChildPosition();
		for (size_t i = 0; i < numChildren(); ++i)
		{
			const GuiItem* item = dynamic_cast<const GuiItem*>(getChild(i));
			if (item)
			{
				if (item == child)
					return position;
				position += childOffset();
			}
		}
		return position;
	}

	void UnifiedWidget::onLoseFocus()
	{
		menuState = NOTHING;
	}
}

#include "util/Name.h"

namespace RBX {

void __thiscall UnifiedWidget::setMenuState(UnifiedWidget::MenuState state)
{
	if (menuState != state)
	{
		menuState = state;
		onMenuStateChanged();
	}
}

}

namespace RBX
{
	int TextDisplay::getFontSize() const
	{
		return fontSize;
	}
}

namespace RBX {
std::string TextDisplay::getLabel() const
{
	return label;
}
}

namespace RBX {
void TextDisplay::render2d(Adorn* adorn)
	{
		label2d(adorn, getLabel(), fontColor, borderColor, align);
	}
}

namespace RBX {
__declspec(noinline) void TextDisplay::init()
	{
		setGuiSize(G3D::Vector2(180.0f, 30.0f));
		fontSize = 18;
		fontColor = G3D::Color3::purple();
		borderColor = G3D::Color4::zero();
		align = Adorn::XALIGN_LEFT;
	}
}

namespace RBX {
TextDisplay::TextDisplay(const std::string& name, const std::string& text)
	{
		init();
		setName(name);
		label = text;
	}
}

namespace RBX {
G3D::Vector2 GuiRoot::toPixelSize(const G3D::Vector2& percent)
{
	G3D::Vector2 pixelSize(0, 0);
	if (canvasSize.y > 0.75f * canvasSize.x)
		pixelSize = (0.01f * percent) * G3D::Vector2(canvasSize.x, 0.75f * canvasSize.x);
	else
		pixelSize = (0.01f * percent) * G3D::Vector2(1.33f * canvasSize.y, canvasSize.y);
	return pixelSize;
}
}

#include "gui/GUI.h"
#include "util/object.h"

namespace RBX {
void TopMenuBar::init()
{
	layoutStyle = Layout::HORIZONTAL;
	backdropColor = G3D::Color4::clear();
	visible = true;
}
}

namespace RBX {
G3D::Vector2 TopMenuBar::getSize() const
{
    G3D::Vector2 result(0.0f, 0.0f);
    for (size_t i = 0; i < numChildren(); ++i) {
        const GuiItem* item = dynamic_cast<const GuiItem*>(getChild(i));
        if (item) {
            G3D::Vector2 size = item->getSize();
            switch (layoutStyle) {
            case Layout::HORIZONTAL:
                result.x += size.x;
                result.y = G3D::max(result.y, size.y);
                break;
            case Layout::VERTICAL:
                result.x = G3D::max(result.x, size.x);
                result.y += size.y;
                break;
            }
        }
    }
    return result;
}
}

namespace RBX {
G3D::Vector2 TopMenuBar::getChildPosition(const GuiItem* child) const
{
    G3D::Vector2 position = getPosition();
    G3D::Vector2 size = getSize();
    for (size_t i = 0; i < numChildren(); ++i) {
        const GuiItem* item = dynamic_cast<const GuiItem*>(getChild(i));
        if (item) {
            G3D::Vector2 childSize = item->getSize();
            if (item == child) {
                int crossAxis = (layoutStyle + 1) % 2;
                position[crossAxis] += (size[crossAxis] - childSize[crossAxis]) * 0.5f;
                return position;
            }
            switch (layoutStyle) {
            case Layout::HORIZONTAL:
            case Layout::VERTICAL:
                position[layoutStyle] += item->getSize()[layoutStyle];
                break;
            }
        }
    }
    return position;
}
}

namespace RBX {
GuiResponse TopMenuBar::process(const GuiEvent& event)
{
    if (isVisible()) {
        {
            GuiResponse response = GuiItem::process(event);
            if (response.wasUsed())
                return response;
        }
        if (backdropColor.a > 0.0f && event.eventType >= UIEvent::MOUSE_RIGHT_BUTTON_DOWN
            && event.eventType <= UIEvent::MOUSE_IDLE && getMyRect().pointInRect(event.mousePosition))
            return GuiResponse::used();
    }
    return GuiResponse::notUsed();
}
}
