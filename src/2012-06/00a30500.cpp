// roc 2012-06 00a30500  unit: CXTPReportHyperlink  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a30500
//
// 00a30500  b8e403c200           mov eax, 0xc203e4
// 00a30505  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a30500()
{
    return &G;
}
