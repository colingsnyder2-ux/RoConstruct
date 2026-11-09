// roc 2012-06 008545ae  unit: lua_exception  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008545ae
//
// 008545ae  b8cf458500           mov eax, 0x8545cf
// 008545b3  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_008545ae()
{
    return &G;
}
