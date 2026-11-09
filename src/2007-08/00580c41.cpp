// roc 2007-08 00580c41  unit: RBX::Log  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00580c41
//
// 00580c41  b8470c5800           mov eax, 0x580c47
// 00580c46  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00580c41()
{
    return &G;
}
