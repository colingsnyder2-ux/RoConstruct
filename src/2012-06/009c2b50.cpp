// roc 2012-06 009c2b50  unit: CXTTreeCtrl  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c2b50
//
// 009c2b50  b8741cc100           mov eax, 0xc11c74
// 009c2b55  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009c2b50()
{
    return &G;
}
