// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00442350  unit: TextureItem  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00442350
//
// 00442350  6aff                 push -1
// 00442352  6868917d00           push 0x7d9168
// 00442357  64a100000000         mov eax, dword ptr fs:[0]
// 0044235d  50                   push eax
// 0044235e  64892500000000       mov dword ptr fs:[0], esp
// 00442365  83ec08               sub esp, 8
// 00442368  8b442418             mov eax, dword ptr [esp + 0x18]
// 0044236c  56                   push esi
// 0044236d  8bf1                 mov esi, ecx
// 0044236f  8b481c               mov ecx, dword ptr [eax + 0x1c]
// 00442372  50                   push eax
// 00442373  8d542408             lea edx, [esp + 8]
// 00442377  52                   push edx
// 00442378  894c2424             mov dword ptr [esp + 0x24], ecx
// 0044237c  e8bf661d00           call 0x618a40
// 00442381  83c408               add esp, 8
// 00442384  50                   push eax
// 00442385  8d442420             lea eax, [esp + 0x20]
// 00442389  50                   push eax
// 0044238a  8bce                 mov ecx, esi
// 0044238c  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00442394  e8a7fdffff           call 0x442140
// 00442399  8bc8                 mov ecx, eax
// 0044239b  e870ddfdff           call 0x420110
// 004423a0  8b442408             mov eax, dword ptr [esp + 8]
// 004423a4  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004423ac  85c0                 test eax, eax
// 004423ae  742c                 je 0x4423dc
// 004423b0  8bf0                 mov esi, eax
// 004423b2  83c004               add eax, 4
// 004423b5  83c9ff               or ecx, 0xffffffff
// 004423b8  f00fc108             lock xadd dword ptr [eax], ecx
// 004423bc  751e                 jne 0x4423dc
// 004423be  8b16                 mov edx, dword ptr [esi]
// 004423c0  8b4204               mov eax, dword ptr [edx + 4]
// 004423c3  8bce                 mov ecx, esi
// 004423c5  ffd0                 call eax
// 004423c7  8d4e08               lea ecx, [esi + 8]
// 004423ca  83caff               or edx, 0xffffffff
// 004423cd  f00fc111             lock xadd dword ptr [ecx], edx
// 004423d1  7509                 jne 0x4423dc
// 004423d3  8b06                 mov eax, dword ptr [esi]
// 004423d5  8b5008               mov edx, dword ptr [eax + 8]
// 004423d8  8bce                 mov ecx, esi
// 004423da  ffd2                 call edx
// 004423dc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004423e0  5e                   pop esi
// 004423e1  64890d00000000       mov dword ptr fs:[0], ecx
// 004423e8  83c414               add esp, 0x14
// 004423eb  c20400               ret 4

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

struct Shared {
    void* object;
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

struct Source {
    char padding[28];
    int key;
};

Shared __cdecl makeShared(Source* source);

struct Result {
    void apply();
};

struct TextureItem {
    Result* find(const int* key, const Shared& value);
    void update(Source* source);
};

void TextureItem::update(Source* source)
{
    int key = source->key;
    find(&key, makeShared(source))->apply();
}
