// from server: 94% by EspClaude
// from server: 100% by colin
// roc 2008-06 005bd4f0  unit: VStockSound::?$FactoryProduct  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bd4f0
//
// 005bd4f0  83ec08               sub esp, 8
// 005bd4f3  56                   push esi
// 005bd4f4  8bf1                 mov esi, ecx
// 005bd4f6  56                   push esi
// 005bd4f7  e8b4f9ffff           call 0x5bceb0
// 005bd4fc  8b8668010000         mov eax, dword ptr [esi + 0x168]
// 005bd502  40                   inc eax
// 005bd503  89442408             mov dword ptr [esp + 8], eax
// 005bd507  83f801               cmp eax, 1
// 005bd50a  c744240401000000     mov dword ptr [esp + 4], 1
// 005bd512  8d442404             lea eax, [esp + 4]
// 005bd516  7c04                 jl 0x5bd51c
// 005bd518  8d442408             lea eax, [esp + 8]
// 005bd51c  8b00                 mov eax, dword ptr [eax]
// 005bd51e  6810709700           push 0x977010
// 005bd523  8bce                 mov ecx, esi
// 005bd525  898668010000         mov dword ptr [esi + 0x168], eax
// 005bd52b  e8d005e5ff           call 0x40db00
// 005bd530  5e                   pop esi
// 005bd531  83c408               add esp, 8
// 005bd534  c3                   ret 

struct VStockSound {
    char pad[0x168];
    int field168;
    void method();
};

struct VMember {
    void set(const char*);
};

extern "C" void __stdcall sub_5bceb0(void*);

void VStockSound::method() {
    sub_5bceb0(this);
    int v = field168 + 1;
    int one = 1;
    int* p;
    if (v < 1)
        p = &one;
    else
        p = &v;
    field168 = *p;
    ((VMember*)this)->set((const char*)0x977010);
}
