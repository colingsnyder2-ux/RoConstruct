// roc 2008-06 0062199e  unit: lua_exception  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0062199e
//
// 0062199e  b8bf196200           mov eax, 0x6219bf
// 006219a3  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0062199e()
{
    return &G;
}
