// from server: 100% by Yeetserama
// roc 2010-06 0078d070  unit: RBX::MovingStage  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0078d070
//
// 0078d070  6aff                 push -1
// 0078d072  6868d19a00           push 0x9ad168
// 0078d077  64a100000000         mov eax, dword ptr fs:[0]
// 0078d07d  50                   push eax
// 0078d07e  64892500000000       mov dword ptr fs:[0], esp
// 0078d085  51                   push ecx
// 0078d086  56                   push esi
// 0078d087  8bf1                 mov esi, ecx
// 0078d089  89742404             mov dword ptr [esp + 4], esi
// 0078d08d  c706a43ca500         mov dword ptr [esi], 0xa53ca4
// 0078d093  8d4e10               lea ecx, [esi + 0x10]
// 0078d096  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0078d09e  e8fd53c7ff           call 0x4024a0
// 0078d0a3  8b4e08               mov ecx, dword ptr [esi + 8]
// 0078d0a6  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0078d0ae  5e                   pop esi
// 0078d0af  85c9                 test ecx, ecx
// 0078d0b1  7408                 je 0x78d0bb
// 0078d0b3  8b01                 mov eax, dword ptr [ecx]
// 0078d0b5  8b10                 mov edx, dword ptr [eax]
// 0078d0b7  6a01                 push 1
// 0078d0b9  ffd2                 call edx
// 0078d0bb  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0078d0bf  64890d00000000       mov dword ptr fs:[0], ecx
// 0078d0c6  83c410               add esp, 0x10
// 0078d0c9  c3                   ret 
// copied from an identical function in another client (function ??1ClumpStage@ns_ROCX000019@@UAE@XZ)

namespace ns_ROCX000019 {
// from server: 100% by king_originala
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
