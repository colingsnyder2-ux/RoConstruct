// roc 2008-06 007185fe  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007185fe
//
// 007185fe  b8ea857100           mov eax, 0x7185ea
// 00718603  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_007185fe()
{
    return &G;
}
