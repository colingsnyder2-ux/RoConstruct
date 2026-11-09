// roc 2012-06 009c2b00  unit: CXTTreeView  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c2b00
//
// 009c2b00  b8581cc100           mov eax, 0xc11c58
// 009c2b05  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009c2b00()
{
    return &G;
}
