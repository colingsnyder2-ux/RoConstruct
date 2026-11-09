// roc 2012-06 00a1c180  unit: CXTPDockBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a1c180
//
// 00a1c180  b884e0c100           mov eax, 0xc1e084
// 00a1c185  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a1c180()
{
    return &G;
}
