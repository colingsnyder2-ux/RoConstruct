// from server: 100% by colin
// from server: 96% by colin
// roc 2008-06 00454f30  unit: CRobloxDoc  size: 297 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00454f30
//
// 00454f30  6aff                 push -1
// 00454f32  68f8217c00           push 0x7c21f8
// 00454f37  64a100000000         mov eax, dword ptr fs:[0]
// 00454f3d  50                   push eax
// 00454f3e  64892500000000       mov dword ptr fs:[0], esp
// 00454f45  83ec1c               sub esp, 0x1c
// 00454f48  56                   push esi
// 00454f49  57                   push edi
// 00454f4a  8bf1                 mov esi, ecx
// 00454f4c  8b8e94000000         mov ecx, dword ptr [esi + 0x94]
// 00454f52  8d442410             lea eax, [esp + 0x10]
// 00454f56  50                   push eax
// 00454f57  e8e4590100           call 0x46a940
// 00454f5c  8b10                 mov edx, dword ptr [eax]
// 00454f5e  83ec08               sub esp, 8
// 00454f61  8bcc                 mov ecx, esp
// 00454f63  8911                 mov dword ptr [ecx], edx
// 00454f65  8b4004               mov eax, dword ptr [eax + 4]
// 00454f68  c744243400000000     mov dword ptr [esp + 0x34], 0
// 00454f70  89642410             mov dword ptr [esp + 0x10], esp
// 00454f74  894104               mov dword ptr [ecx + 4], eax
// 00454f77  85c0                 test eax, eax
// 00454f79  740c                 je 0x454f87
// 00454f7b  83c004               add eax, 4
// 00454f7e  b901000000           mov ecx, 1
// 00454f83  f00fc108             lock xadd dword ptr [eax], ecx
// 00454f87  8d4c2420             lea ecx, [esp + 0x20]
// 00454f8b  e8b0cbfbff           call 0x411b40
// 00454f90  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00454f94  c644242c02           mov byte ptr [esp + 0x2c], 2
// 00454f99  85ff                 test edi, edi
// 00454f9b  742a                 je 0x454fc7
// 00454f9d  8d5704               lea edx, [edi + 4]
// 00454fa0  83c8ff               or eax, 0xffffffff
// 00454fa3  f00fc102             lock xadd dword ptr [edx], eax
// 00454fa7  751e                 jne 0x454fc7
// 00454fa9  8b17                 mov edx, dword ptr [edi]
// 00454fab  8b4204               mov eax, dword ptr [edx + 4]
// 00454fae  8bcf                 mov ecx, edi
// 00454fb0  ffd0                 call eax
// 00454fb2  8d4f08               lea ecx, [edi + 8]
// 00454fb5  83caff               or edx, 0xffffffff
// 00454fb8  f00fc111             lock xadd dword ptr [ecx], edx
// 00454fbc  7509                 jne 0x454fc7
// 00454fbe  8b07                 mov eax, dword ptr [edi]
// 00454fc0  8b5008               mov edx, dword ptr [eax + 8]
// 00454fc3  8bcf                 mov ecx, edi
// 00454fc5  ffd2                 call edx
// 00454fc7  8d442408             lea eax, [esp + 8]
// 00454fcb  50                   push eax
// 00454fcc  8bce                 mov ecx, esi
// 00454fce  e86de0faff           call 0x403040
// 00454fd3  8b00                 mov eax, dword ptr [eax]
// 00454fd5  8b742434             mov esi, dword ptr [esp + 0x34]
// 00454fd9  8b3e                 mov edi, dword ptr [esi]
// 00454fdb  8bc8                 mov ecx, eax
// 00454fdd  c644242c03           mov byte ptr [esp + 0x2c], 3
// 00454fe2  e829d7fbff           call 0x412710
// 00454fe7  8bc8                 mov ecx, eax
// 00454fe9  e8a2130400           call 0x496390
// 00454fee  8b17                 mov edx, dword ptr [edi]
// 00454ff0  33c9                 xor ecx, ecx
// 00454ff2  84c0                 test al, al
// 00454ff4  0f95c1               setne cl
// 00454ff7  51                   push ecx
// 00454ff8  8bce                 mov ecx, esi
// 00454ffa  ffd2                 call edx
// 00454ffc  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00455000  c644242c02           mov byte ptr [esp + 0x2c], 2
// 00455005  85c0                 test eax, eax
// 00455007  742c                 je 0x455035
// 00455009  8bf0                 mov esi, eax
// 0045500b  83c004               add eax, 4
// 0045500e  83c9ff               or ecx, 0xffffffff
// 00455011  f00fc108             lock xadd dword ptr [eax], ecx
// 00455015  751e                 jne 0x455035
// 00455017  8b16                 mov edx, dword ptr [esi]
// 00455019  8b4204               mov eax, dword ptr [edx + 4]
// 0045501c  8bce                 mov ecx, esi
// 0045501e  ffd0                 call eax
// 00455020  8d4e08               lea ecx, [esi + 8]
// 00455023  83caff               or edx, 0xffffffff
// 00455026  f00fc111             lock xadd dword ptr [ecx], edx
// 0045502a  7509                 jne 0x455035
// 0045502c  8b06                 mov eax, dword ptr [esi]
// 0045502e  8b5008               mov edx, dword ptr [eax + 8]
// 00455031  8bce                 mov ecx, esi
// 00455033  ffd2                 call edx
// 00455035  8d4c2418             lea ecx, [esp + 0x18]
// 00455039  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 00455041  e87a231200           call 0x5773c0
// 00455046  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0045504a  5f                   pop edi
// 0045504b  64890d00000000       mov dword ptr fs:[0], ecx
// 00455052  5e                   pop esi
// 00455053  83c428               add esp, 0x28
// 00455056  c20400               ret 4

