// from server: 100% by Yeetserama
// roc 2010-06 00461870  unit: CRobloxReportDocView  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00461870
//
// 00461870  6aff                 push -1
// 00461872  6813369800           push 0x983613
// 00461877  64a100000000         mov eax, dword ptr fs:[0]
// 0046187d  50                   push eax
// 0046187e  64892500000000       mov dword ptr fs:[0], esp
// 00461885  83ec08               sub esp, 8
// 00461888  56                   push esi
// 00461889  8bf1                 mov esi, ecx
// 0046188b  57                   push edi
// 0046188c  89742408             mov dword ptr [esp + 8], esi
// 00461890  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00461894  83ec08               sub esp, 8
// 00461897  8bc4                 mov eax, esp
// 00461899  8908                 mov dword ptr [eax], ecx
// 0046189b  8b542430             mov edx, dword ptr [esp + 0x30]
// 0046189f  895004               mov dword ptr [eax + 4], edx
// 004618a2  8b442430             mov eax, dword ptr [esp + 0x30]
// 004618a6  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004618ae  89642414             mov dword ptr [esp + 0x14], esp
// 004618b2  85c0                 test eax, eax
// 004618b4  740c                 je 0x4618c2
// 004618b6  83c004               add eax, 4
// 004618b9  b901000000           mov ecx, 1
// 004618be  f00fc108             lock xadd dword ptr [eax], ecx
// 004618c2  8d4e7c               lea ecx, [esi + 0x7c]
// 004618c5  e8761d2c00           call 0x723640
// 004618ca  8bce                 mov ecx, esi
// 004618cc  c644241801           mov byte ptr [esp + 0x18], 1
// 004618d1  e8cacf3600           call 0x7ce8a0
// 004618d6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004618da  8b542420             mov edx, dword ptr [esp + 0x20]
// 004618de  c7067ce4a000         mov dword ptr [esi], 0xa0e47c
// 004618e4  899684000000         mov dword ptr [esi + 0x84], edx
// 004618ea  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004618f2  85ff                 test edi, edi
// 004618f4  742a                 je 0x461920
// 004618f6  8d4704               lea eax, [edi + 4]
// 004618f9  83c9ff               or ecx, 0xffffffff
// 004618fc  f00fc108             lock xadd dword ptr [eax], ecx
// 00461900  751e                 jne 0x461920
// 00461902  8b17                 mov edx, dword ptr [edi]
// 00461904  8b4204               mov eax, dword ptr [edx + 4]
// 00461907  8bcf                 mov ecx, edi
// 00461909  ffd0                 call eax
// 0046190b  8d4f08               lea ecx, [edi + 8]
// 0046190e  83caff               or edx, 0xffffffff
// 00461911  f00fc111             lock xadd dword ptr [ecx], edx
// 00461915  7509                 jne 0x461920
// 00461917  8b07                 mov eax, dword ptr [edi]
// 00461919  8b5008               mov edx, dword ptr [eax + 8]
// 0046191c  8bcf                 mov ecx, edi
// 0046191e  ffd2                 call edx
// 00461920  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00461924  5f                   pop edi
// 00461925  8bc6                 mov eax, esi
// 00461927  64890d00000000       mov dword ptr fs:[0], ecx
// 0046192e  5e                   pop esi
// 0046192f  83c414               add esp, 0x14
// 00461932  c20c00               ret 0xc
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
