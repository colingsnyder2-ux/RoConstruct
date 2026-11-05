// roc 2012-06 00a700f0  unit: CXTPRibbonTab  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a700f0
//
// 00a700f0  b8f07ee000           mov eax, 0xe07ef0
// 00a700f5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a700f0()
{
    return &G;
}
