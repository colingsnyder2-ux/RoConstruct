// roc 2012-06 007328e0  unit: RBX::GameBasicSettings  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007328e0
//
// 007328e0  8d819c000000         lea eax, [ecx + 0x9c]
// 007328e6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007328e0 {
    char pad0[156];
    int m_x;
    int* f();
};
int* S_func_007328e0::f()
{
    return &m_x;
}
