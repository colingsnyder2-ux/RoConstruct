// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 0048c690  unit: RBX::VTimerService::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048c690
// 0048c690  55                   push ebp
// 0048c691  8bec                 mov ebp, esp
// 0048c693  6aff                 push -1
// 0048c695  6800737400           push 0x747300
// 0048c69a  64a100000000         mov eax, dword ptr fs:[0]
// 0048c6a0  50                   push eax
// 0048c6a1  51                   push ecx
// 0048c6a2  53                   push ebx
// 0048c6a3  56                   push esi
// 0048c6a4  57                   push edi
// 0048c6a5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048c6aa  33c5                 xor eax, ebp
// 0048c6ac  50                   push eax
// 0048c6ad  8d45f4               lea eax, [ebp - 0xc]
// 0048c6b0  64a300000000         mov dword ptr fs:[0], eax
// 0048c6b6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048c6b9  8bf1                 mov esi, ecx
// 0048c6bb  6a14                 push 0x14
// 0048c6bd  c70600000000         mov dword ptr [esi], 0
// 0048c6c3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048c6ca  e827381a00           call 0x62fef6
// 0048c6cf  83c404               add esp, 4
// 0048c6d2  85c0                 test eax, eax
// 0048c6d4  7419                 je 0x48c6ef
// 0048c6d6  b901000000           mov ecx, 1
// 0048c6db  894804               mov dword ptr [eax + 4], ecx
// 0048c6de  894808               mov dword ptr [eax + 8], ecx
// 0048c6e1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0048c6e4  c700ccb07900         mov dword ptr [eax], 0x79b0cc
// 0048c6ea  89480c               mov dword ptr [eax + 0xc], ecx
// 0048c6ed  eb02                 jmp 0x48c6f1
// 0048c6ef  33c0                 xor eax, eax
// 0048c6f1  8906                 mov dword ptr [esi], eax
// 0048c6f3  8bc6                 mov eax, esi
// 0048c6f5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048c6f8  64890d00000000       mov dword ptr fs:[0], ecx
// 0048c6ff  59                   pop ecx
// 0048c700  5f                   pop edi
// 0048c701  5e                   pop esi
// 0048c702  5b                   pop ebx
// 0048c703  8be5                 mov esp, ebp
// 0048c705  5d                   pop ebp
// 0048c706  c20800               ret 8

namespace RBX { class TimerService; }

class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(const void*) = 0;
};

template<class P, class D> class sp_counted_impl_pd : public sp_counted_base {
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(const void*) { return 0; }
};

struct Deleter { void operator()(RBX::TimerService*) const; };

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

template shared_count::shared_count(RBX::TimerService*, Deleter);
