// roc 2012-06 00558730  unit: XVCrashReporter::XV?$mf0::V?$bind_t::?$thread_data  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00558730
//
// 00558730  dd81d8000000         fld qword ptr [ecx + 0xd8]
// 00558736  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00558730 {
    char pad[216];
    double m_x;
    double f();
};
double S_func_00558730::f()
{
    return m_x;
}
