// roc 2012-06 007931f0  unit: RBX::Profiling::Profiler  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007931f0
//
// 007931f0  dd81a8000000         fld qword ptr [ecx + 0xa8]
// 007931f6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007931f0 {
    char pad[168];
    double m_x;
    double f();
};
double S_func_007931f0::f()
{
    return m_x;
}
