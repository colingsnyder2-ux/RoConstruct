// roc 2012-06 009d8010  unit: CXTPPropExchangeXMLNode  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d8010
//
// 009d8010  b87c5fc100           mov eax, 0xc15f7c
// 009d8015  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009d8010()
{
    return &G;
}
