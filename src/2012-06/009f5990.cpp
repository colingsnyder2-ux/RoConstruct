// roc 2012-06 009f5990  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f5990
//
// 009f5990  b896599f00           mov eax, 0x9f5996
// 009f5995  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f5990()
{
    return &G;
}
