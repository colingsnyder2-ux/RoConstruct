// from server: 100% by Xemicl
// roc 2012-06 0048ff60  unit: CRobloxReportView::CStatsItemRecord::CValueItem  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0048ff60
//
// 0048ff60  6aff                 push -1
// 0048ff62  68ab2baa00           push 0xaa2bab
// 0048ff67  64a100000000         mov eax, dword ptr fs:[0]
// 0048ff6d  50                   push eax
// 0048ff6e  64892500000000       mov dword ptr fs:[0], esp
// 0048ff75  51                   push ecx
// 0048ff76  56                   push esi
// 0048ff77  8bf1                 mov esi, ecx
// 0048ff79  89742404             mov dword ptr [esp + 4], esi
// 0048ff7d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0048ff85  e8f66c5200           call 0x9b6c80
// 0048ff8a  8bb680000000         mov esi, dword ptr [esi + 0x80]
// 0048ff90  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0048ff98  85f6                 test esi, esi
// 0048ff9a  742a                 je 0x48ffc6
// 0048ff9c  8d4604               lea eax, [esi + 4]
// 0048ff9f  83c9ff               or ecx, 0xffffffff
// 0048ffa2  f00fc108             lock xadd dword ptr [eax], ecx
// 0048ffa6  751e                 jne 0x48ffc6
// 0048ffa8  8b16                 mov edx, dword ptr [esi]
// 0048ffaa  8b4204               mov eax, dword ptr [edx + 4]
// 0048ffad  8bce                 mov ecx, esi
// 0048ffaf  ffd0                 call eax
// 0048ffb1  8d4e08               lea ecx, [esi + 8]
// 0048ffb4  83caff               or edx, 0xffffffff
// 0048ffb7  f00fc111             lock xadd dword ptr [ecx], edx
// 0048ffbb  7509                 jne 0x48ffc6
// 0048ffbd  8b06                 mov eax, dword ptr [esi]
// 0048ffbf  8b5008               mov edx, dword ptr [eax + 8]
// 0048ffc2  8bce                 mov ecx, esi
// 0048ffc4  ffd2                 call edx
// 0048ffc6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0048ffca  5e                   pop esi
// 0048ffcb  64890d00000000       mov dword ptr fs:[0], ecx
// 0048ffd2  83c410               add esp, 0x10
// 0048ffd5  c3                   ret 
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