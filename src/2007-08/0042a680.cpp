// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 0042a680  unit: CLuaHtmlView  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042a680
//
// 0042a680  55                   push ebp
// 0042a681  8bec                 mov ebp, esp
// 0042a683  6aff                 push -1
// 0042a685  6800cf7300           push 0x73cf00
// 0042a68a  64a100000000         mov eax, dword ptr fs:[0]
// 0042a690  50                   push eax
// 0042a691  51                   push ecx
// 0042a692  53                   push ebx
// 0042a693  56                   push esi
// 0042a694  57                   push edi
// 0042a695  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042a69a  33c5                 xor eax, ebp
// 0042a69c  50                   push eax
// 0042a69d  8d45f4               lea eax, [ebp - 0xc]
// 0042a6a0  64a300000000         mov dword ptr fs:[0], eax
// 0042a6a6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0042a6a9  8bf1                 mov esi, ecx
// 0042a6ab  6a10                 push 0x10
// 0042a6ad  c70600000000         mov dword ptr [esi], 0
// 0042a6b3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0042a6ba  e837582000           call 0x62fef6
// 0042a6bf  83c404               add esp, 4
// 0042a6c2  85c0                 test eax, eax
// 0042a6c4  7419                 je 0x42a6df
// 0042a6c6  b901000000           mov ecx, 1
// 0042a6cb  894804               mov dword ptr [eax + 4], ecx
// 0042a6ce  894808               mov dword ptr [eax + 8], ecx
// 0042a6d1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0042a6d4  c700f4a17800         mov dword ptr [eax], 0x78a1f4
// 0042a6da  89480c               mov dword ptr [eax + 0xc], ecx
// 0042a6dd  eb02                 jmp 0x42a6e1
// 0042a6df  33c0                 xor eax, eax
// 0042a6e1  8906                 mov dword ptr [esi], eax
// 0042a6e3  8bc6                 mov eax, esi
// 0042a6e5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0042a6e8  64890d00000000       mov dword ptr fs:[0], ecx
// 0042a6ef  59                   pop ecx
// 0042a6f0  5f                   pop edi
// 0042a6f1  5e                   pop esi
// 0042a6f2  5b                   pop ebx
// 0042a6f3  8be5                 mov esp, ebp
// 0042a6f5  5d                   pop ebp
// 0042a6f6  c20400               ret 4

// roc-flags: /O2 /GS /EHsc /MD

struct X;

class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(int) = 0;
};

class sp_counted_impl_p : public sp_counted_base {
    X* px_;
public:
    explicit sp_counted_impl_p(X* px) : px_(px) {}
    virtual void dispose();
    virtual void* get_deleter(int) { return 0; }
};

void checked_delete_X(X* p);

class shared_count {
    sp_counted_base* pi_;
public:
    explicit shared_count(X* p);
};

shared_count::shared_count(X* p) : pi_(0)
{
    try {
        pi_ = new sp_counted_impl_p(p);
    } catch (...) {
        checked_delete_X(p);
        throw;
    }
}
