// roc 2008-06 005f98d0  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f98d0
//
// 005f98d0  b8d6985f00           mov eax, 0x5f98d6
// 005f98d5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_005f98d0()
{
    return &G;
}
