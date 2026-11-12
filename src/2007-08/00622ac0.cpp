// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
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
// FUNCTION: ROBLOX 0x0058caf0
const G3D::Color4& GuiItem::disabledFill()
{
	static G3D::Color4 c(0.7f, 0.7f, 0.7f, 0.5f);
	return c;
}

// FUNCTION: ROBLOX 0x0058cb30
const G3D::Color4& GuiItem::menuEnabledFill()
{
	static G3D::Color4 c(0.3f, 0.3f, 0.3f, 1.0f);
	return c;
}

// FUNCTION: ROBLOX 0x0058cb70
const G3D::Color4& GuiItem::menuDisabledFill()
{
	static G3D::Color4 c(0.6f, 0.6f, 0.6f, 1.0f);
	return c;
}

// FUNCTION: ROBLOX 0x0058cbb0
const G3D::Color4& GuiItem::menuSelect()
{
	static G3D::Color4 c(0.7f, 0.7f, 0.7f, 1.0f);
	return c;
}

// FUNCTION: WEBSERVICE 0x100d1000
// FUNCTION: ROBLOX 0x0058cbf0
const G3D::Color4& GuiItem::translucentBackdrop()
{
	static G3D::Color4 c(0.6f, 0.6f, 0.6f, 0.6f);
	return c;
}

// FUNCTION: WEBSERVICE 0x100d1040 FOLDED
// FUNCTION: ROBLOX 0x0058cc50 FOLDED
GuiItem* GuiItem::getGuiParent()
{
	return dynamic_cast<GuiItem*>(getParent());
}

// FUNCTION: WEBSERVICE 0x100d1040 FOLDED
// FUNCTION: ROBLOX 0x0058cc50 FOLDED
const GuiItem* GuiItem::getGuiParent() const
{
	return dynamic_cast<const GuiItem*>(getParent());
}

// FUNCTION: WEBSERVICE 0x100d1060
// FUNCTION: ROBLOX 0x0058cc70
Rect GuiItem::getMyRect() const
{
	Vector2 pos = getPosition();

	return Rect(pos, pos + getSize());
}

// STUB: WEBSERVICE 0x100d10b0
// STUB: ROBLOX 0x0058ccc0
void GuiItem::label2d(
	Adorn* adorn, const std::string& label, const G3D::Color4& fill, const G3D::Color4& border, Adorn::XAlign align
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

	adorn->drawFont2D(
		label, pos, getFontSize(), fill, border, align, Adorn::YALIGN_CENTER, Adorn::PROPORTIONAL_SPACING
	);
}

// FUNCTION: ROBLOX 0x0058cd90
void GuiRoot::render2dItem(Adorn* p_unk0x04, GuiItem* p_unk0x08)
{
	setCanvasSize(G3D::Vector2(G3D::Vector2int16(p_unk0x04->getWidth(), p_unk0x04->getHeight())));
	p_unk0x08->render2d(p_unk0x04);
}

// FUNCTION: WEBSERVICE 0x100d1180
// FUNCTION: ROBLOX 0x0058cde0
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
// FUNCTION: ROBLOX 0x0058ce90
void TopMenuBar::init()
{
	layoutStyle = Layout::HORIZONTAL;
	backdropColor = G3D::Color4::clear();
	visible = true;
}

// FUNCTION: ROBLOX 0x0058ced0
void UnifiedWidget::init()
{
	setGuiSize(G3D::Vector2(140, 24));
	menuState = NOTHING;
}

// FUNCTION: ROBLOX 0x0058cf00
G3D::Vector2 UnifiedWidget::childOffset() const
{
	return G3D::Vector2(0, 28);
}

// FUNCTION: ROBLOX 0x0058cf20
void UnifiedWidget::setMenuState(MenuState p_unk0x04)
{
	if (menuState != p_unk0x04) {
		menuState = p_unk0x04;
		onMenuStateChanged();
	}
}

// FUNCTION: ROBLOX 0x0058cf40
void TextDisplay::init()
{
	setGuiSize(G3D::Vector2(180, 30));
	fontSize = 18;
	fontColor = G3D::Color4(G3D::Color3::purple());
	borderColor = G3D::Color4::clear();
	align = Adorn::XALIGN_LEFT;
}

// FUNCTION: ROBLOX 0x0058cfd0
void TextDisplay::render2d(Adorn* adorn)
{
	label2d(adorn, getLabel(), fontColor, borderColor, align);
}

// FUNCTION: WEBSERVICE 0x100d1270
// FUNCTION: ROBLOX 0x0058d050
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
// FUNCTION: ROBLOX 0x0058d0d0
int GuiRoot::normalizedFontSize(int fontSize)
{
	static G3D::Vector2 percentSize(100.0f, 75.0f);

	return G3D::iRound(floorf(fontSize * toPixelSize(percentSize).x * 0.001f));
}

