// roc 2012-06 006a2350  unit: std::D::DU?$char_traits::?$basic_istringstream  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006a2350
//
// 006a2350  c6810801000001       mov byte ptr [ecx + 0x108], 1
// 006a2357  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006a2350 {
    char pad0[264];
    char m_x;
    void f();
};
void S_func_006a2350::f()
{
    m_x = (char)1;
}
