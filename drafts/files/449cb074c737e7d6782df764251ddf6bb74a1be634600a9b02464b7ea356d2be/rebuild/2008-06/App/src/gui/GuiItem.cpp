#include "gui/Gui.h"
namespace RBX {
GuiItem::GuiItem() : guiSize(0, 0) { setName("Unnamed GuiItem"); }

// 00573310: the item's rectangle is its position plus its size.
Rect GuiItem::getMyRect() const
{
    G3D::Vector2 position = getPosition();
    G3D::Vector2 size = getSize();
    return Rect(position, position + size);
}

// 005732f0: the parent gui item, or NULL when the parent is not a GuiItem.
const GuiItem* GuiItem::getGuiParent() const
{
    return dynamic_cast<const GuiItem*>(getParent());
}

// 00573ac0: the index-th child gui item, or NULL when the child is not a GuiItem.
GuiItem* GuiItem::getGuiItem(int index)
{
    return dynamic_cast<GuiItem*>(getChild(index));
}
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