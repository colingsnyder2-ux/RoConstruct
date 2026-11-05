// roc 2007-08 0054cfee  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054cfee
//
// 0054cfee  b8f4cf5400           mov eax, 0x54cff4
// 0054cff3  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0054cfee()
{
    return &G;
}
