// roc 2010-06 0081fb9d  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081fb9d
//
// 0081fb9d  b8a3fb8100           mov eax, 0x81fba3
// 0081fba2  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0081fb9d()
{
    return &G;
}