// FUNCTION: WEBSERVICE 0x100d1360
// FUNCTION: ROBLOX 0x0058d140
G3D::Vector2 RelativePanel::getPosition() const
{
	Rect canvas(G3D::Vector2::zero(), GuiRoot::getCanvasSize());
	Rect me(G3D::Vector2::zero(), getSize());

	canvas = canvas.inset(offset);

	return canvas.positionChild(me, xLocation, yLocation).low;
}

// FUNCTION: ROBLOX 0x0058d240
G3D::Vector2 PercentPanel::getPosition() const
{
	Rect canvas(G3D::Vector2::zero(), GuiRoot::getCanvasSize());
	G3D::Vector2 pixelPosition = GuiRoot::toPixelSize(position);

	return canvas.positionPoint(pixelPosition, xLocation, yLocation);
}

// FUNCTION: WEBSERVICE 0x100d14d0
// FUNCTION: ROBLOX 0x0058d330
GuiItem::GuiItem() : guiSize(0, 0)
{
	setName("Unnamed GuiItem");
}

// FUNCTION: ROBLOX 0x0058d420 FOLDED
const GuiItem* GuiItem::getGuiItem(int p_unk0x04) const
{
	return dynamic_cast<const GuiItem*>((*getChildren())[p_unk0x04].get());
}

// FUNCTION: ROBLOX 0x0058d420 FOLDED
GuiItem* GuiItem::getGuiItem(int p_unk0x04)
{
	return dynamic_cast<GuiItem*>((*getChildren())[p_unk0x04].get());
}

// FUNCTION: WEBSERVICE 0x100d15f0
// FUNCTION: ROBLOX 0x0058d470
GuiRoot::GuiRoot()
{
	setName("GuiRoot");
}

// FUNCTION: WEBSERVICE 0x100d1700
// FUNCTION: ROBLOX 0x0058d560
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

// FUNCTION: ROBLOX 0x0058d620
TopMenuBar::TopMenuBar(const std::string& p_unk0x04, Layout::Style p_unk0x08, bool p_unk0x0c)
{
	init();
	setName(p_unk0x04);
	layoutStyle = p_unk0x08;

	if (p_unk0x0c) {
		backdropColor = translucentBackdrop();
	}
}

// FUNCTION: WEBSERVICE 0x100d17c0
// FUNCTION: ROBLOX 0x0058d790
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
// FUNCTION: ROBLOX 0x0058d8a0
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
// FUNCTION: ROBLOX 0x0058d9c0
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

// FUNCTION: ROBLOX 0x0058dab0
int UnifiedWidget::getFontSize() const
{
	return 10;
}

// FUNCTION: ROBLOX 0x0058dac0
void UnifiedWidget::render2dMe(Adorn* p_unk0x04)
{
	p_unk0x04->rect2d(getMyRect2D(), menuState != NOTHING ? menuSelect() : G3D::Color4(G3D::Color3::white()));
	p_unk0x04->outlineRect2d(getMyRect2D(), 1.0f, G3D::Color4(G3D::Color3::black()));
	label2d(p_unk0x04, getName(), G3D::Color4(G3D::Color3::black()), G3D::Color4::clear(), Adorn::XALIGN_CENTER);
}

// FUNCTION: ROBLOX 0x0058dbd0
void UnifiedWidget::render2dChildren(Adorn* p_unk0x04)
{
	if (showChildren()) {
		for (unsigned int i = 0; i < numChildren(); ++i) {
			GuiItem* item = getGuiItem(i);

			if (item != NULL) {
				item->render2d(p_unk0x04);
			}
		}
	}
}

// FUNCTION: ROBLOX 0x0058dc50
void UnifiedWidget::render2d(Adorn* adorn)
{
	if (isVisible()) {
		render2dMe(adorn);
		render2dChildren(adorn);
	}
}

// FUNCTION: ROBLOX 0x0058dc80
G3D::Vector2 UnifiedWidget::firstChildPosition() const
{
	G3D::Vector2 position = getPosition();
	G3D::Vector2 size = getSize();

	float offset = size.x + 4;
	position.x += offset;

	int step = (int) size.y + 4;
	int rows = ((int) GuiRoot::getCanvasSize().y - 120) / step;
	int row = ((int) position.y - 20) / step;
	int half = (int) numChildren() / 2;
	int lastRow = rows - half;

	row = std::max(half, row);
	row = std::min(lastRow, row);
	position.y = (float) ((row - half) * step + 20);

	return position;
}

// FUNCTION: ROBLOX 0x0058dd60
G3D::Vector2 UnifiedWidget::getChildPosition(const GuiItem* child) const
{
	G3D::Vector2 position = firstChildPosition();

	for (unsigned int i = 0; i < numChildren(); ++i) {
		const GuiItem* item = getGuiItem(i);

		if (item != NULL) {
			if (item == child) {
				return position;
			}

			position += childOffset();
		}
	}

	return position;
}

