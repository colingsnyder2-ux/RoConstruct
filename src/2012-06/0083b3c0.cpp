// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
namespace boost {
namespace detail {
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
};
}
template <class T>
class shared_ptr {
    T* px;
    detail::shared_count pn;
public:
    shared_ptr() : px(0), pn() {}
};
}
struct Target;
struct Owner
{
    char pad[0x10];
    boost::shared_ptr<Target> ptr;
    boost::shared_ptr<Target> get() const;
};
boost::shared_ptr<Target> Owner::get() const
{
    return ptr;
}