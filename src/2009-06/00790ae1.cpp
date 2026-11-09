// roc 2009-06 00790ae1  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00790ae1
//
// 00790ae1  b8e70a7900           mov eax, 0x790ae7
// 00790ae6  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00790ae1()
{
    return &G;
}
