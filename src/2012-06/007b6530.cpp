// roc 2012-06 007b6530  unit: RBX::P8HopperBin::?$SetImpl  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b6530
//
// 007b6530  d98194000000         fld dword ptr [ecx + 0x94]
// 007b6536  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007b6530 {
    char pad[148];
    float m_x;
    float f();
};
float S_func_007b6530::f()
{
    return m_x;
}
