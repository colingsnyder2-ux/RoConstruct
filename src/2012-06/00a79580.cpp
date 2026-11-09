// roc 2012-06 00a79580  unit: CXTMemDC  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a79580
//
// 00a79580  b87c98c200           mov eax, 0xc2987c
// 00a79585  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a79580()
{
    return &G;
}
