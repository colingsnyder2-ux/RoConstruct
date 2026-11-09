// roc 2012-06 00735fb0  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00735fb0
//
// 00735fb0  8b4150               mov eax, dword ptr [ecx + 0x50]
// 00735fb3  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00735fb0 {
    char pad0[80];
    int m_x;
    int f();
};
int S_func_00735fb0::f()
{
    return m_x;
}
