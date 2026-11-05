// roc 2012-06 00794770  unit: RBX::KernelJoint  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00794770
//
// 00794770  8d81a4010000         lea eax, [ecx + 0x1a4]
// 00794776  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00794770 {
    char pad0[420];
    int m_x;
    int* f();
};
int* S_func_00794770::f()
{
    return &m_x;
}
