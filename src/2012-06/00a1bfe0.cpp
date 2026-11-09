// roc 2012-06 00a1bfe0  unit: CXTPDockBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a1bfe0
//
// 00a1bfe0  b890dfc100           mov eax, 0xc1df90
// 00a1bfe5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a1bfe0()
{
    return &G;
}
