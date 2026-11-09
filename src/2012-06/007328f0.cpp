// roc 2012-06 007328f0  unit: RBX::GameBasicSettings  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007328f0
//
// 007328f0  8d81a4000000         lea eax, [ecx + 0xa4]
// 007328f6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007328f0 {
    char pad0[164];
    int m_x;
    int* f();
};
int* S_func_007328f0::f()
{
    return &m_x;
}
