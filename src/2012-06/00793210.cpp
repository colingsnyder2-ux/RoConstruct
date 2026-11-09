// roc 2012-06 00793210  unit: RBX::Profiling::Profiler  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00793210
//
// 00793210  dd81b0000000         fld qword ptr [ecx + 0xb0]
// 00793216  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00793210 {
    char pad[176];
    double m_x;
    double f();
};
double S_func_00793210::f()
{
    return m_x;
}
