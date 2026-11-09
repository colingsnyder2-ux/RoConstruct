// roc 2007-08 005c5957  unit: lua_exception  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c5957
//
// 005c5957  b878595c00           mov eax, 0x5c5978
// 005c595c  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_005c5957()
{
    return &G;
}
