// roc 2012-06 00a792f0  unit: CXTWindowMap  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a792f0
//
// 00a792f0  b81498c200           mov eax, 0xc29814
// 00a792f5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a792f0()
{
    return &G;
}
