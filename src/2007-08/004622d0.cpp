// from server: 100% by Yeetserama
// roc 2007-08 004622d0  unit: CSelectionCaption  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004622d0
//
// 004622d0  6aff                 push -1
// 004622d2  68762b7400           push 0x742b76
// 004622d7  64a100000000         mov eax, dword ptr fs:[0]
// 004622dd  50                   push eax
// 004622de  51                   push ecx
// 004622df  56                   push esi
// 004622e0  a188518b00           mov eax, dword ptr [0x8b5188]
// 004622e5  33c4                 xor eax, esp
// 004622e7  50                   push eax
// 004622e8  8d44240c             lea eax, [esp + 0xc]
// 004622ec  64a300000000         mov dword ptr fs:[0], eax
// 004622f2  8bf1                 mov esi, ecx
// 004622f4  89742408             mov dword ptr [esp + 8], esi
// 004622f8  33c9                 xor ecx, ecx
// 004622fa  894c2414             mov dword ptr [esp + 0x14], ecx
// 004622fe  c7061c537900         mov dword ptr [esi], 0x79531c
// 00462304  894e04               mov dword ptr [esi + 4], ecx
// 00462307  894e08               mov dword ptr [esi + 8], ecx
// 0046230a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0046230e  8b542424             mov edx, dword ptr [esp + 0x24]
// 00462312  89460c               mov dword ptr [esi + 0xc], eax
// 00462315  8b442428             mov eax, dword ptr [esp + 0x28]
// 00462319  3bc1                 cmp eax, ecx
// 0046231b  895610               mov dword ptr [esi + 0x10], edx
// 0046231e  894614               mov dword ptr [esi + 0x14], eax
// 00462321  740c                 je 0x46232f
// 00462323  83c004               add eax, 4
// 00462326  ba01000000           mov edx, 1
// 0046232b  f00fc110             lock xadd dword ptr [eax], edx
// 0046232f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00462333  894618               mov dword ptr [esi + 0x18], eax
// 00462336  8b442430             mov eax, dword ptr [esp + 0x30]
// 0046233a  3bc1                 cmp eax, ecx
// 0046233c  89461c               mov dword ptr [esi + 0x1c], eax
// 0046233f  740c                 je 0x46234d
// 00462341  83c004               add eax, 4
// 00462344  b901000000           mov ecx, 1
// 00462349  f00fc108             lock xadd dword ptr [eax], ecx
// 0046234d  8b542420             mov edx, dword ptr [esp + 0x20]
// 00462351  52                   push edx
// 00462352  8bce                 mov ecx, esi
// 00462354  c644241803           mov byte ptr [esp + 0x18], 3
// 00462359  e8f21dffff           call 0x454150
// 0046235e  8d4c2424             lea ecx, [esp + 0x24]
// 00462362  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0046236a  e891b6fbff           call 0x41da00
// 0046236f  8bc6                 mov eax, esi
// 00462371  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00462375  64890d00000000       mov dword ptr fs:[0], ecx
// 0046237c  59                   pop ecx
// 0046237d  5e                   pop esi
// 0046237e  83c410               add esp, 0x10
// 00462381  c21800               ret 0x18
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
