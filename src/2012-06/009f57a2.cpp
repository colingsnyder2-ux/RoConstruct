// roc 2012-06 009f57a2  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f57a2
//
// 009f57a2  b8a8579f00           mov eax, 0x9f57a8
// 009f57a7  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f57a2()
{
    return &G;
}
