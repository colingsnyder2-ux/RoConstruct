// roc 2012-06 00a2b660  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a2b660
//
// 00a2b660  8b4128               mov eax, dword ptr [ecx + 0x28]
// 00a2b663  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a2b660 {
    char pad0[40];
    int m_x;
    int f();
};
int S_func_00a2b660::f()
{
    return m_x;
}
