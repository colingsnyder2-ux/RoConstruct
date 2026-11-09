// roc 2012-06 009dc5f0  unit: CXTPControlTabWorkspace  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009dc5f0
//
// 009dc5f0  b87045e000           mov eax, 0xe04570
// 009dc5f5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009dc5f0()
{
    return &G;
}
