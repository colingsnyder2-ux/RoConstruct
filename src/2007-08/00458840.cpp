// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 00458840  unit: CRobloxWnd  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00458840
//
// 00458840  55                   push ebp
// 00458841  8bec                 mov ebp, esp
// 00458843  6aff                 push -1
// 00458845  68901f7400           push 0x741f90
// 0045884a  64a100000000         mov eax, dword ptr fs:[0]
// 00458850  50                   push eax
// 00458851  51                   push ecx
// 00458852  53                   push ebx
// 00458853  56                   push esi
// 00458854  57                   push edi
// 00458855  a188518b00           mov eax, dword ptr [0x8b5188]
// 0045885a  33c5                 xor eax, ebp
// 0045885c  50                   push eax
// 0045885d  8d45f4               lea eax, [ebp - 0xc]
// 00458860  64a300000000         mov dword ptr fs:[0], eax
// 00458866  8965f0               mov dword ptr [ebp - 0x10], esp
// 00458869  8bf1                 mov esi, ecx
// 0045886b  6a14                 push 0x14
// 0045886d  c70600000000         mov dword ptr [esi], 0
// 00458873  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0045887a  e877761d00           call 0x62fef6
// 0045887f  83c404               add esp, 4
// 00458882  85c0                 test eax, eax
// 00458884  7419                 je 0x45889f
// 00458886  b901000000           mov ecx, 1
// 0045888b  894804               mov dword ptr [eax + 4], ecx
// 0045888e  894808               mov dword ptr [eax + 8], ecx
// 00458891  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00458894  c70010337900         mov dword ptr [eax], 0x793310
// 0045889a  89480c               mov dword ptr [eax + 0xc], ecx
// 0045889d  eb02                 jmp 0x4588a1
// 0045889f  33c0                 xor eax, eax
// 004588a1  8906                 mov dword ptr [esi], eax
// 004588a3  8bc6                 mov eax, esi
// 004588a5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004588a8  64890d00000000       mov dword ptr fs:[0], ecx
// 004588af  59                   pop ecx
// 004588b0  5f                   pop edi
// 004588b1  5e                   pop esi
// 004588b2  5b                   pop ebx
// 004588b3  8be5                 mov esp, ebp
// 004588b5  5d                   pop ebp
// 004588b6  c20800               ret 8


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
