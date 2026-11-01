// from server: 100% by EspClaude
// from server: 78% by colin
// roc 2008-06 00457ff0  unit: CRobloxReportView::CStatsItemRecord  size: 347 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00457ff0
//
// 00457ff0  6aff                 push -1
// 00457ff2  68c2267c00           push 0x7c26c2
// 00457ff7  64a100000000         mov eax, dword ptr fs:[0]
// 00457ffd  50                   push eax
// 00457ffe  64892500000000       mov dword ptr fs:[0], esp
// 00458005  83ec14               sub esp, 0x14
// 00458008  53                   push ebx
// 00458009  55                   push ebp
// 0045800a  56                   push esi
// 0045800b  8bf1                 mov esi, ecx
// 0045800d  8d6e54               lea ebp, [esi + 0x54]
// 00458010  8d5e78               lea ebx, [esi + 0x78]
// 00458013  57                   push edi
// 00458014  89742410             mov dword ptr [esp + 0x10], esi
// 00458018  c706748a8100         mov dword ptr [esi], 0x818a74
// 0045801e  c745005c8a8100       mov dword ptr [ebp], 0x818a5c
// 00458025  c703488a8100         mov dword ptr [ebx], 0x818a48
// 0045802b  8b869c000000         mov eax, dword ptr [esi + 0x9c]
// 00458031  83ec08               sub esp, 8
// 00458034  8bcc                 mov ecx, esp
// 00458036  8901                 mov dword ptr [ecx], eax
// 00458038  8b86a0000000         mov eax, dword ptr [esi + 0xa0]
// 0045803e  c744243404000000     mov dword ptr [esp + 0x34], 4
// 00458046  8964241c             mov dword ptr [esp + 0x1c], esp
// 0045804a  894104               mov dword ptr [ecx + 4], eax
// 0045804d  85c0                 test eax, eax
// 0045804f  740c                 je 0x45805d
// 00458051  83c004               add eax, 4
// 00458054  b901000000           mov ecx, 1
// 00458059  f00fc108             lock xadd dword ptr [eax], ecx
// 0045805d  8d4c2420             lea ecx, [esp + 0x20]
// 00458061  e8da9afbff           call 0x411b40
// 00458066  8b86a8000000         mov eax, dword ptr [esi + 0xa8]
// 0045806c  c644242c05           mov byte ptr [esp + 0x2c], 5
// 00458071  85c0                 test eax, eax
// 00458073  7409                 je 0x45807e
// 00458075  55                   push ebp
// 00458076  8d4824               lea ecx, [eax + 0x24]
// 00458079  e802da1800           call 0x5e5a80
// 0045807e  8b86a8000000         mov eax, dword ptr [esi + 0xa8]
// 00458084  85c0                 test eax, eax
// 00458086  7409                 je 0x458091
// 00458088  53                   push ebx
// 00458089  8d4844               lea ecx, [eax + 0x44]
// 0045808c  e8efd91800           call 0x5e5a80
// 00458091  8d4c2418             lea ecx, [esp + 0x18]
// 00458095  c644242c04           mov byte ptr [esp + 0x2c], 4
// 0045809a  e821f31100           call 0x5773c0
// 0045809f  8bbeac000000         mov edi, dword ptr [esi + 0xac]
// 004580a5  c644242c03           mov byte ptr [esp + 0x2c], 3
// 004580aa  85ff                 test edi, edi
// 004580ac  742a                 je 0x4580d8
// 004580ae  8d5704               lea edx, [edi + 4]
// 004580b1  83c8ff               or eax, 0xffffffff
// 004580b4  f00fc102             lock xadd dword ptr [edx], eax
// 004580b8  751e                 jne 0x4580d8
// 004580ba  8b17                 mov edx, dword ptr [edi]
// 004580bc  8b4204               mov eax, dword ptr [edx + 4]
// 004580bf  8bcf                 mov ecx, edi
// 004580c1  ffd0                 call eax
// 004580c3  8d4f08               lea ecx, [edi + 8]
// 004580c6  83caff               or edx, 0xffffffff
// 004580c9  f00fc111             lock xadd dword ptr [ecx], edx
// 004580cd  7509                 jne 0x4580d8
// 004580cf  8b07                 mov eax, dword ptr [edi]
// 004580d1  8b5008               mov edx, dword ptr [eax + 8]
// 004580d4  8bcf                 mov ecx, edi
// 004580d6  ffd2                 call edx
// 004580d8  8bcb                 mov ecx, ebx
// 004580da  c644242c02           mov byte ptr [esp + 0x2c], 2
// 004580df  e80cf8ffff           call 0x4578f0
// 004580e4  8bcd                 mov ecx, ebp
// 004580e6  c644242c01           mov byte ptr [esp + 0x2c], 1
// 004580eb  e8f0f6ffff           call 0x4577e0
// 004580f0  8bbea0000000         mov edi, dword ptr [esi + 0xa0]
// 004580f6  c644242c00           mov byte ptr [esp + 0x2c], 0
// 004580fb  85ff                 test edi, edi
// 004580fd  742a                 je 0x458129
// 004580ff  8d4704               lea eax, [edi + 4]
// 00458102  83c9ff               or ecx, 0xffffffff
// 00458105  f00fc108             lock xadd dword ptr [eax], ecx
// 00458109  751e                 jne 0x458129
// 0045810b  8b17                 mov edx, dword ptr [edi]
// 0045810d  8b4204               mov eax, dword ptr [edx + 4]
// 00458110  8bcf                 mov ecx, edi
// 00458112  ffd0                 call eax
// 00458114  8d4f08               lea ecx, [edi + 8]
// 00458117  83caff               or edx, 0xffffffff
// 0045811a  f00fc111             lock xadd dword ptr [ecx], edx
// 0045811e  7509                 jne 0x458129
// 00458120  8b07                 mov eax, dword ptr [edi]
// 00458122  8b5008               mov edx, dword ptr [eax + 8]
// 00458125  8bcf                 mov ecx, edi
// 00458127  ffd2                 call edx
// 00458129  8bce                 mov ecx, esi
// 0045812b  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 00458133  e8c8ff2700           call 0x6d8100
// 00458138  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0045813c  5f                   pop edi
// 0045813d  5e                   pop esi
// 0045813e  5d                   pop ebp
// 0045813f  64890d00000000       mov dword ptr fs:[0], ecx
// 00458146  5b                   pop ebx
// 00458147  83c420               add esp, 0x20
// 0045814a  c3                   ret 

