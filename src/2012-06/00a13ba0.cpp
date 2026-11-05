// roc 2012-06 00a13ba0  unit: CXTPControlEdit  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a13ba0
//
// 00a13ba0  b81059e000           mov eax, 0xe05910
// 00a13ba5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a13ba0()
{
    return &G;
}
