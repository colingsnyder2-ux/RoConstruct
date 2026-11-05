// roc 2012-06 00a64820  unit: CXTColorBase  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a64820
//
// 00a64820  b8c84fc200           mov eax, 0xc24fc8
// 00a64825  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a64820()
{
    return &G;
}
