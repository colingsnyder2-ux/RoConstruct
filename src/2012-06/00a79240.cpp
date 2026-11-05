// roc 2012-06 00a79240  unit: CXTShadowHook  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a79240
//
// 00a79240  b8f897c200           mov eax, 0xc297f8
// 00a79245  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a79240()
{
    return &G;
}
