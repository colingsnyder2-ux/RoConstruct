// roc 2012-06 009dc7d0  unit: CXTPTabClientWnd  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009dc7d0
//
// 009dc7d0  b8f062c100           mov eax, 0xc162f0
// 009dc7d5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009dc7d0()
{
    return &G;
}
