// from server: 100% by EspClaude
// from server: 99% by EspClaude
// roc 2009-06 006273a0  unit: RBX::Tool  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006273a0
//
// 006273a0  64a100000000         mov eax, dword ptr fs:[0]
// 006273a6  6aff                 push -1
// 006273a8  6838938500           push 0x859338
// 006273ad  50                   push eax
// 006273ae  64892500000000       mov dword ptr fs:[0], esp
// 006273b5  56                   push esi
// 006273b6  8bf1                 mov esi, ecx
// 006273b8  56                   push esi
// 006273b9  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006273c1  e80ac4e8ff           call 0x4b37d0
// 006273c6  83c404               add esp, 4
// 006273c9  85c0                 test eax, eax
// 006273cb  742a                 je 0x6273f7
// 006273cd  8b442414             mov eax, dword ptr [esp + 0x14]
// 006273d1  3bc6                 cmp eax, esi
// 006273d3  7422                 je 0x6273f7
// 006273d5  3b8600010000         cmp eax, dword ptr [esi + 0x100]
// 006273db  7513                 jne 0x6273f0
// 006273dd  56                   push esi
// 006273de  e8edc3e8ff           call 0x4b37d0
// 006273e3  83c404               add esp, 4
// 006273e6  50                   push eax
// 006273e7  6a04                 push 4
// 006273e9  8bce                 mov ecx, esi
// 006273eb  e810330000           call 0x62a700
// 006273f0  8bce                 mov ecx, esi
// 006273f2  e8d9feffff           call 0x6272d0
// 006273f7  8b742418             mov esi, dword ptr [esp + 0x18]
// 006273fb  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 00627403  85f6                 test esi, esi
// 00627405  742a                 je 0x627431
// 00627407  8d4604               lea eax, [esi + 4]
// 0062740a  83c9ff               or ecx, 0xffffffff
// 0062740d  f00fc108             lock xadd dword ptr [eax], ecx
// 00627411  751e                 jne 0x627431
// 00627413  8b16                 mov edx, dword ptr [esi]
// 00627415  8b4204               mov eax, dword ptr [edx + 4]
// 00627418  8bce                 mov ecx, esi
// 0062741a  ffd0                 call eax
// 0062741c  8d4e08               lea ecx, [esi + 8]
// 0062741f  83caff               or edx, 0xffffffff
// 00627422  f00fc111             lock xadd dword ptr [ecx], edx
// 00627426  7509                 jne 0x627431
// 00627428  8b06                 mov eax, dword ptr [esi]
// 0062742a  8b5008               mov edx, dword ptr [eax + 8]
// 0062742d  8bce                 mov ecx, esi
// 0062742f  ffd2                 call edx
// 00627431  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00627435  64890d00000000       mov dword ptr fs:[0], ecx
// 0062743c  5e                   pop esi
// 0062743d  83c40c               add esp, 0xc
// 00627440  c20800               ret 8

// from server: 100% by colin
// roc 2008-06 005fdc40  unit: RBX::Tool  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fdc40
//
// 005fdc40  64a100000000         mov eax, dword ptr fs:[0]
// 005fdc46  6aff                 push -1
// 005fdc48  6868617c00           push 0x7c6168
// 005fdc4d  50                   push eax
// 005fdc4e  64892500000000       mov dword ptr fs:[0], esp
// 005fdc55  56                   push esi
// 005fdc56  8bf1                 mov esi, ecx
// 005fdc58  56                   push esi
// 005fdc59  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005fdc61  e86abce8ff           call 0x4898d0
// 005fdc66  83c404               add esp, 4
// 005fdc69  85c0                 test eax, eax
// 005fdc6b  742a                 je 0x5fdc97
// 005fdc6d  8b442414             mov eax, dword ptr [esp + 0x14]
// 005fdc71  3bc6                 cmp eax, esi
// 005fdc73  7422                 je 0x5fdc97
// 005fdc75  3b86a4010000         cmp eax, dword ptr [esi + 0x1a4]
// 005fdc7b  7513                 jne 0x5fdc90
// 005fdc7d  56                   push esi
// 005fdc7e  e84dbce8ff           call 0x4898d0
// 005fdc83  83c404               add esp, 4
// 005fdc86  50                   push eax
// 005fdc87  6a04                 push 4
// 005fdc89  8bce                 mov ecx, esi
// 005fdc8b  e8701c0000           call 0x5ff900
// 005fdc90  8bce                 mov ecx, esi
// 005fdc92  e8d9feffff           call 0x5fdb70
// 005fdc97  8b742418             mov esi, dword ptr [esp + 0x18]
// 005fdc9b  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 005fdca3  85f6                 test esi, esi
// 005fdca5  742a                 je 0x5fdcd1
// 005fdca7  8d4604               lea eax, [esi + 4]
// 005fdcaa  83c9ff               or ecx, 0xffffffff
// 005fdcad  f00fc108             lock xadd dword ptr [eax], ecx
// 005fdcb1  751e                 jne 0x5fdcd1
// 005fdcb3  8b16                 mov edx, dword ptr [esi]
// 005fdcb5  8b4204               mov eax, dword ptr [edx + 4]
// 005fdcb8  8bce                 mov ecx, esi
// 005fdcba  ffd0                 call eax
// 005fdcbc  8d4e08               lea ecx, [esi + 8]
// 005fdcbf  83caff               or edx, 0xffffffff
// 005fdcc2  f00fc111             lock xadd dword ptr [ecx], edx
// 005fdcc6  7509                 jne 0x5fdcd1
// 005fdcc8  8b06                 mov eax, dword ptr [esi]
// 005fdcca  8b5008               mov edx, dword ptr [eax + 8]
// 005fdccd  8bce                 mov ecx, esi
// 005fdccf  ffd2                 call edx
// 005fdcd1  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005fdcd5  64890d00000000       mov dword ptr fs:[0], ecx
// 005fdcdc  5e                   pop esi
// 005fdcdd  83c40c               add esp, 0xc
// 005fdce0  c20800               ret 8

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


struct RefCount {
    virtual ~RefCount();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    RefCount* count;
    ~Shared();
};

__forceinline Shared::~Shared() {
    RefCount* p = count;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Tool {
    char pad[0x100];
    void* field_1a4;

    void f(Shared value);
    void method_5d4650(int, int);
    void method_5d2200();
};

extern "C" int __cdecl sub_486830(Tool*);

void Tool::f(Shared value) {
    if (sub_486830(this) && value.object != this) {
        if (value.object == field_1a4)
            method_5d4650(4, sub_486830(this));
        method_5d2200();
    }
}
