// from server: 100% by Yeetserama
// roc 2011-06 00731c70  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00731c70
//
// 00731c70  6aff                 push -1
// 00731c72  6868449d00           push 0x9d4468
// 00731c77  64a100000000         mov eax, dword ptr fs:[0]
// 00731c7d  50                   push eax
// 00731c7e  64892500000000       mov dword ptr fs:[0], esp
// 00731c85  83ec08               sub esp, 8
// 00731c88  56                   push esi
// 00731c89  8d442404             lea eax, [esp + 4]
// 00731c8d  8bf1                 mov esi, ecx
// 00731c8f  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00731c93  50                   push eax
// 00731c94  e8d7c5d7ff           call 0x4ae270
// 00731c99  8b442404             mov eax, dword ptr [esp + 4]
// 00731c9d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00731ca1  8b16                 mov edx, dword ptr [esi]
// 00731ca3  8b5234               mov edx, dword ptr [edx + 0x34]
// 00731ca6  50                   push eax
// 00731ca7  51                   push ecx
// 00731ca8  8bce                 mov ecx, esi
// 00731caa  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00731cb2  ffd2                 call edx
// 00731cb4  8b742408             mov esi, dword ptr [esp + 8]
// 00731cb8  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00731cc0  85f6                 test esi, esi
// 00731cc2  742a                 je 0x731cee
// 00731cc4  8d4604               lea eax, [esi + 4]
// 00731cc7  83c9ff               or ecx, 0xffffffff
// 00731cca  f00fc108             lock xadd dword ptr [eax], ecx
// 00731cce  751e                 jne 0x731cee
// 00731cd0  8b16                 mov edx, dword ptr [esi]
// 00731cd2  8b4204               mov eax, dword ptr [edx + 4]
// 00731cd5  8bce                 mov ecx, esi
// 00731cd7  ffd0                 call eax
// 00731cd9  8d4e08               lea ecx, [esi + 8]
// 00731cdc  83caff               or edx, 0xffffffff
// 00731cdf  f00fc111             lock xadd dword ptr [ecx], edx
// 00731ce3  7509                 jne 0x731cee
// 00731ce5  8b06                 mov eax, dword ptr [esi]
// 00731ce7  8b5008               mov edx, dword ptr [eax + 8]
// 00731cea  8bce                 mov ecx, esi
// 00731cec  ffd2                 call edx
// 00731cee  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00731cf2  5e                   pop esi
// 00731cf3  64890d00000000       mov dword ptr fs:[0], ecx
// 00731cfa  83c414               add esp, 0x14
// 00731cfd  c20800               ret 8
// copied from an identical function in another client (function ?f@Descriptor@ns_ROCX000016@@QAEXPAXPAUSource@2@@Z)

namespace ns_ROCX000016 {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;

    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Pair
{
    void* object;
    Control* control;
    ~Pair();
};

inline Pair::~Pair()
{
    if (control)
        control->release();
}

struct Source
{
    Pair get();
};

struct Descriptor
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void set(void*, void*);

    void f(void*, Source*);
};

void Descriptor::f(void* instance, Source* source)
{
    Pair value = source->get();
    set(instance, value.object);
}
}
