// roc 2009-06 00790c17  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00790c17
//
// 00790c17  b81d0c7900           mov eax, 0x790c1d
// 00790c1c  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00790c17()
{
    return &G;
}
