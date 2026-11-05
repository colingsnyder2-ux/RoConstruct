// roc 2012-06 00993160  unit: CXTPCommandBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00993160
//
// 00993160  b808e1c000           mov eax, 0xc0e108
// 00993165  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00993160()
{
    return &G;
}
