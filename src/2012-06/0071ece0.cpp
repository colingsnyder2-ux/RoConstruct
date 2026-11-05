// roc 2012-06 0071ece0  unit: RBX::Script  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071ece0
//
// 0071ece0  dd8158020000         fld qword ptr [ecx + 0x258]
// 0071ece6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0071ece0 {
    char pad[600];
    double m_x;
    double f();
};
double S_func_0071ece0::f()
{
    return m_x;
}
