// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#define NULL 0
namespace RBX {
class IDataState { public: virtual void setDirty(bool) = 0; };
class Verb {
public:
	virtual ~Verb();
	virtual void v1();
	virtual bool isEnabled() const;
	virtual bool isChecked() const;
	virtual void doIt(IDataState*) = 0;
};
class VerbContainer {
public:
	virtual ~VerbContainer();
	Verb* getVerb(std::string name);
	char vcpad[0x24];
};
class GuiResponse {
	enum ResponseType { NOT_USED, USED, USED_AND_FINISHED };
	ResponseType response;
	void* target;
	GuiResponse(ResponseType response) : response(response), target(0) {}
public:
	static GuiResponse notUsed() { return GuiResponse(NOT_USED); }
	static GuiResponse used() { return GuiResponse(USED); }
};
class UIEvent {
public:
	enum EventType { NO_EVENT, MOUSE_RIGHT_BUTTON_DOWN, MOUSE_RIGHT_BUTTON_UP, MOUSE_LEFT_BUTTON_DOWN, MOUSE_LEFT_BUTTON_UP, MOUSE_MOVE, MOUSE_DELTA, MOUSE_IDLE, MOUSE_WHEEL_FORWARD, MOUSE_WHEEL_BACKWARD, KEY_DOWN, KEY_UP };
	EventType eventType;
	void* userInput;
	int key;
	int mod;
};
class GuiEvent : public UIEvent { public: void* iDataState; };
namespace Network { class Player; class Players { public: static Player* findLocalPlayer(const void* context); }; }
class Tool { public: static void dropAll(Network::Player*); };
class Hat { public: static void dropAll(Network::Player*); };
class LocalBackpack { public: bool hotkey(int); void scrollLeft(); void scrollRight(); };
class RunService { public: void setRunState(int); };
class Workspace { public: char pad[0x2ec]; VerbContainer verbs; };
template<class T> class shared_ptr { public: T* px; void* pn; T* operator->() const { return px; } };
class DataModelBase { public: virtual ~DataModelBase(); char pad[0x1c8 - 4]; };
class DataModel : public DataModelBase, public VerbContainer, public IDataState {
public:
	char pad1f4[0x1fc - 0x1f4];
	shared_ptr<LocalBackpack> localBackpack;
	shared_ptr<Workspace> workspace;
	shared_ptr<RunService> runService;
	GuiResponse processAccelerators(const GuiEvent&);
};
}

namespace RBX {
GuiResponse DataModel::processAccelerators(const GuiEvent& event)
{
	Verb* verb = NULL;
	switch (event.eventType)
	{
	case UIEvent::KEY_DOWN:
		if (event.key > '0' && event.key <= '9')
		{
			if (localBackpack->hotkey(event.key - '0'))
				return GuiResponse::used();
		}
		else
		{
			switch (event.key)
			{
			case 27:
				runService->setRunState(2);
				break;
			case 8:
				if (Network::Player* player = Network::Players::findLocalPlayer(this))
					Tool::dropAll(player);
				break;
			case ',':
				verb = workspace->verbs.getVerb("CameraPanLeft");
				break;
			case 'o':
				verb = workspace->verbs.getVerb("CameraZoomOut");
				break;
			case '.':
				verb = workspace->verbs.getVerb("CameraPanRight");
				break;
			case 280:
				verb = workspace->verbs.getVerb("CameraTiltDown");
				break;
			case 281:
				verb = workspace->verbs.getVerb("CameraTiltUp");
				break;
			case '=':
				if (Network::Player* player = Network::Players::findLocalPlayer(this))
					Hat::dropAll(player);
				break;
			case ']':
				localBackpack->scrollRight();
				break;
			case '[':
				localBackpack->scrollLeft();
				break;
			case 282:
				if (event.mod == 0)
					verb = getVerb("Help");
				else
					verb = getVerb("Stats");
				break;
			case 'i':
				verb = workspace->verbs.getVerb("CameraZoomIn");
				break;
			}
		}
		break;
	case UIEvent::MOUSE_WHEEL_FORWARD:
		verb = workspace->verbs.getVerb("CameraZoomIn");
		break;
	case UIEvent::MOUSE_WHEEL_BACKWARD:
		verb = workspace->verbs.getVerb("CameraZoomOut");
		break;
	}
	if (verb && verb->isEnabled())
	{
		verb->doIt(this);
		return GuiResponse::used();
	}
	return GuiResponse::notUsed();
}
}
