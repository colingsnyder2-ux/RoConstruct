// roc 2012-06 00a56b40  unit: CXTPPropertyGridInplaceEdit  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a56b40
//
// 00a56b40  b8f835c200           mov eax, 0xc235f8
// 00a56b45  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a56b40()
{
    return &G;
}
