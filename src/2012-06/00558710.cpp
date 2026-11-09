// roc 2012-06 00558710  unit: XVCrashReporter::XV?$mf0::V?$bind_t::?$thread_data  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00558710
//
// 00558710  d981cc000000         fld dword ptr [ecx + 0xcc]
// 00558716  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00558710 {
    char pad[204];
    float m_x;
    float f();
};
float S_func_00558710::f()
{
    return m_x;
}
