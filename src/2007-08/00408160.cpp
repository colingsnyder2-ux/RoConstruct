// from server: 92% by EspClaude
// from server: 50% by colin
// roc 2007-08 00408160  unit: RBX::VScript::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00408160
//
// 00408160  55                   push ebp
// 00408161  8bec                 mov ebp, esp
// 00408163  6aff                 push -1
// 00408165  6820967300           push 0x739620
// 0040816a  64a100000000         mov eax, dword ptr fs:[0]
// 00408170  50                   push eax
// 00408171  51                   push ecx
// 00408172  53                   push ebx
// 00408173  56                   push esi
// 00408174  57                   push edi
// 00408175  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040817a  33c5                 xor eax, ebp
// 0040817c  50                   push eax
// 0040817d  8d45f4               lea eax, [ebp - 0xc]
// 00408180  64a300000000         mov dword ptr fs:[0], eax
// 00408186  8965f0               mov dword ptr [ebp - 0x10], esp
// 00408189  8bf1                 mov esi, ecx
// 0040818b  6a14                 push 0x14
// 0040818d  c70600000000         mov dword ptr [esi], 0
// 00408193  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0040819a  e8577d2200           call 0x62fef6
// 0040819f  83c404               add esp, 4
// 004081a2  85c0                 test eax, eax
// 004081a4  7419                 je 0x4081bf
// 004081a6  b901000000           mov ecx, 1
// 004081ab  894804               mov dword ptr [eax + 4], ecx
// 004081ae  894808               mov dword ptr [eax + 8], ecx
// 004081b1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004081b4  c70004517800         mov dword ptr [eax], 0x785104
// 004081ba  89480c               mov dword ptr [eax + 0xc], ecx
// 004081bd  eb02                 jmp 0x4081c1
// 004081bf  33c0                 xor eax, eax
// 004081c1  8906                 mov dword ptr [esi], eax
// 004081c3  8bc6                 mov eax, esi
// 004081c5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004081c8  64890d00000000       mov dword ptr fs:[0], ecx
// 004081cf  59                   pop ecx
// 004081d0  5f                   pop edi
// 004081d1  5e                   pop esi
// 004081d2  5b                   pop ebx
// 004081d3  8be5                 mov esp, ebp
// 004081d5  5d                   pop ebp
// 004081d6  c20800               ret 8

namespace RBX { class VScript; }

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

struct Deleter { void operator()(RBX::VScript*) const; };

struct shared_count {
    sp_counted_base* pi_;
    shared_count(RBX::VScript* p, Deleter d);
};
shared_count::shared_count(RBX::VScript* p, Deleter d) : pi_(0)
{
        try {
            pi_ = new sp_counted_impl_pd<RBX::VScript*, Deleter>(p, d);
        } catch (...) {
            d(p);
            throw;
        }
}
