// roc 2012-06 009d25f0  unit: CXTPControlOleItems  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d25f0
//
// 009d25f0  b80041e000           mov eax, 0xe04100
// 009d25f5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009d25f0()
{
    return &G;
}
