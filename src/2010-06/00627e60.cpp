// from server: 100% by Yeetserama
// roc 2010-06 00627e60  unit: RBX::VStockSound::?$FactoryProduct::Creator  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00627e60
//
// 00627e60  6aff                 push -1
// 00627e62  688bb29900           push 0x99b28b
// 00627e67  64a100000000         mov eax, dword ptr fs:[0]
// 00627e6d  50                   push eax
// 00627e6e  64892500000000       mov dword ptr fs:[0], esp
// 00627e75  51                   push ecx
// 00627e76  56                   push esi
// 00627e77  8bf1                 mov esi, ecx
// 00627e79  89742404             mov dword ptr [esp + 4], esi
// 00627e7d  8b06                 mov eax, dword ptr [esi]
// 00627e7f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00627e87  85c0                 test eax, eax
// 00627e89  7415                 je 0x627ea0
// 00627e8b  50                   push eax
// 00627e8c  e8a3fa1700           call 0x7a7934
// 00627e91  50                   push eax
// 00627e92  e839deffff           call 0x625cd0
// 00627e97  83c404               add esp, 4
// 00627e9a  c70600000000         mov dword ptr [esi], 0
// 00627ea0  8d4e0c               lea ecx, [esi + 0xc]
// 00627ea3  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00627eab  ff1500a49e00         call dword ptr [0x9ea400]
// 00627eb1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00627eb5  5e                   pop esi
// 00627eb6  64890d00000000       mov dword ptr fs:[0], ecx
// 00627ebd  83c410               add esp, 0x10
// 00627ec0  c3                   ret 
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
