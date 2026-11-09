// roc 2011-06 00430bf1  unit: CMainFrame  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00430bf1
//
// 00430bf1  b8e00b4300           mov eax, 0x430be0
// 00430bf6  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00430bf1()
{
    return &G;
}
