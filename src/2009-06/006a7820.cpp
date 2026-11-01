// from server: 100% by EspClaude
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espclaude_2bd888f34b5cf9b9.cpp

// Candidate translation unit (score above; library headers required).
#ifndef GUI_GUI_H
#define GUI_GUI_H

#include "decomp.h"
#include "gui/GuiEvent.h"
#include "gui/Layout.h"
#include "rbxgraphics/Adorn.h"
#include "util/Name.h"
#include "util/Rect.h"
#include "v8tree/Instance.h"

#include <G3D/Color4.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Matrix4.h>
#include <G3D/Rect2D.h>
#include <G3D/Vector2.h>
#include <G3D/Vector2int16.h>

namespace RBX {
class ExeInstance2009 {
public:
	virtual ~ExeInstance2009();
	virtual void setName(const std::string& value);
	virtual bool askAddChild(const Instance* instance) const;
	virtual bool askSetParent(const Instance* instance) const;
	virtual void v04();
	virtual void v05();
	virtual void onDescendentRemoving(const shared_ptr<Instance>& instance);
	virtual void v07();
	virtual void v08();
	virtual void v09();
	virtual void v10();
	virtual void v11();
	virtual void v12();
	virtual void v13();
	virtual void v14();
	virtual void v15();
	virtual void v16();
	const std::string& getName() const;
	char exePad[0x88];
};

// SIZE 0x10c
class GuiItem : public ExeInstance2009, public GuiTarget
{
public:
	GuiItem();

private:
	// FUNCTION: WEBSERVICE 0x100c7460
	virtual bool askAddChild(const Instance* instance) const { return dynamic_cast<const GuiItem*>(instance) != NULL; }

public:

protected:
	virtual void onLoseFocus() {}                 // vtable+0x40
	virtual bool canLoseFocus() { return false; } // vtable+0x44

	// FUNCTION: WEBSERVICE 0x100c7490
	virtual G3D::Vector2 getPosition() const { return getGuiParent()->getChildPosition(this); } // vtable+0x48

	// FUNCTION: WEBSERVICE 0x100c74b0
	virtual G3D::Vector2 getChildPosition(const GuiItem* child) const { return G3D::Vector2::zero(); } // vtable+0x4c

	// FUNCTION: WEBSERVICE 0x100c72b0
	virtual int getFontSize() const { return 14; } // vtable+0x50

	virtual bool isVisible() const { return true; } // vtable+0x54

	// FUNCTION: WEBSERVICE 0x100c72c0
	virtual std::string getTitle() { return getName(); } // vtable+0x58

public:
	// FUNCTION: WEBSERVICE 0x100c75b0
	virtual G3D::Vector2 getSize() const { return guiSize; } // vtable+0x5c

	virtual void render2d(Adorn* adorn) {} // vtable+0x60

	virtual GuiResponse process(const GuiEvent& event);

	void addGuiItem(shared_ptr<GuiItem> item);

	void setGuiSize(const G3D::Vector2& value) { guiSize = value; }
	const G3D::Vector2& getGuiSize() const { return guiSize; }

	const GuiItem* getGuiParent() const;
	GuiItem* getGuiParent();

	const GuiItem* getGuiItem(int index) const;
	GuiItem* getGuiItem(int index);

	static const G3D::Color4& enabledFill();
	static const G3D::Color4& disabledFill();
	static const G3D::Color4& menuEnabledFill();
	static const G3D::Color4& menuDisabledFill();
	static const G3D::Color4& translucentBorder();
	static const G3D::Color4& menuSelect();
	static const G3D::Color4& menuBackground();
	static const G3D::Color4& fontBorder();
	static const G3D::Color4& translucentBackdrop();
	static const G3D::Color4& toolboxColor();

protected:
	GuiItem* getFocus();
	void loseFocus();

	Rect getMyRect() const;

