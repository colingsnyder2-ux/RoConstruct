// roc 2012-06 00a6ef10  unit: CXTPRibbonGroup  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a6ef10
//
// 00a6ef10  b8487ee000           mov eax, 0xe07e48
// 00a6ef15  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a6ef10()
{
    return &G;
}
