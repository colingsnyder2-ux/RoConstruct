// from server: 100% by Xemicl
// roc 2012-06 00522800  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00522800
//
// 00522800  64a100000000         mov eax, dword ptr fs:[0]
// 00522806  6aff                 push -1
// 00522808  68085fad00           push 0xad5f08
// 0052280d  50                   push eax
// 0052280e  64892500000000       mov dword ptr fs:[0], esp
// 00522815  8b01                 mov eax, dword ptr [ecx]
// 00522817  83ec38               sub esp, 0x38
// 0052281a  85c0                 test eax, eax
// 0052281c  7517                 jne 0x522835
// 0052281e  8d4c2410             lea ecx, [esp + 0x10]
// 00522822  e8b99aeeff           call 0x40c2e0
// 00522827  50                   push eax
// 00522828  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00522830  e88bcceeff           call 0x40f4c0
// 00522835  8b542458             mov edx, dword ptr [esp + 0x58]
// 00522839  52                   push edx
// 0052283a  8b542458             mov edx, dword ptr [esp + 0x58]
// 0052283e  52                   push edx
// 0052283f  8b542458             mov edx, dword ptr [esp + 0x58]
// 00522843  52                   push edx
// 00522844  8b542458             mov edx, dword ptr [esp + 0x58]
// 00522848  52                   push edx
// 00522849  8b5004               mov edx, dword ptr [eax + 4]
// 0052284c  83c108               add ecx, 8
// 0052284f  51                   push ecx
// 00522850  8d4c2414             lea ecx, [esp + 0x14]
// 00522854  51                   push ecx
// 00522855  ffd2                 call edx
// 00522857  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0052285b  8b10                 mov edx, dword ptr [eax]
// 0052285d  8911                 mov dword ptr [ecx], edx
// 0052285f  8b5004               mov edx, dword ptr [eax + 4]
// 00522862  895104               mov dword ptr [ecx + 4], edx
// 00522865  8b5008               mov edx, dword ptr [eax + 8]
// 00522868  8b400c               mov eax, dword ptr [eax + 0xc]
// 0052286b  895108               mov dword ptr [ecx + 8], edx
// 0052286e  89410c               mov dword ptr [ecx + 0xc], eax
// 00522871  8bc1                 mov eax, ecx
// 00522873  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 00522877  83c418               add esp, 0x18
// 0052287a  64890d00000000       mov dword ptr fs:[0], ecx
// 00522881  83c444               add esp, 0x44
// 00522884  c21400               ret 0x14
// copied from an identical function in another client (function ??R?$function4@UR16@@HHHH@boost@@QBE?AUR16@@HHHH@Z)

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
template<class R, class T0, class T1, class T2, class T3>
class function4 {
public:
    struct vtable_type {
        void* manager;
        R (*invoker)(detail::function::function_buffer&, T0, T1, T2, T3);
    };
    vtable_type* vtable;
    mutable detail::function::function_buffer functor;
    bool empty() const { return !vtable; }
    R operator()(T0 a0, T1 a1, T2 a2, T3 a3) const;
};
template<class R, class T0, class T1, class T2, class T3>
R function4<R, T0, T1, T2, T3>::operator()(T0 a0, T1 a1, T2 a2, T3 a3) const
{
    if (this->empty())
        boost::throw_exception(bad_function_call());
    return vtable->invoker(this->functor, a0, a1, a2, a3);
}
}
struct R16 { float x, y, z, w; };
template class boost::function4<R16, int, int, int, int>;