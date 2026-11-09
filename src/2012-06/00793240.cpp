// roc 2012-06 00793240  unit: RBX::Profiling::Profiler  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00793240
//
// 00793240  dd81a0000000         fld qword ptr [ecx + 0xa0]
// 00793246  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00793240 {
    char pad[160];
    double m_x;
    double f();
};
double S_func_00793240::f()
{
    return m_x;
}
