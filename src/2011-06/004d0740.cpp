// from server: 100% by Yeetserama
// roc 2011-06 004d0740  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004d0740
//
// 004d0740  6aff                 push -1
// 004d0742  6868449d00           push 0x9d4468
// 004d0747  64a100000000         mov eax, dword ptr fs:[0]
// 004d074d  50                   push eax
// 004d074e  64892500000000       mov dword ptr fs:[0], esp
// 004d0755  83ec08               sub esp, 8
// 004d0758  56                   push esi
// 004d0759  8d442404             lea eax, [esp + 4]
// 004d075d  8bf1                 mov esi, ecx
// 004d075f  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004d0763  50                   push eax
// 004d0764  e8078afcff           call 0x499170
// 004d0769  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004d076d  894c2420             mov dword ptr [esp + 0x20], ecx
// 004d0771  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d0774  8b11                 mov edx, dword ptr [ecx]
// 004d0776  8b520c               mov edx, dword ptr [edx + 0xc]
// 004d0779  8d442420             lea eax, [esp + 0x20]
// 004d077d  50                   push eax
// 004d077e  8b442420             mov eax, dword ptr [esp + 0x20]
// 004d0782  50                   push eax
// 004d0783  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004d078b  ffd2                 call edx
// 004d078d  8b742408             mov esi, dword ptr [esp + 8]
// 004d0791  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004d0799  85f6                 test esi, esi
// 004d079b  742a                 je 0x4d07c7
// 004d079d  8d4604               lea eax, [esi + 4]
// 004d07a0  83c9ff               or ecx, 0xffffffff
// 004d07a3  f00fc108             lock xadd dword ptr [eax], ecx
// 004d07a7  751e                 jne 0x4d07c7
// 004d07a9  8b16                 mov edx, dword ptr [esi]
// 004d07ab  8b4204               mov eax, dword ptr [edx + 4]
// 004d07ae  8bce                 mov ecx, esi
// 004d07b0  ffd0                 call eax
// 004d07b2  8d4e08               lea ecx, [esi + 8]
// 004d07b5  83caff               or edx, 0xffffffff
// 004d07b8  f00fc111             lock xadd dword ptr [ecx], edx
// 004d07bc  7509                 jne 0x4d07c7
// 004d07be  8b06                 mov eax, dword ptr [esi]
// 004d07c0  8b5008               mov edx, dword ptr [eax + 8]
// 004d07c3  8bce                 mov ecx, esi
// 004d07c5  ffd2                 call edx
// 004d07c7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004d07cb  5e                   pop esi
// 004d07cc  64890d00000000       mov dword ptr fs:[0], ecx
// 004d07d3  83c414               add esp, 0x14
// 004d07d6  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX000013@@QAEXPAX0@Z)

namespace ns_ROCX000013 {
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
    void release();
};

inline void Control::release() {
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Shared {
    void* pointer;
    Control* control;
    ~Shared();
};

inline Shared::~Shared() {
    if (control)
        control->release();
}

struct Holder {
    Shared get();
};

struct Property {
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void set(void*, void**);
};

struct S {
    void* vtable;
    Property* property;
    void f(void*, void*);
};

void S::f(void* object, void* value) {
    Shared temporary = static_cast<Holder*>(value)->get();
    value = temporary.pointer;
    property->set(object, &value);
}
}
