// roc 2012-06 005d6f80  unit: RBX::VCylinderMesh::?$FactoryProduct::Creator  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005d6f80
//
// 005d6f80  d981c4000000         fld dword ptr [ecx + 0xc4]
// 005d6f86  c3                   ret 
// auto-matched from its assembly shape

struct S_func_005d6f80 {
    char pad[196];
    float m_x;
    float f();
};
float S_func_005d6f80::f()
{
    return m_x;
}
