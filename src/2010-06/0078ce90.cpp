// from server: 100% by Yeetserama
// roc 2010-06 0078ce90  unit: RBX::SpatialFilter  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0078ce90
//
// 0078ce90  6aff                 push -1
// 0078ce92  6868d19a00           push 0x9ad168
// 0078ce97  64a100000000         mov eax, dword ptr fs:[0]
// 0078ce9d  50                   push eax
// 0078ce9e  64892500000000       mov dword ptr fs:[0], esp
// 0078cea5  51                   push ecx
// 0078cea6  56                   push esi
// 0078cea7  8bf1                 mov esi, ecx
// 0078cea9  89742404             mov dword ptr [esp + 4], esi
// 0078cead  c7067c3ca500         mov dword ptr [esi], 0xa53c7c
// 0078ceb3  8d4e10               lea ecx, [esi + 0x10]
// 0078ceb6  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0078cebe  e8dd55c7ff           call 0x4024a0
// 0078cec3  8b4e08               mov ecx, dword ptr [esi + 8]
// 0078cec6  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0078cece  5e                   pop esi
// 0078cecf  85c9                 test ecx, ecx
// 0078ced1  7408                 je 0x78cedb
// 0078ced3  8b01                 mov eax, dword ptr [ecx]
// 0078ced5  8b10                 mov edx, dword ptr [eax]
// 0078ced7  6a01                 push 1
// 0078ced9  ffd2                 call edx
// 0078cedb  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0078cedf  64890d00000000       mov dword ptr fs:[0], ecx
// 0078cee6  83c410               add esp, 0x10
// 0078cee9  c3                   ret 
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
