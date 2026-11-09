// roc 2012-06 009eac20  unit: CXTPToolTipContextToolTip  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009eac20
//
// 009eac20  b83081c100           mov eax, 0xc18130
// 009eac25  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009eac20()
{
    return &G;
}
