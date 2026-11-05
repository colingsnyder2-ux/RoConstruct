// roc 2012-06 00435a11  unit: CMainFrame  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00435a11
//
// 00435a11  b8005a4300           mov eax, 0x435a00
// 00435a16  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00435a11()
{
    return &G;
}
