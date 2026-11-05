// roc 2011-06 00423acd  unit: InsertObject  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00423acd
//
// 00423acd  b8b03a4200           mov eax, 0x423ab0
// 00423ad2  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00423acd()
{
    return &G;
}
