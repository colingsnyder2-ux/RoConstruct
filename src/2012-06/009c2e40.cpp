// roc 2012-06 009c2e40  unit: RootNode  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c2e40
//
// 009c2e40  b83c29c100           mov eax, 0xc1293c
// 009c2e45  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009c2e40()
{
    return &G;
}
