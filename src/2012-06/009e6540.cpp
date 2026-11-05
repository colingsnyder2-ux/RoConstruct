// roc 2012-06 009e6540  unit: CXTSplitterWnd  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e6540
//
// 009e6540  b87477c100           mov eax, 0xc17774
// 009e6545  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009e6540()
{
    return &G;
}
