// roc 2012-06 00a302a0  unit: CXTPReportHeaderDragWnd  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a302a0
//
// 00a302a0  b81403c200           mov eax, 0xc20314
// 00a302a5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a302a0()
{
    return &G;
}
