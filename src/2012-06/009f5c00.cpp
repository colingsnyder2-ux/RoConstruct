// roc 2012-06 009f5c00  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f5c00
//
// 009f5c00  b8065c9f00           mov eax, 0x9f5c06
// 009f5c05  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f5c00()
{
    return &G;
}
