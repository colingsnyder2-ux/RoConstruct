// from server: 100% by Xemicl
// roc 2012-06 006a7db0  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 322 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006a7db0
//
// 006a7db0  64a100000000         mov eax, dword ptr fs:[0]
// 006a7db6  6aff                 push -1
// 006a7db8  6840d2ab00           push 0xabd240
// 006a7dbd  50                   push eax
// 006a7dbe  64892500000000       mov dword ptr fs:[0], esp
// 006a7dc5  83ec10               sub esp, 0x10
// 006a7dc8  56                   push esi
// 006a7dc9  57                   push edi
// 006a7dca  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006a7dce  57                   push edi
// 006a7dcf  e81c9d1800           call 0x831af0
// 006a7dd4  83c404               add esp, 4
// 006a7dd7  85c0                 test eax, eax
// 006a7dd9  0f8e98000000         jle 0x6a7e77
// 006a7ddf  8d442408             lea eax, [esp + 8]
// 006a7de3  50                   push eax
// 006a7de4  e8f71c0100           call 0x6b9ae0
// 006a7de9  83c404               add esp, 4
// 006a7dec  8b30                 mov esi, dword ptr [eax]
// 006a7dee  c744242000000000     mov dword ptr [esp + 0x20], 0
// 006a7df6  e8e5a1e7ff           call 0x521fe0
// 006a7dfb  8b08                 mov ecx, dword ptr [eax]
// 006a7dfd  51                   push ecx
// 006a7dfe  6a00                 push 0
// 006a7e00  6aff                 push -1
// 006a7e02  57                   push edi
// 006a7e03  e8e8a01800           call 0x831ef0
// 006a7e08  83c40c               add esp, 0xc
// 006a7e0b  50                   push eax
// 006a7e0c  68e449b900           push 0xb949e4
// 006a7e11  6a00                 push 0
// 006a7e13  56                   push esi
// 006a7e14  e897190100           call 0x6b97b0
// 006a7e19  8b442420             mov eax, dword ptr [esp + 0x20]
// 006a7e1d  83c414               add esp, 0x14
// 006a7e20  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 006a7e28  85c0                 test eax, eax
// 006a7e2a  0f84af000000         je 0x6a7edf
// 006a7e30  8bf0                 mov esi, eax
// 006a7e32  83c004               add eax, 4
// 006a7e35  83caff               or edx, 0xffffffff
// 006a7e38  f00fc110             lock xadd dword ptr [eax], edx
// 006a7e3c  0f859d000000         jne 0x6a7edf
// 006a7e42  8b06                 mov eax, dword ptr [esi]
// 006a7e44  8b5004               mov edx, dword ptr [eax + 4]
// 006a7e47  8bce                 mov ecx, esi
// 006a7e49  ffd2                 call edx
// 006a7e4b  8d4608               lea eax, [esi + 8]
// 006a7e4e  83c9ff               or ecx, 0xffffffff
// 006a7e51  f00fc108             lock xadd dword ptr [eax], ecx
// 006a7e55  0f8584000000         jne 0x6a7edf
// 006a7e5b  8b16                 mov edx, dword ptr [esi]
// 006a7e5d  8b4208               mov eax, dword ptr [edx + 8]
// 006a7e60  8bce                 mov ecx, esi
// 006a7e62  ffd0                 call eax
// 006a7e64  5f                   pop edi
// 006a7e65  33c0                 xor eax, eax
// 006a7e67  5e                   pop esi
// 006a7e68  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006a7e6c  64890d00000000       mov dword ptr fs:[0], ecx
// 006a7e73  83c41c               add esp, 0x1c
// 006a7e76  c3                   ret 
// 006a7e77  8d4c2410             lea ecx, [esp + 0x10]
// 006a7e7b  51                   push ecx
// 006a7e7c  e85f1c0100           call 0x6b9ae0
// 006a7e81  8b30                 mov esi, dword ptr [eax]
// 006a7e83  c744242401000000     mov dword ptr [esp + 0x24], 1
// 006a7e8b  e850a1e7ff           call 0x521fe0
// 006a7e90  8b10                 mov edx, dword ptr [eax]
// 006a7e92  52                   push edx
// 006a7e93  68cc49b900           push 0xb949cc
// 006a7e98  6a00                 push 0
// 006a7e9a  56                   push esi
// 006a7e9b  e810190100           call 0x6b97b0
// 006a7ea0  8b442428             mov eax, dword ptr [esp + 0x28]
// 006a7ea4  83c414               add esp, 0x14
// 006a7ea7  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 006a7eaf  85c0                 test eax, eax
// 006a7eb1  742c                 je 0x6a7edf
// 006a7eb3  8bf0                 mov esi, eax
// 006a7eb5  83c004               add eax, 4
// 006a7eb8  83c9ff               or ecx, 0xffffffff
// 006a7ebb  f00fc108             lock xadd dword ptr [eax], ecx
// 006a7ebf  751e                 jne 0x6a7edf
// 006a7ec1  8b16                 mov edx, dword ptr [esi]
// 006a7ec3  8b4204               mov eax, dword ptr [edx + 4]
// 006a7ec6  8bce                 mov ecx, esi
// 006a7ec8  ffd0                 call eax
// 006a7eca  8d4e08               lea ecx, [esi + 8]
// 006a7ecd  83caff               or edx, 0xffffffff
// 006a7ed0  f00fc111             lock xadd dword ptr [ecx], edx
// 006a7ed4  7509                 jne 0x6a7edf
// 006a7ed6  8b06                 mov eax, dword ptr [esi]
// 006a7ed8  8b5008               mov edx, dword ptr [eax + 8]
// 006a7edb  8bce                 mov ecx, esi
// 006a7edd  ffd2                 call edx
// 006a7edf  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006a7ee3  5f                   pop edi
// 006a7ee4  33c0                 xor eax, eax
// 006a7ee6  5e                   pop esi
// 006a7ee7  64890d00000000       mov dword ptr fs:[0], ecx
// 006a7eee  83c41c               add esp, 0x1c
// 006a7ef1  c3                   ret 
// copied from an identical function in another client (function ?sub_5add30@ns_ROCX00001b@@YAHPAX@Z)

