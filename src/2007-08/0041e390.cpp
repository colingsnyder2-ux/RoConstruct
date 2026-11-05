// from server: 100% by Yeetserama
// roc 2007-08 0041e390  unit: RBX::VInstance::?$MarshaledListener  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041e390
//
// 0041e390  6aff                 push -1
// 0041e392  68762b7400           push 0x742b76
// 0041e397  64a100000000         mov eax, dword ptr fs:[0]
// 0041e39d  50                   push eax
// 0041e39e  51                   push ecx
// 0041e39f  56                   push esi
// 0041e3a0  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041e3a5  33c4                 xor eax, esp
// 0041e3a7  50                   push eax
// 0041e3a8  8d44240c             lea eax, [esp + 0xc]
// 0041e3ac  64a300000000         mov dword ptr fs:[0], eax
// 0041e3b2  8bf1                 mov esi, ecx
// 0041e3b4  89742408             mov dword ptr [esp + 8], esi
// 0041e3b8  33c9                 xor ecx, ecx
// 0041e3ba  894c2414             mov dword ptr [esp + 0x14], ecx
// 0041e3be  c706887f7800         mov dword ptr [esi], 0x787f88
// 0041e3c4  894e04               mov dword ptr [esi + 4], ecx
// 0041e3c7  894e08               mov dword ptr [esi + 8], ecx
// 0041e3ca  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041e3ce  8b542424             mov edx, dword ptr [esp + 0x24]
// 0041e3d2  89460c               mov dword ptr [esi + 0xc], eax
// 0041e3d5  8b442428             mov eax, dword ptr [esp + 0x28]
// 0041e3d9  3bc1                 cmp eax, ecx
// 0041e3db  895610               mov dword ptr [esi + 0x10], edx
// 0041e3de  894614               mov dword ptr [esi + 0x14], eax
// 0041e3e1  740c                 je 0x41e3ef
// 0041e3e3  83c004               add eax, 4
// 0041e3e6  ba01000000           mov edx, 1
// 0041e3eb  f00fc110             lock xadd dword ptr [eax], edx
// 0041e3ef  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0041e3f3  894618               mov dword ptr [esi + 0x18], eax
// 0041e3f6  8b442430             mov eax, dword ptr [esp + 0x30]
// 0041e3fa  3bc1                 cmp eax, ecx
// 0041e3fc  89461c               mov dword ptr [esi + 0x1c], eax
// 0041e3ff  740c                 je 0x41e40d
// 0041e401  83c004               add eax, 4
// 0041e404  b901000000           mov ecx, 1
// 0041e409  f00fc108             lock xadd dword ptr [eax], ecx
// 0041e40d  8b542420             mov edx, dword ptr [esp + 0x20]
// 0041e411  52                   push edx
// 0041e412  8bce                 mov ecx, esi
// 0041e414  c644241803           mov byte ptr [esp + 0x18], 3
// 0041e419  e8325d0300           call 0x454150
// 0041e41e  8d4c2424             lea ecx, [esp + 0x24]
// 0041e422  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0041e42a  e8d1f5ffff           call 0x41da00
// 0041e42f  8bc6                 mov eax, esi
// 0041e431  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041e435  64890d00000000       mov dword ptr fs:[0], ecx
// 0041e43c  59                   pop ecx
// 0041e43d  5e                   pop esi
// 0041e43e  83c410               add esp, 0x10
// 0041e441  c21800               ret 0x18
// copied from an identical function in another client (function ??0S@ns_ROCX000017@@QAE@PAX0UPair@1@@Z)

namespace ns_ROCX000017 {
// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

__forceinline void increment(volatile long* p)
{
    _InterlockedExchangeAdd(p, 1);
}

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* pointer;
    Control* control;

    __forceinline Shared(const Shared&);
    ~Shared();
};

struct Pair
{
    Shared first;
    Shared second;

    ~Pair();
};

struct Weak
{
    void* pointer;
    Control* control;

    __forceinline Weak();
    ~Weak();
};

struct Base
{
    virtual ~Base();
};

struct S : Base
{
    Weak weak;
    void* pointer;
    Pair arguments;

    S(void*, void*, Pair);
    virtual ~S();
    void set(void*);
};

__forceinline Weak::Weak()
    : pointer(0), control(0)
{
}

__forceinline Shared::Shared(const Shared& value)
    : pointer(value.pointer), control(value.control)
{
    if (control)
        increment(&control->strong);
}

S::S(void* p, void* q, Pair value)
    : weak(), pointer(p), arguments(value)
{
    set(q);
}
}
