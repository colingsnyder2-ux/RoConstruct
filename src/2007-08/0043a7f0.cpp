// from server: 100% by Yeetserama
// roc 2007-08 0043a7f0  unit: IIHAAH::?$CMap  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043a7f0
//
// 0043a7f0  56                   push esi
// 0043a7f1  8b742410             mov esi, dword ptr [esp + 0x10]
// 0043a7f5  57                   push edi
// 0043a7f6  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0043a7fa  3bf7                 cmp esi, edi
// 0043a7fc  743a                 je 0x43a838
// 0043a7fe  8bff                 mov edi, edi
// 0043a800  8b06                 mov eax, dword ptr [esi]
// 0043a802  83ec08               sub esp, 8
// 0043a805  8bcc                 mov ecx, esp
// 0043a807  8901                 mov dword ptr [ecx], eax
// 0043a809  8b4604               mov eax, dword ptr [esi + 4]
// 0043a80c  85c0                 test eax, eax
// 0043a80e  89642418             mov dword ptr [esp + 0x18], esp
// 0043a812  894104               mov dword ptr [ecx + 4], eax
// 0043a815  740c                 je 0x43a823
// 0043a817  83c004               add eax, 4
// 0043a81a  b901000000           mov ecx, 1
// 0043a81f  f00fc108             lock xadd dword ptr [eax], ecx
// 0043a823  8d542430             lea edx, [esp + 0x30]
// 0043a827  52                   push edx
// 0043a828  8d4c242c             lea ecx, [esp + 0x2c]
// 0043a82c  e8bff0ffff           call 0x4398f0
// 0043a831  83c608               add esi, 8
// 0043a834  3bf7                 cmp esi, edi
// 0043a836  75c8                 jne 0x43a800
// 0043a838  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0043a83c  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0043a840  8b542424             mov edx, dword ptr [esp + 0x24]
// 0043a844  8908                 mov dword ptr [eax], ecx
// 0043a846  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0043a84a  895004               mov dword ptr [eax + 4], edx
// 0043a84d  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0043a851  5f                   pop edi
// 0043a852  894808               mov dword ptr [eax + 8], ecx
// 0043a855  89500c               mov dword ptr [eax + 0xc], edx
// 0043a858  5e                   pop esi
// 0043a859  c3                   ret 
// copied from an identical function in another client (function ?apply@ns_ROCX000008@@YA?AUFunctor@1@UIterator@1@0U21@@Z)

namespace ns_ROCX000008 {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct Control {
    int unused;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;

    Shared(const Shared& other);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control) {
        volatile long* references = &control->references;
        _ReadWriteBarrier();
        _InterlockedExchangeAdd(references, 1);
    }
}

struct Iterator {
    void* unused;
    Shared* current;
};

struct Functor {
    int first;
    int second;
    int third;
    int fourth;

    void invoke(int*, Shared);
};

Functor apply(Iterator first, Iterator last, Functor function)
{
    Shared* current = first.current;
    Shared* end = last.current;
    for (; current != end; ++current)
        function.invoke(&function.third, *current);
    return function;
}
}
