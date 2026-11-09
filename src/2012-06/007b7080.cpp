// roc 2012-06 007b7080  unit: RBX::VSmoke::?$FactoryProduct  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b7080
//
// 007b7080  d981a4000000         fld dword ptr [ecx + 0xa4]
// 007b7086  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007b7080 {
    char pad[164];
    float m_x;
    float f();
};
float S_func_007b7080::f()
{
    return m_x;
}
