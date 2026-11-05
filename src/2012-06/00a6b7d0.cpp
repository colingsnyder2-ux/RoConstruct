// roc 2012-06 00a6b7d0  unit: CXTCaptionPopupWnd  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a6b7d0
//
// 00a6b7d0  b85c5ec200           mov eax, 0xc25e5c
// 00a6b7d5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a6b7d0()
{
    return &G;
}
