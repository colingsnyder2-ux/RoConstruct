// roc 2012-06 00a64900  unit: CXTPRichRender  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a64900
//
// 00a64900  b84051c200           mov eax, 0xc25140
// 00a64905  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a64900()
{
    return &G;
}
