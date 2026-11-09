// from server: 100% by Yeetserama
// roc 2011-06 00630f20  unit: RBX::Tool  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00630f20
//
// 00630f20  64a100000000         mov eax, dword ptr fs:[0]
// 00630f26  6aff                 push -1
// 00630f28  68585f9d00           push 0x9d5f58
// 00630f2d  50                   push eax
// 00630f2e  64892500000000       mov dword ptr fs:[0], esp
// 00630f35  56                   push esi
// 00630f36  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00630f3e  394c2414             cmp dword ptr [esp + 0x14], ecx
// 00630f42  7405                 je 0x630f49
// 00630f44  e857ffffff           call 0x630ea0
// 00630f49  8b742418             mov esi, dword ptr [esp + 0x18]
// 00630f4d  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 00630f55  85f6                 test esi, esi
// 00630f57  742a                 je 0x630f83
// 00630f59  8d4604               lea eax, [esi + 4]
// 00630f5c  83c9ff               or ecx, 0xffffffff
// 00630f5f  f00fc108             lock xadd dword ptr [eax], ecx
// 00630f63  751e                 jne 0x630f83
// 00630f65  8b16                 mov edx, dword ptr [esi]
// 00630f67  8b4204               mov eax, dword ptr [edx + 4]
// 00630f6a  8bce                 mov ecx, esi
// 00630f6c  ffd0                 call eax
// 00630f6e  8d4e08               lea ecx, [esi + 8]
// 00630f71  83caff               or edx, 0xffffffff
// 00630f74  f00fc111             lock xadd dword ptr [ecx], edx
// 00630f78  7509                 jne 0x630f83
// 00630f7a  8b06                 mov eax, dword ptr [esi]
// 00630f7c  8b5008               mov edx, dword ptr [eax + 8]
// 00630f7f  8bce                 mov ecx, esi
// 00630f81  ffd2                 call edx
// 00630f83  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00630f87  64890d00000000       mov dword ptr fs:[0], ecx
// 00630f8e  5e                   pop esi
// 00630f8f  83c40c               add esp, 0xc
// 00630f92  c20800               ret 8
// copied from an identical function in another client (function ?fn_ROCX000008_005b1110@S@ns_ROCX000008@@QAEXUShared@2@@Z)

namespace ns_ROCX000008 {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct S;

struct Shared {
    S* pointer;
    Control* control;
    ~Shared();
};

struct S {
    void helper();
    void fn_ROCX000008_005b1110(Shared value);
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

void S::fn_ROCX000008_005b1110(Shared value)
{
    if (value.pointer != this)
        helper();
}
}
