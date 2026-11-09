// roc 2012-06 009f5b42  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f5b42
//
// 009f5b42  b8485b9f00           mov eax, 0x9f5b48
// 009f5b47  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f5b42()
{
    return &G;
}
