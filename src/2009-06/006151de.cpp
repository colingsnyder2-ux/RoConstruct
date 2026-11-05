// roc 2009-06 006151de  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006151de
//
// 006151de  b8e4516100           mov eax, 0x6151e4
// 006151e3  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006151de()
{
    return &G;
}
