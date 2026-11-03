// from server: 100% by EspClaude
// roc 2007-08 005fa200  RBX::Seat::unseatCharacter() (v8datamodel/Seat.cpp; 2007 also clears an occupied flag @+0x2b0)
// roc-flags: /O2 /GS /EHsc /MD
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
    void swap(shared_count& r) { sp_counted_base* t = r.pi_; r.pi_ = pi_; pi_ = t; }
};
}
template<class T> class shared_ptr {
    T* px;
    detail::shared_count pn;
public:
    shared_ptr() : px(0) {}
    T* get() const { return px; }
    T* operator->() const { return px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
    void swap(shared_ptr& o) { T* t = px; px = o.px; o.px = t; pn.swap(o.pn); }
    void reset() { shared_ptr().swap(*this); }
};
}
namespace G3D { class System { public: static double getLocalTime(); }; }
namespace RBX {
class Instance { public: void setParent(Instance* newParent); };
class Weld : public Instance {};
class SeatPad { public: virtual ~SeatPad(); char pad[0x2a8 - 4]; };
class Seat : public SeatPad {
    boost::shared_ptr<Weld> weld;   // +0x2a8
    bool occupied;                  // +0x2b0
    double sleepTime;               // +0x2b8
public:
    void unseatCharacter();
};
void Seat::unseatCharacter()
{
    sleepTime = G3D::System::getLocalTime();
    if (weld) {
        weld->setParent(0);
        weld.reset();
    }
    occupied = false;
}
}
