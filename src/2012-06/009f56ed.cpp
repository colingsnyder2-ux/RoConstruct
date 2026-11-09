// roc 2012-06 009f56ed  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f56ed
//
// 009f56ed  b8f3569f00           mov eax, 0x9f56f3
// 009f56f2  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f56ed()
{
    return &G;
}
