// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 00458690  unit: CRobloxWnd  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00458690
//
// 00458690  55                   push ebp
// 00458691  8bec                 mov ebp, esp
// 00458693  6aff                 push -1
// 00458695  68301f7400           push 0x741f30
// 0045869a  64a100000000         mov eax, dword ptr fs:[0]
// 004586a0  50                   push eax
// 004586a1  51                   push ecx
// 004586a2  53                   push ebx
// 004586a3  56                   push esi
// 004586a4  57                   push edi
// 004586a5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004586aa  33c5                 xor eax, ebp
// 004586ac  50                   push eax
// 004586ad  8d45f4               lea eax, [ebp - 0xc]
// 004586b0  64a300000000         mov dword ptr fs:[0], eax
// 004586b6  8965f0               mov dword ptr [ebp - 0x10], esp
// 004586b9  8bf1                 mov esi, ecx
// 004586bb  6a14                 push 0x14
// 004586bd  c70600000000         mov dword ptr [esi], 0
// 004586c3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004586ca  e827781d00           call 0x62fef6
// 004586cf  83c404               add esp, 4
// 004586d2  85c0                 test eax, eax
// 004586d4  7419                 je 0x4586ef
// 004586d6  b901000000           mov ecx, 1
// 004586db  894804               mov dword ptr [eax + 4], ecx
// 004586de  894808               mov dword ptr [eax + 8], ecx
// 004586e1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004586e4  c700d4327900         mov dword ptr [eax], 0x7932d4
// 004586ea  89480c               mov dword ptr [eax + 0xc], ecx
// 004586ed  eb02                 jmp 0x4586f1
// 004586ef  33c0                 xor eax, eax
// 004586f1  8906                 mov dword ptr [esi], eax
// 004586f3  8bc6                 mov eax, esi
// 004586f5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004586f8  64890d00000000       mov dword ptr fs:[0], ecx
// 004586ff  59                   pop ecx
// 00458700  5f                   pop edi
// 00458701  5e                   pop esi
// 00458702  5b                   pop ebx
// 00458703  8be5                 mov esp, ebp
// 00458705  5d                   pop ebp
// 00458706  c20800               ret 8


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
