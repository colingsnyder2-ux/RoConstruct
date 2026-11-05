// roc 2012-06 00a2f220  unit: CXTPReportInplaceEdit  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a2f220
//
// 00a2f220  b868ffc100           mov eax, 0xc1ff68
// 00a2f225  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a2f220()
{
    return &G;
}
