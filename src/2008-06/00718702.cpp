// roc 2008-06 00718702  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00718702
//
// 00718702  b808877100           mov eax, 0x718708
// 00718707  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00718702()
{
    return &G;
}
