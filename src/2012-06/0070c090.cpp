// roc 2012-06 0070c090  unit: RBX::VWidget::?$NonFactoryProduct  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0070c090
//
// 0070c090  c7819400000000000000 mov dword ptr [ecx + 0x94], 0
// 0070c09a  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0070c090 {
    char pad0[148];
    int m_x;
    void f();
};
void S_func_0070c090::f()
{
    m_x = (int)0;
}
