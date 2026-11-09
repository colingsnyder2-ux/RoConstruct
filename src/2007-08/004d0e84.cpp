// roc 2007-08 004d0e84  unit: RBX::View::Part  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d0e84
//
// 004d0e84  b88a0e4d00           mov eax, 0x4d0e8a
// 004d0e89  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_004d0e84()
{
    return &G;
}
