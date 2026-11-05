// roc 2012-06 0085c38e  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085c38e
//
// 0085c38e  b894c38500           mov eax, 0x85c394
// 0085c393  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0085c38e()
{
    return &G;
}
