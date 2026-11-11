// from server: 98% by EspClaude
// from server: 83% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)

namespace boost {
namespace detail {
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
class shared_count {
    sp_counted_base* pi_;
public:
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};
}
template<class T> class shared_ptr {
    typedef T* shared_ptr::*unspecified_bool_type;
public:
    shared_ptr() : px(0), pn() {}
    shared_ptr& operator=(const shared_ptr& r) { px = r.px; pn = r.pn; return *this; }
    T* get() const { return px; }
    T* operator->() const { return px; }
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
    T* px;
    detail::shared_count pn;
};
}

namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0xbc - 4];
    Instance* parent;
    char pad1[0x228 - 0xc0];
    Instance* getParent() const { return parent; }
    bool isDescendentOf(const Instance* other) const;
    void setParent(Instance* p);
};
class Selection : public Instance {};
template<class T> class Creatable {
public:
    template<class U> static boost::shared_ptr<U> create();
};
class ISelectionOwner {
public:
    virtual Selection* getSelection() = 0;
};
class Workspace : public Instance, public ISelectionOwner {
    char pad2[0x330 - 0x22c];
    boost::shared_ptr<Selection> selection;
public:
    Selection* getSelection();
};
static inline bool validParent(Instance* p, Instance* owner)
{
    return owner == p || (p && p->isDescendentOf(owner));
}
Selection* Workspace::getSelection()
{
    if (!selection || !validParent(selection->getParent(), this)) {
        boost::shared_ptr<Selection> s = Creatable<Instance>::create<Selection>();
        Instance* self = this;
        s->setParent(self);
        selection = s;
    }
    return selection.get();
}
}
