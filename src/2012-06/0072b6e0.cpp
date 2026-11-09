// roc 2012-06 0072b6e0  unit: RBX::Workspace  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0072b6e0
//
// 0072b6e0  8d81c0000000         lea eax, [ecx + 0xc0]
// 0072b6e6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0072b6e0 {
    char pad0[192];
    int m_x;
    int* f();
};
int* S_func_0072b6e0::f()
{
    return &m_x;
}
