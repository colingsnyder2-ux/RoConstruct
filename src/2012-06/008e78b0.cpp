// roc 2012-06 008e78b0  unit: RBX::TextureTrail  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008e78b0
//
// 008e78b0  d981e4000000         fld dword ptr [ecx + 0xe4]
// 008e78b6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008e78b0 {
    char pad[228];
    float m_x;
    float f();
};
float S_func_008e78b0::f()
{
    return m_x;
}
