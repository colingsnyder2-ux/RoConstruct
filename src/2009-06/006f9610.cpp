// from server: 100% by EspClaude
// roc 2009-06 006f9610  unit: RBX::GroupDragTool  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006f9610
//
// 006f9610  6aff                 push -1
// 006f9612  68e8a68600           push 0x86a6e8
// 006f9617  64a100000000         mov eax, dword ptr fs:[0]
// 006f961d  50                   push eax
// 006f961e  64892500000000       mov dword ptr fs:[0], esp
// 006f9625  83ec08               sub esp, 8
// 006f9628  57                   push edi
// 006f9629  8d442404             lea eax, [esp + 4]
// 006f962d  50                   push eax
// 006f962e  8bf9                 mov edi, ecx
// 006f9630  e8fb04f0ff           call 0x5f9b30
// 006f9635  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006f9639  8b00                 mov eax, dword ptr [eax]
// 006f963b  51                   push ecx
// 006f963c  8bc8                 mov ecx, eax
// 006f963e  c744241800000000     mov dword ptr [esp + 0x18], 0
// 006f9646  e8a576f6ff           call 0x660cf0
// 006f964b  8b442408             mov eax, dword ptr [esp + 8]
// 006f964f  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 006f9657  85c0                 test eax, eax
// 006f9659  742e                 je 0x6f9689
// 006f965b  56                   push esi
// 006f965c  8bf0                 mov esi, eax
// 006f965e  83c004               add eax, 4
// 006f9661  83caff               or edx, 0xffffffff
// 006f9664  f00fc110             lock xadd dword ptr [eax], edx
// 006f9668  751e                 jne 0x6f9688
// 006f966a  8b06                 mov eax, dword ptr [esi]
// 006f966c  8b5004               mov edx, dword ptr [eax + 4]
// 006f966f  8bce                 mov ecx, esi
// 006f9671  ffd2                 call edx
// 006f9673  8d4608               lea eax, [esi + 8]
// 006f9676  83c9ff               or ecx, 0xffffffff
// 006f9679  f00fc108             lock xadd dword ptr [eax], ecx
// 006f967d  7509                 jne 0x6f9688
// 006f967f  8b16                 mov edx, dword ptr [esi]
// 006f9681  8b4208               mov eax, dword ptr [edx + 8]
// 006f9684  8bce                 mov ecx, esi
// 006f9686  ffd0                 call eax
// 006f9688  5e                   pop esi
// 006f9689  8bcf                 mov ecx, edi
// 006f968b  e8f0fdffff           call 0x6f9480
// 006f9690  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006f9694  5f                   pop edi
// 006f9695  64890d00000000       mov dword ptr fs:[0], ecx
// 006f969c  83c414               add esp, 0x14
// 006f969f  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000003@@QAEXH@Z)

namespace ns_ROCX000003 {
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct ControlBlock {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

struct Service {
    void apply(int value);
};

struct ServicePtr {
    Service* pointer;
    ControlBlock* control;
    ~ServicePtr();
    Service* operator->() const;
};

struct S {
    ServicePtr getService();
    void finish();
    void f(int value);
};

__forceinline void ControlBlock::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

__forceinline Service* ServicePtr::operator->() const
{
    return pointer;
}

__forceinline ServicePtr::~ServicePtr()
{
    if (control)
        control->release();
}

void S::f(int value)
{
    getService()->apply(value);
    finish();
}
}
