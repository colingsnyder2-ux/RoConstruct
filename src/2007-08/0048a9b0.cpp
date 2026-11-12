// from server: 92% by EspClaude
// from server: 46% by colin
// roc 2007-08 0048a9b0  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$TSignalDesc::TSignalInstance  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048a9b0
// 0048a9b0  55                   push ebp
// 0048a9b1  8bec                 mov ebp, esp
// 0048a9b3  6aff                 push -1
// 0048a9b5  6860717400           push 0x747160
// 0048a9ba  64a100000000         mov eax, dword ptr fs:[0]
// 0048a9c0  50                   push eax
// 0048a9c1  51                   push ecx
// 0048a9c2  53                   push ebx
// 0048a9c3  56                   push esi
// 0048a9c4  57                   push edi
// 0048a9c5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048a9ca  33c5                 xor eax, ebp
// 0048a9cc  50                   push eax
// 0048a9cd  8d45f4               lea eax, [ebp - 0xc]
// 0048a9d0  64a300000000         mov dword ptr fs:[0], eax
// 0048a9d6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048a9d9  8bf1                 mov esi, ecx
// 0048a9db  6a14                 push 0x14
// 0048a9dd  c70600000000         mov dword ptr [esi], 0
// 0048a9e3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048a9ea  e807551a00           call 0x62fef6
// 0048a9ef  83c404               add esp, 4
// 0048a9f2  85c0                 test eax, eax
// 0048a9f4  7419                 je 0x48aa0f
// 0048a9f6  b901000000           mov ecx, 1
// 0048a9fb  894804               mov dword ptr [eax + 4], ecx
// 0048a9fe  894808               mov dword ptr [eax + 8], ecx
// 0048aa01  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0048aa04  c70088af7900         mov dword ptr [eax], 0x79af88
// 0048aa0a  89480c               mov dword ptr [eax + 0xc], ecx
// 0048aa0d  eb02                 jmp 0x48aa11
// 0048aa0f  33c0                 xor eax, eax
// 0048aa11  8906                 mov dword ptr [esi], eax
// 0048aa13  8bc6                 mov eax, esi
// 0048aa15  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048aa18  64890d00000000       mov dword ptr fs:[0], ecx
// 0048aa1f  59                   pop ecx
// 0048aa20  5f                   pop edi
// 0048aa21  5e                   pop esi
// 0048aa22  5b                   pop ebx
// 0048aa23  8be5                 mov esp, ebp
// 0048aa25  5d                   pop ebp
// 0048aa26  c20800               ret 8

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
