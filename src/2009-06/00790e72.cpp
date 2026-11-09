// roc 2009-06 00790e72  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00790e72
//
// 00790e72  b8780e7900           mov eax, 0x790e78
// 00790e77  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00790e72()
{
    return &G;
}
