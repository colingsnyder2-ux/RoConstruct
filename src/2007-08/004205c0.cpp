// from server: 100% by Intel_Inside
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)

class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0) destroy();
        }
    }
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(shared_count const& r)
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

struct dynamic_cast_tag {};

namespace RBX {
class Instance { public: virtual ~Instance(); };
class Script : public Instance { };
}

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    template<class Y> shared_ptr(shared_ptr<Y> const& r, dynamic_cast_tag)
        : px(dynamic_cast<T*>(r.px)), pn(r.pn)
    {
        if (px == 0)
            pn = shared_count();
    }
};

template shared_ptr<RBX::Script>::shared_ptr(shared_ptr<RBX::Instance> const&, dynamic_cast_tag);
