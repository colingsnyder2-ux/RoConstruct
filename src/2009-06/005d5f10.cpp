// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <stdexcept>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0)
                destroy();
        }
    }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
class bad_function_call : public std::runtime_error {
public:
    bad_function_call();
};
template<class E> __declspec(noreturn) void throw_exception(const E& e);
namespace detail { namespace function {
union function_buffer { void* obj_ptr; double align; char data[16]; };
} }
template<class R, class T0, class T1>
class function2 {
public:
    struct vtable_type {
        void* manager;
        R (*invoker)(detail::function::function_buffer&, T0, T1);
    };
    vtable_type* vtable;
    mutable detail::function::function_buffer functor;
    bool empty() const { return !vtable; }
    R operator()(T0 a0, T1 a1) const;
};
template<class R, class T0, class T1>
R function2<R, T0, T1>::operator()(T0 a0, T1 a1) const
{
    if (this->empty())
        boost::throw_exception(bad_function_call());
    return vtable->invoker(this->functor, a0, a1);
}
}
namespace RBX { class Instance; }
template class boost::function2<void, double, double>;
