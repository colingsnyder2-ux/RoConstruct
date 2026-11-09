// roc 2010-06 006a33ee  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006a33ee
//
// 006a33ee  b8f4336a00           mov eax, 0x6a33f4
// 006a33f3  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006a33ee()
{
    return &G;
}
