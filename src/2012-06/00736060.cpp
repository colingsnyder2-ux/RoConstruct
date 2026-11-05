// roc 2012-06 00736060  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00736060
//
// 00736060  8a4145               mov al, byte ptr [ecx + 0x45]
// 00736063  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00736060 {
    char pad0[69];
    char m_x;
    char f();
};
char S_func_00736060::f()
{
    return m_x;
}
