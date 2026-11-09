// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use_count_;
    long weak_count_;
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
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* operator->() const { return px; }
};
}
namespace RBX {
class Instance;
class Base0 { public: virtual void v0(); char pad[0x10]; };
class EventSource { public: char pad[4]; };
class Mid { public: char pad[0x84 - 0x18]; };
struct DescendentRemoving {
    boost::shared_ptr<Instance> instance;
    boost::shared_ptr<Instance> parent;
    DescendentRemoving(const boost::shared_ptr<Instance>& i, const boost::shared_ptr<Instance>& p) : instance(i), parent(p) {}
};
template<class Class, class Event> class Notifier {
    char pad[0x4];
    std::vector<void*> listeners;
protected:
    bool hasListeners() const { return listeners.size() > 0; }
    void raise(Event event) throw();
};
template<class Source, class Arg> class Signal {
public:
    void fire(Source* source, Arg arg) throw();
};
boost::shared_ptr<Instance> shared_from(Instance* instance) throw();
class Instance : public Base0, public EventSource, public Mid, public Notifier<Instance, DescendentRemoving> {
public:
    char pad2[0x104 - 0x84 - 0x1c];
    Instance* parent;
    static Signal<EventSource, boost::shared_ptr<Instance> > event_descendentRemoving;
protected:
    virtual void onDescendentRemoving(const boost::shared_ptr<Instance>& instance);
};
void Instance::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
{
    event_descendentRemoving.fire(this, instance);
    if (Notifier<Instance, DescendentRemoving>::hasListeners())
        Notifier<Instance, DescendentRemoving>::raise(DescendentRemoving(instance, shared_from(instance->parent)));
}
}
