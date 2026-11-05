// roc 2012-06 00a1e100  unit: CXTPRibbonBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a1e100
//
// 00a1e100  b81c5ee000           mov eax, 0xe05e1c
// 00a1e105  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a1e100()
{
    return &G;
}
