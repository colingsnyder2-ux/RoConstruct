// roc 2012-06 00736020  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00736020
//
// 00736020  d94140               fld dword ptr [ecx + 0x40]
// 00736023  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00736020 {
    char pad[64];
    float m_x;
    float f();
};
float S_func_00736020::f()
{
    return m_x;
}
