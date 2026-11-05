// roc 2012-06 00a304b0  unit: CXTPReportHeaderDropWnd  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a304b0
//
// 00a304b0  b84c03c200           mov eax, 0xc2034c
// 00a304b5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a304b0()
{
    return &G;
}
