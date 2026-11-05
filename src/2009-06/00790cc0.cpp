// roc 2009-06 00790cc0  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00790cc0
//
// 00790cc0  b8c60c7900           mov eax, 0x790cc6
// 00790cc5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00790cc0()
{
    return &G;
}
