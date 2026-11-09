// from server: 100% by EspClaude
// roc 2009-06 006f68e0  unit: Ogre::RbxMeshLoader  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006f68e0
//
// 006f68e0  6aff                 push -1
// 006f68e2  6828268700           push 0x872628
// 006f68e7  64a100000000         mov eax, dword ptr fs:[0]
// 006f68ed  50                   push eax
// 006f68ee  64892500000000       mov dword ptr fs:[0], esp
// 006f68f5  51                   push ecx
// 006f68f6  56                   push esi
// 006f68f7  8bf1                 mov esi, ecx
// 006f68f9  89742404             mov dword ptr [esp + 4], esi
// 006f68fd  c70634e98e00         mov dword ptr [esi], 0x8ee934
// 006f6903  8d4e10               lea ecx, [esi + 0x10]
// 006f6906  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006f690e  e89d1ffcff           call 0x6b88b0
// 006f6913  8b4e08               mov ecx, dword ptr [esi + 8]
// 006f6916  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006f691e  5e                   pop esi
// 006f691f  85c9                 test ecx, ecx
// 006f6921  7408                 je 0x6f692b
// 006f6923  8b01                 mov eax, dword ptr [ecx]
// 006f6925  8b10                 mov edx, dword ptr [eax]
// 006f6927  6a01                 push 1
// 006f6929  ffd2                 call edx
// 006f692b  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006f692f  64890d00000000       mov dword ptr fs:[0], ecx
// 006f6936  83c410               add esp, 0x10
// 006f6939  c3                   ret 
// copied from an identical function in another client (function ??1ClumpStage@ns_ROCX000002@@UAE@XZ)

namespace ns_ROCX000002 {
struct Stage {
    virtual ~Stage();
};

struct StageOwner {
    unsigned int reserved0;
    Stage* owned;
    unsigned int reserved1;
    ~StageOwner();
};

inline StageOwner::~StageOwner()
{
    if (owned)
        delete owned;
}

struct Collection {
    ~Collection();
};

struct ClumpStage : StageOwner {
    Collection collection;
    virtual ~ClumpStage();
};

ClumpStage::~ClumpStage()
{
}
}
