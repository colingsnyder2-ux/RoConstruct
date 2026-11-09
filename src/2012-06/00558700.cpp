// roc 2012-06 00558700  unit: XVCrashReporter::XV?$mf0::V?$bind_t::?$thread_data  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00558700
//
// 00558700  8b81c4000000         mov eax, dword ptr [ecx + 0xc4]
// 00558706  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00558700 {
    char pad0[196];
    int m_x;
    int f();
};
int S_func_00558700::f()
{
    return m_x;
}
