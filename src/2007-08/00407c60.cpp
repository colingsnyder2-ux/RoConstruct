// from server: 92% by EspClaude
// from server: 50% by colin
// roc 2007-08 00407c60  unit: RBX::VSelection::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00407c60
//
// 00407c60  55                   push ebp
// 00407c61  8bec                 mov ebp, esp
// 00407c63  6aff                 push -1
// 00407c65  68e0957300           push 0x7395e0
// 00407c6a  64a100000000         mov eax, dword ptr fs:[0]
// 00407c70  50                   push eax
// 00407c71  51                   push ecx
// 00407c72  53                   push ebx
// 00407c73  56                   push esi
// 00407c74  57                   push edi
// 00407c75  a188518b00           mov eax, dword ptr [0x8b5188]
// 00407c7a  33c5                 xor eax, ebp
// 00407c7c  50                   push eax
// 00407c7d  8d45f4               lea eax, [ebp - 0xc]
// 00407c80  64a300000000         mov dword ptr fs:[0], eax
// 00407c86  8965f0               mov dword ptr [ebp - 0x10], esp
// 00407c89  8bf1                 mov esi, ecx
// 00407c8b  6a14                 push 0x14
// 00407c8d  c70600000000         mov dword ptr [esi], 0
// 00407c93  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00407c9a  e857822200           call 0x62fef6
// 00407c9f  83c404               add esp, 4
// 00407ca2  85c0                 test eax, eax
// 00407ca4  7419                 je 0x407cbf
// 00407ca6  b901000000           mov ecx, 1
// 00407cab  894804               mov dword ptr [eax + 4], ecx
// 00407cae  894808               mov dword ptr [eax + 8], ecx
// 00407cb1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00407cb4  c700cc507800         mov dword ptr [eax], 0x7850cc
// 00407cba  89480c               mov dword ptr [eax + 0xc], ecx
// 00407cbd  eb02                 jmp 0x407cc1
// 00407cbf  33c0                 xor eax, eax
// 00407cc1  8906                 mov dword ptr [esi], eax
// 00407cc3  8bc6                 mov eax, esi
// 00407cc5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00407cc8  64890d00000000       mov dword ptr fs:[0], ecx
// 00407ccf  59                   pop ecx
// 00407cd0  5f                   pop edi
// 00407cd1  5e                   pop esi
// 00407cd2  5b                   pop ebx
// 00407cd3  8be5                 mov esp, ebp
// 00407cd5  5d                   pop ebp
// 00407cd6  c20800               ret 8

#include <typeinfo>

namespace boost { namespace detail {

class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(std::type_info const& ti) = 0;
};

template<class P, class D> class sp_counted_impl_pd : public sp_counted_base {
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(std::type_info const& ti) {
        return ti == typeid(D) ? &del : 0;
    }
};

class shared_count {
    sp_counted_base* pi_;
public:
    template<class P, class D> shared_count(P p, D d) : pi_(0) {
        try {
            pi_ = new sp_counted_impl_pd<P, D>(p, d);
        } catch (...) {
            d(p);
            throw;
        }
    }
};

}}

namespace RBX {
class Instance;
struct Deleter { void operator()(Instance* p); };
}

template boost::detail::shared_count::shared_count(RBX::Instance*, RBX::Deleter);
