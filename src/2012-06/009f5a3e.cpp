// roc 2012-06 009f5a3e  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f5a3e
//
// 009f5a3e  b82a5a9f00           mov eax, 0x9f5a2a
// 009f5a43  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f5a3e()
{
    return &G;
}
