// roc 2012-06 007e7dc0  unit: RBX::GuiTarget  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e7dc0
//
// 007e7dc0  c70100000000         mov dword ptr [ecx], 0
// 007e7dc6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007e7dc0 {
    int m_x;
    void f();
};
void S_func_007e7dc0::f()
{
    m_x = (int)0;
}
