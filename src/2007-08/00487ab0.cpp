// from server: 92% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 0048ac30  unit: RBX::Network::P8Player::?$GetSetImpl  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048ac30
//
// 0048ac30  55                   push ebp
// 0048ac31  8bec                 mov ebp, esp
// 0048ac33  6aff                 push -1
// 0048ac35  68e0607c00           push 0x7c60e0
// 0048ac3a  64a100000000         mov eax, dword ptr fs:[0]
// 0048ac40  50                   push eax
// 0048ac41  64892500000000       mov dword ptr fs:[0], esp
// 0048ac48  51                   push ecx
// 0048ac49  53                   push ebx
// 0048ac4a  56                   push esi
// 0048ac4b  57                   push edi
// 0048ac4c  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048ac4f  8bf1                 mov esi, ecx
// 0048ac51  6a14                 push 0x14
// 0048ac53  c70600000000         mov dword ptr [esi], 0
// 0048ac59  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048ac60  e8bb5c2100           call 0x6a0920
// 0048ac65  83c404               add esp, 4
// 0048ac68  85c0                 test eax, eax
// 0048ac6a  7419                 je 0x48ac85
// 0048ac6c  b901000000           mov ecx, 1
// 0048ac71  894804               mov dword ptr [eax + 4], ecx
// 0048ac74  894808               mov dword ptr [eax + 8], ecx
// 0048ac77  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0048ac7a  c7009c158200         mov dword ptr [eax], 0x82159c
// 0048ac80  89480c               mov dword ptr [eax + 0xc], ecx
// 0048ac83  eb02                 jmp 0x48ac87
// 0048ac85  33c0                 xor eax, eax
// 0048ac87  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048ac8a  8906                 mov dword ptr [esi], eax
// 0048ac8c  5f                   pop edi
// 0048ac8d  8bc6                 mov eax, esi
// 0048ac8f  5e                   pop esi
// 0048ac90  64890d00000000       mov dword ptr fs:[0], ecx
// 0048ac97  5b                   pop ebx
// 0048ac98  8be5                 mov esp, ebp
// 0048ac9a  5d                   pop ebp
// 0048ac9b  c20800               ret 8

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
