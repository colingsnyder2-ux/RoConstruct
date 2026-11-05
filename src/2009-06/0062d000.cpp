// from server: 100% by EspClaude
// roc 2009-06 0062d000  unit: RBX::ArrowTool  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0062d000
//
// 0062d000  64a100000000         mov eax, dword ptr fs:[0]
// 0062d006  6aff                 push -1
// 0062d008  6838938500           push 0x859338
// 0062d00d  50                   push eax
// 0062d00e  64892500000000       mov dword ptr fs:[0], esp
// 0062d015  56                   push esi
// 0062d016  8b442414             mov eax, dword ptr [esp + 0x14]
// 0062d01a  6a00                 push 0
// 0062d01c  6850f99d00           push 0x9df950
// 0062d021  6840be9d00           push 0x9dbe40
// 0062d026  6a00                 push 0
// 0062d028  50                   push eax
// 0062d029  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0062d031  8bf0                 mov esi, eax
// 0062d033  e842cc0e00           call 0x719c7a
// 0062d038  83c414               add esp, 0x14
// 0062d03b  85c0                 test eax, eax
// 0062d03d  7409                 je 0x62d048
// 0062d03f  8bc8                 mov ecx, eax
// 0062d041  e86af20200           call 0x65c2b0
// 0062d046  eb0c                 jmp 0x62d054
// 0062d048  6830cb6200           push 0x62cb30
// 0062d04d  8bce                 mov ecx, esi
// 0062d04f  e84cf2e2ff           call 0x45c2a0
// 0062d054  8b742418             mov esi, dword ptr [esp + 0x18]
// 0062d058  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 0062d060  85f6                 test esi, esi
// 0062d062  742a                 je 0x62d08e
// 0062d064  8d4604               lea eax, [esi + 4]
// 0062d067  83c9ff               or ecx, 0xffffffff
// 0062d06a  f00fc108             lock xadd dword ptr [eax], ecx
// 0062d06e  751e                 jne 0x62d08e
// 0062d070  8b16                 mov edx, dword ptr [esi]
// 0062d072  8b4204               mov eax, dword ptr [edx + 4]
// 0062d075  8bce                 mov ecx, esi
// 0062d077  ffd0                 call eax
// 0062d079  8d4e08               lea ecx, [esi + 8]
// 0062d07c  83caff               or edx, 0xffffffff
// 0062d07f  f00fc111             lock xadd dword ptr [ecx], edx
// 0062d083  7509                 jne 0x62d08e
// 0062d085  8b06                 mov eax, dword ptr [esi]
// 0062d087  8b5008               mov edx, dword ptr [eax + 8]
// 0062d08a  8bce                 mov ecx, esi
// 0062d08c  ffd2                 call edx
// 0062d08e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0062d092  64890d00000000       mov dword ptr fs:[0], ecx
// 0062d099  5e                   pop esi
// 0062d09a  83c40c               add esp, 0xc
// 0062d09d  c3                   ret 
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
