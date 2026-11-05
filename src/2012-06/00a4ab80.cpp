// roc 2012-06 00a4ab80  unit: CXTPControlCustom  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a4ab80
//
// 00a4ab80  b8686ee000           mov eax, 0xe06e68
// 00a4ab85  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a4ab80()
{
    return &G;
}
