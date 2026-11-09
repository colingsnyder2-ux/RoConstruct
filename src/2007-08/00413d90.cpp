// from server: 100% by Yeetserama
// roc 2007-08 00413d90  unit: std::D::DU?$char_traits::V?$basic_string::?$holder  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00413d90
//
// 00413d90  6aff                 push -1
// 00413d92  689ba67300           push 0x73a69b
// 00413d97  64a100000000         mov eax, dword ptr fs:[0]
// 00413d9d  50                   push eax
// 00413d9e  51                   push ecx
// 00413d9f  56                   push esi
// 00413da0  a188518b00           mov eax, dword ptr [0x8b5188]
// 00413da5  33c4                 xor eax, esp
// 00413da7  50                   push eax
// 00413da8  8d44240c             lea eax, [esp + 0xc]
// 00413dac  64a300000000         mov dword ptr fs:[0], eax
// 00413db2  8bf1                 mov esi, ecx
// 00413db4  89742408             mov dword ptr [esp + 8], esi
// 00413db8  8d4e14               lea ecx, [esi + 0x14]
// 00413dbb  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00413dc3  e8b8901500           call 0x56ce80
// 00413dc8  8b7610               mov esi, dword ptr [esi + 0x10]
// 00413dcb  85f6                 test esi, esi
// 00413dcd  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00413dd5  742a                 je 0x413e01
// 00413dd7  8d4604               lea eax, [esi + 4]
// 00413dda  83c9ff               or ecx, 0xffffffff
// 00413ddd  f00fc108             lock xadd dword ptr [eax], ecx
// 00413de1  751e                 jne 0x413e01
// 00413de3  8b16                 mov edx, dword ptr [esi]
// 00413de5  8b4204               mov eax, dword ptr [edx + 4]
// 00413de8  8bce                 mov ecx, esi
// 00413dea  ffd0                 call eax
// 00413dec  8d4e08               lea ecx, [esi + 8]
// 00413def  83caff               or edx, 0xffffffff
// 00413df2  f00fc111             lock xadd dword ptr [ecx], edx
// 00413df6  7509                 jne 0x413e01
// 00413df8  8b06                 mov eax, dword ptr [esi]
// 00413dfa  8b5008               mov edx, dword ptr [eax + 8]
// 00413dfd  8bce                 mov ecx, esi
// 00413dff  ffd2                 call edx
// 00413e01  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00413e05  64890d00000000       mov dword ptr fs:[0], ecx
// 00413e0c  59                   pop ecx
// 00413e0d  5e                   pop esi
// 00413e0e  83c410               add esp, 0x10
// 00413e11  c3                   ret 
// copied from an identical function in another client (function ??1Holder@ns_ROCX00000e@@QAE@XZ)

namespace ns_ROCX00000e {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct SharedCount {
    Control* control;
    ~SharedCount();
};

inline SharedCount::~SharedCount()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Mutex {
    ~Mutex();
};

struct Holder {
    char padding[16];
    SharedCount count;
    Mutex mutex;
    ~Holder();
};

Holder::~Holder()
{
}
}
