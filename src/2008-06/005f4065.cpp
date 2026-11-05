// roc 2008-06 005f4065  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f4065
//
// 005f4065  b86b405f00           mov eax, 0x5f406b
// 005f406a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_005f4065()
{
    return &G;
}
