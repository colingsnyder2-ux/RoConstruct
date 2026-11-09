// roc 2012-06 00427426  unit: InsertObject  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00427426
//
// 00427426  b809744200           mov eax, 0x427409
// 0042742b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00427426()
{
    return &G;
}
