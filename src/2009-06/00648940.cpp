// from server: 100% by EspClaude
// from server: 99% by EspClaude
// roc 2009-06 00648940  unit: RBX::Soundscape::SoundChannel  size: 358 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00648940
//
// 00648940  64a100000000         mov eax, dword ptr fs:[0]
// 00648946  6aff                 push -1
// 00648948  68d8aa8600           push 0x86aad8
// 0064894d  50                   push eax
// 0064894e  64892500000000       mov dword ptr fs:[0], esp
// 00648955  83ec74               sub esp, 0x74
// 00648958  56                   push esi
// 00648959  57                   push edi
// 0064895a  8bf9                 mov edi, ecx
// 0064895c  833f00               cmp dword ptr [edi], 0
// 0064895f  0f8529010000         jne 0x648a8e
// 00648965  8b94248c000000       mov edx, dword ptr [esp + 0x8c]
// 0064896c  8d470c               lea eax, [edi + 0xc]
// 0064896f  50                   push eax
// 00648970  8d4c240c             lea ecx, [esp + 0xc]
// 00648974  51                   push ecx
// 00648975  52                   push edx
// 00648976  e8e5d5e1ff           call 0x465f60
// 0064897b  83c404               add esp, 4
// 0064897e  8bc8                 mov ecx, eax
// 00648980  e81b82f9ff           call 0x5e0ba0
// 00648985  837c240800           cmp dword ptr [esp + 8], 0
// 0064898a  c784248400000000000000 mov dword ptr [esp + 0x84], 0
// 00648995  7544                 jne 0x6489db
// 00648997  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0064899b  c7842484000000ffffffff mov dword ptr [esp + 0x84], 0xffffffff
// 006489a6  85f6                 test esi, esi
// 006489a8  742a                 je 0x6489d4
// 006489aa  8d4604               lea eax, [esi + 4]
// 006489ad  83c9ff               or ecx, 0xffffffff
// 006489b0  f00fc108             lock xadd dword ptr [eax], ecx
// 006489b4  751e                 jne 0x6489d4
// 006489b6  8b16                 mov edx, dword ptr [esi]
// 006489b8  8b4204               mov eax, dword ptr [edx + 4]
// 006489bb  8bce                 mov ecx, esi
// 006489bd  ffd0                 call eax
// 006489bf  8d4e08               lea ecx, [esi + 8]
// 006489c2  83caff               or edx, 0xffffffff
// 006489c5  f00fc111             lock xadd dword ptr [ecx], edx
// 006489c9  7509                 jne 0x6489d4
// 006489cb  8b06                 mov eax, dword ptr [esi]
// 006489cd  8b5008               mov edx, dword ptr [eax + 8]
// 006489d0  8bce                 mov ecx, esi
// 006489d2  ffd2                 call edx
// 006489d4  33c0                 xor eax, eax
// 006489d6  e9b5000000           jmp 0x648a90
// 006489db  0fb6772c             movzx esi, byte ptr [edi + 0x2c]
// 006489df  f7de                 neg esi
// 006489e1  1bf6                 sbb esi, esi
// 006489e3  83e610               and esi, 0x10
// 006489e6  e8e51ee0ff           call 0x44a8d0
// 006489eb  0fb68095000000       movzx eax, byte ptr [eax + 0x95]
// 006489f2  f7d8                 neg eax
// 006489f4  1bc0                 sbb eax, eax
// 006489f6  83e020               and eax, 0x20
// 006489f9  6a6c                 push 0x6c
// 006489fb  83c020               add eax, 0x20
// 006489fe  8d4c2414             lea ecx, [esp + 0x14]
// 00648a02  0d00080000           or eax, 0x800
// 00648a07  6a00                 push 0
// 00648a09  51                   push ecx
// 00648a0a  0bf0                 or esi, eax
// 00648a0c  e863120d00           call 0x719c74
// 00648a11  8b442414             mov eax, dword ptr [esp + 0x14]
// 00648a15  c744241c6c000000     mov dword ptr [esp + 0x1c], 0x6c
// 00648a1d  8b5014               mov edx, dword ptr [eax + 0x14]
// 00648a20  83c40c               add esp, 0xc
// 00648a23  89542414             mov dword ptr [esp + 0x14], edx
// 00648a27  83781810             cmp dword ptr [eax + 0x18], 0x10
// 00648a2b  7205                 jb 0x648a32
// 00648a2d  8b4004               mov eax, dword ptr [eax + 4]
// 00648a30  eb03                 jmp 0x648a35
// 00648a32  83c004               add eax, 4
// 00648a35  8b5704               mov edx, dword ptr [edi + 4]
// 00648a38  57                   push edi
// 00648a39  8d4c2414             lea ecx, [esp + 0x14]
// 00648a3d  51                   push ecx
// 00648a3e  56                   push esi
// 00648a3f  50                   push eax
// 00648a40  52                   push edx
// 00648a41  e834f40c00           call 0x717e7a
// 00648a46  50                   push eax
// 00648a47  e804aeffff           call 0x643850
// 00648a4c  8b442410             mov eax, dword ptr [esp + 0x10]
// 00648a50  83c404               add esp, 4
// 00648a53  c7842484000000ffffffff mov dword ptr [esp + 0x84], 0xffffffff
// 00648a5e  85c0                 test eax, eax
// 00648a60  742c                 je 0x648a8e
// 00648a62  8bf0                 mov esi, eax
// 00648a64  83c004               add eax, 4
// 00648a67  83c9ff               or ecx, 0xffffffff
// 00648a6a  f00fc108             lock xadd dword ptr [eax], ecx
// 00648a6e  751e                 jne 0x648a8e
// 00648a70  8b16                 mov edx, dword ptr [esi]
// 00648a72  8b4204               mov eax, dword ptr [edx + 4]
// 00648a75  8bce                 mov ecx, esi
// 00648a77  ffd0                 call eax
// 00648a79  8d4e08               lea ecx, [esi + 8]
// 00648a7c  83caff               or edx, 0xffffffff
// 00648a7f  f00fc111             lock xadd dword ptr [ecx], edx
// 00648a83  7509                 jne 0x648a8e
// 00648a85  8b06                 mov eax, dword ptr [esi]
// 00648a87  8b5008               mov edx, dword ptr [eax + 8]
// 00648a8a  8bce                 mov ecx, esi
// 00648a8c  ffd2                 call edx
// 00648a8e  8b07                 mov eax, dword ptr [edi]
// 00648a90  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 00648a94  5f                   pop edi
// 00648a95  5e                   pop esi
// 00648a96  64890d00000000       mov dword ptr fs:[0], ecx
// 00648a9d  81c480000000         add esp, 0x80
// 00648aa3  c20400               ret 4

