// roc 2012-06 00867e00  unit: RBX::MegaClusterPoly  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00867e00
//
// 00867e00  8d4104               lea eax, [ecx + 4]
// 00867e03  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00867e00 {
    char pad0[4];
    int m_x;
    int* f();
};
int* S_func_00867e00::f()
{
    return &m_x;
}
