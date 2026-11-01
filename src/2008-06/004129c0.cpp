// from server: 100% by colin
// from server: 82% by king_originala
// roc 2008-06 004129c0  unit: CChatPrompt  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004129c0
//
// 004129c0  6aff                 push -1
// 004129c2  68e2d77b00           push 0x7bd7e2
// 004129c7  64a100000000         mov eax, dword ptr fs:[0]
// 004129cd  50                   push eax
// 004129ce  64892500000000       mov dword ptr fs:[0], esp
// 004129d5  51                   push ecx
// 004129d6  56                   push esi
// 004129d7  8bf1                 mov esi, ecx
// 004129d9  57                   push edi
// 004129da  89742408             mov dword ptr [esp + 8], esi
// 004129de  c706ace18000         mov dword ptr [esi], 0x80e1ac
// 004129e4  6a00                 push 0
// 004129e6  6a00                 push 0
// 004129e8  c744241c03000000     mov dword ptr [esp + 0x1c], 3
// 004129f0  e80bfeffff           call 0x412800
// 004129f5  8bbea0000000         mov edi, dword ptr [esi + 0xa0]
// 004129fb  c644241402           mov byte ptr [esp + 0x14], 2
// 00412a00  85ff                 test edi, edi
// 00412a02  742a                 je 0x412a2e
// 00412a04  8d4704               lea eax, [edi + 4]
// 00412a07  83c9ff               or ecx, 0xffffffff
// 00412a0a  f00fc108             lock xadd dword ptr [eax], ecx
// 00412a0e  751e                 jne 0x412a2e
// 00412a10  8b17                 mov edx, dword ptr [edi]
// 00412a12  8b4204               mov eax, dword ptr [edx + 4]
// 00412a15  8bcf                 mov ecx, edi
// 00412a17  ffd0                 call eax
// 00412a19  8d4f08               lea ecx, [edi + 8]
// 00412a1c  83caff               or edx, 0xffffffff
// 00412a1f  f00fc111             lock xadd dword ptr [ecx], edx
// 00412a23  7509                 jne 0x412a2e
// 00412a25  8b07                 mov eax, dword ptr [edi]
// 00412a27  8b5008               mov edx, dword ptr [eax + 8]
// 00412a2a  8bcf                 mov ecx, edi
// 00412a2c  ffd2                 call edx
// 00412a2e  8d8e94000000         lea ecx, [esi + 0x94]
// 00412a34  c644241401           mov byte ptr [esp + 0x14], 1
// 00412a39  c70168e08000         mov dword ptr [ecx], 0x80e068
// 00412a3f  e85ce7ffff           call 0x4111a0
// 00412a44  8bbe90000000         mov edi, dword ptr [esi + 0x90]
// 00412a4a  c644241400           mov byte ptr [esp + 0x14], 0
// 00412a4f  85ff                 test edi, edi
// 00412a51  742a                 je 0x412a7d
// 00412a53  8d4704               lea eax, [edi + 4]
// 00412a56  83c9ff               or ecx, 0xffffffff
// 00412a59  f00fc108             lock xadd dword ptr [eax], ecx
// 00412a5d  751e                 jne 0x412a7d
// 00412a5f  8b17                 mov edx, dword ptr [edi]
// 00412a61  8b4204               mov eax, dword ptr [edx + 4]
// 00412a64  8bcf                 mov ecx, edi
// 00412a66  ffd0                 call eax
// 00412a68  8d4f08               lea ecx, [edi + 8]
// 00412a6b  83caff               or edx, 0xffffffff
// 00412a6e  f00fc111             lock xadd dword ptr [ecx], edx
// 00412a72  7509                 jne 0x412a7d
// 00412a74  8b07                 mov eax, dword ptr [edi]
// 00412a76  8b5008               mov edx, dword ptr [eax + 8]
// 00412a79  8bcf                 mov ecx, edi
// 00412a7b  ffd2                 call edx
// 00412a7d  8bce                 mov ecx, esi
// 00412a7f  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00412a87  e890e22800           call 0x6a0d1c
// 00412a8c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00412a90  5f                   pop edi
// 00412a91  5e                   pop esi
// 00412a92  64890d00000000       mov dword ptr fs:[0], ecx
// 00412a99  83c410               add esp, 0x10
// 00412a9c  c3                   ret 

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
