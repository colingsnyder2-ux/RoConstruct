// roc 2012-06 0071ed20  unit: RBX::Script  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071ed20
//
// 0071ed20  dd8148020000         fld qword ptr [ecx + 0x248]
// 0071ed26  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0071ed20 {
    char pad[584];
    double m_x;
    double f();
};
double S_func_0071ed20::f()
{
    return m_x;
}
