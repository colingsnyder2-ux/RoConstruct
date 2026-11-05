// roc 2012-06 009ca7b0  unit: CXTPControlButtonColor  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ca7b0
//
// 009ca7b0  b8403fe000           mov eax, 0xe03f40
// 009ca7b5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009ca7b0()
{
    return &G;
}
