// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 0048ac30  unit: RBX::VHopperBin::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048ac30
//
// 0048ac30  55                   push ebp
// 0048ac31  8bec                 mov ebp, esp
// 0048ac33  6aff                 push -1
// 0048ac35  6880717400           push 0x747180
// 0048ac3a  64a100000000         mov eax, dword ptr fs:[0]
// 0048ac40  50                   push eax
// 0048ac41  51                   push ecx
// 0048ac42  53                   push ebx
// 0048ac43  56                   push esi
// 0048ac44  57                   push edi
// 0048ac45  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048ac4a  33c5                 xor eax, ebp
// 0048ac4c  50                   push eax
// 0048ac4d  8d45f4               lea eax, [ebp - 0xc]
// 0048ac50  64a300000000         mov dword ptr fs:[0], eax
// 0048ac56  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048ac59  8bf1                 mov esi, ecx
// 0048ac5b  6a14                 push 0x14
// 0048ac5d  c70600000000         mov dword ptr [esi], 0
// 0048ac63  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048ac6a  e887521a00           call 0x62fef6
// 0048ac6f  83c404               add esp, 4
// 0048ac72  85c0                 test eax, eax
// 0048ac74  7419                 je 0x48ac8f
// 0048ac76  b901000000           mov ecx, 1
// 0048ac7b  894804               mov dword ptr [eax + 4], ecx
// 0048ac7e  894808               mov dword ptr [eax + 8], ecx
// 0048ac81  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0048ac84  c700a4af7900         mov dword ptr [eax], 0x79afa4
// 0048ac8a  89480c               mov dword ptr [eax + 0xc], ecx
// 0048ac8d  eb02                 jmp 0x48ac91
// 0048ac8f  33c0                 xor eax, eax
// 0048ac91  8906                 mov dword ptr [esi], eax
// 0048ac93  8bc6                 mov eax, esi
// 0048ac95  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048ac98  64890d00000000       mov dword ptr fs:[0], ecx
// 0048ac9f  59                   pop ecx
// 0048aca0  5f                   pop edi
// 0048aca1  5e                   pop esi
// 0048aca2  5b                   pop ebx
// 0048aca3  8be5                 mov esp, ebp
// 0048aca5  5d                   pop ebp
// 0048aca6  c20800               ret 8

// boost::detail::shared_count(P p, D d) shape: pi_(0); try { pi_ = new sp_counted_impl_pd<P,D>(p, d); }
// catch(...) { d(p); throw; }.  new size 0x14 = vptr, use_count, weak_count, ptr, (empty) deleter.

class sp_counted_base
{
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(const void* ti) = 0;
private:
    long use_count_;
    long weak_count_;
};

struct HopperBin;

// catch funclet 0x48aca9: push [ebp+8]; lea ecx,[ebp+0xc]; call 0x4074c0 -> out-of-line thiscall d(p)
struct Deleter
{
    void operator()(HopperBin* p);
};

template<class P, class D>
class sp_counted_impl_pd : public sp_counted_base
{
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(const void*) { return &del; }
};

class shared_count
{
    sp_counted_base* pi_;
public:
    template<class P, class D> shared_count(P p, D d);
};

template<class P, class D>
shared_count::shared_count(P p, D d) : pi_(0)
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

template shared_count::shared_count(HopperBin*, Deleter);
