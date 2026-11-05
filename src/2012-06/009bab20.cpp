// roc 2012-06 009bab20  unit: VCXTPReportRecords::?$CXTPHeapObjectT  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009bab20
//
// 009bab20  b8a817c100           mov eax, 0xc117a8
// 009bab25  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009bab20()
{
    return &G;
}