	void label2d(
		Adorn* adorn,
		const std::string& label,
		const G3D::Color4& fill,
		const G3D::Color4& border,
		Adorn::XAlign align
	) const;
	// FUNCTION: WEBSERVICE 0x100d1460
	G3D::Rect2D getMyRect2D() const { return getMyRect().toRect2D(); }

private:
	GuiResponse processNonFocus(const GuiEvent& event);
	void switchFocus(GuiItem* item);

	virtual void onDescendentRemoving(const shared_ptr<Instance>& instance);

	shared_ptr<GuiItem> focus; // 0x0fc
	G3D::Vector2 guiSize;      // 0x104
};
}
#endif
#include "gui/Widget.h"

namespace RBX {

// FUNCTION: WEBSERVICE 0x10116aa0
GuiResponse Widget::processMouse(const GuiEvent& event)
{
	bool inRect = getMyRect().pointInRect(event.mousePosition);

	switch (widgetState) {
	case NOTHING:
	case HOVER:
		if (inRect) {
			if (!isEnabled()) {
				widgetState = NOTHING;

				return GuiResponse::used();
			}

			switch (event.eventType) {
			case UIEvent::MOUSE_LEFT_BUTTON_DOWN:
				widgetState = DOWN_OVER;
				onDown(event);
				break;

			case UIEvent::MOUSE_MOVE:
				widgetState = HOVER;
				break;

			default:
				return GuiResponse::notUsed();
			}

			return GuiResponse::used();
		}
		else {
			widgetState = NOTHING;

			return GuiResponse::notUsed();
		}
		break;

	case DOWN_OVER:
		switch (event.eventType) {
		case UIEvent::MOUSE_LEFT_BUTTON_DOWN:
			return GuiResponse::used();

		case UIEvent::MOUSE_MOVE:
			if (!inRect) {
				widgetState = onDrag(event) ? NOTHING : DOWN_AWAY;
			}

			return GuiResponse::used();

		case UIEvent::MOUSE_LEFT_BUTTON_UP:
			widgetState = NOTHING;
			onUp(event);

			if (inRect) {
				onClick(event);

				return GuiResponse::finished();
			}

			return GuiResponse::notUsed();
		}
		break;

	case DOWN_AWAY:
		switch (event.eventType) {
		case UIEvent::MOUSE_LEFT_BUTTON_DOWN:
			return GuiResponse::used();

		case UIEvent::MOUSE_MOVE:
			widgetState = inRect ? DOWN_OVER : DOWN_AWAY;

			return GuiResponse::used();

		case UIEvent::MOUSE_LEFT_BUTTON_UP:
			widgetState = NOTHING;
			onUp(event);

			if (inRect) {
				onClick(event);

				return GuiResponse::used();
			}

			return GuiResponse::notUsed();
		}
		break;
	}

	return GuiResponse::notUsed();
}

// FUNCTION: WEBSERVICE 0x10116cd0
GuiResponse Widget::process(const GuiEvent& event)
{
	if (isEnabled() && event.isMouseEvent()) {
		return processMouse(event);
	}

	return GuiResponse::notUsed();
}

// FUNCTION: WEBSERVICE 0x10116d40
Widget::Widget() : widgetState(NOTHING)
{
	setGuiSize(G3D::Vector2(100, 24));
}

// FUNCTION: WEBSERVICE 0x10116dd0
void Widget::render2d(Adorn* adorn)
{
	if (!isVisible()) {
		return;
	}

	if (widgetState == HOVER || widgetState == DOWN_AWAY) {
		adorn->rect2d(getMyRect2D(), G3D::Color4(G3D::Color3::gray(), 1));
	}

	else if (widgetState == DOWN_OVER) {
		adorn->rect2d(getMyRect2D(), G3D::Color4(G3D::Color3::yellow(), 1));
	}

	label2d(
		adorn,
		getTitle(),
		isEnabled() ? getFontColor() : disabledFill(),
		G3D::Color4(0.5f, 0.5f, 0.5f, 0.25f),
		Adorn::XALIGN_LEFT
	);
}

} // namespace RBX
