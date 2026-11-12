// from server: 92% by EspClaude
// from server: 46% by colin
// roc 2007-08 004af430  unit: RBX::VRotateP::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004af430
//
// 004af430  55                   push ebp
// 004af431  8bec                 mov ebp, esp
// 004af433  6aff                 push -1
// 004af435  68d0a57400           push 0x74a5d0
// 004af43a  64a100000000         mov eax, dword ptr fs:[0]
// 004af440  50                   push eax
// 004af441  51                   push ecx
// 004af442  53                   push ebx
// 004af443  56                   push esi
// 004af444  57                   push edi
// 004af445  a188518b00           mov eax, dword ptr [0x8b5188]
// 004af44a  33c5                 xor eax, ebp
// 004af44c  50                   push eax
// 004af44d  8d45f4               lea eax, [ebp - 0xc]
// 004af450  64a300000000         mov dword ptr fs:[0], eax
// 004af456  8965f0               mov dword ptr [ebp - 0x10], esp
// 004af459  8bf1                 mov esi, ecx
// 004af45b  6a14                 push 0x14
// 004af45d  c70600000000         mov dword ptr [esi], 0
// 004af463  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004af46a  e8870a1800           call 0x62fef6
// 004af46f  83c404               add esp, 4
// 004af472  85c0                 test eax, eax
// 004af474  7419                 je 0x4af48f
// 004af476  b901000000           mov ecx, 1
// 004af47b  894804               mov dword ptr [eax + 4], ecx
// 004af47e  894808               mov dword ptr [eax + 8], ecx
// 004af481  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004af484  c700d0d87900         mov dword ptr [eax], 0x79d8d0
// 004af48a  89480c               mov dword ptr [eax + 0xc], ecx
// 004af48d  eb02                 jmp 0x4af491
// 004af48f  33c0                 xor eax, eax
// 004af491  8906                 mov dword ptr [esi], eax
// 004af493  8bc6                 mov eax, esi
// 004af495  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004af498  64890d00000000       mov dword ptr fs:[0], ecx
// 004af49f  59                   pop ecx
// 004af4a0  5f                   pop edi
// 004af4a1  5e                   pop esi
// 004af4a2  5b                   pop ebx
// 004af4a3  8be5                 mov esp, ebp
// 004af4a5  5d                   pop ebp
// 004af4a6  c20800               ret 8



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
