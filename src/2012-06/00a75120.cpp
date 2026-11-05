// roc 2012-06 00a75120  unit: CXTPRibbonGroupPopupToolBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a75120
//
// 00a75120  b8387ac200           mov eax, 0xc27a38
// 00a75125  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a75120()
{
    return &G;
}
