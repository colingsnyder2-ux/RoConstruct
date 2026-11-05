// roc 2012-06 00a71ac0  unit: CXTPDialogBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a71ac0
//
// 00a71ac0  b8986ec200           mov eax, 0xc26e98
// 00a71ac5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a71ac0()
{
    return &G;
}
