// roc 2012-06 009a21b0  unit: CXTPCommandBars  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009a21b0
//
// 009a21b0  b828f2c000           mov eax, 0xc0f228
// 009a21b5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009a21b0()
{
    return &G;
}
