// from server: 92% by EspClaude
// from server: 46% by colin
// roc 2007-08 0041c140  unit: VDHTMLWindow::?$SignalDesc  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041c140
//
// 0041c140  55                   push ebp
// 0041c141  8bec                 mov ebp, esp
// 0041c143  6aff                 push -1
// 0041c145  6830b57300           push 0x73b530
// 0041c14a  64a100000000         mov eax, dword ptr fs:[0]
// 0041c150  50                   push eax
// 0041c151  51                   push ecx
// 0041c152  53                   push ebx
// 0041c153  56                   push esi
// 0041c154  57                   push edi
// 0041c155  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041c15a  33c5                 xor eax, ebp
// 0041c15c  50                   push eax
// 0041c15d  8d45f4               lea eax, [ebp - 0xc]
// 0041c160  64a300000000         mov dword ptr fs:[0], eax
// 0041c166  8965f0               mov dword ptr [ebp - 0x10], esp
// 0041c169  8bf1                 mov esi, ecx
// 0041c16b  6a14                 push 0x14
// 0041c16d  c70600000000         mov dword ptr [esi], 0
// 0041c173  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0041c17a  e8773d2100           call 0x62fef6
// 0041c17f  83c404               add esp, 4
// 0041c182  85c0                 test eax, eax
// 0041c184  7419                 je 0x41c19f
// 0041c186  b901000000           mov ecx, 1
// 0041c18b  894804               mov dword ptr [eax + 4], ecx
// 0041c18e  894808               mov dword ptr [eax + 8], ecx
// 0041c191  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0041c194  c700687a7800         mov dword ptr [eax], 0x787a68
// 0041c19a  89480c               mov dword ptr [eax + 0xc], ecx
// 0041c19d  eb02                 jmp 0x41c1a1
// 0041c19f  33c0                 xor eax, eax
// 0041c1a1  8906                 mov dword ptr [esi], eax
// 0041c1a3  8bc6                 mov eax, esi
// 0041c1a5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0041c1a8  64890d00000000       mov dword ptr fs:[0], ecx
// 0041c1af  59                   pop ecx
// 0041c1b0  5f                   pop edi
// 0041c1b1  5e                   pop esi
// 0041c1b2  5b                   pop ebx
// 0041c1b3  8be5                 mov esp, ebp
// 0041c1b5  5d                   pop ebp
// 0041c1b6  c20800               ret 8

// boost::detail::shared_count(P p, D d) shape: pi_ = 0; try { pi_ = new
// sp_counted_impl_pd<P,D>(p, d) (0x14 bytes: vptr, use=1, weak=1, ptr @+0xc,
// empty deleter @+0x10) } catch (...) { d(p); throw; }   (ret 8 = p + d)
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

struct SignalDescC140;
// catch funclet after the body (exe 0x41c1b9) calls the deleter out of line:
// mov edx,[ebp+8]; push edx; lea ecx,[ebp+0xc]; call
struct null_deleter { void operator()(void const*) const; };

template boost::detail::shared_count::shared_count(SignalDescC140* p, null_deleter d);
