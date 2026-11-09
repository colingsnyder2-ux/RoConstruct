// roc 2012-06 00a2d960  unit: CXTPReportInplaceEdit  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a2d960
//
// 00a2d960  b878fbc100           mov eax, 0xc1fb78
// 00a2d965  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a2d960()
{
    return &G;
}
