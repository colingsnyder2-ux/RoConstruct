// from server: 100% by EspClaude
// roc 2009-06 0060b750  unit: RBX::ClearBackpack  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0060b750
//
// 0060b750  6aff                 push -1
// 0060b752  68b8148500           push 0x8514b8
// 0060b757  64a100000000         mov eax, dword ptr fs:[0]
// 0060b75d  50                   push eax
// 0060b75e  64892500000000       mov dword ptr fs:[0], esp
// 0060b765  51                   push ecx
// 0060b766  56                   push esi
// 0060b767  57                   push edi
// 0060b768  8bf9                 mov edi, ecx
// 0060b76a  897c2408             mov dword ptr [esp + 8], edi
// 0060b76e  c70710848d00         mov dword ptr [edi], 0x8d8410
// 0060b774  8b7718               mov esi, dword ptr [edi + 0x18]
// 0060b777  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0060b77f  85f6                 test esi, esi
// 0060b781  742a                 je 0x60b7ad
// 0060b783  8d4604               lea eax, [esi + 4]
// 0060b786  83c9ff               or ecx, 0xffffffff
// 0060b789  f00fc108             lock xadd dword ptr [eax], ecx
// 0060b78d  751e                 jne 0x60b7ad
// 0060b78f  8b16                 mov edx, dword ptr [esi]
// 0060b791  8b4204               mov eax, dword ptr [edx + 4]
// 0060b794  8bce                 mov ecx, esi
// 0060b796  ffd0                 call eax
// 0060b798  8d4e08               lea ecx, [esi + 8]
// 0060b79b  83caff               or edx, 0xffffffff
// 0060b79e  f00fc111             lock xadd dword ptr [ecx], edx
// 0060b7a2  7509                 jne 0x60b7ad
// 0060b7a4  8b06                 mov eax, dword ptr [esi]
// 0060b7a6  8b5008               mov edx, dword ptr [eax + 8]
// 0060b7a9  8bce                 mov ecx, esi
// 0060b7ab  ffd2                 call edx
// 0060b7ad  8bcf                 mov ecx, edi
// 0060b7af  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0060b7b7  e8e4500000           call 0x6108a0
// 0060b7bc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0060b7c0  5f                   pop edi
// 0060b7c1  5e                   pop esi
// 0060b7c2  64890d00000000       mov dword ptr fs:[0], ecx
// 0060b7c9  83c410               add esp, 0x10
// 0060b7cc  c3                   ret 
// copied from an identical function in another client (function ??1ClearBackpack@ns_ROCX00001b@@UAE@XZ)

namespace ns_ROCX00001b {
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Handle {
    void* object;
    Control* control;
    ~Handle();
};

inline Handle::~Handle()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Base {
    virtual ~Base();
    char padding[16];
};

struct ClearBackpack : Base {
    Handle handle;
    virtual ~ClearBackpack();
};

ClearBackpack::~ClearBackpack()
{
}
}
