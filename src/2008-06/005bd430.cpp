// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 79% by colin
// roc 2008-06 005bd430  unit: VStockSound::?$FactoryProduct  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bd430
//
// 005bd430  d9ee                 fldz 
// 005bd432  56                   push esi
// 005bd433  d9442408             fld dword ptr [esp + 8]
// 005bd437  8bf1                 mov esi, ecx
// 005bd439  d8d1                 fcom st(1)
// 005bd43b  dfe0                 fnstsw ax
// 005bd43d  f6c441               test ah, 0x41
// 005bd440  7b11                 jnp 0x5bd453
// 005bd442  ddd9                 fstp st(1)
// 005bd444  d9e8                 fld1 
// 005bd446  d8d1                 fcom st(1)
// 005bd448  dfe0                 fnstsw ax
// 005bd44a  f6c441               test ah, 0x41
// 005bd44d  7a04                 jp 0x5bd453
// 005bd44f  ddd9                 fstp st(1)
// 005bd451  eb02                 jmp 0x5bd455
// 005bd453  ddd8                 fstp st(0)
// 005bd455  d89660010000         fcom dword ptr [esi + 0x160]
// 005bd45b  dfe0                 fnstsw ax
// 005bd45d  f6c444               test ah, 0x44
// 005bd460  7b45                 jnp 0x5bd4a7
// 005bd462  8b863c010000         mov eax, dword ptr [esi + 0x13c]
// 005bd468  d99660010000         fst dword ptr [esi + 0x160]
// 005bd46e  85c0                 test eax, eax
// 005bd470  7423                 je 0x5bd495
// 005bd472  51                   push ecx
// 005bd473  d91c24               fstp dword ptr [esp]
// 005bd476  50                   push eax
// 005bd477  e8ea270e00           call 0x69fc66
// 005bd47c  50                   push eax
// 005bd47d  e81eb3ffff           call 0x5b87a0
// 005bd482  83c404               add esp, 4
// 005bd485  68b8719700           push 0x9771b8
// 005bd48a  8bce                 mov ecx, esi
// 005bd48c  e86f06e5ff           call 0x40db00
// 005bd491  5e                   pop esi
// 005bd492  c20400               ret 4
// 005bd495  68b8719700           push 0x9771b8
// 005bd49a  ddd8                 fstp st(0)
// 005bd49c  8bce                 mov ecx, esi
// 005bd49e  e85d06e5ff           call 0x40db00
// 005bd4a3  5e                   pop esi
// 005bd4a4  c20400               ret 4
// 005bd4a7  ddd8                 fstp st(0)
// 005bd4a9  5e                   pop esi
// 005bd4aa  c20400               ret 4

extern "C" int __stdcall applyVolume(void*, float);
extern "C" void __cdecl checkResult(int);

extern char volumeProperty;

struct Sound {
    char padding0[0x13c];
    void* handle;
    char padding1[0x20];
    float volume;

    void setVolume(float value);
    void notify(void* property);
};

void Sound::setVolume(float value)
{
    float clamped;
    if (value <= 0.0f)
        clamped = 0.0f;
    else if (value >= 1.0f)
        clamped = 1.0f;
    else
        clamped = value;

    if (volume != clamped) {
        volume = clamped;
        if (handle)
            checkResult(applyVolume(handle, clamped));
        notify(&volumeProperty);
    }
}
