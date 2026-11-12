// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 0040d340  unit: ChatEnter  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040d340
//
// 0040d340  55                   push ebp
// 0040d341  8bec                 mov ebp, esp
// 0040d343  6aff                 push -1
// 0040d345  68909d7300           push 0x739d90
// 0040d34a  64a100000000         mov eax, dword ptr fs:[0]
// 0040d350  50                   push eax
// 0040d351  51                   push ecx
// 0040d352  53                   push ebx
// 0040d353  56                   push esi
// 0040d354  57                   push edi
// 0040d355  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040d35a  33c5                 xor eax, ebp
// 0040d35c  50                   push eax
// 0040d35d  8d45f4               lea eax, [ebp - 0xc]
// 0040d360  64a300000000         mov dword ptr fs:[0], eax
// 0040d366  8965f0               mov dword ptr [ebp - 0x10], esp
// 0040d369  8bf1                 mov esi, ecx
// 0040d36b  6a14                 push 0x14
// 0040d36d  c70600000000         mov dword ptr [esi], 0
// 0040d373  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0040d37a  e8772b2200           call 0x62fef6
// 0040d37f  83c404               add esp, 4
// 0040d382  85c0                 test eax, eax
// 0040d384  7419                 je 0x40d39f
// 0040d386  b901000000           mov ecx, 1
// 0040d38b  894804               mov dword ptr [eax + 4], ecx
// 0040d38e  894808               mov dword ptr [eax + 8], ecx
// 0040d391  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0040d394  c70020657800         mov dword ptr [eax], 0x786520
// 0040d39a  89480c               mov dword ptr [eax + 0xc], ecx
// 0040d39d  eb02                 jmp 0x40d3a1
// 0040d39f  33c0                 xor eax, eax
// 0040d3a1  8906                 mov dword ptr [esi], eax
// 0040d3a3  8bc6                 mov eax, esi
// 0040d3a5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0040d3a8  64890d00000000       mov dword ptr fs:[0], ecx
// 0040d3af  59                   pop ecx
// 0040d3b0  5f                   pop edi
// 0040d3b1  5e                   pop esi
// 0040d3b2  5b                   pop ebx
// 0040d3b3  8be5                 mov esp, ebp

// Boost 1.34-style shared_count(P p, D d): try { new sp_counted_impl_pd } catch(...) { d(p); throw; }
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(int const&) = 0;
};

struct ChatEnter;
struct ChatEnterDeleter {
    void operator()(ChatEnter* p) const;
};

template<class P, class D> class sp_counted_impl_pd : public sp_counted_base {
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(int const&) { return &del; }
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

template shared_count::shared_count(ChatEnter*, ChatEnterDeleter);
