// roc 2008-06 0071808b  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071808b
//
// 0071808b  b891807100           mov eax, 0x718091
// 00718090  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0071808b()
{
    return &G;
}
