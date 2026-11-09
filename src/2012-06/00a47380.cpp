// roc 2012-06 00a47380  unit: IIPAVCRgn::?$CMap  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a47380
//
// 00a47380  b8602ac200           mov eax, 0xc22a60
// 00a47385  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a47380()
{
    return &G;
}
