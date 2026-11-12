// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 00407760  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00407760
//
// 00407760  55                   push ebp
// 00407761  8bec                 mov ebp, esp
// 00407763  6aff                 push -1
// 00407765  68a0957300           push 0x7395a0
// 0040776a  64a100000000         mov eax, dword ptr fs:[0]
// 00407770  50                   push eax
// 00407771  51                   push ecx
// 00407772  53                   push ebx
// 00407773  56                   push esi
// 00407774  57                   push edi
// 00407775  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040777a  33c5                 xor eax, ebp
// 0040777c  50                   push eax
// 0040777d  8d45f4               lea eax, [ebp - 0xc]
// 00407780  64a300000000         mov dword ptr fs:[0], eax
// 00407786  8965f0               mov dword ptr [ebp - 0x10], esp
// 00407789  8bf1                 mov esi, ecx
// 0040778b  6a14                 push 0x14
// 0040778d  c70600000000         mov dword ptr [esi], 0
// 00407793  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0040779a  e857872200           call 0x62fef6
// 0040779f  83c404               add esp, 4
// 004077a2  85c0                 test eax, eax
// 004077a4  7419                 je 0x4077bf
// 004077a6  b901000000           mov ecx, 1
// 004077ab  894804               mov dword ptr [eax + 4], ecx
// 004077ae  894808               mov dword ptr [eax + 8], ecx
// 004077b1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004077b4  c70094507800         mov dword ptr [eax], 0x785094
// 004077ba  89480c               mov dword ptr [eax + 0xc], ecx
// 004077bd  eb02                 jmp 0x4077c1
// 004077bf  33c0                 xor eax, eax
// 004077c1  8906                 mov dword ptr [esi], eax
// 004077c3  8bc6                 mov eax, esi
// 004077c5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004077c8  64890d00000000       mov dword ptr fs:[0], ecx
// 004077cf  59                   pop ecx
// 004077d0  5f                   pop edi
// 004077d1  5e                   pop esi
// 004077d2  5b                   pop ebx
// 004077d3  8be5                 mov esp, ebp
// 004077d5  5d                   pop ebp
// 004077d6  c20800               ret 8



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
