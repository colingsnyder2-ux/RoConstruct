// roc 2012-06 00821dc0  unit: RBX::VCharacterMesh::?$FactoryProduct  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00821dc0
//
// 00821dc0  d981ac000000         fld dword ptr [ecx + 0xac]
// 00821dc6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00821dc0 {
    char pad[172];
    float m_x;
    float f();
};
float S_func_00821dc0::f()
{
    return m_x;
}
