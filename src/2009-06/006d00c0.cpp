// from server: 75% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00643f10  unit: RBX::HUMAN::Climbing  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00643f10
//
// 00643f10  6aff                 push -1
// 00643f12  68a1e77b00           push 0x7be7a1
// 00643f17  64a100000000         mov eax, dword ptr fs:[0]
// 00643f1d  50                   push eax
// 00643f1e  64892500000000       mov dword ptr fs:[0], esp
// 00643f25  83ec0c               sub esp, 0xc
// 00643f28  53                   push ebx
// 00643f29  33db                 xor ebx, ebx
// 00643f2b  8bc1                 mov eax, ecx
// 00643f2d  56                   push esi
// 00643f2e  57                   push edi
// 00643f2f  895c2420             mov dword ptr [esp + 0x20], ebx
// 00643f33  895c240c             mov dword ptr [esp + 0xc], ebx
// 00643f37  3bc3                 cmp eax, ebx
// 00643f39  7405                 je 0x643f40
// 00643f3b  8d5004               lea edx, [eax + 4]
// 00643f3e  eb02                 jmp 0x643f42
// 00643f40  33d2                 xor edx, edx
// 00643f42  8b4808               mov ecx, dword ptr [eax + 8]
// 00643f45  8b891c020000         mov ecx, dword ptr [ecx + 0x21c]
// 00643f4b  8b8984000000         mov ecx, dword ptr [ecx + 0x84]
// 00643f51  8d742430             lea esi, [esp + 0x30]
// 00643f55  56                   push esi
// 00643f56  8d742430             lea esi, [esp + 0x30]
// 00643f5a  56                   push esi
// 00643f5b  83c02c               add eax, 0x2c
// 00643f5e  50                   push eax
// 00643f5f  52                   push edx
// 00643f60  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 00643f64  53                   push ebx
// 00643f65  52                   push edx
// 00643f66  e8959afcff           call 0x60da00
// 00643f6b  8b742428             mov esi, dword ptr [esp + 0x28]
// 00643f6f  8d7e04               lea edi, [esi + 4]
// 00643f72  891e                 mov dword ptr [esi], ebx
// 00643f74  891f                 mov dword ptr [edi], ebx
// 00643f76  895c2420             mov dword ptr [esp + 0x20], ebx
// 00643f7a  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 00643f82  3bc3                 cmp eax, ebx
// 00643f84  7461                 je 0x643fe7
// 00643f86  50                   push eax
// 00643f87  e8f45ff5ff           call 0x599f80
// 00643f8c  50                   push eax
// 00643f8d  8d442418             lea eax, [esp + 0x18]
// 00643f91  50                   push eax
// 00643f92  e8a94afdff           call 0x618a40
// 00643f97  83c40c               add esp, 0xc
// 00643f9a  8b08                 mov ecx, dword ptr [eax]
// 00643f9c  83c004               add eax, 4
// 00643f9f  890e                 mov dword ptr [esi], ecx
// 00643fa1  50                   push eax
// 00643fa2  8bcf                 mov ecx, edi
// 00643fa4  c744242401000000     mov dword ptr [esp + 0x24], 1
// 00643fac  e8ffe5dbff           call 0x4025b0
// 00643fb1  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00643fb5  885c2420             mov byte ptr [esp + 0x20], bl
// 00643fb9  3bfb                 cmp edi, ebx
// 00643fbb  742a                 je 0x643fe7
// 00643fbd  8d5704               lea edx, [edi + 4]
// 00643fc0  83c8ff               or eax, 0xffffffff
// 00643fc3  f00fc102             lock xadd dword ptr [edx], eax
// 00643fc7  751e                 jne 0x643fe7
// 00643fc9  8b17                 mov edx, dword ptr [edi]
// 00643fcb  8b4204               mov eax, dword ptr [edx + 4]
// 00643fce  8bcf                 mov ecx, edi
// 00643fd0  ffd0                 call eax
// 00643fd2  8d4f08               lea ecx, [edi + 8]
// 00643fd5  83caff               or edx, 0xffffffff
// 00643fd8  f00fc111             lock xadd dword ptr [ecx], edx
// 00643fdc  7509                 jne 0x643fe7
// 00643fde  8b07                 mov eax, dword ptr [edi]
// 00643fe0  8b5008               mov edx, dword ptr [eax + 8]
// 00643fe3  8bcf                 mov ecx, edi
// 00643fe5  ffd2                 call edx
// 00643fe7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00643feb  5f                   pop edi
// 00643fec  8bc6                 mov eax, esi
// 00643fee  5e                   pop esi
// 00643fef  5b                   pop ebx
// 00643ff0  64890d00000000       mov dword ptr fs:[0], ecx
// 00643ff7  83c418               add esp, 0x18
// 00643ffa  c20c00               ret 0xc

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct PartInstance;

struct GetSetImpl
{
    static PartInstance* get(PartInstance*);
};

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;

    void release();
    void weakRelease();
};

__forceinline void Control::weakRelease()
{
    if (_InterlockedDecrement(&weak) == 0)
        destroy();
}

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        weakRelease();
    }
}

struct Reference
{
    Control* control;
    Reference& operator=(const Reference&);
    ~Reference();
};

__forceinline Reference::~Reference()
{
    if (control)
        control->release();
}

struct Shared
{
    PartInstance* pointer;
    Reference reference;

    Shared();
    ~Shared();
    Shared& operator=(const Shared&);
};

__forceinline Shared::Shared()
{
    pointer = 0;
    reference.control = 0;
}

__forceinline Shared::~Shared()
{
}

__forceinline Shared& Shared::operator=(const Shared& other)
{
    pointer = other.pointer;
    reference = other.reference;
    return *this;
}

Shared __cdecl makeShared(PartInstance*);

struct Query
{
    PartInstance* find(unsigned, int, void*, void*, unsigned*, unsigned*);
};

struct Link
{
    char padding[0x84];
    Query* query;
};

struct Owner
{
    char padding[0x21c];
    Link* link;
};

struct S
{
    unsigned field0;
    unsigned field4;
    Owner* owner;
    char padding[0x20];
    unsigned field2c;

    Shared f(unsigned, unsigned);
};

Shared S::f(unsigned first, unsigned second)
{
    void* base = this ? &field4 : 0;
    Query* query = owner->link->query;
    PartInstance* part = query->find(
        first, 0, base, &field2c, &first, &second);

    Shared result;
    if (part)
        result = makeShared(GetSetImpl::get(part));
    return result;
}