// from server: 69% by colin
// roc 2008-06 00457ff0  unit: CRobloxReportView::CStatsItemRecord  size: 347 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00457ff0
//
// 00457ff0  6aff                 push -1
// 00457ff2  68c2267c00           push 0x7c26c2
// 00457ff7  64a100000000         mov eax, dword ptr fs:[0]
// 00457ffd  50                   push eax
// 00457ffe  64892500000000       mov dword ptr fs:[0], esp
// 00458005  83ec14               sub esp, 0x14
// 00458008  53                   push ebx
// 00458009  55                   push ebp
// 0045800a  56                   push esi
// 0045800b  8bf1                 mov esi, ecx
// 0045800d  8d6e54               lea ebp, [esi + 0x54]
// 00458010  8d5e78               lea ebx, [esi + 0x78]
// 00458013  57                   push edi
// 00458014  89742410             mov dword ptr [esp + 0x10], esi
// 00458018  c706748a8100         mov dword ptr [esi], 0x818a74
// 0045801e  c745005c8a8100       mov dword ptr [ebp], 0x818a5c
// 00458025  c703488a8100         mov dword ptr [ebx], 0x818a48
// 0045802b  8b869c000000         mov eax, dword ptr [esi + 0x9c]
// 00458031  83ec08               sub esp, 8
// 00458034  8bcc                 mov ecx, esp
// 00458036  8901                 mov dword ptr [ecx], eax
// 00458038  8b86a0000000         mov eax, dword ptr [esi + 0xa0]
// 0045803e  c744243404000000     mov dword ptr [esp + 0x34], 4
// 00458046  8964241c             mov dword ptr [esp + 0x1c], esp
// 0045804a  894104               mov dword ptr [ecx + 4], eax
// 0045804d  85c0                 test eax, eax
// 0045804f  740c                 je 0x45805d
// 00458051  83c004               add eax, 4
// 00458054  b901000000           mov ecx, 1
// 00458059  f00fc108             lock xadd dword ptr [eax], ecx
// 0045805d  8d4c2420             lea ecx, [esp + 0x20]
// 00458061  e8da9afbff           call 0x411b40
// 00458066  8b86a8000000         mov eax, dword ptr [esi + 0xa8]
// 0045806c  c644242c05           mov byte ptr [esp + 0x2c], 5
// 00458071  85c0                 test eax, eax
// 00458073  7409                 je 0x45807e
// 00458075  55                   push ebp
// 00458076  8d4824               lea ecx, [eax + 0x24]
// 00458079  e802da1800           call 0x5e5a80
// 0045807e  8b86a8000000         mov eax, dword ptr [esi + 0xa8]
// 00458084  85c0                 test eax, eax
// 00458086  7409                 je 0x458091
// 00458088  53                   push ebx
// 00458089  8d4844               lea ecx, [eax + 0x44]
// 0045808c  e8efd91800           call 0x5e5a80
// 00458091  8d4c2418             lea ecx, [esp + 0x18]
// 00458095  c644242c04           mov byte ptr [esp + 0x2c], 4
// 0045809a  e821f31100           call 0x5773c0
// 0045809f  8bbeac000000         mov edi, dword ptr [esi + 0xac]
// 004580a5  c644242c03           mov byte ptr [esp + 0x2c], 3
// 004580aa  85ff                 test edi, edi
// 004580ac  742a                 je 0x4580d8
// 004580ae  8d5704               lea edx, [edi + 4]
// 004580b1  83c8ff               or eax, 0xffffffff
// 004580b4  f00fc102             lock xadd dword ptr [edx], eax
// 004580b8  751e                 jne 0x4580d8
// 004580ba  8b17                 mov edx, dword ptr [edi]
// 004580bc  8b4204               mov eax, dword ptr [edx + 4]
// 004580bf  8bcf                 mov ecx, edi
// 004580c1  ffd0                 call eax
// 004580c3  8d4f08               lea ecx, [edi + 8]
// 004580c6  83caff               or edx, 0xffffffff
// 004580c9  f00fc111             lock xadd dword ptr [ecx], edx
// 004580cd  7509                 jne 0x4580d8
// 004580cf  8b07                 mov eax, dword ptr [edi]
// 004580d1  8b5008               mov edx, dword ptr [eax + 8]
// 004580d4  8bcf                 mov ecx, edi
// 004580d6  ffd2                 call edx
// 004580d8  8bcb                 mov ecx, ebx
// 004580da  c644242c02           mov byte ptr [esp + 0x2c], 2
// 004580df  e80cf8ffff           call 0x4578f0
// 004580e4  8bcd                 mov ecx, ebp
// 004580e6  c644242c01           mov byte ptr [esp + 0x2c], 1
// 004580eb  e8f0f6ffff           call 0x4577e0
// 004580f0  8bbea0000000         mov edi, dword ptr [esi + 0xa0]
// 004580f6  c644242c00           mov byte ptr [esp + 0x2c], 0
// 004580fb  85ff                 test edi, edi
// 004580fd  742a                 je 0x458129
// 004580ff  8d4704               lea eax, [edi + 4]
// 00458102  83c9ff               or ecx, 0xffffffff
// 00458105  f00fc108             lock xadd dword ptr [eax], ecx
// 00458109  751e                 jne 0x458129
// 0045810b  8b17                 mov edx, dword ptr [edi]
// 0045810d  8b4204               mov eax, dword ptr [edx + 4]
// 00458110  8bcf                 mov ecx, edi
// 00458112  ffd0                 call eax
// 00458114  8d4f08               lea ecx, [edi + 8]
// 00458117  83caff               or edx, 0xffffffff
// 0045811a  f00fc111             lock xadd dword ptr [ecx], edx
// 0045811e  7509                 jne 0x458129
// 00458120  8b07                 mov eax, dword ptr [edi]
// 00458122  8b5008               mov edx, dword ptr [eax + 8]
// 00458125  8bcf                 mov ecx, edi
// 00458127  ffd2                 call edx
// 00458129  8bce                 mov ecx, esi
// 0045812b  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 00458133  e8c8ff2700           call 0x6d8100
// 00458138  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0045813c  5f                   pop edi
// 0045813d  5e                   pop esi
// 0045813e  5d                   pop ebp
// 0045813f  64890d00000000       mov dword ptr fs:[0], ecx
// 00458146  5b                   pop ebx
// 00458147  83c420               add esp, 0x20
// 0045814a  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

