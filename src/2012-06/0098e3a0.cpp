// roc 2012-06 0098e3a0  unit: CXTPEdit  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0098e3a0
//
// 0098e3a0  b8b4d2c000           mov eax, 0xc0d2b4
// 0098e3a5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0098e3a0()
{
    return &G;
}
