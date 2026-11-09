// roc 2012-06 00a1c3d0  unit: CXTPMenuBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a1c3d0
//
// 00a1c3d0  b8b45ce000           mov eax, 0xe05cb4
// 00a1c3d5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a1c3d0()
{
    return &G;
}
