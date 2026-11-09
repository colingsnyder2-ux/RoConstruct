// roc 2012-06 007e6b20  unit: CXTPReportControl  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e6b20
//
// 007e6b20  8b81ec020000         mov eax, dword ptr [ecx + 0x2ec]
// 007e6b26  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007e6b20 {
    char pad0[748];
    int m_x;
    int f();
};
int S_func_007e6b20::f()
{
    return m_x;
}
