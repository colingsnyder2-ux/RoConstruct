// roc 2012-06 00794760  unit: RBX::KernelJoint  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00794760
//
// 00794760  d981d4010000         fld dword ptr [ecx + 0x1d4]
// 00794766  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00794760 {
    char pad[468];
    float m_x;
    float f();
};
float S_func_00794760::f()
{
    return m_x;
}
