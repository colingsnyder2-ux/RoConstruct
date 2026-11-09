// from server: 92% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00411940  unit: ChatEnter  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00411940
//
// 00411940  55                   push ebp
// 00411941  8bec                 mov ebp, esp
// 00411943  6aff                 push -1
// 00411945  6810d77b00           push 0x7bd710
// 0041194a  64a100000000         mov eax, dword ptr fs:[0]
// 00411950  50                   push eax
// 00411951  64892500000000       mov dword ptr fs:[0], esp
// 00411958  51                   push ecx
// 00411959  53                   push ebx
// 0041195a  56                   push esi
// 0041195b  57                   push edi
// 0041195c  8965f0               mov dword ptr [ebp - 0x10], esp
// 0041195f  8bf1                 mov esi, ecx
// 00411961  6a14                 push 0x14
// 00411963  c70600000000         mov dword ptr [esi], 0
// 00411969  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00411970  e8abef2800           call 0x6a0920
// 00411975  83c404               add esp, 4
// 00411978  85c0                 test eax, eax
// 0041197a  7419                 je 0x411995
// 0041197c  b901000000           mov ecx, 1
// 00411981  894804               mov dword ptr [eax + 4], ecx
// 00411984  894808               mov dword ptr [eax + 8], ecx
// 00411987  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0041198a  c70094e08000         mov dword ptr [eax], 0x80e094
// 00411990  89480c               mov dword ptr [eax + 0xc], ecx
// 00411993  eb02                 jmp 0x411997
// 00411995  33c0                 xor eax, eax
// 00411997  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0041199a  8906                 mov dword ptr [esi], eax
// 0041199c  5f                   pop edi
// 0041199d  8bc6                 mov eax, esi
// 0041199f  5e                   pop esi
// 004119a0  64890d00000000       mov dword ptr fs:[0], ecx
// 004119a7  5b                   pop ebx
// 004119a8  8be5                 mov esp, ebp
// 004119aa  5d                   pop ebp
// 004119ab  c20800               ret 8

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
