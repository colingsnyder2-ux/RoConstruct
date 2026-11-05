// roc 2012-06 009f557b  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f557b
//
// 009f557b  b881559f00           mov eax, 0x9f5581
// 009f5580  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f557b()
{
    return &G;
}
