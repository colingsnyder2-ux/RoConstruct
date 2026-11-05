// roc 2012-06 009c2ed0  unit: CXTPFrameWnd  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c2ed0
//
// 009c2ed0  b8002bc100           mov eax, 0xc12b00
// 009c2ed5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009c2ed0()
{
    return &G;
}
