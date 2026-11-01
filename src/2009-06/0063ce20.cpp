// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005b1190  unit: RBX::Accoutrement  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b1190
//
// 005b1190  64a100000000         mov eax, dword ptr fs:[0]
// 005b1196  6aff                 push -1
// 005b1198  6868617c00           push 0x7c6168
// 005b119d  50                   push eax
// 005b119e  64892500000000       mov dword ptr fs:[0], esp
// 005b11a5  56                   push esi
// 005b11a6  8bf1                 mov esi, ecx
// 005b11a8  8b442414             mov eax, dword ptr [esp + 0x14]
// 005b11ac  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 005b11b4  3bc6                 cmp eax, esi
// 005b11b6  7422                 je 0x5b11da
// 005b11b8  3b8634010000         cmp eax, dword ptr [esi + 0x134]
// 005b11be  7513                 jne 0x5b11d3
// 005b11c0  56                   push esi
// 005b11c1  e80a87edff           call 0x4898d0
// 005b11c6  83c404               add esp, 4
// 005b11c9  50                   push eax
// 005b11ca  6a00                 push 0
// 005b11cc  8bce                 mov ecx, esi
// 005b11ce  e83d130000           call 0x5b2510
// 005b11d3  8bce                 mov ecx, esi
// 005b11d5  e8c6feffff           call 0x5b10a0
// 005b11da  8b742418             mov esi, dword ptr [esp + 0x18]
// 005b11de  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 005b11e6  85f6                 test esi, esi
// 005b11e8  742a                 je 0x5b1214
// 005b11ea  8d4604               lea eax, [esi + 4]
// 005b11ed  83c9ff               or ecx, 0xffffffff
// 005b11f0  f00fc108             lock xadd dword ptr [eax], ecx
// 005b11f4  751e                 jne 0x5b1214
// 005b11f6  8b16                 mov edx, dword ptr [esi]
// 005b11f8  8b4204               mov eax, dword ptr [edx + 4]
// 005b11fb  8bce                 mov ecx, esi
// 005b11fd  ffd0                 call eax
// 005b11ff  8d4e08               lea ecx, [esi + 8]
// 005b1202  83caff               or edx, 0xffffffff
// 005b1205  f00fc111             lock xadd dword ptr [ecx], edx
// 005b1209  7509                 jne 0x5b1214
// 005b120b  8b06                 mov eax, dword ptr [esi]
// 005b120d  8b5008               mov edx, dword ptr [eax + 8]
// 005b1210  8bce                 mov ecx, esi
// 005b1212  ffd2                 call edx
// 005b1214  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b1218  64890d00000000       mov dword ptr fs:[0], ecx
// 005b121f  5e                   pop esi
// 005b1220  83c40c               add esp, 0xc
// 005b1223  c20800               ret 8

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Accoutrement;

struct Shared {
    Accoutrement* pointer;
    Control* control;
    ~Shared();
};

extern Accoutrement* __cdecl helper(Accoutrement*);

struct Accoutrement {
    char padding[0x90];
    Accoutrement* attached;
    void update();
    void change(int, Accoutrement*);
    void f(Shared value);
};

inline Shared::~Shared() {
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

void Accoutrement::f(Shared value) {
    if (value.pointer != this) {
        if (value.pointer == attached)
            change(0, helper(this));
        update();
    }
}
