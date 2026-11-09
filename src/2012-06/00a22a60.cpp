// roc 2012-06 00a22a60  unit: CXTPRibbonBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a22a60
//
// 00a22a60  b870f4c100           mov eax, 0xc1f470
// 00a22a65  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a22a60()
{
    return &G;
}
