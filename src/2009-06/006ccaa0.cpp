// from server: 100% by EspClaude
// roc 2009-06 006ccaa0  unit: RBX::GameTool  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006ccaa0
//
// 006ccaa0  64a100000000         mov eax, dword ptr fs:[0]
// 006ccaa6  6aff                 push -1
// 006ccaa8  6838938500           push 0x859338
// 006ccaad  50                   push eax
// 006ccaae  64892500000000       mov dword ptr fs:[0], esp
// 006ccab5  56                   push esi
// 006ccab6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006ccaba  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006ccabe  50                   push eax
// 006ccabf  51                   push ecx
// 006ccac0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 006ccac8  e87379feff           call 0x6b4440
// 006ccacd  8b742420             mov esi, dword ptr [esp + 0x20]
// 006ccad1  83c408               add esp, 8
// 006ccad4  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 006ccadc  85f6                 test esi, esi
// 006ccade  742a                 je 0x6ccb0a
// 006ccae0  8d5604               lea edx, [esi + 4]
// 006ccae3  83c8ff               or eax, 0xffffffff
// 006ccae6  f00fc102             lock xadd dword ptr [edx], eax
// 006ccaea  751e                 jne 0x6ccb0a
// 006ccaec  8b16                 mov edx, dword ptr [esi]
// 006ccaee  8b4204               mov eax, dword ptr [edx + 4]
// 006ccaf1  8bce                 mov ecx, esi
// 006ccaf3  ffd0                 call eax
// 006ccaf5  8d4e08               lea ecx, [esi + 8]
// 006ccaf8  83caff               or edx, 0xffffffff
// 006ccafb  f00fc111             lock xadd dword ptr [ecx], edx
// 006ccaff  7509                 jne 0x6ccb0a
// 006ccb01  8b06                 mov eax, dword ptr [esi]
// 006ccb03  8b5008               mov edx, dword ptr [eax + 8]
// 006ccb06  8bce                 mov ecx, esi
// 006ccb08  ffd2                 call edx
// 006ccb0a  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006ccb0e  64890d00000000       mov dword ptr fs:[0], ecx
// 006ccb15  5e                   pop esi
// 006ccb16  83c40c               add esp, 0xc
// 006ccb19  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX00000d_006404c0@ns_ROCX00000d@@YAXUShared@1@PAX@Z)

namespace ns_ROCX00000d {
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
};

struct Shared {
    void* object;
    Control* control;
    ~Shared();
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

extern void __cdecl helper(void*, void*);

void __cdecl fn_ROCX00000d_006404c0(Shared value, void* argument)
{
    helper(value.object, argument);
}
}
