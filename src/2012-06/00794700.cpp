// roc 2012-06 00794700  unit: RBX::KernelJoint  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00794700
//
// 00794700  d981d8010000         fld dword ptr [ecx + 0x1d8]
// 00794706  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00794700 {
    char pad[472];
    float m_x;
    float f();
};
float S_func_00794700::f()
{
    return m_x;
}
