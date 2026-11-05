// from server: 100% by Yeetserama
// roc 2010-06 00461a70  unit: CRobloxReportView::CStatsItemRecord::CNameItem  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00461a70
//
// 00461a70  6aff                 push -1
// 00461a72  6813369800           push 0x983613
// 00461a77  64a100000000         mov eax, dword ptr fs:[0]
// 00461a7d  50                   push eax
// 00461a7e  64892500000000       mov dword ptr fs:[0], esp
// 00461a85  83ec08               sub esp, 8
// 00461a88  56                   push esi
// 00461a89  8bf1                 mov esi, ecx
// 00461a8b  57                   push edi
// 00461a8c  89742408             mov dword ptr [esp + 8], esi
// 00461a90  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00461a94  83ec08               sub esp, 8
// 00461a97  8bc4                 mov eax, esp
// 00461a99  8908                 mov dword ptr [eax], ecx
// 00461a9b  8b542430             mov edx, dword ptr [esp + 0x30]
// 00461a9f  895004               mov dword ptr [eax + 4], edx
// 00461aa2  8b442430             mov eax, dword ptr [esp + 0x30]
// 00461aa6  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00461aae  89642414             mov dword ptr [esp + 0x14], esp
// 00461ab2  85c0                 test eax, eax
// 00461ab4  740c                 je 0x461ac2
// 00461ab6  83c004               add eax, 4
// 00461ab9  b901000000           mov ecx, 1
// 00461abe  f00fc108             lock xadd dword ptr [eax], ecx
// 00461ac2  8d4e7c               lea ecx, [esi + 0x7c]
// 00461ac5  e8761b2c00           call 0x723640
// 00461aca  8bce                 mov ecx, esi
// 00461acc  c644241801           mov byte ptr [esp + 0x18], 1
// 00461ad1  e8cacd3600           call 0x7ce8a0
// 00461ad6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00461ada  8b542420             mov edx, dword ptr [esp + 0x20]
// 00461ade  c706cce5a000         mov dword ptr [esi], 0xa0e5cc
// 00461ae4  899684000000         mov dword ptr [esi + 0x84], edx
// 00461aea  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00461af2  85ff                 test edi, edi
// 00461af4  742a                 je 0x461b20
// 00461af6  8d4704               lea eax, [edi + 4]
// 00461af9  83c9ff               or ecx, 0xffffffff
// 00461afc  f00fc108             lock xadd dword ptr [eax], ecx
// 00461b00  751e                 jne 0x461b20
// 00461b02  8b17                 mov edx, dword ptr [edi]
// 00461b04  8b4204               mov eax, dword ptr [edx + 4]
// 00461b07  8bcf                 mov ecx, edi
// 00461b09  ffd0                 call eax
// 00461b0b  8d4f08               lea ecx, [edi + 8]
// 00461b0e  83caff               or edx, 0xffffffff
// 00461b11  f00fc111             lock xadd dword ptr [ecx], edx
// 00461b15  7509                 jne 0x461b20
// 00461b17  8b07                 mov eax, dword ptr [edi]
// 00461b19  8b5008               mov edx, dword ptr [eax + 8]
// 00461b1c  8bcf                 mov ecx, edi
// 00461b1e  ffd2                 call edx
// 00461b20  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00461b24  5f                   pop edi
// 00461b25  8bc6                 mov eax, esi
// 00461b27  64890d00000000       mov dword ptr fs:[0], ecx
// 00461b2e  5e                   pop esi
// 00461b2f  83c414               add esp, 0x14
// 00461b32  c20c00               ret 0xc
// copied from an identical function in another client (function ??0CRobloxReportDocView@ns_ROCX000014@@QAE@HUShared@1@@Z)

namespace ns_ROCX000014 {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* object;
    Control* control;

    Shared(const Shared& other)
        : object(other.object), control(other.control)
    {
        if (control)
            _InterlockedIncrement(&control->strong);
    }

    ~Shared()
    {
        Control* p = control;
        if (p && _InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
};

struct Holder
{
    Shared value;
    Holder(Shared);
    ~Holder();
};

struct Base
{
    virtual void method();
    char storage[120];
    Base();
};

struct CRobloxReportDocView : Holder, Base
{
    int value;
    CRobloxReportDocView(int, Shared);
};

CRobloxReportDocView::CRobloxReportDocView(int n, Shared p)
    : Holder(p), Base(), value(n)
{
}
}
