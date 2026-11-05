// roc 2012-06 00a79870  unit: CXTButtonThemeFactory  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a79870
//
// 00a79870  b83499c200           mov eax, 0xc29934
// 00a79875  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a79870()
{
    return &G;
}
