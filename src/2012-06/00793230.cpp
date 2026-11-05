// roc 2012-06 00793230  unit: RBX::Profiling::Profiler  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00793230
//
// 00793230  dd81c0000000         fld qword ptr [ecx + 0xc0]
// 00793236  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00793230 {
    char pad[192];
    double m_x;
    double f();
};
double S_func_00793230::f()
{
    return m_x;
}
