// from server: 92% by EspClaude
// from server: 50% by colin
// roc 2007-08 004aea30  unit: RBX::VSnap::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004aea30
//
// 004aea30  55                   push ebp
// 004aea31  8bec                 mov ebp, esp
// 004aea33  6aff                 push -1
// 004aea35  6850a57400           push 0x74a550
// 004aea3a  64a100000000         mov eax, dword ptr fs:[0]
// 004aea40  50                   push eax
// 004aea41  51                   push ecx
// 004aea42  53                   push ebx
// 004aea43  56                   push esi
// 004aea44  57                   push edi
// 004aea45  a188518b00           mov eax, dword ptr [0x8b5188]
// 004aea4a  33c5                 xor eax, ebp
// 004aea4c  50                   push eax
// 004aea4d  8d45f4               lea eax, [ebp - 0xc]
// 004aea50  64a300000000         mov dword ptr fs:[0], eax
// 004aea56  8965f0               mov dword ptr [ebp - 0x10], esp
// 004aea59  8bf1                 mov esi, ecx
// 004aea5b  6a14                 push 0x14
// 004aea5d  c70600000000         mov dword ptr [esi], 0
// 004aea63  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004aea6a  e887141800           call 0x62fef6
// 004aea6f  83c404               add esp, 4
// 004aea72  85c0                 test eax, eax
// 004aea74  7419                 je 0x4aea8f
// 004aea76  b901000000           mov ecx, 1
// 004aea7b  894804               mov dword ptr [eax + 4], ecx
// 004aea7e  894808               mov dword ptr [eax + 8], ecx
// 004aea81  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004aea84  c70060d87900         mov dword ptr [eax], 0x79d860
// 004aea8a  89480c               mov dword ptr [eax + 0xc], ecx
// 004aea8d  eb02                 jmp 0x4aea91
// 004aea8f  33c0                 xor eax, eax
// 004aea91  8906                 mov dword ptr [esi], eax
// 004aea93  8bc6                 mov eax, esi
// 004aea95  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004aea98  64890d00000000       mov dword ptr fs:[0], ecx
// 004aea9f  59                   pop ecx
// 004aeaa0  5f                   pop edi
// 004aeaa1  5e                   pop esi
// 004aeaa2  5b                   pop ebx
// 004aeaa3  8be5                 mov esp, ebp
// 004aeaa5  5d                   pop ebp
// 004aeaa6  c20800               ret 8

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
