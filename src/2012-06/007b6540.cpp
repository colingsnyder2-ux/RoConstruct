// roc 2012-06 007b6540  unit: RBX::P8HopperBin::?$SetImpl  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b6540
//
// 007b6540  d98198000000         fld dword ptr [ecx + 0x98]
// 007b6546  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007b6540 {
    char pad[152];
    float m_x;
    float f();
};
float S_func_007b6540::f()
{
    return m_x;
}
