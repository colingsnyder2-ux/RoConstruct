// from server: 100% by EspClaude
// roc 2007-08 00574e90  RBX::Notifier<PartInstance, CanAggregateChanged>::raise(event, listener) (util/Events.h)
// 2007 exe: Notifier<PartInstance,CanAggregateChanged> base at PartInstance+0x158; the 1-byte event is copied with a copy ctor.
// roc-flags: /O2 /GS- /EHsc /MD
#include <exception>
#include <string>
namespace boost {
template<class T> class shared_ptr {
    T* px;
    void* pn;
public:
    ~shared_ptr();
    T* operator->() const { return px; }
};
}
namespace RBX {
enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };
class StandardOut {
public:
    static boost::shared_ptr<StandardOut> singleton();
    void print(MessageType type, const char* format, ...);
};
struct CanAggregateChanged {
    const bool canClump;
    CanAggregateChanged(bool canClump) : canClump(canClump) {}
    CanAggregateChanged(const CanAggregateChanged& other) : canClump(other.canClump) {}
};
template<class Source, class Event> class Listener {
public:
    virtual void onEvent(const Source* source, Event event) = 0;
};
template<class Source, class Event> class Notifier {
public:
    virtual ~Notifier();
    int pad[5];
protected:
    void raise(Event event, Listener<Source, Event>* listener) const;
};
template<class Source, class Event>
void Notifier<Source, Event>::raise(Event event, Listener<Source, Event>* listener) const
{
    try {
        listener->onEvent(static_cast<const Source*>(this), event);
    }
    catch (std::exception& error) {
        std::string what(error.what());
        StandardOut::singleton()->print(MESSAGE_WARNING, "Exception caught in onEvent. %s", what.c_str());
    }
}
class PartPad { public: virtual ~PartPad(); char pad[0x158 - 4]; };
class PartInstance : public PartPad, public Notifier<PartInstance, CanAggregateChanged> {};
template class Notifier<PartInstance, CanAggregateChanged>;
}
