// roc 2012-06 009f6bd0  unit: CXTCaption  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f6bd0
//
// 009f6bd0  b834a5c100           mov eax, 0xc1a534
// 009f6bd5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f6bd0()
{
    return &G;
}
