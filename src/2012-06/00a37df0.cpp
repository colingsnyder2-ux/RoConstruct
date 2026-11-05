// roc 2012-06 00a37df0  unit: CXTPDockingPaneMiniWnd  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a37df0
//
// 00a37df0  b8e811c200           mov eax, 0xc211e8
// 00a37df5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a37df0()
{
    return &G;
}
