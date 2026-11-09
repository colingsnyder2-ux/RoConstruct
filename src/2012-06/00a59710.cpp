// roc 2012-06 00a59710  unit: CXTPPropertyGridInplaceEdit  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a59710
//
// 00a59710  b80c39c200           mov eax, 0xc2390c
// 00a59715  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a59710()
{
    return &G;
}
