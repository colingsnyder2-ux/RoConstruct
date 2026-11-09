// from server: 100% by Yeetserama
// roc 2010-06 004619f0  unit: CRobloxReportView::CStatsItemRecord::CNameItem  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004619f0
//
// 004619f0  6aff                 push -1
// 004619f2  682b369800           push 0x98362b
// 004619f7  64a100000000         mov eax, dword ptr fs:[0]
// 004619fd  50                   push eax
// 004619fe  64892500000000       mov dword ptr fs:[0], esp
// 00461a05  51                   push ecx
// 00461a06  56                   push esi
// 00461a07  8bf1                 mov esi, ecx
// 00461a09  89742404             mov dword ptr [esp + 4], esi
// 00461a0d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00461a15  e8a6c73600           call 0x7ce1c0
// 00461a1a  8bb680000000         mov esi, dword ptr [esi + 0x80]
// 00461a20  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00461a28  85f6                 test esi, esi
// 00461a2a  742a                 je 0x461a56
// 00461a2c  8d4604               lea eax, [esi + 4]
// 00461a2f  83c9ff               or ecx, 0xffffffff
// 00461a32  f00fc108             lock xadd dword ptr [eax], ecx
// 00461a36  751e                 jne 0x461a56
// 00461a38  8b16                 mov edx, dword ptr [esi]
// 00461a3a  8b4204               mov eax, dword ptr [edx + 4]
// 00461a3d  8bce                 mov ecx, esi
// 00461a3f  ffd0                 call eax
// 00461a41  8d4e08               lea ecx, [esi + 8]
// 00461a44  83caff               or edx, 0xffffffff
// 00461a47  f00fc111             lock xadd dword ptr [ecx], edx
// 00461a4b  7509                 jne 0x461a56
// 00461a4d  8b06                 mov eax, dword ptr [esi]
// 00461a4f  8b5008               mov edx, dword ptr [eax + 8]
// 00461a52  8bce                 mov ecx, esi
// 00461a54  ffd2                 call edx
// 00461a56  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00461a5a  5e                   pop esi
// 00461a5b  64890d00000000       mov dword ptr fs:[0], ecx
// 00461a62  83c410               add esp, 0x10
// 00461a65  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX000017@@QAE@XZ)

namespace ns_ROCX000017 {
// from server: 100% by king_originala
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
