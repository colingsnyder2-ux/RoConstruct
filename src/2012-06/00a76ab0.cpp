// roc 2012-06 00a76ab0  unit: CXTPRibbonSystemPopupBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a76ab0
//
// 00a76ab0  b80882e000           mov eax, 0xe08208
// 00a76ab5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a76ab0()
{
    return &G;
}
