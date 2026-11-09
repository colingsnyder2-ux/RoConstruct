// roc 2012-06 00a5e130  unit: CXTSplitterWndThemeFactory  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a5e130
//
// 00a5e130  b8e440c200           mov eax, 0xc240e4
// 00a5e135  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a5e130()
{
    return &G;
}
