// roc 2012-06 00a76af0  unit: CXTPRibbonControlSystemPopupBarButton  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a76af0
//
// 00a76af0  b82482e000           mov eax, 0xe08224
// 00a76af5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a76af0()
{
    return &G;
}