// from server: 100% by king_originala
// roc 2008-06 005bc6f0  unit: RBX::Soundscape::SoundService  size: 358 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bc6f0
//
// 005bc6f0  64a100000000         mov eax, dword ptr fs:[0]
// 005bc6f6  6aff                 push -1
// 005bc6f8  68883d7d00           push 0x7d3d88
// 005bc6fd  50                   push eax
// 005bc6fe  64892500000000       mov dword ptr fs:[0], esp
// 005bc705  83ec74               sub esp, 0x74
// 005bc708  56                   push esi
// 005bc709  57                   push edi
// 005bc70a  8bf9                 mov edi, ecx
// 005bc70c  833f00               cmp dword ptr [edi], 0
// 005bc70f  0f8529010000         jne 0x5bc83e
// 005bc715  8b94248c000000       mov edx, dword ptr [esp + 0x8c]
// 005bc71c  8d470c               lea eax, [edi + 0xc]
// 005bc71f  50                   push eax
// 005bc720  8d4c240c             lea ecx, [esp + 0xc]
// 005bc724  51                   push ecx
// 005bc725  52                   push edx
// 005bc726  e8e58aeaff           call 0x465210
// 005bc72b  83c404               add esp, 4
// 005bc72e  8bc8                 mov ecx, eax
// 005bc730  e8fb5ffaff           call 0x562730
// 005bc735  837c240800           cmp dword ptr [esp + 8], 0
// 005bc73a  c784248400000000000000 mov dword ptr [esp + 0x84], 0
// 005bc745  7544                 jne 0x5bc78b
// 005bc747  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005bc74b  c7842484000000ffffffff mov dword ptr [esp + 0x84], 0xffffffff
// 005bc756  85f6                 test esi, esi
// 005bc758  742a                 je 0x5bc784
// 005bc75a  8d4604               lea eax, [esi + 4]
// 005bc75d  83c9ff               or ecx, 0xffffffff
// 005bc760  f00fc108             lock xadd dword ptr [eax], ecx
// 005bc764  751e                 jne 0x5bc784
// 005bc766  8b16                 mov edx, dword ptr [esi]
// 005bc768  8b4204               mov eax, dword ptr [edx + 4]
// 005bc76b  8bce                 mov ecx, esi
// 005bc76d  ffd0                 call eax
// 005bc76f  8d4e08               lea ecx, [esi + 8]
// 005bc772  83caff               or edx, 0xffffffff
// 005bc775  f00fc111             lock xadd dword ptr [ecx], edx
// 005bc779  7509                 jne 0x5bc784
// 005bc77b  8b06                 mov eax, dword ptr [esi]
// 005bc77d  8b5008               mov edx, dword ptr [eax + 8]
// 005bc780  8bce                 mov ecx, esi
// 005bc782  ffd2                 call edx
// 005bc784  33c0                 xor eax, eax
// 005bc786  e9b5000000           jmp 0x5bc840
// 005bc78b  0fb6772c             movzx esi, byte ptr [edi + 0x2c]
// 005bc78f  f7de                 neg esi
// 005bc791  1bf6                 sbb esi, esi
// 005bc793  83e610               and esi, 0x10
// 005bc796  e845f7e8ff           call 0x44bee0
// 005bc79b  0fb68039010000       movzx eax, byte ptr [eax + 0x139]
// 005bc7a2  f7d8                 neg eax
// 005bc7a4  1bc0                 sbb eax, eax
// 005bc7a6  83e020               and eax, 0x20
// 005bc7a9  6a6c                 push 0x6c
// 005bc7ab  83c020               add eax, 0x20
// 005bc7ae  8d4c2414             lea ecx, [esp + 0x14]
// 005bc7b2  0d00080000           or eax, 0x800
// 005bc7b7  6a00                 push 0
// 005bc7b9  51                   push ecx
// 005bc7ba  0bf0                 or esi, eax
// 005bc7bc  e8434f0e00           call 0x6a1704
// 005bc7c1  8b442414             mov eax, dword ptr [esp + 0x14]
// 005bc7c5  c744241c6c000000     mov dword ptr [esp + 0x1c], 0x6c
// 005bc7cd  8b5014               mov edx, dword ptr [eax + 0x14]
// 005bc7d0  83c40c               add esp, 0xc
// 005bc7d3  89542414             mov dword ptr [esp + 0x14], edx
// 005bc7d7  83781810             cmp dword ptr [eax + 0x18], 0x10
// 005bc7db  7205                 jb 0x5bc7e2
// 005bc7dd  8b4004               mov eax, dword ptr [eax + 4]
// 005bc7e0  eb03                 jmp 0x5bc7e5
// 005bc7e2  83c004               add eax, 4
// 005bc7e5  8b5704               mov edx, dword ptr [edi + 4]
// 005bc7e8  57                   push edi
// 005bc7e9  8d4c2414             lea ecx, [esp + 0x14]
// 005bc7ed  51                   push ecx
// 005bc7ee  56                   push esi
// 005bc7ef  50                   push eax
// 005bc7f0  52                   push edx
// 005bc7f1  e85e340e00           call 0x69fc54
// 005bc7f6  50                   push eax
// 005bc7f7  e8e4a7ffff           call 0x5b6fe0
// 005bc7fc  8b442410             mov eax, dword ptr [esp + 0x10]
// 005bc800  83c404               add esp, 4
// 005bc803  c7842484000000ffffffff mov dword ptr [esp + 0x84], 0xffffffff
// 005bc80e  85c0                 test eax, eax
// 005bc810  742c                 je 0x5bc83e
// 005bc812  8bf0                 mov esi, eax
// 005bc814  83c004               add eax, 4
// 005bc817  83c9ff               or ecx, 0xffffffff
// 005bc81a  f00fc108             lock xadd dword ptr [eax], ecx
// 005bc81e  751e                 jne 0x5bc83e
// 005bc820  8b16                 mov edx, dword ptr [esi]
// 005bc822  8b4204               mov eax, dword ptr [edx + 4]
// 005bc825  8bce                 mov ecx, esi
// 005bc827  ffd0                 call eax
// 005bc829  8d4e08               lea ecx, [esi + 8]
// 005bc82c  83caff               or edx, 0xffffffff
// 005bc82f  f00fc111             lock xadd dword ptr [ecx], edx
// 005bc833  7509                 jne 0x5bc83e
// 005bc835  8b06                 mov eax, dword ptr [esi]
// 005bc837  8b5008               mov edx, dword ptr [eax + 8]
// 005bc83a  8bce                 mov ecx, esi
// 005bc83c  ffd2                 call edx
// 005bc83e  8b07                 mov eax, dword ptr [edi]
// 005bc840  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 005bc844  5f                   pop edi
// 005bc845  5e                   pop esi
// 005bc846  64890d00000000       mov dword ptr fs:[0], ecx
// 005bc84d  81c480000000         add esp, 0x80
// 005bc853  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct RefCount
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;
};

