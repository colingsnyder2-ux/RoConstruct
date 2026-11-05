// roc 2010-06 0081fa42  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081fa42
//
// 0081fa42  b848fa8100           mov eax, 0x81fa48
// 0081fa47  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0081fa42()
{
    return &G;
}
