// from server: 98% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    long use_count_;
    long weak_count_;
};
class shared_count {
public:
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    sp_counted_base* pi_;
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
namespace detail { namespace function {
union function_buffer { void* obj_ptr; char data[0x14]; };
}}
}
namespace RBX {
class Instance;
class PartInstance;
class Handler;
struct BoundMemFn {
    char pmf[0x10];
    void operator()(Handler* p, boost::shared_ptr<Instance> a1) const;
};
struct BoundCall {
    BoundMemFn f_;
    Handler* p_;
};
void invokeBound(boost::detail::function::function_buffer& buf, boost::shared_ptr<Instance> a0)
{
    BoundCall* f = reinterpret_cast<BoundCall*>(&buf.data);
    f->f_(f->p_, a0);
}
}
