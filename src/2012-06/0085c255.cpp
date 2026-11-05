// roc 2012-06 0085c255  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085c255
//
// 0085c255  b85bc28500           mov eax, 0x85c25b
// 0085c25a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0085c255()
{
    return &G;
}
