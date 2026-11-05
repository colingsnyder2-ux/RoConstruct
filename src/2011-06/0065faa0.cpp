// from server: 100% by Yeetserama
// roc 2011-06 0065faa0  unit: RBX::IStepped  size: 198 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0065faa0
//
// 0065faa0  6aff                 push -1
// 0065faa2  6840d99e00           push 0x9ed940
// 0065faa7  64a100000000         mov eax, dword ptr fs:[0]
// 0065faad  50                   push eax
// 0065faae  64892500000000       mov dword ptr fs:[0], esp
// 0065fab5  83ec28               sub esp, 0x28
// 0065fab8  56                   push esi
// 0065fab9  833900               cmp dword ptr [ecx], 0
// 0065fabc  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0065fac4  7514                 jne 0x65fada
// 0065fac6  8d4c2404             lea ecx, [esp + 4]
// 0065faca  e8c1b0daff           call 0x40ab90
// 0065facf  50                   push eax
// 0065fad0  c644243801           mov byte ptr [esp + 0x38], 1
// 0065fad5  e896dedaff           call 0x40d970
// 0065fada  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0065fade  d9442444             fld dword ptr [esp + 0x44]
// 0065fae2  83ec0c               sub esp, 0xc
// 0065fae5  8bc4                 mov eax, esp
// 0065fae7  d95c2408             fstp dword ptr [esp + 8]
// 0065faeb  8910                 mov dword ptr [eax], edx
// 0065faed  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 0065faf1  895004               mov dword ptr [eax + 4], edx
// 0065faf4  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0065faf8  89642450             mov dword ptr [esp + 0x50], esp
// 0065fafc  85c0                 test eax, eax
// 0065fafe  740c                 je 0x65fb0c
// 0065fb00  83c004               add eax, 4
// 0065fb03  ba01000000           mov edx, 1
// 0065fb08  f00fc110             lock xadd dword ptr [eax], edx
// 0065fb0c  8b01                 mov eax, dword ptr [ecx]
// 0065fb0e  83c108               add ecx, 8
// 0065fb11  51                   push ecx
// 0065fb12  8b4804               mov ecx, dword ptr [eax + 4]
// 0065fb15  ffd1                 call ecx
// 0065fb17  8b742450             mov esi, dword ptr [esp + 0x50]
// 0065fb1b  83c410               add esp, 0x10
// 0065fb1e  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 0065fb26  85f6                 test esi, esi
// 0065fb28  742a                 je 0x65fb54
// 0065fb2a  8d5604               lea edx, [esi + 4]
// 0065fb2d  83c8ff               or eax, 0xffffffff
// 0065fb30  f00fc102             lock xadd dword ptr [edx], eax
// 0065fb34  751e                 jne 0x65fb54
// 0065fb36  8b16                 mov edx, dword ptr [esi]
// 0065fb38  8b4204               mov eax, dword ptr [edx + 4]
// 0065fb3b  8bce                 mov ecx, esi
// 0065fb3d  ffd0                 call eax
// 0065fb3f  8d4e08               lea ecx, [esi + 8]
// 0065fb42  83caff               or edx, 0xffffffff
// 0065fb45  f00fc111             lock xadd dword ptr [ecx], edx
// 0065fb49  7509                 jne 0x65fb54
// 0065fb4b  8b06                 mov eax, dword ptr [esi]
// 0065fb4d  8b5008               mov edx, dword ptr [eax + 8]
// 0065fb50  8bce                 mov ecx, esi
// 0065fb52  ffd2                 call edx
// 0065fb54  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0065fb58  64890d00000000       mov dword ptr fs:[0], ecx
// 0065fb5f  5e                   pop esi
// 0065fb60  83c434               add esp, 0x34
// 0065fb63  c20c00               ret 0xc
// copied from an identical function in another client (function ?f@S@ns_ROCX000005@@QAEXUShared@2@M@Z)

namespace ns_ROCX000005 {
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

struct Shared
{
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
    {
        volatile long* count = &control->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

__forceinline Shared::~Shared()
{
    if (control)
        control->release();
}

struct EmptyCall
{
    char storage[40];

    EmptyCall();
    ~EmptyCall();
};

__declspec(noreturn) void __cdecl throwEmpty(const EmptyCall&);

struct Table
{
    void* unused;
    void (__cdecl *invoke)(void*, Shared, float);
};

struct S
{
    Table* table;
    unsigned long reserved;
    unsigned char bound[1];

    void f(Shared, float);
};

void S::f(Shared value, float number)
{
    if (!table)
        throwEmpty(EmptyCall());

    table->invoke(bound, value, number);
}
}