// FUNCTION: ROBLOX 0x0058de10
TextDisplay::TextDisplay(const std::string& p_unk0x04, const std::string& p_unk0x08)
{
	init();
	setName(p_unk0x04);
	label = p_unk0x08;
}

// FUNCTION: ROBLOX 0x0058dee0
int TextDisplay::getFontSize() const
{
	return fontSize;
}

// FUNCTION: ROBLOX 0x0058def0
std::string TextDisplay::getLabel() const
{
	return label;
}

// FUNCTION: WEBSERVICE 0x100d1ae0
// FUNCTION: ROBLOX 0x0058e010
void GuiItem::loseFocus()
{
	if (focus != NULL) {
		focus->onLoseFocus();
	}

	focus.reset();
}

// FUNCTION: WEBSERVICE 0x100d1b50
// FUNCTION: ROBLOX 0x0058e080
void GuiItem::onDescendentRemoving(const shared_ptr<Instance>& instance)
{
	if (instance.get() == focus.get()) {
		loseFocus();
	}

	Instance::onDescendentRemoving(instance);
}

// FUNCTION: ROBLOX 0x0058e0b0
GuiResponse UnifiedWidget::processShown_InTitle(const GuiEvent& p_unk0x04)
{
	loseFocus();

	if (menuState == SHOWN) {
		if (p_unk0x04.eventType == UIEvent::MOUSE_LEFT_BUTTON_UP) {
			setMenuState(HOVER);
		}
	}
	else if (p_unk0x04.eventType == UIEvent::MOUSE_LEFT_BUTTON_UP) {
		setMenuState(SHOWN);
	}

	return GuiResponse::used();
}

// FUNCTION: ROBLOX 0x0058e110
GuiResponse UnifiedWidget::processHover(const GuiEvent& p_unk0x04)
{
	loseFocus();

	if (getMyRect().pointInRect(p_unk0x04.mousePosition)) {
		switch (p_unk0x04.eventType) {
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

// FUNCTION: ROBLOX 0x0058e200
GuiResponse UnifiedWidget::processNothing(const GuiEvent& p_unk0x04)
{
	loseFocus();

	if (getMyRect().pointInRect(p_unk0x04.mousePosition)) {
		switch (p_unk0x04.eventType) {
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

// FUNCTION: WEBSERVICE 0x100d1b80
// FUNCTION: ROBLOX 0x0058e320
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
// FUNCTION: ROBLOX 0x0058e490
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
// FUNCTION: ROBLOX 0x0058e580
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

// STUB: ROBLOX 0x0058e640
GuiResponse UnifiedWidget::processShown_OutOfTitle(const GuiEvent& p_unk0x04)
{
	UnifiedWidget* oldFocus = dynamic_cast<UnifiedWidget*>(getFocus());

	switch (p_unk0x04.eventType) {
	case UIEvent::MOUSE_LEFT_BUTTON_DOWN:
	case UIEvent::MOUSE_LEFT_BUTTON_UP: {
		GuiResponse response = GuiItem::process(p_unk0x04);

		if (response.wasNotUsed() || response.wasFinished()) {
			if (response.wasFinished()) {
				loseFocus();
			}

			setMenuState(NOTHING);
		}

		return response;
	}
	case UIEvent::MOUSE_MOVE: {
		MenuState state = oldFocus != NULL ? oldFocus->getMenuState() : NOTHING;

		GuiItem::process(p_unk0x04);

		if (oldFocus != NULL) {
			UnifiedWidget* newFocus = dynamic_cast<UnifiedWidget*>(getFocus());

			if (newFocus != NULL && newFocus != oldFocus) {
				newFocus->setMenuState(state);
			}
		}

		return GuiResponse::used();
	}
	}

	return GuiResponse::notUsed();
}

// FUNCTION: ROBLOX 0x0058e750
GuiResponse UnifiedWidget::processShown(const GuiEvent& p_unk0x04)
{
	if (getMyRect().pointInRect(p_unk0x04.mousePosition)) {
		return processShown_InTitle(p_unk0x04);
	}

	return processShown_OutOfTitle(p_unk0x04);
}

// FUNCTION: ROBLOX 0x0058e7e0
GuiResponse UnifiedWidget::process(const GuiEvent& p_unk0x04)
{
	if (isVisible() && p_unk0x04.isMouseEvent()) {
		switch (menuState) {
		case NOTHING:
			return processNothing(p_unk0x04);
		case HOVER:
			return processHover(p_unk0x04);
		case SHOWN_APPEARING:
		case SHOWN:
			return processShown(p_unk0x04);
		}
	}

	return GuiResponse::notUsed();
}

} // namespace RBX
