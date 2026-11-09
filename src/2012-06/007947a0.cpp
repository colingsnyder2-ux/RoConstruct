// roc 2012-06 007947a0  unit: RBX::KernelJoint  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007947a0
//
// 007947a0  8a81e8010000         mov al, byte ptr [ecx + 0x1e8]
// 007947a6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007947a0 {
    char pad0[488];
    char m_x;
    char f();
};
char S_func_007947a0::f()
{
    return m_x;
}
