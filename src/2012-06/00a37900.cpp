// roc 2012-06 00a37900  unit: CXTPDockingPaneKeyboardHook  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a37900
//
// 00a37900  b8c010c200           mov eax, 0xc210c0
// 00a37905  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a37900()
{
    return &G;
}
