// roc 2012-06 00a1d850  unit: CXTPMenuBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a1d850
//
// 00a1d850  b810eac100           mov eax, 0xc1ea10
// 00a1d855  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a1d850()
{
    return &G;
}
