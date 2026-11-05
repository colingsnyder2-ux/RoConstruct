// roc 2012-06 00991060  unit: CXTPControlEditCtrl  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00991060
//
// 00991060  b874dec000           mov eax, 0xc0de74
// 00991065  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00991060()
{
    return &G;
}
