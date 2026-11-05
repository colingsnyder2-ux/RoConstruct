// roc 2012-06 007e6a00  unit: CXTPReportControl  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e6a00
//
// 007e6a00  8a81b0000000         mov al, byte ptr [ecx + 0xb0]
// 007e6a06  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007e6a00 {
    char pad0[176];
    char m_x;
    char f();
};
char S_func_007e6a00::f()
{
    return m_x;
}
