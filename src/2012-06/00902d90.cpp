// roc 2012-06 00902d90  unit: RBX::HUMAN::Climbing  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00902d90
//
// 00902d90  d981c8000000         fld dword ptr [ecx + 0xc8]
// 00902d96  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00902d90 {
    char pad[200];
    float m_x;
    float f();
};
float S_func_00902d90::f()
{
    return m_x;
}
