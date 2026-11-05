// roc 2012-06 00997a30  unit: CXTPPropertyGridItemConstraint  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00997a30
//
// 00997a30  8d4130               lea eax, [ecx + 0x30]
// 00997a33  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00997a30 {
    char pad0[48];
    int m_x;
    int* f();
};
int* S_func_00997a30::f()
{
    return &m_x;
}
