// roc 2012-06 00a15e10  unit: CXTPControlEdit  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a15e10
//
// 00a15e10  b8a0d3c100           mov eax, 0xc1d3a0
// 00a15e15  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a15e10()
{
    return &G;
}
