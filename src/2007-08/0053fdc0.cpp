// from server: 30% by TrollStein
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/gui/GUI.cpp

// Candidate translation unit (score above; library headers required).
#include "gui/GUI.h"

#include "util/object.h"

#include <G3D/g3dmath.h>
#include <algorithm>
#include <math.h>

namespace RBX {

G3D::Vector2 GuiRoot::canvasSize;
G3D::Matrix4 GuiRoot::oldProjectionMatrix;
G3D::CoordinateFrame GuiRoot::oldCameraWorld;

// FUNCTION: WEBSERVICE 0x100d0fc0
const G3D::Color4& GuiItem::disabledFill()
{
	static G3D::Color4 c(0.7f, 0.7f, 0.7f, 0.5f);
	return c;
}

// FUNCTION: WEBSERVICE 0x100d1000
const G3D::Color4& GuiItem::translucentBackdrop()
{
	static G3D::Color4 c(0.6f, 0.6f, 0.6f, 0.6f);
	return c;
}

// FUNCTION: WEBSERVICE 0x100d1040 FOLDED
GuiItem* GuiItem::getGuiParent()
{
	return dynamic_cast<GuiItem*>(getParent());
}

// FUNCTION: WEBSERVICE 0x100d1040 FOLDED
const GuiItem* GuiItem::getGuiParent() const
{
	return dynamic_cast<const GuiItem*>(getParent());
}

// FUNCTION: WEBSERVICE 0x100d1060
Rect GuiItem::getMyRect() const
{
	Vector2 pos = getPosition();

	return Rect(pos, pos + getSize());
}

// STUB: WEBSERVICE 0x100d10b0
void GuiItem::label2d(
	Adorn* adorn,
	const std::string& label,
	const G3D::Color4& fill,
	const G3D::Color4& border,
	Adorn::XAlign align
) const
{
	if (label.size() == 0) {
		return;
	}

	Rect myRect = getMyRect();

	G3D::Vector2 size = myRect.size();
	G3D::Vector2 pos = myRect.center();

	switch (align) {
	case Adorn::XALIGN_RIGHT:
		pos.x = myRect.high.x - size.x * 0.1f;
		break;

	case Adorn::XALIGN_CENTER:
		break;

	default:
		pos.x = myRect.low.x + size.x * 0.1f;
		break;
	}

	adorn
		->drawFont2D(label, pos, getFontSize(), fill, border, align, Adorn::YALIGN_CENTER, Adorn::PROPORTIONAL_SPACING);
}

// FUNCTION: WEBSERVICE 0x100d1180
void RelativePanel::init(const Layout& layout)
{
	setName("RelativePanel");
	layoutStyle = layout.layoutStyle;
	backdropColor = layout.backdropColor;
	xLocation = layout.xLocation;
	yLocation = layout.yLocation;
	offset = layout.offset;
}

// FUNCTION: WEBSERVICE 0x100d1230
void TopMenuBar::init()
{
	layoutStyle = Layout::HORIZONTAL;
	backdropColor = G3D::Color4::clear();
	visible = true;
}

// FUNCTION: WEBSERVICE 0x100d1270
G3D::Vector2 GuiRoot::toPixelSize(const G3D::Vector2& percent)
{
	G3D::Vector2 pixelSize(0, 0);

	if (canvasSize.y > 0.75f * canvasSize.x) {
		pixelSize = (0.01f * percent) * G3D::Vector2(canvasSize.x, 0.75f * canvasSize.x);
	}
	else {
		pixelSize = (0.01f * percent) * G3D::Vector2(1.33f * canvasSize.y, canvasSize.y);
	}

	return pixelSize;
}

// FUNCTION: WEBSERVICE 0x100d12f0
int GuiRoot::normalizedFontSize(int fontSize)
{
	static G3D::Vector2 percentSize(100.0f, 75.0f);

	return G3D::iRound(floorf(fontSize * toPixelSize(percentSize).x * 0.001f));
}

// FUNCTION: WEBSERVICE 0x100d1360
G3D::Vector2 RelativePanel::getPosition() const
{
	Rect canvas(G3D::Vector2::zero(), GuiRoot::getCanvasSize());
	Rect me(G3D::Vector2::zero(), getSize());

	canvas = canvas.inset(offset);

	return canvas.positionChild(me, xLocation, yLocation).low;
}

// FUNCTION: WEBSERVICE 0x100d14d0
GuiItem::GuiItem() : guiSize(0, 0)
{
	setName("Unnamed GuiItem");
}

// FUNCTION: WEBSERVICE 0x100d15f0
GuiRoot::GuiRoot()
{
	setName("GuiRoot");
}

// FUNCTION: WEBSERVICE 0x100d1700
void GuiRoot::render2d(Adorn* adorn)
{
	setCanvasSize(G3D::Vector2(G3D::Vector2int16(adorn->getWidth(), adorn->getHeight())));

	for (unsigned int i = 0; i < numChildren(); ++i) {
		Instance* instance = (*getChildren())[i].get();
		GuiItem* item = dynamic_cast<GuiItem*>(instance);

		if (item != NULL) {
			item->render2d(adorn);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100d17c0
G3D::Vector2 TopMenuBar::getSize() const
{
	G3D::Vector2 size(0, 0);

	for (unsigned int i = 0; i < numChildren(); ++i) {
		Instance* child = (*getChildren())[i].get();
		GuiItem* item = dynamic_cast<GuiItem*>(child);

		if (item != NULL) {
			G3D::Vector2 childSize = item->getSize();

			switch (layoutStyle) {
			case Layout::HORIZONTAL:
				size.x += childSize.x;
				size.y = std::max(size.y, childSize.y);
				break;
			case Layout::VERTICAL:
				size.x = std::max(size.x, childSize.x);
				size.y += childSize.y;
				break;
			}
		}
	}

	return size;
}

// FUNCTION: WEBSERVICE 0x100d18d0
G3D::Vector2 TopMenuBar::getChildPosition(const GuiItem* child) const
{
	G3D::Vector2 position = getPosition();
	G3D::Vector2 mySize = getSize();

	for (unsigned int i = 0; i < numChildren(); ++i) {
		Instance* instance = (*getChildren())[i].get();
		GuiItem* item = dynamic_cast<GuiItem*>(instance);

		if (item != NULL) {
			G3D::Vector2 myChildSize = item->getSize();

			if (item == child) {
				int other = (layoutStyle + 1) % 2;

				position[other] += (mySize[other] - myChildSize[other]) * 0.5f;

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

// FUNCTION: WEBSERVICE 0x100d19f0
void TopMenuBar::render2d(Adorn* adorn)
{
	if (!isVisible()) {
		return;
	}

	if (backdropColor != G3D::Color4::clear()) {
		adorn->rect2d(getMyRect2D(), backdropColor);
	}

	for (unsigned int i = 0; i < numChildren(); ++i) {
		Instance* instance = (*getChildren())[i].get();
		GuiItem* item = dynamic_cast<GuiItem*>(instance);

		if (item != NULL) {
			item->render2d(adorn);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100d1ae0
void GuiItem::loseFocus()
{
	if (focus != NULL) {
		focus->onLoseFocus();
	}

	focus.reset();
}

// FUNCTION: WEBSERVICE 0x100d1b50
void GuiItem::onDescendentRemoving(const shared_ptr<Instance>& instance)
{
	if (instance.get() == focus.get()) {
		loseFocus();
	}

	Instance::onDescendentRemoving(instance);
}

// STUB: WEBSERVICE 0x100d1b80
GuiResponse GuiItem::processNonFocus(const GuiEvent& event)
{
	for (unsigned int i = 0; i < numChildren(); ++i) {
		Instance* child = (*getChildren())[i].get();
		GuiItem* item = dynamic_cast<GuiItem*>(child);

		if (item != NULL && item != focus.get()) {
			GuiResponse itemResponse = item->process(event);

			if (itemResponse.wasUsed()) {
				loseFocus();
				focus = shared_from(item);
				focus->loseFocus();

				return itemResponse;
			}
		}
	}

	return GuiResponse::notUsed();
}

// FUNCTION: WEBSERVICE 0x100d1cf0
GuiResponse GuiItem::process(const GuiEvent& event)
{
	if (event.isMouseEvent() && event.eventType == UIEvent::MOUSE_IDLE) {
		return GuiResponse::notUsed();
	}

	if (focus != NULL) {
		if (focus->canLoseFocus()) {
			GuiResponse nonFocus = processNonFocus(event);

			if (nonFocus.wasUsed()) {
				return nonFocus;
			}
		}

		GuiResponse focusResponse = focus->process(event);

		if (focusResponse.wasUsed()) {
			return focusResponse;
		}

		loseFocus();
	}

	return processNonFocus(event);
}

// FUNCTION: WEBSERVICE 0x100d1de0
GuiResponse TopMenuBar::process(const GuiEvent& event)
{
	if (isVisible()) {
		GuiResponse childResponse = GuiItem::process(event);

		if (childResponse.wasUsed()) {
			return childResponse;
		}

		if (backdropColor.a > 0 && event.isMouseEvent() && getMyRect().pointInRect(event.mousePosition)) {
			return GuiResponse::used();
		}
	}

	return GuiResponse::notUsed();
}

} // namespace RBX
