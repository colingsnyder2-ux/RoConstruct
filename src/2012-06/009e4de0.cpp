// roc 2012-06 009e4de0  unit: CXTSplitterWnd  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e4de0
//
// 009e4de0  b86475c100           mov eax, 0xc17564
// 009e4de5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009e4de0()
{
    return &G;
}
