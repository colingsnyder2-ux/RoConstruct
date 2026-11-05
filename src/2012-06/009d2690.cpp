// roc 2012-06 009d2690  unit: CXTPControlWorkspaceActions  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d2690
//
// 009d2690  b85441e000           mov eax, 0xe04154
// 009d2695  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009d2690()
{
    return &G;
}
