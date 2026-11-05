// roc 2012-06 0058f710  unit: RBX::Network::VClient::?$FactoryProduct  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0058f710
//
// 0058f710  c681541f000000       mov byte ptr [ecx + 0x1f54], 0
// 0058f717  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0058f710 {
    char pad0[8020];
    char m_x;
    void f();
};
void S_func_0058f710::f()
{
    m_x = (char)0;
}
