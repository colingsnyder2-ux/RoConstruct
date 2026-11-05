// roc 2011-06 00430c71  unit: CMainFrame  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00430c71
//
// 00430c71  b8600c4300           mov eax, 0x430c60
// 00430c76  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00430c71()
{
    return &G;
}
