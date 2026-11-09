// roc 2012-06 008cc2d0  unit: RBX::FlagStand  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008cc2d0
//
// 008cc2d0  c6816401000000       mov byte ptr [ecx + 0x164], 0
// 008cc2d7  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_008cc2d0 {
    char pad0[356];
    char m_x;
    void f(int a1);
};
void S_func_008cc2d0::f(int a1)
{
    m_x = (char)0;
}
