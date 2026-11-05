// roc 2012-06 00a2b670  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a2b670
//
// 00a2b670  8b4164               mov eax, dword ptr [ecx + 0x64]
// 00a2b673  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a2b670 {
    char pad0[100];
    int m_x;
    int f();
};
int S_func_00a2b670::f()
{
    return m_x;
}
