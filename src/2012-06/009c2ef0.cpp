// roc 2012-06 009c2ef0  unit: CXTPMDIFrameWnd  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c2ef0
//
// 009c2ef0  b81c2bc100           mov eax, 0xc12b1c
// 009c2ef5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009c2ef0()
{
    return &G;
}
