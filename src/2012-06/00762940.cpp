// from server: 100% by Xemicl
// roc 2012-06 00762940  unit: RBX::Explosion::W4ExplosionType::?$EnumDesc  size: 198 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00762940
//
// 00762940  6aff                 push -1
// 00762942  6850b9aa00           push 0xaab950
// 00762947  64a100000000         mov eax, dword ptr fs:[0]
// 0076294d  50                   push eax
// 0076294e  64892500000000       mov dword ptr fs:[0], esp
// 00762955  83ec28               sub esp, 0x28
// 00762958  56                   push esi
// 00762959  833900               cmp dword ptr [ecx], 0
// 0076295c  c744243400000000     mov dword ptr [esp + 0x34], 0
// 00762964  7514                 jne 0x76297a
// 00762966  8d4c2404             lea ecx, [esp + 4]
// 0076296a  e87199caff           call 0x40c2e0
// 0076296f  50                   push eax
// 00762970  c644243801           mov byte ptr [esp + 0x38], 1
// 00762975  e846cbcaff           call 0x40f4c0
// 0076297a  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0076297e  d9442444             fld dword ptr [esp + 0x44]
// 00762982  83ec0c               sub esp, 0xc
// 00762985  8bc4                 mov eax, esp
// 00762987  d95c2408             fstp dword ptr [esp + 8]
// 0076298b  8910                 mov dword ptr [eax], edx
// 0076298d  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 00762991  895004               mov dword ptr [eax + 4], edx
// 00762994  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 00762998  89642450             mov dword ptr [esp + 0x50], esp
// 0076299c  85c0                 test eax, eax
// 0076299e  740c                 je 0x7629ac
// 007629a0  83c004               add eax, 4
// 007629a3  ba01000000           mov edx, 1
// 007629a8  f00fc110             lock xadd dword ptr [eax], edx
// 007629ac  8b01                 mov eax, dword ptr [ecx]
// 007629ae  83c108               add ecx, 8
// 007629b1  51                   push ecx
// 007629b2  8b4804               mov ecx, dword ptr [eax + 4]
// 007629b5  ffd1                 call ecx
// 007629b7  8b742450             mov esi, dword ptr [esp + 0x50]
// 007629bb  83c410               add esp, 0x10
// 007629be  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 007629c6  85f6                 test esi, esi
// 007629c8  742a                 je 0x7629f4
// 007629ca  8d5604               lea edx, [esi + 4]
// 007629cd  83c8ff               or eax, 0xffffffff
// 007629d0  f00fc102             lock xadd dword ptr [edx], eax
// 007629d4  751e                 jne 0x7629f4
// 007629d6  8b16                 mov edx, dword ptr [esi]
// 007629d8  8b4204               mov eax, dword ptr [edx + 4]
// 007629db  8bce                 mov ecx, esi
// 007629dd  ffd0                 call eax
// 007629df  8d4e08               lea ecx, [esi + 8]
// 007629e2  83caff               or edx, 0xffffffff
// 007629e5  f00fc111             lock xadd dword ptr [ecx], edx
// 007629e9  7509                 jne 0x7629f4
// 007629eb  8b06                 mov eax, dword ptr [esi]
// 007629ed  8b5008               mov edx, dword ptr [eax + 8]
// 007629f0  8bce                 mov ecx, esi
// 007629f2  ffd2                 call edx
// 007629f4  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007629f8  64890d00000000       mov dword ptr fs:[0], ecx
// 007629ff  5e                   pop esi
// 00762a00  83c434               add esp, 0x34
// 00762a03  c20c00               ret 0xc
// copied from an identical function in another client (function ?f@S@ns_ROCX000002@@QAEXUShared@2@M@Z)

namespace ns_ROCX000002 {
// from server: 92% by king_originala
// roc 2008-06 0062a1c0  unit: RBX::VNetworkSettings::?$BoundPropGetSet  size: 198 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0062a1c0
//
// 0062a1c0  6aff                 push -1
// 0062a1c2  6880987d00           push 0x7d9880
// 0062a1c7  64a100000000         mov eax, dword ptr fs:[0]
// 0062a1cd  50                   push eax
// 0062a1ce  64892500000000       mov dword ptr fs:[0], esp
// 0062a1d5  83ec28               sub esp, 0x28
// 0062a1d8  56                   push esi
// 0062a1d9  833900               cmp dword ptr [ecx], 0
// 0062a1dc  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0062a1e4  7514                 jne 0x62a1fa
// 0062a1e6  8d4c2404             lea ecx, [esp + 4]
// 0062a1ea  e801fdddff           call 0x409ef0
// 0062a1ef  50                   push eax
// 0062a1f0  c644243801           mov byte ptr [esp + 0x38], 1
// 0062a1f5  e80603deff           call 0x40a500
// 0062a1fa  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0062a1fe  d9442444             fld dword ptr [esp + 0x44]
// 0062a202  83ec0c               sub esp, 0xc
// 0062a205  8bc4                 mov eax, esp
// 0062a207  d95c2408             fstp dword ptr [esp + 8]
// 0062a20b  8910                 mov dword ptr [eax], edx
// 0062a20d  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 0062a211  895004               mov dword ptr [eax + 4], edx
// 0062a214  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0062a218  89642450             mov dword ptr [esp + 0x50], esp
// 0062a21c  85c0                 test eax, eax
// 0062a21e  740c                 je 0x62a22c
// 0062a220  83c004               add eax, 4
// 0062a223  ba01000000           mov edx, 1
// 0062a228  f00fc110             lock xadd dword ptr [eax], edx
// 0062a22c  8b01                 mov eax, dword ptr [ecx]
// 0062a22e  83c108               add ecx, 8
// 0062a231  51                   push ecx
// 0062a232  8b4804               mov ecx, dword ptr [eax + 4]
// 0062a235  ffd1                 call ecx
// 0062a237  8b742450             mov esi, dword ptr [esp + 0x50]
// 0062a23b  83c410               add esp, 0x10
// 0062a23e  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 0062a246  85f6                 test esi, esi
// 0062a248  742a                 je 0x62a274
// 0062a24a  8d5604               lea edx, [esi + 4]
// 0062a24d  83c8ff               or eax, 0xffffffff
// 0062a250  f00fc102             lock xadd dword ptr [edx], eax
// 0062a254  751e                 jne 0x62a274
// 0062a256  8b16                 mov edx, dword ptr [esi]
// 0062a258  8b4204               mov eax, dword ptr [edx + 4]
// 0062a25b  8bce                 mov ecx, esi
// 0062a25d  ffd0                 call eax
// 0062a25f  8d4e08               lea ecx, [esi + 8]
// 0062a262  83caff               or edx, 0xffffffff
// 0062a265  f00fc111             lock xadd dword ptr [ecx], edx
// 0062a269  7509                 jne 0x62a274
// 0062a26b  8b06                 mov eax, dword ptr [esi]
// 0062a26d  8b5008               mov edx, dword ptr [eax + 8]
// 0062a270  8bce                 mov ecx, esi
// 0062a272  ffd2                 call edx
// 0062a274  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0062a278  64890d00000000       mov dword ptr fs:[0], ecx
// 0062a27f  5e                   pop esi
// 0062a280  83c434               add esp, 0x34
// 0062a283  c20c00               ret 0xc

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