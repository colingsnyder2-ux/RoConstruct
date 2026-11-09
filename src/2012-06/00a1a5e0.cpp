// roc 2012-06 00a1a5e0  unit: CXTPDockBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a1a5e0
//
// 00a1a5e0  b8b8ddc100           mov eax, 0xc1ddb8
// 00a1a5e5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a1a5e0()
{
    return &G;
}
