// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 004997a0  unit: RBX::Network::Client  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004997a0
//
// 004997a0  55                   push ebp
// 004997a1  8bec                 mov ebp, esp
// 004997a3  6aff                 push -1
// 004997a5  68a08a7400           push 0x748aa0
// 004997aa  64a100000000         mov eax, dword ptr fs:[0]
// 004997b0  50                   push eax
// 004997b1  51                   push ecx
// 004997b2  53                   push ebx
// 004997b3  56                   push esi
// 004997b4  57                   push edi
// 004997b5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004997ba  33c5                 xor eax, ebp
// 004997bc  50                   push eax
// 004997bd  8d45f4               lea eax, [ebp - 0xc]
// 004997c0  64a300000000         mov dword ptr fs:[0], eax
// 004997c6  8965f0               mov dword ptr [ebp - 0x10], esp
// 004997c9  8bf1                 mov esi, ecx
// 004997cb  6a14                 push 0x14
// 004997cd  c70600000000         mov dword ptr [esi], 0
// 004997d3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004997da  e817671900           call 0x62fef6
// 004997df  83c404               add esp, 4
// 004997e2  85c0                 test eax, eax
// 004997e4  7419                 je 0x4997ff
// 004997e6  b901000000           mov ecx, 1
// 004997eb  894804               mov dword ptr [eax + 4], ecx
// 004997ee  894808               mov dword ptr [eax + 8], ecx
// 004997f1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004997f4  c7008cc07900         mov dword ptr [eax], 0x79c08c
// 004997fa  89480c               mov dword ptr [eax + 0xc], ecx
// 004997fd  eb02                 jmp 0x499801
// 004997ff  33c0                 xor eax, eax
// 00499801  8906                 mov dword ptr [esi], eax
// 00499803  8bc6                 mov eax, esi
// 00499805  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00499808  64890d00000000       mov dword ptr fs:[0], ecx
// 0049980f  59                   pop ecx
// 00499810  5f                   pop edi
// 00499811  5e                   pop esi
// 00499812  5b                   pop ebx
// 00499813  8be5                 mov esp, ebp
// 00499815  5d                   pop ebp
// 00499816  c20800               ret 8
// roc: boost::detail::shared_count::shared_count(P p, D d) with try { new sp_counted_impl_pd } catch(...) { d(p); throw; }
namespace RBX { namespace Network { class Client; } }
namespace boost {
namespace detail {
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(const void* ti) = 0;
};
template<class P, class D> class sp_counted_impl_pd : public sp_counted_base {
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(const void* ti);
};
class shared_count {
    sp_counted_base* pi_;
public:
    template<class P, class D> shared_count(P p, D d) : pi_(0)
    {
        try {
            pi_ = new sp_counted_impl_pd<P, D>(p, d);
        } catch (...) {
            d(p);
            throw;
        }
    }
};
}
}
struct ClientDeleter { void operator()(RBX::Network::Client* p); };
template boost::detail::shared_count::shared_count(RBX::Network::Client*, ClientDeleter);
