// roc 2007-08 00580e59  unit: RBX::Log  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00580e59
//
// 00580e59  b85f0e5800           mov eax, 0x580e5f
// 00580e5e  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00580e59()
{
    return &G;
}
