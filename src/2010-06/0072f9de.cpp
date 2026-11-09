// roc 2010-06 0072f9de  unit: lua_exception  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0072f9de
//
// 0072f9de  b8fff97200           mov eax, 0x72f9ff
// 0072f9e3  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0072f9de()
{
    return &G;
}
