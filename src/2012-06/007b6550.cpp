// roc 2012-06 007b6550  unit: RBX::P8HopperBin::?$SetImpl  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b6550
//
// 007b6550  d9819c000000         fld dword ptr [ecx + 0x9c]
// 007b6556  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007b6550 {
    char pad[156];
    float m_x;
    float f();
};
float S_func_007b6550::f()
{
    return m_x;
}
