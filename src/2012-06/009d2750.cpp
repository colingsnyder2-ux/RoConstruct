// roc 2012-06 009d2750  unit: CXTPControlCheckBox  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d2750
//
// 009d2750  b88c41e000           mov eax, 0xe0418c
// 009d2755  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009d2750()
{
    return &G;
}
