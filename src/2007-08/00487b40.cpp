// from server: 92% by EspClaude
// from server: 50% by colin
// roc 2007-08 00487b40  unit: P8CRenderSettings::?$GetSetImpl  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00487b40
//
// 00487b40  55                   push ebp
// 00487b41  8bec                 mov ebp, esp
// 00487b43  6aff                 push -1
// 00487b45  68306e7400           push 0x746e30
// 00487b4a  64a100000000         mov eax, dword ptr fs:[0]
// 00487b50  50                   push eax
// 00487b51  51                   push ecx
// 00487b52  53                   push ebx
// 00487b53  56                   push esi
// 00487b54  57                   push edi
// 00487b55  a188518b00           mov eax, dword ptr [0x8b5188]
// 00487b5a  33c5                 xor eax, ebp
// 00487b5c  50                   push eax
// 00487b5d  8d45f4               lea eax, [ebp - 0xc]
// 00487b60  64a300000000         mov dword ptr fs:[0], eax
// 00487b66  8965f0               mov dword ptr [ebp - 0x10], esp
// 00487b69  8bf1                 mov esi, ecx
// 00487b6b  6a14                 push 0x14
// 00487b6d  c70600000000         mov dword ptr [esi], 0
// 00487b73  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00487b7a  e877831a00           call 0x62fef6
// 00487b7f  83c404               add esp, 4
// 00487b82  85c0                 test eax, eax
// 00487b84  7419                 je 0x487b9f
// 00487b86  b901000000           mov ecx, 1
// 00487b8b  894804               mov dword ptr [eax + 4], ecx
// 00487b8e  894808               mov dword ptr [eax + 8], ecx
// 00487b91  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00487b94  c70008ae7900         mov dword ptr [eax], 0x79ae08
// 00487b9a  89480c               mov dword ptr [eax + 0xc], ecx
// 00487b9d  eb02                 jmp 0x487ba1
// 00487b9f  33c0                 xor eax, eax
// 00487ba1  8906                 mov dword ptr [esi], eax
// 00487ba3  8bc6                 mov eax, esi
// 00487ba5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00487ba8  64890d00000000       mov dword ptr fs:[0], ecx
// 00487baf  59                   pop ecx
// 00487bb0  5f                   pop edi
// 00487bb1  5e                   pop esi
// 00487bb2  5b                   pop ebx
// 00487bb3  8be5                 mov esp, ebp
// 00487bb5  5d                   pop ebp
// 00487bb6  c20800               ret 8

// boost 1.34-style shared_count(P p, D d) constructor (codegen analog):
// pi_ = 0; try { pi_ = new sp_counted_impl_pd<P,D>(p, d); } catch(...) { d(p); throw; }
// new size 0x14 = vptr + use_count + weak_count + ptr + (empty) deleter.
namespace std { class type_info; }

class CRenderSettings;

class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(std::type_info const& ti) = 0;
};

template<class P, class D> class sp_counted_impl_pd : public sp_counted_base {
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(std::type_info const&) { return 0; }
};

struct GetSetDeleter {
    void operator()(CRenderSettings* p) const; // out-of-line thiscall, called from the catch funclet (lea ecx,[ebp+0xc])
};

class shared_count {
    sp_counted_base* pi_;
public:
    template<class P, class D> shared_count(P p, D d);
};

template<class P, class D> shared_count::shared_count(P p, D d) : pi_(0)
{
    try {
        pi_ = new sp_counted_impl_pd<P, D>(p, d);
    } catch (...) {
        d(p);
        throw;
    }
}

template shared_count::shared_count(CRenderSettings*, GetSetDeleter);
