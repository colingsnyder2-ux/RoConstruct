// roc 2009-06 006150a5  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006150a5
//
// 006150a5  b8ab506100           mov eax, 0x6150ab
// 006150aa  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006150a5()
{
    return &G;
}
