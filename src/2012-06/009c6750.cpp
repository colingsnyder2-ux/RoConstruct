// roc 2012-06 009c6750  unit: CXTPDockingPaneManager  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c6750
//
// 009c6750  b84034c100           mov eax, 0xc13440
// 009c6755  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009c6750()
{
    return &G;
}
