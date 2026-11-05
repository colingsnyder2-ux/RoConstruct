// roc 2009-06 00790d6e  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00790d6e
//
// 00790d6e  b85a0d7900           mov eax, 0x790d5a
// 00790d73  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00790d6e()
{
    return &G;
}
