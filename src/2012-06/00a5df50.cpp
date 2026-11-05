// roc 2012-06 00a5df50  unit: CXTPPropertyGridInplaceList  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a5df50
//
// 00a5df50  b82c40c200           mov eax, 0xc2402c
// 00a5df55  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a5df50()
{
    return &G;
}
