// roc 2009-06 00790a22  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00790a22
//
// 00790a22  b8280a7900           mov eax, 0x790a28
// 00790a27  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00790a22()
{
    return &G;
}
