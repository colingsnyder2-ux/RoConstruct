// roc 2012-06 009d25c0  unit: CXTPControlToolbars  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d25c0
//
// 009d25c0  b8e440e000           mov eax, 0xe040e4
// 009d25c5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009d25c0()
{
    return &G;
}
