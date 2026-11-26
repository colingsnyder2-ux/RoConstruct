// from server: 100% by Xemicl
// roc 2012-06 0078a210  unit: RBX::HeartbeatTask  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0078a210
//
// 0078a210  64a100000000         mov eax, dword ptr fs:[0]
// 0078a216  6aff                 push -1
// 0078a218  68085fad00           push 0xad5f08
// 0078a21d  50                   push eax
// 0078a21e  64892500000000       mov dword ptr fs:[0], esp
// 0078a225  8b01                 mov eax, dword ptr [ecx]
// 0078a227  83ec28               sub esp, 0x28
// 0078a22a  85c0                 test eax, eax
// 0078a22c  7516                 jne 0x78a244
// 0078a22e  8d0c24               lea ecx, [esp]
// 0078a231  e8aa20c8ff           call 0x40c2e0
// 0078a236  50                   push eax
// 0078a237  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0078a23f  e87c52c8ff           call 0x40f4c0
// 0078a244  dd442440             fld qword ptr [esp + 0x40]
// 0078a248  8b4004               mov eax, dword ptr [eax + 4]
// 0078a24b  83ec10               sub esp, 0x10
// 0078a24e  dd5c2408             fstp qword ptr [esp + 8]
// 0078a252  83c108               add ecx, 8
// 0078a255  dd442448             fld qword ptr [esp + 0x48]
// 0078a259  dd1c24               fstp qword ptr [esp]
// 0078a25c  51                   push ecx
// 0078a25d  ffd0                 call eax
// 0078a25f  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0078a263  83c414               add esp, 0x14
// 0078a266  64890d00000000       mov dword ptr fs:[0], ecx
// 0078a26d  83c434               add esp, 0x34
// 0078a270  c21000               ret 0x10
// copied from an identical function in another client (function ??R?$function2@XNN@boost@@QBEXNN@Z)

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