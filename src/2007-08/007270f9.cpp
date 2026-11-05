// roc 2007-08 007270f9  unit: boost::thread_resource_error  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007270f9
//
// 007270f9  b8ff707200           mov eax, 0x7270ff
// 007270fe  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_007270f9()
{
    return &G;
}
