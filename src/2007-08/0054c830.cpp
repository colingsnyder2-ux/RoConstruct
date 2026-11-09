// roc 2007-08 0054c830  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054c830
//
// 0054c830  b836c85400           mov eax, 0x54c836
// 0054c835  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0054c830()
{
    return &G;
}
