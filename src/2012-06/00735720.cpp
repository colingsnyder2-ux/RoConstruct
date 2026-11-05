// roc 2012-06 00735720  unit: RBX::Frame  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00735720
//
// 00735720  d981e0010000         fld dword ptr [ecx + 0x1e0]
// 00735726  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00735720 {
    char pad[480];
    float m_x;
    float f();
};
float S_func_00735720::f()
{
    return m_x;
}
