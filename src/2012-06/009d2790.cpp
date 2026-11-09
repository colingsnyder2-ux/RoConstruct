// roc 2012-06 009d2790  unit: CXTPControlRadioButton  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d2790
//
// 009d2790  b8a841e000           mov eax, 0xe041a8
// 009d2795  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009d2790()
{
    return &G;
}
