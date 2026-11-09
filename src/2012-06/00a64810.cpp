// roc 2012-06 00a64810  unit: CXTColorBase  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a64810
//
// 00a64810  b8484fc200           mov eax, 0xc24f48
// 00a64815  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a64810()
{
    return &G;
}
