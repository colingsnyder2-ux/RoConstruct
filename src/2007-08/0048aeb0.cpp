// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 0048aeb0  unit: RBX::VStarterPackService::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048aeb0
// 0048aeb0  55                   push ebp
// 0048aeb1  8bec                 mov ebp, esp
// 0048aeb3  6aff                 push -1
// 0048aeb5  68a0717400           push 0x7471a0
// 0048aeba  64a100000000         mov eax, dword ptr fs:[0]
// 0048aec0  50                   push eax
// 0048aec1  51                   push ecx
// 0048aec2  53                   push ebx
// 0048aec3  56                   push esi
// 0048aec4  57                   push edi
// 0048aec5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048aeca  33c5                 xor eax, ebp
// 0048aecc  50                   push eax
// 0048aecd  8d45f4               lea eax, [ebp - 0xc]
// 0048aed0  64a300000000         mov dword ptr fs:[0], eax
// 0048aed6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048aed9  8bf1                 mov esi, ecx
// 0048aedb  6a14                 push 0x14
// 0048aedd  c70600000000         mov dword ptr [esi], 0
// 0048aee3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048aeea  e807501a00           call 0x62fef6
// 0048aeef  83c404               add esp, 4
// 0048aef2  85c0                 test eax, eax
// 0048aef4  7419                 je 0x48af0f
// 0048aef6  b901000000           mov ecx, 1
// 0048aefb  894804               mov dword ptr [eax + 4], ecx
// 0048aefe  894808               mov dword ptr [eax + 8], ecx
// 0048af01  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0048af04  c700c0af7900         mov dword ptr [eax], 0x79afc0
// 0048af0a  89480c               mov dword ptr [eax + 0xc], ecx
// 0048af0d  eb02                 jmp 0x48af11
// 0048af0f  33c0                 xor eax, eax
// 0048af11  8906                 mov dword ptr [esi], eax
// 0048af13  8bc6                 mov eax, esi
// 0048af15  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048af18  64890d00000000       mov dword ptr fs:[0], ecx
// 0048af1f  59                   pop ecx
// 0048af20  5f                   pop edi
// 0048af21  5e                   pop esi
// 0048af22  5b                   pop ebx
// 0048af23  8be5                 mov esp, ebp
// 0048af25  5d                   pop ebp
// 0048af26  c20800               ret 8

// boost 1.34 shared_count(P p, D d) with an empty deleter: new sp_counted_impl_pd (0x14 bytes)
namespace RBX { class StarterPackService; }

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

struct Deleter { void operator()(RBX::StarterPackService*) const; };

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

template shared_count::shared_count(RBX::StarterPackService*, Deleter);
