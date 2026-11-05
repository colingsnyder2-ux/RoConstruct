// roc 2012-06 009cb7b0  unit: CXTPPopupBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009cb7b0
//
// 009cb7b0  b8f83fe000           mov eax, 0xe03ff8
// 009cb7b5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009cb7b0()
{
    return &G;
}
