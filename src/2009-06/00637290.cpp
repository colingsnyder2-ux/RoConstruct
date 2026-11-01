// from server: 100% by EspClaude
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
