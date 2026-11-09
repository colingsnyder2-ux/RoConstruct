// roc 2012-06 009d7960  unit: CXTPPropExchange  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d7960
//
// 009d7960  b8445fc100           mov eax, 0xc15f44
// 009d7965  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009d7960()
{
    return &G;
}
