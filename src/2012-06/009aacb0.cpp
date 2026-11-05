// roc 2012-06 009aacb0  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009aacb0
//
// 009aacb0  8b4158               mov eax, dword ptr [ecx + 0x58]
// 009aacb3  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009aacb0 {
    char pad0[88];
    int m_x;
    int f();
};
int S_func_009aacb0::f()
{
    return m_x;
}
