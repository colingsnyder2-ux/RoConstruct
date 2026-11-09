// roc 2007-08 0054ceb5  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054ceb5
//
// 0054ceb5  b8bbce5400           mov eax, 0x54cebb
// 0054ceba  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0054ceb5()
{
    return &G;
}
