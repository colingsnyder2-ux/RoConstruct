// roc 2012-06 00a2ede0  unit: CXTPReportInplaceEdit  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a2ede0
//
// 00a2ede0  b870fec100           mov eax, 0xc1fe70
// 00a2ede5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a2ede0()
{
    return &G;
}
