// roc 2008-06 007181fd  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007181fd
//
// 007181fd  b803827100           mov eax, 0x718203
// 00718202  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_007181fd()
{
    return &G;
}
