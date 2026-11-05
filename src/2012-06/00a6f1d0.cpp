// roc 2012-06 00a6f1d0  unit: CXTPRibbonGroupControlPopup  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a6f1d0
//
// 00a6f1d0  b8647ee000           mov eax, 0xe07e64
// 00a6f1d5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a6f1d0()
{
    return &G;
}
