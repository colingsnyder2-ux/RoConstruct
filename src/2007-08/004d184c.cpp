// roc 2007-08 004d184c  unit: RBX::View::Texture  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d184c
//
// 004d184c  b852184d00           mov eax, 0x4d1852
// 004d1851  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_004d184c()
{
    return &G;
}
