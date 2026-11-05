// from server: 100% by Yeetserama
// roc 2007-08 0040ea60  unit: RBX::Network::VPlayer::?$FactoryProduct::Creator  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040ea60
//
// 0040ea60  6aff                 push -1
// 0040ea62  68929f7300           push 0x739f92
// 0040ea67  64a100000000         mov eax, dword ptr fs:[0]
// 0040ea6d  50                   push eax
// 0040ea6e  51                   push ecx
// 0040ea6f  56                   push esi
// 0040ea70  57                   push edi
// 0040ea71  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040ea76  33c4                 xor eax, esp
// 0040ea78  50                   push eax
// 0040ea79  8d442410             lea eax, [esp + 0x10]
// 0040ea7d  64a300000000         mov dword ptr fs:[0], eax
// 0040ea83  8bf1                 mov esi, ecx
// 0040ea85  8974240c             mov dword ptr [esp + 0xc], esi
// 0040ea89  c7061c667800         mov dword ptr [esi], 0x78661c
// 0040ea8f  6a00                 push 0
// 0040ea91  6a00                 push 0
// 0040ea93  c744242003000000     mov dword ptr [esp + 0x20], 3
// 0040ea9b  e8b0fdffff           call 0x40e850
// 0040eaa0  8bbea0000000         mov edi, dword ptr [esi + 0xa0]
// 0040eaa6  85ff                 test edi, edi
// 0040eaa8  c644241802           mov byte ptr [esp + 0x18], 2
// 0040eaad  742a                 je 0x40ead9
// 0040eaaf  8d4704               lea eax, [edi + 4]
// 0040eab2  83c9ff               or ecx, 0xffffffff
// 0040eab5  f00fc108             lock xadd dword ptr [eax], ecx
// 0040eab9  751e                 jne 0x40ead9
// 0040eabb  8b17                 mov edx, dword ptr [edi]
// 0040eabd  8b4204               mov eax, dword ptr [edx + 4]
// 0040eac0  8bcf                 mov ecx, edi
// 0040eac2  ffd0                 call eax
// 0040eac4  8d4f08               lea ecx, [edi + 8]
// 0040eac7  83caff               or edx, 0xffffffff
// 0040eaca  f00fc111             lock xadd dword ptr [ecx], edx
// 0040eace  7509                 jne 0x40ead9
// 0040ead0  8b07                 mov eax, dword ptr [edi]
// 0040ead2  8b5008               mov edx, dword ptr [eax + 8]
// 0040ead5  8bcf                 mov ecx, edi
// 0040ead7  ffd2                 call edx
// 0040ead9  8d8e94000000         lea ecx, [esi + 0x94]
// 0040eadf  c644241801           mov byte ptr [esp + 0x18], 1
// 0040eae4  c701c8647800         mov dword ptr [ecx], 0x7864c8
// 0040eaea  e83d172200           call 0x63022c
// 0040eaef  8bbe90000000         mov edi, dword ptr [esi + 0x90]
// 0040eaf5  85ff                 test edi, edi
// 0040eaf7  c644241800           mov byte ptr [esp + 0x18], 0
// 0040eafc  742a                 je 0x40eb28
// 0040eafe  8d4704               lea eax, [edi + 4]
// 0040eb01  83c9ff               or ecx, 0xffffffff
// 0040eb04  f00fc108             lock xadd dword ptr [eax], ecx
// 0040eb08  751e                 jne 0x40eb28
// 0040eb0a  8b17                 mov edx, dword ptr [edi]
// 0040eb0c  8b4204               mov eax, dword ptr [edx + 4]
// 0040eb0f  8bcf                 mov ecx, edi
// 0040eb11  ffd0                 call eax
// 0040eb13  8d4f08               lea ecx, [edi + 8]
// 0040eb16  83caff               or edx, 0xffffffff
// 0040eb19  f00fc111             lock xadd dword ptr [ecx], edx
// 0040eb1d  7509                 jne 0x40eb28
// 0040eb1f  8b07                 mov eax, dword ptr [edi]
// 0040eb21  8b5008               mov edx, dword ptr [eax + 8]
// 0040eb24  8bcf                 mov ecx, edi
// 0040eb26  ffd2                 call edx
// 0040eb28  8bce                 mov ecx, esi
// 0040eb2a  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0040eb32  e8bb172200           call 0x6302f2
// 0040eb37  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040eb3b  64890d00000000       mov dword ptr fs:[0], ecx
// 0040eb42  59                   pop ecx
// 0040eb43  5f                   pop edi
// 0040eb44  5e                   pop esi
// 0040eb45  83c410               add esp, 0x10
// 0040eb48  c3                   ret 
// copied from an identical function in another client (function ??1CChatPrompt@ns_ROCX00001e@@UAE@XZ)

namespace ns_ROCX00001e {
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct RefCount
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* pointer;
    RefCount* count;
    ~Shared();
};

inline Shared::~Shared()
{
    RefCount* p = count;
    if (p && _InterlockedDecrement(&p->strong) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct SubBase
{
    virtual ~SubBase();
    unsigned long data;
};

struct Sub : SubBase
{
    virtual ~Sub();
};

inline Sub::~Sub()
{
}

struct Base
{
    virtual ~Base();
    unsigned char data[0x88];
};

struct CChatPrompt : Base
{
    Shared first;
    Sub sub;
    Shared second;

    void reset(int, int);
    virtual ~CChatPrompt();
};

CChatPrompt::~CChatPrompt()
{
    reset(0, 0);
}
}
