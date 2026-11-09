// roc 2010-06 006a32b5  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006a32b5
//
// 006a32b5  b8bb326a00           mov eax, 0x6a32bb
// 006a32ba  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006a32b5()
{
    return &G;
}
