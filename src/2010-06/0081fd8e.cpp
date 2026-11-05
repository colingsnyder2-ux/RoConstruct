// roc 2010-06 0081fd8e  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081fd8e
//
// 0081fd8e  b87afd8100           mov eax, 0x81fd7a
// 0081fd93  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0081fd8e()
{
    return &G;
}
