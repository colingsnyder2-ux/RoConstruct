// roc 2012-06 00426fd9  unit: InsertService  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00426fd9
//
// 00426fd9  b8bc6f4200           mov eax, 0x426fbc
// 00426fde  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00426fd9()
{
    return &G;
}
