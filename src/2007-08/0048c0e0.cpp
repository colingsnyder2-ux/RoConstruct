// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 0048c0e0  unit: RBX::VBodyColors::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048c0e0
//
// 0048c0e0  55                   push ebp
// 0048c0e1  8bec                 mov ebp, esp
// 0048c0e3  6aff                 push -1
// 0048c0e5  68c0727400           push 0x7472c0
// 0048c0ea  64a100000000         mov eax, dword ptr fs:[0]
// 0048c0f0  50                   push eax
// 0048c0f1  51                   push ecx
// 0048c0f2  53                   push ebx
// 0048c0f3  56                   push esi
// 0048c0f4  57                   push edi
// 0048c0f5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048c0fa  33c5                 xor eax, ebp
// 0048c0fc  50                   push eax
// 0048c0fd  8d45f4               lea eax, [ebp - 0xc]
// 0048c100  64a300000000         mov dword ptr fs:[0], eax
// 0048c106  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048c109  8bf1                 mov esi, ecx
// 0048c10b  6a14                 push 0x14
// 0048c10d  c70600000000         mov dword ptr [esi], 0
// 0048c113  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048c11a  e8d73d1a00           call 0x62fef6
// 0048c11f  83c404               add esp, 4
// 0048c122  85c0                 test eax, eax
// 0048c124  7419                 je 0x48c13f
// 0048c126  b901000000           mov ecx, 1
// 0048c12b  894804               mov dword ptr [eax + 4], ecx
// 0048c12e  894808               mov dword ptr [eax + 8], ecx
// 0048c131  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0048c134  c7008cb07900         mov dword ptr [eax], 0x79b08c
// 0048c13a  89480c               mov dword ptr [eax + 0xc], ecx
// 0048c13d  eb02                 jmp 0x48c141
// 0048c13f  33c0                 xor eax, eax
// 0048c141  8906                 mov dword ptr [esi], eax
// 0048c143  8bc6                 mov eax, esi
// 0048c145  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048c148  64890d00000000       mov dword ptr fs:[0], ecx
// 0048c14f  59                   pop ecx
// 0048c150  5f                   pop edi
// 0048c151  5e                   pop esi
// 0048c152  5b                   pop ebx
// 0048c153  8be5                 mov esp, ebp
// 0048c155  5d                   pop ebp
// 0048c156  c20800               ret 8

// Analog of boost 1.34 detail::shared_count(P p, D d): new sp_counted_impl_pd<P,D>
// (0x14 bytes: vptr, use_count=1, weak_count=1, ptr at +0xc, empty deleter) inside
// try/catch(...) { d(p); throw; }. ret 8 = p + by-value empty deleter.
namespace boost { namespace detail {

class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    sp_counted_base(): use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(int const& ti) = 0;
};

template<class P, class D> class sp_counted_impl_pd: public sp_counted_base {
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d): ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(int const& ti) { return 0; }
};

class shared_count {
    sp_counted_base* pi_;
public:
    template<class P, class D> shared_count(P p, D d): pi_(0)
    {
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
struct Product;
struct Deleter { void operator()(Product* p) const; };
}

template boost::detail::shared_count::shared_count(RBX::Product*, RBX::Deleter);
