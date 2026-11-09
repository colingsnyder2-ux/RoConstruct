// from server: 100% by Yeetserama
// roc 2010-06 004cad50  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004cad50
//
// 004cad50  64a100000000         mov eax, dword ptr fs:[0]
// 004cad56  6aff                 push -1
// 004cad58  6819d89a00           push 0x9ad819
// 004cad5d  50                   push eax
// 004cad5e  64892500000000       mov dword ptr fs:[0], esp
// 004cad65  56                   push esi
// 004cad66  8bf1                 mov esi, ecx
// 004cad68  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004cad6c  e86fe30d00           call 0x5a90e0
// 004cad71  83ec1c               sub esp, 0x1c
// 004cad74  8bcc                 mov ecx, esp
// 004cad76  8964243c             mov dword ptr [esp + 0x3c], esp
// 004cad7a  50                   push eax
// 004cad7b  ff150ca49e00         call dword ptr [0x9ea40c]
// 004cad81  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004cad85  c744242800000000     mov dword ptr [esp + 0x28], 0
// 004cad8d  e86ef00d00           call 0x5a9e00
// 004cad92  8b10                 mov edx, dword ptr [eax]
// 004cad94  83ec08               sub esp, 8
// 004cad97  8bcc                 mov ecx, esp
// 004cad99  8911                 mov dword ptr [ecx], edx
// 004cad9b  8b4004               mov eax, dword ptr [eax + 4]
// 004cad9e  89642444             mov dword ptr [esp + 0x44], esp
// 004cada2  894104               mov dword ptr [ecx + 4], eax
// 004cada5  85c0                 test eax, eax
// 004cada7  740c                 je 0x4cadb5
// 004cada9  83c004               add eax, 4
// 004cadac  b901000000           mov ecx, 1
// 004cadb1  f00fc108             lock xadd dword ptr [eax], ecx
// 004cadb5  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 004cadb8  034c2438             add ecx, dword ptr [esp + 0x38]
// 004cadbc  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 004cadc4  8b5638               mov edx, dword ptr [esi + 0x38]
// 004cadc7  ffd2                 call edx
// 004cadc9  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004cadcd  64890d00000000       mov dword ptr fs:[0], ecx
// 004cadd4  5e                   pop esi
// 004cadd5  83c40c               add esp, 0xc
// 004cadd8  c21000               ret 0x10
// copied from an identical function in another client (function ?invoke@Descriptor@@QAEXPAUObject@@PAXPAUSource@@2@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)






struct Control {
    void* table;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control) {
        volatile long* count = &control->references;
        _ReadWriteBarrier();
        _InterlockedExchangeAdd(count, 1);
    }
}

struct Source {
    const std::string& getString();
    const Shared& getShared();
};

struct __multiple_inheritance Object;

struct Descriptor {
    unsigned char padding[56];
    void (Object::*method)(Shared, std::string);

    void invoke(Object*, void*, Source*, Source*);
};

void Descriptor::invoke(Object* object, void*, Source* first, Source* second)
{
    (object->*method)(first->getShared(), second->getString());
}