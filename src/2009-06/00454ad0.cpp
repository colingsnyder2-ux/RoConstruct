// from server: 100% by EspClaude
// roc 2009-06 00454ad0  unit: CRobloxReportView::CStatsItemRecord::CNameItem  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00454ad0
//
// 00454ad0  6aff                 push -1
// 00454ad2  68431c8500           push 0x851c43
// 00454ad7  64a100000000         mov eax, dword ptr fs:[0]
// 00454add  50                   push eax
// 00454ade  64892500000000       mov dword ptr fs:[0], esp
// 00454ae5  83ec08               sub esp, 8
// 00454ae8  56                   push esi
// 00454ae9  8bf1                 mov esi, ecx
// 00454aeb  57                   push edi
// 00454aec  89742408             mov dword ptr [esp + 8], esi
// 00454af0  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00454af4  83ec08               sub esp, 8
// 00454af7  8bc4                 mov eax, esp
// 00454af9  8908                 mov dword ptr [eax], ecx
// 00454afb  8b542430             mov edx, dword ptr [esp + 0x30]
// 00454aff  895004               mov dword ptr [eax + 4], edx
// 00454b02  8b442430             mov eax, dword ptr [esp + 0x30]
// 00454b06  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00454b0e  89642414             mov dword ptr [esp + 0x14], esp
// 00454b12  85c0                 test eax, eax
// 00454b14  740c                 je 0x454b22
// 00454b16  83c004               add eax, 4
// 00454b19  b901000000           mov ecx, 1
// 00454b1e  f00fc108             lock xadd dword ptr [eax], ecx
// 00454b22  8d4e7c               lea ecx, [esi + 0x7c]
// 00454b25  e806061e00           call 0x635130
// 00454b2a  8bce                 mov ecx, esi
// 00454b2c  c644241801           mov byte ptr [esp + 0x18], 1
// 00454b31  e8aaad2e00           call 0x73f8e0
// 00454b36  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00454b3a  8b542420             mov edx, dword ptr [esp + 0x20]
// 00454b3e  c706ec918b00         mov dword ptr [esi], 0x8b91ec
// 00454b44  899684000000         mov dword ptr [esi + 0x84], edx
// 00454b4a  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00454b52  85ff                 test edi, edi
// 00454b54  742a                 je 0x454b80
// 00454b56  8d4704               lea eax, [edi + 4]
// 00454b59  83c9ff               or ecx, 0xffffffff
// 00454b5c  f00fc108             lock xadd dword ptr [eax], ecx
// 00454b60  751e                 jne 0x454b80
// 00454b62  8b17                 mov edx, dword ptr [edi]
// 00454b64  8b4204               mov eax, dword ptr [edx + 4]
// 00454b67  8bcf                 mov ecx, edi
// 00454b69  ffd0                 call eax
// 00454b6b  8d4f08               lea ecx, [edi + 8]
// 00454b6e  83caff               or edx, 0xffffffff
// 00454b71  f00fc111             lock xadd dword ptr [ecx], edx
// 00454b75  7509                 jne 0x454b80
// 00454b77  8b07                 mov eax, dword ptr [edi]
// 00454b79  8b5008               mov edx, dword ptr [eax + 8]
// 00454b7c  8bcf                 mov ecx, edi
// 00454b7e  ffd2                 call edx
// 00454b80  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00454b84  5f                   pop edi
// 00454b85  8bc6                 mov eax, esi
// 00454b87  64890d00000000       mov dword ptr fs:[0], ecx
// 00454b8e  5e                   pop esi
// 00454b8f  83c414               add esp, 0x14
// 00454b92  c20c00               ret 0xc
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
