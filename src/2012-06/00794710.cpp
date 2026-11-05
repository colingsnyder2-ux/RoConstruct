// roc 2012-06 00794710  unit: RBX::KernelJoint  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00794710
//
// 00794710  d981dc010000         fld dword ptr [ecx + 0x1dc]
// 00794716  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00794710 {
    char pad[476];
    float m_x;
    float f();
};
float S_func_00794710::f()
{
    return m_x;
}
