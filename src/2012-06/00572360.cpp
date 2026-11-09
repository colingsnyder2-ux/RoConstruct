// roc 2012-06 00572360  unit: RBX::Network::Replicator  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00572360
//
// 00572360  6aff                 push -1
// 00572362  68e852ad00           push 0xad52e8
// 00572367  64a100000000         mov eax, dword ptr fs:[0]
// 0057236d  50                   push eax
// 0057236e  64892500000000       mov dword ptr fs:[0], esp
// 00572375  51                   push ecx
// 00572376  53                   push ebx
// 00572377  56                   push esi
// 00572378  8bc1                 mov eax, ecx
// 0057237a  8b542420             mov edx, dword ptr [esp + 0x20]
// 0057237e  83ec08               sub esp, 8
// 00572381  8bcc                 mov ecx, esp
// 00572383  8911                 mov dword ptr [ecx], edx
// 00572385  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00572389  895104               mov dword ptr [ecx + 4], edx
// 0057238c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00572390  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00572398  89642410             mov dword ptr [esp + 0x10], esp
// 0057239c  85c9                 test ecx, ecx
// 0057239e  740c                 je 0x5723ac
// 005723a0  83c104               add ecx, 4
// 005723a3  ba01000000           mov edx, 1
// 005723a8  f00fc111             lock xadd dword ptr [ecx], edx
// 005723ac  8b4804               mov ecx, dword ptr [eax + 4]
// 005723af  034c2424             add ecx, dword ptr [esp + 0x24]
// 005723b3  8b00                 mov eax, dword ptr [eax]
// 005723b5  ffd0                 call eax
// 005723b7  8b742424             mov esi, dword ptr [esp + 0x24]
// 005723bb  8ad8                 mov bl, al
// 005723bd  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 005723c5  85f6                 test esi, esi
// 005723c7  742a                 je 0x5723f3
// 005723c9  8d4e04               lea ecx, [esi + 4]
// 005723cc  83caff               or edx, 0xffffffff
// 005723cf  f00fc111             lock xadd dword ptr [ecx], edx
// 005723d3  751e                 jne 0x5723f3
// 005723d5  8b06                 mov eax, dword ptr [esi]
// 005723d7  8b5004               mov edx, dword ptr [eax + 4]
// 005723da  8bce                 mov ecx, esi
// 005723dc  ffd2                 call edx
// 005723de  8d4608               lea eax, [esi + 8]
// 005723e1  83c9ff               or ecx, 0xffffffff
// 005723e4  f00fc108             lock xadd dword ptr [eax], ecx
// 005723e8  7509                 jne 0x5723f3
// 005723ea  8b16                 mov edx, dword ptr [esi]
// 005723ec  8b4208               mov eax, dword ptr [edx + 8]
// 005723ef  8bce                 mov ecx, esi
// 005723f1  ffd0                 call eax
// 005723f3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005723f7  5e                   pop esi
// 005723f8  8ac3                 mov al, bl
// 005723fa  64890d00000000       mov dword ptr fs:[0], ecx
// 00572401  5b                   pop ebx
// 00572402  83c410               add esp, 0x10
// 00572405  c20c00               ret 0xc
// copied from an identical function in another client (function ?f@S_func_004ac550@@QAE_NPADUShared@@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* pointer;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    Control* c = control;
    if (c)
        _InterlockedIncrement(&c->strong);
}

inline Shared::~Shared()
{
    Control* c = control;
    if (c && _InterlockedDecrement(&c->strong) == 0)
    {
        c->dispose();
        if (_InterlockedDecrement(&c->weak) == 0)
            c->destroy();
    }
}

struct S_func_004ac550
{
    typedef bool (__thiscall *Function)(void*, Shared);

    Function function;
    int adjustment;

    bool f(char* object, Shared argument);
};

bool S_func_004ac550::f(char* object, Shared argument)
{
    return function(object + adjustment, argument);
}