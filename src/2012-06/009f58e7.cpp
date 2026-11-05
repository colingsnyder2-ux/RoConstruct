// roc 2012-06 009f58e7  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f58e7
//
// 009f58e7  b8ed589f00           mov eax, 0x9f58ed
// 009f58ec  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f58e7()
{
    return &G;
}
