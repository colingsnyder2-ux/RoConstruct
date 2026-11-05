// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); };
template<class Sig> class SignalDesc {
public:
    void fireEvent(DescribedBase* instance) const;
};
template<class Sig> class SignalDesc1 {
public:
    void fireEvent(DescribedBase* instance, std::string arg) const;
};
}
struct UIEvent {
    int eventType;
    int a;
    unsigned char key;
    int b, c;
};
struct Pad14 { virtual ~Pad14(); char p[0x10]; };
extern const Reflection::SignalDesc<void(int)> event_1;
extern const Reflection::SignalDesc<void(int)> event_2;
extern const Reflection::SignalDesc<void(int)> event_3;
extern const Reflection::SignalDesc<void(int)> event_4;
extern const Reflection::SignalDesc<void(int)> event_5;
extern const Reflection::SignalDesc<void(int)> event_7;
extern const Reflection::SignalDesc<void(int)> event_8;
extern const Reflection::SignalDesc<void(int)> event_9;
extern const Reflection::SignalDesc1<void(std::string)> event_key;
class Mouse : public Pad14, public Reflection::DescribedBase {
public:
    void update(const UIEvent& event);
    void onEvent(const UIEvent& event);
};
void Mouse::onEvent(const UIEvent& event)
{
    switch (event.eventType)
    {
    case 5: update(event); event_5.fireEvent(this); break;
    case 7: update(event); event_7.fireEvent(this); break;
    case 3: update(event); event_3.fireEvent(this); break;
    case 4: update(event); event_4.fireEvent(this); break;
    case 1: update(event); event_1.fireEvent(this); break;
    case 2: update(event); event_2.fireEvent(this); break;
    case 8: event_8.fireEvent(this); break;
    case 9: event_9.fireEvent(this); break;
    case 10: event_key.fireEvent(this, std::string(1, event.key)); break;
    }
}
}
