// roc 2012-06 0071ee30  unit: RBX::ArrowToolBase  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071ee30
//
// 0071ee30  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 0071ee34  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0071ee30 {
    char pad0[28];
    char m_x;
    void f();
};
void S_func_0071ee30::f()
{
    m_x = (char)0;
}
