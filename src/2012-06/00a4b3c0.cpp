// roc 2012-06 00a4b3c0  unit: CXTPTabManagerItem  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a4b3c0
//
// 00a4b3c0  b8602fc200           mov eax, 0xc22f60
// 00a4b3c5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a4b3c0()
{
    return &G;
}