extern "C" void __cdecl release(void*);
extern "C" void __cdecl deallocate(void*);

struct Storage
{
    void* allocation;
    unsigned char reserved0[8];
    void* begin;
    void* end;
    void* capacity;
    unsigned char reserved1[4];
    void* owner;
    ~Storage();
};

struct Storage2
{
    void* first;
    unsigned int reserved[2];
    void* begin;
    void* end;
    void* limit;
    unsigned int extra;
    void* last;
    ~Storage2();
};

struct List
{
    unsigned char reserved[32];
    void remove(void*);
};

struct Owner
{
    unsigned char reserved[36];
    List first;
    List second;
};

struct Guard
{
    void* object;
    Control* control;
    int extra;
    Guard(Shared);
    ~Guard();
};

struct A
{
    virtual ~A();
    unsigned char reserved[0x50];
};

struct B
{
    virtual ~B();
    unsigned char reserved[0x20];
};

struct C
{
    virtual ~C();
    unsigned char reserved[0x20];
};

struct Holder
{
    Shared observed;
};

struct S : A, Holder, B, C
{
    unsigned long reserved4;
    Shared owner;

    ~S();
};

S::~S()
{
    Guard guard(observed);
    if (owner.object)
        static_cast<Owner*>(owner.object)->first.remove(static_cast<B*>(this));
    if (owner.object)
        static_cast<Owner*>(owner.object)->second.remove(static_cast<C*>(this));
}
