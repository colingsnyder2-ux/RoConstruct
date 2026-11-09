// from server: 100% by Yeetserama
// roc 2010-06 00769860  unit: seg_00760000  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00769860
//
// 00769860  6aff                 push -1
// 00769862  6898929800           push 0x989298
// 00769867  64a100000000         mov eax, dword ptr fs:[0]
// 0076986d  50                   push eax
// 0076986e  64892500000000       mov dword ptr fs:[0], esp
// 00769875  83ec08               sub esp, 8
// 00769878  57                   push edi
// 00769879  8d442404             lea eax, [esp + 4]
// 0076987d  50                   push eax
// 0076987e  8bf9                 mov edi, ecx
// 00769880  e8cbbbd3ff           call 0x4a5450
// 00769885  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00769889  8b00                 mov eax, dword ptr [eax]
// 0076988b  51                   push ecx
// 0076988c  8bc8                 mov ecx, eax
// 0076988e  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00769896  e80538edff           call 0x63d0a0
// 0076989b  8b442408             mov eax, dword ptr [esp + 8]
// 0076989f  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 007698a7  85c0                 test eax, eax
// 007698a9  742e                 je 0x7698d9
// 007698ab  56                   push esi
// 007698ac  8bf0                 mov esi, eax
// 007698ae  83c004               add eax, 4
// 007698b1  83caff               or edx, 0xffffffff
// 007698b4  f00fc110             lock xadd dword ptr [eax], edx
// 007698b8  751e                 jne 0x7698d8
// 007698ba  8b06                 mov eax, dword ptr [esi]
// 007698bc  8b5004               mov edx, dword ptr [eax + 4]
// 007698bf  8bce                 mov ecx, esi
// 007698c1  ffd2                 call edx
// 007698c3  8d4608               lea eax, [esi + 8]
// 007698c6  83c9ff               or ecx, 0xffffffff
// 007698c9  f00fc108             lock xadd dword ptr [eax], ecx
// 007698cd  7509                 jne 0x7698d8
// 007698cf  8b16                 mov edx, dword ptr [esi]
// 007698d1  8b4208               mov eax, dword ptr [edx + 8]
// 007698d4  8bce                 mov ecx, esi
// 007698d6  ffd0                 call eax
// 007698d8  5e                   pop esi
// 007698d9  8bcf                 mov ecx, edi
// 007698db  e8d0fdffff           call 0x7696b0
// 007698e0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007698e4  5f                   pop edi
// 007698e5  64890d00000000       mov dword ptr fs:[0], ecx
// 007698ec  83c414               add esp, 0x14
// 007698ef  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX00001b@@QAEXH@Z)

namespace ns_ROCX00001b {
// from server: 100% by king_originala
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
