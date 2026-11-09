// from server: 100% by Yeetserama
// roc 2010-06 005e19c0  unit: RBX::ClearBackpack  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005e19c0
//
// 005e19c0  6aff                 push -1
// 005e19c2  6878299800           push 0x982978
// 005e19c7  64a100000000         mov eax, dword ptr fs:[0]
// 005e19cd  50                   push eax
// 005e19ce  64892500000000       mov dword ptr fs:[0], esp
// 005e19d5  51                   push ecx
// 005e19d6  56                   push esi
// 005e19d7  57                   push edi
// 005e19d8  8bf9                 mov edi, ecx
// 005e19da  897c2408             mov dword ptr [esp + 8], edi
// 005e19de  c70734e2a200         mov dword ptr [edi], 0xa2e234
// 005e19e4  8b7718               mov esi, dword ptr [edi + 0x18]
// 005e19e7  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005e19ef  85f6                 test esi, esi
// 005e19f1  742a                 je 0x5e1a1d
// 005e19f3  8d4604               lea eax, [esi + 4]
// 005e19f6  83c9ff               or ecx, 0xffffffff
// 005e19f9  f00fc108             lock xadd dword ptr [eax], ecx
// 005e19fd  751e                 jne 0x5e1a1d
// 005e19ff  8b16                 mov edx, dword ptr [esi]
// 005e1a01  8b4204               mov eax, dword ptr [edx + 4]
// 005e1a04  8bce                 mov ecx, esi
// 005e1a06  ffd0                 call eax
// 005e1a08  8d4e08               lea ecx, [esi + 8]
// 005e1a0b  83caff               or edx, 0xffffffff
// 005e1a0e  f00fc111             lock xadd dword ptr [ecx], edx
// 005e1a12  7509                 jne 0x5e1a1d
// 005e1a14  8b06                 mov eax, dword ptr [esi]
// 005e1a16  8b5008               mov edx, dword ptr [eax + 8]
// 005e1a19  8bce                 mov ecx, esi
// 005e1a1b  ffd2                 call edx
// 005e1a1d  8bcf                 mov ecx, edi
// 005e1a1f  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 005e1a27  e8d4510000           call 0x5e6c00
// 005e1a2c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005e1a30  5f                   pop edi
// 005e1a31  5e                   pop esi
// 005e1a32  64890d00000000       mov dword ptr fs:[0], ecx
// 005e1a39  83c410               add esp, 0x10
// 005e1a3c  c3                   ret 
// copied from an identical function in another client (function ??1ClearBackpack@ns_ROCX00000b@@UAE@XZ)

namespace ns_ROCX00000b {
// from server: 100% by king_originala
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
