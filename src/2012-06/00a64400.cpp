// roc 2012-06 00a64400  unit: CXTColorPageCustom  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a64400
//
// 00a64400  b8ac4ec200           mov eax, 0xc24eac
// 00a64405  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a64400()
{
    return &G;
}
