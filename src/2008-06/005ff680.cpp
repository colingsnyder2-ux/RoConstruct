// from server: 100% by colin
// from server: 92% by colin
// roc 2008-06 005ff680  unit: RBX::Mouse  size: 193 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ff680
//
// 005ff680  6aff                 push -1
// 005ff682  6829807d00           push 0x7d8029
// 005ff687  64a100000000         mov eax, dword ptr fs:[0]
// 005ff68d  50                   push eax
// 005ff68e  64892500000000       mov dword ptr fs:[0], esp
// 005ff695  83ec0c               sub esp, 0xc
// 005ff698  53                   push ebx
// 005ff699  33db                 xor ebx, ebx
// 005ff69b  895c2404             mov dword ptr [esp + 4], ebx
// 005ff69f  56                   push esi
// 005ff6a0  8b742424             mov esi, dword ptr [esp + 0x24]
// 005ff6a4  57                   push edi
// 005ff6a5  8d7e04               lea edi, [esi + 4]
// 005ff6a8  891e                 mov dword ptr [esi], ebx
// 005ff6aa  891f                 mov dword ptr [edi], ebx
// 005ff6ac  8b8900020000         mov ecx, dword ptr [ecx + 0x200]
// 005ff6b2  8d442410             lea eax, [esp + 0x10]
// 005ff6b6  895c2420             mov dword ptr [esp + 0x20], ebx
// 005ff6ba  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 005ff6c2  50                   push eax
// 005ff6c3  3bcb                 cmp ecx, ebx
// 005ff6c5  740f                 je 0x5ff6d6
// 005ff6c7  e80402fdff           call 0x5cf8d0
// 005ff6cc  c744242001000000     mov dword ptr [esp + 0x20], 1
// 005ff6d4  eb10                 jmp 0x5ff6e6
// 005ff6d6  e825ffffff           call 0x5ff600
// 005ff6db  83c404               add esp, 4
// 005ff6de  c744242002000000     mov dword ptr [esp + 0x20], 2
// 005ff6e6  8b08                 mov ecx, dword ptr [eax]
// 005ff6e8  83c004               add eax, 4
// 005ff6eb  890e                 mov dword ptr [esi], ecx
// 005ff6ed  50                   push eax
// 005ff6ee  8bcf                 mov ecx, edi
// 005ff6f0  e8bb2ee0ff           call 0x4025b0
// 005ff6f5  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005ff6f9  885c2420             mov byte ptr [esp + 0x20], bl
// 005ff6fd  3bfb                 cmp edi, ebx
// 005ff6ff  742a                 je 0x5ff72b
// 005ff701  83c8ff               or eax, 0xffffffff
// 005ff704  8d5704               lea edx, [edi + 4]
// 005ff707  f00fc102             lock xadd dword ptr [edx], eax
// 005ff70b  751e                 jne 0x5ff72b
// 005ff70d  8b17                 mov edx, dword ptr [edi]
// 005ff70f  8b4204               mov eax, dword ptr [edx + 4]
// 005ff712  8bcf                 mov ecx, edi
// 005ff714  ffd0                 call eax
// 005ff716  83caff               or edx, 0xffffffff
// 005ff719  8d4f08               lea ecx, [edi + 8]
// 005ff71c  f00fc111             lock xadd dword ptr [ecx], edx
// 005ff720  7509                 jne 0x5ff72b
// 005ff722  8b07                 mov eax, dword ptr [edi]
// 005ff724  8b5008               mov edx, dword ptr [eax + 8]
// 005ff727  8bcf                 mov ecx, edi
// 005ff729  ffd2                 call edx
// 005ff72b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005ff72f  5f                   pop edi
// 005ff730  8bc6                 mov eax, esi
// 005ff732  5e                   pop esi
// 005ff733  5b                   pop ebx
// 005ff734  64890d00000000       mov dword ptr fs:[0], ecx
// 005ff73b  83c418               add esp, 0x18
// 005ff73e  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy();

    volatile long useCount;
    volatile long weakCount;
    void release();
};

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&useCount) == 0) {
        dispose();
        if (_InterlockedDecrement(&weakCount) == 0)
            destroy();
    }
}

struct Count
{
    Control* control;

    Count();
    ~Count();
    Count& operator=(const Count&);
};

inline Count::Count() : control(0)
{
}

__forceinline Count::~Count()
{
    if (control)
        control->release();
}

struct Shared
{
    void* object;
    Count count;

    Shared();
    Shared(const Shared&);
};

inline Shared::Shared() : object(0)
{
}

struct Source
{
    Shared get();
};

Shared __cdecl create();

struct S
{
    char padding[0x200];
    Source* source;

    Shared get();
};

Shared S::get()
{
    Shared result;
    if (source)
        result = source->get();
    else
        result = create();
    return result;
}
