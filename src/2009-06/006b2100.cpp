// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
class weak_count {
public:
    sp_counted_base* pi_;
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* operator->() const { return px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};
template<class T> class weak_ptr {
public:
    T* px;
    detail::weak_count pn;
    shared_ptr<T> lock() const;
};
}
namespace RBX {
class Instance {
public:
    void setParent(Instance* parent);
};
class Holder {
public:
    char pad[8];
    std::vector<boost::weak_ptr<Instance> > items;
    bool cleared;
    void clearAll();
};
void Holder::clearAll()
{
    for (size_t i = 0; i < items.size(); ++i) {
        boost::shared_ptr<Instance> p = items[i].lock();
        if (p)
            p->setParent(0);
    }
    cleared = true;
}
}
