// from server: 100% by Yeetserama
// roc 2010-06 005f9b80  unit: RBX::Tool  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005f9b80
//
// 005f9b80  64a100000000         mov eax, dword ptr fs:[0]
// 005f9b86  6aff                 push -1
// 005f9b88  68a8859a00           push 0x9a85a8
// 005f9b8d  50                   push eax
// 005f9b8e  64892500000000       mov dword ptr fs:[0], esp
// 005f9b95  56                   push esi
// 005f9b96  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 005f9b9e  394c2414             cmp dword ptr [esp + 0x14], ecx
// 005f9ba2  7405                 je 0x5f9ba9
// 005f9ba4  e857ffffff           call 0x5f9b00
// 005f9ba9  8b742418             mov esi, dword ptr [esp + 0x18]
// 005f9bad  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 005f9bb5  85f6                 test esi, esi
// 005f9bb7  742a                 je 0x5f9be3
// 005f9bb9  8d4604               lea eax, [esi + 4]
// 005f9bbc  83c9ff               or ecx, 0xffffffff
// 005f9bbf  f00fc108             lock xadd dword ptr [eax], ecx
// 005f9bc3  751e                 jne 0x5f9be3
// 005f9bc5  8b16                 mov edx, dword ptr [esi]
// 005f9bc7  8b4204               mov eax, dword ptr [edx + 4]
// 005f9bca  8bce                 mov ecx, esi
// 005f9bcc  ffd0                 call eax
// 005f9bce  8d4e08               lea ecx, [esi + 8]
// 005f9bd1  83caff               or edx, 0xffffffff
// 005f9bd4  f00fc111             lock xadd dword ptr [ecx], edx
// 005f9bd8  7509                 jne 0x5f9be3
// 005f9bda  8b06                 mov eax, dword ptr [esi]
// 005f9bdc  8b5008               mov edx, dword ptr [eax + 8]
// 005f9bdf  8bce                 mov ecx, esi
// 005f9be1  ffd2                 call edx
// 005f9be3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005f9be7  64890d00000000       mov dword ptr fs:[0], ecx
// 005f9bee  5e                   pop esi
// 005f9bef  83c40c               add esp, 0xc
// 005f9bf2  c20800               ret 8
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
