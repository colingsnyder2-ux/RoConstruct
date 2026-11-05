// from server: 100% by EspClaude
// roc 2009-06 006f5e70  unit: RBX::AssemblyStage  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006f5e70
//
// 006f5e70  6aff                 push -1
// 006f5e72  6828268700           push 0x872628
// 006f5e77  64a100000000         mov eax, dword ptr fs:[0]
// 006f5e7d  50                   push eax
// 006f5e7e  64892500000000       mov dword ptr fs:[0], esp
// 006f5e85  51                   push ecx
// 006f5e86  56                   push esi
// 006f5e87  8bf1                 mov esi, ecx
// 006f5e89  89742404             mov dword ptr [esp + 4], esi
// 006f5e8d  c70620d28e00         mov dword ptr [esi], 0x8ed220
// 006f5e93  8d4e10               lea ecx, [esi + 0x10]
// 006f5e96  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006f5e9e  e83d44efff           call 0x5ea2e0
// 006f5ea3  8b4e08               mov ecx, dword ptr [esi + 8]
// 006f5ea6  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006f5eae  5e                   pop esi
// 006f5eaf  85c9                 test ecx, ecx
// 006f5eb1  7408                 je 0x6f5ebb
// 006f5eb3  8b01                 mov eax, dword ptr [ecx]
// 006f5eb5  8b10                 mov edx, dword ptr [eax]
// 006f5eb7  6a01                 push 1
// 006f5eb9  ffd2                 call edx
// 006f5ebb  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006f5ebf  64890d00000000       mov dword ptr fs:[0], ecx
// 006f5ec6  83c410               add esp, 0x10
// 006f5ec9  c3                   ret 
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
