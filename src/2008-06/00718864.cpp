// roc 2008-06 00718864  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00718864
//
// 00718864  b850887100           mov eax, 0x718850
// 00718869  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00718864()
{
    return &G;
}
