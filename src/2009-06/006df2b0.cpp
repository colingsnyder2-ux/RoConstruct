// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 006604a0  unit: RBX::FilterStairs  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006604a0
//
// 006604a0  6aff                 push -1
// 006604a2  68f3bf7d00           push 0x7dbff3
// 006604a7  64a100000000         mov eax, dword ptr fs:[0]
// 006604ad  50                   push eax
// 006604ae  64892500000000       mov dword ptr fs:[0], esp
// 006604b5  83ec0c               sub esp, 0xc
// 006604b8  53                   push ebx
// 006604b9  56                   push esi
// 006604ba  8bf1                 mov esi, ecx
// 006604bc  33db                 xor ebx, ebx
// 006604be  c7066cc48400         mov dword ptr [esi], 0x84c46c
// 006604c4  895e04               mov dword ptr [esi + 4], ebx
// 006604c7  57                   push edi
// 006604c8  8974240c             mov dword ptr [esp + 0xc], esi
// 006604cc  895e08               mov dword ptr [esi + 8], ebx
// 006604cf  8b442428             mov eax, dword ptr [esp + 0x28]
// 006604d3  50                   push eax
// 006604d4  8d4c2414             lea ecx, [esp + 0x14]
// 006604d8  51                   push ecx
// 006604d9  895c2428             mov dword ptr [esp + 0x28], ebx
// 006604dd  e85e85fbff           call 0x618a40
// 006604e2  83c408               add esp, 8
// 006604e5  8b10                 mov edx, dword ptr [eax]
// 006604e7  83c004               add eax, 4
// 006604ea  50                   push eax
// 006604eb  8d4e08               lea ecx, [esi + 8]
// 006604ee  c644242401           mov byte ptr [esp + 0x24], 1
// 006604f3  895604               mov dword ptr [esi + 4], edx
// 006604f6  e8b520daff           call 0x4025b0
// 006604fb  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006604ff  885c2420             mov byte ptr [esp + 0x20], bl
// 00660503  3bfb                 cmp edi, ebx
// 00660505  742a                 je 0x660531
// 00660507  8d4704               lea eax, [edi + 4]
// 0066050a  83c9ff               or ecx, 0xffffffff
// 0066050d  f00fc108             lock xadd dword ptr [eax], ecx
// 00660511  751e                 jne 0x660531
// 00660513  8b17                 mov edx, dword ptr [edi]
// 00660515  8b4204               mov eax, dword ptr [edx + 4]
// 00660518  8bcf                 mov ecx, edi
// 0066051a  ffd0                 call eax
// 0066051c  8d4f08               lea ecx, [edi + 8]
// 0066051f  83caff               or edx, 0xffffffff
// 00660522  f00fc111             lock xadd dword ptr [ecx], edx
// 00660526  7509                 jne 0x660531
// 00660528  8b07                 mov eax, dword ptr [edi]
// 0066052a  8b5008               mov edx, dword ptr [eax + 8]
// 0066052d  8bcf                 mov ecx, edi
// 0066052f  ffd2                 call edx
// 00660531  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00660535  5f                   pop edi
// 00660536  8bc6                 mov eax, esi
// 00660538  5e                   pop esi
// 00660539  5b                   pop ebx
// 0066053a  64890d00000000       mov dword ptr fs:[0], ecx
// 00660541  83c418               add esp, 0x18
// 00660544  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Reference
{
    Control* control;
    Reference();
    ~Reference();
    Reference& operator=(const Reference&);
};

struct Pointer
{
    void* object;
    Reference reference;
    Pointer();
    Pointer& operator=(const Pointer&);
};

Pointer __cdecl makePointer(void*);

struct S
{
    unsigned long table;
    Pointer pointer;
    S(void*);
};

__forceinline Reference::Reference() : control(0)
{
}

__forceinline Reference::~Reference()
{
    Control* p = control;
    if (p)
    {
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

__forceinline Pointer::Pointer() : object(0)
{
}

__forceinline Pointer& Pointer::operator=(const Pointer& other)
{
    object = other.object;
    reference = other.reference;
    return *this;
}

S::S(void* argument) : table(0x0084c46c)
{
    pointer = makePointer(argument);
}
