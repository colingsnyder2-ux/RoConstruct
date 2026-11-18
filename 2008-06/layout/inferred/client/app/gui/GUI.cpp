#include "gui/Gui.h"
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
GuiItem::GuiItem() : guiSize(0, 0) { setName("Unnamed GuiItem"); }
}

void RBX::GuiItem::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
{
    if (instance.get() == focus.get())
        loseFocus();
    Instance::onDescendentRemoving(instance);
}

RBX::GuiResponse RBX::GuiItem::process(const GuiEvent& event)
{
    if ((int)event.eventType >= 1 && event.eventType == UIEvent::MOUSE_IDLE)
        return GuiResponse::notUsed();
    if (focus) {
        if (focus->canLoseFocus()) {
            GuiResponse result = processNonFocus(event);
            if (result.wasUsed())
                return result;
        }
        GuiResponse result = focus->process(event);
        if (result.wasUsed())
            return result;
        loseFocus();
    }
    return processNonFocus(event);
}

const G3D::Color4& RBX::GuiItem::disabledFill() {
    static G3D::Color4 c(0.7f, 0.7f, 0.7f, 0.5f);
    return c;
}

const G3D::Color4& RBX::GuiItem::translucentBackdrop()
{
    static const G3D::Color4 c(0.6f, 0.6f, 0.6f, 0.6f);
    return c;
}

RBX::GuiResponse RBX::GuiItem::processNonFocus(const GuiEvent& event)
{
    for (size_t i = 0; i < numChildren(); ++i) {
        GuiItem* item = dynamic_cast<GuiItem*>(getChild(i));
        if (item && item != focus.get()) {
            GuiResponse response = item->process(event);
            if (response.wasUsed()) {
                loseFocus();
                focus = shared_from(item);
                focus->loseFocus();
                return response;
            }
        }
    }
    return GuiResponse::notUsed();
}
namespace RBX {
GuiItem* GuiItem::getGuiItem(int index)
{
    return dynamic_cast<GuiItem*>(getChild(index));
}
}

namespace RBX {
const GuiItem* GuiItem::getGuiParent() const
{
    return dynamic_cast<const GuiItem*>(getParent());
}
}

namespace RBX {
const G3D::Color4& GuiItem::menuSelect()
{
    static G3D::Color4 c(0.7f, 0.7f, 0.7f, 1.0f);
    return c;
}
}

namespace RBX {
const G3D::Color4& GuiItem::menuEnabledFill()
{
    static G3D::Color4 c(0.3f, 0.3f, 0.3f, 1.0f);
    return c;
}
}

namespace RBX {
const G3D::Color4& GuiItem::menuDisabledFill()
{
    static G3D::Color4 c(0.6f, 0.6f, 0.6f, 1.0f);
    return c;
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
