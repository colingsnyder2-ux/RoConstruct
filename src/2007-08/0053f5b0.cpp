// from server: 92% by EspClaude
// roc 2007-08 0053f5b0  RBX::Notifier<Instance, AncestorChanged>::raise(event) throw() (util/Events.h RaiseRange loop, real std::vector listeners @+4, raiseRange @+0x14)
// roc-flags: /O2 /GS- /EHsc /MD
#include <exception>
#include <string>
#include <vector>
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
class Instance;
struct AncestorChanged {
    Instance* child; Instance* oldParent; Instance* newParent;
    AncestorChanged(Instance* child, Instance* oldParent, Instance* newParent) : child(child), oldParent(oldParent), newParent(newParent) {}
};
template<class Source, class Event> class Listener {
public:
    virtual void onEvent(const Source* source, Event event) = 0;
};
struct RaiseRange {
    unsigned int index;
    unsigned int upper;
    RaiseRange* previous;
};
template<class Source, class Event> class Notifier {
public:
    virtual ~Notifier();
protected:
    void raise(Event event, Listener<Source, Event>* listener) const
{
    try {
        listener->onEvent(static_cast<const Source*>(this), event);
    }
    catch (std::exception& error) {
        std::string what(error.what());
        StandardOut::singleton()->print(MESSAGE_WARNING, "Exception caught in onEvent. %s", what.c_str());
    }
}
    __declspec(nothrow) void raise(Event event) const
    {
        RaiseRange range = {0, listeners.size(), raiseRange};
        raiseRange = &range;
        for (; range.index < range.upper; range.index++) {
            raise(event, listeners[range.index]);
        }
        raiseRange = range.previous;
    }
private:
    mutable std::vector<Listener<Source, Event>*> listeners;
    mutable RaiseRange* raiseRange;
};
class InstancePad { public: virtual ~InstancePad(); char pad[0x74 - 4]; };
class Instance : public InstancePad, public Notifier<Instance, AncestorChanged> {};
template class Notifier<Instance, AncestorChanged>;
}
