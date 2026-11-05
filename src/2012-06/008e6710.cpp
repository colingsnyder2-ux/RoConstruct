// roc 2012-06 008e6710  unit: RBX::VSelectionPointLasso::?$FactoryProduct  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008e6710
//
// 008e6710  d981e8000000         fld dword ptr [ecx + 0xe8]
// 008e6716  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008e6710 {
    char pad[232];
    float m_x;
    float f();
};
float S_func_008e6710::f()
{
    return m_x;
}
