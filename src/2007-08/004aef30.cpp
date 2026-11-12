// from server: 92% by EspClaude
// from server: 50% by colin
// roc 2007-08 004aef30  unit: RBX::VGlue::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004aef30
//
// 004aef30  55                   push ebp
// 004aef31  8bec                 mov ebp, esp
// 004aef33  6aff                 push -1
// 004aef35  6890a57400           push 0x74a590
// 004aef3a  64a100000000         mov eax, dword ptr fs:[0]
// 004aef40  50                   push eax
// 004aef41  51                   push ecx
// 004aef42  53                   push ebx
// 004aef43  56                   push esi
// 004aef44  57                   push edi
// 004aef45  a188518b00           mov eax, dword ptr [0x8b5188]
// 004aef4a  33c5                 xor eax, ebp
// 004aef4c  50                   push eax
// 004aef4d  8d45f4               lea eax, [ebp - 0xc]
// 004aef50  64a300000000         mov dword ptr fs:[0], eax
// 004aef56  8965f0               mov dword ptr [ebp - 0x10], esp
// 004aef59  8bf1                 mov esi, ecx
// 004aef5b  6a14                 push 0x14
// 004aef5d  c70600000000         mov dword ptr [esi], 0
// 004aef63  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004aef6a  e8870f1800           call 0x62fef6
// 004aef6f  83c404               add esp, 4
// 004aef72  85c0                 test eax, eax
// 004aef74  7419                 je 0x4aef8f
// 004aef76  b901000000           mov ecx, 1
// 004aef7b  894804               mov dword ptr [eax + 4], ecx
// 004aef7e  894808               mov dword ptr [eax + 8], ecx
// 004aef81  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004aef84  c70098d87900         mov dword ptr [eax], 0x79d898
// 004aef8a  89480c               mov dword ptr [eax + 0xc], ecx
// 004aef8d  eb02                 jmp 0x4aef91
// 004aef8f  33c0                 xor eax, eax
// 004aef91  8906                 mov dword ptr [esi], eax
// 004aef93  8bc6                 mov eax, esi
// 004aef95  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004aef98  64890d00000000       mov dword ptr fs:[0], ecx
// 004aef9f  59                   pop ecx
// 004aefa0  5f                   pop edi
// 004aefa1  5e                   pop esi
// 004aefa2  5b                   pop ebx
// 004aefa3  8be5                 mov esp, ebp
// 004aefa5  5d                   pop ebp
// 004aefa6  c20800               ret 8

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

namespace RBX { class VGlue { public: virtual ~VGlue(); }; }
struct Deleter { void operator()(RBX::VGlue* p) const; };
template boost::detail::shared_count::shared_count(RBX::VGlue*, Deleter);
