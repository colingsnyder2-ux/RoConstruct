// from server: 96% by EspClaude
// from server: 50% by colin
// roc 2007-08 0041c660  unit: RBX::VTexture::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041c660
//
// 0041c660  55                   push ebp
// 0041c661  8bec                 mov ebp, esp
// 0041c663  6aff                 push -1
// 0041c665  6870b57300           push 0x73b570
// 0041c66a  64a100000000         mov eax, dword ptr fs:[0]
// 0041c670  50                   push eax
// 0041c671  51                   push ecx
// 0041c672  53                   push ebx
// 0041c673  56                   push esi
// 0041c674  57                   push edi
// 0041c675  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041c67a  33c5                 xor eax, ebp
// 0041c67c  50                   push eax
// 0041c67d  8d45f4               lea eax, [ebp - 0xc]
// 0041c680  64a300000000         mov dword ptr fs:[0], eax
// 0041c686  8965f0               mov dword ptr [ebp - 0x10], esp
// 0041c689  8bf1                 mov esi, ecx
// 0041c68b  6a14                 push 0x14
// 0041c68d  c70600000000         mov dword ptr [esi], 0
// 0041c693  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0041c69a  e857382100           call 0x62fef6
// 0041c69f  83c404               add esp, 4
// 0041c6a2  85c0                 test eax, eax
// 0041c6a4  7419                 je 0x41c6bf
// 0041c6a6  b901000000           mov ecx, 1
// 0041c6ab  894804               mov dword ptr [eax + 4], ecx
// 0041c6ae  894808               mov dword ptr [eax + 8], ecx
// 0041c6b1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0041c6b4  c700a87a7800         mov dword ptr [eax], 0x787aa8
// 0041c6ba  89480c               mov dword ptr [eax + 0xc], ecx
// 0041c6bd  eb02                 jmp 0x41c6c1
// 0041c6bf  33c0                 xor eax, eax
// 0041c6c1  8906                 mov dword ptr [esi], eax
// 0041c6c3  8bc6                 mov eax, esi
// 0041c6c5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0041c6c8  64890d00000000       mov dword ptr fs:[0], ecx
// 0041c6cf  59                   pop ecx
// 0041c6d0  5f                   pop edi
// 0041c6d1  5e                   pop esi
// 0041c6d2  5b                   pop ebx
// 0041c6d3  8be5                 mov esp, ebp
// 0041c6d5  5d                   pop ebp
// 0041c6d6  c20800               ret 8

// boost shared_count(P p, D d) shape: try { pi_ = new sp_counted_impl_pd<P,D>(p, d); }
// catch (...) { d(p); throw; }  -- new(0x14), use/weak counts at +4/+8, ptr at +0xc,
// empty deleter at +0x10; ret 8 = pointer + 4-byte deleter by value.
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

struct null_deleter {
    void operator()(const void*) const {}
};

template<class P, class D>
class sp_counted_impl_pd : public sp_counted_base {
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(const void*) { return &del; }
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

template shared_count::shared_count(const void*, null_deleter);
