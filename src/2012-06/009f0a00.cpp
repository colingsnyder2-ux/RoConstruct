// roc 2012-06 009f0a00  unit: CXTPPropertyGridToolTip  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f0a00
//
// 009f0a00  b8c890c100           mov eax, 0xc190c8
// 009f0a05  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f0a00()
{
    return &G;
}
