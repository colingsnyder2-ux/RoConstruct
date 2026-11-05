// roc 2008-06 00718550  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00718550
//
// 00718550  b856857100           mov eax, 0x718556
// 00718555  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00718550()
{
    return &G;
}
