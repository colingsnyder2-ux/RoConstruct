// roc 2008-06 005f419e  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f419e
//
// 005f419e  b8a4415f00           mov eax, 0x5f41a4
// 005f41a3  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_005f419e()
{
    return &G;
}
