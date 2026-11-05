// roc 2012-06 00859bb0  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00859bb0
//
// 00859bb0  b85433de00           mov eax, 0xde3354
// 00859bb5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00859bb0()
{
    return &G;
}
