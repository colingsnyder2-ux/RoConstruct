// roc 2012-06 009f7d30  unit: CXTCaption  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f7d30
//
// 009f7d30  b8f0a9c100           mov eax, 0xc1a9f0
// 009f7d35  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f7d30()
{
    return &G;
}
