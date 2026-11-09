// roc 2012-06 00736010  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00736010
//
// 00736010  d94130               fld dword ptr [ecx + 0x30]
// 00736013  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00736010 {
    char pad[48];
    float m_x;
    float f();
};
float S_func_00736010::f()
{
    return m_x;
}
