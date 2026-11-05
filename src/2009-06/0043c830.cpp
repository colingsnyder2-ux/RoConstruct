// from server: 100% by EspClaude
// roc 2009-06 0043c830  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043c830
//
// 0043c830  6aff                 push -1
// 0043c832  68e8a68600           push 0x86a6e8
// 0043c837  64a100000000         mov eax, dword ptr fs:[0]
// 0043c83d  50                   push eax
// 0043c83e  64892500000000       mov dword ptr fs:[0], esp
// 0043c845  83ec08               sub esp, 8
// 0043c848  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043c84c  56                   push esi
// 0043c84d  8bf1                 mov esi, ecx
// 0043c84f  8b481c               mov ecx, dword ptr [eax + 0x1c]
// 0043c852  50                   push eax
// 0043c853  8d542408             lea edx, [esp + 8]
// 0043c857  52                   push edx
// 0043c858  894c2424             mov dword ptr [esp + 0x24], ecx
// 0043c85c  e84fc11c00           call 0x6089b0
// 0043c861  83c408               add esp, 8
// 0043c864  50                   push eax
// 0043c865  8d442420             lea eax, [esp + 0x20]
// 0043c869  50                   push eax
// 0043c86a  8bce                 mov ecx, esi
// 0043c86c  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0043c874  e8a7fdffff           call 0x43c620
// 0043c879  8bc8                 mov ecx, eax
// 0043c87b  e840282d00           call 0x70f0c0
// 0043c880  8b442408             mov eax, dword ptr [esp + 8]
// 0043c884  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0043c88c  85c0                 test eax, eax
// 0043c88e  742c                 je 0x43c8bc
// 0043c890  8bf0                 mov esi, eax
// 0043c892  83c004               add eax, 4
// 0043c895  83c9ff               or ecx, 0xffffffff
// 0043c898  f00fc108             lock xadd dword ptr [eax], ecx
// 0043c89c  751e                 jne 0x43c8bc
// 0043c89e  8b16                 mov edx, dword ptr [esi]
// 0043c8a0  8b4204               mov eax, dword ptr [edx + 4]
// 0043c8a3  8bce                 mov ecx, esi
// 0043c8a5  ffd0                 call eax
// 0043c8a7  8d4e08               lea ecx, [esi + 8]
// 0043c8aa  83caff               or edx, 0xffffffff
// 0043c8ad  f00fc111             lock xadd dword ptr [ecx], edx
// 0043c8b1  7509                 jne 0x43c8bc
// 0043c8b3  8b06                 mov eax, dword ptr [esi]
// 0043c8b5  8b5008               mov edx, dword ptr [eax + 8]
// 0043c8b8  8bce                 mov ecx, esi
// 0043c8ba  ffd2                 call edx
// 0043c8bc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0043c8c0  5e                   pop esi
// 0043c8c1  64890d00000000       mov dword ptr fs:[0], ecx
// 0043c8c8  83c414               add esp, 0x14
// 0043c8cb  c20400               ret 4
// copied from an identical function in another client (function ?update@TextureItem@ns_ROCX000000@@QAEXPAUSource@2@@Z)

namespace ns_ROCX000000 {
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
}
