// roc 2009-06 00790f30  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00790f30
//
// 00790f30  b8360f7900           mov eax, 0x790f36
// 00790f35  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00790f30()
{
    return &G;
}
