// from server: 100% by EspClaude
// roc 2009-06 00454c50  unit: CRobloxReportView::CStatsItemRecord::CValueItem  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00454c50
//
// 00454c50  6aff                 push -1
// 00454c52  688b1c8500           push 0x851c8b
// 00454c57  64a100000000         mov eax, dword ptr fs:[0]
// 00454c5d  50                   push eax
// 00454c5e  64892500000000       mov dword ptr fs:[0], esp
// 00454c65  51                   push ecx
// 00454c66  56                   push esi
// 00454c67  8bf1                 mov esi, ecx
// 00454c69  89742404             mov dword ptr [esp + 4], esi
// 00454c6d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00454c75  e856a52e00           call 0x73f1d0
// 00454c7a  8bb680000000         mov esi, dword ptr [esi + 0x80]
// 00454c80  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00454c88  85f6                 test esi, esi
// 00454c8a  742a                 je 0x454cb6
// 00454c8c  8d4604               lea eax, [esi + 4]
// 00454c8f  83c9ff               or ecx, 0xffffffff
// 00454c92  f00fc108             lock xadd dword ptr [eax], ecx
// 00454c96  751e                 jne 0x454cb6
// 00454c98  8b16                 mov edx, dword ptr [esi]
// 00454c9a  8b4204               mov eax, dword ptr [edx + 4]
// 00454c9d  8bce                 mov ecx, esi
// 00454c9f  ffd0                 call eax
// 00454ca1  8d4e08               lea ecx, [esi + 8]
// 00454ca4  83caff               or edx, 0xffffffff
// 00454ca7  f00fc111             lock xadd dword ptr [ecx], edx
// 00454cab  7509                 jne 0x454cb6
// 00454cad  8b06                 mov eax, dword ptr [esi]
// 00454caf  8b5008               mov edx, dword ptr [eax + 8]
// 00454cb2  8bce                 mov ecx, esi
// 00454cb4  ffd2                 call edx
// 00454cb6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00454cba  5e                   pop esi
// 00454cbb  64890d00000000       mov dword ptr fs:[0], ecx
// 00454cc2  83c410               add esp, 0x10
// 00454cc5  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX00003e@@QAE@XZ)

namespace ns_ROCX00003e {
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
    void releaseWeak();
};

inline void Control::releaseWeak()
{
    if (_InterlockedDecrement(&weak) == 0)
        destroy();
}

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        releaseWeak();
    }
}

struct Ptr
{
    void* object;
    Control* control;

    ~Ptr();
};

inline Ptr::~Ptr()
{
    if (control)
        control->release();
}

struct S
{
    char data[124];
    Ptr pointer;

    void cleanup();
    ~S();
};

S::~S()
{
    cleanup();
}
}
