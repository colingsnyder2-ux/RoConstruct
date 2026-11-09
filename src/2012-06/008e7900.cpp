// roc 2012-06 008e7900  unit: RBX::TextureTrail  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008e7900
//
// 008e7900  d981ec000000         fld dword ptr [ecx + 0xec]
// 008e7906  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008e7900 {
    char pad[236];
    float m_x;
    float f();
};
float S_func_008e7900::f()
{
    return m_x;
}
