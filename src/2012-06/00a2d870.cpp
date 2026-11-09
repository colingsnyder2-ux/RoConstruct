// roc 2012-06 00a2d870  unit: CXTPReportTip  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a2d870
//
// 00a2d870  b8dcfac100           mov eax, 0xc1fadc
// 00a2d875  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a2d870()
{
    return &G;
}
