// roc 2012-06 0070f390  unit: RBX::HopperBin  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0070f390
//
// 0070f390  8d81f4010000         lea eax, [ecx + 0x1f4]
// 0070f396  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0070f390 {
    char pad0[500];
    int m_x;
    int* f();
};
int* S_func_0070f390::f()
{
    return &m_x;
}
