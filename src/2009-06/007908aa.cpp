// roc 2009-06 007908aa  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007908aa
//
// 007908aa  b8b0087900           mov eax, 0x7908b0
// 007908af  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_007908aa()
{
    return &G;
}
