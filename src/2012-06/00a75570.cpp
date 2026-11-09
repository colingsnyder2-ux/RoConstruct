// roc 2012-06 00a75570  unit: CXTPRibbonControlTab  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a75570
//
// 00a75570  b8ac81e000           mov eax, 0xe081ac
// 00a75575  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a75570()
{
    return &G;
}
