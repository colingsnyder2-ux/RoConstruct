// roc 2012-06 00a76c30  unit: CXTPRibbonControlSystemRecentFileList  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a76c30
//
// 00a76c30  b87882e000           mov eax, 0xe08278
// 00a76c35  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a76c30()
{
    return &G;
}
