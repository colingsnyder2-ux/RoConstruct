// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 0048b1e0  unit: RBX::VBackpack::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048b1e0
//
// 0048b1e0  55                   push ebp
// 0048b1e1  8bec                 mov ebp, esp
// 0048b1e3  6aff                 push -1
// 0048b1e5  6800727400           push 0x747200
// 0048b1ea  64a100000000         mov eax, dword ptr fs:[0]
// 0048b1f0  50                   push eax
// 0048b1f1  51                   push ecx
// 0048b1f2  53                   push ebx
// 0048b1f3  56                   push esi
// 0048b1f4  57                   push edi
// 0048b1f5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048b1fa  33c5                 xor eax, ebp
// 0048b1fc  50                   push eax
// 0048b1fd  8d45f4               lea eax, [ebp - 0xc]
// 0048b200  64a300000000         mov dword ptr fs:[0], eax
// 0048b206  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048b209  8bf1                 mov esi, ecx
// 0048b20b  6a14                 push 0x14
// 0048b20d  c70600000000         mov dword ptr [esi], 0
// 0048b213  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048b21a  e8d74c1a00           call 0x62fef6
// 0048b21f  83c404               add esp, 4
// 0048b222  85c0                 test eax, eax
// 0048b224  7419                 je 0x48b23f
// 0048b226  b901000000           mov ecx, 1
// 0048b22b  894804               mov dword ptr [eax + 4], ecx
// 0048b22e  894808               mov dword ptr [eax + 8], ecx
// 0048b231  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0048b234  c700e4af7900         mov dword ptr [eax], 0x79afe4
// 0048b23a  89480c               mov dword ptr [eax + 0xc], ecx
// 0048b23d  eb02                 jmp 0x48b241
// 0048b23f  33c0                 xor eax, eax
// 0048b241  8906                 mov dword ptr [esi], eax
// 0048b243  8bc6                 mov eax, esi
// 0048b245  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048b248  64890d00000000       mov dword ptr fs:[0], ecx
// 0048b24f  59                   pop ecx
// 0048b250  5f                   pop edi
// 0048b251  5e                   pop esi
// 0048b252  5b                   pop ebx
// 0048b253  8be5                 mov esp, ebp
// 0048b255  5d                   pop ebp
// 0048b256  c20800               ret 8

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
