// roc 2012-06 00794780  unit: RBX::KernelJoint  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00794780
//
// 00794780  8a81e4010000         mov al, byte ptr [ecx + 0x1e4]
// 00794786  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00794780 {
    char pad0[484];
    char m_x;
    char f();
};
char S_func_00794780::f()
{
    return m_x;
}
