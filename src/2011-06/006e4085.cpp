// roc 2011-06 006e4085  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006e4085
//
// 006e4085  b88b406e00           mov eax, 0x6e408b
// 006e408a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006e4085()
{
    return &G;
}
