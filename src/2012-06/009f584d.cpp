// roc 2012-06 009f584d  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f584d
//
// 009f584d  b853589f00           mov eax, 0x9f5853
// 009f5852  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f584d()
{
    return &G;
}
