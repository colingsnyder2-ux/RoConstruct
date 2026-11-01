// Implementation: C:\Users\colin\RoConstruct\src\2008-06\005ba410.cpp
// Build pointer preserved: C:\Users\colin\RoConstruct\src\2008-06\005ba410.cpp
// from server: 100% by king_originala
// roc 2008-06 005ba410  unit: RBX::Soundscape::SoundChannel  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ba410
//
// 005ba410  6aff                 push -1
// 005ba412  683b3b7d00           push 0x7d3b3b
// 005ba417  64a100000000         mov eax, dword ptr fs:[0]
// 005ba41d  50                   push eax
// 005ba41e  64892500000000       mov dword ptr fs:[0], esp
// 005ba425  51                   push ecx
// 005ba426  56                   push esi
// 005ba427  8bf1                 mov esi, ecx
// 005ba429  89742404             mov dword ptr [esp + 4], esi
// 005ba42d  8b06                 mov eax, dword ptr [esi]
// 005ba42f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005ba437  85c0                 test eax, eax
// 005ba439  7415                 je 0x5ba450
// 005ba43b  50                   push eax
// 005ba43c  e8d1570e00           call 0x69fc12
// 005ba441  50                   push eax
// 005ba442  e859e3ffff           call 0x5b87a0
// 005ba447  83c404               add esp, 4
// 005ba44a  c70600000000         mov dword ptr [esi], 0
// 005ba450  8d4e0c               lea ecx, [esi + 0xc]
// 005ba453  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 005ba45b  ff1568248000         call dword ptr [0x802468]
// 005ba461  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005ba465  5e                   pop esi
// 005ba466  64890d00000000       mov dword ptr fs:[0], ecx
// 005ba46d  83c410               add esp, 0x10
// 005ba470  c3                   ret 

typedef void (__thiscall *StringDestructor)(void *);
extern StringDestructor destroyString;

extern "C" void * __stdcall resolveHandle(void *);
void __cdecl releaseHandle(void *);

struct StringStorage {
    unsigned char storage[28];
    ~StringStorage();
};

inline StringStorage::~StringStorage()
{
    destroyString(this);
}

struct SoundChannel {
    void *handle;
    unsigned char padding[8];
    StringStorage name;

    ~SoundChannel();
};

SoundChannel::~SoundChannel()
{
    if (handle) {
        releaseHandle(resolveHandle(handle));
        handle = 0;
    }
}
