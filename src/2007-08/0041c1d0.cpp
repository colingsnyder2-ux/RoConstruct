// from server: 92% by EspClaude
// from server: 42% by colin
// roc 2007-08 0041c1d0  unit: VDHTMLWindow::?$SignalDesc  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041c1d0
// 0041c1d0  55                   push ebp
// 0041c1d1  8bec                 mov ebp, esp
// 0041c1d3  6aff                 push -1
// 0041c1d5  6850b57300           push 0x73b550
// 0041c1da  64a100000000         mov eax, dword ptr fs:[0]
// 0041c1e0  50                   push eax
// 0041c1e1  51                   push ecx
// 0041c1e2  53                   push ebx
// 0041c1e3  56                   push esi
// 0041c1e4  57                   push edi
// 0041c1e5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041c1ea  33c5                 xor eax, ebp
// 0041c1ec  50                   push eax
// 0041c1ed  8d45f4               lea eax, [ebp - 0xc]
// 0041c1f0  64a300000000         mov dword ptr fs:[0], eax
// 0041c1f6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0041c1f9  8bf1                 mov esi, ecx
// 0041c1fb  6a14                 push 0x14
// 0041c1fd  c70600000000         mov dword ptr [esi], 0
// 0041c203  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0041c20a  e8e73c2100           call 0x62fef6
// 0041c20f  83c404               add esp, 4
// 0041c212  85c0                 test eax, eax
// 0041c214  7419                 je 0x41c22f
// 0041c216  b901000000           mov ecx, 1
// 0041c21b  894804               mov dword ptr [eax + 4], ecx
// 0041c21e  894808               mov dword ptr [eax + 8], ecx
// 0041c221  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0041c224  c7007c7a7800         mov dword ptr [eax], 0x787a7c
// 0041c22a  89480c               mov dword ptr [eax + 0xc], ecx
// 0041c22d  eb02                 jmp 0x41c231
// 0041c22f  33c0                 xor eax, eax
// 0041c231  8906                 mov dword ptr [esi], eax
// 0041c233  8bc6                 mov eax, esi
// 0041c235  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0041c238  64890d00000000       mov dword ptr fs:[0], ecx
// 0041c23f  59                   pop ecx
// 0041c240  5f                   pop edi
// 0041c241  5e                   pop esi
// 0041c242  5b                   pop ebx
// 0041c243  8be5                 mov esp, ebp
// 0041c245  5d                   pop ebp
// 0041c246  c20800               ret 8

#include <typeinfo>

namespace RBX { class Instance; }

struct sp_counted_base {
    long use_count_;
    long weak_count_;
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(const std::type_info&) = 0;
};

struct Deleter {
    void operator()(RBX::Instance* p);
};

template<class P, class D>
struct sp_counted_impl_pd : sp_counted_base {
    P ptr;
    D del;
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(const std::type_info& ti) {
        return ti == typeid(D) ? &del : 0;
    }
};

struct shared_count {
    sp_counted_base* pi_;
    template<class P, class D> shared_count(P p, D d);
};

template<class P, class D>
shared_count::shared_count(P p, D d) : pi_(0)
{
    try {
        pi_ = new sp_counted_impl_pd<P, D>(p, d);
    } catch (...) {
        d(p);
        throw;
    }
}

template shared_count::shared_count(RBX::Instance*, Deleter);
