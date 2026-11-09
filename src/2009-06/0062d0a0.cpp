// from server: 100% by EspClaude
// roc 2009-06 0062d0a0  unit: RBX::ArrowTool  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0062d0a0
//
// 0062d0a0  64a100000000         mov eax, dword ptr fs:[0]
// 0062d0a6  6aff                 push -1
// 0062d0a8  6838938500           push 0x859338
// 0062d0ad  50                   push eax
// 0062d0ae  64892500000000       mov dword ptr fs:[0], esp
// 0062d0b5  56                   push esi
// 0062d0b6  8b442414             mov eax, dword ptr [esp + 0x14]
// 0062d0ba  6a00                 push 0
// 0062d0bc  6850f99d00           push 0x9df950
// 0062d0c1  6840be9d00           push 0x9dbe40
// 0062d0c6  6a00                 push 0
// 0062d0c8  50                   push eax
// 0062d0c9  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0062d0d1  8bf0                 mov esi, eax
// 0062d0d3  e8a2cb0e00           call 0x719c7a
// 0062d0d8  83c414               add esp, 0x14
// 0062d0db  85c0                 test eax, eax
// 0062d0dd  7409                 je 0x62d0e8
// 0062d0df  8bc8                 mov ecx, eax
// 0062d0e1  e8aaf10200           call 0x65c290
// 0062d0e6  eb0c                 jmp 0x62d0f4
// 0062d0e8  6870cb6200           push 0x62cb70
// 0062d0ed  8bce                 mov ecx, esi
// 0062d0ef  e8acf1e2ff           call 0x45c2a0
// 0062d0f4  8b742418             mov esi, dword ptr [esp + 0x18]
// 0062d0f8  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 0062d100  85f6                 test esi, esi
// 0062d102  742a                 je 0x62d12e
// 0062d104  8d4604               lea eax, [esi + 4]
// 0062d107  83c9ff               or ecx, 0xffffffff
// 0062d10a  f00fc108             lock xadd dword ptr [eax], ecx
// 0062d10e  751e                 jne 0x62d12e
// 0062d110  8b16                 mov edx, dword ptr [esi]
// 0062d112  8b4204               mov eax, dword ptr [edx + 4]
// 0062d115  8bce                 mov ecx, esi
// 0062d117  ffd0                 call eax
// 0062d119  8d4e08               lea ecx, [esi + 8]
// 0062d11c  83caff               or edx, 0xffffffff
// 0062d11f  f00fc111             lock xadd dword ptr [ecx], edx
// 0062d123  7509                 jne 0x62d12e
// 0062d125  8b06                 mov eax, dword ptr [esi]
// 0062d127  8b5008               mov edx, dword ptr [eax + 8]
// 0062d12a  8bce                 mov ecx, esi
// 0062d12c  ffd2                 call edx
// 0062d12e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0062d132  64890d00000000       mov dword ptr fs:[0], ecx
// 0062d139  5e                   pop esi
// 0062d13a  83c40c               add esp, 0xc
// 0062d13d  c3                   ret 
// copied from an identical function in another client (function ?function_005a2330@ns_ROCX000016@@YAXUShared@1@@Z)

namespace ns_ROCX000016 {
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern char instanceType;
extern char partType;

extern "C" void* __cdecl castObject(void*, long, void*, void*, int);
void __cdecl callback();

struct Instance {
    void fallback(void (__cdecl*)());
};

struct Part {
    void process();
};

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    Instance* pointer;
    Control* control;
    ~Shared();
};

inline Shared::~Shared() {
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

void __cdecl function_005a2330(Shared value) {
    Instance* instance = value.pointer;
    Part* part = static_cast<Part*>(
        castObject(instance, 0, &instanceType, &partType, 0));
    if (part)
        part->process();
    else
        instance->fallback(callback);
}
}
