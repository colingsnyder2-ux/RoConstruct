// roc 2010-06 00419aa9  unit: InsertService  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00419aa9
//
// 00419aa9  b88c9a4100           mov eax, 0x419a8c
// 00419aae  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00419aa9()
{
    return &G;
}
