// roc 2012-06 008e7880  unit: RBX::TextureTrail  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008e7880
//
// 008e7880  d981e0000000         fld dword ptr [ecx + 0xe0]
// 008e7886  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008e7880 {
    char pad[224];
    float m_x;
    float f();
};
float S_func_008e7880::f()
{
    return m_x;
}
