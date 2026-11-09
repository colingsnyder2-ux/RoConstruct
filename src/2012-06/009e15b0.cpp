// roc 2012-06 009e15b0  unit: CXTPTabClientWnd  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e15b0
//
// 009e15b0  b8706bc100           mov eax, 0xc16b70
// 009e15b5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009e15b0()
{
    return &G;
}
