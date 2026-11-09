// roc 2012-06 00793220  unit: RBX::Profiling::Profiler  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00793220
//
// 00793220  dd81b8000000         fld qword ptr [ecx + 0xb8]
// 00793226  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00793220 {
    char pad[184];
    double m_x;
    double f();
};
double S_func_00793220::f()
{
    return m_x;
}
