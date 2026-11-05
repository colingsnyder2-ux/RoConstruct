// roc 2012-06 0071ecd0  unit: RBX::Script  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071ecd0
//
// 0071ecd0  dd8150020000         fld qword ptr [ecx + 0x250]
// 0071ecd6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0071ecd0 {
    char pad[592];
    double m_x;
    double f();
};
double S_func_0071ecd0::f()
{
    return m_x;
}
