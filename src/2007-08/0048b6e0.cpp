// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 0048b6e0  unit: RBX::VSpawnLocation::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048b6e0
//
// 0048b6e0  55                   push ebp
// 0048b6e1  8bec                 mov ebp, esp
// 0048b6e3  6aff                 push -1
// 0048b6e5  6840727400           push 0x747240
// 0048b6ea  64a100000000         mov eax, dword ptr fs:[0]
// 0048b6f0  50                   push eax
// 0048b6f1  51                   push ecx
// 0048b6f2  53                   push ebx
// 0048b6f3  56                   push esi
// 0048b6f4  57                   push edi
// 0048b6f5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048b6fa  33c5                 xor eax, ebp
// 0048b6fc  50                   push eax
// 0048b6fd  8d45f4               lea eax, [ebp - 0xc]
// 0048b700  64a300000000         mov dword ptr fs:[0], eax
// 0048b706  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048b709  8bf1                 mov esi, ecx
// 0048b70b  6a14                 push 0x14
// 0048b70d  c70600000000         mov dword ptr [esi], 0
// 0048b713  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048b71a  e8d7471a00           call 0x62fef6
// 0048b71f  83c404               add esp, 4
// 0048b722  85c0                 test eax, eax
// 0048b724  7419                 je 0x48b73f
// 0048b726  b901000000           mov ecx, 1
// 0048b72b  894804               mov dword ptr [eax + 4], ecx
// 0048b72e  894808               mov dword ptr [eax + 8], ecx
// 0048b731  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0048b734  c7001cb07900         mov dword ptr [eax], 0x79b01c
// 0048b73a  89480c               mov dword ptr [eax + 0xc], ecx
// 0048b73d  eb02                 jmp 0x48b741
// 0048b73f  33c0                 xor eax, eax
// 0048b741  8906                 mov dword ptr [esi], eax
// 0048b743  8bc6                 mov eax, esi
// 0048b745  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048b748  64890d00000000       mov dword ptr fs:[0], ecx
// 0048b74f  59                   pop ecx
// 0048b750  5f                   pop edi
// 0048b751  5e                   pop esi
// 0048b752  5b                   pop ebx
// 0048b753  8be5                 mov esp, ebp
// 0048b755  5d                   pop ebp
// 0048b756  c20800               ret 8

namespace RBX { class SpawnLocation; }

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
    virtual void* get_deleter(const void* ti) { return 0; }
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

}
}

struct null_deleter { void operator()(void const*) const; };

template boost::detail::shared_count::shared_count(RBX::SpawnLocation*, null_deleter);
