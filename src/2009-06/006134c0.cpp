// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00497740  unit: RBX::Network::Players  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00497740
//
// 00497740  6aff                 push -1
// 00497742  6838077d00           push 0x7d0738
// 00497747  64a100000000         mov eax, dword ptr fs:[0]
// 0049774d  50                   push eax
// 0049774e  64892500000000       mov dword ptr fs:[0], esp
// 00497755  51                   push ecx
// 00497756  56                   push esi
// 00497757  8bf1                 mov esi, ecx
// 00497759  89742404             mov dword ptr [esp + 4], esi
// 0049775d  8d4e08               lea ecx, [esi + 8]
// 00497760  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00497768  ff1568248000         call dword ptr [0x802468]
// 0049776e  8b7604               mov esi, dword ptr [esi + 4]
// 00497771  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00497779  85f6                 test esi, esi
// 0049777b  742a                 je 0x4977a7
// 0049777d  8d4604               lea eax, [esi + 4]
// 00497780  83c9ff               or ecx, 0xffffffff
// 00497783  f00fc108             lock xadd dword ptr [eax], ecx
// 00497787  751e                 jne 0x4977a7
// 00497789  8b16                 mov edx, dword ptr [esi]
// 0049778b  8b4204               mov eax, dword ptr [edx + 4]
// 0049778e  8bce                 mov ecx, esi
// 00497790  ffd0                 call eax
// 00497792  8d4e08               lea ecx, [esi + 8]
// 00497795  83caff               or edx, 0xffffffff
// 00497798  f00fc111             lock xadd dword ptr [ecx], edx
// 0049779c  7509                 jne 0x4977a7
// 0049779e  8b06                 mov eax, dword ptr [esi]
// 004977a0  8b5008               mov edx, dword ptr [eax + 8]
// 004977a3  8bce                 mov ecx, esi
// 004977a5  ffd2                 call edx
// 004977a7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004977ab  5e                   pop esi
// 004977ac  64890d00000000       mov dword ptr fs:[0], ecx
// 004977b3  83c410               add esp, 0x10
// 004977b6  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern void (__thiscall *destroy_string)(void*);

struct Control {
    virtual void reserved() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    ~Shared();
};

struct String {
    char storage[28];
    ~String();
};

struct S {
    Shared shared;
    String text;
    ~S();
};

__forceinline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

__forceinline String::~String()
{
    destroy_string(this);
}

S::~S()
{
}
