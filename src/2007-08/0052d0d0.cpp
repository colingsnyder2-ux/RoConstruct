// from server: 100% by EspClaude
// roc 2007-08 0052d0d0  RBX::Notifier<Source, Event>::raise(event, listener) (util/Events.h); Notifier base at Source+0x118, trivially-copyable event
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
struct Ev { int a; int b; };
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
class SrcPad { public: virtual ~SrcPad(); char pad[0x118 - 4]; };
class Src : public SrcPad, public Notifier<Src, Ev> {};
template class Notifier<Src, Ev>;
}
