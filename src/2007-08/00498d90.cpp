// from server: 92% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 0049e620  unit: RBX::Network::AbuseReporter::Udata::?$sp_counted_impl_p  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0049e620
//
// 0049e620  55                   push ebp
// 0049e621  8bec                 mov ebp, esp
// 0049e623  6aff                 push -1
// 0049e625  68e0757c00           push 0x7c75e0
// 0049e62a  64a100000000         mov eax, dword ptr fs:[0]
// 0049e630  50                   push eax
// 0049e631  64892500000000       mov dword ptr fs:[0], esp
// 0049e638  51                   push ecx
// 0049e639  53                   push ebx
// 0049e63a  56                   push esi
// 0049e63b  57                   push edi
// 0049e63c  8965f0               mov dword ptr [ebp - 0x10], esp
// 0049e63f  8bf1                 mov esi, ecx
// 0049e641  6a14                 push 0x14
// 0049e643  c70600000000         mov dword ptr [esi], 0
// 0049e649  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0049e650  e8cb222000           call 0x6a0920
// 0049e655  83c404               add esp, 4
// 0049e658  85c0                 test eax, eax
// 0049e65a  7419                 je 0x49e675
// 0049e65c  b901000000           mov ecx, 1
// 0049e661  894804               mov dword ptr [eax + 4], ecx
// 0049e664  894808               mov dword ptr [eax + 8], ecx
// 0049e667  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0049e66a  c700d82c8200         mov dword ptr [eax], 0x822cd8
// 0049e670  89480c               mov dword ptr [eax + 0xc], ecx
// 0049e673  eb02                 jmp 0x49e677
// 0049e675  33c0                 xor eax, eax
// 0049e677  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0049e67a  8906                 mov dword ptr [esi], eax
// 0049e67c  5f                   pop edi
// 0049e67d  8bc6                 mov eax, esi
// 0049e67f  5e                   pop esi
// 0049e680  64890d00000000       mov dword ptr fs:[0], ecx
// 0049e687  5b                   pop ebx
// 0049e688  8be5                 mov esp, ebp
// 0049e68a  5d                   pop ebp
// 0049e68b  c20800               ret 8

#pragma optimize("y", off)

void* __cdecl operator new(unsigned int);
extern void* controlVtable[];

struct Deleter {
    void operator()(void*) const;
};



struct Control {
    void** vtable;
    int strong;
    int weak;
    void* object;
    Deleter deleter;

    Control(void*, const Deleter&);
};

inline Control::Control(void* p, const Deleter& d)
    : strong(1), weak(1), deleter(d)
{
    vtable = controlVtable;
    object = p;
}

struct S {
    Control* control;
    S(void*, Deleter);
};

S::S(void* p, Deleter d) : control(0)
{
    try {
        control = new Control(p, d);
    }
    catch (...) {
        d(p);
        throw;
    }
}
