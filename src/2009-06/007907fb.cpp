// roc 2009-06 007907fb  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007907fb
//
// 007907fb  b801087900           mov eax, 0x790801
// 00790800  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_007907fb()
{
    return &G;
}
