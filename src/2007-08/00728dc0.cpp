// from server: 100% by EspClaude
// roc 2007-08 00728dc0 303 bytes
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// Shape (from target): boost 1.34 function2<bool, A, A>::operator()(A a0, A a1)
// const. [this+0] manager (empty test), [this+4] functor passed by value,
// [this+8] cdecl invoker. Empty -> throw_exception(bad_function_call())
// via ctor 0x413c00 on a 0x28-byte frame temp and noreturn 0x414170.
// A is 12 bytes (sub esp,0xc per copy): two words + shared_count whose
// counted base has use_count at +4, weak_count at +8, dispose at vtable+4,
// destroy at vtable+8.
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;

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
        if (_InterlockedDecrement(&weak_count_) == 0) {
            destroy();
        }
    }
};

struct shared_count {
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_)
    {
        if (pi_ != 0) pi_->add_ref_copy();
    }
    ~shared_count()
    {
        if (pi_ != 0) pi_->release();
    }
};

struct Arg12 {
    void* a;
    void* b;
    shared_count pn;
};

struct bad_function_call {
    bad_function_call();
    ~bad_function_call();
    int w[10];
};

__declspec(noreturn) void __cdecl throw_exception(const bad_function_call& e);

typedef bool (__cdecl *invoker_type)(void* functor, Arg12 a0, Arg12 a1);

struct function2 {
    void* manager;
    void* functor;
    invoker_type invoker;

    bool operator()(Arg12 a0, Arg12 a1) const;
};

bool function2::operator()(Arg12 a0, Arg12 a1) const
{
    if (manager == 0)
        throw_exception(bad_function_call());
    bool result = invoker(functor, a0, a1);
    return result;
}
