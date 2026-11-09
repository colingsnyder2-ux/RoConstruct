// roc 2012-06 009e6ec0  unit: CXTPStatusBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e6ec0
//
// 009e6ec0  b8d478c100           mov eax, 0xc178d4
// 009e6ec5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009e6ec0()
{
    return &G;
}
