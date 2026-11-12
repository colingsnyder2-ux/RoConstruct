// from server: 92% by EspClaude
// from server: 50% by colin
// roc 2007-08 0040e1f0  unit: RBX::VTeam::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040e1f0
//
// 0040e1f0  55                   push ebp
// 0040e1f1  8bec                 mov ebp, esp
// 0040e1f3  6aff                 push -1
// 0040e1f5  68909e7300           push 0x739e90
// 0040e1fa  64a100000000         mov eax, dword ptr fs:[0]
// 0040e200  50                   push eax
// 0040e201  51                   push ecx
// 0040e202  53                   push ebx
// 0040e203  56                   push esi
// 0040e204  57                   push edi
// 0040e205  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040e20a  33c5                 xor eax, ebp
// 0040e20c  50                   push eax
// 0040e20d  8d45f4               lea eax, [ebp - 0xc]
// 0040e210  64a300000000         mov dword ptr fs:[0], eax
// 0040e216  8965f0               mov dword ptr [ebp - 0x10], esp
// 0040e219  8bf1                 mov esi, ecx
// 0040e21b  6a14                 push 0x14
// 0040e21d  c70600000000         mov dword ptr [esi], 0
// 0040e223  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0040e22a  e8c71c2200           call 0x62fef6
// 0040e22f  83c404               add esp, 4
// 0040e232  85c0                 test eax, eax
// 0040e234  7419                 je 0x40e24f
// 0040e236  b901000000           mov ecx, 1
// 0040e23b  894804               mov dword ptr [eax + 4], ecx
// 0040e23e  894808               mov dword ptr [eax + 8], ecx
// 0040e241  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0040e244  c700b0687800         mov dword ptr [eax], 0x7868b0
// 0040e24a  89480c               mov dword ptr [eax + 0xc], ecx
// 0040e24d  eb02                 jmp 0x40e251
// 0040e24f  33c0                 xor eax, eax
// 0040e251  8906                 mov dword ptr [esi], eax
// 0040e253  8bc6                 mov eax, esi
// 0040e255  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0040e258  64890d00000000       mov dword ptr fs:[0], ecx
// 0040e25f  59                   pop ecx
// 0040e260  5f                   pop edi
// 0040e261  5e                   pop esi
// 0040e262  5b                   pop ebx
// 0040e263  8be5                 mov esp, ebp
// 0040e265  5d                   pop ebp
// 0040e266  c20800               ret 8

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
