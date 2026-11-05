// from server: 35% by atomic.potato
// roc 2009-12 006bbb50  unit: RBX::VTexture::?$FactoryProduct  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bbb50
//
// 006bbb50  f30f1089c8000000     movss xmm1, dword ptr [ecx + 0xc8]
// 006bbb58  f30f10442404         movss xmm0, dword ptr [esp + 4]
// 006bbb5e  0f2ec8               ucomiss xmm1, xmm0
// 006bbb61  9f                   lahf
// 006bbb62  f6c444               test ah, 0x44
// 006bbb65  7b1e                 jnp 0x6bbb85
// 006bbb67  0f2f05886a9a00       comiss xmm0, dword ptr [0x9a6a88]
// 006bbb6e  7215                 jb 0x6bbb85
// 006bbb70  f30f1181c8000000     movss dword ptr [ecx + 0xc8], xmm0
// 006bbb78  c7442404bc20b900     mov dword ptr [esp + 4], 0xb920bc
// 006bbb80  e9fb04d5ff           jmp 0x40c080
// 006bbb85  c20400               ret 4

extern "C" void __cdecl sub_40c080();

struct VTexture {
    float field_c8;
    void setValue(float value);
};

void VTexture::setValue(float value) {
    float current = field_c8;
    if (current == value) {
        return;
    }
    if (value < 0.0f) {
        return;
    }
    field_c8 = value;
    sub_40c080();
}
