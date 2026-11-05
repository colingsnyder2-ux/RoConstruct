// roc 2007-08 0062fbaa  unit: RBX::IndexBox  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0062fbaa
//
// 0062fbaa  b8b0fb6200           mov eax, 0x62fbb0
// 0062fbaf  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0062fbaa()
{
    return &G;
}
