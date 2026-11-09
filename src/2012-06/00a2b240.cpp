// roc 2012-06 00a2b240  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a2b240
//
// 00a2b240  b870f8c100           mov eax, 0xc1f870
// 00a2b245  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a2b240()
{
    return &G;
}
