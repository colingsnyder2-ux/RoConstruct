// roc 2007-08 004d163c  unit: RBX::View::Decal  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d163c
//
// 004d163c  b842164d00           mov eax, 0x4d1642
// 004d1641  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_004d163c()
{
    return &G;
}
