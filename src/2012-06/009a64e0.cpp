// roc 2012-06 009a64e0  unit: CXTPReportViewPrintOptions  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009a64e0
//
// 009a64e0  b860f7c000           mov eax, 0xc0f760
// 009a64e5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009a64e0()
{
    return &G;
}
