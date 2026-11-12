// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 0040df70  unit: CChatPrompt  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040df70
//
// 0040df70  55                   push ebp
// 0040df71  8bec                 mov ebp, esp
// 0040df73  6aff                 push -1
// 0040df75  68709e7300           push 0x739e70
// 0040df7a  64a100000000         mov eax, dword ptr fs:[0]
// 0040df80  50                   push eax
// 0040df81  51                   push ecx
// 0040df82  53                   push ebx
// 0040df83  56                   push esi
// 0040df84  57                   push edi
// 0040df85  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040df8a  33c5                 xor eax, ebp
// 0040df8c  50                   push eax
// 0040df8d  8d45f4               lea eax, [ebp - 0xc]
// 0040df90  64a300000000         mov dword ptr fs:[0], eax
// 0040df96  8965f0               mov dword ptr [ebp - 0x10], esp
// 0040df99  8bf1                 mov esi, ecx
// 0040df9b  6a14                 push 0x14
// 0040df9d  c70600000000         mov dword ptr [esi], 0
// 0040dfa3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0040dfaa  e8471f2200           call 0x62fef6
// 0040dfaf  83c404               add esp, 4
// 0040dfb2  85c0                 test eax, eax
// 0040dfb4  7419                 je 0x40dfcf
// 0040dfb6  b901000000           mov ecx, 1
// 0040dfbb  894804               mov dword ptr [eax + 4], ecx
// 0040dfbe  894808               mov dword ptr [eax + 8], ecx
// 0040dfc1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0040dfc4  c70094687800         mov dword ptr [eax], 0x786894
// 0040dfca  89480c               mov dword ptr [eax + 0xc], ecx
// 0040dfcd  eb02                 jmp 0x40dfd1
// 0040dfcf  33c0                 xor eax, eax
// 0040dfd1  8906                 mov dword ptr [esi], eax
// 0040dfd3  8bc6                 mov eax, esi
// 0040dfd5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0040dfd8  64890d00000000       mov dword ptr fs:[0], ecx
// 0040dfdf  59                   pop ecx
// 0040dfe0  5f                   pop edi
// 0040dfe1  5e                   pop esi
// 0040dfe2  5b                   pop ebx
// 0040dfe3  8be5                 mov esp, ebp
// 0040dfe5  5d                   pop ebp
// 0040dfe6  c20800               ret 8

void* __cdecl operator new(unsigned int);

struct CChatPrompt;

struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(const void*) = 0;
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    long use_count_;
    long weak_count_;
};

struct null_deleter {
    void operator()(CChatPrompt*) const;
};

template<class P, class D>
struct sp_counted_impl_pd : sp_counted_base {
    P ptr;
    D del;
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(const void*) { return 0; }
};

struct shared_count {
    sp_counted_base* pi_;
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

template shared_count::shared_count(CChatPrompt*, null_deleter);
