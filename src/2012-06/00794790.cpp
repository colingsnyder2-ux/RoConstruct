// roc 2012-06 00794790  unit: RBX::KernelJoint  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00794790
//
// 00794790  8a81e7010000         mov al, byte ptr [ecx + 0x1e7]
// 00794796  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00794790 {
    char pad0[487];
    char m_x;
    char f();
};
char S_func_00794790::f()
{
    return m_x;
}
