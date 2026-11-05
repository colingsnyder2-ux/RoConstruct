// roc 2012-06 00793200  unit: RBX::Profiling::Profiler  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00793200
//
// 00793200  dd8198000000         fld qword ptr [ecx + 0x98]
// 00793206  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00793200 {
    char pad[152];
    double m_x;
    double f();
};
double S_func_00793200::f()
{
    return m_x;
}
