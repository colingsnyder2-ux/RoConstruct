// roc 2012-06 00a77ca0  unit: CXTPRibbonSystemPopupBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a77ca0
//
// 00a77ca0  b81c8dc200           mov eax, 0xc28d1c
// 00a77ca5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a77ca0()
{
    return &G;
}
