// roc 2012-06 007947b0  unit: RBX::KernelJoint  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007947b0
//
// 007947b0  8d81bc010000         lea eax, [ecx + 0x1bc]
// 007947b6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007947b0 {
    char pad0[444];
    int m_x;
    int* f();
};
int* S_func_007947b0::f()
{
    return &m_x;
}
