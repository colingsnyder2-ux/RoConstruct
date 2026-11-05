// roc 2012-06 00a35b40  unit: CXTPDockingPaneAutoHidePanel  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a35b40
//
// 00a35b40  b8b40dc200           mov eax, 0xc20db4
// 00a35b45  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a35b40()
{
    return &G;
}
