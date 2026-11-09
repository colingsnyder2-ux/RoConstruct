// roc 2009-06 006c2c0e  unit: lua_exception  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c2c0e
//
// 006c2c0e  b82f2c6c00           mov eax, 0x6c2c2f
// 006c2c13  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006c2c0e()
{
    return &G;
}
