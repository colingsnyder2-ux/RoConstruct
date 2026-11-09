// roc 2012-06 009b0c00  unit: CXTPReportControl  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b0c00
//
// 009b0c00  8b8114010000         mov eax, dword ptr [ecx + 0x114]
// 009b0c06  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009b0c00 {
    char pad0[276];
    int m_x;
    int f();
};
int S_func_009b0c00::f()
{
    return m_x;
}
