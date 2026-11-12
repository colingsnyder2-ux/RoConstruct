// from server: 92% by EspClaude
// from server: 49% by tester
// roc 2007-08 0048bbe0  unit: RBX::VShirtGraphic::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048bbe0
//
// 0048bbe0  55                   push ebp
// 0048bbe1  8bec                 mov ebp, esp
// 0048bbe3  6aff                 push -1
// 0048bbe5  6880727400           push 0x747280
// 0048bbea  64a100000000         mov eax, dword ptr fs:[0]
// 0048bbf0  50                   push eax
// 0048bbf1  51                   push ecx
// 0048bbf2  53                   push ebx
// 0048bbf3  56                   push esi
// 0048bbf4  57                   push edi
// 0048bbf5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048bbfa  33c5                 xor eax, ebp
// 0048bbfc  50                   push eax
// 0048bbfd  8d45f4               lea eax, [ebp - 0xc]
// 0048bc00  64a300000000         mov dword ptr fs:[0], eax
// 0048bc06  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048bc09  8bf1                 mov esi, ecx
// 0048bc0b  6a14                 push 0x14
// 0048bc0d  c70600000000         mov dword ptr [esi], 0
// 0048bc13  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048bc1a  e8d7421a00           call 0x62fef6
// 0048bc1f  83c404               add esp, 4
// 0048bc22  85c0                 test eax, eax
// 0048bc24  7419                 je 0x48bc3f
// 0048bc26  b901000000           mov ecx, 1
// 0048bc2b  894804               mov dword ptr [eax + 4], ecx
// 0048bc2e  894808               mov dword ptr [eax + 8], ecx
// 0048bc31  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0048bc34  c70054b07900         mov dword ptr [eax], 0x79b054
// 0048bc3a  89480c               mov dword ptr [eax + 0xc], ecx
// 0048bc3d  eb02                 jmp 0x48bc41
// 0048bc3f  33c0                 xor eax, eax
// 0048bc41  8906                 mov dword ptr [esi], eax
// 0048bc43  8bc6                 mov eax, esi
// 0048bc45  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048bc48  64890d00000000       mov dword ptr fs:[0], ecx
// 0048bc4f  59                   pop ecx
// 0048bc50  5f                   pop edi
// 0048bc51  5e                   pop esi
// 0048bc52  5b                   pop ebx
// 0048bc53  8be5                 mov esp, ebp
// 0048bc55  5d                   pop ebp
// 0048bc56  c20800               ret 8



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
