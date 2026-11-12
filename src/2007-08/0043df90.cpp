// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 0043df90  unit: RBX::VSoundService::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043df90
//
// 0043df90  55                   push ebp
// 0043df91  8bec                 mov ebp, esp
// 0043df93  6aff                 push -1
// 0043df95  6840ec7300           push 0x73ec40
// 0043df9a  64a100000000         mov eax, dword ptr fs:[0]
// 0043dfa0  50                   push eax
// 0043dfa1  51                   push ecx
// 0043dfa2  53                   push ebx
// 0043dfa3  56                   push esi
// 0043dfa4  57                   push edi
// 0043dfa5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043dfaa  33c5                 xor eax, ebp
// 0043dfac  50                   push eax
// 0043dfad  8d45f4               lea eax, [ebp - 0xc]
// 0043dfb0  64a300000000         mov dword ptr fs:[0], eax
// 0043dfb6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0043dfb9  8bf1                 mov esi, ecx
// 0043dfbb  6a14                 push 0x14
// 0043dfbd  c70600000000         mov dword ptr [esi], 0
// 0043dfc3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0043dfca  e8271f1f00           call 0x62fef6
// 0043dfcf  83c404               add esp, 4
// 0043dfd2  85c0                 test eax, eax
// 0043dfd4  7419                 je 0x43dfef
// 0043dfd6  b901000000           mov ecx, 1
// 0043dfdb  894804               mov dword ptr [eax + 4], ecx
// 0043dfde  894808               mov dword ptr [eax + 8], ecx
// 0043dfe1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0043dfe4  c700d4e37800         mov dword ptr [eax], 0x78e3d4
// 0043dfea  89480c               mov dword ptr [eax + 0xc], ecx
// 0043dfed  eb02                 jmp 0x43dff1
// 0043dfef  33c0                 xor eax, eax
// 0043dff1  8906                 mov dword ptr [esi], eax
// 0043dff3  8bc6                 mov eax, esi
// 0043dff5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0043dff8  64890d00000000       mov dword ptr fs:[0], ecx
// 0043dfff  59                   pop ecx
// 0043e000  5f                   pop edi
// 0043e001  5e                   pop esi
// 0043e002  5b                   pop ebx
// 0043e003  8be5                 mov esp, ebp
// 0043e005  5d                   pop ebp
// 0043e006  c20800               ret 8



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
