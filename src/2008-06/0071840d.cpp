// roc 2008-06 0071840d  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071840d
//
// 0071840d  b813847100           mov eax, 0x718413
// 00718412  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0071840d()
{
    return &G;
}
