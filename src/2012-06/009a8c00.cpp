// roc 2012-06 009a8c00  unit: CXTPReportControl  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009a8c00
//
// 009a8c00  b8e0fec000           mov eax, 0xc0fee0
// 009a8c05  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009a8c00()
{
    return &G;
}
