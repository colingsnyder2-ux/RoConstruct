// roc 2012-06 00a769f0  unit: CXTPRibbonControlSystemButton  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a769f0
//
// 00a769f0  b8ec81e000           mov eax, 0xe081ec
// 00a769f5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a769f0()
{
    return &G;
}
