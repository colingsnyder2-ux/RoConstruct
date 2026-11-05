// from server: 100% by EspClaude
// from server: 89% by EspClaude
// roc 2009-06 00649820  unit: RBX::VStockSound::?$FactoryProduct::Creator  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00649820
//
// 00649820  56                   push esi
// 00649821  8bf1                 mov esi, ecx
// 00649823  8b8694000000         mov eax, dword ptr [esi + 0x94]
// 00649829  85c0                 test eax, eax
// 0064982b  7430                 je 0x64985d
// 0064982d  6a00                 push 0
// 0064982f  50                   push eax
// 00649830  e815e60c00           call 0x717e4a
// 00649835  50                   push eax
// 00649836  e875dcffff           call 0x6474b0
// 0064983b  8b8694000000         mov eax, dword ptr [esi + 0x94]
// 00649841  83c404               add esp, 4
// 00649844  50                   push eax
// 00649845  e878e60c00           call 0x717ec2
// 0064984a  50                   push eax
// 0064984b  e860dcffff           call 0x6474b0
// 00649850  83c404               add esp, 4
// 00649853  c7869400000000000000 mov dword ptr [esi + 0x94], 0
// 0064985d  8bce                 mov ecx, esi
// 0064985f  e80cfeffff           call 0x649670
// 00649864  83c8ff               or eax, 0xffffffff
// 00649867  3986c8000000         cmp dword ptr [esi + 0xc8], eax
// 0064986d  7412                 je 0x649881
// 0064986f  68dcbca400           push 0xa4bcdc
// 00649874  8bce                 mov ecx, esi
// 00649876  8986c8000000         mov dword ptr [esi + 0xc8], eax
// 0064987c  e84f2adcff           call 0x40c2d0
// 00649881  5e                   pop esi
// 00649882  c3                   ret 

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
    char padding0[0x94];
    void *handle;
    char padding1[0x30];
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
