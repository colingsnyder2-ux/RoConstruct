// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
namespace G3D {
class Vector2 { public: float x, y; };
class Vector2int16 {
public:
    short x, y;
    Vector2int16() : x(0), y(0) {}
    Vector2int16(short _x, short _y) : x(_x), y(_y) {}
    Vector2int16(const class Vector2& v);
};
}
namespace RBX {
class UserInputBase;
class UIEvent {
public:
    enum EventType { NO_EVENT, MOUSE_RIGHT_BUTTON_DOWN, MOUSE_RIGHT_BUTTON_UP, MOUSE_LEFT_BUTTON_DOWN, MOUSE_LEFT_BUTTON_UP, MOUSE_MOVE };
    EventType eventType;
    UserInputBase* userInput;
    G3D::Vector2int16 mousePosition;
    G3D::Vector2int16 mouseDelta;
    G3D::Vector2int16 windowSize;
    UIEvent(UserInputBase* u, EventType t, G3D::Vector2int16 mp, G3D::Vector2int16 ws) : userInput(u), eventType(t), mousePosition(mp), windowSize(ws) {}
};
class UserInputBase { public: char padding[0x59]; bool leftDown; };
}
using namespace RBX;
struct DxUserInput : public UserInputBase {
    G3D::Vector2int16 getWindowSize();
    void sendEvent(const UIEvent&);
    void f(UIEvent::EventType type, const G3D::Vector2& position);
};
void DxUserInput::f(UIEvent::EventType type, const G3D::Vector2& position)
{
    if (type == UIEvent::MOUSE_LEFT_BUTTON_DOWN)
        leftDown = true;
    else if (type == UIEvent::MOUSE_LEFT_BUTTON_UP)
        leftDown = false;
    G3D::Vector2int16 p(position);
    UIEvent event(this, type, p, getWindowSize());
    sendEvent(event);
}
