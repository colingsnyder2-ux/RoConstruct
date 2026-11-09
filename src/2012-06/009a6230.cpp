// roc 2012-06 009a6230  unit: CXTPReportView  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009a6230
//
// 009a6230  b844f7c000           mov eax, 0xc0f744
// 009a6235  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009a6230()
{
    return &G;
}
