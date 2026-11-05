// roc 2012-06 00861870  unit: VWiniInetRequest_source::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00861870
//
// 00861870  b8043fde00           mov eax, 0xde3f04
// 00861875  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00861870()
{
    return &G;
}
