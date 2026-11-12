// from server: 92% by EspClaude
// from server: 50% by colin
// roc 2007-08 004945c0  unit: RBX::Network::VClient::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004945c0
//
// 004945c0  55                   push ebp
// 004945c1  8bec                 mov ebp, esp
// 004945c3  6aff                 push -1
// 004945c5  6860807400           push 0x748060
// 004945ca  64a100000000         mov eax, dword ptr fs:[0]
// 004945d0  50                   push eax
// 004945d1  51                   push ecx
// 004945d2  53                   push ebx
// 004945d3  56                   push esi
// 004945d4  57                   push edi
// 004945d5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004945da  33c5                 xor eax, ebp
// 004945dc  50                   push eax
// 004945dd  8d45f4               lea eax, [ebp - 0xc]
// 004945e0  64a300000000         mov dword ptr fs:[0], eax
// 004945e6  8965f0               mov dword ptr [ebp - 0x10], esp
// 004945e9  8bf1                 mov esi, ecx
// 004945eb  6a14                 push 0x14
// 004945ed  c70600000000         mov dword ptr [esi], 0
// 004945f3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004945fa  e8f7b81900           call 0x62fef6
// 004945ff  83c404               add esp, 4
// 00494602  85c0                 test eax, eax
// 00494604  7419                 je 0x49461f
// 00494606  b901000000           mov ecx, 1
// 0049460b  894804               mov dword ptr [eax + 4], ecx
// 0049460e  894808               mov dword ptr [eax + 8], ecx
// 00494611  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00494614  c700d8b97900         mov dword ptr [eax], 0x79b9d8
// 0049461a  89480c               mov dword ptr [eax + 0xc], ecx
// 0049461d  eb02                 jmp 0x494621
// 0049461f  33c0                 xor eax, eax
// 00494621  8906                 mov dword ptr [esi], eax
// 00494623  8bc6                 mov eax, esi
// 00494625  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00494628  64890d00000000       mov dword ptr fs:[0], ecx
// 0049462f  59                   pop ecx
// 00494630  5f                   pop edi
// 00494631  5e                   pop esi
// 00494632  5b                   pop ebx
// 00494633  8be5                 mov esp, ebp
// 00494635  5d                   pop ebp
// 00494636  c20800               ret 8

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

namespace RBX { namespace Network { class VClient { public: virtual ~VClient(); }; } }
struct Deleter { void operator()(RBX::Network::VClient* p) const; };
template boost::detail::shared_count::shared_count(RBX::Network::VClient*, Deleter);
