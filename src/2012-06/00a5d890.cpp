// roc 2012-06 00a5d890  unit: CXTPPropertyGridInplaceList  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a5d890
//
// 00a5d890  b89c3ec200           mov eax, 0xc23e9c
// 00a5d895  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a5d890()
{
    return &G;
}
