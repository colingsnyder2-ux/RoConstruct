// roc 2012-06 009cbce0  unit: CXTPPopupToolBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009cbce0
//
// 009cbce0  b81440e000           mov eax, 0xe04014
// 009cbce5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009cbce0()
{
    return &G;
}
