// from server: 100% by EspClaude
// roc 2009-06 004cb790  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004cb790
//
// 004cb790  64a100000000         mov eax, dword ptr fs:[0]
// 004cb796  6aff                 push -1
// 004cb798  6899a48500           push 0x85a499
// 004cb79d  50                   push eax
// 004cb79e  64892500000000       mov dword ptr fs:[0], esp
// 004cb7a5  56                   push esi
// 004cb7a6  8bf1                 mov esi, ecx
// 004cb7a8  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004cb7ac  e88fcc1100           call 0x5e8440
// 004cb7b1  83ec1c               sub esp, 0x1c
// 004cb7b4  8bcc                 mov ecx, esp
// 004cb7b6  8964243c             mov dword ptr [esp + 0x3c], esp
// 004cb7ba  50                   push eax
// 004cb7bb  ff15b8e48900         call dword ptr [0x89e4b8]
// 004cb7c1  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004cb7c5  c744242800000000     mov dword ptr [esp + 0x28], 0
// 004cb7cd  e82ed61100           call 0x5e8e00
// 004cb7d2  8b10                 mov edx, dword ptr [eax]
// 004cb7d4  83ec08               sub esp, 8
// 004cb7d7  8bcc                 mov ecx, esp
// 004cb7d9  8911                 mov dword ptr [ecx], edx
// 004cb7db  8b4004               mov eax, dword ptr [eax + 4]
// 004cb7de  89642444             mov dword ptr [esp + 0x44], esp
// 004cb7e2  894104               mov dword ptr [ecx + 4], eax
// 004cb7e5  85c0                 test eax, eax
// 004cb7e7  740c                 je 0x4cb7f5
// 004cb7e9  83c004               add eax, 4
// 004cb7ec  b901000000           mov ecx, 1
// 004cb7f1  f00fc108             lock xadd dword ptr [eax], ecx
// 004cb7f5  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 004cb7f8  034c2438             add ecx, dword ptr [esp + 0x38]
// 004cb7fc  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 004cb804  8b5638               mov edx, dword ptr [esi + 0x38]
// 004cb807  ffd2                 call edx
// 004cb809  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004cb80d  64890d00000000       mov dword ptr fs:[0], ecx
// 004cb814  5e                   pop esi
// 004cb815  83c40c               add esp, 0xc
// 004cb818  c21000               ret 0x10
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