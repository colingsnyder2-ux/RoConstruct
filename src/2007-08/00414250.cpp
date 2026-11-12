// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 00414250  unit: std::D::DU?$char_traits::V?$basic_string::?$holder  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00414250
// 00414250  55                   push ebp
// 00414251  8bec                 mov ebp, esp
// 00414253  6aff                 push -1
// 00414255  6850a77300           push 0x73a750
// 0041425a  64a100000000         mov eax, dword ptr fs:[0]
// 00414260  50                   push eax
// 00414261  51                   push ecx
// 00414262  53                   push ebx
// 00414263  56                   push esi
// 00414264  57                   push edi
// 00414265  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041426a  33c5                 xor eax, ebp
// 0041426c  50                   push eax
// 0041426d  8d45f4               lea eax, [ebp - 0xc]
// 00414270  64a300000000         mov dword ptr fs:[0], eax
// 00414276  8965f0               mov dword ptr [ebp - 0x10], esp
// 00414279  8bf1                 mov esi, ecx
// 0041427b  6a14                 push 0x14
// 0041427d  c70600000000         mov dword ptr [esi], 0
// 00414283  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0041428a  e867bc2100           call 0x62fef6
// 0041428f  83c404               add esp, 4
// 00414292  85c0                 test eax, eax
// 00414294  7419                 je 0x4142af
// 00414296  b901000000           mov ecx, 1
// 0041429b  894804               mov dword ptr [eax + 4], ecx
// 0041429e  894808               mov dword ptr [eax + 8], ecx
// 004142a1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004142a4  c700b8717800         mov dword ptr [eax], 0x7871b8
// 004142aa  89480c               mov dword ptr [eax + 0xc], ecx
// 004142ad  eb02                 jmp 0x4142b1
// 004142af  33c0                 xor eax, eax
// 004142b1  8906                 mov dword ptr [esi], eax
// 004142b3  8bc6                 mov eax, esi
// 004142b5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004142b8  64890d00000000       mov dword ptr fs:[0], ecx
// 004142bf  59                   pop ecx
// 004142c0  5f                   pop edi
// 004142c1  5e                   pop esi
// 004142c2  5b                   pop ebx
// 004142c3  8be5                 mov esp, ebp
// 004142c5  5d                   pop ebp
// 004142c6  c20800               ret 8

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
