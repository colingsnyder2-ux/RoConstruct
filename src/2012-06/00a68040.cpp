// roc 2012-06 00a68040  unit: CXTColorPopup  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a68040
//
// 00a68040  b87c54c200           mov eax, 0xc2547c
// 00a68045  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a68040()
{
    return &G;
}
