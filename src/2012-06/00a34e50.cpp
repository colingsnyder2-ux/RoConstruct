// roc 2012-06 00a34e50  unit: CXTPDockingPaneAutoHideWnd  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a34e50
//
// 00a34e50  b8380bc200           mov eax, 0xc20b38
// 00a34e55  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a34e50()
{
    return &G;
}
