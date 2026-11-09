// from server: 100% by colin
// roc 2007-08 004142f0  unit: std::D::DU?$char_traits::V?$basic_string::?$holder  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004142f0
//
// 004142f0  8bc1                 mov eax, ecx
// 004142f2  c70000727800         mov dword ptr [eax], 0x787200
// 004142f8  8b0df8238c00         mov ecx, dword ptr [0x8c23f8]
// 004142fe  894804               mov dword ptr [eax + 4], ecx
// 00414301  8b15fc238c00         mov edx, dword ptr [0x8c23fc]
// 00414307  8bca                 mov ecx, edx
// 00414309  895008               mov dword ptr [eax + 8], edx
// 0041430c  33d2                 xor edx, edx
// 0041430e  3bca                 cmp ecx, edx
// 00414310  740e                 je 0x414320
// 00414312  56                   push esi
// 00414313  83c104               add ecx, 4
// 00414316  be01000000           mov esi, 1
// 0041431b  f00fc131             lock xadd dword ptr [ecx], esi
// 0041431f  5e                   pop esi
// 00414320  89500c               mov dword ptr [eax + 0xc], edx
// 00414323  895010               mov dword ptr [eax + 0x10], edx
// 00414326  895014               mov dword ptr [eax + 0x14], edx
// 00414329  895018               mov dword ptr [eax + 0x18], edx
// 0041432c  89501c               mov dword ptr [eax + 0x1c], edx
// 0041432f  c70008727800         mov dword ptr [eax], 0x787208
// 00414335  895020               mov dword ptr [eax + 0x20], edx
// 00414338  c3                   ret 
// copied from an identical function in another client (function ??0S@@QAE@XZ)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct Counter {
    volatile long value;
    __forceinline void retain();
};

__forceinline void Counter::retain()
{
    volatile long* p = &value;
    _ReadWriteBarrier();
    _InterlockedExchangeAdd(p, 1);
}

struct Ref {
    long reserved;
    Counter count;
    __forceinline void retain();
};

__forceinline void Ref::retain()
{
    count.retain();
}

extern unsigned char initialTable[];
extern unsigned char finalTable[];
extern void* globalObject;
extern Ref* globalReference;

struct S {
    unsigned long tag;
    void* object;
    Ref* reference;
    unsigned long a, b, c, d, e, f;

    S();
};

S::S()
{
    tag = reinterpret_cast<unsigned long>(initialTable);
    object = globalObject;
    reference = globalReference;
    if (reference)
        reference->retain();
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    tag = reinterpret_cast<unsigned long>(finalTable);
    f = 0;
}