// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS- /fp:fast /I{headers}/widget-rect-2008
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
// UnifiedWidget menu handlers of the GUI unit, in source order between onDescendentRemoving 005746a0 and
// processNonFocus 00574980 (openrbx Client/App/gui/GUI.cpp statement shapes); callers: UnifiedWidget::process
// 00574e70 (GuiWidgets2008Chat.cpp: NOTHING -> 00574860, HOVER -> 00574760) and processShown 00574de0
// (pointInRect 00573130 -> 005746e0, else 00574cb0). Rect::pointInRect(Vector2int16) is out of line through the
// widget-rect-2008 profile, as in Widget.cpp.

// INFERRED: unit-local inline definitions (the ScriptFileLoad.cpp getContext pattern). gui/Gui.h declares both out of
// line, but the target handlers inline them: getFocus is the focus (+0x134) pointer read at 00574cbf (no registry
// address: never emitted out of line), and setMenuState (out-of-line copy 005735c0, Inferred_005735c0.cpp) is merged
// into the menuState compare/store at 00574707..00574733 while processShown_OutOfTitle still calls 005735c0 on the
// new focus (00574d3e), as when GUI.cpp defined it ahead of these handlers.
inline GuiItem* GuiItem::getFocus()
{
	return focus.get();
}

// INFERRED: same pattern; getMyRect 00573310 (UnifiedWidgetLayout.cpp) is inlined by the handlers (getPosition slot
// +0x48, getSize slot +0x5c, the x87 adds at 00574e03..00574e32).
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

// 005746e0 (registry placeholder func_005746e0)
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

// 00574760 (registry placeholder func_00574760)
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

// 00574860 (registry placeholder func_00574860)
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
// Pending (batch 42 verify): UnifiedWidgetRecovery_00573570.cpp already defines processShown_OutOfTitle (non-exact
// draft, not assigned here); this GUI-unit variant is also a near miss. Keep one definition: enable this copy and
// retire the other only when this one is proven closer or exact (owner decision).
// 00574cb0 (registry placeholder func_00574cb0): dynamic_cast<UnifiedWidget*>(getFocus()) (RTTI 0092b8d8 ->
// 0094674c), GuiItem::process 00574b10, out-of-line setMenuState 005735c0 on the new focus.
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

// 00574de0 (registry placeholder func_00574de0)
GuiResponse UnifiedWidget::processShown(const GuiEvent& event)
{
	if (getMyRect().pointInRect(event.mousePosition))
		return processShown_InTitle(event);

	return processShown_OutOfTitle(event);
}
}
