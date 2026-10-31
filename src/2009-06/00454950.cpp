// from server: 100% by EspClaude
// roc 2009-06 00454950  unit: CRobloxReportDocView  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00454950
//
// 00454950  6aff                 push -1
// 00454952  68431c8500           push 0x851c43
// 00454957  64a100000000         mov eax, dword ptr fs:[0]
// 0045495d  50                   push eax
// 0045495e  64892500000000       mov dword ptr fs:[0], esp
// 00454965  83ec08               sub esp, 8
// 00454968  56                   push esi
// 00454969  8bf1                 mov esi, ecx
// 0045496b  57                   push edi
// 0045496c  89742408             mov dword ptr [esp + 8], esi
// 00454970  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00454974  83ec08               sub esp, 8
// 00454977  8bc4                 mov eax, esp
// 00454979  8908                 mov dword ptr [eax], ecx
// 0045497b  8b542430             mov edx, dword ptr [esp + 0x30]
// 0045497f  895004               mov dword ptr [eax + 4], edx
// 00454982  8b442430             mov eax, dword ptr [esp + 0x30]
// 00454986  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0045498e  89642414             mov dword ptr [esp + 0x14], esp
// 00454992  85c0                 test eax, eax
// 00454994  740c                 je 0x4549a2
// 00454996  83c004               add eax, 4
// 00454999  b901000000           mov ecx, 1
// 0045499e  f00fc108             lock xadd dword ptr [eax], ecx
// 004549a2  8d4e7c               lea ecx, [esi + 0x7c]
// 004549a5  e886071e00           call 0x635130
// 004549aa  8bce                 mov ecx, esi
// 004549ac  c644241801           mov byte ptr [esp + 0x18], 1
// 004549b1  e82aaf2e00           call 0x73f8e0
// 004549b6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004549ba  8b542420             mov edx, dword ptr [esp + 0x20]
// 004549be  c7069c908b00         mov dword ptr [esi], 0x8b909c
// 004549c4  899684000000         mov dword ptr [esi + 0x84], edx
// 004549ca  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004549d2  85ff                 test edi, edi
// 004549d4  742a                 je 0x454a00
// 004549d6  8d4704               lea eax, [edi + 4]
// 004549d9  83c9ff               or ecx, 0xffffffff
// 004549dc  f00fc108             lock xadd dword ptr [eax], ecx
// 004549e0  751e                 jne 0x454a00
// 004549e2  8b17                 mov edx, dword ptr [edi]
// 004549e4  8b4204               mov eax, dword ptr [edx + 4]
// 004549e7  8bcf                 mov ecx, edi
// 004549e9  ffd0                 call eax
// 004549eb  8d4f08               lea ecx, [edi + 8]
// 004549ee  83caff               or edx, 0xffffffff
// 004549f1  f00fc111             lock xadd dword ptr [ecx], edx
// 004549f5  7509                 jne 0x454a00
// 004549f7  8b07                 mov eax, dword ptr [edi]
// 004549f9  8b5008               mov edx, dword ptr [eax + 8]
// 004549fc  8bcf                 mov ecx, edi
// 004549fe  ffd2                 call edx
// 00454a00  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00454a04  5f                   pop edi
// 00454a05  8bc6                 mov eax, esi
// 00454a07  64890d00000000       mov dword ptr fs:[0], ecx
// 00454a0e  5e                   pop esi
// 00454a0f  83c414               add esp, 0x14
// 00454a12  c20c00               ret 0xc
// copied from an identical function in another client (function ??0CRobloxReportDocView@ns_ROCX00003b@@QAE@HUShared@1@@Z)

namespace ns_ROCX00003b {
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
