// from server: 100% by EspClaude
// roc 2007-08 00532320  RBX::Notifier<Selection, SelectionChanged>::raise(event, listener); Notifier base at Selection+0xe8, event = 2 shared_ptrs with out-of-line dtor
// roc-flags: /O2 /GS- /EHsc /MD
#include <exception>
#include <string>
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
class shared_count {
    sp_counted_base* pi_;
public:
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
    T* px;
    detail::shared_count pn;
public:
    shared_ptr() : px(0) {}
    ~shared_ptr() {}
    T* get() const { return px; }
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
struct SelectionChanged {
    boost::shared_ptr<Instance> addedItem;
    boost::shared_ptr<Instance> removedItem;
    ~SelectionChanged();
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
class SelectionPad { public: virtual ~SelectionPad(); char pad[0xe8 - 4]; };
class Selection : public SelectionPad, public Notifier<Selection, SelectionChanged> {};
template class Notifier<Selection, SelectionChanged>;
}
