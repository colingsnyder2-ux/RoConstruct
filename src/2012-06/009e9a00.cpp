// roc 2012-06 009e9a00  unit: CXTPToolTipContextToolTip  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e9a00
//
// 009e9a00  b8bc7fc100           mov eax, 0xc17fbc
// 009e9a05  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009e9a00()
{
    return &G;
}
