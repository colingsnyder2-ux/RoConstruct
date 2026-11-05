// roc 2012-06 007931e0  unit: RBX::Profiling::Profiler  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007931e0
//
// 007931e0  dd8190000000         fld qword ptr [ecx + 0x90]
// 007931e6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007931e0 {
    char pad[144];
    double m_x;
    double f();
};
double S_func_007931e0::f()
{
    return m_x;
}
