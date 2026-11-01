// from server: 100% by Yeetserama
// roc 2010-06 00410bb0  unit: boost::Vbad_weak_ptr::U?$error_info_injector::?$clone_impl  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00410bb0
//
// 00410bb0  6aff                 push -1
// 00410bb2  68f2e49700           push 0x97e4f2
// 00410bb7  64a100000000         mov eax, dword ptr fs:[0]
// 00410bbd  50                   push eax
// 00410bbe  64892500000000       mov dword ptr fs:[0], esp
// 00410bc5  51                   push ecx
// 00410bc6  56                   push esi
// 00410bc7  8bf1                 mov esi, ecx
// 00410bc9  57                   push edi
// 00410bca  89742408             mov dword ptr [esp + 8], esi
// 00410bce  c706c425a000         mov dword ptr [esi], 0xa025c4
// 00410bd4  6a00                 push 0
// 00410bd6  6a00                 push 0
// 00410bd8  c744241c03000000     mov dword ptr [esp + 0x1c], 3
// 00410be0  e8bbfdffff           call 0x4109a0
// 00410be5  8bbea0000000         mov edi, dword ptr [esi + 0xa0]
// 00410beb  c644241402           mov byte ptr [esp + 0x14], 2
// 00410bf0  85ff                 test edi, edi
// 00410bf2  742a                 je 0x410c1e
// 00410bf4  8d4704               lea eax, [edi + 4]
// 00410bf7  83c9ff               or ecx, 0xffffffff
// 00410bfa  f00fc108             lock xadd dword ptr [eax], ecx
// 00410bfe  751e                 jne 0x410c1e
// 00410c00  8b17                 mov edx, dword ptr [edi]
// 00410c02  8b4204               mov eax, dword ptr [edx + 4]
// 00410c05  8bcf                 mov ecx, edi
// 00410c07  ffd0                 call eax
// 00410c09  8d4f08               lea ecx, [edi + 8]
// 00410c0c  83caff               or edx, 0xffffffff
// 00410c0f  f00fc111             lock xadd dword ptr [ecx], edx
// 00410c13  7509                 jne 0x410c1e
// 00410c15  8b07                 mov eax, dword ptr [edi]
// 00410c17  8b5008               mov edx, dword ptr [eax + 8]
// 00410c1a  8bcf                 mov ecx, edi
// 00410c1c  ffd2                 call edx
// 00410c1e  8d8e94000000         lea ecx, [esi + 0x94]
// 00410c24  c644241401           mov byte ptr [esp + 0x14], 1
// 00410c29  c701c824a000         mov dword ptr [ecx], 0xa024c8
// 00410c2f  e82ceaffff           call 0x40f660
// 00410c34  8bbe90000000         mov edi, dword ptr [esi + 0x90]
// 00410c3a  c644241400           mov byte ptr [esp + 0x14], 0
// 00410c3f  85ff                 test edi, edi
// 00410c41  742a                 je 0x410c6d
// 00410c43  8d4704               lea eax, [edi + 4]
// 00410c46  83c9ff               or ecx, 0xffffffff
// 00410c49  f00fc108             lock xadd dword ptr [eax], ecx
// 00410c4d  751e                 jne 0x410c6d
// 00410c4f  8b17                 mov edx, dword ptr [edi]
// 00410c51  8b4204               mov eax, dword ptr [edx + 4]
// 00410c54  8bcf                 mov ecx, edi
// 00410c56  ffd0                 call eax
// 00410c58  8d4f08               lea ecx, [edi + 8]
// 00410c5b  83caff               or edx, 0xffffffff
// 00410c5e  f00fc111             lock xadd dword ptr [ecx], edx
// 00410c62  7509                 jne 0x410c6d
// 00410c64  8b07                 mov eax, dword ptr [edi]
// 00410c66  8b5008               mov edx, dword ptr [eax + 8]
// 00410c69  8bcf                 mov ecx, edi
// 00410c6b  ffd2                 call edx
// 00410c6d  8bce                 mov ecx, esi
// 00410c6f  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00410c77  e8a8733900           call 0x7a8024
// 00410c7c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00410c80  5f                   pop edi
// 00410c81  5e                   pop esi
// 00410c82  64890d00000000       mov dword ptr fs:[0], ecx
// 00410c89  83c410               add esp, 0x10
// 00410c8c  c3                   ret 
// copied from an identical function in another client (function ??1CChatPrompt@ns_ROCX000003@@UAE@XZ)

namespace ns_ROCX000003 {
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
