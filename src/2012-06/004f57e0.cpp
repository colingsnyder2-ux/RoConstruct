// roc 2012-06 004f57e0  unit: RBX::VPBBBuilder::?$BuilderLevelGenFunc  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004f57e0
//
// 004f57e0  d9410c               fld dword ptr [ecx + 0xc]
// 004f57e3  c3                   ret 
// auto-matched from its assembly shape

struct S_func_004f57e0 {
    char pad[12];
    float m_x;
    float f();
};
float S_func_004f57e0::f()
{
    return m_x;
}
