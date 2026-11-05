// roc 2012-06 005a8c20  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a8c20
//
// 005a8c20  8b4120               mov eax, dword ptr [ecx + 0x20]
// 005a8c23  c3                   ret 
// auto-matched from its assembly shape

struct S_func_005a8c20 {
    char pad0[32];
    int m_x;
    int f();
};
int S_func_005a8c20::f()
{
    return m_x;
}
