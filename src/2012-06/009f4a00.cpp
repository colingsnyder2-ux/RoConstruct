// roc 2012-06 009f4a00  unit: CXTPPropertyGridItemBool  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f4a00
//
// 009f4a00  b8c09bc100           mov eax, 0xc19bc0
// 009f4a05  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f4a00()
{
    return &G;
}
