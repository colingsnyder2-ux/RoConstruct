// roc 2012-06 008f3f80  unit: RBX::VHandles::?$FactoryProduct  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008f3f80
//
// 008f3f80  c681bc00000001       mov byte ptr [ecx + 0xbc], 1
// 008f3f87  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008f3f80 {
    char pad0[188];
    char m_x;
    void f();
};
void S_func_008f3f80::f()
{
    m_x = (char)1;
}
