// from server: 100% by Intel
// from server: 99% by EspClaude
// roc 2007-08 00441d40  unit: RBX::VSoundId::?$XItem  size: 170 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00441d40
//
// 00441d40  6aff                 push -1
// 00441d42  6898d97300           push 0x73d998
// 00441d47  64a100000000         mov eax, dword ptr fs:[0]
// 00441d4d  50                   push eax
// 00441d4e  83ec08               sub esp, 8
// 00441d51  56                   push esi
// 00441d52  a188518b00           mov eax, dword ptr [0x8b5188]
// 00441d57  33c4                 xor eax, esp
// 00441d59  50                   push eax
// 00441d5a  8d442410             lea eax, [esp + 0x10]
// 00441d5e  64a300000000         mov dword ptr fs:[0], eax
// 00441d64  8bf1                 mov esi, ecx
// 00441d66  8b442420             mov eax, dword ptr [esp + 0x20]
// 00441d6a  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00441d6d  50                   push eax
// 00441d6e  8d54240c             lea edx, [esp + 0xc]
// 00441d72  52                   push edx
// 00441d73  894c2428             mov dword ptr [esp + 0x28], ecx
// 00441d77  e8f4b80500           call 0x49d670
// 00441d7c  83c408               add esp, 8
// 00441d7f  50                   push eax
// 00441d80  8d442424             lea eax, [esp + 0x24]
// 00441d84  50                   push eax
// 00441d85  8bce                 mov ecx, esi
// 00441d87  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00441d8f  e80cfdffff           call 0x441aa0
// 00441d94  8bc8                 mov ecx, eax
// 00441d96  e87526feff           call 0x424410
// 00441d9b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00441d9f  85c0                 test eax, eax
// 00441da1  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00441da9  742c                 je 0x441dd7
// 00441dab  8bf0                 mov esi, eax
// 00441dad  83c004               add eax, 4
// 00441db0  83c9ff               or ecx, 0xffffffff
// 00441db3  f00fc108             lock xadd dword ptr [eax], ecx
// 00441db7  751e                 jne 0x441dd7
// 00441db9  8b16                 mov edx, dword ptr [esi]
// 00441dbb  8b4204               mov eax, dword ptr [edx + 4]
// 00441dbe  8bce                 mov ecx, esi
// 00441dc0  ffd0                 call eax
// 00441dc2  8d4e08               lea ecx, [esi + 8]
// 00441dc5  83caff               or edx, 0xffffffff
// 00441dc8  f00fc111             lock xadd dword ptr [ecx], edx
// 00441dcc  7509                 jne 0x441dd7
// 00441dce  8b06                 mov eax, dword ptr [esi]
// 00441dd0  8b5008               mov edx, dword ptr [eax + 8]
// 00441dd3  8bce                 mov ecx, esi
// 00441dd5  ffd2                 call edx
// 00441dd7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00441ddb  64890d00000000       mov dword ptr fs:[0], ecx
// 00441de2  59                   pop ecx
// 00441de3  5e                   pop esi
// 00441de4  83c414               add esp, 0x14
// 00441de7  c20400               ret 4

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
    char padding[0xc];
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
