// roc 2012-06 009f12e0  unit: CXTPPropertyGridItem  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f12e0
//
// 009f12e0  b8a893c100           mov eax, 0xc193a8
// 009f12e5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f12e0()
{
    return &G;
}
