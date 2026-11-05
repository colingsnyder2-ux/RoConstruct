// roc 2007-08 00580d49  unit: RBX::Log  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00580d49
//
// 00580d49  b84f0d5800           mov eax, 0x580d4f
// 00580d4e  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00580d49()
{
    return &G;
}
