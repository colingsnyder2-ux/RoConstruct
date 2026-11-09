// from server: 92% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004094e0  unit: RBX::Network::VPlayer::?$FactoryProduct::Creator  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004094e0
//
// 004094e0  55                   push ebp
// 004094e1  8bec                 mov ebp, esp
// 004094e3  6aff                 push -1
// 004094e5  68d0cf7b00           push 0x7bcfd0
// 004094ea  64a100000000         mov eax, dword ptr fs:[0]
// 004094f0  50                   push eax
// 004094f1  64892500000000       mov dword ptr fs:[0], esp
// 004094f8  51                   push ecx
// 004094f9  53                   push ebx
// 004094fa  56                   push esi
// 004094fb  57                   push edi
// 004094fc  8965f0               mov dword ptr [ebp - 0x10], esp
// 004094ff  8bf1                 mov esi, ecx
// 00409501  6a14                 push 0x14
// 00409503  c70600000000         mov dword ptr [esi], 0
// 00409509  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00409510  e80b742900           call 0x6a0920
// 00409515  83c404               add esp, 4
// 00409518  85c0                 test eax, eax
// 0040951a  7419                 je 0x409535
// 0040951c  b901000000           mov ecx, 1
// 00409521  894804               mov dword ptr [eax + 4], ecx
// 00409524  894808               mov dword ptr [eax + 8], ecx
// 00409527  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0040952a  c700d0b68000         mov dword ptr [eax], 0x80b6d0
// 00409530  89480c               mov dword ptr [eax + 0xc], ecx
// 00409533  eb02                 jmp 0x409537
// 00409535  33c0                 xor eax, eax
// 00409537  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0040953a  8906                 mov dword ptr [esi], eax
// 0040953c  5f                   pop edi
// 0040953d  8bc6                 mov eax, esi
// 0040953f  5e                   pop esi
// 00409540  64890d00000000       mov dword ptr fs:[0], ecx
// 00409547  5b                   pop ebx
// 00409548  8be5                 mov esp, ebp
// 0040954a  5d                   pop ebp
// 0040954b  c20800               ret 8

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
