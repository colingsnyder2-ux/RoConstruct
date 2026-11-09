// from server: 100% by Intel
// from server: 97% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 004423f0  unit: TextureItem  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004423f0
//
// 004423f0  64a100000000         mov eax, dword ptr fs:[0]
// 004423f6  6aff                 push -1
// 004423f8  6868617c00           push 0x7c6168
// 004423fd  50                   push eax
// 004423fe  64892500000000       mov dword ptr fs:[0], esp
// 00442405  56                   push esi
// 00442406  8bf1                 mov esi, ecx
// 00442408  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044240c  50                   push eax
// 0044240d  8d8e18020000         lea ecx, [esi + 0x218]
// 00442413  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0044241b  e830ffffff           call 0x442350
// 00442420  85f6                 test esi, esi
// 00442422  7408                 je 0x44242c
// 00442424  8d8688010000         lea eax, [esi + 0x188]
// 0044242a  eb02                 jmp 0x44242e
// 0044242c  33c0                 xor eax, eax
// 0044242e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00442432  85c9                 test ecx, ecx
// 00442434  740c                 je 0x442442
// 00442436  50                   push eax
// 00442437  81c1c4000000         add ecx, 0xc4
// 0044243d  e85ef4fdff           call 0x4218a0
// 00442442  8b742418             mov esi, dword ptr [esp + 0x18]
// 00442446  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 0044244e  85f6                 test esi, esi
// 00442450  742a                 je 0x44247c
// 00442452  8d4e04               lea ecx, [esi + 4]
// 00442455  83caff               or edx, 0xffffffff
// 00442458  f00fc111             lock xadd dword ptr [ecx], edx
// 0044245c  751e                 jne 0x44247c
// 0044245e  8b06                 mov eax, dword ptr [esi]
// 00442460  8b5004               mov edx, dword ptr [eax + 4]
// 00442463  8bce                 mov ecx, esi
// 00442465  ffd2                 call edx
// 00442467  8d4608               lea eax, [esi + 8]
// 0044246a  83c9ff               or ecx, 0xffffffff
// 0044246d  f00fc108             lock xadd dword ptr [eax], ecx
// 00442471  7509                 jne 0x44247c
// 00442473  8b16                 mov edx, dword ptr [esi]
// 00442475  8b4208               mov eax, dword ptr [edx + 8]
// 00442478  8bce                 mov ecx, esi
// 0044247a  ffd0                 call eax
// 0044247c  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00442480  64890d00000000       mov dword ptr fs:[0], ecx
// 00442487  5e                   pop esi
// 00442488  83c40c               add esp, 0xc
// 0044248b  c20800               ret 8

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

struct Base {
    char padding[0x48];
};

struct Listener {
    void bind(Base* value);
};

struct Source {
    char padding[0x8c];
    Listener listener;
};

struct Shared {
    Source* object;
    Control* control;
    ~Shared();
};

__forceinline Shared::~Shared()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Helper {
    void update(Source* source);
};

struct Prefix {
    char padding[0x17c];
};

struct TextureItem : Prefix, Base {
    Helper helper;
    void update(Shared value);
};

void TextureItem::update(Shared value)
{
    helper.update(value.object);
    Base* base = this;
    if (value.object)
        value.object->listener.bind(base);
}
