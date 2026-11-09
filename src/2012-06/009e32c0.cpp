// roc 2012-06 009e32c0  unit: CPropGrid  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e32c0
//
// 009e32c0  b85872c100           mov eax, 0xc17258
// 009e32c5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009e32c0()
{
    return &G;
}
