// roc 2011-06 00423649  unit: InsertService  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00423649
//
// 00423649  b82c364200           mov eax, 0x42362c
// 0042364e  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00423649()
{
    return &G;
}
