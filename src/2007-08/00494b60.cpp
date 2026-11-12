// from server: 92% by EspClaude
// from server: 50% by colin
// roc 2007-08 00494b60  unit: RBX::Network::VServer::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00494b60
//
// 00494b60  55                   push ebp
// 00494b61  8bec                 mov ebp, esp
// 00494b63  6aff                 push -1
// 00494b65  68f0807400           push 0x7480f0
// 00494b6a  64a100000000         mov eax, dword ptr fs:[0]
// 00494b70  50                   push eax
// 00494b71  51                   push ecx
// 00494b72  53                   push ebx
// 00494b73  56                   push esi
// 00494b74  57                   push edi
// 00494b75  a188518b00           mov eax, dword ptr [0x8b5188]
// 00494b7a  33c5                 xor eax, ebp
// 00494b7c  50                   push eax
// 00494b7d  8d45f4               lea eax, [ebp - 0xc]
// 00494b80  64a300000000         mov dword ptr fs:[0], eax
// 00494b86  8965f0               mov dword ptr [ebp - 0x10], esp
// 00494b89  8bf1                 mov esi, ecx
// 00494b8b  6a10                 push 0x10
// 00494b8d  c70600000000         mov dword ptr [esi], 0
// 00494b93  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00494b9a  e857b31900           call 0x62fef6
// 00494b9f  83c404               add esp, 4
// 00494ba2  85c0                 test eax, eax
// 00494ba4  7419                 je 0x494bbf
// 00494ba6  b901000000           mov ecx, 1
// 00494bab  894804               mov dword ptr [eax + 4], ecx
// 00494bae  894808               mov dword ptr [eax + 8], ecx
// 00494bb1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00494bb4  c70008b87900         mov dword ptr [eax], 0x79b808
// 00494bba  89480c               mov dword ptr [eax + 0xc], ecx
// 00494bbd  eb02                 jmp 0x494bc1
// 00494bbf  33c0                 xor eax, eax
// 00494bc1  8906                 mov dword ptr [esi], eax
// 00494bc3  8bc6                 mov eax, esi
// 00494bc5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00494bc8  64890d00000000       mov dword ptr fs:[0], ecx
// 00494bcf  59                   pop ecx
// 00494bd0  5f                   pop edi
// 00494bd1  5e                   pop esi
// 00494bd2  5b                   pop ebx
// 00494bd3  8be5                 mov esp, ebp
// 00494bd5  5d                   pop ebp
// 00494bd6  c20400               ret 4

#include <typeinfo>
namespace boost {
template<class T> inline void checked_delete(T* x) { typedef char type_must_be_complete[sizeof(T) ? 1 : -1]; (void)sizeof(type_must_be_complete); delete x; }
namespace detail {
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    sp_counted_base(): use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(std::type_info const& ti) = 0;
};
template<class X> class sp_counted_impl_p : public sp_counted_base {
    X* px_;
public:
    explicit sp_counted_impl_p(X* px): px_(px) {}
    virtual void dispose() { boost::checked_delete(px_); }
    virtual void* get_deleter(std::type_info const&) { return 0; }
};
template<class P, class D> class sp_counted_impl_pd : public sp_counted_base {
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d): ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(std::type_info const& ti) { return ti == typeid(D) ? &del : 0; }
};
class shared_count {
    sp_counted_base* pi_;
public:
    template<class Y> explicit shared_count(Y* p): pi_(0) {
        try { pi_ = new sp_counted_impl_p<Y>(p); }
        catch (...) { boost::checked_delete(p); throw; }
    }
    template<class P, class D> shared_count(P p, D d): pi_(0) {
        try { pi_ = new sp_counted_impl_pd<P, D>(p, d); }
        catch (...) { d(p); throw; }
    }
};
}}

namespace RBX { namespace Network { class VServer { public: virtual ~VServer(); }; } }
template boost::detail::shared_count::shared_count(RBX::Network::VServer*);
