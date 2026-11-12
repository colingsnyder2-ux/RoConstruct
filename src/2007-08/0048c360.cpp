// from server: 92% by EspClaude
// from server: 50% by colin
// roc 2007-08 0048c360  unit: RBX::VSkin::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048c360
//
// 0048c360  55                   push ebp
// 0048c361  8bec                 mov ebp, esp
// 0048c363  6aff                 push -1
// 0048c365  68e0727400           push 0x7472e0
// 0048c36a  64a100000000         mov eax, dword ptr fs:[0]
// 0048c370  50                   push eax
// 0048c371  51                   push ecx
// 0048c372  53                   push ebx
// 0048c373  56                   push esi
// 0048c374  57                   push edi
// 0048c375  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048c37a  33c5                 xor eax, ebp
// 0048c37c  50                   push eax
// 0048c37d  8d45f4               lea eax, [ebp - 0xc]
// 0048c380  64a300000000         mov dword ptr fs:[0], eax
// 0048c386  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048c389  8bf1                 mov esi, ecx
// 0048c38b  6a14                 push 0x14
// 0048c38d  c70600000000         mov dword ptr [esi], 0
// 0048c393  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048c39a  e8573b1a00           call 0x62fef6
// 0048c39f  83c404               add esp, 4
// 0048c3a2  85c0                 test eax, eax
// 0048c3a4  7419                 je 0x48c3bf
// 0048c3a6  b901000000           mov ecx, 1
// 0048c3ab  894804               mov dword ptr [eax + 4], ecx
// 0048c3ae  894808               mov dword ptr [eax + 8], ecx
// 0048c3b1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0048c3b4  c700a8b07900         mov dword ptr [eax], 0x79b0a8
// 0048c3ba  89480c               mov dword ptr [eax + 0xc], ecx
// 0048c3bd  eb02                 jmp 0x48c3c1
// 0048c3bf  33c0                 xor eax, eax
// 0048c3c1  8906                 mov dword ptr [esi], eax
// 0048c3c3  8bc6                 mov eax, esi
// 0048c3c5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048c3c8  64890d00000000       mov dword ptr fs:[0], ecx
// 0048c3cf  59                   pop ecx
// 0048c3d0  5f                   pop edi
// 0048c3d1  5e                   pop esi
// 0048c3d2  5b                   pop ebx
// 0048c3d3  8be5                 mov esp, ebp
// 0048c3d5  5d                   pop ebp
// 0048c3d6  c20800               ret 8

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
