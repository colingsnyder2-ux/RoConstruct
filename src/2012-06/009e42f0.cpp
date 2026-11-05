// roc 2012-06 009e42f0  unit: CXTPDockingPane  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e42f0
//
// 009e42f0  b80874c100           mov eax, 0xc17408
// 009e42f5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009e42f0()
{
    return &G;
}
