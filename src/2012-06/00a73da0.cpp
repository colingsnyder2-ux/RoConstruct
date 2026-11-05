// roc 2012-06 00a73da0  unit: CXTPRibbonTabPopupToolBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a73da0
//
// 00a73da0  b85070c200           mov eax, 0xc27050
// 00a73da5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a73da0()
{
    return &G;
}
