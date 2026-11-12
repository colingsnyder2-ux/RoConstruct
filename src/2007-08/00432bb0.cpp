// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 00432bb0  unit: CMainFrame  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00432bb0
//
// 00432bb0  55                   push ebp
// 00432bb1  8bec                 mov ebp, esp
// 00432bb3  6aff                 push -1
// 00432bb5  6870de7300           push 0x73de70
// 00432bba  64a100000000         mov eax, dword ptr fs:[0]
// 00432bc0  50                   push eax
// 00432bc1  51                   push ecx
// 00432bc2  53                   push ebx
// 00432bc3  56                   push esi
// 00432bc4  57                   push edi
// 00432bc5  a188518b00           mov eax, dword ptr [0x8b5188]
// 00432bca  33c5                 xor eax, ebp
// 00432bcc  50                   push eax
// 00432bcd  8d45f4               lea eax, [ebp - 0xc]
// 00432bd0  64a300000000         mov dword ptr fs:[0], eax
// 00432bd6  8965f0               mov dword ptr [ebp - 0x10], esp
// 00432bd9  8bf1                 mov esi, ecx
// 00432bdb  6a14                 push 0x14
// 00432bdd  c70600000000         mov dword ptr [esi], 0
// 00432be3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00432bea  e807d31f00           call 0x62fef6
// 00432bef  83c404               add esp, 4
// 00432bf2  85c0                 test eax, eax
// 00432bf4  7419                 je 0x432c0f
// 00432bf6  b901000000           mov ecx, 1
// 00432bfb  894804               mov dword ptr [eax + 4], ecx
// 00432bfe  894808               mov dword ptr [eax + 8], ecx
// 00432c01  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00432c04  c700b0ba7800         mov dword ptr [eax], 0x78bab0
// 00432c0a  89480c               mov dword ptr [eax + 0xc], ecx
// 00432c0d  eb02                 jmp 0x432c11
// 00432c0f  33c0                 xor eax, eax
// 00432c11  8906                 mov dword ptr [esi], eax
// 00432c13  8bc6                 mov eax, esi
// 00432c15  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00432c18  64890d00000000       mov dword ptr fs:[0], ecx
// 00432c1f  59                   pop ecx
// 00432c20  5f                   pop edi
// 00432c21  5e                   pop esi
// 00432c22  5b                   pop ebx

#include <typeinfo>
// boost 1.34 shared_count(P p, D d) shape: new sp_counted_impl_pd (0x14 bytes) inside try/catch.
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(std::type_info const&) = 0;
};

struct CMainFrame;
// catch funclet (0x432c29): push [ebp+8]; lea ecx,[ebp+0xc]; call 0x4074c0 => out-of-line thiscall D::operator()(P)
struct null_deleter { void operator()(CMainFrame*) const; };

template<class P, class D> class sp_counted_impl_pd : public sp_counted_base {
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(std::type_info const&) { return &del; }
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

template shared_count::shared_count(CMainFrame*, null_deleter);
