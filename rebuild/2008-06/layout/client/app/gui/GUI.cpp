#include "gui/Gui.h"

namespace RBX {
GuiItem::GuiItem() : guiSize(0, 0) { setName("Unnamed GuiItem"); }
}

void RBX::GuiItem::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
{
    if (instance.get() == focus.get())
        loseFocus();
    Instance::onDescendentRemoving(instance);
}

namespace RBX
{

// INFERRED: unit-local inline definitions (the ScriptFileLoad.cpp getContext pattern). gui/Gui.h declares both out of
inline GuiItem* GuiItem::getFocus()
{
	return focus.get();
}

// INFERRED: same pattern; getMyRect 00573310 (UnifiedWidgetLayout.cpp) is inlined by the handlers (getPosition slot
inline Rect GuiItem::getMyRect() const
{
	G3D::Vector2 position = getPosition();
	return Rect(position, position + getSize());
}

inline void UnifiedWidget::setMenuState(MenuState state)
{
	if (menuState != state)
	{
		menuState = state;
		onMenuStateChanged();
	}
}

GuiResponse UnifiedWidget::processShown_InTitle(const GuiEvent& event)
{
	loseFocus();

	if (menuState == SHOWN)
	{
		if (event.eventType == UIEvent::MOUSE_LEFT_BUTTON_UP)
			setMenuState(HOVER);
	}
	else if (event.eventType == UIEvent::MOUSE_LEFT_BUTTON_UP)
	{
		setMenuState(SHOWN);
	}

	return GuiResponse::used();
}

GuiResponse UnifiedWidget::processHover(const GuiEvent& event)
{
	loseFocus();

	if (getMyRect().pointInRect(event.mousePosition))
	{
		switch (event.eventType)
		{
		case UIEvent::MOUSE_LEFT_BUTTON_DOWN:
			setMenuState(SHOWN_APPEARING);
			break;
		case UIEvent::MOUSE_LEFT_BUTTON_UP:
			setMenuState(SHOWN);
			break;
		}

		return GuiResponse::used();
	}

	setMenuState(NOTHING);
	return GuiResponse::notUsed();
}

GuiResponse UnifiedWidget::processNothing(const GuiEvent& event)
{
	loseFocus();

	if (getMyRect().pointInRect(event.mousePosition))
	{
		switch (event.eventType)
		{
		case UIEvent::MOUSE_LEFT_BUTTON_DOWN:
		case UIEvent::MOUSE_LEFT_BUTTON_UP:
			setMenuState(SHOWN_APPEARING);
			return GuiResponse::used();
		case UIEvent::MOUSE_MOVE:
			setMenuState(HOVER);
			return GuiResponse::used();
		}

		return GuiResponse::notUsed();
	}

	setMenuState(NOTHING);
	return GuiResponse::notUsed();
}
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

namespace RBX
{
#ifdef UNIFIEDWIDGET_OUTOFTITLE_IN_GUI_UNIT
GuiResponse UnifiedWidget::processShown_OutOfTitle(const GuiEvent& event)
{
	UnifiedWidget* oldFocus = dynamic_cast<UnifiedWidget*>(getFocus());

	switch (event.eventType)
	{
	case UIEvent::MOUSE_LEFT_BUTTON_DOWN:
	case UIEvent::MOUSE_LEFT_BUTTON_UP:
		{
			GuiResponse response = GuiItem::process(event);

			if (response.wasNotUsed() || response.wasFinished())
			{
				if (response.wasFinished())
					loseFocus();

				setMenuState(NOTHING);
			}

			return response;
		}
	case UIEvent::MOUSE_MOVE:
		{
			MenuState state = oldFocus != NULL ? oldFocus->getMenuState() : NOTHING;

			GuiItem::process(event);

			if (oldFocus != NULL)
			{
				UnifiedWidget* newFocus = dynamic_cast<UnifiedWidget*>(getFocus());

				if (newFocus != NULL && newFocus != oldFocus)
					newFocus->setMenuState(state);
			}

			return GuiResponse::used();
		}
	}

	return GuiResponse::notUsed();
}
#endif

GuiResponse UnifiedWidget::processShown(const GuiEvent& event)
{
	if (getMyRect().pointInRect(event.mousePosition))
		return processShown_InTitle(event);

	return processShown_OutOfTitle(event);
}
}

namespace RBX
{
	void RelativePanel::init(const Layout& layout)
	{
		setName("RelativePanel");
		layoutStyle = layout.layoutStyle;
		backdropColor = layout.backdropColor;
		xLocation = layout.xLocation;
		yLocation = layout.yLocation;
		offset = layout.offset;
	}

	G3D::Vector2 RelativePanel::getPosition() const
	{
		Rect canvas(GuiRoot::getCanvasSize());
		Rect me(getSize());
		canvas = canvas.inset(offset);
		return canvas.positionChild(me, xLocation, yLocation).low;
	}

	G3D::Vector2 PercentPanel::getPosition() const
	{
		Rect canvas(GuiRoot::getCanvasSize());
		G3D::Vector2 pixelPosition = GuiRoot::toPixelSize(position);
		return canvas.positionPoint(pixelPosition, xLocation, yLocation);
	}
}

namespace RBX {
PercentPanel::PercentPanel(Rect::Location xLoc, Rect::Location yLoc, const G3D::Vector2 pos)
	: TopMenuBar(), xLocation(xLoc), yLocation(yLoc), position(pos)
{
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
GuiRoot::GuiRoot()
		: GuiItem()
	{
		setName("GuiRoot");
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