// from server: 95% by king_originala
// roc 2008-06 00454f30  unit: CRobloxDoc  size: 297 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00454f30
//
// 00454f30  6aff                 push -1
// 00454f32  68f8217c00           push 0x7c21f8
// 00454f37  64a100000000         mov eax, dword ptr fs:[0]
// 00454f3d  50                   push eax
// 00454f3e  64892500000000       mov dword ptr fs:[0], esp
// 00454f45  83ec1c               sub esp, 0x1c
// 00454f48  56                   push esi
// 00454f49  57                   push edi
// 00454f4a  8bf1                 mov esi, ecx
// 00454f4c  8b8e94000000         mov ecx, dword ptr [esi + 0x94]
// 00454f52  8d442410             lea eax, [esp + 0x10]
// 00454f56  50                   push eax
// 00454f57  e8e4590100           call 0x46a940
// 00454f5c  8b10                 mov edx, dword ptr [eax]
// 00454f5e  83ec08               sub esp, 8
// 00454f61  8bcc                 mov ecx, esp
// 00454f63  8911                 mov dword ptr [ecx], edx
// 00454f65  8b4004               mov eax, dword ptr [eax + 4]
// 00454f68  c744243400000000     mov dword ptr [esp + 0x34], 0
// 00454f70  89642410             mov dword ptr [esp + 0x10], esp
// 00454f74  894104               mov dword ptr [ecx + 4], eax
// 00454f77  85c0                 test eax, eax
// 00454f79  740c                 je 0x454f87
// 00454f7b  83c004               add eax, 4
// 00454f7e  b901000000           mov ecx, 1
// 00454f83  f00fc108             lock xadd dword ptr [eax], ecx
// 00454f87  8d4c2420             lea ecx, [esp + 0x20]
// 00454f8b  e8b0cbfbff           call 0x411b40
// 00454f90  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00454f94  c644242c02           mov byte ptr [esp + 0x2c], 2
// 00454f99  85ff                 test edi, edi
// 00454f9b  742a                 je 0x454fc7
// 00454f9d  8d5704               lea edx, [edi + 4]
// 00454fa0  83c8ff               or eax, 0xffffffff
// 00454fa3  f00fc102             lock xadd dword ptr [edx], eax
// 00454fa7  751e                 jne 0x454fc7
// 00454fa9  8b17                 mov edx, dword ptr [edi]
// 00454fab  8b4204               mov eax, dword ptr [edx + 4]
// 00454fae  8bcf                 mov ecx, edi
// 00454fb0  ffd0                 call eax
// 00454fb2  8d4f08               lea ecx, [edi + 8]
// 00454fb5  83caff               or edx, 0xffffffff
// 00454fb8  f00fc111             lock xadd dword ptr [ecx], edx
// 00454fbc  7509                 jne 0x454fc7
// 00454fbe  8b07                 mov eax, dword ptr [edi]
// 00454fc0  8b5008               mov edx, dword ptr [eax + 8]
// 00454fc3  8bcf                 mov ecx, edi
// 00454fc5  ffd2                 call edx
// 00454fc7  8d442408             lea eax, [esp + 8]
// 00454fcb  50                   push eax
// 00454fcc  8bce                 mov ecx, esi
// 00454fce  e86de0faff           call 0x403040
// 00454fd3  8b00                 mov eax, dword ptr [eax]
// 00454fd5  8b742434             mov esi, dword ptr [esp + 0x34]
// 00454fd9  8b3e                 mov edi, dword ptr [esi]
// 00454fdb  8bc8                 mov ecx, eax
// 00454fdd  c644242c03           mov byte ptr [esp + 0x2c], 3
// 00454fe2  e829d7fbff           call 0x412710
// 00454fe7  8bc8                 mov ecx, eax
// 00454fe9  e8a2130400           call 0x496390
// 00454fee  8b17                 mov edx, dword ptr [edi]
// 00454ff0  33c9                 xor ecx, ecx
// 00454ff2  84c0                 test al, al
// 00454ff4  0f95c1               setne cl
// 00454ff7  51                   push ecx
// 00454ff8  8bce                 mov ecx, esi
// 00454ffa  ffd2                 call edx
// 00454ffc  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00455000  c644242c02           mov byte ptr [esp + 0x2c], 2
// 00455005  85c0                 test eax, eax
// 00455007  742c                 je 0x455035
// 00455009  8bf0                 mov esi, eax
// 0045500b  83c004               add eax, 4
// 0045500e  83c9ff               or ecx, 0xffffffff
// 00455011  f00fc108             lock xadd dword ptr [eax], ecx
// 00455015  751e                 jne 0x455035
// 00455017  8b16                 mov edx, dword ptr [esi]
// 00455019  8b4204               mov eax, dword ptr [edx + 4]
// 0045501c  8bce                 mov ecx, esi
// 0045501e  ffd0                 call eax
// 00455020  8d4e08               lea ecx, [esi + 8]
// 00455023  83caff               or edx, 0xffffffff
// 00455026  f00fc111             lock xadd dword ptr [ecx], edx
// 0045502a  7509                 jne 0x455035
// 0045502c  8b06                 mov eax, dword ptr [esi]
// 0045502e  8b5008               mov edx, dword ptr [eax + 8]
// 00455031  8bce                 mov ecx, esi
// 00455033  ffd2                 call edx
// 00455035  8d4c2418             lea ecx, [esp + 0x18]
// 00455039  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 00455041  e87a231200           call 0x5773c0
// 00455046  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0045504a  5f                   pop edi
// 0045504b  64890d00000000       mov dword ptr fs:[0], ecx
// 00455052  5e                   pop esi
// 00455053  83c428               add esp, 0x28
// 00455056  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
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

struct State
{
    bool query();
};

struct Object
{
    State* state();
};

struct SharedSource
{
    Object* pointer;
    Object* get() const { return pointer; }
    Control* control;
    ~SharedSource();
};

struct Shared
{
    Object* pointer;
    Object* get() const { return pointer; }
    Control* control;
    Shared(const SharedSource& other);
    ~Shared();
};

Shared::Shared(const SharedSource& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

SharedSource::~SharedSource()
{
    if (control)
    {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

Shared::~Shared()
{
    if (control)
    {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Provider
{
    SharedSource get();
};

struct Guard
{
    unsigned long storage[3];
    Guard(Shared value);
    ~Guard();
};

struct Output
{
    virtual void set(int value) = 0;
};

struct S
{
    unsigned char padding[0x94];
    Provider* provider;
    Shared get();
    void f(Output* output);
};

void S::f(Output* output)
{
    Guard guard(provider->get());
    output->set(get().get()->state()->query() != 0);
}
