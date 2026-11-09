// roc 2012-06 00435a91  unit: CMainFrame  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00435a91
//
// 00435a91  b8805a4300           mov eax, 0x435a80
// 00435a96  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00435a91()
{
    return &G;
}
