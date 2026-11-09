// roc 2012-06 005d6f90  unit: RBX::VCylinderMesh::?$FactoryProduct::Creator  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005d6f90
//
// 005d6f90  8d818c000000         lea eax, [ecx + 0x8c]
// 005d6f96  c3                   ret 
// auto-matched from its assembly shape

struct S_func_005d6f90 {
    char pad0[140];
    int m_x;
    int* f();
};
int* S_func_005d6f90::f()
{
    return &m_x;
}
