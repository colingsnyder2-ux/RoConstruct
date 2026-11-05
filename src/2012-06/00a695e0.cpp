// roc 2012-06 00a695e0  unit: PAVCXTShadowWnd::?$CList  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a695e0
//
// 00a695e0  b84857c200           mov eax, 0xc25748
// 00a695e5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a695e0()
{
    return &G;
}
