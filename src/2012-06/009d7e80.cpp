// roc 2012-06 009d7e80  unit: CXTPPropExchangeArchive  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d7e80
//
// 009d7e80  b8605fc100           mov eax, 0xc15f60
// 009d7e85  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009d7e80()
{
    return &G;
}
