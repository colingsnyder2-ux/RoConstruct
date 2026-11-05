// roc 2012-06 00a3d200  unit: CXTPDockingPaneTabbedContainer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a3d200
//
// 00a3d200  b8b81ac200           mov eax, 0xc21ab8
// 00a3d205  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a3d200()
{
    return &G;
}
