// roc 2012-06 0071ecf0  unit: RBX::Script  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071ecf0
//
// 0071ecf0  dd8160020000         fld qword ptr [ecx + 0x260]
// 0071ecf6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0071ecf0 {
    char pad[608];
    double m_x;
    double f();
};
double S_func_0071ecf0::f()
{
    return m_x;
}
