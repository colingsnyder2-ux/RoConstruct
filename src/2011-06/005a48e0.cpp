// from server: 100% by Yeetserama
// roc 2011-06 005a48e0  unit: SoundServiceStatsItem  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005a48e0
//
// 005a48e0  6aff                 push -1
// 005a48e2  68cb139e00           push 0x9e13cb
// 005a48e7  64a100000000         mov eax, dword ptr fs:[0]
// 005a48ed  50                   push eax
// 005a48ee  64892500000000       mov dword ptr fs:[0], esp
// 005a48f5  51                   push ecx
// 005a48f6  56                   push esi
// 005a48f7  8bf1                 mov esi, ecx
// 005a48f9  89742404             mov dword ptr [esp + 4], esi
// 005a48fd  8b06                 mov eax, dword ptr [esi]
// 005a48ff  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005a4907  85c0                 test eax, eax
// 005a4909  7415                 je 0x5a4920
// 005a490b  50                   push eax
// 005a490c  e887562600           call 0x809f98
// 005a4911  50                   push eax
// 005a4912  e829eeffff           call 0x5a3740
// 005a4917  83c404               add esp, 4
// 005a491a  c70600000000         mov dword ptr [esi], 0
// 005a4920  8d4e0c               lea ecx, [esi + 0xc]
// 005a4923  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 005a492b  ff15d004a400         call dword ptr [0xa404d0]
// 005a4931  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005a4935  5e                   pop esi
// 005a4936  64890d00000000       mov dword ptr fs:[0], ecx
// 005a493d  83c410               add esp, 0x10
// 005a4940  c3                   ret 
// copied from an identical function in another client (function ??1SoundChannel@ns_ROCX000002@@QAE@XZ)

namespace ns_ROCX000002 {
// from server: 100% by king_originala
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
