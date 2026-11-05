// roc 2012-06 009f5ca4  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f5ca4
//
// 009f5ca4  b8905c9f00           mov eax, 0x9f5c90
// 009f5ca9  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f5ca4()
{
    return &G;
}
