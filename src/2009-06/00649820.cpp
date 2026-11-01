// from server: 89% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005bd590  unit: VStockSound::?$FactoryProduct  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bd590
//
// 005bd590  56                   push esi
// 005bd591  8bf1                 mov esi, ecx
// 005bd593  8b863c010000         mov eax, dword ptr [esi + 0x13c]
// 005bd599  85c0                 test eax, eax
// 005bd59b  7430                 je 0x5bd5cd
// 005bd59d  6a00                 push 0
// 005bd59f  50                   push eax
// 005bd5a0  e84f260e00           call 0x69fbf4
// 005bd5a5  50                   push eax
// 005bd5a6  e8f5b1ffff           call 0x5b87a0
// 005bd5ab  8b863c010000         mov eax, dword ptr [esi + 0x13c]
// 005bd5b1  83c404               add esp, 4
// 005bd5b4  50                   push eax
// 005bd5b5  e8be260e00           call 0x69fc78
// 005bd5ba  50                   push eax
// 005bd5bb  e8e0b1ffff           call 0x5b87a0
// 005bd5c0  83c404               add esp, 4
// 005bd5c3  c7863c01000000000000 mov dword ptr [esi + 0x13c], 0
// 005bd5cd  8bce                 mov ecx, esi
// 005bd5cf  e8dcefffff           call 0x5bc5b0
// 005bd5d4  83c8ff               or eax, 0xffffffff
// 005bd5d7  398668010000         cmp dword ptr [esi + 0x168], eax
// 005bd5dd  7412                 je 0x5bd5f1
// 005bd5df  6810709700           push 0x977010
// 005bd5e4  8bce                 mov ecx, esi
// 005bd5e6  898668010000         mov dword ptr [esi + 0x168], eax
// 005bd5ec  e80f05e5ff           call 0x40db00
// 005bd5f1  5e                   pop esi
// 005bd5f2  c3                   ret 

extern "C" int __stdcall soundStop(void *, int);
extern "C" int __stdcall soundRelease(void *);
extern "C" void __cdecl checkSoundResult(int);

extern char changedProperty;

struct Sound {
    char padding0[0x13c];
    void *handle;
    char padding1[0x28];
    int state;

    void reset();
    void update();
    void notify(const void *);
};

void Sound::reset()
{
    if (handle) {
        checkSoundResult(soundStop(handle, 0));
        checkSoundResult(soundRelease(handle));
        handle = 0;
    }

    update();

    if (state != -1) {
        state = -1;
        notify(&changedProperty);
    }
}
