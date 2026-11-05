// roc 2012-06 00a6a580  unit: CXTCaptionButton  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a6a580
//
// 00a6a580  b8a05ac200           mov eax, 0xc25aa0
// 00a6a585  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a6a580()
{
    return &G;
}
