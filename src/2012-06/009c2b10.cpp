// roc 2012-06 009c2b10  unit: CXTTreeView  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c2b10
//
// 009c2b10  b8901cc100           mov eax, 0xc11c90
// 009c2b15  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009c2b10()
{
    return &G;
}
