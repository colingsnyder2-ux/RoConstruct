// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <vector>
#include <algorithm>

namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
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
    sp_counted_base* pi_;
public:
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r)
    {
        sp_counted_base* tmp = r.pi_;
        if (tmp != pi_) {
            if (tmp != 0) tmp->add_ref_copy();
            if (pi_ != 0) pi_->release();
            pi_ = tmp;
        }
        return *this;
    }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    T* operator->() const { return px; }
    T& operator*() const { return *px; }
    T* get() const { return px; }
};
template<class T, class U> inline bool operator==(const shared_ptr<T>& a, const shared_ptr<U>& b) { return a.get() == b.get(); }
}

namespace RBX {
class Instance;
struct AncestorChanged;
template<class Class, class Event> class Listener {
public:
    virtual void onEvent(const Class*, Event) = 0;
};
template<class Class, class Event> class Notifier {
public:
    void addListener(Listener<Class, Event>* listener) const;
    void removeListener(Listener<Class, Event>* listener) const;
};
template<class Class> boost::shared_ptr<Class> shared_from(Class*);
template<class T> class CopyOnWrite {
public:
    const boost::shared_ptr<T>& write();
};
struct AncestorChanged {};

struct SelectionPrefix {
    virtual ~SelectionPrefix();
    char pad[0x14c];
};

class Selection : public SelectionPrefix, public Listener<Instance, AncestorChanged> {
public:
    CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > selection;
    virtual void onEvent(const Instance*, AncestorChanged);
    void raiseAdded(boost::shared_ptr<Instance> instance);
    void raiseRemoved(boost::shared_ptr<Instance> instance);
    void toggleSelection(Instance* instance);
};

void Selection::toggleSelection(Instance* instance)
{
    boost::shared_ptr<Instance> shared = shared_from(instance);
    boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > sel = selection.write();

    std::vector<boost::shared_ptr<Instance> >::iterator found = std::find(sel->begin(), sel->end(), shared);

    if (found == sel->end())
    {
        sel->push_back(shared);
        ((const Notifier<Instance, AncestorChanged>*)((const char*)instance + 0xa4))->addListener(this);
        raiseAdded(shared);
    }
    else
    {
        sel->erase(found);
        ((const Notifier<Instance, AncestorChanged>*)((const char*)instance + 0xa4))->removeListener(this);
        raiseRemoved(shared);
    }
}
}
