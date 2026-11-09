// roc 2012-06 005dda50  unit: RBX::BeveledBlockBuilder  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005dda50
//
// 005dda50  8bc1                 mov eax, ecx
// 005dda52  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005dda56  d901                 fld dword ptr [ecx]
// 005dda58  d918                 fstp dword ptr [eax]
// 005dda5a  d94104               fld dword ptr [ecx + 4]
// 005dda5d  d95804               fstp dword ptr [eax + 4]
// 005dda60  d94108               fld dword ptr [ecx + 8]
// 005dda63  d95808               fstp dword ptr [eax + 8]
// 005dda66  8b510c               mov edx, dword ptr [ecx + 0xc]
// 005dda69  89500c               mov dword ptr [eax + 0xc], edx
// 005dda6c  d94110               fld dword ptr [ecx + 0x10]
// 005dda6f  d95810               fstp dword ptr [eax + 0x10]
// 005dda72  d94114               fld dword ptr [ecx + 0x14]
// 005dda75  d95814               fstp dword ptr [eax + 0x14]
// 005dda78  d94118               fld dword ptr [ecx + 0x18]
// 005dda7b  d95818               fstp dword ptr [eax + 0x18]
// 005dda7e  d9411c               fld dword ptr [ecx + 0x1c]
// 005dda81  d9581c               fstp dword ptr [eax + 0x1c]
// 005dda84  d94120               fld dword ptr [ecx + 0x20]
// 005dda87  d95820               fstp dword ptr [eax + 0x20]
// 005dda8a  d94124               fld dword ptr [ecx + 0x24]
// 005dda8d  d95824               fstp dword ptr [eax + 0x24]
// 005dda90  d94128               fld dword ptr [ecx + 0x28]
// 005dda93  d95828               fstp dword ptr [eax + 0x28]
// 005dda96  d9412c               fld dword ptr [ecx + 0x2c]
// 005dda99  d9582c               fstp dword ptr [eax + 0x2c]
// 005dda9c  d94130               fld dword ptr [ecx + 0x30]
// 005dda9f  d95830               fstp dword ptr [eax + 0x30]
// 005ddaa2  8b5134               mov edx, dword ptr [ecx + 0x34]
// 005ddaa5  895034               mov dword ptr [eax + 0x34], edx
// 005ddaa8  8b5138               mov edx, dword ptr [ecx + 0x38]
// 005ddaab  895038               mov dword ptr [eax + 0x38], edx
// 005ddaae  d9413c               fld dword ptr [ecx + 0x3c]
// 005ddab1  d9583c               fstp dword ptr [eax + 0x3c]
// 005ddab4  d94140               fld dword ptr [ecx + 0x40]
// 005ddab7  d95840               fstp dword ptr [eax + 0x40]
// 005ddaba  d94144               fld dword ptr [ecx + 0x44]
// 005ddabd  d95844               fstp dword ptr [eax + 0x44]
// 005ddac0  c20400               ret 4
// copied from an identical function in another client (function ?copyFrom@RBX_BeveledBlockBuilder@ns_ROCX000008@@QAEPAU12@PAU12@@Z)

namespace ns_ROCX000008 {
// from server: 100% by atomic.potato
struct RBX_BeveledBlockBuilder {
    char pad0[0x48];
    RBX_BeveledBlockBuilder* copyFrom(RBX_BeveledBlockBuilder* other);
};

RBX_BeveledBlockBuilder* RBX_BeveledBlockBuilder::copyFrom(RBX_BeveledBlockBuilder* other) {
    *(float*)((char*)this + 0x00) = *(float*)((char*)other + 0x00);
    *(float*)((char*)this + 0x04) = *(float*)((char*)other + 0x04);
    *(float*)((char*)this + 0x08) = *(float*)((char*)other + 0x08);
    *(int*)((char*)this + 0x0c) = *(int*)((char*)other + 0x0c);
    *(float*)((char*)this + 0x10) = *(float*)((char*)other + 0x10);
    *(float*)((char*)this + 0x14) = *(float*)((char*)other + 0x14);
    *(float*)((char*)this + 0x18) = *(float*)((char*)other + 0x18);
    *(float*)((char*)this + 0x1c) = *(float*)((char*)other + 0x1c);
    *(float*)((char*)this + 0x20) = *(float*)((char*)other + 0x20);
    *(float*)((char*)this + 0x24) = *(float*)((char*)other + 0x24);
    *(float*)((char*)this + 0x28) = *(float*)((char*)other + 0x28);
    *(float*)((char*)this + 0x2c) = *(float*)((char*)other + 0x2c);
    *(float*)((char*)this + 0x30) = *(float*)((char*)other + 0x30);
    *(int*)((char*)this + 0x34) = *(int*)((char*)other + 0x34);
    *(int*)((char*)this + 0x38) = *(int*)((char*)other + 0x38);
    *(float*)((char*)this + 0x3c) = *(float*)((char*)other + 0x3c);
    *(float*)((char*)this + 0x40) = *(float*)((char*)other + 0x40);
    *(float*)((char*)this + 0x44) = *(float*)((char*)other + 0x44);
    return this;
}
}