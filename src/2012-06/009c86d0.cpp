// roc 2012-06 009c86d0  unit: CXTPDockingPaneManager  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c86d0
//
// 009c86d0  b8d036c100           mov eax, 0xc136d0
// 009c86d5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009c86d0()
{
    return &G;
}
