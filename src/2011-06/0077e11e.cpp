// roc 2011-06 0077e11e  unit: lua_exception  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0077e11e
//
// 0077e11e  b83fe17700           mov eax, 0x77e13f
// 0077e123  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0077e11e()
{
    return &G;
}
