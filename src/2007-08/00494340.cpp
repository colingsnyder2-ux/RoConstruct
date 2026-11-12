// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 00494340  unit: RBX::Network::Players  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00494340
//
// 00494340  55                   push ebp
// 00494341  8bec                 mov ebp, esp
// 00494343  6aff                 push -1
// 00494345  6840807400           push 0x748040
// 0049434a  64a100000000         mov eax, dword ptr fs:[0]
// 00494350  50                   push eax
// 00494351  51                   push ecx
// 00494352  53                   push ebx
// 00494353  56                   push esi
// 00494354  57                   push edi
// 00494355  a188518b00           mov eax, dword ptr [0x8b5188]
// 0049435a  33c5                 xor eax, ebp
// 0049435c  50                   push eax
// 0049435d  8d45f4               lea eax, [ebp - 0xc]
// 00494360  64a300000000         mov dword ptr fs:[0], eax
// 00494366  8965f0               mov dword ptr [ebp - 0x10], esp
// 00494369  8bf1                 mov esi, ecx
// 0049436b  6a14                 push 0x14
// 0049436d  c70600000000         mov dword ptr [esi], 0
// 00494373  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0049437a  e877bb1900           call 0x62fef6
// 0049437f  83c404               add esp, 4
// 00494382  85c0                 test eax, eax
// 00494384  7419                 je 0x49439f
// 00494386  b901000000           mov ecx, 1
// 0049438b  894804               mov dword ptr [eax + 4], ecx
// 0049438e  894808               mov dword ptr [eax + 8], ecx
// 00494391  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00494394  c700bcb97900         mov dword ptr [eax], 0x79b9bc
// 0049439a  89480c               mov dword ptr [eax + 0xc], ecx
// 0049439d  eb02                 jmp 0x4943a1
// 0049439f  33c0                 xor eax, eax
// 004943a1  8906                 mov dword ptr [esi], eax
// 004943a3  8bc6                 mov eax, esi
// 004943a5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004943a8  64890d00000000       mov dword ptr fs:[0], ecx
// 004943af  59                   pop ecx
// 004943b0  5f                   pop edi
// 004943b1  5e                   pop esi
// 004943b2  5b                   pop ebx
// 004943b3  8be5                 mov esp, ebp
// 004943b5  5d                   pop ebp
// 004943b6  c20800               ret 8
// roc: boost::detail::shared_count::shared_count(P p, D d) with try { new sp_counted_impl_pd } catch(...) { d(p); throw; }
namespace RBX { namespace Network { class Players; } }
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
struct PlayersDeleter { void operator()(RBX::Network::Players* p); };
template boost::detail::shared_count::shared_count(RBX::Network::Players*, PlayersDeleter);
