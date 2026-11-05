// roc 2012-06 00a6beb0  unit: CXTCaptionPopupWnd  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a6beb0
//
// 00a6beb0  b8e45fc200           mov eax, 0xc25fe4
// 00a6beb5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a6beb0()
{
    return &G;
}
