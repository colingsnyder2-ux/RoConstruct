// roc 2009-06 00790fd4  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00790fd4
//
// 00790fd4  b8c00f7900           mov eax, 0x790fc0
// 00790fd9  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00790fd4()
{
    return &G;
}
