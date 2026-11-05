// from server: 100% by EspClaude
// roc 2009-06 006f6ae0  unit: RBX::MovingStage  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006f6ae0
//
// 006f6ae0  6aff                 push -1
// 006f6ae2  6828268700           push 0x872628
// 006f6ae7  64a100000000         mov eax, dword ptr fs:[0]
// 006f6aed  50                   push eax
// 006f6aee  64892500000000       mov dword ptr fs:[0], esp
// 006f6af5  51                   push ecx
// 006f6af6  56                   push esi
// 006f6af7  8bf1                 mov esi, ecx
// 006f6af9  89742404             mov dword ptr [esp + 4], esi
// 006f6afd  c7065ce98e00         mov dword ptr [esi], 0x8ee95c
// 006f6b03  8d4e10               lea ecx, [esi + 0x10]
// 006f6b06  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006f6b0e  e89d1dfcff           call 0x6b88b0
// 006f6b13  8b4e08               mov ecx, dword ptr [esi + 8]
// 006f6b16  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006f6b1e  5e                   pop esi
// 006f6b1f  85c9                 test ecx, ecx
// 006f6b21  7408                 je 0x6f6b2b
// 006f6b23  8b01                 mov eax, dword ptr [ecx]
// 006f6b25  8b10                 mov edx, dword ptr [eax]
// 006f6b27  6a01                 push 1
// 006f6b29  ffd2                 call edx
// 006f6b2b  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006f6b2f  64890d00000000       mov dword ptr fs:[0], ecx
// 006f6b36  83c410               add esp, 0x10
// 006f6b39  c3                   ret 
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