namespace ns_ROCX00001b {
// from server: 100% by king_originala
// roc 2008-06 005add30  unit: RBX::VScriptContext::?$BoundFuncDesc  size: 267 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005add30
//
// 005add30  64a100000000         mov eax, dword ptr fs:[0]
// 005add36  6aff                 push -1
// 005add38  68d0327d00           push 0x7d32d0
// 005add3d  50                   push eax
// 005add3e  64892500000000       mov dword ptr fs:[0], esp
// 005add45  83ec10               sub esp, 0x10
// 005add48  53                   push ebx
// 005add49  56                   push esi
// 005add4a  57                   push edi
// 005add4b  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005add4f  83cbff               or ebx, 0xffffffff
// 005add52  53                   push ebx
// 005add53  57                   push edi
// 005add54  e857410600           call 0x611eb0
// 005add59  83c408               add esp, 8
// 005add5c  85c0                 test eax, eax
// 005add5e  7467                 je 0x5addc7
// 005add60  8d44240c             lea eax, [esp + 0xc]
// 005add64  50                   push eax
// 005add65  e8b6b8fbff           call 0x569620
// 005add6a  83c404               add esp, 4
// 005add6d  8b30                 mov esi, dword ptr [eax]
// 005add6f  c744242400000000     mov dword ptr [esp + 0x24], 0
// 005add77  e8e459eeff           call 0x493760
// 005add7c  8b08                 mov ecx, dword ptr [eax]
// 005add7e  51                   push ecx
// 005add7f  6a00                 push 0
// 005add81  53                   push ebx
// 005add82  57                   push edi
// 005add83  e888420600           call 0x612010
// 005add88  83c40c               add esp, 0xc
// 005add8b  50                   push eax
// 005add8c  68e0468300           push 0x8346e0
// 005add91  6a00                 push 0
// 005add93  56                   push esi
// 005add94  e807b6fbff           call 0x5693a0
// 005add99  8b442424             mov eax, dword ptr [esp + 0x24]
// 005add9d  83c414               add esp, 0x14
// 005adda0  895c2424             mov dword ptr [esp + 0x24], ebx
// 005adda4  85c0                 test eax, eax
// 005adda6  747f                 je 0x5ade27
// 005adda8  8bf0                 mov esi, eax
// 005addaa  83c004               add eax, 4
// 005addad  8bd3                 mov edx, ebx
// 005addaf  f00fc110             lock xadd dword ptr [eax], edx
// 005addb3  7572                 jne 0x5ade27
// 005addb5  8b06                 mov eax, dword ptr [esi]
// 005addb7  8b5004               mov edx, dword ptr [eax + 4]
// 005addba  8bce                 mov ecx, esi
// 005addbc  ffd2                 call edx
// 005addbe  8d4608               lea eax, [esi + 8]
// 005addc1  f00fc118             lock xadd dword ptr [eax], ebx
// 005addc5  eb55                 jmp 0x5ade1c
// 005addc7  8d4c2414             lea ecx, [esp + 0x14]
// 005addcb  51                   push ecx
// 005addcc  e84fb8fbff           call 0x569620
// 005addd1  8b30                 mov esi, dword ptr [eax]
// 005addd3  c744242801000000     mov dword ptr [esp + 0x28], 1
// 005adddb  e88059eeff           call 0x493760
// 005adde0  8b10                 mov edx, dword ptr [eax]
// 005adde2  52                   push edx
// 005adde3  68c8468300           push 0x8346c8
// 005adde8  6a00                 push 0
// 005addea  56                   push esi
// 005addeb  e8b0b5fbff           call 0x5693a0
// 005addf0  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005addf4  83c414               add esp, 0x14
// 005addf7  895c2424             mov dword ptr [esp + 0x24], ebx
// 005addfb  85c0                 test eax, eax
// 005addfd  7428                 je 0x5ade27
// 005addff  8bf0                 mov esi, eax
// 005ade01  83c004               add eax, 4
// 005ade04  8bcb                 mov ecx, ebx
// 005ade06  f00fc108             lock xadd dword ptr [eax], ecx
// 005ade0a  751b                 jne 0x5ade27
// 005ade0c  8b16                 mov edx, dword ptr [esi]
// 005ade0e  8b4204               mov eax, dword ptr [edx + 4]
// 005ade11  8bce                 mov ecx, esi
// 005ade13  ffd0                 call eax
// 005ade15  8d4e08               lea ecx, [esi + 8]
// 005ade18  f00fc119             lock xadd dword ptr [ecx], ebx
// 005ade1c  7509                 jne 0x5ade27
// 005ade1e  8b16                 mov edx, dword ptr [esi]
// 005ade20  8b4208               mov eax, dword ptr [edx + 8]
// 005ade23  8bce                 mov ecx, esi
// 005ade25  ffd0                 call eax
// 005ade27  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005ade2b  5f                   pop edi
// 005ade2c  5e                   pop esi
// 005ade2d  33c0                 xor eax, eax
// 005ade2f  5b                   pop ebx
// 005ade30  64890d00000000       mov dword ptr fs:[0], ecx
// 005ade37  83c41c               add esp, 0x1c
// 005ade3a  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;
};

struct Output
{
    void __cdecl print(int, const char *, ...);
};

struct Handle
{
    Output *object;
    Control *control;

    Output *operator->() const;
    ~Handle();
};

inline Output *Handle::operator->() const
{
    return object;
}

inline Handle::~Handle()
{
    if (control)
    {
        Control *p = control;
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

int __cdecl sub_611eb0(void *);
const char *__cdecl sub_612010(void *, int, unsigned int *);
Handle __cdecl sub_569620();
int *__cdecl sub_493760();

int __cdecl sub_5add30(void *state)
{
    if (sub_611eb0(state) > 0)
    {
        sub_569620()->print(0, "%s %d",
                           sub_612010(state, -1, 0),
                           *sub_493760());
    }
    else
    {
        sub_569620()->print(0, "Current identity is %d",
                           *sub_493760());
    }
    return 0;
}
}
