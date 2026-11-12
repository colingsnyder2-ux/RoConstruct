// from server: 92% by EspClaude
// from server: 46% by colin
// roc 2007-08 004193f0  unit: VDHTMLWindow::?$SignalDesc  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004193f0
//
// 004193f0  55                   push ebp
// 004193f1  8bec                 mov ebp, esp
// 004193f3  6aff                 push -1
// 004193f5  6860b07300           push 0x73b060
// 004193fa  64a100000000         mov eax, dword ptr fs:[0]
// 00419400  50                   push eax
// 00419401  51                   push ecx
// 00419402  53                   push ebx
// 00419403  56                   push esi
// 00419404  57                   push edi
// 00419405  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041940a  33c5                 xor eax, ebp
// 0041940c  50                   push eax
// 0041940d  8d45f4               lea eax, [ebp - 0xc]
// 00419410  64a300000000         mov dword ptr fs:[0], eax
// 00419416  8965f0               mov dword ptr [ebp - 0x10], esp
// 00419419  8bf1                 mov esi, ecx
// 0041941b  6a14                 push 0x14
// 0041941d  c70600000000         mov dword ptr [esi], 0
// 00419423  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0041942a  e8c76a2100           call 0x62fef6
// 0041942f  83c404               add esp, 4
// 00419432  85c0                 test eax, eax
// 00419434  7419                 je 0x41944f
// 00419436  b901000000           mov ecx, 1
// 0041943b  894804               mov dword ptr [eax + 4], ecx
// 0041943e  894808               mov dword ptr [eax + 8], ecx
// 00419441  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00419444  c70094757800         mov dword ptr [eax], 0x787594
// 0041944a  89480c               mov dword ptr [eax + 0xc], ecx
// 0041944d  eb02                 jmp 0x419451
// 0041944f  33c0                 xor eax, eax
// 00419451  8906                 mov dword ptr [esi], eax
// 00419453  8bc6                 mov eax, esi
// 00419455  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00419458  64890d00000000       mov dword ptr fs:[0], ecx
// 0041945f  59                   pop ecx
// 00419460  5f                   pop edi
// 00419461  5e                   pop esi
// 00419462  5b                   pop ebx
// 00419463  8be5                 mov esp, ebp
// 00419465  5d                   pop ebp
// 00419466  c20800               ret 8

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

struct SignalDesc;
// catch funclet after the body (exe 0x419469) calls the deleter out of line:
// mov edx,[ebp+8]; push edx; lea ecx,[ebp+0xc]; call
struct null_deleter { void operator()(void const*) const; };

template boost::detail::shared_count::shared_count(SignalDesc* p, null_deleter d);
