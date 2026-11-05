// roc 2012-06 00a76b50  unit: CXTPRibbonControlSystemPopupBarListItem  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a76b50
//
// 00a76b50  b84082e000           mov eax, 0xe08240
// 00a76b55  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a76b50()
{
    return &G;
}
