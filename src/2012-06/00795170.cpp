// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
namespace boost {
namespace detail {
struct dynamic_cast_tag {};
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0) destroy();
        }
    }
private:
    long use_count_;
    long weak_count_;
};
class shared_count {
    sp_counted_base* pi_;
public:
    shared_count() : pi_(0) {}
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(shared_count const& r)
    {
        sp_counted_base* tmp = r.pi_;
        if (tmp != pi_)
        {
            if (tmp != 0) tmp->add_ref_copy();
            if (pi_ != 0) pi_->release();
            pi_ = tmp;
        }
        return *this;
    }
};
}
template <class T>
class shared_ptr {
    template <class Y> friend class shared_ptr;
    T* px;
    detail::shared_count pn;
public:
    shared_ptr() : px(0), pn() {}
    template <class Y>
    shared_ptr(shared_ptr<Y> const& r, detail::dynamic_cast_tag) : px(dynamic_cast<T*>(r.px)), pn(r.pn)
    {
        if (px == 0)
        {
            pn = detail::shared_count();
        }
    }
};
}
namespace RBX {
namespace Reflection {
class DescribedBase {
public:
    virtual ~DescribedBase();
};
}
class PartInstance : public Reflection::DescribedBase {
public:
    virtual ~PartInstance();
};
}
template boost::shared_ptr<RBX::PartInstance>::shared_ptr(boost::shared_ptr<RBX::Reflection::DescribedBase> const&, boost::detail::dynamic_cast_tag);
