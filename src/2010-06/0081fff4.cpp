// roc 2010-06 0081fff4  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081fff4
//
// 0081fff4  b8e0ff8100           mov eax, 0x81ffe0
// 0081fff9  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0081fff4()
{
    return &G;
}
