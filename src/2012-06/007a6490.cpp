// roc 2012-06 007a6490  unit: RBX::Pose  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007a6490
//
// 007a6490  d98180000000         fld dword ptr [ecx + 0x80]
// 007a6496  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007a6490 {
    char pad[128];
    float m_x;
    float f();
};
float S_func_007a6490::f()
{
    return m_x;
}
