// roc 2012-06 009f562a  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f562a
//
// 009f562a  b830569f00           mov eax, 0x9f5630
// 009f562f  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f562a()
{
    return &G;
}