struct Asset
{
    unsigned int prefix;
    union
    {
        char text[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
};

struct SharedAsset
{
    Asset* asset;
    RefCount* count;

    ~SharedAsset();
};

inline SharedAsset::~SharedAsset()
{
    if (count)
    {
        RefCount* p = count;
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Key
{
    char data[32];
};

namespace RBX
{
    class Instance;
    class ServiceProvider
    {
    public:
        SharedAsset fetch(const Key&);
    };
}

RBX::ServiceProvider* __cdecl func_00465210(RBX::Instance*);

struct Settings
{
    char padding[0x95];
    unsigned char enabled;
};

Settings* __cdecl getSettings();

struct CreateInfo
{
    unsigned int size;
    unsigned int length;
    char remaining[100];
};

extern "C" void* __cdecl clearMemory(void*, int, unsigned int);
extern "C" int __stdcall createSound(void*, const char*, unsigned int,
                                    CreateInfo*, void*);
void __cdecl checkResult(int);

struct SoundService
{
    void* sound;
    void* system;
    unsigned int unknown;
    Key key;
    unsigned char enabled;

    void* load(RBX::Instance*);
};

void* SoundService::load(RBX::Instance* instance)
{
    if (!sound)
    {
        SharedAsset asset = func_00465210(instance)->fetch(key);
        if (!asset.asset)
            return 0;

        unsigned int flags = enabled ? 0x10 : 0;
        flags |= (getSettings()->enabled ? 0x40 : 0x20) | 0x800;

        CreateInfo info;
        clearMemory(&info, 0, 108);
        info.size = 108;
        info.length = asset.asset->length;

        const char* data;
        if (asset.asset->capacity >= 16)
            data = asset.asset->storage.pointer;
        else
            data = asset.asset->storage.text;

        checkResult(createSound(system, data, flags, &info, this));
    }
    return sound;
}
