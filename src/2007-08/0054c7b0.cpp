// roc 2007-08 0054c7b0  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054c7b0
//
// 0054c7b0  b8b6c75400           mov eax, 0x54c7b6
// 0054c7b5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0054c7b0()
{
    return &G;
}
