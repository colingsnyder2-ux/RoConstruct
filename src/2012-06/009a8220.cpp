// roc 2012-06 009a8220  unit: CXTPReportView  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009a8220
//
// 009a8220  8b4140               mov eax, dword ptr [ecx + 0x40]
// 009a8223  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009a8220 {
    char pad0[64];
    int m_x;
    int f();
};
int S_func_009a8220::f()
{
    return m_x;
}
