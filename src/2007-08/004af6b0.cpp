// from server: 92% by EspClaude
// from server: 50% by colin
// roc 2007-08 004af6b0  unit: RBX::VRotateV::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004af6b0
//
// 004af6b0  55                   push ebp
// 004af6b1  8bec                 mov ebp, esp
// 004af6b3  6aff                 push -1
// 004af6b5  68f0a57400           push 0x74a5f0
// 004af6ba  64a100000000         mov eax, dword ptr fs:[0]
// 004af6c0  50                   push eax
// 004af6c1  51                   push ecx
// 004af6c2  53                   push ebx
// 004af6c3  56                   push esi
// 004af6c4  57                   push edi
// 004af6c5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004af6ca  33c5                 xor eax, ebp
// 004af6cc  50                   push eax
// 004af6cd  8d45f4               lea eax, [ebp - 0xc]
// 004af6d0  64a300000000         mov dword ptr fs:[0], eax
// 004af6d6  8965f0               mov dword ptr [ebp - 0x10], esp
// 004af6d9  8bf1                 mov esi, ecx
// 004af6db  6a14                 push 0x14
// 004af6dd  c70600000000         mov dword ptr [esi], 0
// 004af6e3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004af6ea  e807081800           call 0x62fef6
// 004af6ef  83c404               add esp, 4
// 004af6f2  85c0                 test eax, eax
// 004af6f4  7419                 je 0x4af70f
// 004af6f6  b901000000           mov ecx, 1
// 004af6fb  894804               mov dword ptr [eax + 4], ecx
// 004af6fe  894808               mov dword ptr [eax + 8], ecx
// 004af701  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004af704  c700ecd87900         mov dword ptr [eax], 0x79d8ec
// 004af70a  89480c               mov dword ptr [eax + 0xc], ecx
// 004af70d  eb02                 jmp 0x4af711
// 004af70f  33c0                 xor eax, eax
// 004af711  8906                 mov dword ptr [esi], eax
// 004af713  8bc6                 mov eax, esi
// 004af715  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004af718  64890d00000000       mov dword ptr fs:[0], ecx
// 004af71f  59                   pop ecx
// 004af720  5f                   pop edi
// 004af721  5e                   pop esi
// 004af722  5b                   pop ebx
// 004af723  8be5                 mov esp, ebp
// 004af725  5d                   pop ebp
// 004af726  c20800               ret 8

namespace RBX { class VRotateV; }

struct sp_counted_base {
    long use_count_;
    long weak_count_;
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    virtual void* get_deleter(const void* ti) = 0;
};

template<class P, class D> struct sp_counted_impl_pd : sp_counted_base {
    P ptr;
    D del;
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(const void* ti);
};

struct Deleter { void operator()(RBX::VRotateV*) const; };

struct shared_count {
    sp_counted_base* pi_;
    shared_count(RBX::VRotateV* p, Deleter d);
};
shared_count::shared_count(RBX::VRotateV* p, Deleter d) : pi_(0)
{
        try {
            pi_ = new sp_counted_impl_pd<RBX::VRotateV*, Deleter>(p, d);
        } catch (...) {
            d(p);
            throw;
        }
}
