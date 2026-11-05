// from server: 92% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00440840  unit: RBX::Soundscape::VSoundId::?$ContentItem  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00440840
//
// 00440840  55                   push ebp
// 00440841  8bec                 mov ebp, esp
// 00440843  6aff                 push -1
// 00440845  68300a7c00           push 0x7c0a30
// 0044084a  64a100000000         mov eax, dword ptr fs:[0]
// 00440850  50                   push eax
// 00440851  64892500000000       mov dword ptr fs:[0], esp
// 00440858  51                   push ecx
// 00440859  53                   push ebx
// 0044085a  56                   push esi
// 0044085b  57                   push edi
// 0044085c  8965f0               mov dword ptr [ebp - 0x10], esp
// 0044085f  8bf1                 mov esi, ecx
// 00440861  6a14                 push 0x14
// 00440863  c70600000000         mov dword ptr [esi], 0
// 00440869  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00440870  e8ab002600           call 0x6a0920
// 00440875  83c404               add esp, 4
// 00440878  85c0                 test eax, eax
// 0044087a  7419                 je 0x440895
// 0044087c  b901000000           mov ecx, 1
// 00440881  894804               mov dword ptr [eax + 4], ecx
// 00440884  894808               mov dword ptr [eax + 8], ecx
// 00440887  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0044088a  c7001c538100         mov dword ptr [eax], 0x81531c
// 00440890  89480c               mov dword ptr [eax + 0xc], ecx
// 00440893  eb02                 jmp 0x440897
// 00440895  33c0                 xor eax, eax
// 00440897  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0044089a  8906                 mov dword ptr [esi], eax
// 0044089c  5f                   pop edi
// 0044089d  8bc6                 mov eax, esi
// 0044089f  5e                   pop esi
// 004408a0  64890d00000000       mov dword ptr fs:[0], ecx
// 004408a7  5b                   pop ebx
// 004408a8  8be5                 mov esp, ebp
// 004408aa  5d                   pop ebp
// 004408ab  c20800               ret 8

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
