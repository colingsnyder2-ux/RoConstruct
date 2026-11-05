// roc 2012-06 00a47390  unit: IIPAVCRgn::?$CMap  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a47390
//
// 00a47390  b8b02ac200           mov eax, 0xc22ab0
// 00a47395  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a47390()
{
    return &G;
}
