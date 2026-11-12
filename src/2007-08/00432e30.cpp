// from server: 92% by EspClaude
// from server: 47% by colin
// roc 2007-08 00432e30  unit: RBX::VAccoutrement::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00432e30
//
// 00432e30  55                   push ebp
// 00432e31  8bec                 mov ebp, esp
// 00432e33  6aff                 push -1
// 00432e35  6890de7300           push 0x73de90
// 00432e3a  64a100000000         mov eax, dword ptr fs:[0]
// 00432e40  50                   push eax
// 00432e41  51                   push ecx
// 00432e42  53                   push ebx
// 00432e43  56                   push esi
// 00432e44  57                   push edi
// 00432e45  a188518b00           mov eax, dword ptr [0x8b5188]
// 00432e4a  33c5                 xor eax, ebp
// 00432e4c  50                   push eax
// 00432e4d  8d45f4               lea eax, [ebp - 0xc]
// 00432e50  64a300000000         mov dword ptr fs:[0], eax
// 00432e56  8965f0               mov dword ptr [ebp - 0x10], esp
// 00432e59  8bf1                 mov esi, ecx
// 00432e5b  6a14                 push 0x14
// 00432e5d  c70600000000         mov dword ptr [esi], 0
// 00432e63  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00432e6a  e887d01f00           call 0x62fef6
// 00432e6f  83c404               add esp, 4
// 00432e72  85c0                 test eax, eax
// 00432e74  7419                 je 0x432e8f
// 00432e76  b901000000           mov ecx, 1
// 00432e7b  894804               mov dword ptr [eax + 4], ecx
// 00432e7e  894808               mov dword ptr [eax + 8], ecx
// 00432e81  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00432e84  c700ccba7800         mov dword ptr [eax], 0x78bacc
// 00432e8a  89480c               mov dword ptr [eax + 0xc], ecx
// 00432e8d  eb02                 jmp 0x432e91
// 00432e8f  33c0                 xor eax, eax
// 00432e91  8906                 mov dword ptr [esi], eax
// 00432e93  8bc6                 mov eax, esi
// 00432e95  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00432e98  64890d00000000       mov dword ptr fs:[0], ecx
// 00432e9f  59                   pop ecx
// 00432ea0  5f                   pop edi
// 00432ea1  5e                   pop esi
// 00432ea2  5b                   pop ebx
// 00432ea3  8be5                 mov esp, ebp
// 00432ea5  5d                   pop ebp
// 00432ea6  c20800               ret 8

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
