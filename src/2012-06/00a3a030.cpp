// roc 2012-06 00a3a030  unit: CXTPDockingPaneMiniWnd  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a3a030
//
// 00a3a030  b85414c200           mov eax, 0xc21454
// 00a3a035  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a3a030()
{
    return &G;
}
