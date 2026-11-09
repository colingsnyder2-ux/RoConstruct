// roc 2012-06 007b7070  unit: RBX::VSmoke::?$FactoryProduct  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b7070
//
// 007b7070  d981a0000000         fld dword ptr [ecx + 0xa0]
// 007b7076  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007b7070 {
    char pad[160];
    float m_x;
    float f();
};
float S_func_007b7070::f()
{
    return m_x;
}
