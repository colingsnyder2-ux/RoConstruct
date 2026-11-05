// roc 2007-08 00580bd1  unit: RBX::Log  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00580bd1
//
// 00580bd1  b8d70b5800           mov eax, 0x580bd7
// 00580bd6  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00580bd1()
{
    return &G;
}
