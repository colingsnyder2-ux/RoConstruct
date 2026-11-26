// from server: 100% by Xemicl
// roc 2012-06 00698a60  unit: SoundServiceStatsItem  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00698a60
//
// 00698a60  6aff                 push -1
// 00698a62  68bb6eab00           push 0xab6ebb
// 00698a67  64a100000000         mov eax, dword ptr fs:[0]
// 00698a6d  50                   push eax
// 00698a6e  64892500000000       mov dword ptr fs:[0], esp
// 00698a75  51                   push ecx
// 00698a76  56                   push esi
// 00698a77  8bf1                 mov esi, ecx
// 00698a79  89742404             mov dword ptr [esp + 4], esi
// 00698a7d  8b06                 mov eax, dword ptr [esi]
// 00698a7f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00698a87  85c0                 test eax, eax
// 00698a89  7415                 je 0x698aa0
// 00698a8b  50                   push eax
// 00698a8c  e8c3952e00           call 0x982054
// 00698a91  50                   push eax
// 00698a92  e8c9edffff           call 0x697860
// 00698a97  83c404               add esp, 4
// 00698a9a  c70600000000         mov dword ptr [esi], 0
// 00698aa0  8d4e0c               lea ecx, [esi + 0xc]
// 00698aa3  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00698aab  ff153c26b200         call dword ptr [0xb2263c]
// 00698ab1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00698ab5  5e                   pop esi
// 00698ab6  64890d00000000       mov dword ptr fs:[0], ecx
// 00698abd  83c410               add esp, 0x10
// 00698ac0  c3                   ret 
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