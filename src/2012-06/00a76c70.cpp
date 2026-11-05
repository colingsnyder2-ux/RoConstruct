// roc 2012-06 00a76c70  unit: CXTPRibbonSystemPopupBarPage  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a76c70
//
// 00a76c70  b89482e000           mov eax, 0xe08294
// 00a76c75  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a76c70()
{
    return &G;
}
