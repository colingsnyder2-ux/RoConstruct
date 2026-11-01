// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <intrin.h>
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* get() const { return px; }
    T* operator->() const { return px; }
};
}
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x50];
    std::string name;
    const std::string& getName() const { return name; }
    void setParent(Instance* parent);
};
class Weld : public Instance {};
template<class Base> class SeatImpl : public Base {
public:
    Weld* isChildSeatWeld(Instance* child) {
        if (child->getName() == "SeatWeld") {
            if (Weld* childWeld = dynamic_cast<Weld*>(child)) return childWeld;
        }
        return 0;
    }
    void destroyOtherWeld(boost::shared_ptr<Instance> child, Weld* childWeld) {
        if ((child.get() != childWeld) && isChildSeatWeld(child.get()))
            child->setParent(0);
    }
};
class PartInstance : public Instance {};
template class SeatImpl<PartInstance>;
}
