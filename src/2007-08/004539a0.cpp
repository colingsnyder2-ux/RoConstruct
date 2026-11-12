// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 004539a0  unit: CRobloxReportDocView  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004539a0
//
// 004539a0  55                   push ebp
// 004539a1  8bec                 mov ebp, esp
// 004539a3  6aff                 push -1
// 004539a5  68d0137400           push 0x7413d0
// 004539aa  64a100000000         mov eax, dword ptr fs:[0]
// 004539b0  50                   push eax
// 004539b1  51                   push ecx
// 004539b2  53                   push ebx
// 004539b3  56                   push esi
// 004539b4  57                   push edi
// 004539b5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004539ba  33c5                 xor eax, ebp
// 004539bc  50                   push eax
// 004539bd  8d45f4               lea eax, [ebp - 0xc]
// 004539c0  64a300000000         mov dword ptr fs:[0], eax
// 004539c6  8965f0               mov dword ptr [ebp - 0x10], esp
// 004539c9  8bf1                 mov esi, ecx
// 004539cb  6a14                 push 0x14
// 004539cd  c70600000000         mov dword ptr [esi], 0
// 004539d3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004539da  e817c51d00           call 0x62fef6
// 004539df  83c404               add esp, 4
// 004539e2  85c0                 test eax, eax
// 004539e4  7419                 je 0x4539ff
// 004539e6  b901000000           mov ecx, 1
// 004539eb  894804               mov dword ptr [eax + 4], ecx
// 004539ee  894808               mov dword ptr [eax + 8], ecx
// 004539f1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004539f4  c700b41e7900         mov dword ptr [eax], 0x791eb4
// 004539fa  89480c               mov dword ptr [eax + 0xc], ecx
// 004539fd  eb02                 jmp 0x453a01
// 004539ff  33c0                 xor eax, eax
// 00453a01  8906                 mov dword ptr [esi], eax
// 00453a03  8bc6                 mov eax, esi
// 00453a05  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00453a08  64890d00000000       mov dword ptr fs:[0], ecx
// 00453a0f  59                   pop ecx
// 00453a10  5f                   pop edi
// 00453a11  5e                   pop esi
// 00453a12  5b                   pop ebx
// 00453a13  8be5                 mov esp, ebp
// 00453a15  5d                   pop ebp
// 00453a16  c20800               ret 8

class CRobloxReportDocView;

struct null_deleter { void operator()(CRobloxReportDocView* p) const; };

class sp_counted_base
{
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(int const& ti) = 0;
private:
    long use_count_;
    long weak_count_;
};

template<class P, class D> class sp_counted_impl_pd : public sp_counted_base
{
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(int const& ti) { return 0; }
};

class shared_count
{
    sp_counted_base* pi_;
public:
    template<class P, class D> shared_count(P p, D d) : pi_(0)
    {
        try
        {
            pi_ = new sp_counted_impl_pd<P, D>(p, d);
        }
        catch (...)
        {
            d(p);
            throw;
        }
    }
};

template shared_count::shared_count(CRobloxReportDocView*, null_deleter);
