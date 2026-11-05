// from server: 100% by EspClaude
// roc 2009-06 00410c30  unit: boost::Vbad_weak_ptr::U?$error_info_injector::?$clone_impl  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00410c30
//
// 00410c30  6aff                 push -1
// 00410c32  6892d68400           push 0x84d692
// 00410c37  64a100000000         mov eax, dword ptr fs:[0]
// 00410c3d  50                   push eax
// 00410c3e  64892500000000       mov dword ptr fs:[0], esp
// 00410c45  51                   push ecx
// 00410c46  56                   push esi
// 00410c47  8bf1                 mov esi, ecx
// 00410c49  57                   push edi
// 00410c4a  89742408             mov dword ptr [esp + 8], esi
// 00410c4e  c70664ed8a00         mov dword ptr [esi], 0x8aed64
// 00410c54  6a00                 push 0
// 00410c56  6a00                 push 0
// 00410c58  c744241c03000000     mov dword ptr [esp + 0x1c], 3
// 00410c60  e8bbfdffff           call 0x410a20
// 00410c65  8bbea0000000         mov edi, dword ptr [esi + 0xa0]
// 00410c6b  c644241402           mov byte ptr [esp + 0x14], 2
// 00410c70  85ff                 test edi, edi
// 00410c72  742a                 je 0x410c9e
// 00410c74  8d4704               lea eax, [edi + 4]
// 00410c77  83c9ff               or ecx, 0xffffffff
// 00410c7a  f00fc108             lock xadd dword ptr [eax], ecx
// 00410c7e  751e                 jne 0x410c9e
// 00410c80  8b17                 mov edx, dword ptr [edi]
// 00410c82  8b4204               mov eax, dword ptr [edx + 4]
// 00410c85  8bcf                 mov ecx, edi
// 00410c87  ffd0                 call eax
// 00410c89  8d4f08               lea ecx, [edi + 8]
// 00410c8c  83caff               or edx, 0xffffffff
// 00410c8f  f00fc111             lock xadd dword ptr [ecx], edx
// 00410c93  7509                 jne 0x410c9e
// 00410c95  8b07                 mov eax, dword ptr [edi]
// 00410c97  8b5008               mov edx, dword ptr [eax + 8]
// 00410c9a  8bcf                 mov ecx, edi
// 00410c9c  ffd2                 call edx
// 00410c9e  8d8e94000000         lea ecx, [esi + 0x94]
// 00410ca4  c644241401           mov byte ptr [esp + 0x14], 1
// 00410ca9  c70178ec8a00         mov dword ptr [ecx], 0x8aec78
// 00410caf  e81ce8ffff           call 0x40f4d0
// 00410cb4  8bbe90000000         mov edi, dword ptr [esi + 0x90]
// 00410cba  c644241400           mov byte ptr [esp + 0x14], 0
// 00410cbf  85ff                 test edi, edi
// 00410cc1  742a                 je 0x410ced
// 00410cc3  8d4704               lea eax, [edi + 4]
// 00410cc6  83c9ff               or ecx, 0xffffffff
// 00410cc9  f00fc108             lock xadd dword ptr [eax], ecx
// 00410ccd  751e                 jne 0x410ced
// 00410ccf  8b17                 mov edx, dword ptr [edi]
// 00410cd1  8b4204               mov eax, dword ptr [edx + 4]
// 00410cd4  8bcf                 mov ecx, edi
// 00410cd6  ffd0                 call eax
// 00410cd8  8d4f08               lea ecx, [edi + 8]
// 00410cdb  83caff               or edx, 0xffffffff
// 00410cde  f00fc111             lock xadd dword ptr [ecx], edx
// 00410ce2  7509                 jne 0x410ced
// 00410ce4  8b07                 mov eax, dword ptr [edi]
// 00410ce6  8b5008               mov edx, dword ptr [eax + 8]
// 00410ce9  8bcf                 mov ecx, edi
// 00410ceb  ffd2                 call edx
// 00410ced  8bce                 mov ecx, esi
// 00410cef  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00410cf7  e8c0833000           call 0x7190bc
// 00410cfc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00410d00  5f                   pop edi
// 00410d01  5e                   pop esi
// 00410d02  64890d00000000       mov dword ptr fs:[0], ecx
// 00410d09  83c410               add esp, 0x10
// 00410d0c  c3                   ret 
// copied from an identical function in another client (function ??1CChatPrompt@ns_ROCX000005@@UAE@XZ)

namespace ns_ROCX000005 {
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
}
