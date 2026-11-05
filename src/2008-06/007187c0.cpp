// roc 2008-06 007187c0  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007187c0
//
// 007187c0  b8c6877100           mov eax, 0x7187c6
// 007187c5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_007187c0()
{
    return &G;
}
