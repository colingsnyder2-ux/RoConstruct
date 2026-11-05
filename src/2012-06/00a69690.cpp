// roc 2012-06 00a69690  unit: CXTCaptionThemeFactory  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a69690
//
// 00a69690  b84858c200           mov eax, 0xc25848
// 00a69695  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a69690()
{
    return &G;
}
