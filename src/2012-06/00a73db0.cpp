// roc 2012-06 00a73db0  unit: CXTPRibbonGroupPopupToolBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a73db0
//
// 00a73db0  b88480e000           mov eax, 0xe08084
// 00a73db5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a73db0()
{
    return &G;
}
