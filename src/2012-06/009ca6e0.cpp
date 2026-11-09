// roc 2012-06 009ca6e0  unit: CXTPControlPopupColor  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ca6e0
//
// 009ca6e0  b8243fe000           mov eax, 0xe03f24
// 009ca6e5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009ca6e0()
{
    return &G;
}
