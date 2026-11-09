// roc 2012-06 009e6e20  unit: CXTPStatusBarPane  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e6e20
//
// 009e6e20  b8b878c100           mov eax, 0xc178b8
// 009e6e25  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009e6e20()
{
    return &G;
}
