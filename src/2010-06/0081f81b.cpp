// roc 2010-06 0081f81b  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081f81b
//
// 0081f81b  b821f88100           mov eax, 0x81f821
// 0081f820  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0081f81b()
{
    return &G;
}
