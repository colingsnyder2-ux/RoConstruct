// roc 2012-06 00558720  unit: XVCrashReporter::XV?$mf0::V?$bind_t::?$thread_data  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00558720
//
// 00558720  d981d0000000         fld dword ptr [ecx + 0xd0]
// 00558726  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00558720 {
    char pad[208];
    float m_x;
    float f();
};
float S_func_00558720::f()
{
    return m_x;
}
