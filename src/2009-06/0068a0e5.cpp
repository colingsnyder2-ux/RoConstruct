// roc 2009-06 0068a0e5  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0068a0e5
//
// 0068a0e5  b8eba06800           mov eax, 0x68a0eb
// 0068a0ea  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0068a0e5()
{
    return &G;
}
