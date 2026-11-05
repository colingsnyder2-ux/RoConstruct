// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class Vector2int16 { public: short x, y; }; }
namespace RBX {
class GuiTarget;
class Rect {
public:
	float lx, ly, hx, hy;
	bool pointInRect(G3D::Vector2int16 point);
};
class UIEvent {
public:
	enum EventType { NO_EVENT, MOUSE_RIGHT_BUTTON_DOWN, MOUSE_RIGHT_BUTTON_UP, MOUSE_LEFT_BUTTON_DOWN, MOUSE_LEFT_BUTTON_UP, MOUSE_MOVE };
	EventType eventType;
	void* userInput;
	G3D::Vector2int16 mousePosition;
	G3D::Vector2int16 mouseDelta;
	G3D::Vector2int16 windowSize;
};
class GuiEvent : public UIEvent { public: void* iDataState; };
class GuiResponse {
	enum ResponseType { NOT_USED, USED, USED_AND_FINISHED };
	ResponseType response;
	GuiTarget* target;
	GuiResponse(ResponseType response) : response(response), target(0) {}
public:
	static GuiResponse notUsed() { return GuiResponse(NOT_USED); }
	static GuiResponse used() { return GuiResponse(USED); }
	static GuiResponse finished() { return GuiResponse(USED_AND_FINISHED); }
};
class Widget {
public:
	enum WidgetState { NOTHING, HOVER, DOWN_OVER, DOWN_AWAY };
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
	virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void onClick(const GuiEvent& event);
	virtual bool onDrag(const GuiEvent& event);
	virtual void onDown(const UIEvent& event);
	virtual void onUp(const UIEvent& event);
	virtual void v29();
	virtual bool isEnabled();
	char pad[0x144 - 4];
	WidgetState widgetState;
	Rect getMyRect() const;
	GuiResponse processMouse(const GuiEvent& event);
};

	GuiResponse Widget::processMouse(const GuiEvent& event)
	{
		bool inWidget = getMyRect().pointInRect(event.mousePosition);

		switch (widgetState)
		{
		case NOTHING:
		case HOVER:
			if (inWidget)
			{
				if (!isEnabled())
				{
					widgetState = NOTHING;
					return GuiResponse::used();
				}

				switch (event.eventType)
				{
				case GuiEvent::MOUSE_LEFT_BUTTON_DOWN:
					widgetState = DOWN_OVER;
					onDown(event);
					return GuiResponse::used();

				case GuiEvent::MOUSE_MOVE:
					widgetState = HOVER;
					return GuiResponse::used();
					
				default:
					return GuiResponse::used();
				}
			}
			else
			{
				widgetState = NOTHING;
				return GuiResponse::notUsed();
			}

		case DOWN_OVER:
			switch (event.eventType)
			{
			case GuiEvent::MOUSE_LEFT_BUTTON_DOWN:
				return GuiResponse::used();

			case GuiEvent::MOUSE_LEFT_BUTTON_UP:
				widgetState = NOTHING;
				onUp(event);

				if (inWidget)
				{
					onClick(event);
					return GuiResponse::finished();
				}
				else
				{
					return GuiResponse::notUsed();
				}

			case GuiEvent::MOUSE_MOVE:
				if (!inWidget)
					widgetState = onDrag(event) ? NOTHING : DOWN_AWAY;

				return GuiResponse::used();
			}
			break;

		case DOWN_AWAY:
			switch (event.eventType)
			{
			case GuiEvent::MOUSE_LEFT_BUTTON_DOWN:
				return GuiResponse::used();

			case GuiEvent::MOUSE_LEFT_BUTTON_UP:
				widgetState = NOTHING;
				onUp(event);

				if (inWidget)
				{
					onClick(event);
					return GuiResponse::used();
				}
				else
				{
					return GuiResponse::notUsed();
				}

			case GuiEvent::MOUSE_MOVE:
				widgetState = inWidget ? DOWN_OVER : DOWN_AWAY;
				return GuiResponse::used();
			}

		}
		return GuiResponse::notUsed();
	}
}
