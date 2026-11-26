// from server: 100% by Xemicl
// roc 2012-06 00813030  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00813030
//
// 00813030  6aff                 push -1
// 00813032  6808c8ac00           push 0xacc808
// 00813037  64a100000000         mov eax, dword ptr fs:[0]
// 0081303d  50                   push eax
// 0081303e  64892500000000       mov dword ptr fs:[0], esp
// 00813045  83ec08               sub esp, 8
// 00813048  56                   push esi
// 00813049  8d442404             lea eax, [esp + 4]
// 0081304d  8bf1                 mov esi, ecx
// 0081304f  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00813053  50                   push eax
// 00813054  e81790d1ff           call 0x52c070
// 00813059  8b442404             mov eax, dword ptr [esp + 4]
// 0081305d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00813061  8b16                 mov edx, dword ptr [esi]
// 00813063  8b5234               mov edx, dword ptr [edx + 0x34]
// 00813066  50                   push eax
// 00813067  51                   push ecx
// 00813068  8bce                 mov ecx, esi
// 0081306a  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00813072  ffd2                 call edx
// 00813074  8b742408             mov esi, dword ptr [esp + 8]
// 00813078  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00813080  85f6                 test esi, esi
// 00813082  742a                 je 0x8130ae
// 00813084  8d4604               lea eax, [esi + 4]
// 00813087  83c9ff               or ecx, 0xffffffff
// 0081308a  f00fc108             lock xadd dword ptr [eax], ecx
// 0081308e  751e                 jne 0x8130ae
// 00813090  8b16                 mov edx, dword ptr [esi]
// 00813092  8b4204               mov eax, dword ptr [edx + 4]
// 00813095  8bce                 mov ecx, esi
// 00813097  ffd0                 call eax
// 00813099  8d4e08               lea ecx, [esi + 8]
// 0081309c  83caff               or edx, 0xffffffff
// 0081309f  f00fc111             lock xadd dword ptr [ecx], edx
// 008130a3  7509                 jne 0x8130ae
// 008130a5  8b06                 mov eax, dword ptr [esi]
// 008130a7  8b5008               mov edx, dword ptr [eax + 8]
// 008130aa  8bce                 mov ecx, esi
// 008130ac  ffd2                 call edx
// 008130ae  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008130b2  5e                   pop esi
// 008130b3  64890d00000000       mov dword ptr fs:[0], ecx
// 008130ba  83c414               add esp, 0x14
// 008130bd  c20800               ret 8
// copied from an identical function in another client (function ?f@Descriptor@ns_ROCX000007@@QAEXPAXPAUSource@2@@Z)

namespace ns_ROCX000007 {
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
