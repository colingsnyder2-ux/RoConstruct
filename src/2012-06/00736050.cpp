// roc 2012-06 00736050  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00736050
//
// 00736050  8a4144               mov al, byte ptr [ecx + 0x44]
// 00736053  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00736050 {
    char pad0[68];
    char m_x;
    char f();
};
char S_func_00736050::f()
{
    return m_x;
}
