// from server: 100% by Xemicl
// roc 2012-06 00542430  unit: RBX::VObjectValue::?$FactoryProduct::Creator  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00542430
//
// 00542430  6aff                 push -1
// 00542432  68e852ad00           push 0xad52e8
// 00542437  64a100000000         mov eax, dword ptr fs:[0]
// 0054243d  50                   push eax
// 0054243e  64892500000000       mov dword ptr fs:[0], esp
// 00542445  51                   push ecx
// 00542446  56                   push esi
// 00542447  57                   push edi
// 00542448  8bf9                 mov edi, ecx
// 0054244a  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0054244e  83ec08               sub esp, 8
// 00542451  8bc4                 mov eax, esp
// 00542453  8908                 mov dword ptr [eax], ecx
// 00542455  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00542459  895004               mov dword ptr [eax + 4], edx
// 0054245c  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00542460  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00542468  89642410             mov dword ptr [esp + 0x10], esp
// 0054246c  85c0                 test eax, eax
// 0054246e  740c                 je 0x54247c
// 00542470  83c004               add eax, 4
// 00542473  b901000000           mov ecx, 1
// 00542478  f00fc108             lock xadd dword ptr [eax], ecx
// 0054247c  8b542424             mov edx, dword ptr [esp + 0x24]
// 00542480  52                   push edx
// 00542481  8bcf                 mov ecx, edi
// 00542483  e83857efff           call 0x437bc0
// 00542488  8b742424             mov esi, dword ptr [esp + 0x24]
// 0054248c  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00542494  85f6                 test esi, esi
// 00542496  742a                 je 0x5424c2
// 00542498  8d4604               lea eax, [esi + 4]
// 0054249b  83c9ff               or ecx, 0xffffffff
// 0054249e  f00fc108             lock xadd dword ptr [eax], ecx
// 005424a2  751e                 jne 0x5424c2
// 005424a4  8b16                 mov edx, dword ptr [esi]
// 005424a6  8b4204               mov eax, dword ptr [edx + 4]
// 005424a9  8bce                 mov ecx, esi
// 005424ab  ffd0                 call eax
// 005424ad  8d4e08               lea ecx, [esi + 8]
// 005424b0  83caff               or edx, 0xffffffff
// 005424b3  f00fc111             lock xadd dword ptr [ecx], edx
// 005424b7  7509                 jne 0x5424c2
// 005424b9  8b06                 mov eax, dword ptr [esi]
// 005424bb  8b5008               mov edx, dword ptr [eax + 8]
// 005424be  8bce                 mov ecx, esi
// 005424c0  ffd2                 call edx
// 005424c2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005424c6  8bc7                 mov eax, edi
// 005424c8  5f                   pop edi
// 005424c9  64890d00000000       mov dword ptr fs:[0], ecx
// 005424d0  5e                   pop esi
// 005424d1  83c410               add esp, 0x10
// 005424d4  c21000               ret 0x10
// copied from an identical function in another client (function ??0S@ns_ROCX00001e@@QAE@PAXUShared@1@H@Z)

namespace ns_ROCX00001e {
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;

    void weak_release();
};

__forceinline void Control::weak_release()
{
    if (_InterlockedDecrement(&weak) == 0)
        destroy();
}

struct Shared {
    void* pointer;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    Control* p = control;
    if (p) {
        volatile long* count = &p->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        volatile long* count = &p->strong;
        if (_InterlockedDecrement(count) == 0) {
            p->dispose();
            p->weak_release();
        }
    }
}

struct Base {
    Base(void*, Shared);
};

struct S : Base {
    S(void*, Shared, int);
};

S::S(void* owner, Shared object, int)
    : Base(owner, object)
{
}
}
