// roc 2012-06 00a3ab40  unit: CXTPDockingPaneTabbedContainer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a3ab40
//
// 00a3ab40  b84817c200           mov eax, 0xc21748
// 00a3ab45  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a3ab40()
{
    return &G;
}
