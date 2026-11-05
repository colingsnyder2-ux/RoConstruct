// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00589cd0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00589cd0
//
// 00589cd0  6aff                 push -1
// 00589cd2  6856157d00           push 0x7d1556
// 00589cd7  64a100000000         mov eax, dword ptr fs:[0]
// 00589cdd  50                   push eax
// 00589cde  64892500000000       mov dword ptr fs:[0], esp
// 00589ce5  51                   push ecx
// 00589ce6  8b442414             mov eax, dword ptr [esp + 0x14]
// 00589cea  56                   push esi
// 00589ceb  8bf1                 mov esi, ecx
// 00589ced  8b08                 mov ecx, dword ptr [eax]
// 00589cef  890e                 mov dword ptr [esi], ecx
// 00589cf1  8b5004               mov edx, dword ptr [eax + 4]
// 00589cf4  895604               mov dword ptr [esi + 4], edx
// 00589cf7  8b4808               mov ecx, dword ptr [eax + 8]
// 00589cfa  89742404             mov dword ptr [esp + 4], esi
// 00589cfe  894e08               mov dword ptr [esi + 8], ecx
// 00589d01  85c9                 test ecx, ecx
// 00589d03  740c                 je 0x589d11
// 00589d05  83c104               add ecx, 4
// 00589d08  ba01000000           mov edx, 1
// 00589d0d  f00fc111             lock xadd dword ptr [ecx], edx
// 00589d11  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00589d14  894e0c               mov dword ptr [esi + 0xc], ecx
// 00589d17  8b5010               mov edx, dword ptr [eax + 0x10]
// 00589d1a  895610               mov dword ptr [esi + 0x10], edx
// 00589d1d  8b4814               mov ecx, dword ptr [eax + 0x14]
// 00589d20  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00589d28  894e14               mov dword ptr [esi + 0x14], ecx
// 00589d2b  85c9                 test ecx, ecx
// 00589d2d  740c                 je 0x589d3b
// 00589d2f  83c104               add ecx, 4
// 00589d32  ba01000000           mov edx, 1
// 00589d37  f00fc111             lock xadd dword ptr [ecx], edx
// 00589d3b  83c018               add eax, 0x18
// 00589d3e  50                   push eax
// 00589d3f  8d4e18               lea ecx, [esi + 0x18]
// 00589d42  c644241401           mov byte ptr [esp + 0x14], 1
// 00589d47  e8c4f4ffff           call 0x589210
// 00589d4c  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00589d50  8bc6                 mov eax, esi
// 00589d52  5e                   pop esi
// 00589d53  64890d00000000       mov dword ptr fs:[0], ecx
// 00589d5a  83c410               add esp, 0x10
// 00589d5d  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

__forceinline void increment(volatile long* references)
{
    _InterlockedExchangeAdd(references, 1);
}

struct Control {
    long reserved;
    volatile long references;
};

struct Shared {
    void* pointer;
    Control* control;

    Shared(const Shared& other);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        increment(&control->references);
}

struct Tail {
    Tail(const Tail& other);
};

struct S {
    long first;
    Shared firstShared;
    long second;
    Shared secondShared;
    Tail tail;

    S(const S& other);
};

S::S(const S& other)
    : first(other.first),
      firstShared(other.firstShared),
      second(other.second),
      secondShared(other.secondShared),
      tail(other.tail)
{
}
