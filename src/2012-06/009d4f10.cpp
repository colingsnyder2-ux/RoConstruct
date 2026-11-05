// roc 2012-06 009d4f10  unit: CXTPPrintOptions  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d4f10
//
// 009d4f10  b8105cc100           mov eax, 0xc15c10
// 009d4f15  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009d4f10()
{
    return &G;
}
