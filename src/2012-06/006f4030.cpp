// from server: 100% by Xemicl
// roc 2012-06 006f4030  unit: RBX::ClearBackpack  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f4030
//
// 006f4030  6aff                 push -1
// 006f4032  68b8cbab00           push 0xabcbb8
// 006f4037  64a100000000         mov eax, dword ptr fs:[0]
// 006f403d  50                   push eax
// 006f403e  64892500000000       mov dword ptr fs:[0], esp
// 006f4045  51                   push ecx
// 006f4046  56                   push esi
// 006f4047  57                   push edi
// 006f4048  8bf9                 mov edi, ecx
// 006f404a  897c2408             mov dword ptr [esp + 8], edi
// 006f404e  c70788c3b900         mov dword ptr [edi], 0xb9c388
// 006f4054  8b7718               mov esi, dword ptr [edi + 0x18]
// 006f4057  c744241400000000     mov dword ptr [esp + 0x14], 0
// 006f405f  85f6                 test esi, esi
// 006f4061  742a                 je 0x6f408d
// 006f4063  8d4604               lea eax, [esi + 4]
// 006f4066  83c9ff               or ecx, 0xffffffff
// 006f4069  f00fc108             lock xadd dword ptr [eax], ecx
// 006f406d  751e                 jne 0x6f408d
// 006f406f  8b16                 mov edx, dword ptr [esi]
// 006f4071  8b4204               mov eax, dword ptr [edx + 4]
// 006f4074  8bce                 mov ecx, esi
// 006f4076  ffd0                 call eax
// 006f4078  8d4e08               lea ecx, [esi + 8]
// 006f407b  83caff               or edx, 0xffffffff
// 006f407e  f00fc111             lock xadd dword ptr [ecx], edx
// 006f4082  7509                 jne 0x6f408d
// 006f4084  8b06                 mov eax, dword ptr [esi]
// 006f4086  8b5008               mov edx, dword ptr [eax + 8]
// 006f4089  8bce                 mov ecx, esi
// 006f408b  ffd2                 call edx
// 006f408d  8bcf                 mov ecx, edi
// 006f408f  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 006f4097  e814770000           call 0x6fb7b0
// 006f409c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006f40a0  5f                   pop edi
// 006f40a1  5e                   pop esi
// 006f40a2  64890d00000000       mov dword ptr fs:[0], ecx
// 006f40a9  83c410               add esp, 0x10
// 006f40ac  c3                   ret 
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