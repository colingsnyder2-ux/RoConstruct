// from server: 100% by EspClaude
// roc 2009-06 006492a0  unit: RBX::VStockSound::?$FactoryProduct::Creator  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006492a0
//
// 006492a0  6aff                 push -1
// 006492a2  685bab8600           push 0x86ab5b
// 006492a7  64a100000000         mov eax, dword ptr fs:[0]
// 006492ad  50                   push eax
// 006492ae  64892500000000       mov dword ptr fs:[0], esp
// 006492b5  51                   push ecx
// 006492b6  56                   push esi
// 006492b7  8bf1                 mov esi, ecx
// 006492b9  89742404             mov dword ptr [esp + 4], esi
// 006492bd  8b06                 mov eax, dword ptr [esi]
// 006492bf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006492c7  85c0                 test eax, eax
// 006492c9  7415                 je 0x6492e0
// 006492cb  50                   push eax
// 006492cc  e8a3eb0c00           call 0x717e74
// 006492d1  50                   push eax
// 006492d2  e8d9e1ffff           call 0x6474b0
// 006492d7  83c404               add esp, 4
// 006492da  c70600000000         mov dword ptr [esi], 0
// 006492e0  8d4e0c               lea ecx, [esi + 0xc]
// 006492e3  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006492eb  ff15c4e48900         call dword ptr [0x89e4c4]
// 006492f1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006492f5  5e                   pop esi
// 006492f6  64890d00000000       mov dword ptr fs:[0], ecx
// 006492fd  83c410               add esp, 0x10
// 00649300  c3                   ret 
// copied from an identical function in another client (function ??1SoundChannel@ns_ROCX000001@@QAE@XZ)

namespace ns_ROCX000001 {
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
}
