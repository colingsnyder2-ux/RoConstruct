// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 0048be60  unit: RBX::VShirt::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048be60
//
// 0048be60  55                   push ebp
// 0048be61  8bec                 mov ebp, esp
// 0048be63  6aff                 push -1
// 0048be65  68a0727400           push 0x7472a0
// 0048be6a  64a100000000         mov eax, dword ptr fs:[0]
// 0048be70  50                   push eax
// 0048be71  51                   push ecx
// 0048be72  53                   push ebx
// 0048be73  56                   push esi
// 0048be74  57                   push edi
// 0048be75  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048be7a  33c5                 xor eax, ebp
// 0048be7c  50                   push eax
// 0048be7d  8d45f4               lea eax, [ebp - 0xc]
// 0048be80  64a300000000         mov dword ptr fs:[0], eax
// 0048be86  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048be89  8bf1                 mov esi, ecx
// 0048be8b  6a14                 push 0x14
// 0048be8d  c70600000000         mov dword ptr [esi], 0
// 0048be93  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048be9a  e857401a00           call 0x62fef6
// 0048be9f  83c404               add esp, 4
// 0048bea2  85c0                 test eax, eax
// 0048bea4  7419                 je 0x48bebf
// 0048bea6  b901000000           mov ecx, 1
// 0048beab  894804               mov dword ptr [eax + 4], ecx
// 0048beae  894808               mov dword ptr [eax + 8], ecx
// 0048beb1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0048beb4  c70070b07900         mov dword ptr [eax], 0x79b070
// 0048beba  89480c               mov dword ptr [eax + 0xc], ecx
// 0048bebd  eb02                 jmp 0x48bec1
// 0048bebf  33c0                 xor eax, eax
// 0048bec1  8906                 mov dword ptr [esi], eax
// 0048bec3  8bc6                 mov eax, esi
// 0048bec5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048bec8  64890d00000000       mov dword ptr fs:[0], ecx
// 0048becf  59                   pop ecx
// 0048bed0  5f                   pop edi
// 0048bed1  5e                   pop esi
// 0048bed2  5b                   pop ebx
// 0048bed3  8be5                 mov esp, ebp
// 0048bed5  5d                   pop ebp
// 0048bed6  c20800               ret 8



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
