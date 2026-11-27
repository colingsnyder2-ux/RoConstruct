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
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
private:
    long use_count_;
    long weak_count_;
};
class weak_count {
    sp_counted_base* pi_;
public:
    weak_count() : pi_(0) {}
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template <class T>
class weak_ptr {
    T* px;
    detail::weak_count pn;
};
}
struct Target;
struct Base
{
    char pad[0xa8];
    ~Base();
};
struct Derived : Base
{
    boost::weak_ptr<Target> ref;
    ~Derived();
};
Derived::~Derived()
{
}