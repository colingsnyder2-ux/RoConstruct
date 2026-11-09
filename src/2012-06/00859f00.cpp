// roc 2012-06 00859f00  unit: VWinHttpRequest_source::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00859f00
//
// 00859f00  b80434de00           mov eax, 0xde3404
// 00859f05  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00859f00()
{
    return &G;
}
