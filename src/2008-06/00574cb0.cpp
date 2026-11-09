// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
namespace RBX {
class GuiTarget;
class GuiEvent { public: enum EventType { NO_EVENT, A, B, MOUSE_LEFT_BUTTON_DOWN, MOUSE_LEFT_BUTTON_UP, MOUSE_MOVE }; EventType eventType; };
class GuiResponse {
public:
	enum ResponseType { NOT_USED, USED, USED_AND_FINISHED };
	ResponseType response;
	GuiTarget* target;
	GuiResponse(ResponseType response) : response(response), target(0) {}
	friend class UnifiedWidget;
	GuiResponse(ResponseType r, GuiTarget* t) : response(r), target(t) {}
public:
	bool wasNotUsed() { return response == NOT_USED; }
	bool wasFinished() { return response == USED_AND_FINISHED; }
	static GuiResponse used() { return GuiResponse(USED); }
	static GuiResponse notUsed() { return GuiResponse(NOT_USED); }
};
class Instance { public: virtual ~Instance(); virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15(); char pad[0x12c]; };
class GuiTarget { public: virtual GuiResponse process(const GuiEvent& event) = 0; };
class GuiItem;
template<class T> class shared_ptr { public: T* px; void* pn; T* get() const { return px; } operator bool() const { return px != 0; } T* operator->() const { return px; } void reset(); };
class GuiItem : public Instance, public GuiTarget
{
	shared_ptr<GuiItem> focus;
	float guiSize[2];
protected:
	GuiItem* getFocus() { return focus.get(); }
	__forceinline void loseFocus() { if (focus) focus->onLoseFocus(); focus.reset(); }
	virtual void onLoseFocus() { return; }
public:
	virtual GuiResponse process(const GuiEvent& event);
	virtual void g17();
	virtual void g18();
	virtual void g19();
	virtual void g20();
	virtual void g21();
	virtual void g22();
	virtual void g23();
	virtual void g24();
};
class UnifiedWidget : public GuiItem
{
public:
	enum MenuState { NOTHING, HOVER, SHOWN_APPEARING, SHOWN };
private:
	MenuState menuState;
	GuiResponse processShown_OutOfTitle(const GuiEvent& event);
protected:
	virtual void onMenuStateChanged() {}
public:
	void setMenuState(MenuState newMenuState);
	void setMenuStateI(MenuState newMenuState) { if (menuState != newMenuState) { menuState = newMenuState; onMenuStateChanged(); } }
};
GuiResponse UnifiedWidget::processShown_OutOfTitle(const GuiEvent& event)
{
	UnifiedWidget* oldFocus = dynamic_cast<UnifiedWidget*>(getFocus());
	if (event.eventType >= GuiEvent::MOUSE_LEFT_BUTTON_DOWN)
	{
		if (event.eventType > GuiEvent::MOUSE_LEFT_BUTTON_UP)
		{
			if (event.eventType == GuiEvent::MOUSE_MOVE)
			{
				MenuState oldFocusMenuState = oldFocus ? oldFocus->menuState : NOTHING;
				GuiResponse response = GuiItem::process(event);
				if (oldFocus)
				{
					if (UnifiedWidget* newFocus = dynamic_cast<UnifiedWidget*>(getFocus()))
					{
						if (newFocus != oldFocus)
							newFocus->setMenuState(oldFocusMenuState);
					}
				}
				return GuiResponse::used();
			}
		}
		else
		{
			GuiResponse response = GuiItem::process(event);
			GuiResponse::ResponseType r = response.response; _ReadWriteBarrier();
			if (r == 0)
			{
				setMenuStateI(NOTHING);
			}
			else if (r == 2)
			{
				loseFocus();
				setMenuStateI(NOTHING);
			}
			return GuiResponse(r, response.target);
		}
	}
	return GuiResponse::notUsed();
}
}
